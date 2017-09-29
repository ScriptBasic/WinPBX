' ########################################################################################
' Microsoft Windows
' File: aqadmtyp.inc
' Contents: Data types used in advanced queueing interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AQADMTYP_INC = 1

#INCLUDE ONCE "windows.inc"

'// max *required* size of buffer returned by implementor of QAPI
'// If the size of the requested information exceeds this constant,
'// then QAPI *may* truncate the buffer.
%QUEUE_ADMIN_MAX_BUFFER_REQUIRED = 200

'// @enum QUEUE_ADMIN_VERSIONS | Enum specify current and supported
'//  queue admin versions.
'// @emem CURRENT_QUEUE_ADMIN_VERSION | The current queue admin version
'//  that all structures should have this value in their dwVersion field.

' enum QUEUE_ADMIN_VERSIONS
%CURRENT_QUEUE_ADMIN_VERSION = 4

'//
'// @struct MESSAGE_FILTER | Structure describing criteria for selecting
'// messages
'// @field DWORD | dwVersion | Version of MESSAGE_FILTER struct - must be CURRENT_QUEUE_ADMIN_VERSION
'// @field DWORD | fFlags | <t MESSAGE_FILTER_FLAGS> indicating which
'//  fields of filter are specified
'// @field LPCWSTR | szMessageId | Message ID, as returned in a MESSAGE_INFO
'// struct
'// @field LPCWSTR | szMessageSender | Messages sent by this sender match
'// @field LPCWSTR | szMessageRecipient | Messages sent to this recipient match
'// @field DWORD | dwLargerThanSize | Messages larger than this value match
'// @field SYSTEMTIME | stOlderThan | Messages older than this value match
'//

' // Size = 40 bytes
TYPE MESSAGE_FILTER DWORD
   dwVersion          AS DWORD          ' DWORD
   fFlags             AS DWORD          ' DWORD
   szMessageId        AS WSTRINGZ PTR   ' LPCWSTR
   szMessageSender    AS WSTRINGZ PTR   ' LPCWSTR
   szMessageRecipient AS WSTRINGZ PTR   ' LPCWSTR
   dwLargerThanSize   AS DWORD          ' DWORD
   stOlderThan        AS SYSTEMTIME
END TYPE

'// @enum MESSAGE_FILTER_FLAGS | Type specifying the type of filter
'// requested.  These are bitflags and can be OR'd together.
'// @emem MF_MESSAGEID | The <e MESSAGE_FILTER.szMessageId> is specified
'// @emem MF_SENDER | The <e MESSAGE_FILTER.szMessageSender> is specified
'// @emem MF_RECIPIENT | The <e MESSAGE_FILTER.szMessageRecipient> is specified
'// @emem MF_SIZE | The <e MESSAGE_FILTER.dwLargerThanSize> is specified
'// @emem MF_TIME | The <e MESSAGE_FILTER.stOlderThan> is specified
'// @emem MF_FROZEN | The <e MESSAGE_FILTER.fFrozen> is specified
'// @emem MF_FAILED | Selects messages that have had a failed delivery attempt
'// @emem MF_INVERTSENSE | If set, indicates that the negation of the filter
'// @emem MF_ALL | Select all messages

' enum MESSAGE_FILTER_FLAGS
MACRO MESSAGE_FILTER_FLAGS_ENUM = DWORD
%MF_MESSAGEID                = &H00000001???
%MF_SENDER                   = &H00000002???
%MF_RECIPIENT                = &H00000004???
%MF_SIZE                     = &H00000008???
%MF_TIME                     = &H00000010???
%MF_FROZEN                   = &H00000020???
%MF_FAILED                   = &H00000100???
%MF_ALL                      = &H40000000???
%MF_INVERTSENSE              = &H80000000???

'// @enum MESSAGE_ACTION | Type specifying possible administrative actions
'//      that may be applied to messages in a virtual server, link, or queue
'// @emem MA_DELETE | Remove message from the virtual server, link, or queue
'// @emem MA_DELETE_SILENT | Remove message without generating an NDR
'// @emem MA_FREEZE | Freeze the message in the virtual server, link, or queue
'// @emem MA_THAW | Un-freeze the message in the virtual server, link, or queue
'// @emem MA_COUNT | Null operation, does not affect messages, but does return count.

' enum MESSAGE_ACTION
MACRO MESSAGE_ACTION_ENUM = DWORD
%MA_THAW_GLOBAL              = &H00000001???
%MA_COUNT                    = &H00000002???
%MA_FREEZE_GLOBAL            = &H00000004???
%MA_DELETE                   = &H00000008???
%MA_DELETE_SILENT            = &H00000010???

'// @enum MESSAGE_ENUM_FILTER_TYPE | Type specifying the type of filter
'// requested.  These are bitflags and can be OR'd together.
'// @emem MEF_FIRST_N_MESSAGES | Return the first
'// <e MESSAGE_ENUM_FILTER.cMessages> messages
'// @emem MEF_N_LARGEST_MESSAGES | Return the largest
'// <e MESSAGE_ENUM_FILTER.cMessages> messages
'// @emem MEF_N_OLDEST_MESSAGES | Return the oldest
'// <e MESSAGE_ENUM_FILTER.cMessages> messages
'// @emem MF_SENDER | The <e MESSAGE_ENUM_FILTER.szMessageSender> is specified
'// @emem MF_RECIPIENT | The <e MESSAGE_ENUM_FILTER.szMessageRecipient> is specified
'// @emem MEF_OLDER_THAN | Return messages older than
'// <e MESSAGE_ENUM_FILTER.stDate>
'// @emem MEF_LARGER_THAN | Return messages larger than
'// <e MESSAGE_ENUM_FILTER.cbSize> bytes
'// @emem MEF_FROZEN | Return messages that are frozen
'// @emem MEF_INVERTSENSE  | Invert the meaning of the filter
'// @emem MEF_ALL | Select all messages
'// @emem MEF_FAILED | Return only messages that have had failed delivery
'// attempts.

' enum tagMESSAGE_ENUM_FILTER_TYPE
MACRO MESSAGE_ENUM_FILTER_TYPE_ENUM = DWORD
%MEF_FIRST_N_MESSAGES        = &H00000001???
%MEF_SENDER                  = &H00000002???
%MEF_RECIPIENT               = &H00000004???
%MEF_LARGER_THAN             = &H00000008???
%MEF_OLDER_THAN              = &H00000010???
%MEF_FROZEN                  = &H00000020???
%MEF_N_LARGEST_MESSAGES      = &H00000040???
%MEF_N_OLDEST_MESSAGES       = &H00000080???
%MEF_FAILED                  = &H00000100???
%MEF_ALL                     = &H40000000???
%MEF_INVERTSENSE             = &H80000000???

'// @struct MESSAGE_ENUM_FILTER | Structure describing criteria for enumerating
'// messages
'// @field DWORD | dwVersion | Version of filter - must be CURRENT_QUEUE_ADMIN_VERSION
'// @field MESSAGE_ENUM_FILTER_TYPE | mefType | <t MESSAGE_ENUM_FILTER_TYPE> Flags for filter.
'// @field DWORD | cMessages | Number of messages to return
'// @field DWORD | cbSize | Size parameter of messages
'// @field DWORD | cSkipMessages | Number of messages at front of queue to skip.
'//  This is provided to allow "paged" queries to the server.
'// @field SYSTEMTIME | stDate | Date/Time parameter of messages

' // Size = 44 bytes
TYPE MESSAGE_ENUM_FILTER DWORD
   dwVersion          AS DWORD           ' DWORD
   mefType            AS DWORD           ' DWORD
   cMessages          AS DWORD           ' DWORD
   cbSize             AS DWORD           ' DWORD
   cSkipMessages      AS DWORD           ' DWORD
   stDate             AS SYSTEMTIME      ' SYSTEMTIME
   szMessageSender    AS WSTRINGZ PTR    ' LPCWSTR
   szMessageRecipient AS WSTRINGZ PTR    ' LPCWSTR
END TYPE

'// @enum LINK_INFO_FLAGS | Type specifying the state of the link
'// @emem LI_ACTIVE | Link has an active connection transferring mail
'// @emem LI_READY | Link is ready for a connection, but there are no connections
'// @emem LI_RETRY | Link is waiting for the retry interval to elapse
'// @emem LI_SCHEDULED | Link is waiting for the next scheduled time
'// @emem LI_REMOTE | Link is to be activated by remote server. A connection
'//  will not be made unless requested by a remote server.
'// @emem LI_FROZEN | Link was frozen by administrative action
'// @emem LI_TYPE_REMOTE_DELIVERY | Messages on link are being delivered
'//  remotely.  This is the default type of link.
'// @emem LI_TYPE_LOCAL_DELIVERY | Messages on this link are being delivered
'//  locally.
'// @emem LI_TYPE_PENDING_CAT | Messages on this link are pending message
'//  categorization.
'// @emem LI_TYPE_PENDING_ROUTING | Messages on this link have not been routed
'//  to their next hop.
'// @emem LI_TYPE_CURRENTLY_UNREACHABLE | Messages on this link do not have an
'//  available route to their final destination.  This is due to transient
'//  network or server errors.  These messages will be retried when a route
'//  becomes available.
'// @emem LI_TYPE_INTERNAL | This link is an internal link not described
'//  by the above.

' enum LINK_INFO_FLAGS
MACRO LINK_INFO_FLAGS_ENUM = DWORD
%LI_ACTIVE                       = &H00000001???
%LI_READY                        = &H00000002???
%LI_RETRY                        = &H00000004???
%LI_SCHEDULED                    = &H00000008???
%LI_REMOTE                       = &H00000010???
%LI_FROZEN                       = &H00000020???
%LI_TYPE_REMOTE_DELIVERY         = &H00000100???
%LI_TYPE_LOCAL_DELIVERY          = &H00000200???
%LI_TYPE_PENDING_ROUTING         = &H00000400???
%LI_TYPE_PENDING_CAT             = &H00000800???
%LI_TYPE_CURRENTLY_UNREACHABLE   = &H00001000???
%LI_TYPE_DEFERRED_DELIVERY       = &H00002000???
%LI_TYPE_INTERNAL                = &H00004000???
%LI_TYPE_PENDING_SUBMIT          = &H00008000???

'// @enum LINK_ACTION | Actions that can be applied to a link
'// @emem LA_KICK | Force a connection to be made for this link.
'//  This will even work for connections pending retry or a scheduled connection.
'// @emem LA_FREEZE | Prevent outbound connections from being made for a link
'// @emem LA_THAW | Undo a previous admin freeze action.

' enum LINK_ACTION
MACRO LINK_ACTION_ENUM = DWORD
%LA_INTERNAL                 = &H00000000???
%LA_KICK                     = &H00000001???
%LA_FREEZE                   = &H00000020???
%LA_THAW                     = &H00000040???

'//
'// @struct LINK_INFO | Structure describing state of a virtual server AQ link
'// @field DWORD | dwVersion | Version of LINK_INFO structure - will be CURRENT_QUEUE_ADMIN_VERSION
'// @field LPWSTR | szLinkName | Name of next-hop
'// @field DWORD | cMessages | Number of messages queued up for this link
'// @field DWORD | fStateFlags | <t LINK_INFO_FLAGS> indicating Link State
'// @field SYSTEMTIME | stNextScheduledConnection | The time at which the next
'// connection will be attempted.
'// @field SYSTEMTIME | stOldestMessage | The oldest message on this link
'// @field ULARGE_INTEGER | cbLinkVolume | Total number of bytes on link
'// @field LPWSTR | szLinkDN | DN associated with this link by routing.  Can be NULL.
'// @field LPWSTR | szExtendedStateInfo | If present, this provides additional state
'// information about why a link is in <t LI_RETRY> state.
'// @field DWORD | dwSupportedLinkActions | Tells which <t LINK_ACTIONS> are supported
'// by this link.

' // Size = 72 bytes
TYPE LINK_INFO   ' Must be 8 bytes aligned
   dwVersion                 AS DWORD            ' DWORD
   szLinkName                AS WSTRINGZ PTR     ' LPWSTR
   cMessages                 AS DWORD            ' DWORD
   fStateFlags               AS DWORD            ' DWORD
   stNextScheduledConnection AS SYSTEMTIME       ' SYSTEMTIME
   stOldestMessage           AS SYSTEMTIME       ' SYSTEMTIME
   cbLinkVolume              AS QUAD             ' ULARGE_INTEGER
   szLinkDN                  AS WSTRINGZ PTR     ' LPWSTR
   szExtendedStateInfo       AS WSTRINGZ PTR     ' LPWSTR
   dwSupportedLinkActions    AS DWORD            ' DWORD
   filler_                   AS DWORD            ' // To keep 8 bytes alignment
END TYPE

'//
'// @struct QUEUE_INFO | Structure describing state of a virtual server link
'// queue
'// @field DWORD | dwVersion | Version of LINK_INFO structure - will be CURRENT_QUEUE_ADMIN_VERSION
'// @field LPWSTR | szQueueName | Name of queue
'// @field LPWSTR | szLinkName | Name of link that is servicing this queue
'// @field DWORD | cMessages | Number of messages on this queue
'// @field ULARGE_INTEGER | cbQueueVolume | Total number of bytes on queue
'// @field DWORD | dwMsgEnumFlagsSupported | The types of message enumeration supported

' // Size = 32 bytes
TYPE QUEUE_INFO  ' Must be 8 bytes aligned
   dwVersion               AS DWORD          ' DWORD
   szQueueName             AS WSTRINGZ PTR   ' LPWSTR
   szLinkName              AS WSTRINGZ PTR   ' LPWSTR
   cMessages               AS DWORD          ' DWORD
   cbQueueVolume           AS QUAD           ' ULARGE_INTEGER
   dwMsgEnumFlagsSupported AS DWORD          ' DWORD
   filler_                 AS DWORD          ' // To keep 8 bytes alignment
END TYPE

'//
'// @enum AQ_MESSAGE_FLAGS | Flags describing message properties
'// @flag MP_HIGH | High Priority Message
'// @flag MP_NORMAL | Normal Priority Message
'// @flag MP_LOW | Low Priority Message
'// @flag MP_MSG_FROZEN | Message has been frozen by admin.
'// @flag MP_MSG_RETRY | Delivery has been attempted and failed at least once
'//  for this message.
'// @flag MP_MSG_CONTENT_AVAILABLE | The content for this message can be
'//  accessed through the QAPI.

' enum AQ_MESSAGE_FLAGS
MACRO AQ_MESSAGE_FLAGS_ENUM = DWORD
%MP_HIGH                     = &H00000001???
%MP_NORMAL                   = &H00000002???
%MP_LOW                      = &H00000004???
%MP_MSG_FROZEN               = &H00000008???
%MP_MSG_RETRY                = &H00000010???
%MP_MSG_CONTENT_AVAILABLE    = &H00000020???

'// @struct MESSAGE_INFO | Structure describing a single mail message
'// @field DWORD | dwVersion | Version of LINK_INFO structure - will be CURRENT_QUEUE_ADMIN_VERSION
'// @field LPWSTR | szMessageId | Message ID
'// @field LPWSTR | szSender | Sender Address, from "From:" header
'// @field LPWSTR | szSubject | Message Subject
'// @field DWORD | cRecipients | Number of recipients
'// @field LPWSTR | szRecipients | Recipient Addresses, from "To:" header
'// @field DWORD | cCCRecipients | Number of CC recipients
'// @field LPWSTR | szCCRecipients | CC Recipient Addresses, from "CC:" header
'// @field DWORD | cBCCRecipients | Number of BCC recipients
'// @field LPWSTR | szBCCRecipients | BCC Recipient Addresses, from "BCC:" header
'// @field DWORD | cbMessageSize | size of message in bytes
'// @field DWORD | fMsgFlags | <t AQ_MESSAGE_FLAGS> describing message properties.
'// @field SYSTEMTIME | stSubmission | Time of message submission
'// @field SYSTEMTIME | stReceived | Time message was received by this server
'// @field SYSTEMTIME | stExpiry | Time message will expire by if not delivered
'// to all recipients, thus generating an NDR
'// @field DWORD | cFailures | The number of failured delivery attempts for
'// this message
'// @field DWORD | cEnvRecipients | The number of envelope recipeints
'// @field DWORD | cbEnvRecipients | The size in bytes of the envelope recipients
'// @field WCHAR * | mszEnvRecipients | A multi-string UNICODE buffer containing
'// a NULL-terminated string for each recipient.  The buffer itself is terminated
'// by an additional NULL.  Each recipient string will be formatted in the proxy
'// address format of 'addr-type ":" address'.  The addr-type should match
'// the address type found in the DS (ie SMTP).  The address should be returned
'// in it's native format.

' // Size = 112 bytes
TYPE MESSAGE_INFO DWORD
   dwVersion        AS DWORD          ' DWORD
   szMessageId      AS WSTRINGZ PTR   ' LPWSTR
   szSender         AS WSTRINGZ PTR   ' LPWSTR
   szSubject        AS WSTRINGZ PTR   ' LPWSTR
   cRecipients      AS DWORD          ' DWORD
   szRecipients     AS WSTRINGZ PTR   ' LPWSTR
   cCCRecipients    AS DWORD          ' DWORD
   szCCRecipients   AS WSTRINGZ PTR   ' LPWSTR
   cBCCRecipients   AS DWORD          ' DWORD
   szBCCRecipients  AS WSTRINGZ PTR   ' LPWSTR
   fMsgFlags        AS DWORD          ' DWORD
   cbMessageSize    AS DWORD          ' DWORD
   stSubmission     AS SYSTEMTIME     ' SYSTEMTIME
   stReceived       AS SYSTEMTIME     ' SYSTEMTIME
   stExpiry         AS SYSTEMTIME     ' SYSTEMTIME
   cFailures        AS DWORD          ' DWORD
   cEnvRecipients   AS DWORD          ' DWORD
   cbEnvRecipients  AS DWORD          ' DWORD
   mszEnvRecipients AS WSTRINGZ PTR   ' WCHAR *
END TYPE

' enum QUEUELINK_TYPE
MACRO QUEUELINK_TYPE_ENUM = LONG
%QLT_QUEUE = 0
%QLT_LINK  = 1
%QLT_NONE  = 2

' // Size = 28 bytes
TYPE QUEUELINK_ID DWORD
   uuid    AS GUID                  ' GUID
   szName  AS WSTRINGZ PTR          ' LPWSTR
   dwId    AS DWORD                 ' DWORD
   qltType AS QUEUELINK_TYPE_ENUM   ' QUEUELINK_TYPE
END TYPE
