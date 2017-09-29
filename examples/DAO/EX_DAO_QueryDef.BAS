' ########################################################################################
' This example creates a new QueryDef object and appends it to the QueryDefs collection in
' the current database. Then the example enumerates all the properties of the new QueryDef
' and finally deletes it.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"
#INCLUDE "AfxTime.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pNewQueryDef AS DAOQueryDef      ' Pointer to the QueryDef object
   LOCAL pQueryDef AS DAOQueryDef         ' Pointer to the QueryDef object
   LOCAL pQueryDefs AS DAOQueryDefs       ' Pointer to the QueryDefs collection

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Create a query definition
      pNewQueryDef = pDatabase.CreateQueryDef("This is a test")
      IF ISOBJECT(pNewQueryDef) THEN
         ' Enumerate built-in properties of the new QueryDef
         PRINT "qdfTest.Name: " & pNewQueryDef.Name
         PRINT "qdfTest.DateCreated: " & AfxVarDateToString(VARIANT#(pNewQueryDef.DateCreated))
         PRINT "qdfTest.LastUpdated: " & AfxVarDateToString(VARIANT#(pNewQueryDef.LastUpdated))
         PRINT "qdfTest.SQL: " & pNewQueryDef.SQL
         PRINT "qdfTest.ODBCTimeout: " & STR$(pNewQueryDef.ODBCTimeout)
         PRINT "qdfTest.Updatable: " & STR$(pNewQueryDef.Updatable)
         PRINT "qdfTest.Type: " & STR$(pNewQueryDef.Type)
         PRINT "qdfTest.Connect: " & pNewQueryDef.Connect
         PRINT "qdfTest.ReturnsRecords: " & STR$(pNewQueryDef.ReturnsRecords)
         ' Delete the QueryDef
'         pQueryDefs = pDatabase.QueryDefs
'         IF ISOBJECT(pQueryDefs) THEN
'            pQueryDefs.Delete "This is a test"
'            pQueryDefs = NOTHING
'         END IF
         ' The following compound instruction replaces the above remed lines
         pDatabase.QueryDefs.Delete("This is a test")
         pNewQueryDef = NOTHING
      END IF
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
   END TRY

   ' Cleanup
   pDatabase = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
