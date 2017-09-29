' ========================================================================================
' Example of use of the ODBC raw API functions
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Shows the data
' ========================================================================================
SUB ShowTablesData (BYVAL hDbc AS DWORD, BYREF szInTableTypes AS ASCIIZ)

   LOCAL hStmt AS DWORD
   LOCAL cbbytes AS LONG
   LOCAL r AS INTEGER

   LOCAL szTableCatalogName AS ASCIIZ * 256
   LOCAL szTableSchemaName AS ASCIIZ * 256
   LOCAL szTableName AS ASCIIZ * 129
   LOCAL szTableType AS ASCIIZ * 129
   LOCAL szRemarks AS ASCIIZ * 256

   IF ISFALSE hDbc THEN EXIT SUB
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE hStmt THEN EXIT SUB

   IF LEN(szInTableTypes) THEN
      r = SQLTables (hStmt, _
                     BYVAL %NULL, 0, _          ' All catalogues
                     BYVAL %NULL, 0, _          ' All schemas
                     BYVAL %NULL, 0,_           ' All tables
                     szInTableTypes, %SQL_NTS)  ' Table types
   ELSE
      r = SQLTables (hStmt, _
                     BYVAL %NULL, 0, _          ' All catalogues
                     BYVAL %NULL, 0, _          ' All schemas
                     BYVAL %NULL, 0,_           ' All tables
                     BYVAL %NULL, 0)            ' All table types
   END IF

   IF SQL_SUCCEEDED(r) THEN
      r = SQLBindCol (hStmt, 1, %SQL_C_CHAR, szTableCatalogName, SIZEOF(szTableCatalogName), cbbytes)
      r = SQLBindCol (hStmt, 2, %SQL_C_CHAR, szTableSchemaName, SIZEOF(szTableSchemaName), cbbytes)
      r = SQLBindCol (hStmt, 3, %SQL_C_CHAR, szTableName, SIZEOF(szTableName), cbbytes)
      r = SQLBindCol (hStmt, 4, %SQL_C_CHAR, szTableType, SIZEOF(szTableType), cbbytes)
      r = SQLBindCol (hStmt, 5, %SQL_C_CHAR, szRemarks, SIZEOF(szRemarks), cbbytes)
      DO
         r = SQLFetch(hStmt)   ' Fetch the data
         IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
         ? "szTableCatalogName: " & szTableCatalogName
         ? "szTableSchemaName: " & szTableSchemaName
         ? "szTableName: " & szTableName
         ? "szTableType: " & szTableType
         ? "szRemarks: " & szRemarks
         #IF %DEF(%PB_CC32)
         WAITKEY$
         CLS
         #ENDIF
      LOOP
   END IF

   SQLFreeStmt hStmt, %SQL_CLOSE           ' Closes the cursor
   SQLFreeHandle %SQL_HANDLE_STMT, hStmt   ' Frees the statement handle

END SUB
' ========================================================================================

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

   ShowTablesData (hDbc, "TABLE")

Terminate:

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
