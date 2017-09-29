' ########################################################################################
' Microsoft Windows
' File: LMDFS.inc
' Contents: Structures, function prototypes, and definitions for the NetDfs API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMDFS_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "lmcons.inc"

'//
'// DFS Volume state
'//

%DFS_VOLUME_STATES              = &HF

%DFS_VOLUME_STATE_OK            = 1
%DFS_VOLUME_STATE_INCONSISTENT  = 2
%DFS_VOLUME_STATE_OFFLINE       = 3
%DFS_VOLUME_STATE_ONLINE        = 4

'//
'// These are valid for setting the volume state on the root
'// These are available to force a resynchronize on the root
'// volume or to put it in a standby mode.
'//
%DFS_VOLUME_STATE_RESYNCHRONIZE = &H10
%DFS_VOLUME_STATE_STANDBY       = &H20

'//
'//  When supported by a DFS namespace, the local state on
'//  the DFS root target is refreshed with information from
'//  the master state in the DFS metadata forcibly.
'//

%DFS_VOLUME_STATE_FORCE_SYNC    = &H40

'//
'// These are valid on getting the volume state on the root
'// These are available to determine the flavor of DFS
'// A few bits are reserved to determine the flavor of the DFS root.
'// To get the flavor, and the state with DFS_VOLUME_FLAVORS.
'//
'// (_state & DFS_VOLUME_FLAVORS) will tell you the flavor of the dfs root.
'//
'//

%DFS_VOLUME_FLAVORS            = &H0300


%DFS_VOLUME_FLAVOR_UNUSED1     = &H0000
%DFS_VOLUME_FLAVOR_STANDALONE  = &H0100
%DFS_VOLUME_FLAVOR_AD_BLOB     = &H0200
%DFS_STORAGE_FLAVOR_UNUSED2    = &H0300

'//
'// DFS Storage State
'//

%DFS_STORAGE_STATES            = &HF
%DFS_STORAGE_STATE_OFFLINE     = 1
%DFS_STORAGE_STATE_ONLINE      = 2
%DFS_STORAGE_STATE_ACTIVE      = 4


'//
'// Priority of a DFS target consists of the
'// tuple <priority class, priority rank>. Priority
'// ranks are valid only within a priority class and
'// not across priority classes.
'// Priority rank is 0-n, where 0 is highest rank.
'//
'// We have consciously chosen 0 to indicate the
'// "normal" priority class, i.e. one that would
'// be used if target priorities aren't used.
'//
'// The members of the enumeration have been explicitly
'// set in a specific order (in the enumeration).
'//
'// We need the MIDL_PASS decoration to force sending
'// the enums as 32-bit values instead of the default
'// 16-bit values for enums.
'//

' DFS_TARGET_PRIORITY_CLASS enum
%DfsInvalidPriorityClass        = -1
%DfsSiteCostNormalPriorityClass = 0
%DfsGlobalHighPriorityClass     = 1
%DfsSiteCostHighPriorityClass   = 2
%DfsSiteCostLowPriorityClass    = 3
%DfsGlobalLowPriorityClass      = 4

' // Size = 8 bytes
TYPE DFS_TARGET_PRIORITY WORD
   TargetPriorityClass AS LONG    ' DFS_TARGET_PRIORITY_CLASS  // Priority class of target.
   TargetPriorityRank  AS WORD    ' USHORT  // Priority rank of target.
   Reserved            AS WORD    ' USHORT  // Must be set to 0.
END TYPE

'//
'// Level 1:
'//

' // Size = 4 bytes
TYPE DFS_INFO_1 DWORD
   EntryPath AS WSTRINGZ PTR   ' LPWSTR  // Dfs name for the top of this piece of storage
END TYPE

'#if defined(_WIN64)

'//
'// WOW64 support: Permit 32-bit callers to use 64-bit
'// driver.
'//

' // Size = 4 bytes
TYPE DFS_INFO_1_32 DWORD
   EntryPath AS DWORD   ' ULONG    // Dfs name for the top of this volume
END TYPE

'#endif  /* _WIN64   */


'//
'// Level 2:
'//

' // Size = 16 bytes
TYPE DFS_INFO_2 DWORD
   EntryPath        AS WSTRINGZ PTR   ' LPWSTR  // Dfs name for the top of this volume
   Comment          AS WSTRINGZ PTR   ' LPWSTR  // Comment for this volume
   State            AS DWORD          ' DWORD  // State of this volume, one of DFS_VOLUME_STATE_*
   NumberOfStorages AS DWORD          ' DWORD  // Number of storages for this volume
END TYPE

'#if defined(_WIN64)

'//
'// WOW64 support: Permit 32-bit callers to use 64-bit
'// driver.
'//

' // Size = 16 bytes
TYPE DFS_INFO_2_32 DWORD
   EntryPath        AS DWORD      ' ULONG // Dfs name for the top of this volume
   Comment          AS DWORD      ' ULONG // Comment for this volume
   State            AS DWORD      ' DWORD  // State of this volume, one of DFS_VOLUME_STATE_*
   NumberOfStorages AS DWORD      ' DWORD  // Number of storages for this volume
END TYPE

'#endif  /* _WIN64   */

' // Size = 12 bytes
TYPE DFS_STORAGE_INFO DWORD
   State      AS DWORD          ' ULONG   // State of this storage, one of DFS_STORAGE_STATE_*
                                '         // possibly OR'd with DFS_STORAGE_STATE_ACTIVE
   ServerName AS WSTRINGZ PTR   ' LPWSTR  // Name of server hosting this storage
   ShareName  AS WSTRINGZ PTR   ' LPWSTR  // Name of share hosting this storage
END TYPE

'#if defined(_WIN64)

'//
'// We should be calling this structure DFS_STORAGE_INFO_32 as per
'// convention. However, we don't want to pollute the namespace of new
'// types that have been defined (for example, DFS_STORAGE_INFO_1) as
'// enhancements to the "base" DFS_STORAGE_INFO structure. Hence,
'// we define the WOW64 support structure as DFS_STORAGE_INFO_0_32.
'//

' // Size = 12 bytes
TYPE DFS_STORAGE_INFO_0_32 DWORD
   State      AS DWORD   ' ULONG  // State of this storage, one of DFS_STORAGE_STATE_*
                         '        // possibly OR'd with DFS_STORAGE_STATE_ACTIVE
   ServerName AS DWORD   ' ULONG  // Name of server hosting this storage
   ShareName  AS DWORD   ' ULONG  // Name of share hosting this storage
END TYPE

'#endif  // _WIN64.

'//
'// WOW64 support: Permit 32-bit callers to use 64-bit
'// driver.
'//

' // Size = 20 bytes
TYPE DFS_STORAGE_INFO_1 DWORD
   State          AS DWORD                 ' ULONG   // State of this target, one of DFS_TARGET_STATE_*
                                           '         // possibly OR'd with DFS_STORAGE_STATE_ACTIVE
   ServerName     AS WSTRINGZ PTR          ' LPWSTR  // Name of server hosting this target
   ShareName      AS WSTRINGZ PTR          ' LPWSTR  // Name of share hosting this target
   TargetPriority AS DFS_TARGET_PRIORITY   '         // Priority of this target.
END TYPE

'//
'// Level 3:
'//

' // Size = 20 bytes
TYPE DFS_INFO_3 DWORD
   EntryPath        AS WSTRINGZ PTR           ' LPWSTR  // Dfs name for the top of this volume
   Comment          AS WSTRINGZ PTR           ' LPWSTR  // Comment for this volume
   State            AS DWORD                  ' DWORD   // State of this volume, one of DFS_VOLUME_STATE_*
   NumberOfStorages AS DWORD                  ' DWORD   // Number of storage servers for this volume
   Storage          AS DFS_STORAGE_INFO PTR   ' LPDFS_STORAGE_INFO  // An array (of NumberOfStorages elements) of
                                              '                     // storage-specific information.
END TYPE

'#if defined(_WIN64)

'//
'// WOW64 support: Permit 32-bit callers to use 64-bit
'// driver.
'//

' // Size = 20 bytes
TYPE DFS_INFO_3_32 DWORD
   EntryPath        AS DWORD   ' ULONG  // Dfs name for the top of this volume
   Comment          AS DWORD   ' ULONG  // Comment for this volume
   State            AS DWORD   ' DWORD  // State of this volume, one of DFS_VOLUME_STATE_*
   NumberOfStorages AS DWORD   ' DWORD  // Number of storage servers for this volume
   Storage          AS DWORD   ' ULONG  // An array (of NumberOfStorages elements) of
                               '        //      storage-specific information. Each element
                               '        //      is of type DFS_STORAGE_INFO_0_32.
END TYPE

'#endif  /* _WIN64   */

'//
'// Level 4:
'//
' // Size = 40 bytes
TYPE DFS_INFO_4 DWORD
   EntryPath        AS WSTRINGZ PTR            ' LPWSTR  // Dfs name for the top of this volume
   Comment          AS WSTRINGZ PTR            ' LPWSTR  // Comment for this volume
   State            AS DWORD                   ' DWORD   // State of this volume, one of DFS_VOLUME_STATE_*
   Timeout          AS DWORD                   ' ULONG   // Timeout, in seconds, of this junction point
   Guid             AS GUID                    ' GUID    // Guid of this junction point
   NumberOfStorages AS DWORD                   ' DWORD   // Number of storage servers for this volume
   Storage          AS DFS_STORAGE_INFO PTR    ' LPDFS_STORAGE_INFO   // An array (of NumberOfStorages elements) of
                                               '                      //      storage-specific information.
END TYPE


'#if defined(_WIN64)

'//
'// WOW64 support: Permit 32-bit callers to use 64-bit
'// driver.
'//

' // Size = 40 bytes
TYPE DFS_INFO_4_32 DWORD
   EntryPath        AS DWORD   ' ULONG   // Dfs name for the top of this volume
   Comment          AS DWORD   ' ULONG   // Comment for this volume
   State            AS DWORD   ' DWORD   // State of this volume, one of DFS_VOLUME_STATE_*
   Timeout          AS DWORD   ' ULONG   // Timeout, in seconds, of this junction point
   Guid             AS GUID    ' GUID    // Guid of this junction point
   NumberOfStorages AS DWORD   ' DWORD   // Number of storage servers for this volume
   Storage          AS DWORD   ' ULONG   // An array (of NumberOfStorages elements) of
                               '         //      storage-specific information. Each element
                               '         //      is of type DFS_STORAGE_INFO_0_32.
END TYPE

'#endif  /* _WIN64   */


'//
'// Level 5:
'//
' // Size = 44 bytes
TYPE DFS_INFO_5 DWORD
   EntryPath        AS WSTRINGZ PTR   ' LPWSTR  // Name of DFS namespace, DFS root name.
   Comment          AS WSTRINGZ PTR   ' LPWSTR  // Comment for root/link.
   State            AS DWORD          ' DWORD   // State of the root/link, one of DFS_VOLUME_STATE_*
                                      '         // Also has DFS_VOLUME_FLAVOR_* information.
   Timeout          AS DWORD          ' ULONG   // Referral TTL, in seconds, of root/link.
   Guid             AS GUID           ' GUID    // GUID of this root/link.
   PropertyFlags    AS DWORD          ' ULONG   // Properties of root/link. One of DFS_PROPERTY_FLAG_*
   MetadataSize     AS DWORD          ' ULONG   // Size of Active Directory BLOB for a domain-based
                                      '         // DFS namespace; size of metadata stored in registry
                                      '         // for stand-alone DFS. Valid for DFS roots only.
   NumberOfStorages AS DWORD          ' DWORD   // Number of storage servers for this volume
END TYPE

'//
'// Level 6:
'//
' // Size = 48 bytes
TYPE DFS_INFO_6 DWORD
   EntryPath        AS WSTRINGZ PTR             ' LPWSTR  // Name of DFS namespace, DFS root name.
   Comment          AS WSTRINGZ PTR             ' LPWSTR  // Comment for root/link.
   State            AS DWORD                    '         // State of the root/link, one of DFS_VOLUME_STATE_*
                                                '         //      Also has DFS_VOLUME_FLAVOR_* information.
   Timeout          AS DWORD                    ' ULONG   // Referral TTL, in seconds, of root/link.
   Guid             AS GUID                     ' GUID    // GUID of this root/link.
   PropertyFlags    AS DWORD                    ' ULONG   // Properties of root/link. One of DFS_PROPERTY_FLAG_*
   MetadataSize     AS DWORD                    ' ULONG   // Size of Active Directory BLOB for a domain-based
                                                '         //      DFS namespace; size of metadata stored in registry
                                                '         //      for stand-alone DFS. Valid for DFS roots only.
   NumberOfStorages AS DWORD                    ' DWORD   // Number of targets for this root/link.
   Storage          AS DFS_STORAGE_INFO_1 PTR   ' LPDFS_STORAGE_INFO_1  // An array (of NumberOfStorages elements) of
                                                '                       // storage-specific information.
END TYPE

'//
'// Level 7:
'//
' // Size = 16 bytes
TYPE DFS_INFO_7 DWORD
   GenerationGuid AS GUID   ' GUID  // Guid representation of the version/generation
                            '       // number of the DFS root.
END TYPE

'//
'// Level 8:
'//
' // Size = 52 bytes
TYPE DFS_INFO_8 DWORD
   EntryPath           AS WSTRINGZ PTR              ' LPWSTR // Name of DFS namespace, DFS root name.
   Comment             AS WSTRINGZ PTR              ' LPWSTR // Comment for root/link.
   State               AS DWORD                     ' DWORD  // State of the root/link, one of DFS_VOLUME_STATE_*
                                                    '        // Also has DFS_VOLUME_FLAVOR_* information.
   Timeout             AS DWORD                     ' ULONG  // Referral TTL, in seconds, of root/link.
   Guid                AS GUID                      ' GUID   // GUID of this root/link.
   PropertyFlags       AS DWORD                     ' ULONG  // Properties of root/link. One of DFS_PROPERTY_FLAG_*
   MetadataSize        AS DWORD                     ' ULONG  // Size of Active Directory BLOB for a domain-based
                                                    '        //      DFS namespace; size of metadata stored in registry
                                                    '        //      for stand-alone DFS. Valid for DFS roots only.
   SdLengthReserved    AS DWORD                     ' ULONG
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   NumberOfStorages    AS DWORD                     ' DWORD  // Number of storage servers for this volume
END TYPE

'//
'// Level 9:
'//
' // Size = 56 bytes
TYPE DFS_INFO_9 DWORD
   EntryPath           AS WSTRINGZ PTR              ' LPWSTR // Name of DFS namespace, DFS root name.
   Comment             AS WSTRINGZ PTR              ' LPWSTR // Comment for root/link.
   State               AS DWORD                     ' DWORD  // State of the root/link, one of DFS_VOLUME_STATE_*
                                                    '        // Also has DFS_VOLUME_FLAVOR_* information.
   Timeout             AS DWORD                     ' ULONG  // Referral TTL, in seconds, of root/link.
   Guid                AS GUID                      ' GUID   // GUID of this root/link.
   PropertyFlags       AS DWORD                     ' ULONG  // Properties of root/link. One of DFS_PROPERTY_FLAG_*
   MetadataSize        AS DWORD                     ' ULONG  // Size of Active Directory BLOB for a domain-based
                                                    '        //      DFS namespace; size of metadata stored in registry
                                                    '        //      for stand-alone DFS. Valid for DFS roots only.
   SdLengthReserved    AS DWORD                     ' ULONG
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   NumberOfStorages    AS DWORD                     ' DWORD  // Number of targets for this root/link.
   Storage             AS DFS_STORAGE_INFO_1 PTR    ' LPDFS_STORAGE_INFO_1 // An array (of NumberOfStorages elements) of
                                                    '        // storage-specific information.
END TYPE

'//
'// The PropertyFlags field of DFS_INFO_5, DFS_INFO_6,
'// DFS_INFO_103, DFS_INFO_105 & DFS_INFO_107.
'//

'//
'// The "insite" flag. When set, only targets in the same
'// site as the client are returned.
'//
'// Valid for domain/standalone roots/links
'//

%DFS_PROPERTY_FLAG_INSITE_REFERRALS  = &H00000001???

'//
'// "Root scalability" mode. When set, DFS server polls
'// the nearest DC instead of PDC to check for DFS namespace
'// changes. Valid only for domain roots.
'//

%DFS_PROPERTY_FLAG_ROOT_SCALABILITY  = &H00000002???

'//
'// Enables Active Directory site costing of targets. When enabled,
'// targets are grouped into sets of increasing site costs from
'// DFS client to target. Each set has targets of same cost.
'// If not set, there are only two sets: set of targets in same
'// site as client and set of targets not in the same site as the client.
'// The latter is called "site awareness".
'// Valid only domain/standalone roots
'//

%DFS_PROPERTY_FLAG_SITE_COSTING      = &H00000004???

'//
'// Should the DFS client attempt to failback to a closer target
'// when it is available after failing over to a non-optimal target?
'// Valid for domain/standalone roots/links.
'//

%DFS_PROPERTY_FLAG_TARGET_FAILBACK   = &H00000008???

'//
'// Bit will be 1 if the DFS root is clustered. Cannot be set
'// using the NetDfsSetInfo() API.
'//

%DFS_PROPERTY_FLAG_CLUSTER_ENABLED   = &H00000010???

'//
'//  When set by the caller, Access-Based Directory Enumeration support
'//  is enabled on all the DFS root target share of the DFS namespace.
'//  Valid only for DFS namespaces which support the capability
'//  DFS_NAMESPACE_CAPABILITY_ABDE. Valid only on the DFS namespace root
'//  and not on root targets, link or link targets.
'//  This property must be enabled to associate security descriptor
'//  with a DFS link.
'//

%DFS_PROPERTY_FLAG_ABDE  = &H00000020???

%DFS_VALID_PROPERTY_FLAGS = %DFS_PROPERTY_FLAG_INSITE_REFERRALS OR _
                            %DFS_PROPERTY_FLAG_ROOT_SCALABILITY OR _
                            %DFS_PROPERTY_FLAG_SITE_COSTING OR _
                            %DFS_PROPERTY_FLAG_TARGET_FAILBACK OR _
                            %DFS_PROPERTY_FLAG_CLUSTER_ENABLED OR _
                            %DFS_PROPERTY_FLAG_ABDE

'//
'//  Level 50:
'//

'//
'//  DFS metadata version and capabilities of an existing
'//  DFS namespace.
'//

' // Size = 16 bytes
TYPE DFS_INFO_50 QWORD FILL
   NamespaceMajorVersion AS DWORD   ' ULONG
   NamespaceMinorVersion AS DWORD   ' ULONG
   NamespaceCapabilities AS QUAD    ' ULONGLONG
END TYPE

'//
'// Level 100:
'//
' // Size = 4 bytes
TYPE DFS_INFO_100 DWORD
   Comment AS WSTRINGZ PTR   ' LPWSTR  // Comment for this volume or storage
END TYPE

'//
'// Level 101:
'//
' // Size = 4 bytes
TYPE DFS_INFO_101 DWORD
   State AS DWORD   ' DWORD  // State of this storage, one of DFS_STORAGE_STATE_*
                    '        // possibly OR'd with DFS_STORAGE_STATE_ACTIVE
END TYPE

'//
'// Level 102:
'//
' // Size = 4 bytes
TYPE DFS_INFO_102 DWORD
   Timeout AS DWORD   ' ULONG  // Timeout, in seconds, of the junction
END TYPE

'//
'// Level 103:
'//
' // Size = 8 bytes
TYPE DFS_INFO_103 DWORD
   PropertyFlagMask AS DWORD   ' ULONG  // Indicates which flags in PropertyFlags are valid.
   PropertyFlags    AS DWORD   ' ULONG  // Flag meaningful only if corresponding bit set in
                               '        // PropertyFlagMask above.
END TYPE

'//
'// Level 104:
'//
' // Size = 8 bytes
TYPE DFS_INFO_104 DWORD
   TargetPriority AS DFS_TARGET_PRIORITY   ' // Priority of target.
END TYPE

'//
'// Level 105:
'//
' // Size = 20 bytes
TYPE DFS_INFO_105 DWORD
   Comment          AS WSTRINGZ PTR   ' LPWSTR // Comment for this root/link.
   State            AS DWORD          ' DWORD  // State of this root/link. One of DFS_VOLUME_STATE_*
   Timeout          AS DWORD          ' ULONG  // Referral TTL, in seconds, of root/link.
   PropertyFlagMask AS DWORD          ' ULONG  // Indicates which flags in PropertyFlags are valid.
   PropertyFlags    AS DWORD          ' ULONG  // One of DFS_PROPERTY_FLAG_*
END TYPE

'//
'// Level 106:
'//
' // Size = 12 bytes
TYPE DFS_INFO_106 DWORD
   State          AS DWORD                 ' DWORD  // State of this root/link target.
                                           '        // One of DFS_TARGET_STATE_*
   TargetPriority AS DFS_TARGET_PRIORITY   '        // Priority of this target.
END TYPE

'//
'// Level 107:
'//
' // Size = 28 bytes
TYPE DFS_INFO_107 DWORD
   Comment             AS WSTRINGZ PTR              ' LPWSTR // Comment for this root/link.
   State               AS DWORD                     ' DWORD  // State of this root/link. One of DFS_VOLUME_STATE_*
   Timeout             AS DWORD                     ' ULONG  // Referral TTL, in seconds, of root/link.
   PropertyFlagMask    AS DWORD                     ' ULONG  // Indicates which flags in PropertyFlags are valid.
   PropertyFlags       AS DWORD                     ' ULONG  // One of DFS_PROPERTY_FLAG_*
   SdLengthReserved    AS DWORD                     ' ULONG
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
END TYPE

'//
'// Level 150:
'//
' // Size = 8 bytes
TYPE DFS_INFO_150 DWORD
   SdLengthReserved    AS DWORD                     ' ULONG
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
END TYPE

'//
'// Level 200:
'//
' // Size = 4 bytes
TYPE DFS_INFO_200 DWORD
   FtDfsName AS WSTRINGZ PTR   ' LPWSTR  // FtDfs name
END TYPE

'//
'// Level 300:
'//
' // Size = 8 bytes
TYPE DFS_INFO_300 DWORD
   Flags   AS DWORD          ' DWORD
   DfsName AS WSTRINGZ PTR   ' LPWSTR  // Dfs name
END TYPE

'//
'// Add a new volume or additional storage for an existing volume at
'// DfsEntryPath.
'//

DECLARE FUNCTION NetDfsAdd IMPORT "NETAPI32.DLL" ALIAS "NetDfsAdd" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR DfsEntryPath  // DFS entry path for this added volume or storage
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName    // Name of server hosting the storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR ShareName     // Existing share name for the storage
 , BYREF Comment AS WSTRINGZ _                          ' __in  LPWSTR Comment OPTIONAL  // Optional comment for this volume or storage
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags         // See below. Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Flags:
'//
%DFS_ADD_VOLUME         = 1  ' // Add a new volume to the DFS if not already there
%DFS_RESTORE_VOLUME     = 2  ' // Volume/Replica is being restored - do not verify share etc.

'//
'// Setup/teardown API's for standard and FtDfs roots.
'//

DECLARE FUNCTION NetDfsAddStdRoot IMPORT "NETAPI32.DLL" ALIAS "NetDfsAddStdRoot" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share to make Dfs root
 , BYREF Comment AS WSTRINGZ _                          ' __in  LPWSTR Comment OPTIONAL  // Comment
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsRemoveStdRoot IMPORT "NETAPI32.DLL" ALIAS "NetDfsRemoveStdRoot" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share that host Dfs root
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsAddFtRoot IMPORT "NETAPI32.DLL" ALIAS "NetDfsAddFtRoot" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share to make Dfs root
 , BYREF FtDfsName AS WSTRINGZ _                        ' __in  LPWSTR FtDfsName   // Name of FtDfs to create/join
 , BYREF Comment AS WSTRINGZ _                          ' __in  LPWSTR Comment     // Comment
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsRemoveFtRoot IMPORT "NETAPI32.DLL" ALIAS "NetDfsRemoveFtRoot" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share that host Dfs root
 , BYREF FtDfsName AS WSTRINGZ _                        ' __in  LPWSTR FtDfsName   // Name of FtDfs to remove or unjoin from.
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsRemoveFtRootForced IMPORT "NETAPI32.DLL" ALIAS "NetDfsRemoveFtRootForced" ( _
   BYREF DomainName AS WSTRINGZ _                       ' __in  LPWSTR DomainName  // Name of domain the server is in
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share that host Dfs root
 , BYREF FtDfsName AS WSTRINGZ _                        ' __in  LPWSTR FtDfsName   // Name of FtDfs to remove or unjoin from.
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Call to reinitialize the dfsmanager on a machine
'//

DECLARE FUNCTION NetDfsManagerInitialize IMPORT "NETAPI32.DLL" ALIAS "NetDfsManagerInitialize" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYVAL Flags AS DWORD _                               ' __in  DWORD  Flags       // Flags for operation.  Zero for no flags.
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsAddStdRootForced IMPORT "NETAPI32.DLL" ALIAS "NetDfsAddStdRootForced" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName  // Server to remote to
 , BYREF RootShare AS WSTRINGZ _                        ' __in  LPWSTR RootShare   // Share to make Dfs root
 , BYREF Comment AS WSTRINGZ _                          ' __in  LPWSTR Comment OPTIONAL  // Comment
 , BYREF Store AS WSTRINGZ _                            ' __in  LPWSTR Store       // Drive:\dir backing the share
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsGetDcAddress IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetDcAddress" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in     LPWSTR ServerName  // Server to remote to
 , BYREF DcIpAddress AS DWORD _                         ' __in_out LPWSTR *DcIpAddress  // The IP address of the DC to use
 , BYREF IsRoot AS DWORD _                              ' __in_out BOOLEAN *IsRoot  // TRUE if server is a Dfs root, FALSE otherwise
 , BYREF Timeout AS DWORD _                             ' __in_out ULONG *Timeout  // Time, in sec, that we stay with this DC
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Flags for NetDfsSetDcAddress()
'//

%NET_DFS_SETDC_FLAGS                 = &H00000000???
%NET_DFS_SETDC_TIMEOUT               = &H00000001???
%NET_DFS_SETDC_INITPKT               = &H00000002???

'//
'// Structures used for site reporting.  Last used in Windows 2000, maintained for
'// the obsolete SRVSVC RPC API NetrDfsManagerReportSiteInfo.
'//

' // Size = 8 bytes
TYPE DFS_SITENAME_INFO DWORD
   SiteFlags AS DWORD          ' ULONG    // Below
   SiteName  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'// SiteFlags

%DFS_SITE_PRIMARY    = &H1???    ' // This site returned by DsGetSiteName()

' // Size = 12 bytes
TYPE DFS_SITELIST_INFO DWORD
   cSites  AS DWORD              ' ULONG
   Site(0) AS DFS_SITENAME_INFO  ' Variablesize array
END TYPE

'//
'// Remove a volume or additional storage for volume from the Dfs at
'// DfsEntryPath. When applied to the last storage in a volume, removes
'// the volume from the DFS.
'//

DECLARE FUNCTION NetDfsRemove IMPORT "NETAPI32.DLL" ALIAS "NetDfsRemove" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath  // DFS entry path for this added volume or storage
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR  ServerName    // Name of server hosting the storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR  ShareName     // Name of share hosting the storage
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Get information about all of the volumes in the Dfs. DfsName is
'// the "server" part of the UNC name used to refer to this particular Dfs.
'//
'// Valid levels are 1-5, 200, 300
'//

DECLARE FUNCTION NetDfsEnum IMPORT "NETAPI32.DLL" ALIAS "NetDfsEnum" ( _
   BYREF DfsName AS WSTRINGZ _                          ' __in      LPWSTR  DfsName      // Name of the Dfs for enumeration
 , BYVAL Level AS DWORD _                               ' __in      DWORD   Level        // Level of information requested
 , BYVAL PrefMaxLen AS DWORD _                          ' __in      DWORD   PrefMaxLen   // Advisory, but -1 means "get it all"
 , BYREF Buffer AS DWORD _                              ' __out     LPBYTE* Buffer       // API allocates and returns buffer with requested info
 , BYREF EntriesRead AS DWORD _                         ' __out     LPDWORD EntriesRead  // Number of entries returned
 , BYREF ResumeHandle AS DWORD _                        ' __in_out  LPDWORD ResumeHandle // Must be 0 on first call, reused on subsequent calls
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Get information about the volume or storage.
'// If ServerName and ShareName are specified, the information returned
'// is specific to that server and share, else the information is specific
'// to the volume as a whole.
'//
'// Valid levels are 1-5, 100
'//

DECLARE FUNCTION NetDfsGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetInfo" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath        // DFS entry path for the volume
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR  ServerName OPTIONAL // Name of server hosting a storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR  ShareName OPTIONAL  // Name of share on server serving the volume
 , BYVAL Level AS DWORD _                               ' __in  DWORD   Level               // Level of information requested
 , BYREF Buffer AS DWORD _                              ' __out LPBYTE* Buffer              // API allocates and returns buffer with requested info
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Set info about the volume or storage.
'// If ServerName and ShareName are specified, the information set is
'// specific to that server and share, else the information is specific
'// to the volume as a whole.
'//
'// Valid levels are 100, 101 and 102
'//

DECLARE FUNCTION NetDfsSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetDfsSetInfo" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath        // DFS entry path for the volume
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR  ServerName OPTIONAL // Name of server hosting a storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR  ShareName OPTIONAL  // Name of share hosting a storage
 , BYVAL Level AS DWORD _                               ' __in  DWORD   Level               // Level of information to be set
 , BYREF Buffer AS ANY _                                ' __in  LPBYTE  Buffer              // Buffer holding information
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Get client's cached information about the volume or storage.
'// If ServerName and ShareName are specified, the information returned
'// is specific to that server and share, else the information is specific
'// to the volume as a whole.
'//
'// Valid levels are 1-4
'//

DECLARE FUNCTION NetDfsGetClientInfo IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetClientInfo" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath        // DFS entry path for the volume
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR  ServerName OPTIONAL // Name of server hosting a storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR  ShareName OPTIONAL  // Name of share on server serving the volume
 , BYVAL Level AS DWORD _                               ' __in  DWORD   Level               // Level of information requested
 , BYREF Buffer AS DWORD _                              ' __out LPBYTE* Buffer              // API allocates and returns buffer with requested info
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Set client's cached info about the volume or storage.
'// If ServerName and ShareName are specified, the information set is
'// specific to that server and share, else the information is specific
'// to the volume as a whole.
'//
'// Valid levels are 101 and 102.
'//

DECLARE FUNCTION NetDfsSetClientInfo IMPORT "NETAPI32.DLL" ALIAS "NetDfsSetClientInfo" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath        // DFS entry path for the volume
 , BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR  ServerName OPTIONAL // Name of server hosting a storage
 , BYREF ShareName AS WSTRINGZ _                        ' __in  LPWSTR  ShareName OPTIONAL  // Name of share hosting a storage
 , BYVAL Level AS DWORD _                               ' __in  DWORD   Level               // Level of information to be set
 , BYREF Buffer AS ANY _                                ' __in  LPBYTE  Buffer              // Buffer holding information
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Move a DFS volume and all subordinate volumes from one place in the
'// DFS to another place in the DFS.
'//

DECLARE FUNCTION NetDfsMove IMPORT "NETAPI32.DLL" ALIAS "NetDfsMove" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR  DfsEntryPath     // Current DFS entry path for this volume
 , BYREF DfsNewEntryPath AS WSTRINGZ _                  ' __in  LPWSTR  DfsNewEntryPath  // New DFS entry path for this volume
 , BYVAL Flags AS DWORD _                               ' __in  ULONG   Flags
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Flags accepted by NetDfsMove
'//

'//
'//  This  indicates that if a colliding link is found it should be replaced
'//

%DFS_MOVE_FLAG_REPLACE_IF_EXISTS  = &H00000001???


DECLARE FUNCTION NetDfsRename IMPORT "NETAPI32.DLL" ALIAS "NetDfsRename" ( _
   BYREF Path AS WSTRINGZ _                             ' __in  LPWSTR  Path     // Current Win32 path in a Dfs
 , BYREF NewPath AS WSTRINGZ _                          ' __in  LPWSTR  NewPath  // New Win32 path in the same Dfs
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsAddRootTarget IMPORT "NETAPI32.DLL" ALIAS "NetDfsAddRootTarget" ( _
   BYREF pDfsPath AS WSTRINGZ _                         ' __in        LPWSTR  pDfsPath
 , BYREF pTargetPath AS WSTRINGZ _                      ' __in_opt    LPWSTR  pTargetPath
 , BYVAL MajorVersion AS DWORD _                        ' __in        ULONG   MajorVersion
 , BYREF pComment AS WSTRINGZ _                         ' __in_opt    LPWSTR  pComment
 , BYVAL Flags AS DWORD _                               ' __in        ULONG   Flags
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Reuse existing definition used by NetrDfsRemoveFtRoot().
'//

#IF NOT %DEF(%DFS_FORCE_REMOVE)
%DFS_FORCE_REMOVE = &H80000000???
#ENDIF

DECLARE FUNCTION NetDfsRemoveRootTarget IMPORT "NETAPI32.DLL" ALIAS "NetDfsRemoveRootTarget" ( _
   BYREF pDfsPath AS WSTRINGZ _                         ' __in        LPWSTR  pDfsPath
 , BYREF pTargetPath AS WSTRINGZ _                      ' __in_opt    LPWSTR  pTargetPath
 , BYVAL Flags AS DWORD _                               ' __in        ULONG   Flags
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsGetSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetSecurity" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in  LPWSTR DfsEntryPath
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 , BYREF lpcbSecurityDescriptor AS DWORD _              ' __out LPDWORD lpcbSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsSetSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsSetSecurity" ( _
   BYREF DfsEntryPath AS WSTRINGZ _                     ' __in LPWSTR DfsEntryPath
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsGetStdContainerSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetStdContainerSecurity" ( _
   BYREF MachineName AS WSTRINGZ _                      ' __in  LPWSTR MachineName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 , BYREF lpcbSecurityDescriptor AS DWORD _              ' __out LPDWORD lpcbSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsSetStdContainerSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsSetStdContainerSecurity" ( _
   BYREF MachineName AS WSTRINGZ _                      ' __in  LPWSTR MachineName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsGetFtContainerSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetFtContainerSecurity" ( _
   BYREF DomainName AS WSTRINGZ _                       ' __in  LPWSTR DomainName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 , BYREF lpcbSecurityDescriptor AS DWORD _              ' __out LPDWORD lpcbSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetDfsSetFtContainerSecurity IMPORT "NETAPI32.DLL" ALIAS "NetDfsSetFtContainerSecurity" ( _
   BYREF DomainName AS WSTRINGZ _                       ' __in  LPWSTR DomainName
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in  SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Origin of DFS namespace version information.
'//

' enum DFS_NAMESPACE_VERSION_ORIGIN
%DFS_NAMESPACE_VERSION_ORIGIN_COMBINED = 0   ' //  Max version {server, AD DS domain}
                                             ' //      can support.
%DFS_NAMESPACE_VERSION_ORIGIN_SERVER   = 1   ' //  Max version server can support.
%DFS_NAMESPACE_VERSION_ORIGIN_DOMAIN   = 2   ' //  Max version AD DS domain can support.

'//
'//  Capabilities:
'//      Set of bit flags which indicates support for a specific capability.
'//

'//
'//  DFS namespace supports associating a security descriptor with DFS link
'//  for Access-Based Directory Enumeration purposes.
'//

'#define DFS_NAMESPACE_CAPABILITY_ABDE           ((ULONGLONG) 0x0000000000000001)
%DFS_NAMESPACE_CAPABILITY_ABDE = &H0000000000000001&&


' // Size = 32 bytes
TYPE DFS_SUPPORTED_NAMESPACE_VERSION_INFO QWORD FILL

   ' //
   ' //  Domain-based DFS information.
   ' //  Valid only if DomainDfsMajorVersion != 0.
   ' //

   DomainDfsMajorVersion     AS DWORD  ' ULONG
   DomainDfsMinorVersion     AS DWORD  ' ULONG
   DomainDfsCapabilities     AS QUAD   ' ULONGLONG

   ' //
   ' //  Standalone DFS information.
   ' //  Valid only if StandaloneDfsMajorVersion != 0.
   ' //

   StandaloneDfsMajorVersion AS DWORD  ' ULONG
   StandaloneDfsMinorVersion AS DWORD  ' ULONG
   StandaloneDfsCapabilities AS QUAD   ' ULONGLONG
END TYPE

DECLARE FUNCTION NetDfsGetSupportedNamespaceVersion IMPORT "NETAPI32.DLL" ALIAS "NetDfsGetSupportedNamespaceVersion" ( _
   BYVAL Origin AS LONG _                               ' __in DFS_NAMESPACE_VERSION_ORIGIN Origin
 , BYREF pName AS WSTRINGZ _                            ' __in_opt PWSTR pName
 , BYREF ppVersionInfo AS DFS_SUPPORTED_NAMESPACE_VERSION_INFO _  ' __out PDFS_SUPPORTED_NAMESPACE_VERSION_INFO *ppVersionInfo
 ) AS DWORD                                             ' NET_API_STATUS
