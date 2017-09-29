' ########################################################################################
' Microsoft Windows
' File: ifdef.inc
' Contents: IF_* definitions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IFDEF_INC = 1

'typedef ULONG32 NET_IF_OBJECT_ID, *PNET_IF_OBJECT_ID;

' enum NET_IF_ADMIN_STATUS   // ifAdminStatus
%NET_IF_ADMIN_STATUS_UP      = 1
%NET_IF_ADMIN_STATUS_DOWN    = 2
%NET_IF_ADMIN_STATUS_TESTING = 3

' enum NET_IF_OPER_STATUS   // ifOperStatus
%NET_IF_OPER_STATUS_UP               = 1
%NET_IF_OPER_STATUS_DOWN             = 2
%NET_IF_OPER_STATUS_TESTING          = 3
%NET_IF_OPER_STATUS_UNKNOWN          = 4
%NET_IF_OPER_STATUS_DORMANT          = 5
%NET_IF_OPER_STATUS_NOT_PRESENT      = 6
%NET_IF_OPER_STATUS_LOWER_LAYER_DOWN = 7

'//
'// Flags to extend operational status
'//
%NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED        = &H00000001???
%NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED      = &H00000002???
%NET_IF_OPER_STATUS_DORMANT_PAUSED                = &H00000004???
%NET_IF_OPER_STATUS_DORMANT_LOW_POWER             = &H00000008???

'typedef UINT32 NET_IF_COMPARTMENT_ID, *PNET_IF_COMPARTMENT_ID;

'//
'// Define compartment ID type:
'//
'#define NET_IF_COMPARTMENT_ID_UNSPECIFIED   (NET_IF_COMPARTMENT_ID)0
'#define NET_IF_COMPARTMENT_ID_PRIMARY       (NET_IF_COMPARTMENT_ID)1

%NET_IF_COMPARTMENT_ID_UNSPECIFIED = 0???
%NET_IF_COMPARTMENT_ID_PRIMARY     = 1???

%NET_IF_OID_IF_ALIAS             = &H00000001???  ' // identifies the ifAlias string for an interface
%NET_IF_OID_COMPARTMENT_ID       = &H00000002???  ' // identifies the compartment ID for an interface.
%NET_IF_OID_NETWORK_GUID         = &H00000003???  ' // identifies the NetworkGuid for an interface.
%NET_IF_OID_IF_ENTRY             = &H00000004???  ' // identifies statistics for an interface.

'//
'// Define NetworkGUID type:
'//
'typedef GUID NET_IF_NETWORK_GUID, *PNET_IF_NETWORK_GUID;

'//
'// Define macros for an "unspecified" NetworkGUID value to be used in structures
'// that haven't had the NET_LUID field filled in yet.
'//
'#define NET_SET_UNSPECIFIED_NETWORK_GUID(_pNetworkGuid)
'#define NET_IS_UNSPECIFIED_NETWORK_GUID(_NetworkGuidValue)

'//
'// To prevent collisions between user-assigned and system-assigend site-ids,
'// we partition the site-id space into two:
'// 1. User-Assigned: NET_SITEID_UNSPECIFIED < SiteId < NET_SITEID_MAXUSER
'// 2. System-Assigned: NET_SITEID_MAXUSER < SiteId < NET_SITEID_MAXSYSTEM
'//
'// Note: A network's SiteId doesn't really need to be settable.
'// 1. The network profile manager creates a network per network profile.
'// 2. NDIS/IF assigns a unique SiteId to each network.
'//

%NET_SITEID_UNSPECIFIED = 0
%NET_SITEID_MAXUSER = &H07ffffff???
%NET_SITEID_MAXSYSTEM = &H0fffffff???
'C_ASSERT(NET_SITEID_MAXUSER < NET_SITEID_MAXSYSTEM);

' enum NET_IF_RCV_ADDRESS_TYPE // ifRcvAddressType
%NET_IF_RCV_ADDRESS_TYPE_OTHER        = 1
%NET_IF_RCV_ADDRESS_TYPE_VOLATILE     = 2
%NET_IF_RCV_ADDRESS_TYPE_NON_VOLATILE = 3

' // Size = 8 bytes
TYPE NET_IF_RCV_ADDRESS_LH WORD
   ifRcvAddressType   AS LONG   ' NET_IF_RCV_ADDRESS_TYPE enum
   ifRcvAddressLength AS WORD   ' USHORT
   ifRcvAddressOffset AS WORD   ' USHORT // from beginning of this struct
END TYPE

' // Size = 4 bytes
TYPE NET_IF_ALIAS_LH WORD
   ifAliasLength AS WORD   ' USHORT // in bytes, of ifAlias string
   ifAliasOffset AS WORD   ' USHORT // in bytes, from beginning of this struct
END TYPE

'#pragma warning(push)
'#pragma warning(disable:4214) // bit field types other than int
'typedef union _NET_LUID_LH
'{
'    ULONG64     Value;
'    struct
'    {
'        ULONG64     Reserved:24;
'        ULONG64     NetLuidIndex:24;
'        ULONG64     IfType:16;                  // equal to IANA IF type
'    }Info;
'} NET_LUID_LH, *PNET_LUID_LH;
'#pragma warning(pop)

TYPE NET_LUID_LH_INFO_STRUCT
'   Reserved     AS BIT * 24 IN QUAD
'   NetLuidIndex AS BIT * 24
'   IfType       AS BIT * 16   ' equal to IANA IF type
   Reserved(2)     AS BYTE
   NetLuidIndex(2) AS BYTE
   IfType          AS WORD   ' equal to IANA IF type
END TYPE

' // Size = 8 bytes
UNION NET_LUID_LH QWORD
   Value AS QUAD   ' ULONG64
   Info  AS NET_LUID_LH_INFO_STRUCT   ' PowerBASIC doesn't support BIT fields with QUADs
END UNION

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef NET_IF_RCV_ADDRESS_LH NET_IF_RCV_ADDRESS;
'typedef NET_IF_RCV_ADDRESS* PNET_IF_RCV_ADDRESS;
MACRO NET_IF_RCV_ADDRESS = NET_IF_RCV_ADDRESS_LH

'typedef NET_IF_ALIAS_LH NET_IF_ALIAS;
'typedef NET_IF_ALIAS* PNET_IF_ALIAS;
MACRO NET_IF_ALIAS = NET_IF_ALIAS_LH
'#endif //NTDDI_VISTA

'//
'// Need to make this visible on all platforms (for the purpose of IF_LUID).
'//
'typedef NET_LUID_LH NET_LUID;
'typedef NET_LUID* PNET_LUID;
MACRO NET_LUID = NET_LUID_LH

'//
'// IF_LUID
'//
'// Define the locally unique datalink interface identifier type.
'// This type is persistable.
'//
'typedef NET_LUID IF_LUID, *PIF_LUID;
MACRO IF_LUID = NET_LUID

'typedef ULONG NET_IFINDEX, *PNET_IFINDEX;       // Interface Index (ifIndex)
'typedef UINT16 NET_IFTYPE, *PNET_IFTYPE;        // Interface Type (IANA ifType)

'#define NET_IFINDEX_UNSPECIFIED (NET_IFINDEX)(0)    // Not a valid ifIndex
'#define NET_IFLUID_UNSPECIFIED (0)    // Not a valid if Luid

%NET_IFINDEX_UNSPECIFIED = 0???   ' // Not a valid ifIndex
%NET_IFLUID_UNSPECIFIED  = 0???   ' // Not a valid if Luid

'//
'// Definitions for NET_IF_INFORMATION.Flags
'//
%NIIF_HARDWARE_INTERFACE         = &H00000001???  ' // Set iff hardware
%NIIF_FILTER_INTERFACE           = &H00000002???
%NIIF_NDIS_RESERVED1             = &H00000004???
%NIIF_NDIS_RESERVED2             = &H00000008???
%NIIF_NDIS_RESERVED3             = &H00000010???
%NIIF_NDIS_WDM_INTERFACE         = &H00000020???
%NIIF_NDIS_ENDPOINT_INTERFACE    = &H00000040???
%NIIF_NDIS_ISCSI_INTERFACE       = &H00000080???

'#define NIIF_WAN_TUNNEL_TYPE_UNKNOWN    ((ULONG)(-1))
%NIIF_WAN_TUNNEL_TYPE_UNKNOWN    = &HFFFFFFFF???

'//
'// Define datalink interface access types.
'//
' enum NET_IF_ACCESS_TYPE
%NET_IF_ACCESS_LOOPBACK             = 1
%NET_IF_ACCESS_BROADCAST            = 2
%NET_IF_ACCESS_POINT_TO_POINT       = 3
%NET_IF_ACCESS_POINT_TO_MULTI_POINT = 4
%NET_IF_ACCESS_MAXIMUM              = 5

'//
'// Define datalink interface direction types.
'//
' enum NET_IF_DIRECTION_TYPE
%NET_IF_DIRECTION_SENDRECEIVE = 0
%NET_IF_DIRECTION_SENDONLY    = 1
%NET_IF_DIRECTION_RECEIVEONLY = 2
%NET_IF_DIRECTION_MAXIMUM     = 3


' enum NET_IF_CONNECTION_TYPE
%NET_IF_CONNECTION_DEDICATED = 1
%NET_IF_CONNECTION_PASSIVE   = 2
%NET_IF_CONNECTION_DEMAND    = 3
%NET_IF_CONNECTION_MAXIMUM   = 4


' enum NET_IF_MEDIA_CONNECT_STATE
%MediaConnectStateUnknown      = 0
%MediaConnectStateConnected    = 1
%MediaConnectStateDisconnected = 2

%NET_IF_LINK_SPEED_UNKNOWN = -1   ' ((ULONG64)(-1))

'//
'// Defines the duplex state of media
'//
' enum NET_IF_MEDIA_DUPLEX_STATE
%MediaDuplexStateUnknown = 0
%MediaDuplexStateHalf    = 1
%MediaDuplexStateFull    = 2


'// Special values for fields in NET_PHYSICAL_LOCATION
%NIIF_BUS_NUMBER_UNKNOWN      = &HFFFFFFFF???   '   ((ULONG)(-1))
%NIIF_SLOT_NUMBER_UNKNOWN     = &HFFFFFFFF???   '   ((ULONG)(-1))
%NIIF_FUNCTION_NUMBER_UNKNOWN = &HFFFFFFFF???   '   ((ULONG)(-1))

' // Size = 12 bytes
TYPE NET_PHYSICAL_LOCATION_LH DWORD
   BusNumber      AS DWORD   ' ULONG // Physical location
   SlotNumber     AS DWORD   ' ULONG // ... for hardware
   FunctionNumber AS DWORD   ' ULONG // ... devices.
END TYPE

'//
'// maximum string size in -wchar- units
'//
%IF_MAX_STRING_SIZE = 256

' // Size = 516 bytes
TYPE IF_COUNTED_STRING_LH WORD
   Length AS WORD                                   ' USHORT // in -Bytes-
   String AS WSTRINGZ * (%IF_MAX_STRING_SIZE + 1)   ' WCHAR[IF_MAX_STRING_SIZE + 1]
END TYPE

%IF_MAX_PHYS_ADDRESS_LENGTH = 32

' // Size = 34 bytes
TYPE IF_PHYSICAL_ADDRESS_LH BYTE
   Length  AS WORD                                   ' USHORT
   Address AS STRING * %IF_MAX_PHYS_ADDRESS_LENGTH   ' UCHAR[IF_MAX_PHYS_ADDRESS_LENGTH]
END TYPE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef NET_PHYSICAL_LOCATION_LH NET_PHYSICAL_LOCATION;
'typedef NET_PHYSICAL_LOCATION* PNET_PHYSICAL_LOCATION;
MACRO NET_PHYSICAL_LOCATION = NET_PHYSICAL_LOCATION_LH

'typedef IF_COUNTED_STRING_LH IF_COUNTED_STRING;
'typedef IF_COUNTED_STRING* PIF_COUNTED_STRING;
MACRO IF_COUNTED_STRING = IF_COUNTED_STRING_LH

'typedef IF_PHYSICAL_ADDRESS_LH IF_PHYSICAL_ADDRESS;
'typedef IF_PHYSICAL_ADDRESS* PIF_PHYSICAL_ADDRESS;
MACRO IF_PHYSICAL_ADDRESS = IF_PHYSICAL_ADDRESS_LH
'#endif


'//
'// IF_INDEX
'//
'// Define the interface index type.
'// This type is not persistable.
'// This must be unsigned (not an enum) to replace previous uses of
'// an index that used a DWORD type.
'//

'typedef NET_IFINDEX IF_INDEX, *PIF_INDEX;

%IFI_UNSPECIFIED = %NET_IFINDEX_UNSPECIFIED

'//
'// Get definitions for IFTYPE and IF_ACCESS_TYPE.
'//
#INCLUDE ONCE "ipifcons.inc"


'//
'// Types of tunnels (sub-type of IF_TYPE when IF_TYPE is IF_TYPE_TUNNEL).
'// See http://www.iana.org/assignments/ianaiftype-mib.
'//

' enum TUNNEL_TYPE
%TUNNEL_TYPE_NONE    = 0
%TUNNEL_TYPE_OTHER   = 1
%TUNNEL_TYPE_DIRECT  = 2
%TUNNEL_TYPE_6TO4    = 11
%TUNNEL_TYPE_ISATAP  = 13
%TUNNEL_TYPE_TEREDO  = 14
%TUNNEL_TYPE_IPHTTPS = 15

'//
'// IF_ADMINISTRATIVE_STATE
'//
'// Datalink Interface Administrative State.
'// Indicates whether the interface has been administratively enabled.
'//

' enum IF_ADMINISTRATIVE_STATE {
%IF_ADMINISTRATIVE_DISABLED   = 0
%IF_ADMINISTRATIVE_ENABLED    = 1
%IF_ADMINISTRATIVE_DEMANDDIAL = 2


'//
'// Note: Interface is Operational iff
'// ((MediaSense is Connected) and (AdministrativeState is Enabled))
'// or
'// ((MediaSense is Connected) and (AdministrativeState is OnDemand))
'//
'// !Operational iff
'// ((MediaSense != Connected) or (AdministrativeState is Disabled))
'//

'//
'// OperStatus values from RFC 2863
'//

' enum IF_OPER_STATUS
%IfOperStatusUp             = 1
%IfOperStatusDown           = 2
%IfOperStatusTesting        = 3
%IfOperStatusUnknown        = 4
%IfOperStatusDormant        = 5
%IfOperStatusNotPresent     = 6
%IfOperStatusLowerLayerDown = 7

' // Size = 216 bytes
TYPE NDIS_INTERFACE_INFORMATION   ' Must be 8 byte aligned
   ' //  rod fields
   ifOperStatus               AS LONG    ' NET_IF_OPER_STATUS enum
   ifOperStatusFlags          AS DWORD   ' ULONG
   MediaConnectState          AS LONG    ' NET_IF_MEDIA_CONNECT_STATE
   MediaDuplexState           AS LONG    ' NET_IF_MEDIA_DUPLEX_STATE
   ifMtu                      AS DWORD   ' ULONG
   ifPromiscuousMode          AS BYTE    ' BOOLEAN
   ifDeviceWakeUpEnable       AS BYTE    ' BOOLEAN
   alignment__                AS WORD    ' // To keep 8 byte alignment
   XmitLinkSpeed              AS QUAD    ' ULONG64
   RcvLinkSpeed               AS QUAD    ' ULONG64
   ifLastChange               AS QUAD    ' ULONG64
   ifCounterDiscontinuityTime AS QUAD    ' ULONG64
   ifInUnknownProtos          AS QUAD    ' ULONG64
   ' // OID_GEN_STATISTICS
   ifInDiscards               AS QUAD    ' ULONG64 // OID_GEN_RCV_DISCARDS = OID_GEN_RCV_ERROR + OID_GEN_RCV_NO_BUFFER
   ifInErrors                 AS QUAD    ' ULONG64 // OID_GEN_RCV_ERROR
   ifHCInOctets               AS QUAD    ' ULONG64 // OID_GEN_BYTES_RCV = OID_GEN_DIRECTED_BYTES_RCV + OID_GEN_MULTICAST_BYTES_RCV + OID_GEN_BROADCAST_BYTES_RCV
   ifHCInUcastPkts            AS QUAD    ' ULONG64 // OID_GEN_DIRECTED_FRAMES_RCV
   ifHCInMulticastPkts        AS QUAD    ' ULONG64 // OID_GEN_MULTICAST_FRAMES_RCV
   ifHCInBroadcastPkts        AS QUAD    ' ULONG64 // OID_GEN_BROADCAST_FRAMES_RCV
   ifHCOutOctets              AS QUAD    ' ULONG64 // OID_GEN_BYTES_XMIT = OID_GEN_DIRECTED_BYTES_XMIT + OID_GEN_MULTICAST_BYTES_XMIT + OID_GEN_BROADCAST_BYTES_XMIT
   ifHCOutUcastPkts           AS QUAD    ' ULONG64 // OID_GEN_DIRECTED_FRAMES_XMIT
   ifHCOutMulticastPkts       AS QUAD    ' ULONG64 // OID_GEN_MULTICAST_FRAMES_XMIT
   ifHCOutBroadcastPkts       AS QUAD    ' ULONG64 // OID_GEN_BROADCAST_FRAMES_XMIT
   ifOutErrors                AS QUAD    ' ULONG64 // OID_GEN_XMIT_ERROR
   ifOutDiscards              AS QUAD    ' ULONG64 // OID_GEN_XMIT_DISCARDS
   ifHCInUcastOctets          AS QUAD    ' ULONG64 // OID_GEN_DIRECTED_BYTES_RCV
   ifHCInMulticastOctets      AS QUAD    ' ULONG64 // OID_GEN_MULTICAST_BYTES_RCV
   ifHCInBroadcastOctets      AS QUAD    ' ULONG64 // OID_GEN_BROADCAST_BYTES_RCV
   ifHCOutUcastOctets         AS QUAD    ' ULONG64 // OID_GEN_DIRECTED_BYTES_XMIT
   ifHCOutMulticastOctets     AS QUAD    ' ULONG64 // OID_GEN_MULTICAST_BYTES_XMIT
   ifHCOutBroadcastOctets     AS QUAD    ' ULONG64 // OID_GEN_BROADCAST_BYTES_XMIT
   CompartmentId              AS DWORD   ' NET_IF_COMPARTMENT_ID
   SupportedStatistics        AS DWORD   ' ULONG
END TYPE
