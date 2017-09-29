' ########################################################################################
' Microsoft Windows
' File: imapi2error.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IMAPI2ERROR_INC = 1

'//
'// Error Messages used throughout IMAPIv2
'// Range: 0x80AA0000 - 0x80AA00FF
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


'//
'// Define the severity codes
'//


'//
'// MessageId: E_IMAPI_REQUEST_CANCELLED
'//
'// MessageText:
'//
'//
'// The request was cancelled.
%E_IMAPI_REQUEST_CANCELLED        = &HC0AA0002&

'//
'// MessageId: E_IMAPI_RECORDER_REQUIRED
'//
'// MessageText:
'//
'// The request requires a current disc recorder to be selected.
'//
%E_IMAPI_RECORDER_REQUIRED        = &HC0AA0003&

'//
'// MessageId: S_IMAPI_SPEEDADJUSTED
'//
'// MessageText:
'//
'// The requested write speed was not supported by the drive and the speed was adjusted.
'//
%S_IMAPI_SPEEDADJUSTED            = &H00AA0004&

'//
'// MessageId: S_IMAPI_ROTATIONADJUSTED
'//
'// MessageText:
'//
'// The requested rotation type was not supported by the drive and the rotation type was adjusted.
'//
%S_IMAPI_ROTATIONADJUSTED         = &H00AA0005&

'//
'// MessageId: S_IMAPI_BOTHADJUSTED
'//
'// MessageText:
'//
'// The requested write speed and rotation type were not supported by the drive and they were both adjusted.
'//
%S_IMAPI_BOTHADJUSTED             = &H00AA0006&

'//
'// MessageId: E_IMAPI_BURN_VERIFICATION_FAILED
'//
'// MessageText:
'//
'// The disc did not pass burn verification and may contain corrupt data or be unusable.
'//
%E_IMAPI_BURN_VERIFICATION_FAILED = &HC0AA0007&

'//
'// Error Messages for IDiscMaster2
'// Range: 0x80AA0100 - 0x80AA01FF
'//


'//
'// Error Messages for IDiscRecorder2
'// Range: 0x80AA0200 - 0x80AA02FF
'//

'//
'// MessageId: S_IMAPI_COMMAND_HAS_SENSE_DATA
'//
'// MessageText:
'//
'// The device accepted the command, but returned sense data, indicating an error.
'//
%S_IMAPI_COMMAND_HAS_SENSE_DATA   = &H00AA0200&

'//
'// MessageId: E_IMAPI_RECORDER_NO_SUCH_MODE_PAGE
'//
'// MessageText:
'//
'// The device reported that the requested mode page (and type) is not present.
'//
%E_IMAPI_RECORDER_NO_SUCH_MODE_PAGE = &HC0AA0201&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_NO_MEDIA
'//
'// MessageText:
'//
'// There is no media in the device.
'//
%E_IMAPI_RECORDER_MEDIA_NO_MEDIA  = &HC0AA0202&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_INCOMPATIBLE
'//
'// MessageText:
'//
'// The media is not compatible or of unknown physical format.
'//
%E_IMAPI_RECORDER_MEDIA_INCOMPATIBLE = &HC0AA0203&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_UPSIDE_DOWN
'//
'// MessageText:
'//
'// The media is inserted upside down.
'//
%E_IMAPI_RECORDER_MEDIA_UPSIDE_DOWN = &HC0AA0204&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_BECOMING_READY
'//
'// MessageText:
'//
'// The drive reported that it is in the process of becoming ready.  Please try the request again later.
'//
%E_IMAPI_RECORDER_MEDIA_BECOMING_READY = &HC0AA0205&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_FORMAT_IN_PROGRESS
'//
'// MessageText:
'//
'// The media is currently being formatted.  Please wait for the format to complete before attempting to use the media.
'//
%E_IMAPI_RECORDER_MEDIA_FORMAT_IN_PROGRESS = &HC0AA0206&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_BUSY
'//
'// MessageText:
'//
'// The drive reported that it is performing a long-running operation, such as finishing a write.  The drive may be unusable for a long period of time.
'//
%E_IMAPI_RECORDER_MEDIA_BUSY      = &HC0AA0207&

'//
'// MessageId: E_IMAPI_RECORDER_INVALID_MODE_PARAMETERS
'//
'// MessageText:
'//
'// The drive reported that the combination of parameters provided in the mode page for a MODE SELECT command were not supported.
'//
%E_IMAPI_RECORDER_INVALID_MODE_PARAMETERS = &HC0AA0208&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_WRITE_PROTECTED
'//
'// MessageText:
'//
'// The drive reported that the media is write protected.
'//
%E_IMAPI_RECORDER_MEDIA_WRITE_PROTECTED = &HC0AA0209&

'//
'// MessageId: E_IMAPI_RECORDER_NO_SUCH_FEATURE
'//
'// MessageText:
'//
'// The feature page requested is not supported by the device.
'//
%E_IMAPI_RECORDER_NO_SUCH_FEATURE = &HC0AA020A&

'//
'// MessageId: E_IMAPI_RECORDER_FEATURE_IS_NOT_CURRENT
'//
'// MessageText:
'//
'// The feature page requested is supported, but is not marked as current.
'//
%E_IMAPI_RECORDER_FEATURE_IS_NOT_CURRENT = &HC0AA020B&

'//
'// MessageId: E_IMAPI_RECORDER_GET_CONFIGURATION_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The drive does not support the GET CONFIGURATION command.
'//
%E_IMAPI_RECORDER_GET_CONFIGURATION_NOT_SUPPORTED = &HC0AA020C&

'//
'// MessageId: E_IMAPI_RECORDER_COMMAND_TIMEOUT
'//
'// MessageText:
'//
'// The device failed to accept the command within the timeout period. This may be caused by the device having entered an inconsistent state, or the timeout value for the command may need to be increased.
'//
%E_IMAPI_RECORDER_COMMAND_TIMEOUT = &HC0AA020D&

'//
'// MessageId: E_IMAPI_RECORDER_DVD_STRUCTURE_NOT_PRESENT
'//
'// MessageText:
'//
'// The device failed to accept the command within the timeout period. This may be caused by the device having entered an inconsistent state, or the timeout value for the command may need to be increased.
'//
%E_IMAPI_RECORDER_DVD_STRUCTURE_NOT_PRESENT = &HC0AA020E&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_SPEED_MISMATCH
'//
'// MessageText:
'//
'// The media's speed is incompatible with the device.  This may be caused by using higher or lower speed media than the range of speeds supported by the device.
'//
%E_IMAPI_RECORDER_MEDIA_SPEED_MISMATCH = &HC0AA020F&

'//
'// MessageId: E_IMAPI_RECORDER_LOCKED
'//
'// MessageText:
'//
'// The device associated with this recorder during the last operation has been exclusively locked, causing this operation to failed.
'//
%E_IMAPI_RECORDER_LOCKED          = &HC0AA0210&

'//
'// MessageId: E_IMAPI_RECORDER_CLIENT_NAME_IS_NOT_VALID
'//
'// MessageText:
'//
'// The client name is not valid.
'//
%E_IMAPI_RECORDER_CLIENT_NAME_IS_NOT_VALID = &HC0AA0211&

'//
'// MessageId: E_IMAPI_RECORDER_MEDIA_NOT_FORMATTED
'//
'// MessageText:
'//
'// The media is not formatted. Please format the media before attempting to use it.
'//
%E_IMAPI_RECORDER_MEDIA_NOT_FORMATTED = &HC0AA0212&

'//
'// MessageId: E_IMAPI_RECORDER_INVALID_RESPONSE_FROM_DEVICE
'//
'// MessageText:
'//
'// The device reported unexpected or invalid data for a command.
'//
%E_IMAPI_RECORDER_INVALID_RESPONSE_FROM_DEVICE = &HC0AA02FF&


'//
'// Error Messages for IWriteEngine2
'// Range: 0x80AA0300 - 0x80AA03FF
'//

'//
'// MessageId: E_IMAPI_LOSS_OF_STREAMING
'//
'// MessageText:
'//
'// The write failed because the drive did not receive data quickly enough to continue writing. Moving the source data to the local computer, reducing the write speed, or enabling a "buffer underrun free" setting may resolve this issue.
'//
%E_IMAPI_LOSS_OF_STREAMING        = &HC0AA0300&

'//
'// MessageId: E_IMAPI_UNEXPECTED_RESPONSE_FROM_DEVICE
'//
'// MessageText:
'//
'// The write failed because the drive returned error information that could not be recovered from.
'//
%E_IMAPI_UNEXPECTED_RESPONSE_FROM_DEVICE = &HC0AA0301&

'//
'// MessageId: S_IMAPI_WRITE_NOT_IN_PROGRESS
'//
'// MessageText:
'//
'// There is no write operation currently in progress.
'//
%S_IMAPI_WRITE_NOT_IN_PROGRESS    = &H00AA0302&

'//
'// Error Messages for IDiscFormat2Data
'// Range: 0x80AA0400 - 0x80AA04FF
'//

'//
'// MessageId: E_IMAPI_DF2DATA_WRITE_IN_PROGRESS
'//
'// MessageText:
'//
'// There is currently a write operation in progress.
'//
%E_IMAPI_DF2DATA_WRITE_IN_PROGRESS = &HC0AA0400&

'//
'// MessageId: E_IMAPI_DF2DATA_WRITE_NOT_IN_PROGRESS
'//
'// MessageText:
'//
'// There is no write operation currently in progress.
'//
%E_IMAPI_DF2DATA_WRITE_NOT_IN_PROGRESS = &HC0AA0401&

'//
'// MessageId: E_IMAPI_DF2DATA_INVALID_MEDIA_STATE
'//
'// MessageText:
'//
'// The requested operation is only valid with supported media.
'//
%E_IMAPI_DF2DATA_INVALID_MEDIA_STATE = &HC0AA0402&

'//
'// MessageId: E_IMAPI_DF2DATA_STREAM_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The provided stream to write is not supported.
'//
%E_IMAPI_DF2DATA_STREAM_NOT_SUPPORTED = &HC0AA0403&

'//
'// MessageId: E_IMAPI_DF2DATA_STREAM_TOO_LARGE_FOR_CURRENT_MEDIA
'//
'// MessageText:
'//
'// The provided stream to write is too large for the currently inserted media.
'//
%E_IMAPI_DF2DATA_STREAM_TOO_LARGE_FOR_CURRENT_MEDIA = &HC0AA0404&

'//
'// MessageId: E_IMAPI_DF2DATA_MEDIA_NOT_BLANK
'//
'// MessageText:
'//
'// Overwriting non-blank media is not allowed without the ForceOverwrite property set to VARIANT_TRUE.
'//
%E_IMAPI_DF2DATA_MEDIA_NOT_BLANK  = &HC0AA0405&

'//
'// MessageId: E_IMAPI_DF2DATA_MEDIA_IS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The current media type is unsupported.
'//
%E_IMAPI_DF2DATA_MEDIA_IS_NOT_SUPPORTED = &HC0AA0406&

'//
'// MessageId: E_IMAPI_DF2DATA_RECORDER_NOT_SUPPORTED
'//
'// MessageText:
'//
'// This device does not support the operations required by this disc format.
'//
%E_IMAPI_DF2DATA_RECORDER_NOT_SUPPORTED = &HC0AA0407&

'//
'// MessageId: E_IMAPI_DF2DATA_CLIENT_NAME_IS_NOT_VALID
'//
'// MessageText:
'//
'// The client name is not valid.
'//
%E_IMAPI_DF2DATA_CLIENT_NAME_IS_NOT_VALID = &HC0AA0408&


'//
'// Error Messages for IDiscFormat2TrackAtOnce
'// Range: 0x80AA0500 - 0x80AA05FF
'//

'//
'// MessageId: E_IMAPI_DF2TAO_WRITE_IN_PROGRESS
'//
'// MessageText:
'//
'// There is currently a write operation in progress.
'//
%E_IMAPI_DF2TAO_WRITE_IN_PROGRESS = &HC0AA0500&

'//
'// MessageId: E_IMAPI_DF2TAO_WRITE_NOT_IN_PROGRESS
'//
'// MessageText:
'//
'// There is no write operation currently in progress.
'//
%E_IMAPI_DF2TAO_WRITE_NOT_IN_PROGRESS = &HC0AA0501&

'//
'// MessageId: E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED
'//
'// MessageText:
'//
'// The requested operation is only valid when media has been "prepared".
'//
%E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED = &HC0AA0502&

'//
'// MessageId: E_IMAPI_DF2TAO_MEDIA_IS_PREPARED
'//
'// MessageText:
'//
'// The requested operation is not valid when media has been "prepared" but not released.
'//
%E_IMAPI_DF2TAO_MEDIA_IS_PREPARED = &HC0AA0503&

'//
'// MessageId: E_IMAPI_DF2TAO_PROPERTY_FOR_BLANK_MEDIA_ONLY
'//
'// MessageText:
'//
'// The property cannot be changed once the media has been written to.
'//
%E_IMAPI_DF2TAO_PROPERTY_FOR_BLANK_MEDIA_ONLY = &HC0AA0504&

'//
'// MessageId: E_IMAPI_DF2TAO_TABLE_OF_CONTENTS_EMPTY_DISC
'//
'// MessageText:
'//
'// The table of contents cannot be retrieved from an empty disc.
'//
%E_IMAPI_DF2TAO_TABLE_OF_CONTENTS_EMPTY_DISC = &HC0AA0505&

'//
'// MessageId: E_IMAPI_DF2TAO_MEDIA_IS_NOT_BLANK
'//
'// MessageText:
'//
'// Only blank CD-R/RW media is supported.
'//
%E_IMAPI_DF2TAO_MEDIA_IS_NOT_BLANK = &HC0AA0506&

'//
'// MessageId: E_IMAPI_DF2TAO_MEDIA_IS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Only blank CD-R/RW media is supported.
'//
%E_IMAPI_DF2TAO_MEDIA_IS_NOT_SUPPORTED = &HC0AA0507&

'//
'// MessageId: E_IMAPI_DF2TAO_TRACK_LIMIT_REACHED
'//
'// MessageText:
'//
'// CD-R and CD-RW media support a maximum of 99 audio tracks.
'//
%E_IMAPI_DF2TAO_TRACK_LIMIT_REACHED = &HC0AA0508&

'//
'// MessageId: E_IMAPI_DF2TAO_NOT_ENOUGH_SPACE
'//
'// MessageText:
'//
'// There is not enough space left on the media to add the provided audio track.
'//
%E_IMAPI_DF2TAO_NOT_ENOUGH_SPACE  = &HC0AA0509&

'//
'// MessageId: E_IMAPI_DF2TAO_NO_RECORDER_SPECIFIED
'//
'// MessageText:
'//
'// You cannot prepare the media until you choose a recorder to use.
'//
%E_IMAPI_DF2TAO_NO_RECORDER_SPECIFIED = &HC0AA050A&

'//
'// MessageId: E_IMAPI_DF2TAO_INVALID_ISRC
'//
'// MessageText:
'//
'// The ISRC provided is not valid.
'//
%E_IMAPI_DF2TAO_INVALID_ISRC      = &HC0AA050B&

'//
'// MessageId: E_IMAPI_DF2TAO_INVALID_MCN
'//
'// MessageText:
'//
'// The Media Catalog Number provided is not valid.
'//
%E_IMAPI_DF2TAO_INVALID_MCN       = &HC0AA050C&

'//
'// MessageId: E_IMAPI_DF2TAO_STREAM_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The provided audio stream is not valid.
'//
%E_IMAPI_DF2TAO_STREAM_NOT_SUPPORTED = &HC0AA050D&

'//
'// MessageId: E_IMAPI_DF2TAO_RECORDER_NOT_SUPPORTED
'//
'// MessageText:
'//
'// This device does not support the operations required by this disc format.
'//
%E_IMAPI_DF2TAO_RECORDER_NOT_SUPPORTED = &HC0AA050E&

'//
'// MessageId: E_IMAPI_DF2TAO_CLIENT_NAME_IS_NOT_VALID
'//
'// MessageText:
'//
'// The client name is not valid.
'//
%E_IMAPI_DF2TAO_CLIENT_NAME_IS_NOT_VALID = &HC0AA050F&


'//
'// Error Messages for IDiscFormat2RawCD
'// Range: 0x80AA0600 - 0x80AA06FF
'//
'// 0x0605, 0x0608, 0x060B, 0x060C are not used

'//
'// MessageId: E_IMAPI_DF2RAW_WRITE_IN_PROGRESS
'//
'// MessageText:
'//
'// There is currently a write operation in progress.
'//
%E_IMAPI_DF2RAW_WRITE_IN_PROGRESS = &HC0AA0600&

'//
'// MessageId: E_IMAPI_DF2RAW_WRITE_NOT_IN_PROGRESS
'//
'// MessageText:
'//
'// There is no write operation currently in progress.
'//
%E_IMAPI_DF2RAW_WRITE_NOT_IN_PROGRESS = &HC0AA0601&

'//
'// MessageId: E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED
'//
'// MessageText:
'//
'// The requested operation is only valid when media has been "prepared".
'//
%E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED = &HC0AA0602&

'//
'// MessageId: E_IMAPI_DF2RAW_MEDIA_IS_PREPARED
'//
'// MessageText:
'//
'// The requested operation is not valid when media has been "prepared" but not released.
'//
%E_IMAPI_DF2RAW_MEDIA_IS_PREPARED = &HC0AA0603&

'//
'// MessageId: E_IMAPI_DF2RAW_CLIENT_NAME_IS_NOT_VALID
'//
'// MessageText:
'//
'// The client name is not valid.
'//
%E_IMAPI_DF2RAW_CLIENT_NAME_IS_NOT_VALID = &HC0AA0604&

'//
'// MessageId: E_IMAPI_DF2RAW_MEDIA_IS_NOT_BLANK
'//
'// MessageText:
'//
'// Only blank CD-R/RW media is supported.
'//
%E_IMAPI_DF2RAW_MEDIA_IS_NOT_BLANK = &HC0AA0606&

'//
'// MessageId: E_IMAPI_DF2RAW_MEDIA_IS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Only blank CD-R/RW media is supported.
'//
%E_IMAPI_DF2RAW_MEDIA_IS_NOT_SUPPORTED = &HC0AA0607&

'//
'// MessageId: E_IMAPI_DF2RAW_NOT_ENOUGH_SPACE
'//
'// MessageText:
'//
'// There is not enough space on the media to add the provided session.
'//
%E_IMAPI_DF2RAW_NOT_ENOUGH_SPACE  = &HC0AA0609&

'//
'// MessageId: E_IMAPI_DF2RAW_NO_RECORDER_SPECIFIED
'//
'// MessageText:
'//
'// You cannot prepare the media until you choose a recorder to use.
'//
%E_IMAPI_DF2RAW_NO_RECORDER_SPECIFIED = &HC0AA060A&

'//
'// MessageId: E_IMAPI_DF2RAW_STREAM_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The provided audio stream is not valid.
'//
%E_IMAPI_DF2RAW_STREAM_NOT_SUPPORTED = &HC0AA060D&

'//
'// MessageId: E_IMAPI_DF2RAW_DATA_BLOCK_TYPE_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The requested data block type is not supported by the current device.
'//
%E_IMAPI_DF2RAW_DATA_BLOCK_TYPE_NOT_SUPPORTED = &HC0AA060E&

'//
'// MessageId: E_IMAPI_DF2RAW_STREAM_LEADIN_TOO_SHORT
'//
'// MessageText:
'//
'// The stream does not contain a sufficient number of sectors in the leadin for the current media.
'//
%E_IMAPI_DF2RAW_STREAM_LEADIN_TOO_SHORT = &HC0AA060F&

'//
'// MessageId: E_IMAPI_DF2RAW_RECORDER_NOT_SUPPORTED
'//
'// MessageText:
'//
'// This device does not support the operations required by this disc format.
'//
%E_IMAPI_DF2RAW_RECORDER_NOT_SUPPORTED = &HC0AA0610&


'//
'// Error Messages for IDiscFormat2Erase
'// Range: 0x80AA0900 - 0x80AA09FF
'//

'//
'// MessageId: E_IMAPI_ERASE_RECORDER_IN_USE
'//
'// MessageText:
'//
'// The format is currently using the disc recorder for an erase operation.
'// Please wait for the erase to complete before attempting to set or clear the
'// current disc recorder.
'//
%E_IMAPI_ERASE_RECORDER_IN_USE    = &H80AA0900&

'//
'// MessageId: E_IMAPI_ERASE_ONLY_ONE_RECORDER_SUPPORTED
'//
'// MessageText:
'//
'// The erase format only supports one recorder.  You must clear the current
'// recorder before setting a new one.
'//
%E_IMAPI_ERASE_ONLY_ONE_RECORDER_SUPPORTED = &H80AA0901&

'//
'// MessageId: E_IMAPI_ERASE_DISC_INFORMATION_TOO_SMALL
'//
'// MessageText:
'//
'// The drive did not report sufficient data for a READ DISC INFORMATION command.
'// The drive may not be supported, or the media may not be correct.
'//
%E_IMAPI_ERASE_DISC_INFORMATION_TOO_SMALL = &H80AA0902&

'//
'// MessageId: E_IMAPI_ERASE_MODE_PAGE_2A_TOO_SMALL
'//
'// MessageText:
'//
'// The drive did not report sufficient data for a MODE SENSE (page 0x2A) command.
'// The drive may not be supported, or the media may not be correct.
'//
%E_IMAPI_ERASE_MODE_PAGE_2A_TOO_SMALL = &H80AA0903&

'//
'// MessageId: E_IMAPI_ERASE_MEDIA_IS_NOT_ERASABLE
'//
'// MessageText:
'//
'// The drive reported that the media is not erasable.
'//
%E_IMAPI_ERASE_MEDIA_IS_NOT_ERASABLE = &H80AA0904&

'//
'// MessageId: E_IMAPI_ERASE_DRIVE_FAILED_ERASE_COMMAND
'//
'// MessageText:
'//
'// The drive failed the erase command.
'//
%E_IMAPI_ERASE_DRIVE_FAILED_ERASE_COMMAND = &H80AA0905&

'//
'// MessageId: E_IMAPI_ERASE_TOOK_LONGER_THAN_ONE_HOUR
'//
'// MessageText:
'//
'// The drive did not complete the erase in one hour.  The drive may require a power cycle, media removal, or other manual intervention to resume proper operation.
'//
%E_IMAPI_ERASE_TOOK_LONGER_THAN_ONE_HOUR = &H80AA0906&

'//
'// MessageId: E_IMAPI_ERASE_UNEXPECTED_DRIVE_RESPONSE_DURING_ERASE
'//
'// MessageText:
'//
'// The drive returned an unexpected error during the erase.  The the media may be
'// unusable, the erase may be complete, or the drive may still be in the process
'// of erasing the disc.
'//
%E_IMAPI_ERASE_UNEXPECTED_DRIVE_RESPONSE_DURING_ERASE = &H80AA0907&

'//
'// MessageId: E_IMAPI_ERASE_DRIVE_FAILED_SPINUP_COMMAND
'//
'// MessageText:
'//
'// The drive returned an error for a START UNIT (spinup) command.  Manual intervention may be required.
'//
%E_IMAPI_ERASE_DRIVE_FAILED_SPINUP_COMMAND = &H80AA0908&

'//
'// MessageId: E_IMAPI_ERASE_MEDIA_IS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The current media type is unsupported.
'//
%E_IMAPI_ERASE_MEDIA_IS_NOT_SUPPORTED = &HC0AA0909&

'//
'// MessageId: E_IMAPI_ERASE_RECORDER_NOT_SUPPORTED
'//
'// MessageText:
'//
'// This device does not support the operations required by this disc format.
'//
%E_IMAPI_ERASE_RECORDER_NOT_SUPPORTED = &HC0AA090A&

'//
'// MessageId: E_IMAPI_ERASE_CLIENT_NAME_IS_NOT_VALID
'//
'// MessageText:
'//
'// The client name is not valid.
'//
%E_IMAPI_ERASE_CLIENT_NAME_IS_NOT_VALID = &HC0AA090B&

'//
'// Error Messages for IRawCDImageCreator
'// Range: 0x80AA0A00 - 0x80AA0AFF
'//

'//
'// MessageId: E_IMAPI_RAW_IMAGE_IS_READ_ONLY
'//
'// MessageText:
'//
'// The image has become read-only from a call to CreateResultImage().
'// The object can no longer be modified.
'//
%E_IMAPI_RAW_IMAGE_IS_READ_ONLY   = &H80AA0A00&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TOO_MANY_TRACKS
'//
'// MessageText:
'//
'// No more tracks may be added, as CD media is restricted to track numbers
'// between 1 and 99.
'//
%E_IMAPI_RAW_IMAGE_TOO_MANY_TRACKS = &H80AA0A01&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_SECTOR_TYPE_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The requested sector type is not supported.
'//
%E_IMAPI_RAW_IMAGE_SECTOR_TYPE_NOT_SUPPORTED = &H80AA0A02&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_NO_TRACKS
'//
'// MessageText:
'//
'// Tracks must be added to the image before using this function.
'//
%E_IMAPI_RAW_IMAGE_NO_TRACKS      = &H80AA0A03&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TRACKS_ALREADY_ADDED
'//
'// MessageText:
'//
'// Tracks may not be added to the image prior to the use of this function.
'//
%E_IMAPI_RAW_IMAGE_TRACKS_ALREADY_ADDED = &H80AA0A04&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_INSUFFICIENT_SPACE
'//
'// MessageText:
'//
'// Adding the track would result in exceeding the limit for the start of the leadout.
'//
%E_IMAPI_RAW_IMAGE_INSUFFICIENT_SPACE = &H80AA0A05&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TOO_MANY_TRACK_INDEXES
'//
'// MessageText:
'//
'// Adding the track index would result in exceeding the 99 index limit.
'//
%E_IMAPI_RAW_IMAGE_TOO_MANY_TRACK_INDEXES = &H80AA0A06&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TRACK_INDEX_NOT_FOUND
'//
'// MessageText:
'//
'// The specified LBA offset is not in the list of track indexes.
'//
%E_IMAPI_RAW_IMAGE_TRACK_INDEX_NOT_FOUND = &H80AA0A07&

'//
'// MessageId: S_IMAPI_RAW_IMAGE_TRACK_INDEX_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The specified LBA offset is already in the list of track indexes.
'//
%S_IMAPI_RAW_IMAGE_TRACK_INDEX_ALREADY_EXISTS = &H00AA0A08&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TRACK_INDEX_OFFSET_ZERO_CANNOT_BE_CLEARED
'//
'// MessageText:
'//
'// Index 1 (LBA offset zero) may not be cleared.
'//
%E_IMAPI_RAW_IMAGE_TRACK_INDEX_OFFSET_ZERO_CANNOT_BE_CLEARED = &H80AA0A09&

'//
'// MessageId: E_IMAPI_RAW_IMAGE_TRACK_INDEX_TOO_CLOSE_TO_OTHER_INDEX
'//
'// MessageText:
'//
'// Each index must have a minimum size of ten sectors.
'//
%E_IMAPI_RAW_IMAGE_TRACK_INDEX_TOO_CLOSE_TO_OTHER_INDEX = &H80AA0A0A&
