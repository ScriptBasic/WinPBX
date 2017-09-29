' #####################################################################################
' Microsoft Windows
' File: CSQLiteStmt.inc
' Contents: SQLite3 wrapper class.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CSQLITESTMT_INC = 1

#INCLUDE ONCE "CSQLite.inc"

$CLSID_CSQLiteStatement = GUID$("{D192455F-E72B-40B5-B7A8-F58F070E1F62}")
$IID_ISQLiteStatement = GUID$("{4EFC1B0E-CE4A-4C37-893D-11E196F405F8}")

' ========================================================================================
' CSQLiteStatement class.
' ========================================================================================
CLASS CSQLiteStatement $CLSID_CSQLiteStatement

   INSTANCE m_hStmt AS DWORD                  ' // Statement handle
   INSTANCE m_pColNames AS IPowerCollection   ' // Collection of column names

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
      ' // Collection of column names
      m_pColNames = CLASS "PowerCollection"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Deletes the prepared statement
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Deletes the prepared statement
      IF m_hStmt THEN sqlite3_finalize(m_hStmt)
      ' // Clears the collection of column names
      IF ISOBJECT(m_pColNames) THEN m_pColNames.Clear
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' ISQLiteStatement interface
   ' #####################################################################################

   INTERFACE ISQLiteStatement $IID_ISQLiteStatement : INHERIT IAutomation

   ' =====================================================================================
   ' Gets an English-language description of the error.
   ' =====================================================================================
   PROPERTY GET ErrMsg () AS STRING
      LOCAL pMsg AS ASCIIZ PTR
      pMsg = SQLite3_errmsg(sqlite3_db_handle(m_hStmt))
      IF pMsg THEN PROPERTY = @pMsg
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an English-language description of the error.
   ' =====================================================================================
   PROPERTY GET ErrMsgW () AS WSTRING
      LOCAL pMsg AS WSTRINGZ PTR
      pMsg = SQLite3_errmsg16(sqlite3_db_handle(m_hStmt))
      IF pMsg THEN PROPERTY = @pMsg
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the statement handle
   ' =====================================================================================
   PROPERTY GET hStmt () AS DWORD
      PROPERTY = m_hStmt
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the statement handle
   ' =====================================================================================
   PROPERTY SET hStmt (BYVAL hStmt AS DWORD)
      IF m_hStmt THEN sqlite3_finalize(m_hStmt)
      m_hStmt = hStmt
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the column names
   ' =====================================================================================
   METHOD GetColumnNames () AS IPowerCollection
      LOCAL i AS LONG, numCols AS LONG, bstrKey AS WSTRING, pszName AS ASCIIZ PTR
      IF m_hStmt = 0 THEN EXIT METHOD
      numCols = sqlite3_column_count(m_hStmt)
      IF numCols = 0 THEN EXIT METHOD
      IF ISNOTHING(m_pColNames) THEN EXIT METHOD
      IF ISOBJECT(m_pColNames) THEN m_pColNames.Clear
      FOR i = 0 TO numCols - 1
         pszName = sqlite3_column_name(m_hStmt, i)
         IF pszName THEN bstrKey = UCASE$(@pszName)
         m_pColNames.Add(bstrKey, i)
      NEXT
      METHOD = m_pColNames
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Return the column index given the column name.
   ' If it succeeds, the return value is the column index (0 is the leftmost column index).
   ' If it fails, it returns -1.
   ' =====================================================================================
   METHOD ColNameToIdx (BYVAL vColName AS VARIANT) AS LONG
      LOCAL vCol AS VARIANT, bstrColName AS WSTRING
      bstrColName = VARIANT$$(vColName)
      IF bstrColName = "" THEN METHOD = -1 : EXIT METHOD
      IF ISNOTHING(m_pColNames) THEN METHOD = -1 : EXIT METHOD
      bstrColName = UCASE$(bstrColName)
      vCol = m_pColNames.Item(bstrColName)
      IF OBJRESULT = %S_FALSE THEN METHOD = -1 : EXIT METHOD
      METHOD = VARIANT#(vCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Deletes the statement
   ' =====================================================================================
   METHOD Finalize () AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_finalize(m_hStmt)
      IF lRes = %SQLITE_OK THEN
         m_hStmt = 0
         ' // Clears the collection of column names
         IF ISOBJECT(m_pColNames) THEN m_pColNames.Clear
      END IF
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resets a prepared statement object back to its initial state, ready to be re-executed.
   ' Any SQL statement variables that had values bound to them using the sqlite3_bind_*()
   ' API retain their values. Use ClearBindings to reset the bindings.
   ' =====================================================================================
   METHOD Reset () AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_reset(m_hStmt)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' After a prepared statement has been prepared using either Prepare2 or Prepare2W, this
   ' this method must be called one or more times to evaluate the statement. The use of
   ' the new "v2" interface is recommended for new applications.
   ' =====================================================================================
   METHOD Step () AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_step(m_hStmt)
      METHOD = lRes
      IF lRes <> %SQLITE_OK AND lRes <> %SQLITE_ROW AND lRes <> %SQLITE_DONE THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a blob with the statement.
   ' The leftmost SQL parameter has an index of 1.
   ' =====================================================================================
   METHOD BindBlob (BYVAL idx AS LONG, BYVAL pValue AS DWORD, BYVAL numBytes AS LONG, OPTIONAL BYVAL pDestructor AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_blob(m_hStmt, idx, pValue, numBytes, pDestructor)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a double value with the statement.
   ' The leftmost SQL parameter has an index of 1.
   ' =====================================================================================
   METHOD BindDouble (BYVAL idx AS LONG, BYVAL dblValue AS DOUBLE) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_double(m_hStmt, idx, dblValue)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a long integer value with the statement.
   ' The leftmost SQL parameter has an index of 1.
   ' =====================================================================================
   METHOD BindLong (BYVAL idx AS LONG, BYVAL longValue AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_int(m_hStmt, idx, longValue)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a quad value with the statement.
   ' The leftmost SQL parameter has an index of 1.
   ' =====================================================================================
   METHOD BindQuad (BYVAL idx AS LONG, BYVAL quadValue AS QUAD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_int64(m_hStmt, idx, quadValue)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a null value with the statement.
   ' The leftmost SQL parameter has an index of 1.
   ' =====================================================================================
   METHOD BindNull (BYVAL idx AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_null(m_hStmt, idx)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method actually returns the index of the largest (rightmost) parameter. For all
   ' forms except ?NNN, this will correspond to the number of unique parameters. If parameters
   ' of the ?NNN form are used, there may be gaps in the list.
   ' =====================================================================================
   METHOD BindParameterCount () AS LONG
      METHOD = sqlite3_bind_parameter_count(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the index of an SQL parameter given its name. The index value returned is
   ' suitable for use as the second parameter to the Bind_* methods. A zero is returned if
   ' no matching parameter is found.
   ' =====================================================================================
   METHOD BindParameterIndex (BYVAL strName AS STRING) AS LONG
      METHOD = sqlite3_bind_parameter_index(m_hStmt, BYCOPY strName)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the name of the specified SQL parameter in the prepared statement.
   ' =====================================================================================
   METHOD BindParameterName (BYVAL idx AS LONG) AS STRING
      LOCAL pszName AS ASCIIZ PTR
      pszName = sqlite3_bind_parameter_name(m_hStmt, idx)
      IF pszName THEN METHOD = @pszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a text value with the statement.
   ' =====================================================================================
   METHOD BindText (BYVAL idx AS LONG, BYVAL strValue AS STRING, OPTIONAL BYVAL pDestructor AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_text(m_hStmt, idx, BYCOPY strValue, LEN(strValue), pDestructor)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds an unicode text value with the statement.
   ' =====================================================================================
   METHOD BindTextW (BYVAL idx AS LONG, BYVAL bstrValue AS WSTRING, OPTIONAL BYVAL pDestructor AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_text16(m_hStmt, idx, BYCOPY bstrValue, LEN(bstrValue), pDestructor)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds an arbitrary value with the statement.
   ' =====================================================================================
   METHOD BindValue (BYVAL idx AS LONG, BYVAL pValue AS DWORD) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_value(m_hStmt, idx, BYVAL pValue)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Binds a BLOB of length numBytes that is filled with zeroes.
   ' =====================================================================================
   METHOD BindZeroBlob (BYVAL idx AS LONG, BYVAL numBytes AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_bind_zeroblob(m_hStmt, idx, numBytes)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets all the parameters in the compiled SQL statement to NULL. Contrary to the intuition
   ' of many, sqlite3_reset does not reset the bindings on a prepared statement. Use this
   ' routine to reset all host parameters to NULL.
   ' =====================================================================================
   METHOD ClearBindings () AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_clear_bindings(m_hStmt)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITESTATEMENT." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a pointer to a blob.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnBlob (BYVAL vCol AS VARIANT) AS ISQLiteBlob
      LOCAL hBlob AS DWORD, lRes AS LONG, pBlob AS ISQLiteBlob, nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      hBlob = sqlite3_column_blob(m_hStmt, nCol)
      IF hBlob THEN
         pBlob = CLASS "CSQLiteBlob"
         pBlob.hBlob = hBlob
         METHOD = pBlob
      ELSE
         lRes = sqlite3_errcode(sqlite3_db_handle(m_hStmt))
         IF lRes THEN
            METHOD OBJRESULT = &H80004005&
            OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITECONNECTION." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW
         END IF
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of bytes of the column value.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnBytes (BYVAL vCol AS VARIANT) AS LONG
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_bytes(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of bytes of the column value.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnBytesW (BYVAL vCol AS VARIANT) AS LONG
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_bytes16(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of columns in the result set.
   ' =====================================================================================
   METHOD ColumnCount () AS LONG
      METHOD = sqlite3_column_count(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the database name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnDatabaseName (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszDbName AS ASCIIZ PTR
      pszDbName = sqlite3_column_database_name(m_hStmt, nCol)
      IF pszDbName THEN METHOD = @pszDbName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the database name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnDatabaseNameW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszDbName AS WSTRINGZ PTR
      pwszDbName = sqlite3_column_database_name16(m_hStmt, nCol)
      IF pwszDbName THEN METHOD = @pwszDbName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the database name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnDeclaredType (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszDeclType AS ASCIIZ PTR
      pszDeclType = sqlite3_column_decltype(m_hStmt, nCol)
      IF pszDeclType THEN METHOD = @pszDeclType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the database name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnDeclaredTypeW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszDeclType AS WSTRINGZ PTR
      pwszDeclType = sqlite3_column_decltype16(m_hStmt, nCol)
      IF pwszDeclType THEN METHOD = @pwszDeclType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a double.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnDouble (BYVAL vCol AS VARIANT) AS DOUBLE
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_double(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a long.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnLong (BYVAL vCol AS VARIANT) AS LONG
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_int(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a quad.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnQuad (BYVAL vCol AS VARIANT) AS QUAD
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_int64(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the name assigned to a particular column in the result set of a SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnName (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszName AS ASCIIZ PTR
      pszName = sqlite3_column_name(m_hStmt, nCol)
      IF pszName THEN METHOD = @pszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the name assigned to a particular column in the result set of a SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnNameW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszName AS WSTRINGZ PTR
      pwszName = sqlite3_column_name16(m_hStmt, nCol)
      IF pwszName THEN METHOD = @pwszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnOriginName (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszName AS ASCIIZ PTR
      pszName = sqlite3_column_origin_name(m_hStmt, nCol)
      IF pszName THEN METHOD = @pszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnOriginNameW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszName AS ASCIIZ PTR
      pwszName = sqlite3_column_origin_name16(m_hStmt, nCol)
      IF pwszName THEN METHOD = @pwszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the table name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnTableName (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszName AS ASCIIZ PTR
      pszName = sqlite3_column_table_name(m_hStmt, nCol)
      IF pszName THEN METHOD = @pszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the table name that is the origin of a particular result column in SELECT statement.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnTableNameW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszName AS ASCIIZ PTR
      pwszName = sqlite3_column_table_name16(m_hStmt, nCol)
      IF pwszName THEN METHOD = @pwszName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a UTF-8 string.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnText (BYVAL vCol AS VARIANT) AS STRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pszText AS ASCIIZ PTR
      pszText = sqlite3_column_text(m_hStmt, nCol)
      IF pszText THEN METHOD = @pszText
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column value as a UTF-16 string.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnTextW (BYVAL vCol AS VARIANT) AS WSTRING
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      LOCAL pwszText AS ASCIIZ PTR
      pwszText = sqlite3_column_text16(m_hStmt, nCol)
      IF pwszText THEN METHOD = @pwszText
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column type.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnType (BYVAL vCol AS VARIANT) AS LONG
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_type(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns column value as a pointer to an unprotected sqlite3_value object.
   ' The leftmost column of the result set has the index 0.
   ' =====================================================================================
   METHOD ColumnValue (BYVAL vCol AS VARIANT) AS DWORD
      LOCAL nCol AS LONG
      IF VARIANTVT(vCol) = %VT_BSTR THEN
         nCol = ME.ColNameToIdx(vCol)
         IF nCol = -1 THEN EXIT METHOD
      ELSE
         nCol = VARIANT#(vCol)
      END IF
      METHOD = sqlite3_column_value(m_hStmt, nCol)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of columns in the result set returned by the prepared statement.
   ' This methods returns 0 if pStmt is an SQL statement that does not return data (for example an UPDATE).
   ' =====================================================================================
   METHOD DataCount () AS LONG
      METHOD = sqlite3_data_count(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the database connection handle to which a prepared statement belongs.
   ' =====================================================================================
   METHOD DbHandle () AS DWORD
      METHOD = sqlite3_db_handle(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a saved copy of the original SQL text used to create a prepared statement if
   ' that statement was compiled using either Prepare2 or Prepare2W.
   ' =====================================================================================
   METHOD SQL () AS STRING
      LOCAL pszText AS ASCIIZ PTR
      pszText = sqlite3_sql(m_hStmt)
      IF pszText THEN METHOD = @pszText
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns true (non-zero) if the prepared statement has been stepped at least once
   ' using Step but has not run to completion and/or has not been reset using Reset.
   ' The StatementBusy method returns false if the statement handle is a NULL pointer.
   ' =====================================================================================
   METHOD StatementBusy () AS LONG
      METHOD = sqlite3_stmt_busy(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns true (non-zero) if and only if the prepared statement makes no direct changes
   ' to the content of the database file.
   ' =====================================================================================
   METHOD StatementReadOnly () AS LONG
      METHOD = sqlite3_stmt_readonly(m_hStmt)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method is used to retrieve and reset counter values from a prepared statement.
   ' =====================================================================================
   METHOD StatementStatus (BYVAL op AS LONG, OPTIONAL BYVAL resetFlag AS LONG) AS LONG
      METHOD = sqlite3_stmt_status(m_hStmt, op, resetFlag)
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ========================================================================================
