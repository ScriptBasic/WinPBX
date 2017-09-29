' #####################################################################################
' Microsoft Windows
' File: COdbc.inc
' Contents: ODBC wrapper class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CODBC_INC = 1

#INCLUDE ONCE "ODBC.inc"
#INCLUDE ONCE "COdbcDbc.inc"
#INCLUDE ONCE "COdbcStmt.inc"
#INCLUDE ONCE "COdbcDesc.inc"
#INCLUDE ONCE "Ole2Utils.inc"

$CLSID_COdbc = GUID$("{1D8197B7-9645-4982-8F07-ACF50F12B7A3}")
$IID_IOdbc = GUID$("{1A41317F-C862-41DC-8080-FC2D36F37392}")

CLASS COdbc $CLSID_COdbc

   INSTANCE m_hEnv AS DWORD                      ' // Environment handle
   INSTANCE m_pConnections AS IPowerCollection   ' // Collection of connections

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
      ' // Collection of connections
      m_pConnections = CLASS "PowerCollection"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes cursors, frees statement handles, closes and frees connections and
   ' frees the environment handle.
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Clears the collection of connections
      IF ISOBJECT(m_pConnections) THEN m_pConnections.Clear
      ' // Frees the environment handle
      IF m_hEnv THEN SQLFreeHandle(%SQL_HANDLE_ENV, m_hEnv)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IOdbc interface
   ' #####################################################################################

   INTERFACE IOdbc $IID_IOdbc : INHERIT IAutomation

   ' =====================================================================================
   ' Allocates an environment handle, sets the ODBC version and, optionally, enables
   ' connection pooling.
   ' Connection pooling is enabled by calling SetEnvAttr to set the SQL_ATTR_CONNECTION_POOLING
   ' attribute to SQL_CP_ONE_PER_DRIVER or SQL_CP_ONE_PER_HENV. This call must be made
   ' before the application allocates the shared environment for which connection pooling
   ' is to be enabled. The environment handle in the call to SetEnvAttr is set to null,
   ' which makes SQL_ATTR_CONNECTION_POOLING a process-level attribute. After connection
   ' pooling is enabled, the application then allocates an implicit shared environment by
   ' calling SQLAllocHandle with the InputHandle argument set to SQL_HANDLE_ENV. After
   ' connection pooling has been enabled and a shared environment has been selected for an
   ' application, SQL_ATTR_CONNECTION_POOLING cannot be reset for that environment,
   ' because SetEnvAttr is called with a null environment handle when setting this
   ' attribute. If this attribute is set while connection pooling is already enabled on a
   ' shared environment, the attribute affects only shared environments that are allocated
   ' subsequently.
   ' =====================================================================================
   METHOD Init (OPTIONAL BYVAL dwOdbcVersion AS DWORD, BYVAL dwConnectionPoolingAttr AS DWORD) AS INTEGER
      IF m_hEnv = %NULL THEN
         ' // Connection pooling
         IF dwConnectionPoolingAttr = %SQL_CP_ONE_PER_DRIVER OR dwConnectionPoolingAttr = %SQL_CP_ONE_PER_HENV THEN
            SQLSetEnvAttr(%NULL, %SQL_ATTR_CONNECTION_POOLING, BYVAL dwConnectionPoolingAttr, %SQL_IS_UINTEGER)
         END IF
         ' // Allocates the environment handle
         SQLAllocHandle(%SQL_HANDLE_ENV, %SQL_NULL_HENV, m_hEnv)
         ' // Sets the ODBC version
         IF m_hEnv THEN
            IF dwOdbcVersion THEN
               SQLSetEnvAttr(m_hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL dwOdbcVersion, %SQL_IS_UINTEGER)
            ELSE
#IF %ODBCVER >= &H0380
               SQLSetEnvAttr(m_hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL %SQL_OV_ODBC3_80, %SQL_IS_UINTEGER)
#ELSE
               SQLSetEnvAttr(m_hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL %SQL_OV_ODBC3, %SQL_IS_UINTEGER)
#ENDIF
            END IF
         END IF
      END IF
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Environment methods
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the environment handle
   ' =====================================================================================
   PROPERTY GET Handle () AS DWORD
      PROPERTY = m_hEnv
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current value of a field of a record of the diagnostic data structure
   ' (associated with a specific handle) that contains error, warning, and status information.
   ' =====================================================================================
   METHOD GetDiagField (BYVAL RecNumber AS INTEGER, BYVAL DiagIdentifier AS INTEGER, BYVAL DiagInfoPtr AS DWORD, _
   BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagField(%SQL_HANDLE_ENV, m_hEnv, RecNumber, DiagIdentifier, BYVAL DiagInfoPtr, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
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
      r = SQLGetDiagRec(%SQL_HANDLE_ENV, m_hEnv, RecNumber, Sqlstate, NativeError, MessageText, BufferLength, TextLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   ' Uses SQLGetDiagRec to retrieve an error description.
   ' iErrorCode: Optional. The error code returned by some of the methods of this interface.
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

      iResult = SQLGetDiagField(%SQL_HANDLE_ENV, m_hEnv, 0, %SQL_DIAG_NUMBER, ErrorCount, %SQL_IS_INTEGER, cbbytes)

      IF ErrorCount THEN
         FOR i = 1 TO ErrorCount
            iResult = SQLGetDiagRec(%SQL_HANDLE_ENV, m_hEnv, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
            IF iResult <> %SQL_SUCCESS AND iResult <> %SQL_SUCCESS_WITH_INFO THEN EXIT FOR
            strErrMsg = szErrMsg & $CRLF & "SqlState: " & szSqlState & $CRLF & _
                        "Native error: " & FORMAT$(lNativeError) & $CRLF & szErrMsg
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
   ' Gets the SqlState for the connection handle
   ' =====================================================================================
   PROPERTY GET SqlState () AS STRING
      LOCAL r AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL cbbytes AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_ENV, m_hEnv, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szSqlState
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   ' TRANSACTIONS
   ' #####################################################################################

   ' =====================================================================================
   METHOD CommitTran () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLEndTran(%SQL_HANDLE_ENV, m_hEnv, %SQL_COMMIT)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RollbackTran () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLEndTran(%SQL_HANDLE_ENV, m_hEnv, %SQL_ROLLBACK)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' ENVIRONMENT ATTRIBUTES
   ' #####################################################################################

   ' =====================================================================================
   ' Returns or sets the current setting of an environment attribute.
   ' =====================================================================================
   METHOD GetEnvAttr (BYVAL Attribute AS DWORD, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYVAL StringLength AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetEnvAttr(m_hEnv, Attribute, BYVAL ValuePtr, BufferLength, BYVAL StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetEnvAttr (BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetEnvAttr(m_hEnv, Attribute, BYVAL ValuePtr, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET ConnectionPooling () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetEnvAttr(m_hEnv, %SQL_ATTR_CONNECTION_POOLING, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwAttr
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET CPMatch () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetEnvAttr(m_hEnv, %SQL_ATTR_CP_MATCH, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwAttr
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CPMatch (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetEnvAttr(m_hEnv, %SQL_ATTR_CP_MATCH, BYVAL dwAttr, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET ODBCVersion () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetEnvAttr(m_hEnv, %SQL_ATTR_ODBC_VERSION, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwAttr
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET ODBCVersion (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetEnvAttr(m_hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY GET OutputNTS () AS DWORD
      LOCAL r AS INTEGER
      LOCAL dwAttr AS DWORD
      r = SQLGetEnvAttr(m_hEnv, %SQL_ATTR_OUTPUT_NTS, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = dwAttr
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET OutputNTS (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetEnvAttr(m_hEnv, %SQL_ATTR_OUTPUT_NTS, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                MISCELANEOUS METHODS
   ' #####################################################################################

   ' =====================================================================================
   ' Lists available DSN / Drivers installed.
   ' =====================================================================================
   METHOD DataSources (BYVAL wDirection AS WORD, BYREF strServerName AS STRING, BYREF strDescription AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      LOCAL szServerName AS ASCIIZ * %SQL_MAX_DSN_LENGTH + 1
      LOCAL szDescription AS ASCIIZ * 255
      LOCAL cbServerNameLen AS INTEGER
      LOCAL cbDescription AS INTEGER
      LOCAL cbDescriptionLen AS INTEGER
      r = SQLDataSources(m_hEnv, wDirection, szServerName, SIZEOF(szServerName), cbServerNameLen, szDescription, SIZEOF(szDescription), cbDescriptionLen)
      strServerName = szServerName
      strDescription = szDescription
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Lists driver descriptions and driver attribute keywords. This function is implemented
   ' solely by the driver manager.
   ' =====================================================================================
   METHOD Drivers (BYVAL wDirection AS WORD, BYREF strDriverDesc AS STRING, BYREF strDriverAttributes AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      LOCAL sDriverAttributes AS STRING * 255
      LOCAL szDriverDesc AS ASCIIZ * 255
      LOCAL cbDriverDesc AS INTEGER
      LOCAL cbDrvrAttrLen AS INTEGER
      r = SQLDrivers(m_hEnv, wDirection, szDriverDesc, SIZEOF(szDriverDesc), cbDriverDesc, _
          BYVAL VARPTR(sDriverAttributes), SIZEOF(sDriverAttributes), cbDrvrAttrLen)
      strDriverDesc = szDriverDesc
      REPLACE CHR$(0,0) WITH ";" IN sDriverAttributes
      REPLACE ANY CHR$(0) WITH ";" IN sDriverAttributes
      strDriverAttributes = LEFT$(sDriverAttributes, cbDrvrAttrLen)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbc, "IODBCSTMT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Collection of connections
   ' #####################################################################################

   ' =====================================================================================
   ' Adds a connection to the collection.
   ' =====================================================================================
   METHOD AddConnection (BYVAL bstrKey AS WSTRING, BYVAL vObj AS VARIANT)
      IF ISOBJECT(m_pConnections) THEN m_pConnections.Add(bstrKey, vObj)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes a connection from the collection.
   ' =====================================================================================
   METHOD RemoveConnection (BYVAL bstrKey AS WSTRING)
      IF ISOBJECT(m_pConnections) THEN  m_pConnections.Remove(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a connection from the collection.
   ' =====================================================================================
   METHOD GetConnection (BYVAL bstrKey AS WSTRING) AS VARIANT
      IF ISOBJECT(m_pConnections) THEN METHOD = m_pConnections.Item(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the collection.
   ' =====================================================================================
   METHOD GetConnections () AS IPowerCollection
      METHOD = m_pConnections
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Creation of connections
   ' #####################################################################################

   ' =====================================================================================
   ' Creates a new connection object
   ' =====================================================================================
   METHOD Connection (BYVAL bstrKey AS WSTRING) AS IOdbcConnection
      LOCAL pDbc AS IOdbcConnection
      IF bstrKey = "" THEN EXIT METHOD
      IF ISTRUE m_pConnections.Contains(bstrKey) THEN
         LOCAL vObj AS VARIANT
         vObj = ME.GetConnection(bstrKey)
         pDbc = vObj
         vObj = EMPTY
      ELSE
         pDbc = CLASS "COdbcConnection"
         IF ISOBJECT(pDbc) THEN
            pDbc.AllocConnect(m_hEnv)
            ME.AddConnection(bstrKey, pDbc)
         END IF
      END IF
      METHOD = pDbc
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ========================================================================================
' Creates an instance of the COdbc class and initializes it.
' ========================================================================================
FUNCTION NewOdbc (OPTIONAL BYVAL dwOdbcVersion AS DWORD, BYVAL dwConnectionPoolingAttr AS DWORD) AS IOdbc
   DIM pOdbc AS IOdbc
   pOdbc = CLASS "COdbc"
   pOdbc.Init(dwOdbcVersion, dwConnectionPoolingAttr)
   FUNCTION = pOdbc
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves rich error information.
' For complete accuracy, pass the three parameters. Otherwise, the returned error
' information could belong to a previous call.
' ========================================================================================
FUNCTION OdbcOleErrorInfo (OPTIONAL BYVAL nErrorCode AS LONG) AS WSTRING

   LOCAL bstrMsg AS WSTRING
   LOCAL bstrDescription AS WSTRING
   LOCAL rguid AS GUID
   LOCAL bstrSource AS WSTRING
   LOCAL bstrHelpFile AS WSTRING
   LOCAL dwHelpContext AS DWORD
   LOCAL priid AS DWORD

   IF IErrorInfo_GetErrorInfo(NOTHING, BYVAL %NULL, bstrDescription, bstrSource, rguid, bstrHelpFile, dwHelpContext) = %S_OK THEN
      IF nErrorCode THEN bstrMsg = "SQL error code: " & FORMAT$(nErrorCode) & $CRLF
      IF LEN(bstrSource) THEN bstrMsg += "Source: " & bstrSource & $CRLF
      IF rguid <> $IID_NULL THEN bstrMsg += "GUID: " & GUIDTXT$(rguid) & $CRLF
      IF LEN(bstrDescription) THEN bstrMsg += "Description: " & bstrDescription
   ELSE
      IF nErrorCode THEN bstrMsg = FORMAT$(nErrorCode) & " [&H" & HEX$(nErrorCode, 8) & "] " & OBJRESULT$(nErrorCode)
   END IF
   IF LEN(bstrMsg) = 0 AND nErrorCode <> 0 THEN bstrMsg = "Error code: &H" & HEX$(nErrorCode) & " [" & FORMAT$(nErrorCode) & "]"
   FUNCTION = bstrMsg

END FUNCTION
' ========================================================================================
