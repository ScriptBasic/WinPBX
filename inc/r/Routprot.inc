' ########################################################################################
' Microsoft Windows
' File: Routprot.inc
' Contents: Include file for Routing Protocol inteface to Router Managers
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ROUTPROT_INC = 1

#INCLUDE ONCE "stm.inc"
#INCLUDE ONCE "nldef.inc"
#INCLUDE ONCE "in6addr.inc"

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Supported functionality flags                                            //
'//                                                                          //
'// ROUTING                   Imports Routing Table Manager APIs             //
'// SERVICES                  Exports Service Table Manager APIs             //
'// DEMAND_UPDATE_ROUTES     IP and IPX RIP support for Autostatic           //
'// DEMAND_UPDATE_SERVICES   IPX SAP, NLSP support for Autostatic            //
'// ADD_ALL_INTERFACES       Adds all interfaces, even if no info is present //
'// MULTICAST                Supports multicast                              //
'// POWER                    Power Manageable                                //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

%RF_ROUTING              = &H00000001???
%RF_DEMAND_UPDATE_ROUTES = &H00000004???
%RF_ADD_ALL_INTERFACES   = &H00000010???
%RF_MULTICAST            = &H00000020???
%RF_POWER                = &H00000040???

'#if MPR50
'#define MS_ROUTER_VERSION       0x00000500
'#else
'#error Router version not defined
'#endif

' enum _ROUTING_PROTOCOL_EVENTS
%ROUTER_STOPPED             = 0   ' // Result is empty
%SAVE_GLOBAL_CONFIG_INFO    = 1   ' // Result is empty
%SAVE_INTERFACE_CONFIG_INFO = 2   ' // Result is interface index
                                  ' // for which config info is to be saved.
%UPDATE_COMPLETE            = 3   ' // Result is UPDATE_COMPLETE_MESSAGE structure


' enum _NET_INTERFACE_TYPE
%PERMANENT = 0
%DEMAND_DIAL = 1
%LOCAL_WORKSTATION_DIAL = 2
%REMOTE_WORKSTATION_DIAL = 3

'//
'// Interface Receive Types
'//

%IR_PROMISCUOUS                = 0
%IR_PROMISCUOUS_MULTICAST      = 1

'typedef struct _SUPPORT_FUNCTIONS
'{
'    union
'    {
'        ULONGLONG   _Align8;

'        struct
'        {
'            DWORD   dwVersion;
'            DWORD   dwReserved;
'        };
'    };

'    //
'    // Function called by routing protocol to initiate demand dial connection
'    //

'    OUT DWORD
'    (WINAPI *DemandDialRequest)(
'        IN      DWORD           ProtocolId,
'        IN      DWORD           InterfaceIndex
'        ) ;

'    //
'    // Can be called to set the interface's receive capability
'    // See IR_Xxx values above
'    //

'    OUT DWORD
'    (WINAPI *SetInterfaceReceiveType)(
'        IN      DWORD           ProtocolId,
'        IN      DWORD           InterfaceIndex,
'        IN      DWORD           InterfaceReceiveType,
'        IN      BOOL            bActivate
'        );

'    //
'    // Must be called by every protocol to set the route preference
'    // and perform other validation
'    //

'    OUT DWORD
'    (WINAPI *ValidateRoute)(
'        IN      DWORD           ProtocolId,
'        IN      PVOID           RouteInfo,
'        IN      PVOID           DestAddress OPTIONAL
'        );


'    //
'    // The following entrypoints are provided as a way for getting
'    // information that spans components
'    //

'    OUT DWORD
'    (WINAPI *MIBEntryCreate)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwEntrySize,
'        IN      LPVOID          lpEntry
'        );

'    OUT DWORD
'    (WINAPI *MIBEntryDelete)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwEntrySize,
'        IN      LPVOID          lpEntry
'        );

'    OUT DWORD
'    (WINAPI *MIBEntrySet)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwEntrySize,
'        IN      LPVOID          lpEntry
'        );

'    OUT DWORD
'    (WINAPI *MIBEntryGet)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwInEntrySize,
'        IN      LPVOID          lpInEntry,
'        IN OUT  LPDWORD         lpOutEntrySize,
'        OUT     LPVOID          lpOutEntry
'        );

'    OUT DWORD
'    (WINAPI *MIBEntryGetFirst)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwInEntrySize,
'        IN      LPVOID          lpInEntry,
'        IN OUT  LPDWORD         lpOutEntrySize,
'        OUT     LPVOID          lpOutEntry
'        );

'    OUT DWORD
'    (WINAPI *MIBEntryGetNext)(
'        IN      DWORD           dwRoutingPid,
'        IN      DWORD           dwInEntrySize,
'        IN      LPVOID          lpInEntry,
'        IN OUT  LPDWORD         lpOutEntrySize,
'        OUT     LPVOID          lpOutEntry
'        );

'    //
'    // Can be called to get the router ID value
'    //

'    OUT DWORD
'    (WINAPI *GetRouterId)(VOID);

'    OUT BOOL
'    (WINAPI *HasMulticastBoundary)(
'        IN      DWORD           dwIfIndex,
'        IN      DWORD           dwGroupAddress
'        );

'} SUPPORT_FUNCTIONS, *PSUPPORT_FUNCTIONS ;

'FUNCTION DemandDialRequest (BYVAL ProtocolId AS DWORD, BYVAL InterfaceIndex AS DWORD) AS DWORD
'FUNCTION SetInterfaceReceiveType (BYVAL ProtocolId AS DWORD, BYVAL InterfaceIndex AS DWORD, BYVAL InterfaceReceiveType AS DWORD, BYVAL bActivate AS LONG) AS DWORD
'FUNCTION ValidateRoute (BYVAL ProtocolId AS DWORD, BYVAL RouteInfo AS DWORD, BYVAL DestAddress AS DWORD) AS DWORD
'FUNCTION MIBEntryCreate (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD) AS DWORD
'FUNCTION MIBEntryDelete (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD) AS DWORD
'FUNCTION MIBEntrySet (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD) AS DWORD
'FUNCTION MIBEntryGet (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD, BYREF lpOutEntrySize AS DWORD, BYREF lpOutEntry AS DWORD) AS DWORD
'FUNCTION MIBEntryGetFirst (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD, BYREF lpOutEntrySize AS DWORD, BYREF lpOutEntry AS DWORD) AS DWORD
'FUNCTION MIBEntryGetNext (BYVAL dwRoutingPid AS DWORD, BYVAL dwEntrySize AS DWORD, BYVAL lpEntry AS DWORD, BYREF lpOutEntrySize AS DWORD, BYREF lpOutEntry AS DWORD) AS DWORD
'FUNCTION GetRouterId () AS DWORD
'FUNCTION HasMulticastBoundary (BYVAL dwIfIndex AS DWORD, BYVAL dwGroupAddress AS DWORD) AS LONG

' // Size = 8 bytes
TYPE SUPPORT_FUNCTIONS_UNION_STRUCT DWORD
   dwVersion  AS DWORD
   dwReserved AS DWORD
END TYPE

' // Size = 8 bytes
UNION SUPPORT_FUNCTIONS_UNION
   Align8 AS QUAD
   SUPPORT_FUNCTIONS_UNION_STRUCT
END UNION

' // Size = 56 bytes
TYPE SUPPORT_FUNCTIONS   ' Must be 8 byte aligned
   SUPPORT_FUNCTIONS_UNION
   pfnDemandDialRequest       AS DWORD
   pfnSetInterfaceReceiveType AS DWORD
   pfnValidateRoute           AS DWORD
   pfnMIBEntryCreate          AS DWORD
   pfnMIBEntryDelete          AS DWORD
   pfnMIBEntrySet             AS DWORD
   pfnMIBEntryGet             AS DWORD
   pfnMIBEntryGetFirst        AS DWORD
   pfnMIBEntryGetNext         AS DWORD
   pfnGetRouterId             AS DWORD
   pfnHasMulticastBoundary    AS DWORD
   alignment__                AS DWORD
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// All IP Protocols must use the protocol ids defined in the range below.   //
'// Protocols not identified below can use any unassigned number BELOW       //
'// 0xffff0000                                                               //
'//                                                                          //
'// NOTE: These numbers have been chosen to coincide with MIB-II protocol    //
'// numbers. Allocation should not be arbitrary.                             //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'//
'// See nldef.h for the IANA assigned values of PROTO_IP_*.
'//

'%PROTO_IP_OTHER     = 1
'%PROTO_IP_LOCAL     = 2
'%PROTO_IP_NETMGMT   = 3
'%PROTO_IP_ICMP      = 4
'%PROTO_IP_EGP       = 5
'%PROTO_IP_GGP       = 6
'%PROTO_IP_HELLO     = 7
'%PROTO_IP_RIP       = 8
%PROTO_IP_IS_IS     = 9
%PROTO_IP_ES_IS     = 10
%PROTO_IP_CISCO     = 11
'%PROTO_IP_BBN       = 12
'%PROTO_IP_OSPF      = 13
'%PROTO_IP_BGP       = 14

'' //
'' // The multicast protocol IDs
'' //

%PROTO_IP_MSDP      =  9
%PROTO_IP_IGMP      = 10
%PROTO_IP_BGMP      = 11

' //
' // The IPRTRMGR_PID is 10000 ' // 0x00002710
' //

%PROTO_IP_VRRP              = 112
%PROTO_IP_BOOTP             = 9999    ' // 0x0000270F

'//included for DHCPv6 Relay Agent
%PROTO_IPV6_DHCP            = 999     ' // 0x000003E7

%PROTO_IP_NT_AUTOSTATIC     = 10002   ' // 0x00002712
%PROTO_IP_DNS_PROXY         = 10003   ' // 0x00002713
%PROTO_IP_DHCP_ALLOCATOR    = 10004   ' // 0x00002714
%PROTO_IP_NAT               = 10005   ' // 0x00002715
%PROTO_IP_NT_STATIC         = 10006   ' // 0x00002716
%PROTO_IP_NT_STATIC_NON_DOD = 10007   ' // 0x00002717
%PROTO_IP_DIFFSERV          = 10008   ' // 0x00002718
%PROTO_IP_MGM               = 10009   ' // 0x00002719
%PROTO_IP_ALG               = 10010   ' // 0x0000271A
%PROTO_IP_H323              = 10011   ' // 0x0000271B
%PROTO_IP_FTP               = 10012   ' // 0x0000271C
%PROTO_IP_DTP               = 10013   ' // 0x0000271D

'//
'// For all future development, the following macro must be used to generate
'// Ids
'//

'//
'//  Type            -   2 bits
'//  Vendor          -  14 bits
'//  ProtocolId      -  16 bits
'//

'#define PROTOCOL_ID(Type, VendorId, ProtocolId) \
'    (((Type & 0x03)<<30)|((VendorId & 0x3FFF)<<16)|(ProtocolId & 0xFFFF))

FUNCTION PROTOCOL_ID (BYVAL dwType AS DWORD, BYVAL VendorId AS DWORD, BYVAL ProtocolId AS DWORD) AS DWORD
   dwType = dwType AND &H03?
   SHIFT LEFT dwType, 30
   VendorId = VendorId AND &H3FFF??
   SHIFT LEFT VendorId, 16
   ProtocolId = ProtocolId AND &HFFFF??
   FUNCTION = dwType OR VendorId OR ProtocolId
END FUNCTION

'//
'//  |----|----|----|----|----|----|----|----|
'//   Ty*** Vendor Id *** StandardProtocolId
'//

'#define TYPE_FROM_PROTO_ID(X)       (((X) >> 30) & 0x03)
'#define VENDOR_FROM_PROTO_ID(X)     (((X) >> 16) & 0x3FFF)
'#define PROTO_FROM_PROTO_ID(X)      ((X) & 0xFFFF)

FUNCTION TYPE_FROM_PROTO_ID (BYVAL X AS DWORD) AS BYTE
   SHIFT RIGHT X, 30
   FUNCTION = X AND &H03?
END FUNCTION

FUNCTION VENDOR_FROM_PROTO_ID (BYVAL X AS DWORD) AS WORD
   SHIFT RIGHT X, 16
   FUNCTION = X AND &H3FFF??
END FUNCTION

MACRO PROTO_FROM_PROTO_ID (X) = X AND &HFFFF??

'//
'// Types MS0 and MS1 are Microsoft Reserved
'// A protocol that supports both unicast and multicast should use type
'// MCAST
'//

%PROTO_TYPE_UCAST           = 0
%PROTO_TYPE_MCAST           = 1
%PROTO_TYPE_MS0             = 2
%PROTO_TYPE_MS1             = 3

%PROTO_VENDOR_MS0           = &H0000??
%PROTO_VENDOR_MS1           = &H137??   ' // 311
%PROTO_VENDOR_MS2           = &H3FFF??

'#define MS_IPV6_DHCP                 \
'    PROTOCOL_ID(PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IPV6_DHCP)
%MS_IPV6_DHCP = 999

'// included for IPV6 DHCP
'#define MS_IP_BOOTP                 \
'    PROTOCOL_ID(PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_BOOTP)
%MS_IP_BOOTP = 9999

'#define MS_IP_RIP                   \
'    PROTOCOL_ID(PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_RIP)
%MS_IP_RIP = 8

'#define MS_IP_OSPF                  \
'    PROTOCOL_ID(PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_OSPF)
%MS_IP_OSPF = 13

'#define MS_IP_BGP                   \
'    PROTOCOL_ID(PROTO_TYPE_UCAST, PROTO_VENDOR_MS1, PROTO_IP_BGP)
%MS_IP_BGP = &H137000E???

'#define MS_IP_IGMP                  \
'    PROTOCOL_ID(PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_IGMP)
%MS_IP_IGMP = &H4137000A???

'#define MS_IP_BGMP                  \
'    PROTOCOL_ID(PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_BGMP)
%MS_IP_BGMP = &H4137000B???

'#define MS_IP_MSDP                  \
'    PROTOCOL_ID(PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_MSDP)
%MS_IP_MSDP = &H41370009???

'#define MS_IP_DNS_PROXY             \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DNS_PROXY)
%MS_IP_DNS_PROXY = &H81372713???

'#define MS_IP_DHCP_ALLOCATOR        \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DHCP_ALLOCATOR)
%MS_IP_DHCP_ALLOCATOR = &H81372714???

'#define MS_IP_NAT                   \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_NAT)
%MS_IP_NAT = &H81372715???

'#define MS_IP_DIFFSERV              \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DIFFSERV)
%MS_IP_DIFFSERV = &H81372718???

'#define MS_IP_MGM                   \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_MGM)
%MS_IP_MGM = &H81372719???

'#define MS_IP_VRRP                  \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_VRRP)
%MS_IP_VRRP = &H81370070???

'#define MS_IP_DTP                   \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DTP)
%MS_IP_DTP = &H8137271D???

'#define MS_IP_H323                  \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_H323)
%MS_IP_H323 = &H8137271B???

'#define MS_IP_FTP                   \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_FTP)
%MS_IP_FTP = &H8137271C???

'#define MS_IP_ALG                   \
'    PROTOCOL_ID(PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_ALG)
%MS_IP_ALG = &H8137271A???

'//
'// All IPX Protocols must use the protocol ids defined in the range below.
'// Protocols not identified below can use any unassigned number greater than
'// IPX_PROTOCOL_BASE.
'//

%IPX_PROTOCOL_BASE   = &H0001ffff???
%IPX_PROTOCOL_RIP    = %IPX_PROTOCOL_BASE + 1
' The following two equates are included in the XP SDK but not in the Vista SDK
%IPX_PROTOCOL_SAP    = %IPX_PROTOCOL_BASE + 2
%IPX_PROTOCOL_NLSP   = %IPX_PROTOCOL_BASE + 3

' // Size = 12 bytes
TYPE UPDATE_COMPLETE_MESSAGE DWORD
   InterfaceIndex AS DWORD   ' ULONG
   UpdateType     AS DWORD   ' ULONG // DEMAND_UPDATE_ROUTES, DEMAND_UPDATE_SERVICES
   UpdateStatus   AS DWORD   ' ULONG // NO_ERROR if successfull
END TYPE

'//
'//  Message returned in Result parameter to GET_EVENT_MESSAGE api call.
'//  UpdateCompleteMessage   returned for UPDATE_COMPLETE message
'//  InterfaceIndex          returned for SAVE_INTERFACE_CONFIG_INFO message
'//

' // Size = 12 bytes
UNION MESSAGE DWORD
   UpdateCompleteMessage AS UPDATE_COMPLETE_MESSAGE
   InterfaceIndex        AS DWORD
END UNION

'//
'// Routing Interface Status types
'//

%RIS_INTERFACE_ADDRESS_CHANGE = 0
%RIS_INTERFACE_ENABLED        = 1
%RIS_INTERFACE_DISABLED       = 2
%RIS_INTERFACE_MEDIA_PRESENT  = 3
%RIS_INTERFACE_MEDIA_ABSENT   = 4

'//
'// IPX Adapter Binding Info
'//

' The following structure is included in the XP SDK but not in the Vista/Windows 7 SDKs
' // Size = 28 bytes
TYPE IPX_ADAPTER_BINDING_INFO BYTE
   AdapterIndex  AS DWORD   ' ULONG
   Network(3)    AS BYTE    ' UCHAR[4]
   LocalNode(5)  AS BYTE    ' UCHAR[6]
   RemoteNode(5) AS BYTE    ' UCHAR[6]
   MaxPacketSize AS DWORD   ' ULONG
   LinkSpeed     AS DWORD   ' ULONG
END TYPE

'//
'// IP Adapter Binding Info
'// This is the information associated with an ADDRESS_ARRIVAL event
'// An address arrival may have AddressCount == 0, this implies a unnumbered
'// interface
'//

' // Size = 8 bytes
TYPE IP_LOCAL_BINDING DWORD
   Address AS DWORD
   Mask    AS DWORD
END TYPE

' // Size = 20 bytes
TYPE IPV6_LOCAL_BINDING DWORD
   Address      AS IN6_ADDR
   PrefixLength AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE IP_ADAPTER_BINDING_INFO   ' Must be 8 byte aligned
   AddressCount  AS DWORD              ' ULONG
   RemoteAddress AS DWORD              ' DWORD
   Mtu           AS DWORD              ' ULONG
   alignment__   AS DWORD
   Speed         AS QUAD               ' ULONGULONG
   'Address()     AS IP_LOCAL_BINDING
END TYPE

'#define SIZEOF_IP_BINDING(X)                                \
'    (FIELD_OFFSET(IP_ADAPTER_BINDING_INFO,Address[0]) +     \
'     ((X) * sizeof(IP_LOCAL_BINDING)))


' // Size = 32 bytes
TYPE IPV6_ADAPTER_BINDING_INFO   ' Must be 8 byte aligned
   AddressCount  AS DWORD                ' ULONG
   RemoteAddress AS IN6_ADDR
   Mtu           AS DWORD                ' ULONG
   Speed         AS QUAD                 ' ULONGLONG
   'Address()     AS IPV6_LOCAL_BINDING
END TYPE

'#define SIZEOF_IPV6_BINDING(X)                                \
'    (FIELD_OFFSET(IPV6_ADAPTER_BINDING_INFO,Address[0]) +     \
'     ((X) * sizeof(IPV6_LOCAL_BINDING)))


'typedef
'DWORD
'(WINAPI * PSTART_PROTOCOL) (
'    IN HANDLE               NotificationEvent,
'    IN PSUPPORT_FUNCTIONS   SupportFunctions,
'    IN LPVOID               GlobalInfo,
'    IN ULONG                StructureVersion,
'    IN ULONG                StructureSize,
'    IN ULONG                StructureCount
'    );

'FUNCTION START_PROTOCOL ( _
'   BYVAL NotificationEvent AS DWORD _
' , BYREF SupportFunctions AS SUPPORT_FUNCTIONS _
' , BYVAL GlobalInfo AS DWORD _
' , BYVAL StructureVersion AS DWORD _
' , BYVAL StructureSize AS DWORD _
' , BYVAL StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PSTART_COMPLETE) (
'    VOID
'    );

'FUNCTION START_COMPLETE () AS DWORD

'typedef
'DWORD
'(WINAPI * PSTOP_PROTOCOL) (
'    VOID
'    );

'FUNCTION STOP_PROTOCOL () AS DWORD

'typedef
'DWORD
'(WINAPI * PADD_INTERFACE) (
'    IN LPWSTR               InterfaceName,
'    IN ULONG                InterfaceIndex,
'    IN NET_INTERFACE_TYPE   InterfaceType,
'    IN DWORD                MediaType,
'    IN WORD                 AccessType,
'    IN WORD                 ConnectionType,
'    IN PVOID                InterfaceInfo,
'    IN ULONG                StructureVersion,
'    IN ULONG                StructureSize,
'    IN ULONG                StructureCount
'    );

'FUNCTION ADD_INTERFACE ( _
'   BYVAL InterfaceName AS DWORD _
' , BYVAL InterfaceIndex AS DWORD _
' , BYVAL InterfaceType AS DWORD _
' , BYVAL MediaType AS DWORD
' , BYVAL AccessType AS WORD _
' , BYVAL ConnectionType AS WORD _
' , BYVAL InterfaceInfo AS DWORD _
' , BYVAL StructureVersion AS DWORD _
' , BYVAL StructureSize AS DWORD _
' , BYVAL StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PDELETE_INTERFACE) (
'    IN ULONG   InterfaceIndex
'    );

'FUNCTION DELETE_INTERFACE ( _
'   BYVAL InterfaceIndex AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PGET_EVENT_MESSAGE) (
'    OUT ROUTING_PROTOCOL_EVENTS  *Event,
'    OUT MESSAGE                  *Result
'    );

'FUNCTION GET_EVENT_MESSAGE ( _
'   BYREF tEvent AS OUTING_PROTOCOL_EVENTS _
' , BYREF tResult AS MESSAGE _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PGET_INTERFACE_INFO) (
'    IN      ULONG   InterfaceIndex,
'    IN      PVOID   InterfaceInfo,
'    IN  OUT PULONG  BufferSize,
'    OUT     PULONG  StructureVersion,
'    IN      PULONG  StructureSize,
'    OUT     PULONG  StructureCount
'    );

'FUNCTION GET_INTERFACE_INFO ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL InterfaceInfo AS DWORD _
' , BYREF BufferSize AS DWORD _
' , BYREF StructureVersion AS DWORD _
' , BYREF StructureSize AS DWORD _
' , BYREF StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PSET_INTERFACE_INFO) (
'    IN ULONG   InterfaceIndex,
'    IN PVOID   InterfaceInfo,
'    IN ULONG   StructureVersion,
'    IN ULONG   StructureSize,
'    IN ULONG   StructureCount
'    );

'FUNCTION SET_INTERFACE_INFO ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL InterfaceInfo AS DWORD _
' , BYVAL StructureVersion AS DWORD _
' , BYVAL StructureSize AS DWORD _
' , BYVAL StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PINTERFACE_STATUS) (
'    IN ULONG   InterfaceIndex,
'    IN BOOL    InterfaceActive,
'    IN DWORD   StatusType,
'    IN PVOID   StatusInfo
'    );

'FUNCTION INTERFACE_STATUS ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL InterfaceActive AS LONG _
' , BYVAL StatusType AS DWORD _
' , BYVAL StatusInfo AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PQUERY_POWER) (
'    IN  DWORD   PowerType
'    );

'FUNCTION QUERY_POWER ( _
'   BYVAL PowerType AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PSET_POWER) (
'    IN  DWORD   PowerType
'    );

'FUNCTION SET_POWER ( _
'   BYVAL PowerType AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PGET_GLOBAL_INFO) (
'    IN     PVOID    GlobalInfo,
'    IN OUT PULONG   BufferSize,
'    OUT    PULONG   StructureVersion,
'    OUT    PULONG   StructureSize,
'    OUT    PULONG   StructureCount
'    );

'FUNCTION GET_GLOBAL_INFO ( _
'   BYVAL GlobalInfo AS DWORD _
' , BYREF BufferSize AS DWORD _
' , BYREF StructureVersion AS DWORD _
' , BYREF StructureSize AS DWORD _
' , BYREF StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PSET_GLOBAL_INFO) (
'    IN  PVOID   GlobalInfo,
'    IN  ULONG   StructureVersion,
'    IN  ULONG   StructureSize,
'    IN  ULONG   StructureCount
'    );

'FUNCTION SET_GLOBAL_INFO ( _
'   BYVAL GlobalInfo AS DWORD _
' , BYVAL StructureVersion AS DWORD _
' , BYVAL StructureSize AS DWORD _
' , BYVAL StructureCount AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PDO_UPDATE_ROUTES) (
'    IN ULONG   InterfaceIndex
'    );

'FUNCTION DO_UPDATE_ROUTES ( _
'   BYVAL InterfaceIndex AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_CREATE) (
'    IN ULONG    InputDataSize,
'    IN PVOID    InputData
'    );

'FUNCTION MIB_CREATE ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_DELETE) (
'    IN ULONG    InputDataSize,
'    IN PVOID    InputData
'    );

'FUNCTION MIB_DELETE ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_GET) (
'    IN  ULONG   InputDataSize,
'    IN  PVOID   InputData,
'    OUT PULONG  OutputDataSize,
'    OUT PVOID   OutputData
'    );

'FUNCTION MIB_GET ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' , BYREF OutputDataSize AS DWORD _
' , BYREF OutputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_SET) (
'    IN ULONG   InputDataSize,
'    IN PVOID   InputData
'    );

'FUNCTION MIB_SET ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_GET_FIRST) (
'    IN  ULONG   InputDataSize,
'    IN  PVOID   InputData,
'    OUT PULONG  OutputDataSize,
'    OUT PVOID   OutputData
'    );

'FUNCTION MIB_GET_FIRST ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' , BYREF OutputDataSize AS DWORD _
' , BYREF OutputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_GET_NEXT) (
'    IN  ULONG   InputDataSize,
'    IN  PVOID   InputData,
'    OUT PULONG  OutputDataSize,
'    OUT PVOID   OutputData
'    );

'FUNCTION MIB_GET_NEXT ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' , BYREF OutputDataSize AS DWORD _
' , BYREF OutputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_SET_TRAP_INFO) (
'    IN  HANDLE  Event,
'    IN  ULONG   InputDataSize,
'    IN  PVOID   InputData,
'    OUT PULONG  OutputDataSize,
'    OUT PVOID   OutputData
'    );

'FUNCTION MIB_SET_TRAP_INFO ( _
'   BYVAL hEvent AS DWORD _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' , BYREF OutputDataSize AS DWORD _
' , BYREF OutputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI * PMIB_GET_TRAP_INFO) (
'    IN  ULONG   InputDataSize,
'    IN  PVOID   InputData,
'    OUT PULONG  OutputDataSize,
'    OUT PVOID   OutputData
'    );

'FUNCTION MIB_GET_TRAP_INFO ( _
'   BYVAL InputDataSize AS DWORD _
' , BYVAL InputData AS DWORD _
' , BYREF OutputDataSize AS DWORD _
' , BYREF OutputData AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI *PCONNECT_CLIENT) (
'    IN ULONG    InterfaceIndex,
'    IN PVOID    ClientAddress
'    );

'FUNCTION CONNECT_CLIENT ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL ClientAddress AS DWORD _
' ) AS DWORD

'typedef
'DWORD
'(WINAPI *PDISCONNECT_CLIENT) (
'    IN ULONG    InterfaceIndex,
'    IN PVOID    ClientAddress
'    );

'FUNCTION DISCONNECT_CLIENT ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL ClientAddress AS DWORD _
' ) AS DWORD

'//
'// InterfaceFlags used with the GetNeighbors() call below
'//

%MRINFO_TUNNEL_FLAG   = &H01???
%MRINFO_PIM_FLAG      = &H04???
%MRINFO_DOWN_FLAG     = &H10???
%MRINFO_DISABLED_FLAG = &H20???
%MRINFO_QUERIER_FLAG  = &H40???
%MRINFO_LEAF_FLAG     = &H80???

'typedef
'DWORD
'(WINAPI *PGET_NEIGHBORS) (
'    IN     DWORD  InterfaceIndex,
'    IN     PDWORD NeighborList,
'    IN OUT PDWORD NeighborListSize,
'       OUT PBYTE  InterfaceFlags
'    );

'FUNCTION GET_NEIGHBORS ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL NeighborList AS DWORD _
' , BYREF NeighborListSize AS DWORD _
' , BYREF InterfaceFlags AS BYTE _
' ) AS DWORD

'//
'// StatusCode values used with the GetMfeStatus() call below.
'// The protocol should return the highest-valued one that applies.
'//

%MFE_NO_ERROR          = 0 ' // none of the below events
%MFE_REACHED_CORE      = 1 ' // this router is an RP/core for the group

'//
'// StatusCode values set by oif owner only
'//

%MFE_OIF_PRUNED        = 5 ' // no downstream receivers exist on oif

'//
'// StatusCode values set by iif owner only
'//

%MFE_PRUNED_UPSTREAM   = 4  ' // a prune was send upstream
%MFE_OLD_ROUTER        = 11 ' // upstream nbr doesn't support mtrace

'//
'// StatusCode values which are used only by the Router Manager itself:
'//

%MFE_NOT_FORWARDING    = 2  ' // not fwding for an unspecified reason
%MFE_WRONG_IF          = 3  ' // mtrace received on iif
%MFE_BOUNDARY_REACHED  = 6  ' // iif or oif is admin scope boundary
%MFE_NO_MULTICAST      = 7  ' // oif is not multicast-enabled
%MFE_IIF               = 8  ' // mtrace arrived on iif
%MFE_NO_ROUTE          = 9  ' // router has no route that matches
%MFE_NOT_LAST_HOP      = 10 ' // router is not the proper last-hop router
%MFE_PROHIBITED        = 12 ' // mtrace is administratively prohibited
%MFE_NO_SPACE          = 13 ' // not enough room in packet

'typedef
'DWORD
'(WINAPI *PGET_MFE_STATUS) (
'    IN     DWORD  InterfaceIndex,
'    IN     DWORD  GroupAddress,
'    IN     DWORD  SourceAddress,
'    OUT    PBYTE  StatusCode
'    );

'FUNCTION GET_MFE_STATUS ( _
'   BYVAL InterfaceIndex AS DWORD _
' , BYVAL GroupAddress AS DWORD _
' , BYVAL SourceAddress AS DWORD _
' , BYREF StatusCode AS BYTE _
' ) AS DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// This is the structure passed between the router manager and a protocol   //
'// upon registration.                                                       //
'//                                                                          //
'// IN OUT DWORD dwVersion                                                   //
'// This is filled by the router manager to indicate the version it supports.//
'// The DLL MUST set this to the version that the protocol will support.     //
'//                                                                          //
'// IN DWORD dwProtocolId                                                    //
'// This the protocol the router manager is expecting the DLL to register.   //
'// If the DLL does not support this protocol, it MUST return                //
'// ERROR_NOT_SUPPORTED                                                      //
'// A DLL will be called once for every protocol it supports                 //
'//                                                                          //
'// IN OUT DWORD fSupportedFunctionality                                     //
'// These are the flags denoting the functionality the router manager        //
'// supports. The DLL MUST reset this to the functionality that it supports. //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'typedef struct _MPR50_ROUTING_CHARACTERISTICS
'{
'    DWORD               dwVersion;
'    DWORD               dwProtocolId;
'    DWORD               fSupportedFunctionality;

'    PSTART_PROTOCOL     pfnStartProtocol;
'    PSTART_COMPLETE     pfnStartComplete;
'    PSTOP_PROTOCOL      pfnStopProtocol;
'    PGET_GLOBAL_INFO    pfnGetGlobalInfo;
'    PSET_GLOBAL_INFO    pfnSetGlobalInfo;
'    PQUERY_POWER        pfnQueryPower;
'    PSET_POWER          pfnSetPower;

'    PADD_INTERFACE      pfnAddInterface;
'    PDELETE_INTERFACE   pfnDeleteInterface;
'    PINTERFACE_STATUS   pfnInterfaceStatus;
'    PGET_INTERFACE_INFO pfnGetInterfaceInfo;
'    PSET_INTERFACE_INFO pfnSetInterfaceInfo;

'    PGET_EVENT_MESSAGE  pfnGetEventMessage;

'    PDO_UPDATE_ROUTES   pfnUpdateRoutes;

'    PCONNECT_CLIENT     pfnConnectClient;
'    PDISCONNECT_CLIENT  pfnDisconnectClient;

'    PGET_NEIGHBORS      pfnGetNeighbors;
'    PGET_MFE_STATUS     pfnGetMfeStatus;

'    PMIB_CREATE         pfnMibCreateEntry;
'    PMIB_DELETE         pfnMibDeleteEntry;
'    PMIB_GET            pfnMibGetEntry;
'    PMIB_SET            pfnMibSetEntry;
'    PMIB_GET_FIRST      pfnMibGetFirstEntry;
'    PMIB_GET_NEXT       pfnMibGetNextEntry;
'    PMIB_SET_TRAP_INFO  pfnMibSetTrapInfo;
'    PMIB_GET_TRAP_INFO  pfnMibGetTrapInfo;

'}MPR50_ROUTING_CHARACTERISTICS;

' // Size = 116 bytes
TYPE MPR50_ROUTING_CHARACTERISTICS DWORD
   dwVersion               AS DWORD
   dwProtocolId            AS DWORD
   fSupportedFunctionality AS DWORD
   pfnStartProtocol        AS DWORD
   pfnStartComplete        AS DWORD
   pfnStopProtocol         AS DWORD
   pfnGetGlobalInfo        AS DWORD
   pfnSetGlobalInfo        AS DWORD
   pfnQueryPower           AS DWORD
   pfnSetPower             AS DWORD
   pfnAddInterface         AS DWORD
   pfnDeleteInterface      AS DWORD
   pfnInterfaceStatus      AS DWORD
   pfnGetInterfaceInfo     AS DWORD
   pfnSetInterfaceInfo     AS DWORD
   pfnGetEventMessage      AS DWORD
   pfnUpdateRoutes         AS DWORD
   pfnConnectClient        AS DWORD
   pfnDisconnectClient     AS DWORD
   pfnGetNeighbors         AS DWORD
   pfnGetMfeStatus         AS DWORD
   pfnMibCreateEntry       AS DWORD
   pfnMibDeleteEntry       AS DWORD
   pfnMibGetEntry          AS DWORD
   pfnMibSetEntry          AS DWORD
   pfnMibGetFirstEntry     AS DWORD
   pfnMibGetNextEntry      AS DWORD
   pfnMibSetTrapInfo       AS DWORD
   pfnMibGetTrapInfo       AS DWORD
END TYPE

'#if MPR50
'typedef MPR50_ROUTING_CHARACTERISTICS MPR_ROUTING_CHARACTERISTICS;
'#endif

'typedef MPR_ROUTING_CHARACTERISTICS *PMPR_ROUTING_CHARACTERISTICS;

MACRO MPR_ROUTING_CHARACTERISTICS = MPR50_ROUTING_CHARACTERISTICS

'//
'// All routing protocols must export the following entry point.
'// The router manager calls this function to allow the routing
'// protocol to register
'//

'#define REGISTER_PROTOCOL_ENTRY_POINT           RegisterProtocol
'#define REGISTER_PROTOCOL_ENTRY_POINT_STRING    "RegisterProtocol"

'typedef
'DWORD
'(WINAPI * PREGISTER_PROTOCOL) (
'    IN OUT PMPR_ROUTING_CHARACTERISTICS pRoutingChar,
'    IN OUT PMPR_SERVICE_CHARACTERISTICS pServiceChar
'    );

'FUNCTION REGISTER_PROTOCOL ( _
'   BYREF pRoutingChar AS DWORD _
' , BYREF pServiceChar AS DWORD _
' ) AS DWORD
