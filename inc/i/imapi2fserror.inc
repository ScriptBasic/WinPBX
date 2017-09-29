' ########################################################################################
' Microsoft Windows
' File: imapi2fserror.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IMAPI2FSERROR_INC = 1

#INCLUDE ONCE "windows.inc"

'// Help for constructing this file was provided by
'// ms-help:'//MS.MSDNQTR.2003FEB.1033/tools/tools/about_message_text_files.htm
'// Refer to this documentation for message text syntax.

'#pragma once

'//Since the message codes are also included in the header file produced from the .idl, don't include them here

#IF NOT %DEF(%SKIP_FSI_ERROR_MESSAGE_CODES)

'// -----  Catch-all error(s) -- should not actually occur, indicative of internal state error  --------
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
%FACILITY_IMAPI2                  = &HAA


'//
'// Define the severity codes
'//


'//
'// MessageId: IMAPI_E_FSI_INTERNAL_ERROR
'//
'// MessageText:
'//
'// Internal file system error occurred.
'//
%IMAPI_E_FSI_INTERNAL_ERROR       = &HC0AAB100&

'// ----------------  Miscellenous interface errors   ------------------
'//
'// MessageId: IMAPI_E_INVALID_PARAM
'//
'// MessageText:
'//
'// The value specified for parameter '%1!ls!' is not valid.
'//
%IMAPI_E_INVALID_PARAM            = &HC0AAB101&

'//  NOTE:  the quote characters delimiting the parameter name are used by the Managed Shim
'//         to parse the parameter name from the message text for exception handling
'//         Don't remove or change these quote-delimiters w/o also changing the exception mapping
'//         in the managed shim.
'//
'// MessageId: IMAPI_E_READONLY
'//
'// MessageText:
'//
'// FileSystemImage object is in read only mode.
'//
%IMAPI_E_READONLY                 = &HC0AAB102&

'//
'// MessageId: IMAPI_E_NO_OUTPUT
'//
'// MessageText:
'//
'// No output file system specified.
'//
%IMAPI_E_NO_OUTPUT                = &HC0AAB103&

'//
'// MessageId: IMAPI_E_INVALID_VOLUME_NAME
'//
'// MessageText:
'//
'// The specified Volume Identifier is either too long or contains one or more invalid characters.
'//
%IMAPI_E_INVALID_VOLUME_NAME      = &HC0AAB104&

'//
'// MessageId: IMAPI_E_INVALID_DATE
'//
'// MessageText:
'//
'// Invalid file dates.  %1!ls! time is earlier than %2!ls! time.
'//
%IMAPI_E_INVALID_DATE             = &HC0AAB105&

'//
'// MessageId: IMAPI_E_FILE_SYSTEM_NOT_EMPTY
'//
'// MessageText:
'//
'// The file system must be empty for this function.
'//
%IMAPI_E_FILE_SYSTEM_NOT_EMPTY    = &HC0AAB106&

'// ----------------  Errors associated with state of item   ------------------
'//
'// MessageId: IMAPI_E_NOT_FILE
'//
'// MessageText:
'//
'// Specified path '%1!ls!' does not identify a file.
'//
%IMAPI_E_NOT_FILE                 = &HC0AAB108&

'//
'// MessageId: IMAPI_E_NOT_DIR
'//
'// MessageText:
'//
'// Specified path '%1!ls!' does not identify a directory.
'//
%IMAPI_E_NOT_DIR                  = &HC0AAB109&

'//
'// MessageId: IMAPI_E_DIR_NOT_EMPTY
'//
'// MessageText:
'//
'// The directory '%1!s!' is not empty.
'//
%IMAPI_E_DIR_NOT_EMPTY            = &HC0AAB10A&

'//
'// MessageId: IMAPI_E_NOT_IN_FILE_SYSTEM
'//
'// MessageText:
'//
'// '%1!ls!' is not part of the file system.  It must be added to complete this operation.
'//
%IMAPI_E_NOT_IN_FILE_SYSTEM       = &HC0AAB10B&

'// ----------------  Errors associated with file/directory naming problems   ------------------
'//
'// MessageId: IMAPI_E_INVALID_PATH
'//
'// MessageText:
'//
'// Path '%1!s!' is badly formed or contains invalid characters.
'//
%IMAPI_E_INVALID_PATH             = &HC0AAB110&

'//
'// MessageId: IMAPI_E_RESTRICTED_NAME_VIOLATION
'//
'// MessageText:
'//
'// The name '%1!ls!' specified is not legal:  Name of file or directory object created while the UseRestrictedCharacterSet property is set may only contain ANSI characters.
'//
%IMAPI_E_RESTRICTED_NAME_VIOLATION = &HC0AAB111&

'//
'// MessageId: IMAPI_E_DUP_NAME
'//
'// MessageText:
'//
'// '%1!ls!' name already exists.
'//
%IMAPI_E_DUP_NAME                 = &HC0AAB112&

'//
'// MessageId: IMAPI_E_NO_UNIQUE_NAME
'//
'// MessageText:
'//
'// Attempt to add '%1!ls!' failed:  cannot create a file-system-specific unique name for the %2!ls! file system.
'//
%IMAPI_E_NO_UNIQUE_NAME           = &HC0AAB113&

'// --------------  Errors reported when specified item not found in hierarchy  ---------------
'//
'// MessageId: IMAPI_E_ITEM_NOT_FOUND
'//
'// MessageText:
'//
'// Cannot find item '%1!ls!' in FileSystemImage hierarchy.
'//
%IMAPI_E_ITEM_NOT_FOUND           = &HC0AAB118&

'//
'// MessageId: IMAPI_E_FILE_NOT_FOUND
'//
'// MessageText:
'//
'// The file '%1!s!' not found in FileSystemImage hierarchy.
'//
%IMAPI_E_FILE_NOT_FOUND           = &HC0AAB119&

'//
'// MessageId: IMAPI_E_DIR_NOT_FOUND
'//
'// MessageText:
'//
'// The directory '%1!s!' not found in FileSystemImage hierarchy.
'//
%IMAPI_E_DIR_NOT_FOUND            = &HC0AAB11A&

'// ----------------  Image-size exceeds limit errors  ------------------
'//
'// MessageId: IMAPI_E_IMAGE_SIZE_LIMIT
'//
'// MessageText:
'//
'// Adding '%1!ls!' would result in a result image having a size larger than the current configured limit.
'//
%IMAPI_E_IMAGE_SIZE_LIMIT         = &HC0AAB120&

'//
'// MessageId: IMAPI_E_IMAGE_TOO_BIG
'//
'// MessageText:
'//
'// Value specified for FreeMediaBlocks property is too small for estimated image size based on current data.
'//
%IMAPI_E_IMAGE_TOO_BIG            = &HC0AAB121&

'// ----------------  User file-data stream errors  ------------------
'//
'// MessageId: IMAPI_E_DATA_STREAM_INCONSISTENCY
'//
'// MessageText:
'//
'// Data stream supplied for file '%1!ls!' is inconsistent:  expected %2!I64d! bytes, found %3!I64d!.
'//
%IMAPI_E_DATA_STREAM_INCONSISTENCY = &HC0AAB128&

'//
'// MessageId: IMAPI_E_DATA_STREAM_READ_FAILURE
'//
'// MessageText:
'//
'// Cannot read data from stream supplied for file '%1!ls!'.
'//
%IMAPI_E_DATA_STREAM_READ_FAILURE = &HC0AAB129&

'//
'// MessageId: IMAPI_E_DATA_STREAM_CREATE_FAILURE
'//
'// MessageText:
'//
'// The following error was encountered when trying to create data stream for '%1!ls!':
'//
%IMAPI_E_DATA_STREAM_CREATE_FAILURE = &HC0AAB12A&

'//
'// MessageId: IMAPI_E_DIRECTORY_READ_FAILURE
'//
'// MessageText:
'//
'// The following error was encountered when trying to enumerate files in directory '%1!ls!':
'//
%IMAPI_E_DIRECTORY_READ_FAILURE   = &HC0AAB12B&

'// ----------------  FileSystem-specific limitations  ------------------
'//
'// MessageId: IMAPI_E_TOO_MANY_DIRS
'//
'// MessageText:
'//
'// This file system image has too many directories for the %1!ls! file system.
'//
%IMAPI_E_TOO_MANY_DIRS            = &HC0AAB130&

'//
'// MessageId: IMAPI_E_ISO9660_LEVELS
'//
'// MessageText:
'//
'// ISO9660 is limited to 8 levels of directories.
'//
%IMAPI_E_ISO9660_LEVELS           = &HC0AAB131&

'//
'// MessageId: IMAPI_E_DATA_TOO_BIG
'//
'// MessageText:
'//
'// Data file is too large for '%1!ls!' file system.
'//
%IMAPI_E_DATA_TOO_BIG             = &HC0AAB132&

'//
'// MessageId: IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION
'//
'// MessageText:
'//
'// Operation failed because of incompatible layout of the previous session imported from the medium.
'//
%IMAPI_E_INCOMPATIBLE_PREVIOUS_SESSION = &HC0AAB133&

'// ----------------  Errors associated with stash-file operations   ------------------
'//
'// MessageId: IMAPI_E_STASHFILE_OPEN_FAILURE
'//
'// MessageText:
'//
'// Cannot initialize %1!ls! stash file.
'//
%IMAPI_E_STASHFILE_OPEN_FAILURE   = &HC0AAB138&

'//
'// MessageId: IMAPI_E_STASHFILE_SEEK_FAILURE
'//
'// MessageText:
'//
'// Error seeking in '%1!ls!' stash file.
'//
%IMAPI_E_STASHFILE_SEEK_FAILURE   = &HC0AAB139&

'//
'// MessageId: IMAPI_E_STASHFILE_WRITE_FAILURE
'//
'// MessageText:
'//
'// Error encountered writing to '%1!ls!' stash file.
'//
%IMAPI_E_STASHFILE_WRITE_FAILURE  = &HC0AAB13A&

'//
'// MessageId: IMAPI_E_STASHFILE_READ_FAILURE
'//
'// MessageText:
'//
'// Error encountered reading from '%1!ls!' stash file.
'//
%IMAPI_E_STASHFILE_READ_FAILURE   = &HC0AAB13B&

'// ----------------  Errors associated with attempt to set working directory  ------------------
'//
'// MessageId: IMAPI_E_INVALID_WORKING_DIRECTORY
'//
'// MessageText:
'//
'// The working directory '%1!ls!' is not valid.
'//
%IMAPI_E_INVALID_WORKING_DIRECTORY = &HC0AAB140&

'//
'// MessageId: IMAPI_E_WORKING_DIRECTORY_SPACE
'//
'// MessageText:
'//
'// Cannot set working directory to '%1!ls!'.  Space available is %2!I64d! bytes, approximately %3!I64d! bytes required.
'//
%IMAPI_E_WORKING_DIRECTORY_SPACE  = &HC0AAB141&

'//
'// MessageId: IMAPI_E_STASHFILE_MOVE
'//
'// MessageText:
'//
'// Attempt to move the data stash file to directory '%1!ls!' was not successful.
'//
%IMAPI_E_STASHFILE_MOVE           = &HC0AAB142&

'// ----------------  Errors associated with Boot Image object   ------------------
'//
'// MessageId: IMAPI_E_BOOT_IMAGE_DATA
'//
'// MessageText:
'//
'// The boot object could not be added to the image.
'//
%IMAPI_E_BOOT_IMAGE_DATA          = &HC0AAB148&

'//
'// MessageId: IMAPI_E_BOOT_OBJECT_CONFLICT
'//
'// MessageText:
'//
'// A boot object can only be included in an initial disc image.
'//
%IMAPI_E_BOOT_OBJECT_CONFLICT     = &HC0AAB149&

'//
'// MessageId: IMAPI_E_BOOT_EMULATION_IMAGE_SIZE_MISMATCH
'//
'// MessageText:
'//
'// The emulation type requested does not match the boot image size.
'//
%IMAPI_E_BOOT_EMULATION_IMAGE_SIZE_MISMATCH = &HC0AAB14A&

'// ----------------  Errors associated with import operation   ------------------
'//
'// MessageId: IMAPI_E_EMPTY_DISC
'//
'// MessageText:
'//
'// Optical media is empty.
'//
%IMAPI_E_EMPTY_DISC               = &HC0AAB150&

'//
'// MessageId: IMAPI_E_NO_SUPPORTED_FILE_SYSTEM
'//
'// MessageText:
'//
'// The specified disc does not contain one of the supported file systems.
'//
%IMAPI_E_NO_SUPPORTED_FILE_SYSTEM = &HC0AAB151&

'//
'// MessageId: IMAPI_E_FILE_SYSTEM_NOT_FOUND
'//
'// MessageText:
'//
'// The specified disc does not contain a '%1!ls!' file system.
'//
%IMAPI_E_FILE_SYSTEM_NOT_FOUND    = &HC0AAB152&

'//
'// MessageId: IMAPI_E_FILE_SYSTEM_READ_CONSISTENCY_ERROR
'//
'// MessageText:
'//
'// Consistency error encountered while importing the '%1!ls!' file system.
'//
%IMAPI_E_FILE_SYSTEM_READ_CONSISTENCY_ERROR = &HC0AAB153&

'//
'// MessageId: IMAPI_E_FILE_SYSTEM_FEATURE_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The '%1!ls!'file system on the selected disc contains a feature not supported for import.
'//
%IMAPI_E_FILE_SYSTEM_FEATURE_NOT_SUPPORTED = &HC0AAB154&

'//
'// MessageId: IMAPI_E_IMPORT_TYPE_COLLISION_FILE_EXISTS_AS_DIRECTORY
'//
'// MessageText:
'//
'// Could not import %2!ls! file system from disc.  The file '%1!ls!' already exists within the image hierarchy as a directory.
'//
%IMAPI_E_IMPORT_TYPE_COLLISION_FILE_EXISTS_AS_DIRECTORY = &HC0AAB155&

'//
'// MessageId: IMAPI_E_IMPORT_SEEK_FAILURE
'//
'// MessageText:
'//
'// Cannot seek to block %1!I64d! on source disc.
'//
%IMAPI_E_IMPORT_SEEK_FAILURE      = &HC0AAB156&

'//
'// MessageId: IMAPI_E_IMPORT_READ_FAILURE
'//
'// MessageText:
'//
'// Import from previous session failed due to an error reading a block on the media (most likely block %1!u!).
'//
%IMAPI_E_IMPORT_READ_FAILURE      = &HC0AAB157&

'//
'// MessageId: IMAPI_E_DISC_MISMATCH
'//
'// MessageText:
'//
'// Current disc is not the same one from which file system was imported.
'//
%IMAPI_E_DISC_MISMATCH            = &HC0AAB158&

'//
'// MessageId: IMAPI_E_IMPORT_MEDIA_NOT_ALLOWED
'//
'// MessageText:
'//
'// IMAPI does not allow multi-session with the current media type.
'//
%IMAPI_E_IMPORT_MEDIA_NOT_ALLOWED = &HC0AAB159&

'//
'// MessageId: IMAPI_E_UDF_NOT_WRITE_COMPATIBLE
'//
'// MessageText:
'//
'// IMAPI can not do multi-session with the current media because it does not support a compatible UDF revision for write.
'//
%IMAPI_E_UDF_NOT_WRITE_COMPATIBLE = &HC0AAB15A&

'//
'// MessageId: IMAPI_E_INCOMPATIBLE_MULTISESSION_TYPE
'//
'// MessageText:
'//
'// IMAPI does not support the multisession type requested.
'//
%IMAPI_E_INCOMPATIBLE_MULTISESSION_TYPE = &HC0AAB15B&

'//
'// MessageId: IMAPI_E_NO_COMPATIBLE_MULTISESSION_TYPE
'//
'// MessageText:
'//
'// IMAPI supports none of the multisession type(s) provided on the current media.
'//
%IMAPI_E_NO_COMPATIBLE_MULTISESSION_TYPE = &HC0AAB15C&

'//
'// MessageId: IMAPI_E_MULTISESSION_NOT_SET
'//
'// MessageText:
'//
'// MultisessionInterfaces property must be set prior calling this method.
'//
%IMAPI_E_MULTISESSION_NOT_SET     = &HC0AAB15D&

'//
'// MessageId: IMAPI_E_IMPORT_TYPE_COLLISION_DIRECTORY_EXISTS_AS_FILE
'//
'// MessageText:
'//
'// Could not import %2!ls! file system from disc.  The directory '%1!ls!' already exists within the image hierarchy as a file.
'//
%IMAPI_E_IMPORT_TYPE_COLLISION_DIRECTORY_EXISTS_AS_FILE = &HC0AAB15E&

'//
'// MessageId: IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Feature is not supported for the current file system revision, image will be created without this feature.
'//
%IMAPI_S_IMAGE_FEATURE_NOT_SUPPORTED = &H00AAB15F&

'//
'// MessageId: IMAPI_E_PROPERTY_NOT_ACCESSIBLE
'//
'// MessageText:
'//
'// Property '%1!ls!' is not accessible
'//
%IMAPI_E_PROPERTY_NOT_ACCESSIBLE  = &HC0AAB160&

'//
'// MessageId: IMAPI_E_UDF_REVISION_CHANGE_NOT_ALLOWED
'//
'// MessageText:
'//
'// UDF revision cannot be changed because of the previously imported session
'//
%IMAPI_E_UDF_REVISION_CHANGE_NOT_ALLOWED = &HC0AAB161&

'//
'// MessageId: IMAPI_E_BAD_MULTISESSION_PARAMETER
'//
'// MessageText:
'//
'// One of the multisession parameters cannot be retrieved or has a wrong value.
'//
%IMAPI_E_BAD_MULTISESSION_PARAMETER = &HC0AAB162&

'//
'// MessageId: IMAPI_E_FILE_SYSTEM_CHANGE_NOT_ALLOWED
'//
'// MessageText:
'//
'// You cannot change the file system to be created, because the file system in the imported session and the one in the new session must match.
'//
%IMAPI_E_FILE_SYSTEM_CHANGE_NOT_ALLOWED = &HC0AAB163&

'// ------ Error messages for IIsoImageManager (range: 0x80AAB200 - 0x80AAB2FF) ------
'//
'// MessageId: IMAPI_E_IMAGEMANAGER_IMAGE_NOT_ALIGNED
'//
'// MessageText:
'//
'// The image is not 2kb aligned. Only 2048 bytes aligned images are supported.
'//
%IMAPI_E_IMAGEMANAGER_IMAGE_NOT_ALIGNED = &HC0AAB200&

'//
'// MessageId: IMAPI_E_IMAGEMANAGER_NO_VALID_VD_FOUND
'//
'// MessageText:
'//
'// No valid file system Volume Descriptor was found in the iso image. This image format is not supported and the resulting disc might not be readable.
'//
%IMAPI_E_IMAGEMANAGER_NO_VALID_VD_FOUND = &HC0AAB201&

'//
'// MessageId: IMAPI_E_IMAGEMANAGER_NO_IMAGE
'//
'// MessageText:
'//
'// No image was set (neither path nor stream was given).
'//
%IMAPI_E_IMAGEMANAGER_NO_IMAGE    = &HC0AAB202&

'//
'// MessageId: IMAPI_E_IMAGEMANAGER_IMAGE_TOO_BIG
'//
'// MessageText:
'//
'// Image size exceeds MAXLONG sectors - too big.
'//
%IMAPI_E_IMAGEMANAGER_IMAGE_TOO_BIG = &HC0AAB203&

'// ----------- Empty message, should not occur, used for internal purposes ------------------
'//
'// MessageId: 0x0000FFFFL (No symbolic name defined)
'//
'// MessageText:
'//
'// (empty message)

#ENDIF      '// #ifndef _SKIP_FSI_ERROR_MESSAGE_CODES

%IMAPI_ERROR_FIRST     = &HB100???   ' (unsigned int)0xB100
%IMAPI_ERROR_LAST      = &HB2FF???   ' (unsigned int)0xB2FF

'#define IMAPIError(hr) ((HRESULT_FACILITY(hr) == FACILITY_IMAPI2) && (HRESULT_CODE(hr) <= IMAPI_ERROR_LAST) && (HRESULT_CODE(hr) >= IMAPI_ERROR_FIRST))
MACRO IMAPIError(hr) = ((HRESULT_FACILITY(hr) = %FACILITY_IMAPI2) AND (HRESULT_CODE(hr) <= %IMAPI_ERROR_LAST) AND (HRESULT_CODE(hr) >= %IMAPI_ERROR_FIRST))

%IMAPI_FSI_ERROR_FIRST = &HB100???   ' (unsigned int)0xB100
%IMAPI_FSI_ERROR_LAST  = &HB2FF???   '(unsigned int)0xB2FF

'#define IMAPIFsiError(hr) ((HRESULT_FACILITY(hr) == FACILITY_IMAPI2) && (HRESULT_CODE(hr) <= IMAPI_FSI_ERROR_LAST) && (HRESULT_CODE(hr) >= IMAPI_FSI_ERROR_FIRST))

MACRO IMAPIFsiError(hr) = ((HRESULT_FACILITY(hr) = %FACILITY_IMAPI2) AND (HRESULT_CODE(hr) <= %IMAPI_FSI_ERROR_LAST) AND (HRESULT_CODE(hr) >= %IMAPI_FSI_ERROR_FIRST))
