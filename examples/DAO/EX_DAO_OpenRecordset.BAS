' ########################################################################################
' Creates a recordset and parses it.
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
   LOCAL pWrkMain AS DAOWorkspace         ' Pointer to the main Workspace object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset       ' Pointer to the Recordset object
   LOCAL SqlStr AS WSTRING                ' SQL string
   LOCAL vRes AS VARIANT                  ' General purpose variant

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Create Microsoft Jet Workspace object
      pWrkMain = pDBEngine.CreateWorkSpace("", "admin", "", %dbUseJet)
      ' Open the Database
      pDatabase = pWrkMain.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open a recordset
      SqlStr = "SELECT * FROM Authors ORDER BY Author"
      pRecordset = pDatabase.OpenRecordset(SqlStr, %dbOpenDynaset, %dbReadOnly)
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
      ' Close the Workspace
      IF ISOBJECT(pWrkMain) THEN pWrkMain.Close
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
   END TRY

   ' Cleanup
   pRecordset = NOTHING
   pWrkMain = NOTHING
   pDatabase = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
