' ========================================================================================
' Demonstrates how to pass values to a method, how to call it and how to retrieve return
' values. Uses the "StdRegProv" class to retrieve the ProductName in the
' HKEY_LOCAL_MACHINE "Software\Microsoft\Windows NT\CurrentVersion" in the registry.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE "WMI.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL oReg AS DISPATCH                      ' // Dispatch object variable
   LOCAL bstrDisplayName AS WSTRING            ' // Display name
   LOCAL vDefKey AS VARIANT                    ' // Registry tree
   LOCAL vPath AS VARIANT                      ' // Registry path
   LOCAL vValue AS VARIANT                     ' // Key value
   LOCAL vResult AS VARIANT                    ' // Result
   LOCAL vRes AS VARIANT                       ' // General purpose variant

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\default:StdRegProv"
   oReg = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(oReg) THEN EXIT FUNCTION

   ' %HKEY_LOCAL_MACHINE - The value must be specified as an string and in decimal, not hexadecimal.
   vDefKey = "2147483650"
   vPath = "Software\Microsoft\Windows NT\CurrentVersion"
   vValue = "ProductName"

   TRY
      OBJECT CALL oReg.GetStringValue(vDefKey, vPath, vValue, vResult) TO vRes
      AfxShowMsg(VARIANT$(vResult))
   CATCH
      AfxShowMsg("Error " & HEX$(OBJRESULT) & $CRLF & WmiGetErrorCodeText(OBJRESULT))
   END TRY

END FUNCTION
' ========================================================================================
