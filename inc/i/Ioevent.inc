' ########################################################################################
' Microsoft Windows
' File: Ioevent.inc
' Contents: GUIDS and event structures for io system initiated events
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IOEVENT_INC = 1

'//
'//  Label change event.  This event is signalled upon successful completion
'//  of a label change.  There is no additional data.
'//

$GUID_IO_VOLUME_CHANGE = GUID$("{7373654A-812A-11D0-BEC7-08002BE2092F}")

'//
'//  Volume dismount event.  This event is signalled when an attempt is made to
'//  dismount a volume.  There is no additional data.  Note that this will not
'//  necessarily be preceded by a GUID_IO_VOLUME_LOCK notification.
'//

$GUID_IO_VOLUME_DISMOUNT = GUID$("{D16A55E8-1059-11D2-8FFD-00A0C9A06D32}")

'//
'//  Volume dismount failed event.  This event is signalled when a volume dismount fails.
'//  There is no additional data.
'//

$GUID_IO_VOLUME_DISMOUNT_FAILED = GUID$("{E3C5B178-105D-11D2-8FFD-00A0C9A06D32}")

'//
'//  Volume mount event.  This event is signalled when a volume mount occurs.
'//  There is no additional data.
'//

$GUID_IO_VOLUME_MOUNT = GUID$("{B5804878-1A96-11D2-8FFD-00A0C9A06D32}")

' // Size = 16 bytes
TYPE DEVICE_EVENT_MOUNT DWORD
   Version              AS DWORD   ' ULONG
   Flags                AS DWORD   ' ULONG
   FileSystemNameLength AS DWORD   ' ULONG
   FileSystemNameOffset AS DWORD   ' ULONG
END TYPE

'//
'//  Volume lock event.  This event is signalled when an attempt is made to
'//  lock a volume.  There is no additional data.
'//

$GUID_IO_VOLUME_LOCK = GUID$("{50708874-C9AF-11D1-8FEF-00A0C9A06D32}")

'//
'//  Volume lock failed event.  This event is signalled when an attempt is made to
'//  lock a volume, but it fails.  There is no additional data.
'//

$GUID_IO_VOLUME_LOCK_FAILED = GUID$("{AE2EED10-0BA8-11D2-8FFB-00A0C9A06D32}")


'//
'//  Volume unlock event.  This event is signalled when an attempt is made to
'//  unlock a volume.  There is no additional data.
'//

$GUID_IO_VOLUME_UNLOCK = GUID$("{9A8C3D68-D0CB-11D1-8FEF-00A0C9A06D32}")


'//
'//  Volume name change.  This event is signalled when the list of persistent
'//  names (like drive letters) for a volume changes.  There is no additional
'//  data.
'//

$GUID_IO_VOLUME_NAME_CHANGE = GUID$("{2DE97F83-4C06-11D2-A532-00609713055A}")


'//
'//      Volume needs chkdsk event. Sent when a file system detects corruption.
'//

$GUID_IO_VOLUME_NEED_CHKDSK = GUID$("{799A0960-0A0B-4E03-AD88-2FA7C6CE748A}")


'//
'//  WORK near full event. Send when a wolume with write-once-read-many characteristics
'//  (e.g. CD-R) is becoming full (on these media modifying existing file data
'//  consumes space) so that the user can be notified.
'//

$GUID_IO_VOLUME_WORM_NEAR_FULL = GUID$("{F3BFFF82-F3DE-48D2-AF95-457F80B763F2}")


'//
'//  Media wearing out. Sent when a file sytem determines that the error rate
'//  on a volume is too high, or sparing (defect replacement) space is almost
'//  exhausted.
'//

$GUID_IO_VOLUME_WEARING_OUT = GUID$("{873113CA-1486-4508-82AC-C3B2E5297AAA}")


'//
'//  Volume force closed event. Sent when a volume has been finalised and made
'//  read-only by the filesystem due to (e,g.) WORM type volume full, or sparing
'//  (defect replacement) space has been exhausted.
'//

$GUID_IO_VOLUME_FORCE_CLOSED = GUID$("{411AD84F-433E-4DC2-A5AE-4A2D1A2DE654}")


'//
'//  Notify make compatible function available. Sent after the user removes a disc
'//  which may not be readable in all drives in it's current state (e.g. CD-R with
'//  open session).
'//

$GUID_IO_VOLUME_INFO_MAKE_COMPAT = GUID$("{3AB9A0D2-EF80-45CF-8CDC-CBE02A212906}")


'//
'//  Notify that the drive is preparing the disc for eject (e.g. stopping a background format).
'//

$GUID_IO_VOLUME_PREPARING_EJECT = GUID$("{C79EB16E-0DAC-4E7A-A86C-B25CEEAA88F6}")

'//
'//  Notify that a background format has been initiated on the disc.
'//

$GUID_IO_VOLUME_BACKGROUND_FORMAT = GUID$("{A2E5FC86-D5CD-4038-B2E3-4445065C2377}")

'//
'//  Volume physical configuration change.  This event is signalled when the
'//  physical makeup or current physical state of the volume changes.
'//

$GUID_IO_VOLUME_PHYSICAL_CONFIGURATION_CHANGE = GUID$("{2DE97F84-4C06-11D2-A532-00609713055A}")

'//
'//  Volume unique ID change.  This event is signalled when the
'//  unique ID of the volume changes.
'//

$GUID_IO_VOLUME_UNIQUE_ID_CHANGE = GUID$("{AF39DA42-6622-41F5-970B139D092FA3D9}")

'//
'//  Volume BitLocker Drive Encryption status change.
'//  This event is signalled when BDE is enabled / disabled, or when encryption
'//  begins, ends, pauses or resumes.
'//

$GUID_IO_VOLUME_FVE_STATUS_CHANGE = GUID$("{062998B2-EE1F-4B6A-B857-E76CBBE9A6DA}")


'//
'//  Volume device interface.  This is a device interface GUID that appears
'//  when the device object associated with a volume is created and disappears
'//  when the device object associated with the volume is destroyed.
'//

$GUID_IO_VOLUME_DEVICE_INTERFACE = GUID$("{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B}")

'//
'// The size of the filesystem on the volume has changed.
'//

$GUID_IO_VOLUME_CHANGE_SIZE = GUID$("{3A1625BE-AD03-49F1-8EF8-6BBAC182D1FD}")

'//
'//  Sent when the removable media is changed (added, removed) from a device
'//  (such as a CDROM, tape, changer, etc).
'//
'//  The additional data is a DWORD representing the data event.
'//

$GUID_IO_MEDIA_ARRIVAL = GUID$("{D07433C0-A98E-11D2-917A-00A0C9068FF3}")
$GUID_IO_MEDIA_REMOVAL = GUID$("{D07433C1-A98E-11D2-917A-00A0C9068FF3}")

'//
'// Sent when the CDROM device locked/unlocked for exclusive access
'//

$GUID_IO_CDROM_EXCLUSIVE_LOCK = GUID$("{BC56C139-7A10-47EE-A294-4C6A38F0149A}")
$GUID_IO_CDROM_EXCLUSIVE_UNLOCK = GUID$("{A3B6D27D-5E35-4885-81E5-EE18C00ED779}")

'//
'// Sent when the media is returning that it is not ready right now, but will
'// be ready soon. This can be because the drive has spun down to save power
'// or because new media has been inserted but is not ready for access yet.
'//

$GUID_IO_DEVICE_BECOMING_READY = GUID$("{D07433F0-A98E-11D2-917A-00A0C9068FF3}")

' // Size = 12 bytes
TYPE DEVICE_EVENT_BECOMING_READY DWORD
   Version               AS DWORD   ' ULONG
   Reason                AS DWORD   ' ULONG
   Estimated100msToReady AS DWORD   ' ULONG
END TYPE

'//
'// Sent when the user presses the eject button on the front of the drive,
'// or when other buttons on the front are pressed via GESN command polling
'// (GESN support to be added)
'//

$GUID_IO_DEVICE_EXTERNAL_REQUEST = GUID$("{D07433D0-A98E-11D2-917A-00A0C9068FF3}")
$GUID_IO_MEDIA_EJECT_REQUEST = GUID$("{D07433D1-A98E-11D2-917A-00A0C9068FF3}")

' // Size = 24 bytes
TYPE DEVICE_EVENT_EXTERNAL_REQUEST DWORD
   Version      AS DWORD   ' ULONG
   DeviceClass  AS DWORD   ' ULONG // 0 == MMC Storage Devices
   ButtonStatus AS WORD    ' USHORT // 1 == down, 2 == up
   Request      AS WORD    ' USHORT
   SystemTime   AS QUAD    ' LARGE_INTEGER // for time-related info
END TYPE

'//
'// Sent when a tape drive requires cleaning
'//

$GUID_IO_DRIVE_REQUIRES_CLEANING = GUID$("{7207877C-90ED-44E5-A000-81428D4C79BB}")

'//
'// Sent when a tape is erased
'//

$GUID_IO_TAPE_ERASE = GUID$("{852D11EB-4BB8-4507-9D9B-417CC2B1B438}")

' // Size = 4 bytes
TYPE DEVICE_EVENT_GENERIC_DATA DWORD
   EventNumber AS DWORD   ' ULONG
END TYPE


'//
'//  Represents any asynchronous notification coming from a device driver whose
'//  notification protocol is RBC
'//  Additional data is provided

$GUID_DEVICE_EVENT_RBC = GUID$("{D0744792-A98E-11D2-917A-00A0C9068FF3}")

' // Size = 12 bytes
TYPE DEVICE_EVENT_RBC_DATA BYTE
   EventNumber    AS DWORD   ' ULONG
   SenseQualifier AS BYTE    ' UCHAR
   SenseCode      AS BYTE    ' UCHAR
   SenseKey       AS BYTE    ' UCHAR
   Reserved       AS BYTE    ' UCHAR
   Information    AS DWORD   ' ULONG
END TYPE

'//
'//  A clone of this disk has just arrived in the system.
'//

$GUID_IO_DISK_CLONE_ARRIVAL = GUID$("{6A61885B-7C39-43DD-9B56-B8AC22A549AA}")

TYPE GUID_IO_DISK_CLONE_ARRIVAL_INFORMATION
   DiskNumber AS DWORD   ' ULONG // The disk number of the new disk arriving in the system.
END TYPE

'//
'// The disk layout has changed
'//

$GUID_IO_DISK_LAYOUT_CHANGE = GUID$("{11DFF54C-8469-41F9-B3DE-EF836487C54A}")
