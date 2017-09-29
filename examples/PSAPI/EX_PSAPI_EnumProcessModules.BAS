' ========================================================================================
' Enumerating all modules for a process.
' This is a translation of an example included in the MSDN documentation for PSAPI.
' ========================================================================================

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "PSAPI.INC"

' ========================================================================================
' Displays the modules
' ========================================================================================
SUB PrintModules (BYVAL processID AS DWORD)

   DIM   hMods(0 TO 1023) AS DWORD
   LOCAL hProcess AS DWORD
   LOCAL cbNeeded AS DWORD
   LOCAL i AS LONG
   LOCAL szModName AS ASCIIZ * %MAX_PATH

   '// Print the process identifier.
   PRINT "Process ID: ", processID

   '// Get a list of all the modules in this process.
   hProcess = Openprocess (%PROCESS_QUERY_INFORMATION OR _
                           %PROCESS_VM_READ, %FALSE, processID)
   IF hProcess = 0 THEN EXIT SUB

   IF ISFALSE EnumProcessModules(hProcess, hMods(LBOUND(hMods)), _
      (UBOUND(hMods) - LBOUND(hMods) + 1) * 4, cbNeeded) THEN EXIT SUB

   FOR i = 0 TO cbNeeded \ 4
      '// Get full path to the module's file
      IF GetModuleFileNameEx(hProcess, hMods(i), szModName, SIZEOF(szModName)) THEN
         '// Print the module name and handle value.
         PRINT szModName, hMods(i)
      END IF
   NEXT

   CloseHandle hProcess

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   DIM aProcesses(1024) AS DWORD
   LOCAL cbNeeded AS DWORD
   LOCAL cProcesses AS DWORD
   LOCAL i AS LONG

   IF ISFALSE EnumProcesses(aProcesses(LBOUND(aProcesses)), _
      (UBOUND(aProcesses) - LBOUND(aProcesses) + 1) * 4, cbNeeded) THEN EXIT FUNCTION

   '// Calculate how many process identifiers were returned.
   cProcesses = cbNeeded \ 4

   '// Print the name of the module for each process.

   FOR i = 0 TO cProcesses - 1
      PrintModules aProcesses(i)
   NEXT

   WAITKEY$

END FUNCTION
' ========================================================================================
