' ########################################################################################
' Microsoft Windows
' File: BlueToothAPIs.inc
' Contents: Bluetooth APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BLUETOOTHAPIS_INC = 1

#INCLUDE ONCE "WINDOWS.INC"
#INCLUDE ONCE "BTHDEF.INC"
#INCLUDE ONCE "BTHSDPDEF.INC"

%BLUETOOTH_MAX_NAME_SIZE           = 248
%BLUETOOTH_MAX_PASSKEY_SIZE        = 16
%BLUETOOTH_MAX_PASSKEY_BUFFER_SIZE = %BLUETOOTH_MAX_PASSKEY_SIZE + 1
%BLUETOOTH_MAX_SERVICE_NAME_SIZE   = 256
%BLUETOOTH_DEVICE_NAME_SIZE        = 256

'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)

'// ***************************************************************************
'//
'//  Bluetooth Address
'//
'// ***************************************************************************

'typedef ULONGLONG BTH_ADDR;

'typedef struct _BLUETOOTH_ADDRESS {
'    union {
'        BTH_ADDR ullLong;       //  easier to compare again BLUETOOTH_NULL_ADDRESS
'        BYTE    rgBytes[ 6 ];   //  easier to format when broken out
'    };

'} BLUETOOTH_ADDRESS_STRUCT;

' // Size = 8 bytes
UNION BLUETOOTH_ADDRESS_UNION QWORD
   ullLong    AS QUAD  ' //  easier to compare again BLUETOOTH_NULL_ADDRESS
   rgBytes(5) AS BYTE  ' //  easier to format when broken out
END UNION

' // Size = 8 bytes
TYPE BLUETOOTH_ADDRESS QWORD
   BLUETOOTH_ADDRESS_UNION
END TYPE

'#define BLUETOOTH_ADDRESS BLUETOOTH_ADDRESS_STRUCT

'#define BLUETOOTH_NULL_ADDRESS ( (ULONGLONG) 0x0 )
%BLUETOOTH_NULL_ADDRESS = &H0&&

' // Size = 1040 bytes
TYPE BLUETOOTH_LOCAL_SERVICE_INFO QWORD
   Enabled        AS LONG                                          ' BOOL //  If TRUE, the enable the services
   btAddr         AS BLUETOOTH_ADDRESS                             ' BLUETOOTH_ADDRESS //  If service is to be advertised for a particular remote device
   szName         AS WSTRINGZ * %BLUETOOTH_MAX_SERVICE_NAME_SIZE   ' WCHAR szName[ BLUETOOTH_MAX_SERVICE_NAME_SIZE ];    //  SDP Service Name to be advertised.
   szDeviceString AS WSTRINGZ * %BLUETOOTH_DEVICE_NAME_SIZE        ' WCHAR szDeviceString[ BLUETOOTH_DEVICE_NAME_SIZE ]; //  Local device name (if any) like COM4 or LPT1
END TYPE

'// ***************************************************************************
'//
'//  Radio Enumeration
'//
'//  Description:
'//      This group of APIs enumerates the installed Bluetooth radios.
'//
'//  Sample Usage:
'//      HANDLE hRadio;
'//      BLUETOOTH_FIND_RADIO_PARAMS btfrp = { sizeof(btfrp) };
'//
'//      HBLUETOOTH_RADIO_FIND hFind = BluetoothFindFirstRadio( &btfrp, &hRadio );
'//      if ( NULL != hFind )
'//      {
'//          do
'//          {
'//              //
'//              //  TODO: Do something with the radio handle.
'//              //
'//
'//              CloseHandle( hRadio );
'//
'//          } while( BluetoothFindNextRadio( hFind, &hRadio ) );
'//
'//          BluetoothFindRadioClose( hFind );
'//      }
'//
'// ***************************************************************************

' // Size = 4 bytes
TYPE BLUETOOTH_FIND_RADIO_PARAMS DWORD
   dwSize AS DWORD   ' DWORD //  IN  sizeof this structure
END TYPE

'typedef HANDLE      HBLUETOOTH_RADIO_FIND;

'//
'//  Description:
'//      Begins the enumeration of local Bluetooth radios.
'//
'//  Parameters:
'//      pbtfrp
'//          A pointer to a BLUETOOTH_FIND_RADIO_PARAMS structure. The dwSize
'//          member of this structure must match the sizeof the of the structure.
'//
'//      phRadio
'//          A pointer where the first radio HANDLE enumerated will be returned.
'//
'//  Return Values:
'//      NULL
'//          Error opening radios or no devices found. Use GetLastError() for
'//          more info.
'//
'//          ERROR_INVALID_PARAMETER
'//              pbtfrp parameter is NULL.
'//
'//          ERROR_REVISION_MISMATCH
'//              The pbtfrp structure is not the right length.
'//
'//          ERROR_OUTOFMEMORY
'//              Out of memory.
'//
'//          other Win32 errors.
'//
'//      any other
'//          Success. The return handle is valid and phRadio points to a valid handle.
'//

DECLARE FUNCTION BluetoothFindFirstRadio IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindFirstRadio" ( _
   BYREF pbtfrp AS BLUETOOTH_FIND_RADIO_PARAMS _        ' __in  const BLUETOOTH_FIND_RADIO_PARAMS * pbtfrp
 , BYREF phRadio AS DWORD _                             ' __out HANDLE *                            phRadio
 ) AS DWORD                                             ' HBLUETOOTH_RADIO_FIND

'//
'//  Description:
'//      Finds the next installed Bluetooth radio.
'//
'//  Parameters:
'//      hFind
'//          The handle returned by BluetoothFindFirstRadio().
'//
'//      phRadio
'//          A pointer where the next radio HANDLE enumerated will be returned.
'//
'//  Return Values:
'//      TRUE
'//          Next device succesfully found. pHandleOut points to valid handle.
'//
'//      FALSE
'//          No device found. pHandleOut points to an invalid handle. Call
'//          GetLastError() for more details.
'//
'//          ERROR_INVALID_HANDLE
'//              The handle is NULL.
'//
'//          ERROR_NO_MORE_ITEMS
'//              No more radios found.
'//
'//          ERROR_OUTOFMEMORY
'//              Out of memory.
'//
'//          other Win32 errors
'//

DECLARE FUNCTION BluetoothFindNextRadio IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindNextRadio" ( _
   BYVAL hFind AS DWORD _                               ' __in  HBLUETOOTH_RADIO_FIND hFind
 , BYREF phRadio AS DWORD _                             ' __out HANDLE * phRadio
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Closes the enumeration handle.
'//
'//  Parameters
'//      hFind
'//          The handle returned by BluetoothFindFirstRadio().
'//
'//  Return Values:
'//      TRUE
'//          Handle succesfully closed.
'//
'//      FALSE
'//          Failure. Check GetLastError() for details.
'//
'//          ERROR_INVALID_HANDLE
'//              The handle is NULL.
'//

DECLARE FUNCTION BluetoothFindRadioClose IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindRadioClose" ( _
   BYVAL hFind AS DWORD _                               ' __in HBLUETOOTH_RADIO_FIND hFind
 ) AS LONG                                              ' BOOL

'// ***************************************************************************
'//
'//  Radio Information
'//
'// ***************************************************************************

'typedef struct _BLUETOOTH_RADIO_INFO {
'    DWORD dwSize;                               // Size, in bytes, of this entire data structure

'    BLUETOOTH_ADDRESS address;                  // Address of the local radio

'    WCHAR szName[ BLUETOOTH_MAX_NAME_SIZE ];    // Name of the local radio

'    ULONG ulClassofDevice;                      // Class of device for the local radio

'    USHORT lmpSubversion;                       // lmpSubversion, manufacturer specifc.
'    USHORT manufacturer;                        // Manufacturer of the radio, BTH_MFG_Xxx value.  For the most up to date
'                                                // list, goto the Bluetooth specification website and get the Bluetooth
'                                                // assigned numbers document.
'} BLUETOOTH_RADIO_INFO, *PBLUETOOTH_RADIO_INFO;

' // Size = 520 bytes
TYPE BLUETOOTH_RADIO_INFO   ' Must be 8 bytes aligned
   dwSize          AS DWORD                                   ' DWORD  // Size, in bytes, of this entire data structure
   filler_         AS DWORD                                   ' // To keep QWORD alignment
   address         AS BLUETOOTH_ADDRESS                       ' ASBLUETOOTH_ADDRESS // Address of the local radio
   szName          AS WSTRINGZ * %BLUETOOTH_MAX_NAME_SIZE     ' WCHAR  // Name of the local radio (496 bytes)
   ulClassofDevice AS DWORD                                   ' ULONG  // Class of device for the local radio
   lmpSubversion   AS WORD                                    ' USHORT // lmpSubversion, manufacturer specifc.
   manufacturer    AS WORD                                    ' USHORT // Manufacturer of the radio, BTH_MFG_Xxx value.  For the most up to date
                                                              '        // list, goto the Bluetooth specification website and get the Bluetooth
                                                              '        // assigned numbers document.
END TYPE

'//
'//  Description:
'//      Retrieves the information about the radio represented by the handle.
'//
'//  Parameters:
'//      hRadio
'//          Handle to a local radio retrieved through BluetoothFindFirstRadio()
'//          et al or SetupDiEnumerateDeviceInterfaces()
'//
'//      pRadioInfo
'//          Radio information to be filled in. The dwSize member must match the
'//          size of the structure.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The information was retrieved successfully.
'//
'//      ERROR_INVALID_PARAMETER
'//          pRadioInfo or hRadio is NULL.
'//
'//      ERROR_REVISION_MISMATCH
'//          pRadioInfo->dwSize is invalid.
'//
'//      other Win32 error codes.
'//

DECLARE FUNCTION BluetoothGetRadioInfo IMPORT "IRPROPS.CPL" ALIAS "BluetoothGetRadioInfo" ( _
   BYVAL hRadio AS DWORD _                              ' __in  HANDLE hRadio
 , BYREF pRadioInfo AS BLUETOOTH_RADIO_INFO _           ' __out PBLUETOOTH_RADIO_INFO pRadioInfo
 ) AS DWORD                                             ' DWORD

'// ***************************************************************************
'//
'//  Device Information Stuctures
'//
'// ***************************************************************************

'typedef struct _BLUETOOTH_DEVICE_INFO {
'    __field_range(==, sizeof(BLUETOOTH_DEVICE_INFO_STRUCT))
'    DWORD   dwSize;                             //  size, in bytes, of this structure - must be the sizeof(BLUETOOTH_DEVICE_INFO)

'    BLUETOOTH_ADDRESS Address;                  //  Bluetooth address

'    ULONG   ulClassofDevice;                    //  Bluetooth "Class of Device"

'    BOOL    fConnected;                         //  Device connected/in use
'    BOOL    fRemembered;                        //  Device remembered
'    BOOL    fAuthenticated;                     //  Device authenticated/paired/bonded

'    SYSTEMTIME  stLastSeen;                     //  Last time the device was seen
'    SYSTEMTIME  stLastUsed;                     //  Last time the device was used for other than RNR, inquiry, or SDP

'    WCHAR   szName[ BLUETOOTH_MAX_NAME_SIZE ];  //  Name of the device

'} BLUETOOTH_DEVICE_INFO_STRUCT;

' // Size = 560 bytes
TYPE BLUETOOTH_DEVICE_INFO   ' Must be 8 bytes aligned
   dwSize          AS DWORD                                   ' DWORD //  size, in bytes, of this structure - must be the sizeof(BLUETOOTH_DEVICE_INFO)
   filler_         AS DWORD                                   ' // To keep QWORD alignment
   Address         AS BLUETOOTH_ADDRESS                       ' BLUETOOTH_ADDRESS //  Bluetooth address
   ulClassofDevice AS DWORD                                   ' ULONG //  Bluetooth "Class of Device"
   fConnected      AS LONG                                    ' BOOL //  Device connected/in use
   fRemembered     AS LONG                                    ' BOOL //  Device remembered
   fAuthenticated  AS LONG                                    ' BOOL //  Device authenticated/paired/bonded
   stLastSeen      AS SYSTEMTIME                              ' SYSTEMTIME //  Last time the device was seen
   stLastUsed      AS SYSTEMTIME                              ' SYSTEMTIME //  Last time the device was used for other than RNR, inquiry, or SDP
   szName          AS WSTRINGZ * %BLUETOOTH_MAX_NAME_SIZE     ' WCHAR //  Name of the device
END TYPE

'#define BLUETOOTH_DEVICE_INFO BLUETOOTH_DEVICE_INFO_STRUCT

'typedef BLUETOOTH_DEVICE_INFO * PBLUETOOTH_DEVICE_INFO;

'//
'// Support added after KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

' enum BLUETOOTH_AUTHENTICATION_METHOD
%BLUETOOTH_AUTHENTICATION_METHOD_LEGACY               = &H1
%BLUETOOTH_AUTHENTICATION_METHOD_OOB                  = &H2
%BLUETOOTH_AUTHENTICATION_METHOD_NUMERIC_COMPARISON   = &H3
%BLUETOOTH_AUTHENTICATION_METHOD_PASSKEY_NOTIFICATION = &H4
%BLUETOOTH_AUTHENTICATION_METHOD_PASSKEY              = &H5

' enum BLUETOOTH_IO_CAPABILITY
%BLUETOOTH_IO_CAPABILITY_DISPLAYONLY                  = &H00
%BLUETOOTH_IO_CAPABILITY_DISPLAYYESNO                 = &H01
%BLUETOOTH_IO_CAPABILITY_KEYBOARDONLY                 = &H02
%BLUETOOTH_IO_CAPABILITY_NOINPUTNOOUTPUT              = &H03
%BLUETOOTH_IO_CAPABILITY_UNDEFINED                    = &Hff

' enum BLUETOOTH_AUTHENTICATION_REQUIREMENTS
%BLUETOOTH_MITM_ProtectionNotRequired                 = 0
%BLUETOOTH_MITM_ProtectionRequired                    = &H1
%BLUETOOTH_MITM_ProtectionNotRequiredBonding          = &H2
%BLUETOOTH_MITM_ProtectionRequiredBonding             = &H3
%BLUETOOTH_MITM_ProtectionNotRequiredGeneralBonding   = &H4
%BLUETOOTH_MITM_ProtectionRequiredGeneralBonding      = &H5
%BLUETOOTH_MITM_ProtectionNotDefined                  = &Hff

' // Size = 8 bytes
UNION BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS_UNION DWORD
   Numeric_Value AS DWORD   ' ULONG
   Passkey       AS DWORD   ' ULONG
END UNION

' // Size = 576 bytes
TYPE BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS   ' // Must be 8 bytes aligned
   deviceInfo                 AS BLUETOOTH_DEVICE_INFO
   authenticationMethod       AS LONG   ' BLUETOOTH_AUTHENTICATION_METHOD
   ioCapability               AS LONG   ' BLUETOOTH_IO_CAPABILITY
   authenticationRequirements AS LONG   ' BLUETOOTH_AUTHENTICATION_REQUIREMENTS
   BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS_UNION
END TYPE

'#endif // >= SP1+KB942567

'// ***************************************************************************
'//
'//  Device Enumeration
'//
'//  Description:
'//      Enumerates the Bluetooth devices. The types of returned device depends
'//      on the flags set in the BLUETOOTH_DEVICE_SEARCH_PARAMS (see structure
'//      definition for details).
'//
'//  Sample Usage:
'//      HBLUETOOTH_DEVICE_FIND hFind;
'//      BLUETOOTH_DEVICE_SEARCH_PARAMS btsp = { sizeof(btsp) };
'//      BLUETOOTH_DEVICE_INFO btdi = { sizeof(btdi) };
'//
'//      btsp.fReturnAuthenticated = TRUE;
'//      btsp.fReturnRemembered    = TRUE;
'//
'//      hFind = BluetoothFindFirstDevice( &btsp, &btdi );
'//      if ( NULL != hFind )
'//      {
'//          do
'//          {
'//              //
'//              //  TODO:   Do something useful with the device info.
'//              //
'//
'//          } while( BluetoothFindNextDevice( hFind, &btdi ) );
'//
'//          BluetoothFindDeviceClose( hFind );
'//      }
'//
'// ***************************************************************************

' // Size = 32 bytes
TYPE BLUETOOTH_DEVICE_SEARCH_PARAMS DWORD
   dwSize               AS DWORD   ' DWORD  // IN  sizeof this structure
   fReturnAuthenticated AS LONG    ' BOOL   // IN  return authenticated devices
   fReturnRemembered    AS LONG    ' BOOL   // IN  return remembered devices
   fReturnUnknown       AS LONG    ' BOOL   // IN  return unknown devices
   fReturnConnected     AS LONG    ' BOOL   // IN  return connected devices
   fIssueInquiry        AS LONG    ' BOOL   // IN  issue a new inquiry
   cTimeoutMultiplier   AS BYTE    ' UCHAR  // IN  timeout for the inquiry
   hRadio               AS DWORD   ' HANDLE // IN  handle to radio to enumerate - NULL == all radios will be searched
END TYPE

'typedef HANDLE      HBLUETOOTH_DEVICE_FIND;

'//
'//  Description:
'//      Begins the enumeration of Bluetooth devices.
'//
'//  Parameters:
'//      pbtsp
'//          A pointer to a BLUETOOTH_DEVICE_SEARCH_PARAMS structure. This
'//          structure contains the flags and inputs used to conduct the search.
'//          See BLUETOOTH_DEVICE_SEARCH_PARAMS for details.
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure to return information
'//          about the first Bluetooth device found. Note that the dwSize member
'//          of the structure must be the sizeof(BLUETOOTH_DEVICE_INFO) before
'//          calling because the APIs hast to know the size of the buffer being
'//          past in. The dwSize member must also match the exact
'//          sizeof(BLUETOOTH_DEVICE_INFO) or the call will fail.
'//
'//  Return Values:
'//      NULL
'//          Error opening radios or not devices found. Use GetLastError for more info.
'//
'//          ERROR_INVALID_PARAMETER
'//              pbtsp parameter or pbtdi parameter is NULL.
'//
'//          ERROR_REVISION_MISMATCH
'//              The pbtfrp structure is not the right length.
'//
'//          other Win32 errors
'//
'//      any other value
'//          Success. The return handle is valid and pbtdi points to valid data.
'//

DECLARE FUNCTION BluetoothFindFirstDevice IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindFirstDevice" ( _
   BYREF pbtsp AS BLUETOOTH_DEVICE_SEARCH_PARAMS _      ' __in  const BLUETOOTH_DEVICE_SEARCH_PARAMS * pbtsp
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __out BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS DWORD                                             ' HBLUETOOTH_DEVICE_FIND

'//
'//  Description:
'//      Finds the next Bluetooth device in the enumeration.
'//
'//  Parameters:
'//      hFind
'//          The handle returned from BluetoothFindFirstDevice().
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure to return information
'//          about the first Bluetooth device found. Note that the dwSize member
'//          of the structure must be the sizeof(BLUETOOTH_DEVICE_INFO) before
'//          calling because the APIs hast to know the size of the buffer being
'//          past in. The dwSize member must also match the exact
'//          sizeof(BLUETOOTH_DEVICE_INFO) or the call will fail.
'//
'//  Return Values:
'//      TRUE
'//          Next device succesfully found. pHandleOut points to valid handle.
'//
'//      FALSE
'//          No device found. pHandleOut points to an invalid handle. Call
'//          GetLastError() for more details.
'//
'//          ERROR_INVALID_HANDLE
'//              The handle is NULL.
'//
'//          ERROR_NO_MORE_ITEMS
'//              No more radios found.
'//
'//          ERROR_OUTOFMEMORY
'//              Out of memory.
'//
'//          other Win32 errors
'//

DECLARE FUNCTION BluetoothFindNextDevice IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindNextDevice" ( _
   BYVAL hFind AS DWORD _                               ' __in  HBLUETOOTH_DEVICE_FIND  hFind
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __out BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Closes the enumeration handle.
'//
'//  Parameters:
'//      hFind
'//          The handle returned from BluetoothFindFirstDevice().
'//
'//  Return Values:
'//      TRUE
'//          Handle succesfully closed.
'//
'//      FALSE
'//          Failure. Check GetLastError() for details.
'//
'//          ERROR_INVALID_HANDLE
'//              The handle is NULL.
'//

DECLARE FUNCTION BluetoothFindDeviceClose IMPORT "IRPROPS.CPL" ALIAS "BluetoothFindDeviceClose" ( _
   BYVAL hFind AS DWORD _                               ' __in HBLUETOOTH_DEVICE_FIND  hFind
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Retrieves information about a remote device.
'//
'//      Fill in the dwSize and the Address members of the pbtdi structure
'//      being passed in. On success, the rest of the members will be filled
'//      out with the information that the system knows.
'//
'//  Parameters:
'//      hRadio
'//          Handle to a local radio retrieved through BluetoothFindFirstRadio()
'//          et al or SetupDiEnumerateDeviceInterfaces()
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure to return information
'//          about the first Bluetooth device found. The dwSize member of the
'//          structure must be the sizeof the structure in bytes. The Address
'//          member must be filled out with the Bluetooth address of the remote
'//          device.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          Success. Information returned.
'//
'//      ERROR_REVISION_MISMATCH
'//          The size of the BLUETOOTH_DEVICE_INFO isn't compatible. Check
'//          the dwSize member of the BLUETOOTH_DEVICE_INFO structure you
'//          passed in.
'//
'//      ERROR_NOT_FOUND
'//          The radio is not known by the system or the Address field of
'//          the BLUETOOTH_DEVICE_INFO structure is all zeros.
'//
'//      ERROR_INVALID_PARAMETER
'//          pbtdi is NULL.
'//
'//      other error codes
'//

DECLARE FUNCTION BluetoothGetDeviceInfo IMPORT "IRPROPS.CPL" ALIAS "BluetoothGetDeviceInfo" ( _
   BYVAL hRadio AS DWORD _                              ' __in  HANDLE hRadio
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __out BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS DWORD                                             ' DWORD

'//
'//  Description:
'//      Updates the computer local cache about the device.
'//
'//  Parameters:
'//      pbtdi
'//          A pointer to the BLUETOOTH_DEVICE_INFO structure to be updated.
'//          The following members must be valid:
'//              dwSize
'//                  Must match the size of the structure.
'//              Address
'//                  Must be a previously found radio address.
'//              szName
'//                  New name to be stored.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The device information was updated successfully.
'//
'//      ERROR_INVALID_PARAMETER
'//          pbtdi is NULL.
'//
'//      ERROR_REVISION_MISMATCH
'//          pbtdi->dwSize is invalid.
'//
'//      other Win32 error codes.
'//

DECLARE FUNCTION BluetoothUpdateDeviceRecord IMPORT "IRPROPS.CPL" ALIAS "BluetoothUpdateDeviceRecord" ( _
   BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in const BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS DWORD                                             ' DWORD

'//
'//  Description:
'//      Delete the authentication (aka "bond") between the computer and the
'//      device. Also purges any cached information about the device.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The device was removed successfully.
'//
'//      ERROR_NOT_FOUND
'//          The device was not found. If no Bluetooth radio is installed,
'//          the devices could not be enumerated or removed.
'//

DECLARE FUNCTION BluetoothRemoveDevice IMPORT "IRPROPS.CPL" ALIAS "BluetoothRemoveDevice" ( _
   BYREF pAddress AS BLUETOOTH_ADDRESS _                ' __in const BLUETOOTH_ADDRESS * pAddress
 ) AS DWORD                                             ' DWORD

'// ***************************************************************************
'//
'//  Device Picker Dialog
'//
'//  Description:
'//      Invokes a common dialog for selecting Bluetooth devices. The list
'//      of devices displayed to the user is determined by the flags and
'//      settings the caller specifies in the BLUETOOTH_SELECT_DEVICE_PARAMS
'//      (see structure definition for more details).
'//
'//      If BluetoothSelectDevices() returns TRUE, the caller must call
'//      BluetoothSelectDevicesFree() or memory will be leaked within the
'//      process.
'//
'//  Sample Usage:
'//
'//      BLUETOOTH_SELECT_DEVICE_PARAMS btsdp = { sizeof(btsdp) };
'//
'//      btsdp.hwndParent = hDlg;
'//      btsdp.fShowUnknown = TRUE;
'//      btsdp.fAddNewDeviceWizard = TRUE;
'//
'//      BOOL b = BluetoothSelectDevices( &btsdp );
'//      if ( b )
'//      {
'//          BLUETOOTH_DEVICE_INFO * pbtdi = btsdp.pDevices;
'//          for ( ULONG cDevice = 0; cDevice < btsdp.cNumDevices; cDevice ++ )
'//          {
'//              if ( pbtdi->fAuthenticated || pbtdi->fRemembered )
'//              {
'//                  //
'//                  //  TODO:   Do something usefull with the device info
'//                  //
'//              }
'//
'//              pbtdi = (BLUETOOTH_DEVICE_INFO *) ((LPBYTE)pbtdi + pbtdi->dwSize);
'//          }
'//
'//          BluetoothSelectDevicesFree( &btsdp );
'//      }
'//
'// ***************************************************************************

' // Size = 8 bytes
TYPE BLUETOOTH_COD_PAIRS DWORD
   ulCODMask       AS DWORD          ' ULONG   //  ClassOfDevice mask to compare
   pcszDescription AS WSTRINGZ PTR   ' LPCWSTR //  Descriptive string of mask
END TYPE

'typedef BOOL (WINAPI *PFN_DEVICE_CALLBACK)(LPVOID pvParam, PBLUETOOTH_DEVICE_INFO pDevice);

' // Size = 60 bytes
TYPE BLUETOOTH_SELECT_DEVICE_PARAMS DWORD
   dwSize               AS DWORD                       ' DWORD  //  IN  sizeof this structure
   cNumOfClasses        AS DWORD                       ' ULONG  //  IN  Number in prgClassOfDevice - if ZERO search for all devices
   prgClassOfDevices    AS BLUETOOTH_COD_PAIRS PTR     ' BLUETOOTH_COD_PAIRS * //  IN  Array of CODs to find.
   pszInfo              AS WSTRINGZ PTR                ' LPWSTR //  IN  If not NULL, sets the "information" text
   hwndParent           AS DWORD                       ' HWND   //  IN  parent window - NULL == no parent
   fForceAuthentication AS LONG                        ' BOOL   //  IN  If TRUE, authenication will be forced before returning
   fShowAuthenticated   AS LONG                        ' BOOL   //  IN  If TRUE, authenticated devices will be shown in the picker
   fShowRemembered      AS LONG                        ' BOOL   //  IN  If TRUE, remembered devices will be shown in the picker
   fShowUnknown         AS LONG                        ' BOOL   //  IN  If TRUE, unknown devices that are not authenticated or "remember" will be shown.
   fAddNewDeviceWizard  AS LONG                        ' BOOL   //  IN  If TRUE, invokes the add new device wizard.
   fSkipServicesPage    AS LONG                        ' BOOL   //  IN  If TRUE, skips the "Services" page in the wizard.
   pfnDeviceCallback    AS DWORD                       ' PFN_DEVICE_CALLBACK //  IN  If non-NULL, a callback that will be called for each device. If the
                                                       '                     //  the callback returns TRUE, the item will be added. If the callback is
                                                       '                     //  is FALSE, the item will not be shown.
   pvParam              AS DWORD                       ' LPVOID //  IN  Parameter to be passed to pfnDeviceCallback as the pvParam.
   cNumDevices          AS DWORD                       ' DWORD  //  IN  number calles wants - ZERO == no limit.
                                                       '        //  OUT the number of devices returned.
   pDevices             AS BLUETOOTH_DEVICE_INFO PTR   ' PBLUETOOTH_DEVICE_INFO //  OUT pointer to an array for BLUETOOTH_DEVICE_INFOs.
                                                       '                        //      call BluetoothSelectDevicesFree() to free
END TYPE

'//
'//  Description:
'//      (See header above)
'//
'//  Return Values:
'//      TRUE
'//          User selected a device. pbtsdp->pDevices points to valid data.
'//          Caller should check the fAuthenticated && fRemembered flags to
'//          determine which devices we successfuly authenticated or valid
'//          selections by the user.
'//
'//          Use BluetoothSelectDevicesFree() to free the nessecary data
'//          such as pDevices only if this function returns TRUE.
'//
'//      FALSE
'//          No valid data returned. Call GetLastError() for possible details
'//          of the failure. If GLE() is:
'//
'//          ERROR_CANCELLED
'//              The user cancelled  the request.
'//
'//          ERROR_INVALID_PARAMETER
'//              The pbtsdp is NULL.
'//
'//          ERROR_REVISION_MISMATCH
'//              The structure passed in as pbtsdp is of an unknown size.
'//
'//          other WIN32 errors
'//

DECLARE FUNCTION BluetoothSelectDevices IMPORT "IRPROPS.CPL" ALIAS "BluetoothSelectDevices" ( _
   BYREF pbtsdp AS BLUETOOTH_SELECT_DEVICE_PARAMS _     ' __in BLUETOOTH_SELECT_DEVICE_PARAMS * pbtsdp
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      This function should only be called if BluetoothSelectDevices() returns
'//      TRUE. This function will free any memory and resource returned by the
'//      BluetoothSelectDevices() in the BLUETOOTH_SELECT_DEVICE_PARAMS
'//      structure.
'//
'//  Return Values:
'//      TRUE
'//          Success.
'//
'//      FALSE
'//          Nothing to free.
'//

DECLARE FUNCTION BluetoothSelectDevicesFree IMPORT "IRPROPS.CPL" ALIAS "BluetoothSelectDevicesFree" ( _
   BYREF pbtsdp AS BLUETOOTH_SELECT_DEVICE_PARAMS _     ' __in BLUETOOTH_SELECT_DEVICE_PARAMS * pbtsdp
 ) AS LONG                                              ' BOOL

'// ***************************************************************************
'//
'//  Device Property Sheet
'//
'// ***************************************************************************

'//
'//  Description:
'//      Invokes the CPLs device info property sheet.
'//
'//  Parameters:
'//      hwndParent
'//          HWND to parent the property sheet.
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure of the device
'//          to be displayed.
'//
'//  Return Values:
'//      TRUE
'//          The property page was successfully displayed.
'//
'//      FALSE
'//          Failure. The property page was not displayed. Check GetLastError
'//          for more details.
'//

DECLARE FUNCTION BluetoothDisplayDeviceProperties IMPORT "IRPROPS.CPL" ALIAS "BluetoothDisplayDeviceProperties" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __inout BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS LONG                                              ' BOOL

'// ***************************************************************************
'//
'//  Radio Authentication
'//
'// ***************************************************************************

'//
'//  Description:
'//      Sends an authentication request to a remote device.
'//
'//      There are two modes of operation. "Wizard mode" and "Blind mode."
'//
'//      "Wizard mode" is invoked when the pszPasskey is NULL. This will cause
'//      the "Bluetooth Connection Wizard" to be invoked. The user will be
'//      prompted to enter a passkey during the wizard after which the
'//      authentication request will be sent. The user will see the success
'//      or failure of the authentication attempt. The user will also be
'//      given the oppurtunity to try to fix a failed authentication.
'//
'//      "Blind mode" is invoked when the pszPasskey is non-NULL. This will
'//      cause the computer to send a authentication request to the remote
'//      device. No UI is ever displayed. The Bluetooth status code will be
'//      mapped to a Win32 Error code.
'//
'//  Parameters:
'//
'//      hwndParent
'//          The window to parent the authentication wizard. If NULL, the
'//          wizard will be parented off the desktop.
'//
'//      hRadio
'//          A valid local radio handle or NULL. If NULL, then all radios will
'//          be tired. If any of the radios succeed, then the call will
'//          succeed.
'//
'//      pbtdi
'//          BLUETOOTH_DEVICE_INFO record of the device to be authenticated.
'//
'//      pszPasskey
'//          PIN to be used to authenticate the device.  If NULL, then UI is
'//          displayed and the user steps through the authentication process.
'//          If not NULL, no UI is shown.  The passkey is NOT NULL terminated.
'//
'//      ulPasskeyLength
'//          Length of szPassKey in bytes. The length must be less than or
'//          equal to BLUETOOTH_MAX_PASSKEY_SIZE * sizeof(WCHAR).
'//
'//  Return Values:
'//
'//      ERROR_SUCCESS
'//          Success.
'//
'//      ERROR_CANCELLED
'//          User aborted the operation.
'//
'//      ERROR_INVALID_PARAMETER
'//          The device structure in pbtdi is invalid.
'//
'//      ERROR_NO_MORE_ITEMS
'//          The device in pbtdi is already been marked as authenticated.
'//
'//      other WIN32 error
'//          Failure. Return value is the error code.
'//
'//      For "Blind mode," here is the current mapping of Bluetooth status
'//      code to Win32 error codes:
'//
'//          { BTH_ERROR_SUCCESS,                ERROR_SUCCESS },
'//          { BTH_ERROR_NO_CONNECTION,          ERROR_DEVICE_NOT_CONNECTED },
'//          { BTH_ERROR_PAGE_TIMEOUT,           WAIT_TIMEOUT },
'//          { BTH_ERROR_HARDWARE_FAILURE,       ERROR_GEN_FAILURE },
'//          { BTH_ERROR_AUTHENTICATION_FAILURE, ERROR_NOT_AUTHENTICATED },
'//          { BTH_ERROR_MEMORY_FULL,            ERROR_NOT_ENOUGH_MEMORY },
'//          { BTH_ERROR_CONNECTION_TIMEOUT,     WAIT_TIMEOUT },
'//          { BTH_ERROR_LMP_RESPONSE_TIMEOUT,   WAIT_TIMEOUT },
'//          { BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS, ERROR_REQ_NOT_ACCEP },
'//          { BTH_ERROR_PAIRING_NOT_ALLOWED,    ERROR_ACCESS_DENIED },
'//          { BTH_ERROR_UNSPECIFIED_ERROR,      ERROR_NOT_READY },
'//          { BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION, ERROR_VC_DISCONNECTED },
'//

DECLARE FUNCTION BluetoothAuthenticateDevice IMPORT "IRPROPS.CPL" ALIAS "BluetoothAuthenticateDevice" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL hRadio AS DWORD _                              ' __in HANDLE hRadio
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in BLUETOOTH_DEVICE_INFO * pbtdi
 , BYREF pszPasskey AS WSTRINGZ _                       ' __in_ecount_opt(ulPasskeyLength) PWCHAR pszPasskey
 , BYVAL ulPasskeyLength AS DWORD _                     ' __in ULONG ulPasskeyLength
 ) AS DWORD                                             ' DWORD

'//
'// Support added after KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'//
'// Replaces previous API
'//
'#pragma deprecate("BluetoothAuthenticateDevice")

'//
'// Common header for all PIN related structures
'//

' // Size = 17 bytes
TYPE BLUETOOTH_PIN_INFO BYTE
   pin(%BTH_MAX_PIN_SIZE - 1) AS BYTE   ' UCHAR
   pinLength                  AS BYTE   ' UCHAR
END TYPE

' // Size = 32 bytes
TYPE BLUETOOTH_OOB_DATA_INFO BYTE
   C(15) AS BYTE   ' UCHAR
   R(15) AS BYTE   ' UCHAR
END TYPE

' // Size = 4 bytes
TYPE BLUETOOTH_NUMERIC_COMPARISON_INFO DWORD
   NumericValue AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE BLUETOOTH_PASSKEY_INFO DWORD
   passkey AS DWORD   ' ULONG
END TYPE

'//
'//  Description:
'//      Sends an authentication request to a remote device.
'//
'//      There are two modes of operation. "Wizard mode" and "Blind mode."
'//
'//      "Wizard mode" is invoked when the pbtOobData is NULL. This will cause
'//      the "Bluetooth Connection Wizard" to be invoked. The user will be
'//      prompted to respond to the device authentication during the wizard
'//      after which the authentication request will be sent. The user will see the success
'//      or failure of the authentication attempt. The user will also be
'//      given the oppurtunity to try to fix a failed authentication.
'//
'//      "Blind mode" is invoked when the pbtOobData is non-NULL. This will
'//      cause the computer to send a authentication request to the remote
'//      device. No UI is ever displayed. The Bluetooth status code will be
'//      mapped to a Win32 Error code.
'//
'//  Parameters:
'//
'//      hwndParent
'//          The window to parent the authentication wizard. If NULL, the
'//          wizard will be parented off the desktop.
'//
'//      hRadio
'//          A valid local radio handle or NULL. If NULL, then all radios will
'//          be tired. If any of the radios succeed, then the call will
'//          succeed.
'//
'//      pbtdi
'//          BLUETOOTH_DEVICE_INFO record of the device to be authenticated.
'//
'//      pbtOobData
'//          Out of band data to be used to authenticate the device.  If NULL, then UI is
'//          displayed and the user steps through the authentication process.
'//          If not NULL, no UI is shown.
'//
'//      authenticationRequirement
'//          The Authentication Requirement of the caller.  MITMProtection*
'//
'//
'//  Return Values:
'//
'//      ERROR_SUCCESS
'//          Success.
'//
'//      ERROR_CANCELLED
'//          User aborted the operation.
'//
'//      ERROR_INVALID_PARAMETER
'//          The device structure in pbtdi is invalid.
'//
'//      ERROR_NO_MORE_ITEMS
'//          The device in pbtdi is already been marked as authenticated.
'//
'//      other WIN32 error
'//          Failure. Return value is the error code.
'//
'//      For "Blind mode," here is the current mapping of Bluetooth status
'//      code to Win32 error codes:
'//
'//          { BTH_ERROR_SUCCESS,                ERROR_SUCCESS },
'//          { BTH_ERROR_NO_CONNECTION,          ERROR_DEVICE_NOT_CONNECTED },
'//          { BTH_ERROR_PAGE_TIMEOUT,           WAIT_TIMEOUT },
'//          { BTH_ERROR_HARDWARE_FAILURE,       ERROR_GEN_FAILURE },
'//          { BTH_ERROR_AUTHENTICATION_FAILURE, ERROR_NOT_AUTHENTICATED },
'//          { BTH_ERROR_MEMORY_FULL,            ERROR_NOT_ENOUGH_MEMORY },
'//          { BTH_ERROR_CONNECTION_TIMEOUT,     WAIT_TIMEOUT },
'//          { BTH_ERROR_LMP_RESPONSE_TIMEOUT,   WAIT_TIMEOUT },
'//          { BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS, ERROR_REQ_NOT_ACCEP },
'//          { BTH_ERROR_PAIRING_NOT_ALLOWED,    ERROR_ACCESS_DENIED },
'//          { BTH_ERROR_UNSPECIFIED_ERROR,      ERROR_NOT_READY },
'//          { BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION, ERROR_VC_DISCONNECTED },
'//

DECLARE FUNCTION BluetoothAuthenticateDeviceEx IMPORT "IRPROPS.CPL" ALIAS "BluetoothAuthenticateDeviceEx" ( _
   BYVAL hwndParentIn AS DWORD _                        ' __in_opt HWND hwndParentIn
 , BYVAL hRadioIn AS DWORD _                            ' __in HANDLE hRadioIn
 , BYREF pbtdiInout AS BLUETOOTH_DEVICE_INFO _          ' __in BLUETOOTH_DEVICE_INFO * pbtdiInout
 , BYREF pbtOobData AS BLUETOOTH_OOB_DATA_INFO _        ' __in_opt PBLUETOOTH_OOB_DATA_INFO pbtOobData
 , BYVAL authenticationRequirement AS AUTHENTICATION_REQUIREMENTS_ENUM _ ' __in AUTHENTICATION_REQUIREMENTS authenticationRequirement
 ) AS DWORD                                             ' DWORD

'#endif // >= SP1+KB942567


'//
'//  Description:
'//      Allows the caller to prompt for multiple devices to be authenticated
'//      within a single instance of the "Bluetooth Connection Wizard."
'//
'//  Parameters:
'//
'//      hwndParent
'//          The window to parent the authentication wizard. If NULL, the
'//          wizard will be parented off the desktop.
'//
'//      hRadio
'//          A valid local radio handle or NULL. If NULL, then all radios will
'//          be tired. If any of the radios succeed, then the call will
'//          succeed.
'//
'//      cDevices
'//          Number of devices in the rgbtdi array.
'//
'//      rgbtdi
'//          An array BLUETOOTH_DEVICE_INFO records of the devices to be
'//          authenticated.
'//
'//  Return Values:
'//
'//      ERROR_SUCCESS
'//          Success. Check the fAuthenticate flag on each of the devices.
'//
'//      ERROR_CANCELLED
'//          User aborted the operation. Check the fAuthenticate flags on
'//          each device to determine if any of the devices were authenticated
'//          before the user cancelled the operation.
'//
'//      ERROR_INVALID_PARAMETER
'//          One of the items in the array of devices is invalid.
'//
'//      ERROR_NO_MORE_ITEMS
'//          All the devices in the array of devices are already been marked as
'//          being authenticated.
'//
'//      other WIN32 error
'//          Failure. Return value is the error code.
'//

DECLARE FUNCTION BluetoothAuthenticateMultipleDevices IMPORT "IRPROPS.CPL" ALIAS "BluetoothAuthenticateMultipleDevices" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL hRadio AS DWORD _                              ' __in HANDLE hRadio
 , BYVAL cDevices AS DWORD _                            ' __in DWORD cDevices
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __inout BLUETOOTH_DEVICE_INFO * pbtdi
 ) AS DWORD                                             ' DWORD

'//
'// Deprecated after Vista SP1 and KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'#pragma deprecate("BluetoothAuthenticateMultipleDevices")

'#endif // >= SP1+KB942567

'// ***************************************************************************
'//
'//  Bluetooth Services
'//
'// ***************************************************************************

%BLUETOOTH_SERVICE_DISABLE = &H00
%BLUETOOTH_SERVICE_ENABLE  = &H01
%BLUETOOTH_SERVICE_MASK    = %BLUETOOTH_SERVICE_ENABLE OR %BLUETOOTH_SERVICE_DISABLE

'//
'//  Description:
'//      Enables/disables the services for a particular device.
'//
'//      The system maintains a mapping of service guids to supported drivers for
'//      Bluetooth-enabled devices. Enabling a service installs the corresponding
'//      device driver. Disabling a service removes the corresponding device driver.
'//
'//      If a non-supported service is enabled, a driver will not be installed.
'//
'//  Parameters
'//      hRadio
'//          Handle of the local Bluetooth radio device.
'//
'//      pbtdi
'//          Pointer to a BLUETOOTH_DEVICE_INFO record.
'//
'//      pGuidService
'//          The service GUID on the remote device.
'//
'//      dwServiceFlags
'//          Flags to adjust the service.
'//              BLUETOOTH_SERVICE_DISABLE   -   disable the service
'//              BLUETOOTH_SERVICE_ENABLE    -   enables the service
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The call was successful.
'//
'//      ERROR_INVALID_PARAMETER
'//          dwServiceFlags are invalid.
'//
'//      ERROR_SERVICE_DOES_NOT_EXIST
'//          The GUID in pGuidService is not supported.
'//
'//      other WIN32 error
'//          The call failed.
'//

DECLARE FUNCTION BluetoothSetServiceState IMPORT "IRPROPS.CPL" ALIAS "BluetoothSetServiceState" ( _
   BYVAL hRadio AS DWORD _                              ' __in_opt HANDLE hRadio
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in const BLUETOOTH_DEVICE_INFO * pbtdi
 , BYREF pGuidService AS GUID _                         ' __in const GUID * pGuidService
 , BYVAL dwServiceFlags AS DWORD _                      ' __in DWORD dwServiceFlags
 ) AS DWORD                                             ' DWORD

'//
'//  Description:
'//      Enumerates the services guids enabled on a particular device. If hRadio
'//      is NULL, all device will be searched for the device and all the services
'//      enabled will be returned.
'//
'//  Parameters:
'//      hRadio
'//          Handle of the local Bluetooth radio device. If NULL, it will search
'//          all the radios for the address in the pbtdi.
'//
'//      pbtdi
'//          Pointer to a BLUETOOTH_DEVICE_INFO record.
'//
'//      pcService
'//          On input, the number of records pointed to by pGuidServices.
'//          On output, the number of valid records return in pGuidServices.
'//
'//      pGuidServices
'//          Pointer to memory that is at least *pcService in length.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The call succeeded. pGuidServices is valid.
'//
'//      ERROR_MORE_DATA
'//          The call succeeded. pGuidService contains an incomplete list of
'//          enabled service GUIDs.
'//
'//      other WIN32 errors
'//          The call failed.
'//

DECLARE FUNCTION BluetoothEnumerateInstalledServices IMPORT "IRPROPS.CPL" ALIAS "BluetoothEnumerateInstalledServices" ( _
   BYVAL hRadio AS DWORD _                              ' __in_opt HANDLE hRadio
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in const BLUETOOTH_DEVICE_INFO * pbtdi
 , BYREF pcServices AS DWORD _                          ' __inout DWORD * pcServices
 , BYREF pGuidServices AS GUID _                        ' __out GUID * pGuidServices
 ) AS DWORD                                             ' DWORD

'//
'//  Description:
'//      Change the discovery state of the local radio(s).
'//      If hRadio is NULL, all the radios will be set.
'//
'//      Use BluetoothIsDiscoverable() to determine the radios current state.
'//
'//      The system ensures that a discoverable system is connectable, thus
'//      the radio must allow incoming connections (see
'//      BluetoothEnableIncomingConnections) prior to making a radio
'//      discoverable. Failure to do so will result in this call failing
'//      (returns FALSE).
'//
'//  Parameters:
'//      hRadio
'//          If not NULL, changes the state of a specific radio.
'//          If NULL, the API will interate through all the radios.
'//
'//      fEnabled
'//          If FALSE, discovery will be disabled.
'//
'//  Return Values
'//      TRUE
'//          State was successfully changed. If the caller specified NULL for
'//          hRadio, at least of the radios accepted the state change.
'//
'//      FALSE
'//          State was not changed. If the caller specified NULL for hRadio, all
'//          of the radios did not accept the state change.
'//

DECLARE FUNCTION BluetoothEnableDiscovery IMPORT "IRPROPS.CPL" ALIAS "BluetoothEnableDiscovery" ( _
   BYVAL hRadio AS DWORD _                              ' __in_opt HANDLE hRadio
 , BYVAL fEnabled AS LONG _                             ' __in BOOL fEnabled
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Determines if the Bluetooth radios are discoverable. If there are
'//      multiple radios, the first one to say it is discoverable will cause
'//      this function to return TRUE.
'//
'//  Parameters:
'//      hRadio
'//          Handle of the radio to check. If NULL, it will check all local
'//          radios.
'//
'//  Return Values:
'//      TRUE
'//          A least one radio is discoverable.
'//
'//      FALSE
'//          No radios are discoverable.
'//

DECLARE FUNCTION BluetoothIsDiscoverable IMPORT "IRPROPS.CPL" ALIAS "BluetoothIsDiscoverable" ( _
   BYVAL hRadio AS DWORD _                              ' HANDLE hRadio
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Enables/disables the state of a radio to accept incoming connections.
'//      If hRadio is NULL, all the radios will be set.
'//
'//      Use BluetoothIsConnectable() to determine the radios current state.
'//
'//      The system enforces that a radio that is not connectable is not
'//      discoverable too. The radio must be made non-discoverable (see
'//      BluetoothEnableDiscovery) prior to making a radio non-connectionable.
'//      Failure to do so will result in this call failing (returns FALSE).
'//
'//  Parameters:
'//      hRadio
'//          If not NULL, changes the state of a specific radio.
'//          If NULL, the API will interate through all the radios.
'//
'//      fEnabled
'//          If FALSE, incoming connection will be disabled.
'//
'//  Return Values
'//      TRUE
'//          State was successfully changed. If the caller specified NULL for
'//          hRadio, at least of the radios accepted the state change.
'//
'//      FALSE
'//          State was not changed. If the caller specified NULL for hRadio, all
'//          of the radios did not accept the state change.
'//

DECLARE FUNCTION BluetoothEnableIncomingConnections IMPORT "IRPROPS.CPL" ALIAS "BluetoothEnableIncomingConnections" ( _
   BYVAL hRadio AS DWORD _                              ' __in_opt HANDLE hRadio
 , BYVAL fEnabled AS LONG _                             ' __in BOOL fEnabled
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      Determines if the Bluetooth radios are connectable. If there are
'//      multiple radios, the first one to say it is connectable will cause
'//      this function to return TRUE.
'//
'//  Parameters:
'//      hRadio
'//          Handle of the radio to check. If NULL, it will check all local
'//          radios.
'//
'//  Return Values:
'//      TRUE
'//          A least one radio is allowing incoming connections.
'//
'//      FALSE
'//          No radios are allowing incoming connections.
'//

DECLARE FUNCTION BluetoothIsConnectable IMPORT "IRPROPS.CPL" ALIAS "BluetoothIsConnectable" ( _
   BYVAL hRadio AS DWORD _                              ' __in HANDLE hRadio
 ) AS LONG                                              ' BOOL

'// ***************************************************************************
'//
'//  Authentication Registration
'//
'// ***************************************************************************

'typedef HANDLE HBLUETOOTH_AUTHENTICATION_REGISTRATION;

'typedef BOOL (*PFN_AUTHENTICATION_CALLBACK)(LPVOID pvParam, PBLUETOOTH_DEVICE_INFO pDevice);

'//
'//  Description:
'//      Registers a callback function to be called when a particular device
'//      requests authentication. The request is sent to the last application
'//      that requested authentication for a particular device.
'//
'//  Parameters:
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure. The Bluetooth
'//          address will be used for comparision.
'//
'//      phRegHandle
'//          A pointer to where the registration HANDLE value will be
'//          stored. Call BluetoothUnregisterAuthentication() to close
'//          the handle.
'//
'//      pfnCallback
'//          The function that will be called when the authentication event
'//          occurs. This function should match PFN_AUTHENTICATION_CALLBACK's
'//          prototype.
'//
'//      pvParam
'//          Optional parameter to be past through to the callback function.
'//          This can be anything the application was to define.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          Success. A valid registration handle was returned.
'//
'//      ERROR_OUTOFMEMORY
'//          Out of memory.
'//
'//      other Win32 error.
'//          Failure. The registration handle is invalid.
'//

DECLARE FUNCTION BluetoothRegisterForAuthentication IMPORT "IRPROPS.CPL" ALIAS "BluetoothRegisterForAuthentication" ( _
   BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in_opt const BLUETOOTH_DEVICE_INFO * pbtdi
 , BYREF phRegHandle AS DWORD _                         ' __out HBLUETOOTH_AUTHENTICATION_REGISTRATION * phRegHandle
 , OPTIONAL BYVAL pfnCallback AS DWORD _                ' __in_opt PFN_AUTHENTICATION_CALLBACK pfnCallback
 , OPTIONAL BYVAL pvParam AS DWORD _                    ' __in_opt PVOID pvParam
 ) AS DWORD                                             ' DWORD

'//
'// Support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'//
'// Replaces previous API
'//
'#pragma deprecate("BluetoothRegisterForAuthentication")

'typedef BOOL (*PFN_AUTHENTICATION_CALLBACK_EX)(__in_opt LPVOID pvParam, __in PBLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS pAuthCallbackParams);
'FUNCTION PFN_AUTHENTICATION_CALLBACK_EX(BYVAL pvParam AS DWORD, BYREF pAuthCallbackParams AS BLUETOOTH_AUTHENTICATION_CALLBACK_PARAMS) AS LONG

'//
'//  Description:
'//      Registers a callback function to be called when a particular device
'//      requests authentication. The request is sent to the last application
'//      that requested authentication for a particular device.
'//
'//  Parameters:
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure. The Bluetooth
'//          address will be used for comparision.
'//
'//      phRegHandle
'//          A pointer to where the registration HANDLE value will be
'//          stored. Call BluetoothUnregisterAuthentication() to close
'//          the handle.
'//
'//      pfnCallback
'//          The function that will be called when the authentication event
'//          occurs. This function should match PFN_AUTHENTICATION_CALLBACK_EX's
'//          prototype.
'//
'//      pvParam
'//          Optional parameter to be past through to the callback function.
'//          This can be anything the application was to define.
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          Success. A valid registration handle was returned.
'//
'//      ERROR_OUTOFMEMORY
'//          Out of memory.
'//
'//      other Win32 error.
'//          Failure. The registration handle is invalid.
'//

DECLARE FUNCTION BluetoothRegisterForAuthenticationEx IMPORT "IRPROPS.CPL" ALIAS "BluetoothRegisterForAuthenticationEx" ( _
   BYREF pbtdiIn AS BLUETOOTH_DEVICE_INFO _             ' __in_opt const BLUETOOTH_DEVICE_INFO * pbtdiIn
 , BYREF phRegHandleOut AS DWORD _                      ' __out HBLUETOOTH_AUTHENTICATION_REGISTRATION * phRegHandleOut
 , OPTIONAL BYVAL pfnCallbackIn AS DWORD _              ' __in_opt PFN_AUTHENTICATION_CALLBACK pfnCallbackIn
 , OPTIONAL BYVAL pvParam AS DWORD _                    ' __in_opt PVOID pvParam
 ) AS DWORD                                             ' DWORD

'#endif // >= SP1+KB942567


'//
'//  Description:
'//      Unregisters an authentication callback and closes the handle. See
'//      BluetoothRegisterForAuthentication() for more information about
'//      authentication registration.
'//
'//  Parameters:
'//      hRegHandle
'//          Handle returned by BluetoothRegisterForAuthentication().
'//
'//  Return Value:
'//      TRUE
'//          The handle was successfully closed.
'//
'//      FALSE
'//          The handle was not successfully closed. Check GetLastError for
'//          more details.
'//
'//          ERROR_INVALID_HANDLE
'//              The handle is NULL.
'//
'//          other Win32 errors.
'//

DECLARE FUNCTION BluetoothUnregisterAuthentication IMPORT "IRPROPS.CPL" ALIAS "BluetoothUnregisterAuthentication" ( _
   BYVAL hRegHandle AS DWORD _                          ' __in HBLUETOOTH_AUTHENTICATION_REGISTRATION hRegHandle
 ) AS LONG                                              ' BOOL

'//
'//  Description:
'//      This function should be called after receiving an authentication request
'//      to send the passkey response.
'//
'//  Parameters:
'//
'//      hRadio
'//          Optional handle to the local radio. If NULL, the function will try
'//          each radio until one succeeds.
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure describing the device
'//          being authenticated. This can be the same structure passed to the
'//          callback function.
'//
'//      pszPasskey
'//          A pointer to UNICODE zero-terminated string of the passkey response
'//          that should be sent back to the authenticating device.
'//
'//  Return Values:
'//      ERROR_SUCESS
'//          The device accepted the passkey response. The device is authenticated.
'//
'//      ERROR_CANCELED
'//          The device denied the passkey reponse. This also will returned if there
'//          is a communications problem with the local radio.
'//
'//      E_FAIL
'//          The device returned a failure code during authentication.
'//
'//      other Win32 error codes
'//

DECLARE FUNCTION BluetoothSendAuthenticationResponse IMPORT "IRPROPS.CPL" ALIAS "BluetoothSendAuthenticationResponse" ( _
   BYVAL hRadio AS DWORD _                              ' __in_opt HANDLE hRadio
 , BYREF pbtdi AS BLUETOOTH_DEVICE_INFO _               ' __in const BLUETOOTH_DEVICE_INFO * pbtdi
 , BYREF pszPasskey AS WSTRINGZ _                       ' __in LPWSTR pszPasskey
 ) AS DWORD                                             ' DWORD

'//
'// Support added in KB942567
'//
'#if (NTDDI_VERSION > NTDDI_VISTASP1 || \
'    (NTDDI_VERSION == NTDDI_VISTASP1 && defined(VISTA_KB942567)))

'//
'// Replaces previous API
'//
'#pragma deprecate("BluetoothSendAuthenticationResponse")

'//
'// Structure used when responding to BTH_REMOTE_AUTHENTICATE_REQUEST event
'//

' // Size = 32 bytes
UNION BLUETOOTH_AUTHENTICATE_RESPONSE_UNION   ' Must be 8 bytes aligned
   pinInfo         AS BLUETOOTH_PIN_INFO                  ' Size = 17 bytes
   oobInfo         AS BLUETOOTH_OOB_DATA_INFO             ' Size = 32 bytes
   numericCompInfo AS BLUETOOTH_NUMERIC_COMPARISON_INFO   ' Size = 4 bytes
   passkeyInfo     AS BLUETOOTH_PASSKEY_INFO              ' Size = 4 bytes
END UNION

' // Size = 48 bytes
TYPE BLUETOOTH_AUTHENTICATE_RESPONSE   ' Must be 8 byte aligned
   bthAddressRemote AS BLUETOOTH_ADDRESS   ' Size = 8 bytes
   authMethod       AS LONG                ' BLUETOOTH_AUTHENTICATION_METHOD - Size = 4 bytes
   BLUETOOTH_AUTHENTICATE_RESPONSE_UNION   ' Size = 32 bytes
   negativeResponse AS BYTE                ' UCHAR - Size = 1 byte
   filler_(2)       AS BYTE                ' // To keep 8 byte alignment
END TYPE

'//
'//  Description:
'//      This function should be called after receiving an authentication request
'//      to send the authentication response. (Bluetooth 2.1 and above)
'//
'//  Parameters:
'//
'//      hRadio
'//          Optional handle to the local radio. If NULL, the function will try
'//          each radio until one succeeds.
'//
'//      pbtdi
'//          A pointer to a BLUETOOTH_DEVICE_INFO structure describing the device
'//          being authenticated. This can be the same structure passed to the
'//          callback function.
'//
'//      pauthResponse
'//          A pointer to a BTH_AUTHENTICATION_RESPONSE structure.
'//
'//  Return Values:
'//      ERROR_SUCESS
'//          The device accepted the passkey response. The device is authenticated.
'//
'//      ERROR_CANCELED
'//          The device denied the passkey reponse. This also will returned if there
'//          is a communications problem with the local radio.
'//
'//      E_FAIL
'//          The device returned a failure code during authentication.
'//
'//      other Win32 error codes
'//

DECLARE FUNCTION BluetoothSendAuthenticationResponseEx IMPORT "IRPROPS.CPL" ALIAS "BluetoothSendAuthenticationResponseEx" ( _
   BYVAL hRadioIn AS DWORD _                            ' __in_opt HANDLE hRadioIn
 , BYREF pauthResponse AS BLUETOOTH_AUTHENTICATE_RESPONSE _ ' __in PBLUETOOTH_AUTHENTICATE_RESPONSE pauthResponse
 ) AS DWORD                                             ' DWORD

'#endif // >= SP1+KB942567

'// ***************************************************************************
'//
'//  SDP Parsing Functions
'//
'// ***************************************************************************

'typedef struct _SDP_ELEMENT_DATA {
'    //
'    // Enumeration of SDP element types.  Generic element types will have a
'    // specificType value other then SDP_ST_NONE.  The generic types are:
'    // o SDP_TYPE_UINT
'    // o SDP_TYPE_INT
'    // o SDP_TYPE_UUID
'    //
'    SDP_TYPE type;

'    //
'    // Specific types for the generic SDP element types.
'    //
'    SDP_SPECIFICTYPE specificType;

'    //
'    // Union of all possible data types.  type and specificType will indicate
'    // which field is valid.  For types which do not have a valid specificType,
'    // specific type will be SDP_ST_NONE.
'    //
'    union {
'        // type == SDP_TYPE_INT
'        SDP_LARGE_INTEGER_16 int128;        // specificType == SDP_ST_INT128
'        LONGLONG int64;                     // specificType == SDP_ST_INT64
'        LONG int32;                         // specificType == SDP_ST_INT32
'        SHORT int16;                        // specificType == SDP_ST_INT16
'        CHAR int8;                          // specificType == SDP_ST_INT8

'        // type == SDP_TYPE_UINT
'        SDP_ULARGE_INTEGER_16 uint128;      // specificType == SDP_ST_UINT128
'        ULONGLONG uint64;                   // specificType == SDP_ST_UINT64
'        ULONG uint32;                       // specificType == SDP_ST_UINT32
'        USHORT uint16;                      // specificType == SDP_ST_UINT16
'        UCHAR uint8;                        // specificType == SDP_ST_UINT8

'        // type == SDP_TYPE_BOOLEAN
'        UCHAR booleanVal;

'        // type == SDP_TYPE_UUID
'        GUID uuid128;                       // specificType == SDP_ST_UUID128
'        ULONG uuid32;                       // specificType == SDP_ST_UUID32
'        USHORT uuid16;                      // specificType == SDP_ST_UUID32

'        // type == SDP_TYPE_STRING
'        struct {
'            // raw string buffer, may not be encoded as ANSI, use
'            // BluetoothSdpGetString to convert the value if it is described
'            // by the base language attribute ID list
'            LPBYTE value;

'            // raw length of the string, may not be NULL terminuated
'            ULONG length;
'        } string;

'        // type == SDP_TYPE_URL
'        struct {
'            LPBYTE value;
'            ULONG length;
'        } url;

'        // type == SDP_TYPE_SEQUENCE
'        struct {
'            // raw sequence, starts at sequence element header
'            LPBYTE value;

'            // raw sequence length
'            ULONG length;
'        } sequence;

'        // type == SDP_TYPE_ALTERNATIVE
'        struct {
'            // raw alternative, starts at alternative element header
'            LPBYTE value;

'            // raw alternative length
'            ULONG length;
'        } alternative;

'    } data;

'} SDP_ELEMENT_DATA, *PSDP_ELEMENT_DATA;

' // Size = 8 bytes
TYPE SDP_ELEMENT_DATA_UNION_STRING_STRUCT DWORD
   ' // raw string buffer, may not be encoded as ANSI, use
   ' // BluetoothSdpGetString to convert the value if it is described
   ' // by the base language attribute ID list
   value  AS BYTE PTR   ' LPBYTE
   ' // raw length of the string, may not be NULL terminuated
   length AS DWORD      ' ULONG
END TYPE

' // Size = 8 bytes
TYPE SDP_ELEMENT_DATA_UNION_URL_STRUCT DWORD
   value  AS BYTE PTR   ' LPBYTE
   length AS DWORD      ' ULONG
END TYPE

' // Size = 8 bytes
TYPE SDP_ELEMENT_DATA_UNION_SEQUENCE_STRUCT DWORD
   value  AS BYTE PTR   ' LPBYTE
   length AS DWORD      ' ULONG
END TYPE

' // Size = 8 bytes
TYPE SDP_ELEMENT_DATA_UNION_ALTERNATIVE_STRUCT DWORD
   value  AS BYTE PTR   ' LPBYTE
   length AS DWORD      ' ULONG
END TYPE

' // Size = 16 bytes
UNION SDP_ELEMENT_DATA_UNION   ' Must be 8 bytes aligned
   ' // type == SDP_TYPE_INT
   int128      AS SDP_LARGE_INTEGER_16    ' SDP_LARGE_INTEGER_16 // specificType == SDP_ST_INT128
   int64       AS QUAD                    ' LONGLONG  // specificType == SDP_ST_INT64
   int32       AS LONG                    ' LONG // specificType == SDP_ST_INT32
   int16       AS INTEGER                 ' SHORT // specificType == SDP_ST_INT16
   int8        AS BYTE                    ' CHAR // specificType == SDP_ST_INT8
   ' // type == SDP_TYPE_UINT
   uint128     AS SDP_ULARGE_INTEGER_16   ' SDP_ULARGE_INTEGER_16 // specificType == SDP_ST_UINT128
   uint64      AS QUAD                    ' ULONGLONG // specificType == SDP_ST_UINT64
   uint32      AS DWORD                   ' ULONG // specificType == SDP_ST_UINT32
   uint16      AS WORD                    ' USHORT // specificType == SDP_ST_UINT16
   uint8       AS BYTE                    ' UCHAR // specificType == SDP_ST_UINT8
   ' // type == SDP_TYPE_BOOLEAN
   booleanVal  AS BYTE                    ' UCHAR
   ' // type == SDP_TYPE_UUID
   uuid128     AS GUID                    ' GUID // specificType == SDP_ST_UUID128
   uuid32      AS DWORD                   ' ULONG // specificType == SDP_ST_UUID32
   uuid16      AS WORD                    ' USHORT // specificType == SDP_ST_UUID32
   ' // type == SDP_TYPE_STRING
   string      AS SDP_ELEMENT_DATA_UNION_STRING_STRUCT
   ' // type == SDP_TYPE_URL
   url         AS SDP_ELEMENT_DATA_UNION_URL_STRUCT
   ' // type == SDP_TYPE_SEQUENCE
   sequence    AS SDP_ELEMENT_DATA_UNION_SEQUENCE_STRUCT
   ' // type == SDP_TYPE_ALTERNATIVE
   alternative AS SDP_ELEMENT_DATA_UNION_ALTERNATIVE_STRUCT
END UNION

' // Size = 24 bytes
TYPE SDP_ELEMENT_DATA
   type         AS SDP_TYPE_ENUM            ' SDP_TYPE
   specificType AS SDP_SPECIFICTYPE_ENUM    ' SDP_SPECIFICTYPE
   data         AS SDP_ELEMENT_DATA_UNION
END TYPE

'//
'// Description:
'//      Retrieves and parses the element found at pSdpStream
'//
'// Parameters:
'//      IN pSdpStream
'//          pointer to valid SDP stream
'//
'//      IN cbSdpStreamLength
'//          length of pSdpStream in bytes
'//
'//      OUT pData
'//          pointer to be filled in with the data of the SDP element at the
'//          beginning of pSdpStream
'//
'// Return Values:
'//      ERROR_INVALID_PARAMETER
'//          one of required parameters is NULL or the pSdpStream is invalid
'//
'//      ERROR_SUCCESS
'//          the sdp element was parsed correctly
'//

DECLARE FUNCTION BluetoothSdpGetElementData IMPORT "IRPROPS.CPL" ALIAS "BluetoothSdpGetElementData" ( _
   BYVAL pSdpStream AS BYTE PTR _                       ' __in  LPBYTE pSdpStream
 , BYVAL cbSdpStreamLength AS DWORD _                   ' __in  ULONG cbSdpStreamLength
 , BYREF pData AS SDP_ELEMENT_DATA _                    ' __out PSDP_ELEMENT_DATA pData
 ) AS DWORD                                             ' DWORD

'typedef HANDLE HBLUETOOTH_CONTAINER_ELEMENT;

'//
'// Description:
'//      Iterates over a container stream, returning each elemetn contained with
'//      in the container element at the beginning of pContainerStream
'//
'// Parameters:
'//      IN pContainerStream
'//          pointer to valid SDP stream whose first element is either a sequence
'//          or alternative
'//
'//      IN cbContainerlength
'//          length in bytes of pContainerStream
'//
'//      IN OUT pElement
'//          Value used to keep track of location within the stream.  The first
'//          time this function is called for a particular container, *pElement
'//          should equal NULL.  Upon subsequent calls, the value should be
'//          unmodified.
'//
'//      OUT pData
'//          pointer to be filled in with the data of the SDP element at the
'//          current element of pContainerStream
'//
'//  Return Values:
'//      ERROR_SUCCESS
'//          The call succeeded, pData contains the data
'//
'//      ERROR_NO_MORE_ITEMS
'//          There are no more items in the list, the caller should cease calling
'//          BluetoothSdpGetContainerElementData for this container.
'//
'//      ERROR_INVALID_PARAMETER
'//          A required pointer is NULL or the container is not a valid SDP
'//          stream
'//
'// Usage example:
'//
'// HBLUETOOTH_CONTAINER_ELEMENT element;
'// SDP_ELEMENT_DATA data;
'// ULONG result;
'//
'// element = NULL;
'//
'// while (TRUE) {
'//      result = BluetoothSdpGetContainerElementData(
'//          pContainer, ulContainerLength, &element, &data);
'//
'//      if (result == ERROR_NO_MORE_ITEMS) {
'//          // We are done
'//          break;
'//      }
'//      else if (result != ERROR_SUCCESS) {
'//          // error
'//      }
'//
'//      // do something with data ...
'// }
'//
'//

DECLARE FUNCTION BluetoothSdpGetContainerElementData IMPORT "IRPROPS.CPL" ALIAS "BluetoothSdpGetContainerElementData" ( _
   BYVAL pContainerStream AS BYTE PTR _                 ' __in    LPBYTE pContainerStream
 , BYVAL cbContainerLength AS DWORD _                   ' __in    ULONG cbContainerLength
 , BYREF pElement AS DWORD _                            ' __inout HBLUETOOTH_CONTAINER_ELEMENT* pElement
 , BYREF pData AS SDP_ELEMENT_DATA _                    ' __out   PSDP_ELEMENT_DATA pData
 ) AS DWORD                                             ' DWORD

'//
'// Description:
'//      Retrieves the attribute value for the given attribute ID.  pRecordStream
'//      must be an SDP stream that is formatted as an SDP record, a SEQUENCE
'//      containing UINT16 + element pairs.
'//
'// Parameters:
'//      IN pRecordStream
'//          pointer to a valid SDP stream which is formatted as a singl SDP
'//          record
'//
'//      IN cbRecordlnegh
'//          length of pRecordStream in bytes
'//
'//      IN usAttributeId
'//          the attribute ID to search for.  see bthdef.h for SDP_ATTRIB_Xxx
'//          values.
'//
'//      OUT pAttributeData
'//          pointer that will contain the attribute ID's value
'//
'// Return Values:
'//      ERRROR_SUCCESS
'//          Call succeeded, pAttributeData contains the attribute value
'//
'//      ERROR_INVALID_PARAMETER
'//          One of the required pointers was NULL, pRecordStream was not a valid
'//          SDP stream, or pRecordStream was not a properly formatted SDP record
'//
'//      ERROR_FILE_NOT_FOUND
'//          usAttributeId was not found in the record
'//
'// Usage:
'//
'// ULONG result;
'// SDP_DATA_ELEMENT data;
'//
'// result = BluetoothSdpGetAttributeValue(
'//      pRecordStream, cbRecordLength, SDP_ATTRIB_RECORD_HANDLE, &data);
'// if (result == ERROR_SUCCESS) {
'//      printf("record handle is 0x%x\n", data.data.uint32);
'// }
'//

DECLARE FUNCTION BluetoothSdpGetAttributeValue IMPORT "IRPROPS.CPL" ALIAS "BluetoothSdpGetAttributeValue" ( _
   BYVAL pRecordStream AS BYTE PTR _                    ' __in  LPBYTE pRecordStream
 , BYVAL cbRecordLength AS DWORD _                      ' __in  ULONG  cbRecordLength
 , BYVAL usAttributeId AS WORD _                        ' __in  USHORT usAttributeId
 , BYREF pAttributeData AS SDP_ELEMENT_DATA _           ' __out PSDP_ELEMENT_DATA pAttributeData
 ) AS DWORD                                             ' DWORD

'//
'// These three fields correspond one to one with the triplets defined in the
'// SDP specification for the language base attribute ID list.
'//
'typedef struct _SDP_STRING_TYPE_DATA {
'    //
'    // How the string is encoded according to ISO 639:1988 (E/F): "Code
'    // for the representation of names of languages".
'    //
'    USHORT encoding;

'    //
'    // MIBE number from IANA database
'    //
'    USHORT mibeNum;

'    //
'    // The base attribute where the string is to be found in the record
'    //
'    USHORT attributeId;

'} SDP_STRING_TYPE_DATA, *PSDP_STRING_TYPE_DATA;

' // Size = 6 bytes
TYPE SDP_STRING_TYPE_DATA WORD
   encoding    AS WORD   ' USHORT
   mibeNum     AS WORD   ' USHORT
   attributeId AS WORD   ' USHORT
END TYPE

'//
'// Description:
'//      Converts a raw string embedded in the SDP record into a UNICODE string
'//
'// Parameters:
'//      IN pRecordStream
'//          a valid SDP stream which is formatted as an SDP record
'//
'//      IN cbRecordLength
'//          length of pRecordStream in bytes
'//
'//      IN pStringData
'//          if NULL, then the calling thread's locale will be used to search
'//          for a matching string in the SDP record.  If not NUL, the mibeNum
'//          and attributeId will be used to find the string to convert.
'//
'//      IN usStringOffset
'//          the SDP string type offset to convert.  usStringOffset is added to
'//          the base attribute id of the string.   SDP specification defined
'//          offsets are: STRING_NAME_OFFSET, STRING_DESCRIPTION_OFFSET, and
'//          STRING_PROVIDER_NAME_OFFSET (found in bthdef.h).
'//
'//      OUT pszString
'//          if NULL, pcchStringLength will be filled in with the required number
'//          of characters (not bytes) to retrieve the converted string.
'//
'//      IN OUT pcchStringLength
'//          Upon input, if pszString is not NULL, will contain the length of
'//          pszString in characters.  Upon output, it will contain either the
'//          number of required characters including NULL if an error is returned
'//          or the number of characters written to pszString (including NULL).
'//
'//  Return Values:
'//      ERROR_SUCCES
'//          Call was successful and pszString contains the converted string
'//
'//      ERROR_MORE_DATA
'//          pszString was NULL or too small to contain the converted string,
'//          pccxhStringLength contains the required length in characters
'//
'//      ERROR_INVALID_DATA
'//          Could not perform the conversion
'//
'//      ERROR_NO_SYSTEM_RESOURCES
'//          Could not allocate memory internally to perform the conversion
'//
'//      ERROR_INVALID_PARAMETER
'//          One of the rquired pointers was NULL, pRecordStream was not a valid
'//          SDP stream, pRecordStream was not a properly formatted record, or
'//          the desired attribute + offset was not a string.
'//
'//      Other HRESULTs returned by COM
'//

DECLARE FUNCTION BluetoothSdpGetString IMPORT "IRPROPS.CPL" ALIAS "BluetoothSdpGetString" ( _
   BYVAL pRecordStream AS BYTE PTR _                    ' __in LPBYTE pRecordStream
 , BYVAL cbRecordLength AS DWORD _                      ' __in ULONG cbRecordLength
 , BYREF pStringData AS SDP_STRING_TYPE_DATA _          ' __in_opt const PSDP_STRING_TYPE_DATA pStringData
 , BYVAL usStringOffset AS WORD _                       ' __in USHORT usStringOffset
 , BYREF pszString AS WSTRINGZ _                        ' __out PWCHAR pszString
 , BYREF pcchStringLength AS DWORD _                    ' __inout PULONG pcchStringLength
 ) AS DWORD                                             ' DWORD

'// ***************************************************************************
'//
'//  Raw Attribute  Enumeration
'//
'// ***************************************************************************

'typedef BOOL (CALLBACK *PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK)(
'    __in ULONG   uAttribId,
'    __in_bcount(cbStreamSize) LPBYTE  pValueStream,
'    __in ULONG   cbStreamSize,
'    __in_opt LPVOID  pvParam
'    );

'FUNCTION PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK ( _
'   BYVAL DWORD _                            ' ULONG   uAttribId
' , BYVAL BYTE PTR _                         ' LPBYTE  pValueStream
' , BYVAL DWORD _                            ' ULONG   cbStreamSize
' , BYVAL DWORD _                            ' LPVOID  pvParam
' ) AS LONG                                  ' BOOL

'//
'//  Description:
'//      Enumerates through the SDP record stream calling the Callback function
'//      for each attribute in the record. If the Callback function returns
'//      FALSE, the enumeration is stopped.
'//
'//  Return Values:
'//      TRUE
'//          Success! Something was enumerated.
'//
'//      FALSE
'//          Failure. GetLastError() could be one of the following:
'//
'//          ERROR_INVALID_PARAMETER
'//              pSDPStream or pfnCallback is NULL.
'//
'//          ERROR_INVALID_DATA
'//              The SDP stream is corrupt.
'//
'//          other Win32 errors.
'//
'#define BluetoothEnumAttributes BluetoothSdpEnumAttributes

DECLARE FUNCTION BluetoothSdpEnumAttributes IMPORT "IRPROPS.CPL" ALIAS "BluetoothSdpEnumAttributes" ( _
   BYVAL pSDPStream AS BYTE PTR _                       ' __in LPBYTE pSDPStream
 , BYVAL cbStreamSize AS DWORD _                        ' __in ULONG  cbStreamSize
 , BYVAL pfnCallback AS DWORD _                         ' __in PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK pfnCallback
 , BYVAL pvParam AS DWORD _                             ' __in LPVOID  pvParam
 ) AS DWORD                                             ' DWORD

'#endif // (NTDDI_VERSION >= NTDDI_WINXPSP2)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// The following APIs are only available on Vista or later
'//

DECLARE FUNCTION BluetoothSetLocalServiceInfo IMPORT "IRPROPS.CPL" ALIAS "BluetoothSetLocalServiceInfo" ( _
   BYVAL hRadioIn AS DWORD _                              ' __in_opt HANDLE  hRadioIn
 , BYREF pClassGuid AS GUID _                             ' __in const GUID * pClassGuid
 , BYVAL ulInstance AS DWORD _                            ' __in ULONG ulInstance
 , BYREF pServiceInfoIn AS BLUETOOTH_LOCAL_SERVICE_INFO _ ' __in const BLUETOOTH_LOCAL_SERVICE_INFO * pServiceInfoIn
 ) AS DWORD                                               ' DWORD

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
