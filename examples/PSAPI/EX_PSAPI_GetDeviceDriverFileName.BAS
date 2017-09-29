' ========================================================================================
' Enumerating all device drivers.
' The main function obtains a list of load addresses by using the EnumDeviceDrivers
' function. For each address, main calls the PrintDeviceDriverFileName function passing
' to it the driver address.
' ========================================================================================

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "PSAPI.INC"

' ========================================================================================
' Displays the device driver file name
' ========================================================================================
SUB PrintDeviceDriverFileName (BYVAL dwImageBase AS DWORD)

    LOCAL szFileName AS ASCIIZ * %MAX_PATH

    PRINT "Driver address: ", dwImageBase;
    GetDeviceDriverFileName dwImageBase, szFileName, SIZEOF(szFileName)
    PRINT szFileName

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   DIM   aDrivers(0 TO 1023) AS DWORD
   LOCAL cbNeeded AS DWORD
   LOCAL cAddresses AS DWORD
   LOCAL i AS LONG

   '// Get the list of device drivers addresses
   IF ISFALSE EnumDeviceDrivers(aDrivers(LBOUND(aDrivers)), _
      (UBOUND(aDrivers) - LBOUND(adrivers) + 1) * 4, cbNeeded) THEN EXIT FUNCTION

   '// Calculate how many addresses were returned
   cAddresses = cbNeeded \ 4

   '// Print the base names of the drivers
   FOR i = 0 TO cAddresses - 1
      PrintDeviceDriverFileName aDrivers(i)
   NEXT

   WAITKEY$

END FUNCTION
' ========================================================================================
