' ########################################################################################
' Microsoft Windows
' File: HttpExt.inc
' Contents: Structure definitions and prototypes for the HTTP Server Extension interface
' used to build ISAPI Applications
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTTPEXT_INC = 1

#INCLUDE ONCE "windows.inc"

'/************************************************************
' *   Manifest Constants
' ************************************************************/

%HSE_VERSION_MAJOR        =   7     ' // major version of this spec
%HSE_VERSION_MINOR        =   5     ' // minor version of this spec
%HSE_LOG_BUFFER_LEN       =  80
%HSE_MAX_EXT_DLL_NAME_LEN = 256

'#define   HSE_VERSION     MAKELONG( HSE_VERSION_MINOR, HSE_VERSION_MAJOR )
%HSE_VERSION              = 7

'//
'// the following are the status codes returned by the Extension DLL
'//

%HSE_STATUS_SUCCESS                       = 1
%HSE_STATUS_SUCCESS_AND_KEEP_CONN         = 2
%HSE_STATUS_PENDING                       = 3
%HSE_STATUS_ERROR                         = 4

'//
'// The following are the values to request services with the
'//   ServerSupportFunction().
'//  Values from 0 to 1000 are reserved for future versions of the interface

%HSE_REQ_BASE                             = 0
%HSE_REQ_SEND_URL_REDIRECT_RESP           = %HSE_REQ_BASE + 1
%HSE_REQ_SEND_URL                         = %HSE_REQ_BASE + 2
%HSE_REQ_SEND_RESPONSE_HEADER             = %HSE_REQ_BASE + 3
%HSE_REQ_DONE_WITH_SESSION                = %HSE_REQ_BASE + 4
%HSE_REQ_END_RESERVED                     = 1000

'//
'//  These are Microsoft specific extensions
'//

%HSE_REQ_MAP_URL_TO_PATH                  = %HSE_REQ_END_RESERVED+1
%HSE_REQ_GET_SSPI_INFO                    = %HSE_REQ_END_RESERVED+2
%HSE_APPEND_LOG_PARAMETER                 = %HSE_REQ_END_RESERVED+3
%HSE_REQ_IO_COMPLETION                    = %HSE_REQ_END_RESERVED+5
%HSE_REQ_TRANSMIT_FILE                    = %HSE_REQ_END_RESERVED+6
%HSE_REQ_REFRESH_ISAPI_ACL                = %HSE_REQ_END_RESERVED+7
%HSE_REQ_IS_KEEP_CONN                     = %HSE_REQ_END_RESERVED+8
%HSE_REQ_ASYNC_READ_CLIENT                = %HSE_REQ_END_RESERVED+10
%HSE_REQ_GET_IMPERSONATION_TOKEN          = %HSE_REQ_END_RESERVED+11
%HSE_REQ_MAP_URL_TO_PATH_EX               = %HSE_REQ_END_RESERVED+12
%HSE_REQ_ABORTIVE_CLOSE                   = %HSE_REQ_END_RESERVED+14
%HSE_REQ_GET_CERT_INFO_EX                 = %HSE_REQ_END_RESERVED+15
%HSE_REQ_SEND_RESPONSE_HEADER_EX          = %HSE_REQ_END_RESERVED+16
%HSE_REQ_CLOSE_CONNECTION                 = %HSE_REQ_END_RESERVED+17
%HSE_REQ_IS_CONNECTED                     = %HSE_REQ_END_RESERVED+18
%HSE_REQ_MAP_UNICODE_URL_TO_PATH          = %HSE_REQ_END_RESERVED+23
%HSE_REQ_MAP_UNICODE_URL_TO_PATH_EX       = %HSE_REQ_END_RESERVED+24
%HSE_REQ_EXEC_UNICODE_URL                 = %HSE_REQ_END_RESERVED+25
%HSE_REQ_EXEC_URL                         = %HSE_REQ_END_RESERVED+26
%HSE_REQ_GET_EXEC_URL_STATUS              = %HSE_REQ_END_RESERVED+27
%HSE_REQ_SEND_CUSTOM_ERROR                = %HSE_REQ_END_RESERVED+28
%HSE_REQ_IS_IN_PROCESS                    = %HSE_REQ_END_RESERVED+30
%HSE_REQ_REPORT_UNHEALTHY                 = %HSE_REQ_END_RESERVED+32
%HSE_REQ_NORMALIZE_URL                    = %HSE_REQ_END_RESERVED+33
%HSE_REQ_VECTOR_SEND                      = %HSE_REQ_END_RESERVED+37
%HSE_REQ_GET_ANONYMOUS_TOKEN              = %HSE_REQ_END_RESERVED+38
%HSE_REQ_GET_CACHE_INVALIDATION_CALLBACK  = %HSE_REQ_END_RESERVED+40
%HSE_REQ_GET_UNICODE_ANONYMOUS_TOKEN      = %HSE_REQ_END_RESERVED+41
%HSE_REQ_GET_TRACE_INFO                   = %HSE_REQ_END_RESERVED+42
%HSE_REQ_SET_FLUSH_FLAG                   = %HSE_REQ_END_RESERVED+43
%HSE_REQ_GET_TRACE_INFO_EX                = %HSE_REQ_END_RESERVED+44
%HSE_REQ_RAISE_TRACE_EVENT                = %HSE_REQ_END_RESERVED+45
%HSE_REQ_GET_CONFIG_OBJECT                = %HSE_REQ_END_RESERVED+46
%HSE_REQ_GET_WORKER_PROCESS_SETTINGS      = %HSE_REQ_END_RESERVED+47
%HSE_REQ_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK = %HSE_REQ_END_RESERVED+48
%HSE_REQ_CANCEL_IO                        = %HSE_REQ_END_RESERVED+49
%HSE_REQ_GET_CHANNEL_BINDING_TOKEN        = %HSE_REQ_END_RESERVED+50

'//
'//  Bit Flags for TerminateExtension
'//
'//    HSE_TERM_ADVISORY_UNLOAD - Server wants to unload the extension,
'//          extension can return TRUE if OK, FALSE if the server should not
'//          unload the extension
'//
'//    HSE_TERM_MUST_UNLOAD - Server indicating the extension is about to be
'//          unloaded, the extension cannot refuse.
'//

%HSE_TERM_ADVISORY_UNLOAD                   = &H00000001???
%HSE_TERM_MUST_UNLOAD                       = &H00000002???

'//
'// Flags for IO Functions, supported for IO Funcs.
'//  TF means ServerSupportFunction( HSE_REQ_TRANSMIT_FILE)
'//

%HSE_IO_SYNC                      = &H00000001???   ' // for WriteClient
%HSE_IO_ASYNC                     = &H00000002???   ' // for WriteClient/TF/EU
%HSE_IO_DISCONNECT_AFTER_SEND     = &H00000004???   ' // for TF
%HSE_IO_SEND_HEADERS              = &H00000008???   ' // for TF
%HSE_IO_NODELAY                   = &H00001000???   ' // turn off nagling

'//
'// These three are only used by VectorSend
'//

%HSE_IO_FINAL_SEND                = &H00000010???
%HSE_IO_CACHE_RESPONSE            = &H00000020???
%HSE_IO_TRY_SKIP_CUSTOM_ERRORS    = &H00000040???


'/************************************************************
' *   Type Definitions
' ************************************************************/

'typedef   LPVOID          HCONN;

'//
'// structure passed to GetExtensionVersion()
'//

' // Size = 260 bytes
TYPE HSE_VERSION_INFO DWORD
   dwExtensionVersion AS DWORD                                ' DWORD
   lpszExtensionDesc  AS ASCIIZ * %HSE_MAX_EXT_DLL_NAME_LEN   ' CHAR
END TYPE


'//
'// structure passed to extension procedure on a new request
'//
'typedef struct _EXTENSION_CONTROL_BLOCK {

'    DWORD     cbSize;                 // size of this struct.
'    DWORD     dwVersion;              // version info of this spec
'    HCONN     ConnID;                 // Context number not to be modified!
'    DWORD     dwHttpStatusCode;       // HTTP Status code
'    CHAR      lpszLogData[HSE_LOG_BUFFER_LEN];// null terminated log info specific to this Extension DLL

'    LPSTR     lpszMethod;             // REQUEST_METHOD
'    LPSTR     lpszQueryString;        // QUERY_STRING
'    LPSTR     lpszPathInfo;           // PATH_INFO
'    LPSTR     lpszPathTranslated;     // PATH_TRANSLATED

'    DWORD     cbTotalBytes;           // Total bytes indicated from client
'    DWORD     cbAvailable;            // Available number of bytes
'    LPBYTE    lpbData;                // pointer to cbAvailable bytes

'    LPSTR     lpszContentType;        // Content type of client data

'    BOOL (WINAPI * GetServerVariable) ( HCONN       hConn,
'                                        LPSTR       lpszVariableName,
'                                        LPVOID      lpvBuffer,
'                                        LPDWORD     lpdwSize );

'    BOOL (WINAPI * WriteClient)  ( HCONN      ConnID,
'                                   LPVOID     Buffer,
'                                   LPDWORD    lpdwBytes,
'                                   DWORD      dwReserved );

'    BOOL (WINAPI * ReadClient)  ( HCONN      ConnID,
'                                  LPVOID     lpvBuffer,
'                                  LPDWORD    lpdwSize );

'    BOOL (WINAPI * ServerSupportFunction)( HCONN      hConn,
'                                           DWORD      dwHSERequest,
'                                           LPVOID     lpvBuffer,
'                                           LPDWORD    lpdwSize,
'                                           LPDWORD    lpdwDataType );

'} EXTENSION_CONTROL_BLOCK, *LPEXTENSION_CONTROL_BLOCK;

' // Size = 144 bytes
TYPE EXTENSION_CONTROL_BLOCK DWORD
   cbSize                  AS DWORD                          ' DWORD  // size of this struct.
   dwVersion               AS DWORD                          ' DWORD  // version info of this spec
   ConnID                  AS DWORD                          ' HCONN  // Context number not to be modified!
   dwHttpStatusCode        AS DWORD                          ' DWORD  // HTTP Status code
   lpszLogData             AS ASCIIZ * %HSE_LOG_BUFFER_LEN   ' CHAR   // null terminated log info specific to this Extension DLL
   lpszMethod              AS ASCIIZ PTR                     ' LPSTR  // REQUEST_METHOD
   lpszQueryString         AS ASCIIZ PTR                     ' LPSTR  // QUERY_STRING
   lpszPathInfo            AS ASCIIZ PTR                     ' LPSTR  // PATH_INFO
   lpszPathTranslated      AS ASCIIZ PTR                     ' LPSTR  // PATH_TRANSLATED
   cbTotalBytes            AS DWORD                          ' DWORD  // Total bytes indicated from client
   cbAvailable             AS DWORD                          ' DWORD  // Available number of bytes
   lpbData                 AS BYTE PTR                       ' LPBYTE // pointer to cbAvailable bytes
   lpszContentType         AS ASCIIZ PTR                     ' LPSTR  // Content type of client data
   lpGetServerVariable     AS DWORD                          ' GetServerVariable function pointer
   lpWriteClient           AS DWORD                          ' WriteClient function pointer
   lpReadClient            AS DWORD                          ' ReadClient function pointer
   lpServerSupportFunction AS DWORD                          ' ServerSupportFunction function pointer
END TYPE

' ========================================================================================
' The GetServerVariable function retrieves information about an HTTP connection or about IIS itself.
' Some server variables, such as Request_Method and Content_Length are embedded in the
' EXTENSION_CONTROL_BLOCK structure. You can use GetServerVariable to obtain information
' about the request or server that is not included in EXTENSION_CONTROL_BLOCK.
' ========================================================================================
'    BOOL (WINAPI * GetServerVariable) ( HCONN       hConn,
'                                        LPSTR       lpszVariableName,
'                                        LPVOID      lpvBuffer,
'                                        LPDWORD     lpdwSize );
' ========================================================================================
DECLARE FUNCTION HSE_GetServerVariable ( _
   BYVAL hConn AS DWORD _                               ' __in HCONN       hConn
 , BYREF lpszVariableName AS ASCIIZ _                   ' __in LPSTR       lpszVariableName
 , BYREF lpvBuffer AS ANY _                             ' __in LPVOID      lpvBuffer
 , BYREF lpdwSize AS DWORD _                            ' __out LPDWORD    lpdwSize
 ) AS LONG                                              ' BOOL

' Call it as follows:
' CALL DWORD ECB.lpGetServerVariable USING HSE_GetServerVariable(ECB.ConnID, lpszVariableName, lpvBuffer, lpdwSize)
' where ECB is an EXTENSION_CONTROL_BLOCK structure.

' ========================================================================================
' The WriteClient function is a callback function that is supplied in the EXTENSION_CONTROL_BLOCK
' Structure for a request sent to the ISAPI extension. It sends the data present in the
' given buffer to the client that made the request.
' ========================================================================================
'    BOOL (WINAPI * WriteClient)  ( HCONN      ConnID,
'                                   LPVOID     Buffer,
'                                   LPDWORD    lpdwBytes,
'                                   DWORD      dwReserved );
' ========================================================================================
DECLARE FUNCTION HSE_WriteClient ( _
   BYVAL hConn AS DWORD _                               ' __in HCONN       ConnID
 , BYREF Buffer AS ANY _                                ' __in LPVOID      Buffer
 , BYREF lpdwBytes AS DWORD _                           ' __out LPDWORD    lpdwBytes
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD       dwReserved
 ) AS LONG                                              ' BOOL

' Call it as follows:
' CALL DWORD ECB.lpWriteClient USING HSE_WriteClient(ECB.ConnID, lpvBuffer, lpdwBytes, dwReserved)
' where ECB is an EXTENSION_CONTROL_BLOCK structure.

' ========================================================================================
' The ReadClient function reads data from the body of the client's HTTP request.
' ========================================================================================
'    BOOL (WINAPI * ReadClient)  ( HCONN      ConnID,
'                                  LPVOID     lpvBuffer,
'                                  LPDWORD    lpdwSize );
' ========================================================================================
DECLARE FUNCTION HSE_ReadClient ( _
   BYVAL hConn AS DWORD _                               ' __in HCONN       ConnID
 , BYREF Buffer AS ANY _                                ' __in LPVOID      Buffer
 , BYREF lpdwSize AS DWORD _                            ' __out LPDWORD    lpdwSize
 ) AS LONG                                              ' BOOL

' Call it as follows:
' CALL DWORD ECB.lpReadClient USING HSE_ReadClient(ECB.ConnID, Buffer, lpdwSize)
' where ECB is an EXTENSION_CONTROL_BLOCK structure.

' ========================================================================================
' The ServerSupportFunction function is a callback function that is supplied in the
' EXTENSION_CONTROL_BLOCK Structure that is associated with the current HTTP request.
' ServerSupportFunction can be used to perform a variety of tasks.
' ========================================================================================
'    BOOL (WINAPI * ServerSupportFunction)( HCONN      hConn,
'                                           DWORD      dwHSERequest,
'                                           LPVOID     lpvBuffer,
'                                           LPDWORD    lpdwSize,
'                                           LPDWORD    lpdwDataType );
' ========================================================================================
DECLARE FUNCTION HSE_ServerSupportFunction ( _
   BYVAL hConn AS DWORD _                               ' __in HCONN      hConn
 , BYVAL dwHSERequest AS DWORD _                        ' __in DWORD      dwHSERequest
 , BYREF lpvBuffer AS ANY _                             ' __in LPVOID     lpvBuffer
 , BYREF lpdwSize AS DWORD _                            ' __out LPDWORD   lpdwSize
 , BYREF lpdwDataType AS DWORD _                        ' __out LPDWORD   lpdwDataType
 ) AS LONG                                              ' BOOL

' Call it as follows:
' CALL DWORD ECB.lpServerSupportFunction USING HSE_ServerSupportFunction(ECB.ConnID, dwHSERequest, lpvBuffer, lpdwSize, lpdwDataType)
' where ECB is an EXTENSION_CONTROL_BLOCK structure.

'//
'//  Bit field of flags that can be on a virtual directory
'//

%HSE_URL_FLAGS_READ          = &H00000001???    ' // Allow for Read
%HSE_URL_FLAGS_WRITE         = &H00000002???    ' // Allow for Write
%HSE_URL_FLAGS_EXECUTE       = &H00000004???    ' // Allow for Execute
%HSE_URL_FLAGS_SSL           = &H00000008???    ' // Require SSL
%HSE_URL_FLAGS_DONT_CACHE    = &H00000010???    ' // Don't cache (vroot only)
%HSE_URL_FLAGS_NEGO_CERT     = &H00000020???    ' // Allow client SSL certs
%HSE_URL_FLAGS_REQUIRE_CERT  = &H00000040???    ' // Require client SSL certs
%HSE_URL_FLAGS_MAP_CERT      = &H00000080???    ' // Map SSL cert to NT account
%HSE_URL_FLAGS_SSL128        = &H00000100???    ' // Require 128 bit SSL
%HSE_URL_FLAGS_SCRIPT        = &H00000200???    ' // Allow for Script execution

%HSE_URL_FLAGS_MASK          = &H000003ff???

'//
'//  Structure for extended information on a URL mapping
'//

' // Size = 280 bytes
TYPE HSE_URL_MAPEX_INFO DWORD
   lpszPath        AS ASCIIZ * %MAX_PATH   ' CHAR  // Physical path root mapped to
   dwFlags         AS DWORD                ' DWORD // Flags associated with this URL path
   cchMatchingPath AS DWORD                ' DWORD // Number of matching characters in physical path
   cchMatchingURL  AS DWORD                ' DWORD // Number of matching characters in URL
   dwReserved1     AS DWORD                ' DWORD
   dwReserved2     AS DWORD                ' DWORD
END TYPE

' // Size = 532 bytes
TYPE HSE_UNICODE_URL_MAPEX_INFO DWORD
   lpszPath        AS WSTRINGZ * %MAX_PATH   ' WCHAR // Physical path root mapped to
   dwFlags         AS DWORD                  ' DWORD // Flags associated with this URL path
   cchMatchingPath AS DWORD                  ' DWORD // Number of matching characters in physical path
   cchMatchingURL  AS DWORD                  ' DWORD // Number of matching characters in URL
END TYPE


'//
'// PFN_HSE_IO_COMPLETION - callback function for the Async I/O Completion.
'//

'typedef VOID
'  (WINAPI * PFN_HSE_IO_COMPLETION)(
'                                   IN EXTENSION_CONTROL_BLOCK * pECB,
'                                   IN PVOID    pContext,
'                                   IN DWORD    cbIO,
'                                   IN DWORD    dwError
'                                   );

'SUB HSE_IO_COMPLETION ( _
'   BYREF pECB AS EXTENSION_CONTROL_BLOCK _             ' __in EXTENSION_CONTROL_BLOCK * pECB
' , BYVAL pContext AS DWORD _                           ' __in PVOID    pContext
' , BYVAL cbIO AS DWORD _                               ' __in DWORD    cbIO
' , BYVAL dwError AS DWORD _                            ' __in DWORD    dwError
' )

'//
'// HSE_TF_INFO defines the type for HTTP SERVER EXTENSION support for
'//  ISAPI applications to send files using TransmitFile.
'// A pointer to this object should be used with ServerSupportFunction()
'//  for HSE_REQ_TRANSMIT_FILE.
'//

'typedef struct _HSE_TF_INFO  {

'    //
'    // callback and context information
'    // the callback function will be called when IO is completed.
'    // the context specified will be used during such callback.
'    //
'    // These values (if non-NULL) will override the one set by calling
'    //  ServerSupportFunction() with HSE_REQ_IO_COMPLETION
'    //
'    PFN_HSE_IO_COMPLETION   pfnHseIO;
'    PVOID  pContext;

'    // file should have been opened with FILE_FLAG_SEQUENTIAL_SCAN
'    HANDLE hFile;

'    //
'    // HTTP header and status code
'    // These fields are used only if HSE_IO_SEND_HEADERS is present in dwFlags
'    //

'    LPCSTR pszStatusCode; // HTTP Status Code  eg: "200 OK"

'    DWORD  BytesToWrite;  // special value of "0" means write entire file.
'    DWORD  Offset;        // offset value within the file to start from

'    PVOID  pHead;         // Head buffer to be sent before file data
'    DWORD  HeadLength;    // header length
'    PVOID  pTail;         // Tail buffer to be sent after file data
'    DWORD  TailLength;    // tail length

'    DWORD  dwFlags;       // includes HSE_IO_DISCONNECT_AFTER_SEND, ...

'} HSE_TF_INFO, * LPHSE_TF_INFO;


' // Size = 44 bytes
TYPE HSE_TF_INFO DWORD
   pfnHseIO      AS DWORD        ' PFN_HSE_IO_COMPLETION
   pContext      AS DWORD        ' PVOID
   hFile         AS DWORD        ' HANDLE
   pszStatusCode AS ASCIIZ PTR   ' LPCSTR // HTTP Status Code  eg: "200 OK"
   BytesToWrite  AS DWORD        ' DWORD // special value of "0" means write entire file.
   Offset        AS DWORD        ' DWORD // offset value within the file to start from
   pHead         AS DWORD        ' DWORD // Head buffer to be sent before file data
   HeadLength    AS DWORD        ' DWORD // header length
   pTail         AS DWORD        ' PVOID // Tail buffer to be sent after file data
   TailLength    AS DWORD        ' DWORD // tail length
   dwFlags       AS DWORD        ' DWORD // includes HSE_IO_DISCONNECT_AFTER_SEND, ...
END TYPE

'//
'// HSE_SEND_HEADER_EX_INFO allows an ISAPI application to send headers
'// and specify keep-alive behavior in the same call.
'//

' // Size = 20 bytes
TYPE HSE_SEND_HEADER_EX_INFO DWORD
'  // HTTP status code and header
   pszStatus AS ASCIIZ PTR   ' LPCSTR // HTTP status code  eg: "200 OK"
   pszHeader AS ASCIIZ PTR   ' LPCSTR // HTTP header
   cchStatus AS DWORD        ' DWORD  // number of characters in status code
   cchHeader AS DWORD        ' DWORD  // number of characters in header
   fKeepConn AS LONG         ' BOOL   // keep client connection alive?
END TYPE

'//
'// Flags for use with HSE_REQ_EXEC_URL
'//

%HSE_EXEC_URL_NO_HEADERS                     = &H02???
%HSE_EXEC_URL_IGNORE_CURRENT_INTERCEPTOR     = &H04???
%HSE_EXEC_URL_IGNORE_VALIDATION_AND_RANGE    = &H10???
%HSE_EXEC_URL_DISABLE_CUSTOM_ERROR           = &H20???
%HSE_EXEC_URL_SSI_CMD                        = &H40???
%HSE_EXEC_URL_HTTP_CACHE_ELIGIBLE            = &H80???

'//
'// HSE_EXEC_URL_USER_INFO provides a new user content for use with
'// HSE_REQ_EXEC_URL
'//

' // Size = 12 bytes
TYPE HSE_EXEC_URL_USER_INFO DWORD
   hImpersonationToken AS DWORD        ' HANDLE
   pszCustomUserName   AS ASCIIZ PTR   ' LPSTR
   pszCustomAuthType   AS ASCIIZ PTR   ' LPSTR
END TYPE

'//
'// HSE_EXEC_URL_ENTITY_INFO describes the entity body to be provided
'// to the executed request using HSE_REQ_EXEC_URL
'//

' // Size = 8 bytes
TYPE HSE_EXEC_URL_ENTITY_INFO DWORD
   cbAvailable AS DWORD   ' DWORD
   lpbData     AS DWORD   ' LPVOID
END TYPE

'//
'// HSE_EXEC_URL_STATUS provides the status of the last HSE_REQ_EXEC_URL
'// call
'//

' // Size = 8 bytes
TYPE HSE_EXEC_URL_STATUS DWORD FILL
   uHttpStatusCode AS WORD    ' USHORT
   uHttpSubStatus  AS WORD    ' USHORT
   dwWin32Error    AS DWORD   ' DWORD
END TYPE

'//
'// HSE_EXEC_URL_INFO provides a description of the request to execute
'// on behalf of the ISAPI.
'//

' // Size = 24 bytes
TYPE HSE_EXEC_URL_INFO DWORD
   pszUrl          AS ASCIIZ PTR                     ' LPSTR // URL to execute
   pszMethod       AS ASCIIZ PTR                     ' LPSTR // Method
   pszChildHeaders AS ASCIIZ PTR                     ' LPSTR // Request headers for child
   pUserInfo       AS HSE_EXEC_URL_USER_INFO PTR     ' LPHSE_EXEC_URL_USER_INFO // User for new request
   pEntity         AS HSE_EXEC_URL_ENTITY_INFO PTR   ' LPHSE_EXEC_URL_ENTITY_INFO // Entity body for new request
   dwExecUrlFlags  AS DWORD                          ' DWORD // Flags
END TYPE

'//
'// HSE_EXEC_UNICODE_URL_USER_INFO provides a new user content for use with
'// HSE_REQ_EXEC_UNICODE_URL
'//

' // Size = 12 bytes
TYPE HSE_EXEC_UNICODE_URL_USER_INFO DWORD
   hImpersonationToken AS DWORD          ' HANDLE
   pszCustomUserName   AS WSTRINGZ PTR   ' LPWSTR
   pszCustomAuthType   AS ASCIIZ PTR     ' LPSTR
END TYPE

'//
'// HSE_EXEC_UNICODE_URL_INFO provides a description of the request to execute
'// on behalf of the ISAPI.
'//

' // Size = 24 bytes
TYPE HSE_EXEC_UNICODE_URL_INFO DWORD
   pszUrl          AS WSTRINGZ PTR                         ' LPWSTR // URL to execute
   pszMethod       AS ASCIIZ PTR                           ' LPSTR // Method
   pszChildHeaders AS ASCIIZ PTR                           ' LPSTR // Request headers for child
   pUserInfo       AS HSE_EXEC_UNICODE_URL_USER_INFO PTR   ' LPHSE_EXEC_UNICODE_URL_USER_INFO // User for new request
   pEntity         AS HSE_EXEC_URL_ENTITY_INFO PTR         ' LPHSE_EXEC_URL_ENTITY_INFO // Entity body for new request
   dwExecUrlFlags  AS DWORD                                ' DWORD // Flags
END TYPE

'//
'// HSE_CUSTOM_ERROR_INFO structured used in HSE_REQ_SEND_CUSTOM_ERROR
'//

' // Size = 12 bytes
TYPE HSE_CUSTOM_ERROR_INFO DWORD FILL
   pszStatus     AS ASCIIZ PTR   ' CHAR
   uHttpSubError AS WORD         ' USHORT
   fAsync        AS LONG         ' BOOL
END TYPE


'//
'// structures for the HSE_REQ_VECTOR_SEND ServerSupportFunction
'//


'//
'// Types of vector-elements currently supported
'//
%HSE_VECTOR_ELEMENT_TYPE_MEMORY_BUFFER = 0
%HSE_VECTOR_ELEMENT_TYPE_FILE_HANDLE   = 1

'//
'// element of the vector
'//

' // Size = 24 bytes
TYPE HSE_VECTOR_ELEMENT QWORD FILL
   ElementType AS DWORD   ' DWORD // Type of element (buffer/file/fragment etc)
   pvContext   AS DWORD   ' PVOID // The context representing the element to be sent
   cbOffset    AS QUAD    ' ULONGLONG // Offset from the start of hFile
   cbSize      AS QUAD    ' ULONGLONG // Number of bytes to send
END TYPE

'//
'// The whole vector to be passed to the ServerSupportFunction
'//

' // Size = 20 bytes
TYPE HSE_RESPONSE_VECTOR DWORD
   dwFlags        AS DWORD                    ' DWORD // combination of HSE_IO_* flags
   pszStatus      AS ASCIIZ PTR               ' LPSTR // Status line to send like "200 OK"
   pszHeaders     AS ASCIIZ PTR               ' LPSTR // Headers to send
   nElementCount  AS DWORD                    ' DWORD // Number of HSE_VECTOR_ELEMENT's
   lpElementArray AS HSE_VECTOR_ELEMENT PTR   ' LPHSE_VECTOR_ELEMENT // Pointer to those elements
END TYPE


'typedef HRESULT
'  (WINAPI * PFN_HSE_CACHE_INVALIDATION_CALLBACK)(
'        WCHAR *pszUrl);

'FUNCTION HSE_CACHE_INVALIDATION_CALLBACK (BYVAL pszUrl AS DWORD) AS LONG


'#if(_WIN32_WINNT >= 0x400)
#INCLUDE ONCE "wincrypt.inc"
'//
'//      CERT_CONTEXT_EX is passed as an an argument to
'//  ServerSupportFunction( HSE_REQ_GET_CERT_INFO_EX )
'//

' // Size = 28 bytes
TYPE CERT_CONTEXT_EX DWORD
   CertContext        AS CERT_CONTEXT   ' CERT_CONTEXT
   cbAllocated        AS DWORD          ' DWORD
   dwCertificateFlags AS DWORD          ' DWORD
END TYPE
'#endif



'//
'// HSE_TRACE_INFO structure used to get debug trace info
'// from core web server
'//

' // Size = 28 bytes
TYPE HSE_TRACE_INFO DWORD
   fTraceRequest      AS LONG    ' BOOL // Recommendation from IIS to trace the request
   TraceContextId(15) AS BYTE    ' BYTE [16] // The unique trace context ID for the current request
   dwReserved1        AS DWORD   ' DWORD // Reserved for future use
   dwReserved2        AS DWORD   ' DWORD // Reserved for future use
END TYPE


'//
'// HSE_REQ_GET_TRACE_INFO_EX SSF uses
'// the HTTP_TRACE_CONFIGURATION structure defined in httptrace.h
'//

'//
'// HSE_REQ_RAISE_TRACE_EVENT SSF uses
'// the HTTP_TRACE_EVENT structure defined in httptrace.h
'//

'//
'// SSF_REQ_GET_WORKER_PROCESS_SETTINGS returns IWpfSettings pointer.
'// IWpfSettings is defined in the wpframework.h
'//

'//
'// SSF_REQ_GET_CONFIG_OBJECT returns INativeConfigurationSystem pointer.
'// INativeConfigurationSystem is defined in the nativerd.h
'//

'//
'// HSE_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK returns pointer to
'// PFN_HSE_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK function type
'//

'typedef HRESULT
'  (WINAPI * PFN_HSE_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK)(
'                            LPCWSTR       pszProtocolManagerDll,
'                            LPCWSTR       pszProtocolManagerDllInitFunction,
'                            DWORD         dwCustomInterfaceId,
'                            PVOID*        ppCustomInterface );


'FUNCTION HSE_GET_PROTOCOL_MANAGER_CUSTOM_INTERFACE_CALLBACK ( _
'   BYREF pszProtocolManagerDll AS WSTRINGZ _             ' __in LPCWSTR       pszProtocolManagerDll
' , BYREF pszProtocolManagerDllInitFunction AS WSTRINGZ _ ' __in LPCWSTR       pszProtocolManagerDllInitFunction
' , BYVAL dwCustomInterfaceId AS DWORD _                  ' __in DWORD         dwCustomInterfaceId
' , BYREF ppCustomInterface AS DWORD _                    ' __ut PVOID*        ppCustomInterface
' ) AS LONG                                               ' HRESULT

'//
'// Flags for determining application type
'//

%HSE_APP_FLAG_IN_PROCESS   = 0
%HSE_APP_FLAG_ISOLATED_OOP = 1
%HSE_APP_FLAG_POOLED_OOP   = 2


'/************************************************************
' *   Function Prototypes
' *   o  for functions exported from the ISAPI Application DLL
' ************************************************************/

'BOOL  WINAPI   GetExtensionVersion( __out HSE_VERSION_INFO  *pVer );
'DECLARE FUNCTION GetExtensionVersion (BYREF pVer AS HSE_VERSION_INFO) AS LONG

'DWORD WINAPI   HttpExtensionProc( __in EXTENSION_CONTROL_BLOCK *pECB );
'DECLARE FUNCTION HttpExtensionProc (BYREF pECB AS EXTENSION_CONTROL_BLOCK) AS DWORD

'BOOL  WINAPI   TerminateExtension( DWORD dwFlags );
'DECLARE FUNCTION TerminateExtension (BYVAL dwFlags AS DWORD) AS LONG

'// the following type declarations is for use in the server side

'typedef BOOL
'    (WINAPI * PFN_GETEXTENSIONVERSION)( HSE_VERSION_INFO  *pVer );

'typedef DWORD
'    (WINAPI * PFN_HTTPEXTENSIONPROC )( EXTENSION_CONTROL_BLOCK * pECB );

'typedef BOOL  (WINAPI * PFN_TERMINATEEXTENSION )( DWORD dwFlags );
