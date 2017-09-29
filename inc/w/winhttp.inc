' ########################################################################################
' Microsoft Windows
' File: winhttp.inc
' Contents: Windows HTTP Services
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINHTTP_INC = 1

#INCLUDE ONCE "windows.inc"

'/*
' * Set up Structure Packing to be 4 bytes for all winhttp structures
' */

'#if defined(_WIN64)
'#include <pshpack8.h>
'#else
'#include <pshpack4.h>
'#endif

'#define BOOLAPI WINHTTPAPI BOOL WINAPI
'//
'// types
'//

'typedef LPVOID HINTERNET;
'typedef HINTERNET * LPHINTERNET;

'typedef WORD INTERNET_PORT;
'typedef INTERNET_PORT * LPINTERNET_PORT;

'//
'// manifests
'//

%INTERNET_DEFAULT_PORT             = 0???    ' use the protocol-specific default
%INTERNET_DEFAULT_HTTP_PORT        = 80???   '    "     "  HTTP   "
%INTERNET_DEFAULT_HTTPS_PORT       = 443???  '    "     "  HTTPS  "

'// flags for WinHttpOpen():
%WINHTTP_FLAG_ASYNC                = &H10000000???  ' this session is asynchronous (where supported)

'// flags for WinHttpOpenRequest():
%WINHTTP_FLAG_SECURE               = &H00800000???  ' use SSL if applicable (HTTPS)
%WINHTTP_FLAG_ESCAPE_PERCENT       = &H00000004???  ' if escaping enabled, escape percent as well
%WINHTTP_FLAG_NULL_CODEPAGE        = &H00000008???  ' assume all symbols are ASCII, use fast convertion
%WINHTTP_FLAG_BYPASS_PROXY_CACHE   = &H00000100??? ' add "pragma: no-cache" request header
%WINHTTP_FLAG_REFRESH              = %WINHTTP_FLAG_BYPASS_PROXY_CACHE
%WINHTTP_FLAG_ESCAPE_DISABLE       = &H00000040???  ' disable escaping
%WINHTTP_FLAG_ESCAPE_DISABLE_QUERY = &H00000080???  ' if escaping enabled escape path part, but do not escape query


%SECURITY_FLAG_IGNORE_UNKNOWN_CA        = &H00000100???
%SECURITY_FLAG_IGNORE_CERT_DATE_INVALID = &H00002000??? ' expired X509 Cert.
%SECURITY_FLAG_IGNORE_CERT_CN_INVALID   = &H00001000??? ' bad common name in X509 Cert.
%SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE  = &H00000200???

'//
'// WINHTTP_ASYNC_RESULT - this structure is returned to the application via
'// the callback with WINHTTP_CALLBACK_STATUS_REQUEST_COMPLETE. It is not sufficient to
'// just return the result of the async operation. If the API failed then the
'// app cannot call GetLastError() because the thread context will be incorrect.
'// Both the value returned by the async API and any resultant error code are
'// made available. The app need not check dwError if dwResult indicates that
'// the API succeeded (in this case dwError will be ERROR_SUCCESS)
'//

' // Size = 8 bytes
TYPE WINHTTP_ASYNC_RESULT DWORD
   dwResult AS DWORD  ' DWORD_PTR // indicates which async API has encountered an error
   dwError  AS DWORD  ' DWORD     // the error code if the API failed
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
'// INTERNET_SCHEME - URL scheme type
'//

'typedef int INTERNET_SCHEME, * LPINTERNET_SCHEME;

'#define INTERNET_SCHEME_HTTP        (1)
'#define INTERNET_SCHEME_HTTPS       (2)

' NOTE: Added the prefix WINHTTP_ because these equates already exist in
' WIINET.INC, but with differen values

%WINHHTP_INTERNET_SCHEME_HTTP  = 1
%WINHTTP_INTERNET_SCHEME_HTTPS = 2

'//
'// URL_COMPONENTS - the constituent parts of an URL. Used in WinHttpCrackUrl()
'// and WinHttpCreateUrl()
'//
'// For WinHttpCrackUrl(), if a pointer field and its corresponding length field
'// are both 0 then that component is not returned. If the pointer field is NULL
'// but the length field is not zero, then both the pointer and length fields are
'// returned if both pointer and corresponding length fields are non-zero then
'// the pointer field points to a buffer where the component is copied. The
'// component may be un-escaped, depending on dwFlags
'//
'// For WinHttpCreateUrl(), the pointer fields should be NULL if the component
'// is not required. If the corresponding length field is zero then the pointer
'// field is the address of a zero-terminated string. If the length field is not
'// zero then it is the string length of the corresponding pointer field
'//

'#pragma warning( disable : 4121 )   // disable alignment warning

' NOTE: URL_COMPONENTS is already defined in WinInet.inc as the ansi version of
' this estructure, whereas WinHttp.inc defines it as the unicode version.
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

'typedef URL_COMPONENTS URL_COMPONENTSW;
'typedef LPURL_COMPONENTS LPURL_COMPONENTSW;

'#pragma warning( default : 4121 )   // restore alignment warning

'//
'// WINHTTP_PROXY_INFO - structure supplied with WINHTTP_OPTION_PROXY to get/
'// set proxy information on a WinHttpOpen() handle
'//

' // Size = 12 bytes
TYPE WINHTTP_PROXY_INFO DWORD
   dwAccessType    AS DWORD          ' DWORD  // see WINHTTP_ACCESS_* types below
   lpszProxy       AS WSTRINGZ PTR   ' LPWSTR // proxy server list
   lpszProxyBypass AS WSTRINGZ PTR   ' LPWSTR // proxy bypass list
END TYPE

' // Size = 24 bytes
TYPE WINHTTP_AUTOPROXY_OPTIONS DWORD
   dwFlags                AS DWORD          ' DWORD   dwFlags
   dwAutoDetectFlags      AS DWORD          ' DWORD   dwAutoDetectFlags
   lpszAutoConfigUrl      AS WSTRINGZ PTR   ' LPCWSTR lpszAutoConfigUrl
   lpvReserved            AS DWORD          ' LPVOID  lpvReserved
   dwReserved             AS DWORD          ' DWORD   dwReserved
   fAutoLogonIfChallenged AS LONG           ' BOOL    fAutoLogonIfChallenged
END TYPE


%WINHTTP_AUTOPROXY_AUTO_DETECT         = &H00000001???
%WINHTTP_AUTOPROXY_CONFIG_URL          = &H00000002???
%WINHTTP_AUTOPROXY_HOST_KEEPCASE       = &H00000004???
%WINHTTP_AUTOPROXY_HOST_LOWERCASE      = &H00000008???
%WINHTTP_AUTOPROXY_RUN_INPROCESS       = &H00010000???
%WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY = &H00020000???

'//
'// Flags for dwAutoDetectFlags
'//
%WINHTTP_AUTO_DETECT_TYPE_DHCP         = &H00000001???
%WINHTTP_AUTO_DETECT_TYPE_DNS_A        = &H00000002???


'//
'// WINHTTP_CERTIFICATE_INFO lpBuffer - contains the certificate returned from
'// the server
'//

'typedef struct
'{
'    //
'    // ftExpiry - date the certificate expires.
'    //

'    FILETIME ftExpiry;

'    //
'    // ftStart - date the certificate becomes valid.
'    //

'    FILETIME ftStart;

'    //
'    // lpszSubjectInfo - the name of organization, site, and server
'    //   the cert. was issued for.
'    //

'    LPWSTR lpszSubjectInfo;

'    //
'    // lpszIssuerInfo - the name of orgainzation, site, and server
'    //   the cert was issues by.
'    //

'    LPWSTR lpszIssuerInfo;

'    //
'    // lpszProtocolName - the name of the protocol used to provide the secure
'    //   connection.
'    //

'    LPWSTR lpszProtocolName;

'    //
'    // lpszSignatureAlgName - the name of the algorithm used for signing
'    //  the certificate.
'    //

'    LPWSTR lpszSignatureAlgName;

'    //
'    // lpszEncryptionAlgName - the name of the algorithm used for
'    //  doing encryption over the secure channel (SSL) connection.
'    //

'    LPWSTR lpszEncryptionAlgName;

'    //
'    // dwKeySize - size of the key.
'    //

'    DWORD dwKeySize;

'}
'WINHTTP_CERTIFICATE_INFO;

' // Size = 40 bytes
TYPE WINHTTP_CERTIFICATE_INFO DWORD
   ftExpiry              AS FILETIME       ' FILETIME
   ftStart               AS FILETIME       ' FILETIME
   lpszSubjectInfo       AS WSTRINGZ PTR   ' LPWSTR
   lpszIssuerInfo        AS WSTRINGZ PTR   ' LPWSTR
   lpszProtocolName      AS WSTRINGZ PTR   ' LPWSTR
   lpszSignatureAlgName  AS WSTRINGZ PTR   ' LPWSTR
   lpszEncryptionAlgName AS WSTRINGZ PTR   ' LPWSTR
   dwKeySize             AS DWORD          ' DWORD
END TYPE

#IF %DEF(%WS2DEF_INC)
' // Size = 260 bytes
TYPE WINHTTP_CONNECTION_INFO DWORD
   cbSize        AS DWORD              ' DWORD
   LocalAddress  AS SOCKADDR_STORAGE   ' // local ip, local port
   RemoteAddress AS SOCKADDR_STORAGE   ' // remote ip, remote port
END TYPE
#ENDIF


'//
'// prototypes
'//

'//
'// constants for WinHttpTimeFromSystemTime
'//

%WINHTTP_TIME_FORMAT_BUFSIZE  = 62

DECLARE FUNCTION WinHttpTimeFromSystemTime IMPORT "WinHTTP.DLL" ALIAS "WinHttpTimeFromSystemTime" ( _
   BYREF pst AS SYSTEMTIME _                            ' __in CONST SYSTEMTIME *pst
 , BYREF pwszTime AS WSTRINGZ _                         ' __out LPWSTR pwszTime
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpTimeToSystemTime IMPORT "WinHTTP.DLL" ALIAS "WinHttpTimeToSystemTime" ( _
   BYREF pwszTime AS WSTRINGZ _                         ' __in LPCWSTR pwszTime
 , BYREF pst AS SYSTEMTIME _                            ' __out SYSTEMTIME *pst
 ) AS LONG                                              ' BOOL

'//
'// flags for CrackUrl() and CombineUrl()
'//

%ICU_NO_ENCODE          = &H20000000??? ' Don't convert unsafe characters to escape sequence
%ICU_DECODE             = &H10000000??? ' Convert %XX escape sequences to characters
%ICU_NO_META            = &H08000000??? ' Don't convert .. etc. meta path sequences
%ICU_ENCODE_SPACES_ONLY = &H04000000??? ' Encode spaces only
%ICU_BROWSER_MODE       = &H02000000??? ' Special encode/decode rules for browser
%ICU_ENCODE_PERCENT     = &H00001000??? ' Encode any percent (ASCII25) signs encountered, default is to not encode percent.

' NOTE: We must use the Unicode version of LPURL_COMPONENTS, not the ansi one.
DECLARE FUNCTION WinHttpCrackUrl IMPORT "WinHTTP.DLL" ALIAS "WinHttpCrackUrl" ( _
   BYREF pwszUrl AS WSTRINGZ _                          ' __in LPCWSTR pwszUrl
 , BYVAL dwUrlLength AS DWORD _                         ' __in DWORD dwUrlLength
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpUrlComponents AS URL_COMPONENTSW _           ' __inout LPURL_COMPONENTSW lpUrlComponents
 ) AS LONG                                              ' BOOL

' NOTE: We must use the Unicode version of LPURL_COMPONENTS, not the ansi one.
DECLARE FUNCTION WinHttpCreateUrl IMPORT "WinHTTP.DLL" ALIAS "WinHttpCreateUrl" ( _
   BYREF lpUrlComponents AS URL_COMPONENTSW _           ' __in LPURL_COMPONENTSW lpUrlComponents
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszUrl AS WSTRINGZ _                          ' __out LPWSTR pwszUrl
 , BYREF pdwUrlLength AS DWORD _                        ' __inout LPDWORD pdwUrlLength
 ) AS LONG                                              ' BOOL

'//
'// flags for WinHttpCrackUrl() and WinHttpCreateUrl()
'//

%ICU_ESCAPE           = &H80000000???  ' // (un)escape URL characters
%ICU_ESCAPE_AUTHORITY = &H00002000???  ' //causes InternetCreateUrlA to escape chars in authority components (user, pwd, host)
%ICU_REJECT_USERPWD   = &H00004000???  ' // rejects usrls whick have username/pwd sections


DECLARE FUNCTION WinHttpCheckPlatform IMPORT "WinHTTP.DLL" ALIAS "WinHttpCheckPlatform" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpGetDefaultProxyConfiguration IMPORT "WinHTTP.DLL" ALIAS "WinHttpGetDefaultProxyConfiguration" ( _
   BYREF pProxyInfo AS WINHTTP_PROXY_INFO _             ' __inout WINHTTP_PROXY_INFO * pProxyInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpSetDefaultProxyConfiguration IMPORT "WinHTTP.DLL" ALIAS "WinHttpSetDefaultProxyConfiguration" ( _
   BYREF pProxyInfo AS WINHTTP_PROXY_INFO _             ' __in WINHTTP_PROXY_INFO * pProxyInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpOpen IMPORT "WinHTTP.DLL" ALIAS "WinHttpOpen" ( _
   BYREF pwszUserAgent AS WSTRINGZ _                    ' __in LPCWSTR pwszUserAgent
 , BYVAL dwAccessType AS DWORD _                        ' __in DWORD dwAccessType
 , BYREF pwszProxyName AS WSTRINGZ _                    ' __in_opt LPCWSTR pwszProxyName
 , BYREF pwszProxyBypass AS WSTRINGZ  _                 ' __in_opt LPCWSTR pwszProxyBypass
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HINTERNET

'// WinHttpOpen dwAccessType values (also for WINHTTP_PROXY_INFO::dwAccessType)
%WINHTTP_ACCESS_TYPE_DEFAULT_PROXY = 0
%WINHTTP_ACCESS_TYPE_NO_PROXY      = 1
%WINHTTP_ACCESS_TYPE_NAMED_PROXY   = 3

'// WinHttpOpen prettifiers for optional parameters
%WINHTTP_NO_PROXY_NAME   = %NULL
%WINHTTP_NO_PROXY_BYPASS = %NULL

DECLARE FUNCTION WinHttpCloseHandle IMPORT "WinHTTP.DLL" ALIAS "WinHttpCloseHandle" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpConnect IMPORT "WinHTTP.DLL" ALIAS "WinHttpConnect" ( _
   BYVAL hSession AS DWORD _                            ' __in HINTERNET hSession
 , BYREF pswzServerName AS WSTRINGZ _                   ' __in LPCWSTR pswzServerName
 , BYVAL nServerPort AS WORD _                          ' __in INTERNET_PORT nServerPort
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS DWORD                                             ' HINTERNET

DECLARE FUNCTION WinHttpReadData IMPORT "WinHTTP.DLL" ALIAS "WinHttpReadData" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL lpBuffer AS DWORD _                            ' __in LPVOID lpBuffer
 , BYVAL dwNumberOfBytesToRead AS DWORD _               ' __in DWORD dwNumberOfBytesToRead
 , BYREF lpdwNumberOfBytesRead AS DWORD _               ' __out LPDWORD lpdwNumberOfBytesRead
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpWriteData IMPORT "WinHTTP.DLL" ALIAS "WinHttpWriteData" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL lpBuffer AS DWORD _                            ' __in LPCVOID lpBuffer
 , BYVAL dwNumberOfBytesToWrite AS DWORD _              ' __in DWORD dwNumberOfBytesToWrite
 , BYREF lpdwNumberOfBytesWritten AS DWORD _            ' __out LPDWORD lpdwNumberOfBytesWritten
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpQueryDataAvailable IMPORT "WinHTTP.DLL" ALIAS "WinHttpQueryDataAvailable" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF lpdwNumberOfBytesAvailable AS DWORD _          ' __out_opt LPDWORD lpdwNumberOfBytesAvailable
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpQueryOption IMPORT "WinHTTP.DLL" ALIAS "WinHttpQueryOption" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD _                            ' __out_opt LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' BOOL

%WINHTTP_NO_CLIENT_CERT_CONTEXT = %NULL

DECLARE FUNCTION WinHttpSetOption IMPORT "WinHTTP.DLL" ALIAS "WinHttpSetOption" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYVAL dwOption AS DWORD _                            ' __in DWORD dwOption
 , BYVAL lpBuffer AS DWORD _                            ' __in LPVOID lpBuffer
 , BYVAL dwBufferLength AS DWORD _                      ' __in DWORD dwBufferLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpSetTimeouts IMPORT "WinHTTP.DLL" ALIAS "WinHttpSetTimeouts" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYVAL nResolveTimeout AS LONG _                      ' __in int nResolveTimeout
 , BYVAL nConnectTimeout AS LONG _                      ' __in int nConnectTimeout
 , BYVAL nSendTimeout AS LONG _                         ' __in int nSendTimeout
 , BYVAL nReceiveTimeout AS LONG _                      ' __in int nReceiveTimeout
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpIsHostInProxyBypassList IMPORT "WinHTTP.DLL" ALIAS "WinHttpIsHostInProxyBypassList" ( _
   BYREF pProxyInfo AS WINHTTP_PROXY_INFO _             ' __in const WINHTTP_PROXY_INFO *pProxyInfo
 , BYREF pwszHost AS WSTRINGZ _                         ' __in PCWSTR pwszHost
 , BYVAL tScheme AS LONG _                              ' __in INTERNET_SCHEME tScheme
 , BYVAL nPort AS WORD _                                ' __in INTERNET_PORT nPort
 , BYREF pfIsInBypassList AS LONG _                     ' __out BOOL *pfIsInBypassList
 ) AS DWORD                                             ' DWORD

'//
'// options manifests for WinHttp{Query|Set}Option
'//

%WINHTTP_OPTION_CALLBACK                       = 1
%WINHTTP_FIRST_OPTION                          = %WINHTTP_OPTION_CALLBACK

%WINHTTP_OPTION_RESOLVE_TIMEOUT                = 2
%WINHTTP_OPTION_CONNECT_TIMEOUT                = 3
%WINHTTP_OPTION_CONNECT_RETRIES                = 4
%WINHTTP_OPTION_SEND_TIMEOUT                   = 5
%WINHTTP_OPTION_RECEIVE_TIMEOUT                = 6
%WINHTTP_OPTION_RECEIVE_RESPONSE_TIMEOUT       = 7
%WINHTTP_OPTION_HANDLE_TYPE                    = 9
%WINHTTP_OPTION_READ_BUFFER_SIZE               = 12
%WINHTTP_OPTION_WRITE_BUFFER_SIZE              = 13
%WINHTTP_OPTION_PARENT_HANDLE                  = 21
%WINHTTP_OPTION_EXTENDED_ERROR                 = 24
%WINHTTP_OPTION_SECURITY_FLAGS                 = 31
%WINHTTP_OPTION_SECURITY_CERTIFICATE_STRUCT    = 32
%WINHTTP_OPTION_URL                            = 34
%WINHTTP_OPTION_SECURITY_KEY_BITNESS           = 36
%WINHTTP_OPTION_PROXY                          = 38

%WINHTTP_OPTION_USER_AGENT                     = 41
%WINHTTP_OPTION_CONTEXT_VALUE                  = 45
%WINHTTP_OPTION_CLIENT_CERT_CONTEXT            = 47
%WINHTTP_OPTION_REQUEST_PRIORITY               = 58
%WINHTTP_OPTION_HTTP_VERSION                   = 59
%WINHTTP_OPTION_DISABLE_FEATURE                = 63

%WINHTTP_OPTION_CODEPAGE                       = 68
%WINHTTP_OPTION_MAX_CONNS_PER_SERVER           = 73
%WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER       = 74
%WINHTTP_OPTION_AUTOLOGON_POLICY               = 77
%WINHTTP_OPTION_SERVER_CERT_CONTEXT            = 78
%WINHTTP_OPTION_ENABLE_FEATURE                 = 79
%WINHTTP_OPTION_WORKER_THREAD_COUNT            = 80
%WINHTTP_OPTION_PASSPORT_COBRANDING_TEXT       = 81
%WINHTTP_OPTION_PASSPORT_COBRANDING_URL        = 82
%WINHTTP_OPTION_CONFIGURE_PASSPORT_AUTH        = 83
%WINHTTP_OPTION_SECURE_PROTOCOLS               = 84
%WINHTTP_OPTION_ENABLETRACING                  = 85
%WINHTTP_OPTION_PASSPORT_SIGN_OUT              = 86
%WINHTTP_OPTION_PASSPORT_RETURN_URL            = 87
%WINHTTP_OPTION_REDIRECT_POLICY                = 88
%WINHTTP_OPTION_MAX_HTTP_AUTOMATIC_REDIRECTS   = 89
%WINHTTP_OPTION_MAX_HTTP_STATUS_CONTINUE       = 90
%WINHTTP_OPTION_MAX_RESPONSE_HEADER_SIZE       = 91
%WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE        = 92
%WINHTTP_OPTION_CONNECTION_INFO                = 93
%WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST        = 94
%WINHTTP_OPTION_SPN                            = 96

%WINHTTP_OPTION_GLOBAL_PROXY_CREDS             = 97
%WINHTTP_OPTION_GLOBAL_SERVER_CREDS            = 98

%WINHTTP_OPTION_UNLOAD_NOTIFY_EVENT            = 99
%WINHTTP_OPTION_REJECT_USERPWD_IN_URL          = 100
%WINHTTP_OPTION_USE_GLOBAL_SERVER_CREDENTIALS  = 101

%WINHTTP_OPTION_RECEIVE_PROXY_CONNECT_RESPONSE = 103
%WINHTTP_OPTION_IS_PROXY_CONNECT_RESPONSE      = 104

%WINHTTP_OPTION_SERVER_SPN_USED                = 106
%WINHTTP_OPTION_PROXY_SPN_USED                 = 107

%WINHTTP_OPTION_SERVER_CBT                     = 108

%WINHTTP_LAST_OPTION                           = %WINHTTP_OPTION_SERVER_CBT

%WINHTTP_OPTION_USERNAME                       = &H1000???
%WINHTTP_OPTION_PASSWORD                       = &H1001???
%WINHTTP_OPTION_PROXY_USERNAME                 = &H1002???
%WINHTTP_OPTION_PROXY_PASSWORD                 = &H1003???

'// manifest value for WINHTTP_OPTION_MAX_CONNS_PER_SERVER and WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER
%WINHTTP_CONNS_PER_SERVER_UNLIMITED            = &HFFFFFFFF???


'// values for WINHTTP_OPTION_AUTOLOGON_POLICY
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM  = 0
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_LOW     = 1
%WINHTTP_AUTOLOGON_SECURITY_LEVEL_HIGH    = 2

%WINHTTP_AUTOLOGON_SECURITY_LEVEL_DEFAULT = %WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM

'// values for WINHTTP_OPTION_REDIRECT_POLICY
%WINHTTP_OPTION_REDIRECT_POLICY_NEVER                  = 0
%WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP = 1
%WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS                 = 2

%WINHTTP_OPTION_REDIRECT_POLICY_LAST    = %WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS
%WINHTTP_OPTION_REDIRECT_POLICY_DEFAULT = %WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP

%WINHTTP_DISABLE_PASSPORT_AUTH    = &H00000000???
%WINHTTP_ENABLE_PASSPORT_AUTH     = &H10000000???
%WINHTTP_DISABLE_PASSPORT_KEYRING = &H20000000???
%WINHTTP_ENABLE_PASSPORT_KEYRING  = &H40000000???

'// values for WINHTTP_OPTION_DISABLE_FEATURE
%WINHTTP_DISABLE_COOKIES          = &H00000001???
%WINHTTP_DISABLE_REDIRECTS        = &H00000002???
%WINHTTP_DISABLE_AUTHENTICATION   = &H00000004???
%WINHTTP_DISABLE_KEEP_ALIVE       = &H00000008???

'// values for WINHTTP_OPTION_ENABLE_FEATURE
%WINHTTP_ENABLE_SSL_REVOCATION           = &H00000001???
%WINHTTP_ENABLE_SSL_REVERT_IMPERSONATION = &H00000002???

'// values for WINHTTP_OPTION_SPN
%WINHTTP_DISABLE_SPN_SERVER_PORT           = &H00000000
%WINHTTP_ENABLE_SPN_SERVER_PORT            = &H00000001
%WINHTTP_OPTION_SPN_MASK                   = %WINHTTP_ENABLE_SPN_SERVER_PORT

' // Size = 24 bytes
TYPE WINHTTP_CREDS DWORD
   lpszUserName AS ASCIIZ PTR   ' LPSTR
   lpszPassword AS ASCIIZ PTR   ' LPSTR
   lpszRealm    AS ASCIIZ PTR   ' LPSTR
   dwAuthScheme AS DWORD        ' DWORD
   lpszHostName AS ASCIIZ PTR   ' LPSTR
   dwPort       AS DWORD        ' DWORD
END TYPE

'// structure for WINHTTP_OPTION_GLOBAL_SERVER_CREDS and
'// WINHTTP_OPTION_GLOBAL_PROXY_CREDS
' // Size = 28 bytes
TYPE WINHTTP_CREDS_EX DWORD
   lpszUserName AS ASCIIZ PTR   ' LPSTR
   lpszPassword AS ASCIIZ PTR   ' LPSTR
   lpszRealm    AS ASCIIZ PTR   ' LPSTR
   dwAuthScheme AS DWORD        ' DWORD
   lpszHostName AS ASCIIZ PTR   ' LPSTR
   dwPort       AS DWORD        ' DWORD
   lpszUrl      AS ASCIIZ PTR   ' LPSTR
END TYPE

'//
'// winhttp handle types
'//
%WINHTTP_HANDLE_TYPE_SESSION    = 1
%WINHTTP_HANDLE_TYPE_CONNECT    = 2
%WINHTTP_HANDLE_TYPE_REQUEST    = 3

'//
'// values for auth schemes
'//
%WINHTTP_AUTH_SCHEME_BASIC      = &H00000001???
%WINHTTP_AUTH_SCHEME_NTLM       = &H00000002???
%WINHTTP_AUTH_SCHEME_PASSPORT   = &H00000004???
%WINHTTP_AUTH_SCHEME_DIGEST     = &H00000008???
%WINHTTP_AUTH_SCHEME_NEGOTIATE  = &H00000010???

'// WinHttp supported Authentication Targets

%WINHTTP_AUTH_TARGET_SERVER     = &H00000000???
%WINHTTP_AUTH_TARGET_PROXY      = &H00000001???

'//
'// values for WINHTTP_OPTION_SECURITY_FLAGS
'//

'// query only
%SECURITY_FLAG_SECURE                    = &H00000001??? ' can query only
%SECURITY_FLAG_STRENGTH_WEAK             = &H10000000???
%SECURITY_FLAG_STRENGTH_MEDIUM           = &H40000000???
%SECURITY_FLAG_STRENGTH_STRONG           = &H20000000???


'// Secure connection error status flags
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_REV_FAILED         = &H00000001???
%WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CERT            = &H00000002???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_REVOKED            = &H00000004???
%WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CA              = &H00000008???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_CN_INVALID         = &H00000010???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_DATE_INVALID       = &H00000020???
%WINHTTP_CALLBACK_STATUS_FLAG_CERT_WRONG_USAGE        = &H00000040???
%WINHTTP_CALLBACK_STATUS_FLAG_SECURITY_CHANNEL_ERROR  = &H80000000???

%WINHTTP_FLAG_SECURE_PROTOCOL_SSL2   = &H00000008???
%WINHTTP_FLAG_SECURE_PROTOCOL_SSL3   = &H00000020???
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1   = &H00000080???
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_1 = &H00000200???
%WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_2 = &H00000800???
%WINHTTP_FLAG_SECURE_PROTOCOL_ALL    = (%WINHTTP_FLAG_SECURE_PROTOCOL_SSL2 _
                                    OR %WINHTTP_FLAG_SECURE_PROTOCOL_SSL3 _
                                    OR %WINHTTP_FLAG_SECURE_PROTOCOL_TLS1)

'//
'// callback function for WinHttpSetStatusCallback
'//

'typedef
'VOID
'(CALLBACK * WINHTTP_STATUS_CALLBACK)(
'    IN HINTERNET hInternet,
'    IN DWORD_PTR dwContext,
'    IN DWORD dwInternetStatus,
'    IN LPVOID lpvStatusInformation OPTIONAL,
'    IN DWORD dwStatusInformationLength
'    );

'typedef WINHTTP_STATUS_CALLBACK * LPWINHTTP_STATUS_CALLBACK;

'SUB WINHTTP_STATUS_CALLBACK ( _
'   BYVAL hInternet AS DWORD, _                          ' __in HINTERNET hInternet
'   BYVAL dwContext AS DWORD, _                          ' __in DWORD_PTR dwContext
'   BYVAL dwInternetStatus AS DWORD, _                   ' __in DWORD dwInternetStatus
'   BYVAL lpvStatusInformation AS DWORD, _               ' __in_opt LPVOID lpvStatusInformation
'   BYVAL dwStatusInformationLength AS DWORD _           ' __in DWORD dwStatusInformationLength
'   )                                                    ' VOID


DECLARE FUNCTION WinHttpSetStatusCallback IMPORT "WinHTTP.DLL" ALIAS "WinHttpSetStatusCallback" ( _
   BYVAL hInternet AS DWORD _                           ' __in HINTERNET hInternet
 , BYVAL lpfnInternetCallback AS DWORD _                ' __in WINHTTP_STATUS_CALLBACK lpfnInternetCallback
 , BYVAL dwNotificationFlags AS DWORD _                 ' __in DWORD dwNotificationFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved
 ) AS DWORD                                             ' WINHTTPAPI

'//
'// status manifests for WinHttp status callback
'//

%WINHTTP_CALLBACK_STATUS_RESOLVING_NAME        = &H00000001???
%WINHTTP_CALLBACK_STATUS_NAME_RESOLVED         = &H00000002???
%WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER  = &H00000004???
%WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER   = &H00000008???
%WINHTTP_CALLBACK_STATUS_SENDING_REQUEST       = &H00000010???
%WINHTTP_CALLBACK_STATUS_REQUEST_SENT          = &H00000020???
%WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE    = &H00000040???
%WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED     = &H00000080???
%WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION    = &H00000100???
%WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED     = &H00000200???
%WINHTTP_CALLBACK_STATUS_HANDLE_CREATED        = &H00000400???
%WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING        = &H00000800???
%WINHTTP_CALLBACK_STATUS_DETECTING_PROXY       = &H00001000???
%WINHTTP_CALLBACK_STATUS_REDIRECT              = &H00004000???
%WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE = &H00008000???
%WINHTTP_CALLBACK_STATUS_SECURE_FAILURE        = &H00010000???
%WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE     = &H00020000???
%WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE        = &H00040000???
%WINHTTP_CALLBACK_STATUS_READ_COMPLETE         = &H00080000???
%WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE        = &H00100000???
%WINHTTP_CALLBACK_STATUS_REQUEST_ERROR         = &H00200000???
%WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE  = &H00400000???

'// API Enums for WINHTTP_CALLBACK_STATUS_REQUEST_ERROR:
%API_RECEIVE_RESPONSE     = 1
%API_QUERY_DATA_AVAILABLE = 2
%API_READ_DATA            = 3
%API_WRITE_DATA           = 4
%API_SEND_REQUEST         = 5

%WINHTTP_CALLBACK_FLAG_RESOLVE_NAME          = %WINHTTP_CALLBACK_STATUS_RESOLVING_NAME OR %WINHTTP_CALLBACK_STATUS_NAME_RESOLVED
%WINHTTP_CALLBACK_FLAG_CONNECT_TO_SERVER     = %WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER OR %WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER
%WINHTTP_CALLBACK_FLAG_SEND_REQUEST          = %WINHTTP_CALLBACK_STATUS_SENDING_REQUEST OR %WINHTTP_CALLBACK_STATUS_REQUEST_SENT
%WINHTTP_CALLBACK_FLAG_RECEIVE_RESPONSE      = %WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE OR %WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED
%WINHTTP_CALLBACK_FLAG_CLOSE_CONNECTION      = %WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION OR %WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED
%WINHTTP_CALLBACK_FLAG_HANDLES               = %WINHTTP_CALLBACK_STATUS_HANDLE_CREATED OR %WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING
%WINHTTP_CALLBACK_FLAG_DETECTING_PROXY       = %WINHTTP_CALLBACK_STATUS_DETECTING_PROXY
%WINHTTP_CALLBACK_FLAG_REDIRECT              = %WINHTTP_CALLBACK_STATUS_REDIRECT
%WINHTTP_CALLBACK_FLAG_INTERMEDIATE_RESPONSE = %WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE
%WINHTTP_CALLBACK_FLAG_SECURE_FAILURE        = %WINHTTP_CALLBACK_STATUS_SECURE_FAILURE
%WINHTTP_CALLBACK_FLAG_SENDREQUEST_COMPLETE  = %WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE
%WINHTTP_CALLBACK_FLAG_HEADERS_AVAILABLE     = %WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE
%WINHTTP_CALLBACK_FLAG_DATA_AVAILABLE        = %WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE
%WINHTTP_CALLBACK_FLAG_READ_COMPLETE         = %WINHTTP_CALLBACK_STATUS_READ_COMPLETE
%WINHTTP_CALLBACK_FLAG_WRITE_COMPLETE        = %WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE
%WINHTTP_CALLBACK_FLAG_REQUEST_ERROR         = %WINHTTP_CALLBACK_STATUS_REQUEST_ERROR

%WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS       = %WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE _
                                            OR %WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE _
                                            OR %WINHTTP_CALLBACK_STATUS_READ_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE _
                                            OR %WINHTTP_CALLBACK_STATUS_REQUEST_ERROR
%WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS     = &HFFFFFFFF???

'//
'// if the following value is returned by WinHttpSetStatusCallback, then
'// probably an invalid (non-code) address was supplied for the callback
'//

%WINHTTP_INVALID_STATUS_CALLBACK = &HFFFFFFFF???

'//
'// WinHttpQueryHeaders info levels. Generally, there is one info level
'// for each potential RFC822/HTTP/MIME header that an HTTP server
'// may send as part of a request response.
'//
'// The WINHTTP_QUERY_RAW_HEADERS info level is provided for clients
'// that choose to perform their own header parsing.
'//

%WINHTTP_QUERY_MIME_VERSION               = 0
%WINHTTP_QUERY_CONTENT_TYPE               = 1
%WINHTTP_QUERY_CONTENT_TRANSFER_ENCODING  = 2
%WINHTTP_QUERY_CONTENT_ID                 = 3
%WINHTTP_QUERY_CONTENT_DESCRIPTION        = 4
%WINHTTP_QUERY_CONTENT_LENGTH             = 5
%WINHTTP_QUERY_CONTENT_LANGUAGE           = 6
%WINHTTP_QUERY_ALLOW                      = 7
%WINHTTP_QUERY_PUBLIC                     = 8
%WINHTTP_QUERY_DATE                       = 9
%WINHTTP_QUERY_EXPIRES                    = 10
%WINHTTP_QUERY_LAST_MODIFIED              = 11
%WINHTTP_QUERY_MESSAGE_ID                 = 12
%WINHTTP_QUERY_URI                        = 13
%WINHTTP_QUERY_DERIVED_FROM               = 14
%WINHTTP_QUERY_COST                       = 15
%WINHTTP_QUERY_LINK                       = 16
%WINHTTP_QUERY_PRAGMA                     = 17
%WINHTTP_QUERY_VERSION                    = 18  ' special: part of status line
%WINHTTP_QUERY_STATUS_CODE                = 19  ' special: part of status line
%WINHTTP_QUERY_STATUS_TEXT                = 20  ' special: part of status line
%WINHTTP_QUERY_RAW_HEADERS                = 21  ' special: all headers as ASCIIZ
%WINHTTP_QUERY_RAW_HEADERS_CRLF           = 22  ' special: all headers
%WINHTTP_QUERY_CONNECTION                 = 23
%WINHTTP_QUERY_ACCEPT                     = 24
%WINHTTP_QUERY_ACCEPT_CHARSET             = 25
%WINHTTP_QUERY_ACCEPT_ENCODING            = 26
%WINHTTP_QUERY_ACCEPT_LANGUAGE            = 27
%WINHTTP_QUERY_AUTHORIZATION              = 28
%WINHTTP_QUERY_CONTENT_ENCODING           = 29
%WINHTTP_QUERY_FORWARDED                  = 30
%WINHTTP_QUERY_FROM                       = 31
%WINHTTP_QUERY_IF_MODIFIED_SINCE          = 32
%WINHTTP_QUERY_LOCATION                   = 33
%WINHTTP_QUERY_ORIG_URI                   = 34
%WINHTTP_QUERY_REFERER                    = 35
%WINHTTP_QUERY_RETRY_AFTER                = 36
%WINHTTP_QUERY_SERVER                     = 37
%WINHTTP_QUERY_TITLE                      = 38
%WINHTTP_QUERY_USER_AGENT                 = 39
%WINHTTP_QUERY_WWW_AUTHENTICATE           = 40
%WINHTTP_QUERY_PROXY_AUTHENTICATE         = 41
%WINHTTP_QUERY_ACCEPT_RANGES              = 42
%WINHTTP_QUERY_SET_COOKIE                 = 43
%WINHTTP_QUERY_COOKIE                     = 44
%WINHTTP_QUERY_REQUEST_METHOD             = 45  ' special: GET/POST etc.
%WINHTTP_QUERY_REFRESH                    = 46
%WINHTTP_QUERY_CONTENT_DISPOSITION        = 47

'//
'// HTTP 1.1 defined headers
'//

%WINHTTP_QUERY_AGE                        = 48
%WINHTTP_QUERY_CACHE_CONTROL              = 49
%WINHTTP_QUERY_CONTENT_BASE               = 50
%WINHTTP_QUERY_CONTENT_LOCATION           = 51
%WINHTTP_QUERY_CONTENT_MD5                = 52
%WINHTTP_QUERY_CONTENT_RANGE              = 53
%WINHTTP_QUERY_ETAG                       = 54
%WINHTTP_QUERY_HOST                       = 55
%WINHTTP_QUERY_IF_MATCH                   = 56
%WINHTTP_QUERY_IF_NONE_MATCH              = 57
%WINHTTP_QUERY_IF_RANGE                   = 58
%WINHTTP_QUERY_IF_UNMODIFIED_SINCE        = 59
%WINHTTP_QUERY_MAX_FORWARDS               = 60
%WINHTTP_QUERY_PROXY_AUTHORIZATION        = 61
%WINHTTP_QUERY_RANGE                      = 62
%WINHTTP_QUERY_TRANSFER_ENCODING          = 63
%WINHTTP_QUERY_UPGRADE                    = 64
%WINHTTP_QUERY_VARY                       = 65
%WINHTTP_QUERY_VIA                        = 66
%WINHTTP_QUERY_WARNING                    = 67
%WINHTTP_QUERY_EXPECT                     = 68
%WINHTTP_QUERY_PROXY_CONNECTION           = 69
%WINHTTP_QUERY_UNLESS_MODIFIED_SINCE      = 70

%WINHTTP_QUERY_PROXY_SUPPORT              = 75
%WINHTTP_QUERY_AUTHENTICATION_INFO        = 76
%WINHTTP_QUERY_PASSPORT_URLS              = 77
%WINHTTP_QUERY_PASSPORT_CONFIG            = 78

%WINHTTP_QUERY_MAX                        = 78

'//
'// WINHTTP_QUERY_CUSTOM - if this special value is supplied as the dwInfoLevel
'// parameter of WinHttpQueryHeaders() then the lpBuffer parameter contains the name
'// of the header we are to query
'//

%WINHTTP_QUERY_CUSTOM                     = 65535

'//
'// WINHTTP_QUERY_FLAG_REQUEST_HEADERS - if this bit is set in the dwInfoLevel
'// parameter of WinHttpQueryHeaders() then the request headers will be queried for the
'// request information
'//

%WINHTTP_QUERY_FLAG_REQUEST_HEADERS       = &H80000000???

'//
'// WINHTTP_QUERY_FLAG_SYSTEMTIME - if this bit is set in the dwInfoLevel parameter
'// of WinHttpQueryHeaders() AND the header being queried contains date information,
'// e.g. the "Expires:" header then lpBuffer will contain a SYSTEMTIME structure
'// containing the date and time information converted from the header string
'//

%WINHTTP_QUERY_FLAG_SYSTEMTIME            = &H40000000???

'//
'// WINHTTP_QUERY_FLAG_NUMBER - if this bit is set in the dwInfoLevel parameter of
'// HttpQueryHeader(), then the value of the header will be converted to a number
'// before being returned to the caller, if applicable
'//

%WINHTTP_QUERY_FLAG_NUMBER                = &H20000000???


'//
'// HTTP Response Status Codes:
'//

%HTTP_STATUS_CONTINUE            = 100 ' OK to continue with request
%HTTP_STATUS_SWITCH_PROTOCOLS    = 101 ' server has switched protocols in upgrade header

%HTTP_STATUS_OK                  = 200 ' request completed
%HTTP_STATUS_CREATED             = 201 ' object created, reason = new URI
%HTTP_STATUS_ACCEPTED            = 202 ' async completion (TBS)
%HTTP_STATUS_PARTIAL             = 203 ' partial completion
%HTTP_STATUS_NO_CONTENT          = 204 ' no info to return
%HTTP_STATUS_RESET_CONTENT       = 205 ' request completed, but clear form
%HTTP_STATUS_PARTIAL_CONTENT     = 206 ' partial GET fulfilled
%HTTP_STATUS_WEBDAV_MULTI_STATUS = 207 ' WebDAV Multi-Status

%HTTP_STATUS_AMBIGUOUS           = 300 ' server couldn't decide what to return
%HTTP_STATUS_MOVED               = 301 ' object permanently moved
%HTTP_STATUS_REDIRECT            = 302 ' object temporarily moved
%HTTP_STATUS_REDIRECT_METHOD     = 303 ' redirection w/ new access method
%HTTP_STATUS_NOT_MODIFIED        = 304 ' if-modified-since was not modified
%HTTP_STATUS_USE_PROXY           = 305 ' redirection to proxy, location header specifies proxy to use
%HTTP_STATUS_REDIRECT_KEEP_VERB  = 307 ' HTTP/1.1: keep same verb

%HTTP_STATUS_BAD_REQUEST         = 400 ' invalid syntax
%HTTP_STATUS_DENIED              = 401 ' access denied
%HTTP_STATUS_PAYMENT_REQ         = 402 ' payment required
%HTTP_STATUS_FORBIDDEN           = 403 ' request forbidden
%HTTP_STATUS_NOT_FOUND           = 404 ' object not found
%HTTP_STATUS_BAD_METHOD          = 405 ' method is not allowed
%HTTP_STATUS_NONE_ACCEPTABLE     = 406 ' no response acceptable to client found
%HTTP_STATUS_PROXY_AUTH_REQ      = 407 ' proxy authentication required
%HTTP_STATUS_REQUEST_TIMEOUT     = 408 ' server timed out waiting for request
%HTTP_STATUS_CONFLICT            = 409 ' user should resubmit with more info
%HTTP_STATUS_GONE                = 410 ' the resource is no longer available
%HTTP_STATUS_LENGTH_REQUIRED     = 411 ' the server refused to accept request w/o a length
%HTTP_STATUS_PRECOND_FAILED      = 412 ' precondition given in request failed
%HTTP_STATUS_REQUEST_TOO_LARGE   = 413 ' request entity was too large
%HTTP_STATUS_URI_TOO_LONG        = 414 ' request URI too long
%HTTP_STATUS_UNSUPPORTED_MEDIA   = 415 ' unsupported media type
%HTTP_STATUS_RETRY_WITH          = 449 ' retry after doing the appropriate action.

%HTTP_STATUS_SERVER_ERROR        = 500 ' internal server error
%HTTP_STATUS_NOT_SUPPORTED       = 501 ' required not supported
%HTTP_STATUS_BAD_GATEWAY         = 502 ' error response received from gateway
%HTTP_STATUS_SERVICE_UNAVAIL     = 503 ' temporarily overloaded
%HTTP_STATUS_GATEWAY_TIMEOUT     = 504 ' timed out waiting for gateway
%HTTP_STATUS_VERSION_NOT_SUP     = 505 ' HTTP version not supported

%HTTP_STATUS_FIRST               = %HTTP_STATUS_CONTINUE
%HTTP_STATUS_LAST                = %HTTP_STATUS_VERSION_NOT_SUP

'//
'// prototypes
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WinHttpOpenRequest LIB "WinHTTP.DLL" _
    ALIAS "WinHttpOpenRequest" _
    ( _
    BYVAL hConnect AS DWORD, _
    pwszVerb AS WSTRINGZ, _
    pwszObjectName AS WSTRINGZ, _
    pwszVersion AS WSTRINGZ, _
    pwszReferrer AS WSTRINGZ, _
    ppwszAcceptTypes AS DWORD, _
    BYVAL dwFlags AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WinHttpOpenRequest IMPORT "WinHTTP.DLL" ALIAS "WinHttpOpenRequest" ( _
   BYVAL hConnect AS DWORD _                            ' __in HINTERNET hConnect
 , BYREF pwszVerb AS WSTRINGZ _                         ' __in LPCWSTR pwszVerb
 , BYREF pwszObjectName AS WSTRINGZ _                   ' __in LPCWSTR pwszObjectName
 , BYREF pwszVersion AS WSTRINGZ _                      ' __in LPCWSTR pwszVersion
 , BYREF pwszReferrer AS WSTRINGZ _                     ' __in_opt LPCWSTR pwszReferrer
 , BYVAL ppwszAcceptTypes AS DWORD _                    ' __in_opt LPCWSTR FAR * ppwszAcceptTypes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HINTERNET
#ENDIF

'// WinHttpOpenRequest prettifers for optional parameters
%WINHTTP_NO_REFERER           = %NULL
%WINHTTP_DEFAULT_ACCEPT_TYPES = %NULL

DECLARE FUNCTION WinHttpAddRequestHeaders IMPORT "WinHTTP.DLL" ALIAS "WinHttpAddRequestHeaders" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF pwszHeaders AS WSTRINGZ _                      ' __in LPCWSTR pwszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL dwModifiers AS DWORD _                         ' __in DWORD dwModifiers
 ) AS LONG                                              ' BOOL

'//
'// values for dwModifiers parameter of WinHttpAddRequestHeaders()
'//

%WINHTTP_ADDREQ_INDEX_MASK = &H0000FFFF???
%WINHTTP_ADDREQ_FLAGS_MASK = &HFFFF0000???

'//
'// WINHTTP_ADDREQ_FLAG_ADD_IF_NEW - the header will only be added if it doesn't
'// already exist
'//

%WINHTTP_ADDREQ_FLAG_ADD_IF_NEW = &H10000000???

'//
'// WINHTTP_ADDREQ_FLAG_ADD - if WINHTTP_ADDREQ_FLAG_REPLACE is set but the header is
'// not found then if this flag is set, the header is added anyway, so long as
'// there is a valid header-value
'//

%WINHTTP_ADDREQ_FLAG_ADD        = &H20000000???

'//
'// WINHTTP_ADDREQ_FLAG_COALESCE - coalesce headers with same name. e.g.
'// "Accept: text/*" and "Accept: audio/*" with this flag results in a single
'// header: "Accept: text/*, audio/*"
'//

%WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA     = &H40000000???
%WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON = &H01000000???
%WINHTTP_ADDREQ_FLAG_COALESCE                = %WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA

'//
'// WINHTTP_ADDREQ_FLAG_REPLACE - replaces the specified header. Only one header can
'// be supplied in the buffer. If the header to be replaced is not the first
'// in a list of headers with the same name, then the relative index should be
'// supplied in the low 8 bits of the dwModifiers parameter. If the header-value
'// part is missing, then the header is removed
'//

%WINHTTP_ADDREQ_FLAG_REPLACE         = &H80000000???

%WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH = 0

DECLARE FUNCTION WinHttpSendRequest IMPORT "WinHTTP.DLL" ALIAS "WinHttpSendRequest" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYREF pwszHeaders AS WSTRINGZ _                      ' __in_opt LPCWSTR pwszHeaders
 , BYVAL dwHeadersLength AS DWORD _                     ' __in DWORD dwHeadersLength
 , BYVAL lpOptional AS DWORD _                          ' __in_opt LPVOID lpOptional
 , BYVAL dwOptionalLength AS DWORD _                    ' __in DWORD dwOptionalLength
 , BYVAL dwTotalLength AS DWORD _                       ' __in DWORD dwTotalLength
 , BYVAL dwContext AS DWORD _                           ' __in DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

'// WinHttpSendRequest prettifiers for optional parameters.
%WINHTTP_NO_ADDITIONAL_HEADERS = %NULL
%WINHTTP_NO_REQUEST_DATA       = %NULL

DECLARE FUNCTION WinHttpSetCredentials IMPORT "WinHTTP.DLL" ALIAS "WinHttpSetCredentials" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL AuthTargets AS DWORD _                         ' __in DWORD AuthTargets
 , BYVAL AuthScheme AS DWORD _                          ' __in DWORD AuthScheme
 , BYREF pwszUserName AS WSTRINGZ _                     ' __in LPCWSTR pwszUserName
 , BYREF pwszPassword AS WSTRINGZ _                     ' __in LPCWSTR pwszPassword
 , BYVAL pAuthParams AS DWORD _                         ' __in LPVOID pAuthParams
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpQueryAuthSchemes IMPORT "WinHTTP.DLL" ALIAS "WinHttpQueryAuthSchemes" ( _
   BYVAL hRequest AS DWORD _                            ' __in  HINTERNET hRequest
 , BYREF lpdwSupportedSchemes AS DWORD _                ' __out LPDWORD lpdwSupportedSchemes
 , BYREF lpdwFirstScheme AS DWORD _                     ' __out LPDWORD lpdwFirstScheme
 , BYREF pdwAuthTarget AS DWORD _                       ' __out LPDWORD pdwAuthTarget
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpQueryAuthParams IMPORT "WinHTTP.DLL" ALIAS "WinHttpQueryAuthParams" ( _
   BYVAL hRequest AS DWORD _                            ' __in  HINTERNET hRequest
 , BYVAL AuthScheme AS DWORD _                          ' __in  DWORD AuthScheme
 , BYREF pAuthParams AS ANY _                           ' __out LPVOID* pAuthParams
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpReceiveResponse IMPORT "WinHTTP.DLL" ALIAS "WinHttpReceiveResponse" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpQueryHeaders IMPORT "WinHTTP.DLL" ALIAS "WinHttpQueryHeaders" ( _
   BYVAL hRequest AS DWORD _                            ' __in HINTERNET hRequest
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD dwInfoLevel
 , BYREF pwszName AS WSTRINGZ _                         ' __in_opt LPCWSTR pwszName
 , BYVAL lpBuffer AS DWORD _                            ' __out_opt LPVOID lpBuffer
 , BYREF lpdwBufferLength AS DWORD  _                   ' __inout LPDWORD lpdwBufferLength
 , BYREF lpdwIndex AS DWORD _                           ' __inout_opt LPDWORD lpdwIndex
 ) AS LONG                                              ' BOOL

'// WinHttpQueryHeaders prettifiers for optional parameters.
%WINHTTP_HEADER_NAME_BY_INDEX = %NULL
%WINHTTP_NO_OUTPUT_BUFFER     = %NULL
%WINHTTP_NO_HEADER_INDEX      = %NULL

DECLARE FUNCTION WinHttpDetectAutoProxyConfigUrl IMPORT "WinHTTP.DLL" ALIAS "WinHttpDetectAutoProxyConfigUrl" ( _
   BYVAL dwAutoDetectFlags AS DWORD  _                  ' __in  DWORD dwAutoDetectFlags,
 , BYREF ppwszAutoConfigUrl AS DWORD _                  ' __out LPWSTR *ppwszAutoConfigUrl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHttpGetProxyForUrl IMPORT "WinHTTP.DLL" ALIAS "WinHttpGetProxyForUrl" ( _
   BYVAL hSession AS DWORD _                            ' __in  HINTERNET hSession
 , BYREF lpcwszUrl AS WSTRINGZ _                        ' __in  LPCWSTR lpcwszUrl
 , BYREF pAutoProxyOptions AS WINHTTP_AUTOPROXY_OPTIONS _ ' __in  WINHTTP_AUTOPROXY_OPTIONS * pAutoProxyOptions
 , BYREF pProxyInfo AS WINHTTP_PROXY_INFO _             ' __out WINHTTP_PROXY_INFO * pProxyInfo
 ) AS LONG                                              ' BOOL

' // Size = 16 bytes
TYPE WINHTTP_CURRENT_USER_IE_PROXY_CONFIG DWORD
   fAutoDetect       AS LONG           ' BOOL
   lpszAutoConfigUrl AS WSTRINGZ PTR   ' LPWSTR
   lpszProxy         AS WSTRINGZ PTR   ' LPWSTR
   lpszProxyBypass   AS WSTRINGZ PTR   ' LPWSTR
END TYPE

DECLARE FUNCTION WinHttpGetIEProxyConfigForCurrentUser IMPORT "WinHTTP.DLL" ALIAS "WinHttpGetIEProxyConfigForCurrentUser" ( _
   BYREF pProxyConfig AS WINHTTP_CURRENT_USER_IE_PROXY_CONFIG _ ' __out WINHTTP_CURRENT_USER_IE_PROXY_CONFIG pProxyConfig
 ) AS LONG                                              ' BOOL

'//#if !defined(_WINERROR_)

'//
'// WinHttp API error returns
'//

%WINHTTP_ERROR_BASE                    = 12000

%ERROR_WINHTTP_OUT_OF_HANDLES          = %WINHTTP_ERROR_BASE + 1
%ERROR_WINHTTP_TIMEOUT                 = %WINHTTP_ERROR_BASE + 2
%ERROR_WINHTTP_INTERNAL_ERROR          = %WINHTTP_ERROR_BASE + 4
%ERROR_WINHTTP_INVALID_URL             = %WINHTTP_ERROR_BASE + 5
%ERROR_WINHTTP_UNRECOGNIZED_SCHEME     = %WINHTTP_ERROR_BASE + 6
%ERROR_WINHTTP_NAME_NOT_RESOLVED       = %WINHTTP_ERROR_BASE + 7
%ERROR_WINHTTP_INVALID_OPTION          = %WINHTTP_ERROR_BASE + 9
%ERROR_WINHTTP_OPTION_NOT_SETTABLE     = %WINHTTP_ERROR_BASE + 11
%ERROR_WINHTTP_SHUTDOWN                = %WINHTTP_ERROR_BASE + 12


%ERROR_WINHTTP_LOGIN_FAILURE           = %WINHTTP_ERROR_BASE + 15
%ERROR_WINHTTP_OPERATION_CANCELLED     = %WINHTTP_ERROR_BASE + 17
%ERROR_WINHTTP_INCORRECT_HANDLE_TYPE   = %WINHTTP_ERROR_BASE + 18
%ERROR_WINHTTP_INCORRECT_HANDLE_STATE  = %WINHTTP_ERROR_BASE + 19
%ERROR_WINHTTP_CANNOT_CONNECT          = %WINHTTP_ERROR_BASE + 29
%ERROR_WINHTTP_CONNECTION_ERROR        = %WINHTTP_ERROR_BASE + 30
%ERROR_WINHTTP_RESEND_REQUEST          = %WINHTTP_ERROR_BASE + 32

%ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED = %WINHTTP_ERROR_BASE + 44

'//
'// WinHttpRequest Component errors
'//
%ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN = %WINHTTP_ERROR_BASE + 100
%ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND = %WINHTTP_ERROR_BASE + 101
%ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND  = %WINHTTP_ERROR_BASE + 102
%ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN  = %WINHTTP_ERROR_BASE + 103


'//
'// HTTP API errors
'//

%ERROR_WINHTTP_HEADER_NOT_FOUND        = %WINHTTP_ERROR_BASE + 150
%ERROR_WINHTTP_INVALID_SERVER_RESPONSE = %WINHTTP_ERROR_BASE + 152
%ERROR_WINHTTP_INVALID_QUERY_REQUEST   = %WINHTTP_ERROR_BASE + 154
%ERROR_WINHTTP_HEADER_ALREADY_EXISTS   = %WINHTTP_ERROR_BASE + 155
%ERROR_WINHTTP_REDIRECT_FAILED         = %WINHTTP_ERROR_BASE + 156


'//
'// additional WinHttp API error codes
'//

'//
'// additional WinHttp API error codes
'//
%ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR  = %WINHTTP_ERROR_BASE + 178
%ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT     = %WINHTTP_ERROR_BASE + 166
%ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT = %WINHTTP_ERROR_BASE + 167

%ERROR_WINHTTP_NOT_INITIALIZED           = %WINHTTP_ERROR_BASE + 172
%ERROR_WINHTTP_SECURE_FAILURE            = %WINHTTP_ERROR_BASE + 175

'//
'// Certificate security errors. These are raised only by the WinHttpRequest
'// component. The WinHTTP Win32 API will return ERROR_WINHTTP_SECURE_FAILE and
'// provide additional information via the WINHTTP_CALLBACK_STATUS_SECURE_FAILURE
'// callback notification.
'//
%ERROR_WINHTTP_SECURE_CERT_DATE_INVALID = %WINHTTP_ERROR_BASE + 37
%ERROR_WINHTTP_SECURE_CERT_CN_INVALID   = %WINHTTP_ERROR_BASE + 38
%ERROR_WINHTTP_SECURE_INVALID_CA        = %WINHTTP_ERROR_BASE + 45
%ERROR_WINHTTP_SECURE_CERT_REV_FAILED   = %WINHTTP_ERROR_BASE + 57
%ERROR_WINHTTP_SECURE_CHANNEL_ERROR     = %WINHTTP_ERROR_BASE + 157
%ERROR_WINHTTP_SECURE_INVALID_CERT      = %WINHTTP_ERROR_BASE + 169
%ERROR_WINHTTP_SECURE_CERT_REVOKED      = %WINHTTP_ERROR_BASE + 170
%ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE  = %WINHTTP_ERROR_BASE + 179


%ERROR_WINHTTP_AUTODETECTION_FAILED                  = %WINHTTP_ERROR_BASE + 180
%ERROR_WINHTTP_HEADER_COUNT_EXCEEDED                 = %WINHTTP_ERROR_BASE + 181
%ERROR_WINHTTP_HEADER_SIZE_OVERFLOW                  = %WINHTTP_ERROR_BASE + 182
%ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW = %WINHTTP_ERROR_BASE + 183
%ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW               = %WINHTTP_ERROR_BASE + 184
%ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY            = %WINHTTP_ERROR_BASE + 185
%ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY     = %WINHTTP_ERROR_BASE + 186

%WINHTTP_ERROR_LAST                                  = %WINHTTP_ERROR_BASE + 186


'//#endif // !defined(_WINERROR_)


'/*
' * Return packing to whatever it was before we
' * entered this file
' */
'#include <poppack.h>
