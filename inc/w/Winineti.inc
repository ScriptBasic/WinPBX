' ########################################################################################
' Microsoft Windows
' File: Winineti.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WININETI_INC = 1

#INCLUDE ONCE "wininet.inc"
#INCLUDE ONCE "iedial.inc"
#INCLUDE ONCE "schannel.inc"
%SECURITY_WIN32 = 1
#INCLUDE ONCE "sspi.inc"
'#if !defined(_WININETEX_)
'#define _WININETEX_

%MAX_CACHE_ENTRY_INFO_SIZE = 4096

'//
'// These two flags should really be included in a new mask called INTERNET_FLAGS_INTERNAL_MASK.
'// Since BGUPDATE is included in INTERNET_FLAGS_MASK already it will cause compile
'// errors when used without winineti.h.  FTP_FOLDER_VIEW is not being included
'// so as to not compound the problem.
'//

%INTERNET_FLAG_BGUPDATE        = &H00000008???
%INTERNET_FLAG_FTP_FOLDER_VIEW = &H00000004???
%INTERNET_FLAGS_MASK_INTERNAL  = %INTERNET_FLAGS_MASK OR %INTERNET_FLAG_FTP_FOLDER_VIEW

'//
'// INTERNET_PREFETCH_STATUS -
'//

' // Size = 8 bytes
TYPE INTERNET_PREFETCH_STATUS DWORD
   ' // dwStatus - status of download. See INTERNET_PREFETCH_ flags
   dwStatus AS DWORD   ' DWORD
   ' // dwSize - size of file downloaded so far
   dwSize   AS DWORD   ' DWORD
END TYPE

'//
'// INTERNET_PREFETCH_STATUS - dwStatus values
'//

%INTERNET_PREFETCH_PROGRESS = 0
%INTERNET_PREFETCH_COMPLETE = 1
%INTERNET_PREFETCH_ABORTED  = 2

MACRO INTERNET_ONLINE_OFFLINE_INFO    = INTERNET_CONNECTED_INFO
'#define dwOfflineState                  dwConnectedState

%ISO_FORCE_OFFLINE       = %ISO_FORCE_DISCONNECTED


'// These flags keep track of security errors on a cached certificate entry
'// from WinVerify that was ignored in order to complete the security handshake.
'// These flags should not use the same bits as any other SECURITY_FLAGS.

%DLG_FLAGS_INVALID_CA                    = &H01000000???
%DLG_FLAGS_SEC_CERT_CN_INVALID           = &H02000000???
%DLG_FLAGS_SEC_CERT_DATE_INVALID         = &H04000000???
%DLG_FLAGS_SEC_CERT_REV_FAILED           = &H00800000???

'#ifdef __WINCRYPT_H__
'#ifdef ALGIDDEF

'//
'// INTERNET_SECURITY_INFO - contains information about certificate
'// and encryption settings for a connection.
'//

'#define INTERNET_SECURITY_INFO_DEFINED
%INTERNET_SECURITY_INFO_DEFINED = 1

' // Size = 732 bytes
TYPE INTERNET_SECURITY_INFO DWORD
   ' // dwSize - Size of INTERNET_SECURITY_INFO structure.
   dwSize                AS DWORD   ' DWORD
   ' // pCertificate - Cert context pointing to leaf of certificate chain.
   pCertificate          AS CERT_CONTEXT PTR   ' PCCERT_CONTEXT
   ' // pcCertChain - Certificate chain for the certificate
   pcCertChain           AS CERT_CHAIN_CONTEXT PTR   ' PCCERT_CHAIN_CONTEXT
   ' // SECPKG_ATTR_CONNECTION_INFO
   connectionInfo        AS SecPkgContext_ConnectionInfo
   ' // SECPKG_ATTR_CIPHER_INFO (Supported on >= LH)
   cipherInfo            AS SecPkgContext_CipherInfo
   ' // pcUnverifiedCertChain - Cert chain from initial WinVerifyTrust state
   pcUnverifiedCertChain AS CERT_CHAIN_CONTEXT PTR   ' PCCERT_CHAIN_CONTEXT
   ' // Channel Binding Token
   channelBindingToken   AS SecPkgContext_Bindings
END TYPE

' // Size = 716 bytes
TYPE INTERNET_SECURITY_CONNECTION_INFO DWORD
   ' // dwSize - size of INTERNET_SECURITY_CONNECTION_INFO
   dwSize         AS DWORD   ' DWORD
   ' // fSecure - Is this a secure connection.
   fSecure        AS LONG   ' BOOL
   ' // SECPKG_ATTR_CONNECTION_INFO
   connectionInfo AS SecPkgContext_ConnectionInfo
   ' // SECPKG_ATTR_CIPHER_INFO (Supported on >= LH)
   cipherInfo     AS SecPkgContext_CipherInfo
END TYPE

DECLARE FUNCTION InternetAlgIdToStringA IMPORT "WININET.DLL" ALIAS "InternetAlgIdToStringA" ( _
   BYVAL ai AS DWORD _                                  ' __in     ALG_ID  ai
 , BYREF lpstr AS ASCIIZ _                              ' __out    LPSTR   lpstr
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD   dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetAlgIdToStringW IMPORT "WININET.DLL" ALIAS "InternetAlgIdToStringW" ( _
   BYVAL ai AS DWORD _                                  ' __in     ALG_ID  ai
 , BYREF lpstr AS WSTRINGZ _                            ' __out    LPWSTR  lpstr
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD   dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetAlgIdToString = InternetAlgIdToStringW
#ELSE
   MACRO InternetAlgIdToString = InternetAlgIdToStringA
#ENDIF

DECLARE FUNCTION InternetSecurityProtocolToStringA IMPORT "WININET.DLL" ALIAS "InternetSecurityProtocolToStringA" ( _
   BYVAL dwProtocol AS DWORD _                          ' __in     DWORD   dwProtocol
 , BYREF lpstr AS ASCIIZ _                              ' __out    LPSTR   lpstr
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD   dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetSecurityProtocolToStringW IMPORT "WININET.DLL" ALIAS "InternetSecurityProtocolToStringW" ( _
   BYVAL dwProtocol AS DWORD _                          ' __in     DWORD   dwProtocol
 , BYREF lpstr AS WSTRINGZ _                            ' __out    LPWSTR  lpstr
 , BYREF lpdwBufferLength AS DWORD _                    ' __in_out LPDWORD lpdwBufferLength
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD   dwReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetSecurityProtocolToString = InternetSecurityProtocolToStringW
#ELSE
   MACRO InternetSecurityProtocolToString = InternetSecurityProtocolToStringA
#ENDIF

'#if (_WIN32_IE >= _WIN32_IE_IE70)

'//
'// This is an API for BrowseUI.  It retrieves
'// security info based on a URL
'//

DECLARE FUNCTION InternetGetSecurityInfoByURLA IMPORT "WININET.DLL" ALIAS "InternetGetSecurityInfoByURLA" ( _
   BYREF lpszURL AS ASCIIZ _                            ' __in  LPSTR lpszURL
 , BYREF ppCertChain AS CERT_CHAIN_CONTEXT _            ' __out PCCERT_CHAIN_CONTEXT * ppCertChain
 , BYREF pdwSecureFlags AS DWORD _                      ' __out DWORD *pdwSecureFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetSecurityInfoByURLW IMPORT "WININET.DLL" ALIAS "InternetGetSecurityInfoByURLW" ( _
   BYREF lpszURL AS WSTRINGZ _                          ' __in  LPCWSTR lpszURL
 , BYREF ppCertChain AS CERT_CHAIN_CONTEXT _            ' __out PCCERT_CHAIN_CONTEXT * ppCertChain
 , BYREF pdwSecureFlags AS DWORD _                      ' __out DWORD *pdwSecureFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetGetSecurityInfoByURL = InternetGetSecurityInfoByURLW
#ELSE
   MACRO InternetGetSecurityInfoByURL = InternetGetSecurityInfoByURLA
#ENDIF

'#endif // _WIN32_IE >= _WIN32_IE_IE70

'#endif // ALGIDDEF
'#endif // __WINCRYPT_H__

'#ifdef INTERNET_SECURITY_INFO_DEFINED
DECLARE FUNCTION ShowSecurityInfo IMPORT "WININET.DLL" ALIAS "ShowSecurityInfo" ( _
   BYVAL hWndParent AS DWORD _                          ' __in HWND                      hWndParent
 , BYREF pSecurityInfo AS INTERNET_SECURITY_INFO _      ' __in LPINTERNET_SECURITY_INFO pSecurityInfo
 ) AS DWORD                                             ' DWORD
'#endif // INTERNET_SECURITY_INFO_DEFINED

DECLARE FUNCTION ShowX509EncodedCertificate IMPORT "WININET.DLL" ALIAS "ShowX509EncodedCertificate" ( _
   BYVAL hWndParent AS DWORD _                          ' __in HWND   hWndParent
 , BYVAL lpCert AS BYTE PTR _                           ' __in LPBYTE lpCert
 , BYVAL cbCert AS DWORD _                              ' __in DWORD  cbCert
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ShowClientAuthCerts IMPORT "WININET.DLL" ALIAS "ShowClientAuthCerts" ( _
   BYVAL hWndParent AS DWORD _                          ' __in HWND hWndParent
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ParseX509EncodedCertificateForListBoxEntry IMPORT "WININET.DLL" ALIAS "ParseX509EncodedCertificateForListBoxEntry" ( _
   BYVAL lpCert AS BYTE PTR _                           ' __in     LPBYTE  lpCert
 , BYVAL cbCert AS DWORD _                              ' __in     DWORD   cbCert
 , BYREF lpszLitBoxEntry AS ASCIIZ _                    ' __out    LPSTR   lpszLitBoxEntry
 , BYREF lpdwListBoxEntry AS DWORD _                    ' __in_out LPDWORD lpdwListBoxEntry
 ) AS DWORD                                             ' DWORD

'//
'// This is a private API for Trident.  It displays
'// security info based on a URL
'//

DECLARE FUNCTION InternetShowSecurityInfoByURLA IMPORT "WININET.DLL" ALIAS "InternetShowSecurityInfoByURLA" ( _
   BYREF lpszURL AS ASCIIZ _                            ' __in LPSTR lpszURL
 , BYVAL hwndParent AS DWORD _                          ' __in HWND  hwndParent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetShowSecurityInfoByURLW IMPORT "WININET.DLL" ALIAS "InternetShowSecurityInfoByURLW" ( _
   BYREF lpszURL AS WSTRINGZ _                          ' __in LPWSTR lpszURL
 , BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetShowSecurityInfoByURL = InternetShowSecurityInfoByURLW
#ELSE
   MACRO InternetShowSecurityInfoByURL = InternetShowSecurityInfoByURLA
#ENDIF

'// The InternetGetCertByURL function was never declared in the wininet header
'// files.  It is obsolete and deprecated. An attempt was made to add it for
'// completeness since it is still exported from wininet.dll. However other
'// code has declared it incorrectly.  This causes compiler errors because
'// the function ends up with two different declarations in the same compilation
'// unit.  It is again not included in the header as anything but this comment.
'//
'// INTERNETAPI_(BOOL) InternetGetCertByURL(
'//    __in        LPSTR   lpszURL,
'//    __inout_bcount(dwcbCertText) LPSTR lpszCertText,
'//    __in_out    DWORD    dwcbCertText
'//    );


'//Fortezza related exports. not public

'// The commands that InternetFortezzaCommand supports.

' enum FORTCMD
%FORTCMD_LOGON                   = 1
%FORTCMD_LOGOFF                  = 2
%FORTCMD_CHG_PERSONALITY         = 3

DECLARE FUNCTION InternetFortezzaCommand IMPORT "WININET.DLL" ALIAS "InternetFortezzaCommand" ( _
   BYVAL dwCommand AS DWORD _                           ' __in DWORD dwCommand
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD_PTR dwReserved
 ) AS LONG                                              ' BOOL


' enum FORTSTAT
%FORTSTAT_INSTALLED          = &H00000001
%FORTSTAT_LOGGEDON           = &H00000002

DECLARE FUNCTION InternetQueryFortezzaStatus IMPORT "WININET.DLL" ALIAS "InternetQueryFortezzaStatus" ( _
   BYREF pdwStatus AS DWORD _                           ' __out DWORD *pdwStatus
 , BYVAL dwReserved AS DWORD _                          ' __in  DWORD_PTR dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetDebugGetLocalTime IMPORT "WININET.DLL" ALIAS "InternetDebugGetLocalTime" ( _
   BYREF pstLocalTime AS SYSTEMTIME _                   ' __out SYSTEMTIME * pstLocalTime
 , BYREF pdwReserved AS DWORD _                         ' __out_opt DWORD  * pdwReserved
 ) AS LONG                                              ' BOOL


'// causes InternetCreateUrlA to escape chars in authority components (user, pwd, host)
%ICU_ESCAPE_AUTHORITY = &H00002000???

%INTERNET_SERVICE_URL   = 0

'//
'// InternetConnectUrl() - a macro which allows you to specify an URL instead of
'// the component parts to InternetConnect(). If any API which uses the returned
'// connect handle specifies a NULL path then the URL-path part of the URL
'// specified in InternetConnectUrl() will be used
'//

'#define InternetConnectUrl(hInternet, lpszUrl, dwFlags, dwContext) \
'    InternetConnect(hInternet,                      \
'                    lpszUrl,                        \
'                    INTERNET_INVALID_PORT_NUMBER,   \
'                    NULL,                           \
'                    NULL,                           \
'                    INTERNET_SERVICE_URL,           \
'                    dwFlags,                        \
'                    dwContext                       \
'                    )

FUNCTION InternetConnectUrlA (BYVAL hInternet AS DWORD, BYREF lpszUrl AS ASCIIZ, BYVAL dwFlags AS DWORD, BYVAL dwContext AS DWORD) AS DWORD
   FUNCTION = InternetConnectA(hInternet, lpszUrl, %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION

FUNCTION InternetConnectUrlW (BYVAL hInternet AS DWORD, BYREF lpszUrl AS WSTRINGZ, BYVAL dwFlags AS DWORD, BYVAL dwContext AS DWORD) AS DWORD
   FUNCTION = InternetConnectW(hInternet, lpszUrl, %INTERNET_INVALID_PORT_NUMBER, BYVAL %NULL, BYVAL %NULL, %INTERNET_SERVICE_URL, dwFlags, dwContext)
END FUNCTION

#IF %DEF(%UNICODE)
   MACRO InternetConnectUrl = InternetConnectUrlW
#ELSE
   MACRO InternetConnectUrl = InternetConnectUrlA
#ENDIF

DECLARE FUNCTION InternetWriteFileExA IMPORT "WININET.DLL" ALIAS "InternetWriteFileExA" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYREF lpBuffersIn AS INTERNET_BUFFERS _              ' __in LPINTERNET_BUFFERSA lpBuffersIn
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwContext AS DWORD _                           ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetWriteFileExW IMPORT "WININET.DLL" ALIAS "InternetWriteFileExW" ( _
   BYVAL hFile AS DWORD _                               ' __in HINTERNET hFile
 , BYREF lpBuffersIn AS INTERNET_BUFFERSW _             ' __in LPINTERNET_BUFFERSA lpBuffersIn
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwContext AS DWORD _                           ' __in_opt DWORD_PTR dwContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InternetWriteFileEx = InternetWriteFileExW
#ELSE
   MACRO InternetWriteFileEx = InternetWriteFileExA
#ENDIF

%INTERNET_OPTION_CONTEXT_VALUE_OLD        = 10
%INTERNET_OPTION_NET_SPEED                = 61
'// Pass in pointer to INTERNET_SECURITY_CONNECTION_INFO to be filled in.
%INTERNET_OPTION_SECURITY_CONNECTION_INFO = 66
%INTERNET_OPTION_DETECT_POST_SEND         = 71
%INTERNET_OPTION_DISABLE_NTLM_PREAUTH     = 72
%INTERNET_OPTION_ORIGINAL_CONNECT_FLAGS   = 97


%INTERNET_OPTION_CERT_ERROR_FLAGS         = 98
%INTERNET_OPTION_IGNORE_CERT_ERROR_FLAGS  = 99

%INTERNET_OPTION_SESSION_START_TIME           = 106
%INTERNET_OPTION_PROXY_CREDENTIALS            = 107
%INTERNET_OPTION_EXTENDED_CALLBACKS           = 108
%INTERNET_OPTION_PROXY_FROM_REQUEST           = 109
%INTERNET_OPTION_ALLOW_FAILED_CONNECT_CONTENT = 110
%INTERNET_OPTION_CACHE_PARTITION              = 111
%INTERNET_OPTION_AUTODIAL_HWND                = 112
%INTERNET_OPTION_SERVER_CREDENTIALS           = 113
%INTERNET_OPTION_WPAD_SLEEP                   = 114
%INTERNET_LAST_OPTION_INTERNAL                = %INTERNET_OPTION_WPAD_SLEEP

%INTERNET_OPTION_OFFLINE_TIMEOUT = %INTERNET_OPTION_DISCONNECTED_TIMEOUT
%INTERNET_OPTION_LINE_STATE      = %INTERNET_OPTION_CONNECTED_STATE

%AUTH_FLAG_RESET                         = &H00000000???   ' /* let registry decide */

'//
'// Extended callbacks.
'//
'// They can happen outside the context of the registered session's API calls.
'//

%INTERNET_STATUS_PROXY_CREDENTIALS       = 400
%INTERNET_STATUS_SERVER_CREDENTIALS      = 401
%INTERNET_STATUS_SERVER_CONNECTION_STATE = 410
%INTERNET_STATUS_END_BROWSER_SESSION     = 420
%INTERNET_STATUS_COOKIE                  = 430

'//
'// Extended callback data structures.
'//

' // Size = 32 bytes
TYPE INTERNET_SERVER_CONNECTION_STATE DWORD
   lpcwszHostName        AS WSTRINGZ PTR   ' LPCWSTR
   fProxy                AS LONG           ' BOOL // Is this a proxy?
   dwCounter             AS DWORD          ' DWORD // Server connection state callback counter.
   dwConnectionLimit     AS DWORD          ' DWORD // Current Limit.
   dwAvailableCreates    AS DWORD          ' DWORD // Connections allowed to be created.
   dwAvailableKeepAlives AS DWORD          ' DWORD // Keep alive connections available to be used.
   dwActiveConnections   AS DWORD          ' DWORD // Current number of active connections.
   dwWaiters             AS DWORD          ' DWORD // Number of request waiting on connections.
END TYPE

' // Size = 8 bytes
TYPE INTERNET_END_BROWSER_SESSION_DATA DWORD
   lpBuffer       AS DWORD   ' LPVOID
   dwBufferLength AS DWORD   ' DWORD
END TYPE

' // Size = 28 bytes
TYPE INTERNET_CALLBACK_COOKIE DWORD
   pcwszName   AS WSTRINGZ PTR   ' PCWSTR
   pcwszValue  AS WSTRINGZ PTR   ' PCWSTR
   pcwszDomain AS WSTRINGZ PTR   ' PCWSTR
   pcwszPath   AS WSTRINGZ PTR   ' PCWSTR
   ftExpires   AS FILETIME       ' FILETIME
   dwFlags     AS DWORD          ' DWORD
END TYPE

' // Size = 8 bytes
TYPE INTERNET_CREDENTIALS_UNION_STRUCT DWORD
   lpcwszUserName AS WSTRINGZ PTR   ' LPCWSTR
   lpcwszPassword AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 8 bytes
UNION INTERNET_CREDENTIALS_UNION DWORD
   INTERNET_CREDENTIALS_UNION_STRUCT
   pAuthIdentityOpaque AS DWORD   ' PVOID
END UNION

' // Size = 32 bytes
TYPE INTERNET_CREDENTIALS DWORD
   lpcwszHostName AS WSTRINGZ PTR   ' LPCWSTR
   dwPort         AS DWORD          ' DWORD
   dwScheme       AS DWORD          ' DWORD
   lpcwszUrl      AS WSTRINGZ PTR   ' LPCWSTR
   lpcwszRealm    AS WSTRINGZ PTR   ' LPCWSTR
   fAuthIdentity  AS LONG           ' BOOL // TRUE if pAuthIdentityOpaque is used in below struct.
   INTERNET_CREDENTIALS_UNION
END TYPE

'//
'// !!! NOTE !!!
'//
'// these defines are needed beecause PREFAST donesn't understand enums in
'// range specifications. Make sue that these are always in sync with any
'// changes to the InternetCookieState enum, above.
'//
%COOKIE_STATE_LB    = 0   ' // COOKIE_STATE_UNKNOWN
%COOKIE_STATE_UB    = 5   ' // COOKIE_STATE_MAX

'/* maximum length of privacy-settings in Unicode characters */
%MaxPrivacySettings      = &H4000

'// Utility for mapping P3P compact-policy tokens to unique indexes
DECLARE FUNCTION FindP3PPolicySymbol IMPORT "WININET.DLL" ALIAS "FindP3PPolicySymbol" ( _
   BYREF pszSymbol AS ASCIIZ _                          ' __in const char *pszSymbol
 ) AS LONG                                              ' int


%INTERNET_STATE_ONLINE       = %INTERNET_STATE_CONNECTED
%INTERNET_STATE_OFFLINE      = %INTERNET_STATE_DISCONNECTED
%INTERNET_STATE_OFFLINE_USER = %INTERNET_STATE_DISCONNECTED_BY_USER
%INTERNET_LINE_STATE_MASK    = %INTERNET_STATE_ONLINE OR %INTERNET_STATE_OFFLINE
%INTERNET_BUSY_STATE_MASK    = %INTERNET_STATE_IDLE OR %INTERNET_STATE_BUSY

'//
'// the following are used with InternetSetOption(..., INTERNET_OPTION_CALLBACK_FILTER, ...)
'// to filter out unrequired callbacks. INTERNET_STATUS_REQUEST_COMPLETE cannot
'// be filtered out
'//

%INTERNET_STATUS_FILTER_RESOLVING        = &H00000001???
%INTERNET_STATUS_FILTER_RESOLVED         = &H00000002???
%INTERNET_STATUS_FILTER_CONNECTING       = &H00000004???
%INTERNET_STATUS_FILTER_CONNECTED        = &H00000008???
%INTERNET_STATUS_FILTER_SENDING          = &H00000010???
%INTERNET_STATUS_FILTER_SENT             = &H00000020???
%INTERNET_STATUS_FILTER_RECEIVING        = &H00000040???
%INTERNET_STATUS_FILTER_RECEIVED         = &H00000080???
%INTERNET_STATUS_FILTER_CLOSING          = &H00000100???
%INTERNET_STATUS_FILTER_CLOSED           = &H00000200???
%INTERNET_STATUS_FILTER_HANDLE_CREATED   = &H00000400???
%INTERNET_STATUS_FILTER_HANDLE_CLOSING   = &H00000800???
%INTERNET_STATUS_FILTER_PREFETCH         = &H00001000???
%INTERNET_STATUS_FILTER_REDIRECT         = &H00002000???
%INTERNET_STATUS_FILTER_STATE_CHANGE     = &H00004000???

'//
'// Note that adding any HTTP_QUERY_* codes here must be followed
'//   by an equivlent line in wininet\http\hashgen\hashgen.cpp
'//   please see that file for further information regarding
'//   the addition of new HTTP headers
'//


'// These are not part of HTTP 1.1 yet. We will propose these to the
'// HTTP extensions working group. These are required for the client-caps support
'// we are doing in conjuntion with IIS.

' // Size = 36 bytes
TYPE INTERNET_COOKIE DWORD
   cbSize       AS DWORD          ' DWORD
   pszName      AS ASCIIZ PTR     ' LPSTR
   pszData      AS ASCIIZ PTR     ' LPSTR
   pszDomain    AS ASCIIZ PTR     ' LPSTR
   pszPath      AS ASCIIZ PTR     ' LPSTR
   pftExpires   AS FILETIME PTR   ' FILETIME *
   dwFlags      AS DWORD          ' DWORD
   pszUrl       AS ASCIIZ PTR     ' LPSTR
   pszP3PPolicy AS ASCIIZ PTR     ' LPSTR
END TYPE

'//
'// Support for handling cookie policy
'//

' // Size = 28 bytes
TYPE COOKIE_DLG_INFO DWORD
   pszServer     AS WSTRINGZ PTR          ' LPWSTR
   pic           AS INTERNET_COOKIE PTR   ' PINTERNET_COOKIE
   dwStopWarning AS DWORD                 ' DWORD
   cx            AS LONG                  ' INT
   cy            AS LONG                  ' INT
   pszHeader     AS WSTRINGZ PTR          ' LPWSTR
   dwOperation   AS DWORD                 ' DWORD
END TYPE

'// values returned from cookie UI, for dwStopWarning member
%COOKIE_DONT_ALLOW       = 1???
%COOKIE_ALLOW            = 2???
%COOKIE_ALLOW_ALL        = 4???
%COOKIE_DONT_ALLOW_ALL   = 8???

'// values for dwOperation member
%COOKIE_OP_SET           = &H01???
%COOKIE_OP_MODIFY        = &H02???
%COOKIE_OP_GET           = &H04???
%COOKIE_OP_SESSION       = &H08???
%COOKIE_OP_PERSISTENT    = &H10???
%COOKIE_OP_3RD_PARTY     = &H20???


'// INTERNET_COOKIE_RESTRICTED_ZONE is the same as INTERNET_FLAG_RESTRICTED_ZONE
%INTERNET_COOKIE_RESTRICTED_ZONE = &H00020000???
%INTERNET_COOKIE_NO_CALLBACK     = &H40000000???
%INTERNET_COOKIE_ECTX_3RDPARTY   = &H80000000???

'//
'// DAV Detection
'//

DECLARE FUNCTION HttpCheckDavComplianceA IMPORT "WININET.DLL" ALIAS "HttpCheckDavComplianceA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpszComplianceToken AS ASCIIZ _                ' __in LPCSTR lpszComplianceToken
 , BYREF lpfFound AS LONG _                             ' __in_out LPBOOL lpfFound
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' BOOL

'// INTERNET_COOKIE_RESTRICTED_ZONE is the same as INTERNET_FLAG_RESTRICTED_ZONE
%INTERNET_COOKIE_RESTRICTED_ZONE = &H00020000???
%INTERNET_COOKIE_NO_CALLBACK     = &H40000000???
%INTERNET_COOKIE_ECTX_3RDPARTY   = &H80000000???

'//
'// DAV Detection
'//

DECLARE FUNCTION HttpCheckDavComplianceW IMPORT "WININET.DLL" ALIAS "HttpCheckDavComplianceW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpszComplianceToken AS WSTRINGZ _              ' __in LPCWSTR lpszComplianceToken
 , BYREF lpfFound AS LONG _                             ' __in_out LPBOOL lpfFound
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpCheckDavCompliance = HttpCheckDavComplianceW
#ELSE
   MACRO HttpCheckDavCompliance = HttpCheckDavComplianceA
#ENDIF

DECLARE FUNCTION HttpCheckCachedDavStatusA IMPORT "WININET.DLL" ALIAS "HttpCheckCachedDavStatusA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpdwStatus AS DWORD _                          ' __in_out LPDWORD lpdwStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpCheckCachedDavStatusW IMPORT "WININET.DLL" ALIAS "HttpCheckCachedDavStatusW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpdwStatus AS DWORD _                          ' __in_out LPDWORD lpdwStatus
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpCheckCachedDavStatus = HttpCheckCachedDavStatusW
#ELSE
   MACRO HttpCheckCachedDavStatus = HttpCheckCachedDavStatusA
#ENDIF

DECLARE FUNCTION HttpCheckDavCollectionA IMPORT "WININET.DLL" ALIAS "HttpCheckDavCollectionA" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in LPCSTR lpszUrl
 , BYREF lpfFound AS LONG _                             ' __in_out LPBOOL lpfFound
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HttpCheckDavCollectionW IMPORT "WININET.DLL" ALIAS "HttpCheckDavCollectionW" ( _
   BYREF lpszUrl AS WSTRINGZ _                          ' __in LPCWSTR lpszUrl
 , BYREF lpfFound AS LONG _                             ' __in_out LPBOOL lpfFound
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO HttpCheckDavCollection = HttpCheckDavCollectionW
#ELSE
   MACRO HttpCheckDavCollection = HttpCheckDavCollectionA
#ENDIF

'// DAV detection defines
%DAV_LEVEL1_STATUS                = &H00000001???
%DAV_COLLECTION_STATUS            = &H00004000???
%DAV_DETECTION_REQUIRED           = &H00008000???
%FLAGS_ERROR_UI_SHOW_IDN_HOSTNAME = &H20???
%ERROR_INTERNET_NO_NEW_CONTAINERS = %INTERNET_ERROR_BASE + 51

%ERROR_INTERNET_OFFLINE  = %ERROR_INTERNET_DISCONNECTED

'//
'// internal error codes that are used to communicate specific information inside
'// of Wininet but which are meaningless at the interface
'//

%INTERNET_INTERNAL_ERROR_BASE            = %INTERNET_ERROR_BASE + 900

%ERROR_INTERNET_INTERNAL_SOCKET_ERROR    = %INTERNET_INTERNAL_ERROR_BASE + 1
%ERROR_INTERNET_CONNECTION_AVAILABLE     = %INTERNET_INTERNAL_ERROR_BASE + 2
%ERROR_INTERNET_NO_KNOWN_SERVERS         = %INTERNET_INTERNAL_ERROR_BASE + 3
%ERROR_INTERNET_PING_FAILED              = %INTERNET_INTERNAL_ERROR_BASE + 4
%ERROR_INTERNET_NO_PING_SUPPORT          = %INTERNET_INTERNAL_ERROR_BASE + 5
%ERROR_INTERNET_CACHE_SUCCESS            = %INTERNET_INTERNAL_ERROR_BASE + 6
%ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION_EX = %INTERNET_INTERNAL_ERROR_BASE + 7

%HTTP_1_1_CACHE_ENTRY            = &H00000040???
%STATIC_CACHE_ENTRY              = &H00000080???
%MUST_REVALIDATE_CACHE_ENTRY     = &H00000100???
%SHORTPATH_CACHE_ENTRY           = &H00000200???
%COOKIE_ACCEPTED_CACHE_ENTRY     = &H00001000???
%COOKIE_LEASHED_CACHE_ENTRY      = &H00002000???
%COOKIE_DOWNGRADED_CACHE_ENTRY   = &H00004000???
%COOKIE_REJECTED_CACHE_ENTRY     = &H00008000???
%PRIVACY_MODE_CACHE_ENTRY        = &H00020000???
%XDR_CACHE_ENTRY                 = &H00040000???
%PENDING_DELETE_CACHE_ENTRY      = &H00400000???
%OTHER_USER_CACHE_ENTRY          = &H00800000???
%PRIVACY_IMPACTED_CACHE_ENTRY    = &H02000000???
%POST_RESPONSE_CACHE_ENTRY       = &H04000000???
%INSTALLED_CACHE_ENTRY           = &H10000000???
%POST_CHECK_CACHE_ENTRY          = &H20000000???
%IDENTITY_CACHE_ENTRY            = &H80000000???
%ANY_CACHE_ENTRY                 = &HFFFFFFFF???

'// We include some entry types even if app doesn't specifically ask for them.
%INCLUDE_BY_DEFAULT_CACHE_ENTRY = _
     %HTTP_1_1_CACHE_ENTRY _
  OR %STATIC_CACHE_ENTRY _
  OR %MUST_REVALIDATE_CACHE_ENTRY _
  OR %PRIVACY_IMPACTED_CACHE_ENTRY _
  OR %POST_CHECK_CACHE_ENTRY _
  OR %COOKIE_ACCEPTED_CACHE_ENTRY _
  OR %COOKIE_LEASHED_CACHE_ENTRY _
  OR %COOKIE_DOWNGRADED_CACHE_ENTRY _
  OR %COOKIE_REJECTED_CACHE_ENTRY _
  OR %SHORTPATH_CACHE_ENTRY

%CACHEGROUP_FLAG_VALID               = &H00000007???

'//
'// Well known sticky group ID
'//
%CACHEGROUP_ID_BUILTIN_STICKY       = &H1000000000000007&&

'//
'// INTERNET_CACHE_CONFIG_PATH_ENTRY
'//

' // Size = 264 bytes
TYPE INTERNET_CACHE_CONFIG_PATH_ENTRYA DWORD
   CachePath   AS ASCIIZ * %MAX_PATH   ' CHAR
   dwCacheSize AS DWORD                ' DWORD // in KBytes
END TYPE

MACRO INTERNET_CACHE_CONFIG_PATH_ENTRY = INTERNET_CACHE_CONFIG_PATH_ENTRYA

' // Size = 524 bytes
TYPE INTERNET_CACHE_CONFIG_PATH_ENTRYW DWORD
   CachePath   AS WSTRINGZ * %MAX_PATH   ' WCHAR
   dwCacheSize AS DWORD                  ' DWORD // in KBytes
END TYPE

'//
'// INTERNET_CACHE_CONFIG_INFO
'//

' // Size = 264 bytes
TYPE INTERNET_CACHE_CONFIG_INFOA_UNION_STRUCT DWORD
   CachePath   AS ASCIIZ * %MAX_PATH   ' CHAR
   dwCacheSize AS DWORD   ' DWORD
END TYPE

' // Size = 264 bytes
UNION INTERNET_CACHE_CONFIG_INFOA_UNION DWORD
   INTERNET_CACHE_CONFIG_INFOA_UNION_STRUCT
   CachePaths(0) AS INTERNET_CACHE_CONFIG_PATH_ENTRYA
END UNION

' // Size = 300 bytes
TYPE INTERNET_CACHE_CONFIG_INFOA DWORD
   dwStructSize    AS DWORD   ' DWORD
   dwContainer     AS DWORD   ' DWORD
   dwQuota         AS DWORD   ' DWORD
   dwReserved4     AS DWORD   ' DWORD
   fPerUser        AS LONG    ' BOOL
   dwSyncMode      AS DWORD   ' DWORD
   dwNumCachePaths AS DWORD   ' DWORD
   INTERNET_CACHE_CONFIG_INFOA_UNION
   dwNormalUsage   AS DWORD   ' DWORD
   dwExemptUsage   AS DWORD   ' DWORD
END TYPE

MACRO INTERNET_CACHE_CONFIG_INFO = INTERNET_CACHE_CONFIG_INFOA

' // Size = 524 bytes
TYPE INTERNET_CACHE_CONFIG_INFOW_UNION_STRUCT DWORD
   CachePath   AS WSTRINGZ * %MAX_PATH   ' WCHAR
   dwCacheSize AS DWORD                  ' DWORD
END TYPE

' // Size = 524 bytes
UNION INTERNET_CACHE_CONFIG_INFOW_UNION DWORD
   INTERNET_CACHE_CONFIG_INFOW_UNION_STRUCT
   CachePaths(0) AS INTERNET_CACHE_CONFIG_PATH_ENTRYW
END UNION

' // Size = 560 bytes
TYPE INTERNET_CACHE_CONFIG_INFOW
   dwStructSize    AS DWORD   ' DWORD
   dwContainer     AS DWORD   ' DWORD
   dwQuota         AS DWORD   ' DWORD
   dwReserved4     AS DWORD   ' DWORD
   fPerUser        AS LONG    ' BOOL
   dwSyncMode      AS DWORD   ' DWORD
   dwNumCachePaths AS DWORD   ' DWORD
   INTERNET_CACHE_CONFIG_INFOW_UNION
   dwNormalUsage   AS DWORD   ' DWORD
   dwExemptUsage   AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION IsUrlCacheEntryExpiredA IMPORT "WININET.DLL" ALIAS "IsUrlCacheEntryExpiredA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in     LPCSTR    lpszUrlName
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD     dwFlags
 , BYREF pftLastModified AS FILETIME _                  ' __in_out FILETIME* pftLastModified
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsUrlCacheEntryExpiredW IMPORT "WININET.DLL" ALIAS "IsUrlCacheEntryExpiredW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in     LPCWSTR   lpszUrlName
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD     dwFlags
 , BYREF pftLastModified AS FILETIME _                  ' __in_out FILETIME* pftLastModified
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsUrlCacheEntryExpired = IsUrlCacheEntryExpiredW
#ELSE
   MACRO IsUrlCacheEntryExpired = IsUrlCacheEntryExpiredA
#ENDIF

%INTERNET_CACHE_FLAG_ALLOW_COLLISIONS  = &H00000100???
%INTERNET_CACHE_FLAG_INSTALLED_ENTRY   = &H00000200???
%INTERNET_CACHE_FLAG_ENTRY_OR_MAPPING  = &H00000400???
%INTERNET_CACHE_FLAG_ADD_FILENAME_ONLY = &H00000800???
%INTERNET_CACHE_FLAG_GET_STRUCT_ONLY   = &H00001000???
%CACHE_ENTRY_TYPE_FC                   = &H00001000???
%CACHE_ENTRY_MODIFY_DATA_FC            = &H80000000???   ' // this appears unused

'// Flags for CreateContainer

%INTERNET_CACHE_CONTAINER_NOSUBDIRS     = &H1???
%INTERNET_CACHE_CONTAINER_AUTODELETE    = &H2???
%INTERNET_CACHE_CONTAINER_RESERVED1     = &H4???
%INTERNET_CACHE_CONTAINER_NODESKTOPINIT = &H8???
%INTERNET_CACHE_CONTAINER_MAP_ENABLED   = &H10???

DECLARE FUNCTION CreateUrlCacheContainerA IMPORT "WININET.DLL" ALIAS "CreateUrlCacheContainerA" ( _
   BYREF Name AS ASCIIZ _                               ' __in LPCSTR Name
 , BYREF lpCachePrefix AS ASCIIZ _                      ' __in LPCSTR lpCachePrefix
 , BYREF lpszCachePath AS ASCIIZ _                      ' __in_opt LPCSTR lpszCachePath
 , BYVAL KBCacheLimit AS DWORD _                        ' __in DWORD KBCacheLimit
 , BYVAL dwContainerType AS DWORD _                     ' __in DWORD dwContainerType
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pvBuffer AS DWORD _                            ' __in LPVOID pvBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in LPDWORD cbBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateUrlCacheContainerW IMPORT "WININET.DLL" ALIAS "CreateUrlCacheContainerW" ( _
   BYREF Name AS WSTRINGZ _                             ' __in LPCWSTR Name
 , BYREF lpCachePrefix AS WSTRINGZ _                    ' __in LPCWSTR lpCachePrefix
 , BYREF lpszCachePath AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszCachePath
 , BYVAL KBCacheLimit AS DWORD _                        ' __in DWORD KBCacheLimit
 , BYVAL dwContainerType AS DWORD _                     ' __in DWORD dwContainerType
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pvBuffer AS DWORD _                            ' __in LPVOID pvBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in LPDWORD cbBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateUrlCacheContainer = CreateUrlCacheContainerW
#ELSE
   MACRO CreateUrlCacheContainer = CreateUrlCacheContainerA
#ENDIF

DECLARE FUNCTION DeleteUrlCacheContainerA IMPORT "WININET.DLL" ALIAS "DeleteUrlCacheContainerA" ( _
   BYREF Name AS ASCIIZ _                               ' __in LPCSTR Name
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteUrlCacheContainerW IMPORT "WININET.DLL" ALIAS "DeleteUrlCacheContainerW" ( _
   BYREF Name AS WSTRINGZ _                             ' __in LPCWSTR Name
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteUrlCacheContainer = DeleteUrlCacheContainerW
#ELSE
   MACRO DeleteUrlCacheContainer = DeleteUrlCacheContainerA
#ENDIF

'//
'// INTERNET_CACHE_ENTRY_INFO -
'//

' // Size = 20 bytes
TYPE INTERNET_CACHE_CONTAINER_INFOA DWORD
   dwCacheVersion  AS DWORD        ' DWORD // version of software
   lpszName        AS ASCIIZ PTR   ' LPSTR // embedded pointer to the container name string.
   lpszCachePrefix AS ASCIIZ PTR   ' LPSTR // embedded pointer to the container URL prefix
   lpszVolumeLabel AS ASCIIZ PTR   ' LPSTR // embedded pointer to the container volume label if any.
   lpszVolumeTitle AS ASCIIZ PTR   ' LPSTR // embedded pointer to the container volume title if any.
END TYPE

MACRO INTERNET_CACHE_CONTAINER_INFO = INTERNET_CACHE_CONTAINER_INFOA

' // Size = 20 bytes
TYPE INTERNET_CACHE_CONTAINER_INFOW DWORD
   dwCacheVersion  AS DWORD          ' DWORD  // version of software
   lpszName        AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the container name string.
   lpszCachePrefix AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the container URL prefix
   lpszVolumeLabel AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the container volume label if any.
   lpszVolumeTitle AS WSTRINGZ PTR   ' LPWSTR // embedded pointer to the container volume title if any.
END TYPE

'//  FindFirstContainer options
%CACHE_FIND_CONTAINER_RETURN_NOCHANGE = &H1???

DECLARE FUNCTION FindFirstUrlCacheContainerA IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheContainerA" ( _
   BYREF pdwModified AS DWORD _                         ' __in_out LPDWORD pdwModified
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOA _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOA lpContainerInfo
 , BYREF lpcbContainerInfo AS DWORD _                   ' __in_out LPDWORD lpcbContainerInfo
 , BYVAL dwOptions AS DWORD _                           ' __in     DWORD dwOptions
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindFirstUrlCacheContainerW IMPORT "WININET.DLL" ALIAS "FindFirstUrlCacheContainerW" ( _
   BYREF pdwModified AS DWORD _                         ' __in_out LPDWORD pdwModified
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOW _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOW lpContainerInfo
 , BYREF lpcbContainerInfo AS DWORD _                   ' __in_out LPDWORD lpcbContainerInfo
 , BYVAL dwOptions AS DWORD _                           ' __in     DWORD dwOptions
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO FindFirstUrlCacheContainer = FindFirstUrlCacheContainerW
#ELSE
   MACRO FindFirstUrlCacheContainer = FindFirstUrlCacheContainerA
#ENDIF

DECLARE FUNCTION FindNextUrlCacheContainerA IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheContainerA" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in     HANDLE hEnumHandle
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOA _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOA lpContainerInfo
 , BYREF lpcbContainerInfo AS DWORD _                   ' __in_out LPDWORD lpcbContainerInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindNextUrlCacheContainerW IMPORT "WININET.DLL" ALIAS "FindNextUrlCacheContainerW" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in     HANDLE hEnumHandle
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOW _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOW lpContainerInfo
 , BYREF lpcbContainerInfo AS DWORD _                   ' __in_out LPDWORD lpcbContainerInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FindNextUrlCacheContainer = FindNextUrlCacheContainerW
#ELSE
   MACRO FindNextUrlCacheContainer = FindNextUrlCacheContainerA
#ENDIF

' enum WININET_SYNC_MODE
%SYNC_MODE_NEVER            = 0
%SYNC_MODE_ON_EXPIRY        = 1   ' // bogus
%SYNC_MODE_ONCE_PER_SESSION = 2
%SYNC_MODE_ALWAYS           = 3
%SYNC_MODE_AUTOMATIC        = 4
%SYNC_MODE_DEFAULT          = %SYNC_MODE_AUTOMATIC

DECLARE FUNCTION FreeUrlCacheSpaceA IMPORT "WININET.DLL" ALIAS "FreeUrlCacheSpaceA" ( _
   BYREF lpszCachePath AS ASCIIZ _                      ' __in_opt LPCSTR lpszCachePath
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYVAL dwFilter AS DWORD _                            ' __in DWORD dwFilter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreeUrlCacheSpaceW IMPORT "WININET.DLL" ALIAS "FreeUrlCacheSpaceW" ( _
   BYREF lpszCachePath AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszCachePath
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYVAL dwFilter AS DWORD _                            ' __in DWORD dwFilter
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO FreeUrlCacheSpace = FreeUrlCacheSpaceW
#ELSE
   MACRO FreeUrlCacheSpace = FreeUrlCacheSpaceA
#ENDIF

'//
'// config APIs.
'//

%CACHE_CONFIG_FORCE_CLEANUP_FC           = &H00000020???
%CACHE_CONFIG_DISK_CACHE_PATHS_FC        = &H00000040???
%CACHE_CONFIG_SYNC_MODE_FC               = &H00000080???
%CACHE_CONFIG_CONTENT_PATHS_FC           = &H00000100???
%CACHE_CONFIG_COOKIES_PATHS_FC           = &H00000200???
%CACHE_CONFIG_HISTORY_PATHS_FC           = &H00000400???
%CACHE_CONFIG_QUOTA_FC                   = &H00000800???
%CACHE_CONFIG_USER_MODE_FC               = &H00001000???
%CACHE_CONFIG_CONTENT_USAGE_FC           = &H00002000???
%CACHE_CONFIG_STICKY_CONTENT_USAGE_FC    = &H00004000???

DECLARE FUNCTION GetUrlCacheConfigInfoA IMPORT "WININET.DLL" ALIAS "GetUrlCacheConfigInfoA" ( _
   BYREF lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOA _ ' __out LPINTERNET_CACHE_CONFIG_INFOA lpCacheConfigInfo
 , BYVAL lpcbCacheConfigInfo AS DWORD _                 ' __in LPDWORD lpcbCacheConfigInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheConfigInfoW IMPORT "WININET.DLL" ALIAS "GetUrlCacheConfigInfoW" ( _
   BYREF lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOW _ ' __out LPINTERNET_CACHE_CONFIG_INFOW lpCacheConfigInfo
 , BYVAL lpcbCacheConfigInfo AS DWORD _                 ' __in LPDWORD lpcbCacheConfigInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUrlCacheConfigInfo = GetUrlCacheConfigInfoW
#ELSE
   MACRO GetUrlCacheConfigInfo = GetUrlCacheConfigInfoA
#ENDIF

DECLARE FUNCTION SetUrlCacheConfigInfoA IMPORT "WININET.DLL" ALIAS "SetUrlCacheConfigInfoA" ( _
   BYREF lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOA _ ' __in LPINTERNET_CACHE_CONFIG_INFOA lpCacheConfigInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUrlCacheConfigInfoW IMPORT "WININET.DLL" ALIAS "SetUrlCacheConfigInfoW" ( _
   BYREF lpCacheConfigInfo AS INTERNET_CACHE_CONFIG_INFOW _ ' __in LPINTERNET_CACHE_CONFIG_INFOW lpCacheConfigInfo
 , BYVAL dwFieldControl AS DWORD _                      ' __in DWORD dwFieldControl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetUrlCacheConfigInfo = SetUrlCacheConfigInfoW
#ELSE
   MACRO SetUrlCacheConfigInfo = SetUrlCacheConfigInfoA
#ENDIF

DECLARE FUNCTION RunOnceUrlCache IMPORT "WININET.DLL" ALIAS "RunOnceUrlCache" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND      hwnd
 , BYVAL hinst AS DWORD _                               ' __in HINSTANCE hinst
 , BYREF lpszCmd AS ASCIIZ _                            ' __in LPSTR     lpszCmd
 , BYVAL nCmdShow AS LONG _                             ' __in int       nCmdShow
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeleteIE3Cache IMPORT "WININET.DLL" ALIAS "DeleteIE3Cache" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND      hwnd
 , BYVAL hinst AS DWORD _                               ' __in HINSTANCE hinst
 , BYREF lpszCmd AS ASCIIZ _                            ' __in LPSTR     lpszCmd
 , BYVAL nCmdShow AS LONG _                             ' __in int       nCmdShow
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION UpdateUrlCacheContentPath IMPORT "WININET.DLL" ALIAS "UpdateUrlCacheContentPath" ( _
   BYREF szNewPath AS ASCIIZ _                          ' __in LPCSTR    szNewPath
 ) AS DWORD                                             ' DWORD

'// Cache header data defines.

%CACHE_HEADER_DATA_CURRENT_SETTINGS_VERSION = 0
%CACHE_HEADER_DATA_CONLIST_CHANGE_COUNT     = 1
%CACHE_HEADER_DATA_COOKIE_CHANGE_COUNT      = 2

%CACHE_HEADER_DATA_NOTIFICATION_HWND        = 3
%CACHE_HEADER_DATA_NOTIFICATION_MESG        = 4
%CACHE_HEADER_DATA_ROOTGROUP_OFFSET         = 5
%CACHE_HEADER_DATA_GID_LOW                  = 6
%CACHE_HEADER_DATA_GID_HIGH                 = 7

%CACHE_HEADER_DATA_CACHE_RESERVED_8         = 8
%CACHE_HEADER_DATA_CACHE_RESERVED_9         = 9
%CACHE_HEADER_DATA_CACHE_RESERVED_10        = 10
%CACHE_HEADER_DATA_CACHE_RESERVED_11        = 11
%CACHE_HEADER_DATA_CACHE_RESERVED_12        = 12
%CACHE_HEADER_DATA_CACHE_RESERVED_13        = 13


%CACHE_HEADER_DATA_SSL_STATE_COUNT          = 14
'// legacy alias for ssl state count
%CACHE_HEADER_DATA_DOWNLOAD_PARTIAL = %CACHE_HEADER_DATA_SSL_STATE_COUNT


%CACHE_HEADER_DATA_CACHE_RESERVED_15        = 15
%CACHE_HEADER_DATA_CACHE_RESERVED_16        = 16
%CACHE_HEADER_DATA_CACHE_RESERVED_17        = 17
%CACHE_HEADER_DATA_CACHE_RESERVED_18        = 18
%CACHE_HEADER_DATA_CACHE_RESERVED_19        = 19
%CACHE_HEADER_DATA_CACHE_RESERVED_20        = 20

%CACHE_HEADER_DATA_NOTIFICATION_FILTER      = 21
%CACHE_HEADER_DATA_ROOT_LEAK_OFFSET         = 22

%CACHE_HEADER_DATA_CACHE_RESERVED_23        = 23
%CACHE_HEADER_DATA_CACHE_RESERVED_24        = 24
%CACHE_HEADER_DATA_CACHE_RESERVED_25        = 25
%CACHE_HEADER_DATA_CACHE_RESERVED_26        = 26

%CACHE_HEADER_DATA_ROOT_GROUPLIST_OFFSET    = 27   ' // offset to group list

%CACHE_HEADER_DATA_CACHE_RESERVED_28        = 28
%CACHE_HEADER_DATA_CACHE_RESERVED_29        = 29
%CACHE_HEADER_DATA_CACHE_RESERVED_30        = 30
%CACHE_HEADER_DATA_CACHE_RESERVED_31        = 31

%CACHE_HEADER_DATA_LAST                     = 31

'// options for cache notification filter
%CACHE_NOTIFY_ADD_URL                       = &H00000001???
%CACHE_NOTIFY_DELETE_URL                    = &H00000002???
%CACHE_NOTIFY_UPDATE_URL                    = &H00000004???
%CACHE_NOTIFY_DELETE_ALL                    = &H00000008???
%CACHE_NOTIFY_URL_SET_STICKY                = &H00000010???
%CACHE_NOTIFY_URL_UNSET_STICKY              = &H00000020???
%CACHE_NOTIFY_SET_ONLINE                    = &H00000100???
%CACHE_NOTIFY_SET_OFFLINE                   = &H00000200???

%CACHE_NOTIFY_FILTER_CHANGED                = &H10000000???

DECLARE FUNCTION RegisterUrlCacheNotification IMPORT "WININET.DLL" ALIAS "RegisterUrlCacheNotification" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND    hWnd
 , BYVAL uMsg AS DWORD _                                ' __in     UINT    uMsg
 , BYVAL gid AS WORD _                                  ' __in     GROUPID gid
 , BYVAL dwOpsFilter AS DWORD _                         ' __in     DWORD   dwOpsFilter
 , BYVAL dwReserved AS DWORD _                          ' __in     DWORD   dwReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheHeaderData IMPORT "WININET.DLL" ALIAS "GetUrlCacheHeaderData" ( _
   BYVAL Idx AS DWORD _                                 ' __in  HWND    nIdx
 , BYREF lpdwData AS DWORD _                            ' __out LPDWORD lpdwData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetUrlCacheHeaderData IMPORT "WININET.DLL" ALIAS "SetUrlCacheHeaderData" ( _
   BYVAL nIdx AS DWORD _                                ' __in HWND  nIdx
 , BYVAL dwData AS DWORD _                              ' __in DWORD dwData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IncrementUrlCacheHeaderData IMPORT "WININET.DLL" ALIAS "IncrementUrlCacheHeaderData" ( _
   BYVAL nIdx AS DWORD _                                ' __in  HWND    nIdx
 , BYREF lpdwData AS DWORD _                            ' __out LPDWORD lpdwData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LoadUrlCacheContent IMPORT "WININET.DLL" ALIAS "LoadUrlCacheContent" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheContainerInfoA IMPORT "WININET.DLL" ALIAS "GetUrlCacheContainerInfoA" ( _
   BYREF lpszUrlName AS ASCIIZ _                        ' __in     LPSTR lpszUrlName
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOA _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOA lpContainerInfo
 , BYREF lpdwContainerInfoBufferSize AS DWORD _         ' __in_out LPDWORD lpdwContainerInfoBufferSize
 , BYVAL dwOptions AS DWORD _                           ' __in     DWORD dwOptions
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUrlCacheContainerInfoW IMPORT "WININET.DLL" ALIAS "GetUrlCacheContainerInfoW" ( _
   BYREF lpszUrlName AS WSTRINGZ _                      ' __in     LPWSTR lpszUrlName
 , BYREF lpContainerInfo AS INTERNET_CACHE_CONTAINER_INFOW _ ' __out    LPINTERNET_CACHE_CONTAINER_INFOW lpContainerInfo
 , BYREF lpdwContainerInfoBufferSize AS DWORD _         ' __in_out LPDWORD lpdwContainerInfoBufferSize
 , BYVAL dwOptions AS DWORD _                           ' __in     DWORD dwOptions
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetUrlCacheContainerInfo = GetUrlCacheContainerInfoW
#ELSE
   MACRO GetUrlCacheContainerInfo = GetUrlCacheContainerInfoA
#ENDIF

'//
'// Autodial APIs
'//

' Also declared in wininet.inc
'DECLARE FUNCTION InternetDialA IMPORT "WININET.DLL" ALIAS "InternetDialA" ( _
'   BYVAL hwndParent AS DWORD _                          ' __in HWND        hwndParent
' , BYREF lpszConnectoid AS ASCIIZ _                     ' __in_opt LPSTR   lpszConnectoid
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD       dwFlags
' , BYREF lpdwConnection AS DWORD _                      ' __out DWORD_PTR *lpdwConnection
' , BYVAL dwReserved AS DWORD _                          ' __in DWORD       dwReserved
' ) AS DWORD                                             ' DWORD

' Also declared in wininet.inc
'DECLARE FUNCTION InternetDialW IMPORT "WININET.DLL" ALIAS "InternetDialW" ( _
'   BYVAL hwndParent AS DWORD _                          ' __in HWND        hwndParent
' , BYREF lpszConnectoid AS WSTRINGZ _                   ' __in_opt LPWSTR  lpszConnectoid
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD       dwFlags
' , BYREF lpdwConnection AS DWORD _                      ' __out DWORD_PTR *lpdwConnection
' , BYVAL dwReserved AS DWORD _                          ' __in DWORD       dwReserved
' ) AS DWORD                                             ' DWORD

' Also declared in wininet.inc
'// Flags for InternetDial - must not conflict with InternetAutodial flags
'//                          as they are valid here also.
'%INTERNET_DIAL_FORCE_PROMPT     = &H2000???
'%INTERNET_DIAL_SHOW_OFFLINE     = &H4000???
'%INTERNET_DIAL_UNATTENDED       = &H8000???

'DECLARE FUNCTION InternetHangUp IMPORT "WININET.DLL" ALIAS "InternetHangUp" ( _
'   BYVAL dwConnection AS DWORD _                        ' __in DWORD_PTR dwConnection
' , BYVAL dwReserved AS DWORD _                          ' __in DWORD     dwReserved
' ) AS DWORD                                             ' DWORD

' Also declared in wininet.inc
'%INTERENT_GOONLINE_REFRESH = &H00000001???
'%INTERENT_GOONLINE_MASK    = &H00000001???

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGoOnlineA IMPORT "WININET.DLL" ALIAS "InternetGoOnlineA" ( _
'   BYREF lpszURL AS ASCIIZ _                            ' __in_opt LPSTR lpszURL
' , BYVAL hwndParent AS DWORD _                          ' __in HWND      hwndParent
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD     dwFlags
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGoOnlineW IMPORT "WININET.DLL" ALIAS "InternetGoOnlineW" ( _
'   BYREF lpszURL AS WSTRINGZ _                          ' __in_opt LPWSTR lpszURL
' , BYVAL hwndParent AS DWORD _                          ' __in HWND       hwndParent
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD      dwFlags
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'// Flags for InternetAutodial
'%INTERNET_AUTODIAL_FORCE_ONLINE         = 1
'%INTERNET_AUTODIAL_FORCE_UNATTENDED     = 2
'%INTERNET_AUTODIAL_FAILIFSECURITYCHECK  = 4
'%INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT = 8

'%INTERNET_AUTODIAL_FLAGS_MASK = %INTERNET_AUTODIAL_FORCE_ONLINE OR %INTERNET_AUTODIAL_FORCE_UNATTENDED OR %INTERNET_AUTODIAL_FAILIFSECURITYCHECK OR %INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT

' Also declared in wininet.inc
'DECLARE FUNCTION InternetAutodialHangup IMPORT "WININET.DLL" ALIAS "InternetAutodialHangup" ( _
'   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGetConnectedState IMPORT "WININET.DLL" ALIAS "InternetGetConnectedState" ( _
'   BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD  lpdwFlags
' , BYVAL dwReserved AS DWORD _                          ' __in  DWORD    dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGetConnectedStateExA IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateExA" ( _
'   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD  lpdwFlags
' , BYREF lpszConnectionName AS ASCIIZ _                 ' __out     LPSTR    lpszConnectionName
' , BYVAL dwBufLen AS DWORD _                            ' __in      DWORD    dwBufLen
' , BYVAL dwReserved AS DWORD _                          ' __in      DWORD    dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGetConnectedStateExW IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateExW" ( _
'   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD  lpdwFlags
' , BYREF lpszConnectionName AS WSTRINGZ _               ' __out     LPWSTR   lpszConnectionName
' , BYVAL dwBufLen AS DWORD _                            ' __in      DWORD    dwBufLen
' , BYVAL dwReserved AS DWORD _                          ' __in      DWORD    dwReserved
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternetGetDialEngineW IMPORT "WININET.DLL" ALIAS "InternetGetDialEngineW" ( _
   BYREF pwzConnectoid AS WSTRINGZ _                    ' __in  LPWSTR           pwzConnectoid
 , BYVAL pdes AS IDialEventSink _                       ' __in  IDialEventSink * pdes
 , BYREF ppde AS IDialEngine _                          ' __out IDialEngine **   ppde
 ) AS LONG                                              ' BOOL

MACRO InternetGetDialEngine = InternetGetDialEngineW

DECLARE FUNCTION InternetGetDialBrandingW IMPORT "WININET.DLL" ALIAS "InternetGetDialBrandingW" ( _
   BYREF pwzConnectoid AS WSTRINGZ _                    ' __in  LPWSTR            pwzConnectoid
 , BYREF ppdb AS IDialBranding _                        ' __out IDialBranding **  ppdb
 ) AS LONG                                              ' BOOL

MACRO InternetGetDialBranding = InternetGetDialBrandingW

DECLARE FUNCTION ReadGuidsForConnectedNetworks IMPORT "WININET.DLL" ALIAS "ReadGuidsForConnectedNetworks" ( _
   BYREF pcNetworks AS DWORD _                          ' __out_opt DWORD *pcNetworks
 , BYREF pppwszNetworkGuids AS DWORD _                  ' __out_opt PWSTR **pppwszNetworkGuids
 , BYREF pppbstrNetworkNames AS WSTRING _               ' __out_opt BSTR  **pppbstrNetworkNames
 , BYREF pppwszGWMacs AS DWORD _                        ' __out_opt PWSTR **pppwszGWMacs
 , BYREF pcGatewayMacs AS DWORD _                       ' __out_opt DWORD *pcGatewayMacs
 , BYREF pdwFlags AS DWORD _                            ' __out_opt DWORD *pdwFlags
 ) AS LONG                                              ' BOOL

'//
'// INTERNET_AUTOPROXY_INIT_FLAGS - Flags for InternetInitializeAutoProxyDll
'//
%INTERNET_AUTOPROXY_INIT_DEFAULT      = &H1???
%INTERNET_AUTOPROXY_INIT_DOWNLOADSYNC = &H2???
%INTERNET_AUTOPROXY_INIT_QUERYSTATE   = &H4???
%INTERNET_AUTOPROXY_INIT_ONLYQUERY    = &H8???

%INTERNET_AUTOPROXY_INIT_MASK = %INTERNET_AUTOPROXY_INIT_DEFAULT OR %INTERNET_AUTOPROXY_INIT_DOWNLOADSYNC OR %INTERNET_AUTOPROXY_INIT_QUERYSTATE OR %INTERNET_AUTOPROXY_INIT_ONLYQUERY

' Also declared in wininet.inc
'DECLARE FUNCTION InternetInitializeAutoProxyDll IMPORT "JSPROXY.DLL" ALIAS "InternetInitializeAutoProxyDll" ( _
'   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION DetectAutoProxyUrl IMPORT "WININET.DLL" ALIAS "DetectAutoProxyUrl" ( _
'   BYREF AlpszAutoProxyUrl AS SCIIZ _                   ' __out_ecount(dwAutoProxyUrlLength) LPSTR lpszAutoProxyUrl
' , BYVAL dwAutoProxyUrlLength AS DWORD _                ' __in DWORD dwAutoProxyUrlLength
' , BYVAL dwDetectFlags AS DWORD _                       ' __in DWORD dwDetectFlags
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION CreateMD5SSOHash IMPORT "WININET.DLL" ALIAS "CreateMD5SSOHash" ( _
'   BYREF pszChallengeInfo AS WSTRINGZ _                 ' __in PWSTR    pszChallengeInfo
' , BYREF pwszRealm AS WSTRINGZ _                        ' __in PWSTR    pwszRealm
' , BYREF pwszTarget AS WSTRINGZ _                       ' __in PWSTR    pwszTarget
' , BYREF pbHexHash AS ANY _                             ' __out PBYTE   pbHexHash
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGetConnectedStateEx IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateEx" ( _
'   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD lpdwFlags
' , BYREF lpszConnectionName AS ASCIIZ _                 ' __out_ecount_opt(dwBufLen) LPSTR lpszConnectionName
' , BYVAL dwBufLen AS DWORD _                            ' __in DWORD dwBufLen
' , BYVAL dwReserved AS DWORD _                          ' __null DWORD dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetGetConnectedStateExW IMPORT "WININET.DLL" ALIAS "InternetGetConnectedStateExW" ( _
'   BYREF lpdwFlags AS DWORD _                           ' __out_opt LPDWORD lpdwFlags
' , BYREF lpszConnectionName AS WSTRINGZ _               ' __out_ecount_opt(dwBufLen) LPWSTR lpszConnectionName
' , BYVAL dwBufLen AS DWORD _                            ' __in DWORD dwBufLen
' , BYVAL dwReserved AS DWORD _                          ' __null DWORD dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'// Flags for InternetGetConnectedState and Ex
'%INTERNET_CONNECTION_MODEM           = &H01???
'%INTERNET_CONNECTION_LAN             = &H02???
'%INTERNET_CONNECTION_PROXY           = &H04???
'%INTERNET_CONNECTION_MODEM_BUSY      = &H08???    ' /* no longer used */
'%INTERNET_RAS_INSTALLED              = &H10???
'%INTERNET_CONNECTION_OFFLINE         = &H20???
'%INTERNET_CONNECTION_CONFIGURED      = &H40???

'//
'// Custom dial handler functions
'//

'// Custom dial handler prototype
'typedef DWORD (CALLBACK * PFN_DIAL_HANDLER) (HWND, LPCSTR, DWORD, LPDWORD);

' Also declared in wininet.inc
'// Flags for custom dial handler
'%INTERNET_CUSTOMDIAL_CONNECT         = 0???
'%INTERNET_CUSTOMDIAL_UNATTENDED      = 1???
'%INTERNET_CUSTOMDIAL_DISCONNECT      = 2???
'%INTERNET_CUSTOMDIAL_SHOWOFFLINE     = 4???

' Also declared in wininet.inc
'// Custom dial handler supported functionality flags
'%INTERNET_CUSTOMDIAL_SAFE_FOR_UNATTENDED = 1???
'%INTERNET_CUSTOMDIAL_WILL_SUPPLY_STATE   = 2???
'%INTERNET_CUSTOMDIAL_CAN_HANGUP          = 4???

' Also declared in wininet.inc
'DECLARE FUNCTION InternetSetDialStateA IMPORT "WININET.DLL" ALIAS "InternetSetDialStateA" ( _
'   BYREF lpszConnectoid AS ASCIIZ _                     ' __in_opt   LPCSTR lpszConnectoid
' , BYVAL dwState AS DWORD _                             ' __in   DWORD  dwState
' , BYVAL dwReserved AS DWORD _                          ' __null DWORD  dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetSetDialStateW IMPORT "WININET.DLL" ALIAS "InternetSetDialStateW" ( _
'   BYREF lpszConnectoid AS WSTRINGZ _                   ' __in_opt   LPCWSTR lpszConnectoid
' , BYVAL dwState AS DWORD _                             ' __in   DWORD  dwState
' , BYVAL dwReserved AS DWORD _                          ' __null DWORD  dwReserved
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'// States for InternetSetDialState
'%INTERNET_DIALSTATE_DISCONNECTED = 1

'// Registry entries used by the dialing code
'// All of these entries are in:
'// HKCU\software\microsoft\windows\current version\internet settings

$REGSTR_DIAL_AUTOCONNECT     = "AutoConnect"

'// Registry entries for legacy cookies
$REGSTR_LEASH_LEGACY_COOKIES = "LeashLegacyCookies"

'// Used by security manager.

DECLARE FUNCTION IsHostInProxyBypassList IMPORT "WININET.DLL" ALIAS "IsHostInProxyBypassList" ( _
   BYVAL tScheme AS LONG _                              ' __in INTERNET_SCHEME tScheme
 , BYREF lpszHost AS ASCIIZ _                           ' __in LPCSTR lpszHost
 , BYVAL cchHost AS DWORD _                             ' __in DWORD cchHost
 ) AS LONG                                              ' BOOL


'// Used by Shell to determine if anyone has loaded wininet yet
'// Shell code calls OpenMutex with this name and if no mutex is
'// obtained, we know that no copy of wininet has been loaded yet
'#if _WIN32_WINNT >= _WIN32_WINNT_WINXP
#IF %WINVER >= &H0501
'#define LOCAL_NAMESPACE_PREFIX            "Local\\"
$LOCAL_NAMESPACE_PREFIX            = "Local\"
#ELSE
$LOCAL_NAMESPACE_PREFIX            = ""
'#define LOCAL_NAMESPACE_PREFIX
#ENDIF
$WININET_STARTUP_MUTEX = $LOCAL_NAMESPACE_PREFIX & "WininetStartupMutex"

'BOOL DoConnectoidsExist(void); // Returns TRUE if any RAS connectoids exist and FALSE otherwise
DECLARE FUNCTION DoConnectoidsExist IMPORT "WININET.DLL" ALIAS "DoConnectoidsExist" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDiskInfo IMPORT "WININET.DLL" ALIAS "GetDiskInfoA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in      PCSTR pszPath
 , BYREF pdwClusterSize AS DWORD _                      ' __out_opt PDWORD pdwClusterSize
 , BYREF pdlAvail AS QUAD _                             ' __out_opt PDWORDLONG pdlAvail
 , BYREF pdlTotal AS QUAD _                             ' __out_opt PDWORDLONG pdlTotal
 ) AS LONG                                              ' BOOL

'typedef BOOL (*CACHE_OPERATOR)(INTERNET_CACHE_ENTRY_INFO* pcei, PDWORD pcbcei, PVOID pOpData);

DECLARE FUNCTION PerformOperationOverUrlCacheA IMPORT "WININET.DLL" ALIAS "PerformOperationOverUrlCacheA" ( _
   BYREF pszUrlSearchPattern AS ASCIIZ _                             ' __in_opt PCSTR     pszUrlSearchPattern
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD     dwFlags
 , BYVAL dwFilter AS DWORD _                            ' __in     DWORD     dwFilter
 , BYVAL GroupId AS WORD _                              ' __in     GROUPID   GroupId
 , BYVAL pReserved1 AS DWORD _                          ' __in     PVOID     pReserved1
 , BYVAL pdwReserved2 AS DWORD _                        ' __in     PDWORD    pdwReserved2
 , BYVAL pReserved3 AS DWORD _                          ' __in     PVOID     pReserved3
 , BYVAL op AS DWORD _                                  ' __in     CACHE_OPERATOR op
 , BYREF pOperatorData AS DWORD _                       ' __in_out PVOID     pOperatorData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsProfilesEnabled IMPORT "WININET.DLL" ALIAS "IsProfilesEnabled" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileExtensionFromUrl IMPORT "WININET.DLL" ALIAS "GetFileExtensionFromUrl" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in     LPSTR lpszUrl
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 , BYREF lpszExt AS ASCIIZ _                            ' __in_out LPSTR lpszExt
 , BYREF pcchExt AS DWORD _                             ' __in_out DWORD *pcchExt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InternalInternetGetCookie IMPORT "WININET.DLL" ALIAS "InternalInternetGetCookie" ( _
   BYREF lpszUrl AS ASCIIZ _                            ' __in     LPCSTR lpszUrl
 , BYREF lpszCookieData AS ASCIIZ _                     ' __out    LPSTR lpszCookieData
 , BYREF lpdwDataSize AS DWORD _                        ' __in_out DWORD *lpdwDataSize
 ) AS LONG                                              ' BOOL


'//  in cookimp.cxx and cookexp.cxx
DECLARE FUNCTION ImportCookieFileA IMPORT "WININET.DLL" ALIAS "ImportCookieFileA" ( _
   BYREF szFilename AS ASCIIZ _                         ' __in LPCSTR szFilename
 ) AS LONG                                              ' BOOL

'//  in cookimp.cxx and cookexp.cxx
DECLARE FUNCTION ImportCookieFileW IMPORT "WININET.DLL" ALIAS "ImportCookieFileW" ( _
   BYREF szFilename AS WSTRINGZ _                       ' __in LPCWSTR szFilename
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImportCookieFile = ImportCookieFileW
#ELSE
   MACRO ImportCookieFile = ImportCookieFileA
#ENDIF

DECLARE FUNCTION IsDomainLegalCookieDomainA IMPORT "WININET.DLL" ALIAS "IsDomainLegalCookieDomainA" ( _   ' // in "wininet\http\cookie.cxx"
   BYREF pchDomain AS ASCIIZ _                          ' __in LPCSTR pchDomain
 , BYREF pchFullDomain AS ASCIIZ _                      ' __in LPCSTR pchFullDomain
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsDomainLegalCookieDomainW IMPORT "WININET.DLL" ALIAS "IsDomainLegalCookieDomainW" ( _   ' // in "wininet\http\cookie.cxx"
   BYREF pchDomain AS WSTRINGZ _                        ' __in LPCWSTR pchDomain
 , BYREF pchFullDomain AS WSTRINGZ _                    ' __in LPCWSTR pchFullDomain
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsDomainLegalCookieDomain = IsDomainLegalCookieDomainW
#ELSE
   MACRO IsDomainLegalCookieDomain = IsDomainLegalCookieDomainA
#ENDIF

' Also declared in wininet.inc
'DECLARE FUNCTION InternetEnumPerSiteCookieDecisionA IMPORT "WININET.DLL" ALIAS "InternetEnumPerSiteCookieDecisionA" ( _
'   BYREF pszSiteName AS ASCIIZ _                        ' __out LPSTR pszSiteName
' , BYREF pcSiteNameSize AS LONG _                       ' __in_out unsigned long *pcSiteNameSize
' , BYREF pdwDecision AS LONG _                          ' __out unsigned long *pdwDecision
' , BYVAL dwIndex AS LONG _                              ' __in unsigned long dwIndex
' ) AS LONG                                              ' BOOL

' Also declared in wininet.inc
'DECLARE FUNCTION InternetEnumPerSiteCookieDecisionW IMPORT "WININET.DLL" ALIAS "InternetEnumPerSiteCookieDecisionW" ( _
'   BYREF pszSiteName AS WSTRINGZ _                      ' __out LPWSTR pszSiteName
' , BYREF pcSiteNameSize AS LONG _                       ' __in_out unsigned long *pcSiteNameSize
' , BYREF pdwDecision AS LONG _                          ' __out unsigned long *pdwDecision
' , BYVAL dwIndex AS LONG _                              ' __in unsigned long dwIndex
' ) AS LONG                                              ' BOOL

%INTERNET_SUPPRESS_COOKIE_PERSIST       = &H03
%INTERNET_SUPPRESS_COOKIE_PERSIST_RESET = &H04

' Also declared in wininet.inc
'//
'// Privacy settings values and APIs
'//

'%PRIVACY_TEMPLATE_NO_COOKIES    = 0
'%PRIVACY_TEMPLATE_HIGH          = 1
'%PRIVACY_TEMPLATE_MEDIUM_HIGH   = 2
'%PRIVACY_TEMPLATE_MEDIUM        = 3
'%PRIVACY_TEMPLATE_MEDIUM_LOW    = 4
'%PRIVACY_TEMPLATE_LOW           = 5
'%PRIVACY_TEMPLATE_CUSTOM        = 100
'%PRIVACY_TEMPLATE_ADVANCED      = 101

'%PRIVACY_TEMPLATE_MAX           = %PRIVACY_TEMPLATE_LOW

'%PRIVACY_TYPE_FIRST_PARTY       = 0
'%PRIVACY_TYPE_THIRD_PARTY       = 1

'DECLARE FUNCTION PrivacySetZonePreferenceW IMPORT "WININET.DLL" ALIAS "PrivacySetZonePreferenceW" ( _
'   BYVAL dwZone AS DWORD _                              ' __in DWORD       dwZone
' , BYVAL dwType AS DWORD _                              ' __in DWORD       dwType
' , BYVAL dwTemplate AS DWORD _                          ' __in DWORD       dwTemplate
' , BYREF pszPreference AS WSTRINGZ _                    ' __in_opt LPCWSTR pszPreference
' ) AS DWORD                                             ' DWORD

'DECLARE FUNCTION PrivacyGetZonePreferenceW IMPORT "WININET.DLL" ALIAS "PrivacyGetZonePreferenceW" ( _
'   BYVAL dwZone AS DWORD _                              ' __in DWORD dwZone
' , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
' , BYREF pdwTemplate AS DWORD _                         ' __out_opt LPDWORD pdwTemplate
' , BYREF pszBuffer AS WSTRINGZ _                        ' __out_ecount_opt(*pdwBufferLength) LPWSTR pszBuffer
' , BYREF pdwBufferLength AS DWORD _                     ' __in_out_opt LPDWORD pdwBufferLength
' ) AS DWORD                                             ' DWORD

'#define _P3PGLOBAL_H_

'typedef char  P3PCHAR;
'typedef char *P3PURL;
'typedef char *P3PVERB;
'typedef const char *P3PCURL;
'typedef BSTR P3PCXSL;
'typedef void *P3PHANDLE;

%URL_LIMIT = %INTERNET_MAX_URL_LENGTH

' // Size = 20 bytes
TYPE P3PResource DWORD
   pszLocation     AS ASCIIZ PTR   ' P3PCURL
   pszVerb         AS ASCIIZ PTR   ' P3PVERB
   pszP3PHeaderRef AS ASCIIZ PTR   ' P3PCURL
   pszLinkTagRef   AS ASCIIZ PTR   ' P3PCURL
   pContainer      AS P3PResource PTR   ' struct P3PResource *
END TYPE

' // Size = 20 bytes
TYPE P3PSignal DWORD
   ' /* Window handle for PostMessage and corresponding msg value */
   hwnd     AS DWORD   ' HWND
   message  AS DWORD   ' unsigned int
   ' /* Event handle to signal */
   hEvent   AS DWORD   ' HANDLE
   ' /* Application-defined context */
   pContext AS DWORD   ' void *
   ' /* OUT: request handle */
   hRequest AS DWORD   ' P3PHANDLE
END TYPE

' enum P3PStatus
%P3PStatus_Done       = &H0
%P3PStatus_Success    = &H0

%P3PStatus_NoPolicy   = &H2
%P3PStatus_InProgress = &H3
%P3PStatus_Failed     = &H4
%P3PStatus_NotFound   = &H5
%P3PStatus_FormatErr  = &H6
%P3PStatus_Cancelled  = &H7
%P3PStatus_NotStarted = &H8
%P3PStatus_XMLError   = &H9
%P3PStatus_Expired    = &HA

%P3PStatus_Error      = &HFF

DECLARE FUNCTION MapResourceToPolicy IMPORT "WININET.DLL" ALIAS "MapResourceToPolicy" ( _
   BYREF pResource AS P3PResource _                     ' __in struct P3PResource *pResource
 , BYREF pszPolicy AS ASCIIZ _                          ' __out P3PURL pszPolicy
 , BYVAL dwSize AS DWORD _                              ' __in unsigned long dwSize
 , BYREF pSignal AS P3PSignal _                         ' __out struct P3PSignal *pSignal
 ) AS LONG                                              ' int

DECLARE FUNCTION GetP3PPolicy IMPORT "WININET.DLL" ALIAS "GetP3PPolicy" ( _
   BYREF pszPolicyURL AS ASCIIZ _                       ' __in P3PCURL pszPolicyURL
 , BYVAL hDestination AS DWORD _                        ' __in HANDLE hDestination
 , BYVAL pszXSLtransform AS WSTRING _                   ' __in P3PCXSL pszXSLtransform
 , BYREF pSignal AS P3PSignal _                         ' __out struct P3PSignal *pSignal
 ) AS LONG                                              ' int

DECLARE FUNCTION FreeP3PObject IMPORT "WININET.DLL" ALIAS "FreeP3PObject" ( _
   BYVAL hObject AS DWORD _                             ' __in P3PHANDLE hObject
 ) AS LONG                                              ' int

DECLARE FUNCTION GetP3PRequestStatus IMPORT "WININET.DLL" ALIAS "GetP3PRequestStatus" ( _
   BYVAL hObject AS DWORD _                             ' __in P3PHANDLE hObject
 ) AS LONG                                              ' int
