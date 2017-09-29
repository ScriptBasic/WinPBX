' ########################################################################################
' Microsoft Windows
' File: nserror.inc
' Contents: Definitions for Windows Media events
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NSERROR_INC = 1

'**************************** READ ME ******************************************

' Here are the commented error ranges for the Windows Media Technologies Group


' LEGACY RANGES

'     0  -  199 = General NetShow errors

'   200  -  399 = NetShow error events

'   400  -  599 = NetShow monitor events

'   600  -  799 = NetShow IMmsAutoServer errors

'  1000  - 1199 = NetShow MCMADM errors


' NEW RANGES

'  2000 -  2999 = ASF (defined in ASFERR.MC)

'  3000 -  3999 = Windows Media SDK

'  4000 -  4999 = Windows Media Player

'  5000 -  5999 = Windows Media Server

'  6000 -  6999 = Windows Media HTTP/RTSP result codes (defined in NETERROR.MC)

'  7000 -  7999 = Windows Media Tools

'  8000 -  8999 = Windows Media Content Discovery

'  9000 -  9999 = Windows Media Real Time Collaboration

' 10000 - 10999 = Windows Media Digital Rights Management

' 11000 - 11999 = Windows Media Setup

' 12000 - 12999 = Windows Media Networking

' 13000 - 13999 = Windows Media Client Media Services

'**************************** READ ME ******************************************

'--*/

'#define STATUS_SEVERITY(hr)  (((hr) >> 30) & 0x3)

#IF NOT %DEF(%STATUS_SEVERITY_DEFINED)
%STATUS_SEVERITY_DEFINED = 1
FUNCTION STATUS_SEVERITY(BYVAL hr AS LONG) AS LONG
   SHIFT RIGHT hr, 30
   FUNCTION = hr AND &H3
END FUNCTION
#ENDIF

'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Success Events
'//
'/////////////////////////////////////////////////////////////////////////

'//
'//  Values are 32 bit values laid out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//
%FACILITY_NS_WIN32                = &H7
%FACILITY_NS                      = &HD


'//
'// Define the severity codes
'//

%STATUS_SEVERITY_WARNING          = &H2
%STATUS_SEVERITY_SUCCESS          = &H0
%STATUS_SEVERITY_INFORMATIONAL    = &H1
%STATUS_SEVERITY_ERROR            = &H3

'//
'// MessageId: NS_S_CALLPENDING
'//
'// MessageText:
'//
'// The requested operation is pending completion.%0
'//
%NS_S_CALLPENDING                 = &H000D0000&

'//
'// MessageId: NS_S_CALLABORTED
'//
'// MessageText:
'//
'// The requested operation was aborted by the client.%0
'//
%NS_S_CALLABORTED                 = &H000D0001&

'//
'// MessageId: NS_S_STREAM_TRUNCATED
'//
'// MessageText:
'//
'// The stream was purposefully stopped before completion.%0
'//
%NS_S_STREAM_TRUNCATED            = &H000D0002&


'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Warning Events
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_W_SERVER_BANDWIDTH_LIMIT
'//
'// MessageText:
'//
'// The maximum filebitrate value specified is greater than the server's configured maximum bandwidth.%0
'//
%NS_W_SERVER_BANDWIDTH_LIMIT      = &H800D0003&

'//
'// MessageId: NS_W_FILE_BANDWIDTH_LIMIT
'//
'// MessageText:
'//
'// The maximum bandwidth value specified is less than the maximum filebitrate.%0
'//
%NS_W_FILE_BANDWIDTH_LIMIT        = &H800D0004&


'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Error Events
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_NOCONNECTION
'//
'// MessageText:
'//
'// There is no connection established with the Windows Media server. The operation failed.%0
'//
%NS_E_NOCONNECTION                = &HC00D0005&

'//
'// MessageId: NS_E_CANNOTCONNECT
'//
'// MessageText:
'//
'// Unable to establish a connection to the server.%0
'//
%NS_E_CANNOTCONNECT               = &HC00D0006&

'//
'// MessageId: NS_E_CANNOTDESTROYTITLE
'//
'// MessageText:
'//
'// Unable to destroy the title.%0
'//
%NS_E_CANNOTDESTROYTITLE          = &HC00D0007&

'//
'// MessageId: NS_E_CANNOTRENAMETITLE
'//
'// MessageText:
'//
'// Unable to rename the title.%0
'//
%NS_E_CANNOTRENAMETITLE           = &HC00D0008&

'//
'// MessageId: NS_E_CANNOTOFFLINEDISK
'//
'// MessageText:
'//
'// Unable to offline disk.%0
'//
%NS_E_CANNOTOFFLINEDISK           = &HC00D0009&

'//
'// MessageId: NS_E_CANNOTONLINEDISK
'//
'// MessageText:
'//
'// Unable to online disk.%0
'//
%NS_E_CANNOTONLINEDISK            = &HC00D000A&

'//
'// MessageId: NS_E_NOREGISTEREDWALKER
'//
'// MessageText:
'//
'// There is no file parser registered for this type of file.%0
'//
%NS_E_NOREGISTEREDWALKER          = &HC00D000B&

'//
'// MessageId: NS_E_NOFUNNEL
'//
'// MessageText:
'//
'// There is no data connection established.%0
'//
%NS_E_NOFUNNEL                    = &HC00D000C&

'//
'// MessageId: NS_E_NO_LOCALPLAY
'//
'// MessageText:
'//
'// Failed to load the local play DLL.%0
'//
%NS_E_NO_LOCALPLAY                = &HC00D000D&

'//
'// MessageId: NS_E_NETWORK_BUSY
'//
'// MessageText:
'//
'// The network is busy.%0
'//
%NS_E_NETWORK_BUSY                = &HC00D000E&

'//
'// MessageId: NS_E_TOO_MANY_SESS
'//
'// MessageText:
'//
'// The server session limit was exceeded.%0
'//
%NS_E_TOO_MANY_SESS               = &HC00D000F&

'//
'// MessageId: NS_E_ALREADY_CONNECTED
'//
'// MessageText:
'//
'// The network connection already exists.%0
'//
%NS_E_ALREADY_CONNECTED           = &HC00D0010&

'//
'// MessageId: NS_E_INVALID_INDEX
'//
'// MessageText:
'//
'// Index %1 is invalid.%0
'//
%NS_E_INVALID_INDEX               = &HC00D0011&

'//
'// MessageId: NS_E_PROTOCOL_MISMATCH
'//
'// MessageText:
'//
'// There is no protocol or protocol version supported by both the client and the server.%0
'//
%NS_E_PROTOCOL_MISMATCH           = &HC00D0012&

'//
'// MessageId: NS_E_TIMEOUT
'//
'// MessageText:
'//
'// The server, a computer set up to offer multimedia content to other computers, could not handle your request for multimedia content in a timely manner.  Please try again later.%0
'//
%NS_E_TIMEOUT                     = &HC00D0013&

'//
'// MessageId: NS_E_NET_WRITE
'//
'// MessageText:
'//
'// Error writing to the network.%0
'//
%NS_E_NET_WRITE                   = &HC00D0014&

'//
'// MessageId: NS_E_NET_READ
'//
'// MessageText:
'//
'// Error reading from the network.%0
'//
%NS_E_NET_READ                    = &HC00D0015&

'//
'// MessageId: NS_E_DISK_WRITE
'//
'// MessageText:
'//
'// Error writing to a disk.%0
'//
%NS_E_DISK_WRITE                  = &HC00D0016&

'//
'// MessageId: NS_E_DISK_READ
'//
'// MessageText:
'//
'// Error reading from a disk.%0
'//
%NS_E_DISK_READ                   = &HC00D0017&

'//
'// MessageId: NS_E_FILE_WRITE
'//
'// MessageText:
'//
'// Error writing to a file.%0
'//
%NS_E_FILE_WRITE                  = &HC00D0018&

'//
'// MessageId: NS_E_FILE_READ
'//
'// MessageText:
'//
'// Error reading from a file.%0
'//
%NS_E_FILE_READ                   = &HC00D0019&

'//
'// MessageId: NS_E_FILE_NOT_FOUND
'//
'// MessageText:
'//
'// The system cannot find the file specified.%0
'//
%NS_E_FILE_NOT_FOUND              = &HC00D001A&

'//
'// MessageId: NS_E_FILE_EXISTS
'//
'// MessageText:
'//
'// The file already exists.%0
'//
%NS_E_FILE_EXISTS                 = &HC00D001B&

'//
'// MessageId: NS_E_INVALID_NAME
'//
'// MessageText:
'//
'// The file name, directory name, or volume label syntax is incorrect.%0
'//
%NS_E_INVALID_NAME                = &HC00D001C&

'//
'// MessageId: NS_E_FILE_OPEN_FAILED
'//
'// MessageText:
'//
'// Failed to open a file.%0
'//
%NS_E_FILE_OPEN_FAILED            = &HC00D001D&

'//
'// MessageId: NS_E_FILE_ALLOCATION_FAILED
'//
'// MessageText:
'//
'// Unable to allocate a file.%0
'//
%NS_E_FILE_ALLOCATION_FAILED      = &HC00D001E&

'//
'// MessageId: NS_E_FILE_INIT_FAILED
'//
'// MessageText:
'//
'// Unable to initialize a file.%0
'//
%NS_E_FILE_INIT_FAILED            = &HC00D001F&

'//
'// MessageId: NS_E_FILE_PLAY_FAILED
'//
'// MessageText:
'//
'// Unable to play a file.%0
'//
%NS_E_FILE_PLAY_FAILED            = &HC00D0020&

'//
'// MessageId: NS_E_SET_DISK_UID_FAILED
'//
'// MessageText:
'//
'// Could not set the disk UID.%0
'//
%NS_E_SET_DISK_UID_FAILED         = &HC00D0021&

'//
'// MessageId: NS_E_INDUCED
'//
'// MessageText:
'//
'// An error was induced for testing purposes.%0
'//
%NS_E_INDUCED                     = &HC00D0022&

'//
'// MessageId: NS_E_CCLINK_DOWN
'//
'// MessageText:
'//
'// Two Content Servers failed to communicate.%0
'//
%NS_E_CCLINK_DOWN                 = &HC00D0023&

'//
'// MessageId: NS_E_INTERNAL
'//
'// MessageText:
'//
'// An unknown error occurred.%0
'//
%NS_E_INTERNAL                    = &HC00D0024&

'//
'// MessageId: NS_E_BUSY
'//
'// MessageText:
'//
'// The requested resource is in use.%0
'//
%NS_E_BUSY                        = &HC00D0025&

'//
'// MessageId: NS_E_UNRECOGNIZED_STREAM_TYPE
'//
'// MessageText:
'//
'// The specified protocol is not recognized. Be sure that the file name and syntax, such as slashes, are correct for the protocol.%0
'//
%NS_E_UNRECOGNIZED_STREAM_TYPE    = &HC00D0026&

'//
'// MessageId: NS_E_NETWORK_SERVICE_FAILURE
'//
'// MessageText:
'//
'// The network service provider failed.%0
'//
%NS_E_NETWORK_SERVICE_FAILURE     = &HC00D0027&

'//
'// MessageId: NS_E_NETWORK_RESOURCE_FAILURE
'//
'// MessageText:
'//
'// An attempt to acquire a network resource failed.%0
'//
%NS_E_NETWORK_RESOURCE_FAILURE    = &HC00D0028&

'//
'// MessageId: NS_E_CONNECTION_FAILURE
'//
'// MessageText:
'//
'// The network connection has failed.%0
'//
%NS_E_CONNECTION_FAILURE          = &HC00D0029&

'//
'// MessageId: NS_E_SHUTDOWN
'//
'// MessageText:
'//
'// The session is being terminated locally.%0
'//
%NS_E_SHUTDOWN                    = &HC00D002A&

'//
'// MessageId: NS_E_INVALID_REQUEST
'//
'// MessageText:
'//
'// The request is invalid in the current state.%0
'//
%NS_E_INVALID_REQUEST             = &HC00D002B&

'//
'// MessageId: NS_E_INSUFFICIENT_BANDWIDTH
'//
'// MessageText:
'//
'// There is insufficient bandwidth available to fulfill the request.%0
'//
%NS_E_INSUFFICIENT_BANDWIDTH      = &HC00D002C&

'//
'// MessageId: NS_E_NOT_REBUILDING
'//
'// MessageText:
'//
'// The disk is not rebuilding.%0
'//
%NS_E_NOT_REBUILDING              = &HC00D002D&

'//
'// MessageId: NS_E_LATE_OPERATION
'//
'// MessageText:
'//
'// An operation requested for a particular time could not be carried out on schedule.%0
'//
%NS_E_LATE_OPERATION              = &HC00D002E&

'//
'// MessageId: NS_E_INVALID_DATA
'//
'// MessageText:
'//
'// Invalid or corrupt data was encountered.%0
'//
%NS_E_INVALID_DATA                = &HC00D002F&

'//
'// MessageId: NS_E_FILE_BANDWIDTH_LIMIT
'//
'// MessageText:
'//
'// The bandwidth required to stream a file is higher than the maximum file bandwidth allowed on the server.%0
'//
%NS_E_FILE_BANDWIDTH_LIMIT        = &HC00D0030&

'//
'// MessageId: NS_E_OPEN_FILE_LIMIT
'//
'// MessageText:
'//
'// The client cannot have any more files open simultaneously.%0
'//
%NS_E_OPEN_FILE_LIMIT             = &HC00D0031&

'//
'// MessageId: NS_E_BAD_CONTROL_DATA
'//
'// MessageText:
'//
'// The server received invalid data from the client on the control connection.%0
'//
%NS_E_BAD_CONTROL_DATA            = &HC00D0032&

'//
'// MessageId: NS_E_NO_STREAM
'//
'// MessageText:
'//
'// There is no stream available.%0
'//
%NS_E_NO_STREAM                   = &HC00D0033&

'//
'// MessageId: NS_E_STREAM_END
'//
'// MessageText:
'//
'// There is no more data in the stream.%0
'//
%NS_E_STREAM_END                  = &HC00D0034&

'//
'// MessageId: NS_E_SERVER_NOT_FOUND
'//
'// MessageText:
'//
'// The specified server could not be found.%0
'//
%NS_E_SERVER_NOT_FOUND            = &HC00D0035&

'//
'// MessageId: NS_E_DUPLICATE_NAME
'//
'// MessageText:
'//
'// The specified name is already in use.
'//
%NS_E_DUPLICATE_NAME              = &HC00D0036&

'//
'// MessageId: NS_E_DUPLICATE_ADDRESS
'//
'// MessageText:
'//
'// The specified address is already in use.
'//
%NS_E_DUPLICATE_ADDRESS           = &HC00D0037&

'//
'// MessageId: NS_E_BAD_MULTICAST_ADDRESS
'//
'// MessageText:
'//
'// The specified address is not a valid multicast address.
'//
%NS_E_BAD_MULTICAST_ADDRESS       = &HC00D0038&

'//
'// MessageId: NS_E_BAD_ADAPTER_ADDRESS
'//
'// MessageText:
'//
'// The specified adapter address is invalid.
'//
%NS_E_BAD_ADAPTER_ADDRESS         = &HC00D0039&

'//
'// MessageId: NS_E_BAD_DELIVERY_MODE
'//
'// MessageText:
'//
'// The specified delivery mode is invalid.
'//
%NS_E_BAD_DELIVERY_MODE           = &HC00D003A&

'//
'// MessageId: NS_E_INVALID_CHANNEL
'//
'// MessageText:
'//
'// The specified station does not exist.
'//
%NS_E_INVALID_CHANNEL             = &HC00D003B&

'//
'// MessageId: NS_E_INVALID_STREAM
'//
'// MessageText:
'//
'// The specified stream does not exist.
'//
%NS_E_INVALID_STREAM              = &HC00D003C&

'//
'// MessageId: NS_E_INVALID_ARCHIVE
'//
'// MessageText:
'//
'// The specified archive could not be opened.
'//
%NS_E_INVALID_ARCHIVE             = &HC00D003D&

'//
'// MessageId: NS_E_NOTITLES
'//
'// MessageText:
'//
'// The system cannot find any titles on the server.%0
'//
%NS_E_NOTITLES                    = &HC00D003E&

'//
'// MessageId: NS_E_INVALID_CLIENT
'//
'// MessageText:
'//
'// The system cannot find the client specified.%0
'//
%NS_E_INVALID_CLIENT              = &HC00D003F&

'//
'// MessageId: NS_E_INVALID_BLACKHOLE_ADDRESS
'//
'// MessageText:
'//
'// The Blackhole Address is not initialized.%0
'//
%NS_E_INVALID_BLACKHOLE_ADDRESS   = &HC00D0040&

'//
'// MessageId: NS_E_INCOMPATIBLE_FORMAT
'//
'// MessageText:
'//
'// The station does not support the stream format.
'//
%NS_E_INCOMPATIBLE_FORMAT         = &HC00D0041&

'//
'// MessageId: NS_E_INVALID_KEY
'//
'// MessageText:
'//
'// The specified key is not valid.
'//
%NS_E_INVALID_KEY                 = &HC00D0042&

'//
'// MessageId: NS_E_INVALID_PORT
'//
'// MessageText:
'//
'// The specified port is not valid.
'//
%NS_E_INVALID_PORT                = &HC00D0043&

'//
'// MessageId: NS_E_INVALID_TTL
'//
'// MessageText:
'//
'// The specified TTL is not valid.
'//
%NS_E_INVALID_TTL                 = &HC00D0044&

'//
'// MessageId: NS_E_STRIDE_REFUSED
'//
'// MessageText:
'//
'// The request to fast forward or rewind could not be fulfilled.
'//
%NS_E_STRIDE_REFUSED              = &HC00D0045&

'//
'// IMmsAutoServer Errors
'//
'//
'// MessageId: NS_E_MMSAUTOSERVER_CANTFINDWALKER
'//
'// MessageText:
'//
'// Unable to load the appropriate file parser.%0
'//
%NS_E_MMSAUTOSERVER_CANTFINDWALKER = &HC00D0046&

'//
'// MessageId: NS_E_MAX_BITRATE
'//
'// MessageText:
'//
'// Cannot exceed the maximum bandwidth limit.%0
'//
%NS_E_MAX_BITRATE                 = &HC00D0047&

'//
'// MessageId: NS_E_LOGFILEPERIOD
'//
'// MessageText:
'//
'// Invalid value for LogFilePeriod.%0
'//
%NS_E_LOGFILEPERIOD               = &HC00D0048&

'//
'// MessageId: NS_E_MAX_CLIENTS
'//
'// MessageText:
'//
'// Cannot exceed the maximum client limit.%0
'//
'//
%NS_E_MAX_CLIENTS                 = &HC00D0049&

'//
'// MessageId: NS_E_LOG_FILE_SIZE
'//
'// MessageText:
'//
'// The maximum log file size has been reached.%0
'//
'//
%NS_E_LOG_FILE_SIZE               = &HC00D004A&

'//
'// MessageId: NS_E_MAX_FILERATE
'//
'// MessageText:
'//
'// Cannot exceed the maximum file rate.%0
'//
%NS_E_MAX_FILERATE                = &HC00D004B&

'//
'// File Walker Errors
'//
'//
'// MessageId: NS_E_WALKER_UNKNOWN
'//
'// MessageText:
'//
'// Unknown file type.%0
'//
%NS_E_WALKER_UNKNOWN              = &HC00D004C&

'//
'// MessageId: NS_E_WALKER_SERVER
'//
'// MessageText:
'//
'// The specified file, %1, cannot be loaded onto the specified server, %2.%0
'//
%NS_E_WALKER_SERVER               = &HC00D004D&

'//
'// MessageId: NS_E_WALKER_USAGE
'//
'// MessageText:
'//
'// There was a usage error with file parser.%0
'//
%NS_E_WALKER_USAGE                = &HC00D004E&


'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Monitor Events
'//
'/////////////////////////////////////////////////////////////////////////


 '// Tiger Events

 '// %1 is the tiger name

'//
'// MessageId: NS_I_TIGER_START
'//
'// MessageText:
'//
'// The Title Server %1 is running.%0
'//
%NS_I_TIGER_START                 = &H400D004F&

'//
'// MessageId: NS_E_TIGER_FAIL
'//
'// MessageText:
'//
'// The Title Server %1 has failed.%0
'//
%NS_E_TIGER_FAIL                  = &HC00D0050&


 '// Cub Events

 '// %1 is the cub ID
 '// %2 is the cub name

'//
'// MessageId: NS_I_CUB_START
'//
'// MessageText:
'//
'// Content Server %1 (%2) is starting.%0
'//
%NS_I_CUB_START                   = &H400D0051&

'//
'// MessageId: NS_I_CUB_RUNNING
'//
'// MessageText:
'//
'// Content Server %1 (%2) is running.%0
'//
%NS_I_CUB_RUNNING                 = &H400D0052&

'//
'// MessageId: NS_E_CUB_FAIL
'//
'// MessageText:
'//
'// Content Server %1 (%2) has failed.%0
'//
%NS_E_CUB_FAIL                    = &HC00D0053&


 '// Disk Events

 '// %1 is the tiger disk ID
 '// %2 is the device name
 '// %3 is the cub ID
'//
'// MessageId: NS_I_DISK_START
'//
'// MessageText:
'//
'// Disk %1 ( %2 ) on Content Server %3, is running.%0
'//
%NS_I_DISK_START                  = &H400D0054&

'//
'// MessageId: NS_E_DISK_FAIL
'//
'// MessageText:
'//
'// Disk %1 ( %2 ) on Content Server %3, has failed.%0
'//
%NS_E_DISK_FAIL                   = &HC00D0055&

'//
'// MessageId: NS_I_DISK_REBUILD_STARTED
'//
'// MessageText:
'//
'// Started rebuilding disk %1 ( %2 ) on Content Server %3.%0
'//
%NS_I_DISK_REBUILD_STARTED        = &H400D0056&

'//
'// MessageId: NS_I_DISK_REBUILD_FINISHED
'//
'// MessageText:
'//
'// Finished rebuilding disk %1 ( %2 ) on Content Server %3.%0
'//
%NS_I_DISK_REBUILD_FINISHED       = &H400D0057&

'//
'// MessageId: NS_I_DISK_REBUILD_ABORTED
'//
'// MessageText:
'//
'// Aborted rebuilding disk %1 ( %2 ) on Content Server %3.%0
'//
%NS_I_DISK_REBUILD_ABORTED        = &H400D0058&


 '// Admin Events

'//
'// MessageId: NS_I_LIMIT_FUNNELS
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 set the data stream limit to %2 streams.%0
'//
%NS_I_LIMIT_FUNNELS               = &H400D0059&

'//
'// MessageId: NS_I_START_DISK
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 started disk %2.%0
'//
%NS_I_START_DISK                  = &H400D005A&

'//
'// MessageId: NS_I_STOP_DISK
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 stopped disk %2.%0
'//
%NS_I_STOP_DISK                   = &H400D005B&

'//
'// MessageId: NS_I_STOP_CUB
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 stopped Content Server %2.%0
'//
%NS_I_STOP_CUB                    = &H400D005C&

'//
'// MessageId: NS_I_KILL_USERSESSION
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 aborted user session %2 from the system.%0
'//
%NS_I_KILL_USERSESSION            = &H400D005D&

'//
'// MessageId: NS_I_KILL_CONNECTION
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 aborted obsolete connection %2 from the system.%0
'//
%NS_I_KILL_CONNECTION             = &H400D005E&

'//
'// MessageId: NS_I_REBUILD_DISK
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 started rebuilding disk %2.%0
'//
%NS_I_REBUILD_DISK                = &H400D005F&

'//
'// MessageId: NS_W_UNKNOWN_EVENT
'//
'// MessageText:
'//
'// Unknown %1 event encountered.%0
'//
%NS_W_UNKNOWN_EVENT               = &H800D0060&


 '// Alerts

'//
'// MessageId: NS_E_MAX_FUNNELS_ALERT
'//
'// MessageText:
'//
'// The NetShow data stream limit of %1 streams was reached.%0
'//
%NS_E_MAX_FUNNELS_ALERT           = &HC00D0060&

'//
'// MessageId: NS_E_ALLOCATE_FILE_FAIL
'//
'// MessageText:
'//
'// The NetShow Video Server was unable to allocate a %1 block file named %2.%0
'//
%NS_E_ALLOCATE_FILE_FAIL          = &HC00D0061&

'//
'// MessageId: NS_E_PAGING_ERROR
'//
'// MessageText:
'//
'// A Content Server was unable to page a block.%0
'//
%NS_E_PAGING_ERROR                = &HC00D0062&

'//
'// MessageId: NS_E_BAD_BLOCK0_VERSION
'//
'// MessageText:
'//
'// Disk %1 has unrecognized control block version %2.%0
'//
%NS_E_BAD_BLOCK0_VERSION          = &HC00D0063&

'//
'// MessageId: NS_E_BAD_DISK_UID
'//
'// MessageText:
'//
'// Disk %1 has incorrect uid %2.%0
'//
%NS_E_BAD_DISK_UID                = &HC00D0064&

'//
'// MessageId: NS_E_BAD_FSMAJOR_VERSION
'//
'// MessageText:
'//
'// Disk %1 has unsupported file system major version %2.%0
'//
%NS_E_BAD_FSMAJOR_VERSION         = &HC00D0065&

'//
'// MessageId: NS_E_BAD_STAMPNUMBER
'//
'// MessageText:
'//
'// Disk %1 has bad stamp number in control block.%0
'//
%NS_E_BAD_STAMPNUMBER             = &HC00D0066&

'//
'// MessageId: NS_E_PARTIALLY_REBUILT_DISK
'//
'// MessageText:
'//
'// Disk %1 is partially reconstructed.%0
'//
%NS_E_PARTIALLY_REBUILT_DISK      = &HC00D0067&

'//
'// MessageId: NS_E_ENACTPLAN_GIVEUP
'//
'// MessageText:
'//
'// EnactPlan gives up.%0
'//
%NS_E_ENACTPLAN_GIVEUP            = &HC00D0068&


 '// MCMADM warnings/errors

'//
'// MessageId: MCMADM_I_NO_EVENTS
'//
'// MessageText:
'//
'// Event initialization failed, there will be no MCM events.%0
'//
%MCMADM_I_NO_EVENTS               = &H400D0069&

'//
'// MessageId: MCMADM_E_REGKEY_NOT_FOUND
'//
'// MessageText:
'//
'// The key was not found in the registry.%0
'//
%MCMADM_E_REGKEY_NOT_FOUND        = &HC00D006A&

'//
'// MessageId: NS_E_NO_FORMATS
'//
'// MessageText:
'//
'// The publishing point cannot be started because the server does not have the appropriate stream formats. Use the Multicast Announcement Wizard to create a new announcement for this publishing point.%0
'//
%NS_E_NO_FORMATS                  = &HC00D006B&

'//
'// MessageId: NS_E_NO_REFERENCES
'//
'// MessageText:
'//
'// No reference URLs were found in an ASX file.%0
'//
%NS_E_NO_REFERENCES               = &HC00D006C&

'//
'// MessageId: NS_E_WAVE_OPEN
'//
'// MessageText:
'//
'// Error opening wave device, the device might be in use.%0
'//
%NS_E_WAVE_OPEN                   = &HC00D006D&

'//
'// MessageId: NS_I_LOGGING_FAILED
'//
'// MessageText:
'//
'// The logging operation failed.
'//
%NS_I_LOGGING_FAILED              = &H400D006E&

'//
'// MessageId: NS_E_CANNOTCONNECTEVENTS
'//
'// MessageText:
'//
'// Unable to establish a connection to the NetShow event monitor service.%0
'//
%NS_E_CANNOTCONNECTEVENTS         = &HC00D006F&

'//
'// MessageId: NS_I_LIMIT_BANDWIDTH
'//
'// MessageText:
'//
'// A NetShow administrator at network location %1 set the maximum bandwidth limit to %2 bps.%0
'//
%NS_I_LIMIT_BANDWIDTH             = &H400D0070&

'//
'// MessageId: NS_E_NO_DEVICE
'//
'// MessageText:
'//
'// No device driver is present on the system.%0
'//
%NS_E_NO_DEVICE                   = &HC00D0071&

'//
'// MessageId: NS_E_NO_SPECIFIED_DEVICE
'//
'// MessageText:
'//
'// No specified device driver is present.%0
'//
%NS_E_NO_SPECIFIED_DEVICE         = &HC00D0072&


'// NOTENOTE!!!
'//
'// Due to legacy problems these error codes live inside the ASF error code range
'//
'//
'// MessageId: NS_E_NOTHING_TO_DO
'//
'// MessageText:
'//
'//  NS_E_NOTHING_TO_DO
'//
%NS_E_NOTHING_TO_DO               = &HC00D07F1&

'//
'// MessageId: NS_E_NO_MULTICAST
'//
'// MessageText:
'//
'// Not receiving data from the server.%0
'//
%NS_E_NO_MULTICAST                = &HC00D07F2&


'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Error Events
'//
'// IdRange = 200..399
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_MONITOR_GIVEUP
'//
'// MessageText:
'//
'// Netshow Events Monitor is not operational and has been disconnected.%0
'//
%NS_E_MONITOR_GIVEUP              = &HC00D00C8&

'//
'// MessageId: NS_E_REMIRRORED_DISK
'//
'// MessageText:
'//
'// Disk %1 is remirrored.%0
'//
%NS_E_REMIRRORED_DISK             = &HC00D00C9&

'//
'// MessageId: NS_E_INSUFFICIENT_DATA
'//
'// MessageText:
'//
'// Insufficient data found.%0
'//
%NS_E_INSUFFICIENT_DATA           = &HC00D00CA&

'//
'// MessageId: NS_E_ASSERT
'//
'// MessageText:
'//
'// %1 failed in file %2 line %3.%0
'//
%NS_E_ASSERT                      = &HC00D00CB&

'//
'// MessageId: NS_E_BAD_ADAPTER_NAME
'//
'// MessageText:
'//
'// The specified adapter name is invalid.%0
'//
%NS_E_BAD_ADAPTER_NAME            = &HC00D00CC&

'//
'// MessageId: NS_E_NOT_LICENSED
'//
'// MessageText:
'//
'// The application is not licensed for this feature.%0
'//
%NS_E_NOT_LICENSED                = &HC00D00CD&

'//
'// MessageId: NS_E_NO_SERVER_CONTACT
'//
'// MessageText:
'//
'// Unable to contact the server.%0
'//
%NS_E_NO_SERVER_CONTACT           = &HC00D00CE&

'//
'// MessageId: NS_E_TOO_MANY_TITLES
'//
'// MessageText:
'//
'// Maximum number of titles exceeded.%0
'//
%NS_E_TOO_MANY_TITLES             = &HC00D00CF&

'//
'// MessageId: NS_E_TITLE_SIZE_EXCEEDED
'//
'// MessageText:
'//
'// Maximum size of a title exceeded.%0
'//
%NS_E_TITLE_SIZE_EXCEEDED         = &HC00D00D0&

'//
'// MessageId: NS_E_UDP_DISABLED
'//
'// MessageText:
'//
'// UDP protocol not enabled. Not trying %1!ls!.%0
'//
%NS_E_UDP_DISABLED                = &HC00D00D1&

'//
'// MessageId: NS_E_TCP_DISABLED
'//
'// MessageText:
'//
'// TCP protocol not enabled. Not trying %1!ls!.%0
'//
%NS_E_TCP_DISABLED                = &HC00D00D2&

'//
'// MessageId: NS_E_HTTP_DISABLED
'//
'// MessageText:
'//
'// HTTP protocol not enabled. Not trying %1!ls!.%0
'//
%NS_E_HTTP_DISABLED               = &HC00D00D3&

'//
'// MessageId: NS_E_LICENSE_EXPIRED
'//
'// MessageText:
'//
'// The product license has expired.%0
'//
%NS_E_LICENSE_EXPIRED             = &HC00D00D4&

'//
'// MessageId: NS_E_TITLE_BITRATE
'//
'// MessageText:
'//
'// Source file exceeds the per title maximum bitrate. See NetShow Theater documentation for more information.%0
'//
%NS_E_TITLE_BITRATE               = &HC00D00D5&

'//
'// MessageId: NS_E_EMPTY_PROGRAM_NAME
'//
'// MessageText:
'//
'// The program name cannot be empty.%0
'//
%NS_E_EMPTY_PROGRAM_NAME          = &HC00D00D6&

'//
'// MessageId: NS_E_MISSING_CHANNEL
'//
'// MessageText:
'//
'// Station %1 does not exist.%0
'//
%NS_E_MISSING_CHANNEL             = &HC00D00D7&

'//
'// MessageId: NS_E_NO_CHANNELS
'//
'// MessageText:
'//
'// You need to define at least one station before this operation can complete.%0
'//
%NS_E_NO_CHANNELS                 = &HC00D00D8&


'/////////////////////////////////////////////////////////////////////
'// This error message is to replace previous NS_E_INVALID_INDEX which
'// takes an index value for the error message string.  For some application
'// obtain the idex value at reporting error time is very difficult, so we
'// use this string to avoid the problem.
'//////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_INVALID_INDEX2
'//
'// MessageText:
'//
'// The index specified is invalid.%0
'//
%NS_E_INVALID_INDEX2              = &HC00D00D9&


'/////////////////////////////////////////////////////////////////////////
'//
'// NETSHOW Monitor Events
'//
'// IdRange = 400..599
'//
'// Admin Events:
'//
'// Alerts:
'//
'// Title Server:
'//      %1 is the Title Server name
'//
'// Content Server:
'//      %1 is the Content Server ID
'//      %2 is the Content Server name
'//      %3 is the Peer Content Server name (optiona&
'//
'// Disks:
'//      %1 is the Title Server disk ID
'//      %2 is the device name
'//      %3 is the Content Server ID
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_CUB_FAIL_LINK
'//
'// MessageText:
'//
'// Content Server %1 (%2) has failed its link to Content Server %3.%0
'//
%NS_E_CUB_FAIL_LINK               = &HC00D0190&

'//
'// MessageId: NS_I_CUB_UNFAIL_LINK
'//
'// MessageText:
'//
'// Content Server %1 (%2) has established its link to Content Server %3.%0
'//
%NS_I_CUB_UNFAIL_LINK             = &H400D0191&

'//
'// MessageId: NS_E_BAD_CUB_UID
'//
'// MessageText:
'//
'// Content Server %1 (%2) has incorrect uid %3.%0
'//
%NS_E_BAD_CUB_UID                 = &HC00D0192&

'//
'// MessageId: NS_I_RESTRIPE_START
'//
'// MessageText:
'//
'// Restripe operation has started.%0
'//
%NS_I_RESTRIPE_START              = &H400D0193&

'//
'// MessageId: NS_I_RESTRIPE_DONE
'//
'// MessageText:
'//
'// Restripe operation has completed.%0
'//
%NS_I_RESTRIPE_DONE               = &H400D0194&

'//
'// MessageId: NS_E_GLITCH_MODE
'//
'// MessageText:
'//
'// Server unreliable because multiple components failed.%0
'//
%NS_E_GLITCH_MODE                 = &HC00D0195&

'//
'// MessageId: NS_I_RESTRIPE_DISK_OUT
'//
'// MessageText:
'//
'// Content disk %1 (%2) on Content Server %3 has been restriped out.%0
'//
%NS_I_RESTRIPE_DISK_OUT           = &H400D0196&

'//
'// MessageId: NS_I_RESTRIPE_CUB_OUT
'//
'// MessageText:
'//
'// Content server %1 (%2) has been restriped out.%0
'//
%NS_I_RESTRIPE_CUB_OUT            = &H400D0197&

'//
'// MessageId: NS_I_DISK_STOP
'//
'// MessageText:
'//
'// Disk %1 ( %2 ) on Content Server %3, has been offlined.%0
'//
%NS_I_DISK_STOP                   = &H400D0198&

'//
'// MessageId: NS_I_CATATONIC_FAILURE
'//
'// MessageText:
'//
'// Disk %1 ( %2 ) on Content Server %3, will be failed because it is catatonic.%0
'//
%NS_I_CATATONIC_FAILURE           = &H800D0199&

'//
'// MessageId: NS_I_CATATONIC_AUTO_UNFAIL
'//
'// MessageText:
'//
'// Disk %1 ( %2 ) on Content Server %3, auto online from catatonic state.%0
'//
%NS_I_CATATONIC_AUTO_UNFAIL       = &H800D019A&

'//
'// MessageId: NS_E_NO_MEDIA_PROTOCOL
'//
'// MessageText:
'//
'// Content Server %1 (%2) is unable to communicate with the Media System Network Protocol.%0
'//
%NS_E_NO_MEDIA_PROTOCOL           = &HC00D019B&


'//
'// Advanced Streaming Format (ASF) codes occupy MessageIds 2000-2999
'//
'// See ASFErr.mc for more details - please do not define any symbols
'// in that range in this file.
'//


'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media SDK Errors
'//
'// IdRange = 3000-3199
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_INVALID_INPUT_FORMAT
'//
'// MessageText:
'//
'// The input media format is invalid.%0
'//
%NS_E_INVALID_INPUT_FORMAT        = &HC00D0BB8&

'//
'// MessageId: NS_E_MSAUDIO_NOT_INSTALLED
'//
'// MessageText:
'//
'// The MSAudio codec is not installed on this system.%0
'//
%NS_E_MSAUDIO_NOT_INSTALLED       = &HC00D0BB9&

'//
'// MessageId: NS_E_UNEXPECTED_MSAUDIO_ERROR
'//
'// MessageText:
'//
'// An unexpected error occurred with the MSAudio codec.%0
'//
%NS_E_UNEXPECTED_MSAUDIO_ERROR    = &HC00D0BBA&

'//
'// MessageId: NS_E_INVALID_OUTPUT_FORMAT
'//
'// MessageText:
'//
'// The output media format is invalid.%0
'//
%NS_E_INVALID_OUTPUT_FORMAT       = &HC00D0BBB&

'//
'// MessageId: NS_E_NOT_CONFIGURED
'//
'// MessageText:
'//
'// The object must be fully configured before audio samples can be processed.%0
'//
%NS_E_NOT_CONFIGURED              = &HC00D0BBC&

'//
'// MessageId: NS_E_PROTECTED_CONTENT
'//
'// MessageText:
'//
'// You need a license to perform the requested operation on this media file.%0
'//
%NS_E_PROTECTED_CONTENT           = &HC00D0BBD&

'//
'// MessageId: NS_E_LICENSE_REQUIRED
'//
'// MessageText:
'//
'// You need a license to perform the requested operation on this media file.%0
'//
%NS_E_LICENSE_REQUIRED            = &HC00D0BBE&

'//
'// MessageId: NS_E_TAMPERED_CONTENT
'//
'// MessageText:
'//
'// This media file is corrupted or invalid. Contact the content provider for a new file.%0
'//
%NS_E_TAMPERED_CONTENT            = &HC00D0BBF&

'//
'// MessageId: NS_E_LICENSE_OUTOFDATE
'//
'// MessageText:
'//
'// The license for this media file has expired. Get a new license or contact the content provider for further assistance.%0
'//
%NS_E_LICENSE_OUTOFDATE           = &HC00D0BC0&

'//
'// MessageId: NS_E_LICENSE_INCORRECT_RIGHTS
'//
'// MessageText:
'//
'// You are not allowed to open this file. Contact the content provider for further assistance.%0
'//
%NS_E_LICENSE_INCORRECT_RIGHTS    = &HC00D0BC1&

'//
'// MessageId: NS_E_AUDIO_CODEC_NOT_INSTALLED
'//
'// MessageText:
'//
'// The requested audio codec is not installed on this system.%0
'//
%NS_E_AUDIO_CODEC_NOT_INSTALLED   = &HC00D0BC2&

'//
'// MessageId: NS_E_AUDIO_CODEC_ERROR
'//
'// MessageText:
'//
'// An unexpected error occurred with the audio codec.%0
'//
%NS_E_AUDIO_CODEC_ERROR           = &HC00D0BC3&

'//
'// MessageId: NS_E_VIDEO_CODEC_NOT_INSTALLED
'//
'// MessageText:
'//
'// The requested video codec is not installed on this system.%0
'//
%NS_E_VIDEO_CODEC_NOT_INSTALLED   = &HC00D0BC4&

'//
'// MessageId: NS_E_VIDEO_CODEC_ERROR
'//
'// MessageText:
'//
'// An unexpected error occurred with the video codec.%0
'//
%NS_E_VIDEO_CODEC_ERROR           = &HC00D0BC5&

'//
'// MessageId: NS_E_INVALIDPROFILE
'//
'// MessageText:
'//
'// The Profile is invalid.%0
'//
%NS_E_INVALIDPROFILE              = &HC00D0BC6&

'//
'// MessageId: NS_E_INCOMPATIBLE_VERSION
'//
'// MessageText:
'//
'// A new version of the SDK is needed to play the requested content.%0
'//
%NS_E_INCOMPATIBLE_VERSION        = &HC00D0BC7&

'//
'// MessageId: NS_S_REBUFFERING
'//
'// MessageText:
'//
'// The requested operation has caused the source to rebuffer.%0
'//
%NS_S_REBUFFERING                 = &H000D0BC8&

'//
'// MessageId: NS_S_DEGRADING_QUALITY
'//
'// MessageText:
'//
'// The requested operation has caused the source to degrade codec quality.%0
'//
%NS_S_DEGRADING_QUALITY           = &H000D0BC9&

'//
'// MessageId: NS_E_OFFLINE_MODE
'//
'// MessageText:
'//
'// The requested URL is not available in offline mode.%0
'//
%NS_E_OFFLINE_MODE                = &HC00D0BCA&

'//
'// MessageId: NS_E_NOT_CONNECTED
'//
'// MessageText:
'//
'// The requested URL cannot be accessed because there is no network connection.%0
'//
%NS_E_NOT_CONNECTED               = &HC00D0BCB&

'//
'// MessageId: NS_E_TOO_MUCH_DATA
'//
'// MessageText:
'//
'// The encoding process was unable to keep up with the amount of supplied data.%0
'//
%NS_E_TOO_MUCH_DATA               = &HC00D0BCC&

'//
'// MessageId: NS_E_UNSUPPORTED_PROPERTY
'//
'// MessageText:
'//
'// The given property is not supported.%0
'//
%NS_E_UNSUPPORTED_PROPERTY        = &HC00D0BCD&

'//
'// MessageId: NS_E_8BIT_WAVE_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player cannot copy the files to the CD because they are 8-bit. Convert the files to 16-bit, 44-kHz stereo files by using Sound Recorder or another audio-processing program, and then try again.%0
'//
%NS_E_8BIT_WAVE_UNSUPPORTED       = &HC00D0BCE&

'//
'// MessageId: NS_E_NO_MORE_SAMPLES
'//
'// MessageText:
'//
'// There are no more samples in the current range.%0
'//
%NS_E_NO_MORE_SAMPLES             = &HC00D0BCF&

'//
'// MessageId: NS_E_INVALID_SAMPLING_RATE
'//
'// MessageText:
'//
'// The given sampling rate is invalid.%0
'//
%NS_E_INVALID_SAMPLING_RATE       = &HC00D0BD0&

'//
'// MessageId: NS_E_MAX_PACKET_SIZE_TOO_SMALL
'//
'// MessageText:
'//
'// The given maximum packet size is too small to accommodate this profile
'//
%NS_E_MAX_PACKET_SIZE_TOO_SMALL   = &HC00D0BD1&

'//
'// MessageId: NS_E_LATE_PACKET
'//
'// MessageText:
'//
'// The packet arrived too late to be of use
'//
%NS_E_LATE_PACKET                 = &HC00D0BD2&

'//
'// MessageId: NS_E_DUPLICATE_PACKET
'//
'// MessageText:
'//
'// The packet is a duplicate of one received before
'//
%NS_E_DUPLICATE_PACKET            = &HC00D0BD3&

'//
'// MessageId: NS_E_SDK_BUFFERTOOSMALL
'//
'// MessageText:
'//
'// Supplied buffer is too small
'//
%NS_E_SDK_BUFFERTOOSMALL          = &HC00D0BD4&

'//
'// MessageId: NS_E_INVALID_NUM_PASSES
'//
'// MessageText:
'//
'// The wrong number of preprocessing passes was used for the stream's output type
'//
%NS_E_INVALID_NUM_PASSES          = &HC00D0BD5&

'//
'// MessageId: NS_E_ATTRIBUTE_READ_ONLY
'//
'// MessageText:
'//
'// An attempt was made to add, modify, or delete a read only attribute
'//
%NS_E_ATTRIBUTE_READ_ONLY         = &HC00D0BD6&

'//
'// MessageId: NS_E_ATTRIBUTE_NOT_ALLOWED
'//
'// MessageText:
'//
'// An attempt was made to add attribute that is not allowed for the given media type
'//
%NS_E_ATTRIBUTE_NOT_ALLOWED       = &HC00D0BD7&

'//
'// MessageId: NS_E_INVALID_EDL
'//
'// MessageText:
'//
'// The EDL provided is invalid
'//
%NS_E_INVALID_EDL                 = &HC00D0BD8&

'//
'// MessageId: NS_E_DATA_UNIT_EXTENSION_TOO_LARGE
'//
'// MessageText:
'//
'// The Data Unit Extension data was too large to be used.%0
'//
%NS_E_DATA_UNIT_EXTENSION_TOO_LARGE = &HC00D0BD9&

'//
'// MessageId: NS_E_CODEC_DMO_ERROR
'//
'// MessageText:
'//
'// An unexpected error occurred with a DMO codec.%0
'//
%NS_E_CODEC_DMO_ERROR             = &HC00D0BDA&

'//
'// MessageId: NS_S_TRANSCRYPTOR_EOF
'//
'// MessageText:
'//
'// The transcryptor object has reached end of file.%0
'//
%NS_S_TRANSCRYPTOR_EOF            = &H000D0BDB&

'//
'// MessageId: NS_E_FEATURE_DISABLED_BY_GROUP_POLICY
'//
'// MessageText:
'//
'// This feature has been disabled by group policy.%0
'//
%NS_E_FEATURE_DISABLED_BY_GROUP_POLICY = &HC00D0BDC&

'//
'// MessageId: NS_E_FEATURE_DISABLED_IN_SKU
'//
'// MessageText:
'//
'// This feature is disabled in this SKU.%0
'//
%NS_E_FEATURE_DISABLED_IN_SKU     = &HC00D0BDD&



'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Player Errors
'//
'// IdRange = 4000 - 4999
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// WMP CD Filter Error codes
'//
'//
'// MessageId: NS_E_NO_CD
'//
'// MessageText:
'//
'// There is no CD in the CD drive. Insert a CD, and then try again.%0
'//
%NS_E_NO_CD                       = &HC00D0FA0&

'//
'// MessageId: NS_E_CANT_READ_DIGITAL
'//
'// MessageText:
'//
'// Windows Media Player could not use digital playback to play the CD.
'// To switch to analog playback, Click Organize, click Options, and then click the Devices tab. Double-click the CD drive, and then in the Playback area, click Analog.%0
'//
%NS_E_CANT_READ_DIGITAL           = &HC00D0FA1&

'//
'// MessageId: NS_E_DEVICE_DISCONNECTED
'//
'// MessageText:
'//
'// Windows Media Player no longer detects a connected portable device. Reconnect your portable device, and then try syncing the file again.%0
'//
%NS_E_DEVICE_DISCONNECTED         = &HC00D0FA2&

'//
'// MessageId: NS_E_DEVICE_NOT_SUPPORT_FORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The portable device does not support the specified file type.%0
'//
%NS_E_DEVICE_NOT_SUPPORT_FORMAT   = &HC00D0FA3&

'//
'// MessageId: NS_E_SLOW_READ_DIGITAL
'//
'// MessageText:
'//
'// Windows Media Player could not use digital playback to play the CD. The Player has automatically switched the CD drive to analog playback. To switch back to digital CD playback, click Organize, click Options, and then use the Devices tab.%0
'//
%NS_E_SLOW_READ_DIGITAL           = &HC00D0FA4&

'//
'// MessageId: NS_E_MIXER_INVALID_LINE
'//
'// MessageText:
'//
'// An invalid line error occurred in the mixer.%0
'//
%NS_E_MIXER_INVALID_LINE          = &HC00D0FA5&

'//
'// MessageId: NS_E_MIXER_INVALID_CONTROL
'//
'// MessageText:
'//
'// An invalid control error occurred in the mixer.%0
'//
%NS_E_MIXER_INVALID_CONTROL       = &HC00D0FA6&

'//
'// MessageId: NS_E_MIXER_INVALID_VALUE
'//
'// MessageText:
'//
'// An invalid value error occurred in the mixer.%0
'//
%NS_E_MIXER_INVALID_VALUE         = &HC00D0FA7&

'//
'// MessageId: NS_E_MIXER_UNKNOWN_MMRESULT
'//
'// MessageText:
'//
'// An unrecognized MMRESULT occurred in the mixer.%0
'//
%NS_E_MIXER_UNKNOWN_MMRESULT      = &HC00D0FA8&

'//
'// MessageId: NS_E_USER_STOP
'//
'// MessageText:
'//
'// User has stopped the operation.%0
'//
%NS_E_USER_STOP                   = &HC00D0FA9&

'//
'// MessageId: NS_E_MP3_FORMAT_NOT_FOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot rip the track because a compatible MP3 encoder is not installed on your computer. Install a compatible MP3 encoder or choose a different format to rip to (such as Windows Media Audio).%0
'//
%NS_E_MP3_FORMAT_NOT_FOUND        = &HC00D0FAA&

'//
'// MessageId: NS_E_CD_READ_ERROR_NO_CORRECTION
'//
'// MessageText:
'//
'// Windows Media Player cannot read the CD. The disc might be dirty or damaged. Turn on error correction, and then try again.%0
'//
%NS_E_CD_READ_ERROR_NO_CORRECTION = &HC00D0FAB&

'//
'// MessageId: NS_E_CD_READ_ERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot read the CD. The disc might be dirty or damaged or the CD drive might be malfunctioning.%0
'//
%NS_E_CD_READ_ERROR               = &HC00D0FAC&

'//
'// MessageId: NS_E_CD_SLOW_COPY
'//
'// MessageText:
'//
'// For best performance, do not play CD tracks while ripping them.%0
'//
%NS_E_CD_SLOW_COPY                = &HC00D0FAD&

'//
'// MessageId: NS_E_CD_COPYTO_CD
'//
'// MessageText:
'//
'// It is not possible to directly burn tracks from one CD to another CD. You must first rip the tracks from the CD to your computer, and then burn the files to a blank CD.%0
'//
%NS_E_CD_COPYTO_CD                = &HC00D0FAE&

'//
'// MessageId: NS_E_MIXER_NODRIVER
'//
'// MessageText:
'//
'// Could not open a sound mixer driver.%0
'//
%NS_E_MIXER_NODRIVER              = &HC00D0FAF&

'//
'// MessageId: NS_E_REDBOOK_ENABLED_WHILE_COPYING
'//
'// MessageText:
'//
'// Windows Media Player cannot rip tracks from the CD correctly because the CD drive settings in Device Manager do not match the CD drive settings in the Player.%0
'//
%NS_E_REDBOOK_ENABLED_WHILE_COPYING = &HC00D0FB0&

'//
'// MessageId: NS_E_CD_REFRESH
'//
'// MessageText:
'//
'// Windows Media Player is busy reading the CD.%0
'//
%NS_E_CD_REFRESH                  = &HC00D0FB1&

'//
'// MessageId: NS_E_CD_DRIVER_PROBLEM
'//
'// MessageText:
'//
'// Windows Media Player could not use digital playback to play the CD. The Player has automatically switched the CD drive to analog playback. To switch back to digital CD playback, click Organize, click options, and use the Devices tab.%0
'//
%NS_E_CD_DRIVER_PROBLEM           = &HC00D0FB2&

'//
'// MessageId: NS_E_WONT_DO_DIGITAL
'//
'// MessageText:
'//
'// Windows Media Player could not use digital playback to play the CD. The Player has automatically switched the CD drive to analog playback. To switch back to digital CD playback, click Organize, click options,and use the Devices tab.%0
'//
%NS_E_WONT_DO_DIGITAL             = &HC00D0FB3&

'//
'// WMP IWMPXMLParser Error codes
'//
'//
'// MessageId: NS_E_WMPXML_NOERROR
'//
'// MessageText:
'//
'// A call was made to GetParseError on the XML parser but there was no error to retrieve.%0
'//
%NS_E_WMPXML_NOERROR              = &HC00D0FB4&

'//
'// MessageId: NS_E_WMPXML_ENDOFDATA
'//
'// MessageText:
'//
'// The XML Parser ran out of data while parsing.%0
'//
%NS_E_WMPXML_ENDOFDATA            = &HC00D0FB5&

'//
'// MessageId: NS_E_WMPXML_PARSEERROR
'//
'// MessageText:
'//
'// A generic parse error occurred in the XML parser but no information is available.%0
'//
%NS_E_WMPXML_PARSEERROR           = &HC00D0FB6&

'//
'// MessageId: NS_E_WMPXML_ATTRIBUTENOTFOUND
'//
'// MessageText:
'//
'// A call get GetNamedAttribute or GetNamedAttributeIndex on the XML parser resulted in the index not being found.%0
'//
%NS_E_WMPXML_ATTRIBUTENOTFOUND    = &HC00D0FB7&

'//
'// MessageId: NS_E_WMPXML_PINOTFOUND
'//
'// MessageText:
'//
'// A call was made go GetNamedPI on the XML parser, but the requested Processing Instruction was not found.%0
'//
%NS_E_WMPXML_PINOTFOUND           = &HC00D0FB8&

'//
'// MessageId: NS_E_WMPXML_EMPTYDOC
'//
'// MessageText:
'//
'// Persist was called on the XML parser, but the parser has no data to persist.%0
'//
%NS_E_WMPXML_EMPTYDOC             = &HC00D0FB9&

'//
'// Miscellaneous Media Player Error codes
'//
'//
'// MessageId: NS_E_WMP_PATH_ALREADY_IN_LIBRARY
'//
'// MessageText:
'//
'// This file path is already in the library.%0
'//
%NS_E_WMP_PATH_ALREADY_IN_LIBRARY = &HC00D0FBA&

'//
'// MessageId: NS_E_WMP_FILESCANALREADYSTARTED
'//
'// MessageText:
'//
'// Windows Media Player is already searching for files to add to your library. Wait for the current process to finish before attempting to search again.%0
'//
%NS_E_WMP_FILESCANALREADYSTARTED  = &HC00D0FBE&

'//
'// MessageId: NS_E_WMP_HME_INVALIDOBJECTID
'//
'// MessageText:
'//
'// Windows Media Player is unable to find the media you are looking for.%0
'//
%NS_E_WMP_HME_INVALIDOBJECTID     = &HC00D0FBF&

'//
'// MessageId: NS_E_WMP_MF_CODE_EXPIRED
'//
'// MessageText:
'//
'// A component of Windows Media Player is out-of-date. If you are running a pre-release version of Windows, try upgrading to a more recent version.%0
'//
%NS_E_WMP_MF_CODE_EXPIRED         = &HC00D0FC0&

'//
'// MessageId: NS_E_WMP_HME_NOTSEARCHABLEFORITEMS
'//
'// MessageText:
'//
'// This container does not support search on items.%0
'//
%NS_E_WMP_HME_NOTSEARCHABLEFORITEMS = &HC00D0FC1&

'//
'// MessageId: NS_E_WMP_HME_STALEREQUEST
'//
'// MessageText:
'//
'// The request could not be completed because the request does not match the current state of the media library.%0
'//
%NS_E_WMP_HME_STALEREQUEST        = &HC00D0FC2&

'//
'// MessageId: NS_E_WMP_ADDTOLIBRARY_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while adding one or more files to the library.%0
'//
%NS_E_WMP_ADDTOLIBRARY_FAILED     = &HC00D0FC7&

'//
'// MessageId: NS_E_WMP_WINDOWSAPIFAILURE
'//
'// MessageText:
'//
'// A Windows API call failed but no error information was available.%0
'//
%NS_E_WMP_WINDOWSAPIFAILURE       = &HC00D0FC8&

'//
'// MessageId: NS_E_WMP_RECORDING_NOT_ALLOWED
'//
'// MessageText:
'//
'// This file does not have burn rights. If you obtained this file from an online store, go to the online store to get burn rights.%0
'//
%NS_E_WMP_RECORDING_NOT_ALLOWED   = &HC00D0FC9&

'//
'// MessageId: NS_E_DEVICE_NOT_READY
'//
'// MessageText:
'//
'// Windows Media Player no longer detects a connected portable device. Reconnect your portable device, and then try to sync the file again.%0
'//
%NS_E_DEVICE_NOT_READY            = &HC00D0FCA&

'//
'// MessageId: NS_E_DAMAGED_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because it is corrupted.%0
'//
%NS_E_DAMAGED_FILE                = &HC00D0FCB&

'//
'// MessageId: NS_E_MPDB_GENERIC
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while attempting to access information in the library. Try restarting the Player.%0
'//
%NS_E_MPDB_GENERIC                = &HC00D0FCC&

'//
'// MessageId: NS_E_FILE_FAILED_CHECKS
'//
'// MessageText:
'//
'// The file cannot be added to the library.%0
'//
%NS_E_FILE_FAILED_CHECKS          = &HC00D0FCD&

'//
'// MessageId: NS_E_MEDIA_LIBRARY_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot create the library. You must be logged on as an administrator or a member of the Administrators group to install the Player. For more information, contact your system administrator.%0
'//
%NS_E_MEDIA_LIBRARY_FAILED        = &HC00D0FCE&

'//
'// MessageId: NS_E_SHARING_VIOLATION
'//
'// MessageText:
'//
'// The file is already in use. Close other programs that might be using the file, or stop playing the file, and then try again.%0
'//
%NS_E_SHARING_VIOLATION           = &HC00D0FCF&

'//
'// MessageId: NS_E_NO_ERROR_STRING_FOUND
'//
'// MessageText:
'//
'// Windows Media Player has encountered an unknown error.%0
'//
%NS_E_NO_ERROR_STRING_FOUND       = &HC00D0FD0&

'//
'// MessageId: NS_E_WMPOCX_NO_REMOTE_CORE
'//
'// MessageText:
'//
'// The Windows Media Player ActiveX control cannot connect to remote media services, but will continue with local media services.%0
'//
%NS_E_WMPOCX_NO_REMOTE_CORE       = &HC00D0FD1&

'//
'// MessageId: NS_E_WMPOCX_NO_ACTIVE_CORE
'//
'// MessageText:
'//
'// The requested method or property is not available because the Windows Media Player ActiveX control has not been properly activated.%0
'//
%NS_E_WMPOCX_NO_ACTIVE_CORE       = &HC00D0FD2&

'//
'// MessageId: NS_E_WMPOCX_NOT_RUNNING_REMOTELY
'//
'// MessageText:
'//
'// The Windows Media Player ActiveX control is not running in remote mode.%0
'//
%NS_E_WMPOCX_NOT_RUNNING_REMOTELY = &HC00D0FD3&

'//
'// MessageId: NS_E_WMPOCX_NO_REMOTE_WINDOW
'//
'// MessageText:
'//
'// An error occurred while trying to get the remote Windows Media Player window.%0
'//
%NS_E_WMPOCX_NO_REMOTE_WINDOW     = &HC00D0FD4&

'//
'// MessageId: NS_E_WMPOCX_ERRORMANAGERNOTAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player has encountered an unknown error.%0
'//
%NS_E_WMPOCX_ERRORMANAGERNOTAVAILABLE = &HC00D0FD5&

'//
'// MessageId: NS_E_PLUGIN_NOTSHUTDOWN
'//
'// MessageText:
'//
'// Windows Media Player was not closed properly. A damaged or incompatible plug-in might have caused the problem to occur. As a precaution, all optional plug-ins have been disabled.%0
'//
%NS_E_PLUGIN_NOTSHUTDOWN          = &HC00D0FD6&

'//
'// MessageId: NS_E_WMP_CANNOT_FIND_FOLDER
'//
'// MessageText:
'//
'// Windows Media Player cannot find the specified path. Verify that the path is typed correctly. If it is, the path does not exist in the specified location, or the computer where the path is located is not available.%0
'//
%NS_E_WMP_CANNOT_FIND_FOLDER      = &HC00D0FD7&

'//
'// MessageId: NS_E_WMP_STREAMING_RECORDING_NOT_ALLOWED
'//
'// MessageText:
'//
'// Windows Media Player cannot save a file that is being streamed.%0
'//
%NS_E_WMP_STREAMING_RECORDING_NOT_ALLOWED = &HC00D0FD8&

'//
'// MessageId: NS_E_WMP_PLUGINDLL_NOTFOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot find the selected plug-in. The Player will try to remove it from the menu. To use this plug-in, install it again.%0
'//
%NS_E_WMP_PLUGINDLL_NOTFOUND      = &HC00D0FD9&

'//
'// MessageId: NS_E_NEED_TO_ASK_USER
'//
'// MessageText:
'//
'// Action requires input from the user.%0
'//
%NS_E_NEED_TO_ASK_USER            = &HC00D0FDA&

'//
'// MessageId: NS_E_WMPOCX_PLAYER_NOT_DOCKED
'//
'// MessageText:
'//
'// The Windows Media Player ActiveX control must be in a docked state for this action to be performed.%0
'//
%NS_E_WMPOCX_PLAYER_NOT_DOCKED    = &HC00D0FDB&

'//
'// MessageId: NS_E_WMP_EXTERNAL_NOTREADY
'//
'// MessageText:
'//
'// The Windows Media Player external object is not ready.%0
'//
%NS_E_WMP_EXTERNAL_NOTREADY       = &HC00D0FDC&

'//
'// MessageId: NS_E_WMP_MLS_STALE_DATA
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action. Your computer's time and date might not be set correctly.%0
'//
%NS_E_WMP_MLS_STALE_DATA          = &HC00D0FDD&

'//
'// Generic Media PlayerUI error codes
'//
'//
'// MessageId: NS_E_WMP_UI_SUBCONTROLSNOTSUPPORTED
'//
'// MessageText:
'//
'// The control (%s) does not support creation of sub-controls, yet (%d) sub-controls have been specified.%0
'//
%NS_E_WMP_UI_SUBCONTROLSNOTSUPPORTED = &HC00D0FDE&

'//
'// MessageId: NS_E_WMP_UI_VERSIONMISMATCH
'//
'// MessageText:
'//
'// Version mismatch: (%.1f required, %.1f found).%0
'//
%NS_E_WMP_UI_VERSIONMISMATCH      = &HC00D0FDF&

'//
'// MessageId: NS_E_WMP_UI_NOTATHEMEFILE
'//
'// MessageText:
'//
'// The layout manager was given valid XML that wasn't a theme file.%0
'//
%NS_E_WMP_UI_NOTATHEMEFILE        = &HC00D0FE0&

'//
'// MessageId: NS_E_WMP_UI_SUBELEMENTNOTFOUND
'//
'// MessageText:
'//
'// The %s subelement could not be found on the %s object.%0
'//
%NS_E_WMP_UI_SUBELEMENTNOTFOUND   = &HC00D0FE1&

'//
'// MessageId: NS_E_WMP_UI_VERSIONPARSE
'//
'// MessageText:
'//
'// An error occurred parsing the version tag.\nValid version tags are of the form:\n\n\t<?wmp version='1.0'?>.%0
'//
%NS_E_WMP_UI_VERSIONPARSE         = &HC00D0FE2&

'//
'// MessageId: NS_E_WMP_UI_VIEWIDNOTFOUND
'//
'// MessageText:
'//
'// The view specified in for the 'currentViewID' property (%s) was not found in this theme file.%0
'//
%NS_E_WMP_UI_VIEWIDNOTFOUND       = &HC00D0FE3&

'//
'// MessageId: NS_E_WMP_UI_PASSTHROUGH
'//
'// MessageText:
'//
'// This error used internally for hit testing.%0
'//
%NS_E_WMP_UI_PASSTHROUGH          = &HC00D0FE4&

'//
'// MessageId: NS_E_WMP_UI_OBJECTNOTFOUND
'//
'// MessageText:
'//
'// Attributes were specified for the %s object, but the object was not available to send them to.%0
'//
%NS_E_WMP_UI_OBJECTNOTFOUND       = &HC00D0FE5&

'//
'// MessageId: NS_E_WMP_UI_SECONDHANDLER
'//
'// MessageText:
'//
'// The %s event already has a handler, the second handler was ignored.%0
'//
%NS_E_WMP_UI_SECONDHANDLER        = &HC00D0FE6&

'//
'// MessageId: NS_E_WMP_UI_NOSKININZIP
'//
'// MessageText:
'//
'// No .wms file found in skin archive.%0
'//
%NS_E_WMP_UI_NOSKININZIP          = &HC00D0FE7&

'//
'// MessageId: NS_S_WMP_UI_VERSIONMISMATCH
'//
'// MessageText:
'//
'// An upgrade might be needed for the theme manager to correctly show this skin. Skin reports version: %.1f.%0
'//
%NS_S_WMP_UI_VERSIONMISMATCH      = &H000D0FE8&

'//
'// MessageId: NS_S_WMP_EXCEPTION
'//
'// MessageText:
'//
'// An error occurred in one of the UI components.%0
'//
%NS_S_WMP_EXCEPTION               = &H000D0FE9&

'//
'// MessageId: NS_E_WMP_URLDOWNLOADFAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while downloading the file.%0
'//
%NS_E_WMP_URLDOWNLOADFAILED       = &HC00D0FEA&

'//
'// MessageId: NS_E_WMPOCX_UNABLE_TO_LOAD_SKIN
'//
'// MessageText:
'//
'// The Windows Media Player ActiveX control cannot load the requested uiMode and cannot roll back to the existing uiMode.%0
'//
%NS_E_WMPOCX_UNABLE_TO_LOAD_SKIN  = &HC00D0FEB&

'//
'// MessageId: NS_E_WMP_INVALID_SKIN
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem with the skin file. The skin file might not be valid.%0
'//
%NS_E_WMP_INVALID_SKIN            = &HC00D0FEC&

'//
'// MessageId: NS_E_WMP_SENDMAILFAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot send the link because your e-mail program is not responding. Verify that your e-mail program is configured properly, and then try again.%0
'//
%NS_E_WMP_SENDMAILFAILED          = &HC00D0FED&

'//
'// MessageId: NS_E_WMP_LOCKEDINSKINMODE
'//
'// MessageText:
'//
'// Windows Media Player cannot switch to full mode because your computer administrator has locked this skin.%0
'//
%NS_E_WMP_LOCKEDINSKINMODE        = &HC00D0FEE&

'//
'// MessageId: NS_E_WMP_FAILED_TO_SAVE_FILE
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while saving the file.%0
'//
%NS_E_WMP_FAILED_TO_SAVE_FILE     = &HC00D0FEF&

'//Save As
'//
'// MessageId: NS_E_WMP_SAVEAS_READONLY
'//
'// MessageText:
'//
'// Windows Media Player cannot overwrite a read-only file. Try using a different file name.%0
'//
%NS_E_WMP_SAVEAS_READONLY         = &HC00D0FF0&

'//
'// MessageId: NS_E_WMP_FAILED_TO_SAVE_PLAYLIST
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while creating or saving the playlist.%0
'//
%NS_E_WMP_FAILED_TO_SAVE_PLAYLIST = &HC00D0FF1&

'//
'// MessageId: NS_E_WMP_FAILED_TO_OPEN_WMD
'//
'// MessageText:
'//
'// Windows Media Player cannot open the Windows Media Download file. The file might be damaged.%0
'//
%NS_E_WMP_FAILED_TO_OPEN_WMD      = &HC00D0FF2&

'//
'// MessageId: NS_E_WMP_CANT_PLAY_PROTECTED
'//
'// MessageText:
'//
'// The file cannot be added to the library because it is a protected DVR-MS file. This content cannot be played back by Windows Media Player.%0
'//
%NS_E_WMP_CANT_PLAY_PROTECTED     = &HC00D0FF3&

'//
'// MessageId: NS_E_SHARING_STATE_OUT_OF_SYNC
'//
'// MessageText:
'//
'// Media sharing has been turned off because a required Windows setting or component has changed.%0
'//
%NS_E_SHARING_STATE_OUT_OF_SYNC   = &HC00D0FF4&

'// Additional remoting error(s)
'//
'// MessageId: NS_E_WMPOCX_REMOTE_PLAYER_ALREADY_RUNNING
'//
'// MessageText:
'//
'// Exclusive Services launch failed because the Windows Media Player is already running.%0
'//
%NS_E_WMPOCX_REMOTE_PLAYER_ALREADY_RUNNING = &HC00D0FFA&

'//
'// WMP Regional button control
'//
'//
'// MessageId: NS_E_WMP_RBC_JPGMAPPINGIMAGE
'//
'// MessageText:
'//
'// JPG Images are not recommended for use as a mappingImage.%0
'//
%NS_E_WMP_RBC_JPGMAPPINGIMAGE     = &HC00D1004&

'//
'// MessageId: NS_E_WMP_JPGTRANSPARENCY
'//
'// MessageText:
'//
'// JPG Images are not recommended when using a transparencyColor.%0
'//
%NS_E_WMP_JPGTRANSPARENCY         = &HC00D1005&

'//
'// WMP Slider control
'//
'//
'// MessageId: NS_E_WMP_INVALID_MAX_VAL
'//
'// MessageText:
'//
'// The Max property cannot be less than Min property.%0
'//
%NS_E_WMP_INVALID_MAX_VAL         = &HC00D1009&

'//
'// MessageId: NS_E_WMP_INVALID_MIN_VAL
'//
'// MessageText:
'//
'// The Min property cannot be greater than Max property.%0
'//
%NS_E_WMP_INVALID_MIN_VAL         = &HC00D100A&

'//
'// WMP CustomSlider control
'//
'//
'// MessageId: NS_E_WMP_CS_JPGPOSITIONIMAGE
'//
'// MessageText:
'//
'// JPG Images are not recommended for use as a positionImage.%0
'//
%NS_E_WMP_CS_JPGPOSITIONIMAGE     = &HC00D100E&

'//
'// MessageId: NS_E_WMP_CS_NOTEVENLYDIVISIBLE
'//
'// MessageText:
'//
'// The (%s) image's size is not evenly divisible by the positionImage's size.%0
'//
%NS_E_WMP_CS_NOTEVENLYDIVISIBLE   = &HC00D100F&

'//
'// WMP ZIP Decoder
'//
'//
'// MessageId: NS_E_WMPZIP_NOTAZIPFILE
'//
'// MessageText:
'//
'// The ZIP reader opened a file and its signature did not match that of the ZIP files.%0
'//
%NS_E_WMPZIP_NOTAZIPFILE          = &HC00D1018&

'//
'// MessageId: NS_E_WMPZIP_CORRUPT
'//
'// MessageText:
'//
'// The ZIP reader has detected that the file is corrupted.%0
'//
%NS_E_WMPZIP_CORRUPT              = &HC00D1019&

'//
'// MessageId: NS_E_WMPZIP_FILENOTFOUND
'//
'// MessageText:
'//
'// GetFileStream, SaveToFile, or SaveTemp file was called on the ZIP reader with a file name that was not found in the ZIP file.%0
'//
%NS_E_WMPZIP_FILENOTFOUND         = &HC00D101A&

'//
'// WMP Image Decoding Error codes
'//
'//
'// MessageId: NS_E_WMP_IMAGE_FILETYPE_UNSUPPORTED
'//
'// MessageText:
'//
'// Image type not supported.%0
'//
%NS_E_WMP_IMAGE_FILETYPE_UNSUPPORTED = &HC00D1022&

'//
'// MessageId: NS_E_WMP_IMAGE_INVALID_FORMAT
'//
'// MessageText:
'//
'// Image file might be corrupt.%0
'//
%NS_E_WMP_IMAGE_INVALID_FORMAT    = &HC00D1023&

'//
'// MessageId: NS_E_WMP_GIF_UNEXPECTED_ENDOFFILE
'//
'// MessageText:
'//
'// Unexpected end of file. GIF file might be corrupt.%0
'//
%NS_E_WMP_GIF_UNEXPECTED_ENDOFFILE = &HC00D1024&

'//
'// MessageId: NS_E_WMP_GIF_INVALID_FORMAT
'//
'// MessageText:
'//
'// Invalid GIF file.%0
'//
%NS_E_WMP_GIF_INVALID_FORMAT      = &HC00D1025&

'//
'// MessageId: NS_E_WMP_GIF_BAD_VERSION_NUMBER
'//
'// MessageText:
'//
'// Invalid GIF version. Only 87a or 89a supported.%0
'//
%NS_E_WMP_GIF_BAD_VERSION_NUMBER  = &HC00D1026&

'//
'// MessageId: NS_E_WMP_GIF_NO_IMAGE_IN_FILE
'//
'// MessageText:
'//
'// No images found in GIF file.%0
'//
%NS_E_WMP_GIF_NO_IMAGE_IN_FILE    = &HC00D1027&

'//
'// MessageId: NS_E_WMP_PNG_INVALIDFORMAT
'//
'// MessageText:
'//
'// Invalid PNG image file format.%0
'//
%NS_E_WMP_PNG_INVALIDFORMAT       = &HC00D1028&

'//
'// MessageId: NS_E_WMP_PNG_UNSUPPORTED_BITDEPTH
'//
'// MessageText:
'//
'// PNG bitdepth not supported.%0
'//
%NS_E_WMP_PNG_UNSUPPORTED_BITDEPTH = &HC00D1029&

'//
'// MessageId: NS_E_WMP_PNG_UNSUPPORTED_COMPRESSION
'//
'// MessageText:
'//
'// Compression format defined in PNG file not supported,%0
'//
%NS_E_WMP_PNG_UNSUPPORTED_COMPRESSION = &HC00D102A&

'//
'// MessageId: NS_E_WMP_PNG_UNSUPPORTED_FILTER
'//
'// MessageText:
'//
'// Filter method defined in PNG file not supported.%0
'//
%NS_E_WMP_PNG_UNSUPPORTED_FILTER  = &HC00D102B&

'//
'// MessageId: NS_E_WMP_PNG_UNSUPPORTED_INTERLACE
'//
'// MessageText:
'//
'// Interlace method defined in PNG file not supported.%0
'//
%NS_E_WMP_PNG_UNSUPPORTED_INTERLACE = &HC00D102C&

'//
'// MessageId: NS_E_WMP_PNG_UNSUPPORTED_BAD_CRC
'//
'// MessageText:
'//
'// Bad CRC in PNG file.%0
'//
%NS_E_WMP_PNG_UNSUPPORTED_BAD_CRC = &HC00D102D&

'//
'// MessageId: NS_E_WMP_BMP_INVALID_BITMASK
'//
'// MessageText:
'//
'// Invalid bitmask in BMP file.%0
'//
%NS_E_WMP_BMP_INVALID_BITMASK     = &HC00D102E&

'//
'// MessageId: NS_E_WMP_BMP_TOPDOWN_DIB_UNSUPPORTED
'//
'// MessageText:
'//
'// Topdown DIB not supported.%0
'//
%NS_E_WMP_BMP_TOPDOWN_DIB_UNSUPPORTED = &HC00D102F&

'//
'// MessageId: NS_E_WMP_BMP_BITMAP_NOT_CREATED
'//
'// MessageText:
'//
'// Bitmap could not be created.%0
'//
%NS_E_WMP_BMP_BITMAP_NOT_CREATED  = &HC00D1030&

'//
'// MessageId: NS_E_WMP_BMP_COMPRESSION_UNSUPPORTED
'//
'// MessageText:
'//
'// Compression format defined in BMP not supported.%0
'//
%NS_E_WMP_BMP_COMPRESSION_UNSUPPORTED = &HC00D1031&

'//
'// MessageId: NS_E_WMP_BMP_INVALID_FORMAT
'//
'// MessageText:
'//
'// Invalid Bitmap format.%0
'//
%NS_E_WMP_BMP_INVALID_FORMAT      = &HC00D1032&

'//
'// MessageId: NS_E_WMP_JPG_JERR_ARITHCODING_NOTIMPL
'//
'// MessageText:
'//
'// JPEG Arithmetic coding not supported.%0
'//
%NS_E_WMP_JPG_JERR_ARITHCODING_NOTIMPL = &HC00D1033&

'//
'// MessageId: NS_E_WMP_JPG_INVALID_FORMAT
'//
'// MessageText:
'//
'// Invalid JPEG format.%0
'//
%NS_E_WMP_JPG_INVALID_FORMAT      = &HC00D1034&

'//
'// MessageId: NS_E_WMP_JPG_BAD_DCTSIZE
'//
'// MessageText:
'//
'// Invalid JPEG format.%0
'//
%NS_E_WMP_JPG_BAD_DCTSIZE         = &HC00D1035&

'//
'// MessageId: NS_E_WMP_JPG_BAD_VERSION_NUMBER
'//
'// MessageText:
'//
'// Internal version error. Unexpected JPEG library version.%0
'//
%NS_E_WMP_JPG_BAD_VERSION_NUMBER  = &HC00D1036&

'//
'// MessageId: NS_E_WMP_JPG_BAD_PRECISION
'//
'// MessageText:
'//
'// Internal JPEG Library error. Unsupported JPEG data precision.%0
'//
%NS_E_WMP_JPG_BAD_PRECISION       = &HC00D1037&

'//
'// MessageId: NS_E_WMP_JPG_CCIR601_NOTIMPL
'//
'// MessageText:
'//
'// JPEG CCIR601 not supported.%0
'//
%NS_E_WMP_JPG_CCIR601_NOTIMPL     = &HC00D1038&

'//
'// MessageId: NS_E_WMP_JPG_NO_IMAGE_IN_FILE
'//
'// MessageText:
'//
'// No image found in JPEG file.%0
'//
%NS_E_WMP_JPG_NO_IMAGE_IN_FILE    = &HC00D1039&

'//
'// MessageId: NS_E_WMP_JPG_READ_ERROR
'//
'// MessageText:
'//
'// Could not read JPEG file.%0
'//
%NS_E_WMP_JPG_READ_ERROR          = &HC00D103A&

'//
'// MessageId: NS_E_WMP_JPG_FRACT_SAMPLE_NOTIMPL
'//
'// MessageText:
'//
'// JPEG Fractional sampling not supported.%0
'//
%NS_E_WMP_JPG_FRACT_SAMPLE_NOTIMPL = &HC00D103B&

'//
'// MessageId: NS_E_WMP_JPG_IMAGE_TOO_BIG
'//
'// MessageText:
'//
'// JPEG image too large. Maximum image size supported is 65500 X 65500.%0
'//
%NS_E_WMP_JPG_IMAGE_TOO_BIG       = &HC00D103C&

'//
'// MessageId: NS_E_WMP_JPG_UNEXPECTED_ENDOFFILE
'//
'// MessageText:
'//
'// Unexpected end of file reached in JPEG file.%0
'//
%NS_E_WMP_JPG_UNEXPECTED_ENDOFFILE = &HC00D103D&

'//
'// MessageId: NS_E_WMP_JPG_SOF_UNSUPPORTED
'//
'// MessageText:
'//
'// Unsupported JPEG SOF marker found.%0
'//
%NS_E_WMP_JPG_SOF_UNSUPPORTED     = &HC00D103E&

'//
'// MessageId: NS_E_WMP_JPG_UNKNOWN_MARKER
'//
'// MessageText:
'//
'// Unknown JPEG marker found.%0
'//
%NS_E_WMP_JPG_UNKNOWN_MARKER      = &HC00D103F&

'//
'// MessageId: NS_S_WMP_LOADED_GIF_IMAGE
'//
'// MessageText:
'//
'// Successfully loaded a GIF file.%0
'//
%NS_S_WMP_LOADED_GIF_IMAGE        = &H000D1040&

'//
'// MessageId: NS_S_WMP_LOADED_PNG_IMAGE
'//
'// MessageText:
'//
'// Successfully loaded a PNG file.%0
'//
%NS_S_WMP_LOADED_PNG_IMAGE        = &H000D1041&

'//
'// MessageId: NS_S_WMP_LOADED_BMP_IMAGE
'//
'// MessageText:
'//
'// Successfully loaded a BMP file.%0
'//
%NS_S_WMP_LOADED_BMP_IMAGE        = &H000D1042&

'//
'// MessageId: NS_S_WMP_LOADED_JPG_IMAGE
'//
'// MessageText:
'//
'// Successfully loaded a JPG file.%0
'//
%NS_S_WMP_LOADED_JPG_IMAGE        = &H000D1043&

'//
'// MessageId: NS_E_WMP_FAILED_TO_OPEN_IMAGE
'//
'// MessageText:
'//
'// Windows Media Player cannot display the picture file. The player either does not support the picture type or the picture is corrupted.%0
'//
%NS_E_WMP_FAILED_TO_OPEN_IMAGE    = &HC00D1044&

'//
'// WMP DAI Error code
'//
'//
'// MessageId: NS_E_WMP_DAI_SONGTOOSHORT
'//
'// MessageText:
'//
'// Windows Media Player cannot compute a Digital Audio Id for the song. It is too short.%0
'//
%NS_E_WMP_DAI_SONGTOOSHORT        = &HC00D1049&

'//
'// WMP WM Runtime Error codes
'//
'//
'// MessageId: NS_E_WMG_RATEUNAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file at the requested speed.%0
'//
%NS_E_WMG_RATEUNAVAILABLE         = &HC00D104A&

'//
'// MessageId: NS_E_WMG_PLUGINUNAVAILABLE
'//
'// MessageText:
'//
'// The rendering or digital signal processing plug-in cannot be instantiated.%0
'//
%NS_E_WMG_PLUGINUNAVAILABLE       = &HC00D104B&

'//
'// MessageId: NS_E_WMG_CANNOTQUEUE
'//
'// MessageText:
'//
'// The file cannot be queued for seamless playback.%0
'//
%NS_E_WMG_CANNOTQUEUE             = &HC00D104C&

'//
'// MessageId: NS_E_WMG_PREROLLLICENSEACQUISITIONNOTALLOWED
'//
'// MessageText:
'//
'// Windows Media Player cannot download media usage rights for a file in the playlist.%0
'//
%NS_E_WMG_PREROLLLICENSEACQUISITIONNOTALLOWED = &HC00D104D&

'//
'// MessageId: NS_E_WMG_UNEXPECTEDPREROLLSTATUS
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while trying to queue a file.%0
'//
%NS_E_WMG_UNEXPECTEDPREROLLSTATUS = &HC00D104E&

'//
'// MessageId: NS_S_WMG_FORCE_DROP_FRAME
'//
'// MessageText:
'//
'// Drop this frame.%0
'//
%NS_S_WMG_FORCE_DROP_FRAME        = &H000D104F&

'//
'// MessageId: NS_E_WMG_INVALID_COPP_CERTIFICATE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the protected file. The Player cannot verify that the connection to your video card is secure. Try installing an updated device driver for your video card.%0
'//
%NS_E_WMG_INVALID_COPP_CERTIFICATE = &HC00D1051&

'//
'// MessageId: NS_E_WMG_COPP_SECURITY_INVALID
'//
'// MessageText:
'//
'// Windows Media Player cannot play the protected file. The Player detected that the connection to your hardware might not be secure.%0
'//
%NS_E_WMG_COPP_SECURITY_INVALID   = &HC00D1052&

'//
'// MessageId: NS_E_WMG_COPP_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player output link protection is unsupported on this system.%0
'//
%NS_E_WMG_COPP_UNSUPPORTED        = &HC00D1053&

'//
'// MessageId: NS_E_WMG_INVALIDSTATE
'//
'// MessageText:
'//
'// Operation attempted in an invalid graph state.%0
'//
%NS_E_WMG_INVALIDSTATE            = &HC00D1054&

'//
'// MessageId: NS_E_WMG_SINKALREADYEXISTS
'//
'// MessageText:
'//
'// A renderer cannot be inserted in a stream while one already exists.%0
'//
%NS_E_WMG_SINKALREADYEXISTS       = &HC00D1055&

'//
'// MessageId: NS_E_WMG_NOSDKINTERFACE
'//
'// MessageText:
'//
'// The Windows Media SDK interface needed to complete the operation does not exist at this time.%0
'//
%NS_E_WMG_NOSDKINTERFACE          = &HC00D1056&

'//
'// MessageId: NS_E_WMG_NOTALLOUTPUTSRENDERED
'//
'// MessageText:
'//
'// Windows Media Player cannot play a portion of the file because it requires a codec that either could not be downloaded or that is not supported by the Player.%0
'//
%NS_E_WMG_NOTALLOUTPUTSRENDERED   = &HC00D1057&

'//
'// MessageId: NS_E_WMG_FILETRANSFERNOTALLOWED
'//
'// MessageText:
'//
'// File transfer streams are not allowed in the standalone Player.%0
'//
%NS_E_WMG_FILETRANSFERNOTALLOWED  = &HC00D1058&

'//
'// MessageId: NS_E_WMR_UNSUPPORTEDSTREAM
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The Player does not support the format you are trying to play.%0
'//
%NS_E_WMR_UNSUPPORTEDSTREAM       = &HC00D1059&

'//
'// MessageId: NS_E_WMR_PINNOTFOUND
'//
'// MessageText:
'//
'// An operation was attempted on a pin that does not exist in the DirectShow filter graph.%0
'//
%NS_E_WMR_PINNOTFOUND             = &HC00D105A&

'//
'// MessageId: NS_E_WMR_WAITINGONFORMATSWITCH
'//
'// MessageText:
'//
'// Specified operation cannot be completed while waiting for a media format change from the SDK.%0
'//
%NS_E_WMR_WAITINGONFORMATSWITCH   = &HC00D105B&

'//
'// MessageId: NS_E_WMR_NOSOURCEFILTER
'//
'// MessageText:
'//
'// Specified operation cannot be completed because the source filter does not exist.%0
'//
%NS_E_WMR_NOSOURCEFILTER          = &HC00D105C&

'//
'// MessageId: NS_E_WMR_PINTYPENOMATCH
'//
'// MessageText:
'//
'// The specified type does not match this pin.%0
'//
%NS_E_WMR_PINTYPENOMATCH          = &HC00D105D&

'//
'// MessageId: NS_E_WMR_NOCALLBACKAVAILABLE
'//
'// MessageText:
'//
'// The WMR Source Filter does not have a callback available.%0
'//
%NS_E_WMR_NOCALLBACKAVAILABLE     = &HC00D105E&

'//
'// MessageId: NS_S_WMR_ALREADYRENDERED
'//
'// MessageText:
'//
'// The specified stream has already been rendered.%0
'//
%NS_S_WMR_ALREADYRENDERED         = &H000D105F&

'//
'// MessageId: NS_S_WMR_PINTYPEPARTIALMATCH
'//
'// MessageText:
'//
'// The specified type partially matches this pin type.%0
'//
%NS_S_WMR_PINTYPEPARTIALMATCH     = &H000D1060&

'//
'// MessageId: NS_S_WMR_PINTYPEFULLMATCH
'//
'// MessageText:
'//
'// The specified type fully matches this pin type.%0
'//
%NS_S_WMR_PINTYPEFULLMATCH        = &H000D1061&

'//
'// MessageId: NS_E_WMR_SAMPLEPROPERTYNOTSET
'//
'// MessageText:
'//
'// The specified property has not been set on this sample.%0
'//
%NS_E_WMR_SAMPLEPROPERTYNOTSET    = &HC00D1062&

'//
'// MessageId: NS_E_WMR_CANNOT_RENDER_BINARY_STREAM
'//
'// MessageText:
'//
'// A plug-in is required to correctly play the file. To determine if the plug-in is available to download, click Web Help.%0
'//
%NS_E_WMR_CANNOT_RENDER_BINARY_STREAM = &HC00D1063&

'//
'// MessageId: NS_E_WMG_LICENSE_TAMPERED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because your media usage rights are corrupted. If you previously backed up your media usage rights, try restoring them.%0
'//
%NS_E_WMG_LICENSE_TAMPERED        = &HC00D1064&

'//
'// MessageId: NS_E_WMR_WILLNOT_RENDER_BINARY_STREAM
'//
'// MessageText:
'//
'// Windows Media Player cannot play protected files that contain binary streams.%0
'//
%NS_E_WMR_WILLNOT_RENDER_BINARY_STREAM = &HC00D1065&

'//
'// MessageId: NS_S_WMG_ADVISE_DROP_FRAME
'//
'// MessageText:
'//
'// The timestamp is late compared to the current render position. Advise dropping this frame.%0
'//
%NS_S_WMG_ADVISE_DROP_FRAME       = &H000D1066&

'//
'// MessageId: NS_S_WMG_ADVISE_DROP_TO_KEYFRAME
'//
'// MessageText:
'//
'// The timestamp is severely late compared to the current render position. Advise dropping everything up to the next key frame.%0
'//
%NS_S_WMG_ADVISE_DROP_TO_KEYFRAME = &H000D1067&

'//
'// WMP Playlist Error codes
'//
'//
'// MessageId: NS_E_WMX_UNRECOGNIZED_PLAYLIST_FORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the playlist because it is not valid.%0
'//
%NS_E_WMX_UNRECOGNIZED_PLAYLIST_FORMAT = &HC00D1068&

'//
'// MessageId: NS_E_ASX_INVALIDFORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the playlist because it is not valid.%0
'//
%NS_E_ASX_INVALIDFORMAT           = &HC00D1069&

'//
'// MessageId: NS_E_ASX_INVALIDVERSION
'//
'// MessageText:
'//
'// A later version of Windows Media Player might be required to play this playlist.%0
'//
%NS_E_ASX_INVALIDVERSION          = &HC00D106A&

'//
'// MessageId: NS_E_ASX_INVALID_REPEAT_BLOCK
'//
'// MessageText:
'//
'// The format of a REPEAT loop within the current playlist file is not valid.%0
'//
%NS_E_ASX_INVALID_REPEAT_BLOCK    = &HC00D106B&

'//
'// MessageId: NS_E_ASX_NOTHING_TO_WRITE
'//
'// MessageText:
'//
'// Windows Media Player cannot save the playlist because it does not contain any items.%0
'//
%NS_E_ASX_NOTHING_TO_WRITE        = &HC00D106C&

'//
'// MessageId: NS_E_URLLIST_INVALIDFORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the playlist because it is not valid.%0
'//
%NS_E_URLLIST_INVALIDFORMAT       = &HC00D106D&

'//
'// MessageId: NS_E_WMX_ATTRIBUTE_DOES_NOT_EXIST
'//
'// MessageText:
'//
'// The specified attribute does not exist.%0
'//
%NS_E_WMX_ATTRIBUTE_DOES_NOT_EXIST = &HC00D106E&

'//
'// MessageId: NS_E_WMX_ATTRIBUTE_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The specified attribute already exists.%0
'//
%NS_E_WMX_ATTRIBUTE_ALREADY_EXISTS = &HC00D106F&

'//
'// MessageId: NS_E_WMX_ATTRIBUTE_UNRETRIEVABLE
'//
'// MessageText:
'//
'// Cannot retrieve the specified attribute.%0
'//
%NS_E_WMX_ATTRIBUTE_UNRETRIEVABLE = &HC00D1070&

'//
'// MessageId: NS_E_WMX_ITEM_DOES_NOT_EXIST
'//
'// MessageText:
'//
'// The specified item does not exist in the current playlist.%0
'//
%NS_E_WMX_ITEM_DOES_NOT_EXIST     = &HC00D1071&

'//
'// MessageId: NS_E_WMX_ITEM_TYPE_ILLEGAL
'//
'// MessageText:
'//
'// Items of the specified type cannot be created within the current playlist.%0
'//
%NS_E_WMX_ITEM_TYPE_ILLEGAL       = &HC00D1072&

'//
'// MessageId: NS_E_WMX_ITEM_UNSETTABLE
'//
'// MessageText:
'//
'// The specified item cannot be set in the current playlist.%0
'//
%NS_E_WMX_ITEM_UNSETTABLE         = &HC00D1073&

'//
'// MessageId: NS_E_WMX_PLAYLIST_EMPTY
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action because the playlist does not contain any items.%0
'//
%NS_E_WMX_PLAYLIST_EMPTY          = &HC00D1074&

'//
'// MessageId: NS_E_MLS_SMARTPLAYLIST_FILTER_NOT_REGISTERED
'//
'// MessageText:
'//
'// The specified auto playlist contains a filter type that is either not valid or is not installed on this computer.%0
'//
%NS_E_MLS_SMARTPLAYLIST_FILTER_NOT_REGISTERED = &HC00D1075&

'//
'// MessageId: NS_E_WMX_INVALID_FORMAT_OVER_NESTING
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the associated playlist contains too many nested playlists.%0
'//
%NS_E_WMX_INVALID_FORMAT_OVER_NESTING = &HC00D1076&

'//
'// WMP Core  Error codes
'//
'//
'// MessageId: NS_E_WMPCORE_NOSOURCEURLSTRING
'//
'// MessageText:
'//
'// Windows Media Player cannot find the file. Verify that the path is typed correctly. If it is, the file might not exist in the specified location, or the computer where the file is stored might not be available.%0
'//
%NS_E_WMPCORE_NOSOURCEURLSTRING   = &HC00D107C&

'//
'// MessageId: NS_E_WMPCORE_COCREATEFAILEDFORGITOBJECT
'//
'// MessageText:
'//
'// Failed to create the Global Interface Table.%0
'//
%NS_E_WMPCORE_COCREATEFAILEDFORGITOBJECT = &HC00D107D&

'//
'// MessageId: NS_E_WMPCORE_FAILEDTOGETMARSHALLEDEVENTHANDLERINTERFACE
'//
'// MessageText:
'//
'// Failed to get the marshaled graph event handler interface.%0
'//
%NS_E_WMPCORE_FAILEDTOGETMARSHALLEDEVENTHANDLERINTERFACE = &HC00D107E&

'//
'// MessageId: NS_E_WMPCORE_BUFFERTOOSMALL
'//
'// MessageText:
'//
'// Buffer is too small for copying media type.%0
'//
%NS_E_WMPCORE_BUFFERTOOSMALL      = &HC00D107F&

'//
'// MessageId: NS_E_WMPCORE_UNAVAILABLE
'//
'// MessageText:
'//
'// The current state of the Player does not allow this operation.%0
'//
%NS_E_WMPCORE_UNAVAILABLE         = &HC00D1080&

'//
'// MessageId: NS_E_WMPCORE_INVALIDPLAYLISTMODE
'//
'// MessageText:
'//
'// The playlist manager does not understand the current play mode (for example, shuffle or norma&.%0
'//
%NS_E_WMPCORE_INVALIDPLAYLISTMODE = &HC00D1081&

'//
'// MessageId: NS_E_WMPCORE_ITEMNOTINPLAYLIST
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because it is not in the current playlist.%0
'//
%NS_E_WMPCORE_ITEMNOTINPLAYLIST   = &HC00D1086&

'//
'// MessageId: NS_E_WMPCORE_PLAYLISTEMPTY
'//
'// MessageText:
'//
'// There are no items in the playlist. Add items to the playlist, and then try again.%0
'//
%NS_E_WMPCORE_PLAYLISTEMPTY       = &HC00D1087&

'//
'// MessageId: NS_E_WMPCORE_NOBROWSER
'//
'// MessageText:
'//
'// The website cannot be displayed because no web browser is installed on your computer.%0
'//
%NS_E_WMPCORE_NOBROWSER           = &HC00D1088&

'//
'// MessageId: NS_E_WMPCORE_UNRECOGNIZED_MEDIA_URL
'//
'// MessageText:
'//
'// Windows Media Player cannot find the specified file. Verify the path is typed correctly. If it is, the file does not exist in the specified location, or the computer where the file is stored is not available.%0
'//
%NS_E_WMPCORE_UNRECOGNIZED_MEDIA_URL = &HC00D1089&

'//
'// MessageId: NS_E_WMPCORE_GRAPH_NOT_IN_LIST
'//
'// MessageText:
'//
'// Graph with the specified URL was not found in the prerolled graph list.%0
'//
%NS_E_WMPCORE_GRAPH_NOT_IN_LIST   = &HC00D108A&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_EMPTY_OR_SINGLE_MEDIA
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested operation because there is only one item in the playlist.%0
'//
%NS_E_WMPCORE_PLAYLIST_EMPTY_OR_SINGLE_MEDIA = &HC00D108B&

'//
'// MessageId: NS_E_WMPCORE_ERRORSINKNOTREGISTERED
'//
'// MessageText:
'//
'// An error sink was never registered for the calling object.%0
'//
%NS_E_WMPCORE_ERRORSINKNOTREGISTERED = &HC00D108C&

'//
'// MessageId: NS_E_WMPCORE_ERRORMANAGERNOTAVAILABLE
'//
'// MessageText:
'//
'// The error manager is not available to respond to errors.%0
'//
%NS_E_WMPCORE_ERRORMANAGERNOTAVAILABLE = &HC00D108D&

'//
'// MessageId: NS_E_WMPCORE_WEBHELPFAILED
'//
'// MessageText:
'//
'// The Web Help URL cannot be opened.%0
'//
%NS_E_WMPCORE_WEBHELPFAILED       = &HC00D108E&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_ERROR_RESUME_FAILED
'//
'// MessageText:
'//
'// Could not resume playing next item in playlist.%0
'//
%NS_E_WMPCORE_MEDIA_ERROR_RESUME_FAILED = &HC00D108F&

'//
'// MessageId: NS_E_WMPCORE_NO_REF_IN_ENTRY
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the associated playlist does not contain any items or the playlist is not valid.%0
'//
%NS_E_WMPCORE_NO_REF_IN_ENTRY     = &HC00D1090&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_EMPTY
'//
'// MessageText:
'//
'// An empty string for playlist attribute name was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_EMPTY = &HC00D1091&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_ILLEGAL
'//
'// MessageText:
'//
'// A playlist attribute name that is not valid was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_NAME_ILLEGAL = &HC00D1092&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_EMPTY
'//
'// MessageText:
'//
'// An empty string for a playlist attribute value was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_EMPTY = &HC00D1093&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_ILLEGAL
'//
'// MessageText:
'//
'// An illegal value for a playlist attribute was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ATTRIBUTE_VALUE_ILLEGAL = &HC00D1094&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_EMPTY
'//
'// MessageText:
'//
'// An empty string for a playlist item attribute name was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_EMPTY = &HC00D1095&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_ILLEGAL
'//
'// MessageText:
'//
'// An illegal value for a playlist item attribute name was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_NAME_ILLEGAL = &HC00D1096&

'//
'// MessageId: NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_VALUE_EMPTY
'//
'// MessageText:
'//
'// An illegal value for a playlist item attribute was found.%0
'//
%NS_E_WMPCORE_WMX_LIST_ITEM_ATTRIBUTE_VALUE_EMPTY = &HC00D1097&

'//
'// MessageId: NS_E_WMPCORE_LIST_ENTRY_NO_REF
'//
'// MessageText:
'//
'// The playlist does not contain any items.%0
'//
%NS_E_WMPCORE_LIST_ENTRY_NO_REF   = &HC00D1098&

'//
'// MessageId: NS_E_WMPCORE_MISNAMED_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The file is either corrupted or the Player does not support the format you are trying to play.%0
'//
%NS_E_WMPCORE_MISNAMED_FILE       = &HC00D1099&

'//
'// MessageId: NS_E_WMPCORE_CODEC_NOT_TRUSTED
'//
'// MessageText:
'//
'// The codec downloaded for this file does not appear to be properly signed, so it cannot be installed.%0
'//
%NS_E_WMPCORE_CODEC_NOT_TRUSTED   = &HC00D109A&

'//
'// MessageId: NS_E_WMPCORE_CODEC_NOT_FOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. One or more codecs required to play the file could not be found.%0
'//
%NS_E_WMPCORE_CODEC_NOT_FOUND     = &HC00D109B&

'//
'// MessageId: NS_E_WMPCORE_CODEC_DOWNLOAD_NOT_ALLOWED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because a required codec is not installed on your computer. To try downloading the codec, turn on the "Download codecs automatically" option.%0
'//
%NS_E_WMPCORE_CODEC_DOWNLOAD_NOT_ALLOWED = &HC00D109C&

'//
'// MessageId: NS_E_WMPCORE_ERROR_DOWNLOADING_PLAYLIST
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while downloading the playlist.%0
'//
%NS_E_WMPCORE_ERROR_DOWNLOADING_PLAYLIST = &HC00D109D&

'//
'// MessageId: NS_E_WMPCORE_FAILED_TO_BUILD_PLAYLIST
'//
'// MessageText:
'//
'// Failed to build the playlist.%0
'//
%NS_E_WMPCORE_FAILED_TO_BUILD_PLAYLIST = &HC00D109E&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NONE
'//
'// MessageText:
'//
'// Playlist has no alternates to switch into.%0
'//
%NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NONE = &HC00D109F&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_EXHAUSTED
'//
'// MessageText:
'//
'// No more playlist alternates available to switch to.%0
'//
%NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_EXHAUSTED = &HC00D10A0&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NAME_NOT_FOUND
'//
'// MessageText:
'//
'// Could not find the name of the alternate playlist to switch into.%0
'//
%NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_NAME_NOT_FOUND = &HC00D10A1&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_MORPH_FAILED
'//
'// MessageText:
'//
'// Failed to switch to an alternate for this media.%0
'//
%NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_MORPH_FAILED = &HC00D10A2&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_INIT_FAILED
'//
'// MessageText:
'//
'// Failed to initialize an alternate for the media.%0
'//
%NS_E_WMPCORE_PLAYLIST_ITEM_ALTERNATE_INIT_FAILED = &HC00D10A3&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_ALTERNATE_REF_EMPTY
'//
'// MessageText:
'//
'// No URL specified for the roll over Refs in the playlist file.%0
'//
%NS_E_WMPCORE_MEDIA_ALTERNATE_REF_EMPTY = &HC00D10A4&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_NO_EVENT_NAME
'//
'// MessageText:
'//
'// Encountered a playlist with no name.%0
'//
%NS_E_WMPCORE_PLAYLIST_NO_EVENT_NAME = &HC00D10A5&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_EVENT_ATTRIBUTE_ABSENT
'//
'// MessageText:
'//
'// A required attribute in the event block of the playlist was not found.%0
'//
%NS_E_WMPCORE_PLAYLIST_EVENT_ATTRIBUTE_ABSENT = &HC00D10A6&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_EVENT_EMPTY
'//
'// MessageText:
'//
'// No items were found in the event block of the playlist.%0
'//
%NS_E_WMPCORE_PLAYLIST_EVENT_EMPTY = &HC00D10A7&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_STACK_EMPTY
'//
'// MessageText:
'//
'// No playlist was found while returning from a nested playlist.%0
'//
%NS_E_WMPCORE_PLAYLIST_STACK_EMPTY = &HC00D10A8&

'//
'// MessageId: NS_E_WMPCORE_CURRENT_MEDIA_NOT_ACTIVE
'//
'// MessageText:
'//
'// The media item is not active currently.%0
'//
%NS_E_WMPCORE_CURRENT_MEDIA_NOT_ACTIVE = &HC00D10A9&

'//
'// MessageId: NS_E_WMPCORE_USER_CANCEL
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action because you chose to cancel it.%0
'//
%NS_E_WMPCORE_USER_CANCEL         = &HC00D10AB&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_EMPTY
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem with the playlist. The format of the playlist is not valid.%0
'//
%NS_E_WMPCORE_PLAYLIST_REPEAT_EMPTY = &HC00D10AC&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_START_MEDIA_NONE
'//
'// MessageText:
'//
'// Media object corresponding to start of a playlist repeat block was not found.%0
'//
%NS_E_WMPCORE_PLAYLIST_REPEAT_START_MEDIA_NONE = &HC00D10AD&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_REPEAT_END_MEDIA_NONE
'//
'// MessageText:
'//
'// Media object corresponding to the end of a playlist repeat block was not found.%0
'//
%NS_E_WMPCORE_PLAYLIST_REPEAT_END_MEDIA_NONE = &HC00D10AE&

'//
'// MessageId: NS_E_WMPCORE_INVALID_PLAYLIST_URL
'//
'// MessageText:
'//
'// The playlist URL supplied to the playlist manager is not valid.%0
'//
%NS_E_WMPCORE_INVALID_PLAYLIST_URL = &HC00D10AF&

'//
'// MessageId: NS_E_WMPCORE_MISMATCHED_RUNTIME
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because it is corrupted.%0
'//
%NS_E_WMPCORE_MISMATCHED_RUNTIME  = &HC00D10B0&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_IMPORT_FAILED_NO_ITEMS
'//
'// MessageText:
'//
'// Windows Media Player cannot add the playlist to the library because the playlist does not contain any items.%0
'//
%NS_E_WMPCORE_PLAYLIST_IMPORT_FAILED_NO_ITEMS = &HC00D10B1&

'//
'// MessageId: NS_E_WMPCORE_VIDEO_TRANSFORM_FILTER_INSERTION
'//
'// MessageText:
'//
'// An error has occurred that could prevent the changing of the video contrast on this media.%0
'//
%NS_E_WMPCORE_VIDEO_TRANSFORM_FILTER_INSERTION = &HC00D10B2&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_UNAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. If the file is located on the Internet, connect to the Internet. If the file is located on a removable storage card, insert the storage card.%0
'//
%NS_E_WMPCORE_MEDIA_UNAVAILABLE   = &HC00D10B3&

'//
'// MessageId: NS_E_WMPCORE_WMX_ENTRYREF_NO_REF
'//
'// MessageText:
'//
'// The playlist contains an ENTRYREF for which no href was parsed. Check the syntax of playlist file.%0
'//
%NS_E_WMPCORE_WMX_ENTRYREF_NO_REF = &HC00D10B4&

'//
'// MessageId: NS_E_WMPCORE_NO_PLAYABLE_MEDIA_IN_PLAYLIST
'//
'// MessageText:
'//
'// Windows Media Player cannot play any items in the playlist. To find information about the problem, click the icon next to each file in the list pane.%0
'//
%NS_E_WMPCORE_NO_PLAYABLE_MEDIA_IN_PLAYLIST = &HC00D10B5&

'//
'// MessageId: NS_E_WMPCORE_PLAYLIST_EMPTY_NESTED_PLAYLIST_SKIPPED_ITEMS
'//
'// MessageText:
'//
'// Windows Media Player cannot play some or all of the items in the playlist because the playlist is nested.%0
'//
%NS_E_WMPCORE_PLAYLIST_EMPTY_NESTED_PLAYLIST_SKIPPED_ITEMS = &HC00D10B6&

'//
'// MessageId: NS_E_WMPCORE_BUSY
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file at this time. Try again later.%0
'//
%NS_E_WMPCORE_BUSY                = &HC00D10B7&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_CHILD_PLAYLIST_UNAVAILABLE
'//
'// MessageText:
'//
'// There is no child playlist available for this media item at this time.%0
'//
%NS_E_WMPCORE_MEDIA_CHILD_PLAYLIST_UNAVAILABLE = &HC00D10B8&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_NO_CHILD_PLAYLIST
'//
'// MessageText:
'//
'// There is no child playlist for this media item.%0
'//
%NS_E_WMPCORE_MEDIA_NO_CHILD_PLAYLIST = &HC00D10B9&

'//
'// MessageId: NS_E_WMPCORE_FILE_NOT_FOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot find the file. The link from the item in the library to its associated digital media file might be broken. To fix the problem, try repairing the link or removing the item from the library.%0
'//
%NS_E_WMPCORE_FILE_NOT_FOUND      = &HC00D10BA&

'//
'// MessageId: NS_E_WMPCORE_TEMP_FILE_NOT_FOUND
'//
'// MessageText:
'//
'// The temporary file was not found.%0
'//
%NS_E_WMPCORE_TEMP_FILE_NOT_FOUND = &HC00D10BB&

'//
'// MessageId: NS_E_WMDM_REVOKED
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because the device needs to be updated.%0
'//
%NS_E_WMDM_REVOKED                = &HC00D10BC&

'//
'// MessageId: NS_E_DDRAW_GENERIC
'//
'// MessageText:
'//
'// Windows Media Player cannot play the video because there is a problem with your video card.%0
'//
%NS_E_DDRAW_GENERIC               = &HC00D10BD&

'//
'// MessageId: NS_E_DISPLAY_MODE_CHANGE_FAILED
'//
'// MessageText:
'//
'// Windows Media Player failed to change the screen mode for full-screen video playback.%0
'//
%NS_E_DISPLAY_MODE_CHANGE_FAILED  = &HC00D10BE&

'//
'// MessageId: NS_E_PLAYLIST_CONTAINS_ERRORS
'//
'// MessageText:
'//
'// Windows Media Player cannot play one or more files.  For additional information, right-click an item that cannot be played, and then click Error Details.%0
'//
%NS_E_PLAYLIST_CONTAINS_ERRORS    = &HC00D10BF&

'//
'// MessageId: NS_E_CHANGING_PROXY_NAME
'//
'// MessageText:
'//
'// Cannot change the proxy name if the proxy setting is not set to custom.%0
'//
%NS_E_CHANGING_PROXY_NAME         = &HC00D10C0&

'//
'// MessageId: NS_E_CHANGING_PROXY_PORT
'//
'// MessageText:
'//
'// Cannot change the proxy port if the proxy setting is not set to custom.%0
'//
%NS_E_CHANGING_PROXY_PORT         = &HC00D10C1&

'//
'// MessageId: NS_E_CHANGING_PROXY_EXCEPTIONLIST
'//
'// MessageText:
'//
'// Cannot change the proxy exception list if the proxy setting is not set to custom.%0
'//
%NS_E_CHANGING_PROXY_EXCEPTIONLIST = &HC00D10C2&

'//
'// MessageId: NS_E_CHANGING_PROXYBYPASS
'//
'// MessageText:
'//
'// Cannot change the proxy bypass flag if the proxy setting is not set to custom.%0
'//
%NS_E_CHANGING_PROXYBYPASS        = &HC00D10C3&

'//
'// MessageId: NS_E_CHANGING_PROXY_PROTOCOL_NOT_FOUND
'//
'// MessageText:
'//
'// Cannot find the specified protocol.%0
'//
%NS_E_CHANGING_PROXY_PROTOCOL_NOT_FOUND = &HC00D10C4&

'//
'// MessageId: NS_E_GRAPH_NOAUDIOLANGUAGE
'//
'// MessageText:
'//
'// Cannot change the language settings. Either the graph has no audio or the audio only supports one language.%0
'//
%NS_E_GRAPH_NOAUDIOLANGUAGE       = &HC00D10C5&

'//
'// MessageId: NS_E_GRAPH_NOAUDIOLANGUAGESELECTED
'//
'// MessageText:
'//
'// The graph has no audio language selected.%0
'//
%NS_E_GRAPH_NOAUDIOLANGUAGESELECTED = &HC00D10C6&

'//
'// MessageId: NS_E_CORECD_NOTAMEDIACD
'//
'// MessageText:
'//
'// This is not a media CD.%0
'//
%NS_E_CORECD_NOTAMEDIACD          = &HC00D10C7&

'//
'// MessageId: NS_E_WMPCORE_MEDIA_URL_TOO_LONG
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the URL is too long.%0
'//
%NS_E_WMPCORE_MEDIA_URL_TOO_LONG  = &HC00D10C8&

'//
'// MessageId: NS_E_WMPFLASH_CANT_FIND_COM_SERVER
'//
'// MessageText:
'//
'// To play the selected item, you must install the Adobe Flash Player. To download the Adobe Flash Player, go to the Adobe Web site.%0
'//
%NS_E_WMPFLASH_CANT_FIND_COM_SERVER = &HC00D10C9&

'//
'// MessageId: NS_E_WMPFLASH_INCOMPATIBLEVERSION
'//
'// MessageText:
'//
'// To play the selected item, you must install a later version of the Adobe Flash Player. To download the Adobe Flash Player, go to the Adobe website.%0
'//
%NS_E_WMPFLASH_INCOMPATIBLEVERSION = &HC00D10CA&

'//
'// MessageId: NS_E_WMPOCXGRAPH_IE_DISALLOWS_ACTIVEX_CONTROLS
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because your Internet security settings prohibit the use of ActiveX controls.%0
'//
%NS_E_WMPOCXGRAPH_IE_DISALLOWS_ACTIVEX_CONTROLS = &HC00D10CB&

'//
'// MessageId: NS_E_NEED_CORE_REFERENCE
'//
'// MessageText:
'//
'// The use of this method requires an existing reference to the Player object.%0
'//
%NS_E_NEED_CORE_REFERENCE         = &HC00D10CC&

'//
'// MessageId: NS_E_MEDIACD_READ_ERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot play the CD. The disc might be dirty or damaged.%0
'//
%NS_E_MEDIACD_READ_ERROR          = &HC00D10CD&

'//
'// MessageId: NS_E_IE_DISALLOWS_ACTIVEX_CONTROLS
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because your Internet security settings prohibit the use of ActiveX controls.%0
'//
%NS_E_IE_DISALLOWS_ACTIVEX_CONTROLS = &HC00D10CE&

'//
'// MessageId: NS_E_FLASH_PLAYBACK_NOT_ALLOWED
'//
'// MessageText:
'//
'// Flash playback has been turned off in Windows Media Player.%0
'//
%NS_E_FLASH_PLAYBACK_NOT_ALLOWED  = &HC00D10CF&

'//
'// MessageId: NS_E_UNABLE_TO_CREATE_RIP_LOCATION
'//
'// MessageText:
'//
'// Windows Media Player cannot rip the CD because a valid rip location cannot be created.%0
'//
%NS_E_UNABLE_TO_CREATE_RIP_LOCATION = &HC00D10D0&

'//
'// MessageId: NS_E_WMPCORE_SOME_CODECS_MISSING
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because a required codec is not installed on your computer.%0
'//
%NS_E_WMPCORE_SOME_CODECS_MISSING = &HC00D10D1&

'//
'// MessageId: NS_E_WMP_RIP_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot rip one or more tracks from the CD.%0
'//
%NS_E_WMP_RIP_FAILED              = &HC00D10D2&

'//
'// MessageId: NS_E_WMP_FAILED_TO_RIP_TRACK
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while ripping the track from the CD.%0
'//
%NS_E_WMP_FAILED_TO_RIP_TRACK     = &HC00D10D3&

'//
'// MessageId: NS_E_WMP_ERASE_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while erasing the disc.%0
'//
%NS_E_WMP_ERASE_FAILED            = &HC00D10D4&

'//
'// MessageId: NS_E_WMP_FORMAT_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while formatting the device.%0
'//
%NS_E_WMP_FORMAT_FAILED           = &HC00D10D5&

'//
'// MessageId: NS_E_WMP_CANNOT_BURN_NON_LOCAL_FILE
'//
'// MessageText:
'//
'// This file cannot be burned to a CD because it is not located on your computer.%0
'//
%NS_E_WMP_CANNOT_BURN_NON_LOCAL_FILE = &HC00D10D6&

'//
'// MessageId: NS_E_WMP_FILE_TYPE_CANNOT_BURN_TO_AUDIO_CD
'//
'// MessageText:
'//
'// It is not possible to burn this file type to an audio CD. Windows Media Player can burn the following file types to an audio CD: WMA, MP3, or WAV.%0
'//
%NS_E_WMP_FILE_TYPE_CANNOT_BURN_TO_AUDIO_CD = &HC00D10D7&

'//
'// MessageId: NS_E_WMP_FILE_DOES_NOT_FIT_ON_CD
'//
'// MessageText:
'//
'// This file is too large to fit on a disc.%0
'//
%NS_E_WMP_FILE_DOES_NOT_FIT_ON_CD = &HC00D10D8&

'//
'// MessageId: NS_E_WMP_FILE_NO_DURATION
'//
'// MessageText:
'//
'// It is not possible to determine if this file can fit on a disc because Windows Media Player cannot detect the length of the file. Playing the file before burning might enable the Player to detect the file length.%0
'//
%NS_E_WMP_FILE_NO_DURATION        = &HC00D10D9&

'//
'// MessageId: NS_E_PDA_FAILED_TO_BURN
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while burning the file to the disc.%0
'//
%NS_E_PDA_FAILED_TO_BURN          = &HC00D10DA&

'//
'// MessageId: NS_S_NEED_TO_BUY_BURN_RIGHTS
'//
'// MessageText:
'//
'// No burn rights. You will be prompted to buy burn rights when you try to burn this file to an audio CD.%0
'//
%NS_S_NEED_TO_BUY_BURN_RIGHTS     = &H000D10DB&

'//
'// MessageId: NS_E_FAILED_DOWNLOAD_ABORT_BURN
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the audio CD because some items in the list that you chose to buy could not be downloaded from the online store.%0
'//
%NS_E_FAILED_DOWNLOAD_ABORT_BURN  = &HC00D10DC&

'//
'// MessageId: NS_E_WMPCORE_DEVICE_DRIVERS_MISSING
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. Try using Windows Update or Device Manager to update the device drivers for your audio and video cards. For information about using Windows Update or Device Manager, see Windows Help.%0
'//
%NS_E_WMPCORE_DEVICE_DRIVERS_MISSING = &HC00D10DD&

'//
'// WMP Core  Success codes
'//
'//
'// MessageId: NS_S_WMPCORE_PLAYLISTCLEARABORT
'//
'// MessageText:
'//
'// Failed to clear playlist because it was aborted by user.%0
'//
%NS_S_WMPCORE_PLAYLISTCLEARABORT  = &H000D10FE&

'//
'// MessageId: NS_S_WMPCORE_PLAYLISTREMOVEITEMABORT
'//
'// MessageText:
'//
'// Failed to remove item in the playlist since it was aborted by user.%0
'//
%NS_S_WMPCORE_PLAYLISTREMOVEITEMABORT = &H000D10FF&

'//
'// MessageId: NS_S_WMPCORE_PLAYLIST_CREATION_PENDING
'//
'// MessageText:
'//
'// Playlist is being generated asynchronously.%0
'//
%NS_S_WMPCORE_PLAYLIST_CREATION_PENDING = &H000D1102&

'//
'// MessageId: NS_S_WMPCORE_MEDIA_VALIDATION_PENDING
'//
'// MessageText:
'//
'// Validation of the media is pending...%0
'//
%NS_S_WMPCORE_MEDIA_VALIDATION_PENDING = &H000D1103&

'//
'// MessageId: NS_S_WMPCORE_PLAYLIST_REPEAT_SECONDARY_SEGMENTS_IGNORED
'//
'// MessageText:
'//
'// Encountered more than one Repeat block during ASX processing.%0
'//
%NS_S_WMPCORE_PLAYLIST_REPEAT_SECONDARY_SEGMENTS_IGNORED = &H000D1104&

'//
'// MessageId: NS_S_WMPCORE_COMMAND_NOT_AVAILABLE
'//
'// MessageText:
'//
'// Current state of WMP disallows calling this method or property.%0
'//
%NS_S_WMPCORE_COMMAND_NOT_AVAILABLE = &H000D1105&

'//
'// MessageId: NS_S_WMPCORE_PLAYLIST_NAME_AUTO_GENERATED
'//
'// MessageText:
'//
'// Name for the playlist has been auto generated.%0
'//
%NS_S_WMPCORE_PLAYLIST_NAME_AUTO_GENERATED = &H000D1106&

'//
'// MessageId: NS_S_WMPCORE_PLAYLIST_IMPORT_MISSING_ITEMS
'//
'// MessageText:
'//
'// The imported playlist does not contain all items from the original.%0
'//
%NS_S_WMPCORE_PLAYLIST_IMPORT_MISSING_ITEMS = &H000D1107&

'//
'// MessageId: NS_S_WMPCORE_PLAYLIST_COLLAPSED_TO_SINGLE_MEDIA
'//
'// MessageText:
'//
'// The M3U playlist has been ignored because it only contains one item.%0
'//
%NS_S_WMPCORE_PLAYLIST_COLLAPSED_TO_SINGLE_MEDIA = &H000D1108&

'//
'// MessageId: NS_S_WMPCORE_MEDIA_CHILD_PLAYLIST_OPEN_PENDING
'//
'// MessageText:
'//
'// The open for the child playlist associated with this media is pending.%0
'//
%NS_S_WMPCORE_MEDIA_CHILD_PLAYLIST_OPEN_PENDING = &H000D1109&

'//
'// MessageId: NS_S_WMPCORE_MORE_NODES_AVAIABLE
'//
'// MessageText:
'//
'// More nodes support the interface requested, but the array for returning them is full.%0
'//
%NS_S_WMPCORE_MORE_NODES_AVAIABLE = &H000D110A&

'//
'// WMP Internet Manager error codes
'//
'//
'// MessageId: NS_E_WMPIM_USEROFFLINE
'//
'// MessageText:
'//
'// Windows Media Player has detected that you are not connected to the Internet. Connect to the Internet, and then try again.%0
'//
%NS_E_WMPIM_USEROFFLINE           = &HC00D1126&

'//
'// MessageId: NS_E_WMPIM_USERCANCELED
'//
'// MessageText:
'//
'// The attempt to connect to the Internet was canceled.%0
'//
%NS_E_WMPIM_USERCANCELED          = &HC00D1127&

'//
'// MessageId: NS_E_WMPIM_DIALUPFAILED
'//
'// MessageText:
'//
'// The attempt to connect to the Internet failed.%0
'//
%NS_E_WMPIM_DIALUPFAILED          = &HC00D1128&

'//
'// MessageId: NS_E_WINSOCK_ERROR_STRING
'//
'// MessageText:
'//
'// Windows Media Player has encountered an unknown network error.%0
'//
%NS_E_WINSOCK_ERROR_STRING        = &HC00D1129&

'//
'// WMP Backup and restore error and success codes
'//
'//
'// MessageId: NS_E_WMPBR_NOLISTENER
'//
'// MessageText:
'//
'// No window is currently listening to Backup and Restore events.%0
'//
%NS_E_WMPBR_NOLISTENER            = &HC00D1130&

'//
'// MessageId: NS_E_WMPBR_BACKUPCANCEL
'//
'// MessageText:
'//
'// Your media usage rights were not backed up because the backup was canceled.%0
'//
%NS_E_WMPBR_BACKUPCANCEL          = &HC00D1131&

'//
'// MessageId: NS_E_WMPBR_RESTORECANCEL
'//
'// MessageText:
'//
'// Your media usage rights were not restored because the restoration was canceled.%0
'//
%NS_E_WMPBR_RESTORECANCEL         = &HC00D1132&

'//
'// MessageId: NS_E_WMPBR_ERRORWITHURL
'//
'// MessageText:
'//
'// An error occurred while backing up or restoring your media usage rights. A required web page cannot be displayed.%0
'//
%NS_E_WMPBR_ERRORWITHURL          = &HC00D1133&

'//
'// MessageId: NS_E_WMPBR_NAMECOLLISION
'//
'// MessageText:
'//
'// Your media usage rights were not backed up because the backup was canceled.%0
'//
%NS_E_WMPBR_NAMECOLLISION         = &HC00D1134&

'//
'// MessageId: NS_S_WMPBR_SUCCESS
'//
'// MessageText:
'//
'// Backup or Restore successful!.%0
'//
%NS_S_WMPBR_SUCCESS               = &H000D1135&

'//
'// MessageId: NS_S_WMPBR_PARTIALSUCCESS
'//
'// MessageText:
'//
'// Transfer complete with limitations.%0
'//
%NS_S_WMPBR_PARTIALSUCCESS        = &H000D1136&

'//
'// MessageId: NS_E_WMPBR_DRIVE_INVALID
'//
'// MessageText:
'//
'// Windows Media Player cannot restore your media usage rights from the specified location. Choose another location, and then try again.%0
'//
%NS_E_WMPBR_DRIVE_INVALID         = &HC00D1137&

'//
'// MessageId: NS_E_WMPBR_BACKUPRESTOREFAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot backup or restore your media usage rights.%0
'//
%NS_E_WMPBR_BACKUPRESTOREFAILED   = &HC00D1138&

'//
'// WMP Effects Success codes
'//
'//
'// MessageId: NS_S_WMPEFFECT_TRANSPARENT
'//
'// MessageText:
'//
'// Request to the effects control to change transparency status to transparent.%0
'//
%NS_S_WMPEFFECT_TRANSPARENT       = &H000D1144&

'//
'// MessageId: NS_S_WMPEFFECT_OPAQUE
'//
'// MessageText:
'//
'// Request to the effects control to change transparency status to opaque.%0
'//
%NS_S_WMPEFFECT_OPAQUE            = &H000D1145&

'//
'// WMP Application Success codes
'//
'//
'// MessageId: NS_S_OPERATION_PENDING
'//
'// MessageText:
'//
'// The requested application pane is performing an operation and will not be released.%0
'//
%NS_S_OPERATION_PENDING           = &H000D114E&

'//
'// WMP Convert Plugin error codes
'//
'//
'// MessageId: NS_E_WMP_CONVERT_FILE_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library.%0
'//
%NS_E_WMP_CONVERT_FILE_FAILED     = &HC00D1158&

'//
'// MessageId: NS_E_WMP_CONVERT_NO_RIGHTS_ERRORURL
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library because the content provider prohibits it. For assistance, contact the company that provided the file.%0
'//
%NS_E_WMP_CONVERT_NO_RIGHTS_ERRORURL = &HC00D1159&

'//
'// MessageId: NS_E_WMP_CONVERT_NO_RIGHTS_NOERRORURL
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library because the content provider prohibits it. For assistance, contact the company that provided the file.%0
'//
%NS_E_WMP_CONVERT_NO_RIGHTS_NOERRORURL = &HC00D115A&

'//
'// MessageId: NS_E_WMP_CONVERT_FILE_CORRUPT
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library. The file might not be valid.%0
'//
%NS_E_WMP_CONVERT_FILE_CORRUPT    = &HC00D115B&

'//
'// MessageId: NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_ERRORURL
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library. The plug-in required to add the file is not installed properly. For assistance, click Web Help to display the website of the company that provided the file.%0
'//
%NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_ERRORURL = &HC00D115C&

'//
'// MessageId: NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_NOERRORURL
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library. The plug-in required to add the file is not installed properly. For assistance, contact the company that provided the file.%0
'//
%NS_E_WMP_CONVERT_PLUGIN_UNAVAILABLE_NOERRORURL = &HC00D115D&

'//
'// MessageId: NS_E_WMP_CONVERT_PLUGIN_UNKNOWN_FILE_OWNER
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library. The plug-in required to add the file is not installed properly. For assistance, contact the company that provided the file.%0
'//
%NS_E_WMP_CONVERT_PLUGIN_UNKNOWN_FILE_OWNER = &HC00D115E&

'//
'// WMP DVD Error Codes
'//
'//
'// MessageId: NS_E_DVD_DISC_COPY_PROTECT_OUTPUT_NS
'//
'// MessageText:
'//
'// Windows Media Player cannot play this DVD. Try installing an updated driver for your video card or obtaining a newer video card.%0
'//
%NS_E_DVD_DISC_COPY_PROTECT_OUTPUT_NS = &HC00D1160&

'//
'// MessageId: NS_E_DVD_DISC_COPY_PROTECT_OUTPUT_FAILED
'//
'// MessageText:
'//
'// This DVD's resolution exceeds the maximum allowed by your component video outputs. Try reducing your screen resolution to 640 x 480, or turn off analog component outputs and use a VGA connection to your monitor.%0
'//
%NS_E_DVD_DISC_COPY_PROTECT_OUTPUT_FAILED = &HC00D1161&

'//
'// MessageId: NS_E_DVD_NO_SUBPICTURE_STREAM
'//
'// MessageText:
'//
'// Windows Media Player cannot display subtitles or highlights in DVD menus. Reinstall the DVD decoder or contact the DVD drive manufacturer to obtain an updated decoder.%0
'//
%NS_E_DVD_NO_SUBPICTURE_STREAM    = &HC00D1162&

'//
'// MessageId: NS_E_DVD_COPY_PROTECT
'//
'// MessageText:
'//
'// Windows Media Player cannot play this DVD because there is a problem with digital copy protection between your DVD drive, decoder, and video card. Try installing an updated driver for your video card.%0
'//
%NS_E_DVD_COPY_PROTECT            = &HC00D1163&

'//
'// MessageId: NS_E_DVD_AUTHORING_PROBLEM
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD. The disc was created in a manner that the Player does not support.%0
'//
%NS_E_DVD_AUTHORING_PROBLEM       = &HC00D1164&

'//
'// MessageId: NS_E_DVD_INVALID_DISC_REGION
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because the disc prohibits playback in your region of the world. You must obtain a disc that is intended for your geographic region.%0
'//
%NS_E_DVD_INVALID_DISC_REGION     = &HC00D1165&

'//
'// MessageId: NS_E_DVD_COMPATIBLE_VIDEO_CARD
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because your video card does not support DVD playback.%0
'//
%NS_E_DVD_COMPATIBLE_VIDEO_CARD   = &HC00D1166&

'//
'// MessageId: NS_E_DVD_MACROVISION
'//
'// MessageText:
'//
'// Windows Media Player cannot play this DVD because it is not possible to turn on analog copy protection on the output display. Try installing an updated driver for your video card.%0
'//
%NS_E_DVD_MACROVISION             = &HC00D1167&

'//
'// MessageId: NS_E_DVD_SYSTEM_DECODER_REGION
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because the region assigned to your DVD drive does not match the region assigned to your DVD decoder.%0
'//
%NS_E_DVD_SYSTEM_DECODER_REGION   = &HC00D1168&

'//
'// MessageId: NS_E_DVD_DISC_DECODER_REGION
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because the disc prohibits playback in your region of the world. You must obtain a disc that is intended for your geographic region.%0
'//
%NS_E_DVD_DISC_DECODER_REGION     = &HC00D1169&

'//
'// MessageId: NS_E_DVD_NO_VIDEO_STREAM
'//
'// MessageText:
'//
'// Windows Media Player cannot play DVD video. You might need to adjust your Windows display settings. Open display settings in Control Panel, and then try lowering your screen resolution and color quality settings.%0
'//
%NS_E_DVD_NO_VIDEO_STREAM         = &HC00D116A&

'//
'// MessageId: NS_E_DVD_NO_AUDIO_STREAM
'//
'// MessageText:
'//
'// Windows Media Player cannot play DVD audio. Verify that your sound card is set up correctly, and then try again.%0
'//
%NS_E_DVD_NO_AUDIO_STREAM         = &HC00D116B&

'//
'// MessageId: NS_E_DVD_GRAPH_BUILDING
'//
'// MessageText:
'//
'// Windows Media Player cannot play DVD video. Close any open files and quit any other programs, and then try again. If the problem persists, restart your computer.%0
'//
%NS_E_DVD_GRAPH_BUILDING          = &HC00D116C&

'//
'// MessageId: NS_E_DVD_NO_DECODER
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because a compatible DVD decoder is not installed on your computer.%0
'//
%NS_E_DVD_NO_DECODER              = &HC00D116D&

'//
'// MessageId: NS_E_DVD_PARENTAL
'//
'// MessageText:
'//
'// Windows Media Player cannot play the scene because it has a parental rating higher than the rating that you are authorized to view.%0
'//
%NS_E_DVD_PARENTAL                = &HC00D116E&

'//
'// MessageId: NS_E_DVD_CANNOT_JUMP
'//
'// MessageText:
'//
'// Windows Media Player cannot skip to the requested location on the DVD.%0
'//
%NS_E_DVD_CANNOT_JUMP             = &HC00D116F&

'//
'// MessageId: NS_E_DVD_DEVICE_CONTENTION
'//
'// MessageText:
'//
'// Windows Media Player cannot play the DVD because it is currently in use by another program. Quit the other program that is using the DVD, and then try again.%0
'//
%NS_E_DVD_DEVICE_CONTENTION       = &HC00D1170&

'//
'// MessageId: NS_E_DVD_NO_VIDEO_MEMORY
'//
'// MessageText:
'//
'// Windows Media Player cannot play DVD video. You might need to adjust your Windows display settings. Open display settings in Control Panel, and then try lowering your screen resolution and color quality settings.%0
'//
%NS_E_DVD_NO_VIDEO_MEMORY         = &HC00D1171&

'//
'// MessageId: NS_E_DVD_CANNOT_COPY_PROTECTED
'//
'// MessageText:
'//
'// Windows Media Player cannot rip the DVD because it is copy protected.%0
'//
%NS_E_DVD_CANNOT_COPY_PROTECTED   = &HC00D1172&

'//
'// MessageId: NS_E_DVD_REQUIRED_PROPERTY_NOT_SET
'//
'// MessageText:
'//
'// One of more of the required properties has not been set.%0
'//
%NS_E_DVD_REQUIRED_PROPERTY_NOT_SET = &HC00D1173&

'//
'// MessageId: NS_E_DVD_INVALID_TITLE_CHAPTER
'//
'// MessageText:
'//
'// The specified title and/or chapter number does not exist on this DVD.%0
'//
%NS_E_DVD_INVALID_TITLE_CHAPTER   = &HC00D1174&

'//
'// WMP PDA Error codes
'//
'//
'// MessageId: NS_E_NO_CD_BURNER
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files because the Player cannot find a burner. If the burner is connected properly, try using Windows Update to install the latest device driver.%0
'//
%NS_E_NO_CD_BURNER                = &HC00D1176&

'//
'// MessageId: NS_E_DEVICE_IS_NOT_READY
'//
'// MessageText:
'//
'// Windows Media Player does not detect storage media in the selected device. Insert storage media into the device, and then try again.%0
'//
%NS_E_DEVICE_IS_NOT_READY         = &HC00D1177&

'//
'// MessageId: NS_E_PDA_UNSUPPORTED_FORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot sync this file. The Player might not support the file type.%0
'//
%NS_E_PDA_UNSUPPORTED_FORMAT      = &HC00D1178&

'//
'// MessageId: NS_E_NO_PDA
'//
'// MessageText:
'//
'// Windows Media Player does not detect a portable device. Connect your portable device, and then try again.%0
'//
%NS_E_NO_PDA                      = &HC00D1179&

'//
'// MessageId: NS_E_PDA_UNSPECIFIED_ERROR
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while communicating with the device. The storage card on the device might be full, the device might be turned off, or the device might not allow playlists or folders to be created on it.%0
'//
%NS_E_PDA_UNSPECIFIED_ERROR       = &HC00D117A&

'//
'// MessageId: NS_E_MEMSTORAGE_BAD_DATA
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while burning a CD.%0
'//
%NS_E_MEMSTORAGE_BAD_DATA         = &HC00D117B&

'//
'// MessageId: NS_E_PDA_FAIL_SELECT_DEVICE
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while communicating with a portable device or CD drive.%0
'//
%NS_E_PDA_FAIL_SELECT_DEVICE      = &HC00D117C&

'//
'// MessageId: NS_E_PDA_FAIL_READ_WAVE_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot open the WAV file.%0
'//
%NS_E_PDA_FAIL_READ_WAVE_FILE     = &HC00D117D&

'//
'// MessageId: NS_E_IMAPI_LOSSOFSTREAMING
'//
'// MessageText:
'//
'// Windows Media Player failed to burn all the files to the CD. Select a slower recording speed, and then try again.%0
'//
%NS_E_IMAPI_LOSSOFSTREAMING       = &HC00D117E&

'//
'// MessageId: NS_E_PDA_DEVICE_FULL
'//
'// MessageText:
'//
'// There is not enough storage space on the portable device to complete this operation. Delete some unneeded files on the portable device, and then try again.%0
'//
%NS_E_PDA_DEVICE_FULL             = &HC00D117F&

'//
'// MessageId: NS_E_FAIL_LAUNCH_ROXIO_PLUGIN
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files. Verify that your burner is connected properly, and then try again. If the problem persists, reinstall the Player.%0
'//
%NS_E_FAIL_LAUNCH_ROXIO_PLUGIN    = &HC00D1180&

'//
'// MessageId: NS_E_PDA_DEVICE_FULL_IN_SESSION
'//
'// MessageText:
'//
'// Windows Media Player did not sync some files to the device because there is not enough storage space on the device.%0
'//
%NS_E_PDA_DEVICE_FULL_IN_SESSION  = &HC00D1181&

'//
'// MessageId: NS_E_IMAPI_MEDIUM_INVALIDTYPE
'//
'// MessageText:
'//
'// The disc in the burner is not valid. Insert a blank disc into the burner, and then try again.%0
'//
%NS_E_IMAPI_MEDIUM_INVALIDTYPE    = &HC00D1182&

'//
'// MessageId: NS_E_PDA_MANUALDEVICE
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action because the device does not support sync.%0
'//
%NS_E_PDA_MANUALDEVICE            = &HC00D1183&

'//
'// MessageId: NS_E_PDA_PARTNERSHIPNOTEXIST
'//
'// MessageText:
'//
'// To perform the requested action, you must first set up sync with the device.%0
'//
%NS_E_PDA_PARTNERSHIPNOTEXIST     = &HC00D1184&

'//
'// MessageId: NS_E_PDA_CANNOT_CREATE_ADDITIONAL_SYNC_RELATIONSHIP
'//
'// MessageText:
'//
'// You have already created sync partnerships with 16 devices. To create a new sync partnership, you must first end an existing partnership.%0
'//
%NS_E_PDA_CANNOT_CREATE_ADDITIONAL_SYNC_RELATIONSHIP = &HC00D1185&

'//
'// MessageId: NS_E_PDA_NO_TRANSCODE_OF_DRM
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because protected files cannot be converted to the required quality level or file format.%0
'//
%NS_E_PDA_NO_TRANSCODE_OF_DRM     = &HC00D1186&

'//
'// MessageId: NS_E_PDA_TRANSCODECACHEFULL
'//
'// MessageText:
'//
'// The folder that stores converted files is full. Either empty the folder or increase its size, and then try again.%0
'//
%NS_E_PDA_TRANSCODECACHEFULL      = &HC00D1187&

'//
'// MessageId: NS_E_PDA_TOO_MANY_FILE_COLLISIONS
'//
'// MessageText:
'//
'// There are too many files with the same name in the folder on the device. Change the file name or sync to a different folder.%0
'//
%NS_E_PDA_TOO_MANY_FILE_COLLISIONS = &HC00D1188&

'//
'// MessageId: NS_E_PDA_CANNOT_TRANSCODE
'//
'// MessageText:
'//
'// Windows Media Player cannot convert the file to the format required by the device.%0
'//
%NS_E_PDA_CANNOT_TRANSCODE        = &HC00D1189&

'//
'// MessageId: NS_E_PDA_TOO_MANY_FILES_IN_DIRECTORY
'//
'// MessageText:
'//
'// You have reached the maximum number of files your device allows in a folder. If your device supports playback from subfolders, try creating subfolders on the device and storing some files in them.%0
'//
%NS_E_PDA_TOO_MANY_FILES_IN_DIRECTORY = &HC00D118A&

'//
'// MessageId: NS_E_PROCESSINGSHOWSYNCWIZARD
'//
'// MessageText:
'//
'// Windows Media Player is already trying to start the Device Setup Wizard.%0
'//
%NS_E_PROCESSINGSHOWSYNCWIZARD    = &HC00D118B&

'//
'// MessageId: NS_E_PDA_TRANSCODE_NOT_PERMITTED
'//
'// MessageText:
'//
'// Windows Media Player cannot convert this file format. If an updated version of the codec used to compress this file is available, install it and then try to sync the file again.%0
'//
%NS_E_PDA_TRANSCODE_NOT_PERMITTED = &HC00D118C&

'//
'// MessageId: NS_E_PDA_INITIALIZINGDEVICES
'//
'// MessageText:
'//
'// Windows Media Player is busy setting up devices. Try again later.%0
'//
%NS_E_PDA_INITIALIZINGDEVICES     = &HC00D118D&

'//
'// MessageId: NS_E_PDA_OBSOLETE_SP
'//
'// MessageText:
'//
'// Your device is using an outdated driver that is no longer supported by Windows Media Player.%0
'//
%NS_E_PDA_OBSOLETE_SP             = &HC00D118E&

'//
'// MessageId: NS_E_PDA_TITLE_COLLISION
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because a file with the same name already exists on the device. Change the file name or try to sync the file to a different folder.%0
'//
%NS_E_PDA_TITLE_COLLISION         = &HC00D118F&

'//
'// MessageId: NS_E_PDA_DEVICESUPPORTDISABLED
'//
'// MessageText:
'//
'// Automatic and manual sync have been turned off temporarily. To sync to a device, restart Windows Media Player.%0
'//
%NS_E_PDA_DEVICESUPPORTDISABLED   = &HC00D1190&

'//
'// MessageId: NS_E_PDA_NO_LONGER_AVAILABLE
'//
'// MessageText:
'//
'// This device is not available. Connect the device to the computer, and then try again.%0
'//
%NS_E_PDA_NO_LONGER_AVAILABLE     = &HC00D1191&

'//
'// MessageId: NS_E_PDA_ENCODER_NOT_RESPONDING
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because an error occurred while converting the file to another quality level or format. If the problem persists, remove the file from the list of files to sync.%0
'//
%NS_E_PDA_ENCODER_NOT_RESPONDING  = &HC00D1192&

'//
'// MessageId: NS_E_PDA_CANNOT_SYNC_FROM_LOCATION
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file to your device. The file might be stored in a location that is not supported. Copy the file from its current location to your hard disk, add it to your library, and then try to sync the file again.%0
'//
%NS_E_PDA_CANNOT_SYNC_FROM_LOCATION = &HC00D1193&

'//
'// General Remapped Error codes in WMP
'//
'//
'// MessageId: NS_E_WMP_PROTOCOL_PROBLEM
'//
'// MessageText:
'//
'// Windows Media Player cannot open the specified URL. Verify that the Player is configured to use all available protocols, and then try again.%0
'//
%NS_E_WMP_PROTOCOL_PROBLEM        = &HC00D1194&

'//
'// MessageId: NS_E_WMP_NO_DISK_SPACE
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action because there is not enough storage space on your computer. Delete some unneeded files on your hard disk, and then try again.%0
'//
%NS_E_WMP_NO_DISK_SPACE           = &HC00D1195&

'//
'// MessageId: NS_E_WMP_LOGON_FAILURE
'//
'// MessageText:
'//
'// The server denied access to the file. Verify that you are using the correct user name and password.%0
'//
%NS_E_WMP_LOGON_FAILURE           = &HC00D1196&

'//
'// MessageId: NS_E_WMP_CANNOT_FIND_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot find the file. If you are trying to play, burn, or sync an item that is in your library, the item might point to a file that has been moved, renamed, or deleted.%0
'//
%NS_E_WMP_CANNOT_FIND_FILE        = &HC00D1197&

'//
'// MessageId: NS_E_WMP_SERVER_INACCESSIBLE
'//
'// MessageText:
'//
'// Windows Media Player cannot connect to the server. The server name might not be correct, the server might not be available, or your proxy settings might not be correct.%0
'//
%NS_E_WMP_SERVER_INACCESSIBLE     = &HC00D1198&

'//
'// MessageId: NS_E_WMP_UNSUPPORTED_FORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The Player might not support the file type or might not support the codec that was used to compress the file.%0
'//
%NS_E_WMP_UNSUPPORTED_FORMAT      = &HC00D1199&

'//
'// MessageId: NS_E_WMP_DSHOW_UNSUPPORTED_FORMAT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The Player might not support the file type or a required codec might not be installed on your computer.%0
'//
%NS_E_WMP_DSHOW_UNSUPPORTED_FORMAT = &HC00D119A&

'//
'// MessageId: NS_E_WMP_PLAYLIST_EXISTS
'//
'// MessageText:
'//
'// Windows Media Player cannot create the playlist because the name already exists. Type a different playlist name.%0
'//
%NS_E_WMP_PLAYLIST_EXISTS         = &HC00D119B&

'//
'// MessageId: NS_E_WMP_NONMEDIA_FILES
'//
'// MessageText:
'//
'// Windows Media Player cannot delete the playlist because it contains items that are not digital media files. Any digital media files in the playlist were deleted.%0
'//
%NS_E_WMP_NONMEDIA_FILES          = &HC00D119C&

'//
'// MessageId: NS_E_WMP_INVALID_ASX
'//
'// MessageText:
'//
'// The playlist cannot be opened because it is stored in a shared folder on another computer. If possible, move the playlist to the playlists folder on your computer.%0
'//
%NS_E_WMP_INVALID_ASX             = &HC00D119D&

'//
'// MessageId: NS_E_WMP_ALREADY_IN_USE
'//
'// MessageText:
'//
'// Windows Media Player is already in use. Stop playing any items, close all Player dialog boxes, and then try again.%0
'//
%NS_E_WMP_ALREADY_IN_USE          = &HC00D119E&

'//
'// MessageId: NS_E_WMP_IMAPI_FAILURE
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while burning. Verify that the burner is connected properly and that the disc is clean and not damaged.%0
'//
%NS_E_WMP_IMAPI_FAILURE           = &HC00D119F&

'//
'// MessageId: NS_E_WMP_WMDM_FAILURE
'//
'// MessageText:
'//
'// Windows Media Player has encountered an unknown error with your portable device. Reconnect your portable device, and then try again.%0
'//
%NS_E_WMP_WMDM_FAILURE            = &HC00D11A0&

'//
'// MessageId: NS_E_WMP_CODEC_NEEDED_WITH_4CC
'//
'// MessageText:
'//
'// A codec is required to play this file. To determine if this codec is available to download from the web, click Web Help.%0
'//
%NS_E_WMP_CODEC_NEEDED_WITH_4CC   = &HC00D11A1&

'//
'// MessageId: NS_E_WMP_CODEC_NEEDED_WITH_FORMATTAG
'//
'// MessageText:
'//
'// An audio codec is needed to play this file. To determine if this codec is available to download from the web, click Web Help.%0
'//
%NS_E_WMP_CODEC_NEEDED_WITH_FORMATTAG = &HC00D11A2&

'//
'// MessageId: NS_E_WMP_MSSAP_NOT_AVAILABLE
'//
'// MessageText:
'//
'// To play the file, you must install the latest Windows service pack. To install the service pack from the Windows Update website, click Web Help.%0
'//
%NS_E_WMP_MSSAP_NOT_AVAILABLE     = &HC00D11A3&

'//
'// MessageId: NS_E_WMP_WMDM_INTERFACEDEAD
'//
'// MessageText:
'//
'// Windows Media Player no longer detects a portable device. Reconnect your portable device, and then try again.%0
'//
%NS_E_WMP_WMDM_INTERFACEDEAD      = &HC00D11A4&

'//
'// MessageId: NS_E_WMP_WMDM_NOTCERTIFIED
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because the portable device does not support protected files.%0
'//
%NS_E_WMP_WMDM_NOTCERTIFIED       = &HC00D11A5&

'//
'// MessageId: NS_E_WMP_WMDM_LICENSE_NOTEXIST
'//
'// MessageText:
'//
'// This file does not have sync rights. If you obtained this file from an online store, go to the online store to get sync rights.%0
'//
%NS_E_WMP_WMDM_LICENSE_NOTEXIST   = &HC00D11A6&

'//
'// MessageId: NS_E_WMP_WMDM_LICENSE_EXPIRED
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because the sync rights have expired. Go to the content provider's online store to get new sync rights.%0
'//
%NS_E_WMP_WMDM_LICENSE_EXPIRED    = &HC00D11A7&

'//
'// MessageId: NS_E_WMP_WMDM_BUSY
'//
'// MessageText:
'//
'// The portable device is already in use. Wait until the current task finishes or quit other programs that might be using the portable device, and then try again.%0
'//
%NS_E_WMP_WMDM_BUSY               = &HC00D11A8&

'//
'// MessageId: NS_E_WMP_WMDM_NORIGHTS
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because the content provider or device prohibits it. You might be able to resolve this problem by going to the content provider's online store to get sync rights.%0
'//
%NS_E_WMP_WMDM_NORIGHTS           = &HC00D11A9&

'//
'// MessageId: NS_E_WMP_WMDM_INCORRECT_RIGHTS
'//
'// MessageText:
'//
'// The content provider has not granted you the right to sync this file. Go to the content provider's online store to get sync rights.%0
'//
%NS_E_WMP_WMDM_INCORRECT_RIGHTS   = &HC00D11AA&

'//
'// MessageId: NS_E_WMP_IMAPI_GENERIC
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files to the CD. Verify that the disc is clean and not damaged. If necessary, select a slower recording speed or try a different brand of blank discs.%0
'//
%NS_E_WMP_IMAPI_GENERIC           = &HC00D11AB&

'//
'// MessageId: NS_E_WMP_IMAPI_DEVICE_NOTPRESENT
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files. Verify that the burner is connected properly, and then try again.%0
'//
%NS_E_WMP_IMAPI_DEVICE_NOTPRESENT = &HC00D11AD&

'//
'// MessageId: NS_E_WMP_IMAPI_DEVICE_BUSY
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files. Verify that the burner is connected properly and that the disc is clean and not damaged.
'// If the burner is already in use, wait until the current task finishes or quit other programs that might be using the burner.%0
'//
%NS_E_WMP_IMAPI_DEVICE_BUSY       = &HC00D11AE&

'//
'// MessageId: NS_E_WMP_IMAPI_LOSS_OF_STREAMING
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files to the CD.%0
'//
%NS_E_WMP_IMAPI_LOSS_OF_STREAMING = &HC00D11AF&

'//
'// MessageId: NS_E_WMP_SERVER_UNAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. The server might not be available or there might be a problem with your network or firewall settings.%0
'//
%NS_E_WMP_SERVER_UNAVAILABLE      = &HC00D11B0&

'//
'// MessageId: NS_E_WMP_FILE_OPEN_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while playing the file.%0
'//
%NS_E_WMP_FILE_OPEN_FAILED        = &HC00D11B1&

'//
'// MessageId: NS_E_WMP_VERIFY_ONLINE
'//
'// MessageText:
'//
'// Windows Media Player must connect to the Internet to verify the file's media usage rights. Connect to the Internet, and then try again.%0
'//
%NS_E_WMP_VERIFY_ONLINE           = &HC00D11B2&

'//
'// MessageId: NS_E_WMP_SERVER_NOT_RESPONDING
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because a network error occurred. The server might not be available. Verify that you are connected to the network and that your proxy settings are correct.%0
'//
%NS_E_WMP_SERVER_NOT_RESPONDING   = &HC00D11B3&

'//
'// MessageId: NS_E_WMP_DRM_CORRUPT_BACKUP
'//
'// MessageText:
'//
'// Windows Media Player cannot restore your media usage rights because it could not find any backed up rights on your computer.%0
'//
%NS_E_WMP_DRM_CORRUPT_BACKUP      = &HC00D11B4&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_SERVER_UNAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player cannot download media usage rights because the server is not available (for example, the server might be busy or not online).%0
'//
%NS_E_WMP_DRM_LICENSE_SERVER_UNAVAILABLE = &HC00D11B5&

'//
'// MessageId: NS_E_WMP_NETWORK_FIREWALL
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. A network firewall might be preventing the Player from opening the file by using the UDP transport protocol.
'// If you typed a URL in the Open URL dialog box, try using a different transport protocol (for example, "http:").%0
'//
%NS_E_WMP_NETWORK_FIREWALL        = &HC00D11B6&

'//
'// MessageId: NS_E_WMP_NO_REMOVABLE_MEDIA
'//
'// MessageText:
'//
'// Insert the removable media, and then try again.%0
'//
%NS_E_WMP_NO_REMOVABLE_MEDIA      = &HC00D11B7&

'//
'// MessageId: NS_E_WMP_PROXY_CONNECT_TIMEOUT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the proxy server is not responding. The proxy server might be temporarily unavailable or your Player proxy settings might not be valid.%0
'//
%NS_E_WMP_PROXY_CONNECT_TIMEOUT   = &HC00D11B8&

'//
'// MessageId: NS_E_WMP_NEED_UPGRADE
'//
'// MessageText:
'//
'// To play the file, you might need to install a later version of Windows Media Player. On the Help menu, click Check for Updates, and then follow the instructions.%0
'//
%NS_E_WMP_NEED_UPGRADE            = &HC00D11B9&

'//
'// MessageId: NS_E_WMP_AUDIO_HW_PROBLEM
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because there is a problem with your sound device. There might not be a sound device installed on your computer, it might be in use by another program, or it might not be functioning properly.%0
'//
%NS_E_WMP_AUDIO_HW_PROBLEM        = &HC00D11BA&

'//
'// MessageId: NS_E_WMP_INVALID_PROTOCOL
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the specified protocol is not supported. If you typed a URL in the Open URL dialog box, try using a different transport protocol (for example, "http:" or "rtsp:").%0
'//
%NS_E_WMP_INVALID_PROTOCOL        = &HC00D11BB&

'//
'// MessageId: NS_E_WMP_INVALID_LIBRARY_ADD
'//
'// MessageText:
'//
'// Windows Media Player cannot add the file to the library because the file format is not supported.%0
'//
%NS_E_WMP_INVALID_LIBRARY_ADD     = &HC00D11BC&

'//
'// MessageId: NS_E_WMP_MMS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the specified protocol is not supported. If you typed a URL in the Open URL dialog box, try using a different transport protocol (for example, "mms:").%0
'//
%NS_E_WMP_MMS_NOT_SUPPORTED       = &HC00D11BD&

'//
'// MessageId: NS_E_WMP_NO_PROTOCOLS_SELECTED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because there are no streaming protocols selected. Select one or more protocols, and then try again.%0
'//
%NS_E_WMP_NO_PROTOCOLS_SELECTED   = &HC00D11BE&

'//
'// MessageId: NS_E_WMP_GOFULLSCREEN_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot switch to Full Screen. You might need to adjust your Windows display settings. Open display settings in Control Panel, and then try setting Hardware acceleration to Full.%0
'//
%NS_E_WMP_GOFULLSCREEN_FAILED     = &HC00D11BF&

'//
'// MessageId: NS_E_WMP_NETWORK_ERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because a network error occurred. The server might not be available (for example, the server is busy or not online) or you might not be connected to the network.%0
'//
%NS_E_WMP_NETWORK_ERROR           = &HC00D11C0&

'//
'// MessageId: NS_E_WMP_CONNECT_TIMEOUT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the server is not responding. Verify that you are connected to the network, and then try again later.%0
'//
%NS_E_WMP_CONNECT_TIMEOUT         = &HC00D11C1&

'//
'// MessageId: NS_E_WMP_MULTICAST_DISABLED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the multicast protocol is not enabled. On the Tools menu, click Options, click the Network tab, and then select the Multicast check box.%0
'//
%NS_E_WMP_MULTICAST_DISABLED      = &HC00D11C2&

'//
'// MessageId: NS_E_WMP_SERVER_DNS_TIMEOUT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because a network problem occurred. Verify that you are connected to the network, and then try again later.%0
'//
%NS_E_WMP_SERVER_DNS_TIMEOUT      = &HC00D11C3&

'//
'// MessageId: NS_E_WMP_PROXY_NOT_FOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the network proxy server cannot be found. Verify that your proxy settings are correct, and then try again.%0
'//
%NS_E_WMP_PROXY_NOT_FOUND         = &HC00D11C4&

'//
'// MessageId: NS_E_WMP_TAMPERED_CONTENT
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because it is corrupted.%0
'//
%NS_E_WMP_TAMPERED_CONTENT        = &HC00D11C5&

'//
'// MessageId: NS_E_WMP_OUTOFMEMORY
'//
'// MessageText:
'//
'// Your computer is running low on memory. Quit other programs, and then try again.%0
'//
%NS_E_WMP_OUTOFMEMORY             = &HC00D11C6&

'//
'// MessageId: NS_E_WMP_AUDIO_CODEC_NOT_INSTALLED
'//
'// MessageText:
'//
'// Windows Media Player cannot play, burn, rip, or sync the file because a required audio codec is not installed on your computer.%0
'//
%NS_E_WMP_AUDIO_CODEC_NOT_INSTALLED = &HC00D11C7&

'//
'// MessageId: NS_E_WMP_VIDEO_CODEC_NOT_INSTALLED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the required video codec is not installed on your computer.%0
'//
%NS_E_WMP_VIDEO_CODEC_NOT_INSTALLED = &HC00D11C8&

'//
'// MessageId: NS_E_WMP_IMAPI_DEVICE_INVALIDTYPE
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files. If the burner is busy, wait for the current task to finish. If necessary, verify that the burner is connected properly and that you have installed the latest device driver.%0
'//
%NS_E_WMP_IMAPI_DEVICE_INVALIDTYPE = &HC00D11C9&

'//
'// MessageId: NS_E_WMP_DRM_DRIVER_AUTH_FAILURE
'//
'// MessageText:
'//
'// Windows Media Player cannot play the protected file because there is a problem with your sound device. Try installing a new device driver or use a different sound device.%0
'//
%NS_E_WMP_DRM_DRIVER_AUTH_FAILURE = &HC00D11CA&

'//
'// MessageId: NS_E_WMP_NETWORK_RESOURCE_FAILURE
'//
'// MessageText:
'//
'// Windows Media Player encountered a network error. Restart the Player.%0
'//
%NS_E_WMP_NETWORK_RESOURCE_FAILURE = &HC00D11CB&

'//
'// MessageId: NS_E_WMP_UPGRADE_APPLICATION
'//
'// MessageText:
'//
'// Windows Media Player is not installed properly. Reinstall the Player.%0
'//
%NS_E_WMP_UPGRADE_APPLICATION     = &HC00D11CC&

'//
'// MessageId: NS_E_WMP_UNKNOWN_ERROR
'//
'// MessageText:
'//
'// Windows Media Player encountered an unknown error.%0
'//
%NS_E_WMP_UNKNOWN_ERROR           = &HC00D11CD&

'//
'// MessageId: NS_E_WMP_INVALID_KEY
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because the required codec is not valid.%0
'//
%NS_E_WMP_INVALID_KEY             = &HC00D11CE&

'//
'// MessageId: NS_E_WMP_CD_ANOTHER_USER
'//
'// MessageText:
'//
'// The CD drive is in use by another user. Wait for the task to complete, and then try again.%0
'//
%NS_E_WMP_CD_ANOTHER_USER         = &HC00D11CF&

'//
'// MessageId: NS_E_WMP_DRM_NEEDS_AUTHORIZATION
'//
'// MessageText:
'//
'// Windows Media Player cannot play, sync, or burn the protected file because a problem occurred with the Windows Media Digital Rights Management (DRM) system. You might need to connect to the Internet to update your DRM components.%0
'//
%NS_E_WMP_DRM_NEEDS_AUTHORIZATION = &HC00D11D0&

'//
'// MessageId: NS_E_WMP_BAD_DRIVER
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file because there might be a problem with your sound or video device. Try installing an updated device driver.%0
'//
%NS_E_WMP_BAD_DRIVER              = &HC00D11D1&

'//
'// MessageId: NS_E_WMP_ACCESS_DENIED
'//
'// MessageText:
'//
'// Windows Media Player cannot access the file. The file might be in use, you might not have access to the computer where the file is stored, or your proxy settings might not be correct.%0
'//
%NS_E_WMP_ACCESS_DENIED           = &HC00D11D2&

'//
'// MessageId: NS_E_WMP_LICENSE_RESTRICTS
'//
'// MessageText:
'//
'// The content provider prohibits this action. Go to the content provider's online store to get new media usage rights.%0
'//
%NS_E_WMP_LICENSE_RESTRICTS       = &HC00D11D3&

'//
'// MessageId: NS_E_WMP_INVALID_REQUEST
'//
'// MessageText:
'//
'// Windows Media Player cannot perform the requested action at this time.%0
'//
%NS_E_WMP_INVALID_REQUEST         = &HC00D11D4&

'//
'// MessageId: NS_E_WMP_CD_STASH_NO_SPACE
'//
'// MessageText:
'//
'// Windows Media Player cannot burn the files because there is not enough free disk space to store the temporary files. Delete some unneeded files on your hard disk, and then try again.%0
'//
%NS_E_WMP_CD_STASH_NO_SPACE       = &HC00D11D5&

'//
'// MessageId: NS_E_WMP_DRM_NEW_HARDWARE
'//
'// MessageText:
'//
'// Your media usage rights have become corrupted or are no longer valid. This might happen if you have replaced hardware components in your computer.%0
'//
%NS_E_WMP_DRM_NEW_HARDWARE        = &HC00D11D6&

'//
'// MessageId: NS_E_WMP_DRM_INVALID_SIG
'//
'// MessageText:
'//
'// The required Windows Media Digital Rights Management (DRM) component cannot be validated. You might be able to resolve the problem by reinstalling the Player.%0
'//
%NS_E_WMP_DRM_INVALID_SIG         = &HC00D11D7&

'//
'// MessageId: NS_E_WMP_DRM_CANNOT_RESTORE
'//
'// MessageText:
'//
'// You have exceeded your restore limit for the day. Try restoring your media usage rights tomorrow.%0
'//
%NS_E_WMP_DRM_CANNOT_RESTORE      = &HC00D11D8&

'//
'// MessageId: NS_E_WMP_BURN_DISC_OVERFLOW
'//
'// MessageText:
'//
'// Some files might not fit on the CD. The required space cannot be calculated accurately because some files might be missing duration information. To ensure the calculation is accurate, play the files that are missing duration information.%0
'//
%NS_E_WMP_BURN_DISC_OVERFLOW      = &HC00D11D9&

'//
'// MessageId: NS_E_WMP_DRM_GENERIC_LICENSE_FAILURE
'//
'// MessageText:
'//
'// Windows Media Player cannot verify the file's media usage rights. If you obtained this file from an online store, go to the online store to get the necessary rights.%0
'//
%NS_E_WMP_DRM_GENERIC_LICENSE_FAILURE = &HC00D11DA&

'//
'// MessageId: NS_E_WMP_DRM_NO_SECURE_CLOCK
'//
'// MessageText:
'//
'// It is not possible to sync because this device's internal clock is not set correctly. To set the clock, select the option to set the device clock on the Privacy tab of the Options dialog box, connect to the Internet, and then sync the device again.
'// For additional assistance, click Web Help.%0
'//
%NS_E_WMP_DRM_NO_SECURE_CLOCK     = &HC00D11DB&

'//
'// MessageId: NS_E_WMP_DRM_NO_RIGHTS
'//
'// MessageText:
'//
'// Windows Media Player cannot play, burn, rip, or sync the protected file because you do not have the appropriate rights.%0
'//
%NS_E_WMP_DRM_NO_RIGHTS           = &HC00D11DC&

'//
'// MessageId: NS_E_WMP_DRM_INDIV_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered an error during upgrade.%0
'//
%NS_E_WMP_DRM_INDIV_FAILED        = &HC00D11DD&

'//
'// MessageId: NS_E_WMP_SERVER_NONEWCONNECTIONS
'//
'// MessageText:
'//
'// Windows Media Player cannot connect to the server because it is not accepting any new connections. This could be because it has reached its maximum connection limit. Please try again later.%0
'//
%NS_E_WMP_SERVER_NONEWCONNECTIONS = &HC00D11DE&

'//
'// MessageId: NS_E_WMP_MULTIPLE_ERROR_IN_PLAYLIST
'//
'// MessageText:
'//
'// A number of queued files cannot be played. To find information about the problem, click the icon next to each file in the List pane.%0
'//
%NS_E_WMP_MULTIPLE_ERROR_IN_PLAYLIST = &HC00D11DF&

'//
'// MessageId: NS_E_WMP_IMAPI2_ERASE_FAIL
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while erasing the rewritable CD or DVD. Verify that the CD or DVD burner is connected properly and that the disc is clean and not damaged.%0
'//
%NS_E_WMP_IMAPI2_ERASE_FAIL       = &HC00D11E0&

'//
'// MessageId: NS_E_WMP_IMAPI2_ERASE_DEVICE_BUSY
'//
'// MessageText:
'//
'// Windows Media Player cannot erase the rewritable CD or DVD. Verify that the CD or DVD burner is connected properly and that the disc is clean and not damaged.
'// If the burner is already in use, wait until the current task finishes or quit other programs that might be using the burner.%0
'//
%NS_E_WMP_IMAPI2_ERASE_DEVICE_BUSY = &HC00D11E1&

'//
'// MessageId: NS_E_WMP_DRM_COMPONENT_FAILURE
'//
'// MessageText:
'//
'// A Windows Media Digital Rights Management (DRM) component encountered a problem. Contact Microsoft Product Support.%0
'//
%NS_E_WMP_DRM_COMPONENT_FAILURE   = &HC00D11E2&

'//
'// MessageId: NS_E_WMP_DRM_NO_DEVICE_CERT
'//
'// MessageText:
'//
'// It is not possible to obtain the device's certificate. Please contact the device manufacturer for a firmware update or for other steps to resolve this problem.%0
'//
%NS_E_WMP_DRM_NO_DEVICE_CERT      = &HC00D11E3&

'//
'// MessageId: NS_E_WMP_SERVER_SECURITY_ERROR
'//
'// MessageText:
'//
'// Windows Media Player encountered an error when connecting to the server. The security information from the server could not be validated.%0
'//
%NS_E_WMP_SERVER_SECURITY_ERROR   = &HC00D11E4&

'//
'// MessageId: NS_E_WMP_AUDIO_DEVICE_LOST
'//
'// MessageText:
'//
'// An audio device was disconnected or reconfigured. Verify that the audio device is connected, and then try to play the item again.%0
'//
%NS_E_WMP_AUDIO_DEVICE_LOST       = &HC00D11E5&

'//
'// MessageId: NS_E_WMP_IMAPI_MEDIA_INCOMPATIBLE
'//
'// MessageText:
'//
'// Windows Media Player could not complete burning because the disc is not compatible with your drive. Try inserting a different kind of recordable media or use a disc that supports a write speed that is compatible with your drive.%0
'//
%NS_E_WMP_IMAPI_MEDIA_INCOMPATIBLE = &HC00D11E6&

'//
'// WMP Sync Wizard Error codes extension 4590-4599
'//
'//
'// MessageId: NS_E_SYNCWIZ_DEVICE_FULL
'//
'// MessageText:
'//
'// Windows Media Player cannot save the sync settings because your device is full. Delete some unneeded files on your device and then try again.%0
'//
%NS_E_SYNCWIZ_DEVICE_FULL         = &HC00D11EE&

'//
'// MessageId: NS_E_SYNCWIZ_CANNOT_CHANGE_SETTINGS
'//
'// MessageText:
'//
'// It is not possible to change sync settings at this time. Try again later.%0
'//
%NS_E_SYNCWIZ_CANNOT_CHANGE_SETTINGS = &HC00D11EF&

'//
'// MessageId: NS_E_TRANSCODE_DELETECACHEERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot delete these files right now. If the Player is syncing, wait until it is complete and then try again.%0
'//
%NS_E_TRANSCODE_DELETECACHEERROR  = &HC00D11F0&

'//
'// WMP CD Filter Error codes extension
'//
'//
'// MessageId: NS_E_CD_NO_BUFFERS_READ
'//
'// MessageText:
'//
'// Windows Media Player could not use digital mode to read the CD. The Player has automatically switched the CD drive to analog mode. To switch back to digital mode, use the Devices tab.%0
'//
%NS_E_CD_NO_BUFFERS_READ          = &HC00D11F8&

'//
'// MessageId: NS_E_CD_EMPTY_TRACK_QUEUE
'//
'// MessageText:
'//
'// No CD track was specified for playback.%0
'//
%NS_E_CD_EMPTY_TRACK_QUEUE        = &HC00D11F9&

'//
'// MessageId: NS_E_CD_NO_READER
'//
'// MessageText:
'//
'// The CD filter was not able to create the CD reader.%0
'//
%NS_E_CD_NO_READER                = &HC00D11FA&

'//
'// MessageId: NS_E_CD_ISRC_INVALID
'//
'// MessageText:
'//
'// Invalid ISRC code.%0
'//
%NS_E_CD_ISRC_INVALID             = &HC00D11FB&

'//
'// MessageId: NS_E_CD_MEDIA_CATALOG_NUMBER_INVALID
'//
'// MessageText:
'//
'// Invalid Media Catalog Number.%0
'//
%NS_E_CD_MEDIA_CATALOG_NUMBER_INVALID = &HC00D11FC&

'//
'// MessageId: NS_E_SLOW_READ_DIGITAL_WITH_ERRORCORRECTION
'//
'// MessageText:
'//
'// Windows Media Player cannot play audio CDs correctly because the CD drive is slow and error correction is turned on. To increase performance, turn off playback error correction for this drive.%0
'//
%NS_E_SLOW_READ_DIGITAL_WITH_ERRORCORRECTION = &HC00D11FD&

'//
'// MessageId: NS_E_CD_SPEEDDETECT_NOT_ENOUGH_READS
'//
'// MessageText:
'//
'// Windows Media Player cannot estimate the CD drive's playback speed because the CD track is too short.%0
'//
%NS_E_CD_SPEEDDETECT_NOT_ENOUGH_READS = &HC00D11FE&

'//
'// MessageId: NS_E_CD_QUEUEING_DISABLED
'//
'// MessageText:
'//
'// Cannot queue the CD track because queuing is not enabled.%0
'//
%NS_E_CD_QUEUEING_DISABLED        = &HC00D11FF&

'//
'// WMP DRM error codes 4610-4630
'//
'//
'// MessageId: NS_E_WMP_DRM_ACQUIRING_LICENSE
'//
'// MessageText:
'//
'// Windows Media Player cannot download additional media usage rights until the current download is complete.%0
'//
%NS_E_WMP_DRM_ACQUIRING_LICENSE   = &HC00D1202&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_EXPIRED
'//
'// MessageText:
'//
'// The media usage rights for this file have expired or are no longer valid. If you obtained the file from an online store, sign in to the store, and then try again.%0
'//
%NS_E_WMP_DRM_LICENSE_EXPIRED     = &HC00D1203&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_NOTACQUIRED
'//
'// MessageText:
'//
'// Windows Media Player cannot download the media usage rights for the file. If you obtained the file from an online store, sign in to the store, and then try again.%0
'//
%NS_E_WMP_DRM_LICENSE_NOTACQUIRED = &HC00D1204&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_NOTENABLED
'//
'// MessageText:
'//
'// The media usage rights for this file are not yet valid. To see when they will become valid, right-click the file in the library, click Properties, and then click the Media Usage Rights tab.%0
'//
%NS_E_WMP_DRM_LICENSE_NOTENABLED  = &HC00D1205&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_UNUSABLE
'//
'// MessageText:
'//
'// The media usage rights for this file are not valid. If you obtained this file from an online store, contact the store for assistance.%0
'//
%NS_E_WMP_DRM_LICENSE_UNUSABLE    = &HC00D1206&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_CONTENT_REVOKED
'//
'// MessageText:
'//
'// The content provider has revoked the media usage rights for this file. If you obtained this file from an online store, ask the store if a new version of the file is available.%0
'//
%NS_E_WMP_DRM_LICENSE_CONTENT_REVOKED = &HC00D1207&

'//
'// MessageId: NS_E_WMP_DRM_LICENSE_NOSAP
'//
'// MessageText:
'//
'// The media usage rights for this file require a feature that is not supported in your current version of Windows Media Player or your current version of Windows. If you obtained this file from an online store,
'// contact the store for further assistance.%0
'//
%NS_E_WMP_DRM_LICENSE_NOSAP       = &HC00D1208&

'//
'// MessageId: NS_E_WMP_DRM_UNABLE_TO_ACQUIRE_LICENSE
'//
'// MessageText:
'//
'// Windows Media Player cannot download media usage rights at this time. Try again later.%0
'//
%NS_E_WMP_DRM_UNABLE_TO_ACQUIRE_LICENSE = &HC00D1209&

'//
'// MessageId: NS_E_WMP_LICENSE_REQUIRED
'//
'// MessageText:
'//
'// Windows Media Player cannot play, burn, or sync the file because the media usage rights are missing. If you obtained the file from an online store, sign in to the store, and then try again.%0
'//
%NS_E_WMP_LICENSE_REQUIRED        = &HC00D120A&

'//
'// MessageId: NS_E_WMP_PROTECTED_CONTENT
'//
'// MessageText:
'//
'// Windows Media Player cannot play, burn, or sync the file because the media usage rights are missing. If you obtained the file from an online store, sign in to the store, and then try again.%0
'//
%NS_E_WMP_PROTECTED_CONTENT       = &HC00D120B&

'//
'// WMP Policy error codes
'//
'//
'// MessageId: NS_E_WMP_POLICY_VALUE_NOT_CONFIGURED
'//
'// MessageText:
'//
'// Windows Media Player cannot read a policy. This can occur when the policy does not exist in the registry or when the registry cannot be read.%0
'//
%NS_E_WMP_POLICY_VALUE_NOT_CONFIGURED = &HC00D122A&

'//
'// WMP SYNC error codes 4660 -- 4700
'//
'//
'// MessageId: NS_E_PDA_CANNOT_SYNC_FROM_INTERNET
'//
'// MessageText:
'//
'// Windows Media Player cannot sync content streamed directly from the Internet. If possible, download the file to your computer, and then try to sync the file.%0
'//
%NS_E_PDA_CANNOT_SYNC_FROM_INTERNET = &HC00D1234&

'//
'// MessageId: NS_E_PDA_CANNOT_SYNC_INVALID_PLAYLIST
'//
'// MessageText:
'//
'// This playlist is not valid or is corrupted. Create a new playlist using Windows Media Player, then sync the new playlist instead.%0
'//
%NS_E_PDA_CANNOT_SYNC_INVALID_PLAYLIST = &HC00D1235&

'//
'// MessageId: NS_E_PDA_FAILED_TO_SYNCHRONIZE_FILE
'//
'// MessageText:
'//
'// Windows Media Player encountered a problem while syncing the file to the device.%0
'//
%NS_E_PDA_FAILED_TO_SYNCHRONIZE_FILE = &HC00D1236&

'//
'// MessageId: NS_E_PDA_SYNC_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while syncing to the device.%0
'//
%NS_E_PDA_SYNC_FAILED             = &HC00D1237&

'//
'// MessageId: NS_E_PDA_DELETE_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot delete a file from the device.%0
'//
%NS_E_PDA_DELETE_FAILED           = &HC00D1238&

'//
'// MessageId: NS_E_PDA_FAILED_TO_RETRIEVE_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot copy a file from the device to your library.%0
'//
%NS_E_PDA_FAILED_TO_RETRIEVE_FILE = &HC00D1239&

'//
'// MessageId: NS_E_PDA_DEVICE_NOT_RESPONDING
'//
'// MessageText:
'//
'// Windows Media Player cannot communicate with the device because the device is not responding. Try reconnecting the device, resetting the device, or contacting the device manufacturer for updated firmware.%0
'//
%NS_E_PDA_DEVICE_NOT_RESPONDING   = &HC00D123A&

'//
'// MessageId: NS_E_PDA_FAILED_TO_TRANSCODE_PHOTO
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the picture to the device because a problem occurred while converting the file to another quality level or format. The original file might be damaged or corrupted.%0
'//
%NS_E_PDA_FAILED_TO_TRANSCODE_PHOTO = &HC00D123B&

'//
'// MessageId: NS_E_PDA_FAILED_TO_ENCRYPT_TRANSCODED_FILE
'//
'// MessageText:
'//
'// Windows Media Player cannot convert the file. The file might have been encrypted by the Encrypted File System (EFS). Try decrypting the file first and then syncing it. For information about how to decrypt a file, see Windows Help and Support.%0
'//
%NS_E_PDA_FAILED_TO_ENCRYPT_TRANSCODED_FILE = &HC00D123C&

'//
'// MessageId: NS_E_PDA_CANNOT_TRANSCODE_TO_AUDIO
'//
'// MessageText:
'//
'// Your device requires that this file be converted in order to play on the device. However, the device either does not support playing audio, or Windows Media Player cannot convert the file to an audio format that is supported by the device.%0
'//
%NS_E_PDA_CANNOT_TRANSCODE_TO_AUDIO = &HC00D123D&

'//
'// MessageId: NS_E_PDA_CANNOT_TRANSCODE_TO_VIDEO
'//
'// MessageText:
'//
'// Your device requires that this file be converted in order to play on the device. However, the device either does not support playing video, or Windows Media Player cannot convert the file to a video format that is supported by the device.%0
'//
%NS_E_PDA_CANNOT_TRANSCODE_TO_VIDEO = &HC00D123E&

'//
'// MessageId: NS_E_PDA_CANNOT_TRANSCODE_TO_IMAGE
'//
'// MessageText:
'//
'// Your device requires that this file be converted in order to play on the device. However, the device either does not support displaying pictures, or Windows Media Player cannot convert the file to a picture format that is supported by the device.%0
'//
%NS_E_PDA_CANNOT_TRANSCODE_TO_IMAGE = &HC00D123F&

'//
'// MessageId: NS_E_PDA_RETRIEVED_FILE_FILENAME_TOO_LONG
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file to your computer because the file name is too long. Try renaming the file on the device.%0
'//
%NS_E_PDA_RETRIEVED_FILE_FILENAME_TOO_LONG = &HC00D1240&

'//
'// MessageId: NS_E_PDA_CEWMDM_DRM_ERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the file because the device is not responding. This typically occurs when there is a problem with the device firmwa re.%0
'//
%NS_E_PDA_CEWMDM_DRM_ERROR        = &HC00D1241&

'//
'// MessageId: NS_E_INCOMPLETE_PLAYLIST
'//
'// MessageText:
'//
'//  NS_E_INCOMPLETE_PLAYLIST
'//
%NS_E_INCOMPLETE_PLAYLIST         = &HC00D1242&

'//
'// MessageId: NS_E_PDA_SYNC_RUNNING
'//
'// MessageText:
'//
'// It is not possible to perform the requested action because sync is in progress. You can either stop sync or wait for it to complete, and then try again.%0
'//
%NS_E_PDA_SYNC_RUNNING            = &HC00D1243&

'//
'// MessageId: NS_E_PDA_SYNC_LOGIN_ERROR
'//
'// MessageText:
'//
'// Windows Media Player cannot sync the subscription content because you are not signed in to the online store that provided it. Sign in to the online store, and then try again.%0
'//
%NS_E_PDA_SYNC_LOGIN_ERROR        = &HC00D1244&

'//
'// MessageId: NS_E_PDA_TRANSCODE_CODEC_NOT_FOUND
'//
'// MessageText:
'//
'// Windows Media Player cannot convert the file to the format required by the device. One or more codecs required to convert the file could not be found.%0
'//
%NS_E_PDA_TRANSCODE_CODEC_NOT_FOUND = &HC00D1245&

'//
'// MessageId: NS_E_CANNOT_SYNC_DRM_TO_NON_JANUS_DEVICE
'//
'// MessageText:
'//
'// It is not possible to sync subscription files to this device.%0
'//
%NS_E_CANNOT_SYNC_DRM_TO_NON_JANUS_DEVICE = &HC00D1246&

'//
'// MessageId: NS_E_CANNOT_SYNC_PREVIOUS_SYNC_RUNNING
'//
'// MessageText:
'//
'// Your device is operating slowly or is not responding. Until the device responds, it is not possible to sync again. To return the device to normal operation, try disconnecting it from the computer or resetting it.%0
'//
%NS_E_CANNOT_SYNC_PREVIOUS_SYNC_RUNNING = &HC00D1247&

'//
'//Background download plugin
'//
'//
'// MessageId: NS_E_WMP_HWND_NOTFOUND
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot function properly because the Player main window cannot be found. Try restarting the Player.%0
'//
%NS_E_WMP_HWND_NOTFOUND           = &HC00D125C&

'//
'// MessageId: NS_E_BKGDOWNLOAD_WRONG_NO_FILES
'//
'// MessageText:
'//
'// Windows Media Player encountered a download that has the wrong number of files. This might occur if another program is trying to create jobs with the same signature as the Player.%0
'//
%NS_E_BKGDOWNLOAD_WRONG_NO_FILES  = &HC00D125D&

'//
'// MessageId: NS_E_BKGDOWNLOAD_COMPLETECANCELLEDJOB
'//
'// MessageText:
'//
'// Windows Media Player tried to complete a download that was already canceled. The file will not be available.%0
'//
%NS_E_BKGDOWNLOAD_COMPLETECANCELLEDJOB = &HC00D125E&

'//
'// MessageId: NS_E_BKGDOWNLOAD_CANCELCOMPLETEDJOB
'//
'// MessageText:
'//
'// Windows Media Player tried to cancel a download that was already completed. The file will not be removed.%0
'//
%NS_E_BKGDOWNLOAD_CANCELCOMPLETEDJOB = &HC00D125F&

'//
'// MessageId: NS_E_BKGDOWNLOAD_NOJOBPOINTER
'//
'// MessageText:
'//
'// Windows Media Player is trying to access a download that is not valid.%0
'//
%NS_E_BKGDOWNLOAD_NOJOBPOINTER    = &HC00D1260&

'//
'// MessageId: NS_E_BKGDOWNLOAD_INVALIDJOBSIGNATURE
'//
'// MessageText:
'//
'// This download was not created by Windows Media Player.%0
'//
%NS_E_BKGDOWNLOAD_INVALIDJOBSIGNATURE = &HC00D1261&

'//
'// MessageId: NS_E_BKGDOWNLOAD_FAILED_TO_CREATE_TEMPFILE
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot create a temporary file name. This might occur if the path is not valid or if the disk is full.%0
'//
%NS_E_BKGDOWNLOAD_FAILED_TO_CREATE_TEMPFILE = &HC00D1262&

'//
'// MessageId: NS_E_BKGDOWNLOAD_PLUGIN_FAILEDINITIALIZE
'//
'// MessageText:
'//
'// The Windows Media Player download manager plug-in cannot start. This might occur if the system is out of resources.%0
'//
%NS_E_BKGDOWNLOAD_PLUGIN_FAILEDINITIALIZE = &HC00D1263&

'//
'// MessageId: NS_E_BKGDOWNLOAD_PLUGIN_FAILEDTOMOVEFILE
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot move the file.%0
'//
%NS_E_BKGDOWNLOAD_PLUGIN_FAILEDTOMOVEFILE = &HC00D1264&

'//
'// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCFAILED
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot perform a task because the system has no resources to allocate.%0
'//
%NS_E_BKGDOWNLOAD_CALLFUNCFAILED  = &HC00D1265&

'//
'// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCTIMEOUT
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot perform a task because the task took too long to run.%0
'//
%NS_E_BKGDOWNLOAD_CALLFUNCTIMEOUT = &HC00D1266&

'//
'// MessageId: NS_E_BKGDOWNLOAD_CALLFUNCENDED
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot perform a task because the Player is terminating the service. The task will be recovered when the Player restarts.%0
'//
%NS_E_BKGDOWNLOAD_CALLFUNCENDED   = &HC00D1267&

'//
'// MessageId: NS_E_BKGDOWNLOAD_WMDUNPACKFAILED
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot expand a WMD file. The file will be deleted and the operation will not be completed successfully.%0
'//
%NS_E_BKGDOWNLOAD_WMDUNPACKFAILED = &HC00D1268&

'//
'// MessageId: NS_E_BKGDOWNLOAD_FAILEDINITIALIZE
'//
'// MessageText:
'//
'// The Windows Media Player download manager cannot start. This might occur if the system is out of resources.%0
'//
%NS_E_BKGDOWNLOAD_FAILEDINITIALIZE = &HC00D1269&

'//
'// MessageId: NS_E_INTERFACE_NOT_REGISTERED_IN_GIT
'//
'// MessageText:
'//
'// Windows Media Player cannot access a required functionality. This might occur if the wrong system files or Player DLLs are loaded.%0
'//
%NS_E_INTERFACE_NOT_REGISTERED_IN_GIT = &HC00D126A&

'//
'// MessageId: NS_E_BKGDOWNLOAD_INVALID_FILE_NAME
'//
'// MessageText:
'//
'// Windows Media Player cannot get the file name of the requested download. The requested download will be canceled.%0
'//
%NS_E_BKGDOWNLOAD_INVALID_FILE_NAME = &HC00D126B&

'//
'//Image Graph Errors 4750 -- 4800
'//
'//
'// MessageId: NS_E_IMAGE_DOWNLOAD_FAILED
'//
'// MessageText:
'//
'// Windows Media Player encountered an error while downloading an image.%0
'//
%NS_E_IMAGE_DOWNLOAD_FAILED       = &HC00D128E&

'//
'// UDRM errors
'//
'//
'// MessageId: NS_E_WMP_UDRM_NOUSERLIST
'//
'// MessageText:
'//
'// Windows Media Player cannot update your media usage rights because the Player cannot verify the list of activated users of this computer.%0
'//
%NS_E_WMP_UDRM_NOUSERLIST         = &HC00D12C0&

'//
'// MessageId: NS_E_WMP_DRM_NOT_ACQUIRING
'//
'// MessageText:
'//
'// Windows Media Player is trying to acquire media usage rights for a file that is no longer being used. Rights acquisition will stop.%0
'//
%NS_E_WMP_DRM_NOT_ACQUIRING       = &HC00D12C1&

'//
'// String is too large
'//
'//
'// MessageId: NS_E_WMP_BSTR_TOO_LONG
'//
'// MessageText:
'//
'// The parameter is not valid.%0
'//
%NS_E_WMP_BSTR_TOO_LONG           = &HC00D12F2&

'//
'// Autoplay errors 4860 --- 4870
'//
'//
'// MessageId: NS_E_WMP_AUTOPLAY_INVALID_STATE
'//
'// MessageText:
'//
'// The state is not valid for this request.%0
'//
%NS_E_WMP_AUTOPLAY_INVALID_STATE  = &HC00D12FC&

'//
'// MF mapped errors 4870 --- 4880
'//
'//
'// MessageId: NS_E_WMP_COMPONENT_REVOKED
'//
'// MessageText:
'//
'// Windows Media Player cannot play this file until you complete the software component upgrade. After the component has been upgraded, try to play the file again.%0
'//
%NS_E_WMP_COMPONENT_REVOKED       = &HC00D1306&

'//
'// CURL Errors 4900 -- 4920
'//
'//
'// MessageId: NS_E_CURL_NOTSAFE
'//
'// MessageText:
'//
'// The URL is not safe for the operation specified.%0
'//
%NS_E_CURL_NOTSAFE                = &HC00D1324&

'//
'// MessageId: NS_E_CURL_INVALIDCHAR
'//
'// MessageText:
'//
'// The URL contains one or more characters that are not valid.%0
'//
%NS_E_CURL_INVALIDCHAR            = &HC00D1325&

'//
'// MessageId: NS_E_CURL_INVALIDHOSTNAME
'//
'// MessageText:
'//
'// The URL contains a host name that is not valid.%0
'//
%NS_E_CURL_INVALIDHOSTNAME        = &HC00D1326&

'//
'// MessageId: NS_E_CURL_INVALIDPATH
'//
'// MessageText:
'//
'// The URL contains a path that is not valid.%0
'//
%NS_E_CURL_INVALIDPATH            = &HC00D1327&

'//
'// MessageId: NS_E_CURL_INVALIDSCHEME
'//
'// MessageText:
'//
'// The URL contains a scheme that is not valid.%0
'//
%NS_E_CURL_INVALIDSCHEME          = &HC00D1328&

'//
'// MessageId: NS_E_CURL_INVALIDURL
'//
'// MessageText:
'//
'// The URL is not valid.%0
'//
%NS_E_CURL_INVALIDURL             = &HC00D1329&

'//
'// MessageId: NS_E_CURL_CANTWALK
'//
'// MessageText:
'//
'// Windows Media Player cannot play the file. If you clicked a link on a web page, the link might not be valid.%0
'//
%NS_E_CURL_CANTWALK               = &HC00D132B&

'//
'// MessageId: NS_E_CURL_INVALIDPORT
'//
'// MessageText:
'//
'// The URL port is not valid.%0
'//
%NS_E_CURL_INVALIDPORT            = &HC00D132C&

'//
'// MessageId: NS_E_CURLHELPER_NOTADIRECTORY
'//
'// MessageText:
'//
'// The URL is not a directory.%0
'//
%NS_E_CURLHELPER_NOTADIRECTORY    = &HC00D132D&

'//
'// MessageId: NS_E_CURLHELPER_NOTAFILE
'//
'// MessageText:
'//
'// The URL is not a file.%0
'//
%NS_E_CURLHELPER_NOTAFILE         = &HC00D132E&

'//
'// MessageId: NS_E_CURL_CANTDECODE
'//
'// MessageText:
'//
'// The URL contains characters that cannot be decoded. The URL might be truncated or incomplete.%0
'//
%NS_E_CURL_CANTDECODE             = &HC00D132F&

'//
'// MessageId: NS_E_CURLHELPER_NOTRELATIVE
'//
'// MessageText:
'//
'// The specified URL is not a relative URL.%0
'//
%NS_E_CURLHELPER_NOTRELATIVE      = &HC00D1330&

'//
'// MessageId: NS_E_CURL_INVALIDBUFFERSIZE
'//
'// MessageText:
'//
'// The buffer is smaller than the size specified.%0
'//
%NS_E_CURL_INVALIDBUFFERSIZE      = &HC00D1331&

'//
'// Subscription Service Errors 4950 -- 4969
'//
'//
'// MessageId: NS_E_SUBSCRIPTIONSERVICE_PLAYBACK_DISALLOWED
'//
'// MessageText:
'//
'// The content provider has not granted you the right to play this file. Go to the content provider's online store to get play rights.%0
'//
%NS_E_SUBSCRIPTIONSERVICE_PLAYBACK_DISALLOWED = &HC00D1356&

'//
'// MessageId: NS_E_CANNOT_BUY_OR_DOWNLOAD_FROM_MULTIPLE_SERVICES
'//
'// MessageText:
'//
'// Windows Media Player cannot purchase or download content from multiple online stores.%0
'//
%NS_E_CANNOT_BUY_OR_DOWNLOAD_FROM_MULTIPLE_SERVICES = &HC00D1357&

'//
'// MessageId: NS_E_CANNOT_BUY_OR_DOWNLOAD_CONTENT
'//
'// MessageText:
'//
'// The file cannot be purchased or downloaded. The file might not be available from the online store.%0
'//
%NS_E_CANNOT_BUY_OR_DOWNLOAD_CONTENT = &HC00D1358&

'//
'// MessageId: NS_S_TRACK_BUY_REQUIRES_ALBUM_PURCHASE
'//
'// MessageText:
'//
'// The file is only available for purchase when you buy the entire album.%0
'//
%NS_S_TRACK_BUY_REQUIRES_ALBUM_PURCHASE = &H000D1359&

'//
'// MessageId: NS_E_NOT_CONTENT_PARTNER_TRACK
'//
'// MessageText:
'//
'// The provider of this file cannot be identified.%0
'//
%NS_E_NOT_CONTENT_PARTNER_TRACK   = &HC00D135A&

'//
'// MessageId: NS_E_TRACK_DOWNLOAD_REQUIRES_ALBUM_PURCHASE
'//
'// MessageText:
'//
'// The file is only available for download when you buy the entire album.%0
'//
%NS_E_TRACK_DOWNLOAD_REQUIRES_ALBUM_PURCHASE = &HC00D135B&

'//
'// MessageId: NS_E_TRACK_DOWNLOAD_REQUIRES_PURCHASE
'//
'// MessageText:
'//
'// You must buy the file before you can download it.%0
'//
%NS_E_TRACK_DOWNLOAD_REQUIRES_PURCHASE = &HC00D135C&

'//
'// MessageId: NS_E_TRACK_PURCHASE_MAXIMUM_EXCEEDED
'//
'// MessageText:
'//
'// You have exceeded the maximum number of files that can be purchased in a single transaction.%0
'//
%NS_E_TRACK_PURCHASE_MAXIMUM_EXCEEDED = &HC00D135D&

'//
'// MessageId: NS_S_NAVIGATION_COMPLETE_WITH_ERRORS
'//
'// MessageText:
'//
'// There were problems completing the requested navigation. There are identifiers missing in the catalog.%0
'//
%NS_S_NAVIGATION_COMPLETE_WITH_ERRORS = &H000D135E&

'//
'// MessageId: NS_E_SUBSCRIPTIONSERVICE_LOGIN_FAILED
'//
'// MessageText:
'//
'// Windows Media Player cannot sign in to the online store. Verify that you are using the correct user name and password. If the problem persists, the store might be temporarily unavailable.%0
'//
%NS_E_SUBSCRIPTIONSERVICE_LOGIN_FAILED = &HC00D135F&

'//
'// MessageId: NS_E_SUBSCRIPTIONSERVICE_DOWNLOAD_TIMEOUT
'//
'// MessageText:
'//
'// Windows Media Player cannot download this item because the server is not responding. The server might be temporarily unavailable or you might have lost your Internet connection.%0
'//
%NS_E_SUBSCRIPTIONSERVICE_DOWNLOAD_TIMEOUT = &HC00D1360&

'//
'// MessageId: NS_S_TRACK_ALREADY_DOWNLOADED
'//
'// MessageText:
'//
'//  NS_S_TRACK_ALREADY_DOWNLOADED
'//
%NS_S_TRACK_ALREADY_DOWNLOADED    = &H000D1361&

'//
'// MessageId: NS_E_CONTENT_PARTNER_STILL_INITIALIZING
'//
'// MessageText:
'//
'// The content provider is still initializing.
'//
%NS_E_CONTENT_PARTNER_STILL_INITIALIZING = &HC00D1362&

'//
'// MessageId: NS_E_OPEN_CONTAINING_FOLDER_FAILED
'//
'// MessageText:
'//
'// The folder could not be opened. The folder might have been moved or deleted.
'//
%NS_E_OPEN_CONTAINING_FOLDER_FAILED = &HC00D1363&

'//
'// Advanced Edit Dialog Errors 4970 -- 4989
'//
'//
'// MessageId: NS_E_ADVANCEDEDIT_TOO_MANY_PICTURES
'//
'// MessageText:
'//
'// Windows Media Player could not add all of the images to the file because the images exceeded the 7 megabyte (MB) limit.%0
'//
%NS_E_ADVANCEDEDIT_TOO_MANY_PICTURES = &HC00D136A&



'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Server Errors
'//
'// IdRange = 5000 - 5999
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_REDIRECT
'//
'// MessageText:
'//
'// The client redirected to another server.%0
'//
%NS_E_REDIRECT                    = &HC00D1388&

'//
'// MessageId: NS_E_STALE_PRESENTATION
'//
'// MessageText:
'//
'// The streaming media description is no longer current.%0
'//
%NS_E_STALE_PRESENTATION          = &HC00D1389&


 '// Namespace Errors

'//
'// MessageId: NS_E_NAMESPACE_WRONG_PERSIST
'//
'// MessageText:
'//
'// It is not possible to create a persistent namespace node under a transient parent node.%0
'//
%NS_E_NAMESPACE_WRONG_PERSIST     = &HC00D138A&

'//
'// MessageId: NS_E_NAMESPACE_WRONG_TYPE
'//
'// MessageText:
'//
'// It is not possible to store a value in a namespace node that has a different value type.%0
'//
%NS_E_NAMESPACE_WRONG_TYPE        = &HC00D138B&

'//
'// MessageId: NS_E_NAMESPACE_NODE_CONFLICT
'//
'// MessageText:
'//
'// It is not possible to remove the root namespace node.%0
'//
%NS_E_NAMESPACE_NODE_CONFLICT     = &HC00D138C&

'//
'// MessageId: NS_E_NAMESPACE_NODE_NOT_FOUND
'//
'// MessageText:
'//
'// The specified namespace node could not be found.%0
'//
%NS_E_NAMESPACE_NODE_NOT_FOUND    = &HC00D138D&

'//
'// MessageId: NS_E_NAMESPACE_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'// The buffer supplied to hold namespace node string is too small.%0
'//
%NS_E_NAMESPACE_BUFFER_TOO_SMALL  = &HC00D138E&

'//
'// MessageId: NS_E_NAMESPACE_TOO_MANY_CALLBACKS
'//
'// MessageText:
'//
'// The callback list on a namespace node is at the maximum size.%0
'//
%NS_E_NAMESPACE_TOO_MANY_CALLBACKS = &HC00D138F&

'//
'// MessageId: NS_E_NAMESPACE_DUPLICATE_CALLBACK
'//
'// MessageText:
'//
'// It is not possible to register an already-registered callback on a namespace node.%0
'//
%NS_E_NAMESPACE_DUPLICATE_CALLBACK = &HC00D1390&

'//
'// MessageId: NS_E_NAMESPACE_CALLBACK_NOT_FOUND
'//
'// MessageText:
'//
'// Cannot find the callback in the namespace when attempting to remove the callback.%0
'//
%NS_E_NAMESPACE_CALLBACK_NOT_FOUND = &HC00D1391&

'//
'// MessageId: NS_E_NAMESPACE_NAME_TOO_LONG
'//
'// MessageText:
'//
'// The namespace node name exceeds the allowed maximum length.%0
'//
%NS_E_NAMESPACE_NAME_TOO_LONG     = &HC00D1392&

'//
'// MessageId: NS_E_NAMESPACE_DUPLICATE_NAME
'//
'// MessageText:
'//
'// Cannot create a namespace node that already exists.%0
'//
%NS_E_NAMESPACE_DUPLICATE_NAME    = &HC00D1393&

'//
'// MessageId: NS_E_NAMESPACE_EMPTY_NAME
'//
'// MessageText:
'//
'// The namespace node name cannot be a null string.%0
'//
%NS_E_NAMESPACE_EMPTY_NAME        = &HC00D1394&

'//
'// MessageId: NS_E_NAMESPACE_INDEX_TOO_LARGE
'//
'// MessageText:
'//
'// Finding a child namespace node by index failed because the index exceeded the number of children.%0
'//
%NS_E_NAMESPACE_INDEX_TOO_LARGE   = &HC00D1395&

'//
'// MessageId: NS_E_NAMESPACE_BAD_NAME
'//
'// MessageText:
'//
'// The namespace node name is invalid.%0
'//
%NS_E_NAMESPACE_BAD_NAME          = &HC00D1396&

'//
'// MessageId: NS_E_NAMESPACE_WRONG_SECURITY
'//
'// MessageText:
'//
'// It is not possible to store a value in a namespace node that has a different security type.%0
'//
%NS_E_NAMESPACE_WRONG_SECURITY    = &HC00D1397&


 '// Cache Errors 5100-5199

'//
'// MessageId: NS_E_CACHE_ARCHIVE_CONFLICT
'//
'// MessageText:
'//
'// The archive request conflicts with other requests in progress.%0
'//
%NS_E_CACHE_ARCHIVE_CONFLICT      = &HC00D13EC&

'//
'// MessageId: NS_E_CACHE_ORIGIN_SERVER_NOT_FOUND
'//
'// MessageText:
'//
'// The specified origin server cannot be found.%0
'//
%NS_E_CACHE_ORIGIN_SERVER_NOT_FOUND = &HC00D13ED&

'//
'// MessageId: NS_E_CACHE_ORIGIN_SERVER_TIMEOUT
'//
'// MessageText:
'//
'// The specified origin server is not responding.%0
'//
%NS_E_CACHE_ORIGIN_SERVER_TIMEOUT = &HC00D13EE&

'//
'// MessageId: NS_E_CACHE_NOT_BROADCAST
'//
'// MessageText:
'//
'// The internal code for HTTP status code 412 Precondition Failed due to not broadcast type.%0
'//
%NS_E_CACHE_NOT_BROADCAST         = &HC00D13EF&

'//
'// MessageId: NS_E_CACHE_CANNOT_BE_CACHED
'//
'// MessageText:
'//
'// The internal code for HTTP status code 403 Forbidden due to not cacheable.%0
'//
%NS_E_CACHE_CANNOT_BE_CACHED      = &HC00D13F0&

'//
'// MessageId: NS_E_CACHE_NOT_MODIFIED
'//
'// MessageText:
'//
'// The internal code for HTTP status code 304 Not Modified.%0
'//
%NS_E_CACHE_NOT_MODIFIED          = &HC00D13F1&


'// Object Model Errors 5200-5299

'//
'// MessageId: NS_E_CANNOT_REMOVE_PUBLISHING_POINT
'//
'// MessageText:
'//
'// It is not possible to remove a cache or proxy publishing point.%0
'//
%NS_E_CANNOT_REMOVE_PUBLISHING_POINT = &HC00D1450&

'//
'// MessageId: NS_E_CANNOT_REMOVE_PLUGIN
'//
'// MessageText:
'//
'// It is not possible to remove the last instance of a type of plug-in.%0
'//
%NS_E_CANNOT_REMOVE_PLUGIN        = &HC00D1451&

'//
'// MessageId: NS_E_WRONG_PUBLISHING_POINT_TYPE
'//
'// MessageText:
'//
'// Cache and proxy publishing points do not support this property or method.%0
'//
%NS_E_WRONG_PUBLISHING_POINT_TYPE = &HC00D1452&

'//
'// MessageId: NS_E_UNSUPPORTED_LOAD_TYPE
'//
'// MessageText:
'//
'// The plug-in does not support the specified load type.%0
'//
%NS_E_UNSUPPORTED_LOAD_TYPE       = &HC00D1453&

'//
'// MessageId: NS_E_INVALID_PLUGIN_LOAD_TYPE_CONFIGURATION
'//
'// MessageText:
'//
'// The plug-in does not support any load types. The plug-in must support at least one load type.%0
'//
%NS_E_INVALID_PLUGIN_LOAD_TYPE_CONFIGURATION = &HC00D1454&

'//
'// MessageId: NS_E_INVALID_PUBLISHING_POINT_NAME
'//
'// MessageText:
'//
'// The publishing point name is invalid.%0
'//
%NS_E_INVALID_PUBLISHING_POINT_NAME = &HC00D1455&

'//
'// MessageId: NS_E_TOO_MANY_MULTICAST_SINKS
'//
'// MessageText:
'//
'// Only one multicast data writer plug-in can be enabled for a publishing point.%0
'//
%NS_E_TOO_MANY_MULTICAST_SINKS    = &HC00D1456&

'//
'// MessageId: NS_E_PUBLISHING_POINT_INVALID_REQUEST_WHILE_STARTED
'//
'// MessageText:
'//
'// The requested operation cannot be completed while the publishing point is started.%0
'//
%NS_E_PUBLISHING_POINT_INVALID_REQUEST_WHILE_STARTED = &HC00D1457&

'//
'// MessageId: NS_E_MULTICAST_PLUGIN_NOT_ENABLED
'//
'// MessageText:
'//
'// A multicast data writer plug-in must be enabled in order for this operation to be completed.%0
'//
%NS_E_MULTICAST_PLUGIN_NOT_ENABLED = &HC00D1458&

'//
'// MessageId: NS_E_INVALID_OPERATING_SYSTEM_VERSION
'//
'// MessageText:
'//
'// This feature requires Windows Server 2003, Enterprise Edition.%0
'//
%NS_E_INVALID_OPERATING_SYSTEM_VERSION = &HC00D1459&

'//
'// MessageId: NS_E_PUBLISHING_POINT_REMOVED
'//
'// MessageText:
'//
'// The requested operation cannot be completed because the specified publishing point has been removed.%0
'//
%NS_E_PUBLISHING_POINT_REMOVED    = &HC00D145A&

'//
'// MessageId: NS_E_INVALID_PUSH_PUBLISHING_POINT_START_REQUEST
'//
'// MessageText:
'//
'// Push publishing points are started when the encoder starts pushing the stream. This publishing point cannot be started by the server administrator.%0
'//
%NS_E_INVALID_PUSH_PUBLISHING_POINT_START_REQUEST = &HC00D145B&

'//
'// MessageId: NS_E_UNSUPPORTED_LANGUAGE
'//
'// MessageText:
'//
'// The specified language is not supported.%0
'//
%NS_E_UNSUPPORTED_LANGUAGE        = &HC00D145C&

'//
'// MessageId: NS_E_WRONG_OS_VERSION
'//
'// MessageText:
'//
'// Windows Media Services will only run on Windows Server 2003, Standard Edition and Windows Server 2003, Enterprise Edition.%0
'//
%NS_E_WRONG_OS_VERSION            = &HC00D145D&

'//
'// MessageId: NS_E_PUBLISHING_POINT_STOPPED
'//
'// MessageText:
'//
'// The operation cannot be completed because the publishing point has been stopped.%0
'//
%NS_E_PUBLISHING_POINT_STOPPED    = &HC00D145E&


'// Playlist Errors 5300-5399

'//
'// MessageId: NS_E_PLAYLIST_ENTRY_ALREADY_PLAYING
'//
'// MessageText:
'//
'// The playlist entry is already playing.%0
'//
%NS_E_PLAYLIST_ENTRY_ALREADY_PLAYING = &HC00D14B4&

'//
'// MessageId: NS_E_EMPTY_PLAYLIST
'//
'// MessageText:
'//
'// The playlist or directory you are requesting does not contain content.%0
'//
%NS_E_EMPTY_PLAYLIST              = &HC00D14B5&

'//
'// MessageId: NS_E_PLAYLIST_PARSE_FAILURE
'//
'// MessageText:
'//
'// The server was unable to parse the requested playlist file.%0
'//
%NS_E_PLAYLIST_PARSE_FAILURE      = &HC00D14B6&

'//
'// MessageId: NS_E_PLAYLIST_UNSUPPORTED_ENTRY
'//
'// MessageText:
'//
'// The requested operation is not supported for this type of playlist entry.%0
'//
%NS_E_PLAYLIST_UNSUPPORTED_ENTRY  = &HC00D14B7&

'//
'// MessageId: NS_E_PLAYLIST_ENTRY_NOT_IN_PLAYLIST
'//
'// MessageText:
'//
'// Cannot jump to a playlist entry that is not inserted in the playlist.%0
'//
%NS_E_PLAYLIST_ENTRY_NOT_IN_PLAYLIST = &HC00D14B8&

'//
'// MessageId: NS_E_PLAYLIST_ENTRY_SEEK
'//
'// MessageText:
'//
'// Cannot seek to the desired playlist entry.%0
'//
%NS_E_PLAYLIST_ENTRY_SEEK         = &HC00D14B9&

'//
'// MessageId: NS_E_PLAYLIST_RECURSIVE_PLAYLISTS
'//
'// MessageText:
'//
'// Cannot play recursive playlist.%0
'//
%NS_E_PLAYLIST_RECURSIVE_PLAYLISTS = &HC00D14BA&

'//
'// MessageId: NS_E_PLAYLIST_TOO_MANY_NESTED_PLAYLISTS
'//
'// MessageText:
'//
'// The number of nested playlists exceeded the limit the server can handle.%0
'//
%NS_E_PLAYLIST_TOO_MANY_NESTED_PLAYLISTS = &HC00D14BB&

'//
'// MessageId: NS_E_PLAYLIST_SHUTDOWN
'//
'// MessageText:
'//
'// Cannot execute the requested operation because the playlist has been shut down by the Media Server.%0
'//
%NS_E_PLAYLIST_SHUTDOWN           = &HC00D14BC&

'//
'// MessageId: NS_E_PLAYLIST_END_RECEDING
'//
'// MessageText:
'//
'// The playlist has ended while receding.%0
'//
%NS_E_PLAYLIST_END_RECEDING       = &HC00D14BD&

'//
'// MessageId: NS_I_PLAYLIST_CHANGE_RECEDING
'//
'// MessageText:
'//
'// The playlist change occurred while receding.%0
'//
%NS_I_PLAYLIST_CHANGE_RECEDING    = &H400D14BE&


'// Datapath Errors -- 5400 - 5499

'//
'// MessageId: NS_E_DATAPATH_NO_SINK
'//
'// MessageText:
'//
'// The data path does not have an associated data writer plug-in.%0
'//
%NS_E_DATAPATH_NO_SINK            = &HC00D1518&

'//
'// MessageId: NS_S_PUBLISHING_POINT_STARTED_WITH_FAILED_SINKS
'//
'// MessageText:
'//
'// The publishing point successfully started, but one or more of the requested data writer plug-ins failed.%0
'//
%NS_S_PUBLISHING_POINT_STARTED_WITH_FAILED_SINKS = &H000D1519&

'//
'// MessageId: NS_E_INVALID_PUSH_TEMPLATE
'//
'// MessageText:
'//
'// The specified push template is invalid.%0
'//
%NS_E_INVALID_PUSH_TEMPLATE       = &HC00D151A&

'//
'// MessageId: NS_E_INVALID_PUSH_PUBLISHING_POINT
'//
'// MessageText:
'//
'// The specified push publishing point is invalid.%0
'//
%NS_E_INVALID_PUSH_PUBLISHING_POINT = &HC00D151B&

'//
'// MessageId: NS_E_CRITICAL_ERROR
'//
'// MessageText:
'//
'// The requested operation cannot be performed because the server or publishing point is in a critical error state.%0
'//
%NS_E_CRITICAL_ERROR              = &HC00D151C&

'//
'// MessageId: NS_E_NO_NEW_CONNECTIONS
'//
'// MessageText:
'//
'// The content can not be played because the server is not currently accepting connections. Try connecting at a later time.%0
'//
%NS_E_NO_NEW_CONNECTIONS          = &HC00D151D&

'//
'// MessageId: NS_E_WSX_INVALID_VERSION
'//
'// MessageText:
'//
'// The version of this playlist is not supported by the server.%0
'//
%NS_E_WSX_INVALID_VERSION         = &HC00D151E&

'//
'// MessageId: NS_E_HEADER_MISMATCH
'//
'// MessageText:
'//
'// The command does not apply to the current media header user by a server component.%0
'//
%NS_E_HEADER_MISMATCH             = &HC00D151F&

'//
'// MessageId: NS_E_PUSH_DUPLICATE_PUBLISHING_POINT_NAME
'//
'// MessageText:
'//
'// The specified publishing point name is already in use.%0
'//
%NS_E_PUSH_DUPLICATE_PUBLISHING_POINT_NAME = &HC00D1520&


'// Plugin Errors -- 5500 - 5599

'//
'// MessageId: NS_E_NO_SCRIPT_ENGINE
'//
'// MessageText:
'//
'// There is no script engine available for this file.%0
'//
%NS_E_NO_SCRIPT_ENGINE            = &HC00D157C&

'//
'// MessageId: NS_E_PLUGIN_ERROR_REPORTED
'//
'// MessageText:
'//
'// The plug-in has reported an error. See the Troubleshooting tab or the NT Application Event Log for details.%0
'//
%NS_E_PLUGIN_ERROR_REPORTED       = &HC00D157D&

'//
'// MessageId: NS_E_SOURCE_PLUGIN_NOT_FOUND
'//
'// MessageText:
'//
'// No enabled data source plug-in is available to access the requested content.%0
'//
%NS_E_SOURCE_PLUGIN_NOT_FOUND     = &HC00D157E&

'//
'// MessageId: NS_E_PLAYLIST_PLUGIN_NOT_FOUND
'//
'// MessageText:
'//
'// No enabled playlist parser plug-in is available to access the requested content.%0
'//
%NS_E_PLAYLIST_PLUGIN_NOT_FOUND   = &HC00D157F&

'//
'// MessageId: NS_E_DATA_SOURCE_ENUMERATION_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The data source plug-in does not support enumeration.%0
'//
%NS_E_DATA_SOURCE_ENUMERATION_NOT_SUPPORTED = &HC00D1580&

'//
'// MessageId: NS_E_MEDIA_PARSER_INVALID_FORMAT
'//
'// MessageText:
'//
'// The server cannot stream the selected file because it is either damaged or corrupt. Select a different file.%0
'//
%NS_E_MEDIA_PARSER_INVALID_FORMAT = &HC00D1581&

'//
'// MessageId: NS_E_SCRIPT_DEBUGGER_NOT_INSTALLED
'//
'// MessageText:
'//
'// The plug-in cannot be enabled because a compatible script debugger is not installed on this system.  Install a script debugger, or disable the script debugger option on the general tab of the plug-in's properties page and try again.%0
'//
%NS_E_SCRIPT_DEBUGGER_NOT_INSTALLED = &HC00D1582&

'//
'// MessageId: NS_E_FEATURE_REQUIRES_ENTERPRISE_SERVER
'//
'// MessageText:
'//
'// The plug-in cannot be loaded because it requires Windows Server 2003, Enterprise Edition.%0
'//
%NS_E_FEATURE_REQUIRES_ENTERPRISE_SERVER = &HC00D1583&

'//
'// MessageId: NS_E_WIZARD_RUNNING
'//
'// MessageText:
'//
'// Another wizard is currently running. Please close the other wizard or wait until it finishes before attempting to run this wizard again.%0
'//
%NS_E_WIZARD_RUNNING              = &HC00D1584&

'//
'// MessageId: NS_E_INVALID_LOG_URL
'//
'// MessageText:
'//
'// Invalid log URL. Multicast logging URL must look like "http:'//servername/isapibackend.dll" .%0
'//
%NS_E_INVALID_LOG_URL             = &HC00D1585&

'//
'// MessageId: NS_E_INVALID_MTU_RANGE
'//
'// MessageText:
'//
'// Invalid MTU specified. The valid range for maximum packet size is between 36  and 65507 bytes .%0
'//
%NS_E_INVALID_MTU_RANGE           = &HC00D1586&

'//
'// MessageId: NS_E_INVALID_PLAY_STATISTICS
'//
'// MessageText:
'//
'// Invalid play statistics for logging .%0
'//
%NS_E_INVALID_PLAY_STATISTICS     = &HC00D1587&

'//
'// MessageId: NS_E_LOG_NEED_TO_BE_SKIPPED
'//
'// MessageText:
'//
'// The log needs to be skipped .%0
'//
%NS_E_LOG_NEED_TO_BE_SKIPPED      = &HC00D1588&

'//
'// MessageId: NS_E_HTTP_TEXT_DATACONTAINER_SIZE_LIMIT_EXCEEDED
'//
'// MessageText:
'//
'// The size of the data exceeded the limit the WMS HTTP Download Data Source plugin can handle.%0
'//
%NS_E_HTTP_TEXT_DATACONTAINER_SIZE_LIMIT_EXCEEDED = &HC00D1589&

'//
'// MessageId: NS_E_PORT_IN_USE
'//
'// MessageText:
'//
'// One usage of each socket address (protocol/network address/port) is permitted. Verify that other services or applications are not attempting to use the same port and then try to enable the plug-in again.%0
'//
%NS_E_PORT_IN_USE                 = &HC00D158A&

'//
'// MessageId: NS_E_PORT_IN_USE_HTTP
'//
'// MessageText:
'//
'// One usage of each socket address (protocol/network address/port) is permitted. Verify that other services (such as IIS) or applications are not attempting to use the same port and then try to enable the plug-in again.%0
'//
%NS_E_PORT_IN_USE_HTTP            = &HC00D158B&

'//
'// MessageId: NS_E_HTTP_TEXT_DATACONTAINER_INVALID_SERVER_RESPONSE
'//
'// MessageText:
'//
'// The WMS HTTP Download Data Source plugin was unable to receive the remote server's response.%0
'//
%NS_E_HTTP_TEXT_DATACONTAINER_INVALID_SERVER_RESPONSE = &HC00D158C&

'//
'// MessageId: NS_E_ARCHIVE_REACH_QUOTA
'//
'// MessageText:
'//
'// The archive plug-in has reached its quota.%0
'//
%NS_E_ARCHIVE_REACH_QUOTA         = &HC00D158D&

'//
'// MessageId: NS_E_ARCHIVE_ABORT_DUE_TO_BCAST
'//
'// MessageText:
'//
'// The archive plug-in aborted because the source was from broadcast.%0
'//
%NS_E_ARCHIVE_ABORT_DUE_TO_BCAST  = &HC00D158E&

'//
'// MessageId: NS_E_ARCHIVE_GAP_DETECTED
'//
'// MessageText:
'//
'// The archive plug-in detected an interrupt in the source.%0
'//
%NS_E_ARCHIVE_GAP_DETECTED        = &HC00D158F&

'//
'// MessageId: NS_E_AUTHORIZATION_FILE_NOT_FOUND
'//
'// MessageText:
'//
'// The system cannot find the file specified.%0
'//
%NS_E_AUTHORIZATION_FILE_NOT_FOUND = &HC00D1590&



'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Tools Errors
'//
'// IdRange = 7000 - 7999
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: NS_E_BAD_MARKIN
'//
'// MessageText:
'//
'// The mark-in time should be greater than 0 and less than the mark-out time.%0
'//
%NS_E_BAD_MARKIN                  = &HC00D1B58&

'//
'// MessageId: NS_E_BAD_MARKOUT
'//
'// MessageText:
'//
'// The mark-out time should be greater than the mark-in time and less than the file duration.%0
'//
%NS_E_BAD_MARKOUT                 = &HC00D1B59&

'//
'// MessageId: NS_E_NOMATCHING_MEDIASOURCE
'//
'// MessageText:
'//
'// No matching media type is found in the source %1.%0
'//
%NS_E_NOMATCHING_MEDIASOURCE      = &HC00D1B5A&

'//
'// MessageId: NS_E_UNSUPPORTED_SOURCETYPE
'//
'// MessageText:
'//
'// The specified source type is not supported.%0
'//
%NS_E_UNSUPPORTED_SOURCETYPE      = &HC00D1B5B&

'//
'// MessageId: NS_E_TOO_MANY_AUDIO
'//
'// MessageText:
'//
'// It is not possible to specify more than one audio input.%0
'//
%NS_E_TOO_MANY_AUDIO              = &HC00D1B5C&

'//
'// MessageId: NS_E_TOO_MANY_VIDEO
'//
'// MessageText:
'//
'// It is not possible to specify more than two video inputs.%0
'//
%NS_E_TOO_MANY_VIDEO              = &HC00D1B5D&

'//
'// MessageId: NS_E_NOMATCHING_ELEMENT
'//
'// MessageText:
'//
'// No matching element is found in the list.%0
'//
%NS_E_NOMATCHING_ELEMENT          = &HC00D1B5E&

'//
'// MessageId: NS_E_MISMATCHED_MEDIACONTENT
'//
'// MessageText:
'//
'// The profile's media types must match the media types defined for the session.%0
'//
%NS_E_MISMATCHED_MEDIACONTENT     = &HC00D1B5F&

'//
'// MessageId: NS_E_CANNOT_DELETE_ACTIVE_SOURCEGROUP
'//
'// MessageText:
'//
'// It is not possible to remove an active source while encoding.%0
'//
%NS_E_CANNOT_DELETE_ACTIVE_SOURCEGROUP = &HC00D1B60&

'//
'// MessageId: NS_E_AUDIODEVICE_BUSY
'//
'// MessageText:
'//
'// It is not possible to open the specified audio capture device because it is currently in use.%0
'//
%NS_E_AUDIODEVICE_BUSY            = &HC00D1B61&

'//
'// MessageId: NS_E_AUDIODEVICE_UNEXPECTED
'//
'// MessageText:
'//
'// It is not possible to open the specified audio capture device because an unexpected error has occurred.%0
'//
%NS_E_AUDIODEVICE_UNEXPECTED      = &HC00D1B62&

'//
'// MessageId: NS_E_AUDIODEVICE_BADFORMAT
'//
'// MessageText:
'//
'// The audio capture device does not support the specified audio format.%0
'//
%NS_E_AUDIODEVICE_BADFORMAT       = &HC00D1B63&

'//
'// MessageId: NS_E_VIDEODEVICE_BUSY
'//
'// MessageText:
'//
'// It is not possible to open the specified video capture device because it is currently in use.%0
'//
%NS_E_VIDEODEVICE_BUSY            = &HC00D1B64&

'//
'// MessageId: NS_E_VIDEODEVICE_UNEXPECTED
'//
'// MessageText:
'//
'// It is not possible to open the specified video capture device because an unexpected error has occurred.%0
'//
%NS_E_VIDEODEVICE_UNEXPECTED      = &HC00D1B65&

'//
'// MessageId: NS_E_INVALIDCALL_WHILE_ENCODER_RUNNING
'//
'// MessageText:
'//
'// This operation is not allowed while encoding.%0
'//
%NS_E_INVALIDCALL_WHILE_ENCODER_RUNNING = &HC00D1B66&

'//
'// MessageId: NS_E_NO_PROFILE_IN_SOURCEGROUP
'//
'// MessageText:
'//
'// No profile is set for the source.%0
'//
%NS_E_NO_PROFILE_IN_SOURCEGROUP   = &HC00D1B67&

'//
'// MessageId: NS_E_VIDEODRIVER_UNSTABLE
'//
'// MessageText:
'//
'// The video capture driver returned an unrecoverable error.  It is now in an unstable state.%0
'//
%NS_E_VIDEODRIVER_UNSTABLE        = &HC00D1B68&

'//
'// MessageId: NS_E_VIDCAPSTARTFAILED
'//
'// MessageText:
'//
'// It was not possible to start the video device.%0
'//
%NS_E_VIDCAPSTARTFAILED           = &HC00D1B69&

'//
'// MessageId: NS_E_VIDSOURCECOMPRESSION
'//
'// MessageText:
'//
'// The video source does not support the requested output format or color depth.%0
'//
%NS_E_VIDSOURCECOMPRESSION        = &HC00D1B6A&

'//
'// MessageId: NS_E_VIDSOURCESIZE
'//
'// MessageText:
'//
'// The video source does not support the requested capture size.%0
'//
%NS_E_VIDSOURCESIZE               = &HC00D1B6B&

'//
'// MessageId: NS_E_ICMQUERYFORMAT
'//
'// MessageText:
'//
'// It was not possible to obtain output information from the video compressor.%0
'//
%NS_E_ICMQUERYFORMAT              = &HC00D1B6C&

'//
'// MessageId: NS_E_VIDCAPCREATEWINDOW
'//
'// MessageText:
'//
'// It was not possible to create a video capture window.%0
'//
%NS_E_VIDCAPCREATEWINDOW          = &HC00D1B6D&

'//
'// MessageId: NS_E_VIDCAPDRVINUSE
'//
'// MessageText:
'//
'// There is already a stream active on this video device.%0
'//
%NS_E_VIDCAPDRVINUSE              = &HC00D1B6E&

'//
'// MessageId: NS_E_NO_MEDIAFORMAT_IN_SOURCE
'//
'// MessageText:
'//
'// No media format is set in source.%0
'//
%NS_E_NO_MEDIAFORMAT_IN_SOURCE    = &HC00D1B6F&

'//
'// MessageId: NS_E_NO_VALID_OUTPUT_STREAM
'//
'// MessageText:
'//
'// Cannot find a valid output stream from the source.%0
'//
%NS_E_NO_VALID_OUTPUT_STREAM      = &HC00D1B70&

'//
'// MessageId: NS_E_NO_VALID_SOURCE_PLUGIN
'//
'// MessageText:
'//
'// It was not possible to find a valid source plug-in for the specified source.%0
'//
%NS_E_NO_VALID_SOURCE_PLUGIN      = &HC00D1B71&

'//
'// MessageId: NS_E_NO_ACTIVE_SOURCEGROUP
'//
'// MessageText:
'//
'// No source is currently active.%0
'//
%NS_E_NO_ACTIVE_SOURCEGROUP       = &HC00D1B72&

'//
'// MessageId: NS_E_NO_SCRIPT_STREAM
'//
'// MessageText:
'//
'// No script stream is set in the current source.%0
'//
%NS_E_NO_SCRIPT_STREAM            = &HC00D1B73&

'//
'// MessageId: NS_E_INVALIDCALL_WHILE_ARCHIVAL_RUNNING
'//
'// MessageText:
'//
'// This operation is not allowed while archiving.%0
'//
%NS_E_INVALIDCALL_WHILE_ARCHIVAL_RUNNING = &HC00D1B74&

'//
'// MessageId: NS_E_INVALIDPACKETSIZE
'//
'// MessageText:
'//
'// The setting for the maximum packet size is not valid.%0
'//
%NS_E_INVALIDPACKETSIZE           = &HC00D1B75&

'//
'// MessageId: NS_E_PLUGIN_CLSID_INVALID
'//
'// MessageText:
'//
'// The plug-in CLSID specified is not valid.%0
'//
%NS_E_PLUGIN_CLSID_INVALID        = &HC00D1B76&

'//
'// MessageId: NS_E_UNSUPPORTED_ARCHIVETYPE
'//
'// MessageText:
'//
'// This archive type is not supported.%0
'//
%NS_E_UNSUPPORTED_ARCHIVETYPE     = &HC00D1B77&

'//
'// MessageId: NS_E_UNSUPPORTED_ARCHIVEOPERATION
'//
'// MessageText:
'//
'// This archive operation is not supported.%0
'//
%NS_E_UNSUPPORTED_ARCHIVEOPERATION = &HC00D1B78&

'//
'// MessageId: NS_E_ARCHIVE_FILENAME_NOTSET
'//
'// MessageText:
'//
'// The local archive file name was not set.%0
'//
%NS_E_ARCHIVE_FILENAME_NOTSET     = &HC00D1B79&

'//
'// MessageId: NS_E_SOURCEGROUP_NOTPREPARED
'//
'// MessageText:
'//
'// The source is not yet prepared.%0
'//
%NS_E_SOURCEGROUP_NOTPREPARED     = &HC00D1B7A&

'//
'// MessageId: NS_E_PROFILE_MISMATCH
'//
'// MessageText:
'//
'// Profiles on the sources do not match.%0
'//
%NS_E_PROFILE_MISMATCH            = &HC00D1B7B&

'//
'// MessageId: NS_E_INCORRECTCLIPSETTINGS
'//
'// MessageText:
'//
'// The specified crop values are not valid.%0
'//
%NS_E_INCORRECTCLIPSETTINGS       = &HC00D1B7C&

'//
'// MessageId: NS_E_NOSTATSAVAILABLE
'//
'// MessageText:
'//
'// No statistics are available at this time.%0
'//
%NS_E_NOSTATSAVAILABLE            = &HC00D1B7D&

'//
'// MessageId: NS_E_NOTARCHIVING
'//
'// MessageText:
'//
'// The encoder is not archiving.%0
'//
%NS_E_NOTARCHIVING                = &HC00D1B7E&

'//
'// MessageId: NS_E_INVALIDCALL_WHILE_ENCODER_STOPPED
'//
'// MessageText:
'//
'// This operation is only allowed during encoding.%0
'//
%NS_E_INVALIDCALL_WHILE_ENCODER_STOPPED = &HC00D1B7F&

'//
'// MessageId: NS_E_NOSOURCEGROUPS
'//
'// MessageText:
'//
'// This SourceGroupCollection doesn't contain any SourceGroups.%0
'//
%NS_E_NOSOURCEGROUPS              = &HC00D1B80&

'//
'// MessageId: NS_E_INVALIDINPUTFPS
'//
'// MessageText:
'//
'// This source does not have a frame rate of 30 fps. Therefore, it is not possible to apply the inverse telecine filter to the source.%0
'//
%NS_E_INVALIDINPUTFPS             = &HC00D1B81&

'//
'// MessageId: NS_E_NO_DATAVIEW_SUPPORT
'//
'// MessageText:
'//
'// It is not possible to display your source or output video in the Video panel.%0
'//
%NS_E_NO_DATAVIEW_SUPPORT         = &HC00D1B82&

'//
'// MessageId: NS_E_CODEC_UNAVAILABLE
'//
'// MessageText:
'//
'// One or more codecs required to open this content could not be found.%0
'//
%NS_E_CODEC_UNAVAILABLE           = &HC00D1B83&

'//
'// MessageId: NS_E_ARCHIVE_SAME_AS_INPUT
'//
'// MessageText:
'//
'// The archive file has the same name as an input file. Change one of the names before continuing.%0
'//
%NS_E_ARCHIVE_SAME_AS_INPUT       = &HC00D1B84&

'//
'// MessageId: NS_E_SOURCE_NOTSPECIFIED
'//
'// MessageText:
'//
'// The source has not been set up completely.%0
'//
%NS_E_SOURCE_NOTSPECIFIED         = &HC00D1B85&

'//
'// MessageId: NS_E_NO_REALTIME_TIMECOMPRESSION
'//
'// MessageText:
'//
'// It is not possible to apply time compression to a broadcast session.%0
'//
%NS_E_NO_REALTIME_TIMECOMPRESSION = &HC00D1B86&

'//
'// MessageId: NS_E_UNSUPPORTED_ENCODER_DEVICE
'//
'// MessageText:
'//
'// It is not possible to open this device.%0
'//
%NS_E_UNSUPPORTED_ENCODER_DEVICE  = &HC00D1B87&

'//
'// MessageId: NS_E_UNEXPECTED_DISPLAY_SETTINGS
'//
'// MessageText:
'//
'// It is not possible to start encoding because the display size or color has changed since the current session was defined. Restore the previous settings or create a new session.%0
'//
%NS_E_UNEXPECTED_DISPLAY_SETTINGS = &HC00D1B88&

'//
'// MessageId: NS_E_NO_AUDIODATA
'//
'// MessageText:
'//
'// No audio data has been received for several seconds. Check the audio source and restart the encoder.%0
'//
%NS_E_NO_AUDIODATA                = &HC00D1B89&

'//
'// MessageId: NS_E_INPUTSOURCE_PROBLEM
'//
'// MessageText:
'//
'// One or all of the specified sources are not working properly. Check that the sources are configured correctly.%0
'//
%NS_E_INPUTSOURCE_PROBLEM         = &HC00D1B8A&

'//
'// MessageId: NS_E_WME_VERSION_MISMATCH
'//
'// MessageText:
'//
'// The supplied configuration file is not supported by this version of the encoder.%0
'//
%NS_E_WME_VERSION_MISMATCH        = &HC00D1B8B&

'//
'// MessageId: NS_E_NO_REALTIME_PREPROCESS
'//
'// MessageText:
'//
'// It is not possible to use image preprocessing with live encoding.%0
'//
%NS_E_NO_REALTIME_PREPROCESS      = &HC00D1B8C&

'//
'// MessageId: NS_E_NO_REPEAT_PREPROCESS
'//
'// MessageText:
'//
'// It is not possible to use two-pass encoding when the source is set to loop.%0
'//
%NS_E_NO_REPEAT_PREPROCESS        = &HC00D1B8D&

'//
'// MessageId: NS_E_CANNOT_PAUSE_LIVEBROADCAST
'//
'// MessageText:
'//
'// It is not possible to pause encoding during a broadcast.%0
'//
%NS_E_CANNOT_PAUSE_LIVEBROADCAST  = &HC00D1B8E&

'//
'// MessageId: NS_E_DRM_PROFILE_NOT_SET
'//
'// MessageText:
'//
'// A DRM profile has not been set for the current session.%0
'//
%NS_E_DRM_PROFILE_NOT_SET         = &HC00D1B8F&

'//
'// MessageId: NS_E_DUPLICATE_DRMPROFILE
'//
'// MessageText:
'//
'// The profile ID is already used by a DRM profile. Specify a different profile ID.%0
'//
%NS_E_DUPLICATE_DRMPROFILE        = &HC00D1B90&

'//
'// MessageId: NS_E_INVALID_DEVICE
'//
'// MessageText:
'//
'// The setting of the selected device does not support control for playing back tapes.%0
'//
%NS_E_INVALID_DEVICE              = &HC00D1B91&

'//
'// MessageId: NS_E_SPEECHEDL_ON_NON_MIXEDMODE
'//
'// MessageText:
'//
'// You must specify a mixed voice and audio mode in order to use an optimization definition file.%0
'//
%NS_E_SPEECHEDL_ON_NON_MIXEDMODE  = &HC00D1B92&

'//
'// MessageId: NS_E_DRM_PASSWORD_TOO_LONG
'//
'// MessageText:
'//
'// The specified password is too long. Type a password with fewer than 8 characters.%0
'//
%NS_E_DRM_PASSWORD_TOO_LONG       = &HC00D1B93&

'//
'// MessageId: NS_E_DEVCONTROL_FAILED_SEEK
'//
'// MessageText:
'//
'// It is not possible to seek to the specified mark-in point.%0
'//
%NS_E_DEVCONTROL_FAILED_SEEK      = &HC00D1B94&

'//
'// MessageId: NS_E_INTERLACE_REQUIRE_SAMESIZE
'//
'// MessageText:
'//
'// When you choose to maintain the interlacing in your video, the output video size must match the input video size.%0
'//
%NS_E_INTERLACE_REQUIRE_SAMESIZE  = &HC00D1B95&

'//
'// MessageId: NS_E_TOO_MANY_DEVICECONTROL
'//
'// MessageText:
'//
'// Only one device control plug-in can control a device.%0
'//
%NS_E_TOO_MANY_DEVICECONTROL      = &HC00D1B96&

'//
'// MessageId: NS_E_NO_MULTIPASS_FOR_LIVEDEVICE
'//
'// MessageText:
'//
'// You must also enable storing content to hard disk temporarily in order to use two-pass encoding with the input device.%0
'//
%NS_E_NO_MULTIPASS_FOR_LIVEDEVICE = &HC00D1B97&

'//
'// MessageId: NS_E_MISSING_AUDIENCE
'//
'// MessageText:
'//
'// An audience is missing from the output stream configuration.%0
'//
%NS_E_MISSING_AUDIENCE            = &HC00D1B98&

'//
'// MessageId: NS_E_AUDIENCE_CONTENTTYPE_MISMATCH
'//
'// MessageText:
'//
'// All audiences in the output tree must have the same content type.%0
'//
%NS_E_AUDIENCE_CONTENTTYPE_MISMATCH = &HC00D1B99&

'//
'// MessageId: NS_E_MISSING_SOURCE_INDEX
'//
'// MessageText:
'//
'// A source index is missing from the output stream configuration.%0
'//
%NS_E_MISSING_SOURCE_INDEX        = &HC00D1B9A&

'//
'// MessageId: NS_E_NUM_LANGUAGE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should have the same number of languages.%0
'//
%NS_E_NUM_LANGUAGE_MISMATCH       = &HC00D1B9B&

'//
'// MessageId: NS_E_LANGUAGE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should have the same languages.%0
'//
%NS_E_LANGUAGE_MISMATCH           = &HC00D1B9C&

'//
'// MessageId: NS_E_VBRMODE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should use the same VBR encoding mode.%0
'//
%NS_E_VBRMODE_MISMATCH            = &HC00D1B9D&

'//
'// MessageId: NS_E_INVALID_INPUT_AUDIENCE_INDEX
'//
'// MessageText:
'//
'// The bit rate index specified is not valid.%0
'//
%NS_E_INVALID_INPUT_AUDIENCE_INDEX = &HC00D1B9E&

'//
'// MessageId: NS_E_INVALID_INPUT_LANGUAGE
'//
'// MessageText:
'//
'// The specified language is not valid.%0
'//
%NS_E_INVALID_INPUT_LANGUAGE      = &HC00D1B9F&

'//
'// MessageId: NS_E_INVALID_INPUT_STREAM
'//
'// MessageText:
'//
'// The specified source type is not valid.%0
'//
%NS_E_INVALID_INPUT_STREAM        = &HC00D1BA0&

'//
'// MessageId: NS_E_EXPECT_MONO_WAV_INPUT
'//
'// MessageText:
'//
'// The source must be a mono channel .wav file.%0
'//
%NS_E_EXPECT_MONO_WAV_INPUT       = &HC00D1BA1&

'//
'// MessageId: NS_E_INPUT_WAVFORMAT_MISMATCH
'//
'// MessageText:
'//
'// All the source .wav files must have the same format.%0
'//
%NS_E_INPUT_WAVFORMAT_MISMATCH    = &HC00D1BA2&

'//
'// MessageId: NS_E_RECORDQ_DISK_FULL
'//
'// MessageText:
'//
'// The hard disk being used for temporary storage of content has reached the minimum allowed disk space. Create more space on the hard disk and restart encoding.%0
'//
%NS_E_RECORDQ_DISK_FULL           = &HC00D1BA3&

'//
'// MessageId: NS_E_NO_PAL_INVERSE_TELECINE
'//
'// MessageText:
'//
'// It is not possible to apply the inverse telecine feature to PAL content.%0
'//
%NS_E_NO_PAL_INVERSE_TELECINE     = &HC00D1BA4&

'//
'// MessageId: NS_E_ACTIVE_SG_DEVICE_DISCONNECTED
'//
'// MessageText:
'//
'// A capture device in the current active source is no longer available.%0
'//
%NS_E_ACTIVE_SG_DEVICE_DISCONNECTED = &HC00D1BA5&

'//
'// MessageId: NS_E_ACTIVE_SG_DEVICE_CONTROL_DISCONNECTED
'//
'// MessageText:
'//
'// A device used in the current active source for device control is no longer available.%0
'//
%NS_E_ACTIVE_SG_DEVICE_CONTROL_DISCONNECTED = &HC00D1BA6&

'//
'// MessageId: NS_E_NO_FRAMES_SUBMITTED_TO_ANALYZER
'//
'// MessageText:
'//
'// No frames have been submitted to the analyzer for analysis.%0
'//
%NS_E_NO_FRAMES_SUBMITTED_TO_ANALYZER = &HC00D1BA7&

'//
'// MessageId: NS_E_INPUT_DOESNOT_SUPPORT_SMPTE
'//
'// MessageText:
'//
'// The source video does not support time codes.%0
'//
%NS_E_INPUT_DOESNOT_SUPPORT_SMPTE = &HC00D1BA8&

'//
'// MessageId: NS_E_NO_SMPTE_WITH_MULTIPLE_SOURCEGROUPS
'//
'// MessageText:
'//
'// It is not possible to generate a time code when there are multiple sources in a session.%0
'//
%NS_E_NO_SMPTE_WITH_MULTIPLE_SOURCEGROUPS = &HC00D1BA9&

'//
'// MessageId: NS_E_BAD_CONTENTEDL
'//
'// MessageText:
'//
'// The voice codec optimization definition file can not be found or is corrupted.%0
'//
%NS_E_BAD_CONTENTEDL              = &HC00D1BAA&

'//
'// MessageId: NS_E_INTERLACEMODE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should have the same interlace mode.%0
'//
%NS_E_INTERLACEMODE_MISMATCH      = &HC00D1BAB&

'//
'// MessageId: NS_E_NONSQUAREPIXELMODE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should have the same nonsquare pixel mode.%0
'//
%NS_E_NONSQUAREPIXELMODE_MISMATCH = &HC00D1BAC&

'//
'// MessageId: NS_E_SMPTEMODE_MISMATCH
'//
'// MessageText:
'//
'// The same source index in different audiences should have the same time code mode.%0
'//
%NS_E_SMPTEMODE_MISMATCH          = &HC00D1BAD&

'//
'// MessageId: NS_E_END_OF_TAPE
'//
'// MessageText:
'//
'// Either the end of the tape has been reached or there is no tape. Check the device and tape.%0
'//
%NS_E_END_OF_TAPE                 = &HC00D1BAE&

'//
'// MessageId: NS_E_NO_MEDIA_IN_AUDIENCE
'//
'// MessageText:
'//
'// No audio or video input has been specified.%0
'//
%NS_E_NO_MEDIA_IN_AUDIENCE        = &HC00D1BAF&

'//
'// MessageId: NS_E_NO_AUDIENCES
'//
'// MessageText:
'//
'// The profile must contain a bit rate.%0
'//
%NS_E_NO_AUDIENCES                = &HC00D1BB0&

'//
'// MessageId: NS_E_NO_AUDIO_COMPAT
'//
'// MessageText:
'//
'// You must specify at least one audio stream to be compatible with Windows Media Player 7.1.%0
'//
%NS_E_NO_AUDIO_COMPAT             = &HC00D1BB1&

'//
'// MessageId: NS_E_INVALID_VBR_COMPAT
'//
'// MessageText:
'//
'// Using a VBR encoding mode is not compatible with Windows Media Player 7.1.%0
'//
%NS_E_INVALID_VBR_COMPAT          = &HC00D1BB2&

'//
'// MessageId: NS_E_NO_PROFILE_NAME
'//
'// MessageText:
'//
'// You must specify a profile name.%0
'//
%NS_E_NO_PROFILE_NAME             = &HC00D1BB3&

'//
'// MessageId: NS_E_INVALID_VBR_WITH_UNCOMP
'//
'// MessageText:
'//
'// It is not possible to use a VBR encoding mode with uncompressed audio or video.%0
'//
%NS_E_INVALID_VBR_WITH_UNCOMP     = &HC00D1BB4&

'//
'// MessageId: NS_E_MULTIPLE_VBR_AUDIENCES
'//
'// MessageText:
'//
'// It is not possible to use MBR encoding with VBR encoding.%0
'//
%NS_E_MULTIPLE_VBR_AUDIENCES      = &HC00D1BB5&

'//
'// MessageId: NS_E_UNCOMP_COMP_COMBINATION
'//
'// MessageText:
'//
'// It is not possible to mix uncompressed and compressed content in a session.%0
'//
%NS_E_UNCOMP_COMP_COMBINATION     = &HC00D1BB6&

'//
'// MessageId: NS_E_MULTIPLE_AUDIO_CODECS
'//
'// MessageText:
'//
'// All audiences must use the same audio codec.%0
'//
%NS_E_MULTIPLE_AUDIO_CODECS       = &HC00D1BB7&

'//
'// MessageId: NS_E_MULTIPLE_AUDIO_FORMATS
'//
'// MessageText:
'//
'// All audiences should use the same audio format to be compatible with Windows Media Player 7.1.%0
'//
%NS_E_MULTIPLE_AUDIO_FORMATS      = &HC00D1BB8&

'//
'// MessageId: NS_E_AUDIO_BITRATE_STEPDOWN
'//
'// MessageText:
'//
'// The audio bit rate for an audience with a higher total bit rate must be greater than one with a lower total bit rate.%0
'//
%NS_E_AUDIO_BITRATE_STEPDOWN      = &HC00D1BB9&

'//
'// MessageId: NS_E_INVALID_AUDIO_PEAKRATE
'//
'// MessageText:
'//
'// The audio peak bit rate setting is not valid.%0
'//
%NS_E_INVALID_AUDIO_PEAKRATE      = &HC00D1BBA&

'//
'// MessageId: NS_E_INVALID_AUDIO_PEAKRATE_2
'//
'// MessageText:
'//
'// The audio peak bit rate setting must be greater than the audio bit rate setting.%0
'//
%NS_E_INVALID_AUDIO_PEAKRATE_2    = &HC00D1BBB&

'//
'// MessageId: NS_E_INVALID_AUDIO_BUFFERMAX
'//
'// MessageText:
'//
'// The setting for the maximum buffer size for audio is not valid.%0
'//
%NS_E_INVALID_AUDIO_BUFFERMAX     = &HC00D1BBC&

'//
'// MessageId: NS_E_MULTIPLE_VIDEO_CODECS
'//
'// MessageText:
'//
'// All audiences must use the same video codec.%0
'//
%NS_E_MULTIPLE_VIDEO_CODECS       = &HC00D1BBD&

'//
'// MessageId: NS_E_MULTIPLE_VIDEO_SIZES
'//
'// MessageText:
'//
'// All audiences should use the same video size to be compatible with Windows Media Player 7.1.%0
'//
%NS_E_MULTIPLE_VIDEO_SIZES        = &HC00D1BBE&

'//
'// MessageId: NS_E_INVALID_VIDEO_BITRATE
'//
'// MessageText:
'//
'// The video bit rate setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_BITRATE       = &HC00D1BBF&

'//
'// MessageId: NS_E_VIDEO_BITRATE_STEPDOWN
'//
'// MessageText:
'//
'// The video bit rate for an audience with a higher total bit rate must be greater than one with a lower total bit rate.%0
'//
%NS_E_VIDEO_BITRATE_STEPDOWN      = &HC00D1BC0&

'//
'// MessageId: NS_E_INVALID_VIDEO_PEAKRATE
'//
'// MessageText:
'//
'// The video peak bit rate setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_PEAKRATE      = &HC00D1BC1&

'//
'// MessageId: NS_E_INVALID_VIDEO_PEAKRATE_2
'//
'// MessageText:
'//
'// The video peak bit rate setting must be greater than the video bit rate setting.%0
'//
%NS_E_INVALID_VIDEO_PEAKRATE_2    = &HC00D1BC2&

'//
'// MessageId: NS_E_INVALID_VIDEO_WIDTH
'//
'// MessageText:
'//
'// The video width setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_WIDTH         = &HC00D1BC3&

'//
'// MessageId: NS_E_INVALID_VIDEO_HEIGHT
'//
'// MessageText:
'//
'// The video height setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_HEIGHT        = &HC00D1BC4&

'//
'// MessageId: NS_E_INVALID_VIDEO_FPS
'//
'// MessageText:
'//
'// The video frame rate setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_FPS           = &HC00D1BC5&

'//
'// MessageId: NS_E_INVALID_VIDEO_KEYFRAME
'//
'// MessageText:
'//
'// The video key frame setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_KEYFRAME      = &HC00D1BC6&

'//
'// MessageId: NS_E_INVALID_VIDEO_IQUALITY
'//
'// MessageText:
'//
'// The video image quality setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_IQUALITY      = &HC00D1BC7&

'//
'// MessageId: NS_E_INVALID_VIDEO_CQUALITY
'//
'// MessageText:
'//
'// The video codec quality setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_CQUALITY      = &HC00D1BC8&

'//
'// MessageId: NS_E_INVALID_VIDEO_BUFFER
'//
'// MessageText:
'//
'// The video buffer setting is not valid.%0
'//
%NS_E_INVALID_VIDEO_BUFFER        = &HC00D1BC9&

'//
'// MessageId: NS_E_INVALID_VIDEO_BUFFERMAX
'//
'// MessageText:
'//
'// The setting for the maximum buffer size for video is not valid.%0
'//
%NS_E_INVALID_VIDEO_BUFFERMAX     = &HC00D1BCA&

'//
'// MessageId: NS_E_INVALID_VIDEO_BUFFERMAX_2
'//
'// MessageText:
'//
'// The value of the video maximum buffer size setting must be greater than the video buffer size setting.%0
'//
%NS_E_INVALID_VIDEO_BUFFERMAX_2   = &HC00D1BCB&

'//
'// MessageId: NS_E_INVALID_VIDEO_WIDTH_ALIGN
'//
'// MessageText:
'//
'// The alignment of the video width is not valid.%0
'//
%NS_E_INVALID_VIDEO_WIDTH_ALIGN   = &HC00D1BCC&

'//
'// MessageId: NS_E_INVALID_VIDEO_HEIGHT_ALIGN
'//
'// MessageText:
'//
'// The alignment of the video height is not valid.%0
'//
%NS_E_INVALID_VIDEO_HEIGHT_ALIGN  = &HC00D1BCD&

'//
'// MessageId: NS_E_MULTIPLE_SCRIPT_BITRATES
'//
'// MessageText:
'//
'// All bit rates must have the same script bit rate.%0
'//
%NS_E_MULTIPLE_SCRIPT_BITRATES    = &HC00D1BCE&

'//
'// MessageId: NS_E_INVALID_SCRIPT_BITRATE
'//
'// MessageText:
'//
'// The script bit rate specified is not valid.%0
'//
%NS_E_INVALID_SCRIPT_BITRATE      = &HC00D1BCF&

'//
'// MessageId: NS_E_MULTIPLE_FILE_BITRATES
'//
'// MessageText:
'//
'// All bit rates must have the same file transfer bit rate.%0
'//
%NS_E_MULTIPLE_FILE_BITRATES      = &HC00D1BD0&

'//
'// MessageId: NS_E_INVALID_FILE_BITRATE
'//
'// MessageText:
'//
'// The file transfer bit rate is not valid.%0
'//
%NS_E_INVALID_FILE_BITRATE        = &HC00D1BD1&

'//
'// MessageId: NS_E_SAME_AS_INPUT_COMBINATION
'//
'// MessageText:
'//
'// All audiences in a profile should either be same as input or have video width and height specified.%0
'//
%NS_E_SAME_AS_INPUT_COMBINATION   = &HC00D1BD2&

'//
'// MessageId: NS_E_SOURCE_CANNOT_LOOP
'//
'// MessageText:
'//
'// This source type does not support looping.%0
'//
%NS_E_SOURCE_CANNOT_LOOP          = &HC00D1BD3&

'//
'// MessageId: NS_E_INVALID_FOLDDOWN_COEFFICIENTS
'//
'// MessageText:
'//
'// The fold-down value needs to be between -144 and 0.%0
'//
%NS_E_INVALID_FOLDDOWN_COEFFICIENTS = &HC00D1BD4&

'//
'// MessageId: NS_E_DRMPROFILE_NOTFOUND
'//
'// MessageText:
'//
'// The specified DRM profile does not exist in the system.%0
'//
%NS_E_DRMPROFILE_NOTFOUND         = &HC00D1BD5&

'//
'// MessageId: NS_E_INVALID_TIMECODE
'//
'// MessageText:
'//
'// The specified time code is not valid.%0
'//
%NS_E_INVALID_TIMECODE            = &HC00D1BD6&

'//
'// MessageId: NS_E_NO_AUDIO_TIMECOMPRESSION
'//
'// MessageText:
'//
'// It is not possible to apply time compression to a video-only session.%0
'//
%NS_E_NO_AUDIO_TIMECOMPRESSION    = &HC00D1BD7&

'//
'// MessageId: NS_E_NO_TWOPASS_TIMECOMPRESSION
'//
'// MessageText:
'//
'// It is not possible to apply time compression to a session that is using two-pass encoding.%0
'//
%NS_E_NO_TWOPASS_TIMECOMPRESSION  = &HC00D1BD8&

'//
'// MessageId: NS_E_TIMECODE_REQUIRES_VIDEOSTREAM
'//
'// MessageText:
'//
'// It is not possible to generate a time code for an audio-only session.%0
'//
%NS_E_TIMECODE_REQUIRES_VIDEOSTREAM = &HC00D1BD9&

'//
'// MessageId: NS_E_NO_MBR_WITH_TIMECODE
'//
'// MessageText:
'//
'// It is not possible to generate a time code when you are encoding content at multiple bit rates.%0
'//
%NS_E_NO_MBR_WITH_TIMECODE        = &HC00D1BDA&

'//
'// MessageId: NS_E_INVALID_INTERLACEMODE
'//
'// MessageText:
'//
'// The video codec selected does not support maintaining interlacing in video.%0
'//
%NS_E_INVALID_INTERLACEMODE       = &HC00D1BDB&

'//
'// MessageId: NS_E_INVALID_INTERLACE_COMPAT
'//
'// MessageText:
'//
'// Maintaining interlacing in video is not compatible with Windows Media Player 7.1.%0
'//
%NS_E_INVALID_INTERLACE_COMPAT    = &HC00D1BDC&

'//
'// MessageId: NS_E_INVALID_NONSQUAREPIXEL_COMPAT
'//
'// MessageText:
'//
'// Allowing nonsquare pixel output is not compatible with Windows Media Player 7.1.%0
'//
%NS_E_INVALID_NONSQUAREPIXEL_COMPAT = &HC00D1BDD&

'//
'// MessageId: NS_E_INVALID_SOURCE_WITH_DEVICE_CONTROL
'//
'// MessageText:
'//
'// Only capture devices can be used with device control.%0
'//
%NS_E_INVALID_SOURCE_WITH_DEVICE_CONTROL = &HC00D1BDE&

'//
'// MessageId: NS_E_CANNOT_GENERATE_BROADCAST_INFO_FOR_QUALITYVBR
'//
'// MessageText:
'//
'// It is not possible to generate the stream format file if you are using quality-based VBR encoding for the audio or video stream. Instead use the Windows Media file generated after encoding to create the announcement file.%0
'//
%NS_E_CANNOT_GENERATE_BROADCAST_INFO_FOR_QUALITYVBR = &HC00D1BDF&

'//
'// MessageId: NS_E_EXCEED_MAX_DRM_PROFILE_LIMIT
'//
'// MessageText:
'//
'// It is not possible to create a DRM profile because the maximum number of profiles has been reached. You must delete some DRM profiles before creating new ones.%0
'//
%NS_E_EXCEED_MAX_DRM_PROFILE_LIMIT = &HC00D1BE0&

'//
'// MessageId: NS_E_DEVICECONTROL_UNSTABLE
'//
'// MessageText:
'//
'// The device is in an unstable state. Check that the device is functioning properly and a tape is in place.
'//
%NS_E_DEVICECONTROL_UNSTABLE      = &HC00D1BE1&

'//
'// MessageId: NS_E_INVALID_PIXEL_ASPECT_RATIO
'//
'// MessageText:
'//
'// The pixel aspect ratio value must be between 1 and 255.
'//
%NS_E_INVALID_PIXEL_ASPECT_RATIO  = &HC00D1BE2&

'//
'// MessageId: NS_E_AUDIENCE__LANGUAGE_CONTENTTYPE_MISMATCH
'//
'// MessageText:
'//
'// All streams with different languages in the same audience must have same properties.%0
'//
%NS_E_AUDIENCE__LANGUAGE_CONTENTTYPE_MISMATCH = &HC00D1BE3&

'//
'// MessageId: NS_E_INVALID_PROFILE_CONTENTTYPE
'//
'// MessageText:
'//
'// The profile must contain at least one audio or video stream.%0
'//
%NS_E_INVALID_PROFILE_CONTENTTYPE = &HC00D1BE4&

'//
'// MessageId: NS_E_TRANSFORM_PLUGIN_NOT_FOUND
'//
'// MessageText:
'//
'// The transform plug-in could not be found.%0
'//
%NS_E_TRANSFORM_PLUGIN_NOT_FOUND  = &HC00D1BE5&

'//
'// MessageId: NS_E_TRANSFORM_PLUGIN_INVALID
'//
'// MessageText:
'//
'// The transform plug-in is not valid. It may be damaged or you may not have the required permissions to access the plug-in.%0
'//
%NS_E_TRANSFORM_PLUGIN_INVALID    = &HC00D1BE6&

'//
'// MessageId: NS_E_EDL_REQUIRED_FOR_DEVICE_MULTIPASS
'//
'// MessageText:
'//
'// To use two-pass encoding, you must enable device control and setup an edit decision list (ED& that has at least one entry.%0
'//
%NS_E_EDL_REQUIRED_FOR_DEVICE_MULTIPASS = &HC00D1BE7&

'//
'// MessageId: NS_E_INVALID_VIDEO_WIDTH_FOR_INTERLACED_ENCODING
'//
'// MessageText:
'//
'// When you choose to maintain the interlacing in your video, the output video size must be a multiple of 4.%0
'//
%NS_E_INVALID_VIDEO_WIDTH_FOR_INTERLACED_ENCODING = &HC00D1BE8&

'//
'// MessageId: NS_E_MARKIN_UNSUPPORTED
'//
'// MessageText:
'//
'// Markin/Markout is unsupported with this source type.%0
'//
%NS_E_MARKIN_UNSUPPORTED          = &HC00D1BE9&


'/////////////////////////////////////////////////////////////////////////
'//
'// DRM Specific Errors
'//
'// IdRange = 10000..10999
'/////////////////////////////////////////////////////////////////////////
'//
'// MessageId: NS_E_DRM_INVALID_APPLICATION
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0
'//
%NS_E_DRM_INVALID_APPLICATION     = &HC00D2711&

'//
'// MessageId: NS_E_DRM_LICENSE_STORE_ERROR
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_LICENSE_STORE_ERROR     = &HC00D2712&

'//
'// MessageId: NS_E_DRM_SECURE_STORE_ERROR
'//
'// MessageText:
'//
'// Secure storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_SECURE_STORE_ERROR      = &HC00D2713&

'//
'// MessageId: NS_E_DRM_LICENSE_STORE_SAVE_ERROR
'//
'// MessageText:
'//
'// License acquisition did not work. Acquire a new license or contact the content provider for further assistance.%0
'//
%NS_E_DRM_LICENSE_STORE_SAVE_ERROR = &HC00D2714&

'//
'// MessageId: NS_E_DRM_SECURE_STORE_UNLOCK_ERROR
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
'//
%NS_E_DRM_SECURE_STORE_UNLOCK_ERROR = &HC00D2715&

'//
'// MessageId: NS_E_DRM_INVALID_CONTENT
'//
'// MessageText:
'//
'// The media file is corrupted. Contact the content provider to get a new file.%0
'//
%NS_E_DRM_INVALID_CONTENT         = &HC00D2716&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_OPEN_LICENSE
'//
'// MessageText:
'//
'// The license is corrupted. Acquire a new license.%0
'//
%NS_E_DRM_UNABLE_TO_OPEN_LICENSE  = &HC00D2717&

'//
'// MessageId: NS_E_DRM_INVALID_LICENSE
'//
'// MessageText:
'//
'// The license is corrupted or invalid. Acquire a new license%0
'//
%NS_E_DRM_INVALID_LICENSE         = &HC00D2718&

'//
'// MessageId: NS_E_DRM_INVALID_MACHINE
'//
'// MessageText:
'//
'// Licenses cannot be copied from one computer to another. Use License Management to transfer licenses, or get a new license for the media file.%0
'//
%NS_E_DRM_INVALID_MACHINE         = &HC00D2719&

'//
'// MessageId: NS_E_DRM_ENUM_LICENSE_FAILED
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_ENUM_LICENSE_FAILED     = &HC00D271B&

'//
'// MessageId: NS_E_DRM_INVALID_LICENSE_REQUEST
'//
'// MessageText:
'//
'// The media file is corrupted. Contact the content provider to get a new file.%0
'//
%NS_E_DRM_INVALID_LICENSE_REQUEST = &HC00D271C&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_INITIALIZE
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
'//
%NS_E_DRM_UNABLE_TO_INITIALIZE    = &HC00D271D&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_ACQUIRE_LICENSE
'//
'// MessageText:
'//
'// The license could not be acquired. Try again later.%0
'//
%NS_E_DRM_UNABLE_TO_ACQUIRE_LICENSE = &HC00D271E&

'//
'// MessageId: NS_E_DRM_INVALID_LICENSE_ACQUIRED
'//
'// MessageText:
'//
'// License acquisition did not work. Acquire a new license or contact the content provider for further assistance.%0
'//
%NS_E_DRM_INVALID_LICENSE_ACQUIRED = &HC00D271F&

'//
'// MessageId: NS_E_DRM_NO_RIGHTS
'//
'// MessageText:
'//
'// The requested operation cannot be performed on this file.%0
'//
%NS_E_DRM_NO_RIGHTS               = &HC00D2720&

'//
'// MessageId: NS_E_DRM_KEY_ERROR
'//
'// MessageText:
'//
'// The requested action cannot be performed because a problem occurred with the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_DRM_KEY_ERROR               = &HC00D2721&

'//
'// MessageId: NS_E_DRM_ENCRYPT_ERROR
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0
'//
%NS_E_DRM_ENCRYPT_ERROR           = &HC00D2722&

'//
'// MessageId: NS_E_DRM_DECRYPT_ERROR
'//
'// MessageText:
'//
'// The media file is corrupted. Contact the content provider to get a new file.%0
'//
%NS_E_DRM_DECRYPT_ERROR           = &HC00D2723&

'//
'// MessageId: NS_E_DRM_LICENSE_INVALID_XML
'//
'// MessageText:
'//
'// The license is corrupted. Acquire a new license.%0
'//
%NS_E_DRM_LICENSE_INVALID_XML     = &HC00D2725&

'//
'// MessageId: NS_S_DRM_LICENSE_ACQUIRED
'//
'// MessageText:
'//
'// Status message: The license was acquired.%0
'//
%NS_S_DRM_LICENSE_ACQUIRED        = &H000D2726&

'//
'// MessageId: NS_S_DRM_INDIVIDUALIZED
'//
'// MessageText:
'//
'// Status message: The security upgrade has been completed.%0
'//
%NS_S_DRM_INDIVIDUALIZED          = &H000D2727&

'//
'// MessageId: NS_E_DRM_NEEDS_INDIVIDUALIZATION
'//
'// MessageText:
'//
'// A security upgrade is required to perform the operation on this media file.%0
'//
%NS_E_DRM_NEEDS_INDIVIDUALIZATION = &HC00D2728&

'//
'// MessageId: NS_E_DRM_ALREADY_INDIVIDUALIZED
'//
'// MessageText:
'//
'// You already have the latest security components. No upgrade is necessary at this time.%0
'//
%NS_E_DRM_ALREADY_INDIVIDUALIZED  = &HC00D2729&

'//
'// MessageId: NS_E_DRM_ACTION_NOT_QUERIED
'//
'// MessageText:
'//
'// The application cannot perform this action. Contact product support for this application.%0
'//
%NS_E_DRM_ACTION_NOT_QUERIED      = &HC00D272A&

'//
'// MessageId: NS_E_DRM_ACQUIRING_LICENSE
'//
'// MessageText:
'//
'// You cannot begin a new license acquisition process until the current one has been completed.%0
'//
%NS_E_DRM_ACQUIRING_LICENSE       = &HC00D272B&

'//
'// MessageId: NS_E_DRM_INDIVIDUALIZING
'//
'// MessageText:
'//
'// You cannot begin a new security upgrade until the current one has been completed.%0
'//
%NS_E_DRM_INDIVIDUALIZING         = &HC00D272C&

'//
'// MessageId: NS_E_BACKUP_RESTORE_FAILURE
'//
'// MessageText:
'//
'// Failure in Backup-Restore.%0
'//
%NS_E_BACKUP_RESTORE_FAILURE      = &HC00D272D&

'//
'// MessageId: NS_E_BACKUP_RESTORE_BAD_REQUEST_ID
'//
'// MessageText:
'//
'// Bad Request ID in Backup-Restore.%0
'//
%NS_E_BACKUP_RESTORE_BAD_REQUEST_ID = &HC00D272E&

'//
'// MessageId: NS_E_DRM_PARAMETERS_MISMATCHED
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_PARAMETERS_MISMATCHED   = &HC00D272F&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_LICENSE_OBJECT
'//
'// MessageText:
'//
'// A license cannot be created for this media file. Reinstall the application.%0
'//
%NS_E_DRM_UNABLE_TO_CREATE_LICENSE_OBJECT = &HC00D2730&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_INDI_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_INDI_OBJECT = &HC00D2731&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_ENCRYPT_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_ENCRYPT_OBJECT = &HC00D2732&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_DECRYPT_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_DECRYPT_OBJECT = &HC00D2733&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_PROPERTIES_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_PROPERTIES_OBJECT = &HC00D2734&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_BACKUP_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_BACKUP_OBJECT = &HC00D2735&

'//
'// MessageId: NS_E_DRM_INDIVIDUALIZE_ERROR
'//
'// MessageText:
'//
'// The security upgrade failed. Try again later.%0
'//
%NS_E_DRM_INDIVIDUALIZE_ERROR     = &HC00D2736&

'//
'// MessageId: NS_E_DRM_LICENSE_OPEN_ERROR
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_LICENSE_OPEN_ERROR      = &HC00D2737&

'//
'// MessageId: NS_E_DRM_LICENSE_CLOSE_ERROR
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_LICENSE_CLOSE_ERROR     = &HC00D2738&

'//
'// MessageId: NS_E_DRM_GET_LICENSE_ERROR
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_GET_LICENSE_ERROR       = &HC00D2739&

'//
'// MessageId: NS_E_DRM_QUERY_ERROR
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_QUERY_ERROR             = &HC00D273A&

'//
'// MessageId: NS_E_DRM_REPORT_ERROR
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0
'//
%NS_E_DRM_REPORT_ERROR            = &HC00D273B&

'//
'// MessageId: NS_E_DRM_GET_LICENSESTRING_ERROR
'//
'// MessageText:
'//
'// License storage is not working. Contact Microsoft product support.%0
'//
%NS_E_DRM_GET_LICENSESTRING_ERROR = &HC00D273C&

'//
'// MessageId: NS_E_DRM_GET_CONTENTSTRING_ERROR
'//
'// MessageText:
'//
'// The media file is corrupted. Contact the content provider to get a new file.%0
'//
%NS_E_DRM_GET_CONTENTSTRING_ERROR = &HC00D273D&

'//
'// MessageId: NS_E_DRM_MONITOR_ERROR
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Try again later.%0
'//
%NS_E_DRM_MONITOR_ERROR           = &HC00D273E&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_SET_PARAMETER
'//
'// MessageText:
'//
'// The application has made an invalid call to the Digital Rights Management component. Contact product support for this application.%0
'//
%NS_E_DRM_UNABLE_TO_SET_PARAMETER = &HC00D273F&

'//
'// MessageId: NS_E_DRM_INVALID_APPDATA
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_INVALID_APPDATA         = &HC00D2740&

'//
'// MessageId: NS_E_DRM_INVALID_APPDATA_VERSION
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact product support for this application.%0.
'//
%NS_E_DRM_INVALID_APPDATA_VERSION = &HC00D2741&

'//
'// MessageId: NS_E_DRM_BACKUP_EXISTS
'//
'// MessageText:
'//
'// Licenses are already backed up in this location.%0
'//
%NS_E_DRM_BACKUP_EXISTS           = &HC00D2742&

'//
'// MessageId: NS_E_DRM_BACKUP_CORRUPT
'//
'// MessageText:
'//
'// One or more backed-up licenses are missing or corrupt.%0
'//
%NS_E_DRM_BACKUP_CORRUPT          = &HC00D2743&

'//
'// MessageId: NS_E_DRM_BACKUPRESTORE_BUSY
'//
'// MessageText:
'//
'// You cannot begin a new backup process until the current process has been completed.%0
'//
%NS_E_DRM_BACKUPRESTORE_BUSY      = &HC00D2744&

'//
'// MessageId: NS_E_BACKUP_RESTORE_BAD_DATA
'//
'// MessageText:
'//
'// Bad Data sent to Backup-Restore.%0
'//
%NS_E_BACKUP_RESTORE_BAD_DATA     = &HC00D2745&

'//
'// MessageId: NS_S_DRM_MONITOR_CANCELLED
'//
'// MessageText:
'//
'// Status message: License monitoring has been cancelled.%0
'//
%NS_S_DRM_MONITOR_CANCELLED       = &H000D2746&

'//
'// MessageId: NS_S_DRM_ACQUIRE_CANCELLED
'//
'// MessageText:
'//
'// Status message: License acquisition has been cancelled.%0
'//
%NS_S_DRM_ACQUIRE_CANCELLED       = &H000D2747&

'//
'// MessageId: NS_E_DRM_LICENSE_UNUSABLE
'//
'// MessageText:
'//
'// The license is invalid. Contact the content provider for further assistance.%0
'//
%NS_E_DRM_LICENSE_UNUSABLE        = &HC00D2748&

'//
'// MessageId: NS_E_DRM_INVALID_PROPERTY
'//
'// MessageText:
'//
'// A required property was not set by the application. Contact product support for this application.%0.
'//
%NS_E_DRM_INVALID_PROPERTY        = &HC00D2749&

'//
'// MessageId: NS_E_DRM_SECURE_STORE_NOT_FOUND
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component of this application. Try to acquire a license again.%0
'//
%NS_E_DRM_SECURE_STORE_NOT_FOUND  = &HC00D274A&

'//
'// MessageId: NS_E_DRM_CACHED_CONTENT_ERROR
'//
'// MessageText:
'//
'// Windows Media Digital Rights Management (DRM) cannot play the protected file because you do not have the appropriate rights.%0
'//
%NS_E_DRM_CACHED_CONTENT_ERROR    = &HC00D274B&

'//
'// MessageId: NS_E_DRM_INDIVIDUALIZATION_INCOMPLETE
'//
'// MessageText:
'//
'// A problem occurred during the security upgrade. Try again later.%0
'//
%NS_E_DRM_INDIVIDUALIZATION_INCOMPLETE = &HC00D274C&

'//
'// MessageId: NS_E_DRM_DRIVER_AUTH_FAILURE
'//
'// MessageText:
'//
'// Certified driver components are required to play this media file. Contact Windows Update to see whether updated drivers are available for your hardware.%0
'//
%NS_E_DRM_DRIVER_AUTH_FAILURE     = &HC00D274D&

'//
'// MessageId: NS_E_DRM_NEED_UPGRADE_MSSAP
'//
'// MessageText:
'//
'// One or more of the Secure Audio Path components were not found or an entry point in those components was not found.%0
'//
%NS_E_DRM_NEED_UPGRADE_MSSAP      = &HC00D274E&

'//
'// MessageId: NS_E_DRM_REOPEN_CONTENT
'//
'// MessageText:
'//
'// Status message: Reopen the file.%0
'//
%NS_E_DRM_REOPEN_CONTENT          = &HC00D274F&

'//
'// MessageId: NS_E_DRM_DRIVER_DIGIOUT_FAILURE
'//
'// MessageText:
'//
'// Certain driver functionality is required to play this media file. Contact Windows Update to see whether updated drivers are available for your hardware.%0
'//
%NS_E_DRM_DRIVER_DIGIOUT_FAILURE  = &HC00D2750&

'//
'// MessageId: NS_E_DRM_INVALID_SECURESTORE_PASSWORD
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_INVALID_SECURESTORE_PASSWORD = &HC00D2751&

'//
'// MessageId: NS_E_DRM_APPCERT_REVOKED
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_APPCERT_REVOKED         = &HC00D2752&

'//
'// MessageId: NS_E_DRM_RESTORE_FRAUD
'//
'// MessageText:
'//
'// You cannot restore your license(s).%0
'//
%NS_E_DRM_RESTORE_FRAUD           = &HC00D2753&

'//
'// MessageId: NS_E_DRM_HARDWARE_INCONSISTENT
'//
'// MessageText:
'//
'// The licenses for your media files are corrupted. Contact Microsoft product support.%0
'//
%NS_E_DRM_HARDWARE_INCONSISTENT   = &HC00D2754&

'//
'// MessageId: NS_E_DRM_SDMI_TRIGGER
'//
'// MessageText:
'//
'// To transfer this media file, you must upgrade the application.%0
'//
%NS_E_DRM_SDMI_TRIGGER            = &HC00D2755&

'//
'// MessageId: NS_E_DRM_SDMI_NOMORECOPIES
'//
'// MessageText:
'//
'// You cannot make any more copies of this media file.%0
'//
%NS_E_DRM_SDMI_NOMORECOPIES       = &HC00D2756&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_HEADER_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_HEADER_OBJECT = &HC00D2757&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_KEYS_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_KEYS_OBJECT = &HC00D2758&

'// This error is never shown to user but needed for program logic.
'//
'// MessageId: NS_E_DRM_LICENSE_NOTACQUIRED
'//
'// MessageText:
'//
'// Unable to obtain license.%0
'//
%NS_E_DRM_LICENSE_NOTACQUIRED     = &HC00D2759&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_CODING_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_CODING_OBJECT = &HC00D275A&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_STATE_DATA_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_STATE_DATA_OBJECT = &HC00D275B&

'//
'// MessageId: NS_E_DRM_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'// The buffer supplied is not sufficient.%0.
'//
%NS_E_DRM_BUFFER_TOO_SMALL        = &HC00D275C&

'//
'// MessageId: NS_E_DRM_UNSUPPORTED_PROPERTY
'//
'// MessageText:
'//
'// The property requested is not supported.%0.
'//
%NS_E_DRM_UNSUPPORTED_PROPERTY    = &HC00D275D&

'//
'// MessageId: NS_E_DRM_ERROR_BAD_NET_RESP
'//
'// MessageText:
'//
'// The specified server cannot perform the requested operation.%0.
'//
%NS_E_DRM_ERROR_BAD_NET_RESP      = &HC00D275E&

'//
'// MessageId: NS_E_DRM_STORE_NOTALLSTORED
'//
'// MessageText:
'//
'// Some of the licenses could not be stored.%0.
'//
%NS_E_DRM_STORE_NOTALLSTORED      = &HC00D275F&

'//
'// MessageId: NS_E_DRM_SECURITY_COMPONENT_SIGNATURE_INVALID
'//
'// MessageText:
'//
'// The Digital Rights Management security upgrade component could not be validated. Contact Microsoft product support.%0
'//
%NS_E_DRM_SECURITY_COMPONENT_SIGNATURE_INVALID = &HC00D2760&

'//
'// MessageId: NS_E_DRM_INVALID_DATA
'//
'// MessageText:
'//
'// Invalid or corrupt data was encountered.%0
'//
%NS_E_DRM_INVALID_DATA            = &HC00D2761&

'//
'// MessageId: NS_E_DRM_POLICY_DISABLE_ONLINE
'//
'// MessageText:
'//
'// The Windows Media Digital Rights Management system cannot perform the requested action because your computer or network administrator has enabled the group policy Prevent Windows Media DRM Internet Access. For assistance, contact your administrator.%0
'//
%NS_E_DRM_POLICY_DISABLE_ONLINE   = &HC00D2762&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_AUTHENTICATION_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_AUTHENTICATION_OBJECT = &HC00D2763&

'//
'// MessageId: NS_E_DRM_NOT_CONFIGURED
'//
'// MessageText:
'//
'// Not all of the necessary properties for DRM have been set.%0
'//
%NS_E_DRM_NOT_CONFIGURED          = &HC00D2764&

'//
'// MessageId: NS_E_DRM_DEVICE_ACTIVATION_CANCELED
'//
'// MessageText:
'//
'// The portable device does not have the security required to copy protected files to it. To obtain the additional security, try to copy the file to your portable device again. When a message appears, click OK.%0
'//
%NS_E_DRM_DEVICE_ACTIVATION_CANCELED = &HC00D2765&

'//
'// MessageId: NS_E_BACKUP_RESTORE_TOO_MANY_RESETS
'//
'// MessageText:
'//
'// Too many resets in Backup-Restore.%0
'//
%NS_E_BACKUP_RESTORE_TOO_MANY_RESETS = &HC00D2766&

'//
'// MessageId: NS_E_DRM_DEBUGGING_NOT_ALLOWED
'//
'// MessageText:
'//
'// Running this process under a debugger while using DRM content is not allowed.%0
'//
%NS_E_DRM_DEBUGGING_NOT_ALLOWED   = &HC00D2767&

'//
'// MessageId: NS_E_DRM_OPERATION_CANCELED
'//
'// MessageText:
'//
'// The user canceled the DRM operation.%0
'//
%NS_E_DRM_OPERATION_CANCELED      = &HC00D2768&

'//
'// MessageId: NS_E_DRM_RESTRICTIONS_NOT_RETRIEVED
'//
'// MessageText:
'//
'// The license you are using has associated output restrictions. This license is unusable until these restrictions are queried.%0
'//
%NS_E_DRM_RESTRICTIONS_NOT_RETRIEVED = &HC00D2769&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_PLAYLIST_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_PLAYLIST_OBJECT = &HC00D276A&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_PLAYLIST_BURN_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_PLAYLIST_BURN_OBJECT = &HC00D276B&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_DEVICE_REGISTRATION_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_DEVICE_REGISTRATION_OBJECT = &HC00D276C&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_METERING_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_METERING_OBJECT = &HC00D276D&

'//
'// MessageId: NS_S_DRM_BURNABLE_TRACK
'//
'// MessageText:
'//
'// The track is burnable and had no playlist burn limit.%0.
'//
%NS_S_DRM_BURNABLE_TRACK          = &H000D276E&

'//
'// MessageId: NS_S_DRM_BURNABLE_TRACK_WITH_PLAYLIST_RESTRICTION
'//
'// MessageText:
'//
'// The track is burnable but has a playlist burn limit.%0.
'//
%NS_S_DRM_BURNABLE_TRACK_WITH_PLAYLIST_RESTRICTION = &H000D276F&

'//
'// MessageId: NS_E_DRM_TRACK_EXCEEDED_PLAYLIST_RESTICTION
'//
'// MessageText:
'//
'// The specified track has exceeded it's specified playlist burn limit in this playlist.%0.
'//
%NS_E_DRM_TRACK_EXCEEDED_PLAYLIST_RESTICTION = &HC00D2770&

'//
'// MessageId: NS_E_DRM_TRACK_EXCEEDED_TRACKBURN_RESTRICTION
'//
'// MessageText:
'//
'// The specified track has exceeded it's track burn limit.%0.
'//
%NS_E_DRM_TRACK_EXCEEDED_TRACKBURN_RESTRICTION = &HC00D2771&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_GET_DEVICE_CERT
'//
'// MessageText:
'//
'// A problem has occurred in obtaining the device's certificate.%0.
'//
%NS_E_DRM_UNABLE_TO_GET_DEVICE_CERT = &HC00D2772&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_GET_SECURE_CLOCK
'//
'// MessageText:
'//
'// A problem has occurred in obtaining the device's secure clock. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_GET_SECURE_CLOCK = &HC00D2773&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_SET_SECURE_CLOCK
'//
'// MessageText:
'//
'// A problem has occurred in setting the device's secure clock. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_SET_SECURE_CLOCK = &HC00D2774&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_GET_SECURE_CLOCK_FROM_SERVER
'//
'// MessageText:
'//
'// A problem has occurred in obtaining the secure clock from server. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_GET_SECURE_CLOCK_FROM_SERVER = &HC00D2775&

'//
'// MessageId: NS_E_DRM_POLICY_METERING_DISABLED
'//
'// MessageText:
'//
'// This content requires the metering policy to be enabled.%0.
'//
%NS_E_DRM_POLICY_METERING_DISABLED = &HC00D2776&

'//
'// MessageId: NS_E_DRM_TRANSFER_CHAINED_LICENSES_UNSUPPORTED
'//
'// MessageText:
'//
'// Transfer of chained licenses unsupported.%0.
'//
%NS_E_DRM_TRANSFER_CHAINED_LICENSES_UNSUPPORTED = &HC00D2777&

'//
'// MessageId: NS_E_DRM_SDK_VERSIONMISMATCH
'//
'// MessageText:
'//
'// The Digital Rights Management component is not installed properly.  Reinstall the Player.%0.
'//
%NS_E_DRM_SDK_VERSIONMISMATCH     = &HC00D2778&

'//
'// MessageId: NS_E_DRM_LIC_NEEDS_DEVICE_CLOCK_SET
'//
'// MessageText:
'//
'// The file could not be transferred because the device clock is not set. %0.
'//
%NS_E_DRM_LIC_NEEDS_DEVICE_CLOCK_SET = &HC00D2779&

'//
'// MessageId: NS_E_LICENSE_HEADER_MISSING_URL
'//
'// MessageText:
'//
'// The content header is missing an acquisition URL.%0
'//
%NS_E_LICENSE_HEADER_MISSING_URL  = &HC00D277A&

'//
'// MessageId: NS_E_DEVICE_NOT_WMDRM_DEVICE
'//
'// MessageText:
'//
'// The current attached device does not support WMDRM.%0
'//
%NS_E_DEVICE_NOT_WMDRM_DEVICE     = &HC00D277B&

'//
'// MessageId: NS_E_DRM_INVALID_APPCERT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_INVALID_APPCERT         = &HC00D277C&

'//
'// MessageId: NS_E_DRM_PROTOCOL_FORCEFUL_TERMINATION_ON_PETITION
'//
'// MessageText:
'//
'// The client application has been forcefully terminated during a DRM petition.%0.
'//
%NS_E_DRM_PROTOCOL_FORCEFUL_TERMINATION_ON_PETITION = &HC00D277D&

'//
'// MessageId: NS_E_DRM_PROTOCOL_FORCEFUL_TERMINATION_ON_CHALLENGE
'//
'// MessageText:
'//
'// The client application has been forcefully terminated during a DRM challenge.%0.
'//
%NS_E_DRM_PROTOCOL_FORCEFUL_TERMINATION_ON_CHALLENGE = &HC00D277E&

'//
'// MessageId: NS_E_DRM_CHECKPOINT_FAILED
'//
'// MessageText:
'//
'// Secure storage protection error.  Restore your licenses from a previous backup and try again.%0
'//
%NS_E_DRM_CHECKPOINT_FAILED       = &HC00D277F&

'//
'// MessageId: NS_E_DRM_BB_UNABLE_TO_INITIALIZE
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management root of trust. Contact Microsoft product support.%0
'//
%NS_E_DRM_BB_UNABLE_TO_INITIALIZE = &HC00D2780&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_LOAD_HARDWARE_ID
'//
'// MessageText:
'//
'// A problem has occurred in retrieving the Digital Rights Management machine identification. Contact Microsoft product support.%0
'//
%NS_E_DRM_UNABLE_TO_LOAD_HARDWARE_ID = &HC00D2781&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_OPEN_DATA_STORE
'//
'// MessageText:
'//
'// A problem has occurred in opening the Digital Rights Management data storage file. Contact Microsoft product support.%0
'//
%NS_E_DRM_UNABLE_TO_OPEN_DATA_STORE = &HC00D2782&

'//
'// MessageId: NS_E_DRM_DATASTORE_CORRUPT
'//
'// MessageText:
'//
'// The Digital Rights Management data storage is not functioning properly.  Contact Microsoft product support.%0.
'//
%NS_E_DRM_DATASTORE_CORRUPT       = &HC00D2783&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_INMEMORYSTORE_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_INMEMORYSTORE_OBJECT = &HC00D2784&

'//
'// MessageId: NS_E_DRM_STUBLIB_REQUIRED
'//
'// MessageText:
'//
'// A secured library is required to access the requested functionality.%0.
'//
%NS_E_DRM_STUBLIB_REQUIRED        = &HC00D2785&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_CERTIFICATE_OBJECT
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_UNABLE_TO_CREATE_CERTIFICATE_OBJECT = &HC00D2786&

'//
'// MessageId: NS_E_DRM_MIGRATION_TARGET_NOT_ONLINE
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component during license migration. Contact Microsoft product support.%0.
'//
%NS_E_DRM_MIGRATION_TARGET_NOT_ONLINE = &HC00D2787&

'//
'// MessageId: NS_E_DRM_INVALID_MIGRATION_IMAGE
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component during license migration. Contact Microsoft product support.%0.
'//
%NS_E_DRM_INVALID_MIGRATION_IMAGE = &HC00D2788&

'//
'// MessageId: NS_E_DRM_MIGRATION_TARGET_STATES_CORRUPTED
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component during license migration. Contact Microsoft product support.%0.
'//
%NS_E_DRM_MIGRATION_TARGET_STATES_CORRUPTED = &HC00D2789&

'//
'// MessageId: NS_E_DRM_MIGRATION_IMPORTER_NOT_AVAILABLE
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component during license migration. Contact Microsoft product support.%0.
'//
%NS_E_DRM_MIGRATION_IMPORTER_NOT_AVAILABLE = &HC00D278A&

'//
'// MessageId: NS_DRM_E_MIGRATION_UPGRADE_WITH_DIFF_SID
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component during license migration. Contact Microsoft product support.%0.
'//
%NS_DRM_E_MIGRATION_UPGRADE_WITH_DIFF_SID = &HC00D278B&

'//
'// MessageId: NS_DRM_E_MIGRATION_SOURCE_MACHINE_IN_USE
'//
'// MessageText:
'//
'// The Digital Rights Management component is in use during license migration. Contact Microsoft product support.%0.
'//
%NS_DRM_E_MIGRATION_SOURCE_MACHINE_IN_USE = &HC00D278C&

'//
'// MessageId: NS_DRM_E_MIGRATION_TARGET_MACHINE_LESS_THAN_LH
'//
'// MessageText:
'//
'// Licenses are being migrated to a machine running XP or downlevel OS. This operation can only be performed on Windows Vista or a later OS. Contact Microsoft product support.%0.
'//
%NS_DRM_E_MIGRATION_TARGET_MACHINE_LESS_THAN_LH = &HC00D278D&

'//
'// MessageId: NS_DRM_E_MIGRATION_IMAGE_ALREADY_EXISTS
'//
'// MessageText:
'//
'// Migration Image already exists. Contact Microsoft product support.%0.
'//
%NS_DRM_E_MIGRATION_IMAGE_ALREADY_EXISTS = &HC00D278E&

'//
'// MessageId: NS_E_DRM_HARDWAREID_MISMATCH
'//
'// MessageText:
'//
'// The requested action cannot be performed because a hardware configuration change has been detected by the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_DRM_HARDWAREID_MISMATCH     = &HC00D278F&

'//
'// MessageId: NS_E_INVALID_DRMV2CLT_STUBLIB
'//
'// MessageText:
'//
'// The wrong stublib has been linked to an application or DLL using drmv2clt.dll.%0
'//
%NS_E_INVALID_DRMV2CLT_STUBLIB    = &HC00D2790&

'//
'// MessageId: NS_E_DRM_MIGRATION_INVALID_LEGACYV2_DATA
'//
'// MessageText:
'//
'// The legacy V2 data being imported is invalid
'//
%NS_E_DRM_MIGRATION_INVALID_LEGACYV2_DATA = &HC00D2791&

'//
'// MessageId: NS_E_DRM_MIGRATION_LICENSE_ALREADY_EXISTS
'//
'// MessageText:
'//
'// The license being imported already exists
'//
%NS_E_DRM_MIGRATION_LICENSE_ALREADY_EXISTS = &HC00D2792&

'//
'// MessageId: NS_E_DRM_MIGRATION_INVALID_LEGACYV2_SST_PASSWORD
'//
'// MessageText:
'//
'// The password of the Legacy V2 SST entry being imported is incorrect
'//
%NS_E_DRM_MIGRATION_INVALID_LEGACYV2_SST_PASSWORD = &HC00D2793&

'//
'// MessageId: NS_E_DRM_MIGRATION_NOT_SUPPORTED
'//
'// MessageText:
'//
'// Migration is not supported by the plugin
'//
%NS_E_DRM_MIGRATION_NOT_SUPPORTED = &HC00D2794&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_CREATE_MIGRATION_IMPORTER_OBJECT
'//
'// MessageText:
'//
'// A migration importer cannot be created for this media file. Reinstall the application.%0
'//
%NS_E_DRM_UNABLE_TO_CREATE_MIGRATION_IMPORTER_OBJECT = &HC00D2795&

'//
'// MessageId: NS_E_DRM_CHECKPOINT_MISMATCH
'//
'// MessageText:
'//
'// The requested action cannot be performed because a problem occurred with the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_DRM_CHECKPOINT_MISMATCH     = &HC00D2796&

'//
'// MessageId: NS_E_DRM_CHECKPOINT_CORRUPT
'//
'// MessageText:
'//
'// The requested action cannot be performed because a problem occurred with the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_DRM_CHECKPOINT_CORRUPT      = &HC00D2797&

'//
'// MessageId: NS_E_REG_FLUSH_FAILURE
'//
'// MessageText:
'//
'// The requested action cannot be performed because a problem occurred with the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_REG_FLUSH_FAILURE           = &HC00D2798&

'//
'// MessageId: NS_E_HDS_KEY_MISMATCH
'//
'// MessageText:
'//
'// The requested action cannot be performed because a problem occurred with the Windows Media Digital Rights Management (DRM) components on your computer.%0.
'//
%NS_E_HDS_KEY_MISMATCH            = &HC00D2799&

'//
'// MessageId: NS_E_DRM_MIGRATION_OPERATION_CANCELLED
'//
'// MessageText:
'//
'// Migration was cancelled by the user.%0
'//
%NS_E_DRM_MIGRATION_OPERATION_CANCELLED = &HC00D279A&

'//
'// MessageId: NS_E_DRM_MIGRATION_OBJECT_IN_USE
'//
'// MessageText:
'//
'// Migration object is already in use and cannot be called until the current operation completes.%0
'//
%NS_E_DRM_MIGRATION_OBJECT_IN_USE = &HC00D279B&

'//
'// MessageId: NS_E_DRM_MALFORMED_CONTENT_HEADER
'//
'// MessageText:
'//
'// The content header does not comply with DRM requirements and cannot be used.%0
'//
%NS_E_DRM_MALFORMED_CONTENT_HEADER = &HC00D279C&


'//
'// License Reasons Section
'// Error Codes why a license is not usable. Reserve 10200..10300 for this purpose.
'// 10200..10249 is for license reported reasons. 10250..10300 is for client detected reasons.
'//

'//
'// MessageId: NS_E_DRM_LICENSE_EXPIRED
'//
'// MessageText:
'//
'// The license for this file has expired and is no longer valid. Contact your content provider for further assistance.%0
'//
%NS_E_DRM_LICENSE_EXPIRED         = &HC00D27D8&

'//
'// MessageId: NS_E_DRM_LICENSE_NOTENABLED
'//
'// MessageText:
'//
'// The license for this file is not valid yet, but will be at a future date.%0
'//
%NS_E_DRM_LICENSE_NOTENABLED      = &HC00D27D9&

'//
'// MessageId: NS_E_DRM_LICENSE_APPSECLOW
'//
'// MessageText:
'//
'// The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
'//
%NS_E_DRM_LICENSE_APPSECLOW       = &HC00D27DA&

'//
'// MessageId: NS_E_DRM_STORE_NEEDINDI
'//
'// MessageText:
'//
'// The license cannot be stored as it requires security upgrade of Digital Rights Management component.%0.
'//
%NS_E_DRM_STORE_NEEDINDI          = &HC00D27DB&

'//
'// MessageId: NS_E_DRM_STORE_NOTALLOWED
'//
'// MessageText:
'//
'// Your machine does not meet the requirements for storing the license.%0.
'//
%NS_E_DRM_STORE_NOTALLOWED        = &HC00D27DC&

'//
'// MessageId: NS_E_DRM_LICENSE_APP_NOTALLOWED
'//
'// MessageText:
'//
'// The license for this file requires an upgraded version of your player or a different player.%0.
'//
%NS_E_DRM_LICENSE_APP_NOTALLOWED  = &HC00D27DD&

'//
'// MessageId: NS_S_DRM_NEEDS_INDIVIDUALIZATION
'//
'// MessageText:
'//
'// A security upgrade is required to perform the operation on this media file.%0
'//
%NS_S_DRM_NEEDS_INDIVIDUALIZATION = &H000D27DE&

'//
'// MessageId: NS_E_DRM_LICENSE_CERT_EXPIRED
'//
'// MessageText:
'//
'// The license server's certificate expired. Make sure your system clock is set correctly. Contact your content provider for further assistance. %0.
'//
%NS_E_DRM_LICENSE_CERT_EXPIRED    = &HC00D27DF&

'//
'// MessageId: NS_E_DRM_LICENSE_SECLOW
'//
'// MessageText:
'//
'// The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
'//
%NS_E_DRM_LICENSE_SECLOW          = &HC00D27E0&

'//
'// MessageId: NS_E_DRM_LICENSE_CONTENT_REVOKED
'//
'// MessageText:
'//
'// The content owner for the license you just acquired is no longer supporting their content. Contact the content owner for a newer version of the content.%0
'//
%NS_E_DRM_LICENSE_CONTENT_REVOKED = &HC00D27E1&

'//
'// MessageId: NS_E_DRM_DEVICE_NOT_REGISTERED
'//
'// MessageText:
'//
'// The content owner for the license you just acquired requires your device to register to the current machine.%0
'//
%NS_E_DRM_DEVICE_NOT_REGISTERED   = &HC00D27E2&

'//
'// MessageId: NS_E_DRM_LICENSE_NOSAP
'//
'// MessageText:
'//
'// The license for this file requires a feature that is not supported in your current player or operating system. You can try with newer version of your current player or contact your content provider for further assistance.%0
'//
%NS_E_DRM_LICENSE_NOSAP           = &HC00D280A&

'//
'// MessageId: NS_E_DRM_LICENSE_NOSVP
'//
'// MessageText:
'//
'// The license for this file requires a feature that is not supported in your current player or operating system. You can try with newer version of your current player or contact your content provider for further assistance.%0
'//
%NS_E_DRM_LICENSE_NOSVP           = &HC00D280B&

'//
'// MessageId: NS_E_DRM_LICENSE_NOWDM
'//
'// MessageText:
'//
'// The license for this file requires Windows Driver Model (WDM) audio drivers. Contact your sound card manufacturer for further assistance.%0
'//
%NS_E_DRM_LICENSE_NOWDM           = &HC00D280C&

'//
'// MessageId: NS_E_DRM_LICENSE_NOTRUSTEDCODEC
'//
'// MessageText:
'//
'// The license for this file requires a higher level of security than the player you are currently using has. Try using a different player or download a newer version of your current player.%0
'//
%NS_E_DRM_LICENSE_NOTRUSTEDCODEC  = &HC00D280D&

'//
'// MessageId: NS_E_DRM_SOURCEID_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The license for this file is not supported by your current player. You can try with newer version of your current player or contact your content provider for further assistance.%0
'//
%NS_E_DRM_SOURCEID_NOT_SUPPORTED  = &HC00D280E&


'//
'// End of License Reasons Section
'//

'//
'// MessageId: NS_E_DRM_NEEDS_UPGRADE_TEMPFILE
'//
'// MessageText:
'//
'// An updated version of your media player is required to play the selected content.%0
'//
%NS_E_DRM_NEEDS_UPGRADE_TEMPFILE  = &HC00D283D&

'//
'// MessageId: NS_E_DRM_NEED_UPGRADE_PD
'//
'// MessageText:
'//
'// A new version of the Digital Rights Management component is required. Contact product support for this application to get the latest version.%0
'//
%NS_E_DRM_NEED_UPGRADE_PD         = &HC00D283E&

'//
'// MessageId: NS_E_DRM_SIGNATURE_FAILURE
'//
'// MessageText:
'//
'// Failed to either create or verify the content header.%0
'//
%NS_E_DRM_SIGNATURE_FAILURE       = &HC00D283F&

'//
'// MessageId: NS_E_DRM_LICENSE_SERVER_INFO_MISSING
'//
'// MessageText:
'//
'// Could not read the necessary information from the system registry.%0
'//
%NS_E_DRM_LICENSE_SERVER_INFO_MISSING = &HC00D2840&

'//
'// MessageId: NS_E_DRM_BUSY
'//
'// MessageText:
'//
'// The DRM subsystem is currently locked by another application or user.  Try again later.%0
'//
%NS_E_DRM_BUSY                    = &HC00D2841&

'//
'// MessageId: NS_E_DRM_PD_TOO_MANY_DEVICES
'//
'// MessageText:
'//
'// There are too many target devices registered on the portable media.%0
'//
%NS_E_DRM_PD_TOO_MANY_DEVICES     = &HC00D2842&

'//
'// MessageId: NS_E_DRM_INDIV_FRAUD
'//
'// MessageText:
'//
'// The security upgrade cannot be completed because the allowed number of daily upgrades has been exceeded. Try again tomorrow.%0
'//
%NS_E_DRM_INDIV_FRAUD             = &HC00D2843&

'//
'// MessageId: NS_E_DRM_INDIV_NO_CABS
'//
'// MessageText:
'//
'// The security upgrade cannot be completed because the server is unable to perform the operation. Try again later.%0
'//
%NS_E_DRM_INDIV_NO_CABS           = &HC00D2844&

'//
'// MessageId: NS_E_DRM_INDIV_SERVICE_UNAVAILABLE
'//
'// MessageText:
'//
'// The security upgrade cannot be performed because the server is not available. Try again later.%0
'//
%NS_E_DRM_INDIV_SERVICE_UNAVAILABLE = &HC00D2845&

'//
'// MessageId: NS_E_DRM_RESTORE_SERVICE_UNAVAILABLE
'//
'// MessageText:
'//
'// Windows Media Player cannot restore your licenses because the server is not available. Try again later.%0
'//
%NS_E_DRM_RESTORE_SERVICE_UNAVAILABLE = &HC00D2846&

'//
'// MessageId: NS_E_DRM_CLIENT_CODE_EXPIRED
'//
'// MessageText:
'//
'// Windows Media Player cannot play the protected file. Verify that your computer's date is set correctly. If it is correct, on the Help menu, click Check for Player Updates to install the latest version of the Player.%0
'//
%NS_E_DRM_CLIENT_CODE_EXPIRED     = &HC00D2847&

'//
'// MessageId: NS_E_DRM_NO_UPLINK_LICENSE
'//
'// MessageText:
'//
'// The chained license cannot be created because the referenced uplink license does not exist.
'//
%NS_E_DRM_NO_UPLINK_LICENSE       = &HC00D2848&

'//
'// MessageId: NS_E_DRM_INVALID_KID
'//
'// MessageText:
'//
'// The specified KID is invalid
'//
%NS_E_DRM_INVALID_KID             = &HC00D2849&

'//
'// MessageId: NS_E_DRM_LICENSE_INITIALIZATION_ERROR
'//
'// MessageText:
'//
'// License initialization did not work. Contact Microsoft product support.%0
'//
%NS_E_DRM_LICENSE_INITIALIZATION_ERROR = &HC00D284A&

'//
'// MessageId: NS_E_DRM_CHAIN_TOO_LONG
'//
'// MessageText:
'//
'// The uplink license of a chained license cannot itself be a chained license.
'//
%NS_E_DRM_CHAIN_TOO_LONG          = &HC00D284C&

'//
'// MessageId: NS_E_DRM_UNSUPPORTED_ALGORITHM
'//
'// MessageText:
'//
'// The specified encryption algorithm is unsupported.
'//
%NS_E_DRM_UNSUPPORTED_ALGORITHM   = &HC00D284D&

'//
'// MessageId: NS_E_DRM_LICENSE_DELETION_ERROR
'//
'// MessageText:
'//
'// License deletion did not work. Contact Microsoft product support.%0
'//
%NS_E_DRM_LICENSE_DELETION_ERROR  = &HC00D284E&


'//
'// WMDRMNET Reasons Section
'// Error Codes related to WMDRMNET (WMDRM-ND) or Device Registration.
'// Reserved 10400..10500 for this purpose.
'//

'//
'// MessageId: NS_E_DRM_INVALID_CERTIFICATE
'//
'// MessageText:
'//
'// The client's certificate is corrupted or the signature cannot be verified.%0
'//
%NS_E_DRM_INVALID_CERTIFICATE     = &HC00D28A0&

'//
'// MessageId: NS_E_DRM_CERTIFICATE_REVOKED
'//
'// MessageText:
'//
'// The client's certificate has been revoked.%0
'//
%NS_E_DRM_CERTIFICATE_REVOKED     = &HC00D28A1&

'//
'// MessageId: NS_E_DRM_LICENSE_UNAVAILABLE
'//
'// MessageText:
'//
'// There is no license available for the requested action.%0
'//
%NS_E_DRM_LICENSE_UNAVAILABLE     = &HC00D28A2&

'//
'// MessageId: NS_E_DRM_DEVICE_LIMIT_REACHED
'//
'// MessageText:
'//
'// The maximum number of devices in use has been reached. Unable to open additional devices.%0
'//
%NS_E_DRM_DEVICE_LIMIT_REACHED    = &HC00D28A3&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_VERIFY_PROXIMITY
'//
'// MessageText:
'//
'// The proximity detection procedure could not confirm that the receiver is near the transmitter in the network.%0
'//
%NS_E_DRM_UNABLE_TO_VERIFY_PROXIMITY = &HC00D28A4&

'//
'// MessageId: NS_E_DRM_MUST_REGISTER
'//
'// MessageText:
'//
'// The client must be registered before executing the intended operation.%0
'//
%NS_E_DRM_MUST_REGISTER           = &HC00D28A5&

'//
'// MessageId: NS_E_DRM_MUST_APPROVE
'//
'// MessageText:
'//
'// The client must be approved before executing the intended operation.%0
'//
%NS_E_DRM_MUST_APPROVE            = &HC00D28A6&

'//
'// MessageId: NS_E_DRM_MUST_REVALIDATE
'//
'// MessageText:
'//
'// The client must be revalidated before executing the intended operation.%0
'//
%NS_E_DRM_MUST_REVALIDATE         = &HC00D28A7&

'//
'// MessageId: NS_E_DRM_INVALID_PROXIMITY_RESPONSE
'//
'// MessageText:
'//
'// The response to the proximity detection challenge is invalid.%0
'//
%NS_E_DRM_INVALID_PROXIMITY_RESPONSE = &HC00D28A8&

'//
'// MessageId: NS_E_DRM_INVALID_SESSION
'//
'// MessageText:
'//
'// The requested session is invalid.%0
'//
%NS_E_DRM_INVALID_SESSION         = &HC00D28A9&

'//
'// MessageId: NS_E_DRM_DEVICE_NOT_OPEN
'//
'// MessageText:
'//
'// The device must be opened before it can be used to receive content.%0
'//
%NS_E_DRM_DEVICE_NOT_OPEN         = &HC00D28AA&

'//
'// MessageId: NS_E_DRM_DEVICE_ALREADY_REGISTERED
'//
'// MessageText:
'//
'// Device registration failed because the device is already registered.%0
'//
%NS_E_DRM_DEVICE_ALREADY_REGISTERED = &HC00D28AB&

'//
'// MessageId: NS_E_DRM_UNSUPPORTED_PROTOCOL_VERSION
'//
'// MessageText:
'//
'// Unsupported WMDRM-ND protocol version.%0
'//
%NS_E_DRM_UNSUPPORTED_PROTOCOL_VERSION = &HC00D28AC&

'//
'// MessageId: NS_E_DRM_UNSUPPORTED_ACTION
'//
'// MessageText:
'//
'// The requested action is not supported.%0
'//
%NS_E_DRM_UNSUPPORTED_ACTION      = &HC00D28AD&

'//
'// MessageId: NS_E_DRM_CERTIFICATE_SECURITY_LEVEL_INADEQUATE
'//
'// MessageText:
'//
'// The certificate does not have an adequate security level for the requested action.%0
'//
%NS_E_DRM_CERTIFICATE_SECURITY_LEVEL_INADEQUATE = &HC00D28AE&

'//
'// MessageId: NS_E_DRM_UNABLE_TO_OPEN_PORT
'//
'// MessageText:
'//
'// Unable to open the specified port for receiving Proximity messages.%0
'//
%NS_E_DRM_UNABLE_TO_OPEN_PORT     = &HC00D28AF&

'//
'// MessageId: NS_E_DRM_BAD_REQUEST
'//
'// MessageText:
'//
'// The message format is invalid.%0
'//
%NS_E_DRM_BAD_REQUEST             = &HC00D28B0&

'//
'// MessageId: NS_E_DRM_INVALID_CRL
'//
'// MessageText:
'//
'// The Certificate Revocation List is invalid or corrupted.%0
'//
%NS_E_DRM_INVALID_CRL             = &HC00D28B1&

'//
'// MessageId: NS_E_DRM_ATTRIBUTE_TOO_LONG
'//
'// MessageText:
'//
'// The length of the attribute name or value is too long.%0
'//
%NS_E_DRM_ATTRIBUTE_TOO_LONG      = &HC00D28B2&

'//
'// MessageId: NS_E_DRM_EXPIRED_LICENSEBLOB
'//
'// MessageText:
'//
'// The license blob passed in the cardea request is expired.%0
'//
%NS_E_DRM_EXPIRED_LICENSEBLOB     = &HC00D28B3&

'//
'// MessageId: NS_E_DRM_INVALID_LICENSEBLOB
'//
'// MessageText:
'//
'// The license blob passed in the cardea request is invalid. Contact Microsoft product support.%0
'//
%NS_E_DRM_INVALID_LICENSEBLOB     = &HC00D28B4&

'//
'// MessageId: NS_E_DRM_INCLUSION_LIST_REQUIRED
'//
'// MessageText:
'//
'// The requested operation can not be performed because the license does not contain an inclusion list.%0
'//
%NS_E_DRM_INCLUSION_LIST_REQUIRED = &HC00D28B5&

'//
'// MessageId: NS_E_DRM_DRMV2CLT_REVOKED
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_DRMV2CLT_REVOKED        = &HC00D28B6&

'//
'// MessageId: NS_E_DRM_RIV_TOO_SMALL
'//
'// MessageText:
'//
'// A problem has occurred in the Digital Rights Management component. Contact Microsoft product support.%0.
'//
%NS_E_DRM_RIV_TOO_SMALL           = &HC00D28B7&


'//
'// Output link protection error codes
'//

'//
'// MessageId: NS_E_OUTPUT_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of output protection required by the content.%0
'//
%NS_E_OUTPUT_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2904&

'//
'// MessageId: NS_E_COMPRESSED_DIGITAL_VIDEO_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of protection required for compressed digital video.%0
'//
%NS_E_COMPRESSED_DIGITAL_VIDEO_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2905&

'//
'// MessageId: NS_E_UNCOMPRESSED_DIGITAL_VIDEO_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of protection required for uncompressed digital video.%0
'//
%NS_E_UNCOMPRESSED_DIGITAL_VIDEO_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2906&

'//
'// MessageId: NS_E_ANALOG_VIDEO_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of protection required for analog video.%0
'//
%NS_E_ANALOG_VIDEO_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2907&

'//
'// MessageId: NS_E_COMPRESSED_DIGITAL_AUDIO_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of protection required for compressed digital audio.%0
'//
%NS_E_COMPRESSED_DIGITAL_AUDIO_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2908&

'//
'// MessageId: NS_E_UNCOMPRESSED_DIGITAL_AUDIO_PROTECTION_LEVEL_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the level of protection required for uncompressed digital audio.%0
'//
%NS_E_UNCOMPRESSED_DIGITAL_AUDIO_PROTECTION_LEVEL_UNSUPPORTED = &HC00D2909&

'//
'// MessageId: NS_E_OUTPUT_PROTECTION_SCHEME_UNSUPPORTED
'//
'// MessageText:
'//
'// Windows Media Player does not support the scheme of output protection required by the content.%0
'//
%NS_E_OUTPUT_PROTECTION_SCHEME_UNSUPPORTED = &HC00D290A&



'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Setup Specific Errors
'//
'// IdRange = 11000..11999
'/////////////////////////////////////////////////////////////////////////
'//
'// MessageId: NS_S_REBOOT_RECOMMENDED
'//
'// MessageText:
'//
'// Installation was successful; however, some file cleanup is not complete. For best results, restart your computer.%0
'//
%NS_S_REBOOT_RECOMMENDED          = &H000D2AF8&

'//
'// MessageId: NS_S_REBOOT_REQUIRED
'//
'// MessageText:
'//
'// Installation was successful; however, some file cleanup is not complete. To continue, you must restart your computer.%0
'//
%NS_S_REBOOT_REQUIRED             = &H000D2AF9&

'//
'// MessageId: NS_E_REBOOT_RECOMMENDED
'//
'// MessageText:
'//
'// Installation was not successful and some file cleanup is not complete. For best results, restart your computer.%0
'//
%NS_E_REBOOT_RECOMMENDED          = &HC00D2AFA&

'//
'// MessageId: NS_E_REBOOT_REQUIRED
'//
'// MessageText:
'//
'// Installation was not successful. To continue, you must restart your computer.%0
'//
%NS_E_REBOOT_REQUIRED             = &HC00D2AFB&

'//
'// MessageId: NS_E_SETUP_INCOMPLETE
'//
'// MessageText:
'//
'// Installation was not successful.%0.
'//
%NS_E_SETUP_INCOMPLETE            = &HC00D2AFC&

'//
'// MessageId: NS_E_SETUP_DRM_MIGRATION_FAILED
'//
'// MessageText:
'//
'// Setup cannot migrate the Windows Media Digital Rights Management (DRM) components.%0.
'//
%NS_E_SETUP_DRM_MIGRATION_FAILED  = &HC00D2AFD&

'//
'// MessageId: NS_E_SETUP_IGNORABLE_FAILURE
'//
'// MessageText:
'//
'// Some skin or playlist components cannot be installed.%0.
'//
%NS_E_SETUP_IGNORABLE_FAILURE     = &HC00D2AFE&

'//
'// MessageId: NS_E_SETUP_DRM_MIGRATION_FAILED_AND_IGNORABLE_FAILURE
'//
'// MessageText:
'//
'// Setup cannot migrate the Windows Media Digital Rights Management (DRM) components. In addition, some skin or playlist components cannot be installed.%0.
'//
%NS_E_SETUP_DRM_MIGRATION_FAILED_AND_IGNORABLE_FAILURE = &HC00D2AFF&

'//
'// MessageId: NS_E_SETUP_BLOCKED
'//
'// MessageText:
'//
'// Installation is blocked because your computer does not meet one or more of the setup requirements.%0.
'//
%NS_E_SETUP_BLOCKED               = &HC00D2B00&


'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Networking Errors
'//
'// IdRange = 12000..12999
'/////////////////////////////////////////////////////////////////////////
'//
'// MessageId: NS_E_UNKNOWN_PROTOCOL
'//
'// MessageText:
'//
'// The specified protocol is not supported.%0
'//
%NS_E_UNKNOWN_PROTOCOL            = &HC00D2EE0&

'//
'// MessageId: NS_E_REDIRECT_TO_PROXY
'//
'// MessageText:
'//
'// The client is redirected to a proxy server.%0
'//
%NS_E_REDIRECT_TO_PROXY           = &HC00D2EE1&

'//
'// MessageId: NS_E_INTERNAL_SERVER_ERROR
'//
'// MessageText:
'//
'// The server encountered an unexpected condition which prevented it from fulfilling the request.%0
'//
%NS_E_INTERNAL_SERVER_ERROR       = &HC00D2EE2&

'//
'// MessageId: NS_E_BAD_REQUEST
'//
'// MessageText:
'//
'// The request could not be understood by the server.%0
'//
%NS_E_BAD_REQUEST                 = &HC00D2EE3&

'//
'// MessageId: NS_E_ERROR_FROM_PROXY
'//
'// MessageText:
'//
'// The proxy experienced an error while attempting to contact the media server.%0
'//
%NS_E_ERROR_FROM_PROXY            = &HC00D2EE4&

'//
'// MessageId: NS_E_PROXY_TIMEOUT
'//
'// MessageText:
'//
'// The proxy did not receive a timely response while attempting to contact the media server.%0
'//
%NS_E_PROXY_TIMEOUT               = &HC00D2EE5&

'//
'// MessageId: NS_E_SERVER_UNAVAILABLE
'//
'// MessageText:
'//
'// The server is currently unable to handle the request due to a temporary overloading or maintenance of the server.%0
'//
%NS_E_SERVER_UNAVAILABLE          = &HC00D2EE6&

'//
'// MessageId: NS_E_REFUSED_BY_SERVER
'//
'// MessageText:
'//
'// The server is refusing to fulfill the requested operation.%0
'//
%NS_E_REFUSED_BY_SERVER           = &HC00D2EE7&

'//
'// MessageId: NS_E_INCOMPATIBLE_SERVER
'//
'// MessageText:
'//
'// The server is not a compatible streaming media server.%0
'//
%NS_E_INCOMPATIBLE_SERVER         = &HC00D2EE8&

'//
'// MessageId: NS_E_MULTICAST_DISABLED
'//
'// MessageText:
'//
'// The content cannot be streamed because the Multicast protocol has been disabled.%0
'//
%NS_E_MULTICAST_DISABLED          = &HC00D2EE9&

'//
'// MessageId: NS_E_INVALID_REDIRECT
'//
'// MessageText:
'//
'// The server redirected the player to an invalid location.%0
'//
%NS_E_INVALID_REDIRECT            = &HC00D2EEA&

'//
'// MessageId: NS_E_ALL_PROTOCOLS_DISABLED
'//
'// MessageText:
'//
'// The content cannot be streamed because all protocols have been disabled.%0
'//
%NS_E_ALL_PROTOCOLS_DISABLED      = &HC00D2EEB&

'//
'// MessageId: NS_E_MSBD_NO_LONGER_SUPPORTED
'//
'// MessageText:
'//
'// The MSBD protocol is no longer supported. Please use HTTP to connect to the Windows Media stream.%0
'//
%NS_E_MSBD_NO_LONGER_SUPPORTED    = &HC00D2EEC&

'//
'// MessageId: NS_E_PROXY_NOT_FOUND
'//
'// MessageText:
'//
'// The proxy server could not be located. Please check your proxy server configuration.%0
'//
%NS_E_PROXY_NOT_FOUND             = &HC00D2EED&

'//
'// MessageId: NS_E_CANNOT_CONNECT_TO_PROXY
'//
'// MessageText:
'//
'// Unable to establish a connection to the proxy server. Please check your proxy server configuration.%0
'//
%NS_E_CANNOT_CONNECT_TO_PROXY     = &HC00D2EEE&

'//
'// MessageId: NS_E_SERVER_DNS_TIMEOUT
'//
'// MessageText:
'//
'// Unable to locate the media server. The operation timed out.%0
'//
%NS_E_SERVER_DNS_TIMEOUT          = &HC00D2EEF&

'//
'// MessageId: NS_E_PROXY_DNS_TIMEOUT
'//
'// MessageText:
'//
'// Unable to locate the proxy server. The operation timed out.%0
'//
%NS_E_PROXY_DNS_TIMEOUT           = &HC00D2EF0&

'//
'// MessageId: NS_E_CLOSED_ON_SUSPEND
'//
'// MessageText:
'//
'// Media closed because Windows was shut down.%0
'//
%NS_E_CLOSED_ON_SUSPEND           = &HC00D2EF1&

'//
'// MessageId: NS_E_CANNOT_READ_PLAYLIST_FROM_MEDIASERVER
'//
'// MessageText:
'//
'// Unable to read the contents of a playlist file from a media server.%0
'//
%NS_E_CANNOT_READ_PLAYLIST_FROM_MEDIASERVER = &HC00D2EF2&

'//
'// MessageId: NS_E_SESSION_NOT_FOUND
'//
'// MessageText:
'//
'// Session not found.%0
'//
%NS_E_SESSION_NOT_FOUND           = &HC00D2EF3&

'//
'// MessageId: NS_E_REQUIRE_STREAMING_CLIENT
'//
'// MessageText:
'//
'// Content requires a streaming media client.%0
'//
%NS_E_REQUIRE_STREAMING_CLIENT    = &HC00D2EF4&

'//
'// MessageId: NS_E_PLAYLIST_ENTRY_HAS_CHANGED
'//
'// MessageText:
'//
'// A command applies to a previous playlist entry.%0
'//
%NS_E_PLAYLIST_ENTRY_HAS_CHANGED  = &HC00D2EF5&

'//
'// MessageId: NS_E_PROXY_ACCESSDENIED
'//
'// MessageText:
'//
'// The proxy server is denying access.  The username and/or password might be incorrect.%0
'//
%NS_E_PROXY_ACCESSDENIED          = &HC00D2EF6&

'//
'// MessageId: NS_E_PROXY_SOURCE_ACCESSDENIED
'//
'// MessageText:
'//
'// The proxy could not provide valid authentication credentials to the media server.%0
'//
%NS_E_PROXY_SOURCE_ACCESSDENIED   = &HC00D2EF7&

'//
'// MessageId: NS_E_NETWORK_SINK_WRITE
'//
'// MessageText:
'//
'// The network sink failed to write data to the network.%0
'//
%NS_E_NETWORK_SINK_WRITE          = &HC00D2EF8&

'//
'// MessageId: NS_E_FIREWALL
'//
'// MessageText:
'//
'// Packets are not being received from the server. The packets might be blocked by a filtering device, such as a network firewall.%0
'//
%NS_E_FIREWALL                    = &HC00D2EF9&

'//
'// MessageId: NS_E_MMS_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The MMS protocol is not supported. Please use HTTP or RTSP to connect to the Windows Media stream.%0
'//
%NS_E_MMS_NOT_SUPPORTED           = &HC00D2EFA&

'//
'// MessageId: NS_E_SERVER_ACCESSDENIED
'//
'// MessageText:
'//
'// The Windows Media server is denying access.  The username and/or password might be incorrect.%0
'//
%NS_E_SERVER_ACCESSDENIED         = &HC00D2EFB&

'//
'// MessageId: NS_E_RESOURCE_GONE
'//
'// MessageText:
'//
'// The Publishing Point or file on the Windows Media Server is no longer available.%0
'//
%NS_E_RESOURCE_GONE               = &HC00D2EFC&

'//
'// MessageId: NS_E_NO_EXISTING_PACKETIZER
'//
'// MessageText:
'//
'// There is no existing packetizer plugin for a stream.%0
'//
%NS_E_NO_EXISTING_PACKETIZER      = &HC00D2EFD&

'//
'// MessageId: NS_E_BAD_SYNTAX_IN_SERVER_RESPONSE
'//
'// MessageText:
'//
'// The response from the media server could not be understood. This might be caused by an incompatible proxy server or media server.%0
'//
%NS_E_BAD_SYNTAX_IN_SERVER_RESPONSE = &HC00D2EFE&

'//
'// MessageId: NS_I_RECONNECTED
'//
'// MessageText:
'//
'// The client is reconnected.%0
'//
%NS_I_RECONNECTED                 = &H400D2EFF&

'//
'// MessageId: NS_E_RESET_SOCKET_CONNECTION
'//
'// MessageText:
'//
'// The Windows Media Server reset the network connection.%0
'//
%NS_E_RESET_SOCKET_CONNECTION     = &HC00D2F00&

'//
'// MessageId: NS_I_NOLOG_STOP
'//
'// MessageText:
'//
'// Forcing a switch to a pending header on start.%0
'//
%NS_I_NOLOG_STOP                  = &H400D2F01&

'//
'// MessageId: NS_E_TOO_MANY_HOPS
'//
'// MessageText:
'//
'// The request could not reach the media server (too many hops).%0
'//
%NS_E_TOO_MANY_HOPS               = &HC00D2F02&

'//
'// MessageId: NS_I_EXISTING_PACKETIZER
'//
'// MessageText:
'//
'// There is already an existing packetizer plugin for the stream.%0
'//
%NS_I_EXISTING_PACKETIZER         = &H400D2F03&

'//
'// MessageId: NS_I_MANUAL_PROXY
'//
'// MessageText:
'//
'// The proxy setting is manual.%0
'//
%NS_I_MANUAL_PROXY                = &H400D2F04&

'//
'// MessageId: NS_E_TOO_MUCH_DATA_FROM_SERVER
'//
'// MessageText:
'//
'// The server is sending too much data. The connection has been terminated.%0
'//
%NS_E_TOO_MUCH_DATA_FROM_SERVER   = &HC00D2F05&

'//
'// MessageId: NS_E_CONNECT_TIMEOUT
'//
'// MessageText:
'//
'// It was not possible to establish a connection to the media server in a timely manner. The media server may be down for maintenance, or it may be necessary to use a proxy server to access this media server.%0
'//
%NS_E_CONNECT_TIMEOUT             = &HC00D2F06&

'//
'// MessageId: NS_E_PROXY_CONNECT_TIMEOUT
'//
'// MessageText:
'//
'// It was not possible to establish a connection to the proxy server in a timely manner. Please check your proxy server configuration.%0
'//
%NS_E_PROXY_CONNECT_TIMEOUT       = &HC00D2F07&

'//
'// MessageId: NS_E_SESSION_INVALID
'//
'// MessageText:
'//
'// Session not found.%0
'//
%NS_E_SESSION_INVALID             = &HC00D2F08&

'//
'// MessageId: NS_S_EOSRECEDING
'//
'// MessageText:
'//
'// EOS hit during rewinding.%0
'//
%NS_S_EOSRECEDING                 = &H000D2F09&

'//
'// MessageId: NS_E_PACKETSINK_UNKNOWN_FEC_STREAM
'//
'// MessageText:
'//
'// Unknown packet sink stream.%0
'//
%NS_E_PACKETSINK_UNKNOWN_FEC_STREAM = &HC00D2F0A&

'//
'// MessageId: NS_E_PUSH_CANNOTCONNECT
'//
'// MessageText:
'//
'// Unable to establish a connection to the server. Ensure Windows Media Services is started and the HTTP Server control protocol is properly enabled.%0
'//
%NS_E_PUSH_CANNOTCONNECT          = &HC00D2F0B&

'//
'// MessageId: NS_E_INCOMPATIBLE_PUSH_SERVER
'//
'// MessageText:
'//
'// The Server service that received the HTTP push request is not a compatible version of Windows Media Services (WMS).  This error may indicate the push request was received by IIS instead of WMS.
'//  Ensure WMS is started and has the HTTP Server control protocol properly enabled and try again.%0
'//
%NS_E_INCOMPATIBLE_PUSH_SERVER    = &HC00D2F0C&

'//
'// MessageId: NS_S_CHANGENOTICE
'//
'// MessageText:
'//
'// Internal.%0
'//
%NS_S_CHANGENOTICE                = &H000D2F0D&


'/////////////////////////////////////////////////////////////////////////
'//
'// Windows Media Client Media Services
'//
'// IdRange = 13000..13999 (0x32C8-0x36AF)
'/////////////////////////////////////////////////////////////////////////
'//
'// MessageId: NS_E_END_OF_PLAYLIST
'//
'// MessageText:
'//
'// The playlist has reached its end.%0
'//
%NS_E_END_OF_PLAYLIST             = &HC00D32C8&

'//
'// MessageId: NS_E_USE_FILE_SOURCE
'//
'// MessageText:
'//
'// Use file source.%0
'//
%NS_E_USE_FILE_SOURCE             = &HC00D32C9&

'//
'// MessageId: NS_E_PROPERTY_NOT_FOUND
'//
'// MessageText:
'//
'// The property was not found.%0
'//
%NS_E_PROPERTY_NOT_FOUND          = &HC00D32CA&

'//
'// MessageId: NS_E_PROPERTY_READ_ONLY
'//
'// MessageText:
'//
'// The property is read only.%0
'//
%NS_E_PROPERTY_READ_ONLY          = &HC00D32CC&

'//
'// MessageId: NS_E_TABLE_KEY_NOT_FOUND
'//
'// MessageText:
'//
'// The table key was not found.%0
'//
%NS_E_TABLE_KEY_NOT_FOUND         = &HC00D32CD&

'//
'// MessageId: NS_E_INVALID_QUERY_OPERATOR
'//
'// MessageText:
'//
'// Invalid query operator.%0
'//
%NS_E_INVALID_QUERY_OPERATOR      = &HC00D32CF&

'//
'// MessageId: NS_E_INVALID_QUERY_PROPERTY
'//
'// MessageText:
'//
'// Invalid query property.%0
'//
%NS_E_INVALID_QUERY_PROPERTY      = &HC00D32D0&

'//
'// MessageId: NS_E_PROPERTY_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The property is not supported.%0
'//
%NS_E_PROPERTY_NOT_SUPPORTED      = &HC00D32D2&

'//
'// MessageId: NS_E_SCHEMA_CLASSIFY_FAILURE
'//
'// MessageText:
'//
'// Schema classification failure.%0
'//
%NS_E_SCHEMA_CLASSIFY_FAILURE     = &HC00D32D4&

'//
'// MessageId: NS_E_METADATA_FORMAT_NOT_SUPPORTED
'//
'// MessageText:
'//
'// The metadata format is not supported.%0
'//
%NS_E_METADATA_FORMAT_NOT_SUPPORTED = &HC00D32D5&

'//
'// MessageId: NS_E_METADATA_NO_EDITING_CAPABILITY
'//
'// MessageText:
'//
'// Cannot edit the metadata.%0
'//
%NS_E_METADATA_NO_EDITING_CAPABILITY = &HC00D32D6&

'//
'// MessageId: NS_E_METADATA_CANNOT_SET_LOCALE
'//
'// MessageText:
'//
'// Cannot set the locale id.%0
'//
%NS_E_METADATA_CANNOT_SET_LOCALE  = &HC00D32D7&

'//
'// MessageId: NS_E_METADATA_LANGUAGE_NOT_SUPORTED
'//
'// MessageText:
'//
'// The language is not supported in the format.%0
'//
%NS_E_METADATA_LANGUAGE_NOT_SUPORTED = &HC00D32D8&

'//
'// MessageId: NS_E_METADATA_NO_RFC1766_NAME_FOR_LOCALE
'//
'// MessageText:
'//
'// There is no RFC1766 name translation for the supplied locale id.%0
'//
%NS_E_METADATA_NO_RFC1766_NAME_FOR_LOCALE = &HC00D32D9&

'//
'// MessageId: NS_E_METADATA_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The metadata (or metadata item) is not available.%0
'//
%NS_E_METADATA_NOT_AVAILABLE      = &HC00D32DA&

'//
'// MessageId: NS_E_METADATA_CACHE_DATA_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The cached metadata (or metadata item) is not available.%0
'//
%NS_E_METADATA_CACHE_DATA_NOT_AVAILABLE = &HC00D32DB&

'//
'// MessageId: NS_E_METADATA_INVALID_DOCUMENT_TYPE
'//
'// MessageText:
'//
'// The metadata document is invalid.%0
'//
%NS_E_METADATA_INVALID_DOCUMENT_TYPE = &HC00D32DC&

'//
'// MessageId: NS_E_METADATA_IDENTIFIER_NOT_AVAILABLE
'//
'// MessageText:
'//
'// The metadata content identifier is not available.%0
'//
%NS_E_METADATA_IDENTIFIER_NOT_AVAILABLE = &HC00D32DD&

'//
'// MessageId: NS_E_METADATA_CANNOT_RETRIEVE_FROM_OFFLINE_CACHE
'//
'// MessageText:
'//
'// Cannot retrieve metadata from the offline metadata cache.%0
'//
%NS_E_METADATA_CANNOT_RETRIEVE_FROM_OFFLINE_CACHE = &HC00D32DE&
