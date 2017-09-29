' ########################################################################################
' Microsoft Windows
' File: bitsmsg.inc
' Contents: Error code definitions for the background file copier
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BITSMSG_INC = 1

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


'//
'// Define the severity codes
'//

' //
' // MessageId: BG_E_NOT_FOUND
' //
' // MessageText:
' //
' //  The requested job was not found.
' //
%BG_E_NOT_FOUND                   = &H80200001&

' //
' // MessageId: BG_E_INVALID_STATE
' //
' // MessageText:
' //
' //  The requested action is not allowed in the current job state. The job might have been canceled or completed transferring. It is in a read-only state now.
' //
%BG_E_INVALID_STATE               = &H80200002&

' //
' // MessageId: BG_E_EMPTY
' //
' // MessageText:
' //
' //  There are no files attached to this job. Attach files to the job, and then try again.
' //
%BG_E_EMPTY                       = &H80200003&

' //
' // MessageId: BG_E_FILE_NOT_AVAILABLE
' //
' // MessageText:
' //
' //  No file is available because no URL generated an error.
' //
%BG_E_FILE_NOT_AVAILABLE          = &H80200004&

' //
' // MessageId: BG_E_PROTOCOL_NOT_AVAILABLE
' //
' // MessageText:
' //
' //  No protocol is available because no URL generated an error.
' //
%BG_E_PROTOCOL_NOT_AVAILABLE      = &H80200005&

' //
' // MessageId: BG_S_ERROR_CONTEXT_NONE
' //
' // MessageText:
' //
' //  No errors have occurred.
' //
%BG_S_ERROR_CONTEXT_NONE          = &H00200006&

' //
' // MessageId: BG_E_ERROR_CONTEXT_UNKNOWN
' //
' // MessageText:
' //
' //  The error occurred in an unknown location.
' //
%BG_E_ERROR_CONTEXT_UNKNOWN       = &H80200007&

' //
' // MessageId: BG_E_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER
' //
' // MessageText:
' //
' //  The error occurred in the Background Intelligent Transfer Service (BITS) queue manager.
' //
%BG_E_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER = &H80200008&

' //
' // MessageId: BG_E_ERROR_CONTEXT_LOCAL_FILE
' //
' // MessageText:
' //
' //  The error occurred while the local file was being processed. Verify that the file is not in use, and then try again.
' //
%BG_E_ERROR_CONTEXT_LOCAL_FILE    = &H80200009&

' //
' // MessageId: BG_E_ERROR_CONTEXT_REMOTE_FILE
' //
' // MessageText:
' //
' //  The error occurred while the remote file was being processed.
' //
%BG_E_ERROR_CONTEXT_REMOTE_FILE   = &H8020000A&

' //
' // MessageId: BG_E_ERROR_CONTEXT_GENERAL_TRANSPORT
' //
' // MessageText:
' //
' //  The error occurred in the transport layer. The client could not connect to the server.
' //
%BG_E_ERROR_CONTEXT_GENERAL_TRANSPORT = &H8020000B&

' //
' // MessageId: BG_E_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION
' //
' // MessageText:
' //
' //  The error occurred while the notification callback was being processed. Background Intelligent Transfer Service (BITS) will try again later.
' //
%BG_E_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION = &H8020000C&

' //
' // MessageId: BG_E_DESTINATION_LOCKED
' //
' // MessageText:
' //
' //  The destination file system volume is not available. Verify that another program, such as CheckDisk, is not running, which would lock the volume. When the volume is available, Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_DESTINATION_LOCKED          = &H8020000D&

' //
' // MessageId: BG_E_VOLUME_CHANGED
' //
' // MessageText:
' //
' //  The destination volume has changed. If the disk is removable, it might have been replaced with a different disk. Reinsert the original disk and resume the job.
' //
%BG_E_VOLUME_CHANGED              = &H8020000E&

' //
' // MessageId: BG_E_ERROR_INFORMATION_UNAVAILABLE
' //
' // MessageText:
' //
' //  No errors have occurred.
' //
%BG_E_ERROR_INFORMATION_UNAVAILABLE = &H8020000F&

' //
' // MessageId: BG_E_NETWORK_DISCONNECTED
' //
' // MessageText:
' //
' //  There are currently no active network connections. Background Intelligent Transfer Service (BITS) will try again when an adapter is connected.
' //
%BG_E_NETWORK_DISCONNECTED        = &H80200010&

' //
' // MessageId: BG_E_MISSING_FILE_SIZE
' //
' // MessageText:
' //
' //  The server did not return the file size. The URL might point to dynamic content. The Content-Length header is not available in the server's HTTP reply.
' //
%BG_E_MISSING_FILE_SIZE           = &H80200011&

' //
' // MessageId: BG_E_INSUFFICIENT_HTTP_SUPPORT
' //
' // MessageText:
' //
' //  The server does not support HTTP 1.1.
' //
%BG_E_INSUFFICIENT_HTTP_SUPPORT   = &H80200012&

' //
' // MessageId: BG_E_INSUFFICIENT_RANGE_SUPPORT
' //
' // MessageText:
' //
' //  The server does not support the necessary HTTP protocol. Background Intelligent Transfer Service (BITS) requires that the server support the Range protocol header.
' //
%BG_E_INSUFFICIENT_RANGE_SUPPORT  = &H80200013&

' //
' // MessageId: BG_E_REMOTE_NOT_SUPPORTED
' //
' // MessageText:
' //
' //  Background Intelligent Transfer Service (BITS) cannot be used remotely.
' //
%BG_E_REMOTE_NOT_SUPPORTED        = &H80200014&

' //
' // MessageId: BG_E_NEW_OWNER_DIFF_MAPPING
' //
' // MessageText:
' //
' //  The drive mapping for the job is different for the current owner than for the previous owner. Use a UNC path instead.
' //
%BG_E_NEW_OWNER_DIFF_MAPPING      = &H80200015&

' //
' // MessageId: BG_E_NEW_OWNER_NO_FILE_ACCESS
' //
' // MessageText:
' //
' //  The new owner has insufficient access to the local files for the job. The new owner might not have permissions to access the job files. Verify that the new owner has sufficient permissions, and then try again.
' //
%BG_E_NEW_OWNER_NO_FILE_ACCESS    = &H80200016&

' //
' // MessageId: BG_S_PARTIAL_COMPLETE
' //
' // MessageText:
' //
' //  Some of the transferred files were deleted because they were incomplete.
' //
%BG_S_PARTIAL_COMPLETE            = &H00200017&

' //
' // MessageId: BG_E_PROXY_LIST_TOO_LARGE
' //
' // MessageText:
' //
' //  The HTTP proxy list cannot be longer than 32,000 characters. Try again with a shorter proxy list.
' //
%BG_E_PROXY_LIST_TOO_LARGE        = &H80200018&

' //
' // MessageId: BG_E_PROXY_BYPASS_LIST_TOO_LARGE
' //
' // MessageText:
' //
' //  The HTTP proxy bypass list cannot be longer than 32,000 characters. Try again with a shorter bypass proxy list.
' //
%BG_E_PROXY_BYPASS_LIST_TOO_LARGE = &H80200019&

' //
' // MessageId: BG_S_UNABLE_TO_DELETE_FILES
' //
' // MessageText:
' //
' //  Some of the temporary files could not be deleted. Check the system event log for the complete list of files that could not be deleted.
' //
%BG_S_UNABLE_TO_DELETE_FILES      = &H0020001A&

' //
' // MessageId: BG_E_INVALID_SERVER_RESPONSE
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_INVALID_SERVER_RESPONSE     = &H8020001B&

' //
' // MessageId: BG_E_TOO_MANY_FILES
' //
' // MessageText:
' //
' //  No more files can be added to this job.
' //
%BG_E_TOO_MANY_FILES              = &H8020001C&

' //
' // MessageId: BG_E_LOCAL_FILE_CHANGED
' //
' // MessageText:
' //
' //  The local file was changed during the transfer. Recreate the job, and then try to transfer it again.
' //
%BG_E_LOCAL_FILE_CHANGED          = &H8020001D&

' //
' // MessageId: BG_E_ERROR_CONTEXT_REMOTE_APPLICATION
' //
' // MessageText:
' //
' //  The program on the remote server reported the error.
' //
%BG_E_ERROR_CONTEXT_REMOTE_APPLICATION = &H8020001E&

' //
' // MessageId: BG_E_SESSION_NOT_FOUND
' //
' // MessageText:
' //
' //  The specified session could not be found on the server. Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_SESSION_NOT_FOUND           = &H8020001F&

' //
' // MessageId: BG_E_TOO_LARGE
' //
' // MessageText:
' //
' //  The job is too large for the server to accept. This job might exceed a job size limit set by the server administrator. Reduce the size of the job, and then try again.
' //
%BG_E_TOO_LARGE                   = &H80200020&

' //
' // MessageId: BG_E_STRING_TOO_LONG
' //
' // MessageText:
' //
' //  The specified string is too long.
' //
%BG_E_STRING_TOO_LONG             = &H80200021&

' //
' // MessageId: BG_E_CLIENT_SERVER_PROTOCOL_MISMATCH
' //
' // MessageText:
' //
' //  The client and server versions of Background Intelligent Transfer Service (BITS) are incompatible.
' //
%BG_E_CLIENT_SERVER_PROTOCOL_MISMATCH = &H80200022&

' //
' // MessageId: BG_E_SERVER_EXECUTE_ENABLE
' //
' // MessageText:
' //
' //  Scripting OR execute permissions are enabled on the IIS virtual directory associated with the job. To upload files to the virtual directory, disable the scripting and execute permissions on the virtual directory.
' //
%BG_E_SERVER_EXECUTE_ENABLE       = &H80200023&

' //
' // MessageId: BG_E_NO_PROGRESS
' //
' // MessageText:
' //
' //  The job is not making headway.  The server may be misconfigured.  Background Intelligent Transfer Service (BITS) will try again later.
' //
%BG_E_NO_PROGRESS                 = &H80200024&

' //
' // MessageId: BG_E_USERNAME_TOO_LARGE
' //
' // MessageText:
' //
' //  The user name cannot be longer than 300 characters. Try again with a shorter name.
' //
%BG_E_USERNAME_TOO_LARGE          = &H80200025&

' //
' // MessageId: BG_E_PASSWORD_TOO_LARGE
' //
' // MessageText:
' //
' //  The password cannot be longer than 65536 characters. Try again with a shorter password.
' //
%BG_E_PASSWORD_TOO_LARGE          = &H80200026&

' //
' // MessageId: BG_E_INVALID_AUTH_TARGET
' //
' // MessageText:
' //
' //  The authentication target specified in the credentials is not defined.
' //
%BG_E_INVALID_AUTH_TARGET         = &H80200027&

' //
' // MessageId: BG_E_INVALID_AUTH_SCHEME
' //
' // MessageText:
' //
' //  The authentication scheme specified in the credentials is not defined.
' //
%BG_E_INVALID_AUTH_SCHEME         = &H80200028&

' //
' // MessageId: BG_E_FILE_NOT_FOUND
' //
' // MessageText:
' //
' //  The specified file name does not match any of the files in the job.
' //
%BG_E_FILE_NOT_FOUND              = &H80200029&

' //
' // MessageId: BG_S_PROXY_CHANGED
' //
' // MessageText:
' //
' //  The proxy server was changed.
' //
%BG_S_PROXY_CHANGED               = &H0020002A&

' //
' // MessageId: BG_E_INVALID_RANGE
' //
' // MessageText:
' //
' //  The requested byte range extends beyond the end of the web page.  Use byte ranges that are wholly within the page.
' //
%BG_E_INVALID_RANGE               = &H8020002B&

' //
' // MessageId: BG_E_OVERLAPPING_RANGES
' //
' // MessageText:
' //
' //  The list of byte ranges contains some overlapping ranges, which are not supported.
' //
%BG_E_OVERLAPPING_RANGES          = &H8020002C&

' //
' // MessageId: BG_E_CONNECT_FAILURE
' //
' // MessageText:
' //
' //  A connection could not be established.
' //
%BG_E_CONNECT_FAILURE             = &H8020002D&

' //
' // MessageId: BG_E_CONNECTION_CLOSED
' //
' // MessageText:
' //
' //  The connection was prematurely closed.
' //
%BG_E_CONNECTION_CLOSED           = &H8020002E&

' //
' // MessageId: BG_E_KEEP_ALIVE_FAILURE
' //
' // MessageText:
' //
' //  The connection for a request that specifies the Keep-alive header was closed unexpectedly.
' //
%BG_E_KEEP_ALIVE_FAILURE          = &H8020002F&

' //
' // MessageId: BG_E_MESSAGE_LENGTH_LIMIT_EXCEEDED
' //
' // MessageText:
' //
' //  A message was received that exceeded the specified limit when sending a request or receiving a response from the server.
' //
%BG_E_MESSAGE_LENGTH_LIMIT_EXCEEDED = &H80200030&

' //
' // MessageId: BG_E_NAME_RESOLUTION_FAILURE
' //
' // MessageText:
' //
' //  The host name could not be found.
' //
%BG_E_NAME_RESOLUTION_FAILURE     = &H80200031&

' //
' // MessageId: BG_E_PENDING
' //
' // MessageText:
' //
' //  An internal asynchronous request is pending.
' //
%BG_E_PENDING                     = &H80200032&

' //
' // MessageId: BG_E_PIPELINE_FAILURE
' //
' // MessageText:
' //
' //  BG_E_PIPELINE_FAILURE
' //
%BG_E_PIPELINE_FAILURE            = &H80200033&

' //
' // MessageId: BG_E_PROTOCOL_ERROR
' //
' // MessageText:
' //
' //  The response received from the server was complete but indicated a protocol-level error.
' //
%BG_E_PROTOCOL_ERROR              = &H80200034&

' //
' // MessageId: BG_E_PROXY_NAME_RESOLUTION_FAILURE
' //
' // MessageText:
' //
' //  The proxy name could not be found.
' //
%BG_E_PROXY_NAME_RESOLUTION_FAILURE = &H80200035&

' //
' // MessageId: BG_E_RECEIVE_FAILURE
' //
' // MessageText:
' //
' //  A complete response was not received from the server.
' //
%BG_E_RECEIVE_FAILURE             = &H80200036&

' //
' // MessageId: BG_E_REQUEST_CANCELED
' //
' // MessageText:
' //
' //  The request was canceled.
' //
%BG_E_REQUEST_CANCELED            = &H80200037&

' //
' // MessageId: BG_E_SECURE_CHANNEL_FAILURE
' //
' // MessageText:
' //
' //  An error occurred while establishing a connection using SSL.
' //
%BG_E_SECURE_CHANNEL_FAILURE      = &H80200038&

' //
' // MessageId: BG_E_SEND_FAILURE
' //
' // MessageText:
' //
' //  A complete request could not be sent to the remote server.
' //
%BG_E_SEND_FAILURE                = &H80200039&

' //
' // MessageId: BG_E_SERVER_PROTOCOL_VIOLATION
' //
' // MessageText:
' //
' //  The server response was not valid.
' //
%BG_E_SERVER_PROTOCOL_VIOLATION   = &H8020003A&

' //
' // MessageId: BG_E_TIMEOUT
' //
' // MessageText:
' //
' //  The operation exceeded the time limit.
' //
%BG_E_TIMEOUT                     = &H8020003B&

' //
' // MessageId: BG_E_TRUST_FAILURE
' //
' // MessageText:
' //
' //  A server certificate could not be validated.
' //
%BG_E_TRUST_FAILURE               = &H8020003C&

' //
' // MessageId: BG_E_UNKNOWN_ERROR
' //
' // MessageText:
' //
' //  A unknown error occured.
' //
%BG_E_UNKNOWN_ERROR               = &H8020003D&

' //
' // MessageId: BG_E_BLOCKED_BY_POLICY
' //
' // MessageText:
' //
' //  Group Policy settings prevent background jobs from running at this time.
' //
%BG_E_BLOCKED_BY_POLICY           = &H8020003E&

' //
' // MessageId: BG_E_INVALID_PROXY_INFO
' //
' // MessageText:
' //
' //  The supplied proxy server or bypass list is invalid.
' //
%BG_E_INVALID_PROXY_INFO          = &H8020003F&

' //
' // MessageId: BG_E_INVALID_CREDENTIALS
' //
' // MessageText:
' //
' //  The format of the supplied security credentials is invalid.
' //
%BG_E_INVALID_CREDENTIALS         = &H80200040&


'// MessageId: BG_E_INVALID_HASH_ALGORITHM
'//
'// MessageText:
'//
'// The application chose an unsupported hashing algorithm.
'//
%BG_E_INVALID_HASH_ALGORITHM      = &H80200041&

'//
'// MessageId: BG_E_RECORD_DELETED
'//
'// MessageText:
'//
'// The chosen cache record has been deleted.  The attempt to update it has been abandoned.
'//
%BG_E_RECORD_DELETED              = &H80200042&

'//
'// MessageId: BG_E_COMMIT_IN_PROGRESS
'//
'// MessageText:
'//
'// Another application thread is already updating the cache record.
'//
%BG_E_COMMIT_IN_PROGRESS          = &H80200043&

'//
'// MessageId: BG_E_DISCOVERY_IN_PROGRESS
'//
'// MessageText:
'//
'// The system is already searching for neighbors.  Retry the operation after a few seconds.
'//
%BG_E_DISCOVERY_IN_PROGRESS       = &H80200044&

'//
'// MessageId: BG_E_UPNP_ERROR
'//
'// MessageText:
'//
'// A Universal Plug and Play (UPnP) error has occured.  Please check your Internet Gateway Device.
'//
%BG_E_UPNP_ERROR                  = &H80200045&

'//
'// MessageId: BG_E_TEST_OPTION_BLOCKED_DOWNLOAD
'//
'// MessageText:
'//
'// The test option is blocking the download after the search completed.
'//
%BG_E_TEST_OPTION_BLOCKED_DOWNLOAD = &H80200046&

'//
'// MessageId: BG_E_PEERCACHING_DISABLED
'//
'// MessageText:
'//
'// Peer-caching is disabled.
'//
%BG_E_PEERCACHING_DISABLED        = &H80200047&

'//
'// MessageId: BG_E_BUSYCACHERECORD
'//
'// MessageText:
'//
'// The cache record is in use and can not be changed or deleted at this time.  Try again after a few seconds.
'//
%BG_E_BUSYCACHERECORD             = &H80200048&

'//
'// MessageId: BG_E_TOO_MANY_JOBS_PER_USER
'//
'// MessageText:
'//
'// Job count for the current user has exceeded the per user job limit.
'//
%BG_E_TOO_MANY_JOBS_PER_USER      = &H80200049&

'//
'// MessageId: BG_E_TOO_MANY_JOBS_PER_MACHINE
'//
'// MessageText:
'//
'// Job count for the current machine has exceeded the per machine job limit.
'//
%BG_E_TOO_MANY_JOBS_PER_MACHINE   = &H80200050&

'//
'// MessageId: BG_E_TOO_MANY_FILES_IN_JOB
'//
'// MessageText:
'//
'// File count for the current job has exceeded the per job file limit.
'//
%BG_E_TOO_MANY_FILES_IN_JOB       = &H80200051&

'//
'// MessageId: BG_E_TOO_MANY_RANGES_IN_FILE
'//
'// MessageText:
'//
'// Range count for the current file has exceeded the per file Range limit.
'//
%BG_E_TOO_MANY_RANGES_IN_FILE     = &H80200052&

'//
'// MessageId: BG_E_VALIDATION_FAILED
'//
'// MessageText:
'//
'// The application requested data from a web site, but the response was invalid. Using Event Viewer, check the log 'Application Logs \ Microsoft \ Windows \ Bits-client \ Operational' for more details.
'//
%BG_E_VALIDATION_FAILED           = &H80200053&

'//
'// MessageId: BG_E_MAXDOWNLOAD_TIMEOUT
'//
'// MessageText:
'//
'// BITS timed out downloading the job. The download did not complete within the maximum download time set on the job.
'//
%BG_E_MAXDOWNLOAD_TIMEOUT         = &H80200054&

'// MessageId: BG_S_OVERRIDDEN_BY_POLICY
'//
'// MessageText:
'//
'// The configuration preferences have been saved successfully, but one or more of them are overridden by Group Policy.
'//
%BG_S_OVERRIDDEN_BY_POLICY        = &H00200055&

'//
'// MessageId: BG_E_TOKEN_REQUIRED
'//
'// MessageText:
'//
'// The job is configured to use a different security token for some operations, but the token is not currently available.  The application must provide a token and then resume the job.
'//
%BG_E_TOKEN_REQUIRED              = &H80200056&

' //
' // MessageId: BG_E_HTTP_ERROR_100
' //
' // MessageText:
' //
' //  The request can be continued.
' //
%BG_E_HTTP_ERROR_100              = &H80190064&

' //
' // MessageId: BG_E_HTTP_ERROR_101
' //
' // MessageText:
' //
' //  The server switched protocols in an upgrade header.
' //
%BG_E_HTTP_ERROR_101              = &H80190065&

' //
' // MessageId: BG_E_HTTP_ERROR_200
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_200              = &H801900C8&

' //
' // MessageId: BG_E_HTTP_ERROR_201
' //
' // MessageText:
' //
' //  The request was fulfilled and resulted in the creation of a new resource.
' //
%BG_E_HTTP_ERROR_201              = &H801900C9&

' //
' // MessageId: BG_E_HTTP_ERROR_202
' //
' // MessageText:
' //
' //  The request was accepted for processing, but the processing has not been completed yet.
' //
%BG_E_HTTP_ERROR_202              = &H801900CA&

' //
' // MessageId: BG_E_HTTP_ERROR_203
' //
' // MessageText:
' //
' //  The returned metadata in the entity-header is not the definitive set available from the server of origin.
' //
%BG_E_HTTP_ERROR_203              = &H801900CB&

' //
' // MessageId: BG_E_HTTP_ERROR_204
' //
' // MessageText:
' //
' //  The server has fulfilled the request, but there is no new information to send back.
' //
%BG_E_HTTP_ERROR_204              = &H801900CC&

' //
' // MessageId: BG_E_HTTP_ERROR_205
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_205              = &H801900CD&

' //
' // MessageId: BG_E_HTTP_ERROR_206
' //
' // MessageText:
' //
' //  The server fulfilled the partial GET request for the resource.
' //
%BG_E_HTTP_ERROR_206              = &H801900CE&

' //
' // MessageId: BG_E_HTTP_ERROR_300
' //
' // MessageText:
' //
' //  The server could not return the requested data.
' //
%BG_E_HTTP_ERROR_300              = &H8019012C&

' //
' // MessageId: BG_E_HTTP_ERROR_301
' //
' // MessageText:
' //
' //  The requested resource was assigned to a new permanent Uniform Resource Identifier (URI), and any future references to this resource should use one of the returned URIs.
' //
%BG_E_HTTP_ERROR_301              = &H8019012D&

' //
' // MessageId: BG_E_HTTP_ERROR_302
' //
' // MessageText:
' //
' //  The requested resource was assigned a different Uniform Resource Identifier (URI). This change is temporary.
' //
%BG_E_HTTP_ERROR_302              = &H8019012E&

' //
' // MessageId: BG_E_HTTP_ERROR_303
' //
' // MessageText:
' //
' //  The response to the request is under a different Uniform Resource Identifier (URI) and must be retrieved using a GET method on that resource.
' //
%BG_E_HTTP_ERROR_303              = &H8019012F&

' //
' // MessageId: BG_E_HTTP_ERROR_304
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_304              = &H80190130&

' //
' // MessageId: BG_E_HTTP_ERROR_305
' //
' // MessageText:
' //
' //  The requested resource must be accessed through the proxy given by the location field.
' //
%BG_E_HTTP_ERROR_305              = &H80190131&

' //
' // MessageId: BG_E_HTTP_ERROR_307
' //
' // MessageText:
' //
' //  The URL has been temporarily relocated. Try again later.
' //
%BG_E_HTTP_ERROR_307              = &H80190133&

' //
' // MessageId: BG_E_HTTP_ERROR_400
' //
' // MessageText:
' //
' //  The server cannot process the request because the syntax is not valid.
' //
%BG_E_HTTP_ERROR_400              = &H80190190&

' //
' // MessageId: BG_E_HTTP_ERROR_401
' //
' // MessageText:
' //
' //  The requested resource requires user authentication.
' //
%BG_E_HTTP_ERROR_401              = &H80190191&

' //
' // MessageId: BG_E_HTTP_ERROR_402
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_402              = &H80190192&

' //
' // MessageId: BG_E_HTTP_ERROR_403
' //
' // MessageText:
' //
' //  The client does not have sufficient access rights to the requested server object.
' //
%BG_E_HTTP_ERROR_403              = &H80190193&

' //
' // MessageId: BG_E_HTTP_ERROR_404
' //
' // MessageText:
' //
' //  The requested URL does not exist on the server.
' //
%BG_E_HTTP_ERROR_404              = &H80190194&

' //
' // MessageId: BG_E_HTTP_ERROR_405
' //
' // MessageText:
' //
' //  The method used is not allowed.
' //
%BG_E_HTTP_ERROR_405              = &H80190195&

' //
' // MessageId: BG_E_HTTP_ERROR_406
' //
' // MessageText:
' //
' //  No responses acceptable to the client were found.
' //
%BG_E_HTTP_ERROR_406              = &H80190196&

' //
' // MessageId: BG_E_HTTP_ERROR_407
' //
' // MessageText:
' //
' //  Proxy authentication is required.
' //
%BG_E_HTTP_ERROR_407              = &H80190197&

' //
' // MessageId: BG_E_HTTP_ERROR_408
' //
' // MessageText:
' //
' //  The server timed out waiting for the request.
' //
%BG_E_HTTP_ERROR_408              = &H80190198&

' //
' // MessageId: BG_E_HTTP_ERROR_409
' //
' // MessageText:
' //
' //  The request could not be completed because of a conflict with the current state of the resource. The user should resubmit the request with more information.
' //
%BG_E_HTTP_ERROR_409              = &H80190199&

' //
' // MessageId: BG_E_HTTP_ERROR_410
' //
' // MessageText:
' //
' //  The requested resource is not currently available at the server, and no forwarding address is known.
' //
%BG_E_HTTP_ERROR_410              = &H8019019A&

' //
' // MessageId: BG_E_HTTP_ERROR_411
' //
' // MessageText:
' //
' //  The server cannot accept the request without a defined content length.
' //
%BG_E_HTTP_ERROR_411              = &H8019019B&

' //
' // MessageId: BG_E_HTTP_ERROR_412
' //
' // MessageText:
' //
' //  The precondition given in one or more of the request header fields evaluated to false when it was tested on the server.
' //
%BG_E_HTTP_ERROR_412              = &H8019019C&

' //
' // MessageId: BG_E_HTTP_ERROR_413
' //
' // MessageText:
' //
' //  The server cannot process the request because the request entity is too large.
' //
%BG_E_HTTP_ERROR_413              = &H8019019D&

' //
' // MessageId: BG_E_HTTP_ERROR_414
' //
' // MessageText:
' //
' //  The server cannot process the request because the request Uniform Resource Identifier (URI) is longer than the server can interpret.
' //
%BG_E_HTTP_ERROR_414              = &H8019019E&

' //
' // MessageId: BG_E_HTTP_ERROR_415
' //
' // MessageText:
' //
' //  The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_415              = &H8019019F&

' //
' // MessageId: BG_E_HTTP_ERROR_416
' //
' // MessageText:
' //
' //  The server could not satisfy the range request.
' //
%BG_E_HTTP_ERROR_416              = &H801901A0&

' //
' // MessageId: BG_E_HTTP_ERROR_417
' //
' // MessageText:
' //
' //  The server could not meet the expectation given in an Expect request-header field.
' //
%BG_E_HTTP_ERROR_417              = &H801901A1&

' //
' // MessageId: BG_E_HTTP_ERROR_449
' //
' // MessageText:
' //
' //   The server's response was not valid. The server was not following the defined protocol. Resume the job, and then Background Intelligent Transfer Service (BITS) will try again.
' //
%BG_E_HTTP_ERROR_449              = &H801901C1&

' //
' // MessageId: BG_E_HTTP_ERROR_500
' //
' // MessageText:
' //
' //  An unexpected condition prevented the server from fulfilling the request.
' //
%BG_E_HTTP_ERROR_500              = &H801901F4&

' //
' // MessageId: BG_E_HTTP_ERROR_501
' //
' // MessageText:
' //
' //  The server does not support the functionality required to fulfill the request.
' //
%BG_E_HTTP_ERROR_501              = &H801901F5&

' //
' // MessageId: BG_E_HTTP_ERROR_502
' //
' // MessageText:
' //
' //  The server, while acting as a gateway or proxy to fulfill the request, received an invalid response from the upstream server it accessed.
' //
%BG_E_HTTP_ERROR_502              = &H801901F6&

' //
' // MessageId: BG_E_HTTP_ERROR_503
' //
' // MessageText:
' //
' //  The service is temporarily overloaded.
' //
%BG_E_HTTP_ERROR_503              = &H801901F7&

' //
' // MessageId: BG_E_HTTP_ERROR_504
' //
' // MessageText:
' //
' //  The request was timed out waiting for a gateway.
' //
%BG_E_HTTP_ERROR_504              = &H801901F8&

' //
' // MessageId: BG_E_HTTP_ERROR_505
' //
' // MessageText:
' //
' //  The server does not support the HTTP protocol version that was used in the request message.
' //
%BG_E_HTTP_ERROR_505              = &H801901F9&

' //
' // Additional Background Intelligent Transfer Service (BITS) mc entries
' // Reserved range is = &H4000 to = &H4100
' //
' //
' // MessageId: BITS_MC_JOB_CANCELLED
' //
' // MessageText:
' //
' //  The administrator %4 canceled job "%2" on behalf of %3.  The job ID was %1.
' //
%BITS_MC_JOB_CANCELLED            = &H80194000&

' //
' // MessageId: BITS_MC_FILE_DELETION_FAILED
' //
' // MessageText:
' //
' //  While canceling job "%2", BITS was not able to remove the temporary files listed below.
' //  If you can delete them, then you will regain some disk space.  The job ID was %1.%\
' //
' //  %3
' //
%BITS_MC_FILE_DELETION_FAILED     = &H80194001&

' //
' // MessageId: BITS_MC_FILE_DELETION_FAILED_MORE
' //
' // MessageText:
' //
' //  While canceling job "%2", BITS was not able to remove the temporary files listed below.
' //  If you can delete them, then you will regain some disk space.  The job ID was %1. %\
' //
' //  %3
' //  %\
' //  Due to space limitations, not all files are listed here.  Check for additional files of the form BITxxx.TMP in the same directory.
' //
%BITS_MC_FILE_DELETION_FAILED_MORE = &H80194002&

' //
' // MessageId: BITS_MC_JOB_PROPERTY_CHANGE
' //
' // MessageText:
' //
' //  The administrator %3 modified the %4 property of job "%2".  The job ID was %1.
' //
%BITS_MC_JOB_PROPERTY_CHANGE      = &H80194003&

' //
' // MessageId: BITS_MC_JOB_TAKE_OWNERSHIP
' //
' // MessageText:
' //
' //  The administrator %4 took ownership of job "%2" from %3.  The job ID was %1.
' //
%BITS_MC_JOB_TAKE_OWNERSHIP       = &H80194004&

' //
' // MessageId: BITS_MC_JOB_SCAVENGED
' //
' // MessageText:
' //
' //  Job "%2" owned by %3 was canceled after being inactive for more than %4 days.  The job ID was %1.
' //
%BITS_MC_JOB_SCAVENGED            = &H80194005&

' //
' // MessageId: BITS_MC_JOB_NOTIFICATION_FAILURE
' //
' // MessageText:
' //
' //  Job "%2" owned by %3 failed to notify its associated application.  BITS will retry in %4 minutes.  The job ID was %1.
' //
%BITS_MC_JOB_NOTIFICATION_FAILURE = &H80194006&

' //
' // MessageId: BITS_MC_STATE_FILE_CORRUPT
' //
' // MessageText:
' //
' //  The BITS job list is not in a recognized format.  It may have been created by a different version of BITS.  The job list has been cleared.
' //
%BITS_MC_STATE_FILE_CORRUPT       = &H80194007&

' //
' // MessageId: BITS_MC_FAILED_TO_START
' //
' // MessageText:
' //  The BITS server failed to start. Try restarting the service at a later time.
' //
%BITS_MC_FAILED_TO_START          = &H80194008&

'//
'// MessageId: BITS_MC_FATAL_IGD_ERROR
'//
'// MessageText:
'//
'// BITS has hit a fatal error communicating with an Internet Gateway Device.  Please check that the device is functioning properly. BITS will not attempt to use this device until the next system reboot.
'//
%BITS_MC_FATAL_IGD_ERROR          = &H80194009&

'//
'// MessageId: BITS_MC_PEERCACHING_PORT
'//
'// MessageText:
'//
'// BITS Peer-caching protocol
'//
%BITS_MC_PEERCACHING_PORT         = &H8019400A&

'//
'// MessageId: BITS_MC_WSD_PORT
'//
'// MessageText:
'//
'// Web Services-Discovery protocol
'//
%BITS_MC_WSD_PORT                 = &H8019400B&
