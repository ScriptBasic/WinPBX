' ########################################################################################
' Microsoft Windows
' File: HttpFilt.inc
' Contents: Microsoft HTTP filter extension info
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTTPFILT_INC = 1

'//
'// Define ULONG_PTR if necessary
'//

'#if !defined(__midl) && defined(_X86_) && _MSC_VER >= 1300
'#define _W64 __w64
'#else
'#define _W64
'#endif

'//
'// The INT_PTR is guaranteed to be the same size as a pointer.  Its
'// size with change with pointer size (32/64).  It should be used
'// anywhere that a pointer is cast to an integer type. UINT_PTR is
'// the unsigned variation.
'//
'// __int3264 is intrinsic to 64b MIDL but not to old MIDL or to C compiler.
'//
'#if ( 501 < __midl )

'    typedef unsigned __int3264 ULONG_PTR, *PULONG_PTR;

'#else  // midl64
'// old midl and C++ compiler

'#if defined(_WIN64)
'    typedef unsigned __int64 ULONG_PTR, *PULONG_PTR;
'#else
'    typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;
'#endif
'#endif // midl64


'//
'//  Current version of the filter spec is 7.0
'//

'#define HTTP_FILTER_REVISION    MAKELONG( 5, 7 )
%HTTP_FILTER_REVISION    = &H70005&

%SF_MAX_USERNAME         = 256 + 1
%SF_MAX_PASSWORD         = 256 + 1
%SF_MAX_AUTH_TYPE        =  32 + 1

%SF_MAX_FILTER_DESC_LEN  = 256 + 1


'//
'//  These values can be used with the pfnSFCallback function supplied in
'//  the filter context structure
'//

' enum SF_REQ_TYPE
'//
'//  Sends a complete HTTP server response header including
'//  the status, server version, message time and MIME version.
'//
'//  Server extensions should append other information at the end,
'//  such as Content-type, Content-length etc followed by an extra
'//  '\r\n'.
'//
'//  pData - Zero terminated string pointing to optional
'//      status string (i.e., "401 Access Denied") or NULL for
'//      the default response of "200 OK".
'//
'//  ul1 - Zero terminated string pointing to optional data to be
'//      appended and set with the header.  If NULL, the header will
'//      be terminated with an empty line.
'//

%SF_REQ_SEND_RESPONSE_HEADER = 0

'//
'//  If the server denies the HTTP request, add the specified headers
'//  to the server error response.
'//
'//  This allows an authentication filter to advertise its services
'//  w/o filtering every request.  Generally the headers will be
'//  WWW-Authenticate headers with custom authentication schemes but
'//  no restriction is placed on what headers may be specified.
'//
'//  pData - Zero terminated string pointing to one or more header lines
'//      with terminating '\r\n'.
'//

%SF_REQ_ADD_HEADERS_ON_DENIAL = 1

'//
'//  Only used by raw data filters that return SF_STATUS_READ_NEXT
'//
'//  ul1 - size in bytes for the next read
'//

%SF_REQ_SET_NEXT_READ_SIZE = 2

'//
'//  Used to indicate this request is a proxy request
'//
'//  ul1 - The proxy flags to set
'//      0x00000001 - This is a HTTP proxy request
'//
'//

%SF_REQ_SET_PROXY_INFO = 3

'//
'//  Returns the connection ID contained in the ConnID field of an
'//  ISAPI Application's Extension Control Block.  This value can be used
'//  as a key to cooridinate shared data between Filters and Applications.
'//
'//  pData - Pointer to DWORD that receives the connection ID.
'//

%SF_REQ_GET_CONNID = 4

'//
'// Used to set a SSPI security context + impersonation token
'// derived from a client certificate.
'//
'// pData - certificate info ( PHTTP_FILTER_CERTIFICATE_INFO )
'// ul1 - CtxtHandle*
'// ul2 - impersonation handle
'//

%SF_REQ_SET_CERTIFICATE_INFO = 5

'//
'// Used to get an IIS property
'// as defined in SF_PROPERTY_IIS
'//
'// ul1 - Property ID
'//

%SF_REQ_GET_PROPERTY = 6

'//
'// Used to normalize an URL
'//
'// pData - URL to normalize
'//

%SF_REQ_NORMALIZE_URL = 7

'//
'// Disable Notifications
'//
'// ul1 - notifications to disable
'//

%SF_REQ_DISABLE_NOTIFICATIONS = 8


' enum SF_PROPERTY_IIS
%SF_PROPERTY_SSL_CTXT        = 0
%SF_PROPERTY_INSTANCE_NUM_ID = 1


'//
'//  These values are returned by the filter entry point when a new request is
'//  received indicating their interest in this particular request
'//

' enum SF_STATUS_TYPE
'//
'//  The filter has handled the HTTP request.  The server should disconnect
'//  the session.
'//

%SF_STATUS_REQ_FINISHED = &H8000000???

'//
'//  Same as SF_STATUS_FINISHED except the server should keep the TCP
'//  session open if the option was negotiated
'//

%SF_STATUS_REQ_FINISHED_KEEP_CONN = &H8000001???

'//
'//  The next filter in the notification chain should be called
'//

%SF_STATUS_REQ_NEXT_NOTIFICATION = &H8000002???

'//
'//  This filter handled the notification.  No other handles should be
'//  called for this particular notification type
'//

%SF_STATUS_REQ_HANDLED_NOTIFICATION = &H8000003???

'//
'//  An error occurred.  The server should use GetLastError() and indicate
'//  the error to the client
'//

%SF_STATUS_REQ_ERROR = &H8000004???

'//
'//  The filter is an opaque stream filter and we're negotiating the
'//  session parameters.  Only valid for raw read notification.
'//

%SF_STATUS_REQ_READ_NEXT = &H8000005???

'//
'//  pvNotification points to this structure for all request notification types
'//

'//  Server callbacks

'FUNCTION GetServerVariable ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF lpszVariableName AS ASCIIZ _         ' LPSTR
' , BYVAL lpvBuffer AS DWORD _                 ' LPVOID
' , BYREF lpdwSize AS DWORD _                  ' LPDWORD
' ) AS LONG                                    ' BOOL

'FUNCTION AddResponseHeaders ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF lpszHeaders AS ASCIIZ _              ' LPSTR
' , BYVAL dwReserved AS DWORD _                ' DWORD
' ) AS LONG                                    ' BOOL

'FUNCTION WriteClient ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYVAL Buffer AS DWORD _                    ' LPVOID
' , BYREF lpdwBytes AS DWORD _                 ' LPDWORD
' , BYVAL dwReserved AS DWORD _                ' DWORD
' ) AS LONG                                    ' BOOL

'FUNCTION AllocMem ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYVAL cbSize AS DWORD _                    ' DWORD
' , BYVAL dwReserved AS DWORD _                ' DWORD
' ) AS DWORD                                   ' VOID *

'FUNCTION ServerSupportFunction ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF sfReq AS DWORD _                     ' enum SF_REQ_TYPE
' , BYVAL pData AS DWORD _                     ' PVOID
' , BYVAL ul1 AS DWORD _                       ' ULONG_PTR
' , BYVAL ul2 AS DWORD _                       ' ULONG_PTR
' ) AS LONG                                    ' BOOL

' // Size = 44 bytes
TYPE HTTP_FILTER_CONTEXT DWORD
   cbSize                AS DWORD   ' DWORD
   ' //  This is the structure revision level.
   Revision              AS DWORD   ' DWORD
   ' //  Private context information for the server.
   ServerContext         AS DWORD   ' PVOID
   ulReserved            AS DWORD   ' DWORD
   ' //  TRUE if this request is coming over a secure port
   fIsSecurePort         AS LONG    ' BOOL
   ' //  A context that can be used by the filter
   pFilterContext        AS DWORD   ' PVOID
   ' //  Server callbacks
   GetServerVariable     AS DWORD
   AddResponseHeaders    AS DWORD
   WriteClient           AS DWORD
   AllocMem              AS DWORD
   ServerSupportFunction AS DWORD
END TYPE

'//
'//  This structure is the notification info for the read and send raw data
'//  notification types
'//

' // Size = 16 bytes
TYPE HTTP_FILTER_RAW_DATA DWORD
   ' //  This is a pointer to the data for the filter to process.
   pvInData   AS DWORD   ' PVOID
   cbInData   AS DWORD   ' DWORD // Number of valid data bytes
   cbInBuffer AS DWORD   ' DWORD // Total size of buffer
   dwReserved AS DWORD
END TYPE

'//
'//  This structure is the notification info for when the server is about to
'//  process the client headers
'//

'FUNCTION GetHeader ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF lpszName AS ASCIIZ _                 ' LPSTR
' , BYVAL lpvBuffer AS DWORD _                 ' LPVOID
' , BYVAL lpdwSize AS DWORD _                  ' LPDWORD
' ) AS LONG                                    ' BOOL

'FUNCTION SetHeader ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF lpszName AS ASCIIZ _                 ' LPSTR
' , BYVAL lpszValue AS ASCIIZ _                ' LPSTR
' ) AS LONG                                    ' BOOL

'FUNCTION AddHeader ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYREF lpszName AS ASCIIZ _                 ' LPSTR
' , BYVAL lpszValue AS ASCIIZ _                ' LPSTR
' ) AS LONG                                    ' BOOL

' // Size = 20 bytes
TYPE HTTP_FILTER_PREPROC_HEADERS DWORD
   ' //  For SF_NOTIFY_PREPROC_HEADERS, retrieves the specified header value.
   ' //  Header names should include the trailing ':'.  The special values
   ' //  'method', 'url' and 'version' can be used to retrieve the individual
   ' //  portions of the request line
   GetHeader  AS DWORD
   ' //  Replaces this header value to the specified value.  To delete a header,
   ' //  specified a value of '\0'.
   SetHeader  AS DWORD
   ' //  Adds the specified header and value
   AddHeader  AS DWORD
   HttpStatus AS DWORD   ' DWORD // New in 4.0, status for SEND_RESPONSE
   dwReserved AS DWORD   ' DWORD // New in 4.0
END TYPE

'//
'//  Authentication information for this request.
'//

' // Size = 16 bytes
TYPE HTTP_FILTER_AUTHENT DWORD
   ' //  Pointer to username and password, empty strings for the anonymous user
   ' //  Client's can overwrite these buffers which are guaranteed to be at
   ' //  least SF_MAX_USERNAME and SF_MAX_PASSWORD bytes large.
   pszUser        AS ASCIIZ PTR   ' CHAR *
   cbUserBuff     AS DWORD        ' DWORD
   pszPassword    AS ASCIIZ PTR   ' CHAR *
   cbPasswordBuff AS DWORD        ' DWORD
END TYPE


'//
'//  Indicates the server is going to use the specific physical mapping for
'//  the specified URL.  Filters can modify the physical path in place.
'//

' // Size = 12 bytes
TYPE HTTP_FILTER_URL_MAP DWORD
   pszURL          AS ASCIIZ PTR   ' const CHAR *
   pszPhysicalPath AS ASCIIZ PTR   ' CHAR *
   cbPathBuff      AS DWORD        ' DWORD
END TYPE

'//
'//  Indicates the server is going to use the specific physical mapping for
'//  the specified URL.  Filters can modify the physical path in place.
'//
'//  Additional members beyond those from HTTP_FILTER_URL_MAP are
'//  informational.
'//

' // Size = 28 bytes
TYPE HTTP_FILTER_URL_MAP_EX DWORD
   pszURL            AS ASCIIZ PTR   ' const CHAR *
   pszPhysicalPath   AS ASCIIZ PTR   ' CHAR *
   cbPathBuff        AS DWORD   ' DWORD
   ' // The AccessPerm metabase property that applies to this URL
   dwFlags           AS DWORD   ' DWORD
   ' // Number of matching characters in physical path corresponding
   ' // to the metabase node that applies.
   cchMatchingPath   AS DWORD   ' DWORD
   ' // Number of matching characters in the URL corresponding
   ' // to the metabase node that applies.
   cchMatchingURL    AS DWORD   ' DWORD
   ' // The physical path of the dll or exe that to which this
   ' // URL is script mapped.  This member will be NULL if no
   ' // script map applies.
   pszScriptMapEntry AS ASCIIZ PTR   ' const CHAR *
END TYPE

'//
'//  Bitfield indicating the requested resource has been denied by the server due
'//  to a logon failure, an ACL on a resource, an ISAPI Filter or an
'//  ISAPI Application/CGI Application.
'//
'//  SF_DENIED_BY_CONFIG can appear with SF_DENIED_LOGON if the server
'//  configuration did not allow the user to logon.
'//

%SF_DENIED_LOGON             = &H00000001???
%SF_DENIED_RESOURCE          = &H00000002???
%SF_DENIED_FILTER            = &H00000004???
%SF_DENIED_APPLICATION       = &H00000008???

%SF_DENIED_BY_CONFIG         = &H00010000???

' // Size = 12 bytes
TYPE HTTP_FILTER_ACCESS_DENIED DWORD
   pszURL          AS ASCIIZ PTR   ' const CHAR * // Requesting URL
   pszPhysicalPath AS ASCIIZ PTR   ' const CHAR * Physical path of resource
   dwReason        AS DWORD        ' DWORD // Bitfield of SF_DENIED flags
END TYPE

'//
'//  The log information about to be written to the server log file.  The
'//  string pointers can be replaced but the memory must remain valid until
'//  the next notification
'//

' // Size = 44 bytes
TYPE HTTP_FILTER_LOG DWORD
   pszClientHostName   AS ASCIIZ PTR   ' const CHAR *
   pszClientUserName   AS ASCIIZ PTR   ' const CHAR *
   pszServerName       AS ASCIIZ PTR   ' const CHAR *
   pszOperation        AS ASCIIZ PTR   ' const CHAR *
   pszTarget           AS ASCIIZ PTR   ' const CHAR *
   pszParameters       AS ASCIIZ PTR   ' const CHAR *
   dwHttpStatus        AS DWORD        ' DWORD
   dwWin32Status       AS DWORD        ' DWORD
   dwBytesSent         AS DWORD        ' DWORD // IIS 4.0 and later
   dwBytesRecvd        AS DWORD        ' DWORD // IIS 4.0 and later
   msTimeForProcessing AS DWORD        ' DWORD // IIS 4.0 and later
END TYPE

'//
'// Called once the client request has been authenticated.
'//

'FUNCTION GetUserToken ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' struct _HTTP_FILTER_CONTEXT *
' , BYVAL phToken AS DWORD _                   ' HANDLE *
' ) AS LONG                                    ' BOOL

' // Size = 28 bytes
TYPE HTTP_FILTER_AUTH_COMPLETE_INFO DWORD
   ' //  For SF_NOTIFY_AUTH_COMPLETE, retrieves the specified header value.
   ' //  Header names should include the trailing ':'.  The special values
   ' //  'method', 'url' and 'version' can be used to retrieve the individual
   ' //  portions of the request line
   GetHeader    AS DWORD
   ' //  Replaces this header value to the specified value.  To delete a header,
   ' //  specified a value of '\0'.
   SetHeader    AS DWORD
   ' //  Adds the specified header and value
   AddHeader    AS DWORD
   ' //  Get the authenticated user impersonation token
   GetUserToken AS DWORD
   '//  Status code to use when sending response
   HttpStatus   AS DWORD   ' DWORD
   ' //  Determines whether to reset auth if URL changed
   fResetAuth   AS LONG   ' BOOL
   ' //  Reserved
   dwReserved   AS DWORD   ' DWORD
END TYPE

'//
'//  Notification Flags
'//
'//  SF_NOTIFY_SECURE_PORT
'//  SF_NOTIFY_NONSECURE_PORT
'//
'//      Indicates whether the application wants to be notified for transactions
'//      that are happenning on the server port(s) that support data encryption
'//      (such as PCT and SSL), on only the non-secure port(s) or both.
'//
'//  SF_NOTIFY_READ_RAW_DATA
'//
'//      Applications are notified after the server reads a block of memory
'//      from the client but before the server does any processing on the
'//      block.  The data block may contain HTTP headers and entity data.
'//
'//
'//

%SF_NOTIFY_SECURE_PORT               = &H00000001???
%SF_NOTIFY_NONSECURE_PORT            = &H00000002???

%SF_NOTIFY_READ_RAW_DATA             = &H00008000???
%SF_NOTIFY_PREPROC_HEADERS           = &H00004000???
%SF_NOTIFY_AUTHENTICATION            = &H00002000???
%SF_NOTIFY_URL_MAP                   = &H00001000???
%SF_NOTIFY_ACCESS_DENIED             = &H00000800???
%SF_NOTIFY_SEND_RESPONSE             = &H00000040???
%SF_NOTIFY_SEND_RAW_DATA             = &H00000400???
%SF_NOTIFY_LOG                       = &H00000200???
%SF_NOTIFY_END_OF_REQUEST            = &H00000080???
%SF_NOTIFY_END_OF_NET_SESSION        = &H00000100???
%SF_NOTIFY_AUTH_COMPLETE             = &H04000000???

'//
'//  Filter ordering flags
'//
'//  Filters will tend to be notified by their specified
'//  ordering.  For ties, notification order is determined by load order.
'//
'//  SF_NOTIFY_ORDER_HIGH - Authentication or data transformation filters
'//  SF_NOTIFY_ORDER_MEDIUM
'//  SF_NOTIFY_ORDER_LOW  - Logging filters that want the results of any other
'//                      filters might specify this order.
'//

%SF_NOTIFY_ORDER_HIGH               = &H00080000???
%SF_NOTIFY_ORDER_MEDIUM             = &H00040000???
%SF_NOTIFY_ORDER_LOW                = &H00020000???
%SF_NOTIFY_ORDER_DEFAULT            = %SF_NOTIFY_ORDER_LOW

%SF_NOTIFY_ORDER_MASK               = %SF_NOTIFY_ORDER_HIGH   OR _
                                      %SF_NOTIFY_ORDER_MEDIUM OR _
                                      %SF_NOTIFY_ORDER_LOW

'//
'//  Filter version information, passed to GetFilterVersion
'//

' // Size = 272 bytes
TYPE HTTP_FILTER_VERSION DWORD
   ' //  Version of the spec the server is using
   dwServerFilterVersion AS DWORD   ' DWORD
   ' //  Fields specified by the client
   dwFilterVersion       AS DWORD   ' DWORD
   lpszFilterDesc        AS ASCIIZ * %SF_MAX_FILTER_DESC_LEN   ' CHAR
   dwFlags               AS DWORD   ' DWORD
END TYPE

'//
'//  A filter DLL's entry point looks like this.  The return code should be
'//  an SF_STATUS_TYPE
'//
'//  NotificationType - Type of notification
'//  pvNotification - Pointer to notification specific data
'//

'FUNCTION HttpFilterProc ( _
'   BYREF pfc AS HTTP_FILTER_CONTEXT _         ' HTTP_FILTER_CONTEXT *
' , BYVAL NotificationType AS DWORD _          ' DWORD
' , BYVAL pvNotification AS DWORD _            ' VOID *
' ) AS DWORD                                   ' DWORD

'FUNCTION GetFilterVersion ( _
'   BYREF pVer AS HTTP_FILTER_CONTEXT _        ' HTTP_FILTER_CONTEXT *
' ) AS LONG                                    ' BOOL

'FUNCTION TerminateFilter ( _
'   BYVAL dwFlags DWORD _                      ' DWORD
' ) AS LONG                                    ' BOOL
