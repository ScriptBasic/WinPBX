' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Drivers.bas
' Contents: CODBC class example
' Demonstrates the use of the EndTran method.
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
      ' // Set manual commit
      pCon.SetAutocommitOff
      ' // Allocate an statement handle
      LOCAL pStmt AS IOdbcStatement
      pStmt = pCon.Statement("Statement1")
      ' // Cursor type
      pStmt.SetMultiuserKeysetCursor
      ' // Bind the columns
      ' // Note: If you want to use local variables, make sure they aren't register variables using #REGISTER NONE
      STATIC lAuId, cbAuId AS LONG
      pStmt.BindColToLong(1, lAuId, cbAuId)
      STATIC szAuthor AS ASCIIZ * 256, cbAuthor AS LONG
      pStmt.BindColToString(2, szAuthor, SIZEOF(szAuthor), cbAuthor)
      STATIC iYearBorn AS INTEGER, cbYearBorn AS LONG
      pStmt.BindColToInteger(3, iYearBorn, cbYearBorn)
      ' // Generate a result set
      pStmt.ExecDirect ("SELECT TOP 20 * FROM Authors ORDER BY Author")
      ' // Fill the values of the bounded application variables and its sizes
      lAuId     = 998               : cbAuID     = SIZEOF(lAuId)
      szAuthor  = "Edgar Allan Poe" : cbAuthor   = LEN(szAuthor)
      iYearBorn = 1809              : cbYearBorn = SIZEOF(iYearBorn)
      ' // Add the record
      pStmt.AddRecord
      ? "Record added"
      ' // Commit the transaction
      ' pCon.CommitDbcTran
      ' PRINT "Commit succeeded"
      ' or Rollbacks it because this is a test
      pCon.RollbackTran
      ? "Rollback succeeded"
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
