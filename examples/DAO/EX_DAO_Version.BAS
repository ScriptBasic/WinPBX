' ########################################################################################
' This example retrieves the version number of the database engine.
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

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   PRINT "Version: " & pDbEngine.Version
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
