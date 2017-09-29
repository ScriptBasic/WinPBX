' #####################################################################################
' Microsoft Windows
' File: COdbcDbc.inc
' Contents: ODBC connection class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CODBCDBC_INC = 1

#INCLUDE ONCE "ODBC.INC"

$CLSID_COdbcConnection = GUID$("{96AD0676-7B62-4B2B-8761-68E45782F6EC}")
$IID_IOdbcConnection = GUID$("{9870D614-7EA4-40A1-964C-3C21ED9279A7}")

CLASS COdbcConnection $CLSID_COdbcConnection

   INSTANCE m_hDbc AS DWORD                      ' // Connection handle
   INSTANCE m_hEnv AS DWORD                      ' // Environment handle
   INSTANCE m_pDescriptors AS IPowerCollection   ' // Collection of descriptors
   INSTANCE m_pStatements AS IPowerCollection    ' // Collection of statements

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
      ' // Collection of descriptors
      m_pDescriptors = CLASS "PowerCollection"
      ' // Collection of statements
      m_pStatements = CLASS "PowerCollection"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the connection and frees the statements handles
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Clears the collection of descriptors
      IF ISOBJECT(m_pDescriptors) THEN m_pDescriptors.Clear
      ' // Clears the collection of statements
      IF ISOBJECT(m_pStatements) THEN m_pStatements.Clear
      ' //
      IF m_hDbc THEN
         SQLDisconnect(m_hDbc)
         SQLFreeHandle(%SQL_HANDLE_DBC, m_hDbc)
      END IF
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   INTERFACE IOdbcConnection $IID_IOdbcConnection : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the connection handle
   ' =====================================================================================
   PROPERTY GET Handle () AS DWORD
      PROPERTY = m_hDbc
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Get the environment handle
   ' =====================================================================================
   PROPERTY GET EnvHandle () AS DWORD
      PROPERTY = m_hEnv
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current value of a field of a record of the diagnostic data structure
   ' (associated with a specific handle) that contains error, warning, and status information.
   ' =====================================================================================
   METHOD GetDiagField (BYVAL RecNumber AS INTEGER, BYVAL DiagIdentifier AS INTEGER, BYVAL DiagInfo AS DWORD, _
   BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagField(%SQL_HANDLE_DBC, m_hDbc, RecNumber, DiagIdentifier, BYVAL DiagInfo, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current values of multiple fields of a diagnostic record that contains
   ' error, warning and status information. Unlike GetDiagField, which returns one
   ' diagnostic call per call, GetDiagRec returns several commonly used fields of a
   ' diagnostic record, including the SQLSTATE, the native error code, and the
   ' diagnostic message text.
   ' =====================================================================================
   METHOD GetDiagRec (BYVAL RecNumber AS INTEGER, BYREF Sqlstate AS ASCIIZ, BYREF NativeError AS LONG, _
   BYREF MessageText AS ASCIIZ, BYVAL BufferLength AS INTEGER, BYREF TextLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_DBC, m_hDbc, RecNumber, Sqlstate, NativeError, MessageText, BufferLength, TextLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   ' Uses SQLGetDiagRec to retrieve an error description.
   ' iErrorCode is an optional parameter that allows to set the value returned by
   ' OdbcResult to the desired value.
   ' ========================================================================================
   PROPERTY GET ErrorInfo (OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING

      LOCAL iResult AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL strErrMsg AS STRING
      LOCAL cbbytes AS INTEGER
      LOCAL ErrorCount AS LONG
      LOCAL i AS LONG

      iResult = SQLGetDiagField(%SQL_HANDLE_DBC, m_hDbc, 0, %SQL_DIAG_NUMBER, ErrorCount, %SQL_IS_INTEGER, cbbytes)

      IF ErrorCount THEN
         FOR i = 1 TO ErrorCount
            iResult = SQLGetDiagRec(%SQL_HANDLE_DBC, m_hDbc, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
            IF iResult <> %SQL_SUCCESS AND iResult <> %SQL_SUCCESS_WITH_INFO THEN EXIT FOR
            strErrMsg = szErrMsg & $CRLF & "SqlState: " & szSqlState & $CRLF & _
                        "Native error: " & FORMAT$(lNativeError) & $CRLF
         NEXT
      ELSEIF iErrorCode THEN
         SELECT CASE AS LONG iErrorCode
            CASE  -1 : strErrMsg = "SQL error" ' "SQL_ERROR"
            CASE   2 : strErrMsg = "Still executing" ' "SQL_STILL_EXECUTING"
            CASE  -2 : strErrMsg = "Invalid handle" '"SQL_INVALID_HANDLE"
            CASE  99 : strErrMsg = "Need data" ' "SQL_NEED_DATA"
            CASE 100 : strErrMsg = "No data" '"SQL_NO_DATA"
            CASE ELSE
               strErrMsg = "Error " & FORMAT$(iErrorCode)
         END SELECT
      END IF

      PROPERTY = strErrMsg

   END PROPERTY
   ' ========================================================================================

   ' =====================================================================================
   ' Allocates a connection handle
   ' =====================================================================================
   METHOD AllocConnect (BYVAL hEnv AS DWORD) AS DWORD
      LOCAL r AS INTEGER
      IF m_hDbc THEN
         SQLDisconnect(m_hDbc)
         SQLFreeHandle (%SQL_HANDLE_DBC, m_hDbc)
         m_hDbc = %NULL
      END IF
      r = SQLAllocHandle (%SQL_HANDLE_DBC, hEnv, m_hDbc)
      m_hEnv = hEnv
      METHOD = m_hDbc
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Connects with the database.
   ' =====================================================================================
   METHOD OpenDatabase (BYVAL strConnectionString AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      LOCAL szInConnectionString AS ASCIIZ * 1025
      LOCAL szOutConnectionString AS ASCIIZ * 1025
      IF LEN(strConnectionString) THEN szInConnectionString = strConnectionString
      IF m_hEnv = %NULL OR m_hDbc = %NULL THEN r = %SQL_INVALID_HANDLE : EXIT METHOD
      r = SQLAllocHandle(%SQL_HANDLE_DBC, m_hEnv, m_hDbc)
      IF SQL_SUCCEEDED(r) THEN
         r = SQLDriverConnect(m_hDbc, %HWND_DESKTOP, szInConnectionString, LEN(szInConnectionString), _
             szOutConnectionString, SIZEOF(szOutConnectionString), BYVAL %NULL, %SQL_DRIVER_COMPLETE)
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Disconnects the database and frees the connection handle.
   ' =====================================================================================
   METHOD CloseDatabase () AS INTEGER
      LOCAL r AS INTEGER
      IF m_hDbc THEN
         r = SQLDisconnect(m_hDbc)
         IF SQL_SUCCEEDED(r) THEN
            r = SQLFreeHandle (%SQL_HANDLE_DBC, m_hDbc)
            m_hDbc = %NULL
         END IF
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Establishes connections to a driver and a data source.
   ' =====================================================================================
   METHOD Connect (BYVAL ServerName AS STRING, BYVAL UserName AS STRING, BYVAL Authentication AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      LOCAL szServerName AS ASCIIZ * 1025
      LOCAL szUserName AS ASCIIZ * 256
      LOCAL szAuthentication AS ASCIIZ * 256
      szServerName = ServerName
      szUserName = UserName
      szAuthentication = Authentication
      r = SQLConnect(m_hDbc, szServerName, LEN(szServerName), szUserName, LEN(szUserName), szAuthentication, LEN(szAuthentication))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the connection associated with a specific connection handle.
   ' =====================================================================================
   METHOD Disconnect () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLDisconnect(m_hDbc)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Establishes connections to a driver and a data source.
   ' =====================================================================================
   METHOD DriverConnect (BYVAL hWnd AS DWORD, BYVAL Constr AS STRING, OPTIONAL BYVAL fDriverCompletion AS WORD) AS STRING
      LOCAL r AS INTEGER
      LOCAL szOutConStr AS ASCIIZ * 1025
      IF fDriverCompletion = 0 THEN fDriverCompletion = %SQL_DRIVER_COMPLETE
      r = SQLDriverConnect(m_hDbc, hWnd, BYVAL STRPTR(ConStr), LEN(ConStr), szOutConStr, SIZEOF(szOutConstr), BYVAL %NULL, fDriverCompletion)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = szOutConStr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Establishes connections to a driver and a data source.
   ' Note: Optional function not implemented in Microsoft Access Driver.
   ' =====================================================================================
   METHOD BrowseConnect (BYVAL Constr AS STRING) AS STRING
      LOCAL r AS INTEGER
      LOCAL szOutConStr AS ASCIIZ * 1025
      LOCAL pcbConnStrOut AS INTEGER
      r = SQLBrowseConnect(m_hDbc, BYVAL STRPTR(ConStr), LEN(ConStr), szOutConStr, SIZEOF(szOutConstr), pcbConnStrOut)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = szOutConStr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the SQL string as modified by the driver.
   ' =====================================================================================
   PROPERTY GET NativeSql (BYVAL InText AS STRING) AS STRING
      LOCAL r AS INTEGER
      LOCAL szInText AS ASCIIZ * 1025
      LOCAL szOutText AS ASCIIZ * 1025
      LOCAL cbbytes AS LONG
      IF LEN(InText) = 0 THEN EXIT PROPERTY
      szInText = InText
      r = SQLNativeSql(m_hDbc, szInText, LEN(szInText), szOutText, 1025, cbbytes)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT PROPERTY
      PROPERTY = szOutText
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the SqlState for the connection handle
   ' =====================================================================================
   PROPERTY GET SqlState () AS STRING
      LOCAL r AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL cbbytes AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_DBC, m_hDbc, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
      PROPERTY = szSqlState
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns information about whether a driver supports a specific driver function.
   ' =====================================================================================
   PROPERTY GET Supports (BYVAL FunctionId AS WORD) AS WORD
      LOCAL r AS INTEGER
      LOCAL Supported AS WORD
      r = SQLGetFunctions(m_hDbc, FunctionId, Supported)
      PROPERTY = Supported
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET Functions (BYVAL FunctionId AS WORD) AS WORD
      LOCAL r AS INTEGER
      LOCAL Supported AS WORD
      r = SQLGetFunctions(m_hDbc, FunctionId, Supported)
      PROPERTY = Supported
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   ' TRANSACTIONS
   ' #####################################################################################

   ' =====================================================================================
   METHOD CommitTran () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLEndTran(%SQL_HANDLE_DBC, m_hDbc, %SQL_COMMIT)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RollbackTran () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLEndTran(%SQL_HANDLE_DBC, m_hDbc, %SQL_ROLLBACK)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' CONNECTION ATTRIBUTES
   ' #####################################################################################

   ' =====================================================================================
   ' Returns or sets the current setting of a connection attribute.
   ' =====================================================================================
   METHOD GetConnectAttr (BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetConnectAttr(m_hDbc, Attribute, BYVAL ValuePtr, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetConnectAttr (BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, Attribute, BYVAL ValuePtr, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value. %SQL_MODE_READ_ONLY is used by the driver or data source as an
   ' indicator that the connection is not required to support SQL statements that cause
   ' updates to occur. This mode can be used to optimize locking strategies, transaction
   ' management, or other areas as appropriate to the driver or data source. The driver is
   ' not required to prevent such statements from being submitted to  the data source. The
   ' behavior of the driver and data source when asked to process SQL statements that are not
   ' read-only during a read-only connection is implementation-defined.
   ' %SQL_MODE_READ_WRITE is the default.
   ' =====================================================================================
   PROPERTY GET AccessMode () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_ACCESS_MODE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET AccessMode (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_ACCESS_MODE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that specifies whether a function called with a statement on the
   ' specified connection is executed asynchronously:
   '   %SQL_ASYNC_ENABLE_OFF = Off (the default)
   '   %SQL_ASYNC_ENABLE_ON = On
   ' =====================================================================================
   PROPERTY GET AsyncEnable () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_ASYNC_ENABLE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET AsyncEnable (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_ASYNC_ENABLE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A read-only SQLUINTEGER value that specifies whether automatic population of the IPD
   ' after a call to Prepare is supported:
   '   %SQL_TRUE = Automatic population of the IPD after a call to Prepare is supported
   '   by the driver.
   '   %SQL_FALSE = Automatic population of the IPD after a call to Prepare is not
   '   supported by the driver. Servers that do not support prepared statements will not be
   '   able to populate the IPD automatically.
   ' =====================================================================================
   PROPERTY GET AutoIPD () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_AUTO_IPD, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that specifies whether to use autocommit or manual-commit mode:
   '   %SQL_AUTOCOMMIT_OFF = The driver uses manual-commit mode, and the application must
   '   explicitly commit or roll back transactions with EndTran.
   '   %SQL_AUTOCOMMIT_ON = The driver uses autocommit mode. Each statement is committed
   '   immediately after it is executed. This is the default. Any open transactions on the
   '   connection are committed when %SQL_ATTR_AUTOCOMMIT is set to %SQL_AUTOCOMMIT_ON to
   '   change from manual-commit mode to autocommit mode.
   ' =====================================================================================
   PROPERTY GET AutoCommit () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_AUTOCOMMIT, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET Autocommit (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_AUTOCOMMIT, BYVAL dwAttr, %SQL_IS_UINTEGER)
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetAutocommitOn () AS INTEGER
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      dwAttr = %SQL_AUTOCOMMIT_ON
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_AUTOCOMMIT, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetAutocommitOff () AS INTEGER
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      dwAttr = %SQL_AUTOCOMMIT_OFF
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_AUTOCOMMIT, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that indicates the state of the connection. If %SQL_CD_TRUE, the
   ' connection has been lost. If %SQL_CD_FALSE, the connection is still active.
   ' Note: Relates to connection pooling.
   ' =====================================================================================
   PROPERTY GET ConnectionIsDead () AS INTEGER
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_CONNECTION_DEAD, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF dwAttr = %SQL_CD_TRUE THEN PROPERTY = 1  ' %SQL_TRUE
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConnectionIsAlive () AS INTEGER
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_CONNECTION_DEAD, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF dwAttr = %SQL_CD_FALSE THEN PROPERTY = 1  ' %SQL_TRUE
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value corresponding to the number of seconds to wait for any request on
   ' the connection to complete before returning to the application. The driver should return
   ' SQLSTATE HYT00 (Timeout expired) anytime that it is possible to time out in a situation
   ' not associated with query execution or login.
   ' If ValuePtr is equal to 0 (the default), there is no timeout.
   ' Note: Optional function not implemented in the Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET ConnectionTimeout () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_CONNECTION_TIMEOUT, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET ConnectionTimeout (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_CONNECTION_TIMEOUT, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A character string containing the name of the catalog to be used by the data source. For
   ' example, in SQL Server, the catalog is a database, so the driver sends a USE database
   ' statement to the data source, where database is the database specified in *ValuePtr. For
   ' a single-tier driver, the catalog might be a directory, so the driver changes its
   ' current directory to the directory specified in *ValuePtr.
   ' =====================================================================================
   PROPERTY GET CurrentCatalog () AS STRING
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * 255
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_CURRENT_CATALOG, szAttr, SIZEOF(szAttr), BYVAL %NULL)
      PROPERTY = szAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CurrentCatalog (BYVAL sAttr AS STRING)
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * 255
      szAttr = sAttr
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_CURRENT_CATALOG, szAttr, %SQL_NTS)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value corresponding to the number of seconds to wait for a login request
   ' to complete before returning to the application. The default is driver-dependent. If
   ' ValuePtr is 0, the timeout is disabled and a connection attempt will wait indefinitely.
   ' If the specified timeout exceeds the maximum login timeout in the data source, the
   ' driver substitutes that value and returns SQLSTATE 01S02 (Option value changed).
   ' =====================================================================================
   PROPERTY GET LoginTimeout () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_LOGIN_TIMEOUT, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET LoginTimeout (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_LOGIN_TIMEOUT, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that determines how the string arguments of catalog functions are
   ' treated.
   ' If %SQL_TRUE, the string argument of catalog functions are treated as identifiers. The
   ' case is not significant. For nondelimited strings, the driver removes any trailing
   ' spaces and the string is folded to uppercase.
   ' For delimited strings, the driver removes any leading or trailing spaces and takes
   ' literally whatever is between the delimiters. If one of these arguments is set to a null
   ' pointer, the function returns %SQL_ERROR and SQLSTATE HY009 (Invalid use of null pointer).
   ' If %SQL_FALSE, the string arguments of catalog functions are not treated as identifiers.
   ' The case is significant. They can either contain a string search pattern or not,
   ' depending on the argument.
   ' The default value is %SQL_FALSE.
   ' The TableType argument of Tables, which takes a list of values, is not affected by
   ' this attribute.
   ' %SQL_ATTR_METADATA_ID can also be set on the statement level. (It is the only connection
   ' attribute that is also a statement attribute.)
   ' Note: Optional function not implemented in the Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET MetadataID () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_METADATA_ID, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET MetadataID (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_METADATA_ID, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value specifying how the Driver Manager uses the ODBC cursor library:
   ' - %SQL_CUR_USE_IF_NEEDED = The Driver Manager uses the ODBC cursor library only if it is
   '   needed. If the driver supports the %SQL_FETCH_PRIOR option in FetchScroll, the
   '   Driver Manager uses the scrolling capabilities of the driver. Otherwise, it uses the
   '   ODBC cursor library.
   ' - %SQL_CUR_USE_ODBC = The Driver Manager uses the ODBC cursor library.
   ' - %SQL_CUR_USE_DRIVER = The Driver Manager uses the scrolling capabilities of the
   '   driver. This is the default setting.
   ' =====================================================================================
   PROPERTY GET OdbcCursors () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_ODBC_CURSORS, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET OdbcCursors (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_ODBC_CURSORS, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value specifying the network packet size in bytes.
   ' Note: Many data sources either do not support this option or only can return but not set
   ' the network packet size.
   ' If the specified size exceeds the maximum packet size or is smaller than the minimum
   ' packet size, the driver substitutes that value and returns SQLSTATE 01S02 (Option value
   ' changed).
   ' If the application sets packet size after a connection has already been made, the driver
   ' will return SQLSTATE HY011 (Attribute cannot be set now).
   ' Note: Optional function not implemented in the Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET PacketSize () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_PACKET_SIZE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET PacketSize (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_PACKET_SIZE, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A 32-bit window handle (hwnd).
   ' If the window handle is a null pointer, the driver does not display any dialog boxes.
   ' If the window handle is not a null pointer, it should be the parent window handle of the
   ' application. This is the default. The driver uses this handle to display dialog boxes.
   ' Note: The %SQL_ATTR_QUIET_MODE connection attribute does not apply to dialog boxes
   ' displayed by DriverConnect.
   ' =====================================================================================
   PROPERTY GET QuietMode () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_QUIET_MODE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET QuietMode (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_QUIET_MODE, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value telling the Driver Manager whether to perform tracing:
   '   %SQL_OPT_TRACE_OFF = Tracing off (the default)
   '   %SQL_OPT_TRACE_ON = Tracing on
   ' When tracing is on, the Driver Manager writes each ODBC function call to the trace file.
   ' =====================================================================================
   PROPERTY GET Trace () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_TRACE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET Trace (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_TRACE, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A null-terminated character string containing the name of the trace file.
   ' The default value of the %SQL_ATTR_TRACEFILE attribute is specified with the TraceFile
   ' keyword in the system information. For more information, see "ODBC Subkey" in Chapter
   ' 19: Configuring Data Sources.
   ' Calling SetTraceFile does not require the ConnectionHandle argument to be valid and
   ' will not return %SQL_ERROR if ConnectionHandle is invalid. This attribute applies to all
   ' connections.
   ' =====================================================================================
   PROPERTY GET TraceFile () AS STRING
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * %MAX_PATH + 1
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_TRACEFILE, szAttr, SIZEOF(szAttr), BYVAL %NULL)
      PROPERTY = szAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET TraceFile (BYVAL sAttr AS STRING)
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * %MAX_PATH + 1
      szAttr = sAttr
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_TRACEFILE, szAttr, %SQL_NTS)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A null-terminated character string containing the name of a library containing the
   ' functions DriverToDataSource and DataSourceToDriver that the driver accesses to
   ' perform tasks such as character set translation.
   ' This option may be specified only if the driver has connected to the data source. The
   ' setting of this attribute will persist across connections.
   ' Note: Optional function not implemented in the Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET TranslateLib () AS STRING
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * %MAX_PATH + 1
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_TRANSLATE_LIB, szAttr, SIZEOF(szAttr), BYVAL %NULL)
      PROPERTY = szAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET TranslateLib (BYVAL sAttr AS STRING)
      LOCAL r AS INTEGER
      LOCAL szAttr AS ASCIIZ * %MAX_PATH + 1
      szAttr = sAttr
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_TRANSLATE_LIB, szAttr, %SQL_NTS)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A 32-bit flag value that is passed to the translation DLL. This attribute can be
   ' specified only if the driver has connected to the data source.
   ' =====================================================================================
   PROPERTY GET TxnIsolation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetConnectAttr(m_hDbc, %SQL_ATTR_TXN_ISOLATION, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET TxnIsolation (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetConnectAttr(m_hDbc, %SQL_ATTR_TXN_ISOLATION, BYVAL dwAttr, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   ' INFO METHODS
   ' #####################################################################################

   ' =====================================================================================
   ' Returns general information about the driver and data source associated with a connection.
   ' =====================================================================================
   METHOD GetInfo (BYVAL InfoType AS WORD, BYVAL InfoValuePtr AS DWORD, BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetInfo(m_hDbc, InfoType, BYVAL InfoValuePtr, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetInfoStr (BYVAL InfoType AS WORD) AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 1025
      r = SqlGetInfo(m_hDbc, InfoType, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = szInfoValue
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetInfoInt (BYVAL InfoType AS WORD) AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SqlGetInfo(m_hDbc, InfoType, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = wInfo
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetInfoLong (BYVAL InfoType AS WORD) AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SqlGetInfo(m_hDbc, InfoType, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = dwInfo
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET DMVer () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 16
      r = SQLGetInfo(m_hDbc, %SQL_DM_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DMVerMajor () AS WORD
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 16
      r = SQLGetInfo(m_hDbc, %SQL_DM_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = VAL(LEFT$(szInfoValue, 2))
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DMVerMinor () AS WORD
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 16
      r = SQLGetInfo(m_hDbc, %SQL_DM_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = VAL(MID$(szInfoValue, 4, 2))
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET XOpenCliYear () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 5
      r = SQLGetInfo(m_hDbc, %SQL_XOPEN_CLI_YEAR, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                 DRIVER INFORMATION
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET ActiveEnvironments () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_ACTIVE_ENVIRONMENTS, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET AsyncMode () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_ASYNC_MODE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET BatchRowCount () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_BATCH_ROW_COUNT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET BatchSupport () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_BATCH_SUPPORT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DataSourceName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * %MAX_PATH + 1
      r = SQLGetInfo(m_hDbc, %SQL_DATA_SOURCE_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverhEnv () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_HENV, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverhDbc () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_HDBC, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverhStmt (BYVAL hStmt AS DWORD) AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      dwInfo = hStmt
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_HSTMT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverhDesc (BYVAL hDesc AS DWORD) AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      dwInfo = hDesc
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_HDESC, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverhLib () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_HLIB, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverODBCVer () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 6
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_ODBC_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DriverVer () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 11
      r = SQLGetInfo(m_hDbc, %SQL_DRIVER_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DynamicCursorAttributes1 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DYNAMIC_CURSOR_ATTRIBUTES1, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DynamicCursorAttributes2 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DYNAMIC_CURSOR_ATTRIBUTES2, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ForwardOnlyCursorAttributes1 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ForwardOnlyCursorAttributes2 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET FileUsage () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_FILE_USAGE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DataExtensions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_GETDATA_EXTENSIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET InfoSchemaViews () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_INFO_SCHEMA_VIEWS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET KeysetCursorAttributes1 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_KEYSET_CURSOR_ATTRIBUTES1, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET KeysetCursorAttributes2 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_KEYSET_CURSOR_ATTRIBUTES2, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxAsyncConcurrentStatements () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_ASYNC_CONCURRENT_STATEMENTS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxConcurrentActivities () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_CONCURRENT_ACTIVITIES, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxDriverConnections () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_DRIVER_CONNECTIONS, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET OdbcInterfaceConformance () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_ODBC_INTERFACE_CONFORMANCE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ODBCVer () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 11
      r = SQLGetInfo(m_hDbc, %SQL_ODBC_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ParamArrayRowCounts () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_PARAM_ARRAY_ROW_COUNTS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ParamArraySelects () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_PARAM_ARRAY_SELECTS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET PosOperations () AS LONG
      LOCAL r AS INTEGER
      LOCAL lInfo AS LONG
      r = SQLGetInfo(m_hDbc, %SQL_POS_OPERATIONS, lInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = lInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET StandardCliConformance () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_STANDARD_CLI_CONFORMANCE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET RowUpdates () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_ROW_UPDATES, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SearchPatternEscape () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_SEARCH_PATTERN_ESCAPE, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ServerName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_SERVER_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET StaticCursorAttributes1 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_STATIC_CURSOR_ATTRIBUTES1, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET StaticCursorAttributes2 () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_STATIC_CURSOR_ATTRIBUTES2, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                               DBMS PRODUCT INFORMATION
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET DatabaseName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * %MAX_PATH + 1
      r = SQLGetInfo(m_hDbc, %SQL_DATABASE_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DBMSName () AS STRING
      LOCAL r AS INTEGER
      DIM szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_DBMS_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET DBMSVer () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_DBMS_VER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                              DATA SOURCE INFORMATION
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET AccessibleProcedures () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_ACCESSIBLE_PROCEDURES, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET AccessibleTables () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_ACCESSIBLE_TABLES, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET BookmarkPersistence () AS DWORD
      LOCAL dwInfo AS DWORD
      LOCAL r AS INTEGER
      r = SQLGetInfo(m_hDbc, %SQL_BOOKMARK_PERSISTENCE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CatalogTerm () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_CATALOG_TERM, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CollationSeq () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_COLLATION_SEQ, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConcatNullBehavior () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_CONCAT_NULL_BEHAVIOR, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CursorCommitBehavior () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_CURSOR_COMMIT_BEHAVIOR, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CursorRollbackBehavior () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_CURSOR_ROLLBACK_BEHAVIOR, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CursorSensitivitySupport () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CURSOR_SENSITIVITY, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DataSourceReadOnly () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_DATA_SOURCE_READ_ONLY, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DefaultTxnIsolation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_DEFAULT_TXN_ISOLATION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DescribeParameter () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_DESCRIBE_PARAMETER, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MultResultSets () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_MULT_RESULT_SETS, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MultipleActiveTxn () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_MULTIPLE_ACTIVE_TXN, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET NeedLongDataLen () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_NEED_LONG_DATA_LEN, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET NullCollation () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_NULL_COLLATION, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ProcedureTerm () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_PROCEDURE_TERM, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SchemaTerm () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 255
      r = SQLGetInfo(m_hDbc, %SQL_SCHEMA_TERM, szInfoValue, SIZEOF(szInfoValue), 0)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ScrollOptions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SCROLL_OPTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET TableTerm () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 11
      r = SQLGetInfo(m_hDbc, %SQL_TABLE_TERM, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET TxnCapable () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_TXN_CAPABLE, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET TxnIsolationOption () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_TXN_ISOLATION_OPTION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET UserName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 30
      r = SQLGetInfo(m_hDbc, %SQL_USER_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                    SUPPORTED SQL
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET AggregateFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_AGGREGATE_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET AlterDomain () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_ALTER_DOMAIN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET AlterTable () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_ALTER_TABLE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CatalogLocation () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_CATALOG_LOCATION, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CatalogName () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_CATALOG_NAME, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CatalogNameSeparator () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_CATALOG_NAME_SEPARATOR, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CatalogUsage () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CATALOG_USAGE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ColumnAlias () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_COLUMN_ALIAS, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CorrelationName () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_CORRELATION_NAME, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateAssertion () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_ASSERTION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateCharacterSet () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_CHARACTER_SET, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateCollation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_COLLATION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateDomain () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_DOMAIN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateSchema () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_SCHEMA, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateTable () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_TABLE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateTranslation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_TRANSLATION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CreateView () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CREATE_VIEW, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DateTimeLiterals () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DATETIME_LITERALS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DDLIndex () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DDL_INDEX, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropAssertion () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_ASSERTION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropCharacterSet () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_CHARACTER_SET, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropCollation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_COLLATION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropDomain () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_DOMAIN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropSchema () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_SCHEMA, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropTable () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_TABLE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropTranslation () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_TRANSLATION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET DropView () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_DROP_VIEW, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ExpressionsInOrderBy () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_EXPRESSIONS_IN_ORDERBY, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET GroupBy () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_GROUP_BY, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET IdentifierCase () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_IDENTIFIER_CASE, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET IdentifierQuoteChar () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_IDENTIFIER_QUOTE_CHAR, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET IndexKeywords () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_INDEX_KEYWORDS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET InsertStatement () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_INSERT_STATEMENT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET Integrity () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_INTEGRITY, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET Keywords () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 1025
      r = SQLGetInfo(m_hDbc, %SQL_KEYWORDS, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET LikeEscapeClause () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_LIKE_ESCAPE_CLAUSE, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET NonNullableColumns () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_NON_NULLABLE_COLUMNS, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SqlConformance () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL_CONFORMANCE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET OJCapabilities () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_OJ_CAPABILITIES, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET OuterJoins () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_OUTER_JOINS, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET OrderByColumnsInSelect () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 11
      r = SQLGetInfo(m_hDbc, %SQL_ORDER_BY_COLUMNS_IN_SELECT, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ProceduresSupport () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_PROCEDURES, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET QuotedIdentifierCase () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_QUOTED_IDENTIFIER_CASE, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SchemaUsage () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SCHEMA_USAGE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SpecialCharacters () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 40
      r = SQLGetInfo(m_hDbc, %SQL_SPECIAL_CHARACTERS, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET Subqueries () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SUBQUERIES, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET Union () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_UNION, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                      SQL LIMITS
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET MaxBinaryLiteralLen () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_BINARY_LITERAL_LEN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxCatalogNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_CATALOG_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxCharLiteralLen () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_CHAR_LITERAL_LEN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMN_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnsInGroupBy () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMNS_IN_GROUP_BY, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnsInIndex () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMNS_IN_INDEX, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnsInOrderBy () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMNS_IN_ORDER_BY, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnsInSelect () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMNS_IN_SELECT, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxColumnsInTable () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_COLUMNS_IN_TABLE, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxCursorNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_CURSOR_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxIdentifierLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_IDENTIFIER_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxIndexSize () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_INDEX_SIZE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxProcedureNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_PROCEDURE_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxRowSize () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_ROW_SIZE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxRowSizeIncludesLong () AS STRING
      LOCAL r AS INTEGER
      LOCAL szInfoValue AS ASCIIZ * 2
      r = SQLGetInfo(m_hDbc, %SQL_MAX_ROW_SIZE_INCLUDES_LONG, szInfoValue, SIZEOF(szInfoValue), BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szInfoValue
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxSchemaNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_SCHEMA_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxStatementLen () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_STATEMENT_LEN, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxTableNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_TABLE_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxTablesInSelect () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_TABLES_IN_SELECT, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET MaxUserNameLen () AS WORD
      LOCAL r AS INTEGER
      LOCAL wInfo AS WORD
      r = SQLGetInfo(m_hDbc, %SQL_MAX_USER_NAME_LEN, wInfo, 2, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = wInfo
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                             SCALAR FUNCTIONS INFORMATION
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET ConvertFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET NumericFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_NUMERIC_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET StringFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_STRING_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SystemFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SYSTEM_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET TimeDateAddIntervals () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_TIMEDATE_ADD_INTERVALS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET TimeDateDiffIntervals () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_TIMEDATE_DIFF_INTERVALS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET TimeDateFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_TIMEDATE_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================

   ' ####################################################################################
   '                               CONVERSION INFORMATION
   ' ####################################################################################

   ' =====================================================================================
   PROPERTY GET ConvertBigInt () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_BIGINT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertBinary () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_BINARY, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertBit () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_BIT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertChar () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_CHAR, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertDate () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_DATE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertDecimal () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_DECIMAL, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertDouble () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_DOUBLE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertFloat () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_FLOAT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertInteger () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_INTEGER, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertIntervalYearMonth () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_INTERVAL_YEAR_MONTH, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertIntervalDayTime () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_INTERVAL_DAY_TIME, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertLongVarBinary () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_LONGVARBINARY, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertLongVarChar () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_LONGVARCHAR, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertNumeric () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_NUMERIC, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertReal (BYVAL m_hDbc AS  DWORD) AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_REAL, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertSmallInt () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_SMALLINT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertTime () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_TIME, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertTimeStamp () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_TIMESTAMP, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertTinyInt () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_TINYINT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET ConvertVarBinary () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_VARBINARY, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ConvertVarChar () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_CONVERT_VARCHAR, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                       SQL92
   ' #####################################################################################

   ' =====================================================================================
   PROPERTY GET SQL92DateTimeFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_DATETIME_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92ForeignKeyDeleteRule () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_FOREIGN_KEY_DELETE_RULE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92ForeignKeyUpdateRule () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_FOREIGN_KEY_UPDATE_RULE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92Grant () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_GRANT, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET SQL92NumericValueFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_NUMERIC_VALUE_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92Predicates () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_PREDICATES, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92RelationalJoinOperators () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_RELATIONAL_JOIN_OPERATORS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92Revoke () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_REVOKE, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92RowValueConstructor () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_ROW_VALUE_CONSTRUCTOR, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92StringFunctions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_STRING_FUNCTIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET SQL92ValueExpressions () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwInfo AS DWORD
      r = SQLGetInfo(m_hDbc, %SQL_SQL92_VALUE_EXPRESSIONS, dwInfo, 4, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcConnection, "IODBCCONNECTION." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwInfo
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   ' Collection of descriptors
   ' #####################################################################################

   ' =====================================================================================
   ' Adds a descriptor to the collection.
   ' =====================================================================================
   METHOD AddDescriptor (BYVAL bstrKey AS WSTRING, BYVAL vObj AS VARIANT)
      IF ISOBJECT(m_pDescriptors) THEN m_pDescriptors.Add(bstrKey, vObj)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes a descriptor from the collection.
   ' =====================================================================================
   METHOD RemoveDescriptor (BYVAL bstrKey AS WSTRING)
      IF ISOBJECT(m_pDescriptors) THEN m_pDescriptors.Remove(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a descriptor from the collection.
   ' =====================================================================================
   METHOD GetDescriptor (BYVAL bstrKey AS WSTRING) AS VARIANT
      IF ISOBJECT(m_pDescriptors) THEN METHOD = m_pDescriptors.Item(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the collection.
   ' =====================================================================================
   METHOD GetDescriptors () AS IPowerCollection
      METHOD = m_pDescriptors
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Creation of descriptors
   ' #####################################################################################

   ' =====================================================================================
   ' Creates a new a descriptor object
   ' =====================================================================================
   METHOD Descriptor (BYVAL bstrKey AS WSTRING) AS IOdbcDescriptor
      LOCAL pDesc AS IOdbcDescriptor
      IF bstrKey = "" THEN EXIT METHOD
      IF ISTRUE m_pDescriptors.Contains(bstrKey) THEN
         LOCAL vObj AS VARIANT
         vObj = ME.GetDescriptor(bstrKey)
         pDesc = vObj
         vObj = EMPTY
      ELSE
         pDesc = CLASS "COdbcDescriptor"
         IF ISOBJECT(pDesc) THEN
            pDesc.AllocDesc(m_hDbc)
            ME.AddDescriptor(bstrKey, pDesc)
         END IF
      END IF
      METHOD = pDesc
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Collection of statements
   ' #####################################################################################

   ' =====================================================================================
   ' Adds an statement to the collection.
   ' =====================================================================================
   METHOD AddStatement (BYVAL bstrKey AS WSTRING, BYVAL vObj AS VARIANT)
      IF ISOBJECT(m_pStatements) THEN m_pStatements.Add(bstrKey, vObj)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes an statement from the collection.
   ' =====================================================================================
   METHOD RemoveStatement (BYVAL bstrKey AS WSTRING)
      IF ISOBJECT(m_pStatements) THEN m_pStatements.Remove(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns an statement from the collection.
   ' =====================================================================================
   METHOD GetStatement (BYVAL bstrKey AS WSTRING) AS VARIANT
      IF ISOBJECT(m_pStatements) THEN METHOD = m_pStatements.Item(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the collection.
   ' =====================================================================================
   METHOD GetStatements () AS IPowerCollection
      METHOD = m_pStatements
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Creation of statements
   ' #####################################################################################

   ' =====================================================================================
   ' Creates a new statement object
   ' =====================================================================================
   METHOD Statement (BYVAL bstrKey AS WSTRING) AS IOdbcStatement
      LOCAL pStmt AS IOdbcStatement
      IF bstrKey = "" THEN EXIT METHOD
      IF ISTRUE m_pStatements.Contains(bstrKey) THEN
         LOCAL vObj AS VARIANT
         vObj = ME.GetStatement(bstrKey)
         pStmt = vObj
         vObj = EMPTY
      ELSE
         pStmt = CLASS "COdbcStatement"
         IF ISOBJECT(pStmt) THEN
            pStmt.AllocStmt(m_hDbc)
            ME.AddStatement(bstrKey, pStmt)
         END IF
      END IF
      METHOD = pStmt
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
