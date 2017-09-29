' ========================================================================================
' Example of use of the ODBC raw API functions
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Displays the data
' ========================================================================================
SUB ShowColumnsData (BYVAL hDbc AS DWORD, BYREF szInTableName AS ASCIIZ)

   LOCAL hStmt AS DWORD
   LOCAL cbbytes AS LONG
   LOCAL r AS INTEGER

   IF ISFALSE hDbc THEN EXIT SUB
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE hStmt THEN EXIT SUB

   LOCAL szCatalogName AS ASCIIZ * 256     '  1. Catalog name
   LOCAL szSchemaName AS ASCIIZ * 256      '  2. Schema name
   LOCAL szTableName AS ASCIIZ * 129       '  3. Table name
   LOCAL szColumnName AS ASCIIZ * 129      '  4. Column name
   LOCAL iDataType AS INTEGER              '  5. SQL data type
   LOCAL szTypeName AS ASCIIZ * 129        '  6. Data-source dependent data type
   LOCAL lColumnSize AS LONG               '  7. Column size
   LOCAL lBufferLength AS LONG             '  8. Length in bytes of data transferred
   LOCAL iDecimalDigits AS INTEGER         '  9. Decimal digits
   LOCAL iNumPrecRadix AS INTEGER          ' 10. Numeric precision radix
   LOCAL iNullable AS INTEGER              ' 11. Indicates with certainty if a column can accept nulls
   LOCAL szRemarks AS ASCIIZ * 256         ' 12. A description of the column
   LOCAL szColumnDefault AS ASCIIZ * 129   ' 13. Default value of the column
   LOCAL iSQLDataType AS INTEGER           ' 14. SQL data type as it appears in the SQL_DESC_TYPE record field in the IRD
   LOCAL iDatetimeSubtypeCode AS INTEGER   ' 15. The subtype code for datetime and interval data types
   LOCAL lCharOctetLength AS LONG          ' 16. The maximun length in bytes of a character or binary data type
   LOCAL lOrdinalPosition AS LONG          ' 17. The ordinal position of the column in the table
   LOCAL szIsNullable AS ASCIIZ * 4        ' 18. Indicates with certainty if a column cannot accept nulls

   r = SQLColumns(hStmt, _
                  BYVAL %NULL, 0, _            ' All catalogs
                  BYVAL %NULL, 0, _            ' All schemas
                  szInTableName, %SQL_NTS,_    ' Table name
                  BYVAL %NULL, 0)              ' All columns

   IF SQL_SUCCEEDED(r) THEN
      r = SQLBindCol (hStmt,  1, %SQL_C_CHAR,   szCatalogName, SIZEOF(szCatalogName), cbBytes)
      r = SQLBindCol (hStmt,  2, %SQL_C_CHAR,   szSchemaName, SIZEOF(szSchemaName), cbbytes)
      r = SQLBindCol (hStmt,  3, %SQL_C_CHAR,   szTableName, SIZEOF(szTableName), cbbytes)
      r = SQLBindCol (hStmt,  4, %SQL_C_CHAR,   szColumnName, SIZEOF(szColumnName), cbbytes)
      r = SQLBindCol (hStmt,  5, %SQL_C_SSHORT, iDataType, 0, cbbytes)
      r = SQLBindCol (hStmt,  6, %SQL_C_CHAR,   szTypeName, SIZEOF(szTypeName), cbbytes)
      r = SQLBindCol (hStmt,  7, %SQL_C_SLONG,  lColumnSize, 0, cbbytes)
      r = SQLBindCol (hStmt,  8, %SQL_C_SLONG,  lBufferLength, 0, cbbytes)
      r = SQLBindCol (hStmt,  9, %SQL_C_SSHORT, iDecimalDigits, 0, cbbytes)
      r = SQLBindCol (hStmt, 10, %SQL_C_SSHORT, iNumPrecRadix, 0, cbbytes)
      r = SQLBindCol (hStmt, 11, %SQL_C_SSHORT, iNullable, 0, cbbytes)
      r = SQLBindCol (hStmt, 12, %SQL_C_CHAR,   szRemarks, SIZEOF(szRemarks), cbbytes)
      r = SQLBindCol (hStmt, 13, %SQL_C_CHAR,   szColumnDefault, SIZEOF(szColumnDefault), cbbytes)
      r = SQLBindCol (hStmt, 14, %SQL_C_SSHORT, iSQLDataType, 0, cbbytes)
      r = SQLBindCol (hStmt, 15, %SQL_C_SSHORT, iDatetimeSubtypeCode, 0, cbbytes)
      r = SQLBindCol (hStmt, 16, %SQL_C_SLONG,  lCharOctetLength, 0, cbbytes)
      r = SQLBindCol (hStmt, 17, %SQL_C_SLONG,  lOrdinalPosition, 0, cbbytes)
      r = SQLBindCol (hStmt, 18, %SQL_C_CHAR,   szIsNullable, SIZEOF(szIsNullable), cbbytes)
      DO
         r = SQLFetch(hStmt)   ' Fetch the data
         IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
         ? "Catalog name: " & szCatalogName
         ? "Schema name: " & szSchemaName
         ? "Table name: " & szTableName
         ? "Column name " & szColumnName
         ? "Data type: " & STR$(iDataType)
         ? "Type name: " & szTypeName
         ? "Column size: " & STR$(lColumnSize)
         ? "Buffer length: " & STR$(lBufferLength)
         ? "Decimal digits: " & STR$(iDecimalDigits)
         ? "Numeric precision radix: " & STR$(iNumPrecRadix)
         ? "Can accept nulls: " & STR$(iNullable)
         ? "Remarks: " & szRemarks
         ? "Column default: " & szColumnDefault
         ? "IRD SQL data type: " & STR$(iSqlDataType)
         ? "Datetime subtype code: " & STR$(iDateTimeSubtypeCOde)
         ? "Character octet length: " & STR$(lCharOctetLength)
         ? "Ordinal position: " & STR$(lOrdinalPosition)
         ? "Cannot accept nulls: " & szIsNullable
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

   ShowColumnsData (hDbc, "Authors")

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
