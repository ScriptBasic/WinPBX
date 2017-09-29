' ########################################################################################
' Microsoft Windows
' File: WinBio_Err.inc
' Contents: Definitions of error codes used by Windows Biometric Framework components.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#ifndef _WINBIO_ERR_H_06269BBC_B52E_4d0d_9D35_D23BEA12DE5D_
'%_WINBIO_ERR_H_06269BBC_B52E_4d0d_9D35_D23BEA12DE5D_

#INCLUDE THIS ONCE
%WINBIO_ERR_INC = 1

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// For now, WINBIO errors are piggy-backing on the Security
'// facility code. That may change in a future revision.
'//
'//
'// Error conditions -- values are in the range: 0x8001 - 0xFFFF
'//
'//
'//  Values are 32 bit values laid out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//
%FACILITY_WINBIO                  = &H9&


'//
'// Define the severity codes
'//


'//
'// MessageId: WINBIO_E_UNSUPPORTED_FACTOR
'//
'// MessageText:
'//
'// Windows Biometric Service doesn't support the specified biometric factor.
'//
%WINBIO_E_UNSUPPORTED_FACTOR      = &H80098001&

'//
'// MessageId: WINBIO_E_INVALID_UNIT
'//
'// MessageText:
'//
'// The unit ID number doesn't correspond to a valid biometric device.
'//
%WINBIO_E_INVALID_UNIT            = &H80098002&

'//
'// MessageId: WINBIO_E_UNKNOWN_ID
'//
'// MessageText:
'//
'// The biometric sample doesn't match any known identity.
'//
%WINBIO_E_UNKNOWN_ID              = &H80098003&

'//
'// MessageId: WINBIO_E_CANCELED
'//
'// MessageText:
'//
'// The biometric operation was canceled before it could complete.
'//
%WINBIO_E_CANCELED                = &H80098004&

'//
'// MessageId: WINBIO_E_NO_MATCH
'//
'// MessageText:
'//
'// The biometric sample doesn't match the specified identity or sub-factor.
'//
%WINBIO_E_NO_MATCH                = &H80098005&

'//
'// MessageId: WINBIO_E_CAPTURE_ABORTED
'//
'// MessageText:
'//
'// A biometric sample could not be captured because the operation was aborted.
'//
%WINBIO_E_CAPTURE_ABORTED         = &H80098006&

'//
'// MessageId: WINBIO_E_ENROLLMENT_IN_PROGRESS
'//
'// MessageText:
'//
'// An enrollment transaction could not be started because another enrollment is already in progress.
'//
%WINBIO_E_ENROLLMENT_IN_PROGRESS  = &H80098007&

'//
'// MessageId: WINBIO_E_BAD_CAPTURE
'//
'// MessageText:
'//
'// The captured sample cannot be used for any further biometric operations.
'//
%WINBIO_E_BAD_CAPTURE             = &H80098008&

'//
'// MessageId: WINBIO_E_INVALID_CONTROL_CODE
'//
'// MessageText:
'//
'// The biometric unit doesn't support the specified unit control code.
'//
%WINBIO_E_INVALID_CONTROL_CODE    = &H80098009&

'//
'// WINBIO_E_FACTOR_NOT_PRESENT - 0x8009800A
'// [OBSOLETE] - DO NOT USE
'//

'//
'// MessageId: WINBIO_E_DATA_COLLECTION_IN_PROGRESS
'//
'// MessageText:
'//
'// The driver already has a pending data collection operation in progress.
'//
%WINBIO_E_DATA_COLLECTION_IN_PROGRESS = &H8009800B&

'//
'// MessageId: WINBIO_E_UNSUPPORTED_DATA_FORMAT
'//
'// MessageText:
'//
'// The biometric sensor driver does not support the requested data format.
'//
%WINBIO_E_UNSUPPORTED_DATA_FORMAT = &H8009800C&

'//
'// MessageId: WINBIO_E_UNSUPPORTED_DATA_TYPE
'//
'// MessageText:
'//
'// The biometric sensor driver does not support the requested data type.
'//
%WINBIO_E_UNSUPPORTED_DATA_TYPE   = &H8009800D&

'//
'// MessageId: WINBIO_E_UNSUPPORTED_PURPOSE
'//
'// MessageText:
'//
'// The biometric sensor driver does not support the requested data purpose.
'//
%WINBIO_E_UNSUPPORTED_PURPOSE     = &H8009800E&

'//
'// MessageId: WINBIO_E_INVALID_DEVICE_STATE
'//
'// MessageText:
'//
'// The biometric unit is not in the proper state to perform the specified operation.
'//
%WINBIO_E_INVALID_DEVICE_STATE    = &H8009800F&

'//
'// MessageId: WINBIO_E_DEVICE_BUSY
'//
'// MessageText:
'//
'// The operation could not be performed because the sensor device was busy.
'//
%WINBIO_E_DEVICE_BUSY             = &H80098010&

'//
'// MessageId: WINBIO_E_DATABASE_CANT_CREATE
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to create a new database.
'//
%WINBIO_E_DATABASE_CANT_CREATE    = &H80098011&

'//
'// MessageId: WINBIO_E_DATABASE_CANT_OPEN
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to open an existing database.
'//
%WINBIO_E_DATABASE_CANT_OPEN      = &H80098012&

'//
'// MessageId: WINBIO_E_DATABASE_CANT_CLOSE
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to close a database.
'//
%WINBIO_E_DATABASE_CANT_CLOSE     = &H80098013&

'//
'// MessageId: WINBIO_E_DATABASE_CANT_ERASE
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to erase a database.
'//
%WINBIO_E_DATABASE_CANT_ERASE     = &H80098014&

'//
'// MessageId: WINBIO_E_DATABASE_CANT_FIND
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to find a database.
'//
%WINBIO_E_DATABASE_CANT_FIND      = &H80098015&

'//
'// MessageId: WINBIO_E_DATABASE_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to create a database because that database already exists.
'//
%WINBIO_E_DATABASE_ALREADY_EXISTS = &H80098016&

'//
'// WINBIO_E_DATABASE_INVALID_NAME - 0x80098017
'// [OBSOLETE] - DO NOT USE
'//

'//
'// MessageId: WINBIO_E_DATABASE_FULL
'//
'// MessageText:
'//
'// The biometric unit's storage adapter was unable to add a record to the database because the database is full.
'//
%WINBIO_E_DATABASE_FULL           = &H80098018&

'//
'// MessageId: WINBIO_E_DATABASE_LOCKED
'//
'// MessageText:
'//
'// The database is locked and its contents are inaccessible.
'//
%WINBIO_E_DATABASE_LOCKED         = &H80098019&

'//
'// MessageId: WINBIO_E_DATABASE_CORRUPTED
'//
'// MessageText:
'//
'// The contents of the database have become corrupted and are inaccessible.
'//
%WINBIO_E_DATABASE_CORRUPTED      = &H8009801A&

'//
'// MessageId: WINBIO_E_DATABASE_NO_SUCH_RECORD
'//
'// MessageText:
'//
'// No records were deleted because the specified identity and sub-factor are not present in the database.
'//
%WINBIO_E_DATABASE_NO_SUCH_RECORD = &H8009801B&

'//
'// MessageId: WINBIO_E_DUPLICATE_ENROLLMENT
'//
'// MessageText:
'//
'// The specified identity and sub-factor are already enrolled in the database.
'//
%WINBIO_E_DUPLICATE_ENROLLMENT    = &H8009801C&

'//
'// MessageId: WINBIO_E_DATABASE_READ_ERROR
'//
'// MessageText:
'//
'// An error occurred while trying to read from the database.
'//
%WINBIO_E_DATABASE_READ_ERROR     = &H8009801D&

'//
'// MessageId: WINBIO_E_DATABASE_WRITE_ERROR
'//
'// MessageText:
'//
'// An error occurred while trying to write to the database.
'//
%WINBIO_E_DATABASE_WRITE_ERROR    = &H8009801E&

'//
'// MessageId: WINBIO_E_DATABASE_NO_RESULTS
'//
'// MessageText:
'//
'// No records in the database matched the query.
'//
%WINBIO_E_DATABASE_NO_RESULTS     = &H8009801F&

'//
'// MessageId: WINBIO_E_DATABASE_NO_MORE_RECORDS
'//
'// MessageText:
'//
'// All records from the most recent database query have been viewed.
'//
%WINBIO_E_DATABASE_NO_MORE_RECORDS = &H80098020&

'//
'// MessageId: WINBIO_E_DATABASE_EOF
'//
'// MessageText:
'//
'// A database operation unexpectedly encountered the end of the file.
'//
%WINBIO_E_DATABASE_EOF            = &H80098021&

'//
'// MessageId: WINBIO_E_DATABASE_BAD_INDEX_VECTOR
'//
'// MessageText:
'//
'// A database operation failed due to a malformed index vector.
'//
%WINBIO_E_DATABASE_BAD_INDEX_VECTOR = &H80098022&

'//
'// WINBIO_E_INVALID_IDENTITY - 0x80098023
'// [OBSOLETE] - DO NOT USE
'//

'//
'// MessageId: WINBIO_E_INCORRECT_BSP
'//
'// MessageText:
'//
'// The biometric unit doesn't belong to the specified service provider.
'//
%WINBIO_E_INCORRECT_BSP           = &H80098024&

'//
'// MessageId: WINBIO_E_INCORRECT_SENSOR_POOL
'//
'// MessageText:
'//
'// The biometric unit doesn't belong to the specified sensor pool.
'//
%WINBIO_E_INCORRECT_SENSOR_POOL   = &H80098025&

'//
'// MessageId: WINBIO_E_NO_CAPTURE_DATA
'//
'// MessageText:
'//
'// The sensor adapter's capture buffer is empty.
'//
%WINBIO_E_NO_CAPTURE_DATA         = &H80098026&

'//
'// MessageId: WINBIO_E_INVALID_SENSOR_MODE
'//
'// MessageText:
'//
'// The sensor adapter doesn't support the sensor mode specified in the configuration.
'//
%WINBIO_E_INVALID_SENSOR_MODE     = &H80098027&

'//
'// MessageId: WINBIO_E_LOCK_VIOLATION
'//
'// MessageText:
'//
'// The requested operation cannot be performed due to a locking conflict.
'//
%WINBIO_E_LOCK_VIOLATION          = &H8009802A&

'//
'// MessageId: WINBIO_E_DUPLICATE_TEMPLATE
'//
'// MessageText:
'//
'// The data in a biometric template matches another template already in the database.
'//
%WINBIO_E_DUPLICATE_TEMPLATE      = &H8009802B&

'//
'// MessageId: WINBIO_E_INVALID_OPERATION
'//
'// MessageText:
'//
'// The requested operation is not valid for the current state of the session or biometric unit.
'//
%WINBIO_E_INVALID_OPERATION       = &H8009802C&

'//
'// MessageId: WINBIO_E_SESSION_BUSY
'//
'// MessageText:
'//
'// The session cannot begin a new operation because another operation is already in progress.
'//
%WINBIO_E_SESSION_BUSY            = &H8009802D&

'//
'// WINBIO_E_ASYNC_OPERATION_IN_PROGRESS - 0x8009802E
'// [OBSOLETE] - DO NOT USE
'//

'//
'// WINBIO_E_INVALID_ASYNC_OPERATION - 0x8009802F
'// [OBSOLETE] - DO NOT USE
'//

'//
'// MessageId: WINBIO_E_CRED_PROV_DISABLED
'//
'// MessageText:
'//
'// System policy settings have disabled the Windows biometric credential provider.
'//
%WINBIO_E_CRED_PROV_DISABLED      = &H80098030&

'//
'// MessageId: WINBIO_E_CRED_PROV_NO_CREDENTIAL
'//
'// MessageText:
'//
'// The requested credential was not found.
'//
%WINBIO_E_CRED_PROV_NO_CREDENTIAL = &H80098031&

'//
'// MessageId: WINBIO_E_DISABLED
'//
'// MessageText:
'//
'// System policy settings have disabled the Windows biometric service.
'//
%WINBIO_E_DISABLED                = &H80098032&

'//
'// MessageId: WINBIO_E_CONFIGURATION_FAILURE
'//
'// MessageText:
'//
'// The biometric unit could not be configured.
'//
%WINBIO_E_CONFIGURATION_FAILURE   = &H80098033&

'//
'// MessageId: WINBIO_E_SENSOR_UNAVAILABLE
'//
'// MessageText:
'//
'// A private pool cannot be created because one or more biometric units are not available.
'//
%WINBIO_E_SENSOR_UNAVAILABLE      = &H80098034&

'//
'// MessageId: WINBIO_E_SAS_ENABLED
'//
'// MessageText:
'//
'// A secure attention sequence (CTRL-ALT-DE& is required for logon.
'//
%WINBIO_E_SAS_ENABLED             = &H80098035&

'//
'// MessageId: WINBIO_E_DEVICE_FAILURE
'//
'// MessageText:
'//
'// A biometric sensor has failed.
'//
%WINBIO_E_DEVICE_FAILURE          = &H80098036&

'//
'// MessageId: WINBIO_E_FAST_USER_SWITCH_DISABLED
'//
'// MessageText:
'//
'// Fast user switching is disabled.
'//
%WINBIO_E_FAST_USER_SWITCH_DISABLED = &H80098037&

'//
'// MessageId: WINBIO_E_NOT_ACTIVE_CONSOLE
'//
'// MessageText:
'//
'// The System sensor pool cannot be opened from Terminal Server client sessions.
'//
%WINBIO_E_NOT_ACTIVE_CONSOLE      = &H80098038&

'//
'// MessageId: WINBIO_E_EVENT_MONITOR_ACTIVE
'//
'// MessageText:
'//
'// There is already an active event monitor associated with the specified session.
'//
%WINBIO_E_EVENT_MONITOR_ACTIVE    = &H80098039&

'//
'// MessageId: WINBIO_E_INVALID_PROPERTY_TYPE
'//
'// MessageText:
'//
'// The value specified is not a valid property type.
'//
%WINBIO_E_INVALID_PROPERTY_TYPE   = &H8009803A&

'//
'// MessageId: WINBIO_E_INVALID_PROPERTY_ID
'//
'// MessageText:
'//
'// The value specified is not a valid property ID.
'//
%WINBIO_E_INVALID_PROPERTY_ID     = &H8009803B&

'//
'// MessageId: WINBIO_E_UNSUPPORTED_PROPERTY
'//
'// MessageText:
'//
'// The biometric unit doesn't support the specified property.
'//
%WINBIO_E_UNSUPPORTED_PROPERTY    = &H8009803C&

'//
'// MessageId: WINBIO_E_ADAPTER_INTEGRITY_FAILURE
'//
'// MessageText:
'//
'// The adapter binary did not pass its integrity check.
'//
%WINBIO_E_ADAPTER_INTEGRITY_FAILURE = &H8009803D&

'//
'// Informational messages -- values are in the range: 0x0001 - 0x7FFF
'//
'//
'// MessageId: WINBIO_I_MORE_DATA
'//
'// MessageText:
'//
'// Another sample is needed for the current enrollment template.
'//
%WINBIO_I_MORE_DATA               = &H00090001&


'#endif '// (NTDDI_VERSION >= NTDDI_WIN7)
