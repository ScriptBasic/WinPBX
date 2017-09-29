' ========================================================================================
' Enumerating all device drivers.
' The main function obtains a list of load addresses by using the EnumDeviceDrivers
' function. For each address, main calls the PrintDeviceDriverbaseName function passing
' to it the driver address.
' ========================================================================================

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "PSAPI.INC"

' ========================================================================================
' Displays the device driver address and base name
' ========================================================================================
SUB PrintDeviceDriverBaseName (BYVAL dwImageBase AS DWORD)

    LOCAL szBaseName AS ASCIIZ * %MAX_PATH

    PRINT "Driver address: ", dwImageBase;
    GetDeviceDriverBaseName dwImageBase, szBaseName, SIZEOF(szBaseName)
    PRINT szBaseName

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
      PrintDeviceDriverBaseName aDrivers(i)
   NEXT

   WAITKEY$

END FUNCTION
' ========================================================================================
