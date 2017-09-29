' ========================================================================================
' Enumerating all processes.
' This is a translation of an example included in the MSDN documentation for PSAPI.
' ========================================================================================

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "PSAPI.INC"

' ========================================================================================
' Displays the processes
' ========================================================================================
SUB PrintProcessNameAndID (BYVAL processID AS DWORD)

   LOCAL szProcessName AS ASCIIZ * %MAX_PATH
   LOCAL hProcess AS DWORD
   LOCAL hMod AS DWORD
   LOCAL cbNeeded AS DWORD

   szProcessName = "unknown"
   '// Get a handle to the process.
   hProcess = OpenProcess(%PROCESS_QUERY_INFORMATION OR _
                          %PROCESS_VM_READ, %FALSE, processID)
   '// Get the process name.
   IF ISFALSE hProcess THEN EXIT SUB
   IF ISFALSE EnumProcessModules(hProcess, hMod, SIZEOF(hMod), cbNeeded) THEN EXIT SUB
   GetModuleBaseName hProcess, hMod, szProcessName, SIZEOF(szProcessName)

   '// Print the process name and identifier.
   PRINT "Process ID: ", szProcessName, processID

   CloseHandle hProcess

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   '// Get the list of process identifiers.
   DIM aProcesses(0 TO 1023) AS DWORD
   LOCAL cbNeeded AS DWORD
   LOCAL cProcesses AS DWORD
   LOCAL i AS DWORD

   IF ISFALSE EnumProcesses(aProcesses(LBOUND(aProcesses)), _
      (UBOUND(aProcesses) - LBOUND(aProcesses) + 1) * 4, cbNeeded) THEN EXIT FUNCTION

   '// Calculate how many process identifiers were returned.
   cProcesses = cbNeeded \ 4

   '// Print the name and process identifier for each process.

   FOR i = 0 TO cProcesses - 1
      PrintProcessNameAndId aProcesses(i)
   NEXT

   WAITKEY$

END FUNCTION
' ========================================================================================
