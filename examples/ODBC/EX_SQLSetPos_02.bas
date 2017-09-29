' ========================================================================================
' Example of use of the ODBC raw API functions
' Demonstrates how to update a record using SQLSetPos.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL r AS INTEGER
   LOCAL hEnv AS DWORD
   LOCAL hDbc AS DWORD
   LOCAL hStmt AS DWORD
   LOCAL szInConnectionString AS ASCIIZ * 1025
   LOCAL szOutConnectionString AS ASCIIZ * 1025
   LOCAL strOutput AS STRING

   ' Allocates the environment handle
   r = SQLAllocHandle (%SQL_HANDLE_ENV, %SQL_NULL_HENV, hEnv)
   IF ISFALSE SQL_SUCCEEDED(r) OR ISFALSE hEnv THEN EXIT FUNCTION

   ' Tells to the driver manager that is an application that uses the ODBC driver 3.x
   r = SQLSetEnvAttr (hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL %SQL_OV_ODBC3, %SQL_IS_INTEGER)
   IF ISFALSE SQL_SUCCEEDED(r) THEN GOTO Terminate

   ' Allocates the connection handle
   r =  SQLAllocHandle (%SQL_HANDLE_DBC, hEnv, hDbc)
   IF ISFALSE SQL_SUCCEEDED(r) THEN GOTO Terminate

   ' Connection string
   szInConnectionString = "DRIVER={Microsoft Access Driver (*.mdb)};" & _
                          "DBQ=biblio.mdb;UID=;PWD=;"
   ' Connects with the ODBC driver
   r = SQLDriverConnect (hDbc, _
                        %HWND_DESKTOP, _
                        szInConnectionString, _
                        LEN(szInConnectionString), _
                        szOutConnectionString, _
                        SIZEOF (szOutConnectionString), _
                        BYVAL %NULL, _
                        %SQL_DRIVER_COMPLETE)
   ' Check for errors
   IF ISFALSE SQL_SUCCEEDED(r) THEN
      ? SQLGetErrorInfo(%SQL_HANDLE_DBC, hDbc, r)
      GOTO Terminate
   END IF

   ' Allocates an statement handle
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE SQL_SUCCEEDED(r) OR ISFALSE hStmt THEN GOTO Terminate

   ' Binds the columns
   LOCAL lAuId AS LONG
   LOCAL szAuthor AS ASCIIZ * 256
   LOCAL iYearBorn AS INTEGER
   LOCAL cbAuId AS LONG
   LOCAL cbAuthor AS LONG
   LOCAL cbYearBorn AS LONG

   SQLBindCol(hStmt, 1, %SQL_C_LONG, lAuId, 0, cbAuId)
   SQLBindCol(hStmt, 2, %SQL_C_CHAR, szAuthor, SIZEOF(szAuthor), cbAuthor)
   SQLBindCol(hStmt, 3, %SQL_C_SHORT, iYearBorn, 0, cbYearBorn)

   ' Cursor type
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_KEYSET_DRIVEN, %SQL_IS_UINTEGER)
   ' Optimistic concurrency
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_VALUES, BYVAL %SQL_IS_UINTEGER)

   ' Generates a result set
   r = SQLExecDirect (hStmt, "SELECT * FROM Authors WHERE Au_Id=999", %SQL_NTS)
   ' Check for errors
   IF ISFALSE SQL_SUCCEEDED(r) THEN
      ? SQLGetErrorInfo(%SQL_HANDLE_STMT, hStmt, r)
      GOTO Terminate
   END IF

   ' Fetches the record
   r = SQLFetch(hStmt)
   IF SQL_SUCCEEDED(r) THEN
      ' Fills the values of the bounded application variables and its sizes
      cbAuId = %SQL_COLUMN_IGNORE  ' Ignore the Au_Id column in the update
      szAuthor = "Félix Lope de Vega Carpio" : cbAuthor = LEN(szAuthor)
      iYearBorn = 1562 : cbYearBorn = SIZEOF(iYearBorn)
      ' Updates the record
      r = SQLSetPos(hStmt, 1, %SQL_UPDATE, %SQL_LOCK_NO_CHANGE)
      IF SQL_SUCCEEDED(r) THEN
         ? "Record updated"
      ELSE
         ? SQLGetErrorInfo(%SQL_HANDLE_STMT, hStmt, r)
      END IF
   END IF

Terminate:

   ' Closes the cursor
   IF hStmt THEN SQLCloseCursor(hStmt)
   ' Closes the statement handle
   IF hStmt THEN SQLFreeHandle(%SQL_HANDLE_STMT, hStmt)
   ' Closes the connection
   IF hDbc THEN
      SQLDisconnect(hDbc)
      SQLFreeHandle (%SQL_HANDLE_DBC, hDbc)
   END IF
   ' Frees the environment handle
   IF hEnv THEN SQLFreeHandle(%SQL_HANDLE_ENV, hEnv)

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
