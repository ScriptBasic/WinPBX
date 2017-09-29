' ========================================================================================
' This example demostrates the use of the SQLColumns and SQLNumResultColsfunctions. It
' shows a way to create a recordset and parse its contents if we only knew the name of the
' database and the table.
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
   LOCAL szBuf AS ASCIIZ * 256
   LOCAL szInConnectionString AS ASCIIZ * 1025
   LOCAL szOutConnectionString AS ASCIIZ * 1025
   LOCAL cbbytes AS LONG
   LOCAL szInTableName AS ASCIIZ * 129
   LOCAL szColumnName AS ASCIIZ * 129
   LOCAL idx AS LONG
   LOCAL NumCols AS INTEGER

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

   ' --- Retrieves the column names ------------------------------------------------------
   ' Allocates an statement handle
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   szInTableName = "Authors"
   ' Retrieves the information
   r = SQLColumns(hStmt, _
                  BYVAL %NULL, 0, _            ' All catalogs
                  BYVAL %NULL, 0, _            ' All schemas
                  szInTableName, %SQL_NTS,_    ' Table name
                  BYVAL %NULL, 0)              ' All columns
   IF SQL_SUCCEEDED(r) THEN
      ' Binds the variable
      r = SQLBindCol (hStmt, 4, %SQL_C_CHAR, szColumnName, SIZEOF(szColumnName), cbbytes)
      DO
         r = SQLFetch(hStmt)   ' Fetch the data
         IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
         ' Skip column 0, reserved to bookmarks
         IF idx <> 0 THEN ? "Column name: " & szColumnName
         INCR idx
      LOOP
   END IF

   SQLFreeStmt hStmt, %SQL_CLOSE           ' Closes the cursor
   SQLFreeHandle %SQL_HANDLE_STMT, hStmt   ' Frees the statement handle
   hStmt = %NULL
   ' -------------------------------------------------------------------------------------

   ' Allocates an statement handle
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE SQL_SUCCEEDED(r) OR ISFALSE hStmt THEN GOTO Terminate
   ' Cursor type
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_KEYSET_DRIVEN, %SQL_IS_UINTEGER)
   ' Optimistic concurrency
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_VALUES, BYVAL %SQL_IS_UINTEGER)

   ' Generates a result set
   r = SQLExecDirect (hStmt, "SELECT TOP 20 * FROM Authors ORDER BY Author", %SQL_NTS)
   ' Check for errors
   IF ISFALSE SQL_SUCCEEDED(r) THEN
      ? SQLGetErrorInfo(%SQL_HANDLE_STMT, hStmt, r)
      GOTO Terminate
   END IF

   ' Retrieves the number of columns
   r = SQLNumResultCols(hStmt, NumCols)
   ? "Number of columns: " & STR$(NumCols)
   IF NumCols = 0 THEN GOTO Terminate

   ' Parses the result set using SQLGetData to retrieve the data
   DO
      r = SqlFetch(hStmt)
      IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
      FOR idx = 1 TO NumCols
         r = SQLGetData(hStmt, idx, %SQL_C_CHAR, szBuf, SIZEOF(szBuf), BYVAL %NULL)
         #IF %DEF(%PB_CC32)
         PRINT szBuf " ";
         #ELSE
         MSGBOX szBuf
         #ENDIF
      NEXT
      #IF %DEF(%PB_CC32)
      PRINT
      #ENDIF
   LOOP

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
