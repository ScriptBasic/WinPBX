' ########################################################################################
' Microsoft Windows
' File: WinIoCtl.inc
' Contents: This module defines the 32-Bit Windows Device I/O control codes.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WIONIOCTL_INC = 1

#INCLUDE ONCE "windows.inc"   ' For %WINVER and SID structure

'//
'// Device interface class GUIDs.
'//
'// need these GUIDs outside conditional includes so that user can
'//   #include <winioctl.h> in precompiled header
'//   #include <initguid.h> in a single source file
'//   #include <winioctl.h> in that source file a second time to instantiate the GUIDs
'//
'#ifdef DEFINE_GUID

'DEFINE_GUID(GUID_DEVINTERFACE_DISK,                   0x53f56307L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_CDROM,                  0x53f56308L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_PARTITION,              0x53f5630aL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_TAPE,                   0x53f5630bL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_WRITEONCEDISK,          0x53f5630cL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_VOLUME,                 0x53f5630dL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_MEDIUMCHANGER,          0x53f56310L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_FLOPPY,                 0x53f56311L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_CDCHANGER,              0x53f56312L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);
'DEFINE_GUID(GUID_DEVINTERFACE_STORAGEPORT,            0x2accfe60L, 0xc130, 0x11d2, 0xb0, 0x82, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

'#define  WDI_STORAGE_PREDICT_FAILURE_DPS_GUID        {0xe9f2d03aL, 0x747c, 0x41c2, {0xbb, 0x9a, 0x02, 0xc6, 0x2b, 0x6d, 0x5f, 0xcb}};

'//
'// The interface used to discover volumes that are
'// not reported by Win32 APIs. This includes those
'// with an unrecognized partition type/id and ones
'// with the hidden attribute.
'//
'DEFINE_GUID(GUID_DEVINTERFACE_HIDDEN_VOLUME,          0x7f108a28L, 0x9833, 0x4b3b, 0xb7, 0x80, 0x2c, 0x6b, 0x5f, 0xa5, 0xc0, 0x62);

'DEFINE_GUID(GUID_DEVINTERFACE_COMPORT,                0x86e0d1e0L, 0x8089, 0x11d0, 0x9c, 0xe4, 0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73);
'DEFINE_GUID(GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR, 0x4D36E978L, 0xE325, 0x11CE, 0xBF, 0xC1, 0x08, 0x00, 0x2B, 0xE1, 0x03, 0x18);

'//
'// Obsolete device interface class GUID names.
'// (use of above GUID_DEVINTERFACE_* names is recommended).
'//
'#define DiskClassGuid               GUID_DEVINTERFACE_DISK
'#define CdRomClassGuid              GUID_DEVINTERFACE_CDROM
'#define PartitionClassGuid          GUID_DEVINTERFACE_PARTITION
'#define TapeClassGuid               GUID_DEVINTERFACE_TAPE
'#define WriteOnceDiskClassGuid      GUID_DEVINTERFACE_WRITEONCEDISK
'#define VolumeClassGuid             GUID_DEVINTERFACE_VOLUME
'#define MediumChangerClassGuid      GUID_DEVINTERFACE_MEDIUMCHANGER
'#define FloppyClassGuid             GUID_DEVINTERFACE_FLOPPY
'#define CdChangerClassGuid          GUID_DEVINTERFACE_CDCHANGER
'#define StoragePortClassGuid        GUID_DEVINTERFACE_STORAGEPORT
'#define GUID_CLASS_COMPORT          GUID_DEVINTERFACE_COMPORT
'#define GUID_SERENUM_BUS_ENUMERATOR GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR

'#endif // DEFINE_GUID

'#IF %DEF(%DEFINE_GUID)
' Note: It makes no sense to use this conditional equate with PowerBASIC because
' we aren't going to use the DEFINE_GUID macro, but GUID$.

$GUID_DEVINTERFACE_DISK                   = GUID$("{53F56307-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_CDROM                  = GUID$("{53F56308-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_PARTITION              = GUID$("{53F5630A-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_TAPE                   = GUID$("{53F5630B-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_WRITEONCEDISK          = GUID$("{53F5630C-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_VOLUME                 = GUID$("{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_MEDIUMCHANGER          = GUID$("{53F56310-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_FLOPPY                 = GUID$("{53F56311-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_CDCHANGER              = GUID$("{53F56312-B6BF-11D0-94F2-00A0C91EFB8B}")
$GUID_DEVINTERFACE_STORAGEPORT            = GUID$("{2ACCFE60-C130-11D2-B082-00A0C91EFB8B}")

$WDI_STORAGE_PREDICT_FAILURE_DPS_GUID     = GUID$("{E9F2D03A-747C-41C2-BB9A-02C62B6D5FCB}")

'//
'// The interface used to discover volumes that are
'// not reported by Win32 APIs. This includes those
'// with an unrecognized partition type/id and ones
'// with the hidden attribute.
'//
$GUID_DEVINTERFACE_HIDDEN_VOLUME          = GUID$("{7F108A28-9833-4B3B-B780-2C6B5FA5C062}")

$GUID_DEVINTERFACE_COMPORT                = GUID$("{86E0D1E0-8089-11D0-9CE4-08003E301F73}")
$GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR = GUID$("{4D36E978-E325-11CE-BFC1-08002BE10318}")

'
' Obsolete device interface class GUID names.
' (use of above GUID_DEVINTERFACE_* names is recommended).
'
$DiskClassGuid               = $GUID_DEVINTERFACE_DISK
$CdRomClassGuid              = $GUID_DEVINTERFACE_CDROM
$PartitionClassGuid          = $GUID_DEVINTERFACE_PARTITION
$TapeClassGuid               = $GUID_DEVINTERFACE_TAPE
$WriteOnceDiskClassGuid      = $GUID_DEVINTERFACE_WRITEONCEDISK
$VolumeClassGuid             = $GUID_DEVINTERFACE_VOLUME
$MediumChangerClassGuid      = $GUID_DEVINTERFACE_MEDIUMCHANGER
$FloppyClassGuid             = $GUID_DEVINTERFACE_FLOPPY
$CdChangerClassGuid          = $GUID_DEVINTERFACE_CDCHANGER
$StoragePortClassGuid        = $GUID_DEVINTERFACE_STORAGEPORT
$HiddenVolumeClassGuid       = $GUID_DEVINTERFACE_HIDDEN_VOLUME

$GUID_CLASS_COMPORT          = $GUID_DEVINTERFACE_COMPORT
$GUID_SERENUM_BUS_ENUMERATOR = $GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR

'#ENDIF  ' #IF %DEF(%DEFINE_GUID)

'#ifndef _DEVIOCTL_
'#define _DEVIOCTL_

#IF NOT %DEF(%DEVIOCTL)
    %DEVIOCTL = 1

'// begin_ntddk begin_wdm begin_nthal begin_ntifs
'//
'// Define the various device type values.  Note that values used by Microsoft
'// Corporation are in the range 0-32767, and 32768-65535 are reserved for use
'// by customers.
'//

'#define DEVICE_TYPE DWORD

%FILE_DEVICE_BEEP                = &H00000001???
%FILE_DEVICE_CD_ROM              = &H00000002???
%FILE_DEVICE_CD_ROM_FILE_SYSTEM  = &H00000003???
%FILE_DEVICE_CONTROLLER          = &H00000004???
%FILE_DEVICE_DATALINK            = &H00000005???
%FILE_DEVICE_DFS                 = &H00000006???
%FILE_DEVICE_DISK                = &H00000007???
%FILE_DEVICE_DISK_FILE_SYSTEM    = &H00000008???
%FILE_DEVICE_FILE_SYSTEM         = &H00000009???
%FILE_DEVICE_INPORT_PORT         = &H0000000a???
%FILE_DEVICE_KEYBOARD            = &H0000000b???
%FILE_DEVICE_MAILSLOT            = &H0000000c???
%FILE_DEVICE_MIDI_IN             = &H0000000d???
%FILE_DEVICE_MIDI_OUT            = &H0000000e???
%FILE_DEVICE_MOUSE               = &H0000000f???
%FILE_DEVICE_MULTI_UNC_PROVIDER  = &H00000010???
%FILE_DEVICE_NAMED_PIPE          = &H00000011???
%FILE_DEVICE_NETWORK             = &H00000012???
%FILE_DEVICE_NETWORK_BROWSER     = &H00000013???
%FILE_DEVICE_NETWORK_FILE_SYSTEM = &H00000014???
%FILE_DEVICE_NULL                = &H00000015???
%FILE_DEVICE_PARALLEL_PORT       = &H00000016???
%FILE_DEVICE_PHYSICAL_NETCARD    = &H00000017???
%FILE_DEVICE_PRINTER             = &H00000018???
%FILE_DEVICE_SCANNER             = &H00000019???
%FILE_DEVICE_SERIAL_MOUSE_PORT   = &H0000001a???
%FILE_DEVICE_SERIAL_PORT         = &H0000001b???
%FILE_DEVICE_SCREEN              = &H0000001c???
%FILE_DEVICE_SOUND               = &H0000001d???
%FILE_DEVICE_STREAMS             = &H0000001e???
%FILE_DEVICE_TAPE                = &H0000001f???
%FILE_DEVICE_TAPE_FILE_SYSTEM    = &H00000020???
%FILE_DEVICE_TRANSPORT           = &H00000021???
%FILE_DEVICE_UNKNOWN             = &H00000022???
%FILE_DEVICE_VIDEO               = &H00000023???
%FILE_DEVICE_VIRTUAL_DISK        = &H00000024???
%FILE_DEVICE_WAVE_IN             = &H00000025???
%FILE_DEVICE_WAVE_OUT            = &H00000026???
%FILE_DEVICE_8042_PORT           = &H00000027???
%FILE_DEVICE_NETWORK_REDIRECTOR  = &H00000028???
%FILE_DEVICE_BATTERY             = &H00000029???
%FILE_DEVICE_BUS_EXTENDER        = &H0000002a???
%FILE_DEVICE_MODEM               = &H0000002b???
%FILE_DEVICE_VDM                 = &H0000002c???
%FILE_DEVICE_MASS_STORAGE        = &H0000002d???
%FILE_DEVICE_SMB                 = &H0000002e???
%FILE_DEVICE_KS                  = &H0000002f???
%FILE_DEVICE_CHANGER             = &H00000030???
%FILE_DEVICE_SMARTCARD           = &H00000031???
%FILE_DEVICE_ACPI                = &H00000032???
%FILE_DEVICE_DVD                 = &H00000033???
%FILE_DEVICE_FULLSCREEN_VIDEO    = &H00000034???
%FILE_DEVICE_DFS_FILE_SYSTEM     = &H00000035???
%FILE_DEVICE_DFS_VOLUME          = &H00000036???
%FILE_DEVICE_SERENUM             = &H00000037???
%FILE_DEVICE_TERMSRV             = &H00000038???
%FILE_DEVICE_KSEC                = &H00000039???
%FILE_DEVICE_FIPS                = &H0000003A???
%FILE_DEVICE_INFINIBAND          = &H0000003B???
%FILE_DEVICE_VMBUS               = &H0000003E???
%FILE_DEVICE_CRYPT_PROVIDER      = &H0000003F???
%FILE_DEVICE_WPD                 = &H00000040???
%FILE_DEVICE_BLUETOOTH           = &H00000041???
%FILE_DEVICE_MT_COMPOSITE        = &H00000042???
%FILE_DEVICE_MT_TRANSPORT        = &H00000043???
%FILE_DEVICE_BIOMETRIC           = &H00000044???
%FILE_DEVICE_PMI                 = &H00000045???

'//
'// Macro definition for defining IOCTL and FSCTL function control codes.  Note
'// that function codes 0-2047 are reserved for Microsoft Corporation, and
'// 2048-4095 are reserved for customers.
'//

'#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
'    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
')

FUNCTION CTL_CODE (BYVAL nDeviceType AS DWORD, BYVAL nFunction AS DWORD, BYVAL nMethod AS DWORD, BYVAL nAccess AS DWORD) AS DWORD
   SHIFT LEFT nDeviceType, 16
   SHIFT LEFT nAccess, 14
   SHIFT LEFT nFunction, 2
   FUNCTION = nDeviceType OR nAccess OR nFunction OR nMethod
END FUNCTION

'//
'// Macro to extract device type out of the device io control code
'//
'#define DEVICE_TYPE_FROM_CTL_CODE(ctrlCode)     (((DWORD)(ctrlCode & 0xffff0000)) >> 16)

FUNCTION DEVICE_TYPE_FROM_CTL_CODE (BYVAL ctrlCode AS DWORD) AS DWORD
   LOCAL dwResult AS DWORD
   dwResult = ctrlCode AND &H0FFFF0000
   SHIFT RIGHT dwResult, 16
   FUNCTION = dwResult
END FUNCTION

'//
'// Macro to extract buffering method out of the device io control code
'//

FUNCTION METHOD_FROM_CTL_CODE (BYVAL ctrlCode AS DWORD) AS DWORD
   FUNCTION = ctrlCode AND 3
END FUNCTION

'//
'// Define the method codes for how buffers are passed for I/O and FS controls
'//

%METHOD_BUFFERED                = 0
%METHOD_IN_DIRECT               = 1
%METHOD_OUT_DIRECT              = 2
%METHOD_NEITHER                 = 3

'//
'// Define some easier to comprehend aliases:
'//   METHOD_DIRECT_TO_HARDWARE (writes, aka METHOD_IN_DIRECT)
'//   METHOD_DIRECT_FROM_HARDWARE (reads, aka METHOD_OUT_DIRECT)
'//

%METHOD_DIRECT_TO_HARDWARE   = %METHOD_IN_DIRECT
%METHOD_DIRECT_FROM_HARDWARE = %METHOD_OUT_DIRECT

'//
'// Define the access check value for any access
'//
'//
'// The FILE_READ_ACCESS and FILE_WRITE_ACCESS constants are also defined in
'// ntioapi.h as FILE_READ_DATA and FILE_WRITE_DATA. The values for these
'// constants *MUST* always be in sync.
'//
'//
'// FILE_SPECIAL_ACCESS is checked by the NT I/O system the same as FILE_ANY_ACCESS.
'// The file systems, however, may add additional access checks for I/O and FS controls
'// that use this value.
'//


%FILE_ANY_ACCESS                = 0
%FILE_SPECIAL_ACCESS            = %FILE_ANY_ACCESS
%FILE_READ_ACCESS               = &H0001   ' // file & pipe
%FILE_WRITE_ACCESS              = &H0002   ' // file & pipe

'// end_ntddk end_wdm end_nthal end_ntifs

'#endif // _DEVIOCTL_

#ENDIF  ' #IF NOT %DEF(%DEVIOCTL)


'#ifndef _NTDDSTOR_H_
'#define _NTDDSTOR_H_

#IF NOT %DEF(%NTDDSTOR_H)
    %NTDDSTOR_H = 1

'//
'// IoControlCode values for storage devices
'//

%IOCTL_STORAGE_BASE = %FILE_DEVICE_MASS_STORAGE

'//
'// The following device control codes are common for all class drivers.  They
'// should be used in place of the older IOCTL_DISK, IOCTL_CDROM and IOCTL_TAPE
'// common codes
'//

%IOCTL_STORAGE_CHECK_VERIFY            = &H002D4800???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_CHECK_VERIFY2           = &H002D0800???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0200, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_MEDIA_REMOVAL           = &H002D4804???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0201, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_EJECT_MEDIA             = &H002D4808???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0202, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_LOAD_MEDIA              = &H002D480C???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0203, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_LOAD_MEDIA2             = &H002D080C???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0203, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_RESERVE                 = &H002D4810???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_RELEASE                 = &H002D4814???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0205, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_FIND_NEW_DEVICES        = &H002D4818???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)

%IOCTL_STORAGE_EJECTION_CONTROL        = &H002D0940???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0250, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_MCN_CONTROL             = &H002D0944???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0251, METHOD_BUFFERED, FILE_ANY_ACCESS)

%IOCTL_STORAGE_GET_MEDIA_TYPES         = &H002D0C00???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0300, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_MEDIA_TYPES_EX      = &H002D0C04???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0301, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER = &H002D0C10???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0304, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_GET_HOTPLUG_INFO        = &H002D0C14???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0305, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_SET_HOTPLUG_INFO        = &H002DCC18???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0306, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)

%IOCTL_STORAGE_RESET_BUS               = &H002D5000???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0400, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_RESET_DEVICE            = &H002D5004???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_BREAK_RESERVATION       = &H002D5014???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_PERSISTENT_RESERVE_IN   = &H002D5018???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0406, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_PERSISTENT_RESERVE_OUT  = &H002DD01C???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0407, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

%IOCTL_STORAGE_GET_DEVICE_NUMBER       = &H002D1080???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0420, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_PREDICT_FAILURE         = &H002D1100???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0440, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_READ_CAPACITY           = &H002D5140???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0450, METHOD_BUFFERED, FILE_READ_ACCESS)

'//
'// IOCTLs 0x0463 to 0x0468 reserved for dependent disk support.
'//

%IOCTL_STORAGE_QUERY_PROPERTY          = &H002D1400???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES = &H002D9404???   ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0501, METHOD_BUFFERED, FILE_WRITE_ACCESS)

'//
'// IOCTLs for bandwidth contracts on storage devices
'// (Move this to ntddsfio if we decide to use a new base)
'//

%IOCTL_STORAGE_GET_BC_PROPERTIES       = &H002D5800???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0600, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_STORAGE_ALLOCATE_BC_STREAM      = &H002DD804???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0601, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_STORAGE_FREE_BC_STREAM          = &H002DD808???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0602, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'//
'// IOCTL to check for priority support
'//
%IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT = &H002D1880???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0620, METHOD_BUFFERED, FILE_ANY_ACCESS)

'// begin_winioctl

'//
'// These ioctl codes are obsolete.  They are defined here to avoid resuing them
'// and to allow class drivers to respond to them more easily.
'//

%OBSOLETE_IOCTL_STORAGE_RESET_BUS      = &H002DD000???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0400, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)
%OBSOLETE_IOCTL_STORAGE_RESET_DEVICE   = &H002DD004???  ' CTL_CODE(IOCTL_STORAGE_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS OR FILE_WRITE_ACCESS)

'//
'// IOCTLs 0x0643 to 0x0655 reserved for VHD disk support.
'//

'//
'// IOCTL_STORAGE_GET_HOTPLUG_INFO
'//

' // Size = 8 bytes
TYPE STORAGE_HOTPLUG_INFO BYTE
   Size                     AS DWORD ' DWORD   // version
   MediaRemovable           AS BYTE  ' BOOLEAN // ie. zip, jaz, cdrom, mo, etc. vs hdd
   MediaHotplug             AS BYTE  ' BOOLEAN // ie. does the device succeed a lock even though its not lockable media?
   DeviceHotplug            AS BYTE  ' BOOLEAN // ie. 1394, USB, etc.
   WriteCacheEnableOverride AS BYTE  ' BOOLEAN // This field should not be relied upon because it is no longer used
END TYPE

'//
'// IOCTL_STORAGE_GET_DEVICE_NUMBER
'//
'// input - none
'//
'// output - STORAGE_DEVICE_NUMBER structure
'//          The values in the STORAGE_DEVICE_NUMBER structure are guaranteed
'//          to remain unchanged until the system is rebooted.  They are not
'//          guaranteed to be persistant across boots.
'//

' // Size = 12 bytes
TYPE STORAGE_DEVICE_NUMBER DWORD
   ' // The FILE_DEVICE_XXX type for this device.
   DeviceType      AS DWORD   ' DEVICE_TYPE
   ' // The number of this device
   DeviceNumber    AS DWORD   ' DWORD
   ' // If the device is partitionable, the partition number of the device.
   ' // Otherwise -1
   PartitionNumber AS DWORD   ' DWORD
END TYPE

'//
'// Define the structures for scsi resets
'//

' // Size = 1 byte
TYPE STORAGE_BUS_RESET_REQUEST BYTE
   PathId AS BYTE
END TYPE

'//
'// Break reservation is sent to the Adapter/FDO with the given lun information.
'//

' // Size = 8 bytes
TYPE STORAGE_BREAK_RESERVATION_REQUEST BYTE
   Length   AS DWORD
   unused_  AS BYTE
   PathId   AS BYTE
   TargetId AS BYTE
   Lun      AS BYTE
END TYPE

'//
'// IOCTL_STORAGE_MEDIA_REMOVAL disables the mechanism
'// on a storage device that ejects media. This function
'// may or may not be supported on storage devices that
'// support removable media.
'//
'// TRUE means prevent media from being removed.
'// FALSE means allow media removal.
'//

' // Size = 1 byte
TYPE PREVENT_MEDIA_REMOVAL BYTE
   PreventMediaRemoval AS BYTE   ' BOOLEAN
END TYPE

'//
'//  This is the format of TARGET_DEVICE_CUSTOM_NOTIFICATION.CustomDataBuffer
'//  passed to applications by the classpnp autorun code (via IoReportTargetDeviceChangeAsynchronous).
'//

' // Size = 8 bytes
TYPE CLASS_MEDIA_CHANGE_CONTEXT DWORD
   MediaChangeCount AS DWORD
   NewState         AS DWORD  ' see MEDIA_CHANGE_DETECTION_STATE enum in classpnp.h in DDK
END TYPE

'// begin_ntminitape

' // Size = 48 bytes
TYPE TAPE_STATISTICS   ' Must be 8 byte aligned
   Version                AS DWORD   ' DWORD
   Flags                  AS DWORD   ' DWORD
   RecoveredWrites        AS QUAD    ' LARGE_INTEGER
   UnrecoveredWrites      AS QUAD    ' LARGE_INTEGER
   RecoveredReads         AS QUAD    ' LARGE_INTEGER
   UnrecoveredReads       AS QUAD    ' LARGE_INTEGER
   CompressionRatioReads  AS BYTE    ' BYTE
   CompressionRatioWrites AS BYTE    ' BYTE
   alignment__(5)         AS BYTE
END TYPE

%RECOVERED_WRITES_VALID        = &H00000001???
%UNRECOVERED_WRITES_VALID      = &H00000002???
%RECOVERED_READS_VALID         = &H00000004???
%UNRECOVERED_READS_VALID       = &H00000008???
%WRITE_COMPRESSION_INFO_VALID  = &H00000010???
%READ_COMPRESSION_INFO_VALID   = &H00000020???

' // Size = 4 bytes
TYPE TAPE_GET_STATISTICS DWORD
   Operation AS DWORD
END TYPE

%TAPE_RETURN_STATISTICS = 0???
%TAPE_RETURN_ENV_INFO   = 1???
%TAPE_RESET_STATISTICS  = 2???

'//
'// IOCTL_STORAGE_GET_MEDIA_TYPES_EX will return an array of DEVICE_MEDIA_INFO
'// structures, one per supported type, embedded in the GET_MEDIA_TYPES struct.
'//

' STORAGE_MEDIA_TYPE enum
%DDS_4mm            = &H20   ' // Tape - DAT DDS1,2,... (all vendors)
%MiniQic            = &H21   ' // Tape - miniQIC Tape
%Travan             = &H22   ' // Tape - Travan TR-1,2,3,...
%QIC                = &H23   ' // Tape - QIC
%MP_8mm             = &H24   ' // Tape - 8mm Exabyte Metal Particle
%AME_8mm            = &H25   ' // Tape - 8mm Exabyte Advanced Metal Evap
%AIT1_8mm           = &H26   ' // Tape - 8mm Sony AIT
%DLT                = &H27   ' // Tape - DLT Compact IIIxt, IV
%NCTP               = &H28   ' // Tape - Philips NCTP
%IBM_3480           = &H29   ' // Tape - IBM 3480
%IBM_3490E          = &H2A   ' // Tape - IBM 3490E
%IBM_Magstar_3590   = &H2B   ' // Tape - IBM Magstar 3590
%IBM_Magstar_MP     = &H2C   ' // Tape - IBM Magstar MP
%STK_DATA_D3        = &H2D   ' // Tape - STK Data D3
%SONY_DTF           = &H2E   ' // Tape - Sony DTF
%DV_6mm             = &H2F   ' // Tape - 6mm Digital Video
%DMI                = &H30   ' // Tape - Exabyte DMI and compatibles
%SONY_D2            = &H31   ' // Tape - Sony D2S and D2L
%CLEANER_CARTRIDGE  = &H32   ' // Cleaner - All Drive types that support Drive Cleaners
%CD_ROM             = &H33   ' // Opt_Disk - CD
%CD_R               = &H34   ' // Opt_Disk - CD-Recordable (Write Once)
%CD_RW              = &H35   ' // Opt_Disk - CD-Rewriteable
%DVD_ROM            = &H36   ' // Opt_Disk - DVD-ROM
%DVD_R              = &H37   ' // Opt_Disk - DVD-Recordable (Write Once)
%DVD_RW             = &H38   ' // Opt_Disk - DVD-Rewriteable
%MO_3_RW            = &H39   ' // Opt_Disk - 3.5" Rewriteable MO Disk
%MO_5_WO            = &H3A   ' // Opt_Disk - MO 5.25" Write Once
%MO_5_RW            = &H3B   ' // Opt_Disk - MO 5.25" Rewriteable (not LIMDOW)
%MO_5_LIMDOW        = &H3C   ' // Opt_Disk - MO 5.25" Rewriteable (LIMDOW)
%PC_5_WO            = &H3D   ' // Opt_Disk - Phase Change 5.25" Write Once Optical
%PC_5_RW            = &H3E   ' // Opt_Disk - Phase Change 5.25" Rewriteable
%PD_5_RW            = &H3F   ' // Opt_Disk - PhaseChange Dual Rewriteable
%ABL_5_WO           = &H40   ' // Opt_Disk - Ablative 5.25" Write Once Optical
%PINNACLE_APEX_5_RW = &H41   ' // Opt_Disk - Pinnacle Apex 4.6GB Rewriteable Optical
%SONY_12_WO         = &H42   ' // Opt_Disk - Sony 12" Write Once
%PHILIPS_12_WO      = &H43   ' // Opt_Disk - Philips/LMS 12" Write Once
%HITACHI_12_WO      = &H44   ' // Opt_Disk - Hitachi 12" Write Once
%CYGNET_12_WO       = &H45   ' // Opt_Disk - Cygnet/ATG 12" Write Once
%KODAK_14_WO        = &H46   ' // Opt_Disk - Kodak 14" Write Once
%MO_NFR_525         = &H47   ' // Opt_Disk - Near Field Recording (Terastor)
%NIKON_12_RW        = &H48   ' // Opt_Disk - Nikon 12" Rewriteable
%IOMEGA_ZIP         = &H49   ' // Mag_Disk - Iomega Zip
%IOMEGA_JAZ         = &H4A   ' // Mag_Disk - Iomega Jaz
%SYQUEST_EZ135      = &H4B   ' // Mag_Disk - Syquest EZ135
%SYQUEST_EZFLYER    = &H4C   ' // Mag_Disk - Syquest EzFlyer
%SYQUEST_SYJET      = &H4D   ' // Mag_Disk - Syquest SyJet
%AVATAR_F2          = &H4E   ' // Mag_Disk - 2.5" Floppy
%MP2_8mm            = &H4F   ' // Tape - 8mm Hitachi
%DST_S              = &H50   ' // Ampex DST Small Tapes
%DST_M              = &H51   ' // Ampex DST Medium Tapes
%DST_L              = &H52   ' // Ampex DST Large Tapes
%VXATape_1          = &H53   ' // Ecrix 8mm Tape
%VXATape_2          = &H54   ' // Ecrix 8mm Tape
'#if (NTDDI_VERSION < NTDDI_WINXP)
'    STK_EAGLE,                 // STK Eagle
'#else
'    STK_9840,                  // STK 9840
'#endif
#IF %WINVER < &H0501
%STK_EAGLE          = &H55   ' // STK Eagle
#ELSE
%STK_9840           = &H55   ' // STK 9840
#ENDIF
%LTO_Ultrium        = &H56   ' // IBM, HP, Seagate LTO Ultrium
%LTO_Accelis        = &H57   ' // IBM, HP, Seagate LTO Accelis
%DVD_RAM            = &H58   ' // Opt_Disk - DVD-RAM
%AIT_8mm            = &H59   ' // AIT2 or higher
%ADR_1              = &H5A   ' // OnStream ADR Mediatypes
%ADR_2              = &H5B
%STK_9940           = &H5C   ' // STK 9940
%SAIT               = &H5D   ' // SAIT Tapes
%VXATape            = &H5E   ' // VXA (Ecrix 8mm) Tape

%MEDIA_ERASEABLE         = &H00000001???
%MEDIA_WRITE_ONCE        = &H00000002???
%MEDIA_READ_ONLY         = &H00000004???
%MEDIA_READ_WRITE        = &H00000008???

%MEDIA_WRITE_PROTECTED   = &H00000100???
%MEDIA_CURRENTLY_MOUNTED = &H80000000???

'//
'// Define the different storage bus types
'// Bus types below 128 (0x80) are reserved for Microsoft use
'//

' STORAGE_BUS_TYPE enum
%BusTypeUnknown           = &H00
%BusTypeScsi              = &H01
%BusTypeAtapi             = &H02
%BusTypeAta               = &H03
%BusType1394              = &H04
%BusTypeSsa               = &H05
%BusTypeFibre             = &H06
%BusTypeUsb               = &H07
%BusTypeRAID              = &H08
%BusTypeiScsi             = &H09
%BusTypeSas               = &H0A
%BusTypeSata              = &H0B
%BusTypeSd                = &H0C
%BusTypeMmc               = &H0D
%BusTypeVirtual           = &H0E
%BusTypeFileBackedVirtual = &H0F
%BusTypeMax               = &H0F
%BusTypeMaxReserved       = &H7F

'typedef struct _DEVICE_MEDIA_INFO {
'    union {
'        struct {
'            LARGE_INTEGER Cylinders;
'            STORAGE_MEDIA_TYPE MediaType;
'            DWORD TracksPerCylinder;
'            DWORD SectorsPerTrack;
'            DWORD BytesPerSector;
'            DWORD NumberMediaSides;
'            DWORD MediaCharacteristics; // Bitmask of MEDIA_XXX values.
'        } DiskInfo;

'        struct {
'            LARGE_INTEGER Cylinders;
'            STORAGE_MEDIA_TYPE MediaType;
'            DWORD TracksPerCylinder;
'            DWORD SectorsPerTrack;
'            DWORD BytesPerSector;
'            DWORD NumberMediaSides;
'            DWORD MediaCharacteristics; // Bitmask of MEDIA_XXX values.
'        } RemovableDiskInfo;

'        struct {
'            STORAGE_MEDIA_TYPE MediaType;
'            DWORD   MediaCharacteristics; // Bitmask of MEDIA_XXX values.
'            DWORD   CurrentBlockSize;
'            STORAGE_BUS_TYPE BusType;

'            //
'            // Bus specific information describing the medium supported.
'            //

'            union {
'                struct {
'                    BYTE  MediumType;
'                    BYTE  DensityCode;
'                } ScsiInformation;
'            } BusSpecificData;

'        } TapeInfo;
'    } DeviceSpecific;
'} DEVICE_MEDIA_INFO, *PDEVICE_MEDIA_INFO;

'typedef struct _GET_MEDIA_TYPES {
'    DWORD DeviceType;              // FILE_DEVICE_XXX values
'    DWORD MediaInfoCount;
'    DEVICE_MEDIA_INFO MediaInfo[1];
'} GET_MEDIA_TYPES, *PGET_MEDIA_TYPES;

' // Size = 32 bytes
TYPE DMI_DiskInfo   ' Must be 8 byte aligned
   Cylinders            AS QUAD    ' LARGE_INTEGER
   MediaType            AS LONG    ' STORAGE_MEDIA_TYPE
   TracksPerCylinder    AS DWORD   ' DWORD
   SectorsPerTrack      AS DWORD   ' DWORD
   BytesPerSector       AS DWORD   ' DWORD
   NumberMediaSides     AS DWORD   ' DWORD
   MediaCharacteristics AS DWORD   ' DWORD // Bitmask of MEDIA_XXX values.
END TYPE

' // Size = 32 bytes
TYPE DMI_RemovableDiskInfo   ' Must be 8 byte aligned
   Cylinders            AS QUAD    ' LARGE_INTEGER
   MediaType            AS LONG    ' STORAGE_MEDIA_TYPE
   TracksPerCylinder    AS DWORD   ' DWORD
   SectorsPerTrack      AS DWORD   ' DWORD
   BytesPerSector       AS DWORD   ' DWORD
   NumberMediaSides     AS DWORD   ' DWORD
   MediaCharacteristics AS DWORD   ' DWORD // Bitmask of MEDIA_XXX values.
END TYPE

' // Size = 2 bytes
TYPE DMI_ScsiInformation BYTE
   MediumType  AS BYTE   ' BYTE
   DensityCode AS BYTE   ' BYTE
END TYPE

' // Size = 2 bytes
UNION DMI_BusSpecificData BYTE
   DMI_ScsiInformation
END UNION

' // Size = 20 bytes
TYPE DMI_TapeInfo DWORD
   MediaType            AS LONG    ' STORAGE_MEDIA_TYPE
   MediaCharacteristics AS DWORD   ' Bitmask of MEDIA_XXX values.
   CurrentBlockSize     AS DWORD
   BusType              AS LONG    ' STORAGE_BUS_TYPE
   DMI_BusSpecificData
   alignment__          AS WORD    ' // To keep DWORD alignment
END TYPE

' // Size = 32 bytes
UNION DMI_DeviceSpecific DWORD
   di  AS DMI_DiskInfo
   rdi AS DMI_RemovableDiskInfo
   ti  AS DMI_TapeInfo
END UNION

' // Size = 32 bytes
UNION DEVICE_MEDIA_INFO
   DMI_DeviceSpecific
END UNION

' // Size = 40 bytes
TYPE GET_MEDIA_TYPES
   DeviceType     AS DWORD              ' FILE_DEVICE_XXX values
   MediaInfoCount AS DWORD
   MediaInfo(0)   AS DEVICE_MEDIA_INFO
END TYPE

'//
'// IOCTL_STORAGE_PREDICT_FAILURE
'//
'// input - none
'//
'// output - STORAGE_PREDICT_FAILURE structure
'//          PredictFailure returns zero if no failure predicted and non zero
'//                         if a failure is predicted.
'//
'//          VendorSpecific returns 512 bytes of vendor specific information
'//                         if a failure is predicted
'//
'typedef struct _STORAGE_PREDICT_FAILURE
'{
'    DWORD PredictFailure;
'    BYTE  VendorSpecific[512];
'} STORAGE_PREDICT_FAILURE, *PSTORAGE_PREDICT_FAILURE;

'// end_ntminitape

'#endif // _NTDDSTOR_H_

' // Size = 516 bytes
TYPE STORAGE_PREDICT_FAILURE DWORD
   PredictFailure AS DWORD          ' DWORD PredictFailure
   VendorSpecific AS STRING * 512   ' BYTE  VendorSpecific[512]
END TYPE

' end_ntminitape

'//
'// Property Query Structures
'//

'//
'// IOCTL_STORAGE_QUERY_PROPERTY
'//
'// Input Buffer:
'//      a STORAGE_PROPERTY_QUERY structure which describes what type of query
'//      is being done, what property is being queried for, and any additional
'//      parameters which a particular property query requires.
'//
'//  Output Buffer:
'//      Contains a buffer to place the results of the query into.  Since all
'//      property descriptors can be cast into a STORAGE_DESCRIPTOR_HEADER,
'//      the IOCTL can be called once with a small buffer then again using
'//      a buffer as large as the header reports is necessary.
'//


'//
'// Types of queries
'//

' enum STORAGE_QUERY_TYPE
%PropertyStandardQuery   = 0   ' // Retrieves the descriptor
%PropertyExistsQuery     = 1   ' // Used to test whether the descriptor is supported
%PropertyMaskQuery       = 2   ' // Used to retrieve a mask of writeable fields in the descriptor
%PropertyQueryMaxDefined = 3   ' // use to validate the value

'//
'// define some initial property id's
'//

' enum STORAGE_PROPERTY_ID
%StorageDeviceProperty                 = 0
%StorageAdapterProperty                = 1
%StorageDeviceIdProperty               = 2
%StorageDeviceUniqueIdProperty         = 3   ' // See storduid.h for details
%StorageDeviceWriteCacheProperty       = 4
%StorageMiniportProperty               = 5
%StorageAccessAlignmentProperty        = 6
%StorageDeviceSeekPenaltyProperty      = 7
%StorageDeviceTrimProperty             = 8
%StorageDeviceWriteAggregationProperty = 9

'//
'// Query structure - additional parameters for specific queries can follow
'// the header
'//

' // Size = 12 bytes
TYPE STORAGE_PROPERTY_QUERY DWORD
   ' // ID of the property being retrieved
   PropertyId AS LONG   ' STORAGE_PROPERTY_ID
   ' // Flags indicating the type of query being performed
   QueryType  AS LONG   ' STORAGE_QUERY_TYPE
   ' // Space for additional parameters if necessary
   AdditionalParameters(0) AS BYTE   ' variable-length array
END TYPE

'//
'// Standard property descriptor header.  All property pages should use this
'// as their first element or should contain these two elements
'//

' // Size = 8 bytes
TYPE STORAGE_DESCRIPTOR_HEADER DWORD
   Version AS DWORD   ' DWORD
   Size    AS DWORD   ' DWORD
END TYPE

'//
'// Device property descriptor - this is really just a rehash of the inquiry
'// data retrieved from a scsi device
'//
'// This may only be retrieved from a target device.  Sending this to the bus
'// will result in an error
'//

' // Size = 40 bytes
TYPE STORAGE_DEVICE_DESCRIPTOR DWORD FILL
   ' // Sizeof(STORAGE_DEVICE_DESCRIPTOR)
   Version AS DWORD   ' DWORD
   ' // Total size of the descriptor, including the space for additional
   ' // data and id strings
   Size AS DWORD   ' DWORD
   ' // The SCSI-2 device type
   DeviceType AS BYTE   ' BYTE
   ' // The SCSI-2 device type modifier (if any) - this may be zero
   DeviceTypeModifier AS BYTE   ' BYTE
   ' // Flag indicating whether the device's media (if any) is removable.  This
   ' // field should be ignored for media-less devices
   RemovableMedia AS BYTE   ' BOOLEAN
   ' // Flag indicating whether the device can support mulitple outstanding
   ' // commands.  The actual synchronization in this case is the responsibility
   ' // of the port driver.
   CommandQueueing AS BYTE   ' BOOLEAN
   ' // Byte offset to the zero-terminated ascii string containing the device's
   ' // vendor id string.  For devices with no such ID this will be zero
   VendorIdOffset AS DWORD   ' DWORD
   ' // Byte offset to the zero-terminated ascii string containing the device's
   ' // product id string.  For devices with no such ID this will be zero
   ProductIdOffset AS DWORD   ' DWORD
   ' // Byte offset to the zero-terminated ascii string containing the device's
   ' // product revision string.  For devices with no such string this will be
   ' // zero
   ProductRevisionOffset AS DWORD   ' DWORD
   ' // Byte offset to the zero-terminated ascii string containing the device's
   ' // serial number.  For devices with no serial number this will be zero
   SerialNumberOffset AS DWORD   ' DWORD
   ' // Contains the bus type (as defined above) of the device.  It should be
   ' // used to interpret the raw device properties at the end of this structure
   ' // (if any)
   BusType AS LONG   ' STORAGE_BUS_TYPE
   ' // The number of bytes of bus-specific data which have been appended to
   ' // this descriptor
   RawPropertiesLength AS DWORD   ' DWORD
   ' // Place holder for the first byte of the bus specific property data
   RawDeviceProperties(0) AS BYTE   ' variable-length array
   alignment__(2) AS BYTE
END TYPE


'//
'// Adapter properties
'//
'// This descriptor can be retrieved from a target device object of from the
'// device object for the bus.  Retrieving from the target device object will
'// forward the request to the underlying bus
'//

' // Size = 32 bytes
TYPE STORAGE_ADAPTER_DESCRIPTOR   ' Must be 4 byte aligned
   Version               AS DWORD   ' DWORD
   Size                  AS DWORD   ' DWORD
   MaximumTransferLength AS DWORD   ' DWORD
   MaximumPhysicalPages  AS DWORD   ' DWORD
   AlignmentMask         AS DWORD   ' DWORD
   AdapterUsesPio        AS BYTE    ' BOOLEAN
   AdapterScansDown      AS BYTE    ' BOOLEAN
   CommandQueueing       AS BYTE    ' BOOLEAN
   AcceleratedTransfer   AS BYTE    ' BOOLEAN
'#if (NTDDI_VERSION < NTDDI_WINXP)
'    BOOLEAN BusType;
'#else
'    BYTE  BusType;
   BusType               AS BYTE   ' BYTE
'#endif
   alignment1__          AS BYTE
   BusMajorVersion       AS WORD   ' WORD
   BusMinorVersion       AS WORD   ' WORD
   alignment2__          AS WORD
END TYPE

' // Size = 28 bytes
TYPE STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR DWORD
   ' // Sizeof(STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR)
   Version AS DWORD   ' DWORD
   ' // Total size of the descriptor, including the space for additional
   ' // data and id strings
   Size AS DWORD   ' DWORD
   ' // The number of bytes in a cache line of the device
   BytesPerCacheLine AS DWORD   ' DWORD
   ' // The address offset neccessary for proper cache access alignment in bytes
   BytesOffsetForCacheAlignment AS DWORD   ' DWORD
   ' // The number of bytes in a physical sector of the device
   BytesPerLogicalSector AS DWORD   ' DWORD
   ' // The number of bytes in an addressable logical sector (LBA)of the device
   BytesPerPhysicalSector AS DWORD   ' DWORD
   ' // The address offset neccessary for proper sector access alignment in bytes
   BytesOffsetForSectorAlignment AS DWORD   ' DWORD
END TYPE


' enum STORAGE_PORT_CODE_SET
%StoragePortCodeSetReserved = 0
%StoragePortCodeSetStorport = 1
%StoragePortCodeSetSCSIport = 2

' // Size = 16 bytes
TYPE STORAGE_MINIPORT_DESCRIPTOR
   Version              AS DWORD   ' DWORD
   Size                 AS DWORD   ' DWORD
   Portdriver           AS LONG    ' STORAGE_PORT_CODE_SET
   LUNResetSupported    AS BYTE    ' BOOLEAN
   TargetResetSupported AS BYTE    ' BOOLEAN
   alignment__          AS WORD
END TYPE

'//
'// Storage identification descriptor.
'// The definitions here are based on the SCSI/SBP vital product data
'// device identifier page.
'//

' enum STORAGE_IDENTIFIER_CODE_SET
%StorageIdCodeSetReserved = 0
%StorageIdCodeSetBinary   = 1
%StorageIdCodeSetAscii    = 2
%StorageIdCodeSetUtf8     = 3

' enum STORAGE_IDENTIFIER_TYPE
%StorageIdTypeVendorSpecific           = 0
%StorageIdTypeVendorId                 = 1
%StorageIdTypeEUI64                    = 2
%StorageIdTypeFCPHName                 = 3
%StorageIdTypePortRelative             = 4
%StorageIdTypeTargetPortGroup          = 5
%StorageIdTypeLogicalUnitGroup         = 6
%StorageIdTypeMD5LogicalUnitIdentifier = 7
%StorageIdTypeScsiNameString           = 8

'// Mislabeled above but need to keep it for backwards compatibility
'#define StorageIdTypeNAA StorageIdTypeFCPHName
%StorageIdTypeNAA = %StorageIdTypeFCPHName

'// NAA formats (Used with StorageIdTypeNAA)
' enum STORAGE_ID_NAA_FORMAT
%StorageIdNAAFormatIEEEExtended            = 2
%StorageIdNAAFormatIEEERegistered          = 3
%StorageIdNAAFormatIEEEERegisteredExtended = 5

' enum STORAGE_ASSOCIATION_TYPE
%StorageIdAssocDevice = 0
%StorageIdAssocPort   = 1
%StorageIdAssocTarget = 2

' // Size = 20 bytes
TYPE STORAGE_IDENTIFIER
   CodeSet        AS LONG   ' STORAGE_IDENTIFIER_CODE_SET
   Type           AS LONG   ' STORAGE_IDENTIFIER_TYPE
   IdentifierSize AS WORD   ' WORD
   NextOffset     AS WORD   ' WORD
   ' // Add new fields here since existing code depends on
   ' // the above layout not changing.
   Association    AS LONG   ' STORAGE_ASSOCIATION_TYPE
   ' // The identifier is a variable length array of bytes.
   Identifier(3)  AS BYTE   ' variable-length array
   ' Note: We are using Identifier(3) instead of Identifier(0) to keep DWORD alignment
END TYPE

' // Size = 16 bytes
TYPE STORAGE_DEVICE_ID_DESCRIPTOR DWORD
   Version             AS DWORD   ' DWORD
   Size                AS DWORD   ' DWORD
   ' // The number of identifiers reported by the device.
   NumberOfIdentifiers AS DWORD   ' DWORD
   ' // The following field is actually a variable length array of identification
   ' // descriptors.  Unfortunately there's no C notation for an array of
   ' // variable length structures so we're forced to just pretend.
   Identifiers(0)      AS BYTE   ' variable-length array
END TYPE

'// output buffer for   StorageDeviceSeekPenaltyProperty & PropertyStandardQuery
' // Size = 12 bytes
TYPE DEVICE_SEEK_PENALTY_DESCRIPTOR DWORD
   Version           AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   Size              AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   IncursSeekPenalty AS BYTE    ' BOOLEAN
END TYPE

'// output buffer for   StorageDeviceWriteAggregationProperty & PropertyStandardQuery
' // Size = 12 bytes
TYPE DEVICE_WRITE_AGGREGATION_DESCRIPTOR DWORD
   Version                      AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   Size                         AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   BenefitsFromWriteAggregation AS BYTE    ' BOOLEAN
END TYPE

'// output buffer for   StorageDeviceTrimProperty & PropertyStandardQuery
' // Size = 12 bytes
TYPE DEVICE_TRIM_DESCRIPTOR DWORD
   Version     AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   Size        AS DWORD   ' DWORD // keep compatible with STORAGE_DESCRIPTOR_HEADER
   TrimEnabled AS BYTE    ' BOOLEAN
END TYPE

'//
'// IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES
'//
'// Input Buffer:
'//     Structure of type DEVICE_MANAGE_DATA_SET_ATTRIBUTES
'//
'// Output Buffer:
'//     N/A
'//
'// Note:
'//     1. Management of action Trim will be only allowed for kernel request.
'//        This request sent from user application will be rejected by kernel drivers.
'//

'//
'//  This flag, when OR'd into an action indicates that the given action is
'//  non-destructive.  If this flag is set then storage stack components which
'//  do not understand the action should forward the given request
'//

%DeviceDsmActionFlag_NonDestructive = &H80000000???

'#define IsDsmActionNonDestructive(_Action) ((BOOLEAN)((_Action & DeviceDsmActionFlag_NonDestructive) != 0))
MACRO IsDsmActionNonDestructive(Action_) = ((Action_ AND %DeviceDsmActionFlag_NonDestructive) <> 0)

'//
'//  Defines the various actions
'//

'typedef DWORD DEVICE_DATA_MANAGEMENT_SET_ACTION;
%DeviceDsmAction_None         = 0
%DeviceDsmAction_Trim         = 1
%DeviceDsmAction_Notification = 2 OR %DeviceDsmActionFlag_NonDestructive

'//
'//  Flags that are global across all actions
'//

%DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE = &H00000001???   ' // If set, the DataSetRanges fields should be 0


' // Size = 16 bytes
TYPE DEVICE_DATA_SET_RANGE QWORD
   StartingOffset AS QUAD   ' LONGLONG //in bytes  ,  must allign to sector
   LengthInBytes  AS QUAD   ' DWORDLONG // multiple of sector size.
END TYPE

'//
'// input structure for IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES
'// 1. Value ofParameterBlockOffset or ParameterBlockLength is 0 indicates that Parameter Block does not exist.
'// 2. Value of DataSetRangesOffset or DataSetRangesLength is 0 indicates that DataSetRanges Block does not exist.
'//     If DataSetRanges Block exists, it contains contiguous DEVICE_DATA_SET_RANGE structures.
'// 3. The total size of buffer should be at least:
'//      sizeof (DEVICE_MANAGE_DATA_SET_ATTRIBUTES) + ParameterBlockLength + DataSetRangesLength
'//
' // Size = 28 bytes
TYPE DEVICE_MANAGE_DATA_SET_ATTRIBUTES DWORD
   Size                 AS DWORD   ' DWORD  // Size of structure DEVICE_MANAGE_DATA_SET_ATTRIBUTES
   Action               AS DWORD   ' DEVICE_DATA_MANAGEMENT_SET_ACTION
   Flags                AS DWORD   ' DWORD // Global flags across all actions
   ParameterBlockOffset AS DWORD   ' DWORD // must be alligned to corresponding structure allignment
   ParameterBlockLength AS DWORD   ' DWORD // 0 means Parameter Block does not exist.
   DataSetRangesOffset  AS DWORD   ' DWORD // must be alligned to DEVICE_DATA_SET_RANGE structure allignment.
   DataSetRangesLength  AS DWORD   ' DWORD // 0 means DataSetRanges Block does not exist.
END TYPE

'//
'//  This defines the parameter block for the DeviceDsmAction_Notification
'//  action
'//

' // Size = 28 bytes
TYPE DEVICE_DSM_NOTIFICATION_PARAMETERS DWORD
   Size           AS DWORD   ' DWORD // Size of this structure
   Flags          AS DWORD   ' DWORD // Flags specific to the notify operation
   NumFileTypeIDs AS DWORD   ' DWORD // Count of how many file type ID's are given
   FileTypeID(0)  AS GUID    ' GUID  // Identifier for the type of file being notified
END TYPE

'//
'//  DEVICE_DSM_NOTIFICATION_PARAMETERS flag definitions
'//

%DEVICE_DSM_NOTIFY_FLAG_BEGIN = &H00000001???   ' // The given LBA range is being used as defined by the FileID
%DEVICE_DSM_NOTIFY_FLAG_END   = &H00000002???   ' // The given LBA range is no longer being used as defined by the FileID

'//
'//  There are some well known GUIDS for certail types of files.  They are
'//  defined in NTIFS.H
'//

'//
'// IOCTL_STORAGE_GET_BC_PROPERTIES
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     Structure of type STORAGE_GET_BC_PROPERTIES_OUTPUT
'//

' // Size = 32 bytes
TYPE STORAGE_GET_BC_PROPERTIES_OUTPUT   ' Must be 8 byte aligned
   ' // Specifies the maximum number of requests
   ' // that can be scheduled per period of time
   MaximumRequestsPerPeriod AS DWORD   ' DWORD
   ' // Specifies the minimum period that the
   ' // device uses  when scheduling requests
   MinimumPeriod AS DWORD   ' DWORD
   ' // Specifies the maximum transfer size supported
   ' // for  bandwidth contracts  on this  device. To
   ' // achieve the highest level of performance, all
   ' // requests should be of this size
   MaximumRequestSize AS QUAD   ' DWORDLONG
   ' // Specifies the estimated time taken to
   ' // perform an  Io operstion. This  field
   ' // is  for  informational purposes  only
   EstimatedTimePerRequest AS DWORD   ' DWORD
   ' // Specifies the number of requests that should be
   ' // kept outstanding.  This helps  keep the  device
   ' // device busy and thus obtain maximum throughput.
   ' // This will only be filled in if the target  file
   ' // has an outstanding contract.
   NumOutStandingRequests AS DWORD   ' DWORD
   ' // Specifies the required size of requests in this
   ' // stream.  This  will  only  be filled in  if the
   ' // target file has an outstanding contract.
   RequestSize AS QUAD   ' DWORDLONG
END TYPE


'//
'// IOCTL_STORAGE_ALLOCATE_BC_STREAM
'//
'// Input Buffer:
'//     Structure of type STORAGE_ALLOCATE_BC_STREAM_INPUT
'//
'// Output Buffer:
'//     Structure of type STORAGE_ALLOCATE_BC_STREAM_OUTPUT
'//


'//
'// Current version
'//
%IOCTL_STORAGE_BC_VERSION = 1

' // Size = 24 bytes
TYPE STORAGE_ALLOCATE_BC_STREAM_INPUT BYTE
   ' // Specifies the corresponding structure version
   Version AS DWORD   ' DWORD
   ' // Specifies the number of requests that
   ' // need to  complete  per period of time
   RequestsPerPeriod AS DWORD   ' DWORD
   ' // Specifies the period of time wherein the
   ' // above  number of requests  must complete
   Period AS DWORD   ' DWORD
   ' // Indicates whether failures
   ' // should  be retried  or not
   RetryFailures AS BYTE   ' BOOLEAN
   ' // Indicates whether reqests that  will miss
   ' // their deadline should be discarded or not
   Discardable AS BYTE   ' BOOLEAN
   ' // Helps align the following field
   Reserved1(1) AS BYTE   ' BOOLEAN
   ' // Indicates whether the  Io  will be
   ' // comprised of reads, writes or both
   AccessType AS DWORD   ' DWORD
   ' // Indicates whether the  Io  to the
   ' // file will be sequential or random
   AccessMode AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE STORAGE_ALLOCATE_BC_STREAM_OUTPUT QWORD   ' Must be 8 byte aligned
   ' // Specifies the required size
   ' // of  requests in this stream
   RequestSize AS QUAD   ' DWORDLONG
   ' // Specifies the number of requests that should be
   ' // kept outstanding.  This helps  keep the  device
   ' // device busy and thus obtain maximum  throughput
   NumOutStandingRequests AS DWORD   ' DWORD
END TYPE


'//
'// IOCTL_STORAGE_FREE_BC_STREAM
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     None
'//

'//
'// IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT
'//
'// Input Buffer :
'//      None
'// Output Buffer :
'//      Structure of type STORAGE_PRIORITY_HINT_SUPPORT
'//

%STORAGE_PRIORITY_HINT_SUPPORTED = &H0001

' // Size = 4 bytes
TYPE STORAGE_PRIORITY_HINT_SUPPORT DWORD
   SupportFlags AS DWORD   ' DWORD
END TYPE

'#pragma warning(push)
'#pragma warning(disable:4200)

'#if defined(_MSC_EXTENSIONS)

' // Size = 4 bytes
TYPE STORAGE_MEDIA_SERIAL_NUMBER_DATA
   Reserved AS WORD   ' WORD
   ' // the SerialNumberLength will be set to zero
   ' // if the command is supported and the media
   ' // does not have a valid serial number.
   SerialNumberLength AS WORD   ' WORD
   ' // the following data is binary, and is not guaranteed
   ' // to be NULL terminated.  this is an excercise for the
   ' // caller.
'#if !defined(__midl)
   'SerialNumber() AS BYTE   ' variable-length array
'#endif
END TYPE

'#endif /* _MSC_EXTENSIONS */

' // Size = 32 bytes
TYPE STORAGE_READ_CAPACITY QWORD FILL  ' Must be 8 byte aligned
   ' // The version number, size of the STORAGE_READ_CAPACITY structure
   Version AS DWORD   ' DWORD
   ' // The size of the date returned, size of the STORAGE_READ_CAPACITY structure
   Size AS DWORD   ' DWORD
   ' // Number of bytes per block
   BlockLength AS DWORD   ' DWORD
   ' // Total number of blocks in the disk
   ' // This will have the last LBA + 1
   NumberOfBlocks AS QUAD   ' LARGE_INTEGER
   ' // Disk size in bytes
   DiskLength AS QUAD   ' LARGE_INTEGER
END TYPE

'#pragma warning(pop)

'//
'// Device write cache property
'//
'// This property provides the write cache information
'// about the target device.
'//

' enum WRITE_CACHE_TYPE
%WriteCacheTypeUnknown      = 0
%WriteCacheTypeNone         = 1
%WriteCacheTypeWriteBack    = 2
%WriteCacheTypeWriteThrough = 3

' enum WRITE_CACHE_ENABLE
%WriteCacheEnableUnknown    = 0
%WriteCacheDisabled         = 1
%WriteCacheEnabled          = 2

' enum WRITE_CACHE_CHANGE
%WriteCacheChangeUnknown    = 0
%WriteCacheNotChangeable    = 1
%WriteCacheChangeable       = 2

' enum WRITE_THROUGH
%WriteThroughUnknown        = 0
%WriteThroughNotSupported   = 1
%WriteThroughSupported      = 2

' // Size = 28 bytes
TYPE STORAGE_WRITE_CACHE_PROPERTY   ' Must be 4 byte aligned
   ' // The version number
   ' // Size of STORAGE_WRITE_CACHE_PROPERTY structure
   Version AS DWORD   ' DWORD
   ' // The size of the date returned
   ' // Size of STORAGE_WRITE_CACHE_PROPERTY structure
   Size AS DWORD   ' DWORD
   ' // Current write cache type
   WriteCacheType AS LONG   ' WRITE_CACHE_TYPE
   ' // Current write cache value
   WriteCacheEnabled AS LONG   ' WRITE_CACHE_ENABLE
   ' // Device write cache change capability
   WriteCacheChangeable AS LONG   ' WRITE_CACHE_CHANGE
   ' // Device write through support capability
   WriteThroughSupported AS LONG   ' WRITE_THROUGH
   ' // Device flush cache capability
   FlushCacheSupported AS BYTE   ' BOOLEAN
   ' // User selected power protection option through registry
   UserDefinedPowerProtection AS BYTE   ' BOOLEAN
   ' // Device has battery backup for write cache
   NVCacheEnabled AS BYTE   ' BOOLEAN
   alignment__ AS BYTE   ' To keep DWORD alignment
END TYPE


'#pragma warning(push)
'#pragma warning(disable:4200) // array[0]
'#pragma warning(disable:4201) // nameless struct/unions
'#pragma warning(disable:4214) // bit fields other than int

'#if defined(_MSC_EXTENSIONS)

' // Size = 4 bytes
TYPE PERSISTENT_RESERVE_COMMAND_PR_IN WORD
   ' // Persistent Reserve service action.
   ServiceAction    AS BIT * 5 IN BYTE
   Reserved1        AS BIT * 3
   ' // Number of bytes allocated for returned parameter list.
   AllocationLength AS WORD   ' WORD
END TYPE

' // Size = 2 bytes
TYPE PERSISTENT_RESERVE_COMMAND_PR_OUT BYTE
   ' // Persistent Reserve service action.
   ServiceAction AS BIT * 5 IN BYTE
   Reserved1     AS BIT * 3
   ' // Persistent Reserve type and scope.
   Type          AS BIT * 4 IN BYTE
   Scope         AS BIT * 4
   ' // Space for additional PR Out parameters.
'#if !defined(__midl)
   'ParameterList() AS BYTE   ' variable-length array
'#endif
END TYPE

' // Size = 4 bytes
UNION PERSISTENT_RESERVE_COMMAND_UNION
   PR_IN  AS PERSISTENT_RESERVE_COMMAND_PR_IN
   PR_OUT AS PERSISTENT_RESERVE_COMMAND_PR_OUT
END UNION

' // Size = 12 bytes
TYPE PERSISTENT_RESERVE_COMMAND DWORD
   Version AS DWORD   ' DWORD
   Size    AS DWORD   ' DWORD
   PERSISTENT_RESERVE_COMMAND_UNION
END TYPE

'#endif /* _MSC_EXTENSIONS */
'#pragma warning(pop)


'#ifdef __cplusplus
'}
'#endif

#ENDIF  ' #IF NOT %DEF(%NTDDSTOR_H)

#IF NOT %DEF(%NTDDDISK_H)
    %NTDDDISK_H = 1

'//
'// IoControlCode values for disk devices.
'//

%IOCTL_DISK_BASE                = %FILE_DEVICE_DISK
%IOCTL_DISK_GET_DRIVE_GEOMETRY  = &H00070000???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_GET_PARTITION_INFO  = &H00074004???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_PARTITION_INFO  = &H0007C008???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_DRIVE_LAYOUT    = &H0007400C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_DRIVE_LAYOUT    = &H0007C010???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_VERIFY              = &H00070014???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0005, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_FORMAT_TRACKS       = &H0007C018???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_REASSIGN_BLOCKS     = &H0007C01C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_PERFORMANCE         = &H00070020???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0008, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_IS_WRITABLE         = &H00070024???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0009, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_LOGGING             = &H00070028???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000a, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_FORMAT_TRACKS_EX    = &H0007C02C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_HISTOGRAM_STRUCTURE = &H00070030???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000c, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_HISTOGRAM_DATA      = &H00070034???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000d, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_HISTOGRAM_RESET     = &H00070038???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000e, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_REQUEST_STRUCTURE   = &H0007003C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x000f, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_REQUEST_DATA        = &H00070040???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0010, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_PERFORMANCE_OFF     = &H00070060???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0018, METHOD_BUFFERED, FILE_ANY_ACCESS)


'#if(_WIN32_WINNT >= 0x0400)

%IOCTL_DISK_CONTROLLER_NUMBER    = &H00070044???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0011, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'// IOCTL support for SMART drive fault prediction.
'//

%SMART_GET_VERSION               = &H00074080???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0020, METHOD_BUFFERED, FILE_READ_ACCESS)
%SMART_SEND_DRIVE_COMMAND        = &H0007C084???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0021, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%SMART_RCV_DRIVE_DATA            = &H0007C088???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0022, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if (_WIN32_WINNT >= 0x500)

'//
'// New IOCTLs for GUID Partition tabled disks.
'//

%IOCTL_DISK_GET_PARTITION_INFO_EX    = &H00070048???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0012, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_SET_PARTITION_INFO_EX    = &H0007C04C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_DRIVE_LAYOUT_EX      = &H00070050???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0014, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_DISK_SET_DRIVE_LAYOUT_EX      = &H0007C054???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0015, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_CREATE_DISK              = &H0007C058???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0016, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GET_LENGTH_INFO          = &H0007405C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0017, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_GET_DRIVE_GEOMETRY_EX    = &H000700A0???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if (_WIN32_WINNT >= 0x0502)

'//
'// New IOCTL for disk devices that support 8 byte LBA
'//
%IOCTL_DISK_REASSIGN_BLOCKS_EX       = &H0007C0A4???

'#endif //_WIN32_WINNT >= 0x0502

'#if(_WIN32_WINNT >= 0x0500)

%IOCTL_DISK_UPDATE_DRIVE_SIZE        = &H0007C0C8???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0032, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_GROW_PARTITION           = &H0007C0D0???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0034, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

%IOCTL_DISK_GET_CACHE_INFORMATION    = &H000740D4???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0035, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_SET_CACHE_INFORMATION    = &H0007C0D8???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0036, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
'#if (NTDDI_VERSION < NTDDI_WIN2003)
'#define IOCTL_DISK_GET_WRITE_CACHE_STATE    CTL_CODE(IOCTL_DISK_BASE, 0x0037, METHOD_BUFFERED, FILE_READ_ACCESS)
'#else
'#define OBSOLETE_DISK_GET_WRITE_CACHE_STATE CTL_CODE(IOCTL_DISK_BASE, 0x0037, METHOD_BUFFERED, FILE_READ_ACCESS)
'#endif
%IOCTL_DISK_GET_WRITE_CACHE_STATE    = &H000740DC???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0037, METHOD_BUFFERED, FILE_READ_ACCESS)

%IOCTL_DISK_DELETE_DRIVE_LAYOUT      = &H0007C100???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0040, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'//
'// Called to flush cached information that the driver may have about this
'// device's characteristics.  Not all drivers cache characteristics, and not
'// cached properties can be flushed.  This simply serves as an update to the
'// driver that it may want to do an expensive reexamination of the device's
'// characteristics now (fixed media size, partition table, etc...)
'//

%IOCTL_DISK_UPDATE_PROPERTIES    = &H00070140???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0050, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'//  Special IOCTLs needed to support PC-98 machines in Japan
'//

%IOCTL_DISK_FORMAT_DRIVE         = &H0007C3CC???  ' CTL_CODE(IOCTL_DISK_BASE, 0x00f3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_DISK_SENSE_DEVICE         = &H000703E0???  ' CTL_CODE(IOCTL_DISK_BASE, 0x00f8, METHOD_BUFFERED, FILE_ANY_ACCESS)

'#endif /* _WIN32_WINNT >= 0x0500 */

'//
'// The following device control codes are common for all class drivers.  The
'// functions codes defined here must match all of the other class drivers.
'//
'// Warning: these codes will be replaced in the future by equivalent
'// IOCTL_STORAGE codes
'//

%IOCTL_DISK_CHECK_VERIFY     = &H00074800???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_MEDIA_REMOVAL    = &H00074804???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0201, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_EJECT_MEDIA      = &H00074808???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0202, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_LOAD_MEDIA       = &H0007480C???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0203, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_RESERVE          = &H00074810???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_RELEASE          = &H00074814???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0205, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_FIND_NEW_DEVICES = &H00074818???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_DISK_GET_MEDIA_TYPES  = &H00070C00???  ' CTL_CODE(IOCTL_DISK_BASE, 0x0300, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'// Define the partition types returnable by known disk drivers.
'//

%PARTITION_ENTRY_UNUSED        = &H00      ' Entry unused
%PARTITION_FAT_12              = &H01      ' 12-bit FAT entries
%PARTITION_XENIX_1             = &H02      ' Xenix
%PARTITION_XENIX_2             = &H03      ' Xenix
%PARTITION_FAT_16              = &H04      ' 16-bit FAT entries
%PARTITION_EXTENDED            = &H05      ' Extended partition entry
%PARTITION_HUGE                = &H06      ' Huge partition MS-DOS V4
%PARTITION_IFS                 = &H07      ' IFS Partition
%PARTITION_OS2BOOTMGR          = &H0A      ' OS/2 Boot Manager/OPUS/Coherent swap
%PARTITION_FAT32               = &H0B      ' FAT32
%PARTITION_FAT32_XINT13        = &H0C      ' FAT32 using extended int13 services
%PARTITION_XINT13              = &H0E      ' Win95 partition using extended int13 services
%PARTITION_XINT13_EXTENDED     = &H0F      ' Same as type 5 but uses extended int13 services
%PARTITION_PREP                = &H41      ' PowerPC Reference Platform (PReP) Boot Partition
%PARTITION_LDM                 = &H42      ' Logical Disk Manager partition
%PARTITION_UNIX                = &H63      ' Unix

%VALID_NTFT                    = &H0C0     ' NTFT uses high order bits

'//
'// The high bit of the partition type code indicates that a partition
'// is part of an NTFT mirror or striped array.
'//

%PARTITION_NTFT                = &H080     ' NTFT partition

'//
'// The following macro is used to determine which partitions should be
'// assigned drive letters.
'//

'//++
'//
'// BOOLEAN
'// IsRecognizedPartition(
'//     IN DWORD PartitionType
'//     )
'//
'// Routine Description:
'//
'//     This macro is used to determine to which partitions drive letters
'//     should be assigned.
'//
'// Arguments:
'//
'//     PartitionType - Supplies the type of the partition being examined.
'//
'// Return Value:
'//
'//     The return value is TRUE if the partition type is recognized,
'//     otherwise FALSE is returned.
'//
'//--

'#define IsRecognizedPartition( PartitionType ) (    \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT_12)) ||  \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_IFS)) ||  \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_HUGE)) ||  \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32)) ||  \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_FAT32_XINT13)) ||  \
'     ((PartitionType & PARTITION_NTFT) && ((PartitionType & ~0xC0) == PARTITION_XINT13)) ||  \
'     ((PartitionType) == PARTITION_FAT_12)          ||  \
'     ((PartitionType) == PARTITION_FAT_16)          ||  \
'     ((PartitionType) == PARTITION_IFS)             ||  \
'     ((PartitionType) == PARTITION_HUGE)            ||  \
'     ((PartitionType) == PARTITION_FAT32)           ||  \
'     ((PartitionType) == PARTITION_FAT32_XINT13)    ||  \
'     ((PartitionType) == PARTITION_XINT13) )

MACRO FUNCTION IsRecognizedPartition(PartitionType)

    MACROTEMP b, d, m

    LOCAL b AS BYTE
    LOCAL d AS DWORD
    LOCAL m AS DWORD

    d = PartitionType
    m = d AND NOT &H00C0

    b = (ISTRUE(d AND %PARTITION_NTFT) _
         AND ((m = %PARTITION_FAT_12) OR (m = %PARTITION_IFS)            _
           OR (m = %PARTITION_HUGE)   OR (m = %PARTITION_FAT32)          _
           OR (m = PARTITION_XINT13)  OR (m = %PARTITION_FAT32_XINT13))) _
     OR (d = PARTITION_FAT_12) OR (d = PARTITION_FAT_16)                 _
     OR (d = PARTITION_IFS)    OR (d = PARTITION_HUGE)                   _
     OR (d = PARTITION_FAT32)  OR (d = PARTITION_FAT32_XINT13)           _
     OR (d = PARTITION_XINT13))

END MACRO = ABS(b)

'//++
'//
'// BOOLEAN
'// IsContainerPartition(
'//     IN DWORD PartitionType
'//     )
'//
'// Routine Description:
'//
'//     This macro is used to determine to which partition types are actually
'//     containers for other partitions (ie, extended partitions).
'//
'// Arguments:
'//
'//     PartitionType - Supplies the type of the partition being examined.
'//
'// Return Value:
'//
'//     The return value is TRUE if the partition type is a container,
'//     otherwise FALSE is returned.
'//
'//--

'#define IsContainerPartition( PartitionType ) \
'    ((PartitionType == PARTITION_EXTENDED) || (PartitionType == PARTITION_XINT13_EXTENDED))

MACRO IsContainerPartition(PartitionType) = ABS(((PartitionType) = %PARTITION_EXTENDED) OR ((PartitionType) = %PARTITION_XINT13_EXTENDED)))

'//++
'//
'// BOOLEAN
'// IsFTPartition(
'//     IN DWORD PartitionType
'//     )
'//
'// Routine Description:
'//
'//     This macro is used to determine if the given partition is an FT
'//     partition.
'//
'// Arguments:
'//
'//     PartitionType - Supplies the type of the partition being examined.
'//
'// Return Value:
'//
'//     The return value is TRUE if the partition type is an FT partition,
'//     otherwise FALSE is returned.
'//
'//--

'#define IsFTPartition( PartitionType ) \
'    (((PartitionType)&PARTITION_NTFT) && IsRecognizedPartition(PartitionType))

MACRO IsFTPartition(PartitionType) = ABS(ISTRUE ((PartitionType) AND %PARTITION_NTFT) AND ISTRUE IsRecognizedPartition(PartitionType))

'//
'// Define the media types supported by the driver.
'//

' MEDIA_TYPE enum
%Unknown        = 0      ' Format is unknown
%F5_1Pt2_512    = 1      ' 5.25", 1.2MB,  512 bytes/sector
%F3_1Pt44_512   = 2      ' 3.5",  1.44MB, 512 bytes/sector
%F3_2Pt88_512   = 3      ' 3.5",  2.88MB, 512 bytes/sector
%F3_20Pt8_512   = 4      ' 3.5",  20.8MB, 512 bytes/sector
%F3_720_512     = 5      ' 3.5",  720KB,  512 bytes/sector
%F5_360_512     = 6      ' 5.25", 360KB,  512 bytes/sector
%F5_320_512     = 7      ' 5.25", 320KB,  512 bytes/sector
%F5_320_1024    = 8      ' 5.25", 320KB,  1024 bytes/sector
%F5_180_512     = 9      ' 5.25", 180KB,  512 bytes/sector
%F5_160_512     = 10     ' 5.25", 160KB,  512 bytes/sector
%RemovableMedia = 11     ' Removable media other than floppy
%FixedMedia     = 12     ' Fixed hard disk media
%F3_120M_512    = 13     ' 3.5", 120M Floppy
%F3_640_512     = 14     ' 3.5" ,  640KB,  512 bytes/sector
%F5_640_512     = 15     ' 5.25",  640KB,  512 bytes/sector
%F5_720_512     = 16     ' 5.25",  720KB,  512 bytes/sector
%F3_1Pt2_512    = 17     ' 3.5" ,  1.2Mb,  512 bytes/sector
%F3_1Pt23_1024  = 18     ' 3.5" ,  1.23Mb, 1024 bytes/sector
%F5_1Pt23_1024  = 19     ' 5.25",  1.23MB, 1024 bytes/sector
%F3_128Mb_512   = 20     ' 3.5" MO 128Mb   512 bytes/sector
%F3_230Mb_512   = 21     ' 3.5" MO 230Mb   512 bytes/sector
%F8_256_128     = 22     ' 8",     256KB,  128 bytes/sector
%F3_200Mb_512   = 23     ' 3.5",   200M Floppy (HiFD)
%F3_240M_512    = 24     ' 3.5",   240Mb Floppy (HiFD)
%F3_32M_512     = 25     ' 3.5",   32Mb Floppy

'//
'// Define the input buffer structure for the driver, when
'// it is called with IOCTL_DISK_FORMAT_TRACKS.
'//

' // Size = 20 bytes
TYPE FORMAT_PARAMETERS DWORD
   MediaType           AS LONG    ' MEDIA_TYPE
   StartCylinderNumber AS DWORD   ' DWORD
   EndCylinderNumber   AS DWORD   ' DWORD
   StartHeadNumber     AS DWORD   ' DWORD
   EndHeadNumber       AS DWORD   ' DWORD
END TYPE

'//
'// Define the BAD_TRACK_NUMBER type. An array of elements of this type is
'// returned by the driver on IOCTL_DISK_FORMAT_TRACKS requests, to indicate
'// what tracks were bad during formatting. The length of that array is
'// reported in the `Information' field of the I/O Status Block.
'//

'typedef WORD   BAD_TRACK_NUMBER;
'typedef WORD   *PBAD_TRACK_NUMBER;

'//
'// Define the input buffer structure for the driver, when
'// it is called with IOCTL_DISK_FORMAT_TRACKS_EX.
'//

' // Size = 28 bytes
TYPE FORMAT_EX_PARAMETERS
   MediaType           AS LONG    ' MEDIA_TYPE
   StartCylinderNumber AS DWORD   ' DWORD
   EndCylinderNumber   AS DWORD   ' DWORD
   StartHeadNumber     AS DWORD   ' DWORD
   EndHeadNumber       AS DWORD   ' DWORD
   FormatGapLength     AS WORD    ' WORD
   SectorsPerTrack     AS WORD    ' WORD
   SectorNumber(1)     AS WORD    ' WORD
   ' Note: We are using SectorNumber(1) instead of SectorNumber(0) to keep DWORD alignment
END TYPE


'//
'// The following structure is returned on an IOCTL_DISK_GET_DRIVE_GEOMETRY
'// request and an array of them is returned on an IOCTL_DISK_GET_MEDIA_TYPES
'// request.
'//

' // Size = 24 bytes
TYPE DISK_GEOMETRY   ' Must be 8 byte aligned
   Cylinders         AS QUAD    ' LARGE_INTEGER
   MediaType         AS LONG    ' MEDIA_TYPE
   TracksPerCylinder AS DWORD   ' DWORD
   SectorsPerTrack   AS DWORD   ' DWORD
   BytesPerSector    AS DWORD   ' DWORD
END TYPE

'//
'// This wmi guid returns a DISK_GEOMETRY structure
'//
'#define WMI_DISK_GEOMETRY_GUID         { 0x25007f51, 0x57c2, 0x11d1, { 0xa5, 0x28, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10 } }
$WMI_DISK_GEOMETRY_GUID = GUID$("{25007F51-57C2-11D1-A528-00A0C9062910}")

'//
'// The following structure is returned on an IOCTL_DISK_GET_PARTITION_INFO
'// and an IOCTL_DISK_GET_DRIVE_LAYOUT request.  It is also used in a request
'// to change the drive layout, IOCTL_DISK_SET_DRIVE_LAYOUT.
'//

' // Size = 32 bytes
TYPE PARTITION_INFORMATION   ' Must be 8 byte aligned
   StartingOffset      AS QUAD    ' LARGE_INTEGER
   PartitionLength     AS QUAD    ' LARGE_INTEGER
   HiddenSectors       AS DWORD   ' DWORD
   PartitionNumber     AS DWORD   ' DWORD
   PartitionType       AS BYTE    ' BYTE
   BootIndicator       AS BYTE    ' BOOLEAN
   RecognizedPartition AS BYTE    ' BOOLEAN
   RewritePartition    AS BYTE    ' BOOLEAN
   alignment__         AS DWORD   ' // To keep 8 byte alignment
END TYPE

'//
'// The following structure is used to change the partition type of a
'// specified disk partition using an IOCTL_DISK_SET_PARTITION_INFO
'// request.
'//

' // Size = 1 byte
TYPE SET_PARTITION_INFORMATION BYTE
   PartitionType AS BYTE
END TYPE

'//
'// The following structures is returned on an IOCTL_DISK_GET_DRIVE_LAYOUT
'// request and given as input to an IOCTL_DISK_SET_DRIVE_LAYOUT request.
'//

' // Size = 40 bytes
TYPE DRIVE_LAYOUT_INFORMATION DWORD
   PartitionCount    AS DWORD                   ' DWORD
   Signature         AS DWORD                   ' DWORD
   PartitionEntry(0) AS PARTITION_INFORMATION   ' PARTITION_INFORMATION PartitionEntry[1]
END TYPE

'//
'// The following structure is passed in on an IOCTL_DISK_VERIFY request.
'// The offset and length parameters are both given in bytes.
'//

' // Size = 16 bytes
TYPE VERIFY_INFORMATION QWORD   ' Must be 8 byte aligned
   StartingOffset AS QUAD    ' LARGE_INTEGER
   Length         AS DWORD   ' DWORD
END TYPE

'//
'// The following structure is passed in on an IOCTL_DISK_REASSIGN_BLOCKS
'// request.
'//

' // Size = 8 bytes
TYPE REASSIGN_BLOCKS DWORD FILL
   Reserved       AS WORD    ' WORD   Reserved
   Count          AS WORD    ' WORD   Count
   BlockNumber(0) AS DWORD   ' DWORD BlockNumber[1]
END TYPE

'//
'// The following structure is passed in on an IOCTL_DISK_REASSIGN_BLOCKS_EX
'// request.
'//

'#include <pshpack1.h>
' // Size = 12 bytes
TYPE REASSIGN_BLOCKS_EX BYTE
   Reserved       AS WORD   ' WORD   Reserved
   Count          AS WORD   ' WORD   Count
   BlockNumber(0) AS QUAD   ' LARGE_INTEGER BlockNumber[1]
END TYPE
'#include <poppack.h>


'#if(_WIN32_WINNT >= 0x500)

'//
'// Support for GUID Partition Table (GPT) disks.
'//

'//
'// There are currently two ways a disk can be partitioned. With a traditional
'// AT-style master boot record (PARTITION_STYLE_MBR) and with a new, GPT
'// partition table (PARTITION_STYLE_GPT). RAW is for an unrecognizable
'// partition style. There are a very limited number of things you can
'// do with a RAW partititon.
'//

' PARTITION_STYLE enum
%PARTITION_STYLE_MBR = 0
%PARTITION_STYLE_GPT = 1
%PARTITION_STYLE_RAW = 2

'//
'// The following structure defines information in a GPT partition that is
'// not common to both GPT and MBR partitions.
'//
#IF %DEF(%USEPBDECL)
TYPE PARTITION_INFORMATION_GPT
    PartitionType AS GUID          ' Partition type. See table 16-3.
    PartitionId   AS GUID          ' Unique GUID for this partition.
    Attributes    AS QUAD          ' See table 16-4.
    uName         AS STRING * 72   ' Partition Name in Unicode.
END TYPE
#ELSE
' // Size = 112 bytes
TYPE PARTITION_INFORMATION_GPT   ' Must be 8 byte aligned
   PartitionType AS GUID            ' GUID // Partition type. See table 16-3.
   PartitionId   AS GUID            ' GUID // Unique GUID for this partition.
   Attributes    AS QUAD            ' DWORD64 // See table 16-4.
   Name          AS WSTRINGZ * 36   ' WCHAR Name [36] // Partition Name in Unicode.
END TYPE
#ENDIF

'//
'//  The following are GPT partition attributes applicable for any
'//  partition type. These attributes are not OS-specific
'//

'#define GPT_ATTRIBUTE_PLATFORM_REQUIRED             (0x0000000000000001)
%GPT_ATTRIBUTE_PLATFORM_REQUIRED          = &H0000000000000001&&

'//
'// The following are GPT partition attributes applicable when the
'// PartitionType is PARTITION_BASIC_DATA_GUID.
'//

'#define GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER    (0x8000000000000000)
'#define GPT_BASIC_DATA_ATTRIBUTE_HIDDEN             (0x4000000000000000)
'#define GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY        (0x2000000000000000)
'#define GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY          (0x1000000000000000)

%GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER = &H8000000000000000&&
%GPT_BASIC_DATA_ATTRIBUTE_HIDDEN          = &H4000000000000000&&
%GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY     = &H2000000000000000&&
%GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY       = &H1000000000000000&&

'//
'// The following structure defines information in an MBR partition that is not
'// common to both GPT and MBR partitions.
'//

' // Size = 8 bytes
TYPE PARTITION_INFORMATION_MBR DWORD FILL
   PartitionType       AS BYTE    ' BYTE
   BootIndicator       AS BYTE    ' BOOLEAN
   RecognizedPartition AS BYTE    ' BOOLEAN
   HiddenSectors       AS DWORD   ' DWORD
END TYPE

'//
'// The structure SET_PARTITION_INFO_EX is used with the ioctl
'// IOCTL_SET_PARTITION_INFO_EX to set information about a specific
'// partition. Note that for MBR partitions, you can only set the partition
'// signature, whereas GPT partitions allow setting of all fields that
'// you can get.
'//

'typedef SET_PARTITION_INFORMATION SET_PARTITION_INFORMATION_MBR;
'typedef PARTITION_INFORMATION_GPT SET_PARTITION_INFORMATION_GPT;


'typedef struct _SET_PARTITION_INFORMATION_EX {
'    PARTITION_STYLE PartitionStyle;
'    union {
'        SET_PARTITION_INFORMATION_MBR Mbr;
'        SET_PARTITION_INFORMATION_GPT Gpt;
'    };
'} SET_PARTITION_INFORMATION_EX, *PSET_PARTITION_INFORMATION_EX;

' // Size = 1 byte
TYPE SET_PARTITION_INFORMATION_MBR BYTE
   SET_PARTITION_INFORMATION
END TYPE

' // Size = 112 bytes
TYPE SET_PARTITION_INFORMATION_GPT
   PARTITION_INFORMATION_GPT
END TYPE

' // Size = 112 bytes
UNION SPIMSPIGunion DWORD
   Mbr AS SET_PARTITION_INFORMATION_MBR
   Gpt AS SET_PARTITION_INFORMATION_GPT
END UNION

' // Size = 120 bytes
TYPE SET_PARTITION_INFORMATION_EX QWORD   ' Must be 8 byte aligned
   PartitionStyle AS LONG  ' PARTITION_STYLE
   SPIMSPIGunion
END TYPE

'//
'// The structure CREATE_DISK_GPT with the ioctl IOCTL_DISK_CREATE_DISK
'// to initialize an virgin disk with an empty GPT partition table.
'//

' // Size = 20 bytes
TYPE CREATE_DISK_GPT DWORD
   DiskId            AS GUID          ' GUID  // Unique disk id for the disk.
   MaxPartitionCount AS DWORD         ' DWORD // Maximim number of partitions allowable.
END TYPE

'//
'// The structure CREATE_DISK_MBR with the ioctl IOCTL_DISK_CREATE_DISK
'// to initialize an virgin disk with an empty MBR partition table.
'//

'typedef struct _CREATE_DISK_MBR {
'    DWORD Signature;
'} CREATE_DISK_MBR, *PCREATE_DISK_MBR;

'typedef struct _CREATE_DISK {
'    PARTITION_STYLE PartitionStyle;
'    union {
'        CREATE_DISK_MBR Mbr;
'        CREATE_DISK_GPT Gpt;
'    };
'} CREATE_DISK, *PCREATE_DISK;

' // Size = 4 bytes
TYPE CREATE_DISK_MBR DWORD
   Signature AS DWORD
END TYPE

' // Size = 20 bytes
UNION CREATE_DISK_UNION DWORD
   Mbr AS CREATE_DISK_MBR
   Gpt AS CREATE_DISK_GPT
END UNION

' // Size = 24 bytes
TYPE CREATE_DISK DWORD
   PartitionStyle AS LONG  ' PARTITION_STYLE
   CREATE_DISK_UNION
END TYPE


'//
'// The structure GET_LENGTH_INFORMATION is used with the ioctl
'// IOCTL_DISK_GET_LENGTH_INFO to obtain the length, in bytes, of the
'// disk, partition, or volume.
'//

' // Size = 8 bytes
TYPE GET_LENGTH_INFORMATION QWORD
   Length AS QUAD   ' LARGE_INTEGER
END TYPE

'//
'// The PARTITION_INFORMATION_EX structure is used with the
'// IOCTL_DISK_GET_DRIVE_LAYOUT_EX, IOCTL_DISK_SET_DRIVE_LAYOUT_EX,
'// IOCTL_DISK_GET_PARTITION_INFO_EX and IOCTL_DISK_GET_PARTITION_INFO_EX calls.
'//

'typedef struct _PARTITION_INFORMATION_EX {
'    PARTITION_STYLE PartitionStyle;
'    LARGE_INTEGER StartingOffset;
'    LARGE_INTEGER PartitionLength;
'    DWORD PartitionNumber;
'    BOOLEAN RewritePartition;
'    union {
'        PARTITION_INFORMATION_MBR Mbr;
'        PARTITION_INFORMATION_GPT Gpt;
'    };
'} PARTITION_INFORMATION_EX, *PPARTITION_INFORMATION_EX;

' // Size = 112 bytes
UNION PARTITION_INFORMATION_EX_UNION DWORD
   Mbr AS PARTITION_INFORMATION_MBR
   Gpt AS PARTITION_INFORMATION_GPT
END UNION

' // Size = 144 bytes
TYPE PARTITION_INFORMATION_EX QWORD FILL  ' Must be 8 byte aligned
   PartitionStyle   AS LONG  ' PARTITION_STYLE
   StartingOffset   AS QUAD
   PartitionLength  AS QUAD
   PartitionNumber  AS DWORD
   RewritePartition AS BYTE
   PARTITION_INFORMATION_EX_UNION
END TYPE

'//
'// GPT specific drive layout information.
'//

' // Size = 40 bytes
TYPE DRIVE_LAYOUT_INFORMATION_GPT QWORD   ' Must be 8 byte aligned
   DiskId               AS GUID    ' GUID
   StartingUsableOffset AS QUAD    ' LARGE_INTEGER
   UsableLength         AS QUAD    ' LARGE_INTEGER
   MaxPartitionCount    AS DWORD   ' DWORD
END TYPE

'//
'// MBR specific drive layout information.
'//

' // Size = 4 bytes
TYPE DRIVE_LAYOUT_INFORMATION_MBR DWORD
   Signature AS DWORD
END TYPE

'//
'// The structure DRIVE_LAYOUT_INFORMATION_EX is used with the
'// IOCTL_SET_DRIVE_LAYOUT_EX and IOCTL_GET_DRIVE_LAYOUT_EX calls.
'//

'typedef struct _DRIVE_LAYOUT_INFORMATION_EX {
'    DWORD PartitionStyle;
'    DWORD PartitionCount;
'    union {
'        DRIVE_LAYOUT_INFORMATION_MBR Mbr;
'        DRIVE_LAYOUT_INFORMATION_GPT Gpt;
'    };
'    PARTITION_INFORMATION_EX PartitionEntry[1];
'} DRIVE_LAYOUT_INFORMATION_EX, *PDRIVE_LAYOUT_INFORMATION_EX;

' // Size = 40 bytes
UNION DRIVE_LAYOUT_INFORMATION_EX_UNION DWORD
   Mbr AS DRIVE_LAYOUT_INFORMATION_MBR
   Gpt AS DRIVE_LAYOUT_INFORMATION_GPT
END UNION

' // Size = 192 bytes
TYPE DRIVE_LAYOUT_INFORMATION_EX DWORD
   PartitionStyle AS DWORD
   PartitionCount AS DWORD
   DRIVE_LAYOUT_INFORMATION_EX_UNION
   PartitionEntry(0) AS PARTITION_INFORMATION_EX
END TYPE

'#endif // (_WIN32_WINNT >= 0x0500)


'#if(_WIN32_WINNT >= 0x0500)

'//
'// The DISK_GEOMETRY_EX structure is returned on issuing an
'// IOCTL_DISK_GET_DRIVE_GEOMETRY_EX ioctl.
'//

' DETECTION_TYPE enum
%DetectNone    = 0
%DetectInt13   = 1
%DetectExInt13 = 2

' // Size = 16 bytes
TYPE DISK_INT13_INFO DWORD FILL
   DriveSelect     AS WORD
   MaxCylinders    AS DWORD
   SectorsPerTrack AS WORD
   MaxHeads        AS WORD
   NumberDrives    AS WORD
   alignment__     AS WORD
END TYPE

' // Size = 32 bytes
TYPE DISK_EX_INT13_INFO QWORD FILL  ' Must be 8 byte aligned
   ExBufferSize      AS WORD
   ExFlags           AS WORD
   ExCylinders       AS DWORD
   ExHeads           AS DWORD
   ExSectorsPerTrack AS DWORD
   ExSectorsPerDrive AS QUAD    ' DWORD64
   ExSectorSize      AS WORD
   ExReserved        AS WORD
   alignment__       AS DWORD
END TYPE

'typedef struct _DISK_DETECTION_INFO {
'        DWORD SizeOfDetectInfo;
'        DETECTION_TYPE DetectionType;
'        union {
'                struct {

'                        //
'                        // If DetectionType == DETECTION_INT13 then we have just the Int13
'                        // information.
'                        //

'                        DISK_INT13_INFO Int13;

'                        //
'                        // If DetectionType == DETECTION_EX_INT13, then we have the
'                        // extended int 13 information.
'                        //

'                        DISK_EX_INT13_INFO ExInt13;     // If DetectionType == DetectExInt13
'                };
'        };
'} DISK_DETECTION_INFO, *PDISK_DETECTION_INFO;

' // Size = 56 bytes
TYPE DISK_DETECTION_INFO DWORD
   SizeOfDetectInfo AS DWORD
   DetectionType    AS LONG                ' DETECTION_TYPE
   Int13            AS DISK_INT13_INFO
   ExInt13          AS DISK_EX_INT13_INFO  ' If DetectionType == DetectExInt13
END TYPE


'typedef struct _DISK_PARTITION_INFO {
'        DWORD SizeOfPartitionInfo;
'        PARTITION_STYLE PartitionStyle;                 // PartitionStyle = RAW, GPT or MBR
'        union {
'                struct {                                                        // If PartitionStyle == MBR
'                        DWORD Signature;                                // MBR Signature
'                        DWORD CheckSum;                                 // MBR CheckSum
'                } Mbr;
'                struct {                                                        // If PartitionStyle == GPT
'                        GUID DiskId;
'                } Gpt;
'        };
'} DISK_PARTITION_INFO, *PDISK_PARTITION_INFO;

' // Size = 8 bytes
TYPE DISK_PARTITION_INFO_UNION_MBR DWORD
   Signature AS DWORD   ' MBR Signature
   CheckSum  AS DWORD   ' MBR CheckSum
END TYPE

' // Size = 16 bytes
TYPE DISK_PARTITION_INFO_UNION_GPT DWORD
   DiskId AS GUID
END TYPE

' // Size = 16 bytes
UNION DISK_PARTITION_INFO_UNION DWORD
   Mbr AS DISK_PARTITION_INFO_UNION_MBR
   Gpt AS DISK_PARTITION_INFO_UNION_GPT
END UNION

' // Size = 24 bytes
TYPE DISK_PARTITION_INFO DWORD
   SizeOfPartitionInfo AS DWORD
   PartitionStyle      AS LONG   ' PARTITION_STYLE ( = RAW, GPT or MBR)
   DISK_PARTITION_INFO_UNION
END TYPE

'//
'// The Geometry structure is a variable length structure composed of a
'// DISK_GEOMETRY_EX structure followed by a DISK_PARTITION_INFO structure
'// followed by a DISK_DETECTION_DATA structure.
'//

'#if (NTDDI_VERSION < NTDDI_WIN2003)
'#define DiskGeometryGetPartition(Geometry)\
'                        ((PDISK_PARTITION_INFO)((Geometry)+1))

'#define DiskGeometryGetDetect(Geometry)\
'                        ((PDISK_DETECTION_INFO)(((PBYTE)DiskGeometryGetPartition(Geometry)+\
'                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
'#else
'#define DiskGeometryGetPartition(Geometry)\
'                        ((PDISK_PARTITION_INFO)((Geometry)->Data))

'#define DiskGeometryGetDetect(Geometry)\
'                        ((PDISK_DETECTION_INFO)(((DWORD_PTR)DiskGeometryGetPartition(Geometry)+\
'                                        DiskGeometryGetPartition(Geometry)->SizeOfPartitionInfo)))
'#endif

UNION DISK_GEOMETRY_EX_DISKSIZE_UNION
   DiskSize AS QUAD            ' LARGE_INTEGER // Must always be correct
   ' // For compatibility with the PB declares
   qDiskSize AS QUAD           ' LARGE_INTEGER // Must always be correct
END UNION

UNION DISK_GEOMETRY_EX_DATA_UNION
   Data(0)  AS BYTE            ' BYTE  Data[1] // Partition, Detect info
   ' // For compatibility with the PB declares
   bData(0)  AS BYTE           ' BYTE  Data[1] // Partition, Detect info
END UNION

' // Size = 40 bytes
TYPE DISK_GEOMETRY_EX QWORD  ' Must be 8 byte aligned
   Geometry AS DISK_GEOMETRY   ' DISK_GEOMETRY // Standard disk geometry: may be faked by driver.
   DISK_GEOMETRY_EX_DISKSIZE_UNION
   DISK_GEOMETRY_EX_DATA_UNION
END TYPE

'#endif // (_WIN32_WINNT > 0x0500)

'#if(_WIN32_WINNT >= 0x0400)
'//
'// IOCTL_DISK_CONTROLLER_NUMBER returns the controller and disk
'// number for the handle.  This is used to determine if a disk
'// is attached to the primary or secondary IDE controller.
'//

' // Size = 8 bytes
TYPE DISK_CONTROLLER_NUMBER DWORD
   ControllerNumber AS DWORD
   DiskNumber       AS DWORD
END TYPE

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0500)


'//
'// IOCTL_DISK_SET_CACHE allows the caller to get or set the state of the disk
'// read/write caches.
'//
'// If the structure is provided as the input buffer for the ioctl the read &
'// write caches will be enabled or disabled depending on the parameters
'// provided.
'//
'// If the structure is provided as an output buffer for the ioctl the state
'// of the read & write caches will be returned. If both input and outut buffers
'// are provided the output buffer will contain the cache state BEFORE any
'// changes are made
'//

' DISK_CACHE_RETENTION_PRIORITY enum
%EqualPriority      = 0
%KeepPrefetchedData = 1
%KeepReadData       = 2

'#if (OSVER(NTDDI_VERSION) == NTDDI_WINXP)
' enum DISK_WRITE_CACHE_STATE
%DiskWriteCacheNormal              = 0
%DiskWriteCacheForceDisable        = 1
%DiskWriteCacheDisableNotSupported = 2
'#endif

'typedef struct _DISK_CACHE_INFORMATION {

'    //
'    // on return indicates that the device is capable of saving any parameters
'    // in non-volatile storage.  On send indicates that the device should
'    // save the state in non-volatile storage.
'    //

'    BOOLEAN ParametersSavable;

'    //
'    // Indicates whether the write and read caches are enabled.
'    //

'    BOOLEAN ReadCacheEnabled;
'    BOOLEAN WriteCacheEnabled;

'    //
'    // Controls the likelyhood of data remaining in the cache depending on how
'    // it got there.  Data cached from a READ or WRITE operation may be given
'    // higher, lower or equal priority to data entered into the cache for other
'    // means (like prefetch)
'    //

'    DISK_CACHE_RETENTION_PRIORITY ReadRetentionPriority;
'    DISK_CACHE_RETENTION_PRIORITY WriteRetentionPriority;

'    //
'    // Requests for a larger number of blocks than this may have prefetching
'    // disabled.  If this value is set to 0 prefetch will be disabled.
'    //

'    WORD   DisablePrefetchTransferLength;

'    //
'    // If TRUE then ScalarPrefetch (below) will be valid.  If FALSE then
'    // the minimum and maximum values should be treated as a block count
'    // (BlockPrefetch)
'    //

'    BOOLEAN PrefetchScalar;

'    //
'    // Contains the minimum and maximum amount of data which will be
'    // will be prefetched into the cache on a disk operation.  This value
'    // may either be a scalar multiplier of the transfer length of the request,
'    // or an abolute number of disk blocks.  PrefetchScalar (above) indicates
'    // which interpretation is used.
'    //

'    union {
'        struct {
'            WORD   Minimum;
'            WORD   Maximum;

'            //
'            // The maximum number of blocks which will be prefetched - useful
'            // with the scalar limits to set definite upper limits.
'            //

'            WORD   MaximumBlocks;
'        } ScalarPrefetch;

'        struct {
'            WORD   Minimum;
'            WORD   Maximum;
'        } BlockPrefetch;
'    };

'} DISK_CACHE_INFORMATION, *PDISK_CACHE_INFORMATION;

' // Size = 6 bytes
TYPE DISK_CACHE_INFORMATION_ScalarPrefetch WORD
   Minimum       AS WORD
   Maximum       AS WORD
   MaximumBlocks AS WORD
END TYPE

' // Size = 4 bytes
TYPE DISK_CACHE_INFORMATION_BlockPrefetch WORD
   Minimum       AS WORD
   Maximum       AS WORD
END TYPE

' // Size = 6 bytes
UNION DISK_CACHE_INFORMATION_UNION WORD
   ScalarPrefetch AS DISK_CACHE_INFORMATION_ScalarPrefetch
   BlockPrefetch  AS DISK_CACHE_INFORMATION_BlockPrefetch
END UNION

' // Size = 24 bytes
TYPE DISK_CACHE_INFORMATION WORD FILL
   ParametersSavable             AS BYTE
   ReadCacheEnabled              AS BYTE
   WriteCacheEnabled             AS BYTE
   ReadRetentionPriority         AS LONG  ' DISK_CACHE_RETENTION_PRIORITY
   WriteRetentionPriority        AS LONG  ' DISK_CACHE_RETENTION_PRIORITY
   DisablePrefetchTransferLength AS WORD
   PrefetchScalar                AS BYTE
   DISK_CACHE_INFORMATION_UNION
   alignment__                   AS WORD
END TYPE


'//
'// IOCTL_DISK_GROW_PARTITION will update the size of a partition
'// by adding sectors to the length. The number of sectors must be
'// predetermined by examining PARTITION_INFORMATION.
'//

' // Size = 16 bytes
TYPE DISK_GROW_PARTITION QWORD  ' Must be 8 byte aligned
   PartitionNumber AS DWORD   ' DWORD
   BytesToGrow     AS QUAD    ' LARGE_INTEGER
END TYPE
'#endif /* _WIN32_WINNT >= 0x0500 */

'///////////////////////////////////////////////////////
'//                                                   //
'// The following structures define disk performance  //
'// statistics: specifically the locations of all the //
'// reads and writes which have occured on the disk.  //
'//                                                   //
'// To use these structures, you must issue an IOCTL_ //
'// DISK_HIST_STRUCTURE (with a DISK_HISTOGRAM) to    //
'// obtain the basic histogram information. The       //
'// number of buckets which must allocated is part of //
'// this structure. Allocate the required number of   //
'// buckets and call an IOCTL_DISK_HIST_DATA to fill  //
'// in the data                                       //
'//                                                   //
'///////////////////////////////////////////////////////

%HIST_NO_OF_BUCKETS = 24

' // Size = 8 bytes
TYPE HISTOGRAM_BUCKET DWORD
   Reads  AS DWORD
   Writes AS DWORD
END TYPE

%HISTOGRAM_BUCKET_SIZE = 8  ' SIZEOF(HISTOGRAM_BUCKET)

#IF %DEF(%USEPBDECL)
TYPE DISK_HISTOGRAM
    qDiskSize     AS QUAD
    qStart        AS QUAD
    qEnd          AS QUAD
    qAverage      AS QUAD
    qAverageRead  AS QUAD
    qAverageWrite AS QUAD
    qGranularity  AS DWORD
    qSize         AS DWORD
    qReadCount    AS DWORD
    qWriteCount   AS DWORD
    qHistogram    AS HISTOGRAM_BUCKET PTR
END TYPE
#ELSE
' // Size = 72 bytes
TYPE DISK_HISTOGRAM   ' Must be 8 byte aligned
   DiskSize     AS QUAD                   ' LARGE_INTEGER
   Start        AS QUAD                   ' LARGE_INTEGER
   End_         AS QUAD                   ' LARGE_INTEGER
   Average      AS QUAD                   ' LARGE_INTEGER
   AverageRead  AS QUAD                   ' LARGE_INTEGER
   AverageWrite AS QUAD                   ' LARGE_INTEGER
   Granularity  AS DWORD                  ' DWORD
   Size         AS DWORD                  ' DWORD
   ReadCount    AS DWORD                  ' DWORD
   WriteCount   AS DWORD                  ' DWORD
   Histogram    AS HISTOGRAM_BUCKET PTR   ' PHISTOGRAM_BUCKET
   alignment__  AS DWORD
END TYPE
#ENDIF

'#define DISK_HISTOGRAM_SIZE sizeof(DISK_HISTOGRAM)
%DISK_HISTOGRAM_SIZE = 68  ' SIZEOF(DISK_HISTOGRAM)


'///////////////////////////////////////////////////////
'//                                                   //
'// The following structures define disk debugging    //
'// capabilities. The IOCTLs are directed to one of   //
'// the two disk filter drivers.                      //
'//                                                   //
'// DISKPERF is a utilty for collecting disk request  //
'// statistics.                                       //
'//                                                   //
'// SIMBAD is a utility for injecting faults in       //
'// IO requests to disks.                             //
'//                                                   //
'///////////////////////////////////////////////////////

'//
'// The following structure is exchanged on an IOCTL_DISK_GET_PERFORMANCE
'// request. This ioctl collects summary disk request statistics used
'// in measuring performance.
'//

#IF %DEF(%USEPBDECL)
TYPE DISK_PERFORMANCE   ' Must be 8 byte aligned
   BytesRead           AS QUAD           ' LARGE_INTEGER
   BytesWritten        AS QUAD           ' LARGE_INTEGER
   ReadTime            AS QUAD           ' LARGE_INTEGER
   WriteTime           AS QUAD           ' LARGE_INTEGER
   IdleTime            AS QUAD           ' LARGE_INTEGER
   ReadCount           AS DWORD          ' DWORD
   WriteCount          AS DWORD          ' DWORD
   QueueDepth          AS DWORD          ' DWORD
   SplitCount          AS DWORD          ' DWORD
   QueryTime           AS QUAD           ' LARGE_INTEGER
   StorageDeviceNumber AS DWORD          ' DWORD
   alignment__         AS DWORD          ' // To keep 8 byte alignment
   StorageManagerName  AS STRINGZ * 16   ' WCHAR StorageManagerName[8]
END TYPE
#ELSE
' // Size = 88 bytes
TYPE DISK_PERFORMANCE   ' Must be 8 byte aligned
   BytesRead           AS QUAD           ' LARGE_INTEGER
   BytesWritten        AS QUAD           ' LARGE_INTEGER
   ReadTime            AS QUAD           ' LARGE_INTEGER
   WriteTime           AS QUAD           ' LARGE_INTEGER
   IdleTime            AS QUAD           ' LARGE_INTEGER
   ReadCount           AS DWORD          ' DWORD
   WriteCount          AS DWORD          ' DWORD
   QueueDepth          AS DWORD          ' DWORD
   SplitCount          AS DWORD          ' DWORD
   QueryTime           AS QUAD           ' LARGE_INTEGER
   StorageDeviceNumber AS DWORD          ' DWORD
   alignment__         AS DWORD          ' // To keep 8 byte alignment
   StorageManagerName  AS WSTRINGZ * 8   ' WCHAR StorageManagerName[8]
END TYPE
#ENDIF

'//
'// This structure defines the disk logging record. When disk logging
'// is enabled, one of these is written to an internal buffer for each
'// disk request.
'//

' // Size = 40 bytes
TYPE DISK_RECORD   ' Must be 8 byte aligned
   ByteOffset     AS QUAD    ' LARGE_INTEGER
   StartTime      AS QUAD    ' LARGE_INTEGER
   EndTime        AS QUAD    ' LARGE_INTEGER
   VirtualAddress AS DWORD   ' PVOID
   NumberOfBytes  AS DWORD   ' DWORD
   DeviceNumber   AS BYTE    ' BYTE
   ReadRequest    AS BYTE    ' BOOLEAN
   alignment(5)   AS BYTE    ' // To keep 8 byte alignment
END TYPE

'//
'// The following structure is exchanged on an IOCTL_DISK_LOG request.
'// Not all fields are valid with each function type.
'//

UNION DISK_LOGGING_UNION DWORD
   Function      AS BYTE    ' BYTE
   ' // For compatibility with the PB declares
   bFunction     AS BYTE    ' BYTE
END UNION

' // Size = 12 bytes
TYPE DISK_LOGGING DWORD
   DISK_LOGGING_UNION
   BufferAddress AS DWORD   ' PVOID
   BufferSize    AS DWORD   ' DWORD
END TYPE

'//
'// Disk logging functions
'//
'// Start disk logging. Only the Function and BufferSize fields are valid.
'//

%DISK_LOGGING_START  = 0

'//
'// Stop disk logging. Only the Function field is valid.
'//

%DISK_LOGGING_STOP   = 1

'//
'// Return disk log. All fields are valid. Data will be copied from internal
'// buffer to buffer specified for the number of bytes requested.
'//

%DISK_LOGGING_DUMP   = 2

'//
'// DISK BINNING
'//
'// DISKPERF will keep counters for IO that falls in each of these ranges.
'// The application determines the number and size of the ranges.
'// Joe Lin wanted me to keep it flexible as possible, for instance, IO
'// sizes are interesting in ranges like 0-4096, 4097-16384, 16385-65536, 65537+.
'//

%DISK_BINNING         = 3

'//
'// Bin types
'//

' BIN_TYPES enum
%RequestSize     = 0
%RequestLocation = 1

'//
'// Bin ranges
'//

' BIN_RANGE enum
' // Size = 16 bytes
TYPE BIN_RANGE QWORD
   StartValue AS QUAD
   Length     AS QUAD
END TYPE

'//
'// Bin definition
'//

' // Size = 24 bytes
TYPE PERF_BIN DWORD
   NumberOfBins  AS DWORD
   TypeOfBin     AS DWORD
   BinsRanges(0) AS BIN_RANGE
END TYPE

'//
'// Bin count
'//

' // Size = 24 bytes
TYPE BIN_COUNT   ' Must be 8 byte aligned
   BinRange    AS BIN_RANGE   ' BIN_RANGE
   BinCount    AS DWORD       ' DWORD
   alignment__ AS DWORD       ' // To keep 8 byte alignment
END TYPE

'//
'// Bin results
'//

' // Size = 32 bytes
TYPE BIN_RESULTS   ' Must be 8 byte aligned
   NumberOfBins AS DWORD       ' DWORD
   alignment__ AS DWORD       ' // To keep 8 byte alignment
   BinCounts(0) AS BIN_COUNT   ' BIN_COUNT
END TYPE

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Data structures for SMART drive fault prediction.
'//
'// GETVERSIONINPARAMS contains the data returned from the
'// Get Driver Version function.
'//

'#include <pshpack1.h>
' // Size = 24 bytes
TYPE GETVERSIONINPARAMS BYTE
   bVersion      AS BYTE    ' BYTE  // Binary driver version.
   bRevision     AS BYTE    ' BYTE  // Binary driver revision.
   bReserved     AS BYTE    ' BYTE  // Not used.
   bIDEDeviceMap AS BYTE    ' BYTE  // Bit map of IDE devices.
   fCapabilities AS DWORD   ' DWORD // Bit mask of driver capabilities.
   dwReserved(3) AS DWORD   ' DWORD dwReserved[4] // For future use.
END TYPE
'#include <poppack.h>

'//
'// Bits returned in the fCapabilities member of GETVERSIONINPARAMS
'//

%CAP_ATA_ID_CMD   = 1       ' // ATA ID command supported
%CAP_ATAPI_ID_CMD = 2       ' // ATAPI ID command supported
%CAP_SMART_CMD    = 4       ' // SMART commannds supported

'//
'// IDE registers
'//

'#include <pshpack1.h>
' // Size = 8 bytes
TYPE IDEREGS BYTE
   bFeaturesReg     AS BYTE   ' // Used for specifying SMART "commands".
   bSectorCountReg  AS BYTE   ' // IDE sector count register
   bSectorNumberReg AS BYTE   ' // IDE sector number register
   bCylLowReg       AS BYTE   ' // IDE low order cylinder value
   bCylHighReg      AS BYTE   ' // IDE high order cylinder value
   bDriveHeadReg    AS BYTE   ' // IDE drive/head register
   bCommandReg      AS BYTE   ' // Actual IDE command.
   bReserved        AS BYTE   ' // reserved for future use.  Must be zero.
END TYPE
'#include <poppack.h>

'//
'// Valid values for the bCommandReg member of IDEREGS.
'//

%ATAPI_ID_CMD   = &H0A1        ' // Returns ID sector for ATAPI.
%ID_CMD         = &H0EC        ' // Returns ID sector for ATA.
%SMART_CMD      = &H0B0        ' // Performs SMART cmd.
                               ' // Requires valid bFeaturesReg,
                               ' // bCylLowReg, and bCylHighReg

'//
'// Cylinder register defines for SMART command
'//

%SMART_CYL_LOW  = &H04F
%SMART_CYL_HI   = &H0C2

'//
'// SENDCMDINPARAMS contains the input parameters for the
'// Send Command to Drive function.
'//

'#include <pshpack1.h>
' // Size = 33 bytes
TYPE SENDCMDINPARAMS BYTE
   cBufferSize   AS DWORD     ' DWORD    // Buffer size in bytes
   irDriveRegs   AS IDEREGS   ' SIDEREGS // tructure with drive register values.
   bDriveNumber  AS BYTE      ' BYTE     // Physical drive number to send
                              ' command to (0,1,2,3).
   bReserved(2)  AS BYTE      ' BYTE bReserved[3] // Reserved for future expansion.
   dwReserved(3) AS DWORD     ' DWORD dwReserved[4] // For future use.
   bBuffer(0)    AS BYTE      ' BYTE bBuffer[1] // Input buffer.
END TYPE
'#include <poppack.h>

'//
'// Status returned from driver
'//

'#include <pshpack1.h>
' // Size = 12 bytes
TYPE DRIVERSTATUS BYTE
   bDriverError  AS BYTE    ' BYTE // Error code from driver,
                            '      // or 0 if no error.
   bIDEError     AS BYTE    ' BYTE // Contents of IDE Error register.
                            '      // Only valid when bDriverError
                            '      // is SMART_IDE_ERROR.
   bReserved(1)  AS BYTE    ' BYTE bReserved[2] // Reserved for future expansion.
   dwReserved(1) AS DWORD   ' DWORD dwReserved[2] // Reserved for future expansion.
END TYPE
'#include <poppack.h>

'//
'// bDriverError values
'//

%SMART_NO_ERROR         = 0       ' // No error
%SMART_IDE_ERROR        = 1       ' // Error from IDE controller
%SMART_INVALID_FLAG     = 2       ' // Invalid command flag
%SMART_INVALID_COMMAND  = 3       ' // Invalid command byte
%SMART_INVALID_BUFFER   = 4       ' // Bad buffer (null, invalid addr..)
%SMART_INVALID_DRIVE    = 5       ' // Drive number not valid
%SMART_INVALID_IOCTL    = 6       ' // Invalid IOCTL
%SMART_ERROR_NO_MEM     = 7       ' // Could not lock user's buffer
%SMART_INVALID_REGISTER = 8       ' // Some IDE Register not valid
%SMART_NOT_SUPPORTED    = 9       ' // Invalid cmd flag set
%SMART_NO_IDE_DEVICE    = 10      ' // Cmd issued to device not present
                                  ' // although drive number is valid

'//
'// SMART sub commands for execute offline diags
'//

%SMART_OFFLINE_ROUTINE_OFFLINE   = 0
%SMART_SHORT_SELFTEST_OFFLINE    = 1
%SMART_EXTENDED_SELFTEST_OFFLINE = 2
%SMART_ABORT_OFFLINE_SELFTEST    = 127
%SMART_SHORT_SELFTEST_CAPTIVE    = 129
%SMART_EXTENDED_SELFTEST_CAPTIVE = 130

'#include <pshpack1.h>
' // Size = 17 bytes
TYPE SENDCMDOUTPARAMS BYTE
   cBufferSize  AS DWORD           ' DWORD // Size of bBuffer in bytes
   DriverStatus AS DRIVERSTATUS    ' DRIVERSTATUS // Driver status structure.
   bBuffer(0) AS BYTE              ' BYTE bBuffer[1] // Buffer of arbitrary length in which to store the data read from the                                                                                  ' drive.
END TYPE
'#include <poppack.h>

%READ_ATTRIBUTE_BUFFER_SIZE = 512
%IDENTIFY_BUFFER_SIZE       = 512
%READ_THRESHOLD_BUFFER_SIZE = 512
%SMART_LOG_SECTOR_SIZE      = 512

'//
'// Feature register defines for SMART "sub commands"
'//

%READ_ATTRIBUTES             = &H0D0
%READ_THRESHOLDS             = &H0D1
%ENABLE_DISABLE_AUTOSAVE     = &H0D2
%SAVE_ATTRIBUTE_VALUES       = &H0D3
%EXECUTE_OFFLINE_DIAGS       = &H0D4
%SMART_READ_LOG              = &H0D5
%SMART_WRITE_LOG             = &H0D6
%ENABLE_SMART                = &H0D8
%DISABLE_SMART               = &H0D9
%RETURN_SMART_STATUS         = &H0DA
%ENABLE_DISABLE_AUTO_OFFLINE = &H0DB

'#endif /* _WIN32_WINNT >= 0x0400 */

#ENDIF   ' // _NTDDDISK_H_

%IOCTL_CHANGER_BASE      = %FILE_DEVICE_CHANGER

%IOCTL_CHANGER_GET_PARAMETERS             = &H00304000???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0000, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_GET_STATUS                 = &H00304004???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_GET_PRODUCT_DATA           = &H00304008???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_SET_ACCESS                 = &H0030C010???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_CHANGER_GET_ELEMENT_STATUS         = &H0030C014???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0005, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS  = &H00304018???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_SET_POSITION               = &H0030401C???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0007, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_EXCHANGE_MEDIUM            = &H00304020???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0008, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_MOVE_MEDIUM                = &H00304024???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x0009, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_REINITIALIZE_TRANSPORT     = &H00304028???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x000A, METHOD_BUFFERED, FILE_READ_ACCESS)
%IOCTL_CHANGER_QUERY_VOLUME_TAGS          = &H0030C02C???  ' CTL_CODE(IOCTL_CHANGER_BASE, 0x000B, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

%MAX_VOLUME_ID_SIZE       = 36
%MAX_VOLUME_TEMPLATE_SIZE = 40

%VENDOR_ID_LENGTH         =  8
%PRODUCT_ID_LENGTH        = 16
%REVISION_LENGTH          =  4
%SERIAL_NUMBER_LENGTH     = 32

'//
'// Common structures describing elements.
'//

' ELEMENT_TYPE enum
%AllElements       = 0 ' // As defined by SCSI
%ChangerTransport  = 1 ' // As defined by SCSI
%ChangerSlot       = 2 ' // As defined by SCSI
%ChangerIEPort     = 3 ' // As defined by SCSI
%ChangerDrive      = 4 ' // As defined by SCSI
%ChangerDoor       = 5 ' // Front panel, used to access internal of cabinet.
%ChangerKeypad     = 6 ' // Keypad/input on front panel.
%ChangerMaxElement = 7 ' // Placeholder only. Not a valid type.

' // Size = 8 bytes
TYPE CHANGER_ELEMENT DWORD
   ElementType    AS LONG    ' ELEMENT_TYPE
   ElementAddress AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE CHANGER_ELEMENT_LIST DWORD
   Element          AS CHANGER_ELEMENT
   NumberOfElements AS DWORD
END TYPE

'//
'// Definitions for  IOCTL_CHANGER_GET_PARAMETERS
'//

'//
'// Definitions for Features0 of GET_CHANGER_PARAMETERS
'//

%CHANGER_BAR_CODE_SCANNER_INSTALLED  = &H000000001??? ' The medium-changer has a bar code scanner installed.
%CHANGER_INIT_ELEM_STAT_WITH_RANGE   = &H000000002??? ' The medium-changer has the ability to initialize elements within a specified range.
%CHANGER_CLOSE_IEPORT                = &H000000004??? ' The medium-changer has the ability to close the i/e port door.
%CHANGER_OPEN_IEPORT                 = &H000000008??? ' The medium-changer can open the i/e port door.

%CHANGER_STATUS_NON_VOLATILE         = &H000000010??? ' The medium-changer uses non-volatile memory for element status information.
%CHANGER_EXCHANGE_MEDIA              = &H000000020??? ' The medium-changer supports exchange operations.
%CHANGER_CLEANER_SLOT                = &H000000040??? ' The medium-changer has a fixed slot designated for cleaner cartridges.
%CHANGER_LOCK_UNLOCK                 = &H000000080??? ' The medium-changer can be (un)secured to (allow)prevent media removal.

%CHANGER_CARTRIDGE_MAGAZINE          = &H000000100??? ' The medium-changer uses cartridge magazines for some storage slots.
%CHANGER_MEDIUM_FLIP                 = &H000000200??? ' The medium-changer can flip medium.
%CHANGER_POSITION_TO_ELEMENT         = &H000000400??? ' The medium-changer can position the transport to a particular element.
%CHANGER_REPORT_IEPORT_STATE         = &H000000800??? ' The medium-changer can determine whether media is present
                                                      ' in the IE Port.

%CHANGER_STORAGE_DRIVE               = &H000001000??? ' The medium-changer can use a drive as an independent storage element.
%CHANGER_STORAGE_IEPORT              = &H000002000??? ' The medium-changer can use a i/e port as an independent storage element.
%CHANGER_STORAGE_SLOT                = &H000004000??? ' The medium-changer can use a slot as an independent storage element.
%CHANGER_STORAGE_TRANSPORT           = &H000008000??? ' The medium-changer can use a transport as an independent storage element.

%CHANGER_DRIVE_CLEANING_REQUIRED     = &H000010000??? ' The drives controlled by the medium changer require periodic cleaning
                                                      ' initiated by an application.
%CHANGER_PREDISMOUNT_EJECT_REQUIRED  = &H000020000??? ' The medium-changer requires a drive eject command to be issued, before a changer
                                                      ' move / exchange command can be issued to the drive.

%CHANGER_CLEANER_ACCESS_NOT_VALID    = &H000040000??? ' The access bit in GES isn't valid for cleaner cartridges.
%CHANGER_PREMOUNT_EJECT_REQUIRED     = &H000080000??? ' The medium-changer requires a drive eject command to be issued
                                                      ' before a move / exchange command can be issued with the drive as src/dst.

%CHANGER_VOLUME_IDENTIFICATION       = &H000100000??? ' The medium-changer supports volume identification.
%CHANGER_VOLUME_SEARCH               = &H000200000??? ' The medium-changer can search for volume information.
%CHANGER_VOLUME_ASSERT               = &H000400000??? ' The medium-changer can verify volume information.
%CHANGER_VOLUME_REPLACE              = &H000800000??? ' The medium-changer can replace volume information.
%CHANGER_VOLUME_UNDEFINE             = &H001000000??? ' The medium-changer can undefine volume information.

%CHANGER_SERIAL_NUMBER_VALID         = &H004000000??? ' The serial number reported in GetProductData is valid
                                                      ' and unique.

%CHANGER_DEVICE_REINITIALIZE_CAPABLE = &H008000000??? ' The medium-changer can be issued a ChangerReinitializeUnit.
%CHANGER_KEYPAD_ENABLE_DISABLE       = &H010000000??? ' Indicates that the keypad can be enabled/disabled.
%CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS  = &H020000000??? ' Drives must be empty before access via the door is possible.

%CHANGER_RESERVED_BIT                = &H080000000??? ' Will be used to indicate Features1 capability bits.

'//
'// Definitions for Features1 of GET_CHANGER_PARAMETERS
'//

%CHANGER_PREDISMOUNT_ALIGN_TO_SLOT   = &H080000001??? ' The transport must be prepositioned to the slot prior to ejecting the media.
%CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE  = &H080000002??? ' The transport must be prepositioned to the drive prior to ejecting the media.
%CHANGER_CLEANER_AUTODISMOUNT        = &H080000004??? ' The device will move the cleaner cartridge back into the slot when cleaning has completed.
%CHANGER_TRUE_EXCHANGE_CAPABLE       = &H080000008??? ' Device can do src -> dest2 exchanges.
%CHANGER_SLOTS_USE_TRAYS             = &H080000010??? ' Slots have removable trays, requiring multiple moves for inject/eject.
%CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR  = &H080000020??? ' Media must be returned to the slot from which it originated after a move to another element.
%CHANGER_CLEANER_OPS_NOT_SUPPORTED   = &H080000040??? ' Automated cleaning operations are not supported on this device.
%CHANGER_IEPORT_USER_CONTROL_OPEN    = &H080000080??? ' Indicates that user action is necessary to open a closed ieport.
%CHANGER_IEPORT_USER_CONTROL_CLOSE   = &H080000100??? ' Indicates that user action is necessary to close an opened ieport.
%CHANGER_MOVE_EXTENDS_IEPORT         = &H080000200??? ' Indicates that a move media to the ieport extends the tray.
%CHANGER_MOVE_RETRACTS_IEPORT        = &H080000400??? ' Indicates that a move media from the ieport retracts the tray.

'//
'// Definitions for MoveFrom, ExchangeFrom, and PositionCapabilities
'//

%CHANGER_TO_TRANSPORT    = &H01 ' // The device can carry out the operation to a transport from the specified element.
%CHANGER_TO_SLOT         = &H02 ' // The device can carry out the operation to a slot from the specified element.
%CHANGER_TO_IEPORT       = &H04 ' // The device can carry out the operation to an IE Port from the specified element.
%CHANGER_TO_DRIVE        = &H08 ' // The device can carry out the operation to a drive from the specified element.

'//
'// Definitions for LockUnlockCapabilities
'//

%LOCK_UNLOCK_IEPORT      = &H01 ' // The device can lock/unlock the ieport(s).
%LOCK_UNLOCK_DOOR        = &H02 ' // The device can lock/unlock the door(s).
%LOCK_UNLOCK_KEYPAD      = &H04 ' // The device can lock/unlock the keypad.

' // Size = 60 bytes
TYPE GET_CHANGER_PARAMETERS DWORD FILL
   ' // Size of the structure. Can be used for versioning.
   Size                       AS DWORD
   ' // Number of N element(s) as defined by the Element Address Page (or equivalent...).
   NumberTransportElements    AS WORD
   NumberStorageElements      AS WORD    ' // for data cartridges only
   NumberCleanerSlots         AS WORD    ' // for cleaner cartridges
   NumberIEElements           AS WORD
   NumberDataTransferElements AS WORD
   ' // Number of doors/front panels (allows user entry into the cabinet).
   NumberOfDoors              AS WORD
   ' // The device-specific address (from user manual of the device) of the first N element. Used
   ' // by the UI to relate the various elements to the user.
   FirstSlotNumber            AS WORD
   FirstDriveNumber           AS WORD
   FirstTransportNumber       AS WORD
   FirstIEPortNumber          AS WORD
   FirstCleanerSlotAddress    AS WORD
   ' // Indicates the capacity of each magazine, if they exist.
   MagazineSize               AS WORD
   ' // Specifies the approximate number of seconds for when a cleaning should be completed.
   ' // Only applicable if drive cleaning is supported. See Features0.
   DriveCleanTimeout          AS DWORD
   ' // See features bits, above.
   Features0                  AS DWORD
   Features1                  AS DWORD
   ' // Bitmask defining Move from N element to element. Defined by Device Capabilities Page (or equivalent).
   ' // AND-masking with the TO_XXX values will indicate legal destinations.
   MoveFromTransport          AS BYTE
   MoveFromSlot               AS BYTE
   MoveFromIePort             AS BYTE
   MoveFromDrive              AS BYTE
   ' // Bitmask defining Exchange from N element to element. Defined by Device Capabilities Page (or equivalent).
   ' // AND-masking with the TO_XXX values will indicate legal destinations.
   ExchangeFromTransport      AS BYTE
   ExchangeFromSlot           AS BYTE
   ExchangeFromIePort         AS BYTE
   ExchangeFromDrive          AS BYTE
   ' // Bitmask defining which elements are capable of lock/unlock. Valid only if
   ' // CHANGER_LOCK_UNLOCK is set in Features0.
   LockUnlockCapabilities     AS BYTE
   ' // Bitmask defining which elements valid for positioning operations. Valid only if
   ' // CHANGER_POSITION_TO_ELEMENT is set in Features0.
   PositionCapabilities       AS BYTE
   ' // For future expansion.
   Reserved1(1)               AS BYTE    ' BYTE  Reserved1[2]
   Reserved2(1)               AS DWORD   ' DWORD Reserved2[2]
END TYPE


' // Size = 61 bytes
TYPE CHANGER_PRODUCT_DATA BYTE
   ' // Device manufacturer's name - based on inquiry data
   VendorId(%VENDOR_ID_LENGTH - 1) AS BYTE
   ' // Product identification as defined by the vendor - based on Inquiry data
   ProductId(%PRODUCT_ID_LENGTH - 1) AS BYTE
   ' // Product revision as defined by the vendor.
   Revision(%REVISION_LENGTH - 1) AS BYTE
   ' // Vendor unique value used to globally identify this device. Can
   ' // be from Vital Product Data, for example.
   SerialNumber(%SERIAL_NUMBER_LENGTH - 1) AS BYTE
   ' // Indicates device type of data transports, as defined by SCSI-2.
   DeviceType AS BYTE
END TYPE


'//
'// Definitions for IOCTL_CHANGER_SET_ACCESS
'//

%LOCK_ELEMENT   = 0
%UNLOCK_ELEMENT = 1
%EXTEND_IEPORT  = 2
%RETRACT_IEPORT = 3

UNION CHANGER_SET_ACCESS_CONTROL_UNION DWORD
   Control AS DWORD
   ' // For compatibility wirh the PB declares
   dControl AS DWORD
END UNION

' // Size = 12 bytes
TYPE CHANGER_SET_ACCESS DWORD
   ' // Element can be ChangerIEPort, ChangerDoor, ChangerKeypad
   Element AS CHANGER_ELEMENT
   ' // See above for possible operations.
   CHANGER_SET_ACCESS_CONTROL_UNION
END TYPE

'//
'// Definitions for IOCTL_CHANGER_GET_ELEMENT_STATUS
'//

'//
'// Input buffer.
'//

' // Size = 16 bytes
TYPE CHANGER_READ_ELEMENT_STATUS DWORD
   ' // List describing the elements and range on which to return information.
   ElementList   AS CHANGER_ELEMENT_LIST
   ' // Indicates whether volume tag information is to be returned.
   VolumeTagInfo AS BYTE
END TYPE

'//
'// Output buffer.
'//

' // Size = 100 bytes
TYPE CHANGER_ELEMENT_STATUS BYTE
   ' // Element to which this structure refers.
   Element           AS CHANGER_ELEMENT
   ' // Address of the element from which the media was originally moved.
   ' // Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
   ' // Needs to be converted to a zero-based offset from the device-unique value.
   SrcElementAddress AS CHANGER_ELEMENT
   ' // See below.
   Flags             AS DWORD
   ' // See below for possible values.
   ExceptionCode     AS DWORD
   ' // Scsi Target Id of this element.
   ' // Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
   TargetId          AS BYTE
   ' // LogicalUnitNumber of this element.
   ' // Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
   Lun               AS BYTE
   Reserved          AS WORD
   ' // Primary volume identification for the media.
   ' // Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
   PrimaryVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE
   ' // Alternate volume identification for the media.
   ' // Valid for two-sided media only, and pertains to the id. of the inverted side.
   ' // Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
   AlternateVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE
END TYPE

'//
'// Output buffer. This is same as CHANGER_ELEMENT_STATUS with
'// the addition of product info fields. New applications should
'// use this struct instead of the older CHANGER_ELEMENT_STATUS
'//

' // Size = 156 bytes
TYPE CHANGER_ELEMENT_STATUS_EX BYTE
   ' // Element to which this structure refers.
   Element           AS CHANGER_ELEMENT
   ' // Address of the element from which the media was originally moved.
   ' // Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
   ' // Needs to be converted to a zero-based offset from the device-unique value.
   SrcElementAddress AS CHANGER_ELEMENT
   ' // See below.
   Flags             AS DWORD
   ' // See below for possible values.
   ExceptionCode     AS DWORD
   ' // Scsi Target Id of this element.
   ' // Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
   TargetId          AS BYTE
   ' // LogicalUnitNumber of this element.
   ' // Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
   Lun               AS BYTE
   Reserved          AS WORD
   ' // Primary volume identification for the media.
   ' // Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
   PrimaryVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE
   ' // Alternate volume identification for the media.
   ' // Valid for two-sided media only, and pertains to the id. of the inverted side.
   ' // Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
   AlternateVolumeID(%MAX_VOLUME_ID_SIZE - 1) AS BYTE
   ' // Vendor ID
   VendorIdentification(%VENDOR_ID_LENGTH - 1) AS BYTE
   ' // Product ID
   ProductIdentification(%PRODUCT_ID_LENGTH - 1) AS BYTE
   ' // Serial number
   SerialNumber(%SERIAL_NUMBER_LENGTH - 1) AS BYTE
END TYPE


'//
'// Possible flag values
'//

%ELEMENT_STATUS_FULL         = &H000000001???   ' // Element contains a unit of media.
%ELEMENT_STATUS_IMPEXP       = &H000000002???   ' // Media in i/e port was placed there by an operator.
%ELEMENT_STATUS_EXCEPT       = &H000000004???   ' // Element is in an abnormal state; check ExceptionCode field for more information.
%ELEMENT_STATUS_ACCESS       = &H000000008???   ' // Access to the i/e port from the medium changer is allowed.
%ELEMENT_STATUS_EXENAB       = &H000000010???   ' // Export of media is supported.
%ELEMENT_STATUS_INENAB       = &H000000020???   ' // Import of media is supported.

%ELEMENT_STATUS_PRODUCT_DATA = &H000000040???   ' // Serial number valid for the drive

%ELEMENT_STATUS_LUN_VALID    = &H000001000???   ' // Lun information is valid.
%ELEMENT_STATUS_ID_VALID     = &H000002000???   ' // SCSI Id information is valid.
%ELEMENT_STATUS_NOT_BUS      = &H000008000???   ' // Lun and SCSI Id fields are not on same bus as medium changer.
%ELEMENT_STATUS_INVERT       = &H000400000???   ' // Media in element was inverted (valid only if ELEMENT_STATUS_SVALID bit is set)
%ELEMENT_STATUS_SVALID       = &H000800000???   ' // SourceElementAddress field and ELEMENT_STATUS_INVERT bit are valid.

%ELEMENT_STATUS_PVOLTAG      = &H010000000???   ' // Primary volume information is valid.
%ELEMENT_STATUS_AVOLTAG      = &H020000000???   ' // Alternate volume information is v

'//
'// ExceptionCode values.
'//

%ERROR_LABEL_UNREADABLE      = &H000000001???   ' // Bar code scanner could not read bar code label.
%ERROR_LABEL_QUESTIONABLE    = &H000000002???   ' // Label could be invalid due to unit attention condition.
%ERROR_SLOT_NOT_PRESENT      = &H000000004???   ' // Slot is currently not addressable in the device.
%ERROR_DRIVE_NOT_INSTALLED   = &H000000008???   ' // Drive is not installed.
%ERROR_TRAY_MALFUNCTION      = &H000000010???   ' // Media tray is malfunctioning/broken.
%ERROR_INIT_STATUS_NEEDED    = &H000000011???   ' // An Initialize Element Status command is needed.
%ERROR_UNHANDLED_ERROR       = &H0FFFFFFFF???   ' // Unknown error condition

'//
'// Definitions for IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS
'//

' // Size = 16 bytes
TYPE CHANGER_INITIALIZE_ELEMENT_STATUS DWORD
   ' // List describing the elements and range on which to initialize.
   ElementList AS CHANGER_ELEMENT_LIST
   ' // Indicates whether a bar code scan should be used. Only applicable if
   ' // CHANGER_BAR_CODE_SCANNER_INSTALLED is set in Features0 of CHANGER_GET_PARAMETERS.
   BarCodeScan AS BYTE
END TYPE

'//
'// Definitions for IOCTL_CHANGER_SET_POSITION
'//

' // Size = 20 bytes
TYPE CHANGER_SET_POSITION DWORD
   ' // Indicates which transport to move.
   Transport   AS CHANGER_ELEMENT
   ' // Indicates the final destination of the transport.
   Destination AS CHANGER_ELEMENT
   ' // Indicates whether the media currently carried by Transport, should be flipped.
   Flip AS BYTE
END TYPE

'//
'// Definitions for IOCTL_CHANGER_EXCHANGE_MEDIUM
'//

' // Size = 36 bytes
TYPE CHANGER_EXCHANGE_MEDIUM
   ' // Indicates which transport to use for the exchange operation.
   Transport    AS CHANGER_ELEMENT
   ' // Indicates the source for the media that is to be moved.
   Source       AS CHANGER_ELEMENT
   ' // Indicates the final destination of the media originally at Source.
   Destination1 AS CHANGER_ELEMENT
   ' // Indicates the destination of the media moved from Destination1.
   Destination2 AS CHANGER_ELEMENT
   ' // Indicates whether the medium should be flipped.
   Flip1        AS BYTE
   Flip2        AS BYTE
   alignment__  AS WORD
END TYPE

'//
'// Definitions for IOCTL_CHANGER_MOVE_MEDIUM
'//

' // Size = 28 bytes
TYPE CHANGER_MOVE_MEDIUM DWORD
   ' // Indicates which transport to use for the move operation.
   Transport   AS CHANGER_ELEMENT
   ' // Indicates the source for the media that is to be moved.
   Source      AS CHANGER_ELEMENT
   ' // Indicates the destination of the media originally at Source.
   Destination AS CHANGER_ELEMENT
   ' // Indicates whether the media should be flipped.
   Flip        AS BYTE
END TYPE

'//
'// Definitions for IOCTL_QUERY_VOLUME_TAGS
'//

'//
'// Input buffer.
'//

' // Size = 52 bytes
TYPE CHANGER_SEND_VOLUME_TAG_INFORMATION DWORD
   ' // Describes the starting element for which to return information.
   StartingElement AS CHANGER_ELEMENT
   ' // Indicates the specific action to perform. See below.
   ActionCode      AS DWORD
   ' // Template used by the device to search for volume ids.
   VolumeIDTemplate(%MAX_VOLUME_TEMPLATE_SIZE - 1) AS BYTE
END TYPE

'//
'// Output buffer.
'//

' // Size = 104 bytes
TYPE READ_ELEMENT_ADDRESS_INFO DWORD
   ' // Number of elements matching criteria set forth by ActionCode.
   NumberOfElements AS DWORD
   ' // Array of CHANGER_ELEMENT_STATUS structures, one for each element that corresponded
   ' // with the information passed in with the CHANGER_SEND_VOLUME_TAG_INFORMATION structure.
   ElementStatus(0) AS CHANGER_ELEMENT_STATUS
END TYPE

'//
'// Possible ActionCode values. See Features0 of CHANGER_GET_PARAMETERS for compatibility with
'// the current device.
'//

%SEARCH_ALL         = &H00   ' // Translate - search all defined volume tags.
%SEARCH_PRIMARY     = &H01   ' // Translate - search only primary volume tags.
%SEARCH_ALTERNATE   = &H02   ' // Translate - search only alternate volume tags.
%SEARCH_ALL_NO_SEQ  = &H04   ' // Translate - search all defined volume tags but ignore sequence numbers.
%SEARCH_PRI_NO_SEQ  = &H05   ' // Translate - search only primary volume tags but ignore sequence numbers.
%SEARCH_ALT_NO_SEQ  = &H06   ' // Translate - search only alternate volume tags but ignore sequence numbers.

%ASSERT_PRIMARY     = &H08   ' // Assert - as the primary volume tag - if tag now undefined.
%ASSERT_ALTERNATE   = &H09   ' // Assert - as the alternate volume tag - if tag now undefined.

%REPLACE_PRIMARY    = &H0A   ' // Replace - the primary volume tag - current tag ignored.
%REPLACE_ALTERNATE  = &H0B   ' // Replace - the alternate volume tag - current tag ignored.

%UNDEFINE_PRIMARY   = &H0C   ' // Undefine - the primary volume tag - current tag ignored.
%UNDEFINE_ALTERNATE = &H0D   ' // Undefine - the alternate volume tag - current tag ignored.

'//
'// Changer diagnostic test related definitions
'//

' CHANGER_DEVICE_PROBLEM_TYPE enum
%DeviceProblemNone                 = 0
%DeviceProblemHardware             = 1
%DeviceProblemCHMError             = 2
%DeviceProblemDoorOpen             = 3
%DeviceProblemCalibrationError     = 4
%DeviceProblemTargetFailure        = 5
%DeviceProblemCHMMoveError         = 6
%DeviceProblemCHMZeroError         = 7
%DeviceProblemCartridgeInsertError = 8
%DeviceProblemPositionError        = 9
%DeviceProblemSensorError          = 10
%DeviceProblemCartridgeEjectError  = 11
%DeviceProblemGripperError         = 12
%DeviceProblemDriveError           = 13

%IOCTL_SERIAL_LSRMST_INSERT    = &H001B007C???  ' CTL_CODE(FILE_DEVICE_SERIAL_PORT,31,METHOD_BUFFERED,FILE_ANY_ACCESS)

%IOCTL_SERENUM_EXPOSE_HARDWARE = &H00370200???  ' CTL_CODE(FILE_DEVICE_SERENUM,128,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_REMOVE_HARDWARE = &H00370204???  ' CTL_CODE(FILE_DEVICE_SERENUM,129,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_PORT_DESC       = &H00370208???  ' CTL_CODE(FILE_DEVICE_SERENUM,130,METHOD_BUFFERED,FILE_ANY_ACCESS)
%IOCTL_SERENUM_GET_PORT_NAME   = &H0037020C???  ' CTL_CODE(FILE_DEVICE_SERENUM,131,METHOD_BUFFERED,FILE_ANY_ACCESS)

'//
'// The following values follow the escape designator in the
'// data stream if the LSRMST_INSERT mode has been turned on.
'//
%SERIAL_LSRMST_ESCAPE     = &H00?   ' ((BYTE )0x00)

'//
'// Following this value is the contents of the line status
'// register, and then the character in the RX hardware when
'// the line status register was encountered.
'//
%SERIAL_LSRMST_LSR_DATA   = &H01?   ' ((BYTE )0x01)

'//
'// Following this value is the contents of the line status
'// register.  No error character follows
'//
%SERIAL_LSRMST_LSR_NODATA = &H02?   ' ((BYTE )0x02)

'//
'// Following this value is the contents of the modem status
'// register.
'//
%SERIAL_LSRMST_MST        = &H03   ' ((BYTE )0x03)

'//
'// Bit values for FIFO Control Register
'//

%SERIAL_IOC_FCR_FIFO_ENABLE      = &H00000001???   ' ((DWORD)0x00000001)
%SERIAL_IOC_FCR_RCVR_RESET       = &H00000002???   ' ((DWORD)0x00000002)
%SERIAL_IOC_FCR_XMIT_RESET       = &H00000004???   ' ((DWORD)0x00000004)
%SERIAL_IOC_FCR_DMA_MODE         = &H00000008???   ' ((DWORD)0x00000008)
%SERIAL_IOC_FCR_RES1             = &H00000010???   ' ((DWORD)0x00000010)
%SERIAL_IOC_FCR_RES2             = &H00000020???   ' ((DWORD)0x00000020)
%SERIAL_IOC_FCR_RCVR_TRIGGER_LSB = &H00000040???   ' ((DWORD)0x00000040)
%SERIAL_IOC_FCR_RCVR_TRIGGER_MSB = &H00000080???   ' ((DWORD)0x00000080)

'//
'// Bit values for Modem Control Register
'//

%SERIAL_IOC_MCR_DTR              = &H00000001???   ' ((DWORD)0x00000001)
%SERIAL_IOC_MCR_RTS              = &H00000002???   ' ((DWORD)0x00000002)
%SERIAL_IOC_MCR_OUT1             = &H00000004???   ' ((DWORD)0x00000004)
%SERIAL_IOC_MCR_OUT2             = &H00000008???   ' ((DWORD)0x00000008)
%SERIAL_IOC_MCR_LOOP             = &H00000010???   ' ((DWORD)0x00000010)


#IF NOT %DEF(%FILESYSTEMFSCTL)
    %FILESYSTEMFSCTL = 1

'//
'// The following is a list of the native file system fsctls followed by
'// additional network file system fsctls.  Some values have been
'// decommissioned.
'//

%FSCTL_REQUEST_OPLOCK_LEVEL_1    = &H00090000???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  0, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_REQUEST_OPLOCK_LEVEL_2    = &H00090004???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  1, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_REQUEST_BATCH_OPLOCK      = &H00090008???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  2, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_ACKNOWLEDGE  = &H0009000C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  3, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPBATCH_ACK_CLOSE_PENDING = &H00090010???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  4, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_NOTIFY       = &H00090014???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  5, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_LOCK_VOLUME               = &H00090018???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  6, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_UNLOCK_VOLUME             = &H0009001C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  7, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_DISMOUNT_VOLUME           = &H00090020???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  8, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decommissioned fsctl value                                                           9
%FSCTL_IS_VOLUME_MOUNTED         = &H00090028???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_IS_PATHNAME_VALID         = &H0009002C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11, METHOD_BUFFERED, FILE_ANY_ACCESS) ' PATHNAME_BUFFER,
%FSCTL_MARK_VOLUME_DIRTY         = &H00090030???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decommissioned fsctl value                                                          13
%FSCTL_QUERY_RETRIEVAL_POINTERS  = &H0009003B???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_GET_COMPRESSION           = &H0009003C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SET_COMPRESSION           = &H0009C040???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
' decommissioned fsctl value                                                          17
' decommissioned fsctl value                                                          18
'%FSCTL_MARK_AS_SYSTEM_HIVE       = &H0009004F???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19,  METHOD_NEITHER, FILE_ANY_ACCESS) *** Renamed as FSCTL_SET_BOOTLOADER_ACCESSED in Windows 7 SDK
%FSCTL_SET_BOOTLOADER_ACCESSED   = &H0009004F???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_OPLOCK_BREAK_ACK_NO_2     = &H00090050???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_INVALIDATE_VOLUMES        = &H00090054???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_QUERY_FAT_BPB             = &H00090058???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FSCTL_QUERY_FAT_BPB_BUFFER
%FSCTL_REQUEST_FILTER_OPLOCK     = &H0009005C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_FILESYSTEM_GET_STATISTICS = &H00090060???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24, METHOD_BUFFERED, FILE_ANY_ACCESS) ' FILESYSTEM_STATISTICS
'#IF %WIN32_WINNT >= &H0400
%FSCTL_GET_NTFS_VOLUME_DATA      = &H00090064???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25, METHOD_BUFFERED, FILE_ANY_ACCESS) ' NTFS_VOLUME_DATA_BUFFER
%FSCTL_GET_NTFS_FILE_RECORD      = &H00090068???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26, METHOD_BUFFERED, FILE_ANY_ACCESS) ' NTFS_FILE_RECORD_INPUT_BUFFER, NTFS_FILE_RECORD_OUTPUT_BUFFER
%FSCTL_GET_VOLUME_BITMAP         = &H0009006F???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27,  METHOD_NEITHER, FILE_ANY_ACCESS) ' STARTING_LCN_INPUT_BUFFER, VOLUME_BITMAP_BUFFER
%FSCTL_GET_RETRIEVAL_POINTERS    = &H00090073???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28,  METHOD_NEITHER, FILE_ANY_ACCESS) ' STARTING_VCN_INPUT_BUFFER, RETRIEVAL_POINTERS_BUFFER
%FSCTL_MOVE_FILE                 = &H00090074???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' MOVE_FILE_DATA,
%FSCTL_IS_VOLUME_DIRTY           = &H00090078???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
' decomissioned fsctl value                                                           31
%FSCTL_ALLOW_EXTENDED_DASD_IO    = &H00090083???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER,  FILE_ANY_ACCESS)

'#endif /* _WIN32_WINNT >= 0x0400 */

'#IF %WIN32_WINNT >= &H0500
' decommissioned fsctl value                                                          33
' decommissioned fsctl value                                                          34
%FSCTL_FIND_FILES_BY_SID         = &H0009008F???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35, METHOD_NEITHER, FILE_ANY_ACCESS)
' decommissioned fsctl value                                                          36
' decommissioned fsctl value                                                          37
%FSCTL_SET_OBJECT_ID             = &H00090098???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' // FILE_OBJECTID_BUFFER
%FSCTL_GET_OBJECT_ID             = &H0009009C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39, METHOD_BUFFERED, FILE_ANY_ACCESS) ' // FILE_OBJECTID_BUFFER
%FSCTL_DELETE_OBJECT_ID          = &H000900A0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_SET_REPARSE_POINT         = &H000900A4???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' // REPARSE_DATA_BUFFER
%FSCTL_GET_REPARSE_POINT         = &H000900A8???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42, METHOD_BUFFERED, FILE_ANY_ACCESS) ' // REPARSE_DATA_BUFFER
%FSCTL_DELETE_REPARSE_POINT      = &H000900AC???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' // REPARSE_DATA_BUFFER
%FSCTL_ENUM_USN_DATA             = &H000900B3???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // MFT_ENUM_DATA
%FSCTL_SECURITY_ID_CHECK         = &H000940B7???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45,  METHOD_NEITHER, FILE_READ_DATA)  ' // BULK_SECURITY_TEST_DATA
%FSCTL_READ_USN_JOURNAL          = &H000900BB???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // READ_USN_JOURNAL_DATA, USN
%FSCTL_SET_OBJECT_ID_EXTENDED    = &H000900BC???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_CREATE_OR_GET_OBJECT_ID   = &H000900C0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48, METHOD_BUFFERED, FILE_ANY_ACCESS) ' // FILE_OBJECTID_BUFFER
%FSCTL_SET_SPARSE                = &H000900C4???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_SET_ZERO_DATA             = &H000980C8???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50, METHOD_BUFFERED, FILE_WRITE_DATA) ' // FILE_ZERO_DATA_INFORMATION
%FSCTL_QUERY_ALLOCATED_RANGES    = &H000940CF???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51,  METHOD_NEITHER, FILE_READ_DATA)  ' // FILE_ALLOCATED_RANGE_BUFFER, FILE_ALLOCATED_RANGE_BUFFER
%FSCTL_ENABLE_UPGRADE            = &H000980D0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 52, METHOD_BUFFERED, FILE_WRITE_DATA)
' decommissioned fsctl value                                                          52
%FSCTL_SET_ENCRYPTION            = &H000900D7???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // ENCRYPTION_BUFFER, DECRYPTION_STATUS_BUFFER
%FSCTL_ENCRYPTION_FSCTL_IO       = &H000900DB???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54,  METHOD_NEITHER, FILE_ANY_ACCESS)
%FSCTL_WRITE_RAW_ENCRYPTED       = &H000900DF???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55,  METHOD_NEITHER, FILE_SPECIAL_ACCESS) ' // ENCRYPTED_DATA_INFO, EXTENDED_ENCRYPTED_DATA_INFO
%FSCTL_READ_RAW_ENCRYPTED        = &H000900E3???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56,  METHOD_NEITHER, FILE_SPECIAL_ACCESS) ' // REQUEST_RAW_ENCRYPTED_DATA, ENCRYPTED_DATA_INFO, EXTENDED_ENCRYPTED_DATA_INFO
%FSCTL_CREATE_USN_JOURNAL        = &H000900E7???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // CREATE_USN_JOURNAL_DATA
%FSCTL_READ_FILE_USN_DATA        = &H000900EB???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // Read the Usn Record for a file
%FSCTL_WRITE_USN_CLOSE_RECORD    = &H000900EF???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59,  METHOD_NEITHER, FILE_ANY_ACCESS) ' // Generate Close Usn Record
%FSCTL_EXTEND_VOLUME             = &H000900F0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_QUERY_USN_JOURNAL         = &H000900F4???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 61, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_DELETE_USN_JOURNAL        = &H000900F8???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 62, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_MARK_HANDLE               = &H000900FC???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 63, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SIS_COPYFILE              = &H00090100???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 64, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_SIS_LINK_FILES            = &H0009C104???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
'%FSCTL_HSM_MSG                   = &H0009C108???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 66, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
'// decommissional fsctl value                                             66
'// decommissioned fsctl value                                             67
' decommissioned fsctl value                                                          67
'%FSCTL_HSM_DATA                  = &H0009C113???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 68, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
%FSCTL_RECALL_FILE               = &H00090117???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 69, METHOD_NEITHER, FILE_ANY_ACCESS)
' decommissioned fsctl value                                                          70
%FSCTL_READ_FROM_PLEX            = &H0009411E???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 71, METHOD_OUT_DIRECT, FILE_READ_DATA)
%FSCTL_FILE_PREFETCH             = &H00090120???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 72, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) ' // FILE_PREFETCH
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0600)
%FSCTL_MAKE_MEDIA_COMPATIBLE     = &H00098130???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 76, METHOD_BUFFERED, FILE_WRITE_DATA) // UDFS R/W
%FSCTL_SET_DEFECT_MANAGEMENT     = &H00098134???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 77, METHOD_BUFFERED, FILE_WRITE_DATA) // UDFS R/W
%FSCTL_QUERY_SPARING_INFO        = &H00090138???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 78, METHOD_BUFFERED, FILE_ANY_ACCESS) // UDFS R/W
%FSCTL_QUERY_ON_DISK_VOLUME_INFO = &H0009013C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 79, METHOD_BUFFERED, FILE_ANY_ACCESS) // C/UDFS
%FSCTL_SET_VOLUME_COMPRESSION_STATE = &H00090140???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 80, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) // VOLUME_COMPRESSION_STATE
'// decommissioned fsctl value                                                 80
%FSCTL_TXFS_MODIFY_RM            = &H00098144???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 81, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_QUERY_RM_INFORMATION = &H00094148???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 82, METHOD_BUFFERED, FILE_READ_DATA)  // TxF
'// decommissioned fsctl value                                                        83
%FSCTL_TXFS_ROLLFORWARD_REDO     = &H00098150???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 84, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_ROLLFORWARD_UNDO     = &H00098154???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 85, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_START_RM             = &H00098158???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 86, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_SHUTDOWN_RM          = &H0009815C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 87, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_READ_BACKUP_INFORMATION = &H00094160???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 88, METHOD_BUFFERED, FILE_READ_DATA)  // TxF
%FSCTL_TXFS_WRITE_BACKUP_INFORMATION = &H00098164???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 89, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_CREATE_SECONDARY_RM  = &H00098168???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 90, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_GET_METADATA_INFO    = &H0009416C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 91, METHOD_BUFFERED, FILE_READ_DATA)  // TxF
%FSCTL_TXFS_GET_TRANSACTED_VERSION = &H00094170???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 92, METHOD_BUFFERED, FILE_READ_DATA)  // TxF
''// decommissioned fsctl value                                                       93
%FSCTL_TXFS_SAVEPOINT_INFORMATION = &H00098178???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 94, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
%FSCTL_TXFS_CREATE_MINIVERSION   = &H0009817C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 95, METHOD_BUFFERED, FILE_WRITE_DATA) // TxF
''// decommissioned fsctl value                                                       96
''// decommissioned fsctl value                                                       97
''// decommissioned fsctl value                                                       98
%FSCTL_TXFS_TRANSACTION_ACTIVE   = &H0009418C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 99, METHOD_BUFFERED, FILE_READ_DATA)  // TxF
%FSCTL_SET_ZERO_ON_DEALLOCATION  = &H00090194???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 101, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
%FSCTL_SET_REPAIR                = &H00090198???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 102, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_GET_REPAIR                = &H0009019C???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 103, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_WAIT_FOR_REPAIR           = &H000901A0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 104, METHOD_BUFFERED, FILE_ANY_ACCESS)
'// decommissioned fsctl value                                                        105
%FSCTL_INITIATE_REPAIR           = &H000901A8???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 106, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_CSC_INTERNAL              = &H000901AF???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 107, METHOD_NEITHER, FILE_ANY_ACCESS) // CSC internal implementation
%FSCTL_SHRINK_VOLUME             = &H00090180???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 108, METHOD_BUFFERED, FILE_SPECIAL_ACCESS) // SHRINK_VOLUME_INFORMATION
%FSCTL_SET_SHORT_NAME_BEHAVIOR   = &H00090184???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 109, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_DFSR_SET_GHOST_HANDLE_STATE = &H00090188???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 110, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'//  Values 111 - 119 are reserved for FSRM.
'//

%FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES = &H000941E0???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 120, METHOD_BUFFERED, FILE_READ_DATA) // TxF
%FSCTL_TXFS_LIST_TRANSACTIONS    = &H000941E4???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 121, METHOD_BUFFERED, FILE_READ_DATA) // TxF
%FSCTL_QUERY_PAGEFILE_ENCRYPTION = &H000901E8???  ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 122, METHOD_BUFFERED, FILE_ANY_ACCESS)
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if (_WIN32_WINNT >= 0x0600)
%FSCTL_RESET_VOLUME_ALLOCATION_HINTS = &H000901EC???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 123, METHOD_BUFFERED, FILE_ANY_ACCESS)
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if (_WIN32_WINNT >= 0x0601)
%FSCTL_QUERY_DEPENDENT_VOLUME = &H000901F0???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 124, METHOD_BUFFERED, FILE_ANY_ACCESS)    // Dependency File System Filter
%FSCTL_SD_GLOBAL_CHANGE       = &H000901F4???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 125, METHOD_BUFFERED, FILE_ANY_ACCESS) // Update NTFS Security Descriptors
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if (_WIN32_WINNT >= 0x0600)
%FSCTL_TXFS_READ_BACKUP_INFORMATION2 = &H000901F8???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 126, METHOD_BUFFERED, FILE_ANY_ACCESS) // TxF
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if (_WIN32_WINNT >= 0x0601)
%FSCTL_LOOKUP_STREAM_FROM_CLUSTER = &H000901FC???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 127, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_TXFS_WRITE_BACKUP_INFORMATION2 = &H00090200???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 128, METHOD_BUFFERED, FILE_ANY_ACCESS) // TxF
%FSCTL_FILE_TYPE_NOTIFICATION = &H00090204???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 129, METHOD_BUFFERED, FILE_ANY_ACCESS)
'#endif

'//
'//  Values 130 - 130 are available
'//

'//
'//  Values 131 - 139 are reserved for FSRM.
'//

'//
'//  Values 131 - 139 are reserved for FSRM.
'//

'#if (_WIN32_WINNT >= 0x0601)
%FSCTL_GET_BOOT_AREA_INFO             = &H00090230???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 140, METHOD_BUFFERED, FILE_ANY_ACCESS) // BOOT_AREA_INFO
%FSCTL_GET_RETRIEVAL_POINTER_BASE     = &H00090234???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 141, METHOD_BUFFERED, FILE_ANY_ACCESS) // RETRIEVAL_POINTER_BASE
%FSCTL_SET_PERSISTENT_VOLUME_STATE    = &H00090239???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 142, METHOD_BUFFERED, FILE_ANY_ACCESS)  // FILE_FS_PERSISTENT_VOLUME_INFORMATION
%FSCTL_QUERY_PERSISTENT_VOLUME_STATE  = &H0009023C???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 143, METHOD_BUFFERED, FILE_ANY_ACCESS)  // FILE_FS_PERSISTENT_VOLUME_INFORMATION

%FSCTL_REQUEST_OPLOCK                 = &H00090240???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 144, METHOD_BUFFERED, FILE_ANY_ACCESS)

%FSCTL_CSV_TUNNEL_REQUEST             = &H00090244???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 145, METHOD_BUFFERED, FILE_ANY_ACCESS) // CSV_TUNNEL_REQUEST
%FSCTL_IS_CSV_FILE                    = &H00090248???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 146, METHOD_BUFFERED, FILE_ANY_ACCESS) // IS_CSV_FILE

%FSCTL_QUERY_FILE_SYSTEM_RECOGNITION  = &H0009024C???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 147, METHOD_BUFFERED, FILE_ANY_ACCESS) //
%FSCTL_CSV_GET_VOLUME_PATH_NAME       = &H00090250???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 148, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_CSV_GET_VOLUME_NAME_FOR_VOLUME_MOUNT_POINT = &H00090254???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 149, METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_CSV_GET_VOLUME_PATH_NAMES_FOR_VOLUME_NAME = &H00090258???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 150,  METHOD_BUFFERED, FILE_ANY_ACCESS)
%FSCTL_IS_FILE_ON_CSV_VOLUME          = &H0009025C???   ' CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 151,  METHOD_BUFFERED, FILE_ANY_ACCESS)

'#endif /* _WIN32_WINNT >= 0x0601 */

%FSCTL_MARK_AS_SYSTEM_HIVE           = %FSCTL_SET_BOOTLOADER_ACCESSED

'#endif /* _WIN32_WINNT >= 0x0600 */

'// end_ntifs
'// begin_ntddk
'//
'// AVIO IOCTLS.
'//

' Note: FILE_DEVICE_AVIO isn't defined anywhere.
'#define IOCTL_AVIO_ALLOCATE_STREAM      CTL_CODE(FILE_DEVICE_AVIO, 1, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
'#define IOCTL_AVIO_FREE_STREAM          CTL_CODE(FILE_DEVICE_AVIO, 2, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
'#define IOCTL_AVIO_MODIFY_STREAM        CTL_CODE(FILE_DEVICE_AVIO, 3, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

'// end_ntddk

'// begin_ntifs

'#if(_WIN32_WINNT >= 0x0601)

'//
'// Structure for FSCTL_IS_CSV_FILE
'//

' // Size = 24 bytes
TYPE CSV_NAMESPACE_INFO   ' Must be 8 byte aligned
   Version        AS DWORD   ' DWORD
   DeviceNumber   AS DWORD   ' DWORD
   StartingOffset AS QUAD    ' LARGE_INTEGER
   SectorSize     AS DWORD   ' DWORD
   alignment__    AS DWORD   ' // To keep 8 byte alignment
END TYPE

'#define CSV_NAMESPACE_INFO_V1 (sizeof(CSV_NAMESPACE_INFO))
%CSV_INVALID_DEVICE_NUMBER = &HFFFFFFFF???

'#endif /* _WIN32_WINNT >= 0x0601 */

'//
'// The following long list of structs are associated with the preceeding
'// file system fsctls.
'//

'//
'// Structure for FSCTL_IS_PATHNAME_VALID
'//

' // Size = 8 bytes
TYPE PATHNAME_BUFFER DWORD
   PathNameLength AS DWORD          ' DWORD PathNameLength
   Name           AS WSTRINGZ * 1   ' WCHAR Name[1]
END TYPE

'//
'// Structure for FSCTL_QUERY_BPB_INFO
'//

'typedef struct _FSCTL_QUERY_FAT_BPB_BUFFER {

'    BYTE  First0x24BytesOfBootSector[0x24];

'} FSCTL_QUERY_FAT_BPB_BUFFER, *PFSCTL_QUERY_FAT_BPB_BUFFER;

' // Size = 36 bytes
TYPE FSCTL_QUERY_FAT_BPB_BUFFER BYTE
   First0x24BytesOfBootSector(&H24 - 1) AS BYTE
END TYPE

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Structures for FSCTL_GET_NTFS_VOLUME_DATA.
'// The user must pass the basic buffer below.  Ntfs
'// will return as many fields as available in the extended
'// buffer which follows immediately after the VOLUME_DATA_BUFFER.
'//

' // Size = 96 bytes
TYPE NTFS_VOLUME_DATA_BUFFER   ' Must be 8 byte aligned
   VolumeSerialNumber           AS QUAD    ' LARGE_INTEGER
   NumberSectors                AS QUAD    ' LARGE_INTEGER
   TotalClusters                AS QUAD    ' LARGE_INTEGER
   FreeClusters                 AS QUAD    ' LARGE_INTEGER
   TotalReserved                AS QUAD    ' LARGE_INTEGER
   BytesPerSector               AS DWORD   ' DWORD
   BytesPerCluster              AS DWORD   ' DWORD
   BytesPerFileRecordSegment    AS DWORD   ' DWORD
   ClustersPerFileRecordSegment AS DWORD   ' DWORD
   MftValidDataLength           AS QUAD    ' LARGE_INTEGER
   MftStartLcn                  AS QUAD    ' LARGE_INTEGER
   Mft2StartLcn                 AS QUAD    ' LARGE_INTEGER
   MftZoneStart                 AS QUAD    ' LARGE_INTEGER
   MftZoneEnd                   AS QUAD    ' LARGE_INTEGER
END TYPE

' // Size = 8 bytes
TYPE NTFS_EXTENDED_VOLUME_DATA   ' Must be DWORD aligned
   ByteCount    AS DWORD
   MajorVersion AS WORD
   MinorVersion AS WORD
END TYPE

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Structure for FSCTL_GET_VOLUME_BITMAP
'//

' // Size = 8 bytes
TYPE STARTING_LCN_INPUT_BUFFER QWORD
   StartingLcn AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 24 bytes
TYPE VOLUME_BITMAP_BUFFER QWORD   ' Must be 8 byte aligned
   StartingLcn AS QUAD   ' LARGE_INTEGER
   BitmapSize  AS QUAD   ' LARGE_INTEGER
   Buffer(0)   AS BYTE   ' BYTE  Buffer[1]
END TYPE

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Structure for FSCTL_GET_RETRIEVAL_POINTERS
'//

' // Size = 8 bytes
TYPE STARTING_VCN_INPUT_BUFFER QWORD
   StartingVcn AS QUAD   ' LARGE_INTEGER
END TYPE

'typedef struct RETRIEVAL_POINTERS_BUFFER {

'    DWORD ExtentCount;
'    LARGE_INTEGER StartingVcn;
'    struct {
'        LARGE_INTEGER NextVcn;
'        LARGE_INTEGER Lcn;
'    } Extents[1];

'} RETRIEVAL_POINTERS_BUFFER, *PRETRIEVAL_POINTERS_BUFFER;

' // Size = 16 bytes
TYPE RETRIEVAL_POINTERS_BUFFER_Extents QWORD
   NextVcn AS QUAD
   Lcn     AS QUAD
END TYPE

' // Size = 32 bytes
TYPE RETRIEVAL_POINTERS_BUFFER QWORD   ' Must be 8 byte aligned
   ExtentCount AS DWORD
   StartingVcn AS QUAD
   Extents(0)  AS RETRIEVAL_POINTERS_BUFFER_Extents
END TYPE

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Structures for FSCTL_GET_NTFS_FILE_RECORD
'//

' // Size = 8 bytes
TYPE NTFS_FILE_RECORD_INPUT_BUFFER QWORD
   FileReferenceNumber AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 16 bytes
TYPE NTFS_FILE_RECORD_OUTPUT_BUFFER   ' Must be 8 byte aligned
   FileReferenceNumber AS QUAD    ' LARGE_INTEGER
   FileRecordLength    AS DWORD   ' DWORD
   FileRecordBuffer(3) AS BYTE    ' BYTE  FileRecordBuffer[1]
   ' Note: We are using FileRecordBuffer(3) instead of FileRecordBuffer(0) to keep 8 byte alignment
END TYPE

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0400)
'//
'// Structure for FSCTL_MOVE_FILE
'//

' // Size = 32 bytes
TYPE MOVE_FILE_DATA QWORD  ' Must be 8 byte aligned
   FileHandle   AS DWORD   ' HANDLE
   StartingVcn  AS QUAD    ' LARGE_INTEGER
   StartingLcn  AS QUAD    ' LARGE_INTEGER
   ClusterCount AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE MOVE_FILE_RECORD_DATA QWORD   ' Must be 8 byte aligned
   FileHandle       AS DWORD   ' HANDLE
   SourceFileRecord AS QUAD    ' LARGE_INTEGER
   TargetFileRecord AS QUAD    ' LARGE_INTEGER
END TYPE

'#if defined(_WIN64)
'//
'//  32/64 Bit thunking support structure
'//

'typedef struct _MOVE_FILE_DATA32 {

'    UINT32 FileHandle;
'    LARGE_INTEGER StartingVcn;
'    LARGE_INTEGER StartingLcn;
'    DWORD ClusterCount;

'} MOVE_FILE_DATA32, *PMOVE_FILE_DATA32;
'#endif
'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structures for FSCTL_FIND_FILES_BY_SID
'//

' // Size = 16 bytes
TYPE FIND_BY_SID_DATA DWORD
   Restart AS DWORD   ' DWORD
   FindSid AS SID     ' SID Sid
END TYPE

' // Size = 16 bytes
TYPE FIND_BY_SID_OUTPUT DWORD
   NextEntryOffset AS DWORD          ' DWORD
   FileIndex       AS DWORD          ' DWORD
   FileNameLength  AS DWORD          ' DWORD
   FileName        AS WSTRINGZ * 2   ' WCHAR FileName[1]
   ' Note: We are using WSTRINGZ * 2 instead of WSTRINGZ * 1 to keep DWORD alignment
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'//  The following structures apply to Usn operations.
'//

'//
'// Structure for FSCTL_ENUM_USN_DATA
'//

' // Size = 24 bytes
TYPE MFT_ENUM_DATA QWORD
   StartFileReferenceNumber AS QUAD   ' DWORDLONG
   LowUsn                   AS QUAD   ' USN
   HighUsn                  AS QUAD   ' USN
END TYPE

'//
'// Structure for FSCTL_CREATE_USN_JOURNAL
'//

' // Size = 16 bytes
TYPE CREATE_USN_JOURNAL_DATA QWORD
   MaximumSize     AS QUAD   ' DWORDLONG
   AllocationDelta AS QUAD   ' DWORDLONG
END TYPE

'//
'// Structure for FSCTL_READ_USN_JOURNAL
'//

UNION READ_USN_JOURNAL_DATA_TIMEOUT_UNION QWORD
   Timeout           AS QUAD    ' DWORDLONG
   ' // For compatibility with the PB declares
   qTimeout          AS QUAD    ' DWORDLONG
END UNION

' // Size = 40 bytes
TYPE READ_USN_JOURNAL_DATA QWORD FILL  ' Must be 8 byte aligned
   StartUsn          AS QUAD    ' USN
   ReasonMask        AS DWORD   ' DWORD
   ReturnOnlyOnClose AS DWORD   ' DWORD
   READ_USN_JOURNAL_DATA_TIMEOUT_UNION
   BytesToWaitFor    AS QUAD    ' DWORDLONG
   UsnJournalID      AS QUAD    ' DWORDLONG
END TYPE

'//
'//  The initial Major.Minor version of the Usn record will be 2.0.
'//  In general, the MinorVersion may be changed if fields are added
'//  to this structure in such a way that the previous version of the
'//  software can still correctly the fields it knows about.  The
'//  MajorVersion should only be changed if the previous version of
'//  any software using this structure would incorrectly handle new
'//  records due to structure changes.
'//
'//  The first update to this will force the structure to version 2.0.
'//  This will add the extended information about the source as
'//  well as indicate the file name offset within the structure.
'//
'//  The following structure is returned with these fsctls.
'//
'//      FSCTL_READ_USN_JOURNAL
'//      FSCTL_READ_FILE_USN_DATA
'//      FSCTL_ENUM_USN_DATA
'//

' // Size = 64 bytes
TYPE USN_RECORD   ' Must be 8 byte aligned
   RecordLength              AS DWORD          ' DWORD
   MajorVersion              AS WORD           ' WORD
   MinorVersion              AS WORD           ' WORD
   FileReferenceNumber       AS QUAD           ' DWORDLONG
   ParentFileReferenceNumber AS QUAD           ' DWORDLONG
   Usn                       AS QUAD           ' USN
   TimeStamp                 AS QUAD           ' LARGE_INTEGER
   Reason                    AS DWORD          ' DWORD
   SourceInfo                AS DWORD          ' DWORD
   SecurityId                AS DWORD          ' DWORD
   FileAttributes            AS DWORD          ' DWORD
   FileNameLength            AS WORD           ' WORD
   FileNameOffset            AS WORD           ' WORD
   FileName                  AS WSTRINGZ * 2   ' WCHAR FileName[1]
   ' Note: We are using WSTRINGZ * 2 instead of WSTRINGZ * 1 to keep 8 byte alignment
END TYPE

%USN_PAGE_SIZE                    = &H01000

%USN_REASON_DATA_OVERWRITE        = &H000000001???
%USN_REASON_DATA_EXTEND           = &H000000002???
%USN_REASON_DATA_TRUNCATION       = &H000000004???
%USN_REASON_NAMED_DATA_OVERWRITE  = &H000000010???
%USN_REASON_NAMED_DATA_EXTEND     = &H000000020???
%USN_REASON_NAMED_DATA_TRUNCATION = &H000000040???
%USN_REASON_FILE_CREATE           = &H000000100???
%USN_REASON_FILE_DELETE           = &H000000200???
%USN_REASON_EA_CHANGE             = &H000000400???
%USN_REASON_SECURITY_CHANGE       = &H000000800???
%USN_REASON_RENAME_OLD_NAME       = &H000001000???
%USN_REASON_RENAME_NEW_NAME       = &H000002000???
%USN_REASON_INDEXABLE_CHANGE      = &H000004000???
%USN_REASON_BASIC_INFO_CHANGE     = &H000008000???
%USN_REASON_HARD_LINK_CHANGE      = &H000010000???
%USN_REASON_COMPRESSION_CHANGE    = &H000020000???
%USN_REASON_ENCRYPTION_CHANGE     = &H000040000???
%USN_REASON_OBJECT_ID_CHANGE      = &H000080000???
%USN_REASON_REPARSE_POINT_CHANGE  = &H000100000???
%USN_REASON_STREAM_CHANGE         = &H000200000???
%USN_REASON_TRANSACTED_CHANGE     = &H000400000???
%USN_REASON_CLOSE                 = &H080000000???

'//
'//  Structure for FSCTL_QUERY_USN_JOUNAL
'//

' // Size = 56 bytes
TYPE USN_JOURNAL_DATA QWORD
   UsnJournalID    AS QUAD  ' DWORDLONG
   FirstUsn        AS QUAD  ' USN
   NextUsn         AS QUAD  ' USN
   LowestValidUsn  AS QUAD  ' USN
   MaxUsn          AS QUAD  ' USN
   MaximumSize     AS QUAD  ' DWORDLONG
   AllocationDelta AS QUAD  ' DWORDLONG
END TYPE

'//
'//  Structure for FSCTL_DELETE_USN_JOURNAL
'//

' // Size = 16 bytes
TYPE DELETE_USN_JOURNAL_DATA QWORD
   UsnJournalID AS QUAD    ' DWORDLONG
   DeleteFlags  AS DWORD   ' DWORD
END TYPE

%USN_DELETE_FLAG_DELETE = &H00000001???
%USN_DELETE_FLAG_NOTIFY = &H00000002???

%USN_DELETE_VALID_FLAGS = &H00000003???

'//
'//  Structure for FSCTL_MARK_HANDLE
'//

' // Size = 12 bytes
TYPE MARK_HANDLE_INFO DWORD
   UsnSourceInfo AS DWORD   ' DWORD
   VolumeHandle  AS DWORD   ' HANDLE
   HandleInfo    AS DWORD   ' DWORD
END TYPE

'#if defined(_WIN64)
'//
'//  32/64 Bit thunking support structure
'//

'typedef struct {

'    DWORD UsnSourceInfo;
'    UINT32 VolumeHandle;
'    DWORD HandleInfo;

'} MARK_HANDLE_INFO32, *PMARK_HANDLE_INFO32;
'#endif

'//
'//  Flags for the additional source information above.
'//
'//      USN_SOURCE_DATA_MANAGEMENT - Service is not modifying the external view
'//          of any part of the file.  Typical case is HSM moving data to
'//          and from external storage.
'//
'//      USN_SOURCE_AUXILIARY_DATA - Service is not modifying the external view
'//          of the file with regard to the application that created this file.
'//          Can be used to add private data streams to a file.
'//
'//      USN_SOURCE_REPLICATION_MANAGEMENT - Service is modifying a file to match
'//          the contents of the same file which exists in another member of the
'//          replica set.
'//

%USN_SOURCE_DATA_MANAGEMENT         = &H00000001???
%USN_SOURCE_AUXILIARY_DATA          = &H00000002???
%USN_SOURCE_REPLICATION_MANAGEMENT  = &H00000004???

'//
'//  Flags for the HandleInfo field above
'//
'//  MARK_HANDLE_PROTECT_CLUSTERS - disallow any defragmenting (FSCTL_MOVE_FILE) until the
'//      the handle is closed
'//
'//  MARK_HANDLE_TXF_SYSTEM_LOG - indicates that this stream is being used as the Txf
'//      log for an RM on the volume.  Must be called in the kernel using
'//      IRP_MN_KERNEL_CALL.
'//
'//  MARK_HANDLE_NOT_TXF_SYSTEM_LOG - indicates that this user is no longer using this
'//      object as a log file.
'//

%MARK_HANDLE_PROTECT_CLUSTERS       = &H00000001???
%MARK_HANDLE_TXF_SYSTEM_LOG         = &H00000004???
%MARK_HANDLE_NOT_TXF_SYSTEM_LOG     = &H00000008???

'#if (_WIN32_WINNT >= 0x0601)

%MARK_HANDLE_REALTIME                = &H00000020???
%MARK_HANDLE_NOT_REALTIME            = &H00000040???

%NO_8DOT3_NAME_PRESENT               = &H00000001???
%REMOVED_8DOT3_NAME                  = &H00000002???

%PERSISTENT_VOLUME_STATE_SHORT_NAME_CREATION_DISABLED = &H00000001???

'#endif /* _WIN32_WINNT >= 0x0601 */

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structure for FSCTL_SECURITY_ID_CHECK
'//

' // Size = 8 bytes
TYPE BULK_SECURITY_TEST_DATA DWORD
   DesiredAccess  AS ACCESS_MASK   ' ACCESS_MASK
   SecurityIds(0) AS DWORD         ' DWORD SecurityIds[1]
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'//  Output flags for the FSCTL_IS_VOLUME_DIRTY
'//

%VOLUME_IS_DIRTY                 = &H00000001???
%VOLUME_UPGRADE_SCHEDULED        = &H00000002???
%VOLUME_SESSION_OPEN             = &H00000004???

'#endif /* _WIN32_WINNT >= 0x0500 */

'//
'// Structures for FSCTL_FILE_PREFETCH
'//

UNION FILE_PREFETCH_TYPE_UNION
   Type        AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   dType       AS DWORD   ' DWORD
END UNION

' // Size = 16 bytes
TYPE FILE_PREFETCH QWORD FILL   ' Must be 8 byte aligned
   FILE_PREFETCH_TYPE_UNION
   Count       AS DWORD   ' DWORD
   Prefetch(0) AS QUAD    ' DWORDLONG Prefetch[1]
END TYPE

' // Size = 24 bytes
TYPE FILE_PREFETCH_EX QWORD FILL   ' Must be 8 byte aligned
   Type        AS DWORD   ' DWORD
   Count       AS DWORD   ' DWORD
   Context     AS DWORD   ' PVOID
   Prefetch(0) AS QUAD    ' DWORDLONG Prefetch[1]
END TYPE

%FILE_PREFETCH_TYPE_FOR_CREATE     = &H1
%FILE_PREFETCH_TYPE_FOR_DIRENUM    = &H2
%FILE_PREFETCH_TYPE_FOR_CREATE_EX  = &H3
%FILE_PREFETCH_TYPE_FOR_DIRENUM_EX = &H4

%FILE_PREFETCH_TYPE_MAX            = &H4

'//
'// Structures for FSCTL_SET_VOLUME_COMPRESSION_STATE
'//
' *** Removed in Windows 7 SDK ***
'TYPE VOLUME_COMPRESSION_STATE
'   CompressNewFiles AS BYTE   ' BOOLEAN
'END TYPE

'// Structures for FSCTL_FILESYSTEM_GET_STATISTICS
'//
'// Filesystem performance counters
'//

' // Size = 56 bytes
TYPE FILESYSTEM_STATISTICS DWORD FILL
   FileSystemType          AS WORD
   Version                 AS WORD        ' // currently version 1
   SizeOfCompleteStructure AS DWORD       ' // must by a mutiple of 64 bytes
   UserFileReads           AS DWORD
   UserFileReadBytes       AS DWORD
   UserDiskReads           AS DWORD
   UserFileWrites          AS DWORD
   UserFileWriteBytes      AS DWORD
   UserDiskWrites          AS DWORD
   MetaDataReads           AS DWORD
   MetaDataReadBytes       AS DWORD
   MetaDataDiskReads       AS DWORD
   MetaDataWrites          AS DWORD
   MetaDataWriteBytes      AS DWORD
   MetaDataDiskWrites      AS DWORD
END TYPE

'// values for FS_STATISTICS.FileSystemType

%FILESYSTEM_STATISTICS_TYPE_NTFS  = 1
%FILESYSTEM_STATISTICS_TYPE_FAT   = 2
%FILESYSTEM_STATISTICS_TYPE_EXFAT = 3

'//
'//  File System Specific Statistics Data
'//

' // Size = 36 bytes
TYPE FAT_STATISTICS DWORD
   CreateHits          AS DWORD   ' DWORD
   SuccessfulCreates   AS DWORD   ' DWORD
   FailedCreates       AS DWORD   ' DWORD
   NonCachedReads      AS DWORD   ' DWORD
   NonCachedReadBytes  AS DWORD   ' DWORD
   NonCachedWrites     AS DWORD   ' DWORD
   NonCachedWriteBytes AS DWORD   ' DWORD
   NonCachedDiskReads  AS DWORD   ' DWORD
   NonCachedDiskWrites AS DWORD   ' DWORD
END TYPE

' // Size = 36 bytes
TYPE EXFAT_STATISTICS DWORD
   CreateHits          AS DWORD   ' DWORD
   SuccessfulCreates   AS DWORD   ' DWORD
   FailedCreates       AS DWORD   ' DWORD
   NonCachedReads      AS DWORD   ' DWORD
   NonCachedReadBytes  AS DWORD   ' DWORD
   NonCachedWrites     AS DWORD   ' DWORD
   NonCachedWriteBytes AS DWORD   ' DWORD
   NonCachedDiskReads  AS DWORD   ' DWORD
   NonCachedDiskWrites AS DWORD   ' DWORD
END TYPE

'typedef struct _NTFS_STATISTICS {

'    DWORD LogFileFullExceptions;
'    DWORD OtherExceptions;

'    //
'    // Other meta data io's
'    //

'    DWORD MftReads;
'    DWORD MftReadBytes;
'    DWORD MftWrites;
'    DWORD MftWriteBytes;
'    struct {
'        WORD   Write;
'        WORD   Create;
'        WORD   SetInfo;
'        WORD   Flush;
'    } MftWritesUserLevel;

'    WORD   MftWritesFlushForLogFileFull;
'    WORD   MftWritesLazyWriter;
'    WORD   MftWritesUserRequest;

'    DWORD Mft2Writes;
'    DWORD Mft2WriteBytes;
'    struct {
'        WORD   Write;
'        WORD   Create;
'        WORD   SetInfo;
'        WORD   Flush;
'    } Mft2WritesUserLevel;

'    WORD   Mft2WritesFlushForLogFileFull;
'    WORD   Mft2WritesLazyWriter;
'    WORD   Mft2WritesUserRequest;

'    DWORD RootIndexReads;
'    DWORD RootIndexReadBytes;
'    DWORD RootIndexWrites;
'    DWORD RootIndexWriteBytes;

'    DWORD BitmapReads;
'    DWORD BitmapReadBytes;
'    DWORD BitmapWrites;
'    DWORD BitmapWriteBytes;

'    WORD   BitmapWritesFlushForLogFileFull;
'    WORD   BitmapWritesLazyWriter;
'    WORD   BitmapWritesUserRequest;

'    struct {
'        WORD   Write;
'        WORD   Create;
'        WORD   SetInfo;
'    } BitmapWritesUserLevel;

'    DWORD MftBitmapReads;
'    DWORD MftBitmapReadBytes;
'    DWORD MftBitmapWrites;
'    DWORD MftBitmapWriteBytes;

'    WORD   MftBitmapWritesFlushForLogFileFull;
'    WORD   MftBitmapWritesLazyWriter;
'    WORD   MftBitmapWritesUserRequest;

'    struct {
'        WORD   Write;
'        WORD   Create;
'        WORD   SetInfo;
'        WORD   Flush;
'    } MftBitmapWritesUserLevel;

'    DWORD UserIndexReads;
'    DWORD UserIndexReadBytes;
'    DWORD UserIndexWrites;
'    DWORD UserIndexWriteBytes;

'    //
'    // Additions for NT 5.0
'    //

'    DWORD LogFileReads;
'    DWORD LogFileReadBytes;
'    DWORD LogFileWrites;
'    DWORD LogFileWriteBytes;

'    struct {
'        DWORD Calls;                // number of individual calls to allocate clusters
'        DWORD Clusters;             // number of clusters allocated
'        DWORD Hints;                // number of times a hint was specified

'        DWORD RunsReturned;         // number of runs used to satisify all the requests

'        DWORD HintsHonored;         // number of times the hint was useful
'        DWORD HintsClusters;        // number of clusters allocated via the hint
'        DWORD Cache;                // number of times the cache was useful other than the hint
'        DWORD CacheClusters;        // number of clusters allocated via the cache other than the hint
'        DWORD CacheMiss;            // number of times the cache wasn't useful
'        DWORD CacheMissClusters;    // number of clusters allocated without the cache
'    } Allocate;

'} NTFS_STATISTICS, *PNTFS_STATISTICS;

' // Size = 8 bytes
TYPE NTFS_STATISTICS_MftWritesUserLevel WORD
   Write   AS WORD
   Create  AS WORD
   SetInfo AS WORD
   Flush   AS WORD
END TYPE

' // Size = 8 bytes
TYPE NTFS_STATISTICS_Mft2WritesUserLevel WORD
   Write   AS WORD
   Create  AS WORD
   SetInfo AS WORD
   Flush   AS WORD
END TYPE

' // Size = 6 bytes
TYPE NTFS_STATISTICS_BitmapWritesUserLevel WORD
   Write   AS WORD
   Create  AS WORD
   SetInfo AS WORD
END TYPE

' // Size = 8 bytes
TYPE NTFS_STATISTICS_MftBitmapWritesUserLevel WORD
   Write   AS WORD
   Create  AS WORD
   SetInfo AS WORD
   Flush   AS WORD
END TYPE

' // Size = 40 bytes
TYPE NTFS_STATISTICS_Allocate DWORD
   Calls             AS DWORD   ' // number of individual calls to allocate clusters
   Clusters          AS DWORD   ' // number of clusters allocated
   Hints             AS DWORD   ' // number of times a hint was specified
   RunsReturned      AS DWORD   ' // number of runs used to satisify all the requests
   HintsHonored      AS DWORD   ' // number of times the hint was useful
   HintsClusters     AS DWORD   ' // number of clusters allocated via the hint
   Cache             AS DWORD   ' // number of times the cache was useful other than the hint
   CacheClusters     AS DWORD   ' // number of clusters allocated via the cache other than the hint
   CacheMiss         AS DWORD   ' // number of times the cache wasn't useful
   CacheMissClusters AS DWORD   ' // number of clusters allocated without the cache
END TYPE

' // Size = 212 bytes
TYPE NTFS_STATISTICS   ' Must be 4 byte aligned
   LogFileFullExceptions              AS DWORD
   OtherExceptions                    AS DWORD
   MftReads                           AS DWORD
   MftReadBytes                       AS DWORD
   MftWrites                          AS DWORD
   MftWriteBytes                      AS DWORD
   MftWritesUserLevel                 AS NTFS_STATISTICS_MftWritesUserLevel
   MftWritesFlushForLogFileFull       AS WORD
   MftWritesLazyWriter                AS WORD
   MftWritesUserRequest               AS WORD
   alignment1__                       AS WORD
   Mft2Writes                         AS DWORD
   Mft2WriteBytes                     AS DWORD
   Mft2WritesUserLevel                AS NTFS_STATISTICS_Mft2WritesUserLevel
   Mft2WritesFlushForLogFileFull      AS WORD
   Mft2WritesLazyWriter               AS WORD
   Mft2WritesUserRequest              AS WORD
   alignment2__                       AS WORD
   RootIndexReads                     AS DWORD
   RootIndexReadBytes                 AS DWORD
   RootIndexWrites                    AS DWORD
   RootIndexWriteBytes                AS DWORD
   BitmapReads                        AS DWORD
   BitmapReadBytes                    AS DWORD
   BitmapWrites                       AS DWORD
   BitmapWriteBytes                   AS DWORD
   BitmapWritesFlushForLogFileFull    AS WORD
   BitmapWritesLazyWriter             AS WORD
   BitmapWritesUserRequest            AS WORD
   BitmapWritesUserLevel              AS NTFS_STATISTICS_BitmapWritesUserLevel
   MftBitmapReads                     AS DWORD
   MftBitmapReadBytes                 AS DWORD
   MftBitmapWrites                    AS DWORD
   MftBitmapWriteBytes                AS DWORD
   MftBitmapWritesFlushForLogFileFull AS WORD
   MftBitmapWritesLazyWriter          AS WORD
   MftBitmapWritesUserRequest         AS WORD
   alignment3__                       AS WORD
   MftBitmapWritesUserLevel           AS NTFS_STATISTICS_MftBitmapWritesUserLevel
   UserIndexReads                     AS DWORD
   UserIndexReadBytes                 AS DWORD
   UserIndexWrites                    AS DWORD
   UserIndexWriteBytes                AS DWORD
   LogFileReads                       AS DWORD
   LogFileReadBytes                   AS DWORD
   LogFileWrites                      AS DWORD
   LogFileWriteBytes                  AS DWORD
   Allocate                           AS NTFS_STATISTICS_Allocate
END TYPE

'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structure for FSCTL_SET_OBJECT_ID, FSCTL_GET_OBJECT_ID, and FSCTL_CREATE_OR_GET_OBJECT_ID
'//

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable:4201)       // unnamed struct

'typedef struct _FILE_OBJECTID_BUFFER {

'    //
'    //  This is the portion of the object id that is indexed.
'    //

'    BYTE  ObjectId[16];

'    //
'    //  This portion of the object id is not indexed, it's just
'    //  some metadata for the user's benefit.
'    //

'    union {
'        struct {
'            BYTE  BirthVolumeId[16];
'            BYTE  BirthObjectId[16];
'            BYTE  DomainId[16];
'        } DUMMYSTRUCTNAME;
'        BYTE  ExtendedInfo[48];
'    } DUMMYUNIONNAME;

'} FILE_OBJECTID_BUFFER, *PFILE_OBJECTID_BUFFER;

'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning( default : 4201 )
'#endif

' // Size = 48 bytes
TYPE FILE_OBJECTID_BUFFER_inner BYTE
   BirthVolumeId(15) AS BYTE
   BirthObjectId(15) AS BYTE
   DomainId(15)      AS BYTE
END TYPE

' // Size = 48 bytes
UNION FILE_OBJECTID_BUFFER_union BYTE
   FILE_OBJECTID_BUFFER_inner
   ExtendedInfo(47) AS BYTE
END UNION

' // Size = 64 bytes
TYPE FILE_OBJECTID_BUFFER BYTE
   ObjectId(15) AS BYTE
   FILE_OBJECTID_BUFFER_union
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */


'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structure for FSCTL_SET_SPARSE
'//

' // Size = 1 byte
TYPE FILE_SET_SPARSE_BUFFER BYTE
   SetSparse AS BYTE   ' BOOLEAN
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */


'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structure for FSCTL_SET_ZERO_DATA
'//

' // Size = 16 bytes
TYPE FILE_ZERO_DATA_INFORMATION QWORD
   FileOffset      AS QUAD   ' LARGE_INTEGER
   BeyondFinalZero AS QUAD   ' LARGE_INTEGER
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structure for FSCTL_QUERY_ALLOCATED_RANGES
'//

'//
'// Querying the allocated ranges requires an output buffer to store the
'// allocated ranges and an input buffer to specify the range to query.
'// The input buffer contains a single entry, the output buffer is an
'// array of the following structure.
'//

' // Size = 16 bytes
TYPE FILE_ALLOCATED_RANGE_BUFFER QWORD
   FileOffset AS QUAD   ' LARGE_INTEGER
   Length     AS QUAD   ' LARGE_INTEGER
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'// Structures for FSCTL_SET_ENCRYPTION, FSCTL_WRITE_RAW_ENCRYPTED, and FSCTL_READ_RAW_ENCRYPTED
'//

'//
'//  The input buffer to set encryption indicates whether we are to encrypt/decrypt a file
'//  or an individual stream.
'//

' // Size = 8 bytes
TYPE ENCRYPTION_BUFFER DWORD
   EncryptionOperation AS DWORD   ' DWORD
   Private(0)          AS BYTE    ' BYTE  Private[1]
END TYPE

%FILE_SET_ENCRYPTION       = &H00000001???
%FILE_CLEAR_ENCRYPTION     = &H00000002???
%STREAM_SET_ENCRYPTION     = &H00000003???
%STREAM_CLEAR_ENCRYPTION   = &H00000004???

%MAXIMUM_ENCRYPTION_VALUE  = &H00000004???

'//
'//  The optional output buffer to set encryption indicates that the last encrypted
'//  stream in a file has been marked as decrypted.
'//

' // Size = 1 byte
TYPE DECRYPTION_STATUS_BUFFER BYTE
   NoEncryptedStreams AS BYTE   ' BOOLEAN
END TYPE

%ENCRYPTION_FORMAT_DEFAULT = &H01

%COMPRESSION_FORMAT_SPARSE = &H4000

'//
'//  Request Encrypted Data structure.  This is used to indicate
'//  the range of the file to read.  It also describes the
'//  output buffer used to return the data.
'//

' // Size = 16 bytes
TYPE REQUEST_RAW_ENCRYPTED_DATA QWORD
   FileOffset AS QUAD    ' LONGLONG
   Length     AS DWORD   ' DWORD
END TYPE

'//
'//  Encrypted Data Information structure.  This structure
'//  is used to return raw encrypted data from a file in
'//  order to perform off-line recovery.  The data will be
'//  encrypted or encrypted and compressed.  The off-line
'//  service will need to use the encryption and compression
'//  format information to recover the file data.  In the
'//  event that the data is both encrypted and compressed then
'//  the decryption must occur before decompression.  All
'//  the data units below must be encrypted and compressed
'//  with the same format.
'//
'//  The data will be returned in units.  The data unit size
'//  will be fixed per request.  If the data is compressed
'//  then the data unit size will be the compression unit size.
'//
'//  This structure is at the beginning of the buffer used to
'//  return the encrypted data.  The actual raw bytes from
'//  the file will follow this buffer.  The offset of the
'//  raw bytes from the beginning of this structure is
'//  specified in the REQUEST_RAW_ENCRYPTED_DATA structure
'//  described above.
'//

' // Size = 32 bytes
TYPE ENCRYPTED_DATA_INFO   ' Must be 8 byte aligned
   ' //  This is the file offset for the first entry in the
   ' //  data block array.  The file system will round
   ' //  the requested start offset down to a boundary
   ' //  that is consistent with the format of the file.
   StartingFileOffset         AS QUAD    ' DWORDLONG
   ' //  Data offset in output buffer.  The output buffer
   ' //  begins with an ENCRYPTED_DATA_INFO structure.
   ' //  The file system will then store the raw bytes from
   ' //  disk beginning at the following offset within the
   ' //  output buffer.
   OutputBufferOffset         AS DWORD   ' DWORD
   ' //  The number of bytes being returned that are within
   ' //  the size of the file.  If this value is less than
   ' //  (NumberOfDataBlocks << DataUnitShift), it means the
   ' //  end of the file occurs within this transfer.  Any
   ' //  data beyond file size is invalid and was never
   ' //  passed to the encryption driver.
   BytesWithinFileSize        AS DWORD   ' DWORD
   ' //  The number of bytes being returned that are below
   ' //  valid data length.  If this value is less than
   ' //  (NumberOfDataBlocks << DataUnitShift), it means the
   ' //  end of the valid data occurs within this transfer.
   ' //  After decrypting the data from this transfer, any
   ' //  byte(s) beyond valid data length must be zeroed.
   BytesWithinValidDataLength AS DWORD   ' DWORD
   ' //  Code for the compression format as defined in
   ' //  ntrtl.h.  Note that COMPRESSION_FORMAT_NONE
   ' //  and COMPRESSION_FORMAT_DEFAULT are invalid if
   ' //  any of the described chunks are compressed.
   CompressionFormat          AS WORD    ' WORD
   ' //  The DataUnit is the granularity used to access the
   ' //  disk.  It will be the same as the compression unit
   ' //  size for a compressed file.  For an uncompressed
   ' //  file, it will be some cluster-aligned power of 2 that
   ' //  the file system deems convenient.  A caller should
   ' //  not expect that successive calls will have the
   ' //  same data unit shift value as the previous call.
   ' //
   ' //  Since chunks and compression units are expected to be
   ' //  powers of 2 in size, we express them log2.  So, for
   ' //  example (1 << ChunkShift) == ChunkSizeInBytes.  The
   ' //  ClusterShift indicates how much space must be saved
   ' //  to successfully compress a compression unit - each
   ' //  successfully compressed data unit must occupy
   ' //  at least one cluster less in bytes than an uncompressed
   ' //  data block unit.
   DataUnitShift              AS BYTE    ' BYTE
   ChunkShift                 AS BYTE    ' BYTE
   ClusterShift               AS BYTE    ' BYTE
   ' //  The format for the encryption.
   EncryptionFormat           AS BYTE    ' BYTE
   ' //  This is the number of entries in the data block size
   ' //  array.
   NumberOfDataBlocks         AS WORD    ' WORD
   ' //  This is an array of sizes in the data block array.  There
   ' //  must be one entry in this array for each data block
   ' //  read from disk.  The size has a different meaning
   ' //  depending on whether the file is compressed.
   ' //
   ' //  A size of zero always indicates that the final data consists entirely
   ' //  of zeroes.  There is no decryption or decompression to
   ' //  perform.
   ' //
   ' //  If the file is compressed then the data block size indicates
   ' //  whether this block is compressed.  A size equal to
   ' //  the block size indicates that the corresponding block did
   ' //  not compress.  Any other non-zero size indicates the
   ' //  size of the compressed data which needs to be
   ' //  decrypted/decompressed.
   ' //
   ' //  If the file is not compressed then the data block size
   ' //  indicates the amount of data within the block that
   ' //  needs to be decrypted.  Any other non-zero size indicates
   ' //  that the remaining bytes in the data unit within the file
   ' //  consists of zeros.  An example of this is when the
   ' //  the read spans the valid data length of the file.  There
   ' //  is no data to decrypt past the valid data length.
   DataBlockSize(0)           AS DWORD   ' DWORD DataBlockSize[ANYSIZE_ARRAY]
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'//  FSCTL_READ_FROM_PLEX support
'//  Request Plex Read Data structure.  This is used to indicate
'//  the range of the file to read.  It also describes
'//  which plex to perform the read from.
'//

' // Size = 16 bytes
TYPE PLEX_READ_DATA_REQUEST   ' Must be 8 byte aligned
   ' //  Requested offset and length to read.
   ' //  The offset can be the virtual offset (vbo) in to a file,
   ' //  or a volume. In the case of a file offset,
   ' //  the fsd will round the starting offset down
   ' //  to a file system boundary.  It will also
   ' //  round the length up to a file system boundary and
   ' //  enforce any other applicable limits.
   ByteOffset AS QUAD    ' LARGE_INTEGER
   ByteLength AS DWORD   ' DWORD
   PlexNumber AS DWORD   ' DWORD
END TYPE

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'//
'// FSCTL_SIS_COPYFILE support
'// Source and destination file names are passed in the FileNameBuffer.
'// Both strings are null terminated, with the source name starting at
'// the beginning of FileNameBuffer, and the destination name immediately
'// following.  Length fields include terminating nulls.
'//

' // Size = 16 bytes
TYPE SI_COPYFILE DWORD
   SourceFileNameLength      AS DWORD         ' DWORD
   DestinationFileNameLength AS DWORD         ' DWORD
   Flags                     AS DWORD         ' DWORD
   FileNameBuffer            AS WSTRINGZ * 2  ' WCHAR FileNameBuffer[1]
   ' Note: We are using WSTRINGZ * 2 instead of WSTRINGZ * 1 to keep DWORD alignment
END TYPE

%COPYFILE_SIS_LINK    = &H0001  ' Copy only if source is SIS
%COPYFILE_SIS_REPLACE = &H0002  ' Replace destination if it exists, else don't.
%COPYFILE_SIS_FLAGS   = &H0003

'#if(_WIN32_WINNT >= 0x0600)
'//
'//  Input parameter structure for FSCTL_MAKE_COMPATIBLE
'//

' // Size = 1 byte
TYPE FILE_MAKE_COMPATIBLE_BUFFER BYTE
   CloseDisc AS BYTE   ' BOOLEAN
END TYPE

'//
'//  Input parameter structure for FSCTL_SET_DEFECT_MANAGEMENT
'//

' // Size = 1 byte
TYPE FILE_SET_DEFECT_MGMT_BUFFER BYTE
   Disable AS BYTE   ' BOOLEAN
END TYPE

'//
'//  Output structure for FSCTL_QUERY_SPARING_INFO
'//

' // Size = 16 bytes
TYPE FILE_QUERY_SPARING_BUFFER DWORD
   SparingUnitBytes AS DWORD   ' DWORD
   SoftwareSparing  AS BYTE    ' BOOLEAN
   TotalSpareBlocks AS DWORD   ' DWORD
   FreeSpareBlocks  AS DWORD   ' DWORD
END TYPE

'//
'//  Output structure for FSCTL_QUERY_ON_DISK_VOLUME_INFO
'//

' // Size = 336 bytes
TYPE FILE_QUERY_ON_DISK_VOL_INFO_BUFFER   ' Must be 8 byte aligned
   DirectoryCount                  AS QUAD            ' LARGE_INTEGER // -1 = unknown
   FileCount                       AS QUAD            ' LARGE_INTEGER // -1 = unknown
   FsFormatMajVersion              AS WORD            ' WORD // -1 = unknown or n/a
   FsFormatMinVersion              AS WORD            ' WORD // -1 = unknown or n/a
   alignment1__                    AS DWORD           ' // To keep 8 byte alignment
   FsFormatName                    AS WSTRINGZ * 12   ' WCHAR
   FormatTime                      AS QUAD            ' LARGE_INTEGER
   LastUpdateTime                  AS QUAD            ' LARGE_INTEGER
   CopyrightInfo                   AS WSTRINGZ * 34   ' WCHAR
   AbstractInfo                    AS WSTRINGZ * 34   ' WCHAR
   FormattingImplementationInfo    AS WSTRINGZ * 34   ' WCHAR
   LastModifyingImplementationInfo AS WSTRINGZ * 34   ' WCHAR
END TYPE

'//
'//  Input flags for FSCTL_SET_REPAIR
'//

%SET_REPAIR_ENABLED                                      = &H00000001???
%SET_REPAIR_VOLUME_BITMAP_SCAN                           = &H00000002???
%SET_REPAIR_DELETE_CROSSLINK                             = &H00000004???
%SET_REPAIR_WARN_ABOUT_DATA_LOSS                         = &H00000008???
%SET_REPAIR_DISABLED_AND_BUGCHECK_ON_CORRUPT             = &H00000010???
%SET_REPAIR_VALID_MASK                                   = &H0000001F???

'//
'//  Input structures for FSCTL_SHRINK_VOLUME.
'//

' enum SHRINK_VOLUME_REQUEST_TYPES
%ShrinkPrepare = 1
%ShrinkCommit  = 2
%ShrinkAbort   = 3

' *** Removed in Windows 7 SDK ***
'%SHRINK_VOLUME_FLAG_FAIL_ON_BAD_CLUSTERS                = &H00000001???

' // Size = 24 bytes
TYPE SHRINK_VOLUME_INFORMATION QWORD   ' Must be 8 byte aligned
   ShrinkRequestType  AS LONG   ' SHRINK_VOLUME_REQUEST_TYPES
   Flags              AS QUAD   ' DWORDLONG
   NewNumberOfSectors AS QUAD   ' LONGLONG
END TYPE

'//
'//  Structures for FSCTL_TXFS_MODIFY_RM and FSCTL_TXFS_QUERY_RM_INFORMATION
'//
'//  For ModifyRM, TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS and
'//  TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT are mutually exclusive.
'//  You can specify the log growth amount in number of containers or as a percentage.
'//
'//  For ModifyRM, TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX and
'//  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX are mutually exclusive.
'//
'//  For ModifyRM, TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN and
'//  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN are mutually exclusive.
'//
'//  For ModifyRM, TXFS_RM_FLAG_RESET_RM_AT_NEXT_START and
'//  TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START are mutually exclusive and only
'//  apply to default RMs.
'//
'//  For ModifyRM, TXFS_RM_FLAG_PREFER_CONSISTENCY and
'//  TXFS_RM_FLAG_PREFER_AVAILABILITY are mutually exclusive.  After calling ModifyRM
'//  with one of these flags set the RM must be restarted for the change to take effect.
'//

%TXFS_RM_FLAG_LOGGING_MODE                           = &H00000001???
%TXFS_RM_FLAG_RENAME_RM                              = &H00000002???
%TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX                = &H00000004???
%TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN                = &H00000008???
%TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS    = &H00000010???
%TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT           = &H00000020???
%TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE             = &H00000040???
%TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX             = &H00000080???
%TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN             = &H00000100???
%TXFS_RM_FLAG_GROW_LOG                               = &H00000400???
%TXFS_RM_FLAG_SHRINK_LOG                             = &H00000800???
%TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE                   = &H00001000???
%TXFS_RM_FLAG_PRESERVE_CHANGES                       = &H00002000???
%TXFS_RM_FLAG_RESET_RM_AT_NEXT_START                 = &H00004000???
%TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START          = &H00008000???
%TXFS_RM_FLAG_PREFER_CONSISTENCY                     = &H00010000???
%TXFS_RM_FLAG_PREFER_AVAILABILITY                    = &H00020000???

%TXFS_LOGGING_MODE_SIMPLE        = &H0001
%TXFS_LOGGING_MODE_FULL          = &H0002

%TXFS_TRANSACTION_STATE_NONE         = &H00
%TXFS_TRANSACTION_STATE_ACTIVE       = &H01
%TXFS_TRANSACTION_STATE_PREPARED     = &H02
%TXFS_TRANSACTION_STATE_NOTACTIVE    = &H03

%TXFS_MODIFY_RM_VALID_FLAGS = _
                 %TXFS_RM_FLAG_LOGGING_MODE                          OR _
                 %TXFS_RM_FLAG_RENAME_RM                             OR _
                 %TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX               OR _
                 %TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN               OR _
                 %TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS   OR _
                 %TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT          OR _
                 %TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE            OR _
                 %TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX            OR _
                 %TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN            OR _
                 %TXFS_RM_FLAG_SHRINK_LOG                            OR _
                 %TXFS_RM_FLAG_GROW_LOG                              OR _
                 %TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE                  OR _
                 %TXFS_RM_FLAG_PRESERVE_CHANGES                      OR _
                 %TXFS_RM_FLAG_RESET_RM_AT_NEXT_START                OR _
                 %TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START         OR _
                 %TXFS_RM_FLAG_PREFER_CONSISTENCY                    OR _
                 %TXFS_RM_FLAG_PREFER_AVAILABILITY

' // Size = 40 bytes
TYPE TXFS_MODIFY_RM   ' Must be 8 byte aligned
   ' //  TXFS_RM_FLAG_* flags
   Flags AS DWORD   ' DWORD
   ' //  Maximum log container count if TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX is set.
   LogContainerCountMax AS DWORD   ' DWORD
   ' //  Minimum log container count if TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN is set.
   LogContainerCountMin AS DWORD   ' DWORD
   ' //  Target log container count for TXFS_RM_FLAG_SHRINK_LOG or _GROW_LOG.
   LogContainerCount AS DWORD   ' DWORD
   ' //  When the log is full, increase its size by this much.  Indicated as either a percent of
   ' //  the log size or absolute container count, depending on which of the TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_*
   ' //  flags is set.
   LogGrowthIncrement AS DWORD   ' DWORD
   ' //  Sets autoshrink policy if TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE is set.  Autoshrink
   ' //  makes the log shrink so that no more than this percentage of the log is free at any time.
   LogAutoShrinkPercentage AS DWORD   ' DWORD
   ' //  Reserved.
   Reserved AS QUAD   ' DWORDLONG
   ' //  If TXFS_RM_FLAG_LOGGING_MODE is set, this must contain one of TXFS_LOGGING_MODE_SIMPLE
   ' //  or TXFS_LOGGING_MODE_FULL.
   LoggingMode AS WORD   ' WORD
   alignment__(5) AS BYTE   ' // To keep 8 byte alignment
END TYPE

%TXFS_RM_STATE_NOT_STARTED      = 0
%TXFS_RM_STATE_STARTING         = 1
%TXFS_RM_STATE_ACTIVE           = 2
%TXFS_RM_STATE_SHUTTING_DOWN    = 3

'//
'//  The flags field for query RM information is used for the following information:
'//
'//  1)  To indicate whether the LogGrowthIncrement field is reported as a percent
'//      or as a number of containers.  Possible flag values for this are:
'//
'//      TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS xor TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT
'//
'//  2)  To indicate that there is no set maximum or minimum container count.  Possible
'//      flag values for this are:
'//
'//      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX
'//      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN
'//
'//      Note that these flags are not mutually exclusive.
'//
'//  2)  To report whether the RM will be reset the next time it is started.  Note that
'//      only the default RM will report a meaningful value (secondary RMs will always
'//      report DO_NOT_RESET) Possible flag values for this are:
'//
'//      TXFS_RM_FLAG_RESET_RM_AT_NEXT_START xor TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START
'//
'//  3)  To report whether the RM is in consistency mode or availability mode.  Possible
'//      flag values for this are:
'//
'//      TXFS_RM_FLAG_PREFER_CONSISTENCY xor TXFS_RM_FLAG_PREFER_AVAILABILITY
'//
'//  The RmState field can have exactly one of the above-defined TXF_RM_STATE_ values.
'//

%TXFS_QUERY_RM_INFORMATION_VALID_FLAGS = _
                 %TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS   OR _
                 %TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT          OR _
                 %TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX            OR _
                 %TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN            OR _
                 %TXFS_RM_FLAG_RESET_RM_AT_NEXT_START                OR _
                 %TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START         OR _
                 %TXFS_RM_FLAG_PREFER_CONSISTENCY                    OR _
                 %TXFS_RM_FLAG_PREFER_AVAILABILITY

' // Size = 176 bytes
TYPE TXFS_QUERY_RM_INFORMATION   ' Must be 8 byte aligned
   ' //  If the return value is STATUS_BUFFER_OVERFLOW (ERROR_MORE_DATA), this
   ' //  will indicate how much space is required to hold everything.
   BytesRequired AS DWORD   ' DWORD
   alignment1__ AS DWORD
   ' //  LSN of earliest available record in the RM's log.
   TailLsn AS QUAD   ' DWORDLONG
   ' //  LSN of most recently-written record in the RM's log.
   CurrentLsn AS QUAD   ' DWORDLONG
   ' //  LSN of the log's archive tail.
   ArchiveTailLsn AS QUAD   ' DWORDLONG
   ' //  Size of a log container in bytes.
   LogContainerSize AS QUAD   ' DWORDLONG
   ' //  Highest virtual clock value recorded in this RM's log.
   HighestVirtualClock AS QUAD   ' LARGE_INTEGER
   ' //  Number of containers in this RM's log.
   LogContainerCount AS DWORD   ' DWORD
   ' //  Maximum-allowed log container count.
   LogContainerCountMax AS DWORD   ' DWORD
   ' //  Minimum-allowed log container count.
   LogContainerCountMin AS DWORD   ' DWORD
   ' //  Amount by which log will grow when it gets full.  Indicated as either a percent of
   ' //  the log size or absolute container count, depending on which of the TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_*
   ' //  flags is set.
   LogGrowthIncrement AS DWORD   ' DWORD
   ' //  Reports on the autoshrink policy if.  Autoshrink makes the log shrink so that no more than this
   ' //  percentage of the log is free at any time.  A value of 0 indicates that autoshrink is off (i.e.
   ' //  the log will not automatically shrink).
   LogAutoShrinkPercentage AS DWORD   ' DWORD
   ' //  TXFS_RM_FLAG_* flags.  See the comment above at TXFS_QUERY_RM_INFORMATION_VALID_FLAGS to see
   ' //  what the flags here mean.
   Flags AS DWORD   ' DWORD
   ' //  Exactly one of TXFS_LOGGING_MODE_SIMPLE or TXFS_LOGGING_MODE_FULL.
   LoggingMode AS WORD   ' WORD
   ' //  Reserved.
   Reserved AS WORD   ' WORD
   ' //  Activity state of the RM.  May be exactly one of the above-defined TXF_RM_STATE_ values.
   RmState AS DWORD   ' DWORD
   ' //  Total capacity of the log in bytes.
   LogCapacity AS QUAD   ' DWORDLONG
   ' //  Amount of free space in the log in bytes.
   LogFree AS QUAD   ' DWORDLONG
   ' //  Size of $Tops in bytes.
   TopsSize AS QUAD   ' DWORDLONG
   ' //  Amount of space in $Tops in use.
   TopsUsed AS QUAD   ' DWORDLONG
   ' //  Number of transactions active in the RM at the time of the call.
   TransactionCount AS QUAD   ' DWORDLONG
   ' //  Total number of single-phase commits that have happened the RM.
   OnePCCount AS QUAD   ' DWORDLONG
   ' //  Total number of two-phase commits that have happened the RM.
   TwoPCCount AS QUAD   ' DWORDLONG
   ' //  Number of times the log has filled up.
   NumberLogFileFull AS QUAD   ' DWORDLONG
   ' //  Age of oldest active transaction in the RM, in milliseconds.
   OldestTransactionAge AS QUAD   ' DWORDLONG
   ' //  Name of the RM.
   RMName AS GUID   ' GUID
   ' //  Offset in bytes from the beginning of this structure to a NULL-terminated Unicode
   ' //  string indicating the path to the RM's transaction manager's log.
   TmLogPathOffset AS DWORD   ' DWORD
   alignment2__ AS DWORD
END TYPE

'//
'// Structures for FSCTL_TXFS_ROLLFORWARD_REDO
'//

%TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN        = &H01
%TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK   = &H02

%TXFS_ROLLFORWARD_REDO_VALID_FLAGS = _
                 %TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN OR _
                 %TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK

' // Size = 32 bytes
TYPE TXFS_ROLLFORWARD_REDO_INFORMATION QWORD   ' Must be 8 byte aligned
   LastVirtualClock   AS QUAD    ' LARGE_INTEGER
   LastRedoLsn        AS QUAD    ' DWORDLONG
   HighestRecoveryLsn AS QUAD    ' DWORDLONG
   Flags              AS DWORD   ' DWORD
END TYPE

'//
'//  Structures for FSCTL_TXFS_START_RM
'//
'//  Note that TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS and
'//  TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT are mutually exclusive.
'//  You can specify the log growth amount in number of containers or as a percentage.
'//
'//  TXFS_START_RM_FLAG_CONTAINER_COUNT_MAX and TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX
'//  are mutually exclusive.
'//
'//  TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN and TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN
'//  are mutually exclusive.
'//
'//  TXFS_START_RM_FLAG_PREFER_CONSISTENCY and TXFS_START_RM_FLAG_PREFER_AVAILABILITY
'//  are mutually exclusive.
'//
'//  Optional parameters will have system-supplied defaults applied if omitted.
'//

%TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX              = &H00000001???
%TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN              = &H00000002???
%TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE                   = &H00000004???
%TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS  = &H00000008???
%TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT         = &H00000010???
%TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE           = &H00000020???
%TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX           = &H00000040???
%TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN           = &H00000080???

%TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT                  = &H00000200???
%TXFS_START_RM_FLAG_LOGGING_MODE                         = &H00000400???
%TXFS_START_RM_FLAG_PRESERVE_CHANGES                     = &H00000800???

%TXFS_START_RM_FLAG_PREFER_CONSISTENCY                   = &H00001000???
%TXFS_START_RM_FLAG_PREFER_AVAILABILITY                  = &H00002000???

%TXFS_START_RM_VALID_FLAGS = _
                 %TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX             OR _
                 %TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN             OR _
                 %TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE                  OR _
                 %TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS OR _
                 %TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT        OR _
                 %TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE          OR _
                 %TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT                 OR _
                 %TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX          OR _
                 %TXFS_START_RM_FLAG_LOGGING_MODE                        OR _
                 %TXFS_START_RM_FLAG_PRESERVE_CHANGES                    OR _
                 %TXFS_START_RM_FLAG_PREFER_CONSISTENCY                  OR _
                 %TXFS_START_RM_FLAG_PREFER_AVAILABILITY

' // Size = 48 bytes
TYPE TXFS_START_RM_INFORMATION
   ' //  TXFS_START_RM_FLAG_* flags.
   Flags AS DWORD   ' DWORD
   alignment1__ AS DWORD
   ' //  RM log container size, in bytes.  This parameter is optional.
   LogContainerSize AS QUAD   ' DWORDLONG
   ' //  RM minimum log container count.  This parameter is optional.
   LogContainerCountMin AS DWORD   ' DWORD
   ' //  RM maximum log container count.  This parameter is optional.
   LogContainerCountMax AS DWORD   ' DWORD
   ' //  RM log growth increment in number of containers or percent, as indicated
   ' //  by TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_* flag.  This parameter is
   ' //  optional.
   LogGrowthIncrement AS DWORD   ' DWORD
   ' //  RM log auto shrink percentage.  This parameter is optional.
   LogAutoShrinkPercentage AS DWORD   ' DWORD
   ' //  Offset from the beginning of this structure to the log path for the KTM
   ' //  instance to be used by this RM.  This must be a two-byte (WCHAR) aligned
   ' //  value.  This parameter is required.
   TmLogPathOffset AS DWORD   ' DWORD
   ' //  Length in bytes of log path for the KTM instance to be used by this RM.
   ' //  This parameter is required.
   TmLogPathLength AS WORD   ' WORD
   ' //  Logging mode for this RM.  One of TXFS_LOGGING_MODE_SIMPLE or
   ' //  TXFS_LOGGING_MODE_FULL (mutually exclusive).  This parameter is optional,
   ' //  and will default to TXFS_LOGGING_MODE_SIMPLE.
   LoggingMode AS WORD   ' WORD
   ' //  Length in bytes of the path to the log to be used by the RM.  This parameter
   ' //  is required.
   LogPathLength AS WORD   ' WORD
   ' //  Reserved.
   Reserved AS WORD   ' WORD
   ' //  The path to the log (in Unicode characters) to be used by the RM goes here.
   ' //  This parameter is required.
   LogPath AS WSTRINGZ * 2   ' WCHAR
   ' Note: We are using STRING * 2 instead of * 1 to keep 8 byte alignment
END TYPE

'//
'//  Structures for FSCTL_TXFS_GET_METADATA_INFO
'//

' // Size = 16 bytes
TYPE TXFS_GET_METADATA_INFO_OUT_TxfFileId QWORD
   LowPart  AS QUAD   ' LONGLONG
   HighPart AS QUAD   ' LONGLONG
END TYPE

' // Size = 48 bytes
TYPE TXFS_GET_METADATA_INFO_OUT QWORD  ' Must be 8 byte aligned
   ' //  Returns the TxfId of the file referenced by the handle used to call this routine.
   TxfFileId AS TXFS_GET_METADATA_INFO_OUT_TxfFileId
   ' //  The GUID of the transaction that has the file locked, if applicable.
   LockingTransaction AS GUID   ' GUID
   ' //  Returns the LSN for the most recent log record we've written for the file.
   LastLsn AS QUAD   ' DWORDLONG
   ' //  Transaction state, a TXFS_TRANSACTION_STATE_* value.
   TransactionState AS DWORD   ' DWORD
END TYPE

'//
'//  Structures for FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES
'//
'//  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED means the reported name was created
'//  in the locking transaction.
'//
'//  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED means the reported name was deleted
'//  in the locking transaction.
'//
'//  Note that both flags may appear if the name was both created and deleted in the same
'//  transaction.  In that case the FileName[] member will contain only "\0", as there is
'//  no meaningful name to report.
'//

%TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED = &H00000001???
%TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED = &H00000002???

' // Size = 48 bytes
TYPE TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY QWORD FILL  ' Must be 8 byte aligned
   ' //  Offset in bytes from the beginning of the TXFS_LIST_TRANSACTION_LOCKED_FILES
   ' //  structure to the next TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY.
   Offset AS QUAD   ' DWORDLONG
   ' //  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_* flags to indicate whether the
   ' //  current name was deleted or created in the transaction.
   NameFlags AS DWORD   ' DWORD
   ' //  NTFS File ID of the file.
   FileId AS QUAD   ' LONGLONG
   ' //  Reserved.
   Reserved1 AS DWORD   ' DWORD
   Reserved2 AS DWORD   ' DWORD
   Reserved3 AS QUAD    ' LONGLONG
   ' //  NULL-terminated Unicode path to this file, relative to RM root.
   FileName AS WSTRINGZ * 4   ' WCHAR
   ' Note: We are using STRING * 4 instead of * 1 to keep 8 byte alignment
END TYPE


' // Size = 40 bytes
TYPE TXFS_LIST_TRANSACTION_LOCKED_FILES   ' Must be 8 byte aligned
   ' //  GUID name of the KTM transaction that files should be enumerated from.
   KtmTransaction AS GUID   ' GUID
   ' //  On output, the number of files involved in the transaction on this RM.
   NumberOfFiles AS QUAD   ' DWORDLONG
   ' //  The length of the buffer required to obtain the complete list of files.
   ' //  This value may change from call to call as the transaction locks more files.
   BufferSizeRequired AS QUAD   ' DWORDLONG
   ' //  Offset in bytes from the beginning of this structure to the first
   ' //  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY.
   Offset AS QUAD   ' DWORDLONG
END TYPE

'//
'//  Structures for FSCTL_TXFS_LIST_TRANSACTIONS
'//

' // Size = 40 bytes
TYPE TXFS_LIST_TRANSACTIONS_ENTRY QWORD FILL   ' Must be 8 byte aligned
   ' //  Transaction GUID.
   TransactionId AS GUID   ' GUID
   ' //  Transaction state, a TXFS_TRANSACTION_STATE_* value.
   TransactionState AS DWORD   ' DWORD
   ' //  Reserved fields
   Reserved1 AS DWORD   ' DWORD
   Reserved2 AS DWORD   ' DWORD
   Reserved3 AS QUAD    ' LONGLONG
END TYPE

' // Size = 16 bytes
TYPE TXFS_LIST_TRANSACTIONS QWORD
   ' //  On output, the number of transactions involved in this RM.
   NumberOfTransactions AS QUAD   ' DWORDLONG
   ' //  The length of the buffer required to obtain the complete list of
   ' //  transactions.  Note that this value may change from call to call
   ' //  as transactions enter and exit the system.
   BufferSizeRequired AS QUAD   ' DWORDLONG
END TYPE


'//
'//  Structures for FSCTL_TXFS_READ_BACKUP_INFORMATION
'//

' // Size = 4 bytes
UNION TXFS_READ_BACKUP_INFORMATION_OUT_UNION DWORD
   ' //  Used to return the required buffer size if return code is STATUS_BUFFER_OVERFLOW
   BufferLength AS DWORD   ' DWORD
   ' //  On success the data is copied here.
   Buffer(0) AS BYTE
END UNION

' // Size = 4 bytes
TYPE TXFS_READ_BACKUP_INFORMATION_OUT DWORD
   TXFS_READ_BACKUP_INFORMATION_OUT_UNION
END TYPE

'//
'//  Structures for FSCTL_TXFS_WRITE_BACKUP_INFORMATION
'//

' // Size = 1 byte
TYPE TXFS_WRITE_BACKUP_INFORMATION BYTE
   ' //  The data returned in the Buffer member of a previous call to
   ' //  FSCTL_TXFS_READ_BACKUP_INFORMATION goes here.
   Buffer(0) AS BYTE
END TYPE

'//
'//  Output structure for FSCTL_TXFS_GET_TRANSACTED_VERSION
'//

%TXFS_TRANSACTED_VERSION_NONTRANSACTED   = &HFFFFFFFE???
%TXFS_TRANSACTED_VERSION_UNCOMMITTED     = &HFFFFFFFF???

' // Size = 16 bytes
TYPE TXFS_GET_TRANSACTED_VERSION DWORD FILL
   ' //  The version that this handle is opened to.  This will be
   ' //  TXFS_TRANSACTED_VERSION_UNCOMMITTED for nontransacted and
   ' //  transactional writer handles.
   ThisBaseVersion AS DWORD   ' DWORD
   ' //  The most recent committed version available.
   LatestVersion AS DWORD   ' DWORD
   ' //  If this is a handle to a miniversion, the ID of the miniversion.
   ' //  If it is not a handle to a minivers, this field will be 0.
   ThisMiniVersion AS WORD   ' WORD
   ' //  The first available miniversion.  Unless the miniversions are
   ' //  visible to the transaction bound to this handle, this field will be zero.
   FirstMiniVersion AS WORD   ' WORD
   ' //  The latest available miniversion.  Unless the miniversions are
   ' //  visible to the transaction bound to this handle, this field will be zero.
   LatestMiniVersion AS WORD   ' WORD
   alignment__ AS WORD   ' // To keep DWORD alignment
END TYPE

'//
'//  Structures for FSCTL_TXFS_SAVEPOINT_INFORMATION
'//
'//  Note that the TXFS_SAVEPOINT_INFORMATION structure is both and in and out structure.
'//  The KtmTransaction and ActionCode members are always in-parameters, and the SavepointId
'//  member is either an in-parameter, an out-parameter, or not used (see its definition below).
'//

'//
'//  Create a new savepoint.
'//

%TXFS_SAVEPOINT_SET                      = &H00000001???

'//
'//  Roll back to a specified savepoint.
'//

%TXFS_SAVEPOINT_ROLLBACK                 = &H00000002???

'//
'//  Clear (make unavailable for rollback) the most recently set savepoint
'//  that has not yet been cleared.
'//

%TXFS_SAVEPOINT_CLEAR                    = &H00000004???

'//
'//  Clear all savepoints from the transaction.
'//

%TXFS_SAVEPOINT_CLEAR_ALL                = &H00000010???

' // Size = 12 bytes
TYPE TXFS_SAVEPOINT_INFORMATION DWORD
   ' //  Handle to the transaction on which to perform the savepoint operation.
   KtmTransaction AS DWORD   ' HANDLE
   ' //  Specifies the savepoint action to take.  A TXFS_SAVEPOINT_* value.
   ActionCode AS DWORD   ' DWORD
   ' //  In-parameter for TXFS_ROLLBACK_TO_SAVEPOINT - specifies the savepoint to which
   ' //  to roll back.
   ' //
   ' //  Out-parameter for TXFS_SET_SAVEPOINT - the newly-created savepoint ID will be
   ' //  returned here.
   ' //
   ' //  Not used for TXFS_CLEAR_SAVEPOINT or TXFS_CLEAR_ALL_SAVEPOINTS.
   SavepointId AS DWORD   ' DWORD
END TYPE

'//
'//  Structures for FSCTL_TXFS_CREATE_MINIVERSION
'//
'//      Only an out parameter is necessary.  That returns the identifier of the new miniversion created.
'//

' // Size = 12 bytes
TYPE TXFS_CREATE_MINIVERSION_INFO DWORD FILL
   StructureVersion AS WORD   ' WORD
   StructureLength AS WORD   ' WORD
   ' //  The base version for the newly created miniversion.
   BaseVersion AS DWORD   ' DWORD
   ' //  The miniversion that was just created.
   MiniVersion AS WORD   ' WORD
   alignment__ AS WORD   ' // To keep DWORD alignment
END TYPE

'//
'//  Structure for FSCTL_TXFS_TRANSACTION_ACTIVE
'//

' // Size = 1 byte
TYPE TXFS_TRANSACTION_ACTIVE_INFO BYTE
   ' //  Whether or not the volume had active transactions when this snapshot was taken.
   TransactionsActiveAtSnapshot AS BYTE   ' BOOLEAN
END TYPE

'#endif /* _WIN32_WINNT >= 0x0600 */

'#if (_WIN32_WINNT >= 0x0601)
'//
'// Output structure for FSCTL_GET_BOOT_AREA_INFO
'//

' // Size = 8 bytes
TYPE BOOT_AREA_INFO_BOOTSECTORS_STRUCT QWORD
   Offset AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 24 bytes
TYPE BOOT_AREA_INFO QWORD
   BootSectorCount AS DWORD   ' DWORD // the count of boot sectors present on the file system
   BootSectors(1)  AS BOOT_AREA_INFO_BOOTSECTORS_STRUCT   ' // variable number of boot sectors.
END TYPE

'//
'// Output structure for FSCTL_GET_RETRIEVAL_POINTER_BASE
'//

' // Size = 8 bytes
TYPE RETRIEVAL_POINTER_BASE QWORD
   FileAreaOffset AS QUAD   ' LARGE_INTEGER // sector offset to the first allocatable unit on the filesystem
END TYPE

'//
'// Structure for FSCTL_SET_PERSISTENT_VOLUME_STATE and FSCTL_GET_PERSISTENT_VOLUME_STATE
'// The initial version will be 1.0
'//

' // Size = 16 bytes
TYPE FILE_FS_PERSISTENT_VOLUME_INFORMATION DWORD
   VolumeFlags AS DWORD   ' DWORD
   FlagMask    AS DWORD   ' DWORD
   Version     AS DWORD   ' DWORD
   Reserved    AS DWORD   ' DWORD
END TYPE

'//
'//  Structure for FSCTL_QUERY_FILE_SYSTEM_RECOGNITION
'//

' // Size = 9 bytes
TYPE FILE_SYSTEM_RECOGNITION_INFORMATION BYTE
   FileSystem AS ASCIIZ * 9   ' CHAR[9]
END TYPE

'//
'//  Structures for FSCTL_REQUEST_OPLOCK
'//

%OPLOCK_LEVEL_CACHE_READ         = &H00000001???
%OPLOCK_LEVEL_CACHE_HANDLE       = &H00000002???
%OPLOCK_LEVEL_CACHE_WRITE        = &H00000004???

%REQUEST_OPLOCK_INPUT_FLAG_REQUEST               = &H00000001???
%REQUEST_OPLOCK_INPUT_FLAG_ACK                   = &H00000002???
%REQUEST_OPLOCK_INPUT_FLAG_COMPLETE_ACK_ON_CLOSE = &H00000004???

%REQUEST_OPLOCK_CURRENT_VERSION         = 1

' // Size = 12 bytes
TYPE REQUEST_OPLOCK_INPUT_BUFFER DWORD FILL
   ' //  This should be set to REQUEST_OPLOCK_CURRENT_VERSION.
   StructureVersion     AS WORD    ' WORD
   StructureLength      AS WORD    ' WORD
   ' //  One or more OPLOCK_LEVEL_CACHE_* values to indicate the desired level of the oplock.
   RequestedOplockLevel AS DWORD   ' DWORD
   ' //  REQUEST_OPLOCK_INPUT_FLAG_* flags.
   Flags                AS DWORD   ' DWORD
END TYPE

%REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED   = &H00000001???
%REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED = &H00000002???

' // Size = 24 bytes
TYPE REQUEST_OPLOCK_OUTPUT_BUFFER DWORD FILL
   ' //  This should be set to REQUEST_OPLOCK_CURRENT_VERSION.
   StructureVersion    AS WORD          ' WORD
   StructureLength     AS WORD          ' WORD
   ' //  One or more OPLOCK_LEVEL_CACHE_* values indicating the level of the oplock that
   ' //  was just broken.
   OriginalOplockLevel AS DWORD         ' DWORD
   ' //  One or more OPLOCK_LEVEL_CACHE_* values indicating the level to which an oplock
   ' //  is being broken, or an oplock level that may be available for granting, depending
   ' //  on the operation returning this buffer.
   NewOplockLevel      AS DWORD         ' DWORD
   ' //  REQUEST_OPLOCK_OUTPUT_FLAG_* flags.
   Flags               AS DWORD         ' DWORD
   ' //  When REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED is set, and when the
   ' //  OPLOCK_LEVEL_CACHE_HANDLE level is being lost in an oplock break, these fields
   ' //  contain the access mode and share mode of the request that is causing the break.
   AccessMode          AS ACCESS_MASK   ' ACCESS_MASK
   ShareMode           AS WORD          ' WORD
   alignment__         AS WORD          ' // To keep DWORD alignment
END TYPE

'//
'//  Structures for FSCTL_SD_GLOBAL_CHANGE
'//

'//
'//  list of operations supported
'//

%SD_GLOBAL_CHANGE_TYPE_MACHINE_SID = 1


'//
'//  Operation specific structures for SD_GLOBAL_CHANGE_TYPE_MACHINE_SID
'//
'//  This con
'//

' // Size = 8 bytes
TYPE SD_CHANGE_MACHINE_SID_INPUT WORD
   ' //  The current machine SID to change.
   ' //  This define the offset from the beginning of the SD_GLOBAL_CHANGE_INPUT
   ' //  structure of where the CurrentMachineSID to replace begins.  This will
   ' //  be a SID structure.  The length defines the length of the imbedded SID
   ' //  structure.
   CurrentMachineSIDOffset AS WORD   ' WORD
   CurrentMachineSIDLength AS WORD   ' WORD
   ' //  The new machine SID value to set inplace of the current machine SID
   ' //  This define the offset from the beginning of the SD_GLOBAL_CHANGE_INPUT
   ' //  structure of where the NewMachineSID to set begins.  This will
   ' //  be a SID structure.  The length defines the length of the imbedded SID
   ' //  structure.
   NewMachineSIDOffset     AS WORD   ' WORD
   NewMachineSIDLength     AS WORD   ' WORD
END TYPE

' // Size = 56 bytes
TYPE SD_CHANGE_MACHINE_SID_OUTPUT QWORD
   ' //  How many entries were successfully changed in the $Secure stream
   NumSDChangedSuccess    AS QUAD   ' DWORDLONG
   ' //  How many entires failed the update in the $Secure stream
   NumSDChangedFail       AS QUAD   ' DWORDLONG
   ' //  How many entires are unused in the current security stream
   NumSDUnused            AS QUAD   ' DWORDLONG
   ' //  The total number of entries processed in the $Secure stream
   NumSDTotal             AS QUAD   ' DWORDLONG
   ' //  How many entries were successfully changed in the $MFT file
   NumMftSDChangedSuccess AS QUAD   ' DWORDLONG
   ' //  How many entries failed the update in the $MFT file
   NumMftSDChangedFail    AS QUAD   ' DWORDLONG
   ' //  Total number of entriess process in the $MFT file
   NumMftSDTotal          AS QUAD   ' DWORDLONG
END TYPE

'//
'//  Generic INPUT & OUTPUT structures for FSCTL_SD_GLOBAL_CHANGE
'//

' // Size = 8 bytes
UNION SD_GLOBAL_CHANGE_INPUT_UNION WORD
   SdChange AS SD_CHANGE_MACHINE_SID_INPUT
END UNION

' // Size = 16 bytes
TYPE SD_GLOBAL_CHANGE_INPUT DWORD
   ' //  Input flags (none currently defined)
   Flags AS DWORD   ' DWORD
   ' //  Specifies which type of change we are doing and pics which member
   ' //  of the below union is in use.
   ChangeType AS DWORD   ' DWORD
   SD_GLOBAL_CHANGE_INPUT_UNION
END TYPE

' // Size = 56 bytes
UNION SD_GLOBAL_CHANGE_OUTPUT_UNION DWORD
   SdChange AS SD_CHANGE_MACHINE_SID_OUTPUT
END UNION

' // Size = 64 bytes
TYPE SD_GLOBAL_CHANGE_OUTPUT DWORD
   ' //  Output State Flags (none currently defined)
   Flags AS DWORD   ' DWORD
   ' //  Specifies which below union to use
   ChangeType AS DWORD   ' DWORD
   SD_GLOBAL_CHANGE_OUTPUT_UNION
END TYPE

'//
'//  Flag to indicate the encrypted file is sparse
'//

%ENCRYPTED_DATA_INFO_SPARSE_FILE = 1

' // Size = 16 bytes
TYPE EXTENDED_ENCRYPTED_DATA_INFO DWORD
   ' //  This is really a 4 byte character array which
   ' //  must have the value "EXTD".  We use this
   ' //  to determine if we should read the extended data
   ' //  or not.
   ExtendedCode AS DWORD   ' DWORD
   ' //  The length of the extended data structure
   Length       AS DWORD   ' DWORD
   ' //  Encrypted data flags (currently only sparse is defined)
   Flags        AS DWORD   ' DWORD
   Reserved     AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE LOOKUP_STREAM_FROM_CLUSTER_INPUT   ' Must be 8 byte aligned
   ' //  Flags for the operation.  Currently no flags are defined.
   Flags AS DWORD   ' DWORD
   ' //  Number of clusters in the following array of clusters.
   ' //  The input buffer must be large enough to contain this
   ' //  number or the operation will fail.
   NumberOfClusters AS DWORD   ' DWORD
   ' //  An array of one or more clusters to look up.
   Cluster(0) AS QUAD   ' LARGE_INTEGER[1]
END TYPE

' // Size = 12 bytes
TYPE LOOKUP_STREAM_FROM_CLUSTER_OUTPUT DWORD
   ' //  Offset from the beginning of this structure to the first entry
   ' //  returned.  If no entries are returned, this value is zero.
   Offset             AS DWORD   ' DWORD
   ' //  Number of matches to the input criteria.  Note that more matches
   ' //  may be found than entries returned if the buffer is not large
   ' //  enough.
   NumberOfMatches    AS DWORD   ' DWORD
   ' //  Minimum size of the buffer, in bytes, which would be needed to
   ' //  contain all matching entries to the input criteria.
   BufferSizeRequired AS DWORD   ' DWORD
END TYPE

%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE          = &H00000001???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET    = &H00000002???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE     = &H00000004???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE    = &H00000008???

%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK          = &Hff000000???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA          = &H01000000???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX         = &H02000000???
%LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM        = &H03000000???

' // Size = 32 bytes
TYPE LOOKUP_STREAM_FROM_CLUSTER_ENTRY  ' Must be 8 byte aligned
   ' //  Offset from the beginning of this structure to the next entry
   ' //  returned.  If there are no more entries, this value is zero.
   OffsetToNext AS DWORD   ' DWORD
   ' //  Flags describing characteristics about this stream.
   Flags        AS DWORD   ' DWORD
   ' //  This value is reserved and is currently zero.
   Reserved     AS QUAD    ' LARGE_INTEGER
   ' //  This is the cluster that this entry refers to.  It will be one
   ' //  of the clusters passed in the input structure.
   Cluster      AS QUAD    ' LARGE_INTEGER
   ' //  A NULL-terminated Unicode string containing the path of the
   ' //  object relative to the root of the volume.  This string
   ' //  will refer to the attribute or stream represented by the
   ' //  cluster.
   FileName AS WSTRINGZ * 4   ' WCHAR[1]
   ' Note: We are using WSTRINGZ * 4 instead of * 1 to keep 8 byte alignment
END TYPE

'//
'//  This is the structure for the FSCTL_FILE_TYPE_NOTIFICATION operation.
'//  Its purpose is to notify the storage stack about the extents of certain
'//  types of files.  This is only callable from kernel mode
'//

' // Size = 24 bytes
TYPE FILE_TYPE_NOTIFICATION_INPUT DWORD
   ' //  Flags for this operation
   ' //  FILE_TYPE_NOTIFICATION_FLAG_*
   Flags          AS DWORD   ' DWORD
   ' //  A count of how many FileTypeID guids are given
   NumFileTypeIDs AS DWORD   ' DWORD
   ' //  This is a unique identifer for the type of file notification occuring
   FileTypeID(0)  AS GUID    ' GUID[1]
END TYPE

'//
'//  Flags for the given operation
'//

%FILE_TYPE_NOTIFICATION_FLAG_USAGE_BEGIN = &H00000001???   ' //Set when adding the specified usage on the given file
%FILE_TYPE_NOTIFICATION_FLAG_USAGE_END   = &H00000002???   ' //Set when removing the specified usage on the given file

'//
'//  These are the globally defined file types
'//

$FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE = GUID$("{0d0a64a1-38fc-4db8-9fe7-3f4352cd7c5c}")
$FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE = GUID$("{b7624d64-b9a3-4cf8-8011-5b86c940e7b7}")
$FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE = GUID$("{9d453eb7-d2a6-4dbd-a2e3-fbd0ed9109a9}")
'#endif /* _WIN32_WINNT >= 0x0601 */

'#endif // _FILESYSTEMFSCTL_

#ENDIF  ' #IF NOT %DEF(%FILESYSTEMFSCTL)

'#define IOCTL_VOLUME_BASE   ((DWORD) 'V')
%IOCTL_VOLUME_BASE = 86  ' ((DWORD) 'V')

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

'//
'// IOCTL to obtain the physical location of
'// the specified volume on one or more disks.
'//

%IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS = &H00560000???  ' CTL_CODE(IOCTL_VOLUME_BASE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'// IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     Structure of type VOLUME_DISK_EXTENTS
'//

' // Size = 24 bytes
TYPE DISK_EXTENT QWORD   ' Must be 8 byte aligned
   ' // Specifies the storage device number of
   ' // the disk on which this extent resides.
   DiskNumber     AS DWORD   ' DWORD
   ' // Specifies the offset and length of this
   ' // extent relative to the beginning of the
   ' // disk.
   StartingOffset AS QUAD    ' LARGE_INTEGER
   ExtentLength   AS QUAD    ' LARGE_INTEGER
END TYPE

' // Size = 32 bytes
TYPE VOLUME_DISK_EXTENTS QWORD   ' Must be 8 byte aligned
   ' // Specifies one or more contiguous range
   ' // of sectors that make up this volume.
   NumberOfDiskExtents AS DWORD         ' DWORD
   Extents(0)          AS DISK_EXTENT   ' DISK_EXTENT Extents[1]
END TYPE

'//
'// IOCTLs to transition the specified volume
'// between r/w and non r/w modes.
'//

%IOCTL_VOLUME_ONLINE  = &H0056C008???   ' CTL_CODE(IOCTL_VOLUME_BASE, 2, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_VOLUME_OFFLINE = &H0056C00C???   ' CTL_CODE(IOCTL_VOLUME_BASE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'//
'// IOCTL_VOLUME_ONLINE
'// IOCTL_VOLUME_OFFLINE
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     None
'//

'#endif  // NTDDI_VERSION >= NTDDI_WIN2K

'#if (NTDDI_VERSION >= NTDDI_WINXP)

'//
'// IOCTL to determine  whether  the specified
'// volume resides on a disk that is an online
'// cluster resource or not.
'//

%IOCTL_VOLUME_IS_CLUSTERED            = &H00560030???  ' CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'// IOCTL_VOLUME_IS_CLUSTERED
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     None
'//

'//
'// IOCTL to query the attributes on volumes.
'//

%IOCTL_VOLUME_GET_GPT_ATTRIBUTES = &H00560038???    ' CTL_CODE(IOCTL_VOLUME_BASE, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)

'//
'// IOCTL_VOLUME_GET_GPT_ATTRIBUTES
'//
'// Input Buffer:
'//     None
'//
'// Output Buffer:
'//     Structure of type VOLUME_GET_GPT_ATTRIBUTES_INFORMATION
'//

' // Size = 8 bytes
TYPE VOLUME_GET_GPT_ATTRIBUTES_INFORMATION QWORD
   ' // Specifies all the attributes
   ' // associated with this volume.
   GptAttributes AS QUAD   ' DWORDLONG
END TYPE

'#endif  // NTDDI_VERSION >= NTDDI_WINXP
