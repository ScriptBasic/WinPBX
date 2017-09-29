' ########################################################################################
' This example creates a query based on the Authors table.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset       ' Pointer to the Recordset object
   LOCAL pQueryDef AS DAOQueryDef         ' Pointer to the QueryDef object
   LOCAL vRes AS VARIANT                  ' General purpose variant

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Create a query
      pQueryDef = pDatabase.CreateQueryDef("Name selection")
      IF ISNOTHING(pQueryDef) THEN EXIT TRY
      pQueryDef.SQL = "SELECT * FROM Authors WHERE Author > 'WA'"
      pRecordset = pQueryDef.OpenRecordset(%dbOpenSnapshot)
      IF ISNOTHING(pRecordset) THEN EXIT TRY
      ' While not at the end of the recordset...
      WHILE NOT pRecordset.EOF
         ' Get the content of the "Author" column
         vRes = pRecordset.Collect("Author")
         PRINT VARIANT$$(vRes)
         ' Fetch the next row
         pRecordset.MoveNext
      WEND
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the recordset
      IF ISOBJECT(pRecordset) THEN pRecordset.Close
      IF ISOBJECT(pQueryDef) THEN
         ' Close the query
         pQueryDef.Close
         ' Delete the query
         pDatabase.QueryDefs.Delete("Name selection")
      END IF
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
   END TRY

   ' Cleanup
   pRecordset = NOTHING
   pDatabase = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
