' ========================================================================================
' Example of use of the ODBC raw API functions
' Demonstrates how to update a record using a prepared statement.
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

   ' Binds the parameter
   LOCAL lAuId AS LONG
   LOCAL szAuthor AS ASCIIZ * 256
   LOCAL cbAuId AS LONG
   LOCAL cbAuthor AS LONG

   r = SQLPrepare(hStmt, "UPDATE Authors SET Author=? WHERE Au_ID=?", %SQL_NTS)
   r = SQLBindParameter(hStmt, 1, %SQL_PARAM_INPUT, %SQL_C_CHAR, %SQL_CHAR, 255, 0, szAuthor, SIZEOF(szAuthor), cbAuthor)
   r = SQLBindParameter(hStmt, 2, %SQL_PARAM_INPUT, %SQL_C_LONG, %SQL_INTEGER, 4, 0, lAuId, 0, cbAuID)

   ' Fills the parameter value
   lAuId = 999 : cbAuId = SIZEOF(lAuId)
   szAuthor = "William Shakespeare" : cbAuthor = LEN(szAuthor)
   ' Executes the prepared statement
   r = SQLExecute(hStmt)
   IF SQL_SUCCEEDED(r) THEN
      ? "Record updated"
   ELSE
      ? SQLGetErrorInfo(%SQL_HANDLE_STMT, hStmt, r)
      GOTO Terminate
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
