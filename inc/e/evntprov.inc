' ########################################################################################
' Microsoft Windows
' File: evntprov.inc
' Contents: Unified provider side user mode API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVNTPROV_INC = 1

%EVENT_MIN_LEVEL                      = 0?
%EVENT_MAX_LEVEL                      = &Hff?

%EVENT_ACTIVITY_CTRL_GET_ID           = 1
%EVENT_ACTIVITY_CTRL_SET_ID           = 2
%EVENT_ACTIVITY_CTRL_CREATE_ID        = 3
%EVENT_ACTIVITY_CTRL_GET_SET_ID       = 4
%EVENT_ACTIVITY_CTRL_CREATE_SET_ID    = 5

'typedef ULONGLONG REGHANDLE, *PREGHANDLE;

%MAX_EVENT_DATA_DESCRIPTORS           = 128
%MAX_EVENT_FILTER_DATA_SIZE           = 1024

%EVENT_FILTER_TYPE_SCHEMATIZED        = &H80000000???

'//
'// EVENT_DATA_DESCRIPTOR is used to pass in user data items
'// in events.
'//
' // Size = 16 bytes
TYPE EVENT_DATA_DESCRIPTOR DWORD
   Ptr      AS QUAD    ' ULONGLONG // Pointer to data
   Size     AS DWORD   ' ULONG // Size of data in bytes
   Reserved AS DWORD   ' ULONG
END TYPE

'//
'// EVENT_DESCRIPTOR describes and categorizes an event.
'//
' // Size = 16 bytes
TYPE EVENT_DESCRIPTOR BYTE
   Id      AS WORD   ' USHORT
   Version AS BYTE   ' UCHAR
   Channel AS BYTE   ' UCHAR
   Level   AS BYTE   ' UCHAR
   Opcode  AS BYTE   ' UCHAR
   Task    AS WORD   ' USHORT
   Keyword AS QUAD   ' ULONGLONG
END TYPE

'//
'// EVENT_FILTER_DESCRIPTOR is used to pass in enable filter
'// data item to a user callback function.
'//
' // Size = 16 bytes
TYPE EVENT_FILTER_DESCRIPTOR DWORD
   Ptr  AS QUAD    ' ULONGLONG
   Size AS DWORD   ' ULONG
   Type AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
TYPE EVENT_FILTER_HEADER BYTE
   Id          AS WORD    ' USHORT
   Version     AS BYTE    ' UCHAR
   Reserved(4) AS BYTE    ' UCHAR[5]
   InstanceId  AS QUAD    ' ULONGLONG
   Size        AS DWORD   ' ULONG
   NextOffset  AS DWORD   ' ULONG
END TYPE

'#ifndef _ETW_KM_

'//
'// Optional callback function that users provide
'//
'typedef
'VOID
'(NTAPI *PENABLECALLBACK) (
'    __in LPCGUID SourceId,
'    __in ULONG IsEnabled,
'    __in UCHAR Level,
'    __in ULONGLONG MatchAnyKeyword,
'    __in ULONGLONG MatchAllKeyword,
'    __in_opt PEVENT_FILTER_DESCRIPTOR FilterData,
'    __inout_opt PVOID CallbackContext
'    );

'SUB EnableCallback ( _
'   BYREF GUID _                             ' __in LPCGUID SourceId
' , BYVAL DWORD _                            ' __in ULONG IsEnabled
' , BYVAL BYTE _                             ' __in UCHAR Level
' , BYVAL QUAD _                             ' __in ULONGLONG MatchAnyKeyword
' , BYVAL QUAD _                             ' __in ULONGLONG MatchAllKeyword
' , BYREF EVENT_FILTER_DESCRIPTOR _          ' __in_opt PEVENT_FILTER_DESCRIPTOR FilterData
' , BYVAL DWORD _                            ' __in_opt PVOID CallbackContext
' )

'//
'// Registration APIs
'//

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventRegister IMPORT "Advapi32.dll" ALIAS "EventRegister" ( _
   BYREF ProviderId AS GUID _                           ' __in LPCGUID ProviderId
 , BYVAL EnableCallback AS DWORD _                      ' __in_opt PENABLECALLBACK EnableCallback
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID CallbackContext
 , BYREF RegHandle AS QUAD _                            ' __out PREGHANDLE RegHandle
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventUnregister IMPORT "Advapi32.dll" ALIAS "EventUnregister" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 ) AS DWORD                                             ' ULONG
'#endif

'//
'// Control (Is Enabled) APIs
'//

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventEnabled IMPORT "Advapi32.dll" ALIAS "EventEnabled" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYREF EventDescriptor AS EVENT_DESCRIPTOR _          ' __in PCEVENT_DESCRIPTOR EventDescriptor
 ) AS BYTE                                              ' BOOLEAN
'#endif

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventProviderEnabled IMPORT "Advapi32.dll" ALIAS "EventProviderEnabled" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYVAL Level AS BYTE _                                ' __in UCHAR Level
 , BYVAL Keyword AS QUAD _                              ' __in ULONGLONG Keyword
 ) AS BYTE                                              ' BOOLEAN
'#endif

'//
'// Writing (Publishing/Logging) APIs
'//

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventWrite IMPORT "Advapi32.dll" ALIAS "EventWrite" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYREF EventDescriptor AS EVENT_DESCRIPTOR _          ' __in PCEVENT_DESCRIPTOR EventDescriptor
 , BYVAL UserDataCount AS DWORD _                       ' __in ULONG UserDataCount
 , BYREF UserData AS EVENT_DATA_DESCRIPTOR _            ' __in PEVENT_DATA_DESCRIPTOR UserData
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventWriteTransfer IMPORT "Advapi32.dll" ALIAS "EventWriteTransfer" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYREF EventDescriptor AS EVENT_DESCRIPTOR _          ' __in PCEVENT_DESCRIPTOR EventDescriptor
 , BYREF ActivityId AS GUID _                           ' __in_opt LPCGUID ActivityId
 , BYREF RelatedActivityId AS GUID _                    ' __in LPCGUID RelatedActivityId
 , BYVAL UserDataCount AS DWORD _                       ' __in ULONG UserDataCount
 , BYREF UserData AS EVENT_DATA_DESCRIPTOR _            ' __in PEVENT_DATA_DESCRIPTOR UserData
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION EventWriteEx IMPORT "Advapi32.dll" ALIAS "EventWriteEx" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYREF EventDescriptor AS EVENT_DESCRIPTOR _          ' __in PCEVENT_DESCRIPTOR EventDescriptor
 , BYVAL Filter AS QUAD _                               ' __in ULONG64 Filter
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF ActivityId AS GUID _                           ' __in_opt LPCGUID ActivityId
 , BYREF RelatedActivityId AS GUID _                    ' __in LPCGUID RelatedActivityId
 , BYVAL UserDataCount AS DWORD _                       ' __in ULONG UserDataCount
 , BYREF UserData AS EVENT_DATA_DESCRIPTOR _            ' __in PEVENT_DATA_DESCRIPTOR UserData
 ) AS DWORD                                             ' ULONG
'#endif

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventWriteString IMPORT "Advapi32.dll" ALIAS "EventWriteString" ( _
   BYVAL RegHandle AS QUAD _                            ' __in REGHANDLE RegHandle
 , BYVAL Level AS BYTE _                                ' __in UCHAR Level
 , BYVAL Keyword AS QUAD _                              ' __in ULONGLONG Keyword
 , BYREF String AS WSTRINGZ _                           ' __in PCWSTR String
 ) AS DWORD                                             ' ULONG
'#endif

'//
'// ActivityId Control APIs
'//

'#if (WINVER >= _WIN32_WINNT_VISTA)
DECLARE FUNCTION EventActivityIdControl IMPORT "Advapi32.dll" ALIAS "EventActivityIdControl" ( _
   BYVAL ControlCode AS DWORD _                         ' __in     ULONG ControlCode
 , BYREF ActivityId AS GUID _                           ' __in_out LPGUID ActivityId
 ) AS DWORD                                             ' ULONG
'#endif

'#endif // _ETW_KM_

' Note: I haven't translated the following macros because they're silly.

'//
'// Macros to create Event and Event Data Descriptors
'//

'FORCEINLINE
'VOID
'EventDataDescCreate(
'    __out PEVENT_DATA_DESCRIPTOR EventDataDescriptor,
'    __in  const VOID* DataPtr,
'    __in  ULONG DataSize
'    )
'{
'    EventDataDescriptor->Ptr = (ULONGLONG)(ULONG_PTR)DataPtr;
'    EventDataDescriptor->Size = DataSize;
'    EventDataDescriptor->Reserved = 0;
'    return;
'}

'FORCEINLINE
'VOID
'EventDescCreate(
'    __out PEVENT_DESCRIPTOR         EventDescriptor,
'    __in  USHORT                    Id,
'    __in  UCHAR                     Version,
'    __in  UCHAR                     Channel,
'    __in  UCHAR                     Level,
'    __in  USHORT                    Task,
'    __in  UCHAR                     Opcode,
'    __in  ULONGLONG                 Keyword
'    )
'{
'    EventDescriptor->Id         = Id;
'    EventDescriptor->Version    = Version;
'    EventDescriptor->Channel    = Channel;
'    EventDescriptor->Level      = Level;
'    EventDescriptor->Task       = Task;
'    EventDescriptor->Opcode     = Opcode;
'    EventDescriptor->Keyword    = Keyword;
'    return;
'}

'FORCEINLINE
'VOID
'EventDescZero(
'    __out PEVENT_DESCRIPTOR         EventDescriptor
'    )
'{
'    memset(EventDescriptor, 0, sizeof(EVENT_DESCRIPTOR));
'    return;
'}

'//
'// Macros to extract info from an Event Descriptor
'//

'FORCEINLINE
'USHORT
'EventDescGetId(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Id);
'}

'FORCEINLINE
'UCHAR
'EventDescGetVersion(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Version);
'}

'FORCEINLINE
'USHORT
'EventDescGetTask(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Task);
'}

'FORCEINLINE
'UCHAR
'EventDescGetOpcode(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Opcode);
'}

'FORCEINLINE
'UCHAR
'EventDescGetChannel(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Channel);
'}

'FORCEINLINE
'UCHAR
'EventDescGetLevel(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Level);
'}

'FORCEINLINE
'ULONGLONG
'EventDescGetKeyword(
'    __in PCEVENT_DESCRIPTOR EventDescriptor
'    )
'{
'    return (EventDescriptor->Keyword);
'}

'//
'// Macros to set info into an Event Descriptor
'//

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetId(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in USHORT                     Id
'    )
'{
'    EventDescriptor->Id         = Id;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetVersion(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in UCHAR                      Version
'    )
'{
'    EventDescriptor->Version    = Version;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetTask(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in USHORT                     Task
'    )
'{
'    EventDescriptor->Task       = Task;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetOpcode(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in UCHAR                      Opcode
'    )
'{
'    EventDescriptor->Opcode     = Opcode;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetLevel(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in UCHAR                      Level
'    )
'{
'    EventDescriptor->Level      = Level;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetChannel(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in UCHAR                      Channel
'    )
'{
'    EventDescriptor->Channel    = Channel;
'    return (EventDescriptor);
'}

'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescSetKeyword(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in ULONGLONG                  Keyword
'    )
'{
'    EventDescriptor->Keyword    = Keyword;
'    return (EventDescriptor);
'}


'FORCEINLINE
'PEVENT_DESCRIPTOR
'EventDescOrKeyword(
'    __in PEVENT_DESCRIPTOR          EventDescriptor,
'    __in ULONGLONG                  Keyword
'    )
'{
'    EventDescriptor->Keyword    |= Keyword;
'    return (EventDescriptor);
'}
