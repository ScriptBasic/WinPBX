' ########################################################################################
' Microsoft Windows
' File: tdh.inc
' Contents: ETW Event payload parsing API && ETW trace providers browsing API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TDH_INC = 1

#INCLUDE ONCE "evntrace.inc"
#INCLUDE ONCE "evntcons.inc"

'typedef ULONG  TDHSTATUS;
'#define TDHAPI  TDHSTATUS __stdcall

%TDHCACHE_LINE  = 8
'#define TDHCACHE_ALIGN __declspec(align(TDHCACHE_LINE))

'typedef TDHCACHE_ALIGN struct _EVENT_MAP_ENTRY {
'    ULONG OutputOffset;
'    union {
'        ULONG Value;  // For ULONG value (valuemap and bitmap)
'        ULONG InputOffset;  // For String value (patternmap or valuemap in WBEM)
'    };
'} EVENT_MAP_ENTRY;
'typedef EVENT_MAP_ENTRY *PEVENT_MAP_ENTRY;

' // Size = 4 bytes
UNION EVENT_MAP_ENTRY_UNION DWORD
   Value       AS DWORD   ' ULONG // For ULONG value (valuemap and bitmap)
   InputOffset AS DWORD   ' ULONG // For String value (patternmap or valuemap in WBEM)
END UNION

' // Size = 8 bytes
TYPE EVENT_MAP_ENTRY DWORD
   OutputOffset AS DWORD   ' ULONG
   EVENT_MAP_ENTRY_UNION
END TYPE

' enum MAP_FLAGS
%EVENTMAP_INFO_FLAG_MANIFEST_VALUEMAP   = &H1???
%EVENTMAP_INFO_FLAG_MANIFEST_BITMAP     = &H2???
%EVENTMAP_INFO_FLAG_MANIFEST_PATTERNMAP = &H4???
%EVENTMAP_INFO_FLAG_WBEM_VALUEMAP       = &H8???
%EVENTMAP_INFO_FLAG_WBEM_BITMAP         = &H10???
%EVENTMAP_INFO_FLAG_WBEM_FLAG           = &H20???
%EVENTMAP_INFO_FLAG_WBEM_NO_MAP         = &H40???

' enum MAP_VALUETYPE
%EVENTMAP_ENTRY_VALUETYPE_ULONG  = 0
%EVENTMAP_ENTRY_VALUETYPE_STRING = 1

'typedef TDHCACHE_ALIGN struct _EVENT_MAP_INFO {
'    ULONG NameOffset;
'    MAP_FLAGS Flag;
'    ULONG EntryCount;
'    union {
'        MAP_VALUETYPE MapEntryValueType;
'        ULONG FormatStringOffset;
'    };
'    __field_ecount(EntryCount) EVENT_MAP_ENTRY MapEntryArray[ANYSIZE_ARRAY];
'} EVENT_MAP_INFO;
'typedef EVENT_MAP_INFO *PEVENT_MAP_INFO;

' // Size = 4 bytes
UNION EVENT_MAP_INFO_UNION DWORD
   MapEntryValueType  AS LONG    ' MAP_VALUETYPE
   FormatStringOffset AS DWORD   ' ULONG
END UNION

' // Size = 24 bytes
TYPE EVENT_MAP_INFO DWORD
   NameOffset       AS DWORD   ' ULONG
   Flag             AS DWORD   ' MAP_FLAGS
   EntryCount       AS DWORD   ' ULONG
   EVENT_MAP_INFO_UNION
   MapEntryArray(0) AS EVENT_MAP_ENTRY   ' variable-length array
END TYPE

'// Intypes and outtypes are defined in winmeta.xml

' enum _TDH_IN_TYPE
%TDH_INTYPE_NULL                        = 0
%TDH_INTYPE_UNICODESTRING               = 1
%TDH_INTYPE_ANSISTRING                  = 2
%TDH_INTYPE_INT8                        = 3
%TDH_INTYPE_UINT8                       = 4
%TDH_INTYPE_INT16                       = 5
%TDH_INTYPE_UINT16                      = 6
%TDH_INTYPE_INT32                       = 7
%TDH_INTYPE_UINT32                      = 8
%TDH_INTYPE_INT64                       = 9
%TDH_INTYPE_UINT64                      = 10
%TDH_INTYPE_FLOAT                       = 11
%TDH_INTYPE_DOUBLE                      = 12
%TDH_INTYPE_BOOLEAN                     = 13
%TDH_INTYPE_BINARY                      = 14
%TDH_INTYPE_GUID                        = 15
%TDH_INTYPE_POINTER                     = 16
%TDH_INTYPE_FILETIME                    = 17
%TDH_INTYPE_SYSTEMTIME                  = 18
%TDH_INTYPE_SID                         = 19
%TDH_INTYPE_HEXINT32                    = 20
%TDH_INTYPE_HEXINT64                    = 21    ' // end of winmeta intypes
%TDH_INTYPE_COUNTEDSTRING               = 300   ' // start of TDH intypes for WBEM
%TDH_INTYPE_COUNTEDANSISTRING           = 301
%TDH_INTYPE_REVERSEDCOUNTEDSTRING       = 302
%TDH_INTYPE_REVERSEDCOUNTEDANSISTRING   = 303
%TDH_INTYPE_NONNULLTERMINATEDSTRING     = 304
%TDH_INTYPE_NONNULLTERMINATEDANSISTRING = 305
%TDH_INTYPE_UNICODECHAR                 = 306
%TDH_INTYPE_ANSICHAR                    = 307
%TDH_INTYPE_SIZET                       = 308
%TDH_INTYPE_HEXDUMP                     = 309
%TDH_INTYPE_WBEMSID                     = 310

' enum TDH_OUT_TYPE {
%TDH_OUTTYPE_NULL          = 0
%TDH_OUTTYPE_STRING        = 1
%TDH_OUTTYPE_DATETIME      = 2
%TDH_OUTTYPE_BYTE          = 3
%TDH_OUTTYPE_UNSIGNEDBYTE  = 4
%TDH_OUTTYPE_SHORT         = 5
%TDH_OUTTYPE_UNSIGNEDSHORT = 6
%TDH_OUTTYPE_INT           = 7
%TDH_OUTTYPE_UNSIGNEDINT   = 8
%TDH_OUTTYPE_LONG          = 9
%TDH_OUTTYPE_UNSIGNEDLONG  = 10
%TDH_OUTTYPE_FLOAT         = 11
%TDH_OUTTYPE_DOUBLE        = 12
%TDH_OUTTYPE_BOOLEAN       = 13
%TDH_OUTTYPE_GUID          = 14
%TDH_OUTTYPE_HEXBINARY     = 15
%TDH_OUTTYPE_HEXINT8       = 16
%TDH_OUTTYPE_HEXINT16      = 17
%TDH_OUTTYPE_HEXINT32      = 18
%TDH_OUTTYPE_HEXINT64      = 19
%TDH_OUTTYPE_PID           = 20
%TDH_OUTTYPE_TID           = 21
%TDH_OUTTYPE_PORT          = 22
%TDH_OUTTYPE_IPV4          = 23
%TDH_OUTTYPE_IPV6          = 24
%TDH_OUTTYPE_SOCKETADDRESS = 25
%TDH_OUTTYPE_CIMDATETIME   = 26
%TDH_OUTTYPE_ETWTIME       = 27
%TDH_OUTTYPE_XML           = 28
%TDH_OUTYTPE_ERRORCODE     = 29    ' // end of winmeta outtypes
%TDH_OUTTYPE_REDUCEDSTRING = 300   ' // start of TDH outtypes for WBEM
%TDH_OUTTYPE_NOPRINT       = 301

' enum PROPERTY_FLAGS
%PropertyStruct           = &H1???    ' // type is struct.
%PropertyParamLength      = &H2???    ' // length field is index of param with length
%PropertyParamCount       = &H4???    ' // count file is index of param with count
%PropertyWBEMXmlFragment  = &H8???    ' // WBEM extension flag for property
%PropertyParamFixedLength = &H10???   ' // length of the parameter is fixed.

'typedef TDHCACHE_ALIGN struct _EVENT_PROPERTY_INFO {
'    PROPERTY_FLAGS Flags;
'    ULONG NameOffset;
'    union {
'        struct _nonStructType {
'            USHORT InType;
'            USHORT OutType;
'            ULONG MapNameOffset;
'        } nonStructType;
'        struct _structType {
'            USHORT StructStartIndex;
'            USHORT NumOfStructMembers;
'            ULONG padding;
'        } structType;
'    };
'    union {
'        USHORT count;
'        USHORT countPropertyIndex;
'    };
'    union {
'        USHORT length;
'        USHORT lengthPropertyIndex;
'    };
'    ULONG Reserved;
'} EVENT_PROPERTY_INFO;
'typedef EVENT_PROPERTY_INFO *PEVENT_PROPERTY_INFO;

' // Size = 8 bytes
TYPE EVENT_PROPERTY_INFO_UNION_1_STRUCT_1 DWORD FILL
   InType        AS WORD    ' USHORT
   OutType       AS WORD    ' USHORT
   MapNameOffset AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE EVENT_PROPERTY_INFO_UNION_1_STRUCT_2 DWORD FILL
   StructStartIndex   AS WORD    ' USHORT
   NumOfStructMembers AS WORD    ' USHORT
   padding            AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
UNION EVENT_PROPERTY_INFO_UNION_1 DWORD
   EVENT_PROPERTY_INFO_UNION_1_STRUCT_1
   EVENT_PROPERTY_INFO_UNION_1_STRUCT_2
END UNION

' // Size = 2 bytes
UNION EVENT_PROPERTY_INFO_UNION_2 WORD
   count              AS WORD   ' USHORT
   countPropertyIndex AS WORD   ' USHORT
END UNION

' // Size = 2 bytes
UNION EVENT_PROPERTY_INFO_UNION_3 WORD
   length               AS WORD   ' USHORT
   lengthPropertyIndex  AS WORD   ' USHORT
END UNION

' // Size = 24 bytes
TYPE EVENT_PROPERTY_INFO DWORD FILL
   Flags      AS DWORD   ' PROPERTY_FLAGS
   NameOffset AS DWORD   ' ULONG
   EVENT_PROPERTY_INFO_UNION_1
   EVENT_PROPERTY_INFO_UNION_2
   EVENT_PROPERTY_INFO_UNION_3
   Reserved   AS DWORD   ' ULONG
END TYPE

' enum DECODING_SOURCE
%DecodingSourceXMLFile = 0
%DecodingSourceWbem    = 1
%DecodingSourceWPP     = 2

'// Copy from Binres.h
' enum TEMPLATE_FLAGS
%TEMPLATE_EVENT_DATA = 1   ' // used when custom xml is not specified
%TEMPLATE_USER_DATA  = 2   ' // used when custom xml is specified

'typedef TDHCACHE_ALIGN struct _TRACE_EVENT_INFO {
'    GUID ProviderGuid;
'    GUID EventGuid;
'    EVENT_DESCRIPTOR EventDescriptor; // Loghorn 128 bits event description
'    DECODING_SOURCE DecodingSource;
'    ULONG ProviderNameOffset;
'    ULONG LevelNameOffset;
'    ULONG ChannelNameOffset;
'    ULONG KeywordsNameOffset;
'    ULONG TaskNameOffset;
'    ULONG OpcodeNameOffset;
'    ULONG EventMessageOffset;
'    ULONG ProviderMessageOffset;
'    ULONG BinaryXMLOffset;
'    ULONG BinaryXMLSize;
'    ULONG ActivityIDNameOffset;
'    ULONG RelatedActivityIDNameOffset;
'    ULONG PropertyCount;
'    ULONG TopLevelPropertyCount;
'    TEMPLATE_FLAGS Flags;
'    __field_ecount(PropertyCount) EVENT_PROPERTY_INFO EventPropertyInfoArray[ANYSIZE_ARRAY];
'} TRACE_EVENT_INFO;
'typedef TRACE_EVENT_INFO *PTRACE_EVENT_INFO;

' // Size = 136 bytes
TYPE TRACE_EVENT_INFO DWORD
   ProviderGuid                AS GUID                  ' GUID
   EventGuid                   AS GUID                  ' GUID
   EventDescriptor             AS EVENT_DESCRIPTOR      ' // Loghorn 128 bits event description
   DecodingSource              AS LONG                  ' DECODING_SOURCE
   ProviderNameOffset          AS DWORD                 ' ULONG
   LevelNameOffset             AS DWORD                 ' ULONG
   ChannelNameOffset           AS DWORD                 ' ULONG
   KeywordsNameOffset          AS DWORD                 ' ULONG
   TaskNameOffset              AS DWORD                 ' ULONG
   OpcodeNameOffset            AS DWORD                 ' ULONG
   EventMessageOffset          AS DWORD                 ' ULONG
   ProviderMessageOffset       AS DWORD                 ' ULONG
   BinaryXMLOffset             AS DWORD                 ' ULONG
   BinaryXMLSize               AS DWORD                 ' ULONG
   ActivityIDNameOffset        AS DWORD                 ' ULONG
   RelatedActivityIDNameOffset AS DWORD                 ' ULONG
   PropertyCount               AS DWORD                 ' ULONG
   TopLevelPropertyCount       AS DWORD                 ' ULONG
   Flags                       AS DWORD                 ' TEMPLATE_FLAGS
   EventPropertyInfoArray(0)   AS EVENT_PROPERTY_INFO   ' variable-length array
END TYPE

'typedef TDHCACHE_ALIGN struct _PROPERTY_DATA_DESCRIPTOR {
'    ULONGLONG PropertyName;         // Pointer to property name
'    ULONG ArrayIndex;                      //  Array Index
'    ULONG Reserved;
'} PROPERTY_DATA_DESCRIPTOR;
'typedef PROPERTY_DATA_DESCRIPTOR *PPROPERTY_DATA_DESCRIPTOR;

' // Size = 16 bytes
TYPE PROPERTY_DATA_DESCRIPTOR   ' Must be 8 byte aligned
   PropertyName AS QUAD    ' ULONGLONG // Pointer to property name
   ArrayIndex   AS DWORD   ' ULONG //  Array Index
   Reserved     AS DWORD   ' ULONG
END TYPE

'// Provider Enumeration

' enum EVENT_FIELD_TYPE
%EventKeywordInformation = 0
%EventLevelInformation   = 1
%EventChannelInformation = 2
%EventTaskInformation    = 3
%EventOpcodeInformation  = 4
%EventInformationMax     = 5

'typedef TDHCACHE_ALIGN struct _PROVIDER_FIELD_INFO {
'    ULONG NameOffset; // English only
'    ULONG DescriptionOffset; // Localization String
'    ULONGLONG Value;
'} PROVIDER_FIELD_INFO;
'typedef PROVIDER_FIELD_INFO *PPROVIDER_FIELD_INFO;

' // Size = 16 bytes
TYPE PROVIDER_FIELD_INFO   ' Must be 8 byte aligned
   NameOffset        AS DWORD   ' ULONG // English only
   DescriptionOffset AS DWORD   ' ULONG // Localization String
   Value             AS QUAD    ' ULONGLONG
END TYPE

'typedef TDHCACHE_ALIGN struct _PROVIDER_FIELD_INFOARRAY {
'    ULONG NumberOfElements;
'    EVENT_FIELD_TYPE FieldType;
'    PROVIDER_FIELD_INFO FieldInfoArray[ANYSIZE_ARRAY];
'} PROVIDER_FIELD_INFOARRAY;
'typedef PROVIDER_FIELD_INFOARRAY *PPROVIDER_FIELD_INFOARRAY;

' // Size = 24 bytes
TYPE PROVIDER_FIELD_INFOARRAY DWORD
   NumberOfElements  AS DWORD   ' ULONG
   FieldType         AS LONG    ' EVENT_FIELD_TYPE
   FieldInfoArray(0) AS PROVIDER_FIELD_INFO   ' variable-length array
END TYPE

'typedef TDHCACHE_ALIGN struct _TRACE_PROVIDER_INFO {
'    GUID ProviderGuid;
'    ULONG SchemaSource;
'    ULONG ProviderNameOffset;
'} TRACE_PROVIDER_INFO;
'typedef TRACE_PROVIDER_INFO *PTRACE_PROVIDER_INFO;

' // Size = 24 bytes
TYPE TRACE_PROVIDER_INFO DWORD
   ProviderGuid       AS GUID    ' GUID
   SchemaSource       AS DWORD   ' ULONG
   ProviderNameOffset AS DWORD   ' ULONG
END TYPE

'typedef TDHCACHE_ALIGN struct _PROVIDER_ENUMERATION_INFO {
'    ULONG NumberOfProviders;
'    ULONG Padding; // for 8 bytes alignment
'    __field_ecount(NumberOfProviders) TRACE_PROVIDER_INFO TraceProviderInfoArray[ANYSIZE_ARRAY];
'} PROVIDER_ENUMERATION_INFO;
'typedef PROVIDER_ENUMERATION_INFO *PPROVIDER_ENUMERATION_INFO;

' // Size = 32 bytes
TYPE PROVIDER_ENUMERATION_INFO DWORD
   NumberOfProviders         AS DWORD   ' ULONG
   Padding                   AS DWORD   ' ULONG // for 8 bytes alignment
   TraceProviderInfoArray(0) AS TRACE_PROVIDER_INFO   ' variable-length array
END TYPE

' enum TDH_CONTEXT_TYPE
%TDH_CONTEXT_WPP_TMFFILE       = 0
%TDH_CONTEXT_WPP_TMFSEARCHPATH = 1
%TDH_CONTEXT_WPP_GMT           = 2
%TDH_CONTEXT_POINTERSIZE       = 3
%TDH_CONTEXT_MAXIMUM           = 4

'typedef  TDHCACHE_ALIGN struct _TDH_CONTEXT {
'    ULONGLONG ParameterValue;    // Pointer to Data
'    TDH_CONTEXT_TYPE ParameterType;
'    ULONG ParameterSize;
'} TDH_CONTEXT;
'typedef TDH_CONTEXT *PTDH_CONTEXT;

' // Size = 16 bytes
TYPE TDH_CONTEXT   ' Must be 8 byte aligned
   ParameterValue AS QUAD    ' ULONGLONG // Pointer to Data
   ParameterType  AS LONG    ' TDH_CONTEXT_TYPE
   ParameterSize  AS DWORD   ' ULONG
END TYPE

DECLARE FUNCTION TdhGetEventInformation IMPORT "Tdh.dll" ALIAS "TdhGetEventInformation" ( _
   BYREF pEvent AS EVENT_RECORD _                       ' __in PEVENT_RECORD pEvent
 , BYVAL TdhContextCount AS DWORD _                     ' __in ULONG TdhContextCount
 , BYREF pTdhContext AS TDH_CONTEXT _                   ' __in PTDH_CONTEXT pTdhContext
 , BYREF pBuffer AS ANY _                               ' __out PTRACE_EVENT_INFO pBuffer
 , BYREF pBufferSize AS DWORD _                         ' __in_out ULONG *pBufferSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhGetEventMapInformation IMPORT "Tdh.dll" ALIAS "TdhGetEventMapInformation" ( _
   BYREF pEvent AS EVENT_RECORD _                       ' __in PEVENT_RECORD pEvent
 , BYREF pMapName AS WSTRINGZ _                         ' __in LPWSTR pMapName
 , BYREF pBuffer AS EVENT_MAP_INFO _                    ' __out PEVENT_MAP_INFO pBuffer
 , BYREF pBufferSize AS DWORD _                         ' __in_out ULONG *pBufferSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhGetPropertySize IMPORT "Tdh.dll" ALIAS "TdhGetPropertySize" ( _
   BYREF pEvent AS EVENT_RECORD _                       ' __in PEVENT_RECORD pEvent
 , BYVAL TdhContextCount AS DWORD _                     ' __in ULONG TdhContextCount
 , BYVAL pTdhContext AS LONG _                          ' __in PTDH_CONTEXT pTdhContext
 , BYVAL PropertyDataCount AS DWORD _                   ' __in ULONG PropertyDataCount
 , BYREF pPropertyData AS PROPERTY_DATA_DESCRIPTOR _    ' __in PPROPERTY_DATA_DESCRIPTOR pPropertyData
 , BYREF pPropertySize AS DWORD _                       ' __out ULONG *pPropertySize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhGetProperty IMPORT "Tdh.dll" ALIAS "TdhGetProperty" ( _
   BYREF pEvent AS EVENT_RECORD _                       ' __in PEVENT_RECORD pEvent
 , BYVAL TdhContextCount AS DWORD _                     ' __in ULONG TdhContextCount
 , BYVAL pTdhContext AS LONG _                          ' __in PTDH_CONTEXT pTdhContext
 , BYVAL PropertyDataCount AS DWORD _                   ' __in ULONG PropertyDataCount
 , BYREF pPropertyData AS PROPERTY_DATA_DESCRIPTOR _    ' __in PPROPERTY_DATA_DESCRIPTOR pPropertyData
 , BYVAL BufferSize AS DWORD _                          ' __in ULONG BufferSize
 , BYREF pBuffer AS ANY _                               ' __out PBYTE pBuffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhEnumerateProviders IMPORT "Tdh.dll" ALIAS "TdhEnumerateProviders" ( _
   BYREF pBuffer AS PROVIDER_ENUMERATION_INFO _         ' __out PPROVIDER_ENUMERATION_INFO pBuffer
 , BYREF pBufferSize AS DWORD _                         ' __in_out ULONG *pBufferSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhQueryProviderFieldInformation IMPORT "Tdh.dll" ALIAS "TdhQueryProviderFieldInformation" ( _
   BYREF pGuid AS GUID _                                ' __in LPGUID pGuid
 , BYVAL EventFieldValue AS QUAD _                      ' __in ULONGLONG EventFieldValue
 , BYVAL EventFieldType AS LONG _                       ' __in EVENT_FIELD_TYPE EventFieldType
 , BYREF pBuffer AS PROVIDER_FIELD_INFOARRAY _          ' __out PPROVIDER_FIELD_INFOARRAY pBuffer
 , BYREF pBufferSize AS DWORD _                         ' __in_out ULONG *pBufferSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TdhEnumerateProviderFieldInformation IMPORT "Tdh.dll" ALIAS "TdhEnumerateProviderFieldInformation" ( _
   BYREF pGuid AS GUID _                                ' __in LPGUID pGuid
 , BYVAL EventFieldType AS LONG _                       ' __in EVENT_FIELD_TYPE EventFieldType
 , BYREF pBuffer AS PROVIDER_FIELD_INFOARRAY _          ' __out PPROVIDER_FIELD_INFOARRAY pBuffer
 , BYREF pBufferSize AS DWORD _                         ' __in_out ULONG *pBufferSize
 ) AS DWORD                                             ' ULONG
