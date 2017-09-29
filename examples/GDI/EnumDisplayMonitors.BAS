' ########################################################################################
' Enumerates display monitors.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Callback function for EnumDisplayMonitors
' ========================================================================================
FUNCTION MonitorEnumProc (BYVAL hMonitor AS DWORD, BYVAL hdcMonitor AS LONG, BYREF lprcMonitor AS RECT, BYVAL dwData AS DWORD) AS LONG

   LOCAL tmi AS MONITORINFO
   LOCAL rc AS RECT

   PRINT "hMonitor = " hMonitor
   ' Initialize the MONITORINFO structure
   tmi.cbSize = SIZEOF(tmi)
   ' Get the monitor information of the specified monitor
   GetMonitorInfo hMonitor, tmi
   ' Write some information on teh debug window
   PRINT "Monitor width: " FORMAT$(tmi.rcMonitor.nRight - tmi.rcMonitor.nLeft)
   PRINT "Monitor height: " FORMAT$(tmi.rcMonitor.nBottom - tmi.rcMonitor.nTop)
   PRINT "Primary monitor: " & IIF$(tmi.dwFlags = %MONITORINFOF_PRIMARY, "Yes", "No")
   ' Check whether the point (0, 0) lies within the bounds of this monitor
   IF MonitorFromXY(0, 0, %MONITOR_DEFAULTTONEAREST) = hMonitor THEN
      PRINT "The point (0, 0) lies wihthin the range of this monitor..."
   END IF
   ' Continue enumeration
   MonitorEnumProc = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   EnumDisplayMonitors BYVAL %NULL, BYVAL %NULL, BYVAL CODEPTR(MonitorEnumProc), BYVAL 0
   WAITKEY$

END FUNCTION
' ========================================================================================
