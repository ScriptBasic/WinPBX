' ========================================================================================
' Example of use of the ODBC raw API functions
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Shows the data
' ========================================================================================
SUB ShowStatisticsData (BYVAL hDbc AS DWORD, BYREF szInTableName AS ASCIIZ, BYVAL iUnique AS INTEGER, BYVAL iCardinality AS INTEGER)

   LOCAL hStmt AS DWORD
   LOCAL cbbytes AS LONG
   LOCAL r AS INTEGER

   LOCAL szTableCatalogName AS ASCIIZ * 256
   LOCAL szTableSchemaName AS ASCIIZ * 256
   LOCAL szTableName AS ASCIIZ * 129
   LOCAL iNonUnique AS INTEGER
   LOCAL szIndexQualifier AS ASCIIZ * 129
   LOCAL szIndexName AS ASCIIZ * 129
   LOCAL iInfoType AS INTEGER
   LOCAL iOrdinalPosition AS INTEGER
   LOCAL szColumnName AS ASCIIZ * 129
   LOCAL szAscOrDesc AS ASCIIZ * 2
   LOCAL lCardinality AS LONG
   LOCAL lPages AS LONG
   LOCAL szFilterCondition AS ASCIIZ * 129

   IF ISFALSE hDbc THEN EXIT SUB
   IF LEN(szIntableName) = 0 THEN EXIT SUB
   IF iCardinality > 1 THEN iCardinality = 0
   IF iUnique > 1 THEN iUnique = 1

   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE hStmt THEN EXIT SUB

   r = SQLStatistics(hStmt, _
                     BYVAL %NULL, 0, _            ' All catalogs
                     BYVAL %NULL, 0, _            ' All schemas
                     szInTableName, %SQL_NTS,_    ' Table name
                     iUnique, iCardinality)

   IF SQL_SUCCEEDED(r) THEN
      r = SQLBindCol (hStmt,  1, %SQL_C_CHAR,   szTableCatalogName, SIZEOF(szTableCatalogName), cbBytes)
      r = SQLBindCol (hStmt,  2, %SQL_C_CHAR,   szTableSchemaName, SIZEOF(szTableSchemaName), cbbytes)
      r = SQLBindCol (hStmt,  3, %SQL_C_CHAR,   szTableName, SIZEOF(szTableName), cbbytes)
      r = SQLBindCol (hStmt,  4, %SQL_C_SSHORT, iNonUnique, 0, cbbytes)
      r = SQLBindCol (hStmt,  5, %SQL_C_CHAR,   szIndexQualifier, SIZEOF(szIndexQualifier), cbbytes)
      r = SQLBindCol (hStmt,  6, %SQL_C_CHAR,   szIndexName, SIZEOF(szIndexName), cbbytes)
      r = SQLBindCol (hStmt,  7, %SQL_C_SSHORT, iInfoType, 0, cbbytes)
      r = SQLBindCol (hStmt,  8, %SQL_C_SSHORT, iOrdinalPosition, 0, cbbytes)
      r = SQLBindCol (hStmt,  9, %SQL_C_CHAR,   szColumnName, SIZEOF(szColumnName), cbbytes)
      r = SQLBindCol (hStmt, 10, %SQL_C_CHAR,   szAscOrDesc, SIZEOF(szAscOrDesc), cbbytes)
      r = SQLBindCol (hStmt, 11, %SQL_C_SLONG,  lCardinality, 0, cbbytes)
      r = SQLBindCol (hStmt, 12, %SQL_C_SLONG,  lPages, 0, cbbytes)
      r = SQLBindCol (hStmt, 13, %SQL_C_CHAR,   szFilterCondition, SIZEOF(szFilterCondition), cbbytes)
      DO
         r = SQLFetch(hStmt)   ' Fetch the data
         IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
         ? "Table catalog name: " & szTableCatalogName
         ? "Table schema name: " & szTableSchemaName
         ? "Table name: " & szTableName
         ? "Non unique: " & STR$(iNonUnique)
         ? "Index qualifier: " & szIndexQualifier
         ? "Index name: " & szIndexName
         ? "Info type: " & STR$(iInfoType)
         ? "Ordinal position: " & STR$(iOrdinalPosition)
         ? "Column name: " & szColumnName
         ? "Asc or desc: " & szAscOrDesc
         ? "Cardinality: " & STR$(lCardinality)
         ? "Pages: " & STR$(lPages)
         ? "Filter condition: " & szFilterCondition
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

   ShowStatisticsData hDbc, "Authors", %SQL_INDEX_ALL, %SQL_ENSURE

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
