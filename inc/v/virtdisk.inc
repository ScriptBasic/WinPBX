' ########################################################################################
' Microsoft Windows
' File: VirtDisk.inc
' Contents: Virtual Disk user mode interface
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VIRTDISK_INC = 1

#INCLUDE ONCE "windows.inc"

'#if ((WINVER >= _WIN32_WINNT_WIN7) || defined(VIRTDISK_DEFINE_FLAGS))

'//
'// Identifiers for virtual storage types and providers
'//

#IF NOT %DEF(%VIRTUAL_STORAGE_TYPE_DEFINED)
%VIRTUAL_STORAGE_TYPE_DEFINED = 1
' // Size = 20 bytes
TYPE VIRTUAL_STORAGE_TYPE DWORD
   DeviceId AS DWORD   ' ULONG
   VendorId AS GUID    ' GUID
END TYPE
#ENDIF

'#ifdef DEFINE_GUID
$VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN = GUID$("{00000000-0000-0000-0000-000000000000}")

'// {EC984AEC-A0F9-47e9-901F-71415A66345B}
$VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT = GUID$("{EC984AEC-A0F9-47e9-901F-71415A66345B}")
'#endif

%VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN = 0
%VIRTUAL_STORAGE_TYPE_DEVICE_ISO     = 1
%VIRTUAL_STORAGE_TYPE_DEVICE_VHD     = 2

'#if !defined(VIRTDISK_DEFINE_FLAGS)


'//
'// CreateVirtualDisk
'//

'//
'// This value causes the implementation defaults to be used for block size:
'//
'// Fixed VHDs: 0 is the only valid value since block size is N/A.
'// Dynamic VHDs: The default block size will be used (2 MB, subject to change).
'// Differencing VHDs: 0 causes the parent VHD's block size to be used.
'//
%CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE = 0

'// Default sector size is 512B
%CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_SECTOR_SIZE = &H200


'// Version definitions
' enum CREATE_VIRTUAL_DISK_VERSION
%CREATE_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%CREATE_VIRTUAL_DISK_VERSION_1           = 1

'// Versioned CreateVirtualDisk parameter structure

' // Size = 40 bytes
TYPE CREATE_VIRTUAL_DISK_PARAMETERS_VERSION1   ' Must be 8 byte aligned
   UniqueId          AS GUID           ' GUID
   MaximumSize       AS QUAD           ' ULONGLONG
   BlockSizeInBytes  AS DWORD          ' ULONG
   SectorSizeInBytes AS DWORD          ' ULONG
   ParentPath        AS WSTRINGZ PTR   ' PCWSTR
   SourcePath        AS WSTRINGZ PTR   ' PCWSTR
END TYPE

' // Size = 40 bytes
UNION CREATE_VIRTUAL_DISK_PARAMETERS_UNION   ' Must be 8 byte aligned
   Version1 AS CREATE_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 48 bytes
TYPE CREATE_VIRTUAL_DISK_PARAMETERS QWORD FILL  ' Must be 8 byte aligned
   Version AS LONG   ' CREATE_VIRTUAL_DISK_VERSION enum
   CREATE_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE

'// Flags for CreateVirtualDisk
' enum CREATE_VIRTUAL_DISK_FLAG
%CREATE_VIRTUAL_DISK_FLAG_NONE                     = &H00000000???

'// Pre-allocate all physical space necessary for the virtual
'// size of the disk (e.g. a fixed VHD).
%CREATE_VIRTUAL_DISK_FLAG_FULL_PHYSICAL_ALLOCATION = &H00000001???


'// The default RW Depth parameter value
%OPEN_VIRTUAL_DISK_RW_DEPTH_DEFAULT = 1


'// Version definitions
' enum OPEN_VIRTUAL_DISK_VERSION
%OPEN_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%OPEN_VIRTUAL_DISK_VERSION_1           = 1


'// Versioned OpenVirtualDisk parameter structure

' // Size = 4 bytes
TYPE OPEN_VIRTUAL_DISK_PARAMETERS_VERSION1 DWORD
   RWDepth AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
UNION OPEN_VIRTUAL_DISK_PARAMETERS_UNION DWORD
   Version1 AS OPEN_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 8 bytes
TYPE OPEN_VIRTUAL_DISK_PARAMETERS DWORD
   Version AS LONG   ' OPEN_VIRTUAL_DISK_VERSION enum
   OPEN_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE

'#endif // VIRTDISK_DEFINE_FLAGS

'//
'//  Access Mask for OpenVirtualDisk and CreateVirtualDisk.  The virtual
'//  disk drivers expose file objects as handles therefore we map
'//  it into that AccessMask space.
'//

' enum _VIRTUAL_DISK_ACCESS_MASK
%VIRTUAL_DISK_ACCESS_ATTACH_RO           = &H00010000???
%VIRTUAL_DISK_ACCESS_ATTACH_RW           = &H00020000???
%VIRTUAL_DISK_ACCESS_DETACH              = &H00040000???
%VIRTUAL_DISK_ACCESS_GET_INFO            = &H00080000???
%VIRTUAL_DISK_ACCESS_CREATE              = &H00100000???
%VIRTUAL_DISK_ACCESS_METAOPS             = &H00200000???
%VIRTUAL_DISK_ACCESS_READ                = &H000d0000???
%VIRTUAL_DISK_ACCESS_ALL                 = &H003f0000???

' //
' // A special flag to be used to test if the virtual disk needs to be
' // opened for write.
' //

%VIRTUAL_DISK_ACCESS_WRITABLE            = &H00320000???


'// Flags for OpenVirtualDisk
' enum OPEN_VIRTUAL_DISK_FLAG

%OPEN_VIRTUAL_DISK_FLAG_NONE             = &H00000000???

' // Open the backing store without opening any differencing chain parents.
' // This allows one to fixup broken parent links.
%OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS       = &H00000001???

' // The backing store being opened is an empty file. Do not perform virtual
' // disk verification.
%OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE       = &H00000002???

' // This flag is only specified at boot time to load the system disk
' // during virtual disk boot.  Must be kernel mode to specify this flag.
%OPEN_VIRTUAL_DISK_FLAG_BOOT_DRIVE       = &H00000004???

DECLARE FUNCTION OpenVirtualDisk IMPORT "VirtDisk.dll" ALIAS "OpenVirtualDisk" ( _
   BYREF VirtualStorageType AS VIRTUAL_STORAGE_TYPE _   ' __in     PVIRTUAL_STORAGE_TYPE         VirtualStorageType
 , BYREF Path AS WSTRINGZ _                             ' __in     PCWSTR                        Path
 , BYVAL VirtualDiskAccessMask AS DWORD _               ' __in     VIRTUAL_DISK_ACCESS_MASK      VirtualDiskAccessMask
 , BYVAL Flags AS DWORD _                               ' __in     OPEN_VIRTUAL_DISK_FLAG        Flags
 , BYREF Parameters AS OPEN_VIRTUAL_DISK_PARAMETERS _   ' __in_opt POPEN_VIRTUAL_DISK_PARAMETERS Parameters
 , BYREF Handle AS DWORD _                              ' __out    PHANDLE                       Handle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CreateVirtualDisk IMPORT "VirtDisk.dll" ALIAS "CreateVirtualDisk" ( _
   BYREF VirtualStorageType AS VIRTUAL_STORAGE_TYPE _   ' __in     PVIRTUAL_STORAGE_TYPE         VirtualStorageType
 , BYREF Path AS WSTRINGZ _                             ' __in     PCWSTR                        Path
 , BYVAL VirtualDiskAccessMask AS DWORD _               ' __in     VIRTUAL_DISK_ACCESS_MASK      VirtualDiskAccessMask
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in_opt PSECURITY_DESCRIPTOR            SecurityDescriptor
 , BYVAL Flags AS DWORD _                               ' __in     CREATE_VIRTUAL_DISK_FLAG        Flags
 , BYVAL ProviderSpecificFlags AS DWORD _               ' __in     ULONG                           ProviderSpecificFlags
 , BYREF Parameters AS CREATE_VIRTUAL_DISK_PARAMETERS _ ' __in     PCREATE_VIRTUAL_DISK_PARAMETERS Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED                    Overlapped
 , BYREF Handle AS DWORD _                              ' __out    PHANDLE                         Handle
 ) AS DWORD                                             ' DWORD

'//
'// AttachVirtualDisk
'//

'// Version definitions
' enum ATTACH_VIRTUAL_DISK_VERSION
%ATTACH_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%ATTACH_VIRTUAL_DISK_VERSION_1           = 1

'// Versioned parameter structure for AttachVirtualDisk

' // Size = 4 bytes
TYPE ATTACH_VIRTUAL_DISK_PARAMETERS_VERSION1 DWORD
   Reserved AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
UNION ATTACH_VIRTUAL_DISK_PARAMETERS_UNION DWORD
   Version1 AS ATTACH_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 8 bytes
TYPE ATTACH_VIRTUAL_DISK_PARAMETERS DWORD
   Version AS LONG   ' ATTACH_VIRTUAL_DISK_VERSION enum
   ATTACH_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE

'#endif // VIRTDISK_DEFINE_FLAGS

'// Flags for AttachVirtualDisk
' enum ATTACH_VIRTUAL_DISK_FLAG
%ATTACH_VIRTUAL_DISK_FLAG_NONE                = &H00000000???

'// Attach the disk as read only
%ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY           = &H00000001???

' // Will cause all volumes on the disk to be mounted
' // without drive letters.
' //
%ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER     = &H00000002???

' // Will decouple the disk lifetime from that of the VirtualDiskHandle.
' // The disk will be attached until an explicit call is made to
' // DetachVirtualDisk??? even if all handles are closed.
%ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME  = &H00000004???

' // Indicates that the drive will not be attached to
' // the local system (but rather to a VM).
%ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST       = &H00000008???

DECLARE FUNCTION AttachVirtualDisk IMPORT "VirtDisk.dll" ALIAS "AttachVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in     HANDLE                             VirtualDiskHandle
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in_opt PSECURITY_DESCRIPTOR               SecurityDescriptor
 , BYVAL Flags AS DWORD _                               ' __in     ATTACH_VIRTUAL_DISK_FLAG           Flags
 , BYVAL ProviderSpecificFlags AS DWORD _               ' __in     ULONG                              ProviderSpecificFlags
 , BYREF Parameters AS ATTACH_VIRTUAL_DISK_PARAMETERS _ ' __in_opt PATTACH_VIRTUAL_DISK_PARAMETERS    Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED                       Overlapped
 ) AS DWORD                                             ' DWORD

'//
'// DetachVirtualDisk
'//

'// Flags for DetachVirtualDisk
' enum DETACH_VIRTUAL_DISK_FLAG
%DETACH_VIRTUAL_DISK_FLAG_NONE                = &H00000000???

DECLARE FUNCTION DetachVirtualDisk IMPORT "VirtDisk.dll" ALIAS "DetachVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in     HANDLE                             VirtualDiskHandle
 , BYVAL Flags AS DWORD _                               ' __in     DETACH_VIRTUAL_DISK_FLAG           Flags
 , BYVAL ProviderSpecificFlags AS DWORD _               ' __in     ULONG                              ProviderSpecificFlags
 ) AS DWORD                                             ' DWORD

'//
'// GetVirtualDiskPhysicalPath
'//

DECLARE FUNCTION GetVirtualDiskPhysicalPath IMPORT "VirtDisk.dll" ALIAS "GetVirtualDiskPhysicalPath" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in     HANDLE                   VirtualDiskHandle
 , BYREF DiskPathSizeInBytes AS DWORD _                 ' __inout                           PULONG DiskPathSizeInBytes
 , BYREF DiskPath AS WSTRINGZ _                         ' __out_bcount(DiskPathSizeInBytes) PWSTR DiskPath
 ) AS DWORD                                             ' DWORD

'#endif // VIRTDISK_DEFINE_FLAGS

'//
'// GetStorageDependencyInformation
'//

'// Flags for dependent disks
' enum _DEPENDENT_DISK_FLAG
%DEPENDENT_DISK_FLAG_NONE                 = &H00000000???

' //
' // Multiple files backing the virtual storage device
' //
%DEPENDENT_DISK_FLAG_MULT_BACKING_FILES   = &H00000001???
%DEPENDENT_DISK_FLAG_FULLY_ALLOCATED      = &H00000002???
%DEPENDENT_DISK_FLAG_READ_ONLY            = &H00000004???

' //
' //Backing file of the virtual storage device is not local to the machine
' //
%DEPENDENT_DISK_FLAG_REMOTE               = &H00000008???

' //
' // Volume is the system volume
' //
%DEPENDENT_DISK_FLAG_SYSTEM_VOLUME        = &H00000010???

' //
' // Volume backing the virtual storage device file is the system volume
' //
%DEPENDENT_DISK_FLAG_SYSTEM_VOLUME_PARENT = &H00000020???
%DEPENDENT_DISK_FLAG_REMOVABLE            = &H00000040???

' //
' // Drive letters are not assigned to the volumes
' // on the virtual disk automatically.
' //
%DEPENDENT_DISK_FLAG_NO_DRIVE_LETTER      = &H00000080???
%DEPENDENT_DISK_FLAG_PARENT               = &H00000100???

' //
' // Virtual disk is not attached on the local host
' // (instead attached on a guest VM for instance)
' //
%DEPENDENT_DISK_FLAG_NO_HOST_DISK         = &H00000200???

' //
' // Indicates the lifetime of the disk is not tied
' // to any system handles
' //
%DEPENDENT_DISK_FLAG_PERMANENT_LIFETIME   = &H00000400???


'#if !defined(VIRTDISK_DEFINE_FLAGS)

'// Version definitions
' enum _STORAGE_DEPENDENCY_INFO_VERSION
%STORAGE_DEPENDENCY_INFO_VERSION_UNSPECIFIED = 0
%STORAGE_DEPENDENCY_INFO_VERSION_1           = 1
%STORAGE_DEPENDENCY_INFO_VERSION_2           = 2

'// Parameter structure for GetStorageDependencyInformation
' // Size = 28 bytes
TYPE STORAGE_DEPENDENCY_INFO_TYPE_1 DWORD
   DependencyTypeFlags   AS DWORD                  ' DEPENDENT_DISK_FLAG enum
   ProviderSpecificFlags AS DWORD                  ' ULONG
   VirtualStorageType    AS VIRTUAL_STORAGE_TYPE   ' VIRTUAL_STORAGE_TYPE
END TYPE


'// Parameter structure for GetStorageDependencyInformation
' // Size = 48 bytes
TYPE STORAGE_DEPENDENCY_INFO_TYPE_2 DWORD
   DependencyTypeFlags         AS DWORD                  ' DEPENDENT_DISK_FLAG enum
   ProviderSpecificFlags       AS DWORD                  ' ULONG
   VirtualStorageType          AS VIRTUAL_STORAGE_TYPE   ' VIRTUAL_STORAGE_TYPE
   AncestorLevel               AS DWORD                  ' ULONG
   DependencyDeviceName        AS WSTRINGZ PTR           ' PWSTR
   HostVolumeName              AS WSTRINGZ PTR           ' PWSTR
   DependentVolumeName         AS WSTRINGZ PTR           ' PWSTR
   DependentVolumeRelativePath AS WSTRINGZ PTR           ' PWSTR
END TYPE


'// Parameter structure for GetStorageDependencyInformation

' // Size = 48 bytes
UNION STORAGE_DEPENDENCY_INFO_UNION DWORD
   Version1Entries(0) AS STORAGE_DEPENDENCY_INFO_TYPE_1   ' STORAGE_DEPENDENCY_INFO_TYPE_1 Version1Entries[]
   Version2Entries(0) AS STORAGE_DEPENDENCY_INFO_TYPE_2   ' STORAGE_DEPENDENCY_INFO_TYPE_2 Version2Entries[]
END UNION

' // Size = 56 bytes
TYPE STORAGE_DEPENDENCY_INFO DWORD
   Version       AS LONG    ' STORAGE_DEPENDENCY_INFO_VERSION
   NumberEntries AS DWORD   ' ULONG
   STORAGE_DEPENDENCY_INFO_UNION
END TYPE

'#endif // VIRTDISK_DEFINE_FLAGS

'// Flags for GetStorageDependencyInformation
' enum _GET_STORAGE_DEPENDENCY_FLAG
%GET_STORAGE_DEPENDENCY_FLAG_NONE         = &H00000000???

' // Return information for volumes or disks hosting the volume specified
' // If not set, returns info about volumes or disks being hosted by
' // the volume or disk specified
%GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES = &H00000001???

' //  The handle provided is to a disk, not volume or file
%GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE  = &H00000002???

%GET_STORAGE_DEPENDENCY_FLAG_PARENTS = %GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES


DECLARE FUNCTION GetStorageDependencyInformation IMPORT "VirtDisk.dll" ALIAS "GetStorageDependencyInformation" ( _
   BYVAL ObjectHandle AS DWORD _                        ' __in        HANDLE                      ObjectHandle
 , BYVAL Flags AS DWORD _                               ' __in        GET_STORAGE_DEPENDENCY_FLAG Flags
 , BYVAL StorageDependencyInfoSize AS DWORD _           ' __in        ULONG                       StorageDependencyInfoSize
 , BYREF StorageDependencyInfo AS STORAGE_DEPENDENCY_INFO _ '  __inout     PSTORAGE_DEPENDENCY_INFO    StorageDependencyInfo
 , BYREF SizeUsed AS DWORD _                            ' __inout_opt PULONG                      SizeUsed
 ) AS DWORD                                             ' DWORD


'//
'// GetVirtualDiskInformation
'//

'// Version definitions
' enum GET_VIRTUAL_DISK_INFO_VERSION
%GET_VIRTUAL_DISK_INFO_UNSPECIFIED          = 0
%GET_VIRTUAL_DISK_INFO_SIZE                 = 1
%GET_VIRTUAL_DISK_INFO_IDENTIFIER           = 2
%GET_VIRTUAL_DISK_INFO_PARENT_LOCATION      = 3
%GET_VIRTUAL_DISK_INFO_PARENT_IDENTIFIER    = 4
%GET_VIRTUAL_DISK_INFO_PARENT_TIMESTAMP     = 5
%GET_VIRTUAL_DISK_INFO_VIRTUAL_STORAGE_TYPE = 6
%GET_VIRTUAL_DISK_INFO_PROVIDER_SUBTYPE     = 7


'// Versioned parameter structure for GetVirtualDiskInformation

' // Size = 24 bytes
TYPE GET_VIRTUAL_DISK_INFO_SIZE   ' Must be 8 byte aligned
   VirtualSize  AS QUAD    ' ULONGLONG
   PhysicalSize AS QUAD    ' ULONGLONG
   BlockSize    AS DWORD   ' ULONG
   SectorSize   AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE GET_VIRTUAL_DISK_INFO_PARENTLOCATION DWORD
   ParentResolved          AS LONG           ' BOOL
   ParentLocationBuffer(0) AS WSTRINGZ PTR   ' WCHAR ParentLocationBuffer[1] // MultiSz string
END TYPE

' // Size = 24 bytes
UNION GET_VIRTUAL_DISK_INFO_UNION   ' Must be 8 byte aligned
   Size               AS GET_VIRTUAL_DISK_INFO_SIZE
   Identifier         AS GUID                                   ' GUID
   ParentLocation     AS GET_VIRTUAL_DISK_INFO_PARENTLOCATION
   ParentIdentifier   AS GUID                                   ' GUID
   ParentTimestamp    AS DWORD                                  ' ULONG
   VirtualStorageType AS VIRTUAL_STORAGE_TYPE                   ' VIRTUAL_STORAGE_TYPE
   ProviderSubtype    AS DWORD                                  ' ULONG
END UNION

' // Size = 32 bytes
TYPE GET_VIRTUAL_DISK_INFO QWORD FILL   ' Must be 8 byte aligned
   Version AS LONG   ' GET_VIRTUAL_DISK_INFO_VERSION
   GET_VIRTUAL_DISK_INFO_UNION
END TYPE


DECLARE FUNCTION GetVirtualDiskInformation IMPORT "VirtDisk.dll" ALIAS "GetVirtualDiskInformation" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in        HANDLE                  VirtualDiskHandle
 , BYREF VirtualDiskInfoSize AS DWORD _                 ' __inout     PULONG                  VirtualDiskInfoSize
 , BYREF VirtualDiskInfo AS GET_VIRTUAL_DISK_INFO _     ' __inout     PGET_VIRTUAL_DISK_INFO  VirtualDiskInfo
 , BYREF SizeUsed AS DWORD _                            ' __inout_opt PULONG                  SizeUsed
 ) AS DWORD                                             ' DWORD


'//
'// SetVirtualDiskInformation
'//

'// Version definitions
' enum SET_VIRTUAL_DISK_INFO_VERSION
%SET_VIRTUAL_DISK_INFO_UNSPECIFIED = 0
%SET_VIRTUAL_DISK_INFO_PARENT_PATH = 1
%SET_VIRTUAL_DISK_INFO_IDENTIFIER  = 2


'// Versioned parameter structure for SetVirtualDiskInformation

' // Size = 16 bytes
UNION SET_VIRTUAL_DISK_INFO_UNION
   ParentFilePath   AS WSTRINGZ PTR   ' PCWSTR
   UniqueIdentifier AS GUID           ' GUID
END UNION

' // Size = 20 bytes
TYPE SET_VIRTUAL_DISK_INFO DWORD
   Version AS LONG   ' SET_VIRTUAL_DISK_INFO_VERSION
   SET_VIRTUAL_DISK_INFO_UNION
END TYPE


DECLARE FUNCTION SetVirtualDiskInformation IMPORT "VirtDisk.dll" ALIAS "SetVirtualDiskInformation" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in HANDLE                  VirtualDiskHandle
 , BYREF VirtualDiskInfo AS SET_VIRTUAL_DISK_INFO _     ' __in PSET_VIRTUAL_DISK_INFO  VirtualDiskInfo
 ) AS DWORD                                             ' DWORD


'//
'// GetVirtualDiskOperationProgress
'//

' // Size = 24 bytes
TYPE VIRTUAL_DISK_PROGRESS QWORD FILL   ' Must be 8 byte aligned
   OperationStatus AS DWORD   ' DWORD
   CurrentValue    AS QUAD    ' ULONGLONG
   CompletionValue AS QUAD    ' ULONGLONG
END TYPE


DECLARE FUNCTION GetVirtualDiskOperationProgress IMPORT "VirtDisk.dll" ALIAS "GetVirtualDiskOperationProgress" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in HANDLE                  VirtualDiskHandle
 , BYREF Overlapped AS OVERLAPPED _                     ' __in      LPOVERLAPPED           Overlapped
 , BYREF Progress AS VIRTUAL_DISK_PROGRESS _            ' __out     PVIRTUAL_DISK_PROGRESS Progress
 ) AS DWORD                                             ' DWORD


'//
'// CompactVirtualDisk
'//

'// Version definitions
' enum COMPACT_VIRTUAL_DISK_VERSION
%COMPACT_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%COMPACT_VIRTUAL_DISK_VERSION_1           = 1


'// Versioned structure for CompactVirtualDisk

' // Size = 4 bytes
TYPE COMPACT_VIRTUAL_DISK_PARAMETERS_VERSION1 DWORD
   Reserved AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
UNION COMPACT_VIRTUAL_DISK_PARAMETERS_UNION DWORD
   Version1 AS COMPACT_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 8 bytes
TYPE COMPACT_VIRTUAL_DISK_PARAMETERS DWORD
   Version AS LONG   ' COMPACT_VIRTUAL_DISK_VERSION
   COMPACT_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE


'// Flags for CompactVirtualDisk
' enum COMPACT_VIRTUAL_DISK_FLAG
%COMPACT_VIRTUAL_DISK_FLAG_NONE                 = &H00000000???


DECLARE FUNCTION CompactVirtualDisk IMPORT "VirtDisk.dll" ALIAS "CompactVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in HANDLE VirtualDiskHandle
 , BYVAL Flags AS DWORD _                               ' __in COMPACT_VIRTUAL_DISK_FLAG Flags
 , BYREF Parameters AS COMPACT_VIRTUAL_DISK_PARAMETERS _ ' __in_opt PCOMPACT_VIRTUAL_DISK_PARAMETERS Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED Overlapped
 ) AS DWORD                                             ' DWORD


'//
'// MergeVirtualDisk
'//

'// Version definitions
' enum MERGE_VIRTUAL_DISK_VERSION
%MERGE_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%MERGE_VIRTUAL_DISK_VERSION_1           = 1


'// Versioned parameter structure for MergeVirtualDisk
%MERGE_VIRTUAL_DISK_DEFAULT_MERGE_DEPTH = 1

' // Size = 4 bytes
TYPE MERGE_VIRTUAL_DISK_PARAMETERS_VERSION1 DWORD
   MergeDepth AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
UNION MERGE_VIRTUAL_DISK_PARAMETERS_UNION DWORD
   Version1 AS MERGE_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 8 bytes
TYPE MERGE_VIRTUAL_DISK_PARAMETERS DWORD
   Version AS LONG   ' MERGE_VIRTUAL_DISK_VERSION
   MERGE_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE


'// Flags for MergeVirtualDisk
' enum MERGE_VIRTUAL_DISK_FLAG
%MERGE_VIRTUAL_DISK_FLAG_NONE                 = &H00000000???


DECLARE FUNCTION MergeVirtualDisk IMPORT "VirtDisk.dll" ALIAS "MergeVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in HANDLE VirtualDiskHandle
 , BYVAL Flags AS DWORD _                               ' __in MERGE_VIRTUAL_DISK_FLAG Flags
 , BYREF Parameters AS MERGE_VIRTUAL_DISK_PARAMETERS _  ' __in PMERGE_VIRTUAL_DISK_PARAMETERS Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED Overlapped
 ) AS DWORD                                             ' DWORD


'//
'// ExpandVirtualDisk
'//

'// Version definitions
' enum EXPAND_VIRTUAL_DISK_VERSION
%EXPAND_VIRTUAL_DISK_VERSION_UNSPECIFIED = 0
%EXPAND_VIRTUAL_DISK_VERSION_1           = 1


'// Versioned parameter structure for ExpandVirtualDisk

' // Size = 8 bytes
TYPE EXPAND_VIRTUAL_DISK_PARAMETERS_VERSION1
   NewSize AS QUAD   ' ULONGLONG
END TYPE

' // Size = 8 bytes
UNION EXPAND_VIRTUAL_DISK_PARAMETERS_UNION
   Version1 AS EXPAND_VIRTUAL_DISK_PARAMETERS_VERSION1
END UNION

' // Size = 16 bytes
TYPE EXPAND_VIRTUAL_DISK_PARAMETERS QWORD FILL   ' Must be 8 byte aligned
   Version AS LONG   ' EXPAND_VIRTUAL_DISK_VERSION
   EXPAND_VIRTUAL_DISK_PARAMETERS_UNION
END TYPE


'// Flags for ExpandVirtualDisk
' enum EXPAND_VIRTUAL_DISK_FLAG
%EXPAND_VIRTUAL_DISK_FLAG_NONE                 = &H00000000???


DECLARE FUNCTION ExpandVirtualDisk IMPORT "VirtDisk.dll" ALIAS "ExpandVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in HANDLE VirtualDiskHandle
 , BYVAL Flags AS DWORD _                               ' __in EXPAND_VIRTUAL_DISK_FLAG Flags
 , BYREF Parameters AS EXPAND_VIRTUAL_DISK_PARAMETERS _  ' __in PEXPAND_VIRTUAL_DISK_PARAMETERS Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED Overlapped
 ) AS DWORD                                             ' DWORD

'#endif // VIRTDISK_DEFINE_FLAGS

'//
'//  The Surface and Unsurface API names are deprecated.  Use Attach/Detach versions
'//  instead.  If you use any of these defines below your code will break post Win7.
'//

'#define SurfaceVirtualDisk                           AttachVirtualDisk
'#define UnsurfaceVirtualDisk                         DetachVirtualDisk

DECLARE FUNCTION SurfaceVirtualDisk IMPORT "VirtDisk.dll" ALIAS "AttachVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in     HANDLE                             VirtualDiskHandle
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in_opt PSECURITY_DESCRIPTOR               SecurityDescriptor
 , BYVAL Flags AS DWORD _                               ' __in     ATTACH_VIRTUAL_DISK_FLAG           Flags
 , BYVAL ProviderSpecificFlags AS DWORD _               ' __in     ULONG                              ProviderSpecificFlags
 , BYREF Parameters AS ATTACH_VIRTUAL_DISK_PARAMETERS _ ' __in_opt PATTACH_VIRTUAL_DISK_PARAMETERS    Parameters
 , BYREF Overlapped AS OVERLAPPED _                     ' __in_opt LPOVERLAPPED                       Overlapped
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION UnsurfaceVirtualDisk IMPORT "VirtDisk.dll" ALIAS "DetachVirtualDisk" ( _
   BYVAL VirtualDiskHandle AS DWORD _                   ' __in     HANDLE                             VirtualDiskHandle
 , BYVAL Flags AS DWORD _                               ' __in     DETACH_VIRTUAL_DISK_FLAG           Flags
 , BYVAL ProviderSpecificFlags AS DWORD _               ' __in     ULONG                              ProviderSpecificFlags
 ) AS DWORD                                             ' DWORD

'#define VIRTUAL_DISK_ACCESS_SURFACE_RO               VIRTUAL_DISK_ACCESS_ATTACH_RO
'#define VIRTUAL_DISK_ACCESS_SURFACE_RW               VIRTUAL_DISK_ACCESS_ATTACH_RW
'#define VIRTUAL_DISK_ACCESS_UNSURFACE                VIRTUAL_DISK_ACCESS_DETACH
'#define SURFACE_VIRTUAL_DISK_VERSION_UNSPECIFIED     ATTACH_VIRTUAL_DISK_VERSION_UNSPECIFIED
'#define SURFACE_VIRTUAL_DISK_VERSION_1               ATTACH_VIRTUAL_DISK_VERSION_1
'#define SURFACE_VIRTUAL_DISK_VERSION                 ATTACH_VIRTUAL_DISK_VERSION
'#define _SURFACE_VIRTUAL_DISK_VERSION                _ATTACH_VIRTUAL_DISK_VERSION
'#define SURFACE_VIRTUAL_DISK_PARAMETERS              ATTACH_VIRTUAL_DISK_PARAMETERS
'#define PSURFACE_VIRTUAL_DISK_PARAMETERS             PATTACH_VIRTUAL_DISK_PARAMETERS
'#define _SURFACE_VIRTUAL_DISK_PARAMETERS             _ATTACH_VIRTUAL_DISK_PARAMETERS

' enum SURFACE_VIRTUAL_DISK_FLAG
%SURFACE_VIRTUAL_DISK_FLAG_NONE               = &H00000000???
%SURFACE_VIRTUAL_DISK_FLAG_READ_ONLY          = &H00000001???
%SURFACE_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER    = &H00000002???
%SURFACE_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME = &H00000004???
%SURFACE_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST      = &H00000008???

' enum UNSURFACE_VIRTUAL_DISK_FLAG
%UNSURFACE_VIRTUAL_DISK_FLAG_NONE             = &H00000000???

'#endif

'//  End deprecated APIs

'#endif // WIN32_WINNT_WIN7
