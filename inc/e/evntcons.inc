' ########################################################################################
' Microsoft Windows
' File: evntcons.inc
' Contents: Event consumer API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVNTCONS_INC = 1

#INCLUDE ONCE "wmistr.inc"
#INCLUDE ONCE "evntrace.inc"
#INCLUDE ONCE "evntprov.inc"

%EVENT_HEADER_EXT_TYPE_RELATED_ACTIVITYID   = &H0001??
%EVENT_HEADER_EXT_TYPE_SID                  = &H0002??
%EVENT_HEADER_EXT_TYPE_TS_ID                = &H0003??
%EVENT_HEADER_EXT_TYPE_INSTANCE_INFO        = &H0004??
%EVENT_HEADER_EXT_TYPE_STACK_TRACE32        = &H0005??
%EVENT_HEADER_EXT_TYPE_STACK_TRACE64        = &H0006??
%EVENT_HEADER_EXT_TYPE_MAX                  = &H0007??

' // Size = 4 bytes
TYPE EVENT_HEADER_EXTENDED_DATA_ITEM_STRUCT_1 WORD
   Linkage   AS BIT * 1 IN WORD   ' USHORT Linkage   : 1 // Indicates additional extended data item
   Reserved2 AS BIT * 15          ' USHORT Reserved2 : 15
END TYPE

' // Size = 16 bytes
TYPE EVENT_HEADER_EXTENDED_DATA_ITEM WORD
   Reserved1 AS WORD   ' USHORT // Reserved for internal use
   ExtType   AS WORD   ' USHORT // Extended info type
   EVENT_HEADER_EXTENDED_DATA_ITEM_STRUCT_1
   DataSize  AS WORD   ' USHORT // Size of extended info data
   DataPtr   AS QUAD   ' ULONGLONG // Pointer to extended info data
END TYPE

'//
'// Structures for extended items.
'//

' // Size = 24 bytes
TYPE EVENT_EXTENDED_ITEM_INSTANCE DWORD
   InstanceId       AS DWORD   ' ULONG
   ParentInstanceId AS DWORD   ' ULONG
   ParentGuid       AS GUID    ' GUID
END TYPE

' // Size = 16 bytes
TYPE EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID DWORD
   RelatedActivityId AS GUID   ' GUID
END TYPE

' // Size = 4 bytes
TYPE EVENT_EXTENDED_ITEM_TS_ID DWORD
   SessionId AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE EVENT_EXTENDED_ITEM_STACK_TRACE32 QWORD FILL
   MatchId    AS QUAD    ' ULONG64
   Address(0) AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE EVENT_EXTENDED_ITEM_STACK_TRACE64 QWORD
   MatchId    AS QUAD   ' ULONG64
   Address(0) AS QUAD   ' ULONG64
END TYPE

%EVENT_HEADER_PROPERTY_XML               = &H0001??
%EVENT_HEADER_PROPERTY_FORWARDED_XML     = &H0002??
%EVENT_HEADER_PROPERTY_LEGACY_EVENTLOG   = &H0004??

%EVENT_HEADER_FLAG_EXTENDED_INFO         = &H0001??
%EVENT_HEADER_FLAG_PRIVATE_SESSION       = &H0002??
%EVENT_HEADER_FLAG_STRING_ONLY           = &H0004??
%EVENT_HEADER_FLAG_TRACE_MESSAGE         = &H0008??
%EVENT_HEADER_FLAG_NO_CPUTIME            = &H0010??
%EVENT_HEADER_FLAG_32_BIT_HEADER         = &H0020??
%EVENT_HEADER_FLAG_64_BIT_HEADER         = &H0040??
%EVENT_HEADER_FLAG_CLASSIC_HEADER        = &H0100??

' // Size = 4 bytes
TYPE EVENT_HEADER_UNION_STRUCT DWORD
   KernelTime AS DWORD   ' ULONG // Kernel Mode CPU ticks
   UserTime   AS DWORD   ' ULONG // User mode CPU ticks
END TYPE

' // Size = 8 bytes
UNION EVENT_HEADER_UNION QWORD FILL
   EVENT_HEADER_UNION_STRUCT
   ProcessorTime AS QUAD        ' ULONG64 // Processor Clock for private session events
END UNION

' // Size = 80 bytes
TYPE EVENT_HEADER QWORD FILL
   Size            AS WORD               ' USHORT // Event Size
   HeaderType      AS WORD               ' USHORT // Header Type
   Flags           AS WORD               ' USHORT // Flags
   EventProperty   AS WORD               ' USHORT // User given event property
   ThreadId        AS DWORD              ' ULONG // Thread Id
   ProcessId       AS DWORD              ' ULONG // Process Id
   TimeStamp       AS QUAD               ' LARGE_INTEGER // Event Timestamp
   ProviderId      AS GUID               ' GUID // Provider Id
   EventDescriptor AS EVENT_DESCRIPTOR   ' // Event Descriptor
   EVENT_HEADER_UNION
   ActivityId      AS GUID               ' GUID // Activity Id
END TYPE

' // Size = 104 bytes
TYPE EVENT_RECORD ' Must be 8 byte aligned
   EventHeader       AS EVENT_HEADER         ' // Event header
   BufferContext     AS ETW_BUFFER_CONTEXT   ' // Buffer context
   alignment1__      AS DWORD                ' // To keep 8 byte alignment
   ExtendedDataCount AS WORD                 ' USHORT // Number of extended data items
   UserDataLength    AS WORD                 ' USHORT // User data length
   ExtendedData      AS EVENT_HEADER_EXTENDED_DATA_ITEM PTR   'PEVENT_HEADER_EXTENDED_DATA_ITEM // Pointer to an array of extended data items
   UserData          AS DWORD                ' PVOID // Pointer to user data
   UserContext       AS DWORD                ' PVOID // Context from OpenTrace
END TYPE

%EVENT_ENABLE_PROPERTY_SID                   = &H00000001???
%EVENT_ENABLE_PROPERTY_TS_ID                 = &H00000002???
%EVENT_ENABLE_PROPERTY_STACK_TRACE           = &H00000004???

'//
'// Consumer API
'//
%PROCESS_TRACE_MODE_REAL_TIME                = &H00000100???
%PROCESS_TRACE_MODE_RAW_TIMESTAMP            = &H00001000???
%PROCESS_TRACE_MODE_EVENT_RECORD             = &H10000000???


'//
'// Event Security APIs
'//

' enum EVENTSECURITYOPERATION
%EventSecuritySetDACL = 0
%EventSecuritySetSACL = 1
%EventSecurityAddDACL = 2
%EventSecurityAddSACL = 3
%EventSecurityMax     = 4

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION EventAccessControl IMPORT "Advapi32.dll" ALIAS "EventAccessControl" ( _
   BYREF Guid AS GUID _                                 ' __in LPGUID  Guid
 , BYVAL Operation AS DWORD _                           ' __in ULONG   Operation
 , BYVAL Sid AS SID PTR _                               ' __in PSID    Sid
 , BYVAL Rights AS DWORD _                              ' __in ULONG   Rights
 , BYVAL AllowOrDeny AS BYTE _                          ' __in BOOLEAN AllowOrDeny
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION EventAccessQuery IMPORT "Advapi32.dll" ALIAS "EventAccessQuery" ( _
   BYREF Guid AS GUID _                                 ' __in LPGUID Guid
 , BYREF Buffer AS SECURITY_DESCRIPTOR _                ' __in_out PSECURITY_DESCRIPTOR Buffer
 , BYREF BufferSize AS DWORD _                          ' __in_out PULONG BufferSize
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION EventAccessRemove IMPORT "Advapi32.dll" ALIAS "EventAccessRemove" ( _
   BYREF Guid AS GUID _                                 ' __in LPGUID Guid
 ) AS DWORD                                             ' ULONG
'#endif
