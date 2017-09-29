' ########################################################################################
' Microsoft Windows
' File: rtcerr.inc
' Contents: Error Messages for RTC Core API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RTCERR_INC = 1

' // Possible error codes from SIP interfaces
' //
' //  Values are 32 bit values layed out as follows:
' //
' //   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
' //   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
' //  +---+-+-+-----------------------+-------------------------------+
' //  |Sev|C|R|     Facility          |               Code            |
' //  +---+-+-+-----------------------+-------------------------------+
' //
' //  where
' //
' //      Sev - is the severity code
' //
' //          00 - Success
' //          01 - Informational
' //          10 - Warning
' //          11 - Error
' //
' //      C - is the Customer code flag
' //
' //      R - is a reserved bit
' //
' //      Facility - is the facility code
' //
' //      Code - is the facility's status code
' //
' //
' // Define the facility codes
' //

%FACILITY_SIP_STATUS_CODE         = &HEF
%FACILITY_RTC_INTERFACE           = &HEE
%FACILITY_PINT_STATUS_CODE        = &HF0


' //
' // Define the severity codes
' //
%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_RTC_ERROR        = &H2


' //
' // MessageId: RTC_E_SIP_CODECS_DO_NOT_MATCH
' //
' // MessageText:
' //
' //  No matching codecs with peer
' //
%RTC_E_SIP_CODECS_DO_NOT_MATCH    = &H80EE0000&

' //
' // MessageId: RTC_E_SIP_STREAM_PRESENT
' //
' // MessageText:
' //
' //  Parsing SIP failed
' //  The stream to be started is already present
' //
%RTC_E_SIP_STREAM_PRESENT         = &H80EE0001&

' //
' // MessageId: RTC_E_SIP_STREAM_NOT_PRESENT
' //
' // MessageText:
' //
' //  The stream to be stopped is not present
' //
%RTC_E_SIP_STREAM_NOT_PRESENT     = &H80EE0002&

' //
' // MessageId: RTC_E_SIP_NO_STREAM
' //
' // MessageText:
' //
' //  No stream is active
' //
%RTC_E_SIP_NO_STREAM              = &H80EE0003&

' //
' // MessageId: RTC_E_SIP_PARSE_FAILED
' //
' // MessageText:
' //
' //  Parsing SIP failed
' //
%RTC_E_SIP_PARSE_FAILED           = &H80EE0004&

' //
' // MessageId: RTC_E_SIP_HEADER_NOT_PRESENT
' //
' // MessageText:
' //
' //  The SIP header is not present in the message
' //
%RTC_E_SIP_HEADER_NOT_PRESENT     = &H80EE0005&

' //
' // MessageId: RTC_E_SDP_NOT_PRESENT
' //
' // MessageText:
' //
' //  SDP is not present in the SIP message
' //
%RTC_E_SDP_NOT_PRESENT            = &H80EE0006&

' //
' // MessageId: RTC_E_SDP_PARSE_FAILED
' //
' // MessageText:
' //
' //  Parsing SDP failed
' //
%RTC_E_SDP_PARSE_FAILED           = &H80EE0007&

' //
' // MessageId: RTC_E_SDP_UPDATE_FAILED
' //
' // MessageText:
' //
' //  SDP does not match the previous one
' //
%RTC_E_SDP_UPDATE_FAILED          = &H80EE0008&

' //
' // MessageId: RTC_E_SDP_MULTICAST
' //
' // MessageText:
' //
' //  Multicast is not supported
' //
%RTC_E_SDP_MULTICAST              = &H80EE0009&

' //
' // MessageId: RTC_E_SDP_CONNECTION_ADDR
' //
' // MessageText:
' //
' //  Media does not contain connection address
' //
%RTC_E_SDP_CONNECTION_ADDR        = &H80EE000A&

' //
' // MessageId: RTC_E_SDP_NO_MEDIA
' //
' // MessageText:
' //
' //  No media is available for the session
' //
%RTC_E_SDP_NO_MEDIA               = &H80EE000B&

' //
' // MessageId: RTC_E_SIP_TIMEOUT
' //
' // MessageText:
' //
' //  SIP Transaction timed out
' //
%RTC_E_SIP_TIMEOUT                = &H80EE000C&

' //
' // MessageId: RTC_E_SDP_FAILED_TO_BUILD
' //
' // MessageText:
' //
' //  Failed to build SDP blob
' //
%RTC_E_SDP_FAILED_TO_BUILD        = &H80EE000D&

' //
' // MessageId: RTC_E_SIP_INVITE_TRANSACTION_PENDING
' //
' // MessageText:
' //
' //  Currently processing another INVITE transaction
' //
%RTC_E_SIP_INVITE_TRANSACTION_PENDING = &H80EE000E&

' //
' // MessageId: RTC_E_SIP_AUTH_HEADER_SENT
' //
' // MessageText:
' //
' //  Authorization header was sent in a previous request
' //
%RTC_E_SIP_AUTH_HEADER_SENT       = &H80EE000F&

' //
' // MessageId: RTC_E_SIP_AUTH_TYPE_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  The Authentication type requested is not supported
' //
%RTC_E_SIP_AUTH_TYPE_NOT_SUPPORTED = &H80EE0010&

' //
' // MessageId: RTC_E_SIP_AUTH_FAILED
' //
' // MessageText:
' //
' //  Authentication Failed
' //
%RTC_E_SIP_AUTH_FAILED            = &H80EE0011&

' //
' // MessageId: RTC_E_INVALID_SIP_URL
' //
' // MessageText:
' //
' //  The SIP URL is not valid
' //
%RTC_E_INVALID_SIP_URL            = &H80EE0012&

' //
' // MessageId: RTC_E_DESTINATION_ADDRESS_LOCAL
' //
' // MessageText:
' //
' //  The Destination Address belongs to the local machine
' //
%RTC_E_DESTINATION_ADDRESS_LOCAL  = &H80EE0013&

' //
' // MessageId: RTC_E_INVALID_ADDRESS_LOCAL
' //
' // MessageText:
' //
' //  The Local Address is invalid, check the profile
' //
%RTC_E_INVALID_ADDRESS_LOCAL      = &H80EE0014&

' //
' // MessageId: RTC_E_DESTINATION_ADDRESS_MULTICAST
' //
' // MessageText:
' //
' //  The Destination Address is a multicast address
' //
%RTC_E_DESTINATION_ADDRESS_MULTICAST = &H80EE0015&

' //
' // MessageId: RTC_E_INVALID_PROXY_ADDRESS
' //
' // MessageText:
' //
' //  The Proxy Address is not valid
' //
%RTC_E_INVALID_PROXY_ADDRESS      = &H80EE0016&

' //
' // MessageId: RTC_E_SIP_TRANSPORT_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  The Transport specified is not supported
' //
%RTC_E_SIP_TRANSPORT_NOT_SUPPORTED = &H80EE0017&

' // SIP internal error codes
' //
' // MessageId: RTC_E_SIP_NEED_MORE_DATA
' //
' // MessageText:
' //
' //  Need more data for parsing a whole SIP message
' //
%RTC_E_SIP_NEED_MORE_DATA         = &H80EE0018&

' //
' // MessageId: RTC_E_SIP_CALL_DISCONNECTED
' //
' // MessageText:
' //
' //  The Call has been disconnected
' //
%RTC_E_SIP_CALL_DISCONNECTED      = &H80EE0019&

' //
' // MessageId: RTC_E_SIP_REQUEST_DESTINATION_ADDR_NOT_PRESENT
' //
' // MessageText:
' //
' //  The Request destination address is not known
' //
%RTC_E_SIP_REQUEST_DESTINATION_ADDR_NOT_PRESENT = &H80EE001A&

' //
' // MessageId: RTC_E_SIP_UDP_SIZE_EXCEEDED
' //
' // MessageText:
' //
' //  The sip message size is greater than the UDP message size allowed
' //
%RTC_E_SIP_UDP_SIZE_EXCEEDED      = &H80EE001B&

' //
' // MessageId: RTC_E_SIP_SSL_TUNNEL_FAILED
' //
' // MessageText:
' //
' //  Cannot establish SSL tunnel to Http proxy
' //
%RTC_E_SIP_SSL_TUNNEL_FAILED      = &H80EE001C&

' //
' // MessageId: RTC_E_SIP_SSL_NEGOTIATION_TIMEOUT
' //
' // MessageText:
' //
' //  Timeout during SSL Negotiation
' //
%RTC_E_SIP_SSL_NEGOTIATION_TIMEOUT = &H80EE001D&

' //
' // MessageId: RTC_E_SIP_STACK_SHUTDOWN
' //
' // MessageText:
' //
' //  Sip Stack is already shutdown
' //
%RTC_E_SIP_STACK_SHUTDOWN         = &H80EE001E&

' // media error codes
' //
' // MessageId: RTC_E_MEDIA_CONTROLLER_STATE
' //
' // MessageText:
' //
' //  Operation not allowed in current media controller state
' //
%RTC_E_MEDIA_CONTROLLER_STATE     = &H80EE001F&

' //
' // MessageId: RTC_E_MEDIA_NEED_TERMINAL
' //
' // MessageText:
' //
' //  Can not find device
' //
%RTC_E_MEDIA_NEED_TERMINAL        = &H80EE0020&

' //
' // MessageId: RTC_E_MEDIA_AUDIO_DEVICE_NOT_AVAILABLE
' //
' // MessageText:
' //
' //  Audio device is not available
' //
%RTC_E_MEDIA_AUDIO_DEVICE_NOT_AVAILABLE = &H80EE0021&

' //
' // MessageId: RTC_E_MEDIA_VIDEO_DEVICE_NOT_AVAILABLE
' //
' // MessageText:
' //
' //  Video device is not available
' //
%RTC_E_MEDIA_VIDEO_DEVICE_NOT_AVAILABLE = &H80EE0022&

' //
' // MessageId: RTC_E_START_STREAM
' //
' // MessageText:
' //
' //  Can not start stream
' //
%RTC_E_START_STREAM               = &H80EE0023&

' //
' // MessageId: RTC_E_MEDIA_AEC
' //
' // MessageText:
' //
' //  Failed to enable acoustic echo cancellation
' //
%RTC_E_MEDIA_AEC                  = &H80EE0024&

' // Core error codes
' //
' // MessageId: RTC_E_CLIENT_NOT_INITIALIZED
' //
' // MessageText:
' //
' //  Client not initialized
' //
%RTC_E_CLIENT_NOT_INITIALIZED     = &H80EE0025&

' //
' // MessageId: RTC_E_CLIENT_ALREADY_INITIALIZED
' //
' // MessageText:
' //
' //  Client already initialized
' //
%RTC_E_CLIENT_ALREADY_INITIALIZED = &H80EE0026&

' //
' // MessageId: RTC_E_CLIENT_ALREADY_SHUT_DOWN
' //
' // MessageText:
' //
' //  Client already shut down
' //
%RTC_E_CLIENT_ALREADY_SHUT_DOWN   = &H80EE0027&

' //
' // MessageId: RTC_E_PRESENCE_NOT_ENABLED
' //
' // MessageText:
' //
' //  Presence not enabled
' //
%RTC_E_PRESENCE_NOT_ENABLED       = &H80EE0028&

' //
' // MessageId: RTC_E_INVALID_SESSION_TYPE
' //
' // MessageText:
' //
' //  Invalid session type
' //
%RTC_E_INVALID_SESSION_TYPE       = &H80EE0029&

' //
' // MessageId: RTC_E_INVALID_SESSION_STATE
' //
' // MessageText:
' //
' //  Invalid session state
' //
%RTC_E_INVALID_SESSION_STATE      = &H80EE002A&

' //
' // MessageId: RTC_E_NO_PROFILE
' //
' // MessageText:
' //
' //  No valid profile for this operation
' //
%RTC_E_NO_PROFILE                 = &H80EE002B&

' //
' // MessageId: RTC_E_LOCAL_PHONE_NEEDED
' //
' // MessageText:
' //
' //  A local phone number is needed
' //
%RTC_E_LOCAL_PHONE_NEEDED         = &H80EE002C&

' //
' // MessageId: RTC_E_NO_DEVICE
' //
' // MessageText:
' //
' //  No preferred device
' //
%RTC_E_NO_DEVICE                  = &H80EE002D&

' //
' // MessageId: RTC_E_INVALID_PROFILE
' //
' // MessageText:
' //
' //  Invalid profile
' //
%RTC_E_INVALID_PROFILE            = &H80EE002E&

' //
' // MessageId: RTC_E_PROFILE_NO_PROVISION
' //
' // MessageText:
' //
' //  No provision tag in profile
' //
%RTC_E_PROFILE_NO_PROVISION       = &H80EE002F&

' //
' // MessageId: RTC_E_PROFILE_NO_KEY
' //
' // MessageText:
' //
' //  No profile key
' //
%RTC_E_PROFILE_NO_KEY             = &H80EE0030&

' //
' // MessageId: RTC_E_PROFILE_NO_NAME
' //
' // MessageText:
' //
' //  No profile name
' //
%RTC_E_PROFILE_NO_NAME            = &H80EE0031&

' //
' // MessageId: RTC_E_PROFILE_NO_USER
' //
' // MessageText:
' //
' //  No user tag in profile
' //
%RTC_E_PROFILE_NO_USER            = &H80EE0032&

' //
' // MessageId: RTC_E_PROFILE_NO_USER_URI
' //
' // MessageText:
' //
' //  No user URI in profile
' //
%RTC_E_PROFILE_NO_USER_URI        = &H80EE0033&

' //
' // MessageId: RTC_E_PROFILE_NO_SERVER
' //
' // MessageText:
' //
' //  No server tag in profile
' //
%RTC_E_PROFILE_NO_SERVER          = &H80EE0034&

' //
' // MessageId: RTC_E_PROFILE_NO_SERVER_ADDRESS
' //
' // MessageText:
' //
' //  Server tag missing address in profile
' //
%RTC_E_PROFILE_NO_SERVER_ADDRESS  = &H80EE0035&

' //
' // MessageId: RTC_E_PROFILE_NO_SERVER_PROTOCOL
' //
' // MessageText:
' //
' //  Server tag missing protocol in profile
' //
%RTC_E_PROFILE_NO_SERVER_PROTOCOL = &H80EE0036&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SERVER_PROTOCOL
' //
' // MessageText:
' //
' //  Invalid server protocol in profile
' //
%RTC_E_PROFILE_INVALID_SERVER_PROTOCOL = &H80EE0037&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SERVER_AUTHMETHOD
' //
' // MessageText:
' //
' //  Invalid server authentication method in profile
' //
%RTC_E_PROFILE_INVALID_SERVER_AUTHMETHOD = &H80EE0038&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SERVER_ROLE
' //
' // MessageText:
' //
' //  Invalid server role in profile
' //
%RTC_E_PROFILE_INVALID_SERVER_ROLE = &H80EE0039&

' //
' // MessageId: RTC_E_PROFILE_MULTIPLE_REGISTRARS
' //
' // MessageText:
' //
' //  Multiple registrar servers in profile
' //
%RTC_E_PROFILE_MULTIPLE_REGISTRARS = &H80EE003A&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SESSION
' //
' // MessageText:
' //
' //  Invalid session tag in profile
' //
%RTC_E_PROFILE_INVALID_SESSION    = &H80EE003B&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SESSION_PARTY
' //
' // MessageText:
' //
' //  Invalid session party in profile
' //
%RTC_E_PROFILE_INVALID_SESSION_PARTY = &H80EE003C&

' //
' // MessageId: RTC_E_PROFILE_INVALID_SESSION_TYPE
' //
' // MessageText:
' //
' //  Invalid session type in profile
' //
%RTC_E_PROFILE_INVALID_SESSION_TYPE = &H80EE003D&

' //
' // MessageId: RTC_E_OPERATION_WITH_TOO_MANY_PARTICIPANTS
' //
' // MessageText:
' //
' //  The operation failed because of too many participants in the session
' //
%RTC_E_OPERATION_WITH_TOO_MANY_PARTICIPANTS = &H80EE003E&

' //
' // MessageId: RTC_E_BASIC_AUTH_SET_TLS
' //
' // MessageText:
' //
' //  Must set transport to TLS if Basic Auth is allowed
' //
%RTC_E_BASIC_AUTH_SET_TLS         = &H80EE003F&

' //
' // MessageId: RTC_E_SIP_HIGH_SECURITY_SET_TLS
' //
' // MessageText:
' //
' //  Must set transport to TLS if high security mode is needed
' //
%RTC_E_SIP_HIGH_SECURITY_SET_TLS  = &H80EE0040&

' //
' // MessageId: RTC_S_ROAMING_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  Server does not support this type of roaming
' //
%RTC_S_ROAMING_NOT_SUPPORTED      = &H00EE0041&

' //
' // MessageId: RTC_E_PROFILE_SERVER_UNAUTHORIZED
' //
' // MessageText:
' //
' //  Server address does not match an authorized domain in profile
' //
%RTC_E_PROFILE_SERVER_UNAUTHORIZED = &H80EE0042&

' //
' // MessageId: RTC_E_DUPLICATE_REALM
' //
' // MessageText:
' //
' //  Duplicate realm exists in an enabled profile
' //
%RTC_E_DUPLICATE_REALM            = &H80EE0043&

' //
' // MessageId: RTC_E_POLICY_NOT_ALLOW
' //
' // MessageText:
' //
' //  Current policy settings do not allow this action
' //
%RTC_E_POLICY_NOT_ALLOW           = &H80EE0044&

' //
' // MessageId: RTC_E_PORT_MAPPING_UNAVAILABLE
' //
' // MessageText:
' //
' //  Port mapping can not be obtained from the port manager
' //
%RTC_E_PORT_MAPPING_UNAVAILABLE   = &H80EE0045&

' //
' // MessageId: RTC_E_PORT_MAPPING_FAILED
' //
' // MessageText:
' //
' //  Port mapping failure returned from the port manager
' //
%RTC_E_PORT_MAPPING_FAILED        = &H80EE0046&

' //
' // MessageId: RTC_E_SECURITY_LEVEL_NOT_COMPATIBLE
' //
' // MessageText:
' //
' //  The local and remote security levels are not compatible.
' //
%RTC_E_SECURITY_LEVEL_NOT_COMPATIBLE = &H80EE0047&

' //
' // MessageId: RTC_E_SECURITY_LEVEL_NOT_DEFINED
' //
' // MessageText:
' //
' //  The security level is not defined
' //
%RTC_E_SECURITY_LEVEL_NOT_DEFINED = &H80EE0048&

' //
' // MessageId: RTC_E_SECURITY_LEVEL_NOT_SUPPORTED_BY_PARTICIPANT
' //
' // MessageText:
' //
' //  Participant could not support the requested security level
' //
%RTC_E_SECURITY_LEVEL_NOT_SUPPORTED_BY_PARTICIPANT = &H80EE0049&

' //
' // MessageId: RTC_E_DUPLICATE_BUDDY
' //
' // MessageText:
' //
' //  Buddy already exists
' //
%RTC_E_DUPLICATE_BUDDY            = &H80EE004A&

' //
' // MessageId: RTC_E_DUPLICATE_WATCHER
' //
' // MessageText:
' //
' //  Watcher already exists
' //
%RTC_E_DUPLICATE_WATCHER          = &H80EE004B&

' //
' // MessageId: RTC_E_MALFORMED_XML
' //
' // MessageText:
' //
' //  Malformed XML
' //
%RTC_E_MALFORMED_XML              = &H80EE004C&

' //
' // MessageId: RTC_E_ROAMING_OPERATION_INTERRUPTED
' //
' // MessageText:
' //
' //  Roaming operation interrupted. It may succeed or fail.
' //
%RTC_E_ROAMING_OPERATION_INTERRUPTED = &H80EE004D&

' //
' // MessageId: RTC_E_ROAMING_FAILED
' //
' // MessageText:
' //
' //  Roaming session failed
' //
%RTC_E_ROAMING_FAILED             = &H80EE004E&

' //
' // MessageId: RTC_E_INVALID_BUDDY_LIST
' //
' // MessageText:
' //
' //  Buddy list is invalid
' //
%RTC_E_INVALID_BUDDY_LIST         = &H80EE004F&

' //
' // MessageId: RTC_E_INVALID_ACL_LIST
' //
' // MessageText:
' //
' //  ACL list is invalid
' //
%RTC_E_INVALID_ACL_LIST           = &H80EE0050&

' //
' // MessageId: RTC_E_NO_GROUP
' //
' // MessageText:
' //
' //  Group does not exist
' //
%RTC_E_NO_GROUP                   = &H80EE0051&

' //
' // MessageId: RTC_E_DUPLICATE_GROUP
' //
' // MessageText:
' //
' //  Group already exists
' //
%RTC_E_DUPLICATE_GROUP            = &H80EE0052&

' //
' // MessageId: RTC_E_TOO_MANY_GROUPS
' //
' // MessageText:
' //
' //  Max number of groups has been reached
' //
%RTC_E_TOO_MANY_GROUPS            = &H80EE0053&

' //
' // MessageId: RTC_E_NO_BUDDY
' //
' // MessageText:
' //
' //  Buddy does not exist
' //
%RTC_E_NO_BUDDY                   = &H80EE0054&

' //
' // MessageId: RTC_E_NO_WATCHER
' //
' // MessageText:
' //
' //  Watcher does not exist
' //
%RTC_E_NO_WATCHER                 = &H80EE0055&

' //
' // MessageId: RTC_E_NO_REALM
' //
' // MessageText:
' //
' //  No realm is set
' //
%RTC_E_NO_REALM                   = &H80EE0056&

' //
' // MessageId: RTC_E_NO_TRANSPORT
' //
' // MessageText:
' //
' //  Server can not be specified without a transport protocol
' //
%RTC_E_NO_TRANSPORT               = &H80EE0057&

' //
' // MessageId: RTC_E_NOT_EXIST
' //
' // MessageText:
' //
' //  The required item does not exist
' //
%RTC_E_NOT_EXIST                  = &H80EE0058&

' //
' // MessageId: RTC_E_INVALID_PREFERENCE_LIST
' //
' // MessageText:
' //
' //  Preference list is invalid
' //
%RTC_E_INVALID_PREFERENCE_LIST    = &H80EE0059&

' //
' // MessageId: RTC_E_MAX_PENDING_OPERATIONS
' //
' // MessageText:
' //
' //  Maximum number of pending operations reached
' //
%RTC_E_MAX_PENDING_OPERATIONS     = &H80EE005A&

' //
' // MessageId: RTC_E_TOO_MANY_RETRIES
' //
' // MessageText:
' //
' //  Too many attempts to resend a request
' //
%RTC_E_TOO_MANY_RETRIES           = &H80EE005B&

' //
' // MessageId: RTC_E_INVALID_PORTRANGE
' //
' // MessageText:
' //
' //  Invalid port range
' //
%RTC_E_INVALID_PORTRANGE          = &H80EE005C&

' //
' // MessageId: RTC_E_SIP_CALL_CONNECTION_NOT_ESTABLISHED
' //
' // MessageText:
' //
' //  Call connection has not been established
' //
%RTC_E_SIP_CALL_CONNECTION_NOT_ESTABLISHED = &H80EE005D&

' //
' // MessageId: RTC_E_SIP_ADDITIONAL_PARTY_IN_TWO_PARTY_SESSION
' //
' // MessageText:
' //
' //  Adding additional parties to two party session failed
' //
%RTC_E_SIP_ADDITIONAL_PARTY_IN_TWO_PARTY_SESSION = &H80EE005E&

' //
' // MessageId: RTC_E_SIP_PARTY_ALREADY_IN_SESSION
' //
' // MessageText:
' //
' //  Party already exists in session
' //
%RTC_E_SIP_PARTY_ALREADY_IN_SESSION = &H80EE005F&

' //
' // MessageId: RTC_E_SIP_OTHER_PARTY_JOIN_IN_PROGRESS
' //
' // MessageText:
' //
' //  Join operation is in progress for another party
' //
%RTC_E_SIP_OTHER_PARTY_JOIN_IN_PROGRESS = &H80EE0060&

' //
' // MessageId: RTC_E_INVALID_OBJECT_STATE
' //
' // MessageText:
' //
' //  Object state does not allow to perform this operation
' //
%RTC_E_INVALID_OBJECT_STATE       = &H80EE0061&

' //
' // MessageId: RTC_E_PRESENCE_ENABLED
' //
' // MessageText:
' //
' //  Presence is enabled
' //
%RTC_E_PRESENCE_ENABLED           = &H80EE0062&

' //
' // MessageId: RTC_E_ROAMING_ENABLED
' //
' // MessageText:
' //
' //  Roaming is enabled
' //
%RTC_E_ROAMING_ENABLED            = &H80EE0063&

' //
' // MessageId: RTC_E_SIP_TLS_INCOMPATIBLE_ENCRYPTION
' //
' // MessageText:
' //
' //  Incompatible TLS encryption
' //
%RTC_E_SIP_TLS_INCOMPATIBLE_ENCRYPTION = &H80EE0064&

' //
' // MessageId: RTC_E_SIP_INVALID_CERTIFICATE
' //
' // MessageText:
' //
' //  Invalid certificate
' //
%RTC_E_SIP_INVALID_CERTIFICATE    = &H80EE0065&

' //
' // MessageId: RTC_E_SIP_DNS_FAIL
' //
' // MessageText:
' //
' //  DNS lookup fails
' //
%RTC_E_SIP_DNS_FAIL               = &H80EE0066&

' //
' // MessageId: RTC_E_SIP_TCP_FAIL
' //
' // MessageText:
' //
' //  Fails to make a TCP connection
' //
%RTC_E_SIP_TCP_FAIL               = &H80EE0067&

' //
' // MessageId: RTC_E_TOO_SMALL_EXPIRES_VALUE
' //
' // MessageText:
' //
' //  Expires value received from the server is too small
' //
%RTC_E_TOO_SMALL_EXPIRES_VALUE    = &H80EE0068&

' //
' // MessageId: RTC_E_SIP_TLS_FAIL
' //
' // MessageText:
' //
' //  Fails to make a TLS connection
' //
%RTC_E_SIP_TLS_FAIL               = &H80EE0069&

' //
' // MessageId: RTC_E_NOT_PRESENCE_PROFILE
' //
' // MessageText:
' //
' //  A presence profile must be used
' //
%RTC_E_NOT_PRESENCE_PROFILE       = &H80EE006A&

' //
' // MessageId: RTC_E_SIP_INVITEE_PARTY_TIMEOUT
' //
' // MessageText:
' //
' //  Invitee connection fails
' //
%RTC_E_SIP_INVITEE_PARTY_TIMEOUT  = &H80EE006B&

' //
' // MessageId: RTC_E_SIP_AUTH_TIME_SKEW
' //
' // MessageText:
' //
' //  Authentication failure because of time skew between client and server
' //
%RTC_E_SIP_AUTH_TIME_SKEW         = &H80EE006C&

' //
' // MessageId: RTC_E_INVALID_REGISTRATION_STATE
' //
' // MessageText:
' //
' //  Invalid registration state
' //
%RTC_E_INVALID_REGISTRATION_STATE = &H80EE006D&

' //
' // MessageId: RTC_E_MEDIA_DISABLED
' //
' // MessageText:
' //
' //  Media is disabled
' //
%RTC_E_MEDIA_DISABLED             = &H80EE006E&

' //
' // MessageId: RTC_E_MEDIA_ENABLED
' //
' // MessageText:
' //
' //  Media is enabled
' //
%RTC_E_MEDIA_ENABLED              = &H80EE006F&

' //
' // MessageId: RTC_E_REFER_NOT_ACCEPTED
' //
' // MessageText:
' //
' //  Refer has not been accepted
' //
%RTC_E_REFER_NOT_ACCEPTED         = &H80EE0070&

' //
' // MessageId: RTC_E_REFER_NOT_ALLOWED
' //
' // MessageText:
' //
' //  Refer operation is not allowed in this session
' //
%RTC_E_REFER_NOT_ALLOWED          = &H80EE0071&

' //
' // MessageId: RTC_E_REFER_NOT_EXIST
' //
' // MessageText:
' //
' //  Refer session does not exist or has finished
' //
%RTC_E_REFER_NOT_EXIST            = &H80EE0072&

' //
' // MessageId: RTC_E_SIP_HOLD_OPERATION_PENDING
' //
' // MessageText:
' //
' //  Currently an hold operation is pending
' //
%RTC_E_SIP_HOLD_OPERATION_PENDING = &H80EE0073&

' //
' // MessageId: RTC_E_SIP_UNHOLD_OPERATION_PENDING
' //
' // MessageText:
' //
' //  Currently an unhold operation is pending
' //
%RTC_E_SIP_UNHOLD_OPERATION_PENDING = &H80EE0074&

' //
' // MessageId: RTC_E_MEDIA_SESSION_NOT_EXIST
' //
' // MessageText:
' //
' //  Media session does not exist
' //
%RTC_E_MEDIA_SESSION_NOT_EXIST    = &H80EE0075&

' //
' // MessageId: RTC_E_MEDIA_SESSION_IN_HOLD
' //
' // MessageText:
' //
' //  Media session is in hold
' //
%RTC_E_MEDIA_SESSION_IN_HOLD      = &H80EE0076&

' //
' // MessageId: RTC_E_ANOTHER_MEDIA_SESSION_ACTIVE
' //
' // MessageText:
' //
' //  Another media session is active
' //
%RTC_E_ANOTHER_MEDIA_SESSION_ACTIVE = &H80EE0077&

' //
' // MessageId: RTC_E_MAX_REDIRECTS
' //
' // MessageText:
' //
' //  Too many redirects
' //
%RTC_E_MAX_REDIRECTS              = &H80EE0078&

' //
' // MessageId: RTC_E_REDIRECT_PROCESSING_FAILED
' //
' // MessageText:
' //
' //  Processing redirect failed
' //
%RTC_E_REDIRECT_PROCESSING_FAILED = &H80EE0079&

' //
' // MessageId: RTC_E_LISTENING_SOCKET_NOT_EXIST
' //
' // MessageText:
' //
' //  Listening socket does not exist
' //
%RTC_E_LISTENING_SOCKET_NOT_EXIST = &H80EE007A&

' //
' // MessageId: RTC_E_INVALID_LISTEN_SOCKET
' //
' // MessageText:
' //
' //  Specified address and port is invalid
' //
%RTC_E_INVALID_LISTEN_SOCKET      = &H80EE007B&

' //
' // MessageId: RTC_E_PORT_MANAGER_ALREADY_SET
' //
' // MessageText:
' //
' //  Port manager already set
' //
%RTC_E_PORT_MANAGER_ALREADY_SET   = &H80EE007C&

' //
' // MessageId: RTC_E_SECURITY_LEVEL_ALREADY_SET
' //
' // MessageText:
' //
' //  The security level has already been set for this Media type can and can not be changed
' //
%RTC_E_SECURITY_LEVEL_ALREADY_SET = &H80EE007D&

' //
' // MessageId: RTC_E_UDP_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  This feature is not supported when one of the server in profile has UDP transport
' //
%RTC_E_UDP_NOT_SUPPORTED          = &H80EE007E&

' //
' // MessageId: RTC_E_SIP_REFER_OPERATION_PENDING
' //
' // MessageText:
' //
' //  Currently a refer operation is pending
' //
%RTC_E_SIP_REFER_OPERATION_PENDING = &H80EE007F&

' //
' // MessageId: RTC_E_PLATFORM_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  This operation is not supported on this Windows Platform.
' //
%RTC_E_PLATFORM_NOT_SUPPORTED     = &H80EE0080&

' //
' // MessageId: RTC_E_SIP_PEER_PARTICIPANT_IN_MULTIPARTY_SESSION
' //
' // MessageText:
' //
' //  A peer participant cannot be added to a multiparty session
' //
%RTC_E_SIP_PEER_PARTICIPANT_IN_MULTIPARTY_SESSION = &H80EE0081&

' //
' // MessageId: RTC_E_NOT_ALLOWED
' //
' // MessageText:
' //
' //  This action is not allowed
' //
%RTC_E_NOT_ALLOWED                = &H80EE0082&

' //
' // MessageId: RTC_E_REGISTRATION_DEACTIVATED
' //
' // MessageText:
' //
' //  The user is being moved
' //
%RTC_E_REGISTRATION_DEACTIVATED   = &H80EE0083&

' //
' // MessageId: RTC_E_REGISTRATION_REJECTED
' //
' // MessageText:
' //
' //  The user's account was disabled or deleted or the SIP URI changed
' //
%RTC_E_REGISTRATION_REJECTED      = &H80EE0084&

' //
' // MessageId: RTC_E_REGISTRATION_UNREGISTERED
' //
' // MessageText:
' //
' //  The user was logged out because the user logged in elsewhere
' //
%RTC_E_REGISTRATION_UNREGISTERED  = &H80EE0085&

' // Error codes from SIP status codes
' //
' // MessageId: RTC_E_STATUS_INFO_TRYING
' //
' // MessageText:
' //
' //  Trying
' //
%RTC_E_STATUS_INFO_TRYING         = &H00EF0064&

' //
' // MessageId: RTC_E_STATUS_INFO_RINGING
' //
' // MessageText:
' //
' //  Ringing
' //
%RTC_E_STATUS_INFO_RINGING        = &H00EF00B4&

' //
' // MessageId: RTC_E_STATUS_INFO_CALL_FORWARDING
' //
' // MessageText:
' //
' //  Call Is Being Forwarded
' //
%RTC_E_STATUS_INFO_CALL_FORWARDING = &H00EF00B5&

' //
' // MessageId: RTC_E_STATUS_INFO_QUEUED
' //
' // MessageText:
' //
' //  Queued
' //
%RTC_E_STATUS_INFO_QUEUED         = &H00EF00B6&

' //
' // MessageId: RTC_E_STATUS_SESSION_PROGRESS
' //
' // MessageText:
' //
' //  Session Progress
' //
%RTC_E_STATUS_SESSION_PROGRESS    = &H00EF00B7&

' //
' // MessageId: RTC_E_STATUS_SUCCESS
' //
' // MessageText:
' //
' //  OK
' //
%RTC_E_STATUS_SUCCESS             = &H00EF00C8&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_MULTIPLE_CHOICES
' //
' // MessageText:
' //
' //  Multiple Choices
' //
%RTC_E_STATUS_REDIRECT_MULTIPLE_CHOICES = &H80EF012C&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_MOVED_PERMANENTLY
' //
' // MessageText:
' //
' //  Moved Permanently
' //
%RTC_E_STATUS_REDIRECT_MOVED_PERMANENTLY = &H80EF012D&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_MOVED_TEMPORARILY
' //
' // MessageText:
' //
' //  Moved Temporarily
' //
%RTC_E_STATUS_REDIRECT_MOVED_TEMPORARILY = &H80EF012E&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_SEE_OTHER
' //
' // MessageText:
' //
' //  See Other
' //
%RTC_E_STATUS_REDIRECT_SEE_OTHER  = &H80EF012F&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_USE_PROXY
' //
' // MessageText:
' //
' //  Use Proxy
' //
%RTC_E_STATUS_REDIRECT_USE_PROXY  = &H80EF0131&

' //
' // MessageId: RTC_E_STATUS_REDIRECT_ALTERNATIVE_SERVICE
' //
' // MessageText:
' //
' //  Alternative Service
' //
%RTC_E_STATUS_REDIRECT_ALTERNATIVE_SERVICE = &H80EF017C&

' //
' // MessageId: RTC_E_STATUS_CLIENT_BAD_REQUEST
' //
' // MessageText:
' //
' //  Bad Request
' //
%RTC_E_STATUS_CLIENT_BAD_REQUEST  = &H80EF0190&

' //
' // MessageId: RTC_E_STATUS_CLIENT_UNAUTHORIZED
' //
' // MessageText:
' //
' //  Unauthorized
' //
%RTC_E_STATUS_CLIENT_UNAUTHORIZED = &H80EF0191&

' //
' // MessageId: RTC_E_STATUS_CLIENT_PAYMENT_REQUIRED
' //
' // MessageText:
' //
' //  Payment Required
' //
%RTC_E_STATUS_CLIENT_PAYMENT_REQUIRED = &H80EF0192&

' //
' // MessageId: RTC_E_STATUS_CLIENT_FORBIDDEN
' //
' // MessageText:
' //
' //  Forbidden
' //
%RTC_E_STATUS_CLIENT_FORBIDDEN    = &H80EF0193&

' //
' // MessageId: RTC_E_STATUS_CLIENT_NOT_FOUND
' //
' // MessageText:
' //
' //  Not Found
' //
%RTC_E_STATUS_CLIENT_NOT_FOUND    = &H80EF0194&

' //
' // MessageId: RTC_E_STATUS_CLIENT_METHOD_NOT_ALLOWED
' //
' // MessageText:
' //
' //  Method Not Allowed
' //
%RTC_E_STATUS_CLIENT_METHOD_NOT_ALLOWED = &H80EF0195&

' //
' // MessageId: RTC_E_STATUS_CLIENT_NOT_ACCEPTABLE
' //
' // MessageText:
' //
' //  Not Acceptable
' //
%RTC_E_STATUS_CLIENT_NOT_ACCEPTABLE = &H80EF0196&

' //
' // MessageId: RTC_E_STATUS_CLIENT_PROXY_AUTHENTICATION_REQUIRED
' //
' // MessageText:
' //
' //  Proxy Authentication Required
' //
%RTC_E_STATUS_CLIENT_PROXY_AUTHENTICATION_REQUIRED = &H80EF0197&

' //
' // MessageId: RTC_E_STATUS_CLIENT_REQUEST_TIMEOUT
' //
' // MessageText:
' //
' //  Request Timeout
' //
%RTC_E_STATUS_CLIENT_REQUEST_TIMEOUT = &H80EF0198&

' //
' // MessageId: RTC_E_STATUS_CLIENT_CONFLICT
' //
' // MessageText:
' //
' //  Conflict
' //
%RTC_E_STATUS_CLIENT_CONFLICT     = &H80EF0199&

' //
' // MessageId: RTC_E_STATUS_CLIENT_GONE
' //
' // MessageText:
' //
' //  Gone
' //
%RTC_E_STATUS_CLIENT_GONE         = &H80EF019A&

' //
' // MessageId: RTC_E_STATUS_CLIENT_LENGTH_REQUIRED
' //
' // MessageText:
' //
' //  Length Required
' //
%RTC_E_STATUS_CLIENT_LENGTH_REQUIRED = &H80EF019B&

' //
' // MessageId: RTC_E_STATUS_CLIENT_REQUEST_ENTITY_TOO_LARGE
' //
' // MessageText:
' //
' //  Request Entity Too Large
' //
%RTC_E_STATUS_CLIENT_REQUEST_ENTITY_TOO_LARGE = &H80EF019D&

' //
' // MessageId: RTC_E_STATUS_CLIENT_REQUEST_URI_TOO_LARGE
' //
' // MessageText:
' //
' //  Request-URI Too Long
' //
%RTC_E_STATUS_CLIENT_REQUEST_URI_TOO_LARGE = &H80EF019E&

' //
' // MessageId: RTC_E_STATUS_CLIENT_UNSUPPORTED_MEDIA_TYPE
' //
' // MessageText:
' //
' //  Unsupported Media Type
' //
%RTC_E_STATUS_CLIENT_UNSUPPORTED_MEDIA_TYPE = &H80EF019F&

' //
' // MessageId: RTC_E_STATUS_CLIENT_BAD_EXTENSION
' //
' // MessageText:
' //
' //  Bad Extension
' //
%RTC_E_STATUS_CLIENT_BAD_EXTENSION = &H80EF01A4&

' //
' // MessageId: RTC_E_STATUS_CLIENT_TEMPORARILY_NOT_AVAILABLE
' //
' // MessageText:
' //
' //  Temporarily Unavailable
' //
%RTC_E_STATUS_CLIENT_TEMPORARILY_NOT_AVAILABLE = &H80EF01E0&

' //
' // MessageId: RTC_E_STATUS_CLIENT_TRANSACTION_DOES_NOT_EXIST
' //
' // MessageText:
' //
' //  Call Leg/Transaction Does Not Exist
' //
%RTC_E_STATUS_CLIENT_TRANSACTION_DOES_NOT_EXIST = &H80EF01E1&

' //
' // MessageId: RTC_E_STATUS_CLIENT_LOOP_DETECTED
' //
' // MessageText:
' //
' //  Loop Detected
' //
%RTC_E_STATUS_CLIENT_LOOP_DETECTED = &H80EF01E2&

' //
' // MessageId: RTC_E_STATUS_CLIENT_TOO_MANY_HOPS
' //
' // MessageText:
' //
' //  Too Many Hops
' //
%RTC_E_STATUS_CLIENT_TOO_MANY_HOPS = &H80EF01E3&

' //
' // MessageId: RTC_E_STATUS_CLIENT_ADDRESS_INCOMPLETE
' //
' // MessageText:
' //
' //  Address Incomplete
' //
%RTC_E_STATUS_CLIENT_ADDRESS_INCOMPLETE = &H80EF01E4&

' //
' // MessageId: RTC_E_STATUS_CLIENT_AMBIGUOUS
' //
' // MessageText:
' //
' //  Ambiguous
' //
%RTC_E_STATUS_CLIENT_AMBIGUOUS    = &H80EF01E5&

' //
' // MessageId: RTC_E_STATUS_CLIENT_BUSY_HERE
' //
' // MessageText:
' //
' //  Busy Here
' //
%RTC_E_STATUS_CLIENT_BUSY_HERE    = &H80EF01E6&

' //
' // MessageId: RTC_E_STATUS_REQUEST_TERMINATED
' //
' // MessageText:
' //
' //  Request Terminated
' //
%RTC_E_STATUS_REQUEST_TERMINATED  = &H80EF01E7&

' //
' // MessageId: RTC_E_STATUS_NOT_ACCEPTABLE_HERE
' //
' // MessageText:
' //
' //  Not Acceptable Here
' //
%RTC_E_STATUS_NOT_ACCEPTABLE_HERE = &H80EF01E8&

' //
' // MessageId: RTC_E_STATUS_SERVER_INTERNAL_ERROR
' //
' // MessageText:
' //
' //  Server Internal Error
' //
%RTC_E_STATUS_SERVER_INTERNAL_ERROR = &H80EF01F4&

' //
' // MessageId: RTC_E_STATUS_SERVER_NOT_IMPLEMENTED
' //
' // MessageText:
' //
' //  Not Implemented
' //
%RTC_E_STATUS_SERVER_NOT_IMPLEMENTED = &H80EF01F5&

' //
' // MessageId: RTC_E_STATUS_SERVER_BAD_GATEWAY
' //
' // MessageText:
' //
' //  Bad Gateway
' //
%RTC_E_STATUS_SERVER_BAD_GATEWAY  = &H80EF01F6&

' //
' // MessageId: RTC_E_STATUS_SERVER_SERVICE_UNAVAILABLE
' //
' // MessageText:
' //
' //  Service Unavailable
' //
%RTC_E_STATUS_SERVER_SERVICE_UNAVAILABLE = &H80EF01F7&

' //
' // MessageId: RTC_E_STATUS_SERVER_SERVER_TIMEOUT
' //
' // MessageText:
' //
' //  Server Time-out
' //
%RTC_E_STATUS_SERVER_SERVER_TIMEOUT = &H80EF01F8&

' //
' // MessageId: RTC_E_STATUS_SERVER_VERSION_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  Version Not Supported
' //
%RTC_E_STATUS_SERVER_VERSION_NOT_SUPPORTED = &H80EF01F9&

' //
' // MessageId: RTC_E_STATUS_GLOBAL_BUSY_EVERYWHERE
' //
' // MessageText:
' //
' //  Busy Everywhere
' //
%RTC_E_STATUS_GLOBAL_BUSY_EVERYWHERE = &H80EF0258&

' //
' // MessageId: RTC_E_STATUS_GLOBAL_DECLINE
' //
' // MessageText:
' //
' //  Decline
' //
%RTC_E_STATUS_GLOBAL_DECLINE      = &H80EF025B&

' //
' // MessageId: RTC_E_STATUS_GLOBAL_DOES_NOT_EXIST_ANYWHERE
' //
' // MessageText:
' //
' //  Does Not Exist Anywhere
' //
%RTC_E_STATUS_GLOBAL_DOES_NOT_EXIST_ANYWHERE = &H80EF025C&

' //
' // MessageId: RTC_E_STATUS_GLOBAL_NOT_ACCEPTABLE
' //
' // MessageText:
' //
' //  Not Acceptable
' //
%RTC_E_STATUS_GLOBAL_NOT_ACCEPTABLE = &H80EF025E&

' // Error codes from PINT status codes
' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_BUSY
' //
' // MessageText:
' //
' //  Busy
' //
%RTC_E_PINT_STATUS_REJECTED_BUSY  = &H80F00005&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_NO_ANSWER
' //
' // MessageText:
' //
' //  No Answer
' //
%RTC_E_PINT_STATUS_REJECTED_NO_ANSWER = &H80F00006&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_ALL_BUSY
' //
' // MessageText:
' //
' //  All Busy
' //
%RTC_E_PINT_STATUS_REJECTED_ALL_BUSY = &H80F00007&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_PL_FAILED
' //
' // MessageText:
' //
' //  Primary Leg Failed
' //
%RTC_E_PINT_STATUS_REJECTED_PL_FAILED = &H80F00008&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_SW_FAILED
' //
' // MessageText:
' //
' //  Switch Failed
' //
%RTC_E_PINT_STATUS_REJECTED_SW_FAILED = &H80F00009&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_CANCELLED
' //
' // MessageText:
' //
' //  Cancelled
' //
%RTC_E_PINT_STATUS_REJECTED_CANCELLED = &H80F0000A&

' //
' // MessageId: RTC_E_PINT_STATUS_REJECTED_BADNUMBER
' //
' // MessageText:
' //
' //  Bad Number
' //
%RTC_E_PINT_STATUS_REJECTED_BADNUMBER = &H80F0000B&
