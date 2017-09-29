' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Prepare.bas
' Contents: CODBC class example
' Demonstrates how to update a record using a prepared statement.
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
      ' // Allocate an statement handle
      LOCAL pStmt AS IOdbcStatement
      pStmt = pCon.Statement("Statement1")
      ' // Cursor type
      pStmt.SetMultiuserKeysetCursor
      ' // Prepare the statement
      pStmt.Prepare("UPDATE Authors SET Author=? WHERE Au_ID=?")
      ' // Bind the columns
      ' // Note: If you want to use local variables, make sure they aren't register variables using #REGISTER NONE
      STATIC szAuthor AS ASCIIZ * 256, cbAuthor AS LONG
      STATIC lAuId, cbAuId AS LONG
      pStmt.BindParameter(1, %SQL_PARAM_INPUT, %SQL_C_CHAR, %SQL_CHAR, 255, 0, VARPTR(szAuthor), SIZEOF(szAuthor), cbAuthor)
      pStmt.BindParameter(2, %SQL_PARAM_INPUT, %SQL_C_LONG, %SQL_INTEGER, 4, 0, VARPTR(lAuId), 0, cbAuID)
      ' // Fill the parameter value
      lAuId = 999 : cbAuId = 4
      szAuthor = "William Shakespeare" : cbAuthor = LEN(szAuthor)
      ' // Execute the prepared statement
      pStmt.Execute
      ? "Record updated"
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
