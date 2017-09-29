' ########################################################################################
' Microsoft Windows
' File: winevt.inc
' Contents: Windows Events API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINEVT_INC = 1

#INCLUDE ONCE "windows.inc"

'#if (WINVER >= _WIN32_WINNT_LONGHORN)

'typedef HANDLE EVT_HANDLE, *PEVT_HANDLE;


' enum EVT_VARIANT_TYPE
%EvtVarTypeNull        = 0
%EvtVarTypeString      = 1
%EvtVarTypeAnsiString  = 2
%EvtVarTypeSByte       = 3
%EvtVarTypeByte        = 4
%EvtVarTypeInt16       = 5
%EvtVarTypeUInt16      = 6
%EvtVarTypeInt32       = 7
%EvtVarTypeUInt32      = 8
%EvtVarTypeInt64       = 9
%EvtVarTypeUInt64      = 10
%EvtVarTypeSingle      = 11
%EvtVarTypeDouble      = 12
%EvtVarTypeBoolean     = 13
%EvtVarTypeBinary      = 14
%EvtVarTypeGuid        = 15
%EvtVarTypeSizeT       = 16
%EvtVarTypeFileTime    = 17
%EvtVarTypeSysTime     = 18
%EvtVarTypeSid         = 19
%EvtVarTypeHexInt32    = 20
%EvtVarTypeHexInt64    = 21

'// these types used internally
%EvtVarTypeEvtHandle   = 32
%EvtVarTypeEvtXml      = 35


%EVT_VARIANT_TYPE_MASK  = &H7f
%EVT_VARIANT_TYPE_ARRAY = 128

' // Size = 8 bytes
UNION EVT_VARIANT_UNION
   BooleanVal    AS LONG             ' BOOL
   SByteVal      AS BYTE             ' INT8
   Int16Val      AS INTEGER          ' INT16
   Int32Val      AS LONG             ' INT32
   Int64Val      AS QUAD             ' INT64
   ByteVal       AS BYTE             ' UINT8
   UInt16Val     AS WORD             ' UINT16
   UInt32Val     AS DWORD            ' UINT32
   UInt64Val     AS QUAD             ' UINT64
   SingleVal     AS SINGLE           ' float
   DoubleVal     AS DOUBLE           ' double
   FileTimeVal   AS QUAD             ' ULONGLONG
   SysTimeVal    AS SYSTEMTIME PTR   ' SYSTEMTIME*
   GuidVal       AS GUID PTR         ' GUID*
   StringVal     AS WSTRINGZ PTR     ' LPCWSTR
   AnsiStringVal AS ASCIIZ PTR       ' LPCSTR
   BinaryVal     AS BYTE PTR         ' PBYTE
   SidVal        AS SID PTR          ' PSID
   SizeTVal      AS DWORD            ' size_t

   ' // array fields
   BooleanArr    AS LONG PTR         ' BOOL*
   SByteArr      AS BYTE PTR         ' INT8*
   Int16Arr      AS INTEGER PTR      ' INT16*
   Int32Arr      AS LONG PTR         ' INT32*
   Int64Arr      AS QUAD PTR         ' INT64*
   ByteArr       AS BYTE PTR         ' UINT8*
   UInt16Arr     AS WORD PTR         ' UINT16*
   UInt32Arr     AS DWORD PTR        ' UINT32*
   UInt64Arr     AS QUAD PTR         ' UINT64*
   SingleArr     AS SINGLE PTR       ' float*
   DoubleArr     AS DOUBLE PTR       ' double*
   FileTimeArr   AS FILETIME PTR     ' FILETIME*
   SysTimeArr    AS SYSTEMTIME PTR   ' SYSTEMTIME*
   GuidArr       AS GUID PTR         ' GUID*
   StringArr     AS WSTRINGZ PTR     ' LPWSTR*
   AnsiStringArr AS ASCIIZ PTR       ' LPSTR*
   SidArr        AS SID PTR          ' PSID*
   SizeTArr      AS DWORD PTR        ' size_t*

   ' // internal fields
   EvtHandleVal  AS DWORD            ' EVT_HANDLE
   XmlVal        AS WSTRINGZ PTR     ' LPCWSTR
   XmlValArr     AS WSTRINGZ PTR     ' LPCWSTR*
END UNION

' // Size = 16 bytes
TYPE EVT_VARIANT DWORD
   EVT_VARIANT_UNION
   Count AS DWORD   ' DWORD // number of elements (not length) in bytes.
   Type  AS DWORD   ' DWORD
END TYPE



'////////////////////////////////////////////////////////////////////////////////
'//
'// Sessions
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_LOGIN_CLASS
%EvtRpcLogin = 1

' enum EVT_RPC_LOGIN_FLAGS
%EvtRpcLoginAuthDefault   = 0
%EvtRpcLoginAuthNegotiate = 1
%EvtRpcLoginAuthKerberos  = 2
%EvtRpcLoginAuthNTLM      = 3

' // Size = 20 bytes
TYPE EVT_RPC_LOGIN DWORD
   ' // all str params are optional
   Server   AS WSTRINGZ PTR   ' LPWSTR
   User     AS WSTRINGZ PTR   ' LPWSTR
   Domain   AS WSTRINGZ PTR   ' LPWSTR
   Password AS WSTRINGZ PTR   ' LPWSTR
   Flags    AS DWORD          ' DWORD // EVT_RPC_LOGIN_FLAGS
END TYPE

DECLARE FUNCTION EvtOpenSession IMPORT "Wevtapi.dll" ALIAS "EvtOpenSession" ( _
   BYVAL LoginClass AS LONG _                           ' __in EVT_LOGIN_CLASS LoginClass
 , BYREF Login AS ANY _                                 ' __in PVOID Login
 , BYVAL Timeout AS DWORD _                             ' __in_reserved DWORD Timeout // currently must be 0
 , BYVAL Flags AS DWORD _                               ' __in_reserved DWORD Flags   // currently must be 0
 ) AS DWORD                                             ' EVT_HANDLE

'////////////////////////////////////////////////////////////////////////////////
'//
'// General Purpose Functions
'//
'////////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION EvtClose IMPORT "Wevtapi.dll" ALIAS "EvtClose" ( _
   BYVAL Object AS DWORD _                              ' __in EVT_HANDLE Object
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtCancel IMPORT "Wevtapi.dll" ALIAS "EvtCancel" ( _
   BYVAL Object AS DWORD _                              ' __in EVT_HANDLE Object
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtGetExtendedStatus IMPORT "Wevtapi.dll" ALIAS "EvtGetExtendedStatus" ( _
   BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 , BYREF Buffer AS WSTRINGZ _                           ' __in LPWSTR Buffer
 , BYREF BufferUsed AS DWORD _                          ' __out PDWORD BufferUsed
 ) AS DWORD                                             ' DWORD

'////////////////////////////////////////////////////////////////////////////////
'//
'// Queries
'//
'////////////////////////////////////////////////////////////////////////////////


' enum EVT_QUERY_FLAGS
%EvtQueryChannelPath                 = &H1???
%EvtQueryFilePath                    = &H2???

%EvtQueryForwardDirection            = &H100???
%EvtQueryReverseDirection            = &H200???

%EvtQueryTolerateQueryErrors         = &H1000???

' enum EVT_SEEK_FLAGS
%EvtSeekRelativeToFirst    = 1???
%EvtSeekRelativeToLast     = 2???
%EvtSeekRelativeToCurrent  = 3???
%EvtSeekRelativeToBookmark = 4???
%EvtSeekOriginMask         = 7???

%EvtSeekStrict             = &H10000???

DECLARE FUNCTION EvtQuery IMPORT "Wevtapi.dll" ALIAS "EvtQuery" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF Path AS WSTRINGZ _                             ' __in LPCWSTR Path
 , BYREF Query AS WSTRINGZ _                            ' __in LPCWSTR Query
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtNext IMPORT "Wevtapi.dll" ALIAS "EvtNext" ( _
   BYVAL ResultSet AS DWORD _                           ' __in EVT_HANDLE ResultSet
 , BYVAL EventsSize AS DWORD _                          ' __in DWORD EventsSize
 , BYVAL Events AS DWORD _                              ' __in PEVT_HANDLE Events
 , BYVAL Timeout AS DWORD _                             ' __in DWORD Timeout
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Returned AS DWORD _                            ' __out PDWORD Returned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtSeek IMPORT "Wevtapi.dll" ALIAS "EvtSeek" ( _
   BYVAL ResultSet AS DWORD _                           ' __in EVT_HANDLE ResultSet
 , BYVAL Position AS QUAD _                             ' __in LONGLONG Position
 , BYVAL Bookmark AS DWORD _                            ' __in EVT_HANDLE Bookmark
 , BYVAL Timeout AS DWORD _                             ' __in_reserved DWORD Timeout // currently must be 0
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Subscriptions
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_SUBSCRIBE_FLAGS
%EvtSubscribeToFutureEvents      = 1???
%EvtSubscribeStartAtOldestRecord = 2???
%EvtSubscribeStartAfterBookmark  = 3???
%EvtSubscribeOriginMask          = 3???

%EvtSubscribeTolerateQueryErrors = &H1000???

%EvtSubscribeStrict              = &H10000???

' enum _EVT_SUBSCRIBE_NOTIFY_ACTION
%EvtSubscribeActionError   = 0
%EvtSubscribeActionDeliver = 1

'typedef DWORD (WINAPI *EVT_SUBSCRIBE_CALLBACK)(
'    EVT_SUBSCRIBE_NOTIFY_ACTION Action,
'    PVOID UserContext,
'    EVT_HANDLE Event );

'FUNCTION EVT_SUBSCRIBE_CALLBACK ( _
'   BYVAL Action AS EVT_SUBSCRIBE_NOTIFY_ACTION _
' , BYVAL UserContext AS DWORD _
' , BYVAL dwEvent AS DWORD _
' ) AS DWORD

DECLARE FUNCTION EvtSubscribe IMPORT "Wevtapi.dll" ALIAS "EvtSubscribe" ( _
   BYVAL ResultSet AS DWORD _                           ' __in EVT_HANDLE ResultSet
 , BYVAL SignalEvent AS DWORD _                         ' __in HANDLE SignalEvent
 , BYREF ChannelPath AS WSTRINGZ _                      ' __in LPCWSTR ChannelPath
 , BYREF Query AS WSTRINGZ _                            ' __in LPCWSTR Query
 , BYVAL Bookmark AS DWORD _                            ' __in EVT_HANDLE Bookmark
 , BYVAL context AS DWORD _                             ' __in PVOID context
 , BYVAL Callback AS DWORD _                            ' __in EVT_SUBSCRIBE_CALLBACK Callback
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE


'////////////////////////////////////////////////////////////////////////////////
'//
'// Rendering
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_SYSTEM_PROPERTY_ID
%EvtSystemProviderName      = 0    ' // EvtVarTypeString
%EvtSystemProviderGuid      = 1    ' // EvtVarTypeGuid
%EvtSystemEventID           = 2    ' // EvtVarTypeUInt16
%EvtSystemQualifiers        = 3    ' // EvtVarTypeUInt16
%EvtSystemLevel             = 4    ' // EvtVarTypeUInt8
%EvtSystemTask              = 5    ' // EvtVarTypeUInt16
%EvtSystemOpcode            = 6    ' // EvtVarTypeUInt8
%EvtSystemKeywords          = 7    ' // EvtVarTypeHexInt64
%EvtSystemTimeCreated       = 8    ' // EvtVarTypeFileTime
%EvtSystemEventRecordId     = 9    ' // EvtVarTypeUInt64
%EvtSystemActivityID        = 10   ' // EvtVarTypeGuid
%EvtSystemRelatedActivityID = 11   ' // EvtVarTypeGuid
%EvtSystemProcessID         = 12   ' // EvtVarTypeUInt32
%EvtSystemThreadID          = 13   ' // EvtVarTypeUInt32
%EvtSystemChannel           = 14   ' // EvtVarTypeString
%EvtSystemComputer          = 15   ' // EvtVarTypeString
%EvtSystemUserID            = 16   ' // EvtVarTypeSid
%EvtSystemVersion           = 17   ' // EvtVarTypeUInt8
%EvtSystemPropertyIdEND     = 18

' enum EVT_RENDER_CONTEXT_FLAGS
%EvtRenderContextValues = 0   ' // Render specific properties
%EvtRenderContextSystem = 1   ' // Render all system properties (System)
%EvtRenderContextUser   = 2   ' // Render all user properties (User/EventData)

' enum EVT_RENDER_FLAGS
%EvtRenderEventValues = 0   ' // Variants
%EvtRenderEventXml    = 1   ' // XML
%EvtRenderBookmark    = 2   ' // Bookmark

DECLARE FUNCTION EvtCreateRenderContext IMPORT "Wevtapi.dll" ALIAS "EvtCreateRenderContext" ( _
   BYVAL ValuePathsCount AS DWORD _                     ' __in DWORD ValuePathsCount
 , BYREF ValuePaths AS WSTRINGZ _                       ' __in LPCWSTR* ValuePaths
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags // EVT_RENDER_CONTEXT_FLAGS
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtRender IMPORT "Wevtapi.dll" ALIAS "EvtRender" ( _
   BYVAL Context AS DWORD _                             ' __in EVT_HANDLE Context
 , BYVAL Fragment AS DWORD _                            ' __in EVT_HANDLE Fragment
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags   // EVT_RENDER_FLAGS
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 , BYREF Buffer AS ANY _                                ' __in PVOID Buffer
 , BYREF BufferUsed AS DWORD _                          ' __out PDWORD BufferUsed
 , BYREF PropertyCount AS DWORD _                       ' __out PDWORD PropertyCount
 ) AS LONG                                              ' BOOL

' enum EVT_FORMAT_MESSAGE_FLAGS
%EvtFormatMessageEvent    = 1
%EvtFormatMessageLevel    = 2
%EvtFormatMessageTask     = 3
%EvtFormatMessageOpcode   = 4
%EvtFormatMessageKeyword  = 5
%EvtFormatMessageChannel  = 6
%EvtFormatMessageProvider = 7
%EvtFormatMessageId       = 8
%EvtFormatMessageXml      = 9

DECLARE FUNCTION EvtFormatMessage IMPORT "Wevtapi.dll" ALIAS "EvtFormatMessage" ( _
   BYVAL PublisherMetadata AS DWORD _                   ' __in EVT_HANDLE PublisherMetadata // Except for forwarded events
 , BYVAL Event AS DWORD _                               ' __in EVT_HANDLE Event
 , BYVAL MessageId AS DWORD _                           ' __in DWORD MessageId
 , BYVAL ValueCount AS DWORD _                          ' __in DWORD ValueCount
 , BYREF Values AS EVT_VARIANT _                        ' __in PEVT_VARIANT Values
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 , BYREF Buffer AS WSTRINGZ _                           ' __in LPWSTR Buffer
 , BYREF BufferUsed AS DWORD _                          ' __out PDWORD BufferUsed
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Log Maintenace and Information
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_OPEN_LOG_FLAGS
%EvtOpenChannelPath          = &H1???
%EvtOpenFilePath             = &H2???

' enum EVT_LOG_PROPERTY_ID
%EvtLogCreationTime       = 0   ' // EvtVarTypeFileTime
%EvtLogLastAccessTime     = 1   ' // EvtVarTypeFileTime
%EvtLogLastWriteTime      = 2   ' // EvtVarTypeFileTime
%EvtLogFileSize           = 3   ' // EvtVarTypeUInt64
%EvtLogAttributes         = 4   ' // EvtVarTypeUInt32
%EvtLogNumberOfLogRecords = 5   ' // EvtVarTypeUInt64
%EvtLogOldestRecordNumber = 6   ' // EvtVarTypeUInt64
%EvtLogFull               = 7   ' // EvtVarTypeBoolean

DECLARE FUNCTION EvtOpenLog IMPORT "Wevtapi.dll" ALIAS "EvtOpenLog" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF Path AS WSTRINGZ _                             ' __in LPCWSTR Path
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtGetLogInfo IMPORT "Wevtapi.dll" ALIAS "EvtGetLogInfo" ( _
   BYVAL Log AS DWORD _                                 ' __in EVT_HANDLE Log
 , BYVAL PropertyId AS LONG _                           ' __in EVT_LOG_PROPERTY_ID PropertyId
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EVT_VARIANT _           ' __in PEVT_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtClearLog IMPORT "Wevtapi.dll" ALIAS "EvtClearLog" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF ChannelPath AS WSTRINGZ _                      ' __in LPCWSTR ChannelPath
 , BYREF TargetFilePath AS WSTRINGZ _                   ' __in LPCWSTR TargetFilePath
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

' enum EVT_EXPORTLOG_FLAGS
%EvtExportLogChannelPath         = &H1???
%EvtExportLogFilePath            = &H2???
%EvtExportLogTolerateQueryErrors = &H1000???
%EvtExportLogOverwrite           = &H2000???

DECLARE FUNCTION EvtExportLog IMPORT "Wevtapi.dll" ALIAS "EvtExportLog" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF Path AS WSTRINGZ _                             ' __in LPCWSTR Path
 , BYREF Query AS WSTRINGZ _                            ' __in LPCWSTR Query
 , BYREF TargetFilePath AS WSTRINGZ _                   ' __in LPCWSTR TargetFilePath
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtArchiveExportedLog IMPORT "Wevtapi.dll" ALIAS "EvtArchiveExportedLog" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF LogFilePath AS WSTRINGZ _                      ' __in LPCWSTR LogFilePath
 , BYVAL Locale AS DWORD _                              ' __in LCID Locale
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Channel Configuration
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_CHANNEL_CONFIG_PROPERTY_ID
%EvtChannelConfigEnabled               = 0    ' // EvtVarTypeBoolean
%EvtChannelConfigIsolation             = 1    ' // EvtVarTypeUInt32, EVT_CHANNEL_ISOLATION_TYPE
%EvtChannelConfigType                  = 2    ' // EvtVarTypeUInt32, EVT_CHANNEL_TYPE
%EvtChannelConfigOwningPublisher       = 3    ' // EvtVarTypeString
%EvtChannelConfigClassicEventlog       = 4    ' // EvtVarTypeBoolean
%EvtChannelConfigAccess                = 5    ' // EvtVarTypeString
%EvtChannelLoggingConfigRetention      = 6    ' // EvtVarTypeBoolean
%EvtChannelLoggingConfigAutoBackup     = 7    ' // EvtVarTypeBoolean
%EvtChannelLoggingConfigMaxSize        = 8    ' // EvtVarTypeUInt64
%EvtChannelLoggingConfigLogFilePath    = 9    ' // EvtVarTypeString
%EvtChannelPublishingConfigLevel       = 10   ' // EvtVarTypeUInt32
%EvtChannelPublishingConfigKeywords    = 11   ' // EvtVarTypeUInt64
%EvtChannelPublishingConfigControlGuid = 12   ' // EvtVarTypeGuid
%EvtChannelPublishingConfigBufferSize  = 13   ' // EvtVarTypeUInt32
%EvtChannelPublishingConfigMinBuffers  = 14   ' // EvtVarTypeUInt32
%EvtChannelPublishingConfigMaxBuffers  = 15   ' // EvtVarTypeUInt32
%EvtChannelPublishingConfigLatency     = 16   ' // EvtVarTypeUInt32
%EvtChannelPublishingConfigClockType   = 17   ' // EvtVarTypeUInt32, EVT_CHANNEL_CLOCK_TYPE
%EvtChannelPublishingConfigSidType     = 18   ' // EvtVarTypeUInt32, EVT_CHANNEL_SID_TYPE
%EvtChannelPublisherList               = 19   ' // EvtVarTypeString | EVT_VARIANT_TYPE_ARRAY
%EvtChannelConfigPropertyIdEND         = 20

' enum EVT_CHANNEL_TYPE
%EvtChannelTypeAdmin       = 0
%EvtChannelTypeOperational = 1
%EvtChannelTypeAnalytic    = 2
%EvtChannelTypeDebug       = 3

' enum EVT_CHANNEL_ISOLATION_TYPE
%EvtChannelIsolationTypeApplication = 0
%EvtChannelIsolationTypeSystem      = 1
%EvtChannelIsolationTypeCustom      = 2

' enum EVT_CHANNEL_CLOCK_TYPE
%EvtChannelClockTypeSystemTime = 0   ' // System time
%EvtChannelClockTypeQPC        = 1   ' // Query performance counter

' enum EVT_CHANNEL_SID_TYPE
%EvtChannelSidTypeNone       = 0
%EvtChannelSidTypePublishing = 1

DECLARE FUNCTION EvtOpenChannelEnum IMPORT "Wevtapi.dll" ALIAS "EvtOpenChannelEnum" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtNextChannelPath IMPORT "Wevtapi.dll" ALIAS "EvtNextChannelPath" ( _
   BYVAL ChannelEnum AS DWORD _                         ' __in EVT_HANDLE ChannelEnum
 , BYVAL ChannelPathBufferSize AS DWORD _               ' __in DWORD ChannelPathBufferSize
 , BYREF ChannelPathBuffer AS WSTRINGZ _                ' __in LPWSTR ChannelPathBuffer
 , BYREF ChannelPathBufferUsed AS DWORD _               ' __out PDWORD ChannelPathBufferUsed
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtOpenChannelConfig IMPORT "Wevtapi.dll" ALIAS "EvtOpenChannelConfig" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYREF ChannelPath AS WSTRINGZ _                      ' __in LPCWSTR ChannelPath
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtSaveChannelConfig IMPORT "Wevtapi.dll" ALIAS "EvtSaveChannelConfig" ( _
   BYVAL ChannelConfig AS DWORD _                       ' __in EVT_HANDLE ChannelConfig
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtSetChannelConfigProperty IMPORT "Wevtapi.dll" ALIAS "EvtSaveChannelConfig" ( _
   BYVAL ChannelConfig AS DWORD _                       ' __in EVT_HANDLE ChannelConfig
 , BYVAL PropertyId AS LONG _                           ' __in EVT_CHANNEL_CONFIG_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PropertyValue AS EVT_VARIANT _                 ' __in PEVT_VARIANT PropertyValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtGetChannelConfigProperty IMPORT "Wevtapi.dll" ALIAS "EvtGetChannelConfigProperty" ( _
   BYVAL ChannelConfig AS DWORD _                       ' __in EVT_HANDLE ChannelConfig
 , BYVAL PropertyId AS LONG _                           ' __in EVT_CHANNEL_CONFIG_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EVT_VARIANT _           ' __in PEVT_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Publisher Metadata
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_CHANNEL_REFERENCE_FLAGS
%EvtChannelReferenceImported = &H1???

' enum EVT_PUBLISHER_METADATA_PROPERTY_ID
%EvtPublisherMetadataPublisherGuid             = 0    ' // EvtVarTypeGuid
%EvtPublisherMetadataResourceFilePath          = 1    ' // EvtVarTypeString
%EvtPublisherMetadataParameterFilePath         = 2    ' // EvtVarTypeString
%EvtPublisherMetadataMessageFilePath           = 3    ' // EvtVarTypeString
%EvtPublisherMetadataHelpLink                  = 4    ' // EvtVarTypeString
%EvtPublisherMetadataPublisherMessageID        = 5    ' // EvtVarTypeUInt32

%EvtPublisherMetadataChannelReferences         = 6    ' // EvtVarTypeEvtHandle, ObjectArray
%EvtPublisherMetadataChannelReferencePath      = 7    ' // EvtVarTypeString
%EvtPublisherMetadataChannelReferenceIndex     = 8    ' // EvtVarTypeUInt32
%EvtPublisherMetadataChannelReferenceID        = 9    ' // EvtVarTypeUInt32
%EvtPublisherMetadataChannelReferenceFlags     = 10   ' // EvtVarTypeUInt32
%EvtPublisherMetadataChannelReferenceMessageID = 11   ' // EvtVarTypeUInt32

%EvtPublisherMetadataLevels                    = 12   ' // EvtVarTypeEvtHandle, ObjectArray
%EvtPublisherMetadataLevelName                 = 13   ' // EvtVarTypeString
%EvtPublisherMetadataLevelValue                = 14   ' // EvtVarTypeUInt32
%EvtPublisherMetadataLevelMessageID            = 15   ' // EvtVarTypeUInt32

%EvtPublisherMetadataTasks                     = 16   ' // EvtVarTypeEvtHandle, ObjectArray
%EvtPublisherMetadataTaskName                  = 17   ' // EvtVarTypeString
%EvtPublisherMetadataTaskEventGuid             = 18   ' // EvtVarTypeGuid
%EvtPublisherMetadataTaskValue                 = 19   ' // EvtVarTypeUInt32
%EvtPublisherMetadataTaskMessageID             = 20   ' // EvtVarTypeUInt32

%EvtPublisherMetadataOpcodes                   = 21   ' // EvtVarTypeEvtHandle, ObjectArray
%EvtPublisherMetadataOpcodeName                = 22   ' // EvtVarTypeString
%EvtPublisherMetadataOpcodeValue               = 23   ' // EvtVarTypeUInt32
%EvtPublisherMetadataOpcodeMessageID           = 24   ' // EvtVarTypeUInt32

%EvtPublisherMetadataKeywords                  = 25   ' // EvtVarTypeEvtHandle, ObjectArray
%EvtPublisherMetadataKeywordName               = 26   ' // EvtVarTypeString
%EvtPublisherMetadataKeywordValue              = 27   ' // EvtVarTypeUInt64
%EvtPublisherMetadataKeywordMessageID          = 28   ' // EvtVarTypeUInt32

%EvtPublisherMetadataPropertyIdEND             = 29


DECLARE FUNCTION EvtOpenPublisherEnum IMPORT "Wevtapi.dll" ALIAS "EvtOpenPublisherEnum" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtNextPublisherId IMPORT "Wevtapi.dll" ALIAS "EvtNextPublisherId" ( _
   BYVAL PublisherEnum AS DWORD _                       ' __in EVT_HANDLE PublisherEnum
 , BYVAL PublisherIdBufferSize AS DWORD _               ' __in DWORD PublisherIdBufferSize
 , BYREF PublisherIdBuffer AS WSTRINGZ _                ' __in LPWSTR PublisherIdBuffer
 , BYREF PublisherIdBufferUsed AS DWORD _               ' __out PDWORD PublisherIdBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtOpenPublisherMetadata IMPORT "Wevtapi.dll" ALIAS "EvtOpenPublisherMetadata" ( _
   BYVAL Session AS DWORD _                             ' __in EVT_HANDLE Session
 , BYVAL PublisherId AS DWORD _                         ' __in DWORD PublisherId
 , BYREF LogFilePath AS WSTRINGZ _                      ' __in LPWSTR LogFilePath
 , BYVAL Locale AS DWORD _                              ' __in LCID Locale
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtGetPublisherMetadataProperty IMPORT "Wevtapi.dll" ALIAS "EvtGetPublisherMetadataProperty" ( _
   BYVAL PublisherMetadata AS DWORD _                   ' __in EVT_HANDLE PublisherMetadata
 , BYVAL PropertyId AS LONG _                           ' __in EVT_PUBLISHER_METADATA_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL PublisherMetadataPropertyBufferSize AS DWORD _ ' __in DWORD PublisherMetadataPropertyBufferSize
 , BYREF PublisherMetadataPropertyBuffer AS EVT_VARIANT _ ' __in PEVT_VARIANT PublisherMetadataPropertyBuffer
 , BYREF PublisherMetadataPropertyBufferUsed AS DWORD _ ' __out PDWORD PublisherMetadataPropertyBufferUsed
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Event Metadata Configuratin
'//
'////////////////////////////////////////////////////////////////////////////////

' enum EVT_EVENT_METADATA_PROPERTY_ID
%EventMetadataEventID          = 0   ' // EvtVarTypeUInt32
%EventMetadataEventVersion     = 1   ' // EvtVarTypeUInt32
%EventMetadataEventChannel     = 2   ' // EvtVarTypeUInt32
%EventMetadataEventLevel       = 3   ' // EvtVarTypeUInt32
%EventMetadataEventOpcode      = 4   ' // EvtVarTypeUInt32
%EventMetadataEventTask        = 5   ' // EvtVarTypeUInt32
%EventMetadataEventKeyword     = 6   ' // EvtVarTypeUInt64
%EventMetadataEventMessageID   = 7   ' // EvtVarTypeUInt32
%EventMetadataEventTemplate    = 8   ' // EvtVarTypeString
%EvtEventMetadataPropertyIdEND = 9

DECLARE FUNCTION EvtOpenEventMetadataEnum IMPORT "Wevtapi.dll" ALIAS "EvtOpenEventMetadataEnum" ( _
   BYVAL PublisherMetadata AS DWORD _                   ' __in EVT_HANDLE PublisherMetadata
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtNextEventMetadata IMPORT "Wevtapi.dll" ALIAS "EvtNextEventMetadata" ( _
   BYVAL EventMetadataEnum AS DWORD _                   ' __in EVT_HANDLE EventMetadataEnum
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtGetEventMetadataProperty IMPORT "Wevtapi.dll" ALIAS "EvtGetEventMetadataProperty" ( _
   BYVAL EventMetadata AS DWORD _                       ' __in EVT_HANDLE EventMetadata
 , BYVAL PropertyId AS LONG _                           ' __in EVT_EVENT_METADATA_PROPERTY_ID PropertyId
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL EventMetadataPropertyBufferSize AS DWORD _     ' __in DWORD EventMetadataPropertyBufferSize
 , BYREF EventMetadataPropertyBuffer AS EVT_VARIANT _   ' __in PEVT_VARIANT EventMetadataPropertyBuffer
 , BYREF EventMetadataPropertyBufferUsed AS DWORD _     ' __out PDWORD EventMetadataPropertyBufferUsed
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Array Access
'//
'////////////////////////////////////////////////////////////////////////////////

'typedef HANDLE EVT_OBJECT_ARRAY_PROPERTY_HANDLE;

DECLARE FUNCTION EvtGetObjectArraySize IMPORT "Wevtapi.dll" ALIAS "EvtGetObjectArraySize" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EVT_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYREF ObjectArraySize AS DWORD _                     ' __out PDWORD ObjectArraySize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtGetObjectArrayProperty IMPORT "Wevtapi.dll" ALIAS "EvtGetObjectArrayProperty" ( _
   BYVAL ObjectArray AS DWORD _                         ' __in EVT_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray
 , BYVAL PropertyId AS DWORD _                          ' __in DWORD PropertyId
 , BYVAL ArrayIndex AS DWORD _                          ' __in DWORD ArrayIndex
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EVT_VARIANT _           ' __in EVT_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL


'/////////////////////////////////////////////////////////////////////////////
'//
'// Misc Event Consumer Functions
'//
'////////////////////////////////////////////////////////////////////////////

' enum EVT_QUERY_PROPERTY_ID

'//
'// list of channels or logfiles indentified in the query. Variant will be
'// array of EvtVarTypeString.
'//
%EvtQueryNames = 0

'//
'// Array of EvtVarTypeUInt32, indicating creation status ( Win32 error
'// code ) for the list of names returned by the EvtQueryNames
'// property.
'//
%EvtQueryStatuses = 1

%EvtQueryPropertyIdEND = 2


' enum EVT_EVENT_PROPERTY_ID
%EvtEventQueryIDs      = 0
%EvtEventPath          = 1
%EvtEventPropertyIdEND = 2


DECLARE FUNCTION EvtGetQueryInfo IMPORT "Wevtapi.dll" ALIAS "EvtGetQueryInfo" ( _
   BYVAL QueryOrSubscription AS DWORD _                 ' __in EVT_HANDLE QueryOrSubscription
 , BYVAL PropertyId AS LONG _                           ' __in EVT_QUERY_PROPERTY_ID PropertyId
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EVT_VARIANT _           ' __in PEVT_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtCreateBookmark IMPORT "Wevtapi.dll" ALIAS "EvtCreateBookmark" ( _
   OPTIONAL BYREF BookmarkXml AS WSTRINGZ _             ' __in_opt LPCWSTR BookmarkXml
 ) AS DWORD                                             ' EVT_HANDLE

DECLARE FUNCTION EvtUpdateBookmark IMPORT "Wevtapi.dll" ALIAS "EvtUpdateBookmark" ( _
   BYVAL Bookmark AS DWORD _                            ' __in EVT_HANDLE Bookmark
 , BYVAL Event AS DWORD _                               ' __in EVT_HANDLE Event
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EvtGetEventInfo IMPORT "Wevtapi.dll" ALIAS "EvtGetEventInfo" ( _
   BYVAL Event AS DWORD _                               ' __in EVT_HANDLE Event
 , BYVAL PropertyId AS LONG _                           ' __in EVT_EVENT_PROPERTY_ID PropertyId
 , BYVAL PropertyValueBufferSize AS DWORD _             ' __in DWORD PropertyValueBufferSize
 , BYREF PropertyValueBuffer AS EVT_VARIANT _           ' __in PEVT_VARIANT PropertyValueBuffer
 , BYREF PropertyValueBufferUsed AS DWORD _             ' __out PDWORD PropertyValueBufferUsed
 ) AS LONG                                              ' BOOL

'////////////////////////////////////////////////////////////////////////////////
'//
'// Access Control Permissions
'//
'////////////////////////////////////////////////////////////////////////////////

%EVT_READ_ACCESS  = &H1
%EVT_WRITE_ACCESS = &H2
%EVT_CLEAR_ACCESS = &H4
%EVT_ALL_ACCESS   = &H7

'#endif // WINVER >= _WIN32_WINNT_LONGHORN
