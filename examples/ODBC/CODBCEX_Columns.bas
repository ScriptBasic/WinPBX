' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Columns.bas
' Contents: CODBC class example
' Demonstrates the use of the Columns method.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "CODBC.INC"

' ========================================================================================
' Displays the data
' ========================================================================================
SUB ShowColumnsData (BYVAL pCon AS IOdbcConnection, BYREF szInTableName AS ASCIIZ)

   #REGISTER NONE   ' // Binded variables can't be register variables

   LOCAL cbbytes AS LONG
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

   IF ISNOTHING(pCon) THEN EXIT SUB

   ' // Allocate an statement handle
   LOCAL pStmt AS IOdbcStatement
   pStmt = pCon.Statement("Statement1")
   IF ISNOTHING(pStmt) THEN EXIT SUB

   TRY
      pStmt.Columns("", "", szInTableName, "")
      pStmt.BindColToString ( 1, szCatalogName, SIZEOF(szCatalogName), cbBytes)
      pStmt.BindColToString ( 2, szSchemaName, SIZEOF(szSchemaName), cbbytes)
      pStmt.BindColToString ( 3, szTableName, SIZEOF(szTableName), cbbytes)
      pStmt.BindColToString ( 4, szColumnName, SIZEOF(szColumnName), cbbytes)
      pStmt.BindColToInteger( 5, iDataType, cbbytes)
      pStmt.BindColToString ( 6, szTypeName, SIZEOF(szTypeName), cbbytes)
      pStmt.BindColToLong   ( 7, lColumnSize, cbbytes)
      pStmt.BindColToLong   ( 8, lBufferLength, cbbytes)
      pStmt.BindColToInteger( 9, iDecimalDigits, cbbytes)
      pStmt.BindColToInteger(10, iNumPrecRadix, cbbytes)
      pStmt.BindColToInteger(11, iNullable, cbbytes)
      pStmt.BindColToString (12, szRemarks, SIZEOF(szRemarks), cbbytes)
      pStmt.BindColToString (13, szColumnDefault, SIZEOF(szColumnDefault), cbbytes)
      pStmt.BindColToInteger(14, iSQLDataType, cbbytes)
      pStmt.BindColToInteger(15, iDatetimeSubtypeCode, cbbytes)
      pStmt.BindColToLong   (16, lCharOctetLength, cbbytes)
      pStmt.BindColToLong   (17, lOrdinalPosition, cbbytes)
      pStmt.BindColToString (18, szIsNullable, SIZEOF(szIsNullable), cbbytes)
      ' // Parse the result set
      DO
         ' // Fetch the record
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ' // Get the values of the columns and display them
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
   CATCH
      ' // Display error information
      ? OdbcOleErrorInfo(OBJRESULT)
      #IF %DEF(%PB_CC32)
      WAITKEY$
      #ENDIF
   END TRY

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   ' // Create an instance of the class
   LOCAL pOdbc AS IOdbc
   pOdbc = NewOdbc(%SQL_OV_ODBC3_80)
   IF ISNOTHING(pOdbc) THEN EXIT FUNCTION

   ' // Create a connection
   LOCAL pCon AS IOdbcConnection
   pCon = pOdbc.Connection("Connection1")
   IF ISNOTHING(pCon) THEN EXIT FUNCTION

   TRY
      ' // Open the database
      pCon.OpenDatabase("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb;UID=;PWD=;")
      ' // Display the data
      ShowColumnsData (pCon, "Authors")
   CATCH
     ' // Display error information
      ? OdbcOleErrorInfo(OBJRESULT)
   END TRY

   ' // Destroy the class
   pOdbc = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
