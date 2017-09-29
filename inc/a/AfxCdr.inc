' ########################################################################################
' Microsoft Windows
' File: AfxCdr.inc
' Contents: CDROM wrapper functions
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXCDROM_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "propvarutil.inc"
#INCLUDE ONCE "AfxVarToStr.inc"
#INCLUDE ONCE "WMI.inc"

' ========================================================================================
' Availability and status of the specified CDROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomAvailability (BYVAL bstrDriveLetter AS WSTRING) AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vAvailability AS VARIANT                    ' // Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Availability FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Availability TO vAvailability
   FUNCTION = CWRD(VARIANT#(vAvailability))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Array of capabilities of the media access device. For example, the device may support
' random access (3), removable media (7), and automatic cleaning (9).
' ========================================================================================
FUNCTION AfxGetCDRomCapabilities (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vCapabilities AS VARIANT                    ' // Array - Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Capabilities FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Capabilities TO vCapabilities
   FUNCTION = AfxVarToStr(vCapabilities)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Array of more detailed explanations for any of the access device features indicated in
' the Capabilities array. Each entry of this array is related to the entry in the
' Capabilities array that is located at the same index.
' ========================================================================================
FUNCTION AfxGetCDRomCapabilityDescriptions (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vCapabilityDescriptions AS VARIANT          ' // Array - String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Capabilities, CapabilityDescriptions FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.CapabilityDescriptions TO vCapabilityDescriptions
   FUNCTION = AfxVarToStr(vCapabilityDescriptions)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Short description of the CDROM—a one-line string.
' ========================================================================================
FUNCTION AfxGetCDRomCaption (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vCaption AS VARIANT                         ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Caption FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Caption TO vCaption
   FUNCTION = VARIANT$$(vCaption)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Algorithm or tool used by the device to support compression.
' ========================================================================================
FUNCTION AfxGetCDRomCompressionMethod (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vCompressionMethod AS VARIANT               ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT CompressionMethod FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.CompressionMethod TO vCompressionMethod
   FUNCTION = VARIANT$$(vCompressionMethod)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Configuration Manager error code.
' ========================================================================================
FUNCTION AfxGetCDRomConfigManagerErrorCode (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vConfigManagerErrorCode AS VARIANT          ' // Unsigned 32-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT ConfigManagerErrorCode FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.ConfigManagerErrorCode TO vConfigManagerErrorCode
   FUNCTION = VARIANT#(vConfigManagerErrorCode)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, the device is using a user-defined configuration.
' ========================================================================================
FUNCTION AfxGetCDRomConfigManagerUserConfig (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vConfigManagerUserConfig AS VARIANT         ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT ConfigManagerUserConfig FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.ConfigManagerUserConfig TO vConfigManagerUserConfig
   FUNCTION = CINT(VARIANT#(vConfigManagerUserConfig))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Default block size, in bytes, for this device.
' ========================================================================================
FUNCTION AfxGetCDRomDefaultBlockSize (BYVAL bstrDriveLetter AS WSTRING) AS QUAD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vDefaultBlockSize AS VARIANT                ' // Unsigned 64-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT DefaultBlockSize FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.DefaultBlockSize TO vDefaultBlockSize
   FUNCTION = VAL(VARIANT$$(vDefaultBlockSize))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Description of the CDROM.
' ========================================================================================
FUNCTION AfxGetCDRomDescription (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vDescription AS VARIANT                     ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Description FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Description TO vDescription
   FUNCTION = VARIANT$$(vDescription)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Unique identifier for a CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomDeviceID (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vDeviceID AS VARIANT                        ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT DeviceID FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.DeviceID TO vDeviceID
   FUNCTION = VARIANT$$(vDeviceID)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, files can be accurately read from the CD device.
' ========================================================================================
FUNCTION AfxGetCDRomDriveIntegrity (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vDriveIntegrity AS VARIANT                  ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT DriveIntegrity FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.DriveIntegrity TO vDriveIntegrity
   FUNCTION = CINT(VARIANT#(vDriveIntegrity))

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, the error reported in LastErrorCode is now cleared.
' ========================================================================================
FUNCTION AfxGetCDRomErrorCleared (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vErrorCleared AS VARIANT                    ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT ErrorCleared FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.ErrorCleared TO vErrorCleared
   FUNCTION = CINT(VARIANT#(vErrorCleared))

END FUNCTION
' ========================================================================================

' ========================================================================================
' More information about the error recorded in LastErrorCode, and information about
' corrective actions that can be taken.
' ========================================================================================
FUNCTION AfxGetCDRomErrorDescription (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vErrorDescription AS VARIANT                ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT ErrorDescription FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.ErrorDescription TO vErrorDescription
   FUNCTION = VARIANT$$(vErrorDescription)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Type of error detection and correction supported by this device.
' ========================================================================================
FUNCTION AfxGetCDRomErrorMethodology (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vErrorMethodology AS VARIANT                ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT ErrorMethodology FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.ErrorMethodology TO vErrorMethodology
   FUNCTION = VARIANT$$(vErrorMethodology)

END FUNCTION
' ========================================================================================

' ========================================================================================
' File system flags associated with the Windows CD-ROM drive. This parameter can be any
' combination of flags, but FS_FILE_COMPRESSION and FS_VOL_IS_COMPRESSED are mutually exclusive.
' ========================================================================================
'FUNCTION AfxGetCDRomFileSystemFlagsEx (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

'   LOCAL hr AS LONG                                  ' // HRESULT
'   LOCAL pService AS ISWbemServices                  ' // Services object
'   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
'   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
'   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
'   LOCAL bstrQuery AS WSTRING                        ' // Query string
'   LOCAL oItem AS DISPATCH                           ' // Generic object variable
'   LOCAL vItem AS VARIANT                            ' // Generic object variant
'   LOCAL vFileSystemFlagsEx AS VARIANT               ' // Unsigned 32-bit integer

'   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
'   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
'   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
'   bstrDriveLetter += ":"

'   ' // Connect to WMI using a moniker
'   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
'   pService = WmiGetObject(bstrDisplayName)
'   IF ISNOTHING(pService) THEN EXIT FUNCTION

'   ' // Execute a query to get a reference to the collection of objects
'   bstrQuery = "SELECT FileSystemFlagsEx FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
'   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
'   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

'   ' // Retrieve a reference to the collection's enumerator
'   pEnum = pObjectSet.NewEnum_
'   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
'   hr = pEnum.Next(1, vItem, BYVAL %NULL)
'   IF hr <> %S_OK THEN EXIT FUNCTION
'   oItem = vItem
'   vItem = EMPTY
'   IF ISNOTHING(oItem) THEN EXIT FUNCTION

'   ' // Retrieve the value of the property
'   OBJECT GET oItem.FileSystemFlagsEx TO vFileSystemFlagsEx
'   FUNCTION = VARIANT#(vFileSystemFlagsEx)

'END FUNCTION
' ========================================================================================

' ========================================================================================
' File system flags associated with the Windows CD-ROM drive. This parameter can be any
' combination of flags, but FS_FILE_COMPRESSION and FS_VOL_IS_COMPRESSED are mutually exclusive.
' ========================================================================================
FUNCTION AfxGetCDRomFileSystemFlags (BYVAL bstrDriveLetter AS WSTRING) AS DWORD
   LOCAL r AS LONG
   LOCAL dwFileSystemFlags AS DWORD
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYS") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   r = GetVolumeInformationW(BYCOPY bstrDriveLetter, BYVAL %NULL, 0, 0, 0, dwFileSystemFlags, BYVAL %NULL, 0)
   FUNCTION = dwFileSystemFlags
END FUNCTION
' ========================================================================================

' ========================================================================================
' Date and time the object is installed. This property does not need a value to indicate
' that the object is installed.
' ========================================================================================
FUNCTION AfxGetCDRomInstallDate (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vInstallDate AS VARIANT                     ' // Date/time value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT InstallDate FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.InstallDate TO vInstallDate
   FUNCTION = VARIANT$$(vInstallDate)

END FUNCTION
' ========================================================================================

' ========================================================================================
' File system flags associated with the Windows CD-ROM drive. This parameter can be any
' combination of flags, but FS_FILE_COMPRESSION and FS_VOL_IS_COMPRESSED are mutually exclusive.
' ========================================================================================
FUNCTION AfxGetCDRomLastErrorCode (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vLastErrorCode AS VARIANT                   ' // Unsigned 32-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT LastErrorCode FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.LastErrorCode TO vLastErrorCode
   FUNCTION = VARIANT#(vLastErrorCode)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Manufacturer of the Windows CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomManufacturer (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vManufacturer AS VARIANT                    ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Manufacturer FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Manufacturer TO vManufacturer
   FUNCTION = VARIANT$$(vManufacturer)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum block size, in bytes, for media accessed by this device.
' ========================================================================================
FUNCTION AfxGetCDRomMaxBlockSize (BYVAL bstrDriveLetter AS WSTRING) AS QUAD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMaxBlockSize AS VARIANT                    ' // Unsigned 64-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MaxBlockSize FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MaxBlockSize TO vMaxBlockSize
   FUNCTION = VAL(VARIANT$$(vMaxBlockSize))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum length of a filename component supported by the Windows CD-ROM drive. A file
' name component the portion of a file name between backslashes. The value can be used to
' indicate that long names are supported by the specified file system. For example, for a
' FAT file system supporting long names, the function stores the value 255, rather than
' the previous 8.3 indicator. Long names can also be supported on systems that use the
' NTFS file system.
' ========================================================================================
'FUNCTION AfxGetCDRomMaximumComponentLength (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

'   LOCAL hr AS LONG                                  ' // HRESULT
'   LOCAL pService AS ISWbemServices                  ' // Services object
'   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
'   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
'   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
'   LOCAL bstrQuery AS WSTRING                        ' // Query string
'   LOCAL oItem AS DISPATCH                           ' // Generic object variable
'   LOCAL vItem AS VARIANT                            ' // Generic object variant
'   LOCAL vMaximumComponentLength AS VARIANT          ' // Unsigned 32-bit integer

'   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
'   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
'   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
'   bstrDriveLetter += ":"

'   ' // Connect to WMI using a moniker
'   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
'   pService = WmiGetObject(bstrDisplayName)
'   IF ISNOTHING(pService) THEN EXIT FUNCTION

'   ' // Execute a query to get a reference to the collection of objects
'   bstrQuery = "SELECT MaximumComponentLength FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
'   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
'   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

'   ' // Retrieve a reference to the collection's enumerator
'   pEnum = pObjectSet.NewEnum_
'   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
'   hr = pEnum.Next(1, vItem, BYVAL %NULL)
'   IF hr <> %S_OK THEN EXIT FUNCTION
'   oItem = vItem
'   vItem = EMPTY
'   IF ISNOTHING(oItem) THEN EXIT FUNCTION

'   ' // Retrieve the value of the property
'   OBJECT GET oItem.MaximumComponentLength TO vMaximumComponentLength
'   FUNCTION = VARIANT#(vMaximumComponentLength)

'END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum length of a filename component supported by the Windows CD-ROM drive. A file
' name component the portion of a file name between backslashes. The value can be used to
' indicate that long names are supported by the specified file system. For example, for a
' FAT file system supporting long names, the function stores the value 255, rather than
' the previous 8.3 indicator. Long names can also be supported on systems that use the
' NTFS file system.
' ========================================================================================
FUNCTION AfxGetCDRomMaximumComponentLength (BYVAL bstrDriveLetter AS WSTRING) AS DWORD
   LOCAL r AS LONG
   LOCAL dwMaximumComponentLength AS DWORD
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYS") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   r = GetVolumeInformationW(BYCOPY bstrDriveLetter, BYVAL %NULL, 0, 0, dwMaximumComponentLength, 0, BYVAL %NULL, 0)
   FUNCTION = dwMaximumComponentLength
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum size, in kilobytes, of media supported by this device.
' ========================================================================================
FUNCTION AfxGetCDRomMaxMediaSize (BYVAL bstrDriveLetter AS WSTRING) AS QUAD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMaxMediaSize AS VARIANT                    ' // Unsigned 64-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MaxMediaSize FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MaxMediaSize TO vMaxMediaSize
   FUNCTION = VAL(VARIANT$$(vMaxMediaSize))

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, a CD-ROM is in the drive.
' ========================================================================================
FUNCTION AfxGetCDRomMediaLoaded (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMediaLoaded AS VARIANT                     ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MediaLoaded FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MediaLoaded TO vMediaLoaded
   FUNCTION = CINT(VARIANT#(vMediaLoaded))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Type of media that can be used or accessed by the device.
' ========================================================================================
FUNCTION AfxGetCDRomMediaType (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMediaType AS VARIANT                       ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MediaType FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MediaType TO vMediaType
   FUNCTION = VARIANT$$(vMediaType)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Firmware revision level that is assigned by the manufacturer.
' ========================================================================================
FUNCTION AfxGetCDRomMfrAssignedRevisionLevel (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMfrAssignedRevisionLevel AS VARIANT        ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MfrAssignedRevisionLevel FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MfrAssignedRevisionLevel TO vMfrAssignedRevisionLevel
   FUNCTION = VARIANT$$(vMfrAssignedRevisionLevel)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Minimum block size, in bytes, for media accessed by this device.
' ========================================================================================
FUNCTION AfxGetCDRomMinBlockSize (BYVAL bstrDriveLetter AS WSTRING) AS QUAD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vMinBlockSize AS VARIANT                    ' // Unsigned 64-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT MinBlockSize FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.MinBlockSize TO vMinBlockSize
   FUNCTION = VAL(VARIANT$$(vMinBlockSize))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the specified CDROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vName AS VARIANT                            ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Name FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Name TO vName
   FUNCTION = VARIANT$$(vName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, the media access device needs cleaning. Whether manual or automatic cleaning is
' possible is indicated in the Capabilities property.
' ========================================================================================
FUNCTION AfxGetCDRomNeedsCleaning (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vNeedsCleaning AS VARIANT                   ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT NeedsCleaning FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.NeedsCleaning TO vNeedsCleaning
   FUNCTION = CINT(VARIANT#(vNeedsCleaning))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Maximum number of media that can be supported or inserted, when the media access device
' supports multiple individual media.
' ========================================================================================
FUNCTION AfxGetCDRomNumberOfMediaSupported (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vNumberOfMediaSupported AS VARIANT          ' // Unsigned 32-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT NumberOfMediaSupported FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.NumberOfMediaSupported TO vNumberOfMediaSupported
   FUNCTION = VARIANT#(vNumberOfMediaSupported)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of CDROM drives installed.
' ========================================================================================
FUNCTION AfxGetCDRomNumDrives () AS LONG

   LOCAL i AS LONG
   LOCAL nDrives AS LONG
   FOR i = ASC("A") TO ASC("Z")
      IF GetDriveTypeW(CHR$$(i) & ":\") = %DRIVE_CDROM THEN nDrives += 1
   NEXT
   FUNCTION = nDrives

END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Plug and Play device identifier of the logical device.
' ========================================================================================
FUNCTION AfxGetCDRomPNPDeviceID (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vPNPDeviceID AS VARIANT                     ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT PNPDeviceID FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.PNPDeviceID TO vPNPDeviceID
   FUNCTION = VARIANT$$(vPNPDeviceID)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Array of the specific power-related capabilities of a logical device.
' ========================================================================================
FUNCTION AfxGetCDRomPowerManagementCapabilities (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vPowerManagementCapabilities AS VARIANT     ' // Array - Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT PowerManagementCapabilities FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.PowerManagementCapabilities TO vPowerManagementCapabilities
   FUNCTION = AfxVarToStr(vPowerManagementCapabilities)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If True, the device can be power-managed, which means that it can be put into suspend
' mode, and so on. The property does not indicate that power management features are
' currently enabled, only that the logical device is capable of power management.
' ========================================================================================
FUNCTION AfxGetCDRomPowerManagementSupported (BYVAL bstrDriveLetter AS WSTRING) AS INTEGER

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vPowerManagementSupported AS VARIANT        ' // Boolean value

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT PowerManagementSupported FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.PowerManagementSupported TO vPowerManagementSupported
   FUNCTION = CINT(VARIANT#(vPowerManagementSupported))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Firmware revision level of the Windows CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomRevisionLevel (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vRevisionLevel AS VARIANT                   ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT RevisionLevel FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.RevisionLevel TO vRevisionLevel
   FUNCTION = VARIANT$$(vRevisionLevel)

END FUNCTION
' ========================================================================================

' ========================================================================================
' SCSI bus number for the disk drive.
' ========================================================================================
FUNCTION AfxGetCDRomSCSIBus (BYVAL bstrDriveLetter AS WSTRING) AS DWORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSCSIBus AS VARIANT                         ' // Unsigned 32-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SCSIBus FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SCSIBus TO vSCSIBus
   FUNCTION = VARIANT#(vSCSIBus)

END FUNCTION
' ========================================================================================

' ========================================================================================
' SCSI logical unit number (LUN) of the disk drive. The LUN is used to designate which
' SCSI controller is being accessed in a system with more than one controller being used.
' The SCSI device identifier is similar, but is the designation for multiple devices on
' one controller.
' ========================================================================================
FUNCTION AfxGetCDRomSCSILogicalUnit (BYVAL bstrDriveLetter AS WSTRING) AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSCSILogicalUnit AS VARIANT                 ' // Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SCSILogicalUnit FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SCSILogicalUnit TO vSCSILogicalUnit
   FUNCTION = CWRD(VARIANT#(vSCSILogicalUnit))

END FUNCTION
' ========================================================================================

' ========================================================================================
' SCSI port number of the disk drive.
' ========================================================================================
FUNCTION AfxGetCDRomSCSIPort (BYVAL bstrDriveLetter AS WSTRING) AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSCSIPort AS VARIANT                        ' // Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SCSIPort FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SCSIPort TO vSCSIPort
   FUNCTION = CWRD(VARIANT#(vSCSIPort))

END FUNCTION
' ========================================================================================

' ========================================================================================
' SCSI identifier number of the Windows CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomSCSITargetId (BYVAL bstrDriveLetter AS WSTRING) AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSCSITargetId AS VARIANT                    ' // Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SCSITargetId FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SCSITargetId TO vSCSITargetId
   FUNCTION = CWRD(VARIANT#(vSCSITargetId))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Number supplied by the manufacturer that identifies the physical media.
' ========================================================================================
FUNCTION AfxGetCDRomSerialNumber (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSerialNumber AS VARIANT                    ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SerialNumber FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SerialNumber TO vSerialNumber
   FUNCTION = VARIANT$$(vSerialNumber)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Size of the disk drive, in bytes.
' ========================================================================================
FUNCTION AfxGetCDRomSize (BYVAL bstrDriveLetter AS WSTRING) AS QUAD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSize AS VARIANT                            ' // Unsigned 64-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Size FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Size TO vSize
   FUNCTION = VAL(VARIANT$$(vSize))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Current status of the object. Various operational and nonoperational statuses can be
' defined. Operational statuses include: "OK", "Degraded", and "Pred Fail" (an element,
' such as a SMART-enabled hard disk drive, may be functioning properly but predicting a
' failure in the near future). Nonoperational statuses include: "Error", "Starting",
' "Stopping", and "Service". The latter, "Service", could apply during mirror-resilvering
' of a disk, reload of a user permissions list, or other administrative work. Not all such
' work is online, yet the managed element is neither "OK" nor in one of the other states.
' ========================================================================================
FUNCTION AfxGetCDRomStatus (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vStatus AS VARIANT                          ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Status FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.Status TO vStatus
   FUNCTION = VARIANT$$(vStatus)

END FUNCTION
' ========================================================================================

' ========================================================================================
' State of the logical device.
' ========================================================================================
FUNCTION AfxGetCDRomStatusInfo (BYVAL bstrDriveLetter AS WSTRING) AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vStatusInfo AS VARIANT                      ' // Unsigned 16-bit integer

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT StatusInfo FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.StatusInfo TO vStatusInfo
   FUNCTION = CWRD(VARIANT#(vStatusInfo))

END FUNCTION
' ========================================================================================

' ========================================================================================
' Name of the scoping system.
' ========================================================================================
FUNCTION AfxGetCDRomSystemName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSystemName AS VARIANT                      ' // String

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SystemName FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.SystemName TO vSystemName
   FUNCTION = VARIANT$$(vSystemName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Transfer rate of the CD-ROM drive. A value of -1 indicates that the rate cannot be
' determined. When this happens, the CD is not in the drive. Units: KiloBytes per Second.
' ========================================================================================
FUNCTION AfxGetCDRomTransferRate (BYVAL bstrDriveLetter AS WSTRING) AS DOUBLE

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vTransferRate AS VARIANT                    ' // 64-bit real number

   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":"

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT TransferRate FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

   ' // Retrieve a reference to the collection's enumerator
   pEnum = pObjectSet.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   hr = pEnum.Next(1, vItem, BYVAL %NULL)
   IF hr <> %S_OK THEN EXIT FUNCTION
   oItem = vItem
   vItem = EMPTY
   IF ISNOTHING(oItem) THEN EXIT FUNCTION

   ' // Retrieve the value of the property
   OBJECT GET oItem.TransferRate TO vTransferRate
   FUNCTION = VARIANT#(vTransferRate)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Volume name of the Windows CD-ROM drive.
' ========================================================================================
'FUNCTION AfxGetCDRomVolumeName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

'   LOCAL hr AS LONG                                  ' // HRESULT
'   LOCAL pService AS ISWbemServices                  ' // Services object
'   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
'   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
'   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
'   LOCAL bstrQuery AS WSTRING                        ' // Query string
'   LOCAL oItem AS DISPATCH                           ' // Generic object variable
'   LOCAL vItem AS VARIANT                            ' // Generic object variant
'   LOCAL vVolumeName AS VARIANT                      ' // String

'   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
'   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
'   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
'   bstrDriveLetter += ":"

'   ' // Connect to WMI using a moniker
'   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
'   pService = WmiGetObject(bstrDisplayName)
'   IF ISNOTHING(pService) THEN EXIT FUNCTION

'   ' // Execute a query to get a reference to the collection of objects
'   bstrQuery = "SELECT VolumeName FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
'   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
'   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

'   ' // Retrieve a reference to the collection's enumerator
'   pEnum = pObjectSet.NewEnum_
'   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
'   hr = pEnum.Next(1, vItem, BYVAL %NULL)
'   IF hr <> %S_OK THEN EXIT FUNCTION
'   oItem = vItem
'   vItem = EMPTY
'   IF ISNOTHING(oItem) THEN EXIT FUNCTION

'   ' // Retrieve the value of the property
'   OBJECT GET oItem.VolumeName TO vVolumeName
'   FUNCTION = VARIANT$$(vVolumeName)

'END FUNCTION
' ========================================================================================

' ========================================================================================
' Volume name of the Windows CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomVolumeName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING
   LOCAL r AS LONG
   LOCAL wszVolumeNameBuffer AS WSTRINGZ * %MAX_PATH + 1
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   r = GetVolumeInformationW(BYCOPY bstrDriveLetter, wszVolumeNameBuffer, SIZEOF(wszVolumeNameBuffer), 0, 0, 0, BYVAL %NULL, 0)
   FUNCTION = wszVolumeNameBuffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Volume serial number of the media in the CD-ROM drive.
' ========================================================================================
'FUNCTION AfxGetCDRomVolumeSerialName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING

'   LOCAL hr AS LONG                                  ' // HRESULT
'   LOCAL pService AS ISWbemServices                  ' // Services object
'   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
'   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
'   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
'   LOCAL bstrQuery AS WSTRING                        ' // Query string
'   LOCAL oItem AS DISPATCH                           ' // Generic object variable
'   LOCAL vItem AS VARIANT                            ' // Generic object variant
'   LOCAL vVolumeSerialNumber AS VARIANT              ' // String

'   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
'   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
'   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
'   bstrDriveLetter += ":"

'   ' // Connect to WMI using a moniker
'   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
'   pService = WmiGetObject(bstrDisplayName)
'   IF ISNOTHING(pService) THEN EXIT FUNCTION

'   ' // Execute a query to get a reference to the collection of objects
'   bstrQuery = "SELECT VolumeSerialNumber FROM Win32_CDROMDrive WHERE Drive = '" & bstrDriveLetter & "'"
'   pObjectSet = pService.ExecQuery(bstrQuery, "WQL", %wbemFlagReturnImmediately)
'   IF ISNOTHING(pObjectSet) THEN EXIT FUNCTION

'   ' // Retrieve a reference to the collection's enumerator
'   pEnum = pObjectSet.NewEnum_
'   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
'   hr = pEnum.Next(1, vItem, BYVAL %NULL)
'   IF hr <> %S_OK THEN EXIT FUNCTION
'   oItem = vItem
'   vItem = EMPTY
'   IF ISNOTHING(oItem) THEN EXIT FUNCTION

'   ' // Retrieve the value of the property
'   OBJECT GET oItem.VolumeSerialNumber TO vVolumeSerialNumber
'   FUNCTION = VARIANT$$(vVolumeSerialNumber)

'END FUNCTION
' ========================================================================================

' ========================================================================================
' Volume serial number of the media in the CD-ROM drive.
' ========================================================================================
FUNCTION AfxGetCDRomVolumeSerialName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING
   LOCAL r AS LONG
   LOCAL dwVolumeSerialNumber AS DWORD
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   r = GetVolumeInformationW(BYCOPY bstrDriveLetter, BYVAL %NULL, 0, dwVolumeSerialNumber, 0, 0, BYVAL %NULL, 0)
   FUNCTION = HEX$(dwVolumeSerialNumber)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The name of the file system, for example, the FAT file system or the NTFS file system.
' ========================================================================================
FUNCTION AfxGetCDRomFileSystemName (BYVAL bstrDriveLetter AS WSTRING) AS WSTRING
   LOCAL r AS LONG
   LOCAL wszFileSystemName AS WSTRINGZ * %MAX_PATH + 1
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYS") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   r = GetVolumeInformationW(BYCOPY bstrDriveLetter, BYVAL %NULL, 0, 0, 0, 0, wszFileSystemName, SIZEOF(wszFileSystemName))
   FUNCTION = wszFileSystemName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns True (-1) if the specified drive is a CDROM drive; otherwise, False.
' ========================================================================================
FUNCTION AfxIsCDRomDrive (BYVAL bstrDriveLetter AS WSTRING) AS LONG
   IF LEN(bstrDriveLetter) = 0 THEN EXIT FUNCTION
   bstrDriveLetter = UCASE$(LEFT$(bstrDriveLetter, 1))
   IF INSTR(bstrDriveLetter, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
   bstrDriveLetter += ":\"
   IF GetDriveTypeW(BYCOPY bstrDriveLetter) = %DRIVE_CDROM THEN FUNCTION = -1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Closes the CDROM door. Returns 0 or an error code.
' ========================================================================================
#IF NOT %DEF(%WIN32_LEAN_AND_MEAN)
FUNCTION AfxSetCDRomDoorClosed (BYVAL bstrDriveLetter AS WSTRING) AS DWORD
   LOCAL dwErr AS DWORD
   IF LEN(bstrDriveLetter) = 0 THEN
      FUNCTION = %MCIERR_MISSING_PARAMETER
      EXIT FUNCTION
   END IF
   bstrDriveLetter = LEFT$(bstrDriveLetter, 1)
   dwErr = mciSendStringW("open " & bstrDriveLetter & " type cdaudio alias cdname", BYVAL %NULL, 0, BYVAL %NULL)
   IF dwErr = 0 THEN
      dwErr = mciSendStringW("set cdname door closed", BYVAL %NULL, 0, BYVAL %NULL)
      mciSendStringW("close cdname", BYVAL %NULL, 0, BYVAL %NULL)
   END IF
   FUNCTION = dwErr
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Opens the CDROM door. Returns 0 or an error code.
' ========================================================================================
#IF NOT %DEF(%WIN32_LEAN_AND_MEAN)
FUNCTION AfxSetCDRomDoorOpen (BYVAL bstrDriveLetter AS WSTRING) AS DWORD
   LOCAL dwErr AS DWORD
   IF LEN(bstrDriveLetter) = 0 THEN
      FUNCTION = %MCIERR_MISSING_PARAMETER
      EXIT FUNCTION
   END IF
   bstrDriveLetter = LEFT$(bstrDriveLetter, 1)
   dwErr = mciSendStringW("open " & bstrDriveLetter & " type cdaudio alias cdname", BYVAL %NULL, 0, BYVAL %NULL)
   IF dwErr = 0 THEN
      dwErr = mciSendStringW("set cdname door open", BYVAL %NULL, 0, BYVAL %NULL)
      mciSendStringW("close cdname", BYVAL %NULL, 0, BYVAL %NULL)
   END IF
   FUNCTION = dwErr
END FUNCTION
#ENDIF
' ========================================================================================
