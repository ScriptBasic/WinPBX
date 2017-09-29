' ########################################################################################
' Microsoft Windows
' File: EvnTrace.inc
' Contents: Public headers for event tracing control applications, consumers and providers
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVNTRACE_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "guiddef.inc"
#INCLUDE ONCE "evntprov.inc"
#INCLUDE ONCE "wmistr.inc"

'//
'// EventTraceGuid is used to identify a event tracing session
'//
$EventTraceGuid = GUID$("{68fdd900-4a3e-11d1-84f4-0000f80464e3}")

'//
'// SystemTraceControlGuid. Used to specify event tracing for kernel
'//
$SystemTraceControlGuid = GUID$("{9e814aad-3204-11d2-9a82-006008a86939}")

'//
'// EventTraceConfigGuid. Used to report system configuration records
'//
$EventTraceConfigGuid = GUID$("{01853a65-418f-4f36-aefc-dc0f1d2fd235}")

'//
'// DefaultTraceSecurityGuid. Specifies the default event tracing security
'//
$DefaultTraceSecurityGuid = GUID$("{0811c1af-7a07-4a06-82ed-869455cdf713}")

$KERNEL_LOGGER_NAMEA         = "NT Kernel Logger"
$GLOBAL_LOGGER_NAMEA         = "GlobalLogger"
$EVENT_LOGGER_NAMEA          = "EventLog"
$DIAG_LOGGER_NAMEA           = "DiagLog"

$$KERNEL_LOGGER_NAMEW        = "NT Kernel Logger"$$
$$GLOBAL_LOGGER_NAMEW        = "GlobalLogger"$$
$$EVENT_LOGGER_NAMEW         = "EventLog"$$
$$DIAG_LOGGER_NAMEW          = "DiagLog"$$

#IF %DEF(%UNICODE)
   MACRO KERNEL_LOGGER_NAME = $$KERNEL_LOGGER_NAMEW
   MACRO GLOBAL_LOGGER_NAME = $$GLOBAL_LOGGER_NAMEW
   MACRO EVENT_LOGGER_NAME = $$EVENT_LOGGER_NAMEW
   MACRO DIAG_LOGGER_NAME = $$DIAG_LOGGER_NAMEW
#ELSE
   MACRO KERNEL_LOGGER_NAME = $KERNEL_LOGGER_NAMEA
   MACRO GLOBAL_LOGGER_NAME = $GLOBAL_LOGGER_NAMEA
   MACRO EVENT_LOGGER_NAME = $EVENT_LOGGER_NAMEA
   MACRO DIAG_LOGGER_NAME = $DIAG_LOGGER_NAMEA
#ENDIF

%MAX_MOF_FIELDS              = 16   ' // Limit of USE_MOF_PTR fields

'#ifndef _TRACEHANDLE_DEFINED
'#define _TRACEHANDLE_DEFINED
'typedef ULONG64 TRACEHANDLE, *PTRACEHANDLE;
'#endif

'//types for event data going to System Event Logger
%SYSTEM_EVENT_TYPE           = 1

'//
'// predefined generic event types (0x00 to 0x09 reserved).
'//

%EVENT_TRACE_TYPE_INFO               = &H00?   ' // Info or point event
%EVENT_TRACE_TYPE_START              = &H01?   ' // Start event
%EVENT_TRACE_TYPE_END                = &H02?   ' // End event
%EVENT_TRACE_TYPE_STOP               = &H02?   ' // Stop event (WinEvent compatible)
%EVENT_TRACE_TYPE_DC_START           = &H03?   ' // Collection start marker
%EVENT_TRACE_TYPE_DC_END             = &H04?   ' // Collection end marker
%EVENT_TRACE_TYPE_EXTENSION          = &H05?   ' // Extension/continuation
%EVENT_TRACE_TYPE_REPLY              = &H06?   ' // Reply event
%EVENT_TRACE_TYPE_DEQUEUE            = &H07?   ' // De-queue event
%EVENT_TRACE_TYPE_RESUME             = &H07?   ' // Resume event (WinEvent compatible)
%EVENT_TRACE_TYPE_CHECKPOINT         = &H08?   ' // Generic checkpoint event
%EVENT_TRACE_TYPE_SUSPEND            = &H08?   ' // Suspend event (WinEvent compatible)
%EVENT_TRACE_TYPE_WINEVT_SEND        = &H09?   ' // Send Event (WinEvent compatible)
%EVENT_TRACE_TYPE_WINEVT_RECEIVE     = &HF0?   ' // Receive Event (WinEvent compatible)

'//
'// Predefined Event Tracing Levels for Software/Debug Tracing
'//
'//
'// Trace Level is UCHAR and passed in through the EnableLevel parameter
'// in EnableTrace API. It is retrieved by the provider using the
'// GetTraceEnableLevel macro.It should be interpreted as an integer value
'// to mean everything at or below that level will be traced.
'//
'// Here are the possible Levels.
'//

%TRACE_LEVEL_NONE        = 0?    ' // Tracing is not on
%TRACE_LEVEL_CRITICAL    = 1?    ' // Abnormal exit or termination
%TRACE_LEVEL_FATAL       = 1?    ' // Deprecated name for Abnormal exit or termination
%TRACE_LEVEL_ERROR       = 2?    ' // Severe errors that need logging
%TRACE_LEVEL_WARNING     = 3?    ' // Warnings such as allocation failure
%TRACE_LEVEL_INFORMATION = 4?    ' // Includes non-error cases(e.g.,Entry-Exit)
%TRACE_LEVEL_VERBOSE     = 5?    ' // Detailed traces from intermediate steps
%TRACE_LEVEL_RESERVED6   = 6?
%TRACE_LEVEL_RESERVED7   = 7?
%TRACE_LEVEL_RESERVED8   = 8?
%TRACE_LEVEL_RESERVED9   = 9?


'//
'// Event types for Process & Threads
'//

%EVENT_TRACE_TYPE_LOAD                  = &H0A?     ' // Load image

'//
'// Event types for IO subsystem
'//

%EVENT_TRACE_TYPE_IO_READ               = &H0A?
%EVENT_TRACE_TYPE_IO_WRITE              = &H0B?
%EVENT_TRACE_TYPE_IO_READ_INIT          = &H0C?
%EVENT_TRACE_TYPE_IO_WRITE_INIT         = &H0D?
%EVENT_TRACE_TYPE_IO_FLUSH              = &H0E?
%EVENT_TRACE_TYPE_IO_FLUSH_INIT         = &H0F?


' //
' // Event types for Memory subsystem
' //

%EVENT_TRACE_TYPE_MM_TF                 = &H0A?       ' // Transition fault
%EVENT_TRACE_TYPE_MM_DZF                = &H0B?       ' // Demand Zero fault
%EVENT_TRACE_TYPE_MM_COW                = &H0C?       ' // Copy on Write
%EVENT_TRACE_TYPE_MM_GPF                = &H0D?       ' // Guard Page fault
%EVENT_TRACE_TYPE_MM_HPF                = &H0E?       ' // Hard page fault
%EVENT_TRACE_TYPE_MM_AV                 = &H0F?       ' // Access violation

'//
'// Event types for Network subsystem, all protocols
'//

%EVENT_TRACE_TYPE_SEND                  = &H0A?      ' // Send
%EVENT_TRACE_TYPE_RECEIVE               = &H0B?      ' // Receive
%EVENT_TRACE_TYPE_CONNECT               = &H0C?      ' // Connect
%EVENT_TRACE_TYPE_DISCONNECT            = &H0D?      ' // Disconnect
%EVENT_TRACE_TYPE_RETRANSMIT            = &H0E?      ' // ReTransmit
%EVENT_TRACE_TYPE_ACCEPT                = &H0F?      ' // Accept
%EVENT_TRACE_TYPE_RECONNECT             = &H10?      ' // ReConnect
%EVENT_TRACE_TYPE_CONNFAIL              = &H11?      ' // Fail
%EVENT_TRACE_TYPE_COPY_TCP              = &H12?      ' // Copy in PendData
%EVENT_TRACE_TYPE_COPY_ARP              = &H13?      ' // NDIS_STATUS_RESOURCES Copy
%EVENT_TRACE_TYPE_ACKFULL               = &H14?      ' // A full data ACK
%EVENT_TRACE_TYPE_ACKPART               = &H15?      ' // A Partial data ACK
%EVENT_TRACE_TYPE_ACKDUP                = &H16?      ' // A Duplicate data ACK


'//
'// Event Types for the Header (to handle internal event headers)
'//

%EVENT_TRACE_TYPE_GUIDMAP                = &H0A?
%EVENT_TRACE_TYPE_CONFIG                 = &H0B?
%EVENT_TRACE_TYPE_SIDINFO                = &H0C?
%EVENT_TRACE_TYPE_SECURITY               = &H0D?

'//
'// Event Types for Registry subsystem
'//

%EVENT_TRACE_TYPE_REGCREATE                  = &H0A?      ' // NtCreateKey
%EVENT_TRACE_TYPE_REGOPEN                    = &H0B?      ' // NtOpenKey
%EVENT_TRACE_TYPE_REGDELETE                  = &H0C?      ' // NtDeleteKey
%EVENT_TRACE_TYPE_REGQUERY                   = &H0D?      ' // NtQueryKey
%EVENT_TRACE_TYPE_REGSETVALUE                = &H0E?      ' // NtSetValueKey
%EVENT_TRACE_TYPE_REGDELETEVALUE             = &H0F?      ' // NtDeleteValueKey
%EVENT_TRACE_TYPE_REGQUERYVALUE              = &H10?      ' // NtQueryValueKey
%EVENT_TRACE_TYPE_REGENUMERATEKEY            = &H11?      ' // NtEnumerateKey
%EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY       = &H12?      ' // NtEnumerateValueKey
%EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE      = &H13?      ' // NtQueryMultipleValueKey
%EVENT_TRACE_TYPE_REGSETINFORMATION          = &H14?      ' // NtSetInformationKey
%EVENT_TRACE_TYPE_REGFLUSH                   = &H15?      ' // NtFlushKey
%EVENT_TRACE_TYPE_REGKCBCREATE               = &H16?      ' // KcbCreate
%EVENT_TRACE_TYPE_REGKCBDELETE               = &H17?      ' // KcbDelete
%EVENT_TRACE_TYPE_REGKCBRUNDOWNBEGIN         = &H18?      ' // KcbRundownBegin
%EVENT_TRACE_TYPE_REGKCBRUNDOWNEND           = &H19?      ' // KcbRundownEnd
%EVENT_TRACE_TYPE_REGVIRTUALIZE              = &H1A?      ' // VirtualizeKey
%EVENT_TRACE_TYPE_REGCLOSE                   = &H1B?      ' // NtClose (KeyObject)
%EVENT_TRACE_TYPE_REGSETSECURITY             = &H1C?      ' // SetSecurityDescriptor (KeyObject)
%EVENT_TRACE_TYPE_REGQUERYSECURITY           = &H1D?      ' // QuerySecurityDescriptor (KeyObject)
%EVENT_TRACE_TYPE_REGCOMMIT                  = &H1E?      ' // CmKtmNotification (TRANSACTION_NOTIFY_COMMIT)
%EVENT_TRACE_TYPE_REGPREPARE                 = &H1F?      ' // CmKtmNotification (TRANSACTION_NOTIFY_PREPARE)
%EVENT_TRACE_TYPE_REGROLLBACK                = &H20?      ' // CmKtmNotification (TRANSACTION_NOTIFY_ROLLBACK)
%EVENT_TRACE_TYPE_REGMOUNTHIVE               = &H21?      ' // NtLoadKey variations + system hives

'//
'// Event types for system configuration records
'//
%EVENT_TRACE_TYPE_CONFIG_CPU             = &H0A?      ' // CPU Configuration
%EVENT_TRACE_TYPE_CONFIG_PHYSICALDISK    = &H0B?      ' // Physical Disk Configuration
%EVENT_TRACE_TYPE_CONFIG_LOGICALDISK     = &H0C?      ' // Logical Disk Configuration
%EVENT_TRACE_TYPE_CONFIG_NIC             = &H0D?      ' // NIC Configuration
%EVENT_TRACE_TYPE_CONFIG_VIDEO           = &H0E?      ' // Video Adapter Configuration
%EVENT_TRACE_TYPE_CONFIG_SERVICES        = &H0F?      ' // Active Services
%EVENT_TRACE_TYPE_CONFIG_POWER           = &H10?      ' // ACPI Configuration
%EVENT_TRACE_TYPE_CONFIG_NETINFO         = &H11?      ' // Networking Configuration

%EVENT_TRACE_TYPE_CONFIG_IRQ             = &H15?      ' // IRQ assigned to devices
%EVENT_TRACE_TYPE_CONFIG_PNP             = &H16?      ' // PnP device info
%EVENT_TRACE_TYPE_CONFIG_IDECHANNEL      = &H17?      ' // Primary/Secondary IDE channel Configuration
%EVENT_TRACE_TYPE_CONFIG_PLATFORM        = &H19?      ' // Platform Configuration


'//
'// Enable flags for Kernel Events
'//
%EVENT_TRACE_FLAG_PROCESS            = &H00000001???   ' // process start & end
%EVENT_TRACE_FLAG_THREAD             = &H00000002???   ' // thread start & end
%EVENT_TRACE_FLAG_IMAGE_LOAD         = &H00000004???   ' // image load

%EVENT_TRACE_FLAG_DISK_IO            = &H00000100???   ' // physical disk IO
%EVENT_TRACE_FLAG_DISK_FILE_IO       = &H00000200???   ' // requires disk IO

%EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS = &H00001000???   ' // all page faults
%EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS = &H00002000???   ' // hard faults only

%EVENT_TRACE_FLAG_NETWORK_TCPIP      = &H00010000???   ' // tcpip send & receive

%EVENT_TRACE_FLAG_REGISTRY           = &H00020000???   ' // registry calls
%EVENT_TRACE_FLAG_DBGPRINT           = &H00040000???   ' // DbgPrint(ex) Calls

'//
'// Enable flags for Kernel Events on Vista and above
'//
%EVENT_TRACE_FLAG_PROCESS_COUNTERS   = &H00000008???   ' // process perf counters
%EVENT_TRACE_FLAG_CSWITCH            = &H00000010???   ' // context switches
%EVENT_TRACE_FLAG_DPC                = &H00000020???   ' // deffered procedure calls
%EVENT_TRACE_FLAG_INTERRUPT          = &H00000040???   ' // interrupts
%EVENT_TRACE_FLAG_SYSTEMCALL         = &H00000080???   ' // system calls

%EVENT_TRACE_FLAG_DISK_IO_INIT       = &H00000400???   ' // physical disk IO initiation

%EVENT_TRACE_FLAG_ALPC               = &H00100000???   ' // ALPC traces
%EVENT_TRACE_FLAG_SPLIT_IO           = &H00200000???   ' // split io traces (VolumeManager)

%EVENT_TRACE_FLAG_DRIVER             = &H00800000???   ' // driver delays
%EVENT_TRACE_FLAG_PROFILE            = &H01000000???   ' // sample based profiling
%EVENT_TRACE_FLAG_FILE_IO            = &H02000000???   ' // file IO
%EVENT_TRACE_FLAG_FILE_IO_INIT       = &H04000000???   ' // file IO initiation

'//
'// Enable flags for Kernel Events on Win7 and above
'//
%EVENT_TRACE_FLAG_DISPATCHER         = &H00000800???   ' // scheduler (ReadyThread)
%EVENT_TRACE_FLAG_VIRTUAL_ALLOC      = &H00004000???   ' // VM operations

'//
'// Pre-defined Enable flags for everybody else
'//
%EVENT_TRACE_FLAG_EXTENSION          = &H80000000???   ' // Indicates more flags
%EVENT_TRACE_FLAG_FORWARD_WMI        = &H40000000???   ' // Can forward to WMI
%EVENT_TRACE_FLAG_ENABLE_RESERVE     = &H20000000???   ' // Reserved

'//
'// Logger Mode flags
'//
%EVENT_TRACE_FILE_MODE_NONE          = &H00000000???   ' // Logfile is off
%EVENT_TRACE_FILE_MODE_SEQUENTIAL    = &H00000001???   ' // Log sequentially
%EVENT_TRACE_FILE_MODE_CIRCULAR      = &H00000002???   ' // Log in circular manner
%EVENT_TRACE_FILE_MODE_APPEND        = &H00000004???   ' // Append sequential log

%EVENT_TRACE_REAL_TIME_MODE          = &H00000100???   ' // Real time mode on
%EVENT_TRACE_DELAY_OPEN_FILE_MODE    = &H00000200???   ' // Delay opening file
%EVENT_TRACE_BUFFERING_MODE          = &H00000400???   ' // Buffering mode only
%EVENT_TRACE_PRIVATE_LOGGER_MODE     = &H00000800???   ' // Process Private Logger
%EVENT_TRACE_ADD_HEADER_MODE         = &H00001000???   ' // Add a logfile header

%EVENT_TRACE_USE_GLOBAL_SEQUENCE     = &H00004000???   ' // Use global sequence no.
%EVENT_TRACE_USE_LOCAL_SEQUENCE      = &H00008000???   ' // Use local sequence no.

%EVENT_TRACE_RELOG_MODE              = &H00010000???   ' // Relogger

%EVENT_TRACE_USE_PAGED_MEMORY        = &H01000000???   ' // Use pageable buffers

'//
'// Logger Mode flags on XP and above
'//
%EVENT_TRACE_FILE_MODE_NEWFILE       = &H00000008???   ' // Auto-switch log file
%EVENT_TRACE_FILE_MODE_PREALLOCATE   = &H00000020???   ' // Pre-allocate mode

'//
'// Logger Mode flags on Vista and above
'//
%EVENT_TRACE_NONSTOPPABLE_MODE       = &H00000040???   ' // Session cannot be stopped (Autologger only)
%EVENT_TRACE_SECURE_MODE             = &H00000080???   ' // Secure session
%EVENT_TRACE_USE_KBYTES_FOR_SIZE     = &H00002000???   ' // Use KBytes as file size unit
%EVENT_TRACE_PRIVATE_IN_PROC         = &H00020000???   ' // In process private logger
%EVENT_TRACE_MODE_RESERVED           = &H00100000???   ' // Reserved bit, used to signal Heap/Critsec tracing

'//
'// Logger Mode flags on Win7 and above
'//
%EVENT_TRACE_NO_PER_PROCESSOR_BUFFERING = &H10000000???   ' // Use this for low frequency sessions.

'//
'// ControlTrace Codes
'//
%EVENT_TRACE_CONTROL_QUERY           = 0???
%EVENT_TRACE_CONTROL_STOP            = 1???
%EVENT_TRACE_CONTROL_UPDATE          = 2???

'//
'// Flush ControlTrace Codes for XP and above
'//
%EVENT_TRACE_CONTROL_FLUSH           = 3???        ' // Flushes all the buffers

'//
'// Flags used by WMI Trace Message
'// Note that the order or value of these flags should NOT be changed as they are processed
'// in this order.
'//
%TRACE_MESSAGE_SEQUENCE              = 1???   ' // Message should include a sequence number
%TRACE_MESSAGE_GUID                  = 2???   ' // Message includes a GUID
%TRACE_MESSAGE_COMPONENTID           = 4???   ' // Message has no GUID, Component ID instead
%TRACE_MESSAGE_TIMESTAMP             = 8???   ' // Message includes a timestamp
%TRACE_MESSAGE_PERFORMANCE_TIMESTAMP = 16???  ' // *Obsolete* Clock type is controlled by the logger
%TRACE_MESSAGE_SYSTEMINFO            = 32???  ' // Message includes system information TID,PID

'//
'// Vista flags set by system to indicate provider pointer size.
'//

%TRACE_MESSAGE_POINTER32             = &H0040???   ' // Message logged by 32 bit provider
%TRACE_MESSAGE_POINTER64             = &H0080???   ' // Message logged by 64 bit provider

%TRACE_MESSAGE_FLAG_MASK             = &HFFFF???   ' // Only the lower 16 bits of flags are placed in the message
                                                   ' // those above 16 bits are reserved for local processing
%TRACE_MESSAGE_MAXIMUM_SIZE          = 8*1024      ' // the maximum size allowed for a single trace message
                                                   ' // longer messages will return ERROR_BUFFER_OVERFLOW
'//
'// Flags to indicate to consumer which fields
'// in the EVENT_TRACE_HEADER are valid
'//

%EVENT_TRACE_USE_PROCTIME   = &H0001???     ' // ProcessorTime field is valid
%EVENT_TRACE_USE_NOCPUTIME  = &H0002???     ' // No Kernel/User/Processor Times

 ' //
 ' // TRACE_HEADER_FLAG values are used in the Flags field of EVENT_TRACE_HEADER
 ' // structure while calling into TraceEvent API
 ' //

%TRACE_HEADER_FLAG_USE_TIMESTAMP     = &H00000200???
%TRACE_HEADER_FLAG_TRACED_GUID       = &H00020000???  ' // denotes a trace
%TRACE_HEADER_FLAG_LOG_WNODE         = &H00040000???  ' // request to log Wnode
%TRACE_HEADER_FLAG_USE_GUID_PTR      = &H00080000???  ' // Guid is actually a pointer
%TRACE_HEADER_FLAG_USE_MOF_PTR       = &H00100000???  ' // MOF data are dereferenced

'//
'// Trace header for all legacy events.
'//

' // Size = 1 byte
TYPE EVENT_TRACE_HEADER_UNION_1_STRUCT BYTE
   HeaderType  AS BYTE   ' UCHAR // Header type - internal use only
   MarkerFlags AS BYTE   ' UCHAR // Marker - internal use only
END TYPE

' // Size = 2 bytes
UNION EVENT_TRACE_HEADER_UNION_1
   FieldTypeFlags AS WORD
   EVENT_TRACE_HEADER_UNION_1_STRUCT
END UNION

' // Size = 4 bytes
TYPE EVENT_TRACE_HEADER_UNION_2_STRUCT BYTE
   Type    AS BYTE   ' UCHAR // event type
   Level   AS BYTE   ' UCHAR // trace instrumentation level
   Version AS WORD   ' USHORT // version of trace record
END TYPE

' // Size = 4 bytes
UNION EVENT_TRACE_HEADER_UNION_2
   Version AS DWORD
   Class   AS EVENT_TRACE_HEADER_UNION_2_STRUCT
END UNION

' // Size = 16 bytes
UNION EVENT_TRACE_HEADER_UNION_3
   Guid    AS GUID   ' GUID // Guid that identifies event
   GuidPtr AS QUAD   ' ULONGLONG // use with WNODE_FLAG_USE_GUID_PTR
END UNION

' // Size = 8 bytes
TYPE EVENT_TRACE_HEADER_UNION_4_STRUCT_1 DWORD
   KernelTime AS DWORD   ' ULONG // Kernel Mode CPU ticks
   UserTime   AS DWORD   ' ULONG // User mode CPU ticks
END TYPE

' // Size = 8 bytes
TYPE EVENT_TRACE_HEADER_UNION_4_STRUCT_2
   ClientContext AS DWORD   ' ULONG // Reserved
   Flags         AS DWORD   ' ULONG // Event Flags
END TYPE

' // Size = 8 bytes
UNION EVENT_TRACE_HEADER_UNION_4
   EVENT_TRACE_HEADER_UNION_4_STRUCT_1
   ProcessorTime AS QUAD   ' ULONG64 // Processor Clock
   EVENT_TRACE_HEADER_UNION_4_STRUCT_2
END UNION

' // Size = 48 bytes
TYPE EVENT_TRACE_HEADER BYTE    ' // overlays WNODE_HEADER
   Size      AS WORD            ' USHORT // Size of entire record
   EVENT_TRACE_HEADER_UNION_1
   EVENT_TRACE_HEADER_UNION_2
   ThreadId  AS DWORD           ' ULONG // Thread Id
   ProcessId AS DWORD           ' ULONG // Process Id
   TimeStamp AS QUAD            ' LARGE_INTEGER // time when event happens
   EVENT_TRACE_HEADER_UNION_3
   EVENT_TRACE_HEADER_UNION_4
END TYPE

'//
'// This header is used to trace and track transaction co-relations
'//
' // Size = 2 bytes
TYPE EVENT_INSTANCE_HEADER_UNION_1_STRUCT BYTE
   HeaderType  AS BYTE   ' UCHAR // Header type - internal use only
   MarkerFlags AS BYTE   ' UCHAR // Marker - internal use only
END TYPE

' // Size = 2 bytes
UNION EVENT_INSTANCE_HEADER_UNION_1
   FieldTypeFlags AS WORD
   EVENT_INSTANCE_HEADER_UNION_1_STRUCT
END UNION

' // Size = 4 bytes
TYPE EVENT_INSTANCE_HEADER_UNION_2_STRUCT BYTE
  Type    AS BYTE   ' UCHAR // event type
  Level   AS BYTE   ' UCHAR // trace instrumentation level
  Version AS WORD   ' USHORT // version of trace record
END TYPE

' // Size = 4 bytes
UNION EVENT_INSTANCE_HEADER_UNION_2
   Version AS DWORD
   Class   AS EVENT_INSTANCE_HEADER_UNION_2_STRUCT
END UNION

' // Size = 8 bytes
TYPE EVENT_INSTANCE_HEADER_UNION_3_STRUCT_1 DWORD
   KernelTime AS DWORD   ' ULONG // Kernel Mode CPU ticks
   UserTime   AS DWORD   ' ULONG // User mode CPU ticks
END TYPE

' // Size = 8 bytes
TYPE EVENT_INSTANCE_HEADER_UNION_3_STRUCT_2 DWORD
   EventId AS DWORD   ' ULONG // Event ID
   Flags   AS DWORD   ' ULONG // Trace header Flags
END TYPE

' // Size = 8 bytes
UNION EVENT_INSTANCE_HEADER_UNION_3
   EVENT_INSTANCE_HEADER_UNION_3_STRUCT_1
   ProcessorTime AS QUAD   ' ULONG64 // Processor Clock
   EVENT_INSTANCE_HEADER_UNION_3_STRUCT_2
END UNION

' // Size = 56 bytes
TYPE EVENT_INSTANCE_HEADER BYTE
   Size             AS WORD    ' USHORT
   EVENT_INSTANCE_HEADER_UNION_1
   EVENT_TRACE_HEADER_UNION_2
   ThreadId         AS DWORD   ' ULONG // Thread Id
   ProcessId        AS DWORD   ' ULONG // Process Id
   TimeStamp        AS QUAD    ' LARGE_INTEGER // time when event happens
   RegHandle        AS QUAD    ' ULONGLONG
   InstanceId       AS DWORD   ' ULONG
   ParentInstanceId AS DWORD   ' ULONG
   EVENT_INSTANCE_HEADER_UNION_3
   ParentRegHandle  AS QUAD   ' ULONGLONG
END TYPE

'//
'// Following are structures and macros for use with USE_MOF_PTR
'//

'// Trace data types
%ETW_NULL_TYPE_VALUE                        = 0???
%ETW_OBJECT_TYPE_VALUE                      = 1???
%ETW_STRING_TYPE_VALUE                      = 2???
%ETW_SBYTE_TYPE_VALUE                       = 3???
%ETW_BYTE_TYPE_VALUE                        = 4???
%ETW_INT16_TYPE_VALUE                       = 5???
%ETW_UINT16_TYPE_VALUE                      = 6???
%ETW_INT32_TYPE_VALUE                       = 7???
%ETW_UINT32_TYPE_VALUE                      = 8???
%ETW_INT64_TYPE_VALUE                       = 9???
%ETW_UINT64_TYPE_VALUE                      = 10???
%ETW_CHAR_TYPE_VALUE                        = 11???
%ETW_SINGLE_TYPE_VALUE                      = 12???
%ETW_DOUBLE_TYPE_VALUE                      = 13???
%ETW_BOOLEAN_TYPE_VALUE                     = 14???
%ETW_DECIMAL_TYPE_VALUE                     = 15???
'// Extended types
%ETW_GUID_TYPE_VALUE                        = 101???
%ETW_ASCIICHAR_TYPE_VALUE                   = 102???
%ETW_ASCIISTRING_TYPE_VALUE                 = 103???
%ETW_COUNTED_STRING_TYPE_VALUE              = 104???
%ETW_POINTER_TYPE_VALUE                     = 105???
%ETW_SIZET_TYPE_VALUE                       = 106???
%ETW_HIDDEN_TYPE_VALUE                      = 107???
%ETW_BOOL_TYPE_VALUE                        = 108???
%ETW_COUNTED_ANSISTRING_TYPE_VALUE          = 109???
%ETW_REVERSED_COUNTED_STRING_TYPE_VALUE     = 110???
%ETW_REVERSED_COUNTED_ANSISTRING_TYPE_VALUE = 111???
%ETW_NON_NULL_TERMINATED_STRING_TYPE_VALUE  = 112???
%ETW_REDUCED_ANSISTRING_TYPE_VALUE          = 113???
%ETW_REDUCED_STRING_TYPE_VALUE              = 114???
%ETW_SID_TYPE_VALUE                         = 115???
%ETW_VARIANT_TYPE_VALUE                     = 116???
%ETW_PTVECTOR_TYPE_VALUE                    = 117???
%ETW_WMITIME_TYPE_VALUE                     = 118???
%ETW_DATETIME_TYPE_VALUE                    = 119???
%ETW_REFRENCE_TYPE_VALUE                    = 120???


'#define DEFINE_TRACE_MOF_FIELD(MOF, ptr, length, type) \
'    (MOF)->DataPtr  = (ULONG64)(ULONG_PTR) ptr; \
'    (MOF)->Length   = (ULONG) length; \
'    (MOF)->DataType = (ULONG) type;

' // Size = 16 bytes
TYPE MOF_FIELD QWORD FILL
   DataPtr  AS QUAD    ' ULONG64 // Pointer to the field. Up to 64-bits only
   Length   AS DWORD   ' ULONG   // Length of the MOF field
   DataType AS DWORD   ' ULONG   // Type of data
END TYPE

MACRO DEFINE_TRACE_MOF_FIELD(MOF, ptr_, length, type_)
   MOF.DataPtr  = ptr_
   MOF.Length   = length
   MOF.DataType = type_
END MACRO


'#if !(defined(_NTDDK_) || defined(_NTIFS_)) || defined(_WMIKM_)

'//
'// This is the header for every logfile. The memory for LoggerName
'// and LogFileName must be contiguous adjacent to this structure
'// Allows both user-mode and kernel-mode to understand the header
'//
'// TRACE_LOGFILE_HEADER32 and TRACE_LOGFILE_HEADER64 structures
'// are also provided to simplify cross platform decoding of the
'// header event.
'//

' // Size = 4 bytes
TYPE TRACE_LOGFILE_HEADER_UNION_1_STRUCT BYTE
   MajorVersion    AS BYTE   ' UCHAR
   MinorVersion    AS BYTE   ' UCHAR
   SubVersion      AS BYTE   ' UCHAR
   SubMinorVersion AS BYTE   ' UCHAR
END TYPE

' // Size = 4 bytes
UNION TRACE_LOGFILE_HEADER_UNION_1
   Version AS DWORD   ' ULONG // Logger version
   VersionDetail AS TRACE_LOGFILE_HEADER_UNION_1_STRUCT
END UNION

' // Size = 16 bytes
TYPE TRACE_LOGFILE_HEADER_UNION_2_STRUCT DWORD
   StartBuffers  AS DWORD   ' ULONG // Count of buffers written at start.
   PointerSize   AS DWORD   ' ULONG // Size of pointer type in bits
   EventsLost    AS DWORD   ' ULONG // Events losts during log session
   CpuSpeedInMHz AS DWORD   ' ULONG // Cpu Speed in MHz
END TYPE

' // Size = 16 bytes
UNION TRACE_LOGFILE_HEADER_UNION_2
   LogInstanceGuid AS GUID   ' GUID // For RealTime Buffer Delivery
   TRACE_LOGFILE_HEADER_UNION_2_STRUCT
END UNION

' // Size = 272 bytes
TYPE TRACE_LOGFILE_HEADER QWORD FILL
   BufferSize         AS DWORD          ' ULONG // Logger buffer size in Kbytes
   TRACE_LOGFILE_HEADER_UNION_1
   ProviderVersion    AS DWORD          ' ULONG// defaults to NT version
   NumberOfProcessors AS DWORD          ' ULONG // Number of Processors
   EndTime            AS QUAD           ' LARGE_INTEGER // Time when logger stops
   TimerResolution    AS DWORD          ' ULONG // assumes timer is constant!!!
   MaximumFileSize    AS DWORD          ' ULONG // Maximum in Mbytes
   LogFileMode        AS DWORD          ' ULONG // specify logfile mode
   BuffersWritten     AS DWORD          ' ULONG // used to file start of Circular File
   TRACE_LOGFILE_HEADER_UNION_2
   LoggerName         AS WSTRINGZ PTR   ' LPWSTR
   LogFileName        AS WSTRINGZ PTR   ' LPWSTR
   TimeZone           AS TIME_ZONE_INFORMATION
   BootTime           AS QUAD           ' LARGE_INTEGER
   PerfFreq           AS QUAD           ' LARGE_INTEGER // Reserved
   StartTime          AS QUAD           ' LARGE_INTEGER // Reserved
   ReservedFlags      AS DWORD          ' ULONG // ClockType
   BuffersLost        AS DWORD          ' ULONG
END TYPE

' // Size = 272 bytes
TYPE TRACE_LOGFILE_HEADER32 QWORD FILL
   BufferSize         AS DWORD      ' ULONG // Logger buffer size in Kbytes
   TRACE_LOGFILE_HEADER_UNION_1
   ProviderVersion    AS DWORD      ' ULONG// defaults to NT version
   NumberOfProcessors AS DWORD      ' ULONG // Number of Processors
   EndTime            AS QUAD       ' LARGE_INTEGER // Time when logger stops
   TimerResolution    AS DWORD      ' ULONG // assumes timer is constant!!!
   MaximumFileSize    AS DWORD      ' ULONG // Maximum in Mbytes
   LogFileMode        AS DWORD      ' ULONG // specify logfile mode
   BuffersWritten     AS DWORD      ' ULONG // used to file start of Circular File
   TRACE_LOGFILE_HEADER_UNION_2
   LoggerName         AS DWORD      ' ULONG32
   LogFileName        AS DWORD      ' ULONG32
   TimeZone           AS TIME_ZONE_INFORMATION
   BootTime           AS QUAD       ' LARGE_INTEGER
   PerfFreq           AS QUAD       ' LARGE_INTEGER // Reserved
   StartTime          AS QUAD       ' LARGE_INTEGER // Reserved
   ReservedFlags      AS DWORD      ' ULONG // ClockType
   BuffersLost        AS DWORD      ' ULONG
END TYPE

' // Size = 280 bytes
TYPE TRACE_LOGFILE_HEADER64 QWORD FILL
   BufferSize         AS DWORD      ' ULONG // Logger buffer size in Kbytes
   TRACE_LOGFILE_HEADER_UNION_1
   ProviderVersion    AS DWORD      ' ULONG// defaults to NT version
   NumberOfProcessors AS DWORD      ' ULONG // Number of Processors
   EndTime            AS QUAD       ' LARGE_INTEGER // Time when logger stops
   TimerResolution    AS DWORD      ' ULONG // assumes timer is constant!!!
   MaximumFileSize    AS DWORD      ' ULONG // Maximum in Mbytes
   LogFileMode        AS DWORD      ' ULONG // specify logfile mode
   BuffersWritten     AS DWORD      ' ULONG // used to file start of Circular File
   TRACE_LOGFILE_HEADER_UNION_2
   LoggerName         AS QUAD       ' ULONG64
   LogFileName        AS QUAD       ' ULONG64
   TimeZone           AS TIME_ZONE_INFORMATION
   BootTime           AS QUAD       ' LARGE_INTEGER
   PerfFreq           AS QUAD       ' LARGE_INTEGER // Reserved
   StartTime          AS QUAD       ' LARGE_INTEGER // Reserved
   ReservedFlags      AS DWORD      ' ULONG // ClockType
   BuffersLost        AS DWORD      ' ULONG
END TYPE

'#endif // !_NTDDK_ || _WMIKM_

'//
'// Instance Information to track parent child relationship of Instances.
'//
' // Size = 8 bytes
TYPE EVENT_INSTANCE_INFO DWORD
   RegHandle  AS DWORD   ' HANDLE
   InstanceId AS DWORD   ' ULONG
END TYPE

'#if !defined(_WMIKM_) && !defined(_NTDDK_) && !defined(_NTIFS_)
'//
'// Structures that have UNICODE and ANSI versions are defined here
'//

'//
'// Logger configuration and running statistics. This structure is used
'// by user-mode callers, such as PDH library
'//

' // Size = 120 bytes
TYPE EVENT_TRACE_PROPERTIES   ' Must be 8 bytes aligned
   Wnode               AS WNODE_HEADER
   '// data provided by caller
   BufferSize          AS DWORD   ' ULONG // buffer size for logging (kbytes)
   MinimumBuffers      AS DWORD   ' ULONG // minimum to preallocate
   MaximumBuffers      AS DWORD   ' ULONG // maximum buffers allowed
   MaximumFileSize     AS DWORD   ' ULONG // maximum logfile size (in MBytes)
   LogFileMode         AS DWORD   ' ULONG // sequential, circular
   FlushTimer          AS DWORD   ' ULONG // buffer flush timer, in seconds
   EnableFlags         AS DWORD   ' ULONG // trace enable flags
   AgeLimit            AS LONG    ' LONG  // unused
   '// data returned to caller
   NumberOfBuffers     AS DWORD   ' ULONG // no of buffers in use
   FreeBuffers         AS DWORD   ' ULONG // no of buffers free
   EventsLost          AS DWORD   ' ULONG // event records lost
   BuffersWritten      AS DWORD   ' ULONG // no of buffers written to file
   LogBuffersLost      AS DWORD   ' ULONG // no of logfile write failures
   RealTimeBuffersLost AS DWORD   ' ULONG // no of rt delivery failures
   LoggerThreadId      AS DWORD   ' HANDLE // thread id of Logger
   LogFileNameOffset   AS DWORD   ' ULONG // Offset to LogFileName
   LoggerNameOffset    AS DWORD   ' ULONG // Offset to LoggerName
   alignment__         AS DWORD   ' // To keep 8 bytes alignment
END TYPE

'//
'// Data Provider structures
'//
'// Used by RegisterTraceGuids()
'//
' // Size = 8 bytes
TYPE TRACE_GUID_REGISTRATION DWORD
   Guid      AS GUID PTR    ' LPCGUID // Guid of data block being registered or updated.
   RegHandle AS DWORD       ' HANDLE  // Guid Registration Handle is returned.
END TYPE

'//
'// Data consumer structures
'//

'#endif // !_NTDDK_ || _WMIKM_

' // Size = 36 bytes
TYPE TRACE_GUID_PROPERTIES DWORD
   Guid        AS GUID    ' GUID
   GuidType    AS DWORD   ' ULONG
   LoggerId    AS DWORD   ' ULONG
   EnableLevel AS DWORD   ' ULONG
   EnableFlags AS DWORD   ' ULONG
   IsEnable    AS BYTE    ' BOOLEAN
END TYPE

' // Size = 4 bytes
TYPE ETW_BUFFER_CONTEXT BYTE
   ProcessorNumber AS BYTE   ' UCHAR
   Alignment       AS BYTE   ' UCHAR
   LoggerId        AS WORD   ' USHORT
END TYPE

'//
'// Provider Information Flags used on Vista and above.
'//
%TRACE_PROVIDER_FLAG_LEGACY     = &H00000001???
%TRACE_PROVIDER_FLAG_PRE_ENABLE = &H00000002???

'//
'// Enable Information for Provider Instance
'// Used on Vista and above
'//
' // Size = 32 bytes
TYPE TRACE_ENABLE_INFO QWORD FILL
   IsEnabled       AS DWORD   ' ULONG
   Level           AS BYTE    ' UCHAR
   Reserved1       AS BYTE    ' UCHAR
   LoggerId        AS WORD    ' USHORT
   EnableProperty  AS DWORD   ' ULONG
   Reserved2       AS DWORD   ' ULONG
   MatchAnyKeyword AS QUAD    ' ULONGLONG
   MatchAllKeyword AS QUAD    ' ULONGLONG
END TYPE

'//
'// Instance Information for Provider
'// Used on Vista and above
'//
' // Size = 16 bytes
TYPE TRACE_PROVIDER_INSTANCE_INFO DWORD
   NextOffset  AS DWORD   ' ULONG
   EnableCount AS DWORD   ' ULONG
   Pid         AS DWORD   ' ULONG
   Flags       AS DWORD   ' ULONG
END TYPE

'//
'// GUID Information Used on Vista and above
'//
' // Size = 8 bytes
TYPE TRACE_GUID_INFO DWORD
   InstanceCount AS DWORD   ' ULONG
   Reserved      AS DWORD   ' ULONG
END TYPE

'//
'// An EVENT_TRACE consists of a fixed header (EVENT_TRACE_HEADER) and
'// optionally a variable portion pointed to by MofData. The datablock
'// layout of the variable portion is unknown to the Logger and must
'// be obtained from WBEM CIMOM database.
'//

' // Size = 4 bytes
UNION EVENT_TRACE_UNION
   ClientContext AS DWORD   ' ULONG
   BufferContext AS ETW_BUFFER_CONTEXT
END UNION

' // Size = 88 bytes
TYPE EVENT_TRACE   ' Must be 8 bytes aligned
   Header           AS EVENT_TRACE_HEADER   ' // Event trace header
   InstanceId       AS DWORD                ' ULONG // Instance Id of this event
   ParentInstanceId AS DWORD                ' ULONG // Parent Instance Id.
   ParentGuid       AS GUID                 ' GUID // Parent Guid;
   MofData          AS DWORD                ' PVOID // Pointer to Variable Data
   MofLength        AS DWORD                ' ULONG // Variable Datablock Length
   EVENT_TRACE_UNION
   alignment__      AS DWORD                ' // To keep 8 bytes alignment
END TYPE

%EVENT_CONTROL_CODE_DISABLE_PROVIDER = 0
%EVENT_CONTROL_CODE_ENABLE_PROVIDER  = 1
%EVENT_CONTROL_CODE_CAPTURE_STATE    = 2

'#if !defined(_WMIKM_) && !defined(_NTDDK_) && !defined(_NTIFS_)


'typedef struct _EVENT_RECORD
'                EVENT_RECORD, *PEVENT_RECORD;

'typedef struct _EVENT_TRACE_LOGFILEW
'                EVENT_TRACE_LOGFILEW, *PEVENT_TRACE_LOGFILEW;

'typedef struct _EVENT_TRACE_LOGFILEA
'                EVENT_TRACE_LOGFILEA, *PEVENT_TRACE_LOGFILEA;

'typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKW)
'                (PEVENT_TRACE_LOGFILEW Logfile);

'typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKA)
'                (PEVENT_TRACE_LOGFILEA Logfile);

'typedef VOID (WINAPI *PEVENT_CALLBACK)( PEVENT_TRACE pEvent );

'typedef VOID (WINAPI *PEVENT_RECORD_CALLBACK) (PEVENT_RECORD EventRecord);

'//
'// Prototype for service request callback. Data providers register with WMI
'// by passing a service request callback function that is called for all
'// wmi requests.

'FUNCTION WMIDPREQUEST ( _
'   BYVAL RequestCode AS LONG _                          ' __in WMIDPREQUESTCODE RequestCode
' , BYVAL RequestContext AS DWORD _                      ' __in PVOID RequestContext
' , BYREF BufferSize AS DWORD _                          ' __inout ULONG *BufferSize
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' ) AS DWORD                                             ' ULONG

' // Size = 4 bytes
UNION EVENT_TRACE_LOGFILEW_UNION_1
   LogFileMode      AS DWORD   ' ULONG // Mode of the logfi
   ProcessTraceMode AS DWORD   ' ULONG // Processing flags used on Vista and above
END UNION

' // Size = 4 bytes
UNION EVENT_TRACE_LOGFILEW_UNION_2
   EventCallback       AS DWORD   ' PEVENT_CALLBACK // Callback with EVENT_TRACE
   EventRecordCallback AS DWORD   ' PEVENT_RECORD_CALLBACK // Callback with EVENT_RECORD on Vista and above
END UNION

' // Size = 416 bytes   ' Must be 8 bytes aligned
TYPE EVENT_TRACE_LOGFILEW
   LogFileName    AS WSTRINGZ PTR   ' LPWSTR // Logfile Name
   LoggerName     AS WSTRINGZ PTR   ' LPWSTR // LoggerName
   CurrentTime    AS QUAD           ' LONGLONG // timestamp of last event
   BuffersRead    AS DWORD          ' ULONG // buffers read to date
   EVENT_TRACE_LOGFILEW_UNION_1
   CurrentEvent   AS EVENT_TRACE            ' // Current Event from this stream.
   LogfileHeader  AS TRACE_LOGFILE_HEADER   ' // logfile header structure
   BufferCallback AS DWORD          ' PEVENT_TRACE_BUFFER_CALLBACKW // callback before each buffer is read
   ' //
   ' // following variables are filled for BufferCallback.
   ' //
   BufferSize     AS DWORD      ' ULONG
   Filled         AS DWORD      ' ULONG
   EventsLost     AS DWORD      ' ULONG
   ' //
   ' // following needs to be propaged to each buffer
   ' //
   EVENT_TRACE_LOGFILEW_UNION_2
   IsKernelTrace  AS DWORD     ' ULONG // TRUE for kernel logfile
   Context        AS DWORD     ' PVOID // reserved for internal use
   alignment__    AS DWORD     ' // To keep 8 bytes alignment
END TYPE

' // Size = 4 bytes
UNION EVENT_TRACE_LOGFILEA_UNION_1
   LogFileMode      AS DWORD   ' ULONG // Mode of the logfi
   ProcessTraceMode AS DWORD   ' ULONG // Processing flags used on Vista and above
END UNION

' // Size = 4 bytes
UNION EVENT_TRACE_LOGFILEA_UNION_2
   EventCallback       AS DWORD   ' PEVENT_CALLBACK // Callback with EVENT_TRACE
   EventRecordCallback AS DWORD   ' PEVENT_RECORD_CALLBACK // Callback with EVENT_RECORD on Vista and above
END UNION

' // Size = 416 bytes
TYPE EVENT_TRACE_LOGFILEA
   LogFileName    AS WSTRINGZ PTR   ' LPWSTR // Logfile Name
   LoggerName     AS WSTRINGZ PTR   ' LPWSTR // LoggerName
   CurrentTime    AS QUAD           ' LONGLONG // timestamp of last event
   BuffersRead    AS DWORD          ' ULONG // buffers read to date
   EVENT_TRACE_LOGFILEA_UNION_1
   CurrentEvent   AS EVENT_TRACE            ' // Current Event from this stream.
   LogfileHeader  AS TRACE_LOGFILE_HEADER   ' // logfile header structure
   BufferCallback AS DWORD          ' PEVENT_TRACE_BUFFER_CALLBACKA // callback before each buffer is read
   ' //
   ' // following variables are filled for BufferCallback.
   ' //
   BufferSize     AS DWORD      ' ULONG
   Filled         AS DWORD      ' ULONG
   EventsLost     AS DWORD      ' ULONG
   ' //
   ' // following needs to be propaged to each buffer
   ' //
   EVENT_TRACE_LOGFILEA_UNION_2
   IsKernelTrace  AS DWORD     ' ULONG // TRUE for kernel logfile
   Context        AS DWORD     ' PVOID // reserved for internal use
   alignment__    AS DWORD     ' // To keep 8 bytes alignment
END TYPE

#IF %DEF(%UNICODE)
   MACRO EVENT_TRACE_LOGFILE = EVENT_TRACE_LOGFILEW
#ELSE
   MACRO EVENT_TRACE_LOGFILE = EVENT_TRACE_LOGFILEA
#ENDIF

'//
'// Define generic structures
'//

'#if defined(_UNICODE) || defined(UNICODE)

'//
'// Logger control APIs
'//

'//
'// Use the routine below to start an event trace session
'//

DECLARE FUNCTION StartTraceW IMPORT "Advapi32.dll" ALIAS "StartTraceW" ( _
   BYREF TraceHandle AS QUAD _                          ' __out PTRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION StartTraceA IMPORT "Advapi32.dll" ALIAS "StartTraceA" ( _
   BYREF TraceHandle AS QUAD _                          ' __out PTRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO StartTrace = StartTraceW
#ELSE
   MACRO StartTrace = StartTraceA
#ENDIF

'//
'// Use the routine below to stop an event trace session
'//

DECLARE FUNCTION StopTraceW IMPORT "Advapi32.dll" ALIAS "StopTraceW" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in_opt LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION StopTraceA IMPORT "Advapi32.dll" ALIAS "StopTraceA" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in_opt LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO StopTrace = StopTraceW
#ELSE
   MACRO StopTrace = StopTraceA
#ENDIF

'//
'// Use the routine below to query the properties of an event trace session
'//

DECLARE FUNCTION QueryTraceW IMPORT "Advapi32.dll" ALIAS "QueryTraceW" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in_opt LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION QueryTraceA IMPORT "Advapi32.dll" ALIAS "QueryTraceA" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in_opt LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO QueryTrace = QueryTraceW
#ELSE
   MACRO QueryTrace = QueryTraceA
#ENDIF

'//
'// Use the routine below to update certain properties of an event trace session
'//

DECLARE FUNCTION UpdateTraceW IMPORT "Advapi32.dll" ALIAS "UpdateTraceW" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in_opt LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION UpdateTraceA IMPORT "Advapi32.dll" ALIAS "UpdateTraceA" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in_opt LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO UpdateTrace = UpdateTraceW
#ELSE
   MACRO UpdateTrace = UpdateTraceA
#ENDIF

'//
'// Use the routine below to request that all active buffers an event trace
'// session be "flushed", or written out.
'//

'#if (WINVER >= _WIN32_WINNT_WINXP)
DECLARE FUNCTION FlushTraceW IMPORT "Advapi32.dll" ALIAS "FlushTraceW" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in_opt LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_WINXP)
DECLARE FUNCTION FlushTraceA IMPORT "Advapi32.dll" ALIAS "FlushTraceA" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in_opt LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 ) AS DWORD                                             ' ULONG
'#endif

#IF %DEF(%UNICODE)
   MACRO FlushTrace = FlushTraceW
#ELSE
   MACRO FlushTrace = FlushTraceA
#ENDIF

'//
'// Generic trace control routine
'//
DECLARE FUNCTION ControlTraceW IMPORT "Advapi32.dll" ALIAS "ControlTraceW" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS WSTRINGZ _                     ' __in LPCWSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 , BYVAL ControlCode AS DWORD _                         ' __in ULONG ControlCode
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ControlTraceA IMPORT "Advapi32.dll" ALIAS "ControlTraceA" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF InstanceName AS ASCIIZ _                       ' __in LPCSTR InstanceName
 , BYREF Properties AS EVENT_TRACE_PROPERTIES _         ' __inout PEVENT_TRACE_PROPERTIES Properties
 , BYVAL ControlCode AS DWORD _                         ' __in ULONG ControlCode
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO ControlTrace = ControlTraceW
#ELSE
   MACRO ControlTrace = ControlTraceA
#ENDIF

DECLARE FUNCTION QueryAllTracesW IMPORT "Advapi32.dll" ALIAS "QueryAllTracesW" ( _
   BYREF PropertyArray AS EVENT_TRACE_PROPERTIES _      ' __out PEVENT_TRACE_PROPERTIES *PropertyArray
 , BYVAL PropertyArrayCount AS DWORD _                  ' __in ULONG PropertyArrayCount
 , BYREF LoggerCount AS DWORD _                         ' __out PULONG LoggerCount
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION QueryAllTracesA IMPORT "Advapi32.dll" ALIAS "QueryAllTracesA" ( _
   BYREF PropertyArray AS EVENT_TRACE_PROPERTIES _      ' __out PEVENT_TRACE_PROPERTIES *PropertyArray
 , BYVAL PropertyArrayCount AS DWORD _                  ' __in ULONG PropertyArrayCount
 , BYREF LoggerCount AS DWORD _                         ' __out PULONG LoggerCount
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO QueryAllTraces = QueryAllTracesW
#ELSE
   MACRO QueryAllTraces = QueryAllTracesA
#ENDIF

'//
'// Data Provider Enable APIs
'//

DECLARE FUNCTION EnableTrace IMPORT "Advapi32.dll" ALIAS "EnableTrace" ( _
   BYVAL Enable AS DWORD _                              ' __in ULONG Enable
 , BYVAL EnableFlag AS DWORD _                          ' __in ULONG EnableFlag
 , BYVAL EnableLevel AS DWORD _                         ' __in ULONG EnableLevel
 , BYREF ControlGuid AS GUID _                          ' __in LPCGUID ControlGuid
 , BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 ) AS DWORD                                             ' ULONG

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION EnableTraceEx IMPORT "Advapi32.dll" ALIAS "EnableTraceEx" ( _
   BYREF ProviderId AS GUID _                           ' __in LPCGUID ProviderId
 , BYREF SourceId AS GUID _                             ' __in_opt LPCGUID SourceId
 , BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYVAL IsEnabled AS DWORD _                           ' __in ULONG IsEnabled
 , BYVAL Level AS BYTE _                                ' __in UCHAR Level
 , BYVAL MatchAnyKeyword AS QUAD _                      ' __in ULONGLONG MatchAnyKeyword
 , BYVAL MatchAllKeyword AS QUAD _                      ' __in ULONGLONG MatchAllKeyword
 , BYVAL EnableProperty AS DWORD _                      ' __in ULONG EnableProperty
 , BYREF EnableFilterDesc AS EVENT_FILTER_DESCRIPTOR _  ' __in_opt PEVENT_FILTER_DESCRIPTOR EnableFilterDesc
 ) AS DWORD                                             ' ULONG
'#endif

%ENABLE_TRACE_PARAMETERS_VERSION = 1

' // Size = 32 bytes
TYPE ENABLE_TRACE_PARAMETERS DWORD
   Version          AS DWORD                         ' ULONG
   EnableProperty   AS DWORD                         ' ULONG
   ControlFlags     AS DWORD                         ' ULONG
   SourceId         AS GUID                          ' GUID
   EnableFilterDesc AS EVENT_FILTER_DESCRIPTOR PTR   ' PEVENT_FILTER_DESCRIPTOR
END TYPE

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION EnableTraceEx2 IMPORT "Advapi32.dll" ALIAS "EnableTraceEx2" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF ProviderId AS GUID _                           ' __in LPCGUID ProviderId
 , BYVAL ControlCode AS DWORD _                         ' __in ULONG ControlCode
 , BYVAL Level AS BYTE _                                ' __in UCHAR Level
 , BYVAL MatchAnyKeyword AS QUAD _                      ' __in ULONGLONG MatchAnyKeyword
 , BYVAL MatchAllKeyword AS QUAD _                      ' __in ULONGLONG MatchAllKeyword
 , BYVAL Timeout AS DWORD _                             ' __in ULONG Timeout
 , BYREF EnableFilterDesc AS EVENT_FILTER_DESCRIPTOR _  ' __in_opt PEVENT_FILTER_DESCRIPTOR EnableFilterDesc
 ) AS DWORD                                             ' ULONG
'#endif

' enum TRACE_QUERY_INFO_CLASS alias TRACE_INFO_CLASS
%TraceGuidQueryList    = 0
%TraceGuidQueryInfo    = 1
%TraceGuidQueryProcess = 2
%TraceStackTracingInfo = 3   ' // Win7
%MaxTraceSetInfoClass  = 4

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION EnumerateTraceGuidsEx IMPORT "Advapi32.dll" ALIAS "EnumerateTraceGuidsEx" ( _
   BYVAL TraceQueryInfoClass AS LONG _                  ' __in TRACE_QUERY_INFO_CLASS TraceQueryInfoClass
 , BYREF InBuffer AS ANY _                              ' __in PVOID InBuffer
 , BYVAL InBufferSize AS DWORD _                        ' __in ULONG InBufferSize
 , BYREF OutBuffer AS ANY _                             ' __out PVOID OutBuffer
 , BYVAL OutBufferSize AS DWORD _                       ' __in ULONG OutBufferSize
 , BYREF ReturnLength AS DWORD _                        ' __out PULONG ReturnLength
 ) AS DWORD                                             ' ULONG
'#endif

' // Size = 24 bytes
TYPE CLASSIC_EVENT_ID BYTE
   EventGuid   AS GUID   ' GUID
   Type        AS BYTE   ' UCHAR
   Reserved(6) AS BYTE   ' UCHAR[7]
END TYPE

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION TraceSetInformation IMPORT "Advapi32.dll" ALIAS "TraceSetInformation" ( _
   BYVAL SessionHandle AS QUAD _                        ' __in TRACEHANDLE SessionHandle
 , BYVAL InformationClass AS LONG _                     ' __in TRACE_INFO_CLASS InformationClass
 , BYREF TraceInformation AS ANY _                      ' __in_bcount(InformationLength) PVOID TraceInformation
 , BYVAL InformationLength AS DWORD _                   ' __in ULONG InformationLength
 ) AS DWORD                                             ' ULONG
'#endif

'//
'// Data Provider APIs
'//

DECLARE FUNCTION CreateTraceInstanceId IMPORT "Advapi32.dll" ALIAS "CreateTraceInstanceId" ( _
   BYVAL RegHandle AS DWORD _                           ' __in HANDLE RegHandle
 , BYREF pInstInfo AS EVENT_INSTANCE_INFO _             ' __inout PEVENT_INSTANCE_INFO pInstInfo
 ) AS DWORD                                             ' ULONG

'//
'// Use the routine below to generate and record an event trace
'//

DECLARE FUNCTION TraceEvent IMPORT "Advapi32.dll" ALIAS "TraceEvent" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF EventTrace AS EVENT_TRACE_HEADER _             ' __in PEVENT_TRACE_HEADER EventTrace
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TraceEventInstance IMPORT "Advapi32.dll" ALIAS "TraceEventInstance" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 , BYREF EventTrace AS EVENT_INSTANCE_HEADER _          ' __in PEVENT_TRACE_HEADER EventTrace
 , BYREF pInstInfo AS EVENT_INSTANCE_INFO _             ' __in PEVENT_INSTANCE_INFO pInstInfo
 , BYREF pParentInstInfo AS EVENT_INSTANCE_INFO _       ' __in_opt PEVENT_INSTANCE_INFO pParentInstInfo
 ) AS DWORD                                             ' ULONG

'//
'// Use the routine below to register a guid for tracing.
'//

DECLARE FUNCTION RegisterTraceGuidsW IMPORT "Advapi32.dll" ALIAS "RegisterTraceGuidsW" ( _
   BYVAL RequestAddress AS LONG _                       ' __in WMIDPREQUEST  RequestAddress
 , BYREF RequestContext AS ANY _                        ' __in_opt PVOID     RequestContext
 , BYREF ControlGuid AS GUID _                          ' __in LPCGUID       ControlGuid
 , BYVAL GuidCount AS DWORD _                           ' __in ULONG         GuidCount
 , BYREF TraceGuidReg AS TRACE_GUID_REGISTRATION _      ' __in PTRACE_GUID_REGISTRATION TraceGuidReg
 , BYREF MofImagePath AS WSTRINGZ _                     ' __in_opt LPCWSTR   MofImagePath
 , BYREF MofResourceName AS WSTRINGZ _                  ' __in_opt LPCWSTR   MofResourceName
 , BYREF RegistrationHandle AS QUAD _                   ' __out PTRACEHANDLE RegistrationHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION RegisterTraceGuidsA IMPORT "Advapi32.dll" ALIAS "RegisterTraceGuidsA" ( _
   BYVAL RequestAddress AS LONG _                       ' __in WMIDPREQUEST  RequestAddress
 , BYREF RequestContext AS ANY _                        ' __in_opt PVOID     RequestContext
 , BYREF ControlGuid AS GUID _                          ' __in LPCGUID       ControlGuid
 , BYVAL GuidCount AS DWORD _                           ' __in ULONG         GuidCount
 , BYREF TraceGuidReg AS TRACE_GUID_REGISTRATION _      ' __in PTRACE_GUID_REGISTRATION TraceGuidReg
 , BYREF MofImagePath AS ASCIIZ _                       ' __in_opt LPCSTR    MofImagePath
 , BYREF MofResourceName AS ASCIIZ _                    ' __in_opt LPCSTR    MofResourceName
 , BYREF RegistrationHandle AS QUAD _                   ' __out PTRACEHANDLE RegistrationHandle
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO RegisterTraceGuids = RegisterTraceGuidsW
#ELSE
   MACRO RegisterTraceGuids = RegisterTraceGuidsA
#ENDIF

'#if (WINVER >= _WIN32_WINNT_WINXP)
DECLARE FUNCTION EnumerateTraceGuids IMPORT "Advapi32.dll" ALIAS "EnumerateTraceGuids" ( _
   BYREF GuidPropertiesArray AS TRACE_GUID_PROPERTIES _ ' __inout PTRACE_GUID_PROPERTIES *GuidPropertiesArray
 , BYVAL PropertyArrayCount AS DWORD _                  ' __in __in ULONG PropertyArrayCount
 , BYREF GuidCount AS DWORD _                           ' __out PULONG GuidCount
 ) AS DWORD                                             ' ULONG
'#endif

DECLARE FUNCTION UnregisterTraceGuids IMPORT "Advapi32.dll" ALIAS "UnregisterTraceGuids" ( _
   BYVAL RegistrationHandle AS QUAD _                   ' __in TRACEHANDLE RegistrationHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetTraceLoggerHandle IMPORT "Advapi32.dll" ALIAS "GetTraceLoggerHandle" ( _
   BYREF Buffer AS ANY _                                ' __in PVOID Buffer
 ) AS QUAD                                              ' TRACEHANDLE

DECLARE FUNCTION GetTraceEnableLevel IMPORT "Advapi32.dll" ALIAS "GetTraceEnableLevel" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 ) AS BYTE                                              ' UCHAR

DECLARE FUNCTION GetTraceEnableFlags IMPORT "Advapi32.dll" ALIAS "GetTraceEnableFlags" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 ) AS DWORD                                             ' ULONG

'//
'// Data Consumer APIs and structures start here
'//

DECLARE FUNCTION OpenTraceA IMPORT "Advapi32.dll" ALIAS "OpenTraceA" ( _
   BYREF Logfile AS EVENT_TRACE_LOGFILE _               ' __inout PEVENT_TRACE_LOGFILEA Logfile
 ) AS QUAD                                              ' TRACEHANDLE

DECLARE FUNCTION OpenTraceW IMPORT "Advapi32.dll" ALIAS "OpenTraceW" ( _
   BYREF Logfile AS EVENT_TRACE_LOGFILEW _              ' __inout PEVENT_TRACE_LOGFILEW Logfile
 ) AS QUAD                                              ' TRACEHANDLE

#IF %DEF(%UNICODE)
   MACRO OpenTrace = OpenTraceW
#ELSE
   MACRO OpenTrace = OpenTraceA
#ENDIF

DECLARE FUNCTION ProcessTrace IMPORT "Advapi32.dll" ALIAS "ProcessTrace" ( _
   BYREF HandleArray AS QUAD _                          ' __in PTRACEHANDLE HandleArray
 , BYVAL HandleCount AS DWORD _                         ' __in ULONG HandleCount
 , BYREF StartTime AS FILETIME _                        ' __in_opt LPFILETIME StartTime
 , BYREF EndTime AS FILETIME _                          ' __in_opt LPFILETIME EndTime
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION CloseTrace IMPORT "Advapi32.dll" ALIAS "CloseTrace" ( _
   BYVAL TraceHandle AS QUAD _                          ' __in TRACEHANDLE TraceHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION SetTraceCallback IMPORT "Advapi32.dll" ALIAS "SetTraceCallback" ( _
   BYREF pGuid AS GUID _                                ' __in LPCGUID pGuid
 , BYVAL EventCallback AS DWORD _                       ' __in PEVENT_CALLBACK EventCallback
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION RemoveTraceCallback IMPORT "Advapi32.dll" ALIAS "RemoveTraceCallback" ( _
   BYREF pGuid AS GUID _                                ' __in LPCGUID pGuid
 ) AS DWORD                                             ' ULONG

'//
'// The routines for tracing Messages follow
'//

DECLARE FUNCTION TraceMessage CDECL IMPORT "Advapi32.dll" ALIAS "TraceMessage" ( _
   BYVAL LoggerHandle AS QUAD _                         ' __in TRACEHANDLE LoggerHandle
 , BYVAL MessageFlags AS DWORD _                        ' __in ULONG       MessageFlags
 , BYREF MessageGuid AS GUID _                          ' __in LPCGUID     MessageGuid
 , BYVAL MessageNumber AS WORD _                        ' __in USHORT      MessageNumber
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TraceMessageVa IMPORT "Advapi32.dll" ALIAS "TraceMessageVa" ( _
   BYVAL LoggerHandle AS QUAD _                         ' __in TRACEHANDLE LoggerHandle
 , BYVAL MessageFlags AS DWORD _                        ' __in ULONG       MessageFlags
 , BYREF MessageGuid AS GUID _                          ' __in LPCGUID     MessageGuid
 , BYVAL MessageNumber AS WORD _                        ' __in USHORT      MessageNumber
 , BYREF MessageArgList AS ANY _                        ' __in va_list     MessageArgList
 ) AS DWORD                                             ' ULONG

'#define INVALID_PROCESSTRACE_HANDLE ((TRACEHANDLE)INVALID_HANDLE_VALUE)
%INVALID_PROCESSTRACE_HANDLE = &HFFFFFFFF&&

'//
'//
'// Define the encoding independent routines
'//

'#if defined(UNICODE) || defined(_UNICODE)
'#define RegisterTraceGuids      RegisterTraceGuidsW
'#define StartTrace              StartTraceW
'#define ControlTrace            ControlTraceW
'#if defined(__TRACE_W2K_COMPATIBLE)
'#define StopTrace(a,b,c)        ControlTraceW((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_STOP)
'#define QueryTrace(a,b,c)       ControlTraceW((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_QUERY)
'#define UpdateTrace(a,b,c)      ControlTraceW((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_UPDATE)
'#else
'#define StopTrace               StopTraceW
'#define QueryTrace              QueryTraceW
'#define UpdateTrace             UpdateTraceW
'#endif
'#if (NTDDI_VERSION >= NTDDI_WINXP)
'#define FlushTrace              FlushTraceW
'#endif // NTDDI_VERSION >= NTDDI_WINXP
'#define QueryAllTraces          QueryAllTracesW
'#define OpenTrace               OpenTraceW
'#else
'#define RegisterTraceGuids      RegisterTraceGuidsA
'#define StartTrace              StartTraceA
'#define ControlTrace            ControlTraceA
'#if defined(__TRACE_W2K_COMPATIBLE)
'#define StopTrace(a,b,c)        ControlTraceA((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_STOP)
'#define QueryTrace(a,b,c)       ControlTraceA((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_QUERY)
'#define UpdateTrace(a,b,c)      ControlTraceA((a),(b),(c), \
'                                        EVENT_TRACE_CONTROL_UPDATE)
'#else
'#define StopTrace               StopTraceA
'#define QueryTrace              QueryTraceA
'#define UpdateTrace             UpdateTraceA
'#endif
'#if (NTDDI_VERSION >= NTDDI_WINXP)
'#define FlushTrace              FlushTraceA
'#endif // NTDDI_VERSION >= NTDDI_WINXP
'#define QueryAllTraces          QueryAllTracesA
'#define OpenTrace               OpenTraceA
'#endif  // UNICODE

'MACRO StopTrace(a,b,c) = ControlTrace(a, b, c, %EVENT_TRACE_CONTROL_STOP)
'MACRO QueryTrace(a,b,c) = ControlTrace(a, b, c, %EVENT_TRACE_CONTROL_QUERY)
'MACRO UpdateTrace(a,b,c) = ControlTrace(a, b, c, %EVENT_TRACE_CONTROL_UPDATE)

'MACRO StopTraceW(a,b,c) = ControlTraceW(a, b, c, %EVENT_TRACE_CONTROL_STOP)
'MACRO QueryTraceW(a,b,c) = ControlTraceW(a, b, c, %EVENT_TRACE_CONTROL_QUERY)
'MACRO UpdateTraceW(a,b,c) = ControlTraceW(a, b, c, %EVENT_TRACE_CONTROL_UPDATE)

'#endif /* _WMIKM_  && _NTDDK_ */

'#endif // WINNT
