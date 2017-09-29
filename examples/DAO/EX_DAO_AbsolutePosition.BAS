' ########################################################################################
' AbsolutePosition and PercentPosition example
' This example positions the current record to the nth record in a dynaset-type Recordset object.
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
   LOCAL SqlStr AS WSTRING                ' SQL string
   LOCAL vRes AS VARIANT                  ' General purpose variant

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open a recordset
      SqlStr = "SELECT * FROM Authors"
      pRecordset = pDatabase.OpenRecordset(SqlStr, %dbOpenDynaset, %dbOpenDynaset)
      ' Move the cursor to the last record to fetch all the records
      pRecordset.MoveLast
      ' Set the absolute position in the 11th record (is zero based)
      pRecordset.AbsolutePosition = 10
      ' Print the value of the Author field
      vRes = pRecordset.Collect("Author")
      PRINT VARIANT$$(vRes)
      PRINT "Percent position: " & STR$(pRecordset.PercentPosition) & "%"
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the recordset
      IF ISOBJECT(pRecordset) THEN pRecordset.Close
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
