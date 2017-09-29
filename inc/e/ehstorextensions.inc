' ########################################################################################
' Microsoft Windows
' File: EhStorExtensions.inc
' Contents: Enhanced Storage WPD interfaces for silo drivers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EHSTOREXTENSIONS_INC =1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "propkey.inc"

'// ---------------------------------------------------------------------------
'//
'// This section defines the device interfaces for Enhanced Storage devices.
'//
'// ---------------------------------------------------------------------------

'//
'// {3897F6A4-FD35-4bc8-A0B7-5DBBA36ADAFA}
'//

$GUID_DEVINTERFACE_ENHANCED_STORAGE_SILO = GUID$("{3897F6A4-FD35-4bc8-A0B7-5DBBA36ADAFA}")

'// ---------------------------------------------------------------------------
'//
'// This section defines all Commands, Parameters and Options essociated with:
'// WPD_CATEGORY_ENHANCED_STORAGE
'//
'// This category is for commands and parameters for storage functional objects.
'//
'// ---------------------------------------------------------------------------

$WPD_CATEGORY_ENHANCED_STORAGE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}")

'// ---------------------------------------------------------------------------
'//
'// Authentication specific commands
'//
'// ---------------------------------------------------------------------------

'//
'// ENHANCED_STORAGE_COMMAND_SILO_IS_AUTHENTICATION_SILO
'//     This command will return whether or not the silo is an authentication silo.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - The last status code for Authentication or UnAuthentication
'//      ENHANCED_STORAGE_PROPERTY_IS_AUTHENTICATION_SILO [VT_BOOLEAN] - TRUE if an Auth-C silo, FALSE otherwise
'//

MACRO ENHANCED_STORAGE_COMMAND_SILO_IS_AUTHENTICATION_SILO = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(6)

'//
'// ENHANCED_STORAGE_COMMAND_SILO_GET_AUTHENTICATION_STATE
'//     This command will return the authentication state for the silo.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - The last status code for Authentication or UnAuthentication
'//      ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_STATE [VT_UI4]
'//

MACRO ENHANCED_STORAGE_COMMAND_SILO_GET_AUTHENTICATION_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(7)

'//
'// ENHANCED_STORAGE_COMMAND_SILO_START_AUTHENTICATION
'//     This command will begin authentication for the silo.
'//      An application needs to register for callbacks to get authorization
'//      state change notification
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None.
'//  Results:
'//     WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_SILO_START_AUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(9)

'//
'// ENHANCED_STORAGE_COMMAND_SILO_START_UNAUTHENTICATION
'//     This command will begin unauthentication for the silo.
'//      An application needs to register for callbacks to get authorization
'//      state change notification
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     None.
'//  Results:
'//     WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_SILO_START_UNAUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(10)

'//
'// ENHANCED_STORAGE_COMMAND_SILO_ENUMERATE_SILOS
'//     This command will enumerate the silo information for the specified silo type
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_QUERY_SILO_TYPE
'//  Results:
'//     WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_SILO_ENUMERATE_SILOS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(11)

'// ---------------------------------------------------------------------------
'//
'// Certificate specific commands
'//
'// ---------------------------------------------------------------------------


'//
'// ENHANCED_STORAGE_COMMAND_CERT_HOST_CERTIFICATE_AUTHENTICATION
'//      This command will attempt to do a host authentication based on an HCh
'//      (or XCh) from the device. If an index or certificate is specified, it
'//      will use that certificate.
'//      The default behavior is to authenticate any of the HCh certs present on
'//      the device if possible (or XCh.)
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      [ Optional ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX [VT_UINT]
'//      [ Optional ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE [VT_VECTOR | VT_UI1]
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_HOST_CERTIFICATE_AUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(101)

'//
'// DEVICE_AUTHENTICATION
'// ENHANCED_STORAGE_COMMAND_CERT_DEVICE_CERTIFICATE_AUTHENTICATION
'//      This command will attempt to do a device authentication operation. If
'//      an index or certificate is specified, it will use that certificate. It
'//      must be ASCm or ASCh.
'//      The default behavior is to authenticate ASCm.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      [ Optional ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX [VT_UINT]
'//      [ Optional ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE [VT_VECTOR | VT_UI1]
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_DEVICE_CERTIFICATE_AUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(102)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_ADMIN_CERTIFICATE_AUTHENTICATION
'//      This command will attempt to do an admin authentication based on the PCp
'//      (or XCp) from the device.
'//      This is an admin command - it requires both read and write access.
'//  Access:
'//      (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      None
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_ADMIN_CERTIFICATE_AUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(103)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_INITIALIZE_TO_MANUFACTURER_STATE
'//      This command will attempt to initialized to the manufacturer state.
'//      Requires PCp authentication.
'//  Access:
'//      (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_INITIALIZE_TO_MANUFACTURER_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(104)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_CERTIFICATE_COUNT
'//      This command will get the number of certificate slots on the device.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      none.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_MAX_CERTIFICATE_COUNT [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_STORED_CERTIFICATE_COUNT [VT_UINT]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_CERTIFICATE_COUNT = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(105)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_CERTIFICATE
'//      This command will return the certificate at the certificate index location.
'//      Index 0 is a special location that returns the ASCm chain in PKCS7 format.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX [VT_UINT]
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_TYPE [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_VALIDATION_POLICY [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_SIGNER_CERTIFICATE_INDEX [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_INDEX [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_OF_TYPE_INDEX [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_LENGTH [VT_UINT]
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE [VT_VECTOR | VT_UI1]

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_CERTIFICATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(106)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_SET_CERTIFICATE
'//      This command will set a certificate to the certificate index location.
'//      Requires admin authentication.
'//  Access:
'//      (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX [VT_UINT]
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_TYPE [VT_UINT]
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_VALIDATION_POLICY [VT_UINT]
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_SIGNER_CERTIFICATE_INDEX [VT_UINT]
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE [VT_VECTOR | VT_UI1]
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_SET_CERTIFICATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(107)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_CREATE_CERTIFICATE_REQUEST
'//      This command will esk the device to create a certificate request.
'//      This will then be signed by the application's chosen CA.
'//  Access:
'//      (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_REQUEST [VT_VECTOR | VT_UI1]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_CREATE_CERTIFICATE_REQUEST = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(108)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_UNAUTHENTICATION
'//      This command will issue a command to set the cert silo to the
'//      initialized state.
'//  Access:
'//      (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      None
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_UNAUTHENTICATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(110)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_CAPABILITY
'//      This command will issue a command to get a silo capability from the
'//      silo. Data returned is in the format returned from the silo.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      [ Required ] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_CAPABILITY_TYPE [VT_UINT]
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITY [VT_VECTOR | VT_UI1]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_CAPABILITY = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(111)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_CAPABILITIES
'//      This command will return the silo capabilities as a collection of
'//      capabilities.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITIES [VT_UNKNOWN]
'//      - ENHANCED_STORAGE_CAPABILITY_HASH_ALGS [VT_LPWSTR - semi-colon delimited]
'//      - ENHANCED_STORAGE_CAPABILITY_ASYMMETRIC_KEY_CRYPTOGRAPHY [VT_LPWSTR - semi-colon delimited]
'//      - ENHANCED_STORAGE_CAPABILITY_SIGNING_ALGS [VT_LPWSTR - semi-colon delimited]
'//      - ENHANCED_STORAGE_CAPABILITY_RENDER_USER_DATA_UNUSABLE [ VT_BOOL ]
'//      - ENHANCED_STORAGE_CAPABILITY_CERTIFICATE_EXTENSION_PARSING [ VT_BOOL ]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_CAPABILITIES = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(112)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_ACT_FRIENDLY_NAME
'//      This command will return the friendly name of the ACT containing the silo.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      [optional] ENHANCED_STORAGE_PROPERTY_CERTIFICATE_ACT_FRIENDLY_NAME [VT_LPWSTR]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_ACT_FRIENDLY_NAME = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(113)

'//
'// ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_GUID
'//      This command will return the silo's GUID.
'//  Access:
'//      (FILE_READ_ACCESS)
'//  Parameters:
'//      None.
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT
'//      ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_GUID [VT_LPWSTR]
'//

MACRO ENHANCED_STORAGE_COMMAND_CERT_GET_SILO_GUID = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(114)

'// ---------------------------------------------------------------------------
'//
'// Password specific commands
'//
'// ---------------------------------------------------------------------------


'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_AUTHORIZE_ACT_ACCESS
'//     This command attempts to authenticate to the silo for ACT's data access
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD_INDICATOR
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_AUTHORIZE_ACT_ACCESS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(203)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_UNAUTHORIZE_ACT_ACCESS
'//     This command attempts to un-authenticate to the silo for ACT's data
'//     access.
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_PASSWORD
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_PASSWORD_INDICATOR
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_UNAUTHORIZE_ACT_ACCESS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(204)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_QUERY_INFORMATION
'//     This command queries the current password silo information
'//  Access:
'//     (FILE_READ_ACCESS)
'//  Parameters:
'//      none
'//  Results:
'//      ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_STATE
'//      ENHANCED_STORAGE_PROPERTY_PASSWORD_SILO_INFO
'//      ENHANCED_STORAGE_PROPERTY_ADMIN_HINT
'//      ENHANCED_STORAGE_PROPERTY_USER_HINT
'//      ENHANCED_STORAGE_PROPERTY_USER_NAME
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_QUERY_INFORMATION = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(205)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_CONFIG_ADMINISTRATOR
'//     This command configures the administrator account
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_MAX_AUTH_FAILURES
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_AUTH_REQUIRED_FOR_INITIALIZE
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_CONFIG_ADMINISTRATOR = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(206)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_CREATE_USER
'//     This command creates a user account
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_USER_HINT
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_USER_NAME
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_MAX_AUTH_FAILURES
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_CREATE_USER = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(207)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_DELETE_USER
'//     This command deletes the existing user account
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//      none
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_DELETE_USER = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(208)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_CHANGE_PASSWORD
'//     This command changes the password for adminstritor or user account
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD_INDICATOR
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_HINT
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD_INDICATOR
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_SECURITY_IDENTIFIER
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_CHANGE_PASSWORD = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(209)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_INITIALIZE_USER_PASSWORD
'//     This command initializes the existing user password
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD
'//     [ Required ] ENHANCED_STORAGE_PROPERTY_NEW_HINT
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_INITIALIZE_USER_PASSWORD = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(210)

'//
'// ENHANCED_STORAGE_COMMAND_PASSWORD_START_INITIALIZE_TO_MANUFACTURER_STATE
'//     This command starts the initialization process
'//  Access:
'//     (FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'//  Parameters:
'//     [ Optional ] ENHANCED_STORAGE_PROPERTY_SECURITY_IDENTIFIER
'//  Results:
'//      WPD_PROPERTY_COMMON_HRESULT - status code for the operation
'//

MACRO ENHANCED_STORAGE_COMMAND_PASSWORD_START_INITIALIZE_TO_MANUFACTURER_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(211)

'// ---------------------------------------------------------------------------
'//
'// This section defines all WPD Enhanced Storage Properties
'//
'// ---------------------------------------------------------------------------

'//
'// ENHANCED_STORAGE_PROPERTY_AUTHORIZATION_STATE
'//   [ VT_UI4 ] Authorization status of the Enhanced Storage ACT.
'//

MACRO ENHANCED_STORAGE_PROPERTY_AUTHORIZATION_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(1005)

'//
'// ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_STATE
'//   [ VT_UI4 ] Authentication status of the Enhanced Storage Silo
'//

MACRO ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(1006)

'//
'// ENHANCED_STORAGE_PROPERTY_DRIVER_STATE
'//   [ VT_UI4 ] Current Operation for the ACT.
'//

MACRO ENHANCED_STORAGE_PROPERTY_ACT_DRIVER_STATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(1007)

'//
'// ENHANCED_STORAGE_PROPERTY_IS_AUTHENTICATION_SILO
'//   [ VT_BOOL ] Is this silo an authentication silo?
'//

MACRO ENHANCED_STORAGE_PROPERTY_IS_AUTHENTICATION_SILO = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(1009)

'//
'// ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_NEEDS_UI
'//   [ VT_BOOL ] Is this silo an authentication silo?
'//

MACRO ENHANCED_STORAGE_PROPERTY_AUTHENTICATION_NEEDS_UI = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(1010)

'// ---------------------------------------------------------------------------
'//
'// Password silo specific properties
'//
'// ---------------------------------------------------------------------------

'//
'// ENHANCED_STORAGE_PROPERTY_MAX_AUTH_FAILURES
'//   [ VT_UI4 ] Maximum number of password authentication failures
'//

MACRO ENHANCED_STORAGE_PROPERTY_MAX_AUTH_FAILURES = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2001)

'//
'// ENHANCED_STORAGE_PROPERTY_PASSWORD
'//   [ VT_BLOB ] The password to send or set
'//

MACRO ENHANCED_STORAGE_PROPERTY_PASSWORD = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2004)

'//
'// ENHANCED_STORAGE_PROPERTY_OLD_PASSWORD
'//   [ VT_BLOB ] The password used for changing password.
'//

MACRO ENHANCED_STORAGE_PROPERTY_OLD_PASSWORD = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2005)

'//
'// ENHANCED_STORAGE_PROPERTY_PASSWORD_INDICATOR
'//   [ VT_BOOL ] TRUE: user, FALSE: admin
'//

MACRO ENHANCED_STORAGE_PROPERTY_PASSWORD_INDICATOR = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2006)

'//
'// ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD_INDICATOR
'//   [ VT_BOOL ] TRUE: user, FALSE: admin
'//

MACRO ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD_INDICATOR = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2007)

'//
'// ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD
'//   [ VT_BLOB ] The new password.  Used to re-set the password
'//

MACRO ENHANCED_STORAGE_PROPERTY_NEW_PASSWORD = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2008)

'//
'// ENHANCED_STORAGE_PROPERTY_USER_HINT
'//   [ VT_LPCSTR ] The user hint
'//

MACRO ENHANCED_STORAGE_PROPERTY_USER_HINT = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2009)

'//
'// ENHANCED_STORAGE_PROPERTY_USER_NAME
'//   [ VT_LPCSTR ] The friendly user name
'//

MACRO ENHANCED_STORAGE_PROPERTY_USER_NAME = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2010)

'//
'// ENHANCED_STORAGE_PROPERTY_ADMIN_HINT
'//   [ VT_LPCSTR ] The admin hint
'//

MACRO ENHANCED_STORAGE_PROPERTY_ADMIN_HINT = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2011)

'//
'// ENHANCED_STORAGE_PROPERTY_SILO_NAME
'//   [ VT_LPCSTR ] The friendly name for the silo
'//

MACRO ENHANCED_STORAGE_PROPERTY_SILO_NAME = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2012)

'//
'// ENHANCED_STORAGE_PROPERTY_SILO_FRIENDLYNAME_SPECIFIED
'//   [ VT_BOOL ] Flag to indicate if silo friendly name is given
'//

MACRO ENHANCED_STORAGE_PROPERTY_SILO_FRIENDLYNAME_SPECIFIED = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2013)

'//
'// ENHANCED_STORAGE_PROPERTY_PASSWORD_SILO_INFO
'//   [ VT_BLOB ] The password silo information
'//

MACRO ENHANCED_STORAGE_PROPERTY_PASSWORD_SILO_INFO = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2014)

'//
'// ENHANCED_STORAGE_PROPERTY_SECURITY_IDENTIFIER
'//   [ VT_BLOB ] Security Identifier for the password silo device
'//

MACRO ENHANCED_STORAGE_PROPERTY_SECURITY_IDENTIFIER = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2015)

'//
'// ENHANCED_STORAGE_PROPERTY_QUERY_SILO_TYPE
'//   [ VT_UINT ] Query Silo Type
'//

MACRO ENHANCED_STORAGE_PROPERTY_QUERY_SILO_TYPE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2016)

'//
'// ENHANCED_STORAGE_PROPERTY_QUERY_SILO_RESULTS
'//   [ VT_BLOB ] Query Silo Properties result
'//

MACRO ENHANCED_STORAGE_PROPERTY_QUERY_SILO_RESULTS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(2017)

'//
'// Data format used for the password silo information property
'//

' // Size = 72 bytes
TYPE ENHANCED_STORAGE_PASSWORD_SILO_INFORMATION
   CurrentAdminFailures                  AS BYTE    ' BYTE
   CurrentUserFailures                   AS BYTE    ' BYTE
   alignment1__                          AS WORD    ' // To keep DWORD alignment
   TotalUserAuthenticationCount          AS DWORD   ' DWORD
   TotalAdminAuthenticationCount         AS DWORD   ' DWORD
   FipsCompliant                         AS LONG    ' BOOL
   SecurityIDAvailable                   AS LONG    ' BOOL
   InitializeInProgress                  AS LONG    ' BOOL
   ITMSArmed                             AS LONG    ' BOOL
   ITMSArmable                           AS LONG    ' BOOL
   UserCreated                           AS LONG    ' BOOL
   ResetOnPORDefault                     AS LONG    ' BOOL
   ResetOnPORCurrent                     AS LONG    ' BOOL
   MaxAdminFailures                      AS BYTE    ' BYTE
   MaxUserFailures                       AS BYTE    ' BYTE
   alignment2__                          AS WORD    ' // To keep DWORD alignment
   TimeToCompleteInitialization          AS DWORD   ' DWORD
   TimeRemainingToCompleteInitialization AS DWORD   ' DWORD
   MinTimeToAuthenticate                 AS DWORD   ' DWORD
   ' // Capabilities (never changed)
   MaxAdminPasswordSize                  AS BYTE    ' BYTE
   MinAdminPasswordSize                  AS BYTE    ' BYTE
   MaxAdminHintSize                      AS BYTE    ' BYTE
   MaxUserPasswordSize                   AS BYTE    ' BYTE
   MinUserPasswordSize                   AS BYTE    ' BYTE
   MaxUserHintSize                       AS BYTE    ' BYTE
   MaxUserNameSize                       AS BYTE    ' BYTE
   MaxSiloNameSize                       AS BYTE    ' BYTE
   MaxChallengeSize                      AS WORD    ' WORD
   alignment3__                          AS WORD    ' // To keep DWORD alignment
END TYPE

'// ---------------------------------------------------------------------------
'//
'// Certificate silo specific properties.
'//
'// ---------------------------------------------------------------------------

'//
'// ENHANCED_STORAGE_PROPERTY_MAX_CERTIFICATE_COUNT
'//   [ VT_UINT ] The number of certificate slots available on the device
'//

MACRO ENHANCED_STORAGE_PROPERTY_MAX_CERTIFICATE_COUNT = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3001)

'//
'// ENHANCED_STORAGE_PROPERTY_STORED_CERTIFICATE_COUNT
'//   [ VT_UINT ] The number of certificate slots in use on the device
'//

MACRO ENHANCED_STORAGE_PROPERTY_STORED_CERTIFICATE_COUNT = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3002)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX
'//   [ VT_UINT ] The index for the certificate slot on the device
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_INDEX = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3003)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_TYPE
'//  [ VT_UINT ] The type of certificate
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_TYPE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3004)

'//
'// Certificate Types defines
'//
%CERT_TYPE_EMPTY     = &H00    ' // No certificate
%CERT_TYPE_ASCm      = &H01    ' // Manufacturer's certificate (ASCm)
%CERT_TYPE_PCp       = &H02    ' // Provisioning Certificate (PCp)
%CERT_TYPE_ASCh      = &H03    ' // Authentication Silo Certificate (ASCh)
%CERT_TYPE_HCh       = &H04    ' // Host certificate (HCh)
%CERT_TYPE_SIGNER    = &H06    ' // Signer certificate (SCh)

'//
'// ENHANCED_STORAGE_PROPERTY_VALIDATION_POLICY
'//  [ VT_UINT ] The validation policy for the certificate
'//

MACRO ENHANCED_STORAGE_PROPERTY_VALIDATION_POLICY = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3005)

'//
'// Validation Policy values
'// - None: the corresponding private key of the stored certificate shall be used
'//         for authentication.
'// - Basic: the certificate and certificate chain conforms to the basic validation
'//         policy.
'// - Extended: the certificate chain conforms to the extended validation policy.
'//         The use of this validation policy must result in an error condition
'//         of the Authentication Silo if it does not support parsing of certificate
'//         extensions.
'//
%CERT_VALIDATION_POLICY_RESERVED             = &H00
%CERT_VALIDATION_POLICY_NONE                 = &H01
%CERT_VALIDATION_POLICY_BASIC                = &H02
%CERT_VALIDATION_POLICY_EXTENDED             = &H03

'//
'// ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_INDEX
'//  [ VT_UINT ] The index of the next valid cert
'//

MACRO ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_INDEX = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3006)

'//
'// ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_OF_TYPE_INDEX
'//  [ VT_UINT ] The index of the next valid cert of same type
'//

MACRO ENHANCED_STORAGE_PROPERTY_NEXT_CERTIFICATE_OF_TYPE_INDEX = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3007)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_LENGTH
'//  [ VT_UINT ] Length of the certificate in bytes
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_LENGTH = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3008)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE
'//   [ VT_VECTOR | VT_UI1 ] The certificate buffer in X.509 format
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3009)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_REQUEST
'//   [ VT_VECTOR | VT_UI1 ] The certificate request buffer
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_REQUEST = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3010)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_CAPABILITY_TYPE
'//  [ VT_UINT ] Silo capability type
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_CAPABILITY_TYPE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3011)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITY
'//  [ VT_VECTOR | VT_UINT ] The "raw" capability data return from the silo
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITY = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3012)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITIES
'//  [ VT_UNKNOWN ] The certificate silo capabilities returned in a collection
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_CAPABILITIES = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3013)

'//
'// Cert Silo Capability Types
'//
%CERT_CAPABILITY_HASH_ALG                    = &H1
%CERT_CAPABILITY_ASYMMETRIC_KEY_CRYPTOGRAPHY = &H2
%CERT_CAPABILITY_SIGNATURE_ALG               = &H3
%CERT_CAPABILITY_CERTIFICATE_SUPPORT         = &H4
%CERT_CAPABILITY_OPTIONAL_FEATURES           = &H5
%CERT_MAX_CAPABILITY                         = &HFF   ' // Maximum capability value

'//
'// Supported identifiers defined in 1667 spec
'//
$CERT_RSA_1024_OID = "1.2.840.113549.1.1.1,1024"
$CERT_RSA_2048_OID = "1.2.840.113549.1.1.1,2048"
$CERT_RSA_3072_OID = "1.2.840.113549.1.1.1,3072"
$CERT_RSASSA_PSS_SHA1_OID = "1.2.840.113549.1.1.10,1.3.14.3.2.26"
$CERT_RSASSA_PSS_SHA256_OID = "1.2.840.113549.1.1.10,2.16.840.1.101.3.4.2.1"
$CERT_RSASSA_PSS_SHA384_OID = "1.2.840.113549.1.1.10,2.16.840.1.101.3.4.2.2"
$CERT_RSASSA_PSS_SHA512_OID = "1.2.840.113549.1.1.10,2.16.840.1.101.3.4.2.3"

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_ACT_FRIENDLY_NAME
'//  [ VT_LPWSTR ] The certificate silo's ACT friendly name
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_ACT_FRIENDLY_NAME = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3014)

'//
'// ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_GUID
'//  [ VT_LPWSTR ] The certificate silo GUID
'//

MACRO ENHANCED_STORAGE_PROPERTY_CERTIFICATE_SILO_GUID = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3015)

'//
'// ENHANCED_STORAGE_PROPERTY_SIGNER CERTIFICATE_INDEX
'//   [ VT_UINT ] The index for the signer certificate slot on the device
'//

MACRO ENHANCED_STORAGE_PROPERTY_SIGNER_CERTIFICATE_INDEX = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(3016)


'// ---------------------------------------------------------------------------
'//
'// Silo capability specific properties.
'//
'// ---------------------------------------------------------------------------


'//
'// ENHANCED_STORAGE_CAPABILITY_HASH_ALGS
'//  [VT_LPWSTR] Semi-colon delimited string of hash algorithm identifiers
'//

MACRO ENHANCED_STORAGE_CAPABILITY_HASH_ALGS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(4001)

'//
'// ENHANCED_STORAGE_CAPABILITY_ASYMMETRIC_KEY_CRYPTOGRAPHY
'//  [VT_LPWSTR] Semi-colon delimited string of asymmetric key cryptography supported
'//

MACRO ENHANCED_STORAGE_CAPABILITY_ASYMMETRIC_KEY_CRYPTOGRAPHY = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(4002)

'//
'// ENHANCED_STORAGE_CAPABILITY_SIGNING_ALGS
'//  [VT_LPWSTR] Semi-colon delimited string of signing algorithm identifiers
'//

MACRO ENHANCED_STORAGE_CAPABILITY_SIGNING_ALGS = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(4003)

'//
'// ENHANCED_STORAGE_CAPABILITY_RENDER_USER_DATA_UNUSABLE
'//  [ VT_BOOL ] Boolean indicating whether silo can render user data unusable
'//

MACRO ENHANCED_STORAGE_CAPABILITY_RENDER_USER_DATA_UNUSABLE = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(4004)

'//
'// ENHANCED_STORAGE_CAPABILITY_CERTIFICATE_EXTENSION_PARSING
'//  [ VT_BOOL ] Boolean indicating whether certificate extension fields are supported
'//

MACRO ENHANCED_STORAGE_CAPABILITY_CERTIFICATE_EXTENSION_PARSING = GUID$("{91248166-b832-4ad4-baa4-7ca0b6b2798c}") & MKDWD$(4005)
