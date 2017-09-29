' ########################################################################################
' Microsoft Windows
' File: p2p.inc
' Contents: Win32 APIs and structures for the Microsoft Peer To Peer infrastructure.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%P2P_INC = 1

'//----------------------------------------------------------------------------
'//
'//  If defined, the following flags inhibit definition of the indicated items.
'//
'//  NO_P2P_GROUP    - no Peer-to-Peer Grouping
'//  NO_P2P_GRAPH    - no Peer-to-Peer Graphing
'//  NO_P2P_IDENTITY - no Peer-to-Peer Identity manager
'//  NO_P2P_PNRP     - no Peer-to-Peer Peer Name Resolution Protocol
'//  NO_P2P_COLLABORATION - no Peer-to-Peer Collaboration Infrastructure
'//
'//----------------------------------------------------------------------------

'#include <specstrings.h>
'#include <winsock2.h>
'#include <pnrpns.h>
'#include <ws2tcpip.h>  // for sockaddrin_6

#INCLUDE ONCE "winsock2.inc"
#INCLUDE ONCE "pnrpns.inc"
#INCLUDE ONCE "ws2tcpip.inc"   ' // for sockaddrin_6

'#if NTDDI_VERSION < NTDDI_VISTA

'#ifndef NO_P2P_PNRP
'#define NO_P2P_PNRP //P2P PNRP is not available prior to NTDDI_VISTA
'#endif // NO_P2P_PNRP

'#ifndef NO_P2P_COLLABORATION
'#define NO_P2P_COLLABORATION //P2P COLLABORATION is not available prior to NTDDI_VISTA
'#endif // NO_P2P_COLLABORATION

'#endif // NTDDI_VERSION < NTDDI_VISTA


'//////////////////////////////////////////////////////////////////////////////
'// Constants

' enum PEER_RECORD_CHANGE_TYPE
%PEER_RECORD_ADDED                           = 1
%PEER_RECORD_UPDATED                         = 2
%PEER_RECORD_DELETED                         = 3
%PEER_RECORD_EXPIRED                         = 4

' enum PEER_CONNECTION_STATUS
%PEER_CONNECTED                              = 1
%PEER_DISCONNECTED                           = 2
%PEER_CONNECTION_FAILED                      = 3

' enum PEER_CONNECTION_FLAGS
%PEER_CONNECTION_NEIGHBOR                    = &H0001???
%PEER_CONNECTION_DIRECT                      = &H0002???

' enum PEER_RECORD_FLAGS
%PEER_RECORD_FLAG_AUTOREFRESH                = &H0001???
%PEER_RECORD_FLAG_DELETED                    = &H0002???

'////////////////////////////////////////////////////////////////////////////////////
'// Types

'typedef
'void *HPEEREVENT;
'typedef HPEEREVENT * PHPEEREVENT;

'typedef
'void *HPEERENUM;
'typedef HPEERENUM * PHPEERENUM;

' // Size = 4 bytes
TYPE PEER_VERSION_DATA WORD
   wVersion        AS WORD   ' WORD
   wHighestVersion AS WORD   ' WORD
END TYPE

' // Size = 8 bytes
TYPE PEER_DATA
   cbData AS DWORD      ' ULONG
   pbData AS BYTE PTR   ' PBYTE
END TYPE

' // Size = 96 bytes
TYPE PEER_RECORD DWORD
   dwSize          AS DWORD          ' DWORD
   type            AS GUID           ' GUID
   id              AS GUID           ' GUID
   dwVersion       AS DWORD          ' DWORD
   dwFlags         AS DWORD          ' DWORD
   pwzCreatorId    AS WSTRINGZ PTR   ' PWSTR
   pwzModifiedById AS WSTRINGZ PTR   ' PWSTR
   pwzAttributes   AS WSTRINGZ PTR   ' PWSTR
   ftCreation      AS FILETIME       ' FILETIME
   ftExpiration    AS FILETIME       ' FILETIME
   ftLastModified  AS FILETIME       ' FILETIME
   securityData    AS PEER_DATA      ' PEER_DATA
   data            AS PEER_DATA      ' PEER_DATA
END TYPE

' // Size = 32 bytes
TYPE PEER_ADDRESS DWORD
   dwSize AS DWORD          ' DWORD
   sin6   AS SOCKADDR_IN6   ' SOCKADDR_IN6
END TYPE

' // Size = 64 bytes
TYPE PEER_CONNECTION_INFO QWORD FILL   ' Must be 8 byte aligned
   dwSize          AS DWORD          ' DWORD
   dwFlags         AS DWORD          ' DWORD
   ullConnectionId AS QUAD           ' ULONGLONG
   ullNodeId       AS QUAD           ' ULONGLONG
   pwzPeerId       AS WSTRINGZ PTR   ' PWSTR
   address         AS PEER_ADDRESS   ' PEER_ADDRESS
END TYPE

' // Size = 40 bytes
TYPE PEER_EVENT_INCOMING_DATA QWORD FILL  ' Must be 8 byte aligned
   dwSize          AS DWORD       ' DWORD
   ullConnectionId AS QUAD        ' ULONGLONG
   type            AS GUID        ' GUID
   data            AS PEER_DATA   ' PEER_DATA
END TYPE

' // Size = 40 bytes
TYPE PEER_EVENT_RECORD_CHANGE_DATA DWORD
   dwSize     AS DWORD   ' DWORD
   changeType AS LONG    ' PEER_RECORD_CHANGE_TYPE enum
   recordId   AS GUID    ' GUID
   recordType AS GUID    ' GUID
END TYPE

' // Size = 40 bytes
TYPE PEER_EVENT_CONNECTION_CHANGE_DATA   ' Must be 8 byte aligned
   dwSize                   AS DWORD   ' DWORD
   status                   AS LONG    ' PEER_CONNECTION_STATUS
   ullConnectionId          AS QUAD    ' ULONGLONG
   ullNodeId                AS QUAD    ' ULONGLONG
'#if NTDDI_VERSION >= NTDDI_VISTA
#IF %WINVER >= &H0600
   ullNextConnectionId      AS QUAD    ' ULONGLONG
   hrConnectionFailedReason AS LONG    ' HRESULT
   alignment__              AS DWORD   ' // To keep 8 byte alignment
#ENDIF
'#endif
END TYPE

' // Size = 20 bytes
TYPE PEER_EVENT_SYNCHRONIZED_DATA DWORD
   dwSize     AS DWORD   ' DWORD
   recordType AS GUID    ' GUID
END TYPE

'#ifndef NO_P2P_GRAPH

'/////////////////////////////////////////////////////////////////////////////
'//
'//  G R A P H I N G
'//
'/////////////////////////////////////////////////////////////////////////////

'typedef PVOID HGRAPH, *PHGRAPH;

'/////////////////////////////////////////////////////////////////////////////
'// Constants

'#define PEER_GRAPH_VERSION MAKEWORD(1,0)
%PEER_GRAPH_VERSION = 1??

' enum PEER_GRAPH_EVENT_TYPE
%PEER_GRAPH_EVENT_STATUS_CHANGED         = 1
%PEER_GRAPH_EVENT_PROPERTY_CHANGED       = 2
%PEER_GRAPH_EVENT_RECORD_CHANGED         = 3
%PEER_GRAPH_EVENT_DIRECT_CONNECTION      = 4
%PEER_GRAPH_EVENT_NEIGHBOR_CONNECTION    = 5
%PEER_GRAPH_EVENT_INCOMING_DATA          = 6
%PEER_GRAPH_EVENT_CONNECTION_REQUIRED    = 7
%PEER_GRAPH_EVENT_NODE_CHANGED           = 8
%PEER_GRAPH_EVENT_SYNCHRONIZED           = 9

' enum PEER_NODE_CHANGE_TYPE
%PEER_NODE_CHANGE_CONNECTED              = 1
%PEER_NODE_CHANGE_DISCONNECTED           = 2
%PEER_NODE_CHANGE_UPDATED                = 3

' enum PEER_GRAPH_STATUS_FLAGS
%PEER_GRAPH_STATUS_LISTENING             = &H0001???
%PEER_GRAPH_STATUS_HAS_CONNECTIONS       = &H0002???
%PEER_GRAPH_STATUS_SYNCHRONIZED          = &H0004???

' enum PEER_GRAPH_PROPERTY_FLAGS
%PEER_GRAPH_PROPERTY_HEARTBEATS          = &H0001???
%PEER_GRAPH_PROPERTY_DEFER_EXPIRATION    = &H0002???

' enum PEER_GRAPH_SCOPE
%PEER_GRAPH_SCOPE_ANY                     = 0
%PEER_GRAPH_SCOPE_GLOBAL                  = 1
%PEER_GRAPH_SCOPE_SITELOCAL               = 2
%PEER_GRAPH_SCOPE_LINKLOCAL               = 3
%PEER_GRAPH_SCOPE_LOOPBACK                = 4


'/////////////////////////////////////////////////////////////////////////////
'// Structures

' // Size = 40 bytes
TYPE PEER_GRAPH_PROPERTIES DWORD
   dwSize             AS DWORD          ' DWORD
   dwFlags            AS DWORD          ' DWORD // %PEER_GRAPH_PROPERTY_FLAGS
   dwScope            AS DWORD          ' DWORD
   dwMaxRecordSize    AS DWORD          ' DWORD
   pwzGraphId         AS WSTRINGZ PTR   ' PWSTR
   pwzCreatorId       AS WSTRINGZ PTR   ' PWSTR
   pwzFriendlyName    AS WSTRINGZ PTR   ' PWSTR
   pwzComment         AS WSTRINGZ PTR   ' PWSTR
   ulPresenceLifetime AS DWORD          ' ULONG
   cPresenceMax       AS DWORD          ' ULONG
END TYPE

' // Size = 32 bytes
TYPE PEER_NODE_INFO QWORD FILL  ' Must be 8 byte aligned
   dwSize        AS DWORD              ' DWORD
   ullNodeId     AS QUAD               ' ULONGLONG
   pwzPeerId     AS WSTRINGZ PTR       ' PWSTR
   cAddresses    AS DWORD              ' ULONG
   pAddresses    AS PEER_ADDRESS PTR   '  PEER_ADDRESS
   pwzAttributes AS WSTRINGZ PTR       ' PWSTR
END TYPE

' // Size = 24 bytes
TYPE PEER_EVENT_NODE_CHANGE_DATA   ' Must be 8 byte aligned
   dwSize      AS DWORD          ' DWORD
   changeType  AS LONG           ' PEER_NODE_CHANGE_TYPE
   ullNodeId   AS QUAD           ' ULONGLONG
   pwzPeerId   AS WSTRINGZ PTR   ' PWSTR
   alignment__ AS DWORD          ' // To keep 8 byte alignment
END TYPE

' // Size = 8 bytes
TYPE PEER_GRAPH_EVENT_REGISTRATION DWORD
   eventType AS LONG       ' PEER_GRAPH_EVENT_TYPE
   pType     AS GUID PTR   ' GUID*
END TYPE

' // Size = 40 bytes
UNION PEER_GRAPH_EVENT_DATA_UNION QWORD FILL   ' Must be 8 byte aligned
   dwStatus             AS DWORD                               ' PEER_GRAPH_STATUS_FLAGS
   incomingData         AS PEER_EVENT_INCOMING_DATA            ' PEER_EVENT_INCOMING_DATA
   recordChangeData     AS PEER_EVENT_RECORD_CHANGE_DATA       ' PEER_EVENT_RECORD_CHANGE_DATA
   connectionChangeData AS PEER_EVENT_CONNECTION_CHANGE_DATA   ' PEER_EVENT_CONNECTION_CHANGE_DATA
   nodeChangeData       AS PEER_EVENT_NODE_CHANGE_DATA         ' PEER_EVENT_NODE_CHANGE_DATA
   synchronizedData     AS PEER_EVENT_SYNCHRONIZED_DATA        ' PEER_EVENT_SYNCHRONIZED_DATA
END UNION

' // Size = 48 bytes
TYPE PEER_GRAPH_EVENT_DATA QWORD FILL   ' Must be 8 byte aligned
   eventType AS LONG   ' PEER_GRAPH_EVENT_TYPE
   PEER_GRAPH_EVENT_DATA_UNION
END TYPE

'typedef HRESULT (CALLBACK * PFNPEER_VALIDATE_RECORD)(
'                __in    HGRAPH                  hGraph,
'                __in_opt PVOID                  pvContext,
'                __in PPEER_RECORD               pRecord,
'                __in PEER_RECORD_CHANGE_TYPE    changeType);

'FUNCTION PEER_VALIDATE_RECORD ( _
'   BYVAL hGraph AS DWORD _                              ' __in HGRAPH                  hGraph
' , BYVAL pvContext AS DWORD _                           ' __in_opt PVOID               pvContext
' , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD            pRecord
' , BYVAL changeType AS LONG _                           ' __in PEER_RECORD_CHANGE_TYPE changeType
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK * PFNPEER_SECURE_RECORD)(
'                __in HGRAPH                         hGraph,
'                __in_opt PVOID                      pvContext,
'                __in PPEER_RECORD                   pRecord,
'                __in PEER_RECORD_CHANGE_TYPE        changeType,
'                __out PPEER_DATA              * ppSecurityData);

'FUNCTION PEER_SECURE_RECORD ( _
'   BYVAL hGraph AS DWORD _                              ' __in HGRAPH                   hGraph
' , BYVAL pvContext AS DWORD _                           ' __in_opt PVOID                pvContext
' , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD             pRecord
' , BYVAL changeType AS LONG _                           ' __in PEER_RECORD_CHANGE_TYPE  changeType
' , BYREF ppSecurityData AS PEER_DATA _                  ' __out PPEER_DATA       * ppSecurityData
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK * PFNPEER_FREE_SECURITY_DATA)(
'                __in HGRAPH             hGraph,
'                __in_opt PVOID          pvContext,
'                __in PPEER_DATA         pSecurityData);

'FUNCTION PEER_FREE_SECURITY_DATA ( _
'   BYVAL hGraph AS DWORD _                              ' __in HGRAPH             hGraph
' , BYVAL pvContext AS DWORD _                           ' __in_opt PVOID          pvContext
' , BYREF pSecurityData AS PEER_DATA _                   ' __in PPEER_DATA         pSecurityData
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK * PFNPEER_ON_PASSWORD_AUTH_FAILED)(
'                __in HGRAPH             hGraph,
'                __in_opt PVOID          pvContext);

'FUNCTION PEER_ON_PASSWORD_AUTH_FAILED ( _
'   BYVAL hGraph AS DWORD _                              ' __in HGRAPH             hGraph
' , BYVAL pvContext AS DWORD _                           ' __in_opt PVOID          pvContext
' ) AS LONG                                              ' HRESULT

' // Size = 40 bytes
TYPE PEER_SECURITY_INTERFACE DWORD
   dwSize              AS DWORD          ' DWORD
   pwzSspFilename      AS WSTRINGZ PTR   ' PWSTR
   pwzPackageName      AS WSTRINGZ PTR   ' PWSTR
   cbSecurityInfo      AS DWORD          ' ULONG
   pbSecurityInfo      AS BYTE PTR       ' PBYTE
   pvContext           AS DWORD          ' PVOID
   pfnValidateRecord   AS DWORD          ' PFNPEER_VALIDATE_RECORD
   pfnSecureRecord     AS DWORD          ' PFNPEER_SECURE_RECORD
   pfnFreeSecurityData AS DWORD          ' PFNPEER_FREE_SECURITY_DATA
   pfnAuthFailed       AS DWORD          ' PFNPEER_ON_PASSWORD_AUTH_FAILED
END TYPE


'/////////////////////////////////////////////////////////////////////////////
'// API Definitions

DECLARE FUNCTION PeerGraphStartup IMPORT "P2PGraph.dll" ALIAS "PeerGraphStartup" ( _
   BYVAL wVersionRequested AS WORD _                    ' __in WORD wVersionRequested
 , BYREF pVersionData AS PEER_VERSION_DATA _            ' __out PPEER_VERSION_DATA pVersionData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphShutdown IMPORT "P2PGraph.dll" ALIAS "PeerGraphShutdown" ( _
 ) AS LONG                                              ' HRESULT

DECLARE SUB PeerGraphFreeData IMPORT "P2PGraph.dll" ALIAS "PeerGraphFreeData" ( _
   BYVAL pvData AS DWORD _                              ' __in PVOID pvData
 )                                                      ' VOID

DECLARE FUNCTION PeerGraphGetItemCount IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetItemCount" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 , BYREF pCount AS DWORD _                              ' __out ULONG * pCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphGetNextItem IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetNextItem" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 , BYREF pCount AS DWORD _                              ' __inout ULONG * pCount
 , BYREF pppvItems AS ANY _                             ' __out_ecount(*pCount) PVOID ** pppvItems
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphEndEnumeration IMPORT "P2PGraph.dll" ALIAS "PeerGraphEndEnumeration" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphCreate IMPORT "P2PGraph.dll" ALIAS "PeerGraphCreate" ( _
   BYREF pGraphProperties AS PEER_GRAPH_PROPERTIES _    ' __in PPEER_GRAPH_PROPERTIES pGraphProperties
 , BYREF pwzDatabaseName AS WSTRINGZ _                  ' __in PCWSTR pwzDatabaseName
 , BYREF pSecurityInterface AS PEER_SECURITY_INTERFACE _ ' __in_opt PPEER_SECURITY_INTERFACE pSecurityInterface
 , BYREF phGraph AS DWORD _                             ' __out HGRAPH * phGraph
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphOpen IMPORT "P2PGraph.dll" ALIAS "PeerGraphOpen" ( _
   BYREF pwzGraphId AS WSTRINGZ _                       ' __in PCWSTR pwzGraphId
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in PCWSTR pwzPeerId
 , BYREF pwzDatabaseName AS WSTRINGZ _                  ' __in PCWSTR pwzDatabaseName
 , BYREF pSecurityInterface AS PEER_SECURITY_INTERFACE _ ' __in_opt PPEER_SECURITY_INTERFACE pSecurityInterface
 , BYVAL cRecordTypeSyncPrecedence AS DWORD _           ' __in ULONG cRecordTypeSyncPrecedence
 , BYREF pRecordTypeSyncPrecedence AS GUID _            ' __in_ecount_opt(cRecordTypeSyncPrecedence) const GUID * pRecordTypeSyncPrecedence
 , BYREF phGraph AS DWORD _                             ' __out HGRAPH  * phGraph
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphListen IMPORT "P2PGraph.dll" ALIAS "PeerGraphListen" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , OPTIONAL BYVAL dwScope AS DWORD _                    ' __in_opt DWORD dwScope
 , OPTIONAL BYVAL dwScopeId AS DWORD _                  ' __in_opt DWORD dwScopeId
 , OPTIONAL BYVAL wPort AS WORD _                       ' __in_opt WORD wPort
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphConnect IMPORT "P2PGraph.dll" ALIAS "PeerGraphConnect" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in_opt PCWSTR pwzPeerId
 , BYREF pAddress AS PEER_ADDRESS _                     ' __in  PPEER_ADDRESS pAddress
 , BYREF pullConnectionId AS QUAD _                     ' __out ULONGLONG * pullConnectionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphClose IMPORT "P2PGraph.dll" ALIAS "PeerGraphClose" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphDelete IMPORT "P2PGraph.dll" ALIAS "PeerGraphDelete" ( _
   BYREF pwzGraphId AS WSTRINGZ _                       ' __in PCWSTR pwzGraphId
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in PCWSTR pwzPeerId
 , BYREF pwzDatabaseName AS WSTRINGZ _                  ' __in PCWSTR pwzDatabaseName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphGetStatus IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetStatus" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pdwStatus AS DWORD _                           ' __out DWORD * pdwStatus
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphGetProperties IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetProperties" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF ppGraphProperties AS PEER_GRAPH_PROPERTIES _   ' __out PPEER_GRAPH_PROPERTIES * ppGraphProperties
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphSetProperties IMPORT "P2PGraph.dll" ALIAS "PeerGraphSetProperties" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pGraphProperties AS PEER_GRAPH_PROPERTIES _    ' __in PPEER_GRAPH_PROPERTIES ppGraphProperties
 ) AS LONG                                              ' HRESULT

'// Eventing interfaces

DECLARE FUNCTION PeerGraphRegisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerGraphRegisterEvent" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL cEventRegistrations AS DWORD _                 ' __in ULONG cEventRegistrations
 , BYREF pEventRegistrations AS PEER_GRAPH_EVENT_REGISTRATION _ '__in_ecount(cEventRegistrations) PEER_GRAPH_EVENT_REGISTRATION * pEventRegistrations
 , BYREF phPeerEvent AS DWORD _                         ' __out HPEEREVENT * phPeerEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphUnregisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerGraphUnregisterEvent" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HANDLE hPeerEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphGetEventData IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetEventData" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HANDLE hPeerEvent
 , BYREF ppEventData AS PEER_GRAPH_EVENT_DATA _         ' __out PPEER_GRAPH_EVENT_DATA * ppEventData
 ) AS LONG                                              ' HRESULT

'// Data Storage

DECLARE FUNCTION PeerGraphGetRecord IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetRecord" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 , BYREF ppRecord AS PEER_RECORD _                      ' __out PPEER_RECORD * ppRecord
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphAddRecord IMPORT "P2PGraph.dll" ALIAS "PeerGraphAddRecord" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD pRecord
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphUpdateRecord IMPORT "P2PGraph.dll" ALIAS "PeerGraphUpdateRecord" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD pRecord
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphDeleteRecord IMPORT "P2PGraph.dll" ALIAS "PeerGraphDeleteRecord" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 , BYVAL fLocal AS LONG _                               ' __in BOOL fLocal
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphEnumRecords IMPORT "P2PGraph.dll" ALIAS "PeerGraphEnumRecords" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pRecordType AS GUID _                          ' __in_opt const GUID * pRecordType
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in_opt PCWSTR pwzPeerId
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphSearchRecords IMPORT "P2PGraph.dll" ALIAS "PeerGraphSearchRecords" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzCriteria AS WSTRINGZ _                      ' __in PCWSTR pwzCriteria
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphExportDatabase IMPORT "P2PGraph.dll" ALIAS "PeerGraphExportDatabase" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzFilePath AS WSTRINGZ _                      ' __in PCWSTR pwzFilePath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphImportDatabase IMPORT "P2PGraph.dll" ALIAS "PeerGraphImportDatabase" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzFilePath AS WSTRINGZ _                      ' __in PCWSTR pwzFilePath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphValidateDeferredRecords IMPORT "P2PGraph.dll" ALIAS "PeerGraphValidateDeferredRecords" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL cRecordIds AS DWORD _                          ' __in ULONG cRecordIds
 , BYREF pRecordIds AS GUID _                           ' __in_ecount(cRecordIds) const GUID * pRecordIds
 ) AS LONG                                              ' HRESULT

'// Node/Connection interfaces

DECLARE FUNCTION PeerGraphOpenDirectConnection IMPORT "P2PGraph.dll" ALIAS "PeerGraphOpenDirectConnection" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in PCWSTR pwzPeerId
 , BYREF pAddress AS PEER_ADDRESS _                     ' __in PPEER_ADDRESS pAddress
 , BYREF pullConnectionId AS QUAD _                     ' __out ULONGLONG * pullConnectionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphSendData IMPORT "P2PGraph.dll" ALIAS "PeerGraphSendData" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL ullConnectionId AS QUAD _                      ' __in ULONGLONG ullConnectionId
 , BYREF pType AS GUID _                                ' __in const GUID * pType
 , BYVAL cbData AS DWORD _                              ' __in ULONG cbData
 , BYREF pvData AS ANY _                                ' __in_bcount(cbData) PVOID pvData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphCloseDirectConnection IMPORT "P2PGraph.dll" ALIAS "PeerGraphCloseDirectConnection" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL ullConnectionId AS QUAD _                      ' __in ULONGLONG ullConnectionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphEnumConnections IMPORT "P2PGraph.dll" ALIAS "PeerGraphEnumConnections" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags // PEER_CONNECTION_FLAGS
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphEnumNodes IMPORT "P2PGraph.dll" ALIAS "PeerGraphEnumNodes" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzPeerId AS WSTRINGZ _                        ' __in_opt PCWSTR pwzPeerId
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphSetPresence IMPORT "P2PGraph.dll" ALIAS "PeerGraphSetPresence" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL fPresent AS LONG _                             ' __in BOOL fPresent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphGetNodeInfo IMPORT "P2PGraph.dll" ALIAS "PeerGraphGetNodeInfo" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYVAL ullNodeId AS QUAD _                            ' __in ULONGLONG ullNodeId
 , BYREF ppNodeInfo AS PEER_NODE_INFO _                 ' __out PPEER_NODE_INFO * ppNodeInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphSetNodeAttributes IMPORT "P2PGraph.dll" ALIAS "PeerGraphSetNodeAttributes" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pwzAttributes AS WSTRINGZ _                    ' __in PCWSTR pwzAttributes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphPeerTimeToUniversalTime IMPORT "P2PGraph.dll" ALIAS "PeerGraphPeerTimeToUniversalTime" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pftPeerTime AS FILETIME _                      ' __in FILETIME * pftPeerTime
 , BYREF pftUniversalTime AS FILETIME _                 ' __out FILETIME * pftUniversalTime
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGraphUniversalTimeToPeerTime IMPORT "P2PGraph.dll" ALIAS "PeerGraphUniversalTimeToPeerTime" ( _
   BYVAL hGraph AS DWORD _                              ' __in HGRAPH hGraph
 , BYREF pftUniversalTime AS FILETIME _                 ' __in FILETIME * pftUniversalTime
 , BYREF pftPeerTime AS FILETIME _                      ' __out FILETIME * pftPeerTime
 ) AS LONG                                              ' HRESULT

'#endif // NO_P2P_GRAPH

'#if (!(defined (NO_P2P_GROUP)) || (!defined (NO_P2P_IDENTITY)))

'//////////////////////////////////////////////////////////////////////////////
'//
'//  Common APIs used by Grouping and the Identity Manager
'//
'//////////////////////////////////////////////////////////////////////////////

#INCLUDE ONCE "wincrypt.inc"

DECLARE SUB PeerFreeData IMPORT "P2PGraph.dll" ALIAS "PeerFreeData" ( _
   BYVAL pvData AS DWORD _                              ' __in_opt LPCVOID pvData
 )                                                      ' VOID

DECLARE FUNCTION PeerGetItemCount IMPORT "P2PGraph.dll" ALIAS "PeerGetItemCount" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 , BYREF pCount AS DWORD _                              ' __out ULONG * pCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGetNextItem IMPORT "P2PGraph.dll" ALIAS "PeerGetNextItem" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 , BYREF pCount AS DWORD _                              ' __inout ULONG * pCount
 , BYREF pppvItems AS ANY _                             ' __out_ecount(*pCount) PVOID ** pppvItems
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerEndEnumeration IMPORT "P2PGraph.dll" ALIAS "PeerEndEnumeration" ( _
   BYVAL hPeerEnum AS DWORD _                           ' __in HPEERENUM hPeerEnum
 ) AS LONG                                              ' HRESULT

'#endif

'#ifndef NO_P2P_GROUP
'/////////////////////////////////////////////////////////////////////////////
'//
'//  G R O U P I N G
'//
'/////////////////////////////////////////////////////////////////////////////

'typedef PVOID HGROUP, *PHGROUP;
'typedef GUID  PEER_ROLE_ID;

'/////////////////////////////////////////////////////////////////////////////
'// Constants

'#if NTDDI_VERSION >= NTDDI_VISTA
'    #define PEER_GROUP_VERSION MAKEWORD(1,1)
'#else
'    #define PEER_GROUP_VERSION MAKEWORD(1,0)
'#endif

#IF %WINVER >= &H0600
   %PEER_GROUP_VERSION = &H101
#ELSE
   %PEER_GROUP_VERSION = 1
#ENDIF

' enum PEER_GROUP_EVENT_TYPE
%PEER_GROUP_EVENT_STATUS_CHANGED             = 1
%PEER_GROUP_EVENT_PROPERTY_CHANGED           = 2
%PEER_GROUP_EVENT_RECORD_CHANGED             = 3
%PEER_GROUP_EVENT_DIRECT_CONNECTION          = 4
%PEER_GROUP_EVENT_NEIGHBOR_CONNECTION        = 5
%PEER_GROUP_EVENT_INCOMING_DATA              = 6
%PEER_GROUP_EVENT_MEMBER_CHANGED             = 8
%PEER_GROUP_EVENT_CONNECTION_FAILED          = 10
%PEER_GROUP_EVENT_AUTHENTICATION_FAILED      = 11

' enum PEER_GROUP_STATUS
%PEER_GROUP_STATUS_LISTENING            = &H0001???
%PEER_GROUP_STATUS_HAS_CONNECTIONS      = &H0002???

' enum PEER_GROUP_PROPERTY_FLAGS
%PEER_MEMBER_DATA_OPTIONAL              = &H0001???
%PEER_DISABLE_PRESENCE                  = &H0002???
%PEER_DEFER_EXPIRATION                  = &H0004???


'#if NTDDI_VERSION >= NTDDI_VISTA
' enum PEER_GROUP_AUTHENTICATION_SCHEME
%PEER_GROUP_GMC_AUTHENTICATION          = &H00000001???
%PEER_GROUP_PASSWORD_AUTHENTICATION     = &H00000002???
'#endif

' enum PEER_MEMBER_FLAGS
%PEER_MEMBER_PRESENT                    = &H0001???

' enum PEER_MEMBER_CHANGE_TYPE
%PEER_MEMBER_CONNECTED                  = 1
%PEER_MEMBER_DISCONNECTED               = 2
%PEER_MEMBER_UPDATED                    = 3
%PEER_MEMBER_JOINED                     = 4
%PEER_MEMBER_LEFT                       = 5

' enum PEER_GROUP_ISSUE_CREDENTIAL_FLAGS
%PEER_GROUP_STORE_CREDENTIALS      = &H0001???

'/////////////////////////////////////////////////////////////////////////////
'// Structures


' // Size = 48 bytes
TYPE PEER_CREDENTIAL_INFO DWORD
   dwSize                AS DWORD                      ' DWORD
   dwFlags               AS DWORD                      ' DWORD
   pwzFriendlyName       AS WSTRINGZ PTR               ' PWSTR
   pPublicKey            AS CERT_PUBLIC_KEY_INFO PTR   ' CERT_PUBLIC_KEY_INFO *
   pwzIssuerPeerName     AS WSTRINGZ PTR               ' PWSTR
   pwzIssuerFriendlyName AS WSTRINGZ PTR               ' PWSTR
   ftValidityStart       AS FILETIME                   ' FILETIME
   ftValidityEnd         AS FILETIME                   ' FILETIME
   cRoles                AS DWORD                      ' ULONG
   pRoles                AS GUID PTR                   ' __field_ecount(cRoles) PEER_ROLE_ID *
END TYPE

' // Size = 40 bytes
TYPE PEER_MEMBER   ' Must be 8 byte aligned
   dwSize          AS DWORD                      ' DWORD
   dwFlags         AS DWORD                      ' DWORD // PEER_MEMBER_FLAGS
   pwzIdentity     AS WSTRINGZ PTR               ' PWSTR
   pwzAttributes   AS WSTRINGZ PTR               ' PWSTR
   ullNodeId       AS QUAD                       ' ULONGLONG
   cAddresses      AS DWORD                      ' ULONG
   pAddresses      AS PEER_ADDRESS PTR           ' __field_ecount(cAddresses) PEER_ADDRESS *
   pCredentialInfo AS PEER_CREDENTIAL_INFO PTR   ' PEER_CREDENTIAL_INFO *
   alignment__     AS DWORD                      ' // To keep 8 byte alignment
END TYPE

' // Size = 84 bytes
TYPE PEER_INVITATION_INFO DWORD
   dwSize                 AS DWORD                      ' DWORD
   dwFlags                AS DWORD                      ' DWORD
   pwzCloudName           AS WSTRINGZ PTR               ' PWSTR
   dwScope                AS DWORD                      ' DWORD
   dwCloudFlags           AS DWORD                      ' DWORD
   pwzGroupPeerName       AS WSTRINGZ PTR               ' PWSTR
   pwzIssuerPeerName      AS WSTRINGZ PTR               ' PWSTR
   pwzSubjectPeerName     AS WSTRINGZ PTR               ' PWSTR
   pwzGroupFriendlyName   AS WSTRINGZ PTR               ' PWSTR
   pwzIssuerFriendlyName  AS WSTRINGZ PTR               ' PWSTR
   pwzSubjectFriendlyName AS WSTRINGZ PTR               ' PWSTR
   ftValidityStart        AS FILETIME                   ' FILETIME
   ftValidityEnd          AS FILETIME                   ' FILETIME
   cRoles                 AS DWORD                      ' ULONG
   pRoles                 AS GUID PTR                   ' PEER_ROLE_ID *
   cClassifiers           AS DWORD                      ' ULONG
   ppwzClassifiers        AS WSTRINGZ PTR               ' PWSTR*
   pSubjectPublicKey      AS CERT_PUBLIC_KEY_INFO PTR   ' CERT_PUBLIC_KEY_INFO *
'#if NTDDI_VERSION >= NTDDI_VISTA
#IF %WINVER >= &H0600
   authScheme             AS DWORD                      ' PEER_GROUP_AUTHENTICATION_SCHEME
#ENDIF
'#endif
END TYPE


'//start

' // Size = 64 bytes
TYPE PEER_GROUP_PROPERTIES DWORD
   dwSize                  AS DWORD          ' DWORD
   dwFlags                 AS DWORD          ' DWORD // PEER_GROUP_PROPERTY_FLAGS
   pwzCloud                AS WSTRINGZ PTR   ' PWSTR
   pwzClassifier           AS WSTRINGZ PTR   ' PWSTR
   pwzGroupPeerName        AS WSTRINGZ PTR   ' PWSTR
   pwzCreatorPeerName      AS WSTRINGZ PTR   ' PWSTR
   pwzFriendlyName         AS WSTRINGZ PTR   ' PWSTR
   pwzComment              AS WSTRINGZ PTR   ' PWSTR
   ulMemberDataLifetime    AS DWORD          ' ULONG
   ulPresenceLifetime      AS DWORD          ' ULONG
'#if NTDDI_VERSION >= NTDDI_VISTA
#IF %WINVER >= %WINVER
   dwAuthenticationSchemes AS DWORD      ' DWORD // PEER_GROUP_AUTHENTICATION_SCHEME
   ' // group password authentication data
   pwzGroupPassword        AS WSTRINGZ PTR   ' PWSTR
   groupPasswordRole       AS GUID           ' PEER_ROLE_ID
#ENDIF
'#endif
END TYPE

' // Size = 12 bytes
TYPE PEER_EVENT_MEMBER_CHANGE_DATA DWORD
   dwSize      AS DWORD          ' DWORD
   changeType  AS LONG           ' PEER_MEMBER_CHANGE_TYPE
   pwzIdentity AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 8 bytes
TYPE PEER_GROUP_EVENT_REGISTRATION DWORD
   eventType AS LONG       ' PEER_GROUP_EVENT_TYPE
   pType     AS GUID PTR   ' GUID *
END TYPE

' // Size = 40 bytes
UNION PEER_GROUP_EVENT_DATA_UNION QWORD FILL   ' Must be 8 byte aligned
   dwStatus                 AS DWORD                               ' PEER_GROUP_STATUS
   incomingData             AS PEER_EVENT_INCOMING_DATA            ' PEER_EVENT_INCOMING_DATA
   recordChangeData         AS PEER_EVENT_RECORD_CHANGE_DATA       ' PEER_EVENT_RECORD_CHANGE_DATA
   connectionChangeData     AS PEER_EVENT_CONNECTION_CHANGE_DATA   ' PEER_EVENT_CONNECTION_CHANGE_DATA
   memberChangeData         AS PEER_EVENT_MEMBER_CHANGE_DATA       ' PEER_EVENT_MEMBER_CHANGE_DATA
   hrConnectionFailedReason AS LONG                                ' HRESULT
END UNION

' // Size = 48 bytes
TYPE PEER_GROUP_EVENT_DATA QWORD FILL   ' Must be 8 byte aligned
   eventType AS LONG   ' PEER_GROUP_EVENT_TYPE
   PEER_GROUP_EVENT_DATA_UNION
END TYPE

'//end

' // Size = 12 bytes
TYPE PEER_NAME_PAIR DWORD
   dwSize          AS DWORD          ' DWORD
   pwzPeerName     AS WSTRINGZ PTR   ' PWSTR
   pwzFriendlyName AS WSTRINGZ PTR   ' PWSTR
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// API Definitions

DECLARE FUNCTION PeerGroupStartup IMPORT "P2PGraph.dll" ALIAS "PeerGroupStartup" ( _
   BYVAL wVersionRequested AS WORD _                    ' __in WORD wVersionRequested
 , BYREF pVersionData AS PEER_VERSION_DATA _            ' __out PPEER_VERSION_DATA pVersionData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupShutdown IMPORT "P2PGraph.dll" ALIAS "PeerGroupShutdown" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupCreate IMPORT "P2PGraph.dll" ALIAS "PeerGroupCreate" ( _
   BYREF pProperties AS PEER_GROUP_PROPERTIES _         ' __in  PPEER_GROUP_PROPERTIES pProperties
 , BYREF phGroup AS DWORD _                             ' __out HGROUP * phGroup
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupOpen IMPORT "P2PGraph.dll" ALIAS "PeerGroupOpen" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF pwzGroupPeerName AS WSTRINGZ _                 ' __in PCWSTR pwzGroupPeerName
 , BYREF pwzCloud AS WSTRINGZ _                         ' __in_opt PCWSTR pwzCloud
 , BYREF phGroup AS DWORD _                             ' __out HGROUP * phGroup
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupJoin IMPORT "P2PGraph.dll" ALIAS "PeerGroupJoin" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF pwzInvitation AS WSTRINGZ _                    ' __in PCWSTR pwzInvitation
 , BYREF pwzCloud AS WSTRINGZ _                         ' __in_opt PCWSTR pwzCloud
 , BYREF phGroup AS DWORD _                             ' __out HGROUP * phGroup
 ) AS LONG                                              ' HRESULT

'#if NTDDI_VERSION >= NTDDI_VISTA
DECLARE FUNCTION PeerGroupPasswordJoin IMPORT "P2PGraph.dll" ALIAS "PeerGroupPasswordJoin" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF pwzInvitation AS WSTRINGZ _                    ' __in PCWSTR pwzInvitation
 , BYREF pwzPassword AS WSTRINGZ _                      ' __in_opt PCWSTR pwzPassword
 , BYREF pwzCloud AS WSTRINGZ _                         ' __in_opt PCWSTR pwzCloud
 , BYREF phGroup AS DWORD _                             ' __out HGROUP * phGroup
 ) AS LONG                                              ' HRESULT
'#endif

DECLARE FUNCTION PeerGroupConnect IMPORT "P2PGraph.dll" ALIAS "PeerGroupConnect" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 ) AS LONG                                              ' HRESULT

'#if NTDDI_VERSION >= NTDDI_VISTA
DECLARE FUNCTION PeerGroupConnectByAddress IMPORT "P2PGraph.dll" ALIAS "PeerGroupConnectByAddress" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL cAddresses AS DWORD _                          ' __in ULONG cAddresses
 , BYREF pAddresses AS PEER_ADDRESS _                   ' __in_ecount(cAddresses) PPEER_ADDRESS pAddresses
 ) AS LONG                                              ' HRESULT
'#endif

DECLARE FUNCTION PeerGroupClose IMPORT "P2PGraph.dll" ALIAS "PeerGroupClose" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupDelete IMPORT "P2PGraph.dll" ALIAS "PeerGroupDelete" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF pwzGroupPeerName AS WSTRINGZ _                 ' __in PCWSTR pwzGroupPeerName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupCreateInvitation IMPORT "P2PGraph.dll" ALIAS "PeerGroupCreateInvitation" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzIdentityInfo AS WSTRINGZ _                  ' __in PCWSTR pwzIdentityInfo
 , BYREF pftExpiration AS FILETIME _                    ' __in_opt FILETIME * pftExpiration
 , BYVAL cRoles AS DWORD _                              ' __in ULONG cRoles
 , BYREF pRoles AS GUID _                               ' __in_ecount_opt(cRoles) const GUID * pRoles
 , BYREF ppwzInvitation AS DWORD _                      ' __out PWSTR * ppwzInvitation
 ) AS LONG                                              ' HRESULT

'#if NTDDI_VERSION >= NTDDI_VISTA
DECLARE FUNCTION PeerGroupCreatePasswordInvitation IMPORT "P2PGraph.dll" ALIAS "PeerGroupCreatePasswordInvitation" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF ppwzInvitation AS DWORD _                      ' __out PWSTR * ppwzInvitation
 ) AS LONG                                              ' HRESULT
'#endif

DECLARE FUNCTION PeerGroupParseInvitation IMPORT "P2PGraph.dll" ALIAS "PeerGroupParseInvitation" ( _
   BYREF pwzInvitation AS WSTRINGZ _                    ' __in PCWSTR pwzInvitation
 , BYREF ppInvitationInfo AS PEER_INVITATION_INFO _     ' __out PPEER_INVITATION_INFO * ppInvitationInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupGetStatus IMPORT "P2PGraph.dll" ALIAS "PeerGroupGetStatus" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pdwStatus AS DWORD _                           ' __out DWORD * pdwStatus
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupGetProperties IMPORT "P2PGraph.dll" ALIAS "PeerGroupGetProperties" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF ppProperties AS PEER_GROUP_PROPERTIES _        ' __out PPEER_GROUP_PROPERTIES * ppProperties
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupSetProperties IMPORT "P2PGraph.dll" ALIAS "PeerGroupSetProperties" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pProperties AS PEER_GROUP_PROPERTIES _         ' __in PPEER_GROUP_PROPERTIES pProperties
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupEnumMembers IMPORT "P2PGraph.dll" ALIAS "PeerGroupEnumMembers" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags // PEER_MEMBER_FLAGS
 , BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupOpenDirectConnection IMPORT "P2PGraph.dll" ALIAS "PeerGroupOpenDirectConnection" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF pAddress AS PEER_ADDRESS _                     ' __in PPEER_ADDRESS pAddress
 , BYREF pullConnectionId AS QUAD _                     ' __out ULONGLONG * pullConnectionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupCloseDirectConnection IMPORT "P2PGraph.dll" ALIAS "PeerGroupCloseDirectConnection" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL ullConnectionId AS QUAD _                      ' __in ULONGLONG ullConnectionId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupEnumConnections IMPORT "P2PGraph.dll" ALIAS "PeerGroupEnumConnections" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags // PEER_CONNECTION_FLAGS
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupSendData IMPORT "P2PGraph.dll" ALIAS "PeerGroupSendData" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL ullConnectionId AS QUAD _                      ' __in ULONGLONG ullConnectionId
 , BYREF pType AS GUID _                                ' __in const GUID * pType
 , BYVAL cbData AS DWORD _                              ' __in ULONG cbData
 , BYREF pvData AS ANY _                                ' __in_bcount(cbData) PVOID pvData
 ) AS LONG                                              ' HRESULT


'// Eventing interfaces

DECLARE FUNCTION PeerGroupRegisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerGroupRegisterEvent" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL cEventRegistration AS DWORD _                  ' __in ULONG cEventRegistration
 , BYREF pEventRegistrations AS PEER_GROUP_EVENT_REGISTRATION _ ' __in_ecount(cEventRegistration) PEER_GROUP_EVENT_REGISTRATION * pEventRegistrations
 , BYREF phPeerEvent AS DWORD _                         ' __out HPEEREVENT * phPeerEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupUnregisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerGroupUnregisterEvent" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HPEEREVENT hPeerEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupGetEventData IMPORT "P2PGraph.dll" ALIAS "PeerGroupGetEventData" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HPEEREVENT hPeerEvent
 , BYREF ppEventData AS PEER_GROUP_EVENT_DATA _         ' __out PPEER_GROUP_EVENT_DATA * ppEventData
 ) AS LONG                                              ' HRESULT

'// Data Storage

DECLARE FUNCTION PeerGroupGetRecord IMPORT "P2PGraph.dll" ALIAS "PeerGroupGetRecord" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 , BYREF ppRecord AS PEER_RECORD _                      ' __out PPEER_RECORD * ppRecord
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupAddRecord IMPORT "P2PGraph.dll" ALIAS "PeerGroupAddRecord" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD pRecord
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupUpdateRecord IMPORT "P2PGraph.dll" ALIAS "PeerGroupUpdateRecord" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pRecord AS PEER_RECORD _                       ' __in PPEER_RECORD pRecord
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupDeleteRecord IMPORT "P2PGraph.dll" ALIAS "PeerGroupDeleteRecord" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pRecordId AS GUID _                            ' __in const GUID * pRecordId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupEnumRecords IMPORT "P2PGraph.dll" ALIAS "PeerGroupEnumRecords" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pRecordType AS GUID _                          ' __in_opt const GUID * pRecordType
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupSearchRecords IMPORT "P2PGraph.dll" ALIAS "PeerGroupSearchRecords" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzCriteria AS WSTRINGZ _                      ' __in PCWSTR pwzCriteria
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupExportDatabase IMPORT "P2PGraph.dll" ALIAS "PeerGroupExportDatabase" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzFilePath AS WSTRINGZ _                      ' __in PCWSTR pwzFilePath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupImportDatabase IMPORT "P2PGraph.dll" ALIAS "PeerGroupImportDatabase" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzFilePath AS WSTRINGZ _                      ' __in PCWSTR pwzFilePath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupIssueCredentials IMPORT "P2PGraph.dll" ALIAS "PeerGroupIssueCredentials" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzSubjectIdentity AS WSTRINGZ _               ' __in PCWSTR pwzSubjectIdentity
 , BYREF pCredentialInfo AS PEER_CREDENTIAL_INFO _      ' __in_opt PEER_CREDENTIAL_INFO * pCredentialInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF ppwzInvitation AS DWORD _             ' __opt_out PWSTR * ppwzInvitation
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupExportConfig IMPORT "P2PGraph.dll" ALIAS "PeerGroupExportConfig" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pwzPassword AS WSTRINGZ _                      ' __in PCWSTR pwzPassword
 , BYREF ppwzXML AS DWORD _                             ' __out PWSTR * ppwzXML
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupImportConfig IMPORT "P2PGraph.dll" ALIAS "PeerGroupImportConfig" ( _
   BYREF pwzXML AS WSTRINGZ _                           ' __in PCWSTR pwzXML
 , BYREF pwzPassword AS WSTRINGZ _                      ' __in PCWSTR pwzPassword
 , BYVAL fOverwrite AS LONG _                           ' __in BOOL fOverwrite
 , BYREF ppwzIdentity AS DWORD _                        ' __out PWSTR * ppwzIdentity
 , BYREF ppwzGroup AS DWORD _                           ' __out PWSTR * ppwzGroup
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupPeerTimeToUniversalTime IMPORT "P2PGraph.dll" ALIAS "PeerGroupPeerTimeToUniversalTime" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pftPeerTime AS FILETIME _                      ' __in FILETIME * pftPeerTime
 , BYREF pftUniversalTime AS FILETIME _                 ' __out FILETIME * pftUniversalTime
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerGroupUniversalTimeToPeerTime IMPORT "P2PGraph.dll" ALIAS "PeerGroupUniversalTimeToPeerTime" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYREF pftUniversalTime AS FILETIME _                 ' __in FILETIME * pftUniversalTime
 , BYREF pftPeerTime AS FILETIME _                      ' __out FILETIME * pftPeerTime
 ) AS LONG                                              ' HRESULT

'#if NTDDI_VERSION >= NTDDI_WIN7
DECLARE FUNCTION PeerGroupResumePasswordAuthentication IMPORT "P2PGraph.dll" ALIAS "PeerGroupResumePasswordAuthentication" ( _
   BYVAL hGroup AS DWORD _                              ' __in HGROUP hGroup
 , BYVAL hPeerEventHandle AS DWORD _                    ' __in HPEEREVENT hPeerEventHandle
 ) AS LONG                                              ' HRESULT
'#endif

'#endif // NO_P2P_GROUP

'#ifndef   NO_P2P_IDENTITY

'/////////////////////////////////////////////////////////////////////////////
'//
'//  I D E N T I T Y
'//
'/////////////////////////////////////////////////////////////////////////////

'// API Definitions

DECLARE FUNCTION PeerIdentityCreate IMPORT "P2PGraph.dll" ALIAS "PeerIdentityCreate" ( _
   BYREF pwzClassifier AS WSTRINGZ _                    ' __in_opt PCWSTR pwzClassifier
 , BYREF pwzFriendlyName AS WSTRINGZ _                  ' __in_opt PCWSTR pwzFriendlyName
 , BYVAL hCryptProv AS DWORD _                          ' __in_opt HCRYPTPROV hCryptProv
 , BYREF ppwzIdentity AS DWORD _                        ' __out PWSTR * ppwzIdentity
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityGetFriendlyName IMPORT "P2PGraph.dll" ALIAS "PeerIdentityGetFriendlyName" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF ppwzFriendlyName AS DWORD _                    ' __out PWSTR * ppwzFriendlyName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentitySetFriendlyName IMPORT "P2PGraph.dll" ALIAS "PeerIdentitySetFriendlyName" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF ppwzFriendlyName AS WSTRINGZ _                 ' __in PCWSTR pwzFriendlyName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityGetCryptKey IMPORT "P2PGraph.dll" ALIAS "PeerIdentityGetCryptKey" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF phCryptProv AS DWORD _                         ' __out HCRYPTPROV * phCryptProv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityDelete IMPORT "P2PGraph.dll" ALIAS "PeerIdentityDelete" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerEnumIdentities IMPORT "P2PGraph.dll" ALIAS "PeerEnumIdentities" ( _
   BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerEnumGroups IMPORT "P2PGraph.dll" ALIAS "PeerEnumGroups" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in PCWSTR pwzIdentity
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCreatePeerName IMPORT "P2PGraph.dll" ALIAS "PeerCreatePeerName" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF pwzClassifier AS WSTRINGZ _                    ' __in_opt PCWSTR pwzClassifier
 , BYREF ppwzPeerName AS DWORD _                        ' __out PWSTR * ppwzPeerName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityGetXML IMPORT "P2PGraph.dll" ALIAS "PeerIdentityGetXML" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF ppwzIdentityXML AS DWORD _                     ' __out PWSTR * ppwzIdentityXML
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityExport IMPORT "P2PGraph.dll" ALIAS "PeerIdentityExport" ( _
   BYREF pwzIdentity AS WSTRINGZ _                      ' __in_opt PCWSTR pwzIdentity
 , BYREF pwzPassword AS WSTRINGZ _                      ' __in PCWSTR pwzPassword
 , BYREF ppwzExportXML AS DWORD _                       ' __out PWSTR * ppwzExportXML
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityImport IMPORT "P2PGraph.dll" ALIAS "PeerIdentityImport" ( _
   BYREF pwzImportXML AS WSTRINGZ _                     ' __in PCWSTR pwzImportXML
 , BYREF pwzPassword AS WSTRINGZ _                      ' __in PCWSTR pwzPassword
 , BYREF ppwzIdentity AS DWORD _                        ' __out PWSTR * ppwzIdentity
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerIdentityGetDefault IMPORT "P2PGraph.dll" ALIAS "PeerIdentityGetDefault" ( _
   BYREF ppwzPeerName AS DWORD _                        ' __out PWSTR * ppwzPeerName
 ) AS LONG                                              ' HRESULT

'#endif // NO_P2P_IDENTITY

'#ifndef NO_P2P_COLLABORATION

'/////////////////////////////////////////////////////////////////////////////
'//
'//  C O L L A B O R A T I O N
'//
'/////////////////////////////////////////////////////////////////////////////

'#define PEER_COLLAB_VERSION MAKEWORD(1,0)
%PEER_COLLAB_VERSION = 1

'//////////////////////////////////////////////////////////////////////////////
'//
'//  Common used by AppInvite, Contact API's and Serverless Presence
'//
'//////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// Constants

' enum PEER_SIGNIN_FLAGS
%PEER_SIGNIN_NONE         = &H0???
%PEER_SIGNIN_NEAR_ME      = &H1???
%PEER_SIGNIN_INTERNET     = &H2???
%PEER_SIGNIN_ALL          = %PEER_SIGNIN_INTERNET OR %PEER_SIGNIN_NEAR_ME

' enum PEER_WATCH_PERMISSION
%PEER_WATCH_BLOCKED          = 0
%PEER_WATCH_ALLOWED          = 1

' enum PEER_PUBLICATION_SCOPE
%PEER_PUBLICATION_SCOPE_NONE         = &H0???
%PEER_PUBLICATION_SCOPE_NEAR_ME      = &H1???
%PEER_PUBLICATION_SCOPE_INTERNET     = &H2???
%PEER_PUBLICATION_SCOPE_ALL          = %PEER_PUBLICATION_SCOPE_NEAR_ME OR %PEER_PUBLICATION_SCOPE_INTERNET

'/////////////////////////////////////////////////////////////////////////////
'// Structures

' // Size = 28 bytes
TYPE PEER_APPLICATION DWORD
   id             AS GUID           ' GUID
   data           AS PEER_DATA      ' PEER_DATA
   pwzDescription AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 28 bytes
TYPE PEER_OBJECT DWORD
   id                 AS GUID        ' GUID
   data               AS PEER_DATA   ' PEER_DATA
   dwPublicationScope AS DWORD       ' DWORD
END TYPE

' // Size = 32 bytes
TYPE PEER_CONTACT DWORD
   pwzPeerName        AS WSTRINGZ PTR   ' PWSTR
   pwzNickName        AS WSTRINGZ PTR   ' PWSTR
   pwzDisplayName     AS WSTRINGZ PTR   ' PWSTR
   pwzEmailAddress    AS WSTRINGZ PTR   ' PWSTR
   fWatch             AS LONG           ' BOOL
   WatcherPermissions AS LONG           ' PEER_WATCH_PERMISSION
   credentials        AS PEER_DATA      ' PEER_DATA
END TYPE

' // Size = 36 bytes
TYPE PEER_ENDPOINT DWORD
   address         AS PEER_ADDRESS   ' PEER_ADDRESS
   pwzEndpointName AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 56 bytes
TYPE PEER_PEOPLE_NEAR_ME DWORD
   pwzNickName AS WSTRINGZ PTR    ' PWSTR
   endpoint    AS PEER_ENDPOINT   ' PEER_ENDPOINT
   id          AS GUID            ' GUID
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// APIs

DECLARE FUNCTION PeerCollabStartup IMPORT "P2PGraph.dll" ALIAS "PeerCollabStartup" ( _
   BYVAL wVersionRequested AS WORD _                    ' __in WORD wVersionRequested
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabShutdown IMPORT "P2PGraph.dll" ALIAS "PeerCollabShutdown" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabSignin IMPORT "P2PGraph.dll" ALIAS "PeerCollabSignin" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL dwSigninOptions AS DWORD _                     ' __in DWORD dwSigninOptions
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabSignout IMPORT "P2PGraph.dll" ALIAS "PeerCollabSignout" ( _
   BYVAL dwSigninOptions AS DWORD _                     ' __in DWORD dwSigninOptions
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetSigninOptions IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetSigninOptions" ( _
   BYREF pdwSigninOptions AS DWORD _                    ' __out DWORD * pdwSigninOptions
 ) AS LONG                                              ' HRESULT

'/////////////////////////////////////////////////////////////////////////////
'//
'//  A P P I N V I T E
'//
'/////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// constants

' enum PEER_INVITATION_RESPONSE_TYPE
%PEER_INVITATION_RESPONSE_DECLINED       = 0
%PEER_INVITATION_RESPONSE_ACCEPTED       = 1
%PEER_INVITATION_RESPONSE_EXPIRED        = 2
%PEER_INVITATION_RESPONSE_ERROR          = 3

' enum PEER_APPLICATION_REGISTRATION_TYPE
%PEER_APPLICATION_CURRENT_USER   = 0
%PEER_APPLICATION_ALL_USERS      = 1

'/////////////////////////////////////////////////////////////////////////////
'// Structures

' // Size = 28 bytes
TYPE PEER_INVITATION DWORD
   applicationId   AS GUID           ' GUID
   applicationData AS PEER_DATA      ' PEER_DATA
   pwzMessage      AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 12 bytes
TYPE PEER_INVITATION_RESPONSE DWORD
   action         AS LONG           ' PEER_INVITATION_RESPONSE_TYPE
   pwzMessage     AS WSTRINGZ PTR   ' PWSTR
   hrExtendedInfo AS LONG           ' HRESULT
END TYPE

' // Size = 12 bytes
TYPE PEER_APP_LAUNCH_INFO DWORD
   pContact    AS PEER_CONTACT PTR      ' PPEER_CONTACT
   pEndpoint   AS PEER_ENDPOINT PTR     ' PPEER_ENDPOINT
   pInvitation AS PEER_INVITATION PTR   ' PPEER_INVITATION
END TYPE

' // Size = 40 bytes
TYPE PEER_APPLICATION_REGISTRATION_INFO DWORD
   application             AS PEER_APPLICATION   ' PEER_APPLICATION
   pwzApplicationToLaunch  AS WSTRINGZ PTR       ' PWSTR
   pwzApplicationArguments AS WSTRINGZ PTR       ' PWSTR
   dwPublicationScope      AS DWORD              ' DWORD
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// API's

'// AppInvite sender side API's
DECLARE FUNCTION PeerCollabAsyncInviteContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabAsyncInviteContact" ( _
   BYREF pcContact AS PEER_CONTACT _                    ' __in_opt PCPEER_CONTACT pcContact
 , BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 , BYREF pcInvitation AS PEER_INVITATION _              ' __in PCPEER_INVITATION pcInvitation
 , OPTIONAL BYVAL hEvent AS DWORD _                     ' __in_opt HANDLE hEvent
 , OPTIONAL BYREF phInvitation AS DWORD _               ' __out_opt HANDLE * phInvitation
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetInvitationResponse IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetInvitationResponse" ( _
   BYVAL hInvitation AS DWORD _                         ' __in HANDLE hInvitation
 , BYREF ppInvitationResponse AS PEER_INVITATION_RESPONSE _ ' __out PPEER_INVITATION_RESPONSE * ppInvitationResponse
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabCancelInvitation IMPORT "P2PGraph.dll" ALIAS "PeerCollabCancelInvitation" ( _
   BYVAL hInvitation AS DWORD _                         ' __in HANDLE hInvitation
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabCloseHandle IMPORT "P2PGraph.dll" ALIAS "PeerCollabCloseHandle" ( _
   BYVAL hInvitation AS DWORD _                         ' __in HANDLE hInvitation
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabInviteContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabInviteContact" ( _
   BYREF pcContact AS PEER_CONTACT _                    ' __in_opt PCPEER_CONTACT pcContact
 , BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 , BYREF pcInvitation AS PEER_INVITATION _              ' __in PCPEER_INVITATION pcInvitation
 , BYREF ppResponse AS PEER_INVITATION_RESPONSE _       ' __out PPEER_INVITATION_RESPONSE * ppResponse
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabAsyncInviteEndpoint IMPORT "P2PGraph.dll" ALIAS "PeerCollabAsyncInviteEndpoint" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 , BYREF pcInvitation AS PEER_INVITATION _              ' __in PCPEER_INVITATION pcInvitation
 , OPTIONAL BYVAL hEvent AS DWORD _                     ' __in_opt HANDLE hEvent
 , OPTIONAL BYREF phInvitation AS DWORD _               ' __out_opt HANDLE * phInvitation
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabInviteEndpoint IMPORT "P2PGraph.dll" ALIAS "PeerCollabInviteEndpoint" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 , BYREF pcInvitation AS PEER_INVITATION _              ' __in PCPEER_INVITATION pcInvitation
 , BYREF ppResponse AS PEER_INVITATION_RESPONSE _       ' __out PPEER_INVITATION_RESPONSE * ppResponse
 ) AS LONG                                              ' HRESULT

'// AppInvite receiver side API's
DECLARE FUNCTION PeerCollabGetAppLaunchInfo IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetAppLaunchInfo" ( _
   BYREF ppLaunchInfo AS PEER_APP_LAUNCH_INFO _         ' __out PPEER_APP_LAUNCH_INFO * ppLaunchInfo
 ) AS LONG                                              ' HRESULT

'// Applications registration API's
DECLARE FUNCTION PeerCollabRegisterApplication IMPORT "P2PGraph.dll" ALIAS "PeerCollabRegisterApplication" ( _
   BYREF pcApplication AS PEER_APPLICATION_REGISTRATION_INFO _ ' __in PCPEER_APPLICATION_REGISTRATION_INFO pcApplication
 , BYVAL registrationType AS LONG _                     ' __in PEER_APPLICATION_REGISTRATION_TYPE registrationType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabUnregisterApplication IMPORT "P2PGraph.dll" ALIAS "PeerCollabUnregisterApplication" ( _
   BYVAL pApplicationId AS GUID _                       ' __in const GUID * pApplicationId
 , BYVAL registrationType AS LONG _                     ' __in PEER_APPLICATION_REGISTRATION_TYPE registrationType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetApplicationRegistrationInfo IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetApplicationRegistrationInfo" ( _
   BYVAL pApplicationId AS GUID _                       ' __in const GUID * pApplicationId
 , BYVAL registrationType AS LONG _                     ' __in PEER_APPLICATION_REGISTRATION_TYPE registrationType
 , BYREF ppApplication AS PEER_APPLICATION_REGISTRATION_INFO _ ' __out PPEER_APPLICATION_REGISTRATION_INFO * ppApplication
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabEnumApplicationRegistrationInfo IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumApplicationRegistrationInfo" ( _
   BYVAL registrationType AS LONG _                     ' __in PEER_APPLICATION_REGISTRATION_TYPE registrationType
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

'/////////////////////////////////////////////////////////////////////////////
'//
'//  S E R V E R L E S S    P R E S E N C E
'//
'/////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// constants

' enum PEER_PRESENCE_STATUS
%PEER_PRESENCE_OFFLINE               = 0
%PEER_PRESENCE_OUT_TO_LUNCH          = 1
%PEER_PRESENCE_AWAY                  = 2
%PEER_PRESENCE_BE_RIGHT_BACK         = 3
%PEER_PRESENCE_IDLE                  = 4
%PEER_PRESENCE_BUSY                  = 5
%PEER_PRESENCE_ON_THE_PHONE          = 6
%PEER_PRESENCE_ONLINE                = 7

'/////////////////////////////////////////////////////////////////////////////
'// Structures

' // Size = 8 bytes
TYPE PEER_PRESENCE_INFO DWORD
   status             AS LONG           ' PEER_PRESENCE_STATUS
   pwzDescriptiveText AS WSTRINGZ PTR   ' PWSTR
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'// API's

'// Subscriber
DECLARE FUNCTION PeerCollabGetPresenceInfo IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetPresenceInfo" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in_opt PCPEER_ENDPOINT pcEndpoint
 , BYREF ppPresenceInfo AS PEER_PRESENCE_INFO _         ' __out PPEER_PRESENCE_INFO *ppPresenceInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabEnumApplications IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumApplications" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in_opt PCPEER_ENDPOINT pcEndpoint
 , BYREF pApplicationId AS GUID _                       ' __in_opt const GUID * pApplicationId
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabEnumObjects IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumObjects" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in_opt PCPEER_ENDPOINT pcEndpoint
 , BYREF pApplicationId AS GUID _                       ' __in_opt const GUID * pApplicationId
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabEnumEndpoints IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumEndpoints" ( _
   BYREF pcContact AS PEER_CONTACT _                    ' __in_opt PCPEER_CONTACT pcContact
 , BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabRefreshEndpointData IMPORT "P2PGraph.dll" ALIAS "PeerCollabRefreshEndpointData" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabDeleteEndpointData IMPORT "P2PGraph.dll" ALIAS "PeerCollabDeleteEndpointData" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in PCPEER_ENDPOINT pcEndpoint
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabQueryContactData IMPORT "P2PGraph.dll" ALIAS "PeerCollabQueryContactData" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in_opt PCPEER_ENDPOINT pcEndpoint
 , BYREF ppwzContactData AS DWORD _                     ' __out PWSTR * ppwzContactData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabSubscribeEndpointData IMPORT "P2PGraph.dll" ALIAS "PeerCollabSubscribeEndpointData" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in const PCPEER_ENDPOINT pcEndpoint
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabUnsubscribeEndpointData IMPORT "P2PGraph.dll" ALIAS "PeerCollabUnsubscribeEndpointData" ( _
   BYREF pcEndpoint AS PEER_ENDPOINT _                  ' __in const PCPEER_ENDPOINT pcEndpoint
 ) AS LONG                                              ' HRESULT

'// Publisher

DECLARE FUNCTION PeerCollabSetPresenceInfo IMPORT "P2PGraph.dll" ALIAS "PeerCollabSetPresenceInfo" ( _
   BYREF pcPresenceInfo AS PEER_PRESENCE_INFO _         ' __in PCPEER_PRESENCE_INFO pcPresenceInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetEndpointName IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetEndpointName" ( _
   BYREF ppwzEndpointName AS DWORD _                    ' __out PWSTR * ppwzEndpointName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabSetEndpointName IMPORT "P2PGraph.dll" ALIAS "PeerCollabSetEndpointName" ( _
   BYREF pwzEndpointName AS WSTRINGZ _                  ' __in PCWSTR pwzEndpointName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabSetObject IMPORT "P2PGraph.dll" ALIAS "PeerCollabSetObject" ( _
   BYREF pcObject AS PEER_OBJECT _                      ' __in PCPEER_OBJECT pcObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabDeleteObject IMPORT "P2PGraph.dll" ALIAS "PeerCollabDeleteObject" ( _
   BYREF pObjectId AS GUID _                            ' __in const GUID * pObjectId
 ) AS LONG                                              ' HRESULT

'#endif

'/////////////////////////////////////////////////////////////////////////////
'//
'//  R E G I S T R A T I O N
'//
'/////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// constants

' enum PEER_CHANGE_TYPE
%PEER_CHANGE_ADDED           = 0
%PEER_CHANGE_DELETED         = 1
%PEER_CHANGE_UPDATED         = 2

' enum PEER_COLLAB_EVENT_TYPE
%PEER_EVENT_WATCHLIST_CHANGED                = 1
%PEER_EVENT_ENDPOINT_CHANGED                 = 2
%PEER_EVENT_ENDPOINT_PRESENCE_CHANGED        = 3
%PEER_EVENT_ENDPOINT_APPLICATION_CHANGED     = 4
%PEER_EVENT_ENDPOINT_OBJECT_CHANGED          = 5
%PEER_EVENT_MY_ENDPOINT_CHANGED              = 6
%PEER_EVENT_MY_PRESENCE_CHANGED              = 7
%PEER_EVENT_MY_APPLICATION_CHANGED           = 8
%PEER_EVENT_MY_OBJECT_CHANGED                = 9
%PEER_EVENT_PEOPLE_NEAR_ME_CHANGED           = 10
%PEER_EVENT_REQUEST_STATUS_CHANGED           = 11

'/////////////////////////////////////////////////////////////////////////////
'// Structures

' // Size = 8 bytes
TYPE PEER_COLLAB_EVENT_REGISTRATION DWORD
   eventType AS LONG       ' PEER_COLLAB_EVENT_TYPE
   pInstance AS GUID PTR   ' GUID *
END TYPE

' // Size = 8 bytes
TYPE PEER_EVENT_WATCHLIST_CHANGED_DATA DWORD
   pContact   AS PEER_CONTACT PTR   ' PPEER_CONTACT
   changeType AS LONG               ' PEER_CHANGE_TYPE
END TYPE

' // Size = 16 bytes
TYPE PEER_EVENT_PRESENCE_CHANGED_DATA DWORD
   pContact      AS PEER_CONTACT PTR         ' PPEER_CONTACT
   pEndpoint     AS PEER_ENDPOINT PTR        ' PPEER_ENDPOINT
   changeType    AS LONG                     ' PEER_CHANGE_TYPE
   pPresenceInfo AS PEER_PRESENCE_INFO PTR   ' PPEER_PRESENCE_INFO
END TYPE

' // Size = 16 bytes
TYPE PEER_EVENT_APPLICATION_CHANGED_DATA DWORD
   pContact     AS PEER_CONTACT PTR       ' PPEER_CONTACT
   pEndpoint    AS PEER_ENDPOINT PTR      ' PPEER_ENDPOINT
   changeType   AS LONG                   ' PEER_CHANGE_TYPE
   pApplication AS PEER_APPLICATION PTR   ' PPEER_APPLICATION
END TYPE

' // Size = 16 bytes
TYPE PEER_EVENT_OBJECT_CHANGED_DATA DWORD
   pContact   AS PEER_CONTACT PTR    ' PPEER_CONTACT
   pEndpoint  AS PEER_ENDPOINT PTR   ' PPEER_ENDPOINT
   changeType AS LONG                ' PEER_CHANGE_TYPE
   pObject    AS PEER_OBJECT PTR     ' PEER_OBJECT
END TYPE

' // Size = 8 bytes
TYPE PEER_EVENT_ENDPOINT_CHANGED_DATA DWORD
   pContact  AS PEER_CONTACT PTR    ' PPEER_CONTACT
   pEndpoint AS PEER_ENDPOINT PTR   ' PPEER_ENDPOINT
END TYPE

' // Size = 8 bytes
TYPE PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA DWORD
   changeType    AS LONG                      ' PEER_CHANGE_TYPE
   pPeopleNearMe AS PEER_PEOPLE_NEAR_ME PTR   ' PPEER_PEOPLE_NEAR_ME
END TYPE

' // Size = 8 bytes
TYPE PEER_EVENT_REQUEST_STATUS_CHANGED_DATA DWORD
   pEndpoint AS PEER_ENDPOINT PTR   ' PPEER_ENDPOINT
   hrChange  AS LONG                ' HRESULT
END TYPE

' // Size = 16 bytes
UNION PEER_COLLAB_EVENT_DATA_UNION DWORD
   watchListChangedData     AS PEER_EVENT_WATCHLIST_CHANGED_DATA
   presenceChangedData      AS PEER_EVENT_PRESENCE_CHANGED_DATA
   applicationChangedData   AS PEER_EVENT_APPLICATION_CHANGED_DATA
   objectChangedData        AS PEER_EVENT_OBJECT_CHANGED_DATA
   endpointChangedData      AS PEER_EVENT_ENDPOINT_CHANGED_DATA
   peopleNearMeChangedData  AS PEER_EVENT_PEOPLE_NEAR_ME_CHANGED_DATA
   requestStatusChangedData AS PEER_EVENT_REQUEST_STATUS_CHANGED_DATA
END UNION

' // Size = 20 bytes
TYPE PEER_COLLAB_EVENT_DATA DWORD
   eventType AS LONG   ' PEER_COLLAB_EVENT_TYPE
   PEER_COLLAB_EVENT_DATA_UNION
END TYPE


'/////////////////////////////////////////////////////////////////////////////
'// API's

DECLARE FUNCTION PeerCollabRegisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerCollabRegisterEvent" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 , BYVAL cEventRegistration AS DWORD _                  ' __in DWORD cEventRegistration
 , BYREF pEventRegistrations AS PEER_COLLAB_EVENT_REGISTRATION _ ' __in_ecount(cEventRegistration) PEER_COLLAB_EVENT_REGISTRATION * pEventRegistrations
 , BYREF phPeerEvent AS DWORD _                         ' __out HPEEREVENT *phPeerEvent
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetEventData IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetEventData" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HPEEREVENT hPeerEvent
 , BYREF ppEventData AS PEER_COLLAB_EVENT_DATA _        ' __out PPEER_COLLAB_EVENT_DATA * ppEventData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabUnregisterEvent IMPORT "P2PGraph.dll" ALIAS "PeerCollabUnregisterEvent" ( _
   BYVAL hPeerEvent AS DWORD _                          ' __in HPEEREVENT hPeerEvent
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'//
'//  P N M
'//
'//////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// API's

DECLARE FUNCTION PeerCollabEnumPeopleNearMe IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumPeopleNearMe" ( _
   BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM *phPeerEnum
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'//
'//  C O N T A C T
'//
'//////////////////////////////////////////////////////////////////////////////

'/////////////////////////////////////////////////////////////////////////////
'// API's

DECLARE FUNCTION PeerCollabAddContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabAddContact" ( _
   BYREF pwzContactData AS WSTRINGZ _                   ' __in PCWSTR pwzContactData
 , OPTIONAL BYREF ppContact AS PEER_CONTACT _           ' __opt_out PPEER_CONTACT * ppContact
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabDeleteContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabDeleteContact" ( _
   BYREF pwzPeerName AS WSTRINGZ _                      ' __in PCWSTR pwzPeerName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabGetContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabGetContact" ( _
   BYREF pwzPeerName AS WSTRINGZ _                      ' __in_opt PCWSTR pwzPeerName
 , BYREF ppContact AS PEER_CONTACT _                    ' __out PPEER_CONTACT * ppContact
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabUpdateContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabUpdateContact" ( _
   BYREF pContact AS PEER_CONTACT _                     ' __in PCPEER_CONTACT pContact
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabEnumContacts IMPORT "P2PGraph.dll" ALIAS "PeerCollabEnumContacts" ( _
   BYREF phPeerEnum AS DWORD _                          ' __out HPEERENUM * phPeerEnum
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabExportContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabExportContact" ( _
   BYREF pwzPeerName AS WSTRINGZ _                      ' __in_opt PCWSTR pwzPeerName
 , BYREF ppwzContactData AS DWORD _                     ' __out PWSTR * ppwzContactData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerCollabParseContact IMPORT "P2PGraph.dll" ALIAS "PeerCollabParseContact" ( _
   BYREF pwzContactData AS WSTRINGZ _                   ' __in PCWSTR pwzContactData
 , BYREF ppContact AS PEER_CONTACT _                    ' __out PPEER_CONTACT * ppContact
 ) AS LONG                                              ' HRESULT

'#endif // NO_P2P_COLLABORATION


'/////////////////////////////////////////////////////////////////////////////
'//
'//  PNRP APIs
'//
'/////////////////////////////////////////////////////////////////////////////

'#ifndef   NO_P2P_PNRP

'#define PNRP_VERSION     MAKEWORD(2,0)
%PNRP_VERSION = 2

'#define PEER_PNRP_ALL_LINK_CLOUDS   L"PEER_PNRP_ALL_LINKS"
'#define PEER_PNRP_AUTO_ADDRESSES    ((ULONG)(-1))

$PEER_PNRP_ALL_LINK_CLOUDS = "PEER_PNRP_ALL_LINKS"
%PEER_PNRP_AUTO_ADDRESSES  = &HFFFFFF???

'/////////////////////////////////////////////////////////////////////////////
'// Structures

'typedef PVOID HRESOLUTION, HREGISTRATION;

' // Size = 24 bytes
TYPE PEER_PNRP_ENDPOINT_INFO DWORD
   pwzPeerName AS WSTRINGZ PTR   ' PWSTR
   cAddresses  AS DWORD          ' ULONG
   ppAddresses AS SOCKADDR PTR   ' __field_ecount(cAddresses) SOCKADDR  **
   pwzComment  AS WSTRINGZ PTR   ' PWSTR
   payload     AS PEER_DATA      ' PEER_DATA
END TYPE

' // Size = 12 bytes
TYPE PEER_PNRP_CLOUD_INFO DWORD
   pwzCloudName AS WSTRINGZ PTR   ' PWSTR
   dwScope      AS LONG           ' PNRP_SCOPE
   dwScopeId    AS DWORD          ' DWORD
END TYPE

' // Size = 32 bytes
TYPE PEER_PNRP_REGISTRATION_INFO DWORD
   pwzCloudName          AS WSTRINGZ PTR   ' PWSTR
   pwzPublishingIdentity AS WSTRINGZ PTR   ' PWSTR
   cAddresses            AS DWORD          ' ULONG
   ppAddresses           AS SOCKADDR PTR   ' __field_ecount(cAddresses) SOCKADDR **
   wPort                 AS WORD           ' WORD
   pwzComment            AS WSTRINGZ PTR   ' PWSTR
   payload               AS PEER_DATA      ' PEER_DATA
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// API's

DECLARE FUNCTION PeerNameToPeerHostName IMPORT "P2PGraph.dll" ALIAS "PeerNameToPeerHostName" ( _
   BYREF pwzPeerName AS WSTRINGZ _                      ' __in PCWSTR pwzPeerName
 , BYREF ppwzHostName AS DWORD _                        ' __out PWSTR *ppwzHostName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerHostNameToPeerName IMPORT "P2PGraph.dll" ALIAS "PeerHostNameToPeerName" ( _
   BYREF pwzHostName AS WSTRINGZ _                      ' __in PCWSTR pwzHostName
 , BYREF ppwzPeerName AS DWORD _                        ' __out PWSTR *ppwzPeerName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpStartup IMPORT "P2PGraph.dll" ALIAS "PeerPnrpStartup" ( _
   BYVAL wVersionRequested AS WORD _                    ' __in WORD wVersionRequested
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpShutdown IMPORT "P2PGraph.dll" ALIAS "PeerPnrpShutdown" ( _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpRegister IMPORT "P2PGraph.dll" ALIAS "PeerPnrpRegister" ( _
   BYREF pcwzPeerName AS WSTRINGZ _                     ' __in PCWSTR pcwzPeerName
 , BYREF pRegistrationInfo AS PEER_PNRP_REGISTRATION_INFO _ ' __in_opt PPEER_PNRP_REGISTRATION_INFO pRegistrationInfo
 , BYREF phRegistration AS DWORD _                      ' __out HREGISTRATION *phRegistration
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpUpdateRegistration IMPORT "P2PGraph.dll" ALIAS "PeerPnrpUpdateRegistration" ( _
   BYVAL hRegistration AS DWORD _                       ' __in HREGISTRATION hRegistration
 , BYREF pRegistrationInfo AS PEER_PNRP_REGISTRATION_INFO _ ' __in PPEER_PNRP_REGISTRATION_INFO pRegistrationInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpUnregister IMPORT "P2PGraph.dll" ALIAS "PeerPnrpUnregister" ( _
   BYVAL hRegistration AS DWORD _                       ' __in HREGISTRATION hRegistration
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpResolve IMPORT "P2PGraph.dll" ALIAS "PeerPnrpResolve" ( _
   BYREF pcwzPeerName AS WSTRINGZ _                     ' __in PCWSTR pcwzPeerName
 , BYREF pcwzCloudName AS WSTRINGZ _                    ' __in_opt PCWSTR pcwzCloudName
 , BYREF pcEndpoints AS DWORD _                         ' __inout ULONG *pcEndpoints
 , BYREF ppEndpoints AS PEER_PNRP_ENDPOINT_INFO _       ' __out_ecount(*pcEndpoints) PPEER_PNRP_ENDPOINT_INFO *ppEndpoints
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpStartResolve IMPORT "P2PGraph.dll" ALIAS "PeerPnrpStartResolve" ( _
   BYREF pcwzPeerName AS WSTRINGZ _                     ' __in PCWSTR pcwzPeerName
 , BYREF pcwzCloudName AS WSTRINGZ _                    ' __in_opt PCWSTR pcwzCloudName
 , BYVAL cMaxEndpoints AS DWORD _                       ' __in_opt ULONG cMaxEndpoints
 , BYVAL hEvent AS DWORD _¨                             ' __in HANDLE hEvent
 , BYREF phResolve AS DWORD _                           ' __out HRESOLUTION *phResolve
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpGetCloudInfo IMPORT "P2PGraph.dll" ALIAS "PeerPnrpGetCloudInfo" ( _
   BYREF pcNumClouds AS DWORD _                         ' __out ULONG *pcNumClouds
 , BYREF ppCloudInfo AS PEER_PNRP_CLOUD_INFO _          ' __out_ecount(*pcNumClouds) PPEER_PNRP_CLOUD_INFO *ppCloudInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpGetEndpoint IMPORT "P2PGraph.dll" ALIAS "PeerPnrpGetEndpoint" ( _
   BYVAL hResolve AS DWORD _                            ' __in HRESOLUTION hResolve
 , BYREF ppEndpoint AS PEER_PNRP_ENDPOINT_INFO _        ' __out PPEER_PNRP_ENDPOINT_INFO *ppEndpoint
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PeerPnrpEndResolve IMPORT "P2PGraph.dll" ALIAS "PeerPnrpEndResolve" ( _
   BYVAL hResolve AS DWORD _                            ' __in HRESOLUTION hResolve
 ) AS LONG                                              ' HRESULT

'#endif // NO_P2P_PNRP

'/////////////////////////////////////////////////////////////////////////////
'//
'// Error codes
'//
'/////////////////////////////////////////////////////////////////////////////

#IF NOT %DEF(%FACILITY_P2P)
%FACILITY_P2P = 99
#ENDIF

'#define PEER_E_IPV6_NOT_INSTALLED            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0001)
'#define PEER_E_NOT_INITIALIZED               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0002)
'#define PEER_E_CANNOT_START_SERVICE          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0003)
'#define PEER_E_NOT_LICENSED                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0004)
'#define PEER_E_INVALID_GRAPH                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0010)
'#define PEER_E_DBNAME_CHANGED                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0011)
'#define PEER_E_DUPLICATE_GRAPH               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0012)
'#define PEER_E_GRAPH_NOT_READY               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0013)
'#define PEER_E_GRAPH_SHUTTING_DOWN           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0014)
'#define PEER_E_GRAPH_IN_USE                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0015)
'#define PEER_E_INVALID_DATABASE              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0016)
'#define PEER_E_TOO_MANY_ATTRIBUTES           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0017)

%PEER_E_IPV6_NOT_INSTALLED            = &H80630001&
%PEER_E_NOT_INITIALIZED               = &H80630002&
%PEER_E_CANNOT_START_SERVICE          = &H80630003&
%PEER_E_NOT_LICENSED                  = &H80630004&
%PEER_E_INVALID_GRAPH                 = &H80630010&
%PEER_E_DBNAME_CHANGED                = &H80630011&
%PEER_E_DUPLICATE_GRAPH               = &H80630012&
%PEER_E_GRAPH_NOT_READY               = &H80630013&
%PEER_E_GRAPH_SHUTTING_DOWN           = &H80630014&
%PEER_E_GRAPH_IN_USE                  = &H80630015&
%PEER_E_INVALID_DATABASE              = &H80630016&
%PEER_E_TOO_MANY_ATTRIBUTES           = &H80630017&

'#define PEER_E_CONNECTION_NOT_FOUND          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0103)
'#define PEER_E_CONNECT_SELF                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0106)
'#define PEER_E_ALREADY_LISTENING             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0107)
'#define PEER_E_NODE_NOT_FOUND                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0108)
'#define PEER_E_CONNECTION_FAILED             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0109)
'#define PEER_E_CONNECTION_NOT_AUTHENTICATED  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x010A)
'#define PEER_E_CONNECTION_REFUSED            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x010B)

%PEER_E_CONNECTION_NOT_FOUND          = &H80630103&
%PEER_E_CONNECT_SELF                  = &H80630106&
%PEER_E_ALREADY_LISTENING             = &H80630107&
%PEER_E_NODE_NOT_FOUND                = &H80630108&
%PEER_E_CONNECTION_FAILED             = &H80630109&
%PEER_E_CONNECTION_NOT_AUTHENTICATED  = &H8063010A&
%PEER_E_CONNECTION_REFUSED            = &H8063010B&

'#define PEER_E_CLASSIFIER_TOO_LONG           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0201)
'#define PEER_E_TOO_MANY_IDENTITIES           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0202)
'#define PEER_E_NO_KEY_ACCESS                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0203)
'#define PEER_E_GROUPS_EXIST                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0204)

%PEER_E_CLASSIFIER_TOO_LONG           = &H80630201&
%PEER_E_TOO_MANY_IDENTITIES           = &H80630202&
%PEER_E_NO_KEY_ACCESS                 = &H80630203&
%PEER_E_GROUPS_EXIST                  = &H80630204&

'// record error codes
'#define PEER_E_RECORD_NOT_FOUND              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0301)
'#define PEER_E_DATABASE_ACCESSDENIED         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0302)
'#define PEER_E_DBINITIALIZATION_FAILED       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0303)
'#define PEER_E_MAX_RECORD_SIZE_EXCEEDED      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0304)
'#define PEER_E_DATABASE_ALREADY_PRESENT      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0305)
'#define PEER_E_DATABASE_NOT_PRESENT          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0306)

%PEER_E_RECORD_NOT_FOUND              = &H80630301&
%PEER_E_DATABASE_ACCESSDENIED         = &H80630302&
%PEER_E_DBINITIALIZATION_FAILED       = &H80630303&
%PEER_E_MAX_RECORD_SIZE_EXCEEDED      = &H80630304&
%PEER_E_DATABASE_ALREADY_PRESENT      = &H80630305&
%PEER_E_DATABASE_NOT_PRESENT          = &H80630306&

'#define PEER_E_IDENTITY_NOT_FOUND            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0401)
%PEER_E_IDENTITY_NOT_FOUND            = &H80630401&

'// eventing error
'#define PEER_E_EVENT_HANDLE_NOT_FOUND        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0501)
%PEER_E_EVENT_HANDLE_NOT_FOUND        = &H80630501&

'// searching error
'#define PEER_E_INVALID_SEARCH                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0601)
'#define PEER_E_INVALID_ATTRIBUTES            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0602)

%PEER_E_INVALID_SEARCH                = &H80630601&
%PEER_E_INVALID_ATTRIBUTES            = &H80630602&

'// certificate verification error codes
'#define PEER_E_INVITATION_NOT_TRUSTED        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0701)
'#define PEER_E_CHAIN_TOO_LONG                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0703)
'#define PEER_E_INVALID_TIME_PERIOD           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0705)
'#define PEER_E_CIRCULAR_CHAIN_DETECTED       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0706)

%PEER_E_INVITATION_NOT_TRUSTED        = &H80630701&
%PEER_E_CHAIN_TOO_LONG                = &H80630703&
%PEER_E_INVALID_TIME_PERIOD           = &H80630705&
%PEER_E_CIRCULAR_CHAIN_DETECTED       = &H80630706&

'#define PEER_E_CERT_STORE_CORRUPTED          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x0801)
%PEER_E_CERT_STORE_CORRUPTED          = &H80630801&

'#define PEER_E_NO_CLOUD                      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x1001)
'#define PEER_E_CLOUD_NAME_AMBIGUOUS          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x1005)

%PEER_E_NO_CLOUD                      = &H80631001&
%PEER_E_CLOUD_NAME_AMBIGUOUS          = &H80631005&

'#define PEER_E_INVALID_RECORD                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2010)
'#define PEER_E_NOT_AUTHORIZED                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2020)
'#define PEER_E_PASSWORD_DOES_NOT_MEET_POLICY MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2021)
'#define PEER_E_DEFERRED_VALIDATION           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2030)
'#define PEER_E_INVALID_GROUP_PROPERTIES      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2040)
'#define PEER_E_INVALID_PEER_NAME             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2050)
'#define PEER_E_INVALID_CLASSIFIER            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2060)
'#define PEER_E_INVALID_FRIENDLY_NAME         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2070)
'#define PEER_E_INVALID_ROLE_PROPERTY         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2071)
'#define PEER_E_INVALID_CLASSIFIER_PROPERTY   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2072)
'#define PEER_E_INVALID_RECORD_EXPIRATION     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2080)
'#define PEER_E_INVALID_CREDENTIAL_INFO       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2081)
'#define PEER_E_INVALID_CREDENTIAL            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2082)
'#define PEER_E_INVALID_RECORD_SIZE           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2083)
'#define PEER_E_UNSUPPORTED_VERSION           MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2090)
'#define PEER_E_GROUP_NOT_READY               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2091)
'#define PEER_E_GROUP_IN_USE                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2092)
'#define PEER_E_INVALID_GROUP                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2093)
'#define PEER_E_NO_MEMBERS_FOUND              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2094)
'#define PEER_E_NO_MEMBER_CONNECTIONS         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2095)
'#define PEER_E_UNABLE_TO_LISTEN              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x2096)
'#define PEER_E_IDENTITY_DELETED              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x20A0)
'#define PEER_E_SERVICE_NOT_AVAILABLE         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x20A1)

%PEER_E_INVALID_RECORD                = &H80632010&
%PEER_E_NOT_AUTHORIZED                = &H80632020&
%PEER_E_PASSWORD_DOES_NOT_MEET_POLICY = &H80632021&
%PEER_E_DEFERRED_VALIDATION           = &H80632030&
%PEER_E_INVALID_GROUP_PROPERTIES      = &H80632040&
%PEER_E_INVALID_PEER_NAME             = &H80632050&
%PEER_E_INVALID_CLASSIFIER            = &H80632060&
%PEER_E_INVALID_FRIENDLY_NAME         = &H80632070&
%PEER_E_INVALID_ROLE_PROPERTY         = &H80632071&
%PEER_E_INVALID_CLASSIFIER_PROPERTY   = &H80632072&
%PEER_E_INVALID_RECORD_EXPIRATION     = &H80632080&
%PEER_E_INVALID_CREDENTIAL_INFO       = &H80632081&
%PEER_E_INVALID_CREDENTIAL            = &H80632082&
%PEER_E_INVALID_RECORD_SIZE           = &H80632083&
%PEER_E_UNSUPPORTED_VERSION           = &H80632090&
%PEER_E_GROUP_NOT_READY               = &H80632091&
%PEER_E_GROUP_IN_USE                  = &H80632092&
%PEER_E_INVALID_GROUP                 = &H80632093&
%PEER_E_NO_MEMBERS_FOUND              = &H80632094&
%PEER_E_NO_MEMBER_CONNECTIONS         = &H80632095&
%PEER_E_UNABLE_TO_LISTEN              = &H80632097&
%PEER_E_IDENTITY_DELETED              = &H806320A0&
%PEER_E_SERVICE_NOT_AVAILABLE         = &H806320A1&

'// Contacts APIs error code
'#define PEER_E_CONTACT_NOT_FOUND             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x6001)
%PEER_E_CONTACT_NOT_FOUND             = &H80636001&

'// Special success codes
'#define PEER_S_GRAPH_DATA_CREATED            MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x0001)
'#define PEER_S_NO_EVENT_DATA                 MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x0002)
'#define PEER_S_ALREADY_CONNECTED             MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x2000)
'#define PEER_S_SUBSCRIPTION_EXISTS           MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x6000)
'#define PEER_S_NO_CONNECTIVITY               MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x0005)
'#define PEER_S_ALREADY_A_MEMBER              MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_P2P, 0x0006)

%PEER_S_GRAPH_DATA_CREATED            = &H80630001&
%PEER_S_NO_EVENT_DATA                 = &H80630002&
%PEER_S_ALREADY_CONNECTED             = &H80632000&
%PEER_S_SUBSCRIPTION_EXISTS           = &H80636000&
%PEER_S_NO_CONNECTIVITY               = &H80630005&
%PEER_S_ALREADY_A_MEMBER              = &H80630006&

'// Pnrp helpers errors
'#define PEER_E_CANNOT_CONVERT_PEER_NAME      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x4001)
'#define PEER_E_INVALID_PEER_HOST_NAME        MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x4002)
'#define PEER_E_NO_MORE                       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x4003)
'#define PEER_E_PNRP_DUPLICATE_PEER_NAME      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x4005)

%PEER_E_CANNOT_CONVERT_PEER_NAME      = &H80634001&
%PEER_E_INVALID_PEER_HOST_NAME        = &H80634002&
%PEER_E_NO_MORE                       = &H80634003&
%PEER_E_PNRP_DUPLICATE_PEER_NAME      = &H80634005&

'// AppInvite APIs error code
'#define PEER_E_INVITE_CANCELLED                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x7000)
'#define PEER_E_INVITE_RESPONSE_NOT_AVAILABLE    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x7001)

%PEER_E_INVITE_CANCELLED                 = &H80637000&
%PEER_E_INVITE_RESPONSE_NOT_AVAILABLE    = &H80637001&

'// Serverless presence error codes
'#define PEER_E_NOT_SIGNED_IN                    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x7003)
'#define PEER_E_PRIVACY_DECLINED                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x7004)
'#define PEER_E_TIMEOUT                          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x7005)
'#define PEER_E_INVALID_ADDRESS                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0X7007)
'#define PEER_E_FW_EXCEPTION_DISABLED            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0X7008)
'#define PEER_E_FW_BLOCKED_BY_POLICY             MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0X7009)
'#define PEER_E_FW_BLOCKED_BY_SHIELDS_UP         MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0X700A)
'#define PEER_E_FW_DECLINED                      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_P2P, 0x700B)

%PEER_E_NOT_SIGNED_IN                    = &H80637003&
%PEER_E_PRIVACY_DECLINED                 = &H80637004&
%PEER_E_TIMEOUT                          = &H80637005&
%PEER_E_INVALID_ADDRESS                  = &H80637007&
%PEER_E_FW_EXCEPTION_DISABLED            = &H80637008&
%PEER_E_FW_BLOCKED_BY_POLICY             = &H80637009&
%PEER_E_FW_BLOCKED_BY_SHIELDS_UP         = &H8063700A&
%PEER_E_FW_DECLINED                      = &H8063700B&

'//
'// WSA_PNRP_* error codes returned by the NSP
'//

'// These errors are only used by PNRP NSP and applications using the NSP.
'// Any usage from other system/apps not related to PNRP (for example PNRP based getaddrinfo
'// implementations) would require these errors be moved to winerror.h

'#define WSA_PNRP_ERROR_BASE                    11500
'#define WSA_PNRP_CLOUD_NOT_FOUND               (WSA_PNRP_ERROR_BASE +  1)
'#define WSA_PNRP_CLOUD_DISABLED                (WSA_PNRP_ERROR_BASE +  2)
'#define WSA_PNRP_INVALID_IDENTITY              (WSA_PNRP_ERROR_BASE +  3)
'#define WSA_PNRP_TOO_MUCH_LOAD                 (WSA_PNRP_ERROR_BASE +  4)
'#define WSA_PNRP_CLOUD_IS_SEARCH_ONLY          (WSA_PNRP_ERROR_BASE +  5)
'#define WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID (WSA_PNRP_ERROR_BASE +  6)
'#define WSA_PNRP_DUPLICATE_PEER_NAME           (WSA_PNRP_ERROR_BASE +  8)
'#define WSA_PNRP_CLOUD_IS_DEAD                 (WSA_PNRP_ERROR_BASE +  9)

%WSA_PNRP_ERROR_BASE                    = 11500&
%WSA_PNRP_CLOUD_NOT_FOUND               = %WSA_PNRP_ERROR_BASE +  1
%WSA_PNRP_CLOUD_DISABLED                = %WSA_PNRP_ERROR_BASE +  2
%WSA_PNRP_INVALID_IDENTITY              = %WSA_PNRP_ERROR_BASE +  3
%WSA_PNRP_TOO_MUCH_LOAD                 = %WSA_PNRP_ERROR_BASE +  4
%WSA_PNRP_CLOUD_IS_SEARCH_ONLY          = %WSA_PNRP_ERROR_BASE +  5
%WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID = %WSA_PNRP_ERROR_BASE +  6
%WSA_PNRP_DUPLICATE_PEER_NAME           = %WSA_PNRP_ERROR_BASE +  8
%WSA_PNRP_CLOUD_IS_DEAD                 = %WSA_PNRP_ERROR_BASE +  9

'//
'//   these are the HRESULTs corresponding to the WSA error codes above and returned by Grouping and Simple API
'//
'#define PEER_E_CLOUD_NOT_FOUND                    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_CLOUD_NOT_FOUND)
'#define PEER_E_CLOUD_DISABLED                     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_CLOUD_DISABLED)
'#define PEER_E_INVALID_IDENTITY                   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_INVALID_IDENTITY)
'#define PEER_E_TOO_MUCH_LOAD                      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_TOO_MUCH_LOAD)
'#define PEER_E_CLOUD_IS_SEARCH_ONLY               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_CLOUD_IS_SEARCH_ONLY)
'#define PEER_E_CLIENT_INVALID_COMPARTMENT_ID      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_CLIENT_INVALID_COMPARTMENT_ID)
'#define PEER_E_DUPLICATE_PEER_NAME                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_DUPLICATE_PEER_NAME)
'#define PEER_E_CLOUD_IS_DEAD                      MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, WSA_PNRP_CLOUD_IS_DEAD)

%PEER_E_CLOUD_NOT_FOUND                    = &H80072CED&
%PEER_E_CLOUD_DISABLED                     = &H80072CEE&
%PEER_E_INVALID_IDENTITY                   = &H80072CEF&
%PEER_E_TOO_MUCH_LOAD                      = &H80072CF0&
%PEER_E_CLOUD_IS_SEARCH_ONLY               = &H80072CF1&
%PEER_E_CLIENT_INVALID_COMPARTMENT_ID      = &H80072CF2&
%PEER_E_DUPLICATE_PEER_NAME                = &H80072CF4&
%PEER_E_CLOUD_IS_DEAD                      = &H80072CF5&

'//
'// these are the error codes that are not defined by winerror.h, so we define them as our own
'//
'#define PEER_E_NOT_FOUND                     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_NOT_FOUND)
'#define PEER_E_DISK_FULL                     MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_DISK_FULL)
'#define PEER_E_ALREADY_EXISTS                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_ALREADY_EXISTS)

%PEER_E_NOT_FOUND                     = &H80070490&
%PEER_E_DISK_FULL                     = &H80070070&
%PEER_E_ALREADY_EXISTS                = &H80070087&

'#pragma warning(pop)


'/////////////////////////////////////////////////////////////////////////////
'//
'// These GUIDs are outside conditional includes so you can
'//   #include <p2p.h>   in precompiled header
'// then
'//   #include <initguid.h>  in a single source file
'//   #include <p2p.h>   in that source file a second time to instantiate the GUIDs

'#ifdef DEFINE_GUID

'#ifndef NO_P2P_GROUP

'DEFINE_GUID(PEER_GROUP_ROLE_ADMIN, /* 04387127-aa56-450a-8ce5-4f565c6790f4 */
'    0x04387127, 0xaa56, 0x450a, 0x8c, 0xe5, 0x4f, 0x56, 0x5c, 0x67, 0x90, 0xf4);
$PEER_GROUP_ROLE_ADMIN = GUID$("{04387127-aa56-450a-8ce5-4f565c6790f4}")

'DEFINE_GUID(PEER_GROUP_ROLE_MEMBER, /* f12dc4c7-0857-4ca0-93fc-b1bb19a3d8c2 */
'    0xf12dc4c7, 0x0857, 0x4ca0, 0x93, 0xfc, 0xb1, 0xbb, 0x19, 0xa3, 0xd8, 0xc2);
$PEER_GROUP_ROLE_MEMBER = GUID$("{f12dc4c7-0857-4ca0-93fc-b1bb19a3d8c2}")

'#if NTDDI_VERSION >= NTDDI_VISTA
'DEFINE_GUID(PEER_GROUP_ROLE_INVITING_MEMBER, /* 4370fd89-dc18-4cfb-8dbf-9853a8a9f905 */
'    0x4370fd89, 0xdc18, 0x4cfb, 0x8d, 0xbf, 0x98, 0x53, 0xa8, 0xa9, 0xf9, 0x05);
$PEER_GROUP_ROLE_INVITING_MEMBER = GUID$("{4370fd89-dc18-4cfb-8dbf-9853a8a9f905}")
'#endif

'#endif // NO_P2P_GROUP

'#ifndef NO_P2P_COLLABORATION
'DEFINE_GUID(PEER_COLLAB_OBJECTID_USER_PICTURE, /* dd15f41f-fc4e-4922-b035-4c06a754d01d */
'    0xdd15f41f, 0xfc4e, 0x4922, 0xb0, 0x35, 0x4c, 0x06, 0xa7, 0x54, 0xd0, 0x1d);
$PEER_COLLAB_OBJECTID_USER_PICTURE = GUID$("{dd15f41f-fc4e-4922-b035-4c06a754d01d}")
'#endif

'#endif // DEFINE_GUID

