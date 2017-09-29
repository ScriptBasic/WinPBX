' ########################################################################################
' CreateDatabase example
' This example creates a new Database object and opens it (thereby appending it to the
' Databases collection) in the default Workspace object. Then enumerates the Containers
' collection and closes the new Database.
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
   LOCAL pWorkSpaces AS DAOWorkSpaces     ' Pointer to the Workspaces collection
   LOCAL pWorkDefault AS DAOWorkSpace     ' Pointer to the default workspace object
   LOCAL pNewDatabase AS DAODatabase      ' Pointer to a new database object
   LOCAL pDatabases AS DAODatabases       ' Pointer to the Databases collection
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pContainers AS DAOContainers     ' Pointer to the Containers collection
   LOCAL pContainer AS DAOContainer       ' Pointer to a Container object
   LOCAL nDatabases AS LONG               ' Number of databases
   LOCAL nContainers AS LONG              ' Number of containers
   LOCAL i AS LONG                        ' Loop counter
   LOCAL j AS LONG                        ' Loop counter

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Get a reference to the Workspaces collection
      pWorkSpaces = pDbEngine.Workspaces
      IF ISNOTHING(pWorkSpaces) THEN EXIT TRY
      ' Get a reference to the default workspace
      pWorkDefault = pWorkSpaces.Item(0)
      IF ISNOTHING(pWorkDefault) THEN EXIT TRY
      ' Create a new database
      pNewDatabase = pWorkDefault.CreateDatabase("New.mdb", $dbLangGeneral)
      IF ISNOTHING(pNewDatabase) THEN EXIT TRY
      ' Get a reference to the databases collection
      pDatabases = pWorkDefault.Databases
      IF ISNOTHING(pDatabases) THEN EXIT TRY
      nDatabases = pDatabases.Count
      FOR i = 0 TO nDatabases - 1
         pDatabase = pDatabases.Item(i)
         IF ISOBJECT(pDatabase) THEN
            PRINT "Database name: " & pDatabase.Name
            ' Enumerate containers
            pContainers = pDatabase.Containers
            IF ISOBJECT(pContainers) THEN
               nContainers = pContainers.Count
               FOR j = 0 to nContainers - 1
                  ' Get a reference to the Container object
                  pContainer = pContainers.Item(j)
                  IF ISOBJECT(pContainer) THEN
                     PRINT "Container Name: " & pContainer.Name
                     ' Release the Container object
                     pContainer = NOTHING
                  END IF
               NEXT
               ' Release the Containers collection
               pContainers = NOTHING
            END IF
            ' Release the database
            pDatabase = NOTHING
         END IF
      NEXT
      pDatabases = NOTHING
      ' Release the collection
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the database
      IF ISOBJECT(pNewDatabase) THEN
         pNewDatabase.Close
         pNewDatabase = NOTHING
      END IF
   END TRY

   ' Cleanup
   pWorkDefault = NOTHING
   pWorkSpaces = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
