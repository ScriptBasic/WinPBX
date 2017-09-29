' ########################################################################################
' Microsoft Windows
' File: vsserror.inc
' Contents: This file contains the message definitions for common VSS errors.
' They are a subset of message definitions of vssadmin.exe.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VSSERROR_INC = 1

'//
'//  VSS error codes.
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
'// MessageId: VSS_E_BAD_STATE
'//
'// MessageText:
'//
'// A function call was made when the object was in an incorrect state
'// for that function
'//
%VSS_E_BAD_STATE                  = &H80042301&

'//
'// MessageId: VSS_E_PROVIDER_ALREADY_REGISTERED
'//
'// MessageText:
'//
'// The provider has already been registered.
'//
%VSS_E_PROVIDER_ALREADY_REGISTERED = &H80042303&

'//
'// MessageId: VSS_E_PROVIDER_NOT_REGISTERED
'//
'// MessageText:
'//
'// The volume shadow copy provider is not registered in the system.
'//
%VSS_E_PROVIDER_NOT_REGISTERED    = &H80042304&

'//
'// MessageId: VSS_E_PROVIDER_VETO
'//
'// MessageText:
'//
'// The shadow copy provider had an error. Please see the system and application event logs for more information.
'//
%VSS_E_PROVIDER_VETO              = &H80042306&

'//
'// MessageId: VSS_E_PROVIDER_IN_USE
'//
'// MessageText:
'//
'// The shadow copy provider is currently in use and cannot be unregistered.
'//
%VSS_E_PROVIDER_IN_USE            = &H80042307&

'//
'// MessageId: VSS_E_OBJECT_NOT_FOUND
'//
'// MessageText:
'//
'// The specified object was not found.
'//
%VSS_E_OBJECT_NOT_FOUND           = &H80042308&

'//
'// MessageId: VSS_S_ASYNC_PENDING
'//
'// MessageText:
'//
'// The asynchronous operation is pending.
'//
%VSS_S_ASYNC_PENDING              = &H00042309&

'//
'// MessageId: VSS_S_ASYNC_FINISHED
'//
'// MessageText:
'//
'// The asynchronous operation has completed.
'//
%VSS_S_ASYNC_FINISHED             = &H0004230A&

'//
'// MessageId: VSS_S_ASYNC_CANCELLED
'//
'// MessageText:
'//
'// The asynchronous operation has been cancelled.
'//
%VSS_S_ASYNC_CANCELLED            = &H0004230B&

'//
'// MessageId: VSS_E_VOLUME_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Shadow copying the specified volume is not supported.
'//
%VSS_E_VOLUME_NOT_SUPPORTED       = &H8004230C&

'//
'// MessageId: VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER
'//
'// MessageText:
'//
'// The given shadow copy provider does not support shadow copying the specified volume.
'//
%VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER = &H8004230E&

'//
'// MessageId: VSS_E_OBJECT_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The object already exists.
'//
%VSS_E_OBJECT_ALREADY_EXISTS      = &H8004230D&

'//
'// MessageId: VSS_E_UNEXPECTED_PROVIDER_ERROR
'//
'// MessageText:
'//
'// The shadow copy provider had an unexpected error while trying to process the specified operation.
'//
%VSS_E_UNEXPECTED_PROVIDER_ERROR  = &H8004230F&

'//
'// MessageId: VSS_E_CORRUPT_XML_DOCUMENT
'//
'// MessageText:
'//
'// The given XML document is invalid.  It is either incorrectly-formed XML or it does not match the
'// schema.  This error code is deprecated.
'//
%VSS_E_CORRUPT_XML_DOCUMENT       = &H80042310&

'//
'// MessageId: VSS_E_INVALID_XML_DOCUMENT
'//
'// MessageText:
'//
'// The given XML document is invalid.  It is either incorrectly-formed XML or it does not match the
'// schema.
'//
%VSS_E_INVALID_XML_DOCUMENT       = &H80042311&

'//
'// MessageId: VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED
'//
'// MessageText:
'//
'// The maximum number of volumes for this operation has been rached.
'//
%VSS_E_MAXIMUM_NUMBER_OF_VOLUMES_REACHED = &H80042312&

'//
'// MessageId: VSS_E_FLUSH_WRITES_TIMEOUT
'//
'// MessageText:
'//
'// The shadow copy provider timed out while flushing data to the volume being shadow copied. This is probably due to excessive activity on the volume. Try again later when the volume is not being used so heavily.
'//
%VSS_E_FLUSH_WRITES_TIMEOUT       = &H80042313&

'//
'// MessageId: VSS_E_HOLD_WRITES_TIMEOUT
'//
'// MessageText:
'//
'// The shadow copy provider timed out while holding writes to the volume being shadow copied. This is probably due to excessive activity on the volume by an application or a system service. Try again later when activity on the volume is reduced.
'//
%VSS_E_HOLD_WRITES_TIMEOUT        = &H80042314&

'//
'// MessageId: VSS_E_UNEXPECTED_WRITER_ERROR
'//
'// MessageText:
'//
'// VSS encountered problems while sending events to writers.
'//
%VSS_E_UNEXPECTED_WRITER_ERROR    = &H80042315&

'//
'// MessageId: VSS_E_SNAPSHOT_SET_IN_PROGRESS
'//
'// MessageText:
'//
'// Another shadow copy creation is already in progress. Please wait a few moments and try again.
'//
%VSS_E_SNAPSHOT_SET_IN_PROGRESS   = &H80042316&

'//
'// MessageId: VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED
'//
'// MessageText:
'//
'// The specified volume has already reached its maximum number of shadow copies.
'//
%VSS_E_MAXIMUM_NUMBER_OF_SNAPSHOTS_REACHED = &H80042317&

'//
'// MessageId: VSS_E_WRITER_INFRASTRUCTURE
'//
'// MessageText:
'//
'// An error was detected in the Volume Shadow Copy Service (VSS). The problem occurred while trying to contact VSS writers.
'// Please verify that the Event System service and the VSS service are running and check for associated errors in the event logs.
'//
%VSS_E_WRITER_INFRASTRUCTURE      = &H80042318&

'//
'// MessageId: VSS_E_WRITER_NOT_RESPONDING
'//
'// MessageText:
'//
'// A writer did not respond to a GatherWriterStatus call.  The writer may either have terminated
'// or it may be stuck.  Check the system and application event logs for more information.
'//
%VSS_E_WRITER_NOT_RESPONDING      = &H80042319&

'//
'// MessageId: VSS_E_WRITER_ALREADY_SUBSCRIBED
'//
'// MessageText:
'//
'// The writer has already sucessfully called the Subscribe function.  It cannot call
'// subscribe multiple times.
'//
%VSS_E_WRITER_ALREADY_SUBSCRIBED  = &H8004231A&

'//
'// MessageId: VSS_E_UNSUPPORTED_CONTEXT
'//
'// MessageText:
'//
'// The shadow copy provider does not support the specified shadow copy type.
'//
%VSS_E_UNSUPPORTED_CONTEXT        = &H8004231B&

'//
'// MessageId: VSS_E_VOLUME_IN_USE
'//
'// MessageText:
'//
'// The specified shadow copy storage association is in use and so can't be deleted.
'//
%VSS_E_VOLUME_IN_USE              = &H8004231D&

'//
'// MessageId: VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED
'//
'// MessageText:
'//
'// Maximum number of shadow copy storage associations already reached.
'//
%VSS_E_MAXIMUM_DIFFAREA_ASSOCIATIONS_REACHED = &H8004231E&

'//
'// MessageId: VSS_E_INSUFFICIENT_STORAGE
'//
'// MessageText:
'//
'// Insufficient storage available to create either the shadow copy storage file or other shadow copy data.
'//
%VSS_E_INSUFFICIENT_STORAGE       = &H8004231F&

'//
'// MessageId: VSS_E_NO_SNAPSHOTS_IMPORTED
'//
'// MessageText:
'//
'// No shadow copies were successfully imported.
'//
%VSS_E_NO_SNAPSHOTS_IMPORTED      = &H80042320&

'//
'// MessageId: VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED
'//
'// MessageText:
'//
'// Some shadow copies were not succesfully imported.
'//
%VSS_S_SOME_SNAPSHOTS_NOT_IMPORTED = &H00042321&

'//
'// MessageId: VSS_E_SOME_SNAPSHOTS_NOT_IMPORTED
'//
'// MessageText:
'//
'// Some shadow copies were not succesfully imported.
'//
%VSS_E_SOME_SNAPSHOTS_NOT_IMPORTED = &H80042321&

'//
'// MessageId: VSS_E_MAXIMUM_NUMBER_OF_REMOTE_MACHINES_REACHED
'//
'// MessageText:
'//
'// The maximum number of remote machines for this operation has been reached.
'//
%VSS_E_MAXIMUM_NUMBER_OF_REMOTE_MACHINES_REACHED = &H80042322&

'//
'// MessageId: VSS_E_REMOTE_SERVER_UNAVAILABLE
'//
'// MessageText:
'//
'// The remote server is unavailable.
'//
%VSS_E_REMOTE_SERVER_UNAVAILABLE  = &H80042323&

'//
'// MessageId: VSS_E_REMOTE_SERVER_UNSUPPORTED
'//
'// MessageText:
'//
'// The remote server is running a version of the Volume Shadow Copy Service that does not
'// support remote shadow-copy creation.
'//
%VSS_E_REMOTE_SERVER_UNSUPPORTED  = &H80042324&

'//
'// MessageId: VSS_E_REVERT_IN_PROGRESS
'//
'// MessageText:
'//
'// A revert is currently in progress for the specified volume.  Another revert
'// cannot be initiated until the current revert completes.
'//
%VSS_E_REVERT_IN_PROGRESS         = &H80042325&

'//
'// MessageId: VSS_E_REVERT_VOLUME_LOST
'//
'// MessageText:
'//
'// The volume being reverted was lost during revert.
'//
%VSS_E_REVERT_VOLUME_LOST         = &H80042326&

'//
'// MessageId: VSS_E_REBOOT_REQUIRED
'//
'// MessageText:
'//
'// A reboot is required after completing this operation.
'//
%VSS_E_REBOOT_REQUIRED            = &H80042327&

'//
'// MessageId: VSS_E_TRANSACTION_FREEZE_TIMEOUT
'//
'// MessageText:
'//
'// A timeout occured while freezing a transaction manager.
'//
%VSS_E_TRANSACTION_FREEZE_TIMEOUT = &H80042328&

'//
'// MessageId: VSS_E_TRANSACTION_THAW_TIMEOUT
'//
'// MessageText:
'//
'// Too much time elapsed between freezing a transaction manager and thawing
'// the transaction manager.
'//
%VSS_E_TRANSACTION_THAW_TIMEOUT   = &H80042329&

'//
'// MessageId: VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT
'//
'// MessageText:
'//
'// the shadow-copy set only contains only a subset of the
'// volumes needed to correctly backup the selected components
'// of the writer.
'//
%VSS_E_WRITERERROR_INCONSISTENTSNAPSHOT = &H800423F0&

'//
'// MessageId: VSS_E_WRITERERROR_OUTOFRESOURCES
'//
'// MessageText:
'//
'// A resource allocation failed while processing this operation.
'//
%VSS_E_WRITERERROR_OUTOFRESOURCES = &H800423F1&

'//
'// MessageId: VSS_E_WRITERERROR_TIMEOUT
'//
'// MessageText:
'//
'// The writer's timeout expired between the Freeze and Thaw events.
'//
%VSS_E_WRITERERROR_TIMEOUT        = &H800423F2&

'//
'// MessageId: VSS_E_WRITERERROR_RETRYABLE
'//
'// MessageText:
'//
'// The writer experienced a transient error.  If the backup process is retried,
'// the error may not reoccur.
'//
%VSS_E_WRITERERROR_RETRYABLE      = &H800423F3&

'//
'// MessageId: VSS_E_WRITERERROR_NONRETRYABLE
'//
'// MessageText:
'//
'// The writer experienced a non-transient error.  If the backup process is retried,
'// the error is likely to reoccur.
'//
%VSS_E_WRITERERROR_NONRETRYABLE   = &H800423F4&

'//
'// MessageId: VSS_E_WRITERERROR_RECOVERY_FAILED
'//
'// MessageText:
'//
'// The writer experienced an error while trying to recover the shadow-copy volume.
'//
%VSS_E_WRITERERROR_RECOVERY_FAILED = &H800423F5&

'//
'// MessageId: VSS_E_BREAK_REVERT_ID_FAILED
'//
'// MessageText:
'//
'// The shadow copy set break operation failed because the disk/partition identities could not be reverted. The target identity already exists on the machine or cluster and must be masked before this operation can succeed.
'//
%VSS_E_BREAK_REVERT_ID_FAILED     = &H800423F6&

'//
'// MessageId: VSS_E_LEGACY_PROVIDER
'//
'// MessageText:
'//
'// This version of the hardware provider does not support this operation.
'//
%VSS_E_LEGACY_PROVIDER            = &H800423F7&

'//
'// MessageId: VSS_E_BREAK_FAIL_FROM_PROVIDER
'//
'// MessageText:
'//
'// At least one of the providers in this Shadow Copy Set failed the break operation for a snapshot.
'//
%VSS_E_BREAK_FAIL_FROM_PROVIDER   = &H800423F8&

'//
'// ASR error codes
'//
'//
'// MessageId: VSS_E_ASRERROR_DISK_ASSIGNMENT_FAILED
'//
'// MessageText:
'//
'// There are too few disks on this computer or one or more of the disks is too small. Add or change disks so they match the disks in the backup, and try the restore again.
'//
%VSS_E_ASRERROR_DISK_ASSIGNMENT_FAILED = &H80042401&

'//
'// MessageId: VSS_E_ASRERROR_DISK_RECREATION_FAILED
'//
'// MessageText:
'//
'// Windows cannot create a disk on this computer needed to restore from the backup. Make sure the disks are properly connected, or add or change disks, and try the restore again.
'//
%VSS_E_ASRERROR_DISK_RECREATION_FAILED = &H80042402&

'//
'// MessageId: VSS_E_ASRERROR_NO_ARCPATH
'//
'// MessageText:
'//
'// The computer needs to be restarted to finish preparing a hard disk for restore. To continue, restart your computer and run the restore again.
'//
%VSS_E_ASRERROR_NO_ARCPATH        = &H80042403&

'//
'// MessageId: VSS_E_ASRERROR_MISSING_DYNDISK
'//
'// MessageText:
'//
'// The backup failed due to a missing disk for a dynamic volume. Please ensure the disk is online and retry the backup.
'//
%VSS_E_ASRERROR_MISSING_DYNDISK   = &H80042404&

'//
'// MessageId: VSS_E_ASRERROR_SHARED_CRIDISK
'//
'// MessageText:
'//
'// Automated System Recovery failed the shadow copy, because a selected critical volume is located on a cluster shared disk. This is an unsupported configuration.
'//
%VSS_E_ASRERROR_SHARED_CRIDISK    = &H80042405&

'//
'// MessageId: VSS_E_ASRERROR_DATADISK_RDISK0
'//
'// MessageText:
'//
'// A data disk is currently set as active in BIOS. Set some other disk as active or use the DiskPart utility to clean the data disk, and then retry the restore operation.
'//
%VSS_E_ASRERROR_DATADISK_RDISK0   = &H80042406&

'//
'// MessageId: VSS_E_ASRERROR_RDISK0_TOOSMALL
'//
'// MessageText:
'//
'// The disk that is set as active in BIOS is too small to recover the original system disk. Replace the disk with a larger one and retry the restore operation.
'//
%VSS_E_ASRERROR_RDISK0_TOOSMALL   = &H80042407&

'//
'// MessageId: VSS_E_ASRERROR_CRITICAL_DISKS_TOO_SMALL
'//
'// MessageText:
'//
'// There is not enough disk space on the system to perform the restore operation. Add another disk or replace one of the existing disks and retry the restore operation.
'//
%VSS_E_ASRERROR_CRITICAL_DISKS_TOO_SMALL = &H80042408&

'//
'// MessageId: VSS_E_WRITER_STATUS_NOT_AVAILABLE
'//
'// MessageText:
'//
'// Writer status is not available for one or more writers.  A writer may have reached the limit to the number of available backup-restore session states.
'//
%VSS_E_WRITER_STATUS_NOT_AVAILABLE = &H80042409&
