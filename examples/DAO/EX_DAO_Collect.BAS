' ########################################################################################
' This example shows how to update a record using the undocumented Collect property.
' In the example, it is equivalent to:
'    pFields = pRecordset.Fields
'    pField = pFields.Item("Year Born")
'    pField.Value = 1950
'    pField = NOTHING
'    pFields = NOTHING
' SED_PBCC - Use the PBCC compiler
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEngine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset       ' Pointer to the Recordset object
   LOCAL SqlStr AS WSTRING                ' SQL string

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open a recordset
      SqlStr = "SELECT * FROM Authors Where Author = 'Wolf, Rich'"
      pRecordset = pDatabase.OpenRecordset(SqlStr, %dbOpenDynaset)
      IF pRecordset.RecordCount > 0 AND ISTRUE pRecordset.Updatable THEN
         pRecordset.Edit
         pRecordset.Collect("Year Born") = 1950
         pRecordset.Update %dbUpdateRegular
         PRINT "Record updated"
      ELSE
         PRINT "No such author or table not updatable"
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
