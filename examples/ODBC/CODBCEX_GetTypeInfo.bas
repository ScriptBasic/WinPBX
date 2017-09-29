' ########################################################################################
' Microsoft Windows
' File: CODBCEX_GetTypeInfo.bas
' Contents: CODBC class example
' Demonstrates the use of the GetTypeInfo method.
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
' Shows the data
' ========================================================================================
SUB ShowTypeInfoData (BYVAL pCon AS IOdbcConnection, BYVAL iInDataType AS INTEGER)

   #REGISTER NONE   ' // Binded variables can't be register variables

   LOCAL cbbytes AS LONG
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

   IF ISNOTHING(pCon) THEN EXIT SUB

   ' // Allocate an statement handle
   LOCAL pStmt AS IOdbcStatement
   pStmt = pCon.Statement("Statement1")
   IF ISNOTHING(pStmt) THEN EXIT SUB

   TRY
      pStmt.GetTypeInfo(iInDataType)
      pStmt.BindColToString ( 1, szTypeName, SIZEOF(szTypeName), cbbytes)
      pStmt.BindColToInteger( 2, iDataType, cbbytes)
      pStmt.BindColToLong   ( 3, lColumnSize, cbbytes)
      pStmt.BindColToString ( 4, szIntervalPrefix, SIZEOF(szIntervalPrefix), cbbytes)
      pStmt.BindColToString ( 5, szIntervalSuffix, SIZEOF(szIntervalSuffix), cbbytes)
      pStmt.BindColToString ( 6, szCreateParams, SIZEOF(szCreateParams), cbbytes)
      pStmt.BindColToInteger( 7, iNullable, cbbytes)
      pStmt.BindColToInteger( 8, iCasesensitive, cbbytes)
      pStmt.BindColToInteger( 9, iSearchable, cbbytes)
      pStmt.BindColToInteger(10, iUnsignedAttribute, cbbytes)
      pStmt.BindColToInteger(11, iFixedPrecScale, cbbytes)
      pStmt.BindColToInteger(12, iAutoUniqueValue, cbbytes)
      pStmt.BindColToString (13, szLocalTypeName, SIZEOF(szLocalTypeName), cbbytes)
      pStmt.BindColToInteger(14, iMinimumScale, cbbytes)
      pStmt.BindColToInteger(15, iMaximumScale, cbbytes)
      pStmt.BindColToInteger(16, iSqlDataType, cbbytes)
      pStmt.BindColToInteger(17, iSqlDateTimeSub, cbbytes)
      pStmt.BindColToLong   (18, lNumPrecRadix, cbbytes)
      pStmt.BindColToInteger(19, iIntervalPrecision, cbbytes)
      DO
         IF ISFALSE pStmt.Fetch THEN EXIT DO
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
      ' // Show the type info data
      ShowTypeInfoData (pCon, %SQL_ALL_TYPES)
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
