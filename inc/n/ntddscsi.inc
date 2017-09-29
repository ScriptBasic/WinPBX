' ########################################################################################
' Microsoft Windows
' File: ntddscsi.inc
' Contents: Constants and types for accessing the SCSI port adapters
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTDDSCSI_INC = 1

'#ifdef DEFINE_GUID
$ScsiRawInterfaceGuid = GUID$("{53f56309-b6bf-11d0-94f2-00a0c91efb8b}")
$WmiScsiAddressGuid = GUID$("{53f5630f-b6bf-11d0-94f2-00a0c91efb8b}")
'#endif

#INCLUDE ONCE "winioctl.inc"

'//
'// Device Name - this string is the name of the device.  It is the name
'// that should be passed to NtOpenFile when accessing the device.
'//
'// Note:  For devices that support multiple units, it should be suffixed
'//        with the Ascii representation of the unit number.
'//

%IOCTL_SCSI_BASE                 = %FILE_DEVICE_CONTROLLER
%FILE_DEVICE_SCSI                = &H0000001b???

'#define DD_SCSI_DEVICE_NAME "\\Device\\ScsiPort"
$DD_SCSI_DEVICE_NAME = "\Device\ScsiPort"

'//
'// NtDeviceIoControlFile IoControlCode values for this device.
'//
'// Warning:  Remember that the low two bits of the code specify how the
'//           buffers are passed to the driver!
'//

%IOCTL_SCSI_PASS_THROUGH             = &H0004D004???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_SCSI_MINIPORT                 = &H0004D008???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0402, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_SCSI_GET_INQUIRY_DATA         = &H0004100C???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0403, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_SCSI_GET_CAPABILITIES         = &H00041010???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0404, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_SCSI_PASS_THROUGH_DIRECT      = &H0004D014???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_SCSI_GET_ADDRESS              = &H00041018???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0406, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_SCSI_RESCAN_BUS               = &H0004101C???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0407, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_SCSI_GET_DUMP_POINTERS        = &H00041020???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0408, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_SCSI_FREE_DUMP_POINTERS       = &H00041024???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0409, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_IDE_PASS_THROUGH              = &H0004D028???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x040a, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_ATA_PASS_THROUGH              = &H0004D02C???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x040b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_ATA_PASS_THROUGH_DIRECT       = &H0004D030???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x040c, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_ATA_MINIPORT                  = &H0004D034???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x040d, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_MINIPORT_PROCESS_SERVICE_IRP  = &H0004D038???   ' CTL_CODE(IOCTL_SCSI_BASE,  0x040e, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_MPIO_PASS_THROUGH_PATH        = &H0004D03C???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x040f, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
%IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT = &H0004D040???   ' CTL_CODE(IOCTL_SCSI_BASE, 0x0410, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

'//
'// Non Volatile Cache support
'//

'#define IOCTL_SCSI_MINIPORT_NVCACHE           ((FILE_DEVICE_SCSI << 16) + 0x0600)
%IOCTL_SCSI_MINIPORT_NVCACHE = &H001B0600???

'//
'// Define the SCSI pass through structure.
'//

' // Size = 44 bytes
TYPE SCSI_PASS_THROUGH DWORD FILL
   Length             AS WORD    ' USHORT
   ScsiStatus         AS BYTE    ' UCHAR
   PathId             AS BYTE    ' UCHAR
   TargetId           AS BYTE    ' UCHAR
   Lun                AS BYTE    ' UCHAR
   CdbLength          AS BYTE    ' UCHAR
   SenseInfoLength    AS BYTE    ' UCHAR
   DataIn             AS BYTE    ' UCHAR
   DataTransferLength AS DWORD   ' ULONG
   TimeOutValue       AS DWORD   ' ULONG
   DataBufferOffset   AS DWORD   ' ULONG_PTR
   SenseInfoOffset    AS DWORD   ' ULONG
   Cdb(15)            AS BYTE    ' UCHAR [16]
END TYPE

'//
'// Define the SCSI pass through direct structure.
'//

' // Size = 44 bytes
TYPE SCSI_PASS_THROUGH_DIRECT DWORD FILL
   Length             AS WORD    ' USHORT
   ScsiStatus         AS BYTE    ' UCHAR
   PathId             AS BYTE    ' UCHAR
   TargetId           AS BYTE    ' UCHAR
   Lun                AS BYTE    ' UCHAR
   CdbLength          AS BYTE    ' UCHAR
   SenseInfoLength    AS BYTE    ' UCHAR
   DataIn             AS BYTE    ' UCHAR
   DataTransferLength AS DWORD   ' ULONG
   TimeOutValue       AS DWORD   ' ULONG
   DataBuffer         AS DWORD   ' PVOID
   SenseInfoOffset    AS DWORD   ' ULONG
   Cdb(15)            AS BYTE    ' UCHAR [16]
END TYPE


'//
'// Define the SCSI pass through direct structure for Win64 (thunking).
'//
'#if defined(_WIN64)

' // Size = 44 bytes
TYPE SCSI_PASS_THROUGH32 DWORD FILL
   Length             AS WORD    ' USHORT
   ScsiStatus         AS BYTE    ' UCHAR
   PathId             AS BYTE    ' UCHAR
   TargetId           AS BYTE    ' UCHAR
   Lun                AS BYTE    ' UCHAR
   CdbLength          AS BYTE    ' UCHAR
   SenseInfoLength    AS BYTE    ' UCHAR
   DataIn             AS BYTE    ' UCHAR
   DataTransferLength AS DWORD   ' ULONG
   TimeOutValue       AS DWORD   ' ULONG
   DataBufferOffset   AS DWORD   ' ULONG32
   SenseInfoOffset    AS DWORD   ' ULONG
   Cdb(15)            AS BYTE    ' UCHAR [16]
END TYPE

'//
'// Define the SCSI pass through direct structure.
'//

' // Size = 44 bytes
TYPE SCSI_PASS_THROUGH_DIRECT32 DWORD FILL
   Length             AS WORD    ' USHORT
   ScsiStatus         AS BYTE    ' UCHAR
   PathId             AS BYTE    ' UCHAR
   TargetId           AS BYTE    ' UCHAR
   Lun                AS BYTE    ' UCHAR
   CdbLength          AS BYTE    ' UCHAR
   SenseInfoLength    AS BYTE    ' UCHAR
   DataIn             AS BYTE    ' UCHAR
   DataTransferLength AS DWORD   ' ULONG
   TimeOutValue       AS DWORD   ' ULONG
   DataBuffer         AS DWORD   ' VOID * POINTER_32
   SenseInfoOffset    AS DWORD   ' ULONG
   Cdb(15)            AS BYTE    ' UCHAR [16]
END TYPE

'#endif

'//
'// ATA pass through structure
'//

' // Size = 40 bytes
TYPE ATA_PASS_THROUGH_EX DWORD FILL
   Length              AS WORD    ' USHORT
   AtaFlags            AS WORD    ' USHORT
   PathId              AS BYTE    ' UCHAR
   TargetId            AS BYTE    ' UCHAR
   Lun                 AS BYTE    ' UCHAR
   ReservedAsUchar     AS BYTE    ' UCHAR
   DataTransferLength  AS DWORD   ' ULONG
   TimeOutValue        AS DWORD   ' ULONG
   ReservedAsUlong     AS DWORD   ' ULONG
   DataBufferOffset    AS DWORD   ' ULONG_PTR
   PreviousTaskFile(7) AS BYTE    ' UCHAR [8]
   CurrentTaskFile(7)  AS BYTE    ' UCHAR [8]
END TYPE

'//
'// ATA pass through direct structure.
'//

' // Size = 40 bytes
TYPE ATA_PASS_THROUGH_DIRECT DWORD FILL
   Length              AS WORD    ' USHORT
   AtaFlags            AS WORD    ' USHORT
   PathId              AS BYTE    ' UCHAR
   TargetId            AS BYTE    ' UCHAR
   Lun                 AS BYTE    ' UCHAR
   ReservedAsUchar     AS BYTE    ' UCHAR
   DataTransferLength  AS DWORD   ' ULONG
   TimeOutValue        AS DWORD   ' ULONG
   ReservedAsUlong     AS DWORD   ' ULONG
   DataBuffer          AS DWORD   ' PVOID
   PreviousTaskFile(7) AS BYTE    ' UCHAR [8]
   CurrentTaskFile(7)  AS BYTE    ' UCHAR [8]
END TYPE

'//
'// Define the ATA pass through direct structure for Win64 (thunking).
'//
'#if defined(_WIN64)

' // Size = 40 bytes
TYPE ATA_PASS_THROUGH_EX32 DWORD FILL
   Length              AS WORD    ' USHORT
   AtaFlags            AS WORD    ' USHORT
   PathId              AS BYTE    ' UCHAR
   TargetId            AS BYTE    ' UCHAR
   Lun                 AS BYTE    ' UCHAR
   ReservedAsUchar     AS BYTE    ' UCHAR
   DataTransferLength  AS DWORD   ' ULONG
   TimeOutValue        AS DWORD   ' ULONG
   ReservedAsUlong     AS DWORD   ' ULONG
   DataBufferOffset    AS DWORD   ' ULONG32
   PreviousTaskFile(7) AS BYTE    ' UCHAR [8]
   CurrentTaskFile(7)  AS BYTE    ' UCHAR [8]
END TYPE

'//
'// ATA pass through direct structure.
'//

' // Size = 40 bytes
TYPE ATA_PASS_THROUGH_DIRECT32 DWORD FILL
   Length              AS WORD    ' USHORT
   AtaFlags            AS WORD    ' USHORT
   PathId              AS BYTE    ' UCHAR
   TargetId            AS BYTE    ' UCHAR
   Lun                 AS BYTE    ' UCHAR
   ReservedAsUchar     AS BYTE    ' UCHAR
   DataTransferLength  AS DWORD   ' ULONG
   TimeOutValue        AS DWORD   ' ULONG
   ReservedAsUlong     AS DWORD   ' ULONG
   DataBuffer          AS DWORD   ' VOID * POINTER_32
   PreviousTaskFile(7) AS BYTE    ' UCHAR [8]
   CurrentTaskFile(7)  AS BYTE    ' UCHAR [8]
END TYPE

'#endif

'//
'// ATA Pass Through Flags
'//
%ATA_FLAGS_DRDY_REQUIRED = &H1    ' (1 << 0)
%ATA_FLAGS_DATA_IN       = &H2    ' (1 << 1)
%ATA_FLAGS_DATA_OUT      = &H4    ' (1 << 2)
%ATA_FLAGS_48BIT_COMMAND = &H8    ' (1 << 3)
%ATA_FLAGS_USE_DMA       = &H10   ' (1 << 4)
%ATA_FLAGS_NO_MULTIPLE   = &H20   ' (1 << 5)

'//
'// Define header for IOCTL_ATA_MINIPORT
'//

' // Size = 28 bytes
TYPE IDE_IO_CONTROL DWORD FILL
   HeaderLength AS DWORD   ' ULONG
   Signature(7) AS BYTE    ' UCHAR [8]
   Timeout      AS DWORD   ' ULONG
   ControlCode  AS DWORD   ' ULONG
   ReturnStatus AS DWORD   ' ULONG
   DataLength   AS DWORD   ' ULONG
END TYPE

'//
'// Define the structure for IOCTL_MPIO_PASS_THROUGH_PATH.
'//

' // Size = 64 bytes
TYPE MPIO_PASS_THROUGH_PATH QWORD FILL
   PassThrough AS SCSI_PASS_THROUGH
   Version     AS DWORD   ' ULONG
   Length      AS WORD    ' USHORT
   Flags       AS BYTE    ' UCHAR
   PortNumber  AS BYTE    ' UCHAR
   MpioPathId  AS QUAD    ' ULONGLONG
END TYPE

'//
'// Define the structure for IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT.
'//

' // Size = 64 bytes
TYPE MPIO_PASS_THROUGH_PATH_DIRECT QWORD FILL
   PassThrough AS SCSI_PASS_THROUGH_DIRECT
   Version     AS DWORD   ' ULONG
   Length      AS WORD    ' USHORT
   Flags       AS BYTE    ' UCHAR
   PortNumber  AS BYTE    ' UCHAR
   MpioPathId  AS QUAD    ' ULONGLONG
END TYPE


'//
'// Define the IOCTL_MPIO_PASS_THROUGH_PATH structure for Win64 (thunking).
'//

'#if defined(_WIN64)

' // Size = 64 bytes
TYPE MPIO_PASS_THROUGH_PATH32 QWORD FILL
   PassThrough AS SCSI_PASS_THROUGH32
   Version     AS DWORD   ' ULONG
   Length      AS WORD    ' USHORT
   Flags       AS BYTE    ' UCHAR
   PortNumber  AS BYTE    ' UCHAR
   MpioPathId  AS QUAD    ' ULONGLONG
END TYPE

'//
'// Define the IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT structure for Win64 (thunking).
'//

' // Size = 64 bytes
TYPE MPIO_PASS_THROUGH_PATH_DIRECT32 QWORD FILL
   PassThrough AS SCSI_PASS_THROUGH_DIRECT32
   Version     AS DWORD   ' ULONG
   Length      AS WORD    ' USHORT
   Flags       AS BYTE    ' UCHAR
   PortNumber  AS BYTE    ' UCHAR
   MpioPathId  AS QUAD    ' ULONGLONG
END TYPE

'#endif

'//
'// Define SCSI information.
'// Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'//

' // Size = 8 bytes
TYPE SCSI_BUS_DATA DWORD FILL
   NumberOfLogicalUnits AS BYTE    ' UCHAR
   InitiatorBusId       AS BYTE    ' UCHAR
   InquiryDataOffset    AS DWORD   ' ULONG
END TYPE

'//
'// Define SCSI adapter bus information structure..
'// Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'//

' // Size = 12 bytes
TYPE SCSI_ADAPTER_BUS_INFO DWORD FILL
   NumberOfBuses AS BYTE            ' UCHAR
   BusData(0)    AS SCSI_BUS_DATA   ' SCSI_BUS_DATA [1]
END TYPE

'//
'// Define SCSI adapter bus information.
'// Used with the IOCTL_SCSI_GET_INQUIRY_DATA IOCTL.
'//

' // Size = 16 bytes
TYPE SCSI_INQUIRY_DATA DWORD FILL
   PathId                AS BYTE    ' UCHAR
   TargetId              AS BYTE    ' UCHAR
   Lun                   AS BYTE    ' UCHAR
   DeviceClaimed         AS BYTE    ' BOOLEAN
   InquiryDataLength     AS DWORD   ' ULONG
   NextInquiryDataOffset AS DWORD   ' ULONG
   InquiryData(3)        AS BYTE    ' UCHAR [1]
   ' Note: We are using InquiryData(3) instead of InquiryData(0) to keep DWORD alignment
END TYPE

'//
'// Define header for I/O control SRB.
'//

' // Size = 28 bytes
TYPE SRB_IO_CONTROL DWORD
   HeaderLength AS DWORD   ' ULONG
   Signature(7) AS BYTE    ' UCHAR [8]
   Timeout      AS DWORD   ' ULONG
   ControlCode  AS DWORD   ' ULONG
   ReturnCode   AS DWORD   ' ULONG
   Length       AS DWORD   ' ULONG
END TYPE

' // Size = 48 bytes
TYPE NVCACHE_REQUEST_BLOCK QWORD FILL
   NRBSize          AS DWORD   ' ULONG
   Function         AS WORD    ' USHORT
   NRBFlags         AS DWORD   ' ULONG
   NRBStatus        AS DWORD   ' ULONG
   Count            AS DWORD   ' ULONG
   LBA              AS QUAD    ' ULONGLONG
   DataBufSize      AS DWORD   ' ULONG
   NVCacheStatus    AS DWORD   ' ULONG
   NVCacheSubStatus AS DWORD   ' ULONG
   filler           AS DWORD   ' // To keep 8 bytes alignment
END TYPE

%NRB_FUNCTION_NVCACHE_INFO               = &HEC
%NRB_FUNCTION_SPINDLE_STATUS             = &HE5
%NRB_FUNCTION_NVCACHE_POWER_MODE_SET     = &H00
%NRB_FUNCTION_NVCACHE_POWER_MODE_RETURN  = &H01
%NRB_FUNCTION_FLUSH_NVCACHE              = &H14
%NRB_FUNCTION_QUERY_PINNED_SET           = &H12
%NRB_FUNCTION_QUERY_CACHE_MISS           = &H13
%NRB_FUNCTION_ADD_LBAS_PINNED_SET        = &H10
%NRB_FUNCTION_REMOVE_LBAS_PINNED_SET     = &H11
%NRB_FUNCTION_QUERY_ASCENDER_STATUS      = &HD0
%NRB_FUNCTION_QUERY_HYBRID_DISK_STATUS   = &HD1

%NRB_SUCCESS                             = 0
%NRB_ILLEGAL_REQUEST                     = 1
%NRB_INVALID_PARAMETER                   = 2
%NRB_INPUT_DATA_OVERRUN                  = 3
%NRB_INPUT_DATA_UNDERRUN                 = 4
%NRB_OUTPUT_DATA_OVERRUN                 = 5
%NRB_OUTPUT_DATA_UNDERRUN                = 6

' // Size = 24 bytes
TYPE NV_FEATURE_PARAMETER DWORD FILL
   NVPowerModeEnabled AS WORD    ' USHORT
   NVParameterReserv1 AS WORD    ' USHORT
   NVCmdEnabled       AS WORD    ' USHORT
   NVParameterReserv2 AS WORD    ' USHORT
   NVPowerModeVer     AS WORD    ' USHORT
   NVCmdVer           AS WORD    ' USHORT
   NVSize             AS DWORD   ' ULONG // in number of LBA
   NVReadSpeed        AS WORD    ' USHORT // in MB/s
   NVWrtSpeed         AS WORD    ' USHORT
   DeviceSpinUpTime   AS DWORD   ' ULONG // in second
END TYPE

'//
'// SCSI port driver capabilities structure.
'//

' // Size = 24 bytes
TYPE IO_SCSI_CAPABILITIES DWORD FILL
   ' // Length of this structure
   Length                      AS DWORD   ' ULONG
   ' // Maximum transfer size in single SRB
   MaximumTransferLength       AS DWORD   ' ULONG
   ' // Maximum number of physical pages per data buffer
   MaximumPhysicalPages        AS DWORD   ' ULONG
   ' // Async calls from port to class
   SupportedAsynchronousEvents AS DWORD   ' ULONG
   ' // Alignment mask for data transfers.
   AlignmentMask               AS DWORD   ' ULONG
   ' // Supports tagged queuing
   TaggedQueuing               AS BYTE   ' BOOLEAN
   ' // Host adapter scans down for bios devices.
   AdapterScansDown            AS BYTE   ' BOOLEAN
   ' // The host adapter uses programmed I/O.
   AdapterUsesPio              AS BYTE   ' BOOLEAN
   ' // To keep DWORD alignment
   filler                      AS BYTE
END TYPE

' // Size = 8 bytes
TYPE SCSI_ADDRESS DWORD FILL
   Length     AS DWORD   ' ULONG
   PortNumber AS BYTE    ' UCHAR
   PathId     AS BYTE    ' UCHAR
   TargetId   AS BYTE    ' UCHAR
   Lun        AS BYTE    ' UCHAR
END TYPE

'//
'// Define structure for returning crash dump pointers.
'//

'struct _ADAPTER_OBJECT;
%DUMP_POINTERS_VERSION_1        = 1
%DUMP_POINTERS_VERSION_2        = 2
%DUMP_DRIVER_NAME_LENGTH        = 15

' // Size = 8 bytes
TYPE DUMP_POINTERS_VERSION DWORD
   ' // Dump pointers structure version
   Version AS DWORD   ' ULOONG
   ' // Dump pointers structure size
   Size    AS DWORD   ' ULONG
END TYPE

' // Size = 40 bytes
TYPE DUMP_POINTERS QWORD FILL
   AdapterObject         AS DWORD   ' struct _ADAPTER_OBJECT *
   MappedRegisterBase    AS DWORD   ' PVOID
   DumpData              AS DWORD   ' PVOID
   CommonBufferVa        AS DWORD   ' PVOID
   CommonBufferPa        AS QUAD    ' LARGE_INTEGER
   CommonBufferSize      AS DWORD   ' ULONG
   AllocateCommonBuffers AS BYTE    ' BOOLEAN
'#if (NTDDI_VERSION < NTDDI_WINXP)
'    UCHAR Spare1[3];
'#else
'    BOOLEAN UseDiskDump;
'    UCHAR Spare1[2];
'#endif
   UseDiskDump           AS BYTE    ' BOOLEAN
   Spare1(1)             AS BYTE    ' UCHAR [2]
   DeviceObject          AS DWORD   ' PVOID
   filler                AS DWORD   ' // To keep 8 bytes alignment
END TYPE

' // Size = 32 bytes
TYPE DUMP_POINTERS_EX DWORD FILL
   Header                AS DUMP_POINTERS_VERSION
   DumpData              AS DWORD   ' PVOID
   CommonBufferVa        AS DWORD   ' PVOID
   CommonBufferSize      AS DWORD   ' ULOONG
   AllocateCommonBuffers AS BYTE    ' BOOLEAN
   DeviceObject          AS DWORD   ' PVOID
   DriverList            AS DWORD   ' PVOID
END TYPE

' // Size = 64 bytes
TYPE DUMP_DRIVER WORD
   ' // Dump driver list from port driver
   DumpDriverList AS DWORD   ' PVOID
   ' // Name of the driver to be loaded
   DriverName     AS WSTRINGZ * %DUMP_DRIVER_NAME_LENGTH   ' WCHAR
   ' // Driver base name
   BaseName       AS WSTRINGZ * %DUMP_DRIVER_NAME_LENGTH   ' WCHAR
END TYPE


'//
'// Define values for pass-through DataIn field.
'//

%SCSI_IOCTL_DATA_OUT         = 0
%SCSI_IOCTL_DATA_IN          = 1
%SCSI_IOCTL_DATA_UNSPECIFIED = 2

'//
'// Define values for MPIO-pass-through-path Flags field.
'//

%MPIO_IOCTL_FLAG_USE_PATHID      = 1
%MPIO_IOCTL_FLAG_USE_SCSIADDRESS = 2
%MPIO_IOCTL_FLAG_INVOLVE_DSM     = 4
