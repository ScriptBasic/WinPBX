' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Tables.bas
' Contents: CODBC class example
' Demonstrates the use of the Tables method.
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
SUB ShowTablesData (BYVAL pCon AS IOdbcConnection, BYREF szInTableTypes AS ASCIIZ)

   #REGISTER NONE   ' // Binded variables can't be register variables

   LOCAL cbbytes AS LONG
   LOCAL szTableCatalogName AS ASCIIZ * 256
   LOCAL szTableSchemaName AS ASCIIZ * 256
   LOCAL szTableName AS ASCIIZ * 129
   LOCAL szTableType AS ASCIIZ * 129
   LOCAL szRemarks AS ASCIIZ * 256

   IF ISNOTHING(pCon) THEN EXIT SUB

   ' // Allocate an statement handle
   LOCAL pStmt AS IOdbcStatement
   pStmt = pCon.Statement("Statement1")
   IF ISNOTHING(pStmt) THEN EXIT SUB

   TRY
      pStmt.Tables("", "", "", szInTableTypes)
      pStmt.BindColToString(1, szTableCatalogName, SIZEOF(szTableCatalogName), cbbytes)
      pStmt.BindColToString(2, szTableSchemaName, SIZEOF(szTableSchemaName), cbbytes)
      pStmt.BindColToString(3, szTableName, SIZEOF(szTableName), cbbytes)
      pStmt.BindColToString(4, szTableType, SIZEOF(szTableType), cbbytes)
      pStmt.BindColToString(5, szRemarks, SIZEOF(szRemarks), cbbytes)
      DO
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ? "szTableCatalogName: "; szTableCatalogName
         ? "szTableSchemaName: "; szTableSchemaName
         ? "szTableName: "; szTableName
         ? "szTableType: "; szTableType
         ? "szRemarks: "; szRemarks
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
      ShowTablesData (pCon, "TABLE")
   CATCH
     ' // Display error information
      ? OdbcOleErrorInfo(OBJRESULT)
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
