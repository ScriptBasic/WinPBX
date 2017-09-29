' ########################################################################################
' This example creates a new snapshot-type Recordset object and opens it, appending it to
' the Recordsets collection in the default database. It then finds a record and displays it.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine          ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase          ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset        ' Pointer to the Recordset object
   LOCAL pFields AS DAOFields              ' Pointer to the Fields collection
   LOCAL pField AS DAOField                ' Pointer to the Field object
   LOCAL vValue AS VARIANT                 ' Value

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open recordset on Authors table
      pRecordset = pDatabase.OpenRecordset("Authors", %dbOpenSnapshot)
      IF pRecordset.RecordCount > 0 THEN
         pRecordset.FindFirst("Author Like '*CA*'")
         DO
            IF ISTRUE pRecordset.NoMatch THEN EXIT DO
            vValue = pRecordset.Collect("Author")
            PRINT VARIANT$$(vValue)
            pRecordset.FindNext("Author Like '*CA*'")
         LOOP
      END IF
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
