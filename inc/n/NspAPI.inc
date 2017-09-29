' ########################################################################################
' Microsoft Windows
' File: NspAPI.inc
' Contents: Name Space Provider API prototypes and manifests
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NSPAPI_INC = 1

#INCLUDE ONCE "winsock2.inc"

'#ifndef _tagBLOB_DEFINED
'#define _tagBLOB_DEFINED
'#define _BLOB_DEFINED
'#define _LPBLOB_DEFINED
'typedef struct _BLOB {
'    ULONG cbSize ;
'#ifdef MIDL_PASS
'    [size_is(cbSize)] BYTE *pBlobData;
'#else  // MIDL_PASS
'    BYTE *pBlobData ;
'#endif // MIDL_PASS
'} BLOB, *LPBLOB ;
'#endif

'#ifndef GUID_DEFINED
'#define GUID_DEFINED
'typedef struct _GUID
'{
'    unsigned long  Data1;
'    unsigned short Data2;
'    unsigned short Data3;
'    unsigned char  Data4[8];
'} GUID;
'#endif /* GUID_DEFINED */

'#ifndef __LPGUID_DEFINED__
'#define __LPGUID_DEFINED__
'typedef GUID *LPGUID;
'#endif


'//
'// Service categories
'//
%SERVICE_RESOURCE            = &H00000001???
%SERVICE_SERVICE             = &H00000002???
%SERVICE_LOCAL               = &H00000004???

'//
'// Operation used when calling SetService()
'//
%SERVICE_REGISTER            = &H00000001???
%SERVICE_DEREGISTER          = &H00000002???
%SERVICE_FLUSH               = &H00000003???
%SERVICE_ADD_TYPE            = &H00000004???
%SERVICE_DELETE_TYPE         = &H00000005???

'//
'// Flags that affect the operations above
'//
%SERVICE_FLAG_DEFER          = &H00000001???
%SERVICE_FLAG_HARD           = &H00000002???

'//
'// Used as input to GetService() for setting the dwProps parameter
'//
%PROP_COMMENT                = &H00000001???
%PROP_LOCALE                 = &H00000002???
%PROP_DISPLAY_HINT           = &H00000004???
%PROP_VERSION                = &H00000008???
%PROP_START_TIME             = &H00000010???
%PROP_MACHINE                = &H00000020???
%PROP_ADDRESSES              = &H00000100???
%PROP_SD                     = &H00000200???
%PROP_ALL                    = &H80000000???

'//
'// Flags that describe attributes of Service Addresses
'//

%SERVICE_ADDRESS_FLAG_RPC_CN = &H00000001???
%SERVICE_ADDRESS_FLAG_RPC_DG = &H00000002???
%SERVICE_ADDRESS_FLAG_RPC_NB = &H00000004???

'//
'// Name Spaces
'//

%NS_DEFAULT                  = 0

%NS_SAP                      = 1
%NS_NDS                      = 2
%NS_PEER_BROWSE              = 3

%NS_TCPIP_LOCAL              = 10
%NS_TCPIP_HOSTS              = 11
%NS_DNS                      = 12
%NS_NETBT                    = 13
%NS_WINS                     = 14

%NS_NBP                      = 20

%NS_MS                       = 30
%NS_STDA                     = 31
%NS_NTDS                     = 32

%NS_X500                     = 40
%NS_NIS                      = 41

%NS_VNS                      = 50

'//
'// Name space attributes.
'//
%NSTYPE_HIERARCHICAL         = &H00000001???
%NSTYPE_DYNAMIC              = &H00000002???
%NSTYPE_ENUMERABLE           = &H00000004???
%NSTYPE_WORKGROUP            = &H00000008???

'//
'// Transport attributes.
'//
%XP_CONNECTIONLESS           = &H00000001???
%XP_GUARANTEED_DELIVERY      = &H00000002???
%XP_GUARANTEED_ORDER         = &H00000004???
%XP_MESSAGE_ORIENTED         = &H00000008???
%XP_PSEUDO_STREAM            = &H00000010???
%XP_GRACEFUL_CLOSE           = &H00000020???
%XP_EXPEDITED_DATA           = &H00000040???
%XP_CONNECT_DATA             = &H00000080???
%XP_DISCONNECT_DATA          = &H00000100???
%XP_SUPPORTS_BROADCAST       = &H00000200???
%XP_SUPPORTS_MULTICAST       = &H00000400???
%XP_BANDWIDTH_ALLOCATION     = &H00000800???
%XP_FRAGMENTATION            = &H00001000???
%XP_ENCRYPTS                 = &H00002000???

'//
'// Resolution flags for GetAddressByName().
'//
%RES_SOFT_SEARCH             = &H00000001???
%RES_FIND_MULTIPLE           = &H00000002???
%RES_SERVICE                 = &H00000004???

'//
'// Well known value names for Service Types
'//

$SERVICE_TYPE_VALUE_SAPIDA       = "SapId"
$$SERVICE_TYPE_VALUE_SAPIDW      = "SapId"$$
#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_VALUE_SAPID = SERVICE_TYPE_VALUE_SAPIDW
#ELSE
   MACRO SERVICE_TYPE_VALUE_SAPID = SERVICE_TYPE_VALUE_SAPIDA
#ENDIF

$SERVICE_TYPE_VALUE_CONNA        = "ConnectionOriented"
$$SERVICE_TYPE_VALUE_CONNW       = "ConnectionOriented"$$
#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_VALUE_CONN = SERVICE_TYPE_VALUE_CONNW
#ELSE
   MACRO SERVICE_TYPE_VALUE_CONN = SERVICE_TYPE_VALUE_CONNA
#ENDIF

$SERVICE_TYPE_VALUE_TCPPORTA     = "TcpPort"
$$SERVICE_TYPE_VALUE_TCPPORTW    = "TcpPort"$$
#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_VALUE_TCPPORT = SERVICE_TYPE_VALUE_TCPPORTW
#ELSE
   MACRO SERVICE_TYPE_VALUE_TCPPORT = SERVICE_TYPE_VALUE_TCPPORTA
#ENDIF

$SERVICE_TYPE_VALUE_UDPPORTA     = "UdpPort"
$$SERVICE_TYPE_VALUE_UDPPORTW    = "UdpPort"$$
#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_VALUE_UDPPORT = SERVICE_TYPE_VALUE_UDPPORTW
#ELSE
   MACRO SERVICE_TYPE_VALUE_UDPPORT = SERVICE_TYPE_VALUE_UDPPORTA
#ENDIF

'//
'// status flags returned by SetService
'//
%SET_SERVICE_PARTIAL_SUCCESS  = &H00000001???

'//
'// Name Space Information
'//
' // Size = 12 bytes
TYPE NS_INFOA DWORD
   dwNameSpace      AS DWORD        ' DWORD
   dwNameSpaceFlags AS DWORD        ' DWORD
   lpNameSpace      AS ASCIIZ PTR   ' LPSTR
END TYPE

'//
'// Name Space Information
'//

' // Size = 12 bytes
TYPE NS_INFOW DWORD
   dwNameSpace      AS DWORD          ' DWORD
   dwNameSpaceFlags AS DWORD          ' DWORD
   lpNameSpace      AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO NS_INFO = NS_INFOW
#ELSE
   MACRO NS_INFO = NS_INFOA
#ENDIF

'//
'// Service Type Values. The structures are used to define named Service
'// Type specific values. This structure is self relative and has no pointers.
'//

' // Size = 20 bytes
TYPE SERVICE_TYPE_VALUE DWORD
   dwNameSpace       AS DWORD   ' DWORD
   dwValueType       AS DWORD   ' DWORD
   dwValueSize       AS DWORD   ' DWORD
   dwValueNameOffset AS DWORD   ' DWORD
   dwValueOffset     AS DWORD   ' DWORD
END TYPE

'//
'// An absolute version of above. This structure does contain pointers.
'//

' // Size = 20 bytes
TYPE SERVICE_TYPE_VALUE_ABSA DWORD
   dwNameSpace AS DWORD        ' DWORD
   dwValueType AS DWORD        ' DWORD
   dwValueSize AS DWORD        ' DWORD
   lpValueName AS ASCIIZ PTR   ' LPSTR
   lpValue     AS DWORD        ' PVOID
END TYPE

'//
'// An absolute version of above. This structure does contain pointers.
'//

' // Size = 20 bytes
TYPE SERVICE_TYPE_VALUE_ABSW DWORD
   dwNameSpace AS DWORD          ' DWORD
   dwValueType AS DWORD          ' DWORD
   dwValueSize AS DWORD          ' DWORD
   lpValueName AS WSTRINGZ PTR   ' LPWSTR
   lpValue     AS DWORD          ' PVOID
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_VALUE_ABS = SERVICE_TYPE_VALUE_ABSW
#ELSE
   MACRO SERVICE_TYPE_VALUE_ABS = SERVICE_TYPE_VALUE_ABSA
#ENDIF

'//
'// Service Type Information. Contains the name of the Service Type and
'// and an array of SERVICE_NS_TYPE_VALUE structures. This structure is self
'// relative and has no pointers in it.
'//

' // Size = 28 bytes
TYPE SERVICE_TYPE_INFO DWORD
   dwTypeNameOffset AS DWORD                ' DWORD
   dwValueCount     AS DWORD                ' DWORD
   Values(0)        AS SERVICE_TYPE_VALUE   ' SERVICE_TYPE_VALUE[1]
END TYPE

' // Size = 28 bytes
TYPE SERVICE_TYPE_INFO_ABSA DWORD
   lpTypeName   AS ASCIIZ PTR                ' LPSTR
   dwValueCount AS DWORD                     ' DWORD
   Values(0)    AS SERVICE_TYPE_VALUE_ABSA   ' SERVICE_TYPE_VALUE_ABSA[1]
END TYPE

' // Size = 28 bytes
TYPE SERVICE_TYPE_INFO_ABSW DWORD
   lpTypeName   AS WSTRINGZ PTR              ' LPWSTR
   dwValueCount AS DWORD                     ' DWORD
   Values(0)    AS SERVICE_TYPE_VALUE_ABSW   ' SERVICE_TYPE_VALUE_ABSW[1]
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_TYPE_INFO_ABS = SERVICE_TYPE_INFO_ABSW
#ELSE
   MACRO SERVICE_TYPE_INFO_ABS = SERVICE_TYPE_INFO_ABSA
#ENDIF

'//
'// A Single Address definition.
'//

' // Size = 24 bytes
TYPE SERVICE_ADDRESS DWORD
   dwAddressType     AS DWORD      ' DWORD
   dwAddressFlags    AS DWORD      ' DWORD
   dwAddressLength   AS DWORD      ' DWORD
   dwPrincipalLength AS DWORD      ' DWORD
   lpAddress         AS BYTE PTR   ' BYTE *
   lpPrincipal       AS BYTE PTR   ' BYTE *
END TYPE

'//
'// Addresses used by the service. Contains array of SERVICE_ADDRESS.
'//

' // Size = 28 bytes
TYPE SERVICE_ADDRESSES DWORD
   dwAddressCount AS DWORD             ' DWORD
   Addresses(0)   AS SERVICE_ADDRESS   ' SERVICE_ADDRESS[1]
END TYPE

'//
'// Service Information.
'//

' // Size = 44 bytes
TYPE SERVICE_INFOA DWORD
   lpServiceType       AS GUID PTR                ' LPGUID
   lpServiceName       AS ASCIIZ PTR              ' LPSTR
   lpComment           AS ASCIIZ PTR              ' LPSTR
   lpLocale            AS ASCIIZ PTR              ' LPSTR
   dwDisplayHint       AS DWORD                   ' DWORD
   dwVersion           AS DWORD                   ' DWORD
   dwTime              AS DWORD                   ' DWORD
   lpMachineName       AS ASCIIZ PTR              ' LPSTR
   lpServiceAddress    AS SERVICE_ADDRESSES PTR   ' LPSERVICE_ADDRESSES
   ServiceSpecificInfo AS BLOB
END TYPE

'//
'// Service Information.
'//

' // Size = 44 bytes
TYPE SERVICE_INFOW DWORD
   lpServiceType       AS GUID PTR                ' LPGUID
   lpServiceName       AS WSTRINGZ PTR            ' LPWSTR
   lpComment           AS WSTRINGZ PTR            ' LPWSTR
   lpLocale            AS WSTRINGZ PTR            ' LPWSTR
   dwDisplayHint       AS DWORD                   ' DWORD
   dwVersion           AS DWORD                   ' DWORD
   dwTime              AS DWORD                   ' DWORD
   lpMachineName       AS WSTRINGZ PTR            ' LPWSTR
   lpServiceAddress    AS SERVICE_ADDRESSES PTR   ' LPSERVICE_ADDRESSES
   ServiceSpecificInfo AS BLOB
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_INFO = SERVICE_INFOW
#ELSE
   MACRO SERVICE_INFO = SERVICE_INFOA
#ENDIF

'//
'// Name Space & Service Information
'//

' // Size = 48 bytes
TYPE NS_SERVICE_INFOA DWORD
   dwNameSpace AS DWORD   ' DWORD
   ServiceInfo AS SERVICE_INFOA
END TYPE

'//
'// Name Space & Service Information
'//

' // Size = 48 bytes
TYPE NS_SERVICE_INFOW DWORD
   dwNameSpace AS DWORD   ' DWORD
   ServiceInfo AS SERVICE_INFOW
END TYPE

#IF %DEF(%UNICODE)
   MACRO NS_SERVICE_INFO = NS_SERVICE_INFOW
#ELSE
   MACRO NS_SERVICE_INFO = NS_SERVICE_INFOA
#ENDIF


'#IF NOT %DEF(%CSADDR_DEFINED)
'    %CSADDR_DEFINED = 1

''/*
'' * SockAddr Information
'' */

'' // Size = 8 bytes
'TYPE SOCKET_ADDRESS DWORD
'   lpSocaddr       AS SOCKADDR PTR   ' __field_bcount(iSockaddrLength) LPSOCKADDR lpSockaddr
'   iSockaddrLength AS LONG           ' INT iSockaddrLength
'END TYPE

''/*
'' * CSAddr Information
'' */

'' // Size = 24 bytes
'TYPE CSADDR_INFO DWORD
'   LocalAddr   AS SOCKET_ADDRESS   ' SOCKET_ADDRESS
'   RemoteAddr  AS SOCKET_ADDRESS   ' SOCKET_ADDRESS
'   iSocketType AS LONG             ' INT
'   iProtocol   AS LONG             ' INT
'END TYPE

'#ENDIF   ' /* __CSADDR_DEFINED__ */

'//
'// Protocol Information
'//

' // Size = 32 bytes
TYPE PROTOCOL_INFOA DWORD
   dwServiceFlags AS DWORD        ' DWORD
   iAddressFamily AS LONG         ' INT
   iMaxSockAddr   AS LONG         ' INT
   iMinSockAddr   AS LONG         ' INT
   iSocketType    AS LONG         ' INT
   iProtocol      AS LONG         ' INT
   dwMessageSize  AS DWORD        ' DWORD
   lpProtocol     AS ASCIIZ PTR   ' LPSTR
END TYPE

'//
'// Protocol Information
'//

' // Size = 32 bytes
TYPE PROTOCOL_INFOW DWORD
   dwServiceFlags AS DWORD          ' DWORD
   iAddressFamily AS LONG           ' INT
   iMaxSockAddr   AS LONG           ' INT
   iMinSockAddr   AS LONG           ' INT
   iSocketType    AS LONG           ' INT
   iProtocol      AS LONG           ' INT
   dwMessageSize  AS DWORD          ' DWORD
   lpProtocol     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PROTOCOL_INFO = PROTOCOL_INFOW
#ELSE
   MACRO PROTOCOL_INFO = PROTOCOL_INFOA
#ENDIF

'//
'// NETRESOURCE2 Structure
'//
' // Size = 64 bytes
TYPE NETRESOURCE2A DWORD
   dwScope       AS DWORD        ' DWORD
   dwType        AS DWORD        ' DWORD
   dwUsage       AS DWORD        ' DWORD
   dwDisplayType AS DWORD        ' DWORD
   lpLocalName   AS ASCIIZ PTR   ' LPSTR
   lpRemoteName  AS ASCIIZ PTR   ' LPSTR
   lpComment     AS ASCIIZ PTR   ' LPSTR
   ns_info       AS NS_INFO      ' NS_INFO
   ServiceType   AS GUID         ' GUID
   dwProtocols   AS DWORD        ' DWORD
   lpiProtocols  AS LONG PTR     ' LPINT
END TYPE

'//
'// NETRESOURCE2 Structure
'//

' // Size = 64 bytes
TYPE NETRESOURCE2W DWORD
   dwScope       AS DWORD          ' DWORD
   dwType        AS DWORD          ' DWORD
   dwUsage       AS DWORD          ' DWORD
   dwDisplayType AS DWORD          ' DWORD
   lpLocalName   AS WSTRINGZ PTR   ' LPWSTR
   lpRemoteName  AS WSTRINGZ PTR   ' LPWSTR
   lpComment     AS WSTRINGZ PTR   ' LPWSTR
   ns_info       AS NS_INFO        ' NS_INFO
   ServiceType   AS GUID           ' GUID
   dwProtocols   AS DWORD          ' DWORD
   lpiProtocols  AS LONG PTR       ' LPINT
END TYPE

#IF %DEF(%UNICODE)
   MACRO NETRESOURCE2 = NETRESOURCE2W
#ELSE
   MACRO NETRESOURCE2 = NETRESOURCE2A
#ENDIF

'typedef  DWORD (* LPFN_NSPAPI) (VOID ) ;

'//
'// Structures for using the service routines asynchronously.
'//
'typedef
'VOID
'(*LPSERVICE_CALLBACK_PROC) (
'    __in LPARAM lParam,
'    __in HANDLE hAsyncTaskHandle
'    );

'SUB SERVICE_CALLBACK_PROC (BYVAL lParam AS LONG, BYVAL hAsyncTaskHandle AS DWORD)

' // Size = 12 bytes
TYPE SERVICE_ASYNC_INFO DWORD
   lpServiceCallbackProc AS DWORD   ' LPSERVICE_CALLBACK_PROC
   lParam                AS LONG    ' LPARAM
   hAsyncTaskHandle      AS DWORD   ' HANDLE
END TYPE

'//
'// Public NSP API prototypes.
'//

DECLARE FUNCTION EnumProtocolsA IMPORT "Mswsock.dll" ALIAS "EnumProtocolsA" ( _
   BYVAL lpiProtocols AS DWORD _                        ' __in_opt LPINT lpiProtocols
 , BYREF lpProtocolBuffer AS ANY _                      ' __out LPVOID lpProtocolBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' INT

'//
'// Public NSP API prototypes.
'//

DECLARE FUNCTION EnumProtocolsW IMPORT "Mswsock.dll" ALIAS "EnumProtocolsW" ( _
   BYVAL lpiProtocols AS DWORD _                        ' __in_opt LPINT lpiProtocols
 , BYREF lpProtocolBuffer AS ANY _                      ' __out LPVOID lpProtocolBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO EnumProtocols = EnumProtocolsW
#ELSE
   MACRO EnumProtocols = EnumProtocolsA
#ENDIF

DECLARE FUNCTION GetAddressByNameA IMPORT "Mswsock.dll" ALIAS "GetAddressByNameA" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYREF lpServiceType AS GUID _                        ' __in LPGUID lpServiceType
 , BYREF lpServiceName AS ASCIIZ _                      ' __in_opt LPSTR lpServiceName
 , BYVAL lpiProtocols AS DWORD _                        ' __in_opt LPINT lpiProtocols
 , BYVAL dwResolution AS DWORD _                        ' __in DWORD dwResolution
 , BYREF lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 , BYREF lpCsaddrBuffer AS ANY _                        ' __out LPVOID lpCsaddrBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYVAL lpAliasBuffer AS DWORD _                       ' __inout LPSTR lpAliasBuffer
 , BYREF lpdwAliasBufferLength AS DWORD _               ' __inout LPDWORD lpdwAliasBufferLength
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetAddressByNameW IMPORT "Mswsock.dll" ALIAS "GetAddressByNameW" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYREF lpServiceType AS GUID _                        ' __in LPGUID lpServiceType
 , BYREF lpServiceName AS WSTRINGZ _                    ' __in_opt LPWSTR lpServiceName
 , BYVAL lpiProtocols AS DWORD _                        ' __in_opt LPINT lpiProtocols
 , BYVAL dwResolution AS DWORD _                        ' __in DWORD dwResolution
 , BYREF lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 , BYREF lpCsaddrBuffer AS ANY _                        ' __out LPVOID lpCsaddrBuffer
 , BYREF lpdwBufferLength AS DWORD _                    ' __inout LPDWORD lpdwBufferLength
 , BYREF lpAliasBuffer AS WSTRINGZ _                    ' __inout LPWSTR lpAliasBuffer
 , BYREF lpdwAliasBufferLength AS DWORD _               ' __inout LPDWORD lpdwAliasBufferLength
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO GetAddressByName = GetAddressByNameW
#ELSE
   MACRO GetAddressByName = GetAddressByNameA
#ENDIF

DECLARE FUNCTION GetTypeByNameA IMPORT "Mswsock.dll" ALIAS "GetTypeByNameA" ( _
   BYREF lpServiceName AS ASCIIZ _                      ' __in    LPSTR  lpServiceName
 , BYREF lpServiceType AS GUID _                        ' __inout LPGUID lpServiceType
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetTypeByNameW IMPORT "Mswsock.dll" ALIAS "GetTypeByNameW" ( _
   BYREF lpServiceName AS WSTRINGZ  _                   ' __in    LPWSTR lpServiceName
 , BYREF lpServiceType AS GUID _                        ' __inout LPGUID lpServiceType
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO GetTypeByName = GetTypeByNameW
#ELSE
   MACRO GetTypeByName = GetTypeByNameA
#ENDIF

DECLARE FUNCTION GetNameByTypeA IMPORT "Mswsock.dll" ALIAS "GetNameByTypeA" ( _
   BYREF lpServiceType AS GUID _                        ' __inout LPGUID lpServiceType
 , BYREF lpServiceName AS ASCIIZ _                      ' __out LPSTR lpServiceName
 , BYVAL dwNameLength AS DWORD _                        ' __in DWORD dwNameLength
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetNameByTypeW IMPORT "Mswsock.dll" ALIAS "GetNameByTypeW" ( _
   BYREF lpServiceType AS GUID _                        ' __inout LPGUID lpServiceType
 , BYREF lpServiceName AS WSTRINGZ _                    ' __out LPWSTR lpServiceName
 , BYVAL dwNameLength AS DWORD _                        ' __in DWORD dwNameLength
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO GetNameByType = GetNameByTypeW
#ELSE
   MACRO GetNameByType = GetNameByTypeA
#ENDIF

DECLARE FUNCTION SetServiceA IMPORT "Mswsock.dll" ALIAS "SetServiceA" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYVAL dwOperation AS DWORD _                         ' __in DWORD dwOperation
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpServiceInfo AS SERVICE_INFOA _               ' __in LPSERVICE_INFOA lpServiceInfo
 , BYVAL lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 , BYREF lpdwStatusFlags AS DWORD _                     ' __out LPDWORD lpdwStatusFlags
 ) AS LONG                                              ' INT

DECLARE FUNCTION SetServiceW IMPORT "Mswsock.dll" ALIAS "SetServiceW" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYVAL dwOperation AS DWORD _                         ' __in DWORD dwOperation
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpServiceInfo AS SERVICE_INFOW _               ' __in LPSERVICE_INFOW lpServiceInfo
 , BYVAL lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 , BYREF lpdwStatusFlags AS DWORD _                     ' __out LPDWORD lpdwStatusFlags
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO SetService = SetServiceW
#ELSE
   MACRO SetService = SetServiceA
#ENDIF

DECLARE FUNCTION GetServiceA IMPORT "Mswsock.dll" ALIAS "GetServiceA" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYREF lpGuid AS GUID _                               ' __in LPGUID lpGuid
 , BYREF lpServiceName AS ASCIIZ _                      ' __in LPSTR lpServiceName
 , BYVAL dwProperties AS DWORD _                        ' __in DWORD dwProperties
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwBufferSize AS DWORD _                      ' __inout LPDWORD lpdwBufferSize
 , BYREF lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetServiceW IMPORT "Mswsock.dll" ALIAS "GetServiceW" ( _
   BYVAL dwNameSpace AS DWORD _                         ' __in DWORD dwNameSpace
 , BYREF lpGuid AS GUID _                               ' __in LPGUID lpGuid
 , BYREF lpServiceName AS WSTRINGZ _                    ' __in LPWSTR lpServiceName
 , BYVAL dwProperties AS DWORD _                        ' __in DWORD dwProperties
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpdwBufferSize AS DWORD _                      ' __inout LPDWORD lpdwBufferSize
 , BYREF lpServiceAsyncInfo AS SERVICE_ASYNC_INFO _     ' __in_opt LPSERVICE_ASYNC_INFO lpServiceAsyncInfo
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO GetService = GetServiceW
#ELSE
   MACRO GetService = GetServiceA
#ENDIF
