' ========================================================================================
' Example of use of the ODBC raw API functions
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Shows the data
' ========================================================================================
SUB ShowTypeInfoData (BYVAL hDbc AS DWORD, iInDataType AS INTEGER)

   LOCAL hStmt AS DWORD
   LOCAL cbbytes AS LONG
   LOCAL r AS INTEGER

   LOCAL szTypeName AS ASCIIZ * 129
   LOCAL iDataType AS INTEGER
   LOCAL lColumnSize AS LONG
   LOCAL szIntervalPrefix AS ASCIIZ * 129
   LOCAL szIntervalSuffix AS ASCIIZ * 129
   LOCAL szCreateParams AS ASCIIZ * 129
   LOCAL iNullable AS INTEGER
   LOCAL iCaseSensitive AS INTEGER
   LOCAL iSearchable AS INTEGER
   LOCAL iUnsignedAttribute AS INTEGER
   LOCAL iFixedPrecScale AS INTEGER
   LOCAL iAutoUniqueValue AS INTEGER
   LOCAL szLocalTypeName AS ASCIIZ * 129
   LOCAL iMinimumScale AS INTEGER
   LOCAL iMaximumScale AS INTEGER
   LOCAL iSqlDataType AS INTEGER
   LOCAL iSqlDatetimeSub AS INTEGER
   LOCAL lNumPrecRadix AS LONG
   LOCAL iIntervalPrecision AS INTEGER

   IF ISFALSE hDbc THEN EXIT SUB
   r = SQLAllocHandle (%SQL_HANDLE_STMT, hDbc, hStmt)
   IF ISFALSE hStmt THEN EXIT SUB

   r = SQLGetTypeInfo (hStmt, iInDataType)
   IF SQL_SUCCEEDED(r) THEN
      r = SQLBindCol (hStmt,  1, %SQL_C_CHAR,   szTypeName, SIZEOF(szTypeName), cbbytes)
      r = SQLBindCol (hStmt,  2, %SQL_C_SSHORT, iDataType, 0, cbbytes)
      r = SQLBindcol (hStmt,  3, %SQL_C_SLONG,  lColumnSize, 0, cbbytes)
      r = SQLBindCol (hStmt,  4, %SQL_C_CHAR,   szIntervalPrefix, SIZEOF(szIntervalPrefix), cbbytes)
      r = SQLBindCol (hStmt,  5, %SQL_C_CHAR,   szIntervalSuffix, SIZEOF(szIntervalSuffix), cbbytes)
      r = SQLBindCol (hStmt,  6, %SQL_C_CHAR,   szCreateParams, SIZEOF(szCreateParams), cbbytes)
      r = SQLBindCOl (hStmt,  7, %SQL_C_SSHORT, iNullable, 0, cbbytes)
      r = SQLBindCol (hStmt,  8, %SQL_C_SSHORT, iCasesensitive, 0, cbbytes)
      r = SQLBindCol (hStmt,  9, %SQL_C_SSHORT, iSearchable, 0, cbbytes)
      r = SQLBindCol (hStmt, 10, %SQL_C_SSHORT, iUnsignedAttribute, 0, cbbytes)
      r = SQLBindCol (hStmt, 11, %SQL_C_SSHORT, iFixedPrecScale, 0, cbbytes)
      r = SQLBindCol (hStmt, 12, %SQL_C_SSHORT, iAutoUniqueValue, 0, cbbytes)
      r = SQLBindCol (hStmt, 13, %SQL_C_CHAR,   szLocalTypeName, SIZEOF(szLocalTypeName), cbbytes)
      r = SQLBindCol (hStmt, 14, %SQL_C_SSHORT, iMinimumScale, 0, cbbytes)
      r = SQLBindCol (hStmt, 15, %SQL_C_SSHORT, iMaximumScale, 0, cbbytes)
      r = SQLBindCol (hStmt, 16, %SQL_C_SSHORT, iSqlDataType, 0, cbbytes)
      r = SQLBindCol (hStmt, 17, %SQL_C_SSHORT, iSqlDateTimeSub, 0, cbbytes)
      r = SQLBindCol (hStmt, 18, %SQL_C_SLONG,  lNumPrecRadix, 0, cbbytes)
      r = SQLBindCol (hStmt, 19, %SQL_C_SSHORT, iIntervalPrecision, 0, cbbytes)
      DO
         r = SQLFetch(hStmt)   ' Fetch the data
         IF ISFALSE SQL_SUCCEEDED(r) THEN EXIT DO
         ? "Type name: " & szTypeName
         ? "Data type: " & STR$(iDataType)
         ? "Column size: " & STR$(lColumnSize)
         ? "Interval prefix: " & szIntervalPrefix
         ? "Interval suffix: " & szIntervalSuffix
         ? "Create params: " & szCreateParams
         ? "Nullable: " & STR$(iNullable)
         ? "Case sensitive: " & STR$(iCaseSensitive)
         ? "Searchable: " & STR$(iSearchable)
         ? "Unsigned attribute: " & STR$(iUnsignedAttribute)
         ? "Fixed prec scale: " & STR$(iFixedPrecScale)
         ? "Auto unique value: " & STR$(iAutoUniqueValue)
         ? "Local type name: " & szLocalTypeName
         ? "Minimum scale: " & STR$(iMinimumScale)
         ? "Maximum scale: " & STR$(iMaximumScale)
         ? "SQL data type: " & STR$(iSqlDataType)
         ? "SQL Datetime sub: " & STR$(iSqlDatetimeSub)
         ? "Num prec radix: " & STR$(lNumPrecRadix)
         ? "Interval precision: " & STR$(iIntervalPrecision)
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

   ShowTypeInfoData (hDbc, %SQL_ALL_TYPES)

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
