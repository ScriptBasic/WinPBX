' ########################################################################################
' Microsoft Windows
' File: HttpTrace.inc
' Contents: Event tracing structures for IIS (applies for IIS version >= 7 )
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTTPTRACE_INC = 1

'//
'// HTTP_TRACE_TYPE contains type that are supported by
'// the IIS trace infrastructure.
'// The enum values match the equivalent VARIANT types.
'//
' enum HTTP_TRACE_TYPE
%HTTP_TRACE_TYPE_BYTE = 17         ' // mof type "uint8"
%HTTP_TRACE_TYPE_USHORT = 18       ' // mof type "uint16"
%HTTP_TRACE_TYPE_ULONG = 19        ' // mof type "uint32"
%HTTP_TRACE_TYPE_ULONGLONG = 21    ' // mof type "uint64"
%HTTP_TRACE_TYPE_CHAR = 16         ' // mof type "int8"
%HTTP_TRACE_TYPE_SHORT = 2         ' // mof type "int16"
%HTTP_TRACE_TYPE_LONG = 3          ' // mof type "int32"
%HTTP_TRACE_TYPE_LONGLONG = 20     ' // mof type "int64"
%HTTP_TRACE_TYPE_LPCWSTR = 31      ' // mof type string "w"
%HTTP_TRACE_TYPE_LPCSTR = 30       ' // mof type string "a"
%HTTP_TRACE_TYPE_LPCGUID = 72      ' // mof type object "Guid"
%HTTP_TRACE_TYPE_BOOL = 11         ' // mof type object "boolean"

'// bit values for the HTTP_TRACE_EVENT.dwFlags

'//
'// If HTTP_TRACE_EVENT_FLAG_STATIC_DESCRIPTIVE_FIELDS is set then
'// consumers of the trace event can assume that
'// pProviderGuid, pAreaGuid, pszEventName in the HTTP_TRACE_EVENT
'// and pszName and pszDescription in each HTTP_TRACE_EVENT_ITEM
'// entry are static (their memory is available throughout the
'// process lifetime). If event needs to be buffered there is no need
'// to copy values for these fields
'//
%HTTP_TRACE_EVENT_FLAG_STATIC_DESCRIPTIVE_FIELDS = &H01

'//
'// In addition to TRACE_LEVEL_FATAL - TRACE_LEVEL_VERBOSE
'//
%HTTP_TRACE_LEVEL_START = 6
%HTTP_TRACE_LEVEL_END   = 7

'struct HTTP_TRACE_EVENT_ITEM;

'// Each HTTP_TRACE_EVENT can have multiple items or elements that describe the event
'// (for example the "GENERAL_REQUEST_START" event contains an item with the Request URL)

'struct HTTP_TRACE_EVENT_ITEM
'{
'    //
'    // Friendly name of the item (for example "RequestUrl")
'    //
'    LPCWSTR          pszName;
'    //
'    // Data type that pbData is pointed to
'    //
'    HTTP_TRACE_TYPE  dwDataType;
'    //
'    // Pointer to the actual data (needs to be casted based on the dwDataType)
'    // For example the HTTP_TRACE_EVENT_ITEM describing HTTP request URL would have
'    // the pbData pointing to the actual URL string
'    //
'    PBYTE   pbData;
'    //
'    // # of bytes of the actual data (it should matter only for string types)
'    //
'    DWORD   cbData;
'    //
'    // Additional description of the data - enumerations take advantage of this field
'    // (always set to NULL if not used)
'    //
'    LPCWSTR pszDataDescription;
'};

' // Size = 20 bytes
TYPE HTTP_TRACE_EVENT_ITEM DWORD
   pszName            AS WSTRINGZ PTR   ' LPCWSTR
   dwDataType         AS LONG           ' HTTP_TRACE_TYPE
   pbData             AS BYTE PTR       ' PBYTE
   cbData             AS DWORD          ' DWORD
   pszDataDescription AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'//
'// Each Trace event will need to be described with the HTTP_TRACE_EVENT structure.
'// It is designed to contain all the information relevant to ETW,
'// but ETW is not the only consumer
'//
'//

'struct HTTP_TRACE_EVENT
'{
'    //
'    // Trace Provider (such as "WWW Server")
'    //
'    LPCGUID                 pProviderGuid ;
'    //
'    // Trace Area Flag ( a bit flag that may represent area such as "Authentication")
'    //
'    DWORD                   dwArea;
'    //
'    // GUID equivalent to the Area Flag
'    //
'    LPCGUID                 pAreaGuid;
'    //
'    // ID of the event (in the ETW terminology this would be the Event Type)
'    //
'    DWORD                   dwEvent;
'    //
'    // String matching the event ID (dwEvent)
'    //
'    LPCWSTR                 pszEventName;
'    //
'    // Event version
'    //
'    DWORD                   dwEventVersion;
'    //
'    // Verbosity of the event ( General, FatalError, Error, Warning, Info, Verbose)
'    // In the ETW terminology this is the "event level"
'    DWORD                   dwVerbosity;
'    //
'    // Activity GUID. For the http request based event
'    // it may represent the request ID
'    //
'    LPCGUID                 pActivityGuid;
'    //
'    // Additional GUID to allow to associate
'    // multiple related activities
'    //
'    LPCGUID                 pRelatedActivityGuid;
'    //
'    // Optional timestamp (in GetTickCount() ticks )
'    // If set to 0 then system will fill in the TickCount.
'    //
'    DWORD                   dwTimeStamp;
'    //
'    // Flags (reserved: Set to 0)
'    //
'    DWORD                   dwFlags;
'    //
'    //
'    // Number of entries in the structured
'    // description of the event
'    // Note that the maximum allowed number of EventTraceItems
'    // should match the ETW internal limit of 16
'    //
'    DWORD                   cEventItems;
'    //
'    // Array of individual entries describing
'    // the event
'    //
'    __field_ecount(cEventItems) HTTP_TRACE_EVENT_ITEM * pEventItems;
'};

' // Size = 52 bytes
TYPE HTTP_TRACE_EVENT DWORD
   pProviderGuid        AS GUID PTR                    ' LPCGUID
   dwArea               AS DWORD                       ' DWORD
   pAreaGuid            AS GUID PTR                    ' LPCGUID
   dwEvent              AS DWORD                       ' DWORD
   pszEventName         AS WSTRINGZ PTR                ' LPCWSTR
   dwEventVersion       AS DWORD                       ' DWORD
   dwVerbosity          AS DWORD                       ' DWORD
   pActivityGuid        AS GUID PTR                    ' LPCGUID
   pRelatedActivityGuid AS GUID PTR                    ' LPCGUID
   dwTimeStamp          AS DWORD                       ' DWORD
   dwFlags              AS DWORD                       ' DWORD
   cEventItems          AS DWORD                       ' DWORD
   pEventItems          AS HTTP_TRACE_EVENT_ITEM PTR   ' __field_ecount(cEventItems) HTTP_TRACE_EVENT_ITEM *
END TYPE


'//
'// HTTP_TRACE_CONFIGURATION is used by both trace providers and trace consumers
'// Trace consumers declare the TraceProviders and TraceAreas of the interest.
'// Trace providers can retrieve what areas at what verbosity is allowed
'// for a given provider
'//

' // Size = 16 bytes
TYPE HTTP_TRACE_CONFIGURATION DWORD
   pProviderGuid    AS GUID PTR   ' LPCGUID
   dwAreas          AS DWORD      ' DWORD
   dwVerbosity      AS DWORD      ' DWORD
   fProviderEnabled AS LONG       ' BOOL
END TYPE

'//
'// Definiton of the GUIDs for the TRACE Providers that ship with IIS
'// or are related to IIS
'//

$GUID_IIS_ALL_TRACE_PROVIDERS = GUID$("{00000000-0000-0000-0000-000000000000}")

$GUID_IIS_WWW_SERVER_TRACE_PROVIDER = GUID$("{3A2A4E84-4C21-4981-AE10-3FDA0D9B0F83}")

'// IIS V2(Crimson/Unified) trace provider
$GUID_IIS_WWW_SERVER_V2_TRACE_PROVIDER = GUID$("{de4649c9-15e8-4fea-9d85-1cdda520c334}")

'// ETW name for the provider: "ASP.NET Events
$GUID_IIS_ASPNET_TRACE_PROVIDER = GUID$("{AFF081FE-0247-4275-9C4E-021F3DC1DA35}")

'// ETW name for the provider: "IIS: Active Server Pages (ASP)"
$GUID_IIS_ASP_TRACE_TRACE_PROVIDER = GUID$("{06B94D9A-B15E-456E-A4Ef-37C984A2CB4B}")

$GUID_IIS_WWW_GLOBAL_TRACE_PROVIDER = GUID$("{D55D3BC9-CBA9-44DF-827E-132D3A4596C2}")

'// ETW name for the provider: "IIS: WWW Isapi Extension"
$GUID_IIS_ISAPI_TRACE_PROVIDER = GUID$("{A1C2040E-8840-4C31-BA11-9871031A19EA}")
