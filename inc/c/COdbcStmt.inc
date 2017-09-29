' #####################################################################################
' Microsoft Windows
' File: COdbcStmt.inc
' Contents: ODBC statement class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CODBCSTMT_INC = 1

#INCLUDE ONCE "ODBC.INC"

$CLSID_COdbcStatement = GUID$("{67535891-95D2-4056-8404-DA0458135F52}")
$IID_IOdbcStatement = GUID$("{4A676737-470E-4921-AE0B-0129EF0E62C3}")

CLASS COdbcStatement $CLSID_COdbcStatement

   INSTANCE m_hStmt AS DWORD                  ' // Connection handle
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
   ' Closes the cursor and frees the statement handle
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hStmt THEN
         SQLCloseCursor(m_hStmt)
         SQLFreeHandle(%SQL_HANDLE_STMT, m_hStmt)
      END IF
      ' // Clears the collection of column names
      IF ISOBJECT(m_pColNames) THEN m_pColNames.Clear
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   INTERFACE IOdbcStatement $IID_IOdbcStatement : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the statement handle
   ' =====================================================================================
   PROPERTY GET Handle () AS DWORD
      PROPERTY = m_hStmt
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the current value of a field of a record of the diagnostic data structure
   ' (associated with a specific handle) that contains error, warning, and status information.
   ' =====================================================================================
   METHOD GetDiagField (BYVAL RecNumber AS INTEGER, BYVAL DiagIdentifier AS INTEGER, BYVAL DiagInfo AS DWORD, _
   BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetDiagField(%SQL_HANDLE_STMT, m_hStmt, RecNumber, DiagIdentifier, BYVAL DiagInfo, BufferLength, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
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
      r = SQLGetDiagRec(%SQL_HANDLE_STMT, m_hStmt, RecNumber, Sqlstate, NativeError, MessageText, BufferLength, TextLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
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

      iResult = SQLGetDiagField(%SQL_HANDLE_STMT, m_hStmt, 0, %SQL_DIAG_NUMBER, ErrorCount, %SQL_IS_INTEGER, cbbytes)

      IF ErrorCount THEN
         FOR i = 1 TO ErrorCount
            iResult = SQLGetDiagRec(%SQL_HANDLE_STMT, m_hStmt, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
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
   ' Gets the SqlState for the descriptor handle
   ' =====================================================================================
   PROPERTY GET SqlState () AS STRING
      LOCAL r AS INTEGER
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL cbbytes AS INTEGER
      r = SQLGetDiagRec(%SQL_HANDLE_STMT, m_hStmt, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = szSqlState
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Allocates an statement handle
   ' =====================================================================================
   METHOD AllocStmt (BYVAL hDbc AS DWORD) AS DWORD
      LOCAL r AS INTEGER
      IF m_hStmt THEN
         SQLCloseCursor(m_hStmt)
         SQLFreeHandle(%SQL_HANDLE_STMT, m_hStmt)
         m_hStmt = %NULL
      END IF
      r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, m_hStmt)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = m_hStmt
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves data for a single column in the result set.
   ' =====================================================================================
   METHOD GetData (BYVAL vColumn AS VARIANT, BYVAL TargetType AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_Ind AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      LOCAL ColumnNumber AS WORD
      IF VARIANTVT(vColumn) = %VT_BSTR THEN
         LOCAL bstrKey AS WSTRING
         bstrKey = UCASE$(VARIANT$(vColumn))
         LOCAL vCol AS VARIANT
         IF ISNOTHING(m_pColNames) THEN EXIT METHOD
         vCol = m_pColNames.Item(bstrKey)
         ColumnNumber = VARIANT#(vCol)
      ELSE
         ColumnNumber = VARIANT#(vColumn)
      END IF
      r = SQLGetData(m_hStmt, ColumnNumber, TargetType, TargetValue, BufferLength, StrLen_or_Ind)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the data in a specefied column as a string.
   ' =====================================================================================
   METHOD GetDataString (BYVAL vColumn AS VARIANT, OPTIONAL BYVAL lMaxChars AS LONG) AS STRING
      LOCAL r AS INTEGER, ColumnNumber AS WORD, s AS STRING, cbLen AS LONG
      IF VARIANTVT(vColumn) = %VT_BSTR THEN
         LOCAL bstrKey AS WSTRING
         bstrKey = UCASE$(VARIANT$(vColumn))
         LOCAL vCol AS VARIANT
         IF ISNOTHING(m_pColNames) THEN EXIT METHOD
         vCol = m_pColNames.Item(bstrKey)
         ColumnNumber = VARIANT#(vCol)
      ELSE
         ColumnNumber = VARIANT#(vColumn)
      END IF
      IF lMaxChars < 1 THEN lMaxChars = 256
      s = SPACE$(lMaxChars + 1)  ' Make room for the null character
      r = SQLGetData(m_hStmt, ColumnNumber, %SQL_C_CHAR, BYVAL STRPTR(s), LEN(s), cbLen)
      IF cbLen <> %SQL_NULL_DATA THEN METHOD = LEFT$(s, cbLen)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Reads long variable char data
   ' =====================================================================================
   METHOD GetLongVarcharData (BYVAL vColumn AS VARIANT) AS STRING

      LOCAL r AS INTEGER
      LOCAL cbMemo AS LONG
      LOCAL MemoBuf AS ASCIIZ * 32769         ' 32 Kb buffer + CHR$(0)
      LOCAL s AS STRING
      LOCAL szSqlState AS ASCIIZ * 6
      LOCAL lNativeError AS LONG
      LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
      LOCAL cbbytes AS INTEGER
      LOCAL ColumnNumber AS WORD

      IF VARIANTVT(vColumn) = %VT_BSTR THEN
         LOCAL bstrKey AS WSTRING
         bstrKey = UCASE$(VARIANT$(vColumn))
         LOCAL vCol AS VARIANT
         IF ISNOTHING(m_pColNames) THEN EXIT METHOD
         vCol = m_pColNames.Item(bstrKey)
         ColumnNumber = VARIANT#(vCol)
      ELSE
         ColumnNumber = VARIANT#(vColumn)
      END IF

      DO
         r = SQLGetData(m_hStmt, ColumnNumber, %SQL_C_CHAR, MemoBuf, 32769, cbMemo)
         IF r = %SQL_SUCCESS THEN                  ' We have reall all the content
            s = s & MemoBuf
            EXIT DO
         ELSEIF r = %SQL_SUCCESS_WITH_INFO THEN
            r = SQLGetDiagRec(%SQL_HANDLE_STMT, m_hStmt, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
            IF r <> %SQL_SUCCESS THEN EXIT DO      ' Error in SQLGetDiagRec
            IF szSqlState = "01004" THEN           ' Insufficient buffer
               s = s & MemoBuf
               ITERATE
            ELSE                                   ' Error
               EXIT DO
            END IF
         ELSE                                      ' Error
            IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
               METHOD OBJRESULT = r
               OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
            END IF
         END IF
      LOOP

      IF INSTR(s, CHR$(13,10)) THEN s = EXTRACT$(s, CHR$(13,10))
      METHOD = s

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Checks if the column is null.
   ' Note: Should not be used with a column that is currently binded to a variable or
   ' buffer or it will return an error. The binding functions already return an
   ' indicator in the last parameter.
   ' =====================================================================================
   PROPERTY GET ColIsNull (BYVAL wCol AS WORD) AS INTEGER
      LOCAL r AS INTEGER, ind AS LONG, sz AS ASCIIZ * 256
      r = SQLGetData(m_hStmt, wCol, %SQL_C_CHAR, BYVAL VARPTR(sz), SIZEOF(sz), ind)
      IF SQL_SUCCEEDED(r) THEN
         IF ind = %SQL_NULL_DATA THEN PROPERTY = %TRUE
      ELSE
         IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
            PROPERTY OBJRESULT = r
            OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
         END IF
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Allows an application to send data for a parameter or column to the driver at
   ' statement execution time
   ' =====================================================================================
   METHOD PutData (BYVAL DataPtr AS DWORD, BYVAL StrLen_or_Ind AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLPutData(m_hStmt, BYVAL DataPtr, StrLen_or_Ind)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Used in conjuntion with PutData to supply parameter data at statement
   ' execution time.
   ' =====================================================================================
   METHOD ParamData (BYREF ValuePtrPtr AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLParamData(m_hStmt, ValuePtrPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases all parameter buffers set by BindParameter for the given statement handle.
   ' =====================================================================================
   METHOD ResetParams () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFreeStmt (m_hStmt, %SQL_RESET_PARAMS)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Prepares an SQL string for execution.
   ' =====================================================================================
   METHOD Prepare (BYVAL StatementText AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLPrepare(m_hStmt, BYVAL STRPTR(StatementText), LEN(StatementText))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Executes a prepared statement, using the current values of the parameter marker
   ' variables if any parameter markers exist in the statement.
   ' =====================================================================================
   METHOD Execute () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLExecute(m_hStmt)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
      ' // Clear the collection of column names
      IF ISNOTHING(m_pColNames) THEN EXIT METHOD
      IF m_pColNames.Count THEN m_pColNames.Clear
      ' // Retrieve the column names
      LOCAL i AS LONG, NumCols, colNameLen AS INTEGER
      LOCAL szColName AS ASCIIZ * 255, bstrKey AS WSTRING
      IF SQL_SUCCEEDED(r) THEN
         r = SQLNumResultCols(m_hStmt, NumCols)
         IF NumCols < 1 THEN EXIT METHOD
         FOR i = 1 TO NumCols
            r = SQLColAttribute(m_hStmt, i, %SQL_DESC_NAME, szColName, SIZEOF(szColName), colNameLen, BYVAL %NULL)
            IF SQL_SUCCEEDED(r) = 0 THEN EXIT FOR
            bstrKey = UCASE$(LEFT$(szColName, colNameLen))
            m_pColNames.Add(bstrKey, i)
         NEXT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Executes the specified statement.
   ' =====================================================================================
   METHOD ExecDirect (BYVAL SqlStr AS STRING) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLExecDirect (m_hStmt, BYCOPY SqlStr, LEN(SqlStr))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
      ' // Clear the collection of column names
      IF ISNOTHING(m_pColNames) THEN EXIT METHOD
      IF m_pColNames.Count THEN m_pColNames.Clear
      ' // Retrieve the column names
      LOCAL i AS LONG, NumCols, colNameLen AS INTEGER
      LOCAL szColName AS ASCIIZ * 255, bstrKey AS WSTRING
      IF SQL_SUCCEEDED(r) THEN
         r = SQLNumResultCols(m_hStmt, NumCols)
         IF NumCols < 1 THEN EXIT METHOD
         FOR i = 1 TO NumCols
            r = SQLColAttribute(m_hStmt, i, %SQL_DESC_NAME, szColName, SIZEOF(szColName), colNameLen, BYVAL %NULL)
            IF SQL_SUCCEEDED(r) = 0 THEN EXIT FOR
            bstrKey = UCASE$(LEFT$(szColName, colNameLen))
            m_pColNames.Add(bstrKey, i)
         NEXT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of records in the result set.
   ' Uses an instruction like SqlStr = "SELECT COUNT(*) FROM Customers".
   ' =====================================================================================
   METHOD RecordCount (BYVAL SqlStr AS STRING) AS LONG
      LOCAL r AS INTEGER, rcount AS LONG, NumCols AS INTEGER
      r = SQLExecDirect (m_hStmt, BYCOPY SqlStr, LEN(SqlStr))
      IF SQL_SUCCEEDED(r) THEN
         r = SQLNumResultCols(m_hStmt, NumCols)
         IF SQL_SUCCEEDED(r) THEN
            IF NumCols = 0 THEN EXIT METHOD
            r = SQLFetch(m_hStmt)
            IF SQL_SUCCEEDED(r) = 0 THEN EXIT METHOD
            r = SQLGetData(m_hStmt, 1, %SQL_C_LONG, rcount, 0, BYVAL %NULL)
            IF SQL_SUCCEEDED(r) = 0 THEN EXIT METHOD
         END IF
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = rcount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of rows affected by an UPDATE, INSERT, or DELETE statement; an
   ' SQL_ADD, SQL_UPDATE_BY_BOOKMARK or SQL_DELETE_BY_BOOKMARK operation in
   ' BulkOperations; or an SQL_UPDATE or SQL_DELETE operation in SetPos.
   ' =====================================================================================
   PROPERTY GET RowCount () AS LONG
      LOCAL r AS INTEGER, rcount AS LONG
      r = SQLRowCount(m_hStmt, rcount)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = rcount
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Cancels the processing on a statement.
   ' =====================================================================================
   METHOD Cancel () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLCancel(m_hStmt)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of columns of the result set.
   ' =====================================================================================
   METHOD NumResultCols () AS INTEGER
      LOCAL r, NumCols AS INTEGER
      r = SQLNumResultCols(m_hStmt, NumCols)
      METHOD = NumCols
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the result descriptor --column name, type, column size, decimal
   ' digits, and nullability-- for one column in the result set. This information
   ' also is available in the fields of the IRD.
   ' =====================================================================================
   METHOD DescribeCol (BYVAL ColNumber AS WORD, BYREF ColName AS STRING, BYREF DataType AS INTEGER, _
   BYREF ColSize AS DWORD, BYREF DecimalDigits AS INTEGER, BYREF Nullable AS INTEGER) AS INTEGER
      LOCAL r, NameLength AS INTEGER, szColName AS ASCIIZ * 255
      r = SQLDescribeCol(m_hStmt, ColNumber, szColName, SIZEOF(szColName), NameLength, DataType, ColSize, DecimalDigits, Nullable)
      ColName = szColName
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether more results are available on a statement containing SELECT,
   ' UPDATE, INSERT, or DELETE statements and, if so, initializes processing for those
   ' results.
   ' =====================================================================================
   METHOD MoreResults () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLMoreResults(m_hStmt)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of parameters in an SQL statement.
   ' =====================================================================================
   METHOD NumParams () AS INTEGER
      LOCAL r AS INTEGER
      LOCAL pcpar AS INTEGER
      r = SQLNumParams(m_hStmt, pcpar)
      METHOD = pcpar
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the description of a parameter marker associated with a prepared SQL
   ' statement. This information is also available in the fields of the IRD.
   ' =====================================================================================
   METHOD DescribeParam (BYVAL ipar AS WORD, pfSqlType AS INTEGER, pfcbParamDef AS DWORD, pibScale AS INTEGER, pfNullable AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLDescribeParam(m_hStmt, ipar, pfSqlType, pfcbParamDef, pibScale, pfNullable)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' BINDING
   ' #####################################################################################

   ' =====================================================================================
   ' Binds application data buffers to columns in the result set.
   ' =====================================================================================
   METHOD BindCol (BYVAL ColNumber AS INTEGER, BYVAL TargetType AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_Ind AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, TargetType, BYVAL TargetValue, BufferLength, StrLen_or_Ind)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An INTEGER variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToBit (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS INTEGER, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_BIT, TargetValue, 1, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A BYTE variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToByte (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS BYTE, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_TINYINT, TargetValue, 3, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An ASCIIZ * 22 string is used to bind the column.
   ' =====================================================================================
   METHOD BindColToNumeric (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ * 22, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_CHAR, TargetValue, 21, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An ASCIIZ * 22 string is used to bind the column.
   ' =====================================================================================
   METHOD BindColToDecimal (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ * 22, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_CHAR, TargetValue, 21, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An ASCIIZ string is used to bind the column.
   ' =====================================================================================
   METHOD BindColToString (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS ASCIIZ, BYVAL BufferLenght AS LONG, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_CHAR, TargetValue, BufferLenght, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
'   ' =====================================================================================

   ' =====================================================================================
   ' A memory buffer is used to bind the column.
   ' =====================================================================================
   METHOD BindColToBinary (BYVAL ColNumber AS INTEGER, BYVAL TargetValue AS DWORD, BYVAL BufferLenght AS LONG, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_BINARY, TargetValue, BufferLenght, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' An INTEGER variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToInteger (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS INTEGER, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_SSHORT, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A WORD variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToWord (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS WORD, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_USHORT, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A LONG variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToLong (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS LONG, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_LONG, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A DWORD variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToDword (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DWORD, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_ULONG, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A SINGLE variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToSingle (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS SINGLE, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_FLOAT, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A DOUBLE variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToDouble (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DOUBLE, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_DOUBLE, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A QUAD variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToQuad (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS QUAD, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_SBIGINT, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A DOUBLE variable is used to bind the column.
   ' =====================================================================================
   METHOD BindColToCurrency (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DOUBLE, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_DOUBLE, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A DATE_STRUCT structure is used to bind the column.
   ' =====================================================================================
   METHOD BindColToDate (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS DATE_STRUCT, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_DATE, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A TIME_STRUCT structure is used to bind the column.
   ' =====================================================================================
   METHOD BindColToTime (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS TIME_STRUCT, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_TIME, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' A TIMESTAMP_STRUCT structure is used to bind the column.
   ' =====================================================================================
   METHOD BindColToTimeStamp (BYVAL ColNumber AS INTEGER, BYREF TargetValue AS TIMESTAMP_STRUCT, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol(m_hStmt, ColNumber, %SQL_C_TIMESTAMP, TargetValue, 0, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases the specified column buffer for the given statement handle.
   ' =====================================================================================
   METHOD UnbindCol (BYVAL iCol AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindCol (m_hStmt, iCol, %SQL_C_DEFAULT, BYVAL %NULL, 0, BYVAL %NULL)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases all column buffers bound to the specified statement handle.
   ' =====================================================================================
   METHOD UnbindColumns () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFreeStmt (m_hStmt, %SQL_UNBIND)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' BindParam binds a buffer to a parameter marker in a SQL statement. Supports
   ' binding to a Unicode C data type, even if the underlying driver does not
   ' support Unicode data.
   ' =====================================================================================
   METHOD BindParameter (BYVAL ParameterNumber AS WORD, BYVAL InputOutputType AS INTEGER, BYVAL ValueType AS INTEGER, BYVAL ParameterType AS INTEGER, _
   BYVAL ColumnSize AS DWORD, BYVAL DecimalDigits AS INTEGER, BYVAL ParameterValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StrLen_or_IndPtr AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBindParameter(m_hStmt, ParameterNumber, InputOutputType, ValueType, ParameterType, ColumnSize, DecimalDigits, BYVAL ParameterValuePtr, BufferLength, StrLen_or_IndPtr)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' COLUMN ATTRIBUTES
   ' #####################################################################################

   ' =====================================================================================
   ' ColAttribute returns descriptor information for a column in a result set. Descriptor
   ' information is returned as a character string, a 32-bit descriptor-dependent value, or
   ' an integer value.
   ' =====================================================================================
   METHOD ColAttribute (BYVAL ColumnNumber AS WORD, BYVAL FieldIdentifier AS WORD, BYVAL CharacterAttribute AS DWORD, _
   BYVAL BufferLength AS INTEGER, BYREF StringLength AS INTEGER, BYVAL NumericAttribute AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLColAttribute(m_hStmt, ColumnNumber, FieldIdentifier, CharacterAttribute, BufferLength, StringLength, NumericAttribute)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns %SQL_TRUE if the column is an autoincrementing column, %SQL_FALSE if the column
   ' is not an autoincrementing column or is not numeric.
   ' =====================================================================================
   PROPERTY GET ColAutoUniqueValue (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_AUTO_UNIQUE_VALUE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The base column name for the result set column. If a base column name does not exist
   ' (as in the case of columns that are expressions), then this variable contains an empty
   ' string.
   ' =====================================================================================
   PROPERTY GET ColBaseColumnName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_BASE_COLUMN_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The name of the base table that contains the column. If the base table name cannot be
   ' defined or is not applicable, then this variable contains an empty string.
   ' =====================================================================================
   PROPERTY GET ColBaseTableName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_BASE_TABLE_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns %SQL_TRUE if the column is treated as case-sensitive for collations and
   ' comparisons.
   ' =====================================================================================
   PROPERTY GET ColCaseSensitive (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_CASE_SENSITIVE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The catalog of the table that contains the column. The returned value is
   ' implementation-defined if the column is an expression or if the column is part of a
   ' view. If the data source does not support catalogs or the catalog name cannot be
   ' determined, an empty string is returned. This VARCHAR record field is not limited to
   ' 128 characters.
   ' =====================================================================================
   PROPERTY GET ColCatalogName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_CATALOG_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns The concise data type.
   ' For the datetime and interval data types, this field returns the concise data type; for
   ' example, %SQL_TYPE_TIME or %SQL_INTERVAL_YEAR.
   ' =====================================================================================
   PROPERTY GET ColConciseType (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_CONCISE_TYPE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The number of columns available in the result set. This returns 0 if there are no
   ' columns in the result set. The value in the ColumnNumber argument is ignored.
   ' =====================================================================================
   PROPERTY GET ColCount () AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, 0, %SQL_DESC_COUNT, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Maximum number of characters required to display data from the column.
   ' =====================================================================================
   PROPERTY GET ColDisplaySize (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_DISPLAY_SIZE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns %SQL_TRUE if the column has a fixed precision and nonzero scale that are data
   ' source-specific.
   ' Returns %SQL_FALSE if the column does not have a fixed precision and nonzero scale that
   ' are data source-specific.
   ' =====================================================================================
   PROPERTY GET ColFixedPrecScale (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_FIXED_PREC_SCALE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The column label or title. For example, a column named EmpName might be labeled
   ' Employee Name or might be labeled with an alias.
   ' If a column does not have a label, the column name is returned. If the column is
   ' unlabeled and unnamed, an empty string is returned.
   ' =====================================================================================
   PROPERTY GET ColLabel (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_LABEL, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A numeric value that is either the maximum or actual character length of a character
   ' string or binary data type. It is the maximum character length for a fixed-length data
   ' type, or the actual character length for a variable-length data type. Its value always
   ' excludes the null-termination byte that ends the character string.
   ' =====================================================================================
   PROPERTY GET ColLength (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_LENGTH, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' This VARCHAR(128) record field contains the character or characters that the driver
   ' recognizes as a prefix for a literal of this data type.
   ' This field contains an empty string for a data type for which a literal prefix is not
   ' applicable.
   ' =====================================================================================
   PROPERTY GET ColLiteralPrefix (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 129, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_LITERAL_PREFIX, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' This VARCHAR(128) record field contains the character or characters that the driver
   ' recognizes as a suffix for a literal of this data type.
   ' This field contains an empty string for a data type for which a literal suffix is not
   ' applicable.
   ' =====================================================================================
   PROPERTY GET ColLiteralSuffix (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 129, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_LITERAL_SUFFIX, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' This VARCHAR(128) record field contains any localized (native language) name for the
   ' data type that may be different from the regular name of the data type. If there is no
   ' localized name, then an empty string is returned. This field is for display purposes
   ' only. The character set of the string is locale-dependent and is typically the default
   ' character set of the server.
   ' =====================================================================================
   PROPERTY GET ColLocalTypeName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 129, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_LOCAL_TYPE_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The column alias, if it applies. If the column alias does not apply, the column name is
   ' returned. In either case, %SQL_DESC_UNNAMED is set to %SQL_NAMED. If there is no column
   ' name or a column alias, an empty string is returned and %SQL_DESC_UNNAMED is set to
   ' %SQL_UNNAMED.
   ' =====================================================================================
   PROPERTY GET ColName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns %SQL_ NULLABLE if the column can have NULL values; %SQL_NO_NULLS if the column
   ' does not have NULL values; or %SQL_NULLABLE_UNKNOWN if it is not known whether the
   ' column accepts NULL values.
   ' =====================================================================================
   PROPERTY GET ColNullable (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_NULLABLE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' If the data type in the %SQL_DESC_TYPE field is an approximate numeric data type, this
   ' SQLINTEGER field contains a value of 2 because the %SQL_DESC_PRECISION field contains
   ' the number of bits.
   ' If the data type in the %SQL_DESC_TYPE field is an exact numeric data type, this field
   ' contains a value of 10 because the %SQL_DESC_PRECISION field contains the number of
   ' decimal digits.
   ' This field is set to 0 for all non-numeric data types.
   ' =====================================================================================
   PROPERTY GET ColNumPrecRadix (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_NUM_PREC_RADIX, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The length, in bytes, of a character string or binary data type. For fixed-length
   ' character or binary types, this is the actual length in bytes. For variable-length
   ' character or binary types, this is the maximum length in bytes. This value includes the
   ' null terminator.
   ' =====================================================================================
   PROPERTY GET ColOctetLength (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_OCTET_LENGTH, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A numeric value that for a numeric data type denotes the applicable precision. For data
   ' types %SQL_TYPE_TIME, %SQL_TYPE_TIMESTAMP, and all the interval data types that
   ' represent a time interval, its value is the applicable precision of the fractional
   ' seconds component.
   ' =====================================================================================
   PROPERTY GET ColPrecision (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_PRECISION, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A numeric value that is the applicable scale for a numeric data type.
   ' For DECIMAL and NUMERIC data types, this is the defined scale. It is undefined for all
   ' other data types.
   ' =====================================================================================
   PROPERTY GET ColScale (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_SCALE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The schema of the table that contains the column. The returned value is implementation-
   ' defined if the column is an expression or if the column is part of a view. If the data
   ' source does not support schemas or the schema name cannot be determined, an empty string
   ' is returned. This VARCHAR record field is not limited to 128 characters.
   ' =====================================================================================
   PROPERTY GET ColSchemaName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_SCHEMA_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' %SQL_PRED_NONE if the column cannot be used in a WHERE clause. (This is the same as the
   ' %SQL_UNSEARCHABLE value in ODBC 2.x.)
   ' %SQL_PRED_CHAR if the column can be used in a WHERE clause but only with the LIKE
   ' predicate. (This is the same as the SQL_LIKE_ONLY value in ODBC 2.x.)
   ' %SQL_PRED_BASIC if the column can be used in a WHERE clause with all the comparison
   ' operators except LIKE. (This is the same as the %SQL_EXCEPT_LIKE value in ODBC 2.x.)
   ' %SQL_PRED_SEARCHABLE if the column can be used in a WHERE clause with any comparison
   ' operator.
   ' Columns of type SQL_LONGVARCHAR and %SQL_LONGVARBINARY usually return %SQL_PRED_CHAR.
   ' =====================================================================================
   PROPERTY GET ColSearchable (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_SEARCHABLE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The name of the table that contains the column. The returned value is implementation-
   ' defined if the column is an expression or if the column is part of a view.
   ' If the table name cannot be determined, an empty string is returned.
   ' =====================================================================================
   PROPERTY GET ColTableName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_TABLE_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A numeric value that specifies the SQL data type.
   ' When ColumnNumber is equal to 0, %SQL_BINARY is returned for variable-length bookmarks
   ' and %SQL_INTEGER is returned for fixed-length bookmarks.
   ' For the datetime and interval data types, this field returns the verbose data type:
   ' %SQL_DATETIME or %SQL_INTERVAL.
   ' This information is returned from the %SQL_DESC_TYPE record field of the IRD.
   ' Note: To work against ODBC 2.x drivers, use %SQL_DESC_CONCISE_TYPE instead.
   ' =====================================================================================
   PROPERTY GET ColType (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_TYPE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Data source-dependent data type name; for example, "CHAR", "VARCHAR", "MONEY",
   ' "LONG VARBINARY", or "CHAR ( ) FOR BIT DATA".
   ' If the type is unknown, an empty string is returned.
   ' =====================================================================================
   PROPERTY GET ColTypeName (BYVAL ColNum AS INTEGER) AS STRING
      LOCAL r AS INTEGER, szCharAttr AS ASCIIZ * 255, CharAttrLen AS INTEGER
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_TYPE_NAME, szCharAttr, SIZEOF(szCharAttr), CharAttrLen, BYVAL %NULL)
      PROPERTY = szCharAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' %SQL_NAMED or %SQL_UNNAMED. If the %SQL_DESC_NAME field of the IRD contains a column
   ' alias or a column name, %SQL_NAMED is returned. If there is no column name or column
   ' alias, %SQL_UNNAMED is returned.
   ' =====================================================================================
   PROPERTY GET ColUnnamed (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_UNNAMED, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' %SQL_TRUE if the column is unsigned (or not numeric).
   ' %SQL_FALSE if the column is signed.
   ' =====================================================================================
   PROPERTY GET ColUnsigned (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_UNSIGNED, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' SQL_TRUE if the column is updatable; SQL_FALSE otherwise.
   ' =====================================================================================
   PROPERTY GET ColUpdatable (BYVAL ColNum AS INTEGER) AS LONG
      LOCAL r AS INTEGER, lAttr AS LONG
      r = SQLColAttribute(m_hStmt, ColNum, %SQL_DESC_UPDATABLE, BYVAL %NULL, 0, BYVAL %NULL, lAttr)
      PROPERTY = lAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   ' CURSOR RELATED METHODS
   ' #####################################################################################

   ' =====================================================================================
   ' Closes the cursor associated with m_hStmt (if one was defined) and discards all pending
   ' reults. Returns SQLSTATE 24000 (Invalid cursor state) if no cursor is open in the statement.
   ' =====================================================================================
   METHOD CloseCursor () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLCloseCursor(m_hStmt)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the cursor name associated with a specified statement.
   ' =====================================================================================
   PROPERTY GET CursorName () AS STRING
      LOCAL r AS INTEGER, szCurName AS ASCIIZ * 65
      r = SQLGetCursorName(m_hStmt, szCurName, SIZEOF(szCurName), BYVAL %NULL)
      PROPERTY = szCurName
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Associates a cursor name with an active statement.
   ' =====================================================================================
   PROPERTY SET CursorName (BYVAL strCurName AS STRING)
      LOCAL r AS INTEGER, szCurName AS ASCIIZ * 65
      szCurName = strCurName
      r = SQLSetCursorName(m_hStmt, szCurName, %SQL_NTS)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Fetches the next rowset of data from the result set and returns data for all bound columns.
   ' =====================================================================================
   METHOD Fetch () AS INTEGER
      LOCAL r AS INTEGER
      r = SqlFetch(m_hStmt)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fetches the specified rowset of data from the result set and returns data for all
   ' bound columns. Rowsets can be specified at an absolute position or by bookmark.
   ' =====================================================================================
   METHOD FetchScroll (BYVAL FetchOrientation AS WORD, BYVAL FetchOffset AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SqlFetchScroll(m_hStmt, FetchOrientation, FetchOffset)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fetches the specified rowset of data from the result set and returns data for all
   ' bound columns. Rowsets can be specified at an absolute or relative position or
   ' by bookmark.
   ' NOTE: Since the called function, ExtendedFetch, has been deprecated and replaced by
   ' FetchScroll, users must use the FetchScroll method instead of this one.
   ' =====================================================================================
   METHOD ExtendedFetch (BYVAL FetchOrientation AS WORD, BYVAL FetchOffset AS LONG, BYREF RowCountPtr AS DWORD, BYVAL RowStatusArray AS DWORD)  AS INTEGER
      LOCAL r AS INTEGER
      r = SQLExtendedFetch(m_hStmt, FetchOrientation, FetchOffset, RowCountPtr, BYVAL RowStatusArray)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the first rowset in the result set.
   ' =====================================================================================
   METHOD MoveFirst () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_FIRST, 0)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the last rowset in the result set.
   ' =====================================================================================
   METHOD MoveLast () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_LAST, 0)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the next rowset.
   ' =====================================================================================
   METHOD MoveNext () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_NEXT, 0)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the prior rowset.
   ' =====================================================================================
   METHOD MovePrevious () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_PRIOR, 0)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Moves the cursor forward or backward FetchOffset rowsets.
   ' =====================================================================================
   METHOD Move (BYVAL FetchOffset AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_RELATIVE, FetchOffset)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the rowset starting at row FetchOffset.
   ' =====================================================================================
   METHOD SetAbsolutePosition (BYVAL FetchOffset AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_ABSOLUTE, FetchOffset)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the rowset FetchOffset from the start of the current rowset.
   ' =====================================================================================
   METHOD SetRelativePosition (BYVAL FetchOffset AS LONG) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLFetchScroll(m_hStmt, %SQL_FETCH_RELATIVE, FetchOffset)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cursor position in a rowset.
   ' =====================================================================================
   METHOD SetPos (BYVAL wRow AS WORD, BYVAL fOption AS WORD, BYVAL fLock AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SqlSetPos(m_hStmt, wRow, fOption, fLock)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cursor position in a rowset.
   ' =====================================================================================
   METHOD SetPosition (BYVAL wRow AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetPos(m_hStmt, wRow, %SQL_POSITION, %SQL_LOCK_NO_CHANGE)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The driver positions the cursor in the row specified by RowNumber and updates the
   ' underlying row of data with the values in the rowset buffers (the TargetValuePtr
   ' argument in BindCol). It retrieves the lengths of the data from the length
   ' indicator buffers (the StrLen_or_IndPtr argument in BindCol). If the length of
   ' any column is SQL_COLUMN_IGNORE, the column is not updated. After updating the row,
   ' the driver changes the corresponding element of the row status array to
   ' SQL_ROW_UPDATED or SQL_ROW_ACCESS_WITH_INFO (if the row status array exists).
   ' Note: irow is the row number inside the rowset (if the rowset has only one row, then
   ' irow must be always 1).
   ' =====================================================================================
   METHOD UpdateRecord (OPTIONAL BYVAL wRow AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      IF wRow = 0 THEN wRow = 1
      r = SQLSetPos(m_hStmt, wRow, %SQL_UPDATE, %SQL_LOCK_NO_CHANGE)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cursor position in a rowset and allows to refresh data in the rowset.
   ' =====================================================================================
   METHOD RefreshRecord (OPTIONAL BYVAL wRow AS WORD, BYVAL fLock AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      IF wRow = 0 THEN wRow = 1
      IF fLock = 0 THEN fLock = %SQL_LOCK_NO_CHANGE
      r = SQLSetPos(m_hStmt, wRow, %SQL_REFRESH, fLock)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cursor position in a rowset and locks the record.
   ' =====================================================================================
   METHOD LockRecord (OPTIONAL BYVAL wRow AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      IF wRow = 0 THEN wRow = 1
      r = SQLSetPos(m_hStmt, wRow, %SQL_POSITION, %SQL_LOCK_EXCLUSIVE)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cursor position in a rowset and unlocks the record.
   ' =====================================================================================
   METHOD UnlockRecord (OPTIONAL BYVAL wRow AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      IF wRow = 0 THEN wRow = 1
      r = SQLSetPos(m_hStmt, wRow, %SQL_POSITION, %SQL_LOCK_UNLOCK)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The driver positions the cursor on the row specified by RowNumber and deletes the
   ' underlying row of data. It changes the corresponding element of the row status array
   ' to SQL_ROW_DELETED. After the row has been deleted, the following are not valid for
   ' the row: positioned update and delete statements, calls to GetData and calls to
   ' SetPos with Operation set to anything except SQL_POSITION. For drivers that support
   ' packing, the row is deleted from the cursor when new data is retrieved from the data
   ' source. Whether the row remains visible depends on the cursor type. For example,
   ' deleted rows are visible to static and keyset-driven cursors but invisible to dynamic
   ' cursors.
   ' The row operation array pointed to by the SQL_ATTR_ROW_OPERATION_PTR statement
   ' attribute can be used to indicate that a row in the current rowset should be ignored
   ' during a bulk delete.
   ' Note: irow is the row number inside the rowset (if it is a single row rowset, irow
   ' must be always 1).
   ' =====================================================================================
   METHOD DeleteRecord (OPTIONAL BYVAL wRow AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      IF wRow = 0 THEN wRow = 1
      r = SQLSetPos(m_hStmt, wRow, %SQL_DELETE, %SQL_LOCK_NO_CHANGE)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Performs bulk insertions and bulk bookmark operations, including update, delete, and
   ' fetch by bookmark.
   ' Operation:
   '   %SQL_ADD
   '   %SQL_UPDATE_BY_BOOKMARK
   '   %SQL_DELETE_BY_BOOKMARK
   '   %SQL_FETCH_BY_BOOKMARK
   ' =====================================================================================
   METHOD BulkOperations (BYVAL Operation AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBulkOperations(m_hStmt, Operation)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a record in the the database
   ' =====================================================================================
   METHOD AddRecord () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBulkOperations(m_hStmt, %SQL_ADD)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates a set of rows where each row os identified by a bookmark.
   ' =====================================================================================
   METHOD UpdateByBookmark () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBulkOperations(m_hStmt, %SQL_UPDATE_BY_BOOKMARK)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Deletes a set of rows where each row os identified by a bookmark.
   ' =====================================================================================
   METHOD DeleteByBookmark () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBulkOperations(m_hStmt, %SQL_DELETE_BY_BOOKMARK)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fetches a set of rows where each row os identified by a bookmark.
   ' =====================================================================================
   METHOD FetchByBookmark () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLBulkOperations(m_hStmt, %SQL_FETCH_BY_BOOKMARK)
      METHOD = SQL_SUCCEEDED(r)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' STATEMENT ATTRIBUTES
   ' #####################################################################################

   ' =====================================================================================
   ' Returns the current setting of a statement attribute.
   ' =====================================================================================
   METHOD GetStmtAttr (BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYVAL StringLength AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetStmtAttr(m_hStmt, Attribute, BYVAL ValuePtr, BufferLength, BYVAL StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the current setting of a statement attribute.
   ' =====================================================================================
   METHOD SetStmtAttr (BYVAL Attribute AS LONG, BYVAL ValuePtr AS DWORD, BYVAL StringLength AS DWORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, Attribute, BYVAL ValuePtr, StringLength)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or returns an integer value that specifies the cursor concurrency.
   '   %SQL_CONCUR_READ_ONLY = Cursor is read-only. No updates are allowed.
   '   %SQL_CONCUR_LOCK = Cursor uses the lowest level of locking sufficient to ensure that
   '      the row can be updated.
   '   %SQL_CONCUR_ROWVER = Cursor uses optimistic concurrency control, comparing row
   '      versions such as SQLBase ROWID or Sybase TIMESTAMP.
   '   %SQL_CONCUR_VALUES = Cursor uses optimistic concurrency control, comparing values.
   ' The default attribute is %SQL_CONCUR_READ_ONLY. This attribute cannot be specified for
   ' an open cursor.
   ' =====================================================================================
   PROPERTY GET CursorConcurrency () AS DWORD
      LOCAL r AS INTEGER, CursorConcurrency AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, CursorConcurrency, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = CursorConcurrency
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CursorConcurrency (BYVAL LockType AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL LockType, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetOptimisticConcurrency () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_VALUES, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetLockConcurrency () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_LOCK, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetReadOnlyConcurrency () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_READ_ONLY, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetRowVerConcurrency () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_ROWVER, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or returns a LONG value that specifies the cursor type:
   '   %SQL_CURSOR_FORWARD_ONLY = The cursor only scrolls forward.
   '   %SQL_CURSOR_STATIC = The data in the result set is static.
   '   %SQL_CURSOR_KEYSET_DRIVEN = The driver saves and uses only the keys for the number
   '     of rows specified in the %SQL_ATTR_KEYSET_SIZE statement attribute.
   '   %SQL_CURSOR_DYNAMIC = The driver saves and uses only the keys for the rows in the
   '     rowset.
   ' The default value is %SQL_FORWARD_ONLY. This attribute cannot be specified after the
   '     SQL statement has been prepared.
   ' The application can specify the cursor type before executing a statement that creates a
   ' result set. It does this with the %SQL_ATTR_CURSOR_TYPE statement attribute. If the
   ' application does not explicitly specify a type, a forward-only cursor will be used.
   ' To get a mixed cursor, an application specifies a keyset-driven cursor but declares a
   ' keyset size less than the result set size.
   ' Note: Microsoft Access Driver changes %SQL_CURSOR_DYNAMIC to %SQL_CURSOR_KEYSET_DRIVEN.
   ' =====================================================================================
   PROPERTY GET CursorType () AS DWORD
      LOCAL r AS INTEGER, CursorType AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, CursorType, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = CursorType
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CursorType (BYVAL CursorType AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL CursorType, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetForwardOnlyCursor () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_FORWARD_ONLY, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetKeysetDrivenCursor () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_KEYSET_DRIVEN, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetStaticCursor () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_STATIC, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetDynamicCursor () AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_DYNAMIC, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or returns LONG value that specifies the number of rows in the keyset-driven cursor.
   ' If the keyset size is 0 (the default), the cursor is fully keyset-driven.
   ' If the keyset size is greater than 0, the cursor is mixed (keyset-driven within the
   ' keyset and dynamic outside of the keyset). The default keyset size is 0. Fetch or
   ' FetchScroll returns an error if the keyset size is greater than 0 and less than the
   ' rowset size.
   ' For keyset-driven and mixed cursors, the application can specify the keyset size. It
   ' does this with the %SQL_ATTR_KEYSET_SIZE statement attribute. If the keyset size is set
   ' to 0, which is the default, the keyset size is set to the result size and a
   ' keyset-driven cursor is used. The keyset size can be changed after the cursor has been
   ' opened.
   ' =====================================================================================
   PROPERTY GET CursorKeysetSize () AS DWORD
      LOCAL r AS INTEGER, KeysetSize AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_KEYSET_SIZE, KeysetSize, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = KeysetSize
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CursorKeysetSize (BYVAL KeysetSize AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_KEYSET_SIZE, BYVAL KeysetSize, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or returns a LONG value that specifies the level of support that the application
   ' requires. Setting this attribute affects subsequent calls to ExecDirect and Execute.
   '    %SQL_NONSCROLLABLE = Scrollable cursors are not required on the statement handle. If
   '      the application calls FetchScroll on this handle, the only value of
   '      FetchOrientation is %SQL_FETCH_NEXT. This is the default.
   '    %SQL_SCROLLABLE = Scrollable cursors are required on the statement handle. When
   '      calling FetchScroll the application may specify any valid value of
   '      FetchOrientation, achieving cursor positioning in modes other than the sequential
   '      mode.
   ' Note: Optional function not implemented in Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET CursorScrollability () AS DWORD
      LOCAL r AS INTEGER, CursorScrollability AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_SCROLLABLE, CursorScrollability, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = CursorScrollability
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CursorScrollability (BYVAL CursorScrollability AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_SCROLLABLE, BYVAL CursorScrollability, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets or returns a LONG value that specifies whether cursors on the statement handle
   ' made to a result set by another cursor. Setting this attribute affects subsequent
   ' calls to ExecDirect and Execute. An application can read back the value of this
   ' attribute to obtain its initial state or its state as most recently set by the application.
   '   %SQL_UNSPECIFIED = It is unspecified what the cursor type is and whether cursors on
   '      the statement handle make visible the changes made to a result set by another
   '      cursor. Cursors on the statement handle may make visible none, some, or all such
   '      changes. This is the default.
   '   %SQL_INSENSITIVE = All cursors on the statement handle show the result set without
   '      reflecting any changes made to it by any other cursor, which has a concurrency that
   '      is read-only.
   '   %SQL_SENSITIVE = All cursors on the statement handle make visible all changes made to
   '      a result set by another cursor.
   ' Note: Optional functions not implemented in Microsoft Access Driver.
   ' =====================================================================================
   PROPERTY GET CursorSensitivity () AS DWORD
      LOCAL r AS INTEGER, CursorSensitivity AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_SENSITIVITY, CursorSensitivity, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = CursorSensitivity
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET CursorSensitivity (BYVAL CursorSensitivity AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_SENSITIVITY, BYVAL CursorSensitivity, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a multiuser keyset cursor.
   ' =====================================================================================
   METHOD SetMultiuserKeysetCursor (OPTIONAL BYVAL CursorName AS STRING) AS INTEGER
      LOCAL r AS INTEGER, szCurName AS ASCIIZ * 65
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_KEYSET_DRIVEN, BYVAL %NULL)
      IF SQL_SUCCEEDED(r) THEN
         r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_VALUES, BYVAL %NULL)
         IF SQL_SUCCEEDED(r) THEN
            szCurName = TRIM$(CursorName)
            IF LEN(szCurName) THEN r = SQLSetCursorName(m_hStmt, szCurName, %SQL_NTS)
         END IF
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The handle to the APD for subsequent calls to Execute and ExecDirect on the
   ' statement handle. The initial value of this attribute is the descriptor implicitly
   ' allocated when the statement was initially allocated.
   ' If the value of this attribute is set to SQL_NULL_DESC or the handle originally
   ' allocated for the descriptor, an explicitly allocated APD handle that was previously
   ' associated with the statement handle is dissociated from it and the statement handle
   ' reverts to the implicitly allocated APD handle.
   ' This attribute cannot be set to a descriptor handle that was implicitly allocated for
   ' another statement or to another descriptor handle that was implicitly set on the same
   ' statement; implicitly allocated descriptor handles cannot be associated with more than
   ' one statement or descriptor handle.
   ' =====================================================================================
   PROPERTY GET StmtAppParamDesc () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_APP_PARAM_DESC, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtAppParamDesc (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_APP_PARAM_DESC, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The handle to the ARD for subsequent fetches on the statement handle. The initial value
   ' of this attribute is the descriptor implicitly allocated when the statement was
   ' initially allocated. If the value of this attribute is set to SQL_NULL_DESC or the
   ' handle originally allocated for the descriptor, an explicitly allocated ARD handle that
   ' was previously associated with the statement handle is dissociated from it and the
   ' statement handle reverts to the implicitly allocated ARD handle.
   ' This attribute cannot be set to a descriptor handle that was implicitly allocated for
   ' another statement or to another descriptor handle that was implicitly set on the same
   ' statement; implicitly allocated descriptor handles cannot be associated with more than
   ' one statement or descriptor handle.
   ' =====================================================================================
   PROPERTY GET StmtAppRowDesc () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_APP_ROW_DESC, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtAppRowDesc (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_APP_ROW_DESC, BYVAL dwAttr, BYVAL %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that specifies whether a function called with the specified
   ' statement is executed asynchronously:
   '   SQL_ASYNC_ENABLE_OFF = Off (the default)
   '   SQL_ASYNC_ENABLE_ON = On
   ' =====================================================================================
   PROPERTY GET StmtAsyncEnable () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ASYNC_ENABLE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtAsyncEnable (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ASYNC_ENABLE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' A pointer that points to a binary bookmark value. When FetchScroll is called with
   ' fFetchOrientation equal to SQL_FETCH_BOOKMARK, the driver picks up the bookmark value
   ' from this field. This field defaults to a null pointer.
   ' The value pointed to by this field is not used for delete by bookmark, update by
   ' bookmark, or fetch by bookmark operations in BulkOperations, which use bookmarks
   ' cached in rowset buffers.
   ' =====================================================================================
   PROPERTY GET StmtFetchBookmarkPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_FETCH_BOOKMARK_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtFetchBookmarkPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_FETCH_BOOKMARK_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The handle to the IPD. The value of this attribute is the descriptor allocated when the
   ' statement was initially allocated. The application cannot set this attribute.
   ' This attribute can be retrieved by a call to GetStmtAttr but not set by a call to
   ' SetStmtAttr.
   ' =====================================================================================
   PROPERTY GET StmtImpParamDesc () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' ImpParamDescRec (Implicitily Parameter Descriptor).
   ' Returns the current settings or values of multiple fields of a descriptor record. The
   ' fields returned describe the name, data type, and storage of column or parameter data.
   ' - m_hStmt : Statement handle
   ' - RecNumber : Indicates the descriptor record from which the application seeks information.
   ' Descriptor records are numbered from 1, with record number 0 being the bookmark record.
   ' The RecNumber argument must be less or equal to the value of %SQL_DESC_COUNT. If RecNumber
   ' is less that or equal to %SQL_DESC_COUNT but the row does not contain data for a column or
   ' parameter, a call to GetImpRowDesc will return the default values of the fields.
   ' =====================================================================================
   METHOD GetImpParamDescRec (BYVAL RecNumber AS INTEGER, _
   BYREF strName AS STRING, BYREF StringLength AS INTEGER, BYREF nType AS INTEGER, _
   BYREF nSubType AS INTEGER, BYREF nLength AS LONG, BYREF nPrecision AS INTEGER, _
   BYREF nScale AS INTEGER, BYREF nNullable AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF SQL_SUCCEEDED(r) THEN
         LOCAL szName AS ASCIIZ * 255
         r = SQLGetDescRec(hIpd, RecNumber, szName, SIZEOF(szName), StringLength, nType, _
                           nSubType, nLength, nPrecision, nScale, nNullable)
         IF r = %SQL_SUCCESS OR r = %SQL_SUCCESS_WITH_INFO THEN strName = szName
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescField (BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, _
   BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF SQL_SUCCEEDED(r) THEN
         r = SQLGetDescField(hIpd, RecNumber, FieldIdentifier, BYVAL ValuePtr, BufferLength, StringLength)
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldName (BYVAL RecNumber AS INTEGER) AS STRING
      LOCAL r AS INTEGER, hIpd AS DWORD, szName AS ASCIIZ * 256, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_NAME, BYVAL VARPTR(szName), SIZEOF(szName), StringLength)
      METHOD = szName
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldType (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nType AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_TYPE, BYVAL VARPTR(nType), %SQL_IS_SMALLINT, StringLength)
      METHOD = nType
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldOctetLength (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nOctetLength AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_OCTET_LENGTH, BYVAL VARPTR(nOctetLength), %SQL_IS_SMALLINT, StringLength)
      METHOD = nOctetLength
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldPrecision (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nPrecision AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_PRECISION, BYVAL VARPTR(nPrecision), %SQL_IS_SMALLINT, StringLength)
      METHOD = nPrecision
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldScale (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nScale AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_SCALE, BYVAL VARPTR(nScale), %SQL_IS_SMALLINT, StringLength)
      METHOD = nScale
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   METHOD GetImpParamDescFieldNullable (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nNullable AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_PARAM_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_NULLABLE, BYVAL VARPTR(nNullable), %SQL_IS_SMALLINT, StringLength)
      METHOD = nNullable
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' The handle to the IRD. The value of this attribute is the descriptor allocated when the
   ' statement was initially allocated. The application cannot set this attribute.
   ' This attribute can be retrieved by a call to GetStmtAttr but not set by a call to
   ' SetStmtAttr.
   ' ========================================================================================
   METHOD GetStmtImpRowDesc () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      METHOD = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' ========================================================================================

   ' =====================================================================================
   ' ImpRowDescRec (Implicitily Row Descriptor).
   ' Returns the current settings or values of multiple fields of a descriptor record. The fields
   ' returned describe the name, data type, and storage of column or parameter data.
   ' m_hStmt : Statement handle
   ' RecNumber : Indicates the descriptor record from which the application seeks information.
   ' Descriptor records are numbered from 1, with record number 0 being the bookmark record.
   ' The RecNumber argument must be less or equal to the value of %SQL_DESC_COUNT. If RecNumber
   ' is less that or equal to %SQL_DESC_COUNT but the row does not contain data for a column or
   ' parameter, a call to GetImpRowDesc will return the default values of the fields.
   ' =====================================================================================
   METHOD GetImpRowDescRec (BYVAL RecNumber AS INTEGER, _
   BYREF strName AS STRING, BYREF StringLength AS INTEGER, BYREF nType AS INTEGER, _
   BYREF nSubType AS INTEGER, BYREF nLength AS LONG, BYREF nPrecision AS INTEGER, _
   BYREF nScale AS INTEGER, BYREF nNullable AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF SQL_SUCCEEDED(r) THEN
         LOCAL szName AS ASCIIZ * 255
         r = SQLGetDescRec(hIpd, RecNumber, szName, SIZEOF(szName), StringLength, nType, _
                           nSubType, nLength, nPrecision, nScale, nNullable)
         IF r = %SQL_SUCCESS OR r = %SQL_SUCCESS_WITH_INFO THEN strName = szName
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescField (BYVAL RecNumber AS INTEGER, BYVAL FieldIdentifier AS INTEGER, _
      BYVAL ValuePtr AS DWORD, BYVAL BufferLength AS LONG, BYREF StringLength AS LONG) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF SQL_SUCCEEDED(r) THEN
         r = SQLGetDescField(hIpd, RecNumber, FieldIdentifier, BYVAL ValuePtr, BufferLength, StringLength)
      END IF
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldName (BYVAL RecNumber AS INTEGER) AS STRING
      LOCAL r AS INTEGER, hIpd AS DWORD, szName AS ASCIIZ * 256, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_NAME, BYVAL VARPTR(szName), SIZEOF(szName), StringLength)
      METHOD = szName
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldType (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nType AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_TYPE, BYVAL VARPTR(nType), %SQL_IS_SMALLINT, StringLength)
      METHOD = nType
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldOctetLength (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nOctetLength AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_OCTET_LENGTH, BYVAL VARPTR(nOctetLength), %SQL_IS_SMALLINT, StringLength)
      METHOD = nOctetLength
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldPrecision (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nPrecision AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_PRECISION, BYVAL VARPTR(nPrecision), %SQL_IS_SMALLINT, StringLength)
      METHOD = nPrecision
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldScale (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nScale AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_SCALE, BYVAL VARPTR(nScale), %SQL_IS_SMALLINT, StringLength)
      METHOD = nScale
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD GetImpRowDescFieldNullable (BYVAL RecNumber AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER, hIpd AS DWORD, nNullable AS INTEGER, StringLength AS LONG
      ' Gets the handle of the IPD (implicitily allocated descriptor).
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
      IF ISFALSE hIpd THEN EXIT METHOD
      r = SQLGetDescField(hIpd, RecNumber, %SQL_DESC_NULLABLE, BYVAL VARPTR(nNullable), %SQL_IS_SMALLINT, StringLength)
      METHOD = nNullable
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtMaxLength () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_MAX_LENGTH, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtMaxLength (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_MAX_LENGTH, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtMaxRows () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_MAX_ROWS, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtMaxRows (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_MAX_ROWS, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtNoScan () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_NOSCAN, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      PROPERTY = r
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtNoScan (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_NOSCAN, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamBindOffsetPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_PARAM_BIND_OFFSET_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamBindOffsetPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAM_BIND_OFFSET_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamBindType () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_PARAM_BIND_TYPE, dwAttr, %SQL_IS_UINTEGER, %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamBindType (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAM_BIND_TYPE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamOperationPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_PARAM_OPERATION_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamOperationPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAM_OPERATION_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamsProcessedPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_PARAMS_PROCESSED_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamsProcessedPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAMS_PROCESSED_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamsetSize () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_PARAMSET_SIZE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamsetSize (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAMSET_SIZE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtQueryTimeout () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_QUERY_TIMEOUT, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtQueryTimeout (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_QUERY_TIMEOUT, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRetrieveData () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_RETRIEVE_DATA, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRetrieveData (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_RETRIEVE_DATA, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtParamStatusPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetStmtAttr(m_hStmt, %SQL_ATTR_PARAM_STATUS_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtParamStatusPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_PARAM_STATUS_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowArraySize () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_ARRAY_SIZE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowArraySize (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROW_ARRAY_SIZE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowBindOffsetPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_BIND_OFFSET_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowBindOffsetPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROW_BIND_OFFSET_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowBindType () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_BIND_TYPE, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowBindType (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROW_BIND_TYPE, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' An SQLUINTEGER value that is the number of the current row in the entire result set.
   ' If the number of the current row cannot be determined or there is no current row, the
   ' driver returns 0.
   ' This attribute can be retrieved by a call to GetStmtAttr but not set by a call to
   ' SetStmtAttr.
   ' Note: Microsoft Access Driver returns 0.
   ' =====================================================================================
   PROPERTY GET StmtRowNumber () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_NUMBER, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowOperationPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_OPERATION_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowOperationPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROW_OPERATION_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowStatusPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROW_STATUS_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowStatusPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROW_STATUS_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtRowsFetchedPtr () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_ROWS_FETCHED_PTR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtRowsFetchedPtr (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_ROWS_FETCHED_PTR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtSimulateCursor () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_SIMULATE_CURSOR, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtSimulateCursor (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_SIMULATE_CURSOR, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   PROPERTY GET StmtUseBookmarks () AS DWORD
      LOCAL r AS INTEGER, dwAttr AS DWORD
      r = SQLGetstmtAttr(m_hStmt, %SQL_ATTR_USE_BOOKMARKS, dwAttr, %SQL_IS_UINTEGER, BYVAL %NULL)
      PROPERTY = dwAttr
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET StmtUseBookmarks (BYVAL dwAttr AS DWORD)
      LOCAL r AS INTEGER
      r = SQLSetStmtAttr(m_hStmt, %SQL_ATTR_USE_BOOKMARKS, BYVAL dwAttr, %SQL_IS_UINTEGER)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         PROPERTY OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
   END PROPERTY
   ' =====================================================================================

   ' #####################################################################################
   '                                MISCELANEOUS METHODS
   ' #####################################################################################

   ' =====================================================================================
   ' Retrieves a list of statistics about a single table and the indexes associated with
   ' the table. The driver returns the information as a result set on the specified
   ' statement handle.
   ' =====================================================================================
   METHOD Statistics (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ, BYVAL wUnique AS WORD, BYVAL wCardinality AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLStatistics(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName), wUnique, wCardinality)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the list of column names in specified tables. The driver returns this
   ' information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD Columns (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ, BYREF szColumnName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLColumns(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName), szColumnName, LEN(szColumnName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns information about data types supported by the data source. The driver returns
   ' the information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD GetTypeInfo (BYVAL DataType AS INTEGER) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLGetTypeInfo (m_hStmt, DataType)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the list of table, catalog, or schema names, and table types, stored in a
   ' specific data source. The driver returns the information as a result set on the
   ' specified statement handle.
   ' =====================================================================================
   METHOD Tables (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ, BYREF szTableType AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLTables(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName), szTableType, LEN(szTableType))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a list of tables and the privileges associated with each table. The driver
   ' returns the information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD TablePrivileges (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLTablePrivileges(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the column names that make up the primary key for a table. This function does
   ' not support returning primary keys from multiple tables in a single call. The driver
   ' returns the information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD PrimaryKeys (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLPrimaryKeys(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the list of procedure names stored in a specific data source. Procedure is a
   ' generic term used to describe an executable object, or a named entity that can be
   ' invoked using input and output parameters. The driver returns the information as a
   ' result set on the specified statement handle.
   ' =====================================================================================
   METHOD Procedures (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szProcName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLProcedures(m_hStmt, szCatalogName, LEN(szCatalogName), szSchemaName, LEN(szSchemaName), szProcName, LEN(szProcName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the following information about columns within a specified table.
   ' The driver returns the information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD SpecialColumns (BYVAL wIdentifierType AS WORD, BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, _
   BYREF szTableName AS ASCIIZ, BYVAL wScope AS WORD, BYVAL wNullable AS WORD) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLSpecialColumns(m_hStmt, wIdentifierType, szCatalogName, LEN(szCatalogName), _
          szSchemaName, LEN(szSchemaName), szTableName, LEN (szTableName), wScope, wNullable)
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a list of columns and associated privileges for the specified table. The
   ' driver returns the information as a result set on the specified statement handle.
   ' =====================================================================================
   METHOD ColumnPrivileges (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szTableName AS ASCIIZ, BYREF szColumnName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLColumnPrivileges(m_hStmt, szCatalogName, LEN(szCatalogName), _
          szSchemaName, LEN(szSchemaName), szTableName, LEN(szTableName), _
          szColumnName, LEN(szColumnName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a list of foreign keys. The driver returns the information as a result set
   ' on the specified statement handle.
   ' =====================================================================================
   METHOD ForeignKeys (BYREF szPkCatalogName AS ASCIIZ, BYREF szPkSchemaName AS ASCIIZ, BYREF szPkTableName AS ASCIIZ, _
   BYREF szFkCatalogName AS ASCIIZ, BYREF szFkSchemaName AS ASCIIZ, BYREF szFkTableName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLForeignKeys(m_hStmt, szPkCatalogName, LEN(szPkCatalogName), _
          szPkSchemaName, LEN(szPkSchemaName), szPkTableName, LEN(szPkTableName), _
          szFkCatalogName, LEN(szFkCatalogName), szFkSchemaName, LEN(szFkSchemaName), _
          szFkTableName, LEN(szFkTableName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the list of input and output parameters, as well as the columns that make up
   ' the result set for the specified procedures. The driver returns the information as a
   ' result set on the specified statement.
   ' =====================================================================================
   METHOD ProcedureColumns (BYREF szCatalogName AS ASCIIZ, BYREF szSchemaName AS ASCIIZ, BYREF szProcName AS ASCIIZ, BYREF szColumnName AS ASCIIZ) AS INTEGER
      LOCAL r AS INTEGER
      r = SQLProcedureColumns(m_hStmt, szCatalogName, LEN(szCatalogName), _
          szSchemaName, LEN(szSchemaName), szProcName, LEN(szProcName), _
          szColumnName, LEN(szColumnName))
      IF r = %SQL_ERROR OR r = %SQL_INVALID_HANDLE THEN
         METHOD OBJRESULT = r
         OleSetErrorInfo $IID_IOdbcStatement, "IODBCSTATEMENT." & FUNCNAME$, ME.ErrorInfo(r)
      END IF
      METHOD = r
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
