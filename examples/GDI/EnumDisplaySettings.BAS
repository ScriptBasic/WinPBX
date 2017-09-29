' ########################################################################################
' Retrieves information about all the graphics modes for a display device.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL bResult AS LONG
   LOCAL dv AS DEVMODE
   LOCAL dwMode AS DWORD

   DO
      bResult = EnumDisplaySettings(BYVAL %NULL, dwMode, dv)
      IF bResult = 0 THEN EXIT LOOP
      PRINT "Screen width/height: ";
      PRINT FORMAT$(dv.dmPelsWidth) "x";
      PRINT FORMAT$(dv.dmPelsHeight) " pixels ";
      PRINT "Color depth: " FORMAT$(dv.dmBitsPerPel) " bits per pixel"
      dwMode = dwMode + 1
   LOOP

   WAITKEY$

END FUNCTION
' ========================================================================================
