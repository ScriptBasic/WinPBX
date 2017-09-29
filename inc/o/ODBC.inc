' ########################################################################################
' Microsoft Windows
' File: ODBC.inc
' Contents: ODBC APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ODBC_INC = 1

#INCLUDE ONCE "sqltypes.inc"
#INCLUDE ONCE "sql.inc"
#INCLUDE ONCE "sqlext.inc"
#INCLUDE ONCE "sqlucode.inc"

' ########################################################################################
'                                 HELPER FUNCTIONS
' ########################################################################################

' ========================================================================================
' SQLGetErrorInfo uses SQLGetDiagRec to retrieve an error description.
' HandleType must be one of the following:
'     %SQL_HANDLE_ENV
'     %SQL_HANDLE_DBC
'     %SQL_HANDLE_STMT
'     %SQL_HANDLE_DESC
' hndl is the handle of the environment, connection, statement or descriptor.
' ========================================================================================
FUNCTION SQLGetErrorInfo (BYVAL HandleType AS INTEGER, BYVAL hndl AS DWORD, OPTIONAL BYVAL iErrorCode AS INTEGER) AS STRING

   LOCAL iResult AS INTEGER
   LOCAL szSqlState AS ASCIIZ * 6
   LOCAL lNativeError AS LONG
   LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
   LOCAL strErrMsg AS STRING
   LOCAL cbbytes AS INTEGER
   LOCAL ErrorCount AS LONG
   LOCAL i AS LONG

   iResult = SQLGetDiagField(HandleType, hndl, 0, %SQL_DIAG_NUMBER, ErrorCount, %SQL_IS_INTEGER, cbbytes)

   IF ErrorCount THEN
      FOR i = 1 TO ErrorCount
         iResult = SQLGetDiagRec(HandleType, hndl, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
         IF iResult <> %SQL_SUCCESS AND iResult <> %SQL_SUCCESS_WITH_INFO THEN EXIT FOR
         strErrMsg = strErrMsg & "SqlState: " & szSqlState & $CRLF & _
                    "Native error: " & FORMAT$(lNativeError) & $CRLF & szErrMsg
      NEXT
   ELSEIF iErrorCode THEN
      SELECT CASE iErrorCode
         CASE  -1 : strErrMsg = "SQL error" ' "SQL_ERROR"
         CASE   2 : strErrMsg = "Still executing" ' "SQL_STILL_EXECUTING"
         CASE  -2 : strErrMsg = "Invalid handle" '"SQL_INVALID_HANDLE"
         CASE  99 : strErrMsg = "Need data" ' "SQL_NEED_DATA"
         CASE 100 : strErrMsg = "No data" '"SQL_NO_DATA"
         CASE ELSE
            strErrMsg = "Error " & FORMAT$(iErrorCode)
      END SELECT
   END IF

   FUNCTION = strErrMsg

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of records in the result set
' Uses an instruction like SqlStr = "SELECT COUNT(*) FROM Customers".
' ========================================================================================
FUNCTION SQLRecordCount (BYVAL hDbc AS DWORD, BYVAL SqlStr AS STRING, BYREF rcount AS DWORD) AS INTEGER

   LOCAL r AS INTEGER, hStmt AS DWORD, NumCols AS INTEGER

   IF SqlStr = "" THEN EXIT FUNCTION
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF r <> %SQL_SUCCESS AND r <> %SQL_SUCCESS_WITH_INFO THEN FUNCTION = r : EXIT FUNCTION
   r = SQLExecDirect (hStmt, BYVAL STRPTR(SqlStr), LEN(SqlStr))
   IF r <> %SQL_SUCCESS AND r <> %SQL_SUCCESS_WITH_INFO THEN FUNCTION = r : GOTO LExit
   r = SQLNumResultCols(hStmt, NumCols)
   IF r <> %SQL_SUCCESS AND r <> %SQL_SUCCESS_WITH_INFO THEN FUNCTION = r : GOTO LExit
   IF NumCols = 0 THEN GOTO LExit
   r = SQLFetch(hStmt)
   IF r <> %SQL_SUCCESS AND r <> %SQL_SUCCESS_WITH_INFO THEN FUNCTION = r : GOTO LExit
   r = SQLGetData(hStmt, 1, %SQL_C_LONG, rcount, 0, BYVAL %NULL)
   FUNCTION = r

LExit:

   SQLFreeStmt hStmt, %SQL_CLOSE ' Closes the cursor
   SQLFreeHandle (%SQL_HANDLE_STMT, hStmt)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Reads long variable char data
' ========================================================================================
FUNCTION SQLGetLongVarcharData (BYVAL hStmt AS DWORD, BYVAL iCol AS INTEGER, BYREF strData AS STRING) AS INTEGER

   LOCAL r AS INTEGER
   LOCAL cbMemo AS LONG
   LOCAL MemoBuf AS ASCIIZ * 32769         ' 32 Kb buffer + CHR$(0)
   LOCAL szSqlState AS ASCIIZ * 6
   LOCAL lNativeError AS LONG
   LOCAL szErrMsg AS ASCIIZ * %SQL_MAX_MESSAGE_LENGTH + 1
   LOCAL cbbytes AS INTEGER

   DO
      r = SQLGetData(hStmt, iCol, %SQL_C_CHAR, MemoBuf, 32769, cbMemo)
      IF r = %SQL_SUCCESS THEN           ' We have reall all the content
         strData = strData & MemoBuf
         EXIT DO
      ELSEIF r = %SQL_SUCCESS_WITH_INFO THEN
         r = SQLGetDiagRec(%SQL_HANDLE_STMT, hStmt, 1, szSqlState, lNativeError, szErrMsg, SIZEOF(szErrMsg), cbbytes)
         IF r <> %SQL_SUCCESS THEN EXIT DO      ' Error in SQLGetDiagRec
         IF szSqlState = "01004" THEN           ' Insufficient buffer
            strData = strData & MemoBuf
            ITERATE
         ELSE                                   ' Error
            EXIT DO
         END IF
      ELSE                                      ' Error
         EXIT DO
      END IF
   LOOP

   IF INSTR(strData, CHR$(13,10)) THEN strData = EXTRACT$(strData, CHR$(13,10))
   FUNCTION = r

END FUNCTION
' ========================================================================================
