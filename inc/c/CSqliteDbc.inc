' #####################################################################################
' Microsoft Windows
' File: CSQLiteDbc.inc
' Contents: SQLite3 wrapper class.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CSQLITEDBC_INC = 1

#INCLUDE ONCE "CSQLite.inc"

$CLSID_CSQLiteConnection = GUID$("{E82ACF27-52B4-421F-ACBD-EAFCCBE8EB95}")
$IID_ISQLiteConnection = GUID$("{70C74CD7-1AB3-466C-9CBD-B606D46B25A4}")

' ========================================================================================
' CSQLiteConnection class.
' ========================================================================================
CLASS CSQLiteConnection $CLSID_CSQLiteConnection

   INSTANCE m_hDbc AS DWORD     ' // Database connection handle

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the connections
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Closes the database connection
      SQLite3_close(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' ISQLite3Connection interface
   ' #####################################################################################

   INTERFACE ISQLiteConnection $IID_ISQLiteConnection : INHERIT IAutomation

   ' =====================================================================================
   ' Opens the database
   ' =====================================================================================
   METHOD OpenDatabase (BYVAL strFileName AS STRING) AS LONG
      LOCAL lRes AS LONG
      IF m_hDbc THEN lRes = ME.CloseDatabase
      IF lRes = %SQLITE_OK THEN lRes = SQLite3_open(BYCOPY strFileName, m_hDbc)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Opens the database
   ' =====================================================================================
   METHOD OpenDatabase2 (BYVAL strFileName AS STRING, BYVAL flags AS LONG, OPTIONAL BYREF zVfs AS ASCIIZ) AS LONG
      LOCAL lRes AS LONG
      IF m_hDbc THEN lRes = ME.CloseDatabase
      IF lRes = %SQLITE_OK THEN lRes = SQLite3_open_v2(BYCOPY strFileName, m_hDbc, flags, zvfs)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Opens the database (Unicode version)
   ' =====================================================================================
   METHOD OpenDatabaseW (BYVAL bstrFileName AS WSTRING) AS LONG
      LOCAL lRes AS LONG
      IF m_hDbc THEN lRes = ME.CloseDatabase
      IF lRes = %SQLITE_OK THEN lRes = sqlite3_open16(BYCOPY bstrFileName, m_hDbc)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the database
   ' =====================================================================================
   METHOD CloseDatabase () AS LONG
      LOCAL lRes AS LONG
      lRes = SQLite3_close(m_hDbc)
      m_hDbc = 0
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the database handle
   ' =====================================================================================
   PROPERTY GET hDbc () AS DWORD
      PROPERTY = m_hDbc
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the database handle
   ' =====================================================================================
   PROPERTY SET hDbc (BYVAL hDbc AS DWORD)
      IF m_hDbc THEN SQLite3_close(m_hDbc)
      m_hDbc = hDbc
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the error code
   ' =====================================================================================
   PROPERTY GET ErrCode () AS LONG
      PROPERTY = SQLite3_errcode(m_hDbc)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Enables/disables extended error codes
   ' Not supported by this class.
   ' =====================================================================================
'   METHOD EnableExtErrCodes (BYVAL onoff AS LONG) AS LONG
'      METHOD = sqlite3_extended_result_codes(m_hDbc, onoff)
'   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the extended error code
   ' =====================================================================================
'   PROPERTY GET ExtErrCode () AS LONG
'      PROPERTY = SQLite3_extended_errcode(m_hDbc)
'   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an English-language description of the error.
   ' =====================================================================================
   PROPERTY GET ErrMsg () AS STRING
      LOCAL pMsg AS ASCIIZ PTR
      pMsg = SQLite3_errmsg(m_hDbc)
      IF pMsg THEN PROPERTY = @pMsg
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an English-language description of the error.
   ' =====================================================================================
   PROPERTY GET ErrMsgW () AS WSTRING
      LOCAL pMsg AS WSTRINGZ PTR
      pMsg = SQLite3_errmsg16(m_hDbc)
      IF pMsg THEN PROPERTY = @pMsg
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Runs zero or more semicolon separated SQL statements.
   ' Callback function prototype:
   ' FUNCTION SQLite_Exec_Callback CDECL(BYVAL pUserData AS DWORD, BYVAL numCols AS LONG, _
   '   BYVAL pszColValues AS ASCIIZ PTR, BYVAL pszColNames AS ASCIIZ PTR) AS LONG
   ' Usage example to retrieve the contents of the pColValues and pColNames arrays:
   ' FOR i = 0 TO numCols - 1
   '    ? "Column name: " & @@pszColNames[i]
   '    ? "Column value: " & @@pszColValues[i]
   ' NEXT
   ' If an sqlite3_exec() callback returns non-zero, the sqlite3_exec() routine returns
   ' SQLITE_ABORT without invoking the callback again and without running any subsequent
   ' SQL statements.
   ' =====================================================================================
   METHOD Exec (BYVAL sql AS STRING, OPTIONAL BYVAL pCallback AS DWORD, BYVAL pData AS DWORD, BYREF ppErrMsg AS DWORD) AS LONG
      LOCAL lRes AS LONG, pErrMsg AS ASCIIZ PTR
      lRes = sqlite3_exec(m_hDbc, BYCOPY sql, pCallback, pData, pErrMsg)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         IF pErrMsg THEN
            OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & @pErrMsg
         ELSE
            OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes)
         END IF
         IF VARPTR(ppErrMsg) THEN
            ppErrMsg = pErrMsg
         ELSE
            sqlite3_free pErrMsg
         END IF
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Used to make configuration changes to a database connection. The method is similar
   ' to Config except that the changes apply to a single database connection.
   ' =====================================================================================
   METHOD DbConfig (BYVAL op AS LONG, OPTIONAL BYVAL prm1 AS DWORD, BYVAL prm2 AS DWORD, BYVAL prm3 AS DWORD, BYVAL prm4 AS DWORD, _
      BYVAL prm5 AS DWORD, BYVAL prm6 AS DWORD, BYVAL prm7 AS DWORD, BYVAL prm8 AS DWORD, BYVAL prm9 AS DWORD, _
      BYVAL prm10 AS DWORD, BYVAL prm11 AS DWORD, BYVAL prm12 AS DWORD, BYVAL prm13 AS DWORD, BYVAL prm14 AS DWORD, _
      BYVAL prm15 AS DWORD, BYVAL prm16 AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_db_config(m_hDbc, op, BYVAL prm1, BYVAL prm2, BYVAL prm3, BYVAL prm4, BYVAL prm5, BYVAL prm6, BYVAL prm7, _
             BYVAL prm8, BYVAL prm8, BYVAL prm10, BYVAL prm11, BYVAL prm12, BYVAL prm13, BYVAL prm14, BYVAL prm15, BYVAL prm16)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a callback function that might be invoked whenever an attempt is made to open a
   ' database table that another thread or process has locked.
   ' =====================================================================================
   METHOD BusyHandler (OPTIONAL BYVAL pBusyCallback AS DWORD, BYVAL pData AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_busy_handler(m_hDbc, pBusyCallback, pData)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a callback function that might be invoked whenever an attempt is made to open a
   ' database table that another thread or process has locked.
   ' =====================================================================================
   METHOD BusyTimeout (BYVAL ms AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_busy_timeout(m_hDbc, ms)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of database rows that were changed or inserted or deleted by the
   ' most recently completed SQL statement.
   ' =====================================================================================
   METHOD Changes () AS LONG
      METHOD = sqlite3_changes(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the filename associated with the sepecified connection.
   ' =====================================================================================
   METHOD DbFilename (BYVAL strDbName AS STRING) AS STRING
      LOCAL pszName AS ASCIIZ PTR
      pszName = sqlite3_db_filename(m_hDbc, BYCOPY strDbName)
      IF pszName THEN METHOD = @pszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the filename associated with the sepecified connection.
   ' =====================================================================================
   METHOD DbMutex () AS DWORD
      METHOD = sqlite3_db_mutex(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns 1 if the specified database of the specified connection is read-only, 0 if it
   ' is read/write, or -1 if is not the name of the database on the specified connection.
   ' =====================================================================================
   METHOD DbReadOnly (BYVAL strDbName AS STRING) AS LONG
      METHOD = sqlite3_db_readonly(m_hDbc, BYCOPY strDbName)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Attempts to free as much heap memory as possible from the specified database connection.
   ' Unlike sqlite3_release_memory, this function is effect even when then SQLITE_ENABLE_MEMORY_MANAGEMENT
   ' compile-time option is omitted.
   ' =====================================================================================
   METHOD DbReleaseMemory () AS LONG
      METHOD = sqlite3_db_release_memory(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves runtime status information about a single database connection.
   ' =====================================================================================
   METHOD DbStatus (BYVAL op AS LONG, BYREF pCur AS LONG, BYREF pHiwtr AS LONG, OPTIONAL BYVAL resetFlag AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_db_status(m_hDbc, op, pCur, pHiwtr, resetFlag)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns non-zero or zero if the given database connection is or is not in autocommit
   ' mode, respectively. Autocommit mode is on by default. Autocommit mode is disabled by
   ' a BEGIN statement. Autocommit mode is re-enabled by a COMMIT or ROLLBACK.
   ' =====================================================================================
   METHOD GetAutoCommit () AS LONG
      METHOD = sqlite3_get_autocommit(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method causes any pending database operation to abort and return at its earliest
   ' opportunity. This routine is typically called in response to a user action such as
   ' pressing "Cancel" or Ctrl-C where the user wants a long query operation to halt immediately.
   ' =====================================================================================
   METHOD Interrupt
      sqlite3_interrupt(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the rowid of the most recent successful INSERT into the database from the
   ' database connection.
   ' =====================================================================================
   METHOD LastInsertRowId () AS QUAD
      METHOD = sqlite3_last_insert_rowid(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method allows the size of various constructs to be limited on a connection by connection basis.
   ' =====================================================================================
   METHOD Limit (BYVAL id AS LONG, BYVAL newVal AS LONG) AS LONG
      METHOD = sqlite3_limit(m_hDbc, id, newVal)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method allows the size of various constructs to be limited on a connection by connection basis.
   ' =====================================================================================
   METHOD ProgressHandler (BYVAL N AS LONG, BYVAL pCallBack AS DWORD, OPTIONAL BYVAL pData AS DWORD)
      sqlite3_progress_handler(m_hDbc, N, pCallBack, pData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Registers an authorizer callback with a particular database connection.
   ' =====================================================================================
   METHOD SetAuthorizer (BYVAL pAuthCallback AS DWORD, OPTIONAL BYVAL pData AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_set_authorizer(m_hDbc, pAuthCallback, pData)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method returns metadata about a specific column of a specific database table
   ' accessible using this database connection handle.
   ' =====================================================================================
   METHOD TableColumnMetadata (BYREF strDbName AS STRING, BYREF strTableName AS STRING, BYREF strColumName AS STRING, _
      OPTIONAL BYREF strDataType AS STRING, BYREF strCollSeq AS STRING, BYREF pNotNull AS LONG, BYREF pPrimaryKey AS LONG, BYREF pAuntoinc AS LONG) AS LONG
      LOCAL lRes AS LONG, pszDbName, pszTableName, pszColumnName, pszDataType, pszCollSeq AS ASCIIZ PTR
      lRes = sqlite3_table_column_metadata(m_hDbc, pszDbName, pszTableName, pszColumnName, pszDataType, pszCollSeq, pNotNull, pPrimaryKey, pAuntoinc)
      IF lRes = %SQLITE_OK THEN
         IF pszDbName AND VARPTR(strDbName) THEN strDbName = @pszDbName
         IF pszTableName AND VARPTR(strTableName) THEN strTableName = @pszTableName
         IF pszColumnName AND VARPTR(strColumName) THEN strColumName = @pszColumnName
         IF pszDataType AND VARPTR(strDataType) THEN strDataType = @pszDataType
         IF pszCollSeq AND VARPTR(strCollSeq) THEN strCollSeq = @pszCollSeq
      END IF
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Causes the callback function X to be invoked periodically during long running calls
   ' to Exec, Step and GetTable methods. An example use for this interface is to keep a
   ' GUI updated during a large query.
   ' =====================================================================================
   METHOD NextStatement (BYVAL pStmt AS ISQLiteStatement) AS DWORD
      IF ISNOTHING(pStmt) THEN EXIT METHOD
      METHOD = sqlite3_next_stmt(m_hDbc, pStmt.hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of row changes caused by INSERT, UPDATE or DELETE statements since
   ' the database connection was opened.
   ' =====================================================================================
   METHOD TotalChanges () AS LONG
      METHOD = sqlite3_total_changes(m_hDbc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' When running in shared-cache mode, a database operation may fail with an SQLITE_LOCKED
   ' error if the required locks on the shared-cache or individual tables within the
   ' shared-cache cannot be obtained. This API may be used to register a callback that
   ' SQLite will invoke when the connection currently holding the required lock relinquishes
   ' it. This API is only available if the library was compiled with the SQLITE_ENABLE_UNLOCK_NOTIFY
   ' C-preprocessor symbol defined.
   ' =====================================================================================
   METHOD UnlockNotify (BYVAL pNotify AS DWORD, BYVAL pNotifyArg AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_unlock_notify(m_hDbc, pNotify, pNotifyArg)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new prepared statement object. Uses the new "v2" interface.
   ' =====================================================================================
   ' =====================================================================================
   METHOD Prepare (BYVAL strSQL AS STRING) AS ISQLiteStatement
      LOCAL lRes AS LONG, ppStmt AS DWORD, pStmt AS ISQLiteStatement
      lRes = sqlite3_prepare_v2(m_hDbc, BYCOPY strSQL, -1, ppStmt, BYVAL 0)
      IF lRes = %SQLITE_OK THEN
         pStmt = CLASS "CSQLiteStatement"
         IF ISOBJECT(pStmt) THEN
            pStmt.hStmt = ppStmt
            pstmt.GetColumnNames
            METHOD = pStmt
         END IF
      END IF
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD PrepareW (BYVAL bstrSQL AS WSTRING) AS ISQLiteStatement
      LOCAL lRes AS LONG, ppStmt AS DWORD, pStmt AS ISQLiteStatement
      lRes = sqlite3_prepare16_v2(m_hDbc, BYCOPY bstrSQL, -1, ppStmt, BYVAL 0)
      IF lRes = %SQLITE_OK THEN
         pStmt = CLASS "CSQLiteStatement"
         IF ISOBJECT(pStmt) THEN
            pStmt.hStmt = ppStmt
            pstmt.GetColumnNames
            METHOD = pStmt
         END IF
      END IF
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method opens a handle to the BLOB located in row qRow, column szColumn, table
   ' szTable in database szDb; in other words, the same BLOB that would be selected by:
   ' SELECT szColumn FROM szDb.szTable WHERE rowid = qRow;
   ' Note that the database name is not the filename that contains the database
   ' but rather the symbolic name of the database that appears after the AS keyword when
   ' the database is connected using ATTACH. For the main database file, the database name
   ' is "main". For TEMP tables, the database name is "temp".
   ' =====================================================================================
'   METHOD BlobOpen (BYVAL strDb AS STRING, BYVAL strTable AS STRING, BYVAL strColumn AS STRING, BYVAL qRow AS QUAD, OPTIONAL BYVAL flags AS LONG) AS DWORD
'      LOCAL ppBlob AS DWORD
'      sqlite3_blob_open(m_hDbc, BYCOPY strDb, BYCOPY strTable, BYCOPY strColumn, qRow, flags, ppBlob)
'      METHOD = ppBlob
'   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BlobOpen (BYVAL strDb AS STRING, BYVAL strTable AS STRING, BYVAL strColumn AS STRING, BYVAL qRow AS QUAD, OPTIONAL BYVAL flags AS LONG) AS ISQLiteBlob
      LOCAL lRes AS LONG, pBlob AS ISQLiteBlob
      pBlob = CLASS "CSQLiteBlob"
      IF ISNOTHING(pBlob) THEN EXIT METHOD
      lRes = pBlob.BlobOpen(m_hDbc, strDb, strTable, strColumn, qRow, flags)
      METHOD = pBlob
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Registers a callback function that can be used for tracing the execution of SQL statements.
   ' =====================================================================================
   METHOD Trace (BYVAL pTraceCallback AS DWORD, BYVAL pData AS DWORD) AS DWORD
      METHOD = sqlite3_trace(m_hDbc, pTraceCallback, pData)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Registers a callback function that can be used for profile the execution of SQL statements.
   ' =====================================================================================
   METHOD Profile (BYVAL pProfileCallback AS DWORD, BYVAL pData AS DWORD) AS DWORD
      METHOD = sqlite3_profile(m_hDbc, pProfileCallback, pData)
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
