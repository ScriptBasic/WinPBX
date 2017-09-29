' ########################################################################################
' Microsoft Windows
' File: netioapi.inc
' Contents: Definitions for version agnostic IP helper APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NETIOAPI_INC = 1

#INCLUDE ONCE "NtDDNdis.inc"

'/*++

'Module Name:

'    netioapi.h

'Abstract:

'    This module contains definitions for version agnostic IP helper APIs.


'Environment:

'    User mode or kernel mode.

'    In user mode this file should be included from iphlpapi.h,
'    after including the following headers:

'    #include <ws2def.h>
'    #include <ws2ipdef.h>

'    In kernel mode the following files should be included.

'    #include <ntddk.h>

'    For all APIs, the caller IRQL should be less than DISPATCH_LEVEL.

'Notes:

'    Please follow these notes to maintain consistency within this API set,
'    as well as across the legacy IP helper API:

'    1. Express objects and functions in terms of MIB operations if possible.
'       E.g. MIB_UNICASTIPADDRESS_ROW structure is associated with the
'       GetUnicastIpAddress() function.

'    2. Use the NETIO/RTL coding convention for naming structures and functions.
'       When modifying a structure with a legacy IP helper API counterpart,
'       try to maintain the same name (without abbreviations).
'       The hungarian convention must not be used and, for structure fields,
'       the structure name need not prefix the field.

'    3. For versioning a new structure or API,
'       append a version number to the constructs.

'    4. The functions in this file are grouped by the object they operate upon.
'       Within the group, they are sorted alphabetically.

'--*/

'//
'// General types.
'//


#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

'#ifdef __IPHLPAPI_H__

'//
'// User Mode.  This file should be included from iphlpapi.h
'// User should include ws2ipdef.h to use these APIs.
'//

'#define NETIO_STATUS DWORD
'#define NETIO_SUCCESS(x) ((x) == NO_ERROR)
'#define NETIOAPI_API_ WINAPI

'#else

'//
'// Kernel Mode.
'//

#INCLUDE ONCE "ws2def.inc"
#INCLUDE ONCE "ws2ipdef.inc"
#INCLUDE ONCE "ifdef.inc"
#INCLUDE ONCE "nldef.inc"

'#define NETIO_STATUS NTSTATUS
'#define NETIO_SUCCESS(x) NT_SUCCESS(x)
'#define NETIOAPI_API_ NTAPI

'#endif

'#define NETIOAPI_API NETIO_STATUS NETIOAPI_API_

' enum _MIB_NOTIFICATION_TYPE
'// ParameterChange.
%MibParameterNotification = 0
'// Addition.
%MibAddInstance           = 1
'// Deletion.
%MibDeleteInstance        = 2
'// Initial notification.
%MibInitialNotification   = 3

'//
'// Interface management routines.
'//

'//
'// The MIB structure for Interface management routines.
'//

#IF %DEF(%WS2IPDEF_INC)
#INCLUDE ONCE "ntddndis.inc"

' // Size = 1 byte
TYPE InterfaceAndOperStatusFlags BYTE
   HardwareInterface AS BIT * 1 IN BYTE
   FilterInterface   AS BIT * 1
   ConnectorPresent  AS BIT * 1
   NotAuthenticated  AS BIT * 1
   NotMediaConnected AS BIT * 1
   Paused            AS BIT * 1
   LowPower          AS BIT * 1
   EndPointInterface AS BIT * 1
END TYPE

' // Size = 1352 bytes
TYPE MIB_IF_ROW2   ' Must be 8 byte aligned
   ' // Key structure.  Sorted by preference.
   InterfaceLuid         AS NET_LUID   ' NET_LUID
   InterfaceIndex        AS DWORD   ' NET_IFINDEX
   alignment1__          AS DWORD   ' // To keep 8 byte alignment
   ' // Read-Only fields.
   InterfaceGuid         AS GUID    ' GUID
   Alias                 AS WSTRINGZ * %IF_MAX_STRING_SIZE   ' WCHAR
   Description           AS WSTRINGZ * %IF_MAX_STRING_SIZE   ' WCHAR
   PhysicalAddressLength AS DWORD   ' ULONG
   PhysicalAddress       AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH   ' UCHAR
   PermanentPhysicalAddress AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH   ' UCHAR
   Mtu                   AS DWORD   ' ULONG
   Type                  AS DWORD   ' IFTYPE // Interface Type.
   TunnelType            AS LONG    ' TUNNEL_TYPE enum // Tunnel Type, if Type = IF_TUNNEL.
   MediaType             AS LONG    ' NDIS_MEDIUM enum
   PhysicalMediumType    AS LONG    ' NDIS_PHYSICAL_MEDIUM enum
   AccessType            AS LONG    ' NET_IF_ACCESS_TYPE enum
   DirectionType         AS LONG    ' NET_IF_DIRECTION_TYPE enum
   InterfaceAndOperStatusFlags
   alignment2__(6)       AS BYTE   ' // To keep 8 byte alignment
   OperStatus            AS LONG    ' IF_OPER_STATUS enum
   AdminStatus           AS LONG    ' NET_IF_ADMIN_STATUS enum
   MediaConnectState     AS LONG    ' NET_IF_MEDIA_CONNECT_STATE enum
   NetworkGuid           AS GUID    ' NET_IF_NETWORK_GUID
   ConnectionType        AS LONG    ' NET_IF_CONNECTION_TYPE enum
   ' // Statistics.
   TransmitLinkSpeed     AS QUAD    ' ULONG64
   ReceiveLinkSpeed      AS QUAD    ' ULONG64
   InOctets              AS QUAD    ' ULONG64
   InUcastPkts           AS QUAD    ' ULONG64
   InNUcastPkts          AS QUAD    ' ULONG64
   InDiscards            AS QUAD    ' ULONG64
   InErrors              AS QUAD    ' ULONG64
   InUnknownProtos       AS QUAD    ' ULONG64
   InUcastOctets         AS QUAD    ' ULONG64
   InMulticastOctets     AS QUAD    ' ULONG64
   InBroadcastOctets     AS QUAD    ' ULONG64
   OutOctets             AS QUAD    ' ULONG64
   OutUcastPkts          AS QUAD    ' ULONG64
   OutNUcastPkts         AS QUAD    ' ULONG64
   OutDiscards           AS QUAD    ' ULONG64
   OutErrors             AS QUAD    ' ULONG64
   OutUcastOctets        AS QUAD    ' ULONG64
   OutMulticastOctets    AS QUAD    ' ULONG64
   OutBroadcastOctets    AS QUAD    ' ULONG64
   OutQLen               AS QUAD    ' ULONG64
END TYPE

' // Size = 1360 bytes
TYPE MIB_IF_TABLE2   ' Must be 8 byte aligned
   NumEntries  AS DWORD         ' ULONG
   alignment__ AS DWORD         ' // To keep 8 byte alignment
   Table(0)    AS MIB_IF_ROW2   ' MIB_IF_ROW2 Table[ANY_SIZE]
END TYPE

DECLARE FUNCTION GetIfEntry2 IMPORT "Iphlpapi.dll" ALIAS "GetIfEntry2" ( _
   BYREF Row AS MIB_IF_ROW2 _                           ' __inout PMIB_IF_ROW2 Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves information for the specified interface on the local computer.

'Arguments:

'    Row - Supplies a MIB_IF_ROW2 structure with either the Luid or Index
'        initialized to that of the interface for which to retrieve
'        information.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1.  At least one of InterfaceLuid or InterfaceIndex must be specified.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetIfTable2 IMPORT "Iphlpapi.dll" ALIAS "GetIfTable2" ( _
   BYREF Table AS ANY _                                 ' __out PMIB_IF_TABLE2 *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the MIB-II interface table.

'Arguments:

'    Table - Returns the table of interfaces in a MIB_IFTABLE2 structure.
'        Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

' enum MIB_IF_TABLE_LEVEL
%MibIfTableNormal = 0
%MibIfTableRaw    = 1

DECLARE FUNCTION GetIfTable2Ex IMPORT "Iphlpapi.dll" ALIAS "GetIfTable2Ex" ( _
   BYVAL Level AS LONG _                                ' __in  MIB_IF_TABLE_LEVEL Level
 , BYREF Table AS ANY _                                 ' __out PMIB_IF_TABLE2 *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the MIB-II interface table.

'Arguments:

'    Table - Returns the table of interfaces in a MIB_IFTABLE2 structure.
'        Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

'//
'// IpInterface management routines.
'//

'//
'// The MIB structure for Network layer Interface management routines.
'//
' // Size = 168 bytes
TYPE MIB_IPINTERFACE_ROW   ' Must be 8 byte aligned
   ' // Key Structure
   Family                               AS WORD       ' ADDRESS_FAMILY
   alignment1__(5)                      AS BYTE       ' // To keep 8 byte alignment
   InterfaceLuid                        AS NET_LUID   ' NET_LUID
   InterfaceIndex                       AS DWORD      ' NET_IFINDEX
'   ' // Read-Write fields.
'   ' // Fields currently not exposed.
   MaxReassemblySize                    AS DWORD      ' ULONG
   InterfaceIdentifier                  AS QUAD       ' ULONG64
   MinRouterAdvertisementInterval       AS DWORD      ' ULONG
   MaxRouterAdvertisementInterval       AS DWORD      ' ULONG
   ' // Fileds currently exposed.
   AdvertisingEnabled                   AS BYTE       ' BOOLEAN
   ForwardingEnabled                    AS BYTE       ' BOOLEAN
   WeakHostSend                         AS BYTE       ' BOOLEAN
   WeakHostReceive                      AS BYTE       ' BOOLEAN
   UseAutomaticMetric                   AS BYTE       ' BOOLEAN
   UseNeighborUnreachabilityDetection   AS BYTE       ' BOOLEAN
   ManagedAddressConfigurationSupported AS BYTE       ' BOOLEAN
   OtherStatefulConfigurationSupported  AS BYTE       ' BOOLEAN
   AdvertiseDefaultRoute                AS BYTE       ' BOOLEAN
   alignment2__(2)                      AS BYTE       ' // To keep 8 byte alignment
   RouterDiscoveryBehavior              AS LONG       ' NL_ROUTER_DISCOVERY_BEHAVIOR enum
   DadTransmits                         AS DWORD      ' ULONG // DupAddrDetectTransmits in RFC 2462.
   BaseReachableTime                    AS DWORD      ' ULONG
   RetransmitTime                       AS DWORD      ' ULONG
   PathMtuDiscoveryTimeout              AS DWORD      ' ULONG // Path MTU discovery timeout (in ms).
   LinkLocalAddressBehavior             AS LONG       ' NL_LINK_LOCAL_ADDRESS_BEHAVIOR enum
   LinkLocalAddressTimeout              AS DWORD      ' ULONG // In ms.
   ZoneIndices(%ScopeLevelCount - 1)    AS DWORD      ' ULONG // Zone part of a SCOPE_ID.
   SitePrefixLength                     AS DWORD      ' ULONG
   Metric                               AS DWORD      ' ULONG
   NlMtu                                AS DWORD      ' ULONG
   ' // Read Only fields.
   Connected                            AS BYTE       ' BOOLEAN
   SupportsWakeUpPatterns               AS BYTE       ' BOOLEAN
   SupportsNeighborDiscovery            AS BYTE       ' BOOLEAN
   SupportsRouterDiscovery              AS BYTE       ' BOOLEAN
   ReachableTime                        AS DWORD      ' ULONG
   TransmitOffload                      AS NL_INTERFACE_OFFLOAD_ROD    ' NL_INTERFACE_OFFLOAD_ROD
   ReceiveOffload                       AS NL_INTERFACE_OFFLOAD_ROD    ' NL_INTERFACE_OFFLOAD_ROD
   ' // Disables using default route on the interface. This flag
   ' // can be used by VPN clients to restrict Split tunnelling.
   DisableDefaultRoutes                 AS BYTE       ' BOOLEAN
   alignment3__                         AS BYTE       ' // To keep 8 byte alignment
END TYPE

' // Size = 176 bytes
TYPE MIB_IPINTERFACE_TABLE   ' Must be 8 byte aligned
   NumEntries  AS DWORD                 ' ULONG
   alignment__ AS DWORD                 ' // To keep 8 byte alignment
   Table(0)    AS MIB_IPINTERFACE_ROW   '  MIB_IPINTERFACE_ROW Table[ANY_SIZE]
END TYPE

' // Size = 8 bytes
TYPE MIB_IFSTACK_ROW DWORD
   HigherLayerInterfaceIndex AS DWORD   ' NET_IFINDEX
   LowerLayerInterfaceIndex  AS DWORD   ' NET_IFINDEX
END TYPE

' // Size = 8 bytes
TYPE MIB_INVERTEDIFSTACK_ROW DWORD
   LowerLayerInterfaceIndex  AS DWORD   ' NET_IFINDEX
   HigherLayerInterfaceIndex AS DWORD   ' NET_IFINDEX
END TYPE

' // Size = 12 bytes
TYPE MIB_IFSTACK_TABLE DWORD
   NumEntries AS DWORD           ' ULONG
   Table(0) AS MIB_IFSTACK_ROW   ' MIB_IFSTACK_ROW Table[ANY_SIZE]
END TYPE

' // Size = 12 bytes
TYPE MIB_INVERTEDIFSTACK_TABLE DWORD
   NumEntries AS DWORD                   ' ULONG
   Table(0) AS MIB_INVERTEDIFSTACK_ROW   ' MIB_INVERTEDIFSTACK_ROW Table[ANY_SIZE]
END TYPE

'typedef
'VOID
'(NETIOAPI_API_ *PIPINTERFACE_CHANGE_CALLBACK) (
'    __in PVOID CallerContext,
'    __in PMIB_IPINTERFACE_ROW Row OPTIONAL,
'    __in MIB_NOTIFICATION_TYPE NotificationType
'    );

'SUB IPINTERFACE_CHANGE_CALLBACK ( _
'   BYVAL CallerContext AS DWORD _           ' __in PVOID CallerContext
' , BYREF Row AS PMIB_IPINTERFACE_ROW _      ' __in PMIB_IPINTERFACE_ROW Row OPTIONAL
' , BYVAL NotificationType AS LONG _         ' __in MIB_NOTIFICATION_TYPE NotificationType
' )                                          ' void

DECLARE FUNCTION GetIfStackTable IMPORT "Iphlpapi.dll" ALIAS "GetIfStackTable" ( _
   BYREF Table AS ANY _                                 ' __out PMIB_IFSTACK_TABLE *Table
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetInvertedIfStackTable IMPORT "Iphlpapi.dll" ALIAS "GetInvertedIfStackTable" ( _
   BYREF Table AS ANY _                                 ' __out PMIB_INVERTEDIFSTACK_TABLE *Table
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetIpInterfaceEntry IMPORT "Iphlpapi.dll" ALIAS "GetIpInterfaceEntry" ( _
   BYREF Row AS MIB_IPINTERFACE_ROW _                   ' __out PMIB_IPINTERFACE_ROW Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves IP information for the specified interface on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPINTERFACE_ROW structure with either the Luid or
'        Index initialized to that of the interface for which to retrieve
'        information.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Family: it must be either AF_INET or AF_INET6
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetIpInterfaceTable IMPORT "Iphlpapi.dll" ALIAS "GetIpInterfaceTable" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_IPINTERFACE_TABLE *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the network-layer interface table.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 MIB entries.

'        AF_INET6: Only returns IPv6 MIB entries.

'        AF_UNSPEC: Returns both IPv4 and IPv6 MIB entries.

'    Table - Returns the table of interfaces in a MIB_IPINTERFACE_TABLE
'        structure.  Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

DECLARE SUB InitializeIpInterfaceEntry IMPORT "Iphlpapi.dll" ALIAS "InitializeIpInterfaceEntry" ( _
   BYREF Row AS ANY _                                   ' __out PMIB_IPINTERFACE_ROW Row
 )                                                      ' void

'/*++

'Routine Description:

'    Initialize the MIB_IPINTERFACE_ROW entry for use in SetIpInterfaceRow.

'Arguments:

'    Row - Returns an initialized MIB_IPINTERFACE_ROW structure.

'Return Value:

'    None.

'Notes:

'    InitializeIpInterfaceEntry must be used to initialize the fields of
'    MIB_IPINTERFACE_ROW with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpInterfaceEntry.

'--*/

DECLARE FUNCTION NotifyIpInterfaceChange IMPORT "Iphlpapi.dll" ALIAS "NotifyIpInterfaceChange" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 , BYVAL Callback AS DWORD _                            ' __in PIPINTERFACE_CHANGE_CALLBACK Callback
 , BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
 , BYVAL InitialNotification AS BYTE _                  ' __in BOOLEAN InitialNotification
 , BYREF NotificationHandle AS DWORD _                  ' __inout HANDLE *NotificationHandle
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Register for notification for IP interface changes.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only register for IPv4 change notifications.

'        AF_INET6: Only register for IPv6 change notifications.

'        AF_UNSPEC: Register for both IPv4 and IPv6 change notifications.

'    Callback - Supplies a callback function.  This function will be invoked
'        when an interface notification is received.

'    CallerContext - Provides the user specific caller context.  This context
'        will be supplied to the callback function.

'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.

'    NotificationHandle - Returns a handle to the notification registration.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    1. Invokation of the callback function is serialized.

'    2. Use CancelMibChangeNotify2 to deregister for change notifications.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetIpInterfaceEntry LIB "IpHlpApi.dll" _
    ALIAS "SetIpInterfaceEntry" ( _
    BYVAL pRow AS MIB_IPINTERFACE_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION SetIpInterfaceEntry IMPORT "Iphlpapi.dll" ALIAS "SetIpInterfaceEntry" ( _
   BYREF Row AS MIB_IPINTERFACE_ROW _                   ' __inout PMIB_IPINTERFACE_ROW Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Set the properties of an IP interface.

'Arguments:

'    Row - Supplies a MIB_IPINTERFACE_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    InitializeIpInterfaceEntry must be used to initialize the fields of
'    MIB_IPINTERFACE_ROW with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpInterfaceEntry.

'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpInterfaceEntry:
'    1. Family: To AF_INET or AF_INET6.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/


'//
'// Unicast address management routines.
'//

'//
'// The structure for unicast IP Address management.
'//

' // Size = 80 bytes
TYPE MIB_UNICASTIPADDRESS_ROW QWORD FILL
   ' // Key Structure.
   Address            AS SOCKADDR_INET   ' SOCKADDR_INET
   InterfaceLuid      AS NET_LUID        ' NET_LUID
   InterfaceIndex     AS DWORD           ' NET_IFINDEX
   ' // Read-Write Fileds.
   PrefixOrigin       AS LONG            ' NL_PREFIX_ORIGIN enum
   SuffixOrigin       AS LONG            ' NL_SUFFIX_ORIGIN enum
   ValidLifetime      AS DWORD           ' ULONG
   PreferredLifetime  AS DWORD           ' ULONG
   OnLinkPrefixLength AS BYTE            ' UINT8
   SkipAsSource       AS BYTE            ' BOOLEAN
   ' // Read-Only Fields.
   DadState           AS LONG            ' NL_DAD_STATE
   ScopeId            AS SCOPE_ID        ' SCOPE_ID
   CreationTimeStamp  AS QUAD            ' LARGE_INTEGER
END TYPE

' // Size = 88 bytes
TYPE MIB_UNICASTIPADDRESS_TABLE QWORD FILL
   NumEntries AS DWORD                    ' ULONG
   Table(0) AS MIB_UNICASTIPADDRESS_ROW   ' MIB_UNICASTIPADDRESS_ROW Table[ANY_SIZE];
END TYPE

'typedef
'VOID
'(NETIOAPI_API_ *PUNICAST_IPADDRESS_CHANGE_CALLBACK) (
'    __in PVOID CallerContext,
'    __in_opt PMIB_UNICASTIPADDRESS_ROW Row,
'    __in MIB_NOTIFICATION_TYPE NotificationType
'    );

'SUB UNICAST_IPADDRESS_CHANGE_CALLBACK ( _
'   BYVAL CallerContext AS DWORD _           ' __in PVOID CallerContext
' , BYREF Row AS MIB_UNICASTIPADDRESS_ROW _  ' __in PMIB_UNICASTIPADDRESS_ROW Row OPTIONAL
' , BYVAL NotificationType AS LONG _         ' __in MIB_NOTIFICATION_TYPE NotificationType
' )                                          ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION CreateUnicastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "CreateUnicastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __in CONST MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Create a unicast IP address entry on the local computer.

'Arguments:

'    Row - Supplies a MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke CreateIpInterfaceEntry.

'    On input, the following key fields of Row must be initialized after
'    invoking InitializeUnicastIpAddressEntry:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DeleteUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION DeleteUnicastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "DeleteUnicastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __in CONST MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Delete a unicast IP address entry on the local computer.

'Arguments:

'    Row - Supplies a MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "GetUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION GetUnicastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "GetUnicastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __inout MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Retrieves information for the specified unicast IP address entry on the
'        local computer.

'Arguments:

'    Address - Supplies a MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetUnicastIpAddressTable IMPORT "Iphlpapi.dll" ALIAS "GetUnicastIpAddressTable" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_UNICASTIPADDRESS_TABLE *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the unicast IP address table on a local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 unicast addresses.

'        AF_INET6: Only returns IPv6 unicast addresses.

'        AF_UNSPEC: Returns both IPv4 and IPv6 unicast addresses.

'    Table - Returns the table of unicast IP addresses in a
'        MIB_UNICASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE SUB InitializeUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "InitializeUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    )
#ELSE
DECLARE SUB InitializeUnicastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "InitializeUnicastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __out PMIB_UNICASTIPADDRESS_ROW Row
 )                                                      ' void
#ENDIF

'/*++

'Routine Description:

'    Initialize the MIB_UNICASTIPADDRESS_ROW entry for use in
'    CreateUnicastIpAddressEntry and SetUnicastIpAddressEntry.

'Arguments:

'    Address - Returns an initialized MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    None.

'Notes:

'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke CreateUnicastIpAddressEntry or
'    SetUnicastIpAddressEntry.

'--*/

DECLARE FUNCTION NotifyUnicastIpAddressChange IMPORT "Iphlpapi.dll" ALIAS "NotifyUnicastIpAddressChange" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 , BYVAL Callback AS DWORD _                            ' __in PUNICAST_IPADDRESS_CHANGE_CALLBACK Callback
 , BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
 , BYVAL InitialNotification AS BYTE _                  ' __in BOOLEAN InitialNotification
 , BYREF NotificationHandle AS DWORD _                  ' __inout HANDLE *NotificationHandle
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Register for notification for unicast IP address changes.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only register for IPv4 change notifications.

'        AF_INET6: Only register for IPv6 change notifications.

'        AF_UNSPEC: Register for both IPv4 and IPv6 change notifications.

'    Callback - Supplies a callback function.  This function will be invoked
'        when an unicast IP address notification is received.

'    CallerContext - Provides the user specific caller context.  This context
'        will be supplied to the callback function.

'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.

'    NotificationHandle - Returns a handle to the notification registration.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    1. Invokation of the callback function is serialized.

'    2. Use CancelMibChangeNotify2 to deregister for change notifications.

'--*/

'typedef
'VOID
'(NETIOAPI_API_ *PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK) (
'    __in PVOID CallerContext,
'    __in PMIB_UNICASTIPADDRESS_TABLE AddressTable
'    );

'SUB STABLE_UNICAST_IPADDRESS_TABLE_CALLBACK ( _
'   BYVAL CallerContext AS DWORD _                     ' __in PVOID CallerContext
' , BYREF AddressTable AS MIB_UNICASTIPADDRESS_TABLE _ '  IN PMIB_UNICASTIPADDRESS_TABLE AddressTable
' )                                                    ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NotifyStableUnicastIpAddressTable LIB "IpHlpApi.dll" _
    ALIAS "NotifyStableUnicastIpAddressTable" ( _
    BYVAL Family         AS WORD, _
    Table                AS ANY, _   ' PMIB_UNICASTIPADDRESS_TABLE*
    BYVAL CallerCallback AS DWORD, _ ' PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK
    CallerContext        AS ANY, _   ' PVOID
    NotificationHandle   AS DWORD _  ' HANDLE *
    ) AS LONG
#ELSE
DECLARE FUNCTION NotifyStableUnicastIpAddressTable IMPORT "Iphlpapi.dll" ALIAS "NotifyStableUnicastIpAddressTable" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 , BYREF Table AS MIB_UNICASTIPADDRESS_TABLE _          ' __inout PMIB_UNICASTIPADDRESS_TABLE* Table
 , BYVAL CallerCallback AS DWORD _                      ' __in PSTABLE_UNICAST_IPADDRESS_TABLE_CALLBACK CallerCallback
 , BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
 , BYREF NotificationHandle AS DWORD _                  ' __inout HANDLE *NotificationHandle
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetUnicastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "SetUnicastIpAddressEntry" ( _
    BYVAL Row AS MIB_UNICASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION SetUnicastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "SetUnicastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __in CONST MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Set the properties of an unicast IP address.

'Arguments:

'    Address - Supplies a MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    InitializeUnicastIpAddressEntry must be used to initialize the fields of
'    MIB_UNICASTIPADDRESS_ROW with default values.  The caller can then update
'    the fields it wishes to modify and invoke SetUnicastIpAddressEntry.

'    On input, the following key fields of Row must be initialized after
'    invoking InitializeUnicastIpAddressEntry:
'    1. Address to a valid IPv4 or IPv6 unicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/

'//
'// Anycast address management routines.
'//

' // Size = 48 bytes
TYPE MIB_ANYCASTIPADDRESS_ROW QWORD FILL
   ' // Key Structure.
   Address        AS SOCKADDR_INET   ' SOCKADDR_INET
   InterfaceLuid  AS NET_LUID   ' NET_LUID
   InterfaceIndex AS DWORD   ' NET_IFINDEX
   ' // Read-Only Fields.
   ScopeId        AS SCOPE_ID   ' SCOPE_ID
END TYPE

' // Size = 56 bytes
TYPE MIB_ANYCASTIPADDRESS_TABLE QWORD FILL
   NumEntries AS DWORD                    ' ULONG
   Table(0) AS MIB_ANYCASTIPADDRESS_ROW   ' MIB_ANYCASTIPADDRESS_ROW Table[ANY_SIZE];
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "CreateAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION CreateAnycastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "CreateAnycastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __in CONST MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Create an anycast IP address entry on the local computer.

'Arguments:

'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DeleteAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "DeleteAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION DeleteAnycastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "DeleteAnycastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __in CONST MIB_UNICASTIPADDRESS_ROW *Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Delete an anycast IP address entry on the local computer.

'Arguments:

'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAnycastIpAddressEntry LIB "IpHlpApi.dll" _
    ALIAS "GetAnycastIpAddressEntry" ( _
    BYVAL Row AS MIB_ANYCASTIPADDRESS_ROW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION GetAnycastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "GetAnycastIpAddressEntry" ( _
   BYREF Row AS MIB_UNICASTIPADDRESS_ROW _              ' __inout PMIB_UNICASTIPADDRESS_ROW Row
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Retrieves information for the specified anycast IP address entry on the
'    local computer.

'Arguments:

'    Address - Supplies a MIB_ANYCASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. Address to a valid IPv4 or IPv6 anycast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetAnycastIpAddressTable IMPORT "Iphlpapi.dll" ALIAS "GetAnycastIpAddressTable" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_ANYCASTIPADDRESS_TABLE *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the anycast IP address table.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 anycast addresses.

'        AF_INET6: Only returns IPv6 anycast addresses.

'        AF_UNSPEC: Returns both IPv4 and IPv6 anycast addresses.

'    Table - Returns the table of anycast IP addresses in a
'        MIB_ANYCASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/


'//
'// Multicast address management routines.
'//

' // Size = 48 bytes
TYPE MIB_MULTICASTIPADDRESS_ROW   ' Must be 8 byte aligned
   ' // Key Structure.
   Address        AS SOCKADDR_INET   ' SOCKADDR_INET
   InterfaceIndex AS DWORD           ' NET_IFINDEX
   InterfaceLuid  AS NET_LUID        ' NET_LUID
   ' // Read-Only Fields.
   ScopeId        AS SCOPE_ID        ' SCOPE_ID
   alignment__    AS DWORD           ' // To keep 8 byte alignment
END TYPE

' // Size = 56 bytes
TYPE MIB_MULTICASTIPADDRESS_TABLE   ' Must be 8 byte aligned
   NumEntries  AS DWORD                        ' ULONG
   alignment__ AS DWORD                        ' // To keep 8 byte alignment
   Table(0)    AS MIB_MULTICASTIPADDRESS_ROW   ' MIB_MULTICASTIPADDRESS_ROW Table[ANY_SIZE];
END TYPE

DECLARE FUNCTION GetMulticastIpAddressEntry IMPORT "Iphlpapi.dll" ALIAS "GetMulticastIpAddressEntry" ( _
   BYREF Row AS MIB_MULTICASTIPADDRESS_ROW _            ' __inout PMIB_MULTICASTIPADDRESS_ROW Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves information for the specified mulitcast IP address entry on the
'    local computer.

'Arguments:

'    Row - Supplies a MIB_MULTICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized.
'    1. Address to a valid IPv4 or IPv6 multicast address.
'    2. At least one of InterfaceLuid or InterfaceIndex must be specified.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetMulticastIpAddressTable IMPORT "Iphlpapi.dll" ALIAS "GetMulticastIpAddressTable" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_MULTICASTIPADDRESS_TABLE *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the multicast IP address table on the local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 multicast addresses.

'        AF_INET6: Only returns IPv6 multicast addresses.

'        AF_UNSPEC: Returns both IPv4 and IPv6 multicast addresses.

'    Table - Returns the table of multicast IP addresses in a
'        MIB_MULTICASTIPADDRESS_TABLE Structure.  Use FreeMibTable to free this
'        buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

'//
'// Route management routines.
'//

' // Size = 32 bytes
TYPE IP_ADDRESS_PREFIX   ' Must be 8 byte aligned
   Prefix         AS SOCKADDR_INET   ' SOCKADDR_INET
   PrefixLength   AS BYTE            ' UINT8
   alignment__(2) AS BYTE            ' // To keep 8 byte alignment
END TYPE

' // Size = 104 bytes
TYPE MIB_IPFORWARD_ROW2   ' Must be 8 byte aligned
   ' // Key Structure.
   InterfaceLuid        AS NET_LUID            ' NET_LUID
   InterfaceIndex       AS DWORD               ' NET_IFINDEX
   DestinationPrefix    AS IP_ADDRESS_PREFIX   ' IP_ADDRESS_PREFIX
   NextHop              AS SOCKADDR_INET       ' SOCKADDR_INET
   ' // Read-Write Fields.
   SitePrefixLength     AS BYTE                ' UCHAR
   alignment__(2)       AS BYTE                ' // To keep 8 byte alignment
   ValidLifetime        AS DWORD               ' ULONG
   PreferredLifetime    AS DWORD               ' ULONG
   Metric               AS DWORD               ' ULONG
   Protocol             AS LONG                ' NL_ROUTE_PROTOCOL
   Loopback             AS BYTE                ' BOOLEAN
   AutoconfigureAddress AS BYTE                ' BOOLEAN
   Publish              AS BYTE                ' BOOLEAN
   Immortal             AS BYTE                ' BOOLEAN
   ' // Read-Only Fields.
   Age                  AS DWORD               ' ULONG
   Origin               AS LONG                ' NL_ROUTE_ORIGIN
END TYPE

' // Size = 112 bytes
TYPE MIB_IPFORWARD_TABLE2
   NumEntries  AS DWORD                ' ULONG
   alignment__ AS DWORD                ' // To keep 8 byte alignment
   Table(0)    AS MIB_IPFORWARD_ROW2   ' MIB_IPFORWARD_ROW2 Table[ANY_SIZE];
END TYPE

'typedef
'VOID
'(NETIOAPI_API_ *PIPFORWARD_CHANGE_CALLBACK) (
'    __in PVOID CallerContext,
'    __in_opt PMIB_IPFORWARD_ROW2 Row,
'    __in MIB_NOTIFICATION_TYPE NotificationType
'    );

'SUB IPFORWARD_CHANGE_CALLBACK ( _
'   BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
' , BYREF Row AS MIB_IPFORWARD_ROW2 _                    ' __in PMIB_IPFORWARD_ROW2 Row OPTIONAL
' , BYVAL NotificationType AS LONG _                     ' __in MIB_NOTIFICATION_TYPE NotificationType
' )                                                      ' void

'/*++

'Routine Description:

'    Create a route on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPFORWARD_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    InitializeIpForwardEntry must be used to initialize the fields of
'    MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'    fields it wishes to modify and invoke CreateIpForwardEntry2.

'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpForwardEntry:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.

'--*/

DECLARE FUNCTION DeleteIpForwardEntry2 IMPORT "Iphlpapi.dll" ALIAS "DeleteIpForwardEntry2" ( _
   BYREF Row AS MIB_IPFORWARD_ROW2 _                    ' __in CONST MIB_IPFORWARD_ROW2 *Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Delete a route on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPFORWARD_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.

'--*/

DECLARE FUNCTION GetBestRoute2 IMPORT "Iphlpapi.dll" ALIAS "GetBestRoute2" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in NET_LUID *InterfaceLuid OPTIONAL
 , BYVAL InterfaceIndex AS DWORD _                      ' __in NET_IFINDEX InterfaceIndex
 , BYREF SourceAddress AS SOCKADDR_INET _               ' __in CONST IN SOCKADDR_INET *SourceAddress
 , BYREF DestinationAddress AS SOCKADDR_INET _          ' __in CONST IN SOCKADDR_INET *DestinationAddress
 , BYVAL AddressSortOptions AS DWORD _                  ' __in ULONG AddressSortOptions
 , BYREF BestRoute AS MIB_IPFORWARD_ROW2 _              ' __out PMIB_IPFORWARD_ROW2 BestRoute
 , BYREF BestSourceAddress AS SOCKADDR_INET _           ' __out SOCKADDR_INET *BestSourceAddress
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieve the best route between source and destination address on a local
'        computer.

'Arguments:

'    InterfaceLuid - Supplies Luid to specify an interface.

'    InterfaceIndex - Supplies Index to specify an interface.

'    SourceAddress - Supplies source address.

'    DestinationAddress - Supplies destination address.

'    AddressSortOptions - Supplies AddressSortOptions.

'    BestRoute - Returns the MIB structure that holds the best route.

'    BestSourceAddress - Returns the source address of the best route.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following parameters must be supplied:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. SourceAddress.
'    3. DestinationAddress.

'--*/

DECLARE FUNCTION GetIpForwardEntry2 IMPORT "Iphlpapi.dll" ALIAS "GetIpForwardEntry2" ( _
   BYREF Row AS MIB_IPFORWARD_ROW2 _                    ' __inout PMIB_IPFORWARD_ROW2 Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves information for the specified route entry on the local computer.

'Arguments:

'    Route - Supplies a MIB_IPFORWARD_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix and NextHop can be specified.

'    On output, the remaining fields of Row are filled in.

'    If one or more routes matches the specified criteria,
'    this API matches the first entry.

'--*/

DECLARE FUNCTION GetIpForwardTable2 IMPORT "Iphlpapi.dll" ALIAS "GetIpForwardTable2" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_IPFORWARD_TABLE2 *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the route table on a local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 route entries.

'        AF_INET6: Only returns IPv6 route entries.

'        AF_UNSPEC: Returns both IPv4 and IPv6 route entries.

'    Table - Returns the table of routes in a MIB_IPFORWARD_TABLE2 Structure.
'        Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

DECLARE SUB InitializeIpForwardEntry IMPORT "Iphlpapi.dll" ALIAS "InitializeIpForwardEntry" ( _
   BYREF Row AS MIB_IPFORWARD_ROW2 _                    ' __out PMIB_IPFORWARD_ROW2 Row
 )                                                      ' void

'/*++

'Routine Description:

'    Initialize the MIB_IPFORWARD_ROW2 entry for use in SetIpForwardEntry2.

'Arguments:

'    Row - Returns an initialized PMIB_IPFORWARD_ROW2 structure.

'Return Value:

'    None.

'Notes:

'    InitializeIpForwardEntry must be used to initialize the fields of
'        MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'        fields it wishes to modify and invoke SetIpForwardEntry2.

'--*/

DECLARE FUNCTION NotifyRouteChange2 IMPORT "Iphlpapi.dll" ALIAS "NotifyRouteChange2" ( _
   BYVAL AddressFamily AS WORD _                        ' __in ADDRESS_FAMILY AddressFamily
 , BYVAL Callback AS DWORD _                            ' __in PIPFORWARD_CHANGE_CALLBACK Callback
 , BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
 , BYVAL InitialNotification AS BYTE _                  ' __in BOOLEAN InitialNotification
 , BYREF NotificationHandle AS DWORD _                  ' __inout HANDLE *NotificationHandle
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Register for notification for route changes.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only register for IPv4 route change notifications.

'        AF_INET6: Only register for IPv6 route change notifications.

'        AF_UNSPEC: Register for both IPv4 and IPv6 route change notifications.

'    Callback - Supplies a callback function. This function will be invoked when
'        an unicast IP address notification is received.

'    CallerContext - Provides the user specific caller context. This context
'        will be supplied to the callback function.

'    InitialNotification - Supplies a boolean to indicate whether an
'        initialization notification should be provided.

'    NotificationHandle - Returns a handle to the notification registration.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    1. Invokation of the callback function is serialized.

'    2. Use CancelMibChangeNotify2 to deregister for change notifications.

'--*/

DECLARE FUNCTION SetIpForwardEntry2 IMPORT "Iphlpapi.dll" ALIAS "SetIpForwardEntry2" ( _
   BYREF Route AS MIB_IPFORWARD_ROW2 _                  ' __in CONST MIB_IPFORWARD_ROW2 *Route
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Set the properties of a route entry.

'Arguments:

'    Route - Supplies a MIB_UNICASTIPADDRESS_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    InitializeIpForwardEntry must be used to initialize the fields of
'    MIB_IPFORWARD_ROW2 with default values.  The caller can then update the
'    fields it wishes to modify and invoke SetIpForwardEntry2.

'    On input, the following key fields of Row must be initialized after
'    invoking InitializeIpForwardEntry:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. DestinationPrefix.
'    3. NextHop.

'--*/

'//
'// Path management routines.
'//

' // Size = 4 bytes
UNION MIB_IPPATH_ROW_UNION DWORD
   LastReachable   AS DWORD   ' ULONG // Milliseconds.
   LastUnreachable AS DWORD   ' ULONG  // Milliseconds.
END UNION

' // Size = 136 bytes
TYPE MIB_IPPATH_ROW   ' Must be 8 byte aligned
   ' // Key.
   Source            AS SOCKADDR_INET   ' SOCKADDR_INET
   Destination       AS SOCKADDR_INET   ' SOCKADDR_INET
   InterfaceLuid     AS NET_LUID        ' NET_LUID
   InterfaceIndex    AS DWORD           ' NET_IFINDEX
   ' // RO.
   ' // The current next hop.  This can change over the lifetime of a path.
   CurrentNextHop    AS SOCKADDR_INET   ' SOCKADDR_INET
   ' // MTU of path to destination. Includes the IP header length.
   PathMtu           AS DWORD           ' ULONG
   ' // Estimated mean RTT.
   RttMean           AS DWORD           ' ULONG
   ' // Mean deviation of RTT.
   RttDeviation      AS DWORD           ' ULONG
   MIB_IPPATH_ROW_UNION
   IsReachable       AS BYTE            ' BOOLEAN
   alignment__(6)    AS BYTE            ' // To keep 8 byte alignment
   ' // Estimated speed.
   LinkTransmitSpeed AS QUAD            ' ULONG64
   LinkReceiveSpeed  AS QUAD            ' ULONG64
END TYPE

' // Size = 144 bytes
TYPE MIB_IPPATH_TABLE
   NumEntries  AS DWORD            ' ULONG
   alignment__ AS DWORD            ' // To keep 8 byte alignment
   Table(0)    AS MIB_IPPATH_ROW   ' MIB_IPPATH_ROW Table[ANY_SIZE]
END TYPE


DECLARE FUNCTION FlushIpPathTable IMPORT "Iphlpapi.dll" ALIAS "FlushIpPathTable" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Flush the IP Path table on the local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only flush the IPv4 path table.

'        AF_INET6: Only flush the IPv6 path table.

'        AF_UNSPEC: Flush both IPv4 and IPv6 path table.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION GetIpPathEntry IMPORT "Iphlpapi.dll" ALIAS "GetIpPathEntry" ( _
   BYREF Row AS MIB_IPPATH_ROW _                        ' __inout PMIB_IPPATH_ROW Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves information for the specified path entry on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPPATH_ROW structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Source.
'    3. Destination.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetIpPathTable IMPORT "Iphlpapi.dll" ALIAS "GetIpPathTable" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_IPPATH_TABLE *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the path table on a local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 paths.

'        AF_INET6: Only returns IPv6 paths.

'        AF_UNSPEC: Returns both IPv4 and IPv6 paths.

'    Table - Returns the table of paths in a MIB_IPPATH_TABLE
'        structure.  Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

'//
'// ARP and IPv6 Neighbor management routines.
'//

' // Size = 1 byte
TYPE MIB_IPNET_ROW2_UNION_STRUCT BYTE
   IsRouter      AS BIT * 1 IN BYTE   ' BOOLEAN
   IsUnreachable AS BIT * 1           ' BOOLEAN
END TYPE

' // Size = 1 byte
UNION MIB_IPNET_ROW2_UNION BYTE
   MIB_IPNET_ROW2_UNION_STRUCT
   Flags AS BYTE   ' UCHAR
END UNION

' // Size = 4 bytes
UNION MIB_IPNET_ROW2_ReachabilityTime DWORD
   LastReachable   AS DWORD   ' ULONG
   LastUnreachable AS DWORD   ' ULONG
END UNION

' // Size = 88 bytes
TYPE MIB_IPNET_ROW2
   ' // Key Struture.
   Address               AS SOCKADDR_INET   ' SOCKADDR_INET
   InterfaceIndex        AS DWORD           ' NET_IFINDEX
   InterfaceLuid         AS NET_LUID        ' NET_LUID
   ' // Read-Write.
   PhysicalAddress(%IF_MAX_PHYS_ADDRESS_LENGTH - 1) AS BYTE   ' UCHAR
   ' // Read-Only.
   PhysicalAddressLength AS DWORD           ' ULONG
   State                 AS LONG            ' NL_NEIGHBOR_STATE
   MIB_IPNET_ROW2_UNION
   ReachabilityTime      AS MIB_IPNET_ROW2_ReachabilityTime
   alignment__(2)        AS BYTE            ' // To keep 8 byte alignment
END TYPE

' // Size = 96 bytes
TYPE MIB_IPNET_TABLE2
   NumEntries  AS DWORD            ' ULONG
   alignment__ AS DWORD            ' // To keep 8 byte alignment
   Table(0)    AS MIB_IPNET_ROW2   ' MIB_IPNET_ROW2 Table[ANY_SIZE];
END TYPE

DECLARE FUNCTION CreateIpNetEntry2 IMPORT "Iphlpapi.dll" ALIAS "CreateIpNetEntry2" ( _
   BYREF Row AS MIB_IPNET_ROW2 _                        ' __in CONST MIB_IPNET_ROW2 *Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Create a neighbor entry on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPNET_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'    3. PhysicalAddress.

'--*/

DECLARE FUNCTION DeleteIpNetEntry2 IMPORT "Iphlpapi.dll" ALIAS "DeleteIpNetEntry2" ( _
   BYREF Row AS MIB_IPNET_ROW2 _                        ' __in CONST MIB_IPNET_ROW2 *Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Delete a neighbor entry on the local computer.

'Arguments:

'    Row - Supplies a MIB_IPNET_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.

'--*/


DECLARE FUNCTION FlushIpNetTable2 IMPORT "Iphlpapi.dll" ALIAS "FlushIpNetTable2" ( _
   BYVAL Family AS WORD _                               ' __in ADDRESS_FAMILY Family
 , BYVAL InterfaceIndex AS DWORD _                      ' __in NET_IFINDEX InterfaceIndex
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Flush the neighbor entry table on the local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only flush the IPv4 neighbor table.

'        AF_INET6: Only flush the IPv6 neighbor table.

'        AF_UNSPEC: Flush both IPv4 and IPv6 neighbor table.

'    InterfaceIndex - Supplies the Interface index.  If the index is specified,
'        flush the neighbor entries on a specific interface, otherwise flush the
'        neighbor entries on all the interfaces.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION GetIpNetEntry2 IMPORT "Iphlpapi.dll" ALIAS "GetIpNetEntry2" ( _
   BYREF Row AS MIB_IPNET_ROW2 _                        ' __inout PMIB_IPNET_ROW2 Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves information for the specified neighbor entry on the local
'    computer.

'Arguments:

'    Row - Supplies a MIB_IPNET_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION GetIpNetTable2 IMPORT "Iphlpapi.dll" ALIAS "GetIpNetTable2" ( _
   BYVAL Family AS WORD _                               ' __in  ADDRESS_FAMILY Family
 , BYREF Table AS ANY _                                 ' __out PMIB_IPNET_TABLE2 *Table
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Retrieves the neighbor table on the local computer.

'Arguments:

'    Family - Supplies the address family.

'        AF_INET: Only returns IPv4 neighbor entries.

'        AF_INET6: Only returns IPv6 neighbor entries.

'        AF_UNSPEC: Returns both IPv4 and IPv6 neighbor entries.

'    Table - Returns the table of neighbor entries in a MIB_IPNET_TABLE2
'        structure.  Use FreeMibTable to free this buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    The API allocates the buffer for Table.  Use FreeMibTable to free it.

'--*/

DECLARE FUNCTION ResolveIpNetEntry2 IMPORT "Iphlpapi.dll" ALIAS "ResolveIpNetEntry2" ( _
   BYREF Row AS MIB_IPNET_ROW2 _                        ' __inout PMIB_IPNET_ROW2 Row
 , OPTIONAL BYREF SourceAddress AS SOCKADDR_INET _      ' __in CONST SOCKADDR_INET *SourceAddress OPTIONAL
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Resolve the physical address of a specific neighbor.

'Arguments:

'    NetEntry - Supplies a MIB_IPNET_ROW2 structure.

'    SourceAddress - Supplies the source address.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    This API flushes any existing neighbor entry and resolves the MAC address
'    by sending ARP requests (IPv4) or Neighbor Solicitation (IPv6).
'    If source address is not provided, the API will automatically select the
'    best interface to send the request on.

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.

'    On output, the remaining fields of Row are filled in.

'--*/

DECLARE FUNCTION SetIpNetEntry2 IMPORT "Iphlpapi.dll" ALIAS "SetIpNetEntry2" ( _
   BYREF Row AS MIB_IPNET_ROW2 _                        ' __inout PMIB_IPNET_ROW2 Row
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Set the physical address of a neighbor entry.

'Arguments:

'    NetEntry - Supplies a MIB_IPNET_ROW2 structure.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    On input, the following key fields of Row must be initialized:
'    1. At least one of InterfaceLuid or InterfaceIndex must be specified.
'    2. Address.
'    3. PhysicalAddress.

'--*/

'//
'// Teredo APIs.
'//
%MIB_INVALID_TEREDO_PORT_NUMBER = 0

'typedef
'VOID
'(NETIOAPI_API_ *PTEREDO_PORT_CHANGE_CALLBACK) (
'    __in PVOID CallerContext,
'    __in USHORT Port,
'    __inout MIB_NOTIFICATION_TYPE NotificationType
'    );

'SUB TEREDO_PORT_CHANGE_CALLBACK ( _
'   BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
' , BYVAL Port AS WORD _                                 ' __in USHORT Port
' , BYVAL NotificationType AS LONG _                     ' __in MIB_NOTIFICATION_TYPE NotificationType
' )                                                      ' void

DECLARE FUNCTION NotifyTeredoPortChange IMPORT "Iphlpapi.dll" ALIAS "NotifyTeredoPortChange" ( _
   BYVAL Callback AS DWORD _                            ' __in PTEREDO_PORT_CHANGE_CALLBACK Callback
 , BYVAL CallerContext AS DWORD _                       ' __in PVOID CallerContext
 , BYVAL InitialNotification AS BYTE _                  ' __in BOOLEAN InitialNotification
 , BYREF NotificationHandle AS DWORD _                  ' __inout HANDLE *NotificationHandle
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetTeredoPort IMPORT "Iphlpapi.dll" ALIAS "GetTeredoPort" ( _
   BYREF Port AS WORD _                                 ' __out USHORT *Port
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Get the Teredo client port.

'Arguments:

'    Port - returns the Teredo port.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

'#ifndef TEREDO_API_NO_DEPRECATE

'//
'// Deprecate all of the unsafe functions to generate compiletime errors.
'// Use the following routines instead : FwpmSystemPortsGet
'//

'#pragma deprecated(NotifyTeredoPortChange)
'#pragma deprecated(GetTeredoPort)

'#endif // TEREDO_API_NO_DEPRECATE


'//
'// Generic (not IP-specific) interface definitions.
'//

DECLARE FUNCTION CancelMibChangeNotify2 IMPORT "Iphlpapi.dll" ALIAS "CancelMibChangeNotify2" ( _
   BYVAL NotificationHandle AS DWORD _                  ' __in HANDLE NotificationHandle
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Deregister for change notifications.

'Arguments:

'    NotificationHandle - Supplies the handle returned from a notification
'        registration.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'Notes:

'    Blocks until all callback have returned.

'--*/

DECLARE SUB FreeMibTable IMPORT "Iphlpapi.dll" ALIAS "FreeMibTable" ( _
   BYREF Memory AS ANY _                                ' __in PVOID Memory
 )                                                      ' VOID

'/*++

'Routine Description:

'    Free the buffer allocated by Get*Table APIs.

'Arguments:

'    Memory - Supplies the buffer to free.

'Return Value:

'    None.

'--*/

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateSortedAddressPairs LIB "IpHlpApi.dll" _
    ALIAS "CreateSortedAddressPairs" ( _
    BYVAL SourceAddressList       AS SOCKADDR_IN6 PTR, _
    BYVAL SourceAddressCount      AS DWORD, _
    BYVAL DestinationAddressList  AS SOCKADDR_IN6 PTR, _
    BYVAL DestinationAddressCount AS DWORD, _
    BYVAL AddressSortOptions      AS DWORD, _
    SortedAddressPairList         AS ANY, _  ' PSOCKADDR_IN6_PAIR *
    SortedAddressPairCount        AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION CreateSortedAddressPairs IMPORT "Iphlpapi.dll" ALIAS "CreateSortedAddressPairs" ( _
   BYREF SourceAddressList AS SOCKADDR_IN6 _            ' __in const PSOCKADDR_IN6 SourceAddressList OPTIONAL
 , BYVAL SourceAddressCount AS DWORD _                  ' __in ULONG SourceAddressCount
 , BYREF DestinationAddressList AS SOCKADDR_IN6 _       ' __in const PSOCKADDR_IN6 DestinationAddressList
 , BYVAL DestinationAddressCount AS DWORD _             ' __in ULONG DestinationAddressCount
 , BYVAL AddressSortOptions AS DWORD _                  ' __in ULONG AddressSortOptions
 , BYREF SortedAddressPairList AS SOCKADDR_IN6_PAIR _   ' __out PSOCKADDR_IN6_PAIR *SortedAddressPairList
 , BYREF SortedAddressPairCount AS DWORD _              ' __out ULONG *SortedAddressPairCount
 ) AS LONG                                              ' HRESULT
#ENDIF

'/*++

'Routine Description:

'    Given a list of source and destination addresses, returns a list of
'    pairs of addresses in sorted order.  The list is sorted by which address
'    pair is best suited for communication between two peers.

'    The list of source addresses is optional, in which case the function
'    automatically uses all the host machine's local addresses.

'Arguments:

'    SourceAddressList - Supplies list of potential source addresses.
'        If NULL the routine automatically uses all local addresses.
'        IPv4 addresses can be specified in IPv4-mapped format.
'        Reserved for future use.  Must be NULL.

'    SourceAddressCount - Supplies the number of addresses in the
'        SourceAddressList.
'        Reserved for future use.  Must be 0.

'    DestinationAddressList - Supplies list of potential destination addresses.
'        IPv4 addresses can be specified in IPv4-mapped format.

'    DestinationAddressCount -  Supplies the number of addresses in the
'        DestinationAddressList.

'    AddressSortOptions - Reserved for future use.  Must be 0.

'    SortedAddressPairList - Returns a sorted list of pairs of addresses
'        in prefered order of communication.  The list must be freed with a
'        single call to NetioFreeMemory.

'    SortedAddressPairCount - Returns the number of address pairs in
'        SortedAddressPairList.

'Return Value:

'    ERROR_SUCCESS on success.  WIN32 error code on error.

'--*/

#ENDIF   ' //_WS2IPDEF_

DECLARE FUNCTION ConvertInterfaceNameToLuidA IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceNameToLuidA" ( _
   BYREF InterfaceName AS ASCIIZ _                      ' __in  CONST CHAR *InterfaceName
 , BYREF InterfaceLuid AS NET_LUID _                    ' __out NET_LUID *InterfaceLuid
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Name to Luid.

'Arguments:

'    InterfaceName - Supplies the interface name to be converted.

'    InterfaceLuid - Returns the interface Luid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceNameToLuidW IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceNameToLuidW" ( _
   BYREF InterfaceName AS WSTRINGZ _                    ' __in  CONST WCHAR *InterfaceName
 , BYREF InterfaceLuid AS NET_LUID _                    ' __out NET_LUID *InterfaceLuid
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO ConvertInterfaceNameToLuid = ConvertInterfaceNameToLuidW
#ELSE
   MACRO ConvertInterfaceNameToLuid = ConvertInterfaceNameToLuidA
#ENDIF

'/*++

'Routine Description:

'    Convert an Interface Name to Luid.

'Arguments:

'    InterfaceName - Supplies the interface name to be converted.

'    InterfaceLuid - Returns the interface Luid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceLuidToNameA IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceLuidToNameA" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in CONST NET_LUID *InterfaceLuid
 , BYREF InterfaceName AS ASCIIZ _                      ' __out_ecount(Length) PSTR InterfaceName
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Luid to Name.

'Arguments:

'    InterfaceLuid - Supplies the interface Luid to be converted.

'    InterfaceName - Returns the interface name.

'    Lenght - Supplies the length of the InterfaceName buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceLuidToNameW IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceLuidToNameW" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in CONST NET_LUID *InterfaceLuid
 , BYREF InterfaceName AS WSTRINGZ _                    ' __out_ecount(Length) PWSTR InterfaceName
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO ConvertInterfaceLuidToName = ConvertInterfaceLuidToNameW
#ELSE
   MACRO ConvertInterfaceLuidToName = ConvertInterfaceLuidToNameA
#ENDIF

'/*++

'Routine Description:

'    Convert an Interface Luid to Name.

'Arguments:

'    InterfaceLuid - Supplies the interface Luid to be converted.

'    InterfaceName - Returns the interface name.

'    Length - Supplies the length of the InterfaceName buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceLuidToIndex IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceLuidToIndex" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in  CONST NET_LUID *InterfaceLuid
 , BYREF InterfaceIndex AS DWORD _                      ' __out PNET_IFINDEX InterfaceIndex
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Luid to Index.

'Arguments:

'    InterfaceLuid - Supplies the interface Luid to be converted.

'    InterfaceName - Returns the interface Index.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceIndexToLuid IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceIndexToLuid" ( _
   BYVAL InterfaceIndex AS DWORD _                      ' __in  NET_IFINDEX InterfaceIndex
 , BYREF InterfaceLuid AS NET_LUID _                    ' __out PNET_LUID InterfaceLuid
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Index to Luid.

'Arguments:

'    InterfaceName - Supplies the interface Index to be converted.

'    InterfaceLuid - Returns the interface Luid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceLuidToAlias IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceLuidToAlias" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in CONST NET_LUID *InterfaceLuid
 , BYREF InterfaceAlias AS WSTRINGZ _                   ' __out_ecount(Length) PWSTR InterfaceAlias
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Luid to Alias.

'Arguments:

'    InterfaceLuid - Supplies the interface Luid to be converted.

'    InterfaceAlias - Returns the interface Alias.

'    Length - Supplies the length of InterfaceAlias buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceAliasToLuid IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceAliasToLuid" ( _
   BYREF InterfaceAlias AS WSTRINGZ _                   ' __in  CONST WCHAR *InterfaceAlias
 , BYREF InterfaceLuid AS NET_LUID _                    ' __out PNET_LUID InterfaceLuid
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Alias to Luid.

'Arguments:

'    InterfaceAlias - Supplies the null terminated interface Alias.

'    InterfaceLuid - Returns the interface Luid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceLuidToGuid IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceLuidToGuid" ( _
   BYREF InterfaceLuid AS NET_LUID _                    ' __in  CONST NET_LUID *InterfaceLuid
 , BYREF InterfaceGuid AS GUID _                        ' __out GUID *InterfaceGuid
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Luid to Guid.

'Arguments:

'    InterfaceLuid - Supplies the interface Luid to be converted.

'    InterfaceGuid - Returns the interface Guid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertInterfaceGuidToLuid IMPORT "Iphlpapi.dll" ALIAS "ConvertInterfaceGuidToLuid" ( _
   BYREF InterfaceGuid AS GUID _                        ' __in  CONST GUID *InterfaceGuid
 , BYREF InterfaceLuid AS GUID _                        ' __out PNET_LUID InterfaceLuid
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Convert an Interface Luid to Guid.

'Arguments:

'    InterfaceGuid - Supplies the interface Guid to be converted.

'    InterfaceGuid - Returns the interface Luid.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

%IF_NAMESIZE = %NDIS_IF_MAX_STRING_SIZE

DECLARE FUNCTION if_nametoindex IMPORT "Iphlpapi.dll" ALIAS "if_nametoindex" ( _
   BYREF InterfaceName AS ASCIIZ _                      ' __in PCSTR InterfaceName
 ) AS DWORD                                             ' NET_IFINDEX

'/*++

'Routine Description:

'    Convert an Interface name to Index.

'Arguments:

'    InterfaceName - Supplies the null terminated interface name to convert.

'Return Value:

'    Interface index on success, 0 otherwise.

'--*/

DECLARE FUNCTION if_indextoname IMPORT "Iphlpapi.dll" ALIAS "if_indextoname" ( _
   BYVAL InterfaceIndex AS DWORD _                      ' __in NET_IFINDEX InterfaceIndex
 , BYREF InterfaceName AS ASCIIZ _                      ' __out_ecount(IF_NAMESIZE) PCHAR InterfaceName
 ) AS DWORD                                             ' PCHAR

'/*++

'Routine Description:

'    Convert an Interface index to Name.

'Arguments:

'    InterfaceIndex - Supplies the Interface index to convert.

'    InterfaceName - Returns the null terminated interface name.

'Return Value:

'    Interface name on success, NULL otherwise.

'Notes:

'    The length of InterfaceName buffer must be equal to or greater than
'        IF_NAMESIZE.

'--*/

DECLARE FUNCTION GetCurrentThreadCompartmentId IMPORT "Iphlpapi.dll" ALIAS "GetCurrentThreadCompartmentId" ( _
 ) AS DWORD                                             ' NET_IF_COMPARTMENT_ID

'/*++

'Routine Description:

'    Get the compartment ID of current thread.

'Arguments:

'    None.

'Return Value:

'    The compartment ID of current thread.

'--*/

DECLARE FUNCTION SetCurrentThreadCompartmentId IMPORT "Iphlpapi.dll" ALIAS "SetCurrentThreadCompartmentId" ( _
   BYVAL CompartmentId AS DWORD _                       ' __in NET_IF_COMPARTMENT_ID CompartmentId
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Set the compartment ID of current thread.

'Arguments:

'    CompartmentId - Supplies the compartment ID to be set.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.


'--*/

DECLARE FUNCTION GetSessionCompartmentId IMPORT "Iphlpapi.dll" ALIAS "GetSessionCompartmentId" ( _
   BYVAL SessionId AS DWORD _                           ' __in ULONG SessionId
 ) AS DWORD                                             ' NET_IF_COMPARTMENT_ID

'/*++

'Routine Description:

'    Get the compartment ID of the session.

'Arguments:

'    SessionId - Supplies the session ID.

'Return Value:

'    The compartment ID of the session.

'--*/

DECLARE FUNCTION SetSessionCompartmentId IMPORT "Iphlpapi.dll" ALIAS "SetSessionCompartmentId" ( _
   BYVAL SessionId AS DWORD _                           ' __in ULONG SessionId
 , BYVAL CompartmentId AS DWORD _                       ' __in NET_IF_COMPARTMENT_ID CompartmentId
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Set the compartment ID of the session.

'Arguments:

'    SessionId - Supplies the session ID.

'    CompartmentId - Supplies the compartment ID to be set.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

' Reserved for future use. Do not use this function.
DECLARE FUNCTION GetNetworkInformation IMPORT "Iphlpapi.dll" ALIAS "GetNetworkInformation" ( _
   BYREF NetworkGuid AS GUID _                          ' __in CONST NET_IF_NETWORK_GUID *NetworkGuid
 , BYREF CompartmentId AS DWORD _                       ' __out PNET_IF_COMPARTMENT_ID CompartmentId
 , BYREF SiteId AS DWORD _                              ' __out PULONG SiteId
 , BYREF NetworkName AS WSTRINGZ _                      ' __out_ecount(Length) PWCHAR NetworkName
 , BYVAL Length AS DWORD _                              ' __in ULONG Length
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Get the network information.

'Arguments:

'    NetworkGuid - Supplies the Network GUID.

'    CompartmentId - Returns the compartment ID.

'    SiteId - Returns Site ID.

'    NetowrkName - Returns the network name.

'    Length - Supplies the length of NetworkName buffer.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION SetNetworkInformation IMPORT "Iphlpapi.dll" ALIAS "SetNetworkInformation" ( _
   BYREF NetworkGuid AS GUID _                          ' __in CONST NET_IF_NETWORK_GUID *NetworkGuid
 , BYVAL CompartmentId AS DWORD _                       ' __in NET_IF_COMPARTMENT_ID CompartmentId
 , BYREF NetworkName AS WSTRINGZ _                      ' __in CONST WCHAR *NetworkName
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Set the Network Information.

'Arguments:

'    NetworkGuid - Supplies the session ID.

'    CompartmentId - Supplies the compartment ID to be set.

'    NetworkName - Supplies the Network name to be set.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

'#pragma warning(pop)

DECLARE FUNCTION ConvertLengthToIpv4Mask IMPORT "Iphlpapi.dll" ALIAS "ConvertLengthToIpv4Mask" ( _
   BYVAL MaskLength AS DWORD _                          ' __in  ULONG MaskLength
 , BYREF Mask AS DWORD _                                ' __out PULONG Mask
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Converts a prefixLength to a subnet mask.

'Arguments:

'    MaskLength - Prefix Length.

'    Mask - Mask generated.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

DECLARE FUNCTION ConvertIpv4MaskToLength IMPORT "Iphlpapi.dll" ALIAS "ConvertIpv4MaskToLength" ( _
   BYVAL Mask AS DWORD _                                ' __in  ULONG Mask
 , BYREF MaskLength AS BYTE _                           ' __out PUINT8 MaskLength
 ) AS LONG                                              ' HRESULT

'/*++

'Routine Description:

'    Converts a subnet mask to a prefix length.

'Arguments:

'    Mask - Subnet mask to use.

'    MaskLength - Prefix length computed.

'Return Value:

'    User-Mode: NO_ERROR on success, error code on failure.

'    Kernel-Mode: STATUS_SUCCESS on success, error code on failure.

'--*/

'//
'//4201.
'//
