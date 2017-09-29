' ########################################################################################
' Microsoft Windows
' File: Wmistr.inc
' Contents: WMI structure definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMISTR_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// WNODE definition
' // Size = 8 bytes
TYPE WNODE_HEADER_UNION_STRUCT DWORD
   Version AS DWORD   ' ULONG // Reserved
   Linkage AS DWORD   ' ULONG // Linkage field reserved for WMI
END TYPE

' // Size = 8 bytes
UNION WNODE_HEADER_UNION_1   ' Must be 8 byte aligned
   HistoricalContext AS QUAD   ' ULONG64 // Logger use
   WNODE_HEADER_UNION_STRUCT
END UNION

' // Size = 8 bytes
UNION WNODE_HEADER_UNION_2   ' Must be 8 byte aligned
   CountLost    AS DWORD   ' ULONG // Reserved
   KernelHandle AS DWORD   ' HANDLE // Kernel handle for data block
   TimeStamp    AS QUAD    ' LARGE_INTEGER // Timestamp as returned in units of 100ns
                           '               // since 1/1/1601
END UNION

' // Size = 48 bytes
TYPE WNODE_HEADER   ' Must be 8 byte aligned
   BufferSize           AS DWORD   ' ULONG // Size of entire buffer inclusive of this ULONG
   ProviderId           AS DWORD   ' ULONG // Provider Id of driver returning this buffer
   WNODE_HEADER_UNION_1
   WNODE_HEADER_UNION_2
   Guid                 AS GUID    ' GUID // Guid for data block returned with results
   ClientContext        AS DWORD   ' ULONG
   Flags                AS DWORD   ' ULONG // Flags, see below
END TYPE

'//
'// WNODE_HEADER flags are defined as follows
%WNODE_FLAG_ALL_DATA        = &H00000001???  ' // set for WNODE_ALL_DATA
%WNODE_FLAG_SINGLE_INSTANCE = &H00000002???  ' // set for WNODE_SINGLE_INSTANCE
%WNODE_FLAG_SINGLE_ITEM     = &H00000004???  ' // set for WNODE_SINGLE_ITEM
%WNODE_FLAG_EVENT_ITEM      = &H00000008???  ' // set for WNODE_EVENT_ITEM

'                                              // Set if data block size is
'                                              // identical for all instances
'                                              // (used with  WNODE_ALL_DATA
'                                              // only)
%WNODE_FLAG_FIXED_INSTANCE_SIZE = &H00000010???

%WNODE_FLAG_TOO_SMALL           = &H00000020???  ' // set for WNODE_TOO_SMALL

'                                 // Set when a data provider returns a
'                                 // WNODE_ALL_DATA in which the number of
'                                 // instances and their names returned
'                                 // are identical to those returned from the
'                                 // previous WNODE_ALL_DATA query. Only data
'                                 // blocks registered with dynamic instance
'                                 // names should use this flag.
%WNODE_FLAG_INSTANCES_SAME  = &H00000040???

'                                 // Instance names are not specified in
'                                 // WNODE_ALL_DATA; values specified at
'                                 // registration are used instead. Always
'                                 // set for guids registered with static
'                                 // instance names
%WNODE_FLAG_STATIC_INSTANCE_NAMES = &H00000080???

%WNODE_FLAG_INTERNAL      = &H00000100???   ' // Used internally by WMI

'                                  ' // timestamp should not be modified by
'                                  ' // a historical logger
%WNODE_FLAG_USE_TIMESTAMP = &H00000200???
%WNODE_FLAG_PERSIST_EVENT = &H00000400???

%WNODE_FLAG_EVENT_REFERENCE = &H00002000???

' ' // Set if Instance names are ansi. Only set when returning from
' ' // WMIQuerySingleInstanceA and WMIQueryAllDataA
%WNODE_FLAG_ANSI_INSTANCENAMES = &H00004000???

' ' // Set if WNODE is a method call
%WNODE_FLAG_METHOD_ITEM     = &H00008000???

' ' // Set if instance names originated from a PDO
%WNODE_FLAG_PDO_INSTANCE_NAMES  = &H00010000???

' ' // The second byte, except the first bit is used exclusively for tracing
%WNODE_FLAG_TRACED_GUID   = &H00020000???  ' // denotes a trace

%WNODE_FLAG_LOG_WNODE     = &H00040000???  ' // request to log Wnode

%WNODE_FLAG_USE_GUID_PTR  = &H00080000???  ' // Guid is actually a pointer

%WNODE_FLAG_USE_MOF_PTR   = &H00100000???  ' // MOF data are dereferenced

%WNODE_FLAG_NO_HEADER     = &H00200000???  ' // Trace without header

'// Set for events that are WNODE_EVENT_REFERENCE
'// Mask for event severity level. Level 0xff is the most severe type of event
%WNODE_FLAG_SEVERITY_MASK = &Hff000000???

'//
'// This structure is used within the WNODE_ALL_DATA when the data blocks
'// for the different instances are different lengths. If the data blocks
'// for the different instances are identical lengths then
'// WNODE_FLAG_FIXED_INSTANCE_SIZE should be set and FixedInstanceSize
'// set to the common data block size.

' // Size = 8 bytes
TYPE OFFSETINSTANCEDATAANDLENGTH DWORD
   OffsetInstanceData AS DWORD   ' ULONG // Offset from beginning of WNODE_ALL_DATA
                                 '       // to Data block for instance
   LengthInstanceData AS DWORD   ' ULONG // Length of data block for instance
END TYPE

' // Size = 8 bytes
UNION WNODE_ALL_DATA_UNION DWORD
   FixedInstanceSize              AS DWORD   ' ULONG
   OffsetInstanceDataAndLength(0) AS OFFSETINSTANCEDATAANDLENGTH
                              ' /* [InstanceCount] */
END UNION

' // Size = 72 bytes
TYPE WNODE_ALL_DATA   ' Must be 8 byte aligned
   WnodeHeader               AS WNODE_HEADER   ' struct _WNODE_HEADER
   DataBlockOffset           AS DWORD          ' ULONG // Offset from begin of WNODE to first data block
   InstanceCount             AS DWORD          ' ULONG // Count of instances whose data follows.
                                               ' // Offset to an array of offsets to the instance names
   OffsetInstanceNameOffsets AS DWORD          ' ULONG
   alignment__               AS DWORD          ' // To keep 8 byte alignment
   WNODE_ALL_DATA_UNION
END TYPE

' // Size = 64 bytes
TYPE WNODE_SINGLE_INSTANCE   ' Must be 8 byte aligned
   WnodeHeader        AS WNODE_HEADER   ' struct _WNODE_HEADER
   OffsetInstanceName AS DWORD          ' ULONG
   InstanceIndex      AS DWORD          ' ULONG // (Static Instance Names)
   DataBlockOffset    AS DWORD          ' ULONG // offset from beginning of WNODE to data block
   SizeDataBlock      AS DWORD          ' ULONG // Size of data block for instance
   'VariableData()     AS BYTE
END TYPE

' // Size = 72 bytes
TYPE WNODE_SINGLE_ITEM   ' Must be 8 byte aligned
   WnodeHeader        AS WNODE_HEADER   ' struct _WNODE_HEADER
   OffsetInstanceName AS DWORD          ' ULONG
   InstanceIndex      AS DWORD          ' ULONG //  set (Static Instance Names)
   ItemId             AS DWORD          ' ULONG // Item Id for data item being set
   DataBlockOffset    AS DWORD          ' ULONG // offset from WNODE begin to data item value
   SizeDataItem       AS DWORD          ' ULONG // Size of data item
   alignment__        AS DWORD          ' // To keep 8 byte alignment
   'VariableData()     AS BYTE
END TYPE

' // Size = 72 bytes
TYPE WNODE_METHOD_ITEM   ' Must be 8 byte aligned
   WnodeHeader        AS WNODE_HEADER   ' struct _WNODE_HEADER
   OffsetInstanceName AS DWORD          ' ULONG
   InstanceIndex      AS DWORD          ' ULONG //  set (Static Instance Names)
   MethodId           AS DWORD          ' ULONG // Method id of method being called
   DataBlockOffset    AS DWORD          ' ULONG // On Entry: offset from WNODE to input data
   SizeDataBlock      AS DWORD          ' ULONG // On Entry: Size of input data, 0 if no input
   alignment__        AS DWORD          ' // To keep 8 byte alignment
   'VariableData()     AS BYTE
END TYPE

' // Size = 48 bytes
TYPE WNODE_EVENT_ITEM   ' Must be 8 byte aligned
   WnodeHeader AS WNODE_HEADER   ' struct _WNODE_HEADER
'    // Different data could be here depending upon the flags set in the
'    // WNODE_HEADER above. If the WNODE_FLAG_ALL_DATA flag is set then the
'    // contents of a WNODE_ALL_DATA  (excluding WNODE_HEADER) is here. If the
'    // WNODE_FLAG_SINGLE_INSTANCE flag is set then a WNODE_SINGLE_INSTANCE
'    // (excluding WNODE_HEADER) is here. Lastly if the  WNODE_FLAG_SINGLE_ITEM
'    // flag is set then a WNODE_SINGLE_ITEM (excluding WNODE_HEADER) is here.
END TYPE

'//
'// If a KM data provider needs to fire an event that is larger than the
'// maximum size that WMI allows then it should fire a WNODE_EVENT_REFERENCE
'// that specifies which guid and instance name to query for the actual data
'// that should be part of the event.

' // Size = 4 bytes
UNION WNODE_EVENT_REFERENCE_UNION
   TargetInstanceIndex   AS DWORD        ' ULONG
   'TargetInstanceName AS WSTRINGZ * 1   ' WCHAR[]
END UNION

' // Size = 72 bytes
TYPE WNODE_EVENT_REFERENCE   ' Must be 8 byte aligned
   WnodeHeader         AS WNODE_HEADER   ' struct _WNODE_HEADER
   TargetGuid          AS GUID           ' GUID
   TargetDataBlockSize AS DWORD          ' ULONG
   WNODE_EVENT_REFERENCE_UNION
END TYPE

' // Size = 56 bytes
TYPE WNODE_TOO_SMALL   ' Must be 8 byte aligned
   WnodeHeader AS WNODE_HEADER   ' struct _WNODE_HEADER
   SizeNeeded  AS DWORD          ' ULONG // Size needed to build WNODE result
   alignment__ AS DWORD          ' // To keep 8 byte alignment
END TYPE

' // Size = 4 bytes
UNION WMIREGGUIDW_UNION DWORD
   InstanceNameList AS DWORD   ' ULONG
   BaseNameOffset   AS DWORD   ' ULONG
   Pdo              AS DWORD   ' DWORD_PTR
   InstanceInfo     AS DWORD   ' ULONG_PTR // Offset from beginning of the WMIREGINFO structure to
END UNION

' // Size = 28 bytes
TYPE WMIREGGUIDW DWORD
   Guid          AS GUID    ' GUID // Guid of data block being registered or updated
   Flags         AS DWORD   ' ULONG // Flags
   InstanceCount AS DWORD   ' ULONG // Count of static instances names for the guid
   WMIREGGUIDW_UNION
END TYPE

'// Set if collection must be enabled for the guid before the data provider
'// can be queried for data.
%WMIREG_FLAG_EXPENSIVE          = &H00000001???

'// Set if instance names for this guid are specified in a static list within
'// the WMIREGINFO
%WMIREG_FLAG_INSTANCE_LIST      = &H00000004???

'// Set if instance names are to be static and generated by WMI using a
'// base name in the WMIREGINFO and an index
%WMIREG_FLAG_INSTANCE_BASENAME  = &H00000008???

'// Set if WMI should do automatic mapping of a PDO to device instance name
'// as the instance name for the guid. This flag should only be used by
'// kernel mode data providers.
%WMIREG_FLAG_INSTANCE_PDO       = &H00000020???

'// Note the flags WMIREG_FLAG_INSTANCE_LIST, WMIREG_FLAG_INSTANCE_BASENAME,
'// WMIREG_FLAG_INSTANCE_REFERENCE and WMIREG_FLAG_INSTANCE_PDO are mutually
'// exclusive.

'//
'// These flags are only valid in a response to WMI_GUID_REGUPDATE
%WMIREG_FLAG_REMOVE_GUID       = &H00010000???  ' // Remove support for  guid
%WMIREG_FLAG_RESERVED1         = &H00020000???  ' // Reserved by WMI
%WMIREG_FLAG_RESERVED2         = &H00040000???  ' // Reserved by WMI

'// Set if guid is one that is written to trace log.
'// This guid cannot be queried directly via WMI, but must be read using
'// logger apis.
%WMIREG_FLAG_TRACED_GUID        = &H00080000???

'//
'// Only those Trace Guids that have this bit set can receive
'// Enable/Disable Notifications.
'//
%WMIREG_FLAG_TRACE_CONTROL_GUID = &H00001000???

'//
'// Set if the guid is only used for firing events. Guids that can be queried
'// and that fire events should not have this bit set.
%WMIREG_FLAG_EVENT_ONLY_GUID    = &H00000040???

' // Size = 20 bytes
TYPE WMIREGINFOW DWORD
   BufferSize      AS DWORD         ' ULONG
   NextWmiRegInfo  AS DWORD         ' ULONG // Offset to next WMIREGINFO structure
   RegistryPath    AS DWORD         ' ULONG // Offset from beginning of WMIREGINFO structure to a
   MofResourceName AS DWORD         ' ULONG
   GuidCount       AS DWORD         ' ULONG
   'WmiRegGuid()    AS WMIREGGUIDW   ' // array of GuidCount WMIREGGUID structures
END TYPE

MACRO WMIREGINFO = WMIREGINFOW

'//
'// WMI request codes
%WMI_GET_ALL_DATA        = 0
%WMI_GET_SINGLE_INSTANCE = 1
%WMI_SET_SINGLE_INSTANCE = 2
%WMI_SET_SINGLE_ITEM     = 3
%WMI_ENABLE_EVENTS       = 4
%WMI_DISABLE_EVENTS      = 5
%WMI_ENABLE_COLLECTION   = 6
%WMI_DISABLE_COLLECTION  = 7
%WMI_REGINFO             = 8
%WMI_EXECUTE_METHOD      = 9
%WMI_CAPTURE_STATE       = 10

'#if defined(_WINNT_) || defined(WINNT)
'//
'// WMI guid objects have the following rights
'// WMIGUID_QUERY
'// WMIGUID_SET
'// WMIGUID_NOTIFICATION
'// WMIGUID_READ_DESCRIPTION
'// WMIGUID_EXECUTE
'// TRACELOG_CREATE_REALTIME
'// TRACELOG_CREATE_ONDISK
'// TRACELOG_GUID_ENABLE
'// TRACELOG_ACCESS_KERNEL_LOGGER
'// TRACELOG_CREATE_INPROC
'// TRACELOG_ACCESS_REALTIME

'//
'// GuidTypes
'//
'//#ifndef _WMIKM_
%WMI_GUIDTYPE_TRACECONTROL = 0
%WMI_GUIDTYPE_TRACE        = 1
%WMI_GUIDTYPE_DATA         = 2
%WMI_GUIDTYPE_EVENT        = 3
'//#endif

'//
'// Specific rights for WMI guid objects. These are available from 0x0001 to
'// 0xffff (ie up to 16 rights)
'//
%WMIGUID_QUERY                 = &H0001
%WMIGUID_SET                   = &H0002
%WMIGUID_NOTIFICATION          = &H0004
%WMIGUID_READ_DESCRIPTION      = &H0008
%WMIGUID_EXECUTE               = &H0010
%TRACELOG_CREATE_REALTIME      = &H0020
%TRACELOG_CREATE_ONDISK        = &H0040
%TRACELOG_GUID_ENABLE          = &H0080
%TRACELOG_ACCESS_KERNEL_LOGGER = &H0100
%TRACELOG_CREATE_INPROC        = &H0200
%TRACELOG_ACCESS_REALTIME      = &H0400
%TRACELOG_REGISTER_GUIDS       = &H0800

%WMIGUID_ALL_ACCESS = %STANDARD_RIGHTS_READ OR _
                      %SYNCHRONIZE OR _
                      %WMIGUID_QUERY OR _
                      %WMIGUID_SET OR _
                      %WMIGUID_NOTIFICATION OR _
                      %WMIGUID_READ_DESCRIPTION OR _
                      %WMIGUID_EXECUTE OR _
                      %TRACELOG_CREATE_REALTIME OR _
                      %TRACELOG_CREATE_ONDISK OR _
                      %TRACELOG_GUID_ENABLE OR _
                      %TRACELOG_ACCESS_KERNEL_LOGGER OR _
                      %TRACELOG_CREATE_INPROC OR _
                      %TRACELOG_ACCESS_REALTIME OR _
                      %TRACELOG_REGISTER_GUIDS

%WMI_GLOBAL_LOGGER_ID          = &H0001
'#endif
