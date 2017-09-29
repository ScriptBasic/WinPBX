' ########################################################################################
' Enumerates all display the devices in the system.
' ########################################################################################

' SED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL bResult AS LONG
   LOCAL dwDevEnum AS LONG
   LOCAL dv AS DISPLAY_DEVICE
   LOCAL strFlag AS STRING
   LOCAL strDeviceName AS STRING

   dv.cb = SIZEOF(dv)
   DO
      ' Retrieve information about the display device adapter
      bResult = EnumDisplayDevices (BYVAL %NULL, dwDevEnum, dv, 0)
      IF bResult = 0 THEN EXIT DO
      PRINT "Device name: " dv.DeviceName
      PRINT "Device string: " dv.DeviceString
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_ATTACHED_TO_DESKTOP, "Yes", "No")
      PRINT " - Attached to desktop: " strFlag
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_PRIMARY_DEVICE, "Yes", "No")
      PRINT " - Primary device: " strFlag
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_MIRRORING_DRIVER, "Yes", "No")
      PRINT " - Mirroring driver: Yes" strFlag
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_VGA_COMPATIBLE, "Yes", "No")
      PRINT " - VGA compatible: Yes" strFlag
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_REMOVABLE, "Yes", "No")
      PRINT " - Removable: Yes" strFlag
      strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_MODESPRUNED, "Yes", "No")
      PRINT " - Modes pruned: " strFlag
      ' By calling EnumDisplayDevices once again, this time specifying
      ' the retrieved device name and an index of zero, the same call returns
      ' information about the monitor connected to the specified device.
      strDeviceName = dv.DeviceName
      bResult = EnumDisplayDevices (BYCOPY strDeviceName, 0, dv, 0)
      IF bResult THEN
         PRINT "Monitor name: " dv.DeviceName
         PRINT "Monitor string: " dv.DeviceString
         strFlag = IIF$ (dv.StateFlags AND %DISPLAY_DEVICE_MULTI_DRIVER, "Yes", "No")
         PRINT " - Multidriver: " strFlag
      END IF
      ' Increment the index
      dwDevEnum = dwDevEnum + 1
   LOOP

   WAITKEY$

END FUNCTION
' ========================================================================================
