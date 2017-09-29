' ========================================================================================
' Example of use of the ODBC raw API functions
' Demonstrates the use of the SQLGetDescRec function.
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
   ' Cursor type
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CURSOR_TYPE, BYVAL %SQL_CURSOR_KEYSET_DRIVEN, %SQL_IS_UINTEGER)
   ' Optimistic concurrency
   r = SQLSetStmtAttr(hStmt, %SQL_ATTR_CONCURRENCY, BYVAL %SQL_CONCUR_VALUES, BYVAL %SQL_IS_UINTEGER)

   ' Generates a result set
   r = SQLExecDirect (hStmt, "SELECT TOP 20 * FROM Titles ORDER BY Title", %SQL_NTS)
   ' Check for errors
   IF ISFALSE SQL_SUCCEEDED(r) THEN
      ? SQLGetErrorInfo(%SQL_HANDLE_STMT, hStmt, r)
      GOTO Terminate
   END IF

   ' Get the current setting or values of the descriptor record
   ' for the 9th field ("Price")

   LOCAL hIpd AS DWORD, StringLengthPtr AS INTEGER, TypePtr AS INTEGER
   LOCAL SubTypePtr AS INTEGER, LengthPtr AS LONG, PrecisionPtr AS INTEGER
   LOCAL ScalePtr AS INTEGER, NullablePtr AS INTEGER
   LOCAL szName AS ASCIIZ * 255

   ' Gets the handle of the IPD (implicitily allocated descriptor).
   r = SQLGetStmtAttr(hStmt, %SQL_ATTR_IMP_ROW_DESC, hIpd, %SQL_IS_UINTEGER, BYVAL %NULL)
   IF ISTRUE hIpd THEN
      r = SQLGetDescRec(hIpd, 9, szName, SIZEOF(szName), StringLengthPtr, TypePtr, SubTypePtr, _
                        LengthPtr, PrecisionPtr, ScalePtr, NullablePtr)
      IF SQL_SUCCEEDED(r) THEN
         ? "Name: " & szName
         ? "String length: " & STR$(StringLengthPtr)
         ? "Type: " & STR$(TypePtr)
         ? "Subtype: " & STR$(SubTypePtr)
         ? "Length: " & STR$(LengthPtr)
         ? "Precision: " & STR$(PrecisionPtr)
         ? "Scale: " & STR$(ScalePtr)
         ? "Nullable: " & STR$(NullablePtr)
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
