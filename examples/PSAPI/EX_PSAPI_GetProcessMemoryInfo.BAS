' ========================================================================================
' Collecting memory usage information for a process.
' This is a translation of an example included in the MSDN documentation for PSAPI.
' ========================================================================================

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "PSAPI.INC"

' ========================================================================================
' Displays the information
' ========================================================================================
SUB PrintMemoryInfo (BYVAL processID AS DWORD)

   LOCAL hProcess AS DWORD
   LOCAL pmc AS PROCESS_MEMORY_COUNTERS

   '// Print the process identifier
   PRINT "Process ID: " processID

   '// Print information about the memory usage of the process.
   hProcess = Openprocess (%PROCESS_QUERY_INFORMATION OR _
                           %PROCESS_VM_READ, %FALSE, processID)

   IF hProcess = 0 THEN EXIT SUB

   IF (GetProcessMemoryInfo(hProcess, pmc, SIZEOF(pmc))) THEN
      PRINT "PageFaultCount: ", pmc.PageFaultCount
      PRINT "PeakWorkinSetSize: ", pmc.PeakWorkingSetSize
      PRINT "WorkingSetSize: "pmc.WorkingSetSize
      PRINT "QuotaPeakPagegPoolUsage: ", pmc.QuotaPeakPagedPoolUsage
      PRINT "QuotaPagedPoolUsage: ", pmc.QuotaPagedPoolUsage
      PRINT "QuotaPeakNonPagedPoolUsage: ", pmc.QuotaPeakNonPagedPoolUsage
      PRINT "QuotaNonPagedPoolUsage: ", pmc.QuotaNonPagedPoolUsage
      PRINT "PageFileUsage: ", pmc.PageFileUsage
      PRINT "PeakPageFileUsage: ", pmc.PeakPageFileUsage
   END IF

   CloseHandle hProcess

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   DIM   aProcesses(0 TO 1023) AS DWORD
   LOCAL cbNeeded AS DWORD
   LOCAL cProcesses AS DWORD
   LOCAL i AS LONG

   '// Get the list of process identifiers
   IF ISFALSE EnumProcesses(aProcesses(LBOUND(aProcesses)), _
      (UBOUND(aProcesses) - LBOUND(aProcesses) + 1) * 4, cbNeeded) THEN EXIT FUNCTION

   '// Calculate how many process identifiers were returned.
   cProcesses = cbNeeded \ 4

   '// Print the memory usage for each process
   FOR i= 0 TO cProcesses - 1
      PrintMemoryInfo aProcesses(i)
   NEXT

   WAITKEY$

END FUNCTION
' ========================================================================================
