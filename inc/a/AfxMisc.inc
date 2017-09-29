' ########################################################################################
' Microsoft Windows
' File: AfxMisc.inc
' Contents: Miscellaneous wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXMISC_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "WMI.inc"

' ========================================================================================
' Retrieves the baseboard (also known as a motherboard or system board) serial number.
' ========================================================================================
FUNCTION AfxGetBaseBoardSerialNumber () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSerialNumber AS VARIANT                    ' // String

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SerialNumber FROM Win32_BaseBoard"
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
' Retrieves the Bios serial number
' ========================================================================================
FUNCTION AfxGetBiosSerialNumber () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSerialNumber AS VARIANT                    ' // String

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SerialNumber FROM Win32_BIOS"
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
' Retrieves the manufacturer serial number
' Requires Windows Vista+.
' ========================================================================================
FUNCTION AfxGetManufacturerSerialNumber () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSerialNumber AS VARIANT                    ' // String

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SerialNumber FROM Win32_PhysicalMedia"
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
' Retrieves the disk drive serial number
' Requires Windows Vista+.
' ========================================================================================
FUNCTION AfxGetDiskDriveSerialNumber () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL vSerialNumber AS VARIANT                    ' // String

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SerialNumber FROM Win32_DiskDrive"
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
' Retrieves the address width of the processor. On a 32-bit operating system, the value is
' 32 and on a 64-bit operating system it is 64. This function can be used to determine if
' the processor is 32 or 64 bit.
' ========================================================================================
FUNCTION AfxGetAddressWidth () AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL wAddressWidth AS WORD                       ' // uint16

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT AddressWidth FROM Win32_Processor"
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
   OBJECT GET oItem.AddressWidth TO wAddressWidth
   FUNCTION = wAddressWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the system running on the Windows-based computer. The following list identifiers
' the returned value: "X86-based PC", "MIPS-based PC", "Alpha-based PC", "Power PC",
' "SH-x PC", "StrongARM PC", "64-bit Intel PC", "64-bit Alpha PC", "Unknown", "X86-Nec98 PC".
' ========================================================================================
FUNCTION AfxGetSystemType () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL bstrSystemType AS WSTRING                   ' // System type

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT SystemType FROM Win32_ComputerSystem"
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
   OBJECT GET oItem.SystemType TO bstrSystemType
   FUNCTION = bstrSystemType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the architecture of the operating system, as opposed to the processor.
' Example: 32-bit. Windows Server 2003, Windows 2000, Windows NT 4.0, Windows XP, and
' Windows Me/98/95: This property is not available.
' ========================================================================================
FUNCTION AfxGetOSArchitecture () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL bstrArchitecture AS WSTRING                 ' // Architecture

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT OSArchitecture FROM Win32_OperatingSystem"
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
   OBJECT GET oItem.OSArchitecture TO bstrArchitecture
   FUNCTION = bstrArchitecture

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of the computer in use, such as laptop, desktop, or Tablet.
' Windows Server 2003, Windows XP, Windows 2000, Windows NT 4.0, and Windows Me/98/95:
' This property is not available.
' Value   Meaning
' ------- --------------------------------------------
' 0 (&H0) Unspecified
' 1 (&H1) Desktop
' 2 (&H2) Mobile
' 3 (&H3) Workstation
' 4 (&H4) Enterprise Server
' 5 (&H5) Small Office and Home Office (SOHO) Server
' 6 (&H6) Appliance PC
' 7 (&H7) Performance Server
' 8 (&H8) Maximum
' ========================================================================================
FUNCTION AfxGetPCSystemType () AS WORD

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL wPCSystemType AS WORD                       ' // uint16

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT PCSystemType FROM Win32_ComputerSystem"
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
   OBJECT GET oItem.PCSystemType TO wPCSystemType
   FUNCTION = wPCSystemType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks if the computer is part of a domain.
' Return value: If TRUE, the computer is part of a domain. If FALSE, the computer is not
' in a domain or the status is unknown. If you unjoin the computer from a domain, the
' value becomes false.
' ========================================================================================
FUNCTION AfxIsPartOfDomain () AS BYTE

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL bPartOfDomain AS BYTE                       ' // boolean

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT PartOfDomain FROM Win32_ComputerSystem"
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
   OBJECT GET oItem.PartOfDomain TO bPartOfDomain
   FUNCTION = bPartOfDomain

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the domain or workgroup to which a computer belongs.
' If the computer is not part of a domain, then the name of the workgroup is returned.
' If you need to run in both domain-based and workgroup-based environments, you might
' encounter problems using the %USERDOMAIN% environment variable because if the computer
' is not part of a domain, it returns the name of the local computer instead of the
' name of the workgroup.
' ========================================================================================
FUNCTION AfxGetDomainOrWorkGroup () AS WSTRING

   LOCAL hr AS LONG                                  ' // HRESULT
   LOCAL pService AS ISWbemServices                  ' // Services object
   LOCAL pObjectSet AS ISWbemObjectSet               ' // ISWbemObjectSet interface
   LOCAL pEnum AS IEnumVariant                       ' // Generic collection's enumerator reference
   LOCAL bstrDisplayName AS WSTRING                  ' // Display name
   LOCAL bstrQuery AS WSTRING                        ' // Query string
   LOCAL oItem AS DISPATCH                           ' // Generic object variable
   LOCAL vItem AS VARIANT                            ' // Generic object variant
   LOCAL bstrDomainOrWorkGroup AS WSTRING            ' // Domain or workgroup name

   ' // Connect to WMI using a moniker
   bstrDisplayName = "winmgmts:{impersonationLevel=impersonate}!\\.\root\CIMV2"
   pService = WmiGetObject(bstrDisplayName)
   IF ISNOTHING(pService) THEN EXIT FUNCTION

   ' // Execute a query to get a reference to the collection of objects
   bstrQuery = "SELECT Domain FROM Win32_ComputerSystem"
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
   OBJECT GET oItem.Domain TO bstrDomainOrWorkGroup
   FUNCTION = bstrDomainOrWorkGroup

END FUNCTION
' ========================================================================================
