' ########################################################################################
' Parses the Properties collection
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
   LOCAL pProperties AS DAOProperties     ' Pointer to the Properties collection
   LOCAL pProperty AS DAOProperty         ' Pointer to the Property object
   LOCAL nCount AS LONG                   ' Number of objects in the collection
   LOCAL i AS LONG                        ' Loop counter variable

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Create Microsoft Jet Workspace object
      pWrkMain = pDBEngine.CreateWorkSpace("", "admin", "", %dbUseJet)
      ' Open the Database
      pDatabase = pWrkMain.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Enumerate the Properties collection of the Database object.
      PRINT "Database properties for " & pDatabase.Name
      pProperties = pDatabase.Properties
      IF ISNOTHING(pProperties) THEN EXIT TRY
      ' Get the number of properties
      nCount = pProperties.Count
      ' Parse the Properties collection
      FOR i = 0 TO nCount - 1
         ' Get a reference to the property object
         pProperty = pProperties.Item(i)
         IF ISOBJECT(pProperty) THEN
            ' Show the name of the property
            PRINT pProperty.Name
            pProperty = NOTHING
         END IF
      NEXT
      pProperties = NOTHING
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
      ' Close the Workspace
      IF ISOBJECT(pWrkMain) THEN pWrkMain.Close
   END TRY

   ' Cleanup
   pDatabase = NOTHING
   pWrkMain = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
