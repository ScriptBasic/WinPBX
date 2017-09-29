' ########################################################################################
' Microsoft Windows
' File: hidsdi.inc
' Contents: Public definitions for the code that implements the HID dll.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HIDSDI_INC = 1

'#include <pshpack4.h>

'//#include "wtypes.h"

'//#include <windef.h>
'//#include <win32.h>
'//#include <basetyps.h>

'typedef LONG NTSTATUS;
#INCLUDE ONCE "hidusage.inc"
#INCLUDE ONCE "hidpi.inc"

' // Size = 12 bytes
TYPE HIDD_CONFIGURATION BYTE
   cookie         AS DWORD   ' PVOID
   size           AS DWORD   ' ULONG
   RingBufferSize AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE HIDD_ATTRIBUTES BYTE
   Size          AS DWORD   ' ULONG // = sizeof (struct _HIDD_ATTRIBUTES)
   ' // Vendor ids of this hid device
   VendorID      AS WORD    ' USHORT
   ProductID     AS WORD    ' USHORT
   VersionNumber AS WORD    ' USHORT
   ' // Additional fields will be added to the end of this structure.
   alignment__   AS WORD    ' // To keep DWORD alignment
END TYPE

DECLARE FUNCTION HidD_GetAttributes LIB "Hid.dll" ALIAS "HidD_GetAttributes" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Attributes AS HIDD_ATTRIBUTES _                ' __out PHIDD_ATTRIBUTES Attributes
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Fill in the given HIDD_ATTRIBUTES structure with the attributes of the
'    given hid device.

'--*/

DECLARE SUB HidD_GetHidGuid LIB "Hid.dll" ALIAS "HidD_GetHidGuid" ( _
   BYREF HidGuid AS GUID _                              ' __out LPGUID HidGuid
 )                                                      ' void

DECLARE FUNCTION HidD_GetPreparsedData LIB "Hid.dll" ALIAS "HidD_GetPreparsedData" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF PreparsedData AS DWORD _                       ' __out __drv_when(return!=0, __drv_allocatesMem(Mem)) PHIDP_PREPARSED_DATA  * PreparsedData
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Given a handle to a valid Hid Class Device Object, retrieve the preparsed
'    data for the device.  This routine will allocate the appropriately
'    sized buffer to hold this preparsed data.  It is up to client to call
'    HidP_FreePreparsedData to free the memory allocated to this structure when
'    it is no longer needed.

'Arguments:
'   HidDeviceObject A handle to a Hid Device that the client obtains using
'                   a call to CreateFile on a valid Hid device string name.
'                   The string name can be obtained using standard PnP calls.

'   PreparsedData   An opaque data structure used by other functions in this
'                   library to retrieve information about a given device.

'Return Value:
'   TRUE if successful.
'   FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_FreePreparsedData LIB "Hid.dll" ALIAS "HidD_FreePreparsedData" ( _
   BYVAL PreparsedData AS DWORD _                       ' __in __drv_freesMem(Mem) PHIDP_PREPARSED_DATA PreparsedData
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION HidD_FlushQueue LIB "Hid.dll" ALIAS "HidD_FlushQueue" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Flush the input queue for the given HID device.

'Arguments:
'   HidDeviceObject A handle to a Hid Device that the client obtains using
'                   a call to CreateFile on a valid Hid device string name.
'                   The string name can be obtained using standard PnP calls.

'Return Value:
'   TRUE if successful
'   FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetConfiguration LIB "Hid.dll" ALIAS "HidD_GetConfiguration" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Configuration AS HIDD_CONFIGURATION _          ' __out_bcount(ConfigurationLength) PHIDD_CONFIGURATION Configuration
 , BYVAL ConfigurationLength AS DWORD _                 ' __in ULONG ConfigurationLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Get the configuration information for this Hid device

'Arguments:
'   HidDeviceObject      A handle to a Hid Device Object.

'   Configuration        A configuration structure.  HidD_GetConfiguration MUST
'                        be called before the configuration can be modified and
'                        set using HidD_SetConfiguration

'   ConfigurationLength  That is ``sizeof (HIDD_CONFIGURATION)''. Using this
'                        parameter, we can later increase the length of the
'                        configuration array and not break older apps.

'Return Value:
'   TRUE if successful
'   FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_SetConfiguration LIB "Hid.dll" ALIAS "HidD_SetConfiguration" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Configuration AS HIDD_CONFIGURATION _          ' __in_bcount(ConfigurationLength) PHIDD_CONFIGURATION Configuration,
 , BYVAL ConfigurationLength AS DWORD _                 ' __in ULONG ConfigurationLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'   Set the configuration information for this Hid device...

'   NOTE: HidD_GetConfiguration must be called to retrieve the current
'         configuration information before this information can be modified
'         and set.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Configuration        A configuration structure.  HidD_GetConfiguration MUST
'                         be called before the configuration can be modified and
'                         set using HidD_SetConfiguration

'    ConfigurationLength  That is ``sizeof (HIDD_CONFIGURATION)''. Using this
'                         parameter, we can later increase the length of the
'                         configuration array and not break older apps.

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetFeature LIB "Hid.dll" ALIAS "HidD_GetFeature" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF ReportBuffer AS ANY _                          ' __out_bcount(ReportBufferLength) PVOID ReportBuffer
 , BYVAL ReportBufferLength AS DWORD _                  ' __in ULONG ReportBufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Retrieve a feature report from a HID device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    ReportBuffer         The buffer that the feature report should be placed
'                         into.  The first byte of the buffer should be set to
'                         the report ID of the desired report

'    ReportBufferLength   The size (in bytes) of ReportBuffer.  This value
'                         should be greater than or equal to the
'                         FeatureReportByteLength field as specified in the
'                         HIDP_CAPS structure for the device
'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_SetFeature LIB "Hid.dll" ALIAS "HidD_SetFeature" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF ReportBuffer AS ANY _                          ' __in_bcount(ReportBufferLength) PVOID ReportBuffer
 , BYVAL ReportBufferLength AS DWORD _                  ' __in ULONG ReportBufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Send a feature report to a HID device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    ReportBuffer         The buffer of the feature report to send to the device

'    ReportBufferLength   The size (in bytes) of ReportBuffer.  This value
'                         should be greater than or equal to the
'                         FeatureReportByteLength field as specified in the
'                         HIDP_CAPS structure for the device
'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

'#if (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION HidD_GetInputReport LIB "Hid.dll" ALIAS "HidD_GetInputReport" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF ReportBuffer AS ANY _                          ' __out_bcount(ReportBufferLength) PVOID ReportBuffer
 , BYVAL ReportBufferLength AS DWORD _                  ' __in ULONG ReportBufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Retrieve an input report from a HID device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    ReportBuffer         The buffer that the input report should be placed
'                         into.  The first byte of the buffer should be set to
'                         the report ID of the desired report

'    ReportBufferLength   The size (in bytes) of ReportBuffer.  This value
'                         should be greater than or equal to the
'                         InputReportByteLength field as specified in the
'                         HIDP_CAPS structure for the device
'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_SetOutputReport LIB "Hid.dll" ALIAS "HidD_SetOutputReport" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF ReportBuffer AS ANY _                          ' __in_bcount(ReportBufferLength) PVOID ReportBuffer
 , BYVAL ReportBufferLength AS DWORD _                  ' __in ULONG ReportBufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    Send an output report to a HID device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    ReportBuffer         The buffer of the output report to send to the device

'    ReportBufferLength   The size (in bytes) of ReportBuffer.  This value
'                         should be greater than or equal to the
'                         OutputReportByteLength field as specified in the
'                         HIDP_CAPS structure for the device
'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

'#endif

DECLARE FUNCTION HidD_GetNumInputBuffers LIB "Hid.dll" ALIAS "HidD_GetNumInputBuffers" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF NumberBuffers AS DWORD _                       ' __out PULONG NumberBuffers
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function returns the number of input buffers used by the specified
'    file handle to the Hid device.  Each file object has a number of buffers
'    associated with it to queue reports read from the device but which have
'    not yet been read by the user-mode app with a handle to that device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    NumberBuffers        Number of buffers currently being used for this file
'                         handle to the Hid device

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_SetNumInputBuffers LIB "Hid.dll" ALIAS "HidD_SetNumInputBuffers" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYVAL NumberBuffers AS DWORD _                       ' __in ULONG NumberBuffers
 ) AS BYTE                                              ' BOOLEAN

'/*++

'Routine Description:
'    This function sets the number of input buffers used by the specified
'    file handle to the Hid device.  Each file object has a number of buffers
'    associated with it to queue reports read from the device but which have
'    not yet been read by the user-mode app with a handle to that device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    NumberBuffers        New number of buffers to use for this file handle to
'                         the Hid device

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetPhysicalDescriptor LIB "Hid.dll" ALIAS "HidD_GetPhysicalDescriptor" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves the raw physical descriptor for the specified
'    Hid device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Buffer               Buffer which on return will contain the physical
'                         descriptor if one exists for the specified device
'                         handle

'    BufferLength         Length of buffer (in bytes)


'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetManufacturerString LIB "Hid.dll" ALIAS "HidD_GetManufacturerString" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves the manufacturer string from the specified
'    Hid device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Buffer               Buffer which on return will contain the manufacturer
'                         string returned from the device.  This string is a
'                         wide-character string

'    BufferLength         Length of Buffer (in bytes)


'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetProductString LIB "Hid.dll" ALIAS "HidD_GetProductString" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves the product string from the specified
'    Hid device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Buffer               Buffer which on return will contain the product
'                         string returned from the device.  This string is a
'                         wide-character string

'    BufferLength         Length of Buffer (in bytes)


'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetIndexedString LIB "Hid.dll" ALIAS "HidD_GetIndexedString" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYVAL StringIndex AS DWORD _                         ' __in ULONG StringIndex
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves a string from the specified Hid device that is
'    specified with a certain string index.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    StringIndex          Index of the string to retrieve

'    Buffer               Buffer which on return will contain the product
'                         string returned from the device.  This string is a
'                         wide-character string

'    BufferLength         Length of Buffer (in bytes)

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

DECLARE FUNCTION HidD_GetSerialNumberString LIB "Hid.dll" ALIAS "HidD_GetSerialNumberString" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves the serial number string from the specified
'    Hid device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Buffer               Buffer which on return will contain the serial number
'                         string returned from the device.  This string is a
'                         wide-character string

'    BufferLength         Length of Buffer (in bytes)

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/

'#if (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION HidD_GetMsGenreDescriptor LIB "Hid.dll" ALIAS "HidD_GetMsGenreDescriptor" ( _
   BYVAL HidDeviceObject AS DWORD _                     ' __in HANDLE HidDeviceObject
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLength) PVOID Buffer
 , BYVAL BufferLength AS DWORD _                        ' __in ULONG BufferLength
 ) AS BYTE                                              ' BOOLEAN

'/*++
'Routine Description:
'    This function retrieves the Microsoft Genre descriptor from the specified
'    Hid device.

'Arguments:
'    HidDeviceObject      A handle to a Hid Device Object.

'    Buffer               Buffer which on return will contain the descriptor
'                         returned from the device.

'    BufferLength         Length of Buffer (in bytes)

'Return Value:
'    TRUE if successful
'    FALSE otherwise  -- Use GetLastError() to get extended error information
'--*/
'#endif


'#include <poppack.h>
