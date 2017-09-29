' ########################################################################################
' Microsoft Windows
' File: madcapcl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MADCAPCL_INC = 1

'#INCLUDE ONCE "time.inc"

' Not included in Windows 7 SDK, but needed here.
#IF NOT %DEF(%UNICODE_STRING_DEFINED)
%UNICODE_STRING_DEFINED = 1
' // Size = 8 bytes
TYPE UNICODE_STRING WORD
   Length        AS WORD           ' USHORT Length
   MaximumLength AS WORD           ' USHORT MaximumLength
   Buffer        AS WSTRINGZ PTR   ' PWSTR  Buffer
END TYPE
#ENDIF

%MCAST_CLIENT_ID_LEN = 17

%MCAST_API_VERSION_0 = 0
%MCAST_API_VERSION_1 = 1

%MCAST_API_CURRENT_VERSION = %MCAST_API_VERSION_1

'typedef unsigned short IP_ADDR_FAMILY;

' // Size = 16 bytes
UNION IPNG_ADDRESS BYTE
   IpAddrV4     AS DWORD   ' DWORD
   IpAddrV6(15) AS BYTE    ' BYTE [16]
END UNION


'/*++
'Description:

'    This union is used to pass both IPv4 and IPv6 style address.

'Members:

'    IpAddrV4 - IPv4 style address

'    IpAddrV6 - IPv6 style address

'--*/

' // Size = 8 bytes
TYPE MCAST_CLIENT_UID DWORD
   ClientUID       AS BYTE PTR   ' LPBYTE
   ClientUIDLength AS DWORD      ' DWORD
END TYPE

'/*++
'Description:

'    This describes the unique clientID for each request.

'Members:

'    ClientUID - Buffer containing the clientID

'    ClientUIDLength - The size of the above buffer in bytes.

'--*/


' // Size = 48 bytes
TYPE MCAST_SCOPE_CTX DWORD FILL
   ScopeID   AS IPNG_ADDRESS
   Interface AS IPNG_ADDRESS
   ServerID  AS IPNG_ADDRESS
END TYPE

'/*++
'Description:

'    This defines the handle of the scope from which the address
'    is to be allocated/renewed/released.

'Members:

'    ScopeID - Scope ID is essentially first ip of the scope

'    Interface - Interface on which this scope was found

'    ServerID - IPAddress of the MADCAP server

'--*/


' // Size = 76 bytes
TYPE MCAST_SCOPE_ENTRY DWORD FILL
   ScopeCtx  AS MCAST_SCOPE_CTX
   LastAddr  AS IPNG_ADDRESS
   TTL       AS DWORD             ' DWORD
   ScopeDesc AS UNICODE_STRING
END TYPE

'/*++
'Description:

'    This structure contains all the info pertaining to a given multicast
'    scope.

'Members:

'    ScopeCtx - the handle for this scope

'    LastAddr - last addr of the scope

'    TTL - TTL value of this scope.

'    ScopeDesc - user friendly description of scope

'--*/

' // Size = 40 bytes
TYPE MCAST_LEASE_REQUEST DWORD FILL
   LeaseStartTime    AS LONG           ' LONG
   MaxLeaseStartTime AS LONG           ' LONG
   LeaseDuration     AS DWORD          ' DWORD
   MinLeaseDuration  AS DWORD          ' DWORD
   ServerAddress     AS IPNG_ADDRESS
   MinAddrCount      AS WORD           ' WORD
   AddrCount         AS WORD           ' WORD
   pAddrBuf          AS BYTE PTR       ' PBYTE
END TYPE

'/*++
'Description:

'    This structure is used to describe the request parameters for
'    requesting/renewing/releasing multicast addresses

'Members:

'    LeaseStartTime - desired start time of the lease, pass 0 if desired start time
'                     is current time. The desired time is specified in the number of seconds elapsed
'                     since midnight (00:00:00), January 1, 1970, coordinated universal time.

'    MaxLeaseStartTime - the maximum start time that the client is willing to accept.
'                        Where time is the number of seconds elapsed since midnight (00:00:00),
'                        January 1, 1970, coordinated universal time.

'    LeaseDuration - desired lease time for the request, pass 0 if default
'                    lease time is requested.

'    MinLeaseDuration - the minimum lease time that the client is willing
'                       to accept

'    ServerAddress - server's ip address where this lease whas renewed/requested.
'                    pass 0 if unknown (e.g in McastRequestAddress)

'    MinAddrCount - minimum number of addresses that the client is willing
'                   to accept

'    AddrCount - the desired number of addresses requested/allocated/renewed.
'                This also specifies the size of the array specified by Addr.

'    pAddrBuf - buffer containing specific addresses being requested/renewed/released.
'                For IPv4 it is a pointer to 4 byte addresses and for IPv6 it
'                points to 16 byte chunks. Pass NULL if no specific addresses
'                are requested.

'Remarks:

'    In MCAST_API_VERSION_1 version, the MaxLeaseStartTime, MinLeaseDuration and
'    MinAddrCount are ignored by the API implementation. However, the clients should
'    set appropriate desired values for these members so as when the OS update brings
'    new implementation of the APIs then the clients can take advantage of it.

'--*/

' // Size = 32 bytes
TYPE MCAST_LEASE_RESPONSE DWORD FILL
   LeaseStartTime AS LONG               ' LONG
   LeaseEndTime   AS LONG               ' LONG
   ServerAddress  AS IPNG_ADDRESS
   AddrCount      AS WORD               ' WORD
   pAddrBuf       AS BYTE PTR           ' PBYTE
END TYPE

'/*++

'Description:

'    This structure is used to pass the response of the operation of
'    requesting/renewing/releasing multicast addresses.

'Members:

'    LeaseStartTime - start time of the lease in number of seconds elapsed since
'                     midnight (00:00:00), January 1, 1970, coordinated universal time.

'    LeaseEndTime - time when lease ends, where time is the number of seconds elapsed
'                   since midnight (00:00:00), January 1, 1970, coordinated universal time.

'    ServerAddress - server's ip address where this lease is renewed/requested.

'    AddrCount - number of addresses requested/allocated/renewed.
'                This also specifies the size of the array specified by Addr.

'    Addr - buffer containing addresses being requested/renewed/released. For IPv4
'            it is a pointer to 4 byte addresses and for IPv6 it points to 16 byte chunks

'--*/

DECLARE FUNCTION McastApiStartup IMPORT "Dhcpcsvc.dll" ALIAS "McastApiStartup" ( _
   BYVAL Version AS DWORD _                             ' __inout PDWORD Version
 ) AS DWORD                                             ' DWORD

DECLARE SUB McastApiCleanup IMPORT "Dhcpcsvc.dll" ALIAS "McastApiCleanup" ()

DECLARE FUNCTION McastGenUID IMPORT "Dhcpcsvc.dll" ALIAS "McastGenUID" ( _
   BYREF pRequestID AS MCAST_CLIENT_UID _               ' __inout LPMCAST_CLIENT_UID pRequestID
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION McastEnumerateScopes IMPORT "Dhcpcsvc.dll" ALIAS "McastEnumerateScopes" ( _
   BYREF AddrFamily AS WORD _                           ' __in IP_ADDR_FAMILY AddrFamily
 , BYVAL ReQuery AS LONG _                              ' __in BOOL ReQuery
 , BYREF pScopeList AS MCAST_SCOPE_ENTRY _              ' __inout PMCAST_SCOPE_ENTRY pScopeList
 , BYREF pScopeLen AS DWORD _                           ' __inout PDWORD pScopeLen
 , BYREF pScopeCount AS DWORD _                         ' __out PDWORD pScopeCount
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION McastRequestAddress IMPORT "Dhcpcsvc.dll" ALIAS "McastRequestAddress" ( _
   BYREF AddrFamily AS WORD _                           ' __in IP_ADDR_FAMILY AddrFamily
 , BYREF pRequestID AS MCAST_CLIENT_UID _               ' __in LPMCAST_CLIENT_UID pRequestID
 , BYREF pScopeCtx AS MCAST_SCOPE_CTX _                 ' __in PMCAST_SCOPE_CTX pScopeCtx
 , BYREF pAddrRequest AS MCAST_LEASE_REQUEST _          ' __in PMCAST_LEASE_REQUEST pAddrRequest
 , BYREF pAddrResponse AS MCAST_LEASE_RESPONSE _        ' __inout PMCAST_LEASE_RESPONSE pAddrResponse
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION McastRenewAddress IMPORT "Dhcpcsvc.dll" ALIAS "McastRenewAddress" ( _
   BYREF AddrFamily AS WORD _                           ' __in IP_ADDR_FAMILY AddrFamily
 , BYREF pRequestID AS MCAST_CLIENT_UID _               ' __in LPMCAST_CLIENT_UID pRequestID
 , BYREF pRenewRequest AS MCAST_LEASE_REQUEST _         ' __in PMCAST_LEASE_REQUEST pRenewRequest
 , BYREF pRenewResponse AS MCAST_LEASE_RESPONSE _       ' __inout PMCAST_LEASE_RESPONSE pRenewResponse
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION McastReleaseAddress IMPORT "Dhcpcsvc.dll" ALIAS "McastReleaseAddress" ( _
   BYREF AddrFamily AS WORD _                           ' __in IP_ADDR_FAMILY AddrFamily
 , BYREF pRequestID AS MCAST_CLIENT_UID _               ' __in LPMCAST_CLIENT_UID pRequestID
 , BYREF pReleaseRequest AS MCAST_LEASE_REQUEST _       ' __in PMCAST_LEASE_REQUEST pReleaseRequest
 ) AS DWORD                                             ' DWORD
