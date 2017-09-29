' ########################################################################################
' Microsoft Windows
' File: WinInet.inc
' Contents: Microsoft Windows Internet Extensions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WININET_INC = 1

'#if !defined(_WININET_)
'#include <SpecStrings.h>
'#define _WININET_

#INCLUDE ONCE "windows.inc"

'/*
' * Set up Structure Packing to be 4 bytes
' * for all wininet structures
' */
'#if defined(_WIN64)
'#include <pshpack8.h>
'#else
'#include <pshpack4.h>
'#endif

'#define BOOLAPI INTERNETAPI_(BOOL)

'//
'// internet types
'//

'typedef LPVOID HINTERNET;
'typedef HINTERNET * LPHINTERNET;

'typedef WORD INTERNET_PORT;
'typedef INTERNET_PORT * LPINTERNET_PORT;

'//
'// Internet APIs
'//

'//
'// manifests
'//

%INTERNET_INVALID_PORT_NUMBER  = 0       ' use the protocol-specific default

%INTERNET_DEFAULT_FTP_PORT     = 21      ' default for FTP servers
%INTERNET_DEFAULT_GOPHER_PORT  = 70      '    "     "  gopher "
%INTERNET_DEFAULT_HTTP_PORT    = 80      '    "     "  HTTP   "
%INTERNET_DEFAULT_HTTPS_PORT   = 443     '    "     "  HTTPS  "
%INTERNET_DEFAULT_SOCKS_PORT   = 1080    ' default for SOCKS firewall servers.

'//
'// maximum field lengths (arbitrary)
'//

%INTERNET_MAX_HOST_NAME_LENGTH   = 256
%INTERNET_MAX_USER_NAME_LENGTH   = 128
%INTERNET_MAX_PASSWORD_LENGTH    = 128
%INTERNET_MAX_PORT_NUMBER_LENGTH = 5     ' %INTERNET_PORT is unsigned short
%INTERNET_MAX_PORT_NUMBER_VALUE  = 65535 ' maximum unsigned short value
%INTERNET_MAX_PATH_LENGTH        = 2048
%INTERNET_MAX_SCHEME_LENGTH      = 32    ' longest protocol name length
%INTERNET_MAX_URL_LENGTH         = (%INTERNET_MAX_SCHEME_LENGTH _
                                    + 4 _ ' sizeof("://") + null
                                    + %INTERNET_MAX_PATH_LENGTH)


'//
'// values returned by InternetQueryOption() with INTERNET_OPTION_KEEP_CONNECTION:
'//

%INTERNET_KEEP_ALIVE_UNKNOWN     = &HFFFFFFFF???   ' ((DWORD)-1)
%INTERNET_KEEP_ALIVE_ENABLED     = 1
%INTERNET_KEEP_ALIVE_DISABLED    = 0

'//
'// flags returned by InternetQueryOption() with INTERNET_OPTION_REQUEST_FLAGS
'//

%INTERNET_REQFLAG_FROM_CACHE     = &H00000001???  ' response came from cache
%INTERNET_REQFLAG_ASYNC          = &H00000002???  ' request was made asynchronously
%INTERNET_REQFLAG_VIA_PROXY      = &H00000004???  ' request was made via a proxy
%INTERNET_REQFLAG_NO_HEADERS     = &H00000008???  ' orginal response contained no headers
%INTERNET_REQFLAG_PASSIVE        = &H00000010???  ' FTP: passive-mode connection
%INTERNET_REQFLAG_CACHE_WRITE_DISABLED = &H00000040???  ' HTTPS: this request not cacheable
%INTERNET_REQFLAG_NET_TIMEOUT    = &H00000080???  ' w/ _FROM_CACHE: net request timed out

'//
'// flags for IDN enable/disable via INTERNET_OPTION_IDN
'//

%INTERNET_FLAG_IDN_DIRECT        = &H00000001???   ' // IDN enabled for direct connections
%INTERNET_FLAG_IDN_PROXY         = &H00000002???   ' // IDN enabled for proxy

'//
'// flags common to open functions (not InternetOpen()):
'//

%INTERNET_FLAG_RELOAD            = &H80000000???  ' retrieve the original item

'//
'// flags for InternetOpenUrl():
'//

%INTERNET_FLAG_RAW_DATA          = &H40000000???  ' FTP/gopher find: receive the item as raw (structured) data
%INTERNET_FLAG_EXISTING_CONNECT  = &H20000000???  ' FTP: use existing InternetConnect handle for server if possible

'//
'// flags for InternetOpen():
'//

%INTERNET_FLAG_ASYNC             = &H10000000???  ' this request is asynchronous (where supported)

'//
'// protocol-specific flags:
'//

%INTERNET_FLAG_PASSIVE           = &H08000000???  ' used for FTP connections

'//
'// additional cache flags
'//

%INTERNET_FLAG_NO_CACHE_WRITE    = &H04000000???  ' don't write this item to the cache
%INTERNET_FLAG_DONT_CACHE        = %INTERNET_FLAG_NO_CACHE_WRITE
%INTERNET_FLAG_MAKE_PERSISTENT   = &H02000000???  ' make this item persistent in cache
%INTERNET_FLAG_FROM_CACHE        = &H01000000???  ' use offline semantics
%INTERNET_FLAG_OFFLINE           = %INTERNET_FLAG_FROM_CACHE

'//
'// additional flags
'//

%INTERNET_FLAG_SECURE            = &H00800000???  ' use PCT/SSL if applicable (HTTP)
%INTERNET_FLAG_KEEP_CONNECTION   = &H00400000???  ' use keep-alive semantics
%INTERNET_FLAG_NO_AUTO_REDIRECT  = &H00200000???  ' don't handle redirections automatically
%INTERNET_FLAG_READ_PREFETCH     = &H00100000???  ' do background read prefetch
%INTERNET_FLAG_NO_COOKIES        = &H00080000???  ' no automatic cookie handling
%INTERNET_FLAG_NO_AUTH           = &H00040000???  ' no automatic authentication handling
%INTERNET_FLAG_RESTRICTED_ZONE   = &H00020000???  ' apply restricted zone policies for cookies, auth
%INTERNET_FLAG_CACHE_IF_NET_FAIL = &H00010000???  ' return cache file if net request fails

'//
'// Security Ignore Flags, Allow HttpOpenRequest to overide
'//  Secure Channel (SSL/PCT) failures of the following types.
'//

%INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP   = &H00008000??? ' ex: https:// to http://
%INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS  = &H00004000??? ' ex: http:// to https://
%INTERNET_FLAG_IGNORE_CERT_DATE_INVALID  = &H00002000??? ' expired X509 Cert.
%INTERNET_FLAG_IGNORE_CERT_CN_INVALID    = &H00001000??? ' bad common name in X509 Cert.

'//
'// more caching flags
'//

%INTERNET_FLAG_RESYNCHRONIZE      = &H00000800???  ' asking wininet to update an item if it is newer
%INTERNET_FLAG_HYPERLINK          = &H00000400???  ' asking wininet to do hyperlinking semantic which works right for scripts
%INTERNET_FLAG_NO_UI              = &H00000200???  ' no cookie popup
%INTERNET_FLAG_PRAGMA_NOCACHE     = &H00000100???  ' asking wininet to add "pragma: no-cache"
%INTERNET_FLAG_CACHE_ASYNC        = &H00000080???  ' ok to perform lazy cache-write
%INTERNET_FLAG_FORMS_SUBMIT       = &H00000040???  ' this is a forms submit
%INTERNET_FLAG_FWD_BACK           = &H00000020???  ' fwd-back button op
%INTERNET_FLAG_NEED_FILE          = &H00000010???  ' need a file for this request
%INTERNET_FLAG_MUST_CACHE_REQUEST = %INTERNET_FLAG_NEED_FILE

'//
'// flags for FTP
'//

%INTERNET_FLAG_TRANSFER_ASCII    = &H00000001???   ' %FTP_TRANSFER_TYPE_ASCII
%INTERNET_FLAG_TRANSFER_BINARY   = &H00000002???   ' %FTP_TRANSFER_TYPE_BINARY

'//
'// flags field masks
'//

%SECURITY_INTERNET_MASK  = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID    OR  _
                           %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID  OR  _
                           %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS  OR  _
                           %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP

'%SECURITY_IGNORE_ERROR_MASK = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID   OR _
'                              %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID OR _
'                              %SECURITY_FLAG_IGNORE_UNKNOWN_CA        OR _
'                              %SECURITY_FLAG_IGNORE_REVOCATION

%SECURITY_IGNORE_ERROR_MASK = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID   OR _
                              %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID OR _
                              &H00000100???                           OR _
                              &H00000080???

%INTERNET_FLAGS_MASK     = %INTERNET_FLAG_RELOAD               _
                           OR %INTERNET_FLAG_RAW_DATA          _
                           OR %INTERNET_FLAG_EXISTING_CONNECT  _
                           OR %INTERNET_FLAG_ASYNC             _
                           OR %INTERNET_FLAG_PASSIVE           _
                           OR %INTERNET_FLAG_NO_CACHE_WRITE    _
                           OR %INTERNET_FLAG_MAKE_PERSISTENT   _
                           OR %INTERNET_FLAG_FROM_CACHE        _
                           OR %INTERNET_FLAG_SECURE            _
                           OR %INTERNET_FLAG_KEEP_CONNECTION   _
                           OR %INTERNET_FLAG_NO_AUTO_REDIRECT  _
                           OR %INTERNET_FLAG_READ_PREFETCH     _
                           OR %INTERNET_FLAG_NO_COOKIES        _
                           OR %INTERNET_FLAG_NO_AUTH           _
                           OR %INTERNET_FLAG_CACHE_IF_NET_FAIL _
                           OR %SECURITY_INTERNET_MASK          _
                           OR %INTERNET_FLAG_RESYNCHRONIZE     _
                           OR %INTERNET_FLAG_HYPERLINK         _
                           OR %INTERNET_FLAG_NO_UI             _
                           OR %INTERNET_FLAG_PRAGMA_NOCACHE    _
                           OR %INTERNET_FLAG_CACHE_ASYNC       _
                           OR %INTERNET_FLAG_FORMS_SUBMIT      _
                           OR %INTERNET_FLAG_NEED_FILE         _
                           OR %INTERNET_FLAG_RESTRICTED_ZONE   _
                           OR %INTERNET_FLAG_TRANSFER_BINARY   _
                           OR %INTERNET_FLAG_TRANSFER_ASCII    _
                           OR %INTERNET_FLAG_FWD_BACK          _
                           OR &H00000008???   ' INTERNET_FLAG_BGUPDATE

%INTERNET_ERROR_MASK_INSERT_CDROM                      = &H1
%INTERNET_ERROR_MASK_COMBINED_SEC_CERT                 = &H2
%INTERNET_ERROR_MASK_NEED_MSN_SSPI_PKG                 = &H4
%INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = &H8

%INTERNET_OPTIONS_MASK    = NOT %INTERNET_FLAGS_MASK

'//
'// common per-API flags (new APIs)
'//

%WININET_API_FLAG_ASYNC       = &H00000001???  ' force async operation
%WININET_API_FLAG_SYNC        = &H00000004???  ' force sync operation
%WININET_API_FLAG_USE_CONTEXT = &H00000008???  ' use value supplied in dwContext (even if 0)

'//
'// INTERNET_NO_CALLBACK - if this value is presented as the dwContext parameter
'// then no call-backs will be made for that API
'//

%INTERNET_NO_CALLBACK            = 0

'//
'// structures/types
'//

'//
'// INTERNET_SCHEME - enumerated URL scheme type
'//

%INTERNET_SCHEME_PARTIAL    = -2
%INTERNET_SCHEME_UNKNOWN    = -1
%INTERNET_SCHEME_DEFAULT    = 0
%INTERNET_SCHEME_FTP        = 1
%INTERNET_SCHEME_GOPHER     = 2
%INTERNET_SCHEME_HTTP       = 3
%INTERNET_SCHEME_HTTPS      = 4
%INTERNET_SCHEME_FILE       = 5
%INTERNET_SCHEME_NEWS       = 6
%INTERNET_SCHEME_MAILTO     = 7
%INTERNET_SCHEME_SOCKS      = 8
%INTERNET_SCHEME_JAVASCRIPT = 9
%INTERNET_SCHEME_VBSCRIPT   = 10
%INTERNET_SCHEME_RES        = 11
%INTERNET_SCHEME_FIRST      = %INTERNET_SCHEME_FTP
%INTERNET_SCHEME_LAST       = %INTERNET_SCHEME_RES

'//
'// INTERNET_ASYNC_RESULT - this structure is returned to the application via
'// the callback with INTERNET_STATUS_REQUEST_COMPLETE. It is not sufficient to
'// just return the result of the async operation. If the API failed then the
'// app cannot call GetLastError() because the thread context will be incorrect.
'// Both the value returned by the async API and any resultant error code are
'// made available. The app need not check dwError if dwResult indicates that
'// the API succeeded (in this case dwError will be ERROR_SUCCESS)
'//

' // Size = 8 bytes
TYPE INTERNET_ASYNC_RESULT DWORD
   dwResult AS DWORD   ' DWORD_PTR  // the HINTERNET, DWORD, or BOOL return code from an async API
   dwError  AS DWORD   ' DWORD      // the error code if the API failed
END TYPE

'//
'// INTERNET_DIAGNOSTIC_SOCKET_INFO - info about the socket in use
'//

' // Size = 16 bytes
TYPE INTERNET_DIAGNOSTIC_SOCKET_INFO DWORD
   Socket     AS DWORD   ' DWORD_PTR
   SourcePort AS DWORD   ' DWORD
   DestPort   AS DWORD   ' DWORD
   Flags      AS DWORD   ' DWORD
END TYPE

'//
'// INTERNET_DIAGNOSTIC_SOCKET_INFO.Flags definitions
'//

%IDSI_FLAG_KEEP_ALIVE    = &H00000001???   ' // set if from keep-alive pool
%IDSI_FLAG_SECURE        = &H00000002???   ' // set if secure connection
%IDSI_FLAG_PROXY         = &H00000004???   ' // set if using proxy
%IDSI_FLAG_TUNNEL        = &H00000008???   ' // set if tunnelling through proxy

'//
'// INTERNET_PROXY_INFO - structure supplied with INTERNET_OPTION_PROXY to get/
'// set proxy information on a InternetOpen() handle
'//

' // Size = 12 bytes
TYPE INTERNET_PROXY_INFO DWORD
   dwAccessType    AS DWORD      ' DWORD // dwAccessType - INTERNET_OPEN_TYPE_DIRECT,
                                 '                         INTERNET_OPEN_TYPE_PROXY,
                                 '                         or INTERNET_OPEN_TYPE_PRECONFIG (set only)
   lpszProxy       AS ASCIIZ PTR ' LPCTSTR // lpszProxy - proxy server list
   lpszProxyBypass AS ASCIIZ PTR ' LPCTSTR // lpszProxyBypass - proxy bypass list
END TYPE

'//
'// INTERNET_PER_CONN_OPTION_LIST - set per-connection options such as proxy
'// and autoconfig info
'//
'// Set and queried using Internet[Set|Query]Option with
'// INTERNET_OPTION_PER_CONNECTION_OPTION
'//

' // Size = 8 bytes
UNION INTERNET_PER_CONN_OPTIONA_VALUE DWORD
   dwValue  AS DWORD        ' DWORD  // dword value for the option
   pszValue AS ASCIIZ PTR   ' LPSTR // pointer to string value for the option
   ftValue  AS FILETIME     ' FILETIME // file-time value for the option
END UNION

' // Size = 12 bytes
TYPE INTERNET_PER_CONN_OPTIONA DWORD
   dwOption AS DWORD        ' DWORD // option to be queried or set
   Value    AS INTERNET_PER_CONN_OPTIONA_VALUE
END TYPE

' // Size = 8 bytes
UNION INTERNET_PER_CONN_OPTIONW_VALUE DWORD
   dwValue  AS DWORD          ' DWORD // dword value for the option
   pszValue AS WSTRINGZ PTR   ' LPWSTR // pointer to string value for the option
   ftValue  AS FILETIME       ' FILETIME // file-time value for the option
END UNION

' // Size = 12 bytes
TYPE INTERNET_PER_CONN_OPTIONW DWORD
   dwOption AS DWORD        ' DWORD // option to be queried or set
   Value    AS INTERNET_PER_CONN_OPTIONW_VALUE
END TYPE

#IF %DEF(%UNICODE)
   MACRO INTERNET_PER_CONN_OPTION = INTERNET_PER_CONN_OPTIONW
#ELSE
   MACRO INTERNET_PER_CONN_OPTION = INTERNET_PER_CONN_OPTIONA
#ENDIF

' // Size = 20 bytes
TYPE INTERNET_PER_CONN_OPTION_LISTA DWORD
   dwSize        AS DWORD                     ' DWORD // size of the INTERNET_PER_CONN_OPTION_LIST struct
   pszConnection AS ASCIIZ PTR                ' LPSTR // connection name to set/query options
   dwOptionCount AS DWORD                     ' DWORD // number of options to set/query
   dwOptionError AS DWORD                     ' DWORD // on error, which option failed
   pOptions AS INTERNET_PER_CONN_OPTION PTR   ' LPINTERNET_PER_CONN_OPTIONW // array of options to set/query
END TYPE

' // Size = 20 bytes
TYPE INTERNET_PER_CONN_OPTION_LISTW DWORD
   dwSize        AS DWORD                      ' DWORD // size of the INTERNET_PER_CONN_OPTION_LIST struct
   pszConnection AS WSTRINGZ PTR               ' LPWSTR // connection name to set/query options
   dwOptionCount AS DWORD                      ' DWORD // number of options to set/query
   dwOptionError AS DWORD                      ' DWORD // on error, which option failed
   pOptions AS INTERNET_PER_CONN_OPTIONW PTR   ' LPINTERNET_PER_CONN_OPTIONW // array of options to set/query
END TYPE

#IF %DEF(%UNICODE)
   MACRO INTERNET_PER_CONN_OPTION_LIST = INTERNET_PER_CONN_OPTION_LISTW
#ELSE
   MACRO INTERNET_PER_CONN_OPTION_LIST = INTERNET_PER_CONN_OPTION_LISTA
#ENDIF

'//
'// Options used in INTERNET_PER_CONN_OPTON struct
'//
%INTERNET_PER_CONN_FLAGS                        = 1
%INTERNET_PER_CONN_PROXY_SERVER                 = 2
%INTERNET_PER_CONN_PROXY_BYPASS                 = 3
%INTERNET_PER_CONN_AUTOCONFIG_URL               = 4
%INTERNET_PER_CONN_AUTODISCOVERY_FLAGS          = 5
%INTERNET_PER_CONN_AUTOCONFIG_SECONDARY_URL     = 6
%INTERNET_PER_CONN_AUTOCONFIG_RELOAD_DELAY_MINS = 7
%INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_TIME  = 8
%INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_URL   = 9
%INTERNET_PER_CONN_FLAGS_UI                     = 10

'//
'// PER_CONN_FLAGS
'//
%PROXY_TYPE_DIRECT         = &H00000001???   ' direct to net
%PROXY_TYPE_PROXY          = &H00000002???   ' via named proxy
%PROXY_TYPE_AUTO_PROXY_URL = &H00000004???   ' autoproxy URL
%PROXY_TYPE_AUTO_DETECT    = &H00000008???   ' use autoproxy detection

'//
'// PER_CONN_AUTODISCOVERY_FLAGS
'//
%AUTO_PROXY_FLAG_USER_SET                = &H00000001??? ' user changed this setting
%AUTO_PROXY_FLAG_ALWAYS_DETECT           = &H00000002??? ' force detection even when its not needed
%AUTO_PROXY_FLAG_DETECTION_RUN           = &H00000004??? ' detection has been run
%AUTO_PROXY_FLAG_MIGRATED                = &H00000008??? ' migration has just been done
%AUTO_PROXY_FLAG_DONT_CACHE_PROXY_RESULT = &H00000010??? ' don't cache result of host=proxy name
%AUTO_PROXY_FLAG_CACHE_INIT_RUN          = &H00000020??? ' don't initalize and run unless URL expired
%AUTO_PROXY_FLAG_DETECTION_SUSPECT       = &H00000040??? ' if we're on a LAN & Modem, with only one IP, bad?!?

'//
'// INTERNET_VERSION_INFO - version information returned via
'// InternetQueryOption(..., INTERNET_OPTION_VERSION, ...)
'//

' // Size = 8 bytes
TYPE INTERNET_VERSION_INFO DWORD
   dwMajorVersion AS DWORD
   dwMinorVersion AS DWORD
END TYPE

'//
'// HTTP_VERSION_INFO - query or set global HTTP version (1.0 or 1.1)
'//

' // Size = 8 bytes
TYPE HTTP_VERSION_INFO DWORD
   dwMajorVersion AS DWORD
   dwMinorVersion AS DWORD
END TYPE

'//
'// INTERNET_CONNECTED_INFO - information used to set the global connected state
'//

' // Size = 8 bytes
TYPE INTERNET_CONNECTED_INFO DWORD
   dwConnectedState AS DWORD
   dwFlags          AS DWORD
END TYPE

'//
'// flags for INTERNET_CONNECTED_INFO dwFlags
'//

'//
'// ISO_FORCE_DISCONNECTED - if set when putting Wininet into disconnected mode,
'// all outstanding requests will be aborted with a cancelled error
'//

%ISO_FORCE_DISCONNECTED = &H00000001???


'//
'// URL_COMPONENTS - the constituent parts of an URL. Used in InternetCrackUrl()
'// and InternetCreateUrl()
'//
'// For InternetCrackUrl(), if a pointer field and its corresponding length field
'// are both 0 then that component is not returned. If the pointer field is NULL
'// but the length field is not zero, then both the pointer and length fields are
'// returned if both pointer and corresponding length fields are non-zero then
'// the pointer field points to a buffer where the component is copied. The
'// component may be un-escaped, depending on dwFlags
'//
'// For InternetCreateUrl(), the pointer fields should be NULL if the component
'// is not required. If the corresponding length field is zero then the pointer
'// field is the address of a zero-terminated string. If the length field is not
'// zero then it is the string length of the corresponding pointer field
'//

'#pragma warning( disable : 4121 )   // disable alignment warning

' // Size = 60 bytes
TYPE URL_COMPONENTSA DWORD
   dwStructSize      AS DWORD       ' DWORD // size of this structure. Used in version check
   lpszScheme        AS ASCIIZ PTR  ' LPSTR // pointer to scheme name
   dwSchemeLength    AS DWORD       ' DWORD // length of scheme name
   nScheme           AS LONG        ' INTERNET_SCHEME // enumerated scheme type (if known)
   lpszHostName      AS ASCIIZ PTR  ' LPSTR // pointer to host name
   dwHostNameLength  AS DWORD       ' DWORD // length of host name
   nPort             AS WORD        ' INTERNET_PORT // converted port number
   lpszUserName      AS ASCIIZ PTR  ' LPSTR // pointer to user name
   dwUserNameLength  AS DWORD       ' DWORD // length of user name
   lpszPassword      AS ASCIIZ PTR  ' LPSTR // pointer to password
   dwPasswordLength  AS DWORD       ' DWORD // length of password
   lpszUrlPath       AS ASCIIZ PTR  ' LPSTR // pointer to URL-path
   dwUrlPathLength   AS DWORD       ' DWORD // length of URL-path
   lpszExtraInfo     AS ASCIIZ PTR  ' LPSTR // pointer to extra information (e.g. ?foo or #foo)
   dwExtraInfoLength AS DWORD       ' DWORD // length of extra information
END TYPE

' NOTE: The unicode version of this structure is also defined in winhhtp.inc
#IF NOT %DEF(%URL_COMPONENTSW_DEFINED)
%URL_COMPONENTSW_DEFINED = 1
' // Size = 60 bytes
TYPE URL_COMPONENTSW DWORD
   dwStructSize      AS DWORD         ' DWORD // size of this structure. Used in version check
   lpszScheme        AS WSTRINGZ PTR  ' LPWSTR // pointer to scheme name
   dwSchemeLength    AS DWORD         ' DWORD // length of scheme name
   nScheme           AS LONG          ' INTERNET_SCHEME // enumerated scheme type (if known)
   lpszHostName      AS WSTRINGZ PTR  ' LPWSTR // pointer to host name
   dwHostNameLength  AS DWORD         ' DWORD // length of host name
   nPort             AS WORD          ' INTERNET_PORT // converted port number
   lpszUserName      AS WSTRINGZ PTR  ' LPWSTR // pointer to user name
   dwUserNameLength  AS DWORD         ' DWORD // length of user name
   lpszPassword      AS WSTRINGZ PTR  ' LPWSTR // pointer to password
   dwPasswordLength  AS DWORD         ' DWORD // length of password
   lpszUrlPath       AS WSTRINGZ PTR  ' LPWSTR // pointer to URL-path
   dwUrlPathLength   AS DWORD         ' DWORD // length of URL-path
   lpszExtraInfo     AS WSTRINGZ PTR  ' LPWSTR // pointer to extra information (e.g. ?foo or #foo) (UnicodeZ string)
   dwExtraInfoLength AS DWORD         ' DWORD // length of extra information
END TYPE
#ENDIF

#IF %DEF(%UNICODE)
   MACRO URL_COMPONENTS = URL_COMPONENTSW
#ELSE
   MACRO URL_COMPONENTS = URL_COMPONENTSA
#ENDIF

'#pragma warning( default : 4121 )   // restore alignment warning

'//
'// INTERNET_CERTIFICATE_INFO lpBuffer - contains the certificate returned from
'// the server
'//

' // Size = 40 bytes
TYPE INTERNET_CERTIFICATE_INFO DWORD
   ftExpiry              AS FILETIME     ' FILETIME
   ftStart               AS FILETIME     ' FILETIME
   lpszSubjectInfo       AS ASCIIZ PTR   ' LPTSTR
   lpszIssuerInfo        AS ASCIIZ PTR   ' LPTSTR
   lpszProtocolName      AS ASCIIZ PTR   ' LPTSTR
   lpszSignatureAlgName  AS ASCIIZ PTR   ' LPTSTR
   lpszEncryptionAlgName AS ASCIIZ PTR   ' LPTSTR
   dwKeySize             AS DWORD        ' DWORD
END TYPE

'//
'// INTERNET_BUFFERS - combines headers and data. May be chained for e.g. file
'// upload or scatter/gather operations. For chunked read/write, lpcszHeader
'// contains the chunked-ext
'//

' // Size = 40 bytes
TYPE INTERNET_BUFFERSA DWORD
   dwStructSize    AS DWORD                   ' DWORD // used for API versioning. Set to sizeof(INTERNET_BUFFERS)
   pNext           AS INTERNET_BUFFERSA PTR   ' struct _INTERNET_BUFFERSA // chain of buffers
   lpcszHeader     AS ASCIIZ PTR              ' LPCSTR // pointer to headers (may be NULL)
   dwHeadersLength AS DWORD                   ' DWORD // length of headers if not NULL
   dwHeadersTotal  AS DWORD                   ' DWORD // size of headers if not enough buffer
   lpvBuffer       AS BYTE PTR                ' LPVOID // pointer to data buffer (may be NULL)
   dwBufferLength  AS DWORD                   ' DWORD // length of data buffer if not NULL
   dwBufferTotal   AS DWORD                   ' DWORD // total size of chunk, or content-length if not chunked
   dwOffsetLow     AS DWORD                   ' DWORD // used for read-ranges (only used in HttpSendRequest2)
   dwOffsetHigh    AS DWORD                   ' DWORD
END TYPE

' // Size = 40 bytes
TYPE INTERNET_BUFFERSW DWORD
   dwStructSize    AS DWORD                   ' DWORD // used for API versioning. Set to sizeof(INTERNET_BUFFERS)
   pNext           AS INTERNET_BUFFERSW PTR   ' struct _INTERNET_BUFFERSW // chain of buffers
   lpcszHeader     AS WSTRINGZ PTR            ' LPCWSTR // pointer to headers (may be NULL)
   dwHeadersLength AS DWORD                   ' DWORD // length of headers if not NULL
   dwHeadersTotal  AS DWORD                   ' DWORD // size of headers if not enough buffer
   lpvBuffer       AS BYTE PTR                ' LPVOID // pointer to data buffer (may be NULL)
   dwBufferLength  AS DWORD                   ' DWORD // length of data buffer if not NULL
   dwBufferTotal   AS DWORD                   ' DWORD // total size of chunk, or content-length if not chunked
   dwOffsetLow     AS DWORD                   ' DWORD // used for read-ranges (only used in HttpSendRequest2)
   dwOffsetHigh    AS DWORD                   ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO INTERNET_BUFFERS = INTERNET_BUFFERSW
#ELSE
   MACRO INTERNET_BUFFERS = INTERNET_BUFFERSA
#ENDIF

'//
'// prototypes
'//

DECLARE FUNCTION InternetTimeFromSystemTimeA IMPORT "WININET.DLL" ALIAS "InternetTimeFromSystemTimeA" ( _
   BYREF pst AS SYSTEMTIME _                            ' __in CONST SYSTEMTIME *pst
 , BYVAL dwRFC AS DWORD _                               ' __in DWORD dwRFC
 , BYREF lpszTime AS ASCIIZ _                           ' __out LPSTR lpszTime
 , BYVAL cbTime AS DWORD _                              ' __in DWORD cbTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetTimeFromSystemTimeW IMPORT "WININET.DLL" ALIAS "InternetTimeFromSystemTimeW" ( _
   BYREF pst AS SYSTEMTIME _                            ' __in CONST SYSTEMTIME *pst
 , BYVAL dwRFC AS DWORD _                               ' __in DWORD dwRFC
 , BYREF lpszTime AS WSTRINGZ _                         ' __out LPWSTR lpszTime
 , BYVAL cbTime AS DWORD _                              ' __in DWORD cbTime
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetTimeFromSystemTime = InternetTimeFromSystemTimeW
#ELSE
   MACRO InternetTimeFromSystemTime = InternetTimeFromSystemTimeA
#ENDIF

'//
'// constants for InternetTimeFromSystemTime
'//

%INTERNET_RFC1123_FORMAT     = 0
%INTERNET_RFC1123_BUFSIZE    = 30

DECLARE FUNCTION InternetTimeToSystemTimeA IMPORT "WININET.DLL" ALIAS "InternetTimeToSystemTimeA" ( _
   BYREF lpszTime AS ASCIIZ _                           ' __in LPCSTR lpszTime
 , BYREF pst AS SYSTEMTIME _                            ' __out SYSTEMTIME *pst
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetTimeToSystemTimeW IMPORT "WININET.DLL" ALIAS "InternetTimeToSystemTimeW" ( _
   BYREF lpszTime AS WSTRINGZ _                         ' __in LPCWSTR lpszTime
 , BYREF pst AS SYSTEMTIME _                            ' __out SYSTEMTIME *pst
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetTimeToSystemTime = InternetTimeToSystemTimeW
#ELSE
   MACRO InternetTimeToSystemTime = InternetTimeToSystemTimeA
#ENDIF

DECLARE FUNCTION InternetCrackUrlA IMPORT "WININET.DLL" ALIAS "InternetCrackUrlA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYVAL dwUrlLength AS DWORD _                         ' __in DWORD dwUrlLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpUrlComponents AS URL_COMPONENTSA _           ' __inout LPURL_COMPONENTSA lpUrlComponents
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetCrackUrlW IMPORT "WININET.DLL" ALIAS "InternetCrackUrlW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYVAL dwUrlLength AS DWORD _                         ' __in DWORD dwUrlLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpUrlComponents AS URL_COMPONENTSW _           ' __inout LPURL_COMPONENTSW lpUrlComponents
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetCrackUrl = InternetCrackUrlW
#ELSE
   MACRO InternetCrackUrl = InternetCrackUrlA
#ENDIF

DECLARE FUNCTION InternetCreateUrlA IMPORT "WININET.DLL" ALIAS "InternetCreateUrlA" ( _
   BYREF lpUrlComponents AS URL_COMPONENTSA _           ' __in LPURL_COMPONENTSA lpUrlComponents
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpszUrl AS ASCIIZ _                            ' __out LPSTR lpszUrl
 , BYREF lpdwUrlLength AS DWORD _                       ' __inout LPDWORD lpdwUrlLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetCreateUrlW IMPORT "WININET.DLL" ALIAS "InternetCreateUrlW" ( _
   BYREF lpUrlComponents AS URL_COMPONENTSW _           ' __in LPURL_COMPONENTSW lpUrlComponents
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpszUrl AS WSTRINGZ _                          ' __out LPWSTR lpszUrl
 , BYREF lpdwUrlLength AS DWORD _                       ' __inout LPDWORD lpdwUrlLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetCreateUrl = InternetCreateUrlW
#ELSE
   MACRO InternetCreateUrl = InternetCreateUrlA
#ENDIF

DECLARE FUNCTION InternetCanonicalizeUrlA IMPORT "WININET.DLL" ALIAS "InternetCanonicalizeUrlA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszBuffer AS ASCIIZ _                         ' __out LPSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetCanonicalizeUrlW IMPORT "WININET.DLL" ALIAS "InternetCanonicalizeUrlW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszBuffer AS WSTRINGZ _                       ' __out LPWSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetCanonicalizeUrl = InternetCanonicalizeUrlW
#ELSE
   MACRO InternetCanonicalizeUrl = InternetCanonicalizeUrlA
#ENDIF

DECLARE FUNCTION InternetCombineUrlA IMPORT "WININET.DLL" ALIAS "InternetCombineUrlA" ( _
   BYREF lpszBaseUrl AS ASCIIZ _                        ' __in LPCSTR lpszBaseUrl
 , BYREF lpszRelativeUrl AS ASCIIZ _                    ' __in LPCSTR lpszRelativeUrl
 , BYREF lpszBuffer AS ASCIIZ _                         ' __out LPSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetCombineUrlW IMPORT "WININET.DLL" ALIAS "InternetCombineUrlW" ( _
   BYREF lpszBaseUrl AS WSTRINGZ _                      ' __in LPCWSTR lpszBaseUrl
 , BYREF lpszRelativeUrl AS WSTRINGZ _                  ' __in LPCWSTR lpszRelativeUrl
 , BYREF lpszBuffer AS WSTRINGZ _                       ' __out LPWSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetCombineUrl = InternetCombineUrlW
#ELSE
   MACRO InternetCombineUrl = InternetCombineUrlA
#ENDIF

'//
'// flags for InternetCrackUrl() and InternetCreateUrl()
'//

%ICU_ESCAPE      = &H80000000???  ' (un)escape URL characters
%ICU_USERNAME    = &H40000000???  ' use internal username & password


'//
'// flags for InternetCanonicalizeUrl() and InternetCombineUrl()
'//

%ICU_NO_ENCODE          = &H20000000??? ' Don't convert unsafe characters to escape sequence
%ICU_DECODE             = &H10000000??? ' Convert %XX escape sequences to characters
%ICU_NO_META            = &H08000000??? ' Don't convert .. etc. meta path sequences
%ICU_ENCODE_SPACES_ONLY = &H04000000??? ' Encode spaces only
%ICU_BROWSER_MODE       = &H02000000??? ' Special encode/decode rules for browser
%ICU_ENCODE_PERCENT     = &H00001000??? ' Encode any percent (ASCII &H25) signs
                                        ' (default is to not encode percent).

DECLARE FUNCTION InternetOpenA IMPORT "WININET.DLL" ALIAS "InternetOpenA" ( _
   BYREF lpszAgent AS ASCIIZ _                          ' __in_opt LPCSTR lpszAgent
 , BYVAL dwAccessType AS DWORD _                        ' __in DWORD dwAccessType
 , BYREF lpszProxy AS ASCIIZ _                          ' __in_opt LPCSTR lpszProxy
 , BYREF lpszProxyBypass AS ASCIIZ _                    ' __in_opt LPCSTR lpszProxyBypass
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION InternetOpenW IMPORT "WININET.DLL" ALIAS "InternetOpenW" ( _
   BYREF lpszAgent AS WSTRINGZ _                        ' __in_opt LPCSTR lpszAgent
 , BYVAL dwAccessType AS DWORD _                        ' __in DWORD dwAccessType
 , BYREF lpszProxy AS WSTRINGZ _                        ' __in_opt LPCWSTR lpszProxy
 , BYREF lpszProxyBypass AS WSTRINGZ _                  ' __in_opt LPCWSTR lpszProxyBypass
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO InternetOpen = InternetOpenW
#ELSE
   MACRO InternetOpen = InternetOpenA
#ENDIF

'//
'// access types for InternetOpen()
'//

%INTERNET_OPEN_TYPE_PRECONFIG                   = 0 ' use registry configuration
%INTERNET_OPEN_TYPE_DIRECT                      = 1 ' direct to net
%INTERNET_OPEN_TYPE_PROXY                       = 3 ' via named proxy
%INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY = 4 ' prevent using java/script/INS

'//
'// old names for access types
'//

%PRE_CONFIG_INTERNET_ACCESS  = %INTERNET_OPEN_TYPE_PRECONFIG
%LOCAL_INTERNET_ACCESS       = %INTERNET_OPEN_TYPE_DIRECT
%CERN_PROXY_INTERNET_ACCESS  = %INTERNET_OPEN_TYPE_PROXY

DECLARE FUNCTION InternetCloseHandle IMPORT "WININET.DLL" ALIAS "InternetCloseHandle" ( _
   BYVAL hInternet AS DWORD _                       ' __in HINTERNET hInternet
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetConnectA IMPORT "WININET.DLL" ALIAS "InternetConnectA" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYREF lpszServerName AS ASCIIZ _                     ' __in LPCSTR lpszServerName
 , BYVAL nServerPort AS WORD _                          ' __in INTERNET_PORT nServerPort
 , BYREF lpszUserName AS ASCIIZ _                       ' __in_opt LPCSTR lpszUserName
 , BYREF lpszPassword AS ASCIIZ _                       ' __in_opt LPCSTR lpszPassword
 , BYVAL dwService AS DWORD _                           ' __in DWORD dwService
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION InternetConnectW IMPORT "WININET.DLL" ALIAS "InternetConnectW" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYREF lpszServerName AS WSTRINGZ _                   ' __in LPCWSTR lpszServerName
 , BYVAL nServerPort AS WORD _                          ' __in INTERNET_PORT nServerPort
 , BYREF lpszUserName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpszUserName
 , BYREF lpszPassword AS WSTRINGZ _                     ' __in_opt LPCWSTR lpszPassword
 , BYVAL dwService AS DWORD _                           ' __in DWORD dwService
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO InternetConnect = InternetConnectW
#ELSE
   MACRO InternetConnect = InternetConnectA
#ENDIF

'//
'// service types for InternetConnect()
'//

%INTERNET_SERVICE_URL    = 0  ' not listed in current wininet.h
%INTERNET_SERVICE_FTP    = 1
%INTERNET_SERVICE_GOPHER = 2
%INTERNET_SERVICE_HTTP   = 3

DECLARE FUNCTION InternetOpenUrlA IMPORT "WININET.DLL" ALIAS "InternetOpenUrlA" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszHeaders AS ASCIIZ _                        ' __in LPCSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION InternetOpenUrlW IMPORT "WININET.DLL" ALIAS "InternetOpenUrlW" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszHeaders AS WSTRINGZ _                      ' __in LPCWSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO InternetOpenUrl = InternetOpenUrlW
#ELSE
   MACRO InternetOpenUrl = InternetOpenUrlA
#ENDIF

DECLARE FUNCTION InternetReadFile IMPORT "WININET.DLL" ALIAS "InternetReadFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYVAL lpBuffer AS BYTE PTR _                         ' __out LPVOID lpBuffer
 , BYVAL dwNumberOfBytesToRead AS DWORD _               ' __in DWORD dwNumberOfBytesToRead
 , BYREF lpdwNumberOfBytesRead AS DWORD _               ' __out LPDWORD lpdwNumberOfBytesRead
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetReadFileExA IMPORT "WININET.DLL" ALIAS "InternetReadFileExA" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYREF lpBuffersOut AS INTERNET_BUFFERSA _            ' __out LPINTERNET_BUFFERSA lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetReadFileExW IMPORT "WININET.DLL" ALIAS "InternetReadFileExW" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYREF lpBuffersOut AS INTERNET_BUFFERSW _            ' __out LPINTERNET_BUFFERSW lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetReadFileEx = InternetReadFileExW
#ELSE
   MACRO InternetReadFileEx = InternetReadFileExA
#ENDIF

'//
'// flags for InternetReadFileEx()
'//

%IRF_ASYNC       = %WININET_API_FLAG_ASYNC
%IRF_SYNC        = %WININET_API_FLAG_SYNC
%IRF_USE_CONTEXT = %WININET_API_FLAG_USE_CONTEXT
%IRF_NO_WAIT     = &H00000008???

DECLARE FUNCTION InternetSetFilePointer IMPORT "WININET.DLL" ALIAS "InternetSetFilePointer" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYVAL lDistanceToMove AS LONG _                      ' __in LONG lDistanceToMove
 , BYREF lpDistanceToMoveHigh AS LONG _                 ' __inout_opt PLONG lpDistanceToMoveHigh
 , BYVAL dwMoveMethod AS DWORD _                        ' __in DWORD dwMoveMethod
 , BYVAL dwContext AS DWORD _                           ' __in DWORD_PTR dwContext
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InternetWriteFile IMPORT "WININET.DLL" ALIAS "InternetWriteFile" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYVAL lpBuffer AS DWORD _                            ' __in LPCVOID lpBuffer
 , BYVAL dwNumberOfBytesToWrite AS DWORD _              ' __in DWORD dwNumberOfBytesToWrite
 , BYREF lpdwNumberOfBytesWritten AS DWORD _            ' __out LPDWORD lpdwNumberOfBytesWritten
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetQueryDataAvailable IMPORT "WININET.DLL" ALIAS "InternetQueryDataAvailable" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYREF lpdwNumberOfBytesAvailable AS DWORD _          ' __out_opt LPDWORD lpdwNumberOfBytesAvailable
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetFindNextFileA LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileA" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetFindNextFileA IMPORT "WININET.DLL" ALIAS "InternetFindNextFileA" ( _
   BYVAL hFind AS DWORD  _                              ' __in HINTERNET hFind
 , BYREF lpvFindData AS ANY _                           ' __out LPVOID lpvFindData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetFindNextFileW LIB "WinINet.dll" _
   ALIAS "InternetFindNextFileW" _
   ( _
    BYVAL hFind AS DWORD, _         ' in
    BYVAL lpvFindData AS BYTE PTR _ ' out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetFindNextFileW IMPORT "WININET.DLL" ALIAS "InternetFindNextFileW" ( _
   BYVAL hFind AS DWORD _                               ' __in HINTERNET hFind
 , BYREF lpvFindData AS ANY _                           ' __out LPVOID lpvFindData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO InternetFindNextFile = InternetFindNextFileW
#ELSE
   MACRO InternetFindNextFile = InternetFindNextFileA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetQueryOptionA LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionA" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetQueryOptionA IMPORT "WININET.DLL" ALIAS "InternetQueryOptionA" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetQueryOptionW LIB "WinINet.dll" _
   ALIAS "InternetQueryOptionW" _
   ( _
    BYVAL hInternet AS DWORD, _        ' in
    BYVAL dwOption AS DWORD, _         ' in
    BYVAL lpBuffer AS BYTE PTR, _      ' out
    lpdwBufferLength AS DWORD _        ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION InternetQueryOptionW IMPORT "WININET.DLL" ALIAS "InternetQueryOptionW" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO InternetQueryOption = InternetQueryOptionW
#ELSE
   MACRO InternetQueryOption = InternetQueryOptionA
#ENDIF

DECLARE FUNCTION InternetSetOptionA IMPORT "WININET.DLL" ALIAS "InternetSetOptionA" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD _                            ' __in_opt LPVOID lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSetOptionW IMPORT "WININET.DLL" ALIAS "InternetSetOptionW" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD  _                           ' __in_opt LPVOID lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSetOption = InternetSetOptionW
#ELSE
   MACRO InternetSetOption = InternetSetOptionA
#ENDIF

DECLARE FUNCTION InternetSetOptionExA IMPORT "WININET.DLL" ALIAS "InternetSetOptionExA" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD _                            ' __in_opt LPVOID lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSetOptionExW IMPORT "WININET.DLL" ALIAS "InternetSetOptionExW" ( _
   BYVAL hInternet AS DWORD _                           ' __in_opt HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD _                            ' __in_opt LPVOID lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSetOptionEx = InternetSetOptionExW
#ELSE
   MACRO InternetSetOptionEx = InternetSetOptionExA
#ENDIF

DECLARE FUNCTION InternetLockRequestFile IMPORT "WININET.DLL" ALIAS "InternetLockRequestFile" ( _
   BYVAL hInternet AS LONG _                            ' __in  HINTERNET hInternet
 , BYREF lphLockRequestInfo AS DWORD _                  ' __out HANDLE * lphLockRequestInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetUnlockRequestFile IMPORT "WININET.DLL" ALIAS "InternetUnlockRequestFile" ( _
   BYVAL hLockRequestInfo AS DWORD _                    ' __in HANDLE hLockRequestInfo
 ) AS LONG                                              ' BOOL

'//
'// flags for InternetSetOptionEx()
'//

%ISO_GLOBAL      = &H00000001???  ' modify option globally
%ISO_REGISTRY    = &H00000002???  ' write option to registry (where applicable)

%ISO_VALID_FLAGS = %ISO_GLOBAL OR %ISO_REGISTRY

'//
'// options manifests for Internet{Query|Set}Option
'//

%INTERNET_OPTION_CALLBACK                = 1
%INTERNET_OPTION_CONNECT_TIMEOUT         = 2
%INTERNET_OPTION_CONNECT_RETRIES         = 3
%INTERNET_OPTION_CONNECT_BACKOFF         = 4
%INTERNET_OPTION_SEND_TIMEOUT            = 5
%INTERNET_OPTION_CONTROL_SEND_TIMEOUT    = %INTERNET_OPTION_SEND_TIMEOUT
%INTERNET_OPTION_RECEIVE_TIMEOUT         = 6
%INTERNET_OPTION_CONTROL_RECEIVE_TIMEOUT = %INTERNET_OPTION_RECEIVE_TIMEOUT
%INTERNET_OPTION_DATA_SEND_TIMEOUT       = 7
%INTERNET_OPTION_DATA_RECEIVE_TIMEOUT    = 8
%INTERNET_OPTION_HANDLE_TYPE             = 9
%INTERNET_OPTION_LISTEN_TIMEOUT          = 11
%INTERNET_OPTION_READ_BUFFER_SIZE        = 12
%INTERNET_OPTION_WRITE_BUFFER_SIZE       = 13

%INTERNET_OPTION_ASYNC_ID                = 15
%INTERNET_OPTION_ASYNC_PRIORITY          = 16

%INTERNET_OPTION_PARENT_HANDLE           = 21
%INTERNET_OPTION_KEEP_CONNECTION         = 22
%INTERNET_OPTION_REQUEST_FLAGS           = 23
%INTERNET_OPTION_EXTENDED_ERROR          = 24

%INTERNET_OPTION_OFFLINE_MODE            = 26
%INTERNET_OPTION_CACHE_STREAM_HANDLE     = 27
%INTERNET_OPTION_USERNAME                = 28
%INTERNET_OPTION_PASSWORD                = 29
%INTERNET_OPTION_ASYNC                   = 30
%INTERNET_OPTION_SECURITY_FLAGS          = 31
%INTERNET_OPTION_SECURITY_CERTIFICATE_STRUCT = 32
%INTERNET_OPTION_DATAFILE_NAME           = 33
%INTERNET_OPTION_URL                     = 34
%INTERNET_OPTION_SECURITY_CERTIFICATE    = 35
%INTERNET_OPTION_SECURITY_KEY_BITNESS    = 36
%INTERNET_OPTION_REFRESH                 = 37
%INTERNET_OPTION_PROXY                   = 38
%INTERNET_OPTION_SETTINGS_CHANGED        = 39
%INTERNET_OPTION_VERSION                 = 40
%INTERNET_OPTION_USER_AGENT              = 41
%INTERNET_OPTION_END_BROWSER_SESSION     = 42
%INTERNET_OPTION_PROXY_USERNAME          = 43
%INTERNET_OPTION_PROXY_PASSWORD          = 44
%INTERNET_OPTION_CONTEXT_VALUE           = 45
%INTERNET_OPTION_CONNECT_LIMIT           = 46
%INTERNET_OPTION_SECURITY_SELECT_CLIENT_CERT = 47
%INTERNET_OPTION_POLICY                  = 48
%INTERNET_OPTION_DISCONNECTED_TIMEOUT    = 49
%INTERNET_OPTION_CONNECTED_STATE         = 50
%INTERNET_OPTION_IDLE_STATE              = 51
%INTERNET_OPTION_OFFLINE_SEMANTICS       = 52
%INTERNET_OPTION_SECONDARY_CACHE_KEY     = 53
%INTERNET_OPTION_CALLBACK_FILTER         = 54
%INTERNET_OPTION_CONNECT_TIME            = 55
%INTERNET_OPTION_SEND_THROUGHPUT         = 56
%INTERNET_OPTION_RECEIVE_THROUGHPUT      = 57
%INTERNET_OPTION_REQUEST_PRIORITY        = 58
%INTERNET_OPTION_HTTP_VERSION            = 59
%INTERNET_OPTION_RESET_URLCACHE_SESSION  = 60
%INTERNET_OPTION_ERROR_MASK              = 62
%INTERNET_OPTION_FROM_CACHE_TIMEOUT      = 63
%INTERNET_OPTION_BYPASS_EDITED_ENTRY     = 64

%INTERNET_OPTION_HTTP_DECODING           = 65

%INTERNET_OPTION_DIAGNOSTIC_SOCKET_INFO   = 67
%INTERNET_OPTION_CODEPAGE                 = 68
%INTERNET_OPTION_CACHE_TIMESTAMPS         = 69
%INTERNET_OPTION_DISABLE_AUTODIAL         = 70
%INTERNET_OPTION_MAX_CONNS_PER_SERVER     = 73
%INTERNET_OPTION_MAX_CONNS_PER_1_0_SERVER = 74
%INTERNET_OPTION_PER_CONNECTION_OPTION    = 75
%INTERNET_OPTION_DIGEST_AUTH_UNLOAD       = 76
%INTERNET_OPTION_IGNORE_OFFLINE           = 77
%INTERNET_OPTION_IDENTITY                 = 78
%INTERNET_OPTION_REMOVE_IDENTITY          = 79
%INTERNET_OPTION_ALTER_IDENTITY           = 80
%INTERNET_OPTION_SUPPRESS_BEHAVIOR        = 81
%INTERNET_OPTION_AUTODIAL_MODE            = 82
%INTERNET_OPTION_AUTODIAL_CONNECTION      = 83
%INTERNET_OPTION_CLIENT_CERT_CONTEXT      = 84
%INTERNET_OPTION_AUTH_FLAGS               = 85
%INTERNET_OPTION_COOKIES_3RD_PARTY        = 86
%INTERNET_OPTION_DISABLE_PASSPORT_AUTH    = 87
%INTERNET_OPTION_SEND_UTF8_SERVERNAME_TO_PROXY = 88
%INTERNET_OPTION_EXEMPT_CONNECTION_LIMIT  = 89
%INTERNET_OPTION_ENABLE_PASSPORT_AUTH     = 90

%INTERNET_OPTION_HIBERNATE_INACTIVE_WORKER_THREADS = 91
%INTERNET_OPTION_ACTIVATE_WORKER_THREADS           = 92
%INTERNET_OPTION_RESTORE_WORKER_THREAD_DEFAULTS    = 93
%INTERNET_OPTION_SOCKET_SEND_BUFFER_LENGTH         = 94
%INTERNET_OPTION_PROXY_SETTINGS_CHANGED            = 95

%INTERNET_OPTION_DATAFILE_EXT                      = 96

%INTERNET_OPTION_CODEPAGE_PATH               = 100
%INTERNET_OPTION_CODEPAGE_EXTRA              = 101
%INTERNET_OPTION_IDN                         = 102
%INTERNET_OPTION_MAX_CONNS_PER_PROXY         = 103
%INTERNET_OPTION_SUPPRESS_SERVER_AUTH        = 104
%INTERNET_OPTION_SERVER_CERT_CHAIN_CONTEXT   = 105

%INTERNET_FIRST_OPTION  = %INTERNET_OPTION_CALLBACK
%INTERNET_LAST_OPTION   = %INTERNET_OPTION_SERVER_CERT_CHAIN_CONTEXT

'//
'// values for INTERNET_OPTION_PRIORITY
'//

%INTERNET_PRIORITY_FOREGROUND = 1000

'//
'// handle types
'//

%INTERNET_HANDLE_TYPE_INTERNET         = 1
%INTERNET_HANDLE_TYPE_CONNECT_FTP      = 2
%INTERNET_HANDLE_TYPE_CONNECT_GOPHER   = 3
%INTERNET_HANDLE_TYPE_CONNECT_HTTP     = 4
%INTERNET_HANDLE_TYPE_FTP_FIND         = 5
%INTERNET_HANDLE_TYPE_FTP_FIND_HTML    = 6
%INTERNET_HANDLE_TYPE_FTP_FILE         = 7
%INTERNET_HANDLE_TYPE_FTP_FILE_HTML    = 8
%INTERNET_HANDLE_TYPE_GOPHER_FIND      = 9
%INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML = 10
%INTERNET_HANDLE_TYPE_GOPHER_FILE      = 11
%INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML = 12
%INTERNET_HANDLE_TYPE_HTTP_REQUEST     = 13
%INTERNET_HANDLE_TYPE_FILE_REQUEST     = 14

'//
'// values for INTERNET_OPTION_AUTH_FLAGS
'//
%AUTH_FLAG_DISABLE_NEGOTIATE          = &H00000001???
%AUTH_FLAG_ENABLE_NEGOTIATE           = &H00000002???
%AUTH_FLAG_DISABLE_BASIC_CLEARCHANNEL = &H00000004???

'//
'// values for INTERNET_OPTION_SECURITY_FLAGS
'//

'// query only
%SECURITY_FLAG_SECURE                    = &H00000001??? ' can query only
%SECURITY_FLAG_STRENGTH_WEAK             = &H10000000???
%SECURITY_FLAG_STRENGTH_MEDIUM           = &H40000000???
%SECURITY_FLAG_STRENGTH_STRONG           = &H20000000???
%SECURITY_FLAG_UNKNOWNBIT                = &H80000000???
%SECURITY_FLAG_FORTEZZA                  = &H08000000???
%SECURITY_FLAG_NORMALBITNESS             = %SECURITY_FLAG_STRENGTH_WEAK

'// The following are unused
%SECURITY_FLAG_SSL                       = &H00000002???
%SECURITY_FLAG_SSL3                      = &H00000004???
%SECURITY_FLAG_PCT                       = &H00000008???
%SECURITY_FLAG_PCT4                      = &H00000010???
%SECURITY_FLAG_IETFSSL4                  = &H00000020???

'// The following are for backwards compatability only.
%SECURITY_FLAG_40BIT                     = %SECURITY_FLAG_STRENGTH_WEAK
%SECURITY_FLAG_128BIT                    = %SECURITY_FLAG_STRENGTH_STRONG
%SECURITY_FLAG_56BIT                     = %SECURITY_FLAG_STRENGTH_MEDIUM

'// setable flags
%SECURITY_FLAG_IGNORE_REVOCATION         = &H00000080???
%SECURITY_FLAG_IGNORE_UNKNOWN_CA         = &H00000100???
%SECURITY_FLAG_IGNORE_WRONG_USAGE        = &H00000200???

%SECURITY_FLAG_IGNORE_CERT_CN_INVALID    = %INTERNET_FLAG_IGNORE_CERT_CN_INVALID
%SECURITY_FLAG_IGNORE_CERT_DATE_INVALID  = %INTERNET_FLAG_IGNORE_CERT_DATE_INVALID

%SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTPS  = %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS
%SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTP   = %INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP

%SECURITY_SET_MASK       = %SECURITY_FLAG_IGNORE_REVOCATION  OR _
                           %SECURITY_FLAG_IGNORE_UNKNOWN_CA  OR _
                           %SECURITY_FLAG_IGNORE_CERT_CN_INVALID  OR _
                           %SECURITY_FLAG_IGNORE_CERT_DATE_INVALID  OR _
                           %SECURITY_FLAG_IGNORE_WRONG_USAGE

'// valid autodial modes
%AUTODIAL_MODE_NEVER              = 1
%AUTODIAL_MODE_ALWAYS             = 2
%AUTODIAL_MODE_NO_NETWORK_PRESENT = 4

DECLARE FUNCTION InternetGetLastResponseInfoA IMPORT "WININET.DLL" ALIAS "InternetGetLastResponseInfoA" ( _
   BYREF lpdwError AS DWORD _                           ' __out LPDWORD lpdwError
 , BYREF lpszBuffer AS ASCIIZ _                         ' __out LPSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetLastResponseInfoW IMPORT "WININET.DLL" ALIAS "InternetGetLastResponseInfoW" ( _
   BYREF lpdwError AS DWORD _                           ' __out LPDWORD lpdwError
 , BYREF lpszBuffer AS WSTRINGZ _                       ' __out LPWSTR lpszBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetLastResponseInfo = InternetGetLastResponseInfoW
#ELSE
   MACRO InternetGetLastResponseInfo = InternetGetLastResponseInfoA
#ENDIF

'//
'// callback function for InternetSetStatusCallback
'//

'typedef
'VOID
'(CALLBACK * INTERNET_STATUS_CALLBACK)(
'    __in HINTERNET hInternet,
'    __in_opt DWORD_PTR dwContext,
'    __in DWORD dwInternetStatus,
'    __in_opt LPVOID lpvStatusInformation,
'    __in DWORD dwStatusInformationLength
'    );

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetSetStatusCallbackA LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackA" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetSetStatusCallbackA IMPORT "WININET.DLL" ALIAS "InternetSetStatusCallback" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , OPTIONAL BYVAL lpfnInternetCallback AS DWORD _       ' __in_opt INTERNET_STATUS_CALLBACK lpfnInternetCallback
 ) AS DWORD                                             ' INTERNET_STATUS_CALLBACK
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetSetStatusCallbackW LIB "WinINet.dll" _
   ALIAS "InternetSetStatusCallbackW" _
   ( _
    BYVAL hInternet AS DWORD, _              ' in
    BYVAL lpfnInternetCallback AS DWORD _    ' in
   ) _
   AS DWORD
#ELSE
DECLARE FUNCTION InternetSetStatusCallbackW IMPORT "WININET.DLL" ALIAS "InternetSetStatusCallbackW" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , OPTIONAL BYVAL lpfnInternetCallback AS DWORD _       ' __in_opt INTERNET_STATUS_CALLBACK lpfnInternetCallback
 ) AS DWORD                                             ' INTERNET_STATUS_CALLBACK
#ENDIF

#IF %DEF(%UNICODE)
   MACRO InternetSetStatusCallback = InternetSetStatusCallbackW
#ELSE
   MACRO InternetSetStatusCallback = InternetSetStatusCallbackA
#ENDIF

'//
'// status manifests for Internet status callback
'//

%INTERNET_STATUS_RESOLVING_NAME        = 10
%INTERNET_STATUS_NAME_RESOLVED         = 11
%INTERNET_STATUS_CONNECTING_TO_SERVER  = 20
%INTERNET_STATUS_CONNECTED_TO_SERVER   = 21
%INTERNET_STATUS_SENDING_REQUEST       = 30
%INTERNET_STATUS_REQUEST_SENT          = 31
%INTERNET_STATUS_RECEIVING_RESPONSE    = 40
%INTERNET_STATUS_RESPONSE_RECEIVED     = 41
%INTERNET_STATUS_CTL_RESPONSE_RECEIVED = 42
%INTERNET_STATUS_PREFETCH              = 43
%INTERNET_STATUS_CLOSING_CONNECTION    = 50
%INTERNET_STATUS_CONNECTION_CLOSED     = 51
%INTERNET_STATUS_HANDLE_CREATED        = 60
%INTERNET_STATUS_HANDLE_CLOSING        = 70
%INTERNET_STATUS_DETECTING_PROXY       = 80
%INTERNET_STATUS_REQUEST_COMPLETE      = 100
%INTERNET_STATUS_REDIRECT              = 110
%INTERNET_STATUS_INTERMEDIATE_RESPONSE = 120
%INTERNET_STATUS_USER_INPUT_REQUIRED   = 140
%INTERNET_STATUS_STATE_CHANGE          = 200
%INTERNET_STATUS_COOKIE_SENT           = 320
%INTERNET_STATUS_COOKIE_RECEIVED       = 321
%INTERNET_STATUS_PRIVACY_IMPACTED      = 324
%INTERNET_STATUS_P3P_HEADER            = 325
%INTERNET_STATUS_P3P_POLICYREF         = 326
%INTERNET_STATUS_COOKIE_HISTORY        = 327

'//
'// the following can be indicated in a state change notification:
'//

%INTERNET_STATE_CONNECTED                = &H00000001???  ' connected state (mutually exclusive with disconnected)
%INTERNET_STATE_DISCONNECTED             = &H00000002???  ' disconnected from network
%INTERNET_STATE_DISCONNECTED_BY_USER     = &H00000010???  ' disconnected by user request
%INTERNET_STATE_IDLE                     = &H00000100???  ' no network requests being made (by Wininet)
%INTERNET_STATE_BUSY                     = &H00000200???  ' network requests being made (by Wininet)

'//
'// the following values are used for cookie state:
'//

' InternetCookieState enum
%COOKIE_STATE_UNKNOWN   = &H0
%COOKIE_STATE_ACCEPT    = &H1
%COOKIE_STATE_PROMPT    = &H2
%COOKIE_STATE_LEASH     = &H3
%COOKIE_STATE_DOWNGRADE = &H4
%COOKIE_STATE_REJECT    = &H5
%COOKIE_STATE_MAX       = %COOKIE_STATE_REJECT

' // Size = 28 bytes
TYPE IncomingCookieState DWORD
   cSession    AS LONG         ' int
   cPersistent AS LONG         ' int
   cAccepted   AS LONG         ' int
   cLeashed    AS LONG         ' int
   cDowngraded AS LONG         ' int
   cBlocked    AS LONG         ' int
   pszLocation AS ASCIIZ PTR   ' const char *pszLocation
END TYPE

' // Size = 12 bytes
TYPE OutgoingCookieState DWORD
   cSent       AS LONG         ' int
   cSuppressed AS LONG         ' int
   pszLocation AS ASCIIZ PTR   ' const char *pszLocation
END TYPE

' // Size = 16 bytes
TYPE InternetCookieHistory DWORD
   fAccepted   AS LONG   ' BOOL
   fLeashed    AS LONG   ' BOOL
   fDowngraded AS LONG   ' BOOL
   fRejected   AS LONG   ' BOOL
END TYPE

' // Size = 8 bytes
TYPE CookieDecision DWORD
   dwCookieState AS DWORD   ' DWORD
   fAllowSession AS LONG    ' BOOL
END TYPE

'//
'// if the following value is returned by InternetSetStatusCallback, then
'// probably an invalid (non-code) address was supplied for the callback
'//

'#define INTERNET_INVALID_STATUS_CALLBACK        ((INTERNET_STATUS_CALLBACK)(-1L))
%INTERNET_INVALID_STATUS_CALLBACK = &HFFFFFFFF???

'//
'// FTP
'//

'//
'// manifests
'//

%FTP_TRANSFER_TYPE_UNKNOWN    = &H00000000???
%FTP_TRANSFER_TYPE_ASCII      = &H00000001???
%FTP_TRANSFER_TYPE_BINARY     = &H00000002???

%FTP_TRANSFER_TYPE_MASK       = %FTP_TRANSFER_TYPE_ASCII OR %FTP_TRANSFER_TYPE_BINARY

'//
'// prototypes
'//

DECLARE FUNCTION FtpFindFirstFileA IMPORT "WININET.DLL" ALIAS "FtpFindFirstFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszSearchFile AS ASCIIZ _                     ' __in_opt LPCSTR lpszSearchFile
 , BYREF lpFindFileData AS WIN32_FIND_DATAA _           ' __out_opt LPWIN32_FIND_DATAA lpFindFileData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION FtpFindFirstFileW IMPORT "WININET.DLL" ALIAS "FtpFindFirstFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszSearchFile AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszSearchFile
 , BYREF lpFindFileData AS WIN32_FIND_DATAW _           ' __out_opt LPWIN32_FIND_DATAW lpFindFileData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO FtpFindFirstFile = FtpFindFirstFileW
#ELSE
   MACRO FtpFindFirstFile = FtpFindFirstFileA
#ENDIF

DECLARE FUNCTION FtpGetFileA IMPORT "WININET.DLL" ALIAS "FtpGetFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszRemoteFile AS ASCIIZ _                     ' __in LPCSTR lpszRemoteFile
 , BYREF lpszNewFile AS ASCIIZ _                        ' __in LPCSTR lpszNewFile
 , BYVAL fFailIfExists AS LONG _                        ' __in BOOL fFailIfExists
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpGetFileW IMPORT "WININET.DLL" ALIAS "FtpGetFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszRemoteFile AS WSTRINGZ _                   ' __in LPCWSTR lpszRemoteFile
 , BYREF lpszNewFile AS WSTRINGZ  _                     ' __in LPCWSTR lpszNewFile
 , BYVAL fFailIfExists AS LONG _                        ' __in BOOL fFailIfExists
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpGetFile = FtpGetFileW
#ELSE
   MACRO FtpGetFile = FtpGetFileA
#ENDIF

DECLARE FUNCTION FtpPutFileA IMPORT "WININET.DLL" ALIAS "FtpPutFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocalFile AS ASCIIZ _                      ' __in LPCSTR lpszLocalFile
 , BYREF lpszNewRemoteFile AS ASCIIZ _                  ' __in LPCSTR lpszNewRemoteFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpPutFileW IMPORT "WININET.DLL" ALIAS "FtpPutFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocalFile AS WSTRINGZ _                    ' __in LPCWSTR lpszLocalFile
 , BYREF lpszNewRemoteFile AS WSTRINGZ _                ' __in LPCWSTR lpszNewRemoteFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpPutFile = FtpPutFileW
#ELSE
   MACRO FtpPutFile = FtpPutFileA
#ENDIF

DECLARE FUNCTION FtpGetFileEx IMPORT "WININET.DLL" ALIAS "FtpGetFileEx" ( _
   BYVAL hFtpSession AS DWORD _                         ' __in HINTERNET hFtpSession
 , BYREF lpszRemoteFile AS ASCIIZ _                     ' __in LPCSTR lpszRemoteFile
 , BYREF lpszNewFile AS WSTRINGZ _                      ' __in LPCWSTR lpszNewFile
 , BYVAL fFailIfExists AS LONG _                        ' __in BOOL fFailIfExists
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlagsAndAttributes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpPutFileEx IMPORT "WININET.DLL" ALIAS "FtpPutFileEx" ( _
   BYVAL hFtpSession AS DWORD _                         ' __in HINTERNET hFtpSession
 , BYREF lpszLocalFile AS WSTRINGZ _                    ' __in LPCWSTR lpszLocalFile
 , BYREF lpszNewRemoteFile AS ASCIIZ _                  ' __in LPCSTR lpszNewRemoteFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpDeleteFileA IMPORT "WININET.DLL" ALIAS "FtpDeleteFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPCSTR lpszFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpDeleteFileW IMPORT "WININET.DLL" ALIAS "FtpDeleteFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszFileName AS WSTRINGZ _                     ' __in LPCWSTR lpszFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpDeleteFile = FtpDeleteFileW
#ELSE
   MACRO FtpDeleteFile = FtpDeleteFileA
#ENDIF

DECLARE FUNCTION FtpRenameFileA IMPORT "WININET.DLL" ALIAS "FtpRenameFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszExisting AS ASCIIZ _                       ' __in LPCSTR lpszExisting
 , BYREF lpszNew AS ASCIIZ _                            ' __in LPCSTR lpszNew
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpRenameFileW IMPORT "WININET.DLL" ALIAS "FtpRenameFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszExisting AS WSTRINGZ _                     ' __in LPCWSTR lpszExisting
 , BYREF lpszNew AS WSTRINGZ _                          ' __in LPCWSTR lpszNew
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpRenameFile = FtpRenameFileW
#ELSE
   MACRO FtpRenameFile = FtpRenameFileA
#ENDIF

DECLARE FUNCTION FtpOpenFileA IMPORT "WININET.DLL" ALIAS "FtpOpenFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPCSTR lpszFileName
 , BYVAL dwAccess AS DWORD _                            ' __in DWORD dwAccess
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION FtpOpenFileW IMPORT "WININET.DLL" ALIAS "FtpOpenFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszFileName AS WSTRINGZ _                     ' __in LPCWSTR lpszFileName
 , BYVAL dwAccess AS DWORD _                            ' __in DWORD dwAccess
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO FtpOpenFile = FtpOpenFileW
#ELSE
   MACRO FtpOpenFile = FtpOpenFileA
#ENDIF

DECLARE FUNCTION FtpCreateDirectoryA IMPORT "WININET.DLL" ALIAS "FtpCreateDirectoryA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS ASCIIZ _                      ' __in LPCSTR lpszDirectory
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpCreateDirectoryW IMPORT "WININET.DLL" ALIAS "FtpCreateDirectoryW" ( _
   BYVAL hConnect AS DWORD  _                           ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS WSTRINGZ _                    ' __in LPCWSTR lpszDirectory
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpCreateDirectory = FtpCreateDirectoryW
#ELSE
   MACRO FtpCreateDirectory = FtpCreateDirectoryA
#ENDIF

DECLARE FUNCTION FtpRemoveDirectoryA IMPORT "WININET.DLL" ALIAS "FtpRemoveDirectoryA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS ASCIIZ _                      ' __in LPCSTR lpszDirectory
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpRemoveDirectoryW IMPORT "WININET.DLL" ALIAS "FtpRemoveDirectoryW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS WSTRINGZ _                    ' __in LPCWSTR lpszDirectory
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpRemoveDirectory = FtpRemoveDirectoryW
#ELSE
   MACRO FtpRemoveDirectory = FtpRemoveDirectoryA
#ENDIF

DECLARE FUNCTION FtpSetCurrentDirectoryA IMPORT "WININET.DLL" ALIAS "FtpSetCurrentDirectoryA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS ASCIIZ _                      ' __in LPCSTR lpszDirectory
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpSetCurrentDirectoryW IMPORT "WININET.DLL" ALIAS "FtpSetCurrentDirectoryW" ( _
   BYVAL hConnect AS DWORD  _                           ' __in HINTERNET hConnect
 , BYREF lpszDirectory AS WSTRINGZ _                    ' __in LPCWSTR lpszDirectory
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpSetCurrentDirectory = FtpSetCurrentDirectoryW
#ELSE
   MACRO FtpSetCurrentDirectory = FtpSetCurrentDirectoryA
#ENDIF

DECLARE FUNCTION FtpGetCurrentDirectoryA IMPORT "WININET.DLL" ALIAS "FtpGetCurrentDirectoryA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszCurrentDirectory AS ASCIIZ _               ' __out LPSTR lpszCurrentDirectory
 , BYREF lpdwCurrentDirectory AS DWORD _                ' __inout LPDWORD lpdwCurrentDirectory
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpGetCurrentDirectoryW IMPORT "WININET.DLL" ALIAS "FtpGetCurrentDirectoryW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszCurrentDirectory AS WSTRINGZ _             ' __out LPWSTR lpszCurrentDirectory
 , BYREF lpdwCurrentDirectory AS DWORD _                ' __inout LPDWORD lpdwCurrentDirectory
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpGetCurrentDirectory = FtpGetCurrentDirectoryW
#ELSE
   MACRO FtpGetCurrentDirectory = FtpGetCurrentDirectoryA
#ENDIF

DECLARE FUNCTION FtpCommandA IMPORT "WININET.DLL" ALIAS "FtpCommandA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYVAL fExpectResponse AS LONG _                      ' __in BOOL fExpectResponse
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpszCommand AS ASCIIZ _                        ' __in LPCSTR lpszCommand
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 , OPTIONAL BYREF phFtpCommand AS DWORD _               ' __out_opt HINTERNET *phFtpCommand
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FtpCommandW IMPORT "WININET.DLL" ALIAS "FtpCommandW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYVAL fExpectResponse AS LONG _                      ' __in BOOL fExpectResponse
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpszCommand AS WSTRINGZ _                      ' __in LPCWSTR lpszCommand
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 , OPTIONAL BYREF phFtpCommand AS DWORD _               ' __out_opt HINTERNET *phFtpCommand
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FtpCommand = FtpCommandW
#ELSE
   MACRO FtpCommand = FtpCommandA
#ENDIF

DECLARE FUNCTION FtpGetFileSize IMPORT "WININET.DLL" AlIAS "FtpGetFileSize" ( _
   BYVAL hFile AS DWORD  _                              ' __in HINTERNET hFile
 , OPTIONAL BYREF lpdwFileSizeHigh AS DWORD _           ' __out_opt LPDWORD lpdwFileSizeHigh
 ) AS DWORD                                             ' DWORD

'//
'// Gopher
'//

'//
'// manifests
'//

'//
'// string field lengths (in characters, not bytes)
'//

%MAX_GOPHER_DISPLAY_TEXT     = 128
%MAX_GOPHER_SELECTOR_TEXT    = 256
%MAX_GOPHER_HOST_NAME        = %INTERNET_MAX_HOST_NAME_LENGTH
%MAX_GOPHER_LOCATOR_LENGTH   = 1                                   _
                               + %MAX_GOPHER_DISPLAY_TEXT          _
                               + 1                                 _
                               + %MAX_GOPHER_SELECTOR_TEXT         _
                               + 1                                 _
                               + %MAX_GOPHER_HOST_NAME             _
                               + 1                                 _
                               + %INTERNET_MAX_PORT_NUMBER_LENGTH  _
                               + 1                                 _
                               + 1                                 _
                               + 2

'//
'// structures/types
'//

'//
'// GOPHER_FIND_DATA - returns the results of a GopherFindFirstFile()/
'// InternetFindNextFile() request
'//

' // Size = 808 bytes
TYPE GOPHER_FIND_DATAA DWORD
   DisplayString        AS ASCIIZ * %MAX_GOPHER_DISPLAY_TEXT + 1     ' CHAR[MAX_GOPHER_DISPLAY_TEXT]
   GopherType           AS DWORD                                     ' DWORD
   SizeLow              AS DWORD                                     ' DWORD
   SizeHigh             AS DWORD                                     ' DWORD
   LastModificationTime AS FILETIME                                  ' FILETIME
   Locator              AS ASCIIZ * %MAX_GOPHER_LOCATOR_LENGTH + 1   ' CHAR[MAX_GOPHER_LOCATOR_LENGTH]
END TYPE

' // Size = 1588 bytes
TYPE GOPHER_FIND_DATAW DWORD
   DisplayString        AS WSTRINGZ * %MAX_GOPHER_DISPLAY_TEXT + 1     ' WCHAR[MAX_GOPHER_DISPLAY_TEXT]
   GopherType           AS DWORD                                       ' DWORD
   SizeLow              AS DWORD                                       ' DWORD
   SizeHigh             AS DWORD                                       ' DWORD
   LastModificationTime AS FILETIME                                    ' FILETIME
   Locator              AS WSTRINGZ * %MAX_GOPHER_LOCATOR_LENGTH + 1   ' MAX_GOPHER_LOCATOR_LENGTH
END TYPE

#IF %DEF(%UNICODE)
   MACRO GOPHER_FIND_DATA = GOPHER_FIND_DATAW
#ELSE
   MACRO GOPHER_FIND_DATA = GOPHER_FIND_DATAA
#ENDIF

'//
'// manifests for GopherType
'//

%GOPHER_TYPE_TEXT_FILE       = &H00000001???
%GOPHER_TYPE_DIRECTORY       = &H00000002???
%GOPHER_TYPE_CSO             = &H00000004???
%GOPHER_TYPE_ERROR           = &H00000008???
%GOPHER_TYPE_MAC_BINHEX      = &H00000010???
%GOPHER_TYPE_DOS_ARCHIVE     = &H00000020???
%GOPHER_TYPE_UNIX_UUENCODED  = &H00000040???
%GOPHER_TYPE_INDEX_SERVER    = &H00000080???
%GOPHER_TYPE_TELNET          = &H00000100???
%GOPHER_TYPE_BINARY          = &H00000200???
%GOPHER_TYPE_REDUNDANT       = &H00000400???
%GOPHER_TYPE_TN3270          = &H00000800???
%GOPHER_TYPE_GIF             = &H00001000???
%GOPHER_TYPE_IMAGE           = &H00002000???
%GOPHER_TYPE_BITMAP          = &H00004000???
%GOPHER_TYPE_MOVIE           = &H00008000???
%GOPHER_TYPE_SOUND           = &H00010000???
%GOPHER_TYPE_HTML            = &H00020000???
%GOPHER_TYPE_PDF             = &H00040000???
%GOPHER_TYPE_CALENDAR        = &H00080000???
%GOPHER_TYPE_INLINE          = &H00100000???
%GOPHER_TYPE_UNKNOWN         = &H20000000???
%GOPHER_TYPE_ASK             = &H40000000???
%GOPHER_TYPE_GOPHER_PLUS     = &H80000000???

'//
'// GOPHER_TYPE_FILE_MASK - use this to determine if a locator identifies a
'// (known) file type
'//

%GOPHER_TYPE_FILE_MASK = %GOPHER_TYPE_TEXT_FILE          _
                       OR %GOPHER_TYPE_MAC_BINHEX        _
                       OR %GOPHER_TYPE_DOS_ARCHIVE       _
                       OR %GOPHER_TYPE_UNIX_UUENCODED    _
                       OR %GOPHER_TYPE_BINARY            _
                       OR %GOPHER_TYPE_GIF               _
                       OR %GOPHER_TYPE_IMAGE             _
                       OR %GOPHER_TYPE_BITMAP            _
                       OR %GOPHER_TYPE_MOVIE             _
                       OR %GOPHER_TYPE_SOUND             _
                       OR %GOPHER_TYPE_HTML              _
                       OR %GOPHER_TYPE_PDF               _
                       OR %GOPHER_TYPE_CALENDAR          _
                       OR %GOPHER_TYPE_INLINE

'//
'// gopher type macros
'//

'#define IS_GOPHER_FILE(type)            (BOOL)(((type) & GOPHER_TYPE_FILE_MASK) ? TRUE : FALSE)
'#define IS_GOPHER_DIRECTORY(type)       (BOOL)(((type) & GOPHER_TYPE_DIRECTORY) ? TRUE : FALSE)
'#define IS_GOPHER_PHONE_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_CSO) ? TRUE : FALSE)
'#define IS_GOPHER_ERROR(type)           (BOOL)(((type) & GOPHER_TYPE_ERROR) ? TRUE : FALSE)
'#define IS_GOPHER_INDEX_SERVER(type)    (BOOL)(((type) & GOPHER_TYPE_INDEX_SERVER) ? TRUE : FALSE)
'#define IS_GOPHER_TELNET_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TELNET) ? TRUE : FALSE)
'#define IS_GOPHER_BACKUP_SERVER(type)   (BOOL)(((type) & GOPHER_TYPE_REDUNDANT) ? TRUE : FALSE)
'#define IS_GOPHER_TN3270_SESSION(type)  (BOOL)(((type) & GOPHER_TYPE_TN3270) ? TRUE : FALSE)
'#define IS_GOPHER_ASK(type)             (BOOL)(((type) & GOPHER_TYPE_ASK) ? TRUE : FALSE)
'#define IS_GOPHER_PLUS(type)            (BOOL)(((type) & GOPHER_TYPE_GOPHER_PLUS) ? TRUE : FALSE)

'#define IS_GOPHER_TYPE_KNOWN(type)      (BOOL)(((type) & GOPHER_TYPE_UNKNOWN) ? FALSE : TRUE)

FUNCTION IS_GOPHER_FILE (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_FILE_MASK) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_DIRECTORY (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_DIRECTORY) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_PHONE_SERVER (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_CSO) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_ERROR (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_ERROR) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_INDEX_SERVER (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_INDEX_SERVER) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_TELNET_SESSION (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_TELNET) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_BACKUP_SERVER (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_REDUNDANT) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_TN3280_SESSION (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_TN3270) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_ASK (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_ASK) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_PLUS (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_GOPHER_PLUS) <> 0))
END FUNCTION

FUNCTION IS_GOPHER_TYPE_KNOWN (BYVAL nType AS DWORD) AS LONG
   FUNCTION = ABS(((nType AND %GOPHER_TYPE_UNKNOWN) = 0))
END FUNCTION

'//
'// structured gopher attributes (as defined in gopher+ protocol document)
'//

' // Size = 8 bytes
TYPE GOPHER_ADMIN_ATTRIBUTE_TYPE DWORD
   Comment      AS ASCIIZ PTR   ' LPCTSTR
   EmailAddress AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 8 bytes
TYPE GOPHER_MOD_DATE_ATTRIBUTE_TYPE DWORD
   DateAndTime AS FILETIME
END TYPE

' // Size = 4 bytes
TYPE GOPHER_TTL_ATTRIBUTE_TYPE DWORD
   Ttl AS DWORD
END TYPE

' // Size = 4 bytes
TYPE GOPHER_SCORE_ATTRIBUTE_TYPE DWORD
   Score AS LONG   ' INT
END TYPE

' // Size = 8 bytes
TYPE GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE DWORD
   LowerBound AS LONG   ' INT
   UpperBound AS LONG   ' INT
END TYPE

' // Size = 4 bytes
TYPE GOPHER_SITE_ATTRIBUTE_TYPE DWORD
   Site AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 4 bytes
TYPE GOPHER_ORGANIZATION_ATTRIBUTE_TYPE DWORD
   Organization AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 4 bytes
TYPE GOPHER_LOCATION_ATTRIBUTE_TYPE DWORD
   Location AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 24 bytes
TYPE GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE DWORD
   DegreesNorth AS LONG   ' INT
   MinutesNorth AS LONG   ' INT
   SecondsNorth AS LONG   ' INT
   DegreesEast  AS LONG   ' INT
   MinutesEast  AS LONG   ' INT
   SecondsEast  AS LONG   ' INT
END TYPE

' // Size = 4 bytes
TYPE GOPHER_TIMEZONE_ATTRIBUTE_TYPE DWORD
   Zone AS LONG   ' INT
END TYPE

' // Size = 4 bytes
TYPE GOPHER_PROVIDER_ATTRIBUTE_TYPE DWORD
   Provider AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 4 bytes
TYPE GOPHER_VERSION_ATTRIBUTE_TYPE DWORD
   Version AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 8 bytes
TYPE GOPHER_ABSTRACT_ATTRIBUTE_TYPE DWORD
   ShortAbstract AS ASCIIZ PTR   ' LPCTSTR
   AbstractFile  AS ASCIIZ PTR   ' LPCTSTR
END TYPE

' // Size = 12 bytes
TYPE GOPHER_VIEW_ATTRIBUTE_TYPE DWORD
   ContentType AS ASCIIZ PTR   ' LPCTSTR
   Language    AS ASCIIZ PTR   ' LPCTSTR
   Size        AS DWORD        ' DWORD
END TYPE

' // Size = 4 bytes
TYPE GOPHER_VERONICA_ATTRIBUTE_TYPE DWORD
   TreeWalk AS LONG   ' BOOL
END TYPE

' // Size = 8 bytes
TYPE GOPHER_ASK_ATTRIBUTE_TYPE DWORD
   QuestionType AS ASCIIZ PTR   ' LPCTSTR
   QuestionText AS ASCIIZ PTR   ' LPCTSTR
END TYPE

'//
'// GOPHER_UNKNOWN_ATTRIBUTE_TYPE - this is returned if we retrieve an attribute
'// that is not specified in the current gopher/gopher+ documentation. It is up
'// to the application to parse the information
'//

' // Size = 4 bytes
TYPE GOPHER_UNKNOWN_ATTRIBUTE_TYPE DWORD
   Text AS ASCIIZ PTR   ' LPCTSTR
END TYPE

'//
'// GOPHER_ATTRIBUTE_TYPE - returned in the user's buffer when an enumerated
'// GopherGetAttribute call is made
'//

'typedef struct {
'    DWORD CategoryId;   // e.g. GOPHER_CATEGORY_ID_ADMIN
'    DWORD AttributeId;  // e.g. GOPHER_ATTRIBUTE_ID_ADMIN
'    union {
'        GOPHER_ADMIN_ATTRIBUTE_TYPE Admin;
'        GOPHER_MOD_DATE_ATTRIBUTE_TYPE ModDate;
'        GOPHER_TTL_ATTRIBUTE_TYPE Ttl;
'        GOPHER_SCORE_ATTRIBUTE_TYPE Score;
'        GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE ScoreRange;
'        GOPHER_SITE_ATTRIBUTE_TYPE Site;
'        GOPHER_ORGANIZATION_ATTRIBUTE_TYPE Organization;
'        GOPHER_LOCATION_ATTRIBUTE_TYPE Location;
'        GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE GeographicalLocation;
'        GOPHER_TIMEZONE_ATTRIBUTE_TYPE TimeZone;
'        GOPHER_PROVIDER_ATTRIBUTE_TYPE Provider;
'        GOPHER_VERSION_ATTRIBUTE_TYPE Version;
'        GOPHER_ABSTRACT_ATTRIBUTE_TYPE Abstract;
'        GOPHER_VIEW_ATTRIBUTE_TYPE View;
'        GOPHER_VERONICA_ATTRIBUTE_TYPE Veronica;
'        GOPHER_ASK_ATTRIBUTE_TYPE Ask;
'        GOPHER_UNKNOWN_ATTRIBUTE_TYPE Unknown;
'    } AttributeType;
'} GOPHER_ATTRIBUTE_TYPE, * LPGOPHER_ATTRIBUTE_TYPE;

' // Size = 24 bytes
UNION GOPHER_ATTRIBUTE_TYPE_UNION DWORD
   Admin                AS GOPHER_ADMIN_ATTRIBUTE_TYPE
   ModDate              AS GOPHER_MOD_DATE_ATTRIBUTE_TYPE
   Ttl                  AS GOPHER_TTL_ATTRIBUTE_TYPE
   Score                AS GOPHER_SCORE_ATTRIBUTE_TYPE
   ScoreRange           AS GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE
   Site                 AS GOPHER_SITE_ATTRIBUTE_TYPE
   Organization         AS GOPHER_ORGANIZATION_ATTRIBUTE_TYPE
   Location             AS GOPHER_LOCATION_ATTRIBUTE_TYPE
   GeographicalLocation AS GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE
   TimeZone             AS GOPHER_TIMEZONE_ATTRIBUTE_TYPE
   Provider             AS GOPHER_PROVIDER_ATTRIBUTE_TYPE
   Version              AS GOPHER_VERSION_ATTRIBUTE_TYPE
   Abstract             AS GOPHER_ABSTRACT_ATTRIBUTE_TYPE
   View                 AS GOPHER_VIEW_ATTRIBUTE_TYPE
   Veronica             AS GOPHER_VERONICA_ATTRIBUTE_TYPE
   Ask                  AS GOPHER_ASK_ATTRIBUTE_TYPE
   Unknown              AS GOPHER_UNKNOWN_ATTRIBUTE_TYPE
END UNION

' // Size = 32 bytes
TYPE GOPHER_ATTRIBUTE_TYPE DWORD
   CategoryId    AS DWORD   ' e.g. %GOPHER_CATEGORY_ID_ADMIN
   AttributeId   AS DWORD   ' e.g. %GOPHER_ATTRIBUTE_ID_ADMIN
   AttributeType AS GOPHER_ATTRIBUTE_TYPE_UNION
END TYPE

'#define MAX_GOPHER_CATEGORY_NAME    128     // arbitrary
'#define MAX_GOPHER_ATTRIBUTE_NAME   128     //     "
'#define MIN_GOPHER_ATTRIBUTE_LENGTH 256     //     "

%MAX_GOPHER_CATEGORY_NAME    = 128     ' arbitrary
%MAX_GOPHER_ATTRIBUTE_NAME   = 128     '     "
%MIN_GOPHER_ATTRIBUTE_LENGTH = 256     '     "

'//
'// known gopher attribute categories. See below for ordinals
'//

$GOPHER_INFO_CATEGORY        = "+INFO"
$GOPHER_ADMIN_CATEGORY       = "+ADMIN"
$GOPHER_VIEWS_CATEGORY       = "+VIEWS"
$GOPHER_ABSTRACT_CATEGORY    = "+ABSTRACT"
$GOPHER_VERONICA_CATEGORY    = "+VERONICA"

'//
'// known gopher attributes. These are the attribute names as defined in the
'// gopher+ protocol document
'//

$GOPHER_ADMIN_ATTRIBUTE      = "Admin"
$GOPHER_MOD_DATE_ATTRIBUTE   = "Mod-Date"
$GOPHER_TTL_ATTRIBUTE        = "TTL"
$GOPHER_SCORE_ATTRIBUTE      = "Score"
$GOPHER_RANGE_ATTRIBUTE      = "Score-range"
$GOPHER_SITE_ATTRIBUTE       = "Site"
$GOPHER_ORG_ATTRIBUTE        = "Org"
$GOPHER_LOCATION_ATTRIBUTE   = "Loc"
$GOPHER_GEOG_ATTRIBUTE       = "Geog"
$GOPHER_TIMEZONE_ATTRIBUTE   = "TZ"
$GOPHER_PROVIDER_ATTRIBUTE   = "Provider"
$GOPHER_VERSION_ATTRIBUTE    = "Version"
$GOPHER_ABSTRACT_ATTRIBUTE   = "Abstract"
$GOPHER_VIEW_ATTRIBUTE       = "View"
$GOPHER_TREEWALK_ATTRIBUTE   = "treewalk"

'//
'// identifiers for attribute strings
'//

%GOPHER_ATTRIBUTE_ID_BASE     = &Habcccc00???

%GOPHER_CATEGORY_ID_ALL       = %GOPHER_ATTRIBUTE_ID_BASE + 1

%GOPHER_CATEGORY_ID_INFO      = %GOPHER_ATTRIBUTE_ID_BASE + 2
%GOPHER_CATEGORY_ID_ADMIN     = %GOPHER_ATTRIBUTE_ID_BASE + 3
%GOPHER_CATEGORY_ID_VIEWS     = %GOPHER_ATTRIBUTE_ID_BASE + 4
%GOPHER_CATEGORY_ID_ABSTRACT  = %GOPHER_ATTRIBUTE_ID_BASE + 5
%GOPHER_CATEGORY_ID_VERONICA  = %GOPHER_ATTRIBUTE_ID_BASE + 6
%GOPHER_CATEGORY_ID_ASK       = %GOPHER_ATTRIBUTE_ID_BASE + 7

%GOPHER_CATEGORY_ID_UNKNOWN   = %GOPHER_ATTRIBUTE_ID_BASE + 8

%GOPHER_ATTRIBUTE_ID_ALL      = %GOPHER_ATTRIBUTE_ID_BASE + 9

%GOPHER_ATTRIBUTE_ID_ADMIN    = %GOPHER_ATTRIBUTE_ID_BASE + 10
%GOPHER_ATTRIBUTE_ID_MOD_DATE = %GOPHER_ATTRIBUTE_ID_BASE + 11
%GOPHER_ATTRIBUTE_ID_TTL      = %GOPHER_ATTRIBUTE_ID_BASE + 12
%GOPHER_ATTRIBUTE_ID_SCORE    = %GOPHER_ATTRIBUTE_ID_BASE + 13
%GOPHER_ATTRIBUTE_ID_RANGE    = %GOPHER_ATTRIBUTE_ID_BASE + 14
%GOPHER_ATTRIBUTE_ID_SITE     = %GOPHER_ATTRIBUTE_ID_BASE + 15
%GOPHER_ATTRIBUTE_ID_ORG      = %GOPHER_ATTRIBUTE_ID_BASE + 16
%GOPHER_ATTRIBUTE_ID_LOCATION = %GOPHER_ATTRIBUTE_ID_BASE + 17
%GOPHER_ATTRIBUTE_ID_GEOG     = %GOPHER_ATTRIBUTE_ID_BASE + 18
%GOPHER_ATTRIBUTE_ID_TIMEZONE = %GOPHER_ATTRIBUTE_ID_BASE + 19
%GOPHER_ATTRIBUTE_ID_PROVIDER = %GOPHER_ATTRIBUTE_ID_BASE + 20
%GOPHER_ATTRIBUTE_ID_VERSION  = %GOPHER_ATTRIBUTE_ID_BASE + 21
%GOPHER_ATTRIBUTE_ID_ABSTRACT = %GOPHER_ATTRIBUTE_ID_BASE + 22
%GOPHER_ATTRIBUTE_ID_VIEW     = %GOPHER_ATTRIBUTE_ID_BASE + 23
%GOPHER_ATTRIBUTE_ID_TREEWALK = %GOPHER_ATTRIBUTE_ID_BASE + 24

%GOPHER_ATTRIBUTE_ID_UNKNOWN  = %GOPHER_ATTRIBUTE_ID_BASE + 25

'//
'// prototypes
'//

DECLARE FUNCTION GopherCreateLocatorA IMPORT "WININET.DLL" ALIAS "GopherCreateLocatorA" ( _
   BYREF lpszHost AS ASCIIZ _                           ' __in LPCSTR lpszHost
 , BYVAL nServerPort AS WORD _                          ' __in INTERNET_PORT nServerPort
 , BYREF lpszDisplayString AS ASCIIZ _                  ' __in_opt LPCSTR lpszDisplayString
 , BYREF lpszSelectorString AS ASCIIZ _                 ' __in_opt LPCSTR lpszSelectorString
 , BYVAL dwGopherType AS DWORD _                        ' __in DWORD dwGopherType
 , BYREF lpszLocator AS ASCIIZ  _                       ' __out_opt LPSTR lpszLocator
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GopherCreateLocatorW IMPORT "WININET.DLL" ALIAS "GopherCreateLocatorW" ( _
   BYREF lpszHost AS WSTRINGZ  _                        ' __in LPCWSTR lpszHost
 , BYVAL nServerPort AS WORD _                          ' __in INTERNET_PORT nServerPort
 , BYREF lpszDisplayString AS WSTRINGZ _                ' __in_opt LPCWSTR lpszDisplayString
 , BYREF lpszSelectorString AS WSTRINGZ _               ' __in_opt LPCWSTR lpszSelectorString
 , BYVAL dwGopherType AS DWORD _                        ' __in DWORD dwGopherType
 , BYREF lpszLocator AS WSTRINGZ _                      ' __out_opt LPWSTR lpszLocator
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GopherCreateLocator = GopherCreateLocatorW
#ELSE
   MACRO GopherCreateLocator = GopherCreateLocatorA
#ENDIF

DECLARE FUNCTION GopherGetLocatorTypeA IMPORT "WININET.DLL" ALIAS "GopherGetLocatorTypeA" ( _
   BYREF lpszLocator AS ASCIIZ _                        ' __in LPCSTR lpszLocator
 , BYREF lpdwGopherType AS DWORD _                      ' __out LPDWORD lpdwGopherType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GopherGetLocatorTypeW IMPORT "WININET.DLL" ALIAS "GopherGetLocatorTypeW" ( _
   BYREF lpszLocator AS WSTRINGZ _                      ' __in LPCWSTR lpszLocator
 , BYREF lpdwGopherType AS DWORD _                      ' __out LPDWORD lpdwGopherType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GopherGetLocatorType = GopherGetLocatorTypeW
#ELSE
   MACRO GopherGetLocatorType = GopherGetLocatorTypeA
#ENDIF

DECLARE FUNCTION GopherFindFirstFileA IMPORT "WININET.DLL" ALIAS "GopherFindFirstFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS ASCIIZ _                        ' __in_opt LPCSTR lpszLocator
 , BYREF lpszSearchString AS ASCIIZ _                   ' __in_opt LPCSTR lpszSearchString
 , BYREF lpFindData AS GOPHER_FIND_DATAA _              ' __out_opt LPGOPHER_FIND_DATAA lpFindData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION GopherFindFirstFileW IMPORT "WININET.DLL" ALIAS "GopherFindFirstFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS WSTRINGZ _                      ' __in_opt LPCWSTR lpszLocator
 , BYREF lpszSearchString AS WSTRINGZ _                 ' __in_opt LPCWSTR lpszSearchString
 , BYREF lpFindData AS GOPHER_FIND_DATAW _              ' __out_opt LPGOPHER_FIND_DATAW lpFindData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO GopherFindFirstFile = GopherFindFirstFileW
#ELSE
   MACRO GopherFindFirstFile = GopherFindFirstFileA
#ENDIF

DECLARE FUNCTION GopherOpenFileA IMPORT "WININET.DLL" ALIAS "GopherOpenFileA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS ASCIIZ _                        ' __in LPCSTR lpszLocator
 , BYREF lpszView AS ASCIIZ _                           ' __in_opt LPCSTR lpszView
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION GopherOpenFileW IMPORT "WININET.DLL" ALIAS "GopherOpenFileW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS WSTRINGZ _                      ' __in LPCWSTR lpszLocator
 , BYREF lpszView AS WSTRINGZ _                         ' __in_opt LPCWSTR lpszView
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO GopherOpenFile = GopherOpenFileW
#ELSE
   MACRO GopherOpenFile = GopherOpenFileA
#ENDIF

'typedef BOOL (CALLBACK * GOPHER_ATTRIBUTE_ENUMERATOR)(
'    __in LPGOPHER_ATTRIBUTE_TYPE lpAttributeInfo,
'    __in DWORD dwError
'    );

DECLARE FUNCTION GopherGetAttributeA IMPORT "WININET.DLL" ALIAS "GopherGetAttributeA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS ASCIIZ _                        ' __in LPCSTR lpszLocator
 , BYREF lpszAttributeName AS ASCIIZ _                  ' __in_opt LPCSTR lpszAttributeName
 , BYVAL lpBuffer AS DWORD _                            ' __out LPBYTE lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYREF lpdwCharactersReturned AS DWORD _              ' __out LPDWORD lpdwCharactersReturned
 , OPTIONAL BYVAL lpfnEnumerator AS DWORD _             ' __in_opt GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GopherGetAttributeW IMPORT "WININET.DLL" ALIAS "GopherGetAttributeW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszLocator AS WSTRINGZ _                      ' __in LPCWSTR lpszLocator
 , BYREF lpszAttributeName AS WSTRINGZ _                ' __in_opt LPCWSTR lpszAttributeName
 , BYVAL lpBuffer AS DWORD _                            ' __out LPBYTE lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 , BYREF lpdwCharactersReturned AS DWORD _              ' __out LPDWORD lpdwCharactersReturned
 , OPTIONAL BYVAL lpfnEnumerator AS DWORD _             ' __in_opt GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GopherGetAttribute = GopherGetAttributeW
#ELSE
   MACRO GopherGetAttribute = GopherGetAttributeA
#ENDIF

'//
'// HTTP
'//

'//
'// manifests
'//

'//
'// the default major/minor HTTP version numbers
'//

%HTTP_MAJOR_VERSION      = 1
%HTTP_MINOR_VERSION      = 0

$HTTP_VERSIONA                 = "HTTP/1.0"
$$HTTP_VERSIONW                = "HTTP/1.0"$$
#IF %DEF(%UNICODE)
   MACRO HTTP_VERSION = $HTTP_VERSIONA
#ELSE
   MACRO HTTP_VERSION = $$HTTP_VERSIONW
#ENDIF

'//
'// HttpQueryInfo info levels. Generally, there is one info level
'// for each potential RFC822/HTTP/MIME header that an HTTP server
'// may send as part of a request response.
'//
'// The HTTP_QUERY_RAW_HEADERS info level is provided for clients
'// that choose to perform their own header parsing.
'//

%HTTP_QUERY_MIME_VERSION              = 0
%HTTP_QUERY_CONTENT_TYPE              = 1
%HTTP_QUERY_CONTENT_TRANSFER_ENCODING = 2
%HTTP_QUERY_CONTENT_ID                = 3
%HTTP_QUERY_CONTENT_DESCRIPTION       = 4
%HTTP_QUERY_CONTENT_LENGTH            = 5
%HTTP_QUERY_CONTENT_LANGUAGE          = 6
%HTTP_QUERY_ALLOW                     = 7
%HTTP_QUERY_PUBLIC                    = 8
%HTTP_QUERY_DATE                      = 9
%HTTP_QUERY_EXPIRES                   = 10
%HTTP_QUERY_LAST_MODIFIED             = 11
%HTTP_QUERY_MESSAGE_ID                = 12
%HTTP_QUERY_URI                       = 13
%HTTP_QUERY_DERIVED_FROM              = 14
%HTTP_QUERY_COST                      = 15
%HTTP_QUERY_LINK                      = 16
%HTTP_QUERY_PRAGMA                    = 17
%HTTP_QUERY_VERSION                   = 18  ' special: part of status line
%HTTP_QUERY_STATUS_CODE               = 19  ' special: part of status line
%HTTP_QUERY_STATUS_TEXT               = 20  ' special: part of status line
%HTTP_QUERY_RAW_HEADERS               = 21  ' special: all headers as ASCIIZ
%HTTP_QUERY_RAW_HEADERS_CRLF          = 22  ' special: all headers
%HTTP_QUERY_CONNECTION                = 23
%HTTP_QUERY_ACCEPT                    = 24
%HTTP_QUERY_ACCEPT_CHARSET            = 25
%HTTP_QUERY_ACCEPT_ENCODING           = 26
%HTTP_QUERY_ACCEPT_LANGUAGE           = 27
%HTTP_QUERY_AUTHORIZATION             = 28
%HTTP_QUERY_CONTENT_ENCODING          = 29
%HTTP_QUERY_FORWARDED                 = 30
%HTTP_QUERY_FROM                      = 31
%HTTP_QUERY_IF_MODIFIED_SINCE         = 32
%HTTP_QUERY_LOCATION                  = 33
%HTTP_QUERY_ORIG_URI                  = 34
%HTTP_QUERY_REFERER                   = 35
%HTTP_QUERY_RETRY_AFTER               = 36
%HTTP_QUERY_SERVER                    = 37
%HTTP_QUERY_TITLE                     = 38
%HTTP_QUERY_USER_AGENT                = 39
%HTTP_QUERY_WWW_AUTHENTICATE          = 40
%HTTP_QUERY_PROXY_AUTHENTICATE        = 41
%HTTP_QUERY_ACCEPT_RANGES             = 42
%HTTP_QUERY_SET_COOKIE                = 43
%HTTP_QUERY_COOKIE                    = 44
%HTTP_QUERY_REQUEST_METHOD            = 45  ' special: GET/POST etc.
%HTTP_QUERY_REFRESH                   = 46
%HTTP_QUERY_CONTENT_DISPOSITION       = 47

'//
'// HTTP 1.1 defined headers
'//

%HTTP_QUERY_AGE                       = 48
%HTTP_QUERY_CACHE_CONTROL             = 49
%HTTP_QUERY_CONTENT_BASE              = 50
%HTTP_QUERY_CONTENT_LOCATION          = 51
%HTTP_QUERY_CONTENT_MD5               = 52
%HTTP_QUERY_CONTENT_RANGE             = 53
%HTTP_QUERY_ETAG                      = 54
%HTTP_QUERY_HOST                      = 55
%HTTP_QUERY_IF_MATCH                  = 56
%HTTP_QUERY_IF_NONE_MATCH             = 57
%HTTP_QUERY_IF_RANGE                  = 58
%HTTP_QUERY_IF_UNMODIFIED_SINCE       = 59
%HTTP_QUERY_MAX_FORWARDS              = 60
%HTTP_QUERY_PROXY_AUTHORIZATION       = 61
%HTTP_QUERY_RANGE                     = 62
%HTTP_QUERY_TRANSFER_ENCODING         = 63
%HTTP_QUERY_UPGRADE                   = 64
%HTTP_QUERY_VARY                      = 65
%HTTP_QUERY_VIA                       = 66
%HTTP_QUERY_WARNING                   = 67
%HTTP_QUERY_EXPECT                    = 68
%HTTP_QUERY_PROXY_CONNECTION          = 69
%HTTP_QUERY_UNLESS_MODIFIED_SINCE     = 70


%HTTP_QUERY_ECHO_REQUEST              = 71
%HTTP_QUERY_ECHO_REPLY                = 72

'// These are the set of headers that should be added back to a request when
'// re-doing a request after a RETRY_WITH response.
%HTTP_QUERY_ECHO_HEADERS              = 73
%HTTP_QUERY_ECHO_HEADERS_CRLF         = 74

%HTTP_QUERY_PROXY_SUPPORT             = 75
%HTTP_QUERY_AUTHENTICATION_INFO       = 76
%HTTP_QUERY_PASSPORT_URLS             = 77
%HTTP_QUERY_PASSPORT_CONFIG           = 78

%HTTP_QUERY_MAX                       = 78

'//
'// HTTP_QUERY_CUSTOM - if this special value is supplied as the dwInfoLevel
'// parameter of HttpQueryInfo() then the lpBuffer parameter contains the name
'// of the header we are to query
'//

%HTTP_QUERY_CUSTOM                       = 65535

'//
'// HTTP_QUERY_FLAG_REQUEST_HEADERS - if this bit is set in the dwInfoLevel
'// parameter of HttpQueryInfo() then the request headers will be queried for the
'// request information
'//

%HTTP_QUERY_FLAG_REQUEST_HEADERS          = &H80000000???

'//
'// HTTP_QUERY_FLAG_SYSTEMTIME - if this bit is set in the dwInfoLevel parameter
'// of HttpQueryInfo() AND the header being queried contains date information,
'// e.g. the "Expires:" header then lpBuffer will contain a SYSTEMTIME structure
'// containing the date and time information converted from the header string
'//

%HTTP_QUERY_FLAG_SYSTEMTIME              = &H40000000???

'//
'// HTTP_QUERY_FLAG_NUMBER - if this bit is set in the dwInfoLevel parameter of
'// HttpQueryInfo(), then the value of the header will be converted to a 32bit
'// number before being returned to the caller, if applicable
'//

%HTTP_QUERY_FLAG_NUMBER                  = &H20000000???

'//
'// HTTP_QUERY_FLAG_COALESCE - combine the values from several headers of the
'// same name into the output buffer
'//

%HTTP_QUERY_FLAG_COALESCE                = &H10000000???

'//
'// HTTP_QUERY_FLAG_NUMBER64 - if this bit is set in the dwInfoLevel parameter of
'// HttpQueryInfo(), then the value of the header will be converted to a 64bit
'// number before being returned to the caller, if applicable
'//

%HTTP_QUERY_FLAG_NUMBER64                = &H08000000???


%HTTP_QUERY_MODIFIER_FLAGS_MASK          = %HTTP_QUERY_FLAG_REQUEST_HEADERS _
                                         OR %HTTP_QUERY_FLAG_SYSTEMTIME     _
                                         OR %HTTP_QUERY_FLAG_NUMBER         _
                                         OR %HTTP_QUERY_FLAG_COALESCE       _
                                         OR %HTTP_QUERY_FLAG_NUMBER64

%HTTP_QUERY_HEADER_MASK                  = NOT %HTTP_QUERY_MODIFIER_FLAGS_MASK

'//
'// HTTP Response Status Codes:
'//

%HTTP_STATUS_CONTINUE           = 100 ' OK to continue with request
%HTTP_STATUS_SWITCH_PROTOCOLS   = 101 ' server has switched protocols in upgrade header

%HTTP_STATUS_OK                 = 200 ' request completed
%HTTP_STATUS_CREATED            = 201 ' object created, reason = new URI
%HTTP_STATUS_ACCEPTED           = 202 ' async completion (TBS)
%HTTP_STATUS_PARTIAL            = 203 ' partial completion
%HTTP_STATUS_NO_CONTENT         = 204 ' no info to return
%HTTP_STATUS_RESET_CONTENT      = 205 ' request completed, but clear form
%HTTP_STATUS_PARTIAL_CONTENT    = 206 ' partial GET furfilled

%HTTP_STATUS_AMBIGUOUS          = 300 ' server couldn't decide what to return
%HTTP_STATUS_MOVED              = 301 ' object permanently moved
%HTTP_STATUS_REDIRECT           = 302 ' object temporarily moved
%HTTP_STATUS_REDIRECT_METHOD    = 303 ' redirection w/ new access method
%HTTP_STATUS_NOT_MODIFIED       = 304 ' if-modified-since was not modified
%HTTP_STATUS_USE_PROXY          = 305 ' redirection to proxy, location header specifies proxy to use
%HTTP_STATUS_REDIRECT_KEEP_VERB = 307 ' HTTP/1.1: keep same verb

%HTTP_STATUS_BAD_REQUEST        = 400 ' invalid syntax
%HTTP_STATUS_DENIED             = 401 ' access denied
%HTTP_STATUS_PAYMENT_REQ        = 402 ' payment required
%HTTP_STATUS_FORBIDDEN          = 403 ' request forbidden
%HTTP_STATUS_NOT_FOUND          = 404 ' object not found
%HTTP_STATUS_BAD_METHOD         = 405 ' method is not allowed
%HTTP_STATUS_NONE_ACCEPTABLE    = 406 ' no response acceptable to client found
%HTTP_STATUS_PROXY_AUTH_REQ     = 407 ' proxy authentication required
%HTTP_STATUS_REQUEST_TIMEOUT    = 408 ' server timed out waiting for request
%HTTP_STATUS_CONFLICT           = 409 ' user should resubmit with more info
%HTTP_STATUS_GONE               = 410 ' the resource is no longer available
%HTTP_STATUS_LENGTH_REQUIRED    = 411 ' the server refused to accept request w/o a length
%HTTP_STATUS_PRECOND_FAILED     = 412 ' precondition given in request failed
%HTTP_STATUS_REQUEST_TOO_LARGE  = 413 ' request entity was too large
%HTTP_STATUS_URI_TOO_LONG       = 414 ' request URI too long
%HTTP_STATUS_UNSUPPORTED_MEDIA  = 415 ' unsupported media type
%HTTP_STATUS_RETRY_WITH         = 449 ' retry after doing the appropriate action.

%HTTP_STATUS_SERVER_ERROR       = 500 ' internal server error
%HTTP_STATUS_NOT_SUPPORTED      = 501 ' required not supported
%HTTP_STATUS_BAD_GATEWAY        = 502 ' error response received from gateway
%HTTP_STATUS_SERVICE_UNAVAIL    = 503 ' temporarily overloaded
%HTTP_STATUS_GATEWAY_TIMEOUT    = 504 ' timed out waiting for gateway
%HTTP_STATUS_VERSION_NOT_SUP    = 505 ' HTTP version not supported

%HTTP_STATUS_FIRST              = %HTTP_STATUS_CONTINUE
%HTTP_STATUS_LAST               = %HTTP_STATUS_VERSION_NOT_SUP

'//
'// prototypes
'//

DECLARE FUNCTION HttpOpenRequestA IMPORT "WININET.DLL" ALIAS "HttpOpenRequestA" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszVerb AS ASCIIZ _                           ' __in_opt LPCSTR lpszVerb
 , BYREF lpszObjectName AS ASCIIZ _                     ' __in_opt LPCSTR lpszObjectName
 , BYREF lpszVersion AS ASCIIZ _                        ' __in_opt LPCSTR lpszVersion
 , BYREF lpszReferrer AS ASCIIZ _                       ' __in_opt LPCSTR lpszReferrer
 , BYREF lplpszAcceptTypes AS ANY _                     ' __in_opt LPCSTR FAR * lplpszAcceptTypes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION HttpOpenRequestW IMPORT "WININET.DLL" ALIAS "HttpOpenRequestW" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF lpszVerb AS WSTRINGZ _                         ' __in_opt LPCWSTR lpszVerb
 , BYREF lpszObjectName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszObjectName
 , BYREF lpszVersion AS WSTRINGZ _                      ' __in_opt LPCWSTR lpszVersion
 , BYREF lpszReferrer AS WSTRINGZ _                     ' __in_opt LPCWSTR lpszReferrer
 , BYREF lplpszAcceptTypes AS ANY _                     ' __in_opt LPCWSTR FAR * lplpszAcceptTypes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS DWORD                                             ' HINTERNET

#IF %DEF(%UNICODE)
   MACRO HttpOpenRequest = HttpOpenRequestW
#ELSE
   MACRO HttpOpenRequest = HttpOpenRequestA
#ENDIF

DECLARE FUNCTION HttpAddRequestHeadersA IMPORT "WININET.DLL" ALIAS "HttpAddRequestHeadersA" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpszHeaders AS ASCIIZ _                        ' __in LPCSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL dwModifiers AS DWORD _                         ' __in DWORD dwModifiers
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpAddRequestHeadersW IMPORT "WININET.DLL" ALIAS "HttpAddRequestHeadersW" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpszHeaders AS WSTRINGZ _                      ' __in LPCWSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL dwModifiers AS DWORD _                         ' __in DWORD dwModifiers
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpAddRequestHeaders = HttpAddRequestHeadersW
#ELSE
   MACRO HttpAddRequestHeaders = HttpAddRequestHeadersA
#ENDIF

'//
'// values for dwModifiers parameter of HttpAddRequestHeaders()
'//

%HTTP_ADDREQ_INDEX_MASK      = &H0000FFFF???
%HTTP_ADDREQ_FLAGS_MASK      = &HFFFF0000???

'//
'// HTTP_ADDREQ_FLAG_ADD_IF_NEW - the header will only be added if it doesn't
'// already exist
'//

%HTTP_ADDREQ_FLAG_ADD_IF_NEW = &H10000000???

'//
'// HTTP_ADDREQ_FLAG_ADD - if HTTP_ADDREQ_FLAG_REPLACE is set but the header is
'// not found then if this flag is set, the header is added anyway, so long as
'// there is a valid header-value
'//

%HTTP_ADDREQ_FLAG_ADD        = &H20000000???

'//
'// HTTP_ADDREQ_FLAG_COALESCE - coalesce headers with same name. e.g.
'// "Accept: text/*" and "Accept: audio/*" with this flag results in a single
'// header: "Accept: text/*, audio/*"
'//

%HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA       = &H40000000???
%HTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON   = &H01000000???
%HTTP_ADDREQ_FLAG_COALESCE                  = %HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA

'//
'// HTTP_ADDREQ_FLAG_REPLACE - replaces the specified header. Only one header can
'// be supplied in the buffer. If the header to be replaced is not the first
'// in a list of headers with the same name, then the relative index should be
'// supplied in the low 8 bits of the dwModifiers parameter. If the header-value
'// part is missing, then the header is removed
'//

%HTTP_ADDREQ_FLAG_REPLACE    = &H80000000???

DECLARE FUNCTION HttpSendRequestA IMPORT "WININET.DLL" ALIAS "HttpSendRequestA" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpszHeaders AS ASCIIZ _                        ' __in LPCSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL lpOptional AS DWORD _                          ' __in LPVOID lpOptional
 , BYVAL dwOptionalLength AS DWORD _                    ' __in DWORD dwOptionalLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpSendRequestW IMPORT "WININET.DLL" ALIAS "HttpSendRequestW" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpszHeaders AS WSTRINGZ _                      ' __in LPCWSTR lpszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL lpOptional AS DWORD _                          ' __in LPVOID lpOptional
 , BYVAL dwOptionalLength AS DWORD _                    ' __in DWORD dwOptionalLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpSendRequest = HttpSendRequestW
#ELSE
   MACRO HttpSendRequest = HttpSendRequestA
#ENDIF

DECLARE FUNCTION HttpSendRequestExA IMPORT "WININET.DLL" ALIAS "HttpSendRequestExA" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpBuffersIn AS INTERNET_BUFFERSA _             ' __in_opt LPINTERNET_BUFFERSA lpBuffersIn
 , BYREF lpBuffersOut AS INTERNET_BUFFERSA _            ' __out_opt LPINTERNET_BUFFERSA lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpSendRequestExW IMPORT "WININET.DLL" ALIAS "HttpSendRequestExW" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpBuffersIn AS INTERNET_BUFFERSW _             ' __in_opt LPINTERNET_BUFFERSW lpBuffersIn
 , BYREF lpBuffersOut AS INTERNET_BUFFERSW _            ' __out_opt LPINTERNET_BUFFERSW lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpSendRequestEx = HttpSendRequestExW
#ELSE
   MACRO HttpSendRequestEx = HttpSendRequestExA
#ENDIF

'//
'// flags for HttpSendRequestEx(), HttpEndRequest()
'//

%HSR_ASYNC       = %WININET_API_FLAG_ASYNC         ' force async
%HSR_SYNC        = %WININET_API_FLAG_SYNC          ' force sync
%HSR_USE_CONTEXT = %WININET_API_FLAG_USE_CONTEXT   ' use dwContext value
%HSR_INITIATE    = &H00000008???                  ' iterative operation (completed by HttpEndRequest)
%HSR_DOWNLOAD    = &H00000010???                  ' download to file
%HSR_CHUNKED     = &H00000020???                  ' operation is send of chunked data

DECLARE FUNCTION HttpEndRequestA IMPORT "WININET.DLL" ALIAS "HttpEndRequestA" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpBuffersOut AS INTERNET_BUFFERSA _            ' __out_opt LPINTERNET_BUFFERSA lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpEndRequestW IMPORT "WININET.DLL" ALIAS "HttpEndRequestW" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpBuffersOut AS INTERNET_BUFFERSW _            ' __out_opt LPINTERNET_BUFFERSW lpBuffersOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL dwContext AS DWORD _                  ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpEndRequest = HttpEndRequestW
#ELSE
   MACRO HttpEndRequest = HttpEndRequestA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION HttpQueryInfoA LIB "WinINet.dll" ALIAS "HttpQueryInfoA" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpQueryInfoA IMPORT "WININET.DLL" ALIAS "HttpQueryInfoA" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __inout LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , OPTIONAL BYREF lpdwIndex AS DWORD _                  ' __inout_opt LPDWORD lpdwIndex
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION HttpQueryInfoW LIB "WinINet.dll" ALIAS "HttpQueryInfoW" _
   ( _
    BYVAL hRequest AS DWORD, _              ' in
    BYVAL dwInfoLevel AS DWORD, _           ' in
    BYVAL lpBuffer AS BYTE PTR, _           ' in, out
    lpdwBufferLength AS DWORD, _            ' in, out
    BYVAL lpdwIndex AS DWORD PTR _          ' in, out
   ) AS LONG
#ELSE
DECLARE FUNCTION HttpQueryInfoW IMPORT "WININET.DLL" ALIAS "HttpQueryInfoW" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __inout LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , OPTIONAL BYREF lpdwIndex AS DWORD _                  ' __inout_opt LPDWORD lpdwIndex
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO HttpQueryInfo = HttpQueryInfoW
#ELSE
   MACRO HttpQueryInfo = HttpQueryInfoA
#ENDIF

'//
'// Cookie APIs
'//

%INTERNET_COOKIE_IS_SECURE       = &H01???
%INTERNET_COOKIE_IS_SESSION      = &H02???

%INTERNET_COOKIE_THIRD_PARTY     = &H10???
%INTERNET_COOKIE_PROMPT_REQUIRED = &H20???
%INTERNET_COOKIE_EVALUATE_P3P    = &H40???
%INTERNET_COOKIE_APPLY_P3P       = &H80???

%INTERNET_COOKIE_P3P_ENABLED     = &H100???
%INTERNET_COOKIE_IS_RESTRICTED   = &H200???
%INTERNET_COOKIE_IE6             = &H400???
%INTERNET_COOKIE_IS_LEGACY       = &H800???

%INTERNET_COOKIE_NON_SCRIPT      = &H00001000???
%INTERNET_COOKIE_HTTPONLY        = &H00002000???

DECLARE FUNCTION InternetSetCookieA IMPORT "WININET.DLL" ALIAS "InternetSetCookieA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszCookieName AS ASCIIZ _                     ' __in_opt LPCSTR lpszCookieName
 , BYREF lpszCookieData AS ASCIIZ _                     ' __in LPCSTR lpszCookieData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSetCookieW IMPORT "WININET.DLL" ALIAS "InternetSetCookieW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __in LPCWSTR lpszCookieData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSetCookie = InternetSetCookieW
#ELSE
   MACRO InternetSetCookie = InternetSetCookieA
#ENDIF

DECLARE FUNCTION InternetGetCookieA IMPORT "WININET.DLL" ALIAS "InternetGetCookieA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszCookieName AS ASCIIZ _                     ' __in_opt LPCSTR lpszCookieName
 , BYREF lpszCookieData AS ASCIIZ _                     ' __out LPSTR lpszCookieData
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetCookieW IMPORT "WININET.DLL" ALIAS "InternetGetCookieW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __out LPWSTR lpszCookieData
 , BYREF lpdwSize AS DWORD _                            ' __inout LPDWORD lpdwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetCookie = InternetGetCookieW
#ELSE
   MACRO InternetGetCookie = InternetGetCookieA
#ENDIF

DECLARE FUNCTION InternetSetCookieExA IMPORT "WININET.DLL" ALIAS "InternetSetCookieExA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszCookieName AS ASCIIZ _                     ' __in_opt LPCSTR lpszCookieName
 , BYREF lpszCookieData AS ASCIIZ _                     ' __in LPCSTR lpszCookieData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InternetSetCookieExW IMPORT "WININET.DLL" ALIAS "InternetSetCookieExW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __in LPCWSTR lpszCookieData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO InternetSetCookieEx = InternetSetCookieExW
#ELSE
   MACRO InternetSetCookieEx = InternetSetCookieExA
#ENDIF

DECLARE FUNCTION InternetGetCookieExA IMPORT "WININET.DLL" ALIAS "InternetGetCookieExA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszCookieName AS ASCIIZ _                     ' __in_opt LPCSTR lpszCookieName
 , BYREF lpszCookieData AS ASCIIZ _                     ' __in LPSTR lpszCookieData
 , BYREF lpdwSize AS DWORD _                            ' __inout_opt LPDWORD lpdwSize
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetCookieExW IMPORT "WININET.DLL" ALIAS "InternetGetCookieExW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __in LPWSTR lpszCookieData
 , BYREF lpdwSize AS DWORD _                            ' __inout_opt LPDWORD lpdwSize
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetCookieEx = InternetGetCookieExW
#ELSE
   MACRO InternetGetCookieEx = InternetGetCookieExA
#ENDIF

'//
'// offline browsing
'//

DECLARE FUNCTION InternetAttemptConnect IMPORT "WININET.DLL" ALIAS "InternetAttemptConnect" ( _
   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InternetCheckConnectionA IMPORT "WININET.DLL" ALIAS "InternetCheckConnectionA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in_opt LPCSTR lpszUrl
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetCheckConnectionW IMPORT "WININET.DLL" ALIAS "InternetCheckConnectionW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in_opt LPCWSTR lpszUrl
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetCheckConnection = InternetCheckConnectionW
#ELSE
   MACRO InternetCheckConnection = InternetCheckConnectionA
#ENDIF

%FLAG_ICC_FORCE_CONNECTION       = &H00000001???

'//
'// Internet UI
'//

'//
'// InternetErrorDlg - Provides UI for certain Errors.
'//

%FLAGS_ERROR_UI_FILTER_FOR_ERRORS        = &H01
%FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS     = &H02
%FLAGS_ERROR_UI_FLAGS_GENERATE_DATA      = &H04
%FLAGS_ERROR_UI_FLAGS_NO_UI              = &H08
%FLAGS_ERROR_UI_SERIALIZE_DIALOGS        = &H10

'//
'// If SERIALIZE_DIALOGS flag set, client should implement thread-safe non-blocking callback...
'//

'DWORD InternetAuthNotifyCallback
'(
'    DWORD_PTR       dwContext,    // as passed to InternetErrorDlg
'    DWORD           dwReturn,     // error code: success, resend, or cancel
'    LPVOID          lpReserved    // reserved: will be set to null
');
'typedef DWORD (CALLBACK * PFN_AUTH_NOTIFY) (DWORD_PTR, DWORD, LPVOID);

'//
'// ... and last parameter of InternetErrorDlg should point to...
'//

' // Size = 16 bytes
TYPE INTERNET_AUTH_NOTIFY_DATA DWORD
   cbStruct  AS DWORD   ' DWORD  // size of this structure
   dwOptions AS DWORD   ' DWORD  // reserved: must be set to 0
   pfnNotify AS DWORD   ' PFN_AUTH_NOTIFY // notification callback to retry InternetErrorDlg
   dwContext AS DWORD   ' DWORD_PTR  // context to pass to to notification function
END TYPE

DECLARE FUNCTION ResumeSuspendedDownload IMPORT "WININET.DLL" ALIAS "ResumeSuspendedDownload" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL dwResultCode AS DWORD _                        ' __in DWORD dwResultCode
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InternetErrorDlg LIB "WinINet.dll" _
   ALIAS "InternetErrorDlg" _
   ( _
    BYVAL hWnd     AS DWORD, _              ' in
    hRequest       AS DWORD, _              ' in, out
    BYVAL dwError  AS DWORD, _              ' in
    BYVAL dwFlags  AS DWORD, _              ' in
    BYVAL lppvData AS BYTE PTR _            ' in, out
   ) AS DWORD
#ELSE
DECLARE FUNCTION InternetErrorDlg IMPORT "WININET.DLL" ALIAS "InternetErrorDlg" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF hRequest AS DWORD _                            ' __in_opt HINTERNET hRequest
 , BYVAL dwError AS DWORD _                             ' __in DWORD dwError
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF lppvData AS ANY _                     ' __inout_opt LPVOID * lppvData
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION InternetConfirmZoneCrossingA IMPORT "WININET.DLL" ALIAS "InternetConfirmZoneCrossingA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szUrlPrev AS ASCIIZ _                          ' __in LPSTR szUrlPrev
 , BYREF szUrlNew AS ASCIIZ  _                          ' __in LPSTR szUrlNew
 , BYVAL bPost AS LONG _                                ' __in BOOL bPost
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InternetConfirmZoneCrossingW IMPORT "WININET.DLL" ALIAS "InternetConfirmZoneCrossingW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szUrlPrev AS WSTRINGZ _                        ' __in LPWSTR szUrlPrev
 , BYREF szUrlNew AS WSTRINGZ _                         ' __in LPWSTR szUrlNew
 , BYVAL bPost AS LONG _                                ' __in BOOL bPost
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO InternetConfirmZoneCrossing = InternetConfirmZoneCrossingW
#ELSE
   MACRO InternetConfirmZoneCrossing = InternetConfirmZoneCrossingA
#ENDIF

'#endif // !UNICODE

'//#if !defined(_WINERROR_)

'//
'// Internet API error returns
'//

%INTERNET_ERROR_BASE                     = 12000

%ERROR_INTERNET_OUT_OF_HANDLES           = (%INTERNET_ERROR_BASE + 1)
%ERROR_INTERNET_TIMEOUT                  = (%INTERNET_ERROR_BASE + 2)
%ERROR_INTERNET_EXTENDED_ERROR           = (%INTERNET_ERROR_BASE + 3)
%ERROR_INTERNET_INTERNAL_ERROR           = (%INTERNET_ERROR_BASE + 4)
%ERROR_INTERNET_INVALID_URL              = (%INTERNET_ERROR_BASE + 5)
%ERROR_INTERNET_UNRECOGNIZED_SCHEME      = (%INTERNET_ERROR_BASE + 6)
%ERROR_INTERNET_NAME_NOT_RESOLVED        = (%INTERNET_ERROR_BASE + 7)
%ERROR_INTERNET_PROTOCOL_NOT_FOUND       = (%INTERNET_ERROR_BASE + 8)
%ERROR_INTERNET_INVALID_OPTION           = (%INTERNET_ERROR_BASE + 9)
%ERROR_INTERNET_BAD_OPTION_LENGTH        = (%INTERNET_ERROR_BASE + 10)
%ERROR_INTERNET_OPTION_NOT_SETTABLE      = (%INTERNET_ERROR_BASE + 11)
%ERROR_INTERNET_SHUTDOWN                 = (%INTERNET_ERROR_BASE + 12)
%ERROR_INTERNET_INCORRECT_USER_NAME      = (%INTERNET_ERROR_BASE + 13)
%ERROR_INTERNET_INCORRECT_PASSWORD       = (%INTERNET_ERROR_BASE + 14)
%ERROR_INTERNET_LOGIN_FAILURE            = (%INTERNET_ERROR_BASE + 15)
%ERROR_INTERNET_INVALID_OPERATION        = (%INTERNET_ERROR_BASE + 16)
%ERROR_INTERNET_OPERATION_CANCELLED      = (%INTERNET_ERROR_BASE + 17)
%ERROR_INTERNET_INCORRECT_HANDLE_TYPE    = (%INTERNET_ERROR_BASE + 18)
%ERROR_INTERNET_INCORRECT_HANDLE_STATE   = (%INTERNET_ERROR_BASE + 19)
%ERROR_INTERNET_NOT_PROXY_REQUEST        = (%INTERNET_ERROR_BASE + 20)
%ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND = (%INTERNET_ERROR_BASE + 21)
%ERROR_INTERNET_BAD_REGISTRY_PARAMETER   = (%INTERNET_ERROR_BASE + 22)
%ERROR_INTERNET_NO_DIRECT_ACCESS         = (%INTERNET_ERROR_BASE + 23)
%ERROR_INTERNET_NO_CONTEXT               = (%INTERNET_ERROR_BASE + 24)
%ERROR_INTERNET_NO_CALLBACK              = (%INTERNET_ERROR_BASE + 25)
%ERROR_INTERNET_REQUEST_PENDING          = (%INTERNET_ERROR_BASE + 26)
%ERROR_INTERNET_INCORRECT_FORMAT         = (%INTERNET_ERROR_BASE + 27)
%ERROR_INTERNET_ITEM_NOT_FOUND           = (%INTERNET_ERROR_BASE + 28)
%ERROR_INTERNET_CANNOT_CONNECT           = (%INTERNET_ERROR_BASE + 29)
%ERROR_INTERNET_CONNECTION_ABORTED       = (%INTERNET_ERROR_BASE + 30)
%ERROR_INTERNET_CONNECTION_RESET         = (%INTERNET_ERROR_BASE + 31)
%ERROR_INTERNET_FORCE_RETRY              = (%INTERNET_ERROR_BASE + 32)
%ERROR_INTERNET_INVALID_PROXY_REQUEST    = (%INTERNET_ERROR_BASE + 33)
%ERROR_INTERNET_NEED_UI                  = (%INTERNET_ERROR_BASE + 34)

%ERROR_INTERNET_HANDLE_EXISTS            = (%INTERNET_ERROR_BASE + 36)
%ERROR_INTERNET_SEC_CERT_DATE_INVALID    = (%INTERNET_ERROR_BASE + 37)
%ERROR_INTERNET_SEC_CERT_CN_INVALID      = (%INTERNET_ERROR_BASE + 38)
%ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR   = (%INTERNET_ERROR_BASE + 39)
%ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR   = (%INTERNET_ERROR_BASE + 40)
%ERROR_INTERNET_MIXED_SECURITY           = (%INTERNET_ERROR_BASE + 41)
%ERROR_INTERNET_CHG_POST_IS_NON_SECURE   = (%INTERNET_ERROR_BASE + 42)
%ERROR_INTERNET_POST_IS_NON_SECURE       = (%INTERNET_ERROR_BASE + 43)
%ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED  = (%INTERNET_ERROR_BASE + 44)
%ERROR_INTERNET_INVALID_CA               = (%INTERNET_ERROR_BASE + 45)
%ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP    = (%INTERNET_ERROR_BASE + 46)
%ERROR_INTERNET_ASYNC_THREAD_FAILED      = (%INTERNET_ERROR_BASE + 47)
%ERROR_INTERNET_REDIRECT_SCHEME_CHANGE   = (%INTERNET_ERROR_BASE + 48)
%ERROR_INTERNET_DIALOG_PENDING           = (%INTERNET_ERROR_BASE + 49)
%ERROR_INTERNET_RETRY_DIALOG             = (%INTERNET_ERROR_BASE + 50)
%ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR  = (%INTERNET_ERROR_BASE + 52)
%ERROR_INTERNET_INSERT_CDROM             = (%INTERNET_ERROR_BASE + 53)
%ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED    = (%INTERNET_ERROR_BASE + 54)
%ERROR_INTERNET_SEC_CERT_ERRORS          = (%INTERNET_ERROR_BASE + 55)
%ERROR_INTERNET_SEC_CERT_NO_REV          = (%INTERNET_ERROR_BASE + 56)
%ERROR_INTERNET_SEC_CERT_REV_FAILED      = (%INTERNET_ERROR_BASE + 57)

'//
'// FTP API errors
'//

%ERROR_FTP_TRANSFER_IN_PROGRESS          = (%INTERNET_ERROR_BASE + 110)
%ERROR_FTP_DROPPED                       = (%INTERNET_ERROR_BASE + 111)
%ERROR_FTP_NO_PASSIVE_MODE               = (%INTERNET_ERROR_BASE + 112)

'//
'// gopher API errors
'//

%ERROR_GOPHER_PROTOCOL_ERROR             = (%INTERNET_ERROR_BASE + 130)
%ERROR_GOPHER_NOT_FILE                   = (%INTERNET_ERROR_BASE + 131)
%ERROR_GOPHER_DATA_ERROR                 = (%INTERNET_ERROR_BASE + 132)
%ERROR_GOPHER_END_OF_DATA                = (%INTERNET_ERROR_BASE + 133)
%ERROR_GOPHER_INVALID_LOCATOR            = (%INTERNET_ERROR_BASE + 134)
%ERROR_GOPHER_INCORRECT_LOCATOR_TYPE     = (%INTERNET_ERROR_BASE + 135)
%ERROR_GOPHER_NOT_GOPHER_PLUS            = (%INTERNET_ERROR_BASE + 136)
%ERROR_GOPHER_ATTRIBUTE_NOT_FOUND        = (%INTERNET_ERROR_BASE + 137)
%ERROR_GOPHER_UNKNOWN_LOCATOR            = (%INTERNET_ERROR_BASE + 138)

'//
'// HTTP API errors
'//

%ERROR_HTTP_HEADER_NOT_FOUND             = (%INTERNET_ERROR_BASE + 150)
%ERROR_HTTP_DOWNLEVEL_SERVER             = (%INTERNET_ERROR_BASE + 151)
%ERROR_HTTP_INVALID_SERVER_RESPONSE      = (%INTERNET_ERROR_BASE + 152)
%ERROR_HTTP_INVALID_HEADER               = (%INTERNET_ERROR_BASE + 153)
%ERROR_HTTP_INVALID_QUERY_REQUEST        = (%INTERNET_ERROR_BASE + 154)
%ERROR_HTTP_HEADER_ALREADY_EXISTS        = (%INTERNET_ERROR_BASE + 155)
%ERROR_HTTP_REDIRECT_FAILED              = (%INTERNET_ERROR_BASE + 156)
%ERROR_HTTP_NOT_REDIRECTED               = (%INTERNET_ERROR_BASE + 160)
%ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION    = (%INTERNET_ERROR_BASE + 161)
%ERROR_HTTP_COOKIE_DECLINED              = (%INTERNET_ERROR_BASE + 162)
%ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION  = (%INTERNET_ERROR_BASE + 168)

'//
'// additional Internet API error codes
'//

%ERROR_INTERNET_SECURITY_CHANNEL_ERROR    = (%INTERNET_ERROR_BASE + 157)
%ERROR_INTERNET_UNABLE_TO_CACHE_FILE      = (%INTERNET_ERROR_BASE + 158)
%ERROR_INTERNET_TCPIP_NOT_INSTALLED       = (%INTERNET_ERROR_BASE + 159)
%ERROR_INTERNET_DISCONNECTED              = (%INTERNET_ERROR_BASE + 163)
%ERROR_INTERNET_SERVER_UNREACHABLE        = (%INTERNET_ERROR_BASE + 164)
%ERROR_INTERNET_PROXY_SERVER_UNREACHABLE  = (%INTERNET_ERROR_BASE + 165)

%ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT     = (%INTERNET_ERROR_BASE + 166)
%ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT = (%INTERNET_ERROR_BASE + 167)
%ERROR_INTERNET_SEC_INVALID_CERT          = (%INTERNET_ERROR_BASE + 169)
%ERROR_INTERNET_SEC_CERT_REVOKED          = (%INTERNET_ERROR_BASE + 170)

'// InternetAutodial specific errors

%ERROR_INTERNET_FAILED_DUETOSECURITYCHECK  = (%INTERNET_ERROR_BASE + 171)
%ERROR_INTERNET_NOT_INITIALIZED            = (%INTERNET_ERROR_BASE + 172)
%ERROR_INTERNET_NEED_MSN_SSPI_PKG          = (%INTERNET_ERROR_BASE + 173)
%ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY   = (%INTERNET_ERROR_BASE + 174)

'// Decoding/Decompression specific errors

%ERROR_INTERNET_DECODING_FAILED          = %INTERNET_ERROR_BASE + 175

%INTERNET_ERROR_LAST                     = %ERROR_INTERNET_DECODING_FAILED


'//#endif // !defined(_WINERROR_)

'//
'// URLCACHE APIs
'//

'//
'// datatype definitions.
'//

'//
'// cache entry type flags.
'//

%NORMAL_CACHE_ENTRY              = &H00000001???
%STICKY_CACHE_ENTRY              = &H00000004???
%EDITED_CACHE_ENTRY              = &H00000008???
%TRACK_OFFLINE_CACHE_ENTRY       = &H00000010???
%TRACK_ONLINE_CACHE_ENTRY        = &H00000020???
%SPARSE_CACHE_ENTRY              = &H00010000???
%COOKIE_CACHE_ENTRY              = &H00100000???
%URLHISTORY_CACHE_ENTRY          = &H00200000???

%URLCACHE_FIND_DEFAULT_FILTER    = %NORMAL_CACHE_ENTRY _
                                   OR %COOKIE_CACHE_ENTRY _
                                   OR %URLHISTORY_CACHE_ENTRY _
                                   OR %TRACK_OFFLINE_CACHE_ENTRY _
                                   OR %TRACK_ONLINE_CACHE_ENTRY _
                                   OR %STICKY_CACHE_ENTRY


'//
'// INTERNET_CACHE_ENTRY_INFO -
'//

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable:4201)

'typedef struct _INTERNET_CACHE_ENTRY_INFOA {
'    DWORD dwStructSize;         // version of cache system.
'    LPSTR   lpszSourceUrlName;    // embedded pointer to the URL name string.
'    LPSTR   lpszLocalFileName;  // embedded pointer to the local file name.
'    DWORD CacheEntryType;       // cache type bit mask.
'    DWORD dwUseCount;           // current users count of the cache entry.
'    DWORD dwHitRate;            // num of times the cache entry was retrieved.
'    DWORD dwSizeLow;            // low DWORD of the file size.
'    DWORD dwSizeHigh;           // high DWORD of the file size.
'    FILETIME LastModifiedTime;  // last modified time of the file in GMT format.
'    FILETIME ExpireTime;        // expire time of the file in GMT format
'    FILETIME LastAccessTime;    // last accessed time in GMT format
'    FILETIME LastSyncTime;      // last time the URL was synchronized
'                                // with the source
'    LPSTR   lpHeaderInfo;        // embedded pointer to the header info.
'    DWORD dwHeaderInfoSize;     // size of the above header.
'    LPSTR   lpszFileExtension;  // File extension used to retrive the urldata as a file.
'        union {                     // Exemption delta from last access time.
'                DWORD dwReserved;
'                DWORD dwExemptDelta;
'    };                          // Exemption delta from last access
'} INTERNET_CACHE_ENTRY_INFOA, * LPINTERNET_CACHE_ENTRY_INFOA;

' // Size = 80 bytes
TYPE INTERNET_CACHE_ENTRY_INFOA DWORD
   dwStructSize      AS DWORD      ' DWORD // version of cache system.
   lpszSourceUrlName AS ASCIIZ PTR ' LPSTR // embedded pointer to the URL name string.
   lpszLocalFileName AS ASCIIZ PTR ' LPSTR // embedded pointer to the local file name.
   CacheEntryType    AS DWORD      ' DWORD // cache type bit mask.
   dwUseCount        AS DWORD      ' DWORD // current users count of the cache entry.
   dwHitRate         AS DWORD      ' DWORD // num of times the cache entry was retrieved.
   dwSizeLow         AS DWORD      ' DWORD // low DWORD of the file size.
   dwSizeHigh        AS DWORD      ' DWORD // high DWORD of the file size.
   LastModifiedTime  AS FILETIME   ' FILETIME // last modified time of the file in GMT format.
   ExpireTime        AS FILETIME   ' FILETIME // expire time of the file in GMT format
   LastAccessTime    AS FILETIME   ' FILETIME // last accessed time in GMT format
   LastSyncTime      AS FILETIME   ' FILETIME // last time the URL was synchronized with the source
   lpHeaderInfo      AS BYTE PTR   ' LPBYTE // embedded pointer to the header info.
   dwHeaderInfoSize  AS DWORD      ' DWORD // size of the above header.
   lpszFileExtension AS ASCIIZ PTR ' LPSTR // File extension used to retrieve the urldata as a file.
   dwExemptDelta     AS DWORD      ' DWORD // Exemption delta from last access time.
END TYPE

'typedef struct _INTERNET_CACHE_ENTRY_INFOW {
'    DWORD dwStructSize;         // version of cache system.
'    LPWSTR  lpszSourceUrlName;  // embedded pointer to the URL name string.
'    LPWSTR  lpszLocalFileName;  // embedded pointer to the local file name.
'    DWORD CacheEntryType;       // cache type bit mask.
'    DWORD dwUseCount;           // current users count of the cache entry.
'    DWORD dwHitRate;            // num of times the cache entry was retrieved.
'    DWORD dwSizeLow;            // low DWORD of the file size.
'    DWORD dwSizeHigh;           // high DWORD of the file size.
'    FILETIME LastModifiedTime;  // last modified time of the file in GMT format.
'    FILETIME ExpireTime;        // expire time of the file in GMT format
'    FILETIME LastAccessTime;    // last accessed time in GMT format
'    FILETIME LastSyncTime;      // last time the URL was synchronized
'                                // with the source
'    LPWSTR  lpHeaderInfo;       // embedded pointer to the header info.
'    DWORD dwHeaderInfoSize;     // size of the above header.
'    LPWSTR  lpszFileExtension;  // File extension used to retrive the urldata as a file.
'        union {                 // Exemption delta from last access time.
'                DWORD dwReserved;
'                DWORD dwExemptDelta;
'    };                          // Exemption delta from last access
'} INTERNET_CACHE_ENTRY_INFOW, * LPINTERNET_CACHE_ENTRY_INFOW;

' // Size = 80 bytes
TYPE INTERNET_CACHE_ENTRY_INFOW
   dwStructSize      AS DWORD          ' DWORD // version of cache system.
   lpszSourceUrlName AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the URL name string.
   lpszLocalFileName AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the local file name.
   CacheEntryType    AS DWORD          ' DWORD // cache type bit mask.
   dwUseCount        AS DWORD          ' DWORD // current users count of the cache entry.
   dwHitRate         AS DWORD          ' DWORD // num of times the cache entry was retrieved.
   dwSizeLow         AS DWORD          ' DWORD // low DWORD of the file size.
   dwSizeHigh        AS DWORD          ' DWORD // high DWORD of the file size.
   LastModifiedTime  AS FILETIME       ' FILETIME // last modified time of the file in GMT format.
   ExpireTime        AS FILETIME       ' FILETIME // expire time of the file in GMT format
   LastAccessTime    AS FILETIME       ' FILETIME // last accessed time in GMT format
   LastSyncTime      AS FILETIME       ' FILETIME // last time the URL was synchronized with the source
   lpHeaderInfo      AS BYTE PTR       ' LPBYTE // embedded pointer to the header info.
   dwHeaderInfoSize  AS DWORD          ' DWORD // size of the above header.
   lpszFileExtension AS WSTRINGZ PTR   ' LPWSTR // File extension used to retrieve the urldata as a file.
   dwExemptDelta     AS DWORD          ' DWORD // Exemption delta from last access time.
END TYPE

#IF %DEF(%UNICODE)
   MACRO INTERNET_CACHE_ENTRY_INFO = INTERNET_CACHE_ENTRY_INFOW
#ELSE
   MACRO INTERNET_CACHE_ENTRY_INFO = INTERNET_CACHE_ENTRY_INFOA
#ENDIF

'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning(default:4201)
'#endif

' // Size = 16 bytes
TYPE INTERNET_CACHE_TIMESTAMPS DWORD
   ftExpires      AS FILETIME
   ftLastModified AS FILETIME
END TYPE

'//
'// Cache Group
'//
'typedef LONGLONG GROUPID;


'//
'// Cache Group Flags
'//
%CACHEGROUP_ATTRIBUTE_GET_ALL      = &Hffffffff???
%CACHEGROUP_ATTRIBUTE_BASIC        = &H00000001???
%CACHEGROUP_ATTRIBUTE_FLAG         = &H00000002???
%CACHEGROUP_ATTRIBUTE_TYPE         = &H00000004???
%CACHEGROUP_ATTRIBUTE_QUOTA        = &H00000008???
%CACHEGROUP_ATTRIBUTE_GROUPNAME    = &H00000010???
%CACHEGROUP_ATTRIBUTE_STORAGE      = &H00000020???

%CACHEGROUP_FLAG_NONPURGEABLE      = &H00000001???
%CACHEGROUP_FLAG_GIDONLY           = &H00000004???

%CACHEGROUP_FLAG_FLUSHURL_ONDELETE = &H00000002???

%CACHEGROUP_SEARCH_ALL             = &H00000000???
%CACHEGROUP_SEARCH_BYURL           = &H00000001???

%CACHEGROUP_TYPE_INVALID           = &H00000001???

'//
'// updatable cache group fields
'//
%CACHEGROUP_READWRITE_MASK =                 _
           %CACHEGROUP_ATTRIBUTE_TYPE        _
        OR %CACHEGROUP_ATTRIBUTE_QUOTA       _
        OR %CACHEGROUP_ATTRIBUTE_GROUPNAME   _
        OR %CACHEGROUP_ATTRIBUTE_STORAGE

'//
'// INTERNET_CACHE_GROUP_INFO
'//

%GROUPNAME_MAX_LENGTH     = 120
%GROUP_OWNER_STORAGE_SIZE = 4

' // Size = 156 bytes
TYPE INTERNET_CACHE_GROUP_INFOA
   dwGroupSize  AS DWORD                                    ' DWORD
   dwGroupFlags AS DWORD                                    ' DWORD
   dwGroupType  AS DWORD                                    ' DWORD
   dwDiskUsage  AS DWORD                                    ' DWORD // in KB
   dwDiskQuota  AS DWORD                                    ' DWORD // in KB
   dwOwnerStorage(%GROUP_OWNER_STORAGE_SIZE - 1) AS DWORD   ' DWORD[GROUP_OWNER_STORAGE_SIZE]
   szGroupName AS ASCIIZ * %GROUPNAME_MAX_LENGTH            ' CHAR[GROUPNAME_MAX_LENGTH]
END TYPE

' // Size = 276 bytes
TYPE INTERNET_CACHE_GROUP_INFOW
   dwGroupSize  AS DWORD                                     ' DWORD
   dwGroupFlags AS DWORD                                     ' DWORD
   dwGroupType  AS DWORD                                     ' DWORD
   dwDiskUsage  AS DWORD                                     ' DWORD // in KB
   dwDiskQuota  AS DWORD                                     ' DWORD // in KB
   dwOwnerStorage(%GROUP_OWNER_STORAGE_SIZE - 1) AS DWORD    ' DWORD[GROUP_OWNER_STORAGE_SIZE]
   szGroupName  AS WSTRINGZ * %GROUPNAME_MAX_LENGTH          ' WCHAR[GROUPNAME_MAX_LENGTH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO INTERNET_CACHE_GROUP_INFO = INTERNET_CACHE_GROUP_INFOW
#ELSE
   MACRO INTERNET_CACHE_GROUP_INFO = INTERNET_CACHE_GROUP_INFOA
#ENDIF

'//
'// Cache APIs
'//

DECLARE FUNCTION CreateUrlCacheEntryA IMPORT "WININET.DLL" ALIAS "CreateUrlCacheEntryA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrlName
 , BYVAL dwExpectedFileSize AS DWORD _                  ' __in DWORD dwExpectedFileSize
 , BYREF lpszFileExtension AS ASCIIZ _                  ' __in_opt LPCSTR lpszFileExtension
 , BYREF lpszFileName AS ASCIIZ _                       ' __out LPSTR lpszFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateUrlCacheEntryW IMPORT "WININET.DLL" ALIAS "CreateUrlCacheEntryW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrlName
 , BYVAL dwExpectedFileSize AS DWORD _                  ' __in DWORD dwExpectedFileSize
 , BYREF lpszFileExtension AS WSTRINGZ _                ' __in_opt LPCWSTR lpszFileExtension
 , BYREF lpszFileName AS WSTRINGZ _                     ' __out LPWSTR lpszFileName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateUrlCacheEntry = CreateUrlCacheEntryW
#ELSE
   MACRO CreateUrlCacheEntry = CreateUrlCacheEntryA
#ENDIF

'#ifndef USE_FIXED_COMMIT_URL_CACHE_ENTRY
'// Temporary state of affairs until we reconcile our apis.

'// Why are we doing this? HeaderInfo _should_ be string data.
'// However, one group is passing binary data instead. For the
'// unicode api, we've decided to disallow this, but this
'// brings up an inconsistency between the u and a apis, which
'// is undesirable.

'// For Beta 1, we'll go with this behaviour, but in future releases
'// we want to make these apis consistent.

DECLARE FUNCTION CommitUrlCacheEntryA IMPORT "WININET.DLL" ALIAS "CommitUrlCacheEntryA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in LPCSTR lpszUrlName
 , BYREF lpszLocalFileName AS ASCIIZ _                  ' __in_opt LPCSTR lpszLocalFileName
 , BYVAL ExpireTime AS FILETIME _                       ' __in FILETIME ExpireTime
 , BYVAL LastModifiedTime AS FILETIME _                 ' __in FILETIME LastModifiedTime
 , BYVAL CacheEntryType AS DWORD _                      ' __in DWORD CacheEntryType
 , BYVAL lpHeaderInfo AS BYTE PTR _                     ' __in LPBYTE lpHeaderInfo
 , BYREF dwHeaderSize AS DWORD _                        ' __in_opt DWORD dwHeaderSize
 , BYREF lpszFileExtension AS ASCIIZ _                  ' __in LPCSTR lpszFileExtension
 , OPTIONAL BYREF lpszOriginalUrl AS ASCIIZ _           ' __in_opt LPCSTR lpszOriginalUrl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CommitUrlCacheEntryW IMPORT "WININET.DLL" ALIAS "CommitUrlCacheEntryW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in LPCWSTR lpszUrlName
 , BYREF lpszLocalFileName AS WSTRINGZ _                ' __in_opt LPCWSTR lpszLocalFileName
 , BYVAL ExpireTime AS FILETIME _                       ' __in FILETIME ExpireTime
 , BYVAL LastModifiedTime AS FILETIME _                 ' __in FILETIME LastModifiedTime
 , BYVAL CacheEntryType AS DWORD _                      ' __in DWORD CacheEntryType
 , BYREF lpHeaderInfo AS WSTRINGZ _                     ' __in LPCWSTR lpHeaderInfo
 , BYREF dwHeaderSize AS DWORD _                        ' __in_opt DWORD dwHeaderSize
 , BYREF lpszFileExtension AS WSTRINGZ _                ' __in LPCWSTR lpszFileExtension
 , OPTIONAL BYREF lpszOriginalUrl AS WSTRINGZ _         ' __in_opt LPWCSTR lpszOriginalUrl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CommitUrlCacheEntry = CommitUrlCacheEntryW
#ELSE
   MACRO CommitUrlCacheEntry = CommitUrlCacheEntryA
#ENDIF

DECLARE FUNCTION RetrieveUrlCacheEntryFileA IMPORT "WININET.DLL" ALIAS "RetrieveUrlCacheEntryFileA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RetrieveUrlCacheEntryFileW IMPORT "WININET.DLL" ALIAS "RetrieveUrlCacheEntryFileW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RetrieveUrlCacheEntryFile = RetrieveUrlCacheEntryFileW
#ELSE
   MACRO RetrieveUrlCacheEntryFile = RetrieveUrlCacheEntryFileA
#ENDIF

DECLARE FUNCTION UnlockUrlCacheEntryFileA IMPORT "WININET.DLL" ALIAS "UnlockUrlCacheEntryFileA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrlName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnlockUrlCacheEntryFileW IMPORT "WININET.DLL" ALIAS "UnlockUrlCacheEntryFileW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrlName
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UnlockUrlCacheEntryFile = UnlockUrlCacheEntryFileW
#ELSE
   MACRO UnlockUrlCacheEntryFile = UnlockUrlCacheEntryFileA
#ENDIF

DECLARE FUNCTION RetrieveUrlCacheEntryStreamA IMPORT "WININET.DLL" ALIAS "RetrieveUrlCacheEntryStreamA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in LPCSTR  lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 , BYVAL fRandomRead AS LONG _                          ' __in BOOL fRandomRead
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION RetrieveUrlCacheEntryStreamW IMPORT "WININET.DLL" ALIAS "RetrieveUrlCacheEntryStreamW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in LPCWSTR  lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 , BYVAL fRandomRead AS LONG _                          ' __in BOOL fRandomRead
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO RetrieveUrlCacheEntryStream = RetrieveUrlCacheEntryStreamW
#ELSE
   MACRO RetrieveUrlCacheEntryStream = RetrieveUrlCacheEntryStreamA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadUrlCacheEntryStream LIB "WinINet.dll" _
   ALIAS "ReadUrlCacheEntryStream" _
   ( _
    BYVAL hUrlCacheStream AS DWORD, _      ' in
    BYVAL dwLocation      AS DWORD, _      ' in
    BYVAL lpBuffer        AS BYTE PTR, _   ' in, out
    lpdwLen               AS DWORD, _      ' in, out
    BYVAL dwReserved      AS DWORD _       ' in
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION ReadUrlCacheEntryStream IMPORT "WININET.DLL" ALIAS "ReadUrlCacheEntryStream" ( _
   BYVAL hUrlCacheStream AS DWORD _                     ' __in HANDLE hUrlCacheStream
 , BYVAL dwLocation AS DWORD _                          ' __in DWORD dwLocation
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwLen AS DWORD _                             ' __inout LPDWORD lpdwLen
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadUrlCacheEntryStreamEx LIB "WinINet.dll" _
   ALIAS "ReadUrlCacheEntryStreamEx" _
   ( _
    BYVAL hUrlCacheStream AS DWORD, _      ' in
    BYVAL dwLocation      AS QUAD, _       ' in
    BYVAL lpBuffer        AS BYTE PTR, _   ' in, out
    lpdwLen               AS DWORD _       ' in, out
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION ReadUrlCacheEntryStreamEx IMPORT "WININET.DLL" ALIAS "ReadUrlCacheEntryStreamEx" ( _
   BYVAL hUrlCacheStream AS DWORD _                     ' __in HANDLE hUrlCacheStream
 , BYVAL qwLocation AS QUAD _                           ' __in DWORDLONG qwLocation
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwLen AS DWORD _                             ' __inout LPDWORD lpdwLen
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION UnlockUrlCacheEntryStream IMPORT "WININET.DLL" ALIAS "UnlockUrlCacheEntryStream" ( _
   BYVAL hUrlCacheStream AS DWORD _                     ' __in HANDLE hUrlCacheStream
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheEntryInfoA IMPORT "WININET.DLL" ALIAS "GetUrlCacheEntryInfoA" ( _
   BYREF lpszUrl AS ASCIIZ _                      ' __in LPCSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _  ' __out LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo,
 , OPTIONAL BYREF lpcbCacheEntryInfo AS DWORD _         ' __inout_opt LPDWORD lpcbCacheEntryInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheEntryInfoW IMPORT "WININET.DLL" ALIAS "GetUrlCacheEntryInfoW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo,
 , OPTIONAL BYREF lpcbCacheEntryInfo AS DWORD _         ' __inout_opt LPDWORD lpcbCacheEntryInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUrlCacheEntryInfo = GetUrlCacheEntryInfoW
#ELSE
   MACRO GetUrlCacheEntryInfo = GetUrlCacheEntryInfoA
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheGroup IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheGroup" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL LPVOIDlpSearchCondition AS DWORD _             ' __in LPVOIDlpSearchCondition
 , BYVAL dwSearchCondition AS DWORD _                   ' __in DWORD dwSearchCondition
 , BYREF lpGroupId AS QUAD _                            ' __out GROUPID* lpGroupId
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindNextUrlCacheGroup IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheGroup" ( _
   BYVAL hFind AS DWORD _                               ' __in HANDLE hFind
 , BYREF lpGroupId AS QUAD _                            ' __out GROUPID* lpGroupId
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheGroupAttributeA IMPORT "WININET.DLL" ALIAS "GetUrlCacheGroupAttributeA" ( _
   BYVAL gid AS QUAD _                                  ' __in GROUPID gid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYREF lpGroupInfo AS INTERNET_CACHE_GROUP_INFOA _    ' __out LPINTERNET_CACHE_GROUP_INFOA lpGroupInfo
 , BYREF lpdwGroupInfo AS DWORD _                       ' __inout LPDWORD lpdwGroupInfo
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheGroupAttributeW IMPORT "WININET.DLL" ALIAS "GetUrlCacheGroupAttributeW" ( _
   BYVAL gid AS QUAD _                                  ' __in GROUPID gid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYREF lpGroupInfo AS INTERNET_CACHE_GROUP_INFOW _    ' __out LPINTERNET_CACHE_GROUP_INFOW lpGroupInfo
 , BYREF lpdwGroupInfo AS DWORD _                       ' __inout LPDWORD lpdwGroupInfo
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUrlCacheGroupAttribute = GetUrlCacheGroupAttributeW
#ELSE
   MACRO GetUrlCacheGroupAttribute = GetUrlCacheGroupAttributeA
#ENDIF

DECLARE FUNCTION SetUrlCacheGroupAttributeA IMPORT "WININET.DLL" ALIAS "SetUrlCacheGroupAttributeA" ( _
   BYVAL gid AS QUAD _                                  ' __in GROUPID gid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYREF lpGroupInfo AS INTERNET_CACHE_GROUP_INFOA _    ' __in LPINTERNET_CACHE_GROUP_INFOA lpGroupInfo
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUrlCacheGroupAttributeW IMPORT "WININET.DLL" ALIAS "SetUrlCacheGroupAttributeW" ( _
   BYVAL gid AS QUAD _                                  ' __in GROUPID gid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYREF lpGroupInfo AS INTERNET_CACHE_GROUP_INFOW _    ' __in LPINTERNET_CACHE_GROUP_INFOW lpGroupInfo
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetUrlCacheGroupAttribute = SetUrlCacheGroupAttributeW
#ELSE
   MACRO SetUrlCacheGroupAttribute = SetUrlCacheGroupAttributeA
#ENDIF

DECLARE FUNCTION CreateUrlCacheGroup IMPORT "WININET.DLL" ALIAS "CreateUrlCacheGroup" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS QUAD                                              ' GROUPID

DECLARE FUNCTION DeleteUrlCacheGroup IMPORT "WININET.DLL" ALIAS "DeleteUrlCacheGroup" ( _
   BYVAL GroupId AS QUAD _                              ' __in GROUPID GroupId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID  lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUrlCacheEntryInfoExA LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExA" _
   ( _
    lpszUrl                   AS ASCIIZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOA, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GetUrlCacheEntryInfoExA IMPORT "WININET.DLL" ALIAS "GetUrlCacheEntryInfoExA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout_opt LPDWORD lpcbCacheEntryInfo
 , BYREF lpszRedirectUrl AS ASCIIZ _                    ' __in LPSTR lpszRedirectUrl
 , BYVAL lpcbRedirectUrl AS DWORD _                     ' __in LPDWORD lpcbRedirectUrl
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUrlCacheEntryInfoExW LIB "WinINet.dll" _
   ALIAS "GetUrlCacheEntryInfoExW" _
   ( _
    lpszUrl                   AS WSTRINGZ, _   ' in
    lpCacheEntryInfo          AS INTERNET_CACHE_ENTRY_INFOW, _  ' out
    lpdwCacheEntryInfoBufSize AS DWORD, _    ' in, out
    BYVAL lpszReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpdwReserved        AS DWORD, _    ' must pass %NULL
    BYVAL lpReserved          AS DWORD, _    ' must pass %NULL
    BYVAL dwFlags             AS DWORD _     ' must pass %NULL
   ) _
   AS LONG
#ELSE
DECLARE FUNCTION GetUrlCacheEntryInfoExW IMPORT "WININET.DLL" ALIAS "GetUrlCacheEntryInfoExW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout_opt LPDWORD lpcbCacheEntryInfo
 , BYREF lpszRedirectUrl AS WSTRINGZ _                  ' __in LPWSTR lpszRedirectUrl
 , BYVAL lpcbRedirectUrl AS DWORD _                     ' __in LPDWORD lpcbRedirectUrl
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetUrlCacheEntryInfoEx = GetUrlCacheEntryInfoExW
#ELSE
   MACRO GetUrlCacheEntryInfoEx = GetUrlCacheEntryInfoExA
#ENDIF

%CACHE_ENTRY_ATTRIBUTE_FC    = &H00000004???
%CACHE_ENTRY_HITRATE_FC      = &H00000010???
%CACHE_ENTRY_MODTIME_FC      = &H00000040???
%CACHE_ENTRY_EXPTIME_FC      = &H00000080???
%CACHE_ENTRY_ACCTIME_FC      = &H00000100???
%CACHE_ENTRY_SYNCTIME_FC     = &H00000200???
%CACHE_ENTRY_HEADERINFO_FC   = &H00000400???
%CACHE_ENTRY_EXEMPT_DELTA_FC = &H00000800???

DECLARE FUNCTION SetUrlCacheEntryInfoA IMPORT "WININET.DLL" ALIAS "SetUrlCacheEntryInfoA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __in LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUrlCacheEntryInfoW IMPORT "WININET.DLL" ALIAS "SetUrlCacheEntryInfoW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrlName
 , BYREF lpCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __in LPINTERNET_CACHE_ENTRY_INFOW lpCacheEntryInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetUrlCacheEntryInfo = SetUrlCacheEntryInfoW
#ELSE
   MACRO SetUrlCacheEntryInfo = SetUrlCacheEntryInfoA
#ENDIF

'// Flags for SetUrlCacheEntryGroup
%INTERNET_CACHE_GROUP_ADD      = 0
%INTERNET_CACHE_GROUP_REMOVE   = 1

DECLARE FUNCTION SetUrlCacheEntryGroupA IMPORT "WININET.DLL" ALIAS "SetUrlCacheEntryGroupA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in LPCSTR   lpszUrlName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 , BYVAL GroupId AS QUAD _                              ' __in GROUPID  GroupId
 , BYREF pbGroupAttributes AS DWORD _                   ' __in LPBYTE   pbGroupAttributes // must pass NULL
 , BYVAL cbGroupAttributes AS DWORD _                   ' __in DWORD    cbGroupAttributes // must pass 0
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID   lpReserved         // must pass NULL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUrlCacheEntryGroupW IMPORT "WININET.DLL" ALIAS "SetUrlCacheEntryGroupW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in LPCWSTR  lpszUrlName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD    dwFlags
 , BYVAL GroupId AS QUAD _                              ' __in GROUPID  GroupId
 , BYREF pbGroupAttributes AS DWORD _                   ' __in LPBYTE   pbGroupAttributes // must pass NULL
 , BYVAL cbGroupAttributes AS DWORD _                   ' __in DWORD    cbGroupAttributes // must pass 0
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID   lpReserved         // must pass NULL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetUrlCacheEntryGroup = SetUrlCacheEntryGroupW
#ELSE
   MACRO SetUrlCacheEntryGroup = SetUrlCacheEntryGroupA
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheEntryExA IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheEntryExA" ( _
   BYREF lpszUrlSearchPattern AS ASCIIZ _               ' __in_opt LPCSTR lpszUrlSearchPattern
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwFilter AS DWORD _                            ' __in DWORD dwFilter
 , BYVAL GroupId AS QUAD _                              ' __in GROUPID GroupId
 , BYREF lpFirstCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo,
 , BYREF lpcbEntryInfo AS DWORD _                       ' __inout LPDWORD lpcbEntryInfo
 , BYVAL lpGroupAttributes AS DWORD _                   ' __in LPVOID lpGroupAttributes
 , BYVAL lpcbGroupAttributes AS DWORD _                 ' __in LPDWORD lpcbGroupAttributes
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstUrlCacheEntryExW IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheEntryExW" ( _
   BYREF lpszUrlSearchPattern AS WSTRINGZ _             ' __in_opt LPCWSTR lpszUrlSearchPattern
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwFilter AS DWORD _                            ' __in DWORD dwFilter
 , BYVAL GroupId AS QUAD _                              ' __in GROUPID GroupId
 , BYREF lpFirstCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo,
 , BYREF lpcbEntryInfo AS DWORD _                       ' __inout LPDWORD lpcbEntryInfo
 , BYVAL lpGroupAttributes AS DWORD _                   ' __in LPVOID lpGroupAttributes
 , BYVAL lpcbGroupAttributes AS DWORD _                 ' __in LPDWORD lpcbGroupAttributes
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstUrlCacheEntryEx = FindFirstUrlCacheEntryExW
#ELSE
   MACRO FindFirstUrlCacheEntryEx = FindFirstUrlCacheEntryExA
#ENDIF

DECLARE FUNCTION FindNextUrlCacheEntryExA IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheEntryExA" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in HANDLE hEnumHandle
 , BYREF lpNextCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo,
 , BYREF lpcbEntryInfo AS DWORD _                       ' __inout LPDWORD lpcbEntryInfo
 , BYVAL lpGroupAttributes AS DWORD _                   ' __in LPVOID lpGroupAttributes
 , BYVAL lpcbGroupAttributes AS DWORD _                 ' __in LPDWORD lpcbGroupAttributes
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextUrlCacheEntryExW IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheEntryExW" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in HANDLE hEnumHandle
 , BYREF lpNextCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo,
 , BYREF lpcbEntryInfo AS DWORD _                       ' __inout LPDWORD lpcbEntryInfo
 , BYVAL lpGroupAttributes AS DWORD _                   ' __in LPVOID lpGroupAttributes
 , BYVAL lpcbGroupAttributes AS DWORD _                 ' __in LPDWORD lpcbGroupAttributes
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextUrlCacheEntryEx = FindNextUrlCacheEntryExW
#ELSE
   MACRO FindNextUrlCacheEntryEx = FindNextUrlCacheEntryExA
#ENDIF

DECLARE FUNCTION FindFirstUrlCacheEntryA IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheEntryA" ( _
   BYREF lpszUrlSearchPattern AS ASCIIZ _               ' __in_opt LPCSTR lpszUrlSearchPattern
 , BYREF lpFirstCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' __out LPINTERNET_CACHE_ENTRY_INFOA lpFirstCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstUrlCacheEntryW IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheEntryW" ( _
   BYREF lpszUrlSearchPattern AS WSTRINGZ _             ' __in_opt LPCWSTR lpszUrlSearchPattern
 , BYREF lpFirstCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpFirstCacheEntryInfo,
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstUrlCacheEntry = FindFirstUrlCacheEntryW
#ELSE
   MACRO FindFirstUrlCacheEntry = FindFirstUrlCacheEntryA
#ENDIF

DECLARE FUNCTION FindNextUrlCacheEntryA IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheEntryA" ( _
   BYVAL hEnumHandle AS DWORD  _                        ' __in HANDLE hEnumHandle
 , BYREF lpNextCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOA _ ' _out LPINTERNET_CACHE_ENTRY_INFOA lpNextCacheEntryInfo
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextUrlCacheEntryW IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheEntryW" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in HANDLE hEnumHandle
 , BYREF lpNextCacheEntryInfo AS INTERNET_CACHE_ENTRY_INFOW _ ' __out LPINTERNET_CACHE_ENTRY_INFOW lpNextCacheEntryInfo
 , BYREF lpcbCacheEntryInfo AS DWORD _                  ' __inout LPDWORD lpcbCacheEntryInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextUrlCacheEntry = FindNextUrlCacheEntryW
#ELSE
   MACRO FindNextUrlCacheEntry = FindNextUrlCacheEntryA
#ENDIF

DECLARE FUNCTION FindCloseUrlCache IMPORT "WININET.DLL" ALIAS "FindCloseUrlCache" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in HANDLE hEnumHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteUrlCacheEntryA IMPORT "WININET.DLL" ALIAS "DeleteUrlCacheEntryA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in LPCSTR lpszUrlName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteUrlCacheEntryW IMPORT "WININET.DLL" ALIAS "DeleteUrlCacheEntryW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in LPCWSTR lpszUrlName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteUrlCacheEntry = DeleteUrlCacheEntryW
#ELSE
   MACRO DeleteUrlCacheEntry = DeleteUrlCacheEntryA
#ENDIF

'//
'// Autodial APIs
'//

DECLARE FUNCTION InternetDialA IMPORT "WININET.DLL" ALIAS "InternetDialA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF lpszConnectoid AS ASCIIZ _                     ' __in LPSTR lpszConnectoid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpdwConnection AS DWORD _                      ' __out DWORD_PTR *lpdwConnection
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION InternetDialW IMPORT "WININET.DLL" ALIAS "InternetDialW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF lpszConnectoid AS WSTRINGZ _                   ' __in LPWSTR lpszConnectoid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpdwConnection AS DWORD _                      ' __out DWORD_PTR *lpdwConnection
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO InternetDial = InternetDialW
#ELSE
   MACRO InternetDial = InternetDialA
#ENDIF

'// Flags for InternetDial - must not conflict with InternetAutodial flags
'//                          as they are valid here also.
%INTERNET_DIAL_FORCE_PROMPT = &H2000???
%INTERNET_DIAL_SHOW_OFFLINE = &H4000???
%INTERNET_DIAL_UNATTENDED   = &H8000???

DECLARE FUNCTION InternetHangUp IMPORT "WININET.DLL" ALIAS "InternetHangUp" ( _
   BYVAL dwConnection AS DWORD _                        ' __in DWORD_PTR dwConnection
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' DWORD

%INTERENT_GOONLINE_REFRESH = &H00000001???
%INTERENT_GOONLINE_MASK    = &H00000001???

DECLARE FUNCTION InternetGoOnlineA IMPORT "WININET.DLL" ALIAS "InternetGoOnlineA" ( _
   BYREF lpszURL AS ASCIIZ _                            ' __in_opt LPCSTR lpszURL
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGoOnlineW IMPORT "WININET.DLL" ALIAS "InternetGoOnlineW" ( _
   BYREF lpszURL AS WSTRINGZ _                          ' __in_opt LPCWSTR lpszURL
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGoOnline = InternetGoOnlineW
#ELSE
   MACRO InternetGoOnline = InternetGoOnlineA
#ENDIF

DECLARE FUNCTION InternetAutodial IMPORT "WININET.DLL" ALIAS "InternetAutodial" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 ) AS LONG                                              ' BOOL

'// Flags for InternetAutodial
%INTERNET_AUTODIAL_FORCE_ONLINE         = 1
%INTERNET_AUTODIAL_FORCE_UNATTENDED     = 2
%INTERNET_AUTODIAL_FAILIFSECURITYCHECK  = 4
%INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT = 8

%INTERNET_AUTODIAL_FLAGS_MASK = %INTERNET_AUTODIAL_FORCE_ONLINE _
                             OR %INTERNET_AUTODIAL_FORCE_UNATTENDED _
                             OR %INTERNET_AUTODIAL_FAILIFSECURITYCHECK _
                             OR %INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT

DECLARE FUNCTION InternetAutodialHangup IMPORT "WININET.DLL" ALIAS "InternetAutodialHangup" ( _
   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetConnectedState IMPORT "WININET.DLL" ALIAS "InternetGetConnectedState" ( _
   BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetConnectedStateExA IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateExA" ( _
   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD lpdwFlags
 , BYREF lpszConnectionName AS ASCIIZ _                 ' __out LPSTR lpszConnectionName
 , BYVAL dwBufLen AS DWORD _                            ' __in DWORD dwBufLen
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetConnectedStateExW IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateExW" ( _
   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD lpdwFlags
 , BYREF lpszConnectionName AS WSTRINGZ _               ' __out LPWSTR lpszConnectionName
 , BYVAL dwBufLen AS DWORD _                            ' __in DWORD dwBufLen
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetConnectedStateEx = InternetGetConnectedStateExW
#ELSE
   MACRO InternetGetConnectedStateEx = InternetGetConnectedStateExA
#ENDIF

%PROXY_AUTO_DETECT_TYPE_DHCP   = 1
%PROXY_AUTO_DETECT_TYPE_DNS_A  = 2

'struct AutoProxyHelperFunctions;

'typedef struct AutoProxyHelperVtbl
'{
'    BOOL ( __stdcall *IsResolvable )(
'            LPSTR   lpszHost);

'    DWORD ( __stdcall *GetIPAddress )(
'           LPSTR   lpszIPAddress,
'           LPDWORD lpdwIPAddressSize);

'    DWORD ( __stdcall *ResolveHostName )(
'           LPSTR   lpszHostName,
'           LPSTR   lpszIPAddress,
'           LPDWORD lpdwIPAddressSize);

'    BOOL ( __stdcall *IsInNet )(
'            LPSTR   lpszIPAddress,
'            LPSTR   lpszDest,
'            LPSTR   lpszMask);

'    BOOL ( __stdcall *IsResolvableEx )(
'            LPSTR lpszHost
'        );

'    DWORD ( __stdcall *GetIPAddressEx )(
'            LPSTR     lpszIPAddress,
'            LPDWORD lpdwIPAddressSize
'        );

'    DWORD ( __stdcall *ResolveHostNameEx )(
'            LPSTR lpszHostName,
'            LPSTR lpszIPAddress,
'            LPDWORD lpdwIPAddressSize
'        );

'    BOOL ( __stdcall *IsInNetEx )(
'            LPSTR lpszIPAddress,
'            LPSTR lpszIPPrefix
'        );

'    DWORD ( __stdcall *SortIpList )(
'            LPSTR lpszIPAddressList,
'            LPSTR lpszIPSortedList,
'            LPDWORD lpdwIPSortedListSize
'        );


'}AutoProxyHelperVtbl;

' // Size = 36 bytes
TYPE AutoProxyHelperVtbl DWORD
   IsResolvable      AS DWORD
   GetIPAddress      AS DWORD
   ResolveHostName   AS DWORD
   IsInNet           AS DWORD
   IsResolvableEx    AS DWORD
   GetIPAddressEx    AS DWORD
   ResolveHostNameEx AS DWORD
   IsInNetEx         AS DWORD
   SortIpList        AS DWORD
END TYPE

' // Size = 12 bytes
TYPE AUTO_PROXY_SCRIPT_BUFFER DWORD
   dwStructSize       AS DWORD        ' DWORD // Size of struct
   lpszScriptBuffer   AS ASCIIZ PTR   ' LPSTR // Buffer to Pass
   dwScriptBufferSize AS DWORD        ' DWORD // Size of buffer above
END TYPE

'typedef struct AutoProxyHelperFunctions
'{
'    const struct AutoProxyHelperVtbl * lpVtbl;
'} AutoProxyHelperFunctions;

' // Size = 4 bytes
TYPE AutoProxyHelperFunctions DWORD
   lpVtbl AS AutoProxyHelperVtbl PTR   ' const struct AutoProxyHelperVtbl * lpVtbl
END TYPE

'typedef BOOL ( CALLBACK *pfnInternetInitializeAutoProxyDll)(DWORD dwVersion,
'                           LPSTR lpszDownloadedTempFile,
'                           LPSTR lpszMime,
'                           AutoProxyHelperFunctions* lpAutoProxyCallbacks,
'                           LPAUTO_PROXY_SCRIPT_BUFFER lpAutoProxyScriptBuffer );

'typedef BOOL (CALLBACK *pfnInternetDeInitializeAutoProxyDll)(LPSTR lpszMime,
'                           DWORD dwReserved);

'typedef BOOL (CALLBACK *pfnInternetGetProxyInfo)(LPCSTR lpszUrl,
'                           DWORD dwUrlLength,
'                           LPSTR lpszUrlHostName,
'                           DWORD dwUrlHostNameLength,
'                           LPSTR* lplpszProxyHostName,
'                           LPDWORD lpdwProxyHostNameLength);

' enum WPAD_CACHE_DELETE
%WPAD_CACHE_DELETE_CURRENT = &H0
%WPAD_CACHE_DELETE_ALL = &H1

DECLARE FUNCTION DeleteWpadCacheForNetworks IMPORT "JSPROXY.DLL" ALIAS "DeleteWpadCacheForNetworks" ( _
   BYVAL DWORD _                                        ' __in WPAD_CACHE_DELETE
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetInitializeAutoProxyDll IMPORT "JSPROXY.DLL" ALIAS "InternetInitializeAutoProxyDll" ( _
   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetDeInitializeAutoProxyDll IMPORT "JSPROXY.DLL" ALIAS "InternetDeInitializeAutoProxyDll" ( _
   BYREF lpszMime AS ASCIIZ _                           ' __in LPSTR lpszMime
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetProxyInfo IMPORT "JSPROXY.DLL" ALIAS "InternetGetProxyInfo" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYVAL dwUrlLength AS DWORD _                         ' __in DWORD dwUrlLength
 , BYREF lpszUrlHostName AS ASCIIZ _                    ' __in LPSTR lpszUrlHostName
 , BYVAL dwUrlHostNameLength AS DWORD _                 ' __in DWORD dwUrlHostNameLength
 , BYREF lplpszProxyHostName AS ASCIIZ _                ' __out LPSTR * lplpszProxyHostName
 , BYREF lpdwProxyHostNameLength AS DWORD _             ' __out LPDWORD lpdwProxyHostNameLength
 ) AS LONG                                              ' BOOL

' Not in Vista SDK. See DetectAutoProxyUrl below.
DECLARE FUNCTION InternetAutoProxyUrl IMPORT "WININET.DLL" ALIAS "InternetAutoProxyUrl" ( _
   BYREF lpszAutoProxyUrl AS ASCIIZ _                   ' __out LPSTR lpszAutoProxyUrl
 , BYVAL dwAutoProxyUrlLength AS DWORD _                ' __in DWORD dwAutoProxyUrlLength
 , BYVAL dwDetectFlags AS DWORD _                       ' __in DWORD dwDetectFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DetectAutoProxyUrl IMPORT "WININET.DLL" ALIAS "DetectAutoProxyUrl" ( _
   BYREF lpszAutoProxyUrl AS ASCIIZ _                   ' __out LPSTR lpszAutoProxyUrl
 , BYVAL dwAutoProxyUrlLength AS DWORD _                ' __in DWORD dwAutoProxyUrlLength
 , BYVAL dwDetectFlags AS DWORD _                       ' __in DWORD dwDetectFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateMD5SSOHash LIB "WinINet.dll" _
    ALIAS "CreateMD5SSOHash" ( _
    pszChallengeInfo AS WSTRINGZ, _
    pwszRealm        AS WSTRINGZ, _
    pwszTarget       AS WSTRINGZ, _
    BYVAL pbHexHash  AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CreateMD5SSOHash IMPORT "WININET.DLL" ALIAS "CreateMD5SSOHash" ( _
   BYREF pszChallengeInfo AS WSTRINGZ _                 ' __in PWSTR pszChallengeInfo
 , BYREF pwszRealm AS WSTRINGZ _                        ' __in PWSTR pwszRealm
 , BYREF pwszTarget AS WSTRINGZ _                       ' __in PWSTR pwszTarget
 , BYREF pbHexHash AS ANY _                             ' __out PBYTE pbHexHash
 ) AS LONG                                              ' BOOL
#ENDIF

'// Flags for InternetGetConnectedState and Ex
%INTERNET_CONNECTION_MODEM           = &H01???
%INTERNET_CONNECTION_LAN             = &H02???
%INTERNET_CONNECTION_PROXY           = &H04???
%INTERNET_CONNECTION_MODEM_BUSY      = &H08???    ' /* no longer used */
%INTERNET_RAS_INSTALLED              = &H10???
%INTERNET_CONNECTION_OFFLINE         = &H20???
%INTERNET_CONNECTION_CONFIGURED      = &H40???

'//
'// Custom dial handler functions
'//

'// Custom dial handler prototype
'typedef DWORD (CALLBACK * PFN_DIAL_HANDLER) (HWND, LPCSTR, DWORD, LPDWORD);

'// Flags for custom dial handler
%INTERNET_CUSTOMDIAL_CONNECT         = 0???
%INTERNET_CUSTOMDIAL_UNATTENDED      = 1???
%INTERNET_CUSTOMDIAL_DISCONNECT      = 2???
%INTERNET_CUSTOMDIAL_SHOWOFFLINE     = 4???

'// Custom dial handler supported functionality flags
%INTERNET_CUSTOMDIAL_SAFE_FOR_UNATTENDED = 1???
%INTERNET_CUSTOMDIAL_WILL_SUPPLY_STATE   = 2???
%INTERNET_CUSTOMDIAL_CAN_HANGUP          = 4???

DECLARE FUNCTION InternetSetDialStateA IMPORT "WININET.DLL" ALIAS "InternetSetDialStateA" ( _
   BYREF lpszConnectoid AS ASCIIZ _                     ' __in_opt LPCSTR lpszConnectoid
 , BYVAL dwState AS DWORD _                             ' __in DWORD dwState
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSetDialStateW IMPORT "WININET.DLL" ALIAS "InternetSetDialStateW" ( _
   BYREF lpszConnectoid AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszConnectoid
 , BYVAL dwState AS DWORD _                             ' __in DWORD dwState
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSetDialState = InternetSetDialStateW
#ELSE
   MACRO InternetSetDialState = InternetSetDialStateA
#ENDIF

'// States for InternetSetDialState
%INTERNET_DIALSTATE_DISCONNECTED = 1

DECLARE FUNCTION InternetSetPerSiteCookieDecisionA IMPORT "WININET.DLL" ALIAS "InternetSetPerSiteCookieDecisionA" ( _
   BYREF pchHostName AS ASCIIZ _                        ' __in LPCSTR pchHostName
 , BYVAL dwDecision AS DWORD _                          ' __in DWORD dwDecision
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSetPerSiteCookieDecisionW IMPORT "WININET.DLL" ALIAS "InternetSetPerSiteCookieDecisionW" ( _
   BYREF pchHostName AS WSTRINGZ _                      ' __in LPCWSTR pchHostName
 , BYVAL dwDecision AS DWORD _                          ' __in DWORD dwDecision
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSetPerSiteCookieDecision = InternetSetPerSiteCookieDecisionW
#ELSE
   MACRO InternetSetPerSiteCookieDecision = InternetSetPerSiteCookieDecisionA
#ENDIF

DECLARE FUNCTION InternetGetPerSiteCookieDecisionA IMPORT "WININET.DLL" ALIAS "InternetGetPerSiteCookieDecisionA" ( _
   BYREF pchHostName AS ASCIIZ _                        ' __in LPCSTR pchHostName
 , BYREF pResult AS DWORD _                             ' __out unsigned long* pResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetPerSiteCookieDecisionW IMPORT "WININET.DLL" ALIAS "InternetGetPerSiteCookieDecisionW" ( _
   BYREF pchHostName AS WSTRINGZ _                      ' __in LPCWSTR pchHostName
 , BYREF pResult AS DWORD _                             ' __out unsigned long* pResult
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetPerSiteCookieDecision = InternetGetPerSiteCookieDecisionW
#ELSE
   MACRO InternetGetPerSiteCookieDecision = InternetGetPerSiteCookieDecisionA
#ENDIF

' Not in Vista/Windows 7 SDKs
'DECLARE FUNCTION InternetClearAllSiteCookieDecisions IMPORT "WININET.DLL" ALIAS "InternetClearAllSiteCookieDecisions" ( _
'   ) AS LONG                                            ' BOOL

DECLARE FUNCTION InternetClearAllPerSiteCookieDecisions IMPORT "WININET.DLL" ALIAS "InternetClearAllPerSiteCookieDecisions" ( _
   ) AS LONG                                            ' BOOL

DECLARE FUNCTION InternetEnumPerSiteCookieDecisionA IMPORT "WININET.DLL" ALIAS "InternetEnumPerSiteCookieDecisionA" ( _
   BYREF pszSiteName AS ASCIIZ _                        ' __out LPSTR pszSiteName
 , BYREF pcSiteNameSize AS DWORD _                      ' __inout unsigned long *pcSiteNameSize
 , BYREF pdwDecision AS DWORD _                         ' __out unsigned long *pdwDecision
 , BYVAL dwIndex AS DWORD _                             ' __in unsigned long dwIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetEnumPerSiteCookieDecisionW IMPORT "WININET.DLL" ALIAS "InternetEnumPerSiteCookieDecisionW" ( _
   BYREF pszSiteName AS WSTRINGZ _                      ' __out LPWSTR pszSiteName
 , BYREF pcSiteNameSize AS DWORD _                      ' __inout unsigned long *pcSiteNameSize
 , BYREF pdwDecision AS DWORD  _                        ' __out unsigned long *pdwDecision
 , BYVAL dwIndex AS DWORD _                             ' __in unsigned long dwIndex
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetEnumPerSiteCookieDecision = InternetEnumPerSiteCookieDecisionW
#ELSE
   MACRO InternetEnumPerSiteCookieDecision = InternetEnumPerSiteCookieDecisionA
#ENDIF

%INTERNET_IDENTITY_FLAG_PRIVATE_CACHE    = &H01
%INTERNET_IDENTITY_FLAG_SHARED_CACHE     = &H02
%INTERNET_IDENTITY_FLAG_CLEAR_DATA       = &H04
%INTERNET_IDENTITY_FLAG_CLEAR_COOKIES    = &H08
%INTERNET_IDENTITY_FLAG_CLEAR_HISTORY    = &H10
%INTERNET_IDENTITY_FLAG_CLEAR_CONTENT    = &H20

%INTERNET_SUPPRESS_RESET_ALL             = &H00
%INTERNET_SUPPRESS_COOKIE_POLICY         = &H01
%INTERNET_SUPPRESS_COOKIE_POLICY_RESET   = &H02

'//
'// Privacy settings values and APIs
'//

%PRIVACY_TEMPLATE_NO_COOKIES   = 0
%PRIVACY_TEMPLATE_HIGH         = 1
%PRIVACY_TEMPLATE_MEDIUM_HIGH  = 2
%PRIVACY_TEMPLATE_MEDIUM       = 3
%PRIVACY_TEMPLATE_MEDIUM_LOW   = 4
%PRIVACY_TEMPLATE_LOW          = 5
%PRIVACY_TEMPLATE_CUSTOM       = 100
%PRIVACY_TEMPLATE_ADVANCED     = 101

%PRIVACY_TEMPLATE_MAX          = %PRIVACY_TEMPLATE_LOW

%PRIVACY_TYPE_FIRST_PARTY      = 0
%PRIVACY_TYPE_THIRD_PARTY      = 1

DECLARE FUNCTION PrivacySetZonePreferenceW IMPORT "WININET.DLL" ALIAS "PrivacySetZonePreferenceW" ( _
   BYVAL dwZone AS DWORD _                              ' __in DWORD dwZone
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYVAL dwTemplate AS DWORD _                          ' __in DWORD dwTemplate
 , OPTIONAL BYREF pszPreference AS WSTRINGZ _           ' __in_opt LPCWSTR pszPreference
 ) AS DWORD                                             ' DWORD

MACRO PrivacySetZonePreference = PrivacySetZonePreferenceW

DECLARE FUNCTION PrivacyGetZonePreferenceW IMPORT "WININET.DLL" ALIAS "PrivacyGetZonePreferenceW" ( _
   BYVAL dwZone AS DWORD _                              ' __in DWORD dwZone
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pdwTemplate AS DWORD _                         ' __out_opt LPDWORD pdwTemplate
 , BYREF pszBuffer AS WSTRINGZ  _                       ' __out LPWSTR pszBuffer
 , OPTIONAL BYREF pdwBufferLength AS DWORD _            ' __inout_opt LPDWORD pdwBufferLength
 ) AS DWORD                                             ' DWORD

MACRO PrivacyGetZonePreference = PrivacyGetZonePreferenceW

'/*
' * Return packing to whatever it was before we
' * entered this file
' */
'#include <poppack.h>
