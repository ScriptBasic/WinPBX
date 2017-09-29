' ########################################################################################
' This example enumerates the workspaces of the database engine.
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
   LOCAL pWorkSpace AS DAOWorkSpace       ' Pointer to the Workspace object
   LOCAL nCount AS LONG                   ' Number of workspaces
   LOCAL i AS LONG                        ' Loop counter

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Get a reference to the Workspaces collection
      pWorkSpaces = pDbEngine.Workspaces
      IF ISNOTHING(pWorkSpaces) THEN EXIT TRY
      ' Retrieve the number of workspaces
      nCount = pWorkspaces.Count
      ' Enumerate the workspaces
      FOR i = 0 TO nCount - 1
         pWorkSpace = pWorkspaces.Item(i)
         IF ISOBJECT(pWorkSpace) THEN
            PRINT "Name: " & pWorkspace.Name
            PRINT "UserName: " & pWorkspace.UserName
            ' Release the Workspace object
            pWorkSpace = NOTHING
         END IF
      NEXT
      ' Release the workspaces collection
      pWorkSpaces = NOTHING
      ' Display built-in properties.
      PRINT "DBEngine Version: " & pDbEngine.Version
      PRINT "DBEngine LoginTimeout: " & STR$(pDbEngine.LoginTimeout)
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   END TRY

   ' Cleanup
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
