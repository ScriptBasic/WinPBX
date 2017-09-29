' ########################################################################################
' Microsoft Windows
' File: IpTypes.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPTYPES_INC = 1

#INCLUDE ONCE "windows.inc"
'#INCLUDE ONCE "time.inc"
#INCLUDE ONCE "ifdef.inc"
#INCLUDE ONCE "nldef.inc"

'// Definitions and structures used by getnetworkparams and getadaptersinfo apis

%MAX_ADAPTER_DESCRIPTION_LENGTH = 128   ' // arb.
%MAX_ADAPTER_NAME_LENGTH        = 256   ' // arb.
%MAX_ADAPTER_ADDRESS_LENGTH     = 8     ' // arb.
%DEFAULT_MINIMUM_ENTITIES       = 32    ' // arb.
%MAX_HOSTNAME_LEN               = 128   ' // arb.
%MAX_DOMAIN_NAME_LEN            = 128   ' // arb.
%MAX_SCOPE_ID_LEN               = 256   ' // arb.
%MAX_DHCPV6_DUID_LENGTH         = 130   ' // RFC 3315.
%MAX_DNS_SUFFIX_STRING_LENGTH   = 256

'//
'// types
'//

'// Node Type

%BROADCAST_NODETYPE    = 1
%PEER_TO_PEER_NODETYPE = 2
%MIXED_NODETYPE        = 4
%HYBRID_NODETYPE       = 8

'//
'// IP_ADDRESS_STRING - store an IP address as a dotted decimal string
'//

' // To workaround a conflict with the PB declaration, that uses sString instead of String.
UNION IP_ADDRESS_STRING_UNION
   sString AS STRING * 16
   String AS STRING * 4 * 4   ' char String[4 * 4]
END UNION
' // Size = 16 bytes
TYPE IP_ADDRESS_STRING DWORD
   IP_ADDRESS_STRING_UNION
END TYPE

' // Size = 16 bytes
TYPE IP_MASK_STRING DWORD
   IP_ADDRESS_STRING
END TYPE

'//
'// IP_ADDR_STRING - store an IP address with its corresponding subnet mask,
'// both as dotted decimal strings
'//

' // Size = 40 bytes
TYPE IP_ADDR_STRING DWORD
   pNext     AS IP_ADDR_STRING PTR   ' struct _IP_ADDR_STRING* Next
   IpAddress AS IP_ADDRESS_STRING    ' IP_ADDRESS_STRING IpAddress
   IpMask    AS IP_MASK_STRING       ' IP_MASK_STRING IpMask
   Context   AS DWORD                ' DWORD Context
END TYPE

'//
'// ADAPTER_INFO - per-adapter information. All IP addresses are stored as
'// strings
'//

' // Size = 640 bytes
TYPE IP_ADAPTER_INFO   ' Must be 8 bytes aligned
   pNext               AS IP_ADAPTER_INFO PTR                            ' struct _IP_ADAPTER_INFO* Next
   ComboIndex          AS DWORD                                          ' DWORD ComboIndex
   AdapterName         AS ASCIIZ * %MAX_ADAPTER_NAME_LENGTH + 4          ' char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4]
   Description         AS ASCIIZ * %MAX_ADAPTER_DESCRIPTION_LENGTH + 4   ' char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4]
   AddressLength       AS DWORD                                          ' UINT AddressLength
   Address             AS STRING * %MAX_ADAPTER_ADDRESS_LENGTH           ' BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH]
   Index               AS DWORD                                          ' DWORD Index
   Type                AS DWORD                                          ' UINT Type
   DhcpEnabled         AS DWORD                                          ' UINT DhcpEnabled
   CurrentIpAddress    AS IP_ADDR_STRING PTR                             ' PIP_ADDR_STRING CurrentIpAddress
   IpAddressList       AS IP_ADDR_STRING                                 ' IP_ADDR_STRING IpAddressList
   GatewayList         AS IP_ADDR_STRING                                 ' IP_ADDR_STRING GatewayList
   DhcpServer          AS IP_ADDR_STRING                                 ' IP_ADDR_STRING DhcpServer
   HaveWins            AS LONG                                           ' BOOL HaveWins
   PrimaryWinsServer   AS IP_ADDR_STRING                                 ' IP_ADDR_STRING PrimaryWinsServer
   SecondaryWinsServer AS IP_ADDR_STRING                                 ' IP_ADDR_STRING SecondaryWinsServer
   LeaseObtained       AS LONG                                           ' time_t LeaseObtained
   LeaseExpires        AS LONG                                           ' time_t LeaseExpires
END TYPE

'#ifdef _WINSOCK2API_

#IF %DEF(%WINSOCK2API)

'//
'// The following types require Winsock2.
'//

'typedef NL_PREFIX_ORIGIN IP_PREFIX_ORIGIN;
'typedef NL_SUFFIX_ORIGIN IP_SUFFIX_ORIGIN;
'typedef NL_DAD_STATE IP_DAD_STATE;

' // Size = 8 bytes
TYPE IP_ADAPTER_COMMON_UNION_STRUCT
   Length AS DWORD   ' ULONG Length
   Flags  AS DWORD   ' DWORD Flags
END TYPE

' // Size = 8 bytes
UNION IP_ADAPTER_COMMON_UNION
   Alignment AS QUAD   ' ULONGLONG
   IP_ADAPTER_COMMON_UNION_STRUCT
END UNION

' // Size = 48 bytes
TYPE IP_ADAPTER_UNICAST_ADDRESS_LH   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext              AS IP_ADAPTER_UNICAST_ADDRESS_LH PTR   ' struct _IP_ADAPTER_UNICAST_ADDRESS_XP *Next
#ELSE
   Next               AS IP_ADAPTER_UNICAST_ADDRESS_LH PTR   ' struct _IP_ADAPTER_UNICAST_ADDRESS_XP *Next
#ENDIF
   Address            AS SOCKET_ADDRESS                      ' SOCKET_ADDRESS
   PrefixOrigin       AS LONG                                ' IP_PREFIX_ORIGIN PrefixOrigin enum
   SuffixOrigin       AS LONG                                ' IP_SUFFIX_ORIGIN SuffixOrigin enum
   DadState           AS LONG                                ' IP_DAD_STATE DadState enum
   ValidLifetime      AS DWORD                               ' ULONG ValidLifetime
   PreferredLifetime  AS DWORD                               ' ULONG PreferredLifetime
   LeaseLifetime      AS DWORD                               ' ULONG LeaseLifetime
   OnLinkPrefixLength AS BYTE                                ' UINT8
   alignment__(2)     AS BYTE                                ' // To keep 8 byte alignment
END TYPE

' // Size = 48 bytes
TYPE IP_ADAPTER_UNICAST_ADDRESS_XP   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext             AS IP_ADAPTER_UNICAST_ADDRESS_XP PTR   ' struct _IP_ADAPTER_UNICAST_ADDRESS_XP *Next
#ELSE
   Next              AS IP_ADAPTER_UNICAST_ADDRESS_XP PTR   ' struct _IP_ADAPTER_UNICAST_ADDRESS_XP *Next
#ENDIF
   Address           AS SOCKET_ADDRESS                      ' SOCKET_ADDRESS
   PrefixOrigin      AS LONG                                ' IP_PREFIX_ORIGIN PrefixOrigin enum
   SuffixOrigin      AS LONG                                ' IP_SUFFIX_ORIGIN SuffixOrigin enum
   DadState          AS LONG                                ' IP_DAD_STATE DadState enum
   ValidLifetime     AS DWORD                               ' ULONG ValidLifetime
   PreferredLifetime AS DWORD                               ' ULONG PreferredLifetime
   LeaseLifetime     AS DWORD                               ' ULONG LeaseLifetime
   alignment__       AS DWORD
END TYPE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef  IP_ADAPTER_UNICAST_ADDRESS_LH IP_ADAPTER_UNICAST_ADDRESS;
'typedef  IP_ADAPTER_UNICAST_ADDRESS_LH *PIP_ADAPTER_UNICAST_ADDRESS;
'#elif (NTDDI_VERSION >= NTDDI_WINXP)
'typedef  IP_ADAPTER_UNICAST_ADDRESS_XP IP_ADAPTER_UNICAST_ADDRESS;
'typedef  IP_ADAPTER_UNICAST_ADDRESS_XP *PIP_ADAPTER_UNICAST_ADDRESS;
'#endif

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
   MACRO IP_ADAPTER_UNICAST_ADDRESS = IP_ADAPTER_UNICAST_ADDRESS_LH
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WINXP)
   MACRO IP_ADAPTER_UNICAST_ADDRESS = IP_ADAPTER_UNICAST_ADDRESS_XP
#ENDIF

'//
'// Bit values of IP_ADAPTER_UNICAST_ADDRESS Flags field.
'//
%IP_ADAPTER_ADDRESS_DNS_ELIGIBLE = &H01???
%IP_ADAPTER_ADDRESS_TRANSIENT    = &H02???

' // Size = 24 bytes
TYPE IP_ADAPTER_ANYCAST_ADDRESS_XP   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
   Next        AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR   ' struct _IP_ADAPTER_ANYCAST_ADDRESS_XP *Next
   alignment__ AS DWORD                               ' SOCKET_ADDRESS Address
   Address     AS SOCKET_ADDRESS                      ' To keep 8 byte alignment
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
   MACRO IP_ADAPTER_ANYCAST_ADDRESS = IP_ADAPTER_ANYCAST_ADDRESS_XP
#ENDIF

' // Size = 24 bytes
TYPE IP_ADAPTER_MULTICAST_ADDRESS_XP   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext       AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR   ' struct _IP_ADAPTER_MULTICAST_ADDRESS_XP *Next
#ELSE
   Next        AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR   ' struct _IP_ADAPTER_MULTICAST_ADDRESS_XP *Next
#ENDIF
   alignment__ AS DWORD                                 ' SOCKET_ADDRESS Address
   Address     AS SOCKET_ADDRESS                        ' SOCKET_ADDRESS Address
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
   MACRO IP_ADAPTER_MULTICAST_ADDRESS = IP_ADAPTER_MULTICAST_ADDRESS_XP
#ENDIF

' // Size = 24 bytes
TYPE IP_ADAPTER_DNS_SERVER_ADDRESS_XP   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext       AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR   ' struct _IP_ADAPTER_DNS_SERVER_ADDRESS_XP *Next
#ELSE
   Next        AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR   ' struct _IP_ADAPTER_DNS_SERVER_ADDRESS_XP *Next
#ENDIF
   alignment__ AS DWORD                                  ' // To keep 8 byte alignment
   Address     AS SOCKET_ADDRESS                         ' SOCKET_ADDRESS Address
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
MACRO IP_ADAPTER_DNS_SERVER_ADDRESS = IP_ADAPTER_DNS_SERVER_ADDRESS_XP
#ENDIF

' // Size = 24 bytes
TYPE IP_ADAPTER_WINS_SERVER_ADDRESS_LH   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext       AS IP_ADAPTER_WINS_SERVER_ADDRESS_LH PTR   ' struct _IP_ADAPTER_WINS_SERVER_ADDRESS_LH *Next
#ELSE
   Next        AS IP_ADAPTER_WINS_SERVER_ADDRESS_LH PTR   ' struct _IP_ADAPTER_WINS_SERVER_ADDRESS_LH *Next
#ENDIF
   alignment__ AS DWORD                                   ' // To keeo 8 byte alignment
   Address     AS SOCKET_ADDRESS                          ' SOCKET_ADDRESS Address
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO IP_ADAPTER_WINS_SERVER_ADDRESS = IP_ADAPTER_WINS_SERVER_ADDRESS_LH
#ENDIF

' // Size = 24 bytes
TYPE IP_ADAPTER_GATEWAY_ADDRESS_LH   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext       AS IP_ADAPTER_GATEWAY_ADDRESS_LH PTR   ' struct _IP_ADAPTER_GATEWAY_ADDRESS_LH *Next
#ELSE
   Next        AS IP_ADAPTER_GATEWAY_ADDRESS_LH PTR   ' struct _IP_ADAPTER_GATEWAY_ADDRESS_LH *Next
#ENDIF
   alignment__ AS DWORD                               ' // To keep 8 byte alignment
   Address     AS SOCKET_ADDRESS                      ' SOCKET_ADDRESS Address
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO IP_ADAPTER_GATEWAY_ADDRESS = IP_ADAPTER_GATEWAY_ADDRESS_LH
#ENDIF

' // Size = 24 bytes
TYPE IP_ADAPTER_PREFIX_XP   ' Must be 8 byte aligned
   IP_ADAPTER_COMMON_UNION
#IF %DEF(%USEPBDECL)
   pNext        AS IP_ADAPTER_PREFIX_XP PTR   ' struct _IP_ADAPTER_PREFIX_XP *Next
#ELSE
   Next         AS IP_ADAPTER_PREFIX_XP PTR   ' struct _IP_ADAPTER_PREFIX_XP *Next
#ENDIF
   Address      AS SOCKET_ADDRESS             ' SOCKET_ADDRESS Address
   PrefixLength AS DWORD                      ' ULONG PrefixLength
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WINXP)
MACRO IP_ADAPTER_PREFIX = IP_ADAPTER_PREFIX_XP
#ENDIF

' // Size = 516 bytes
TYPE IP_ADAPTER_DNS_SUFFIX
#IF %DEF(%USEPBDECL)
   pNext   AS IP_ADAPTER_DNS_SUFFIX PTR                  ' struct _IP_ADAPTER_DNS_SUFFIX *Next
   sString AS WSTRINGZ * %MAX_DNS_SUFFIX_STRING_LENGTH   ' WCHAR String[MAX_DNS_SUFFIX_STRING_LENGTH]
#ELSE
   Next   AS IP_ADAPTER_DNS_SUFFIX PTR                   ' struct _IP_ADAPTER_DNS_SUFFIX *Next
   String AS WSTRINGZ * %MAX_DNS_SUFFIX_STRING_LENGTH    ' WCHAR String[MAX_DNS_SUFFIX_STRING_LENGTH]
#ENDIF
END TYPE

'//
'// Bit values of IP_ADAPTER_ADDRESSES Flags field.
'//
%IP_ADAPTER_DDNS_ENABLED               = &H00000001???
%IP_ADAPTER_REGISTER_ADAPTER_SUFFIX    = &H00000002???
%IP_ADAPTER_DHCP_ENABLED               = &H00000004???
%IP_ADAPTER_RECEIVE_ONLY               = &H00000008???
%IP_ADAPTER_NO_MULTICAST               = &H00000010???
%IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG = &H00000020???
%IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED = &H00000040???
%IP_ADAPTER_IPV4_ENABLED               = &H00000080???
%IP_ADAPTER_IPV6_ENABLED               = &H00000100???
%IP_ADAPTER_IPV6_MANAGE_ADDRESS_CONFIG = &H00000200???

' // Size = 8 bytes
TYPE IP_ADAPTER_ADDRESSES_UNION_STRUCT
   Length  AS DWORD   ' ULONG Length
   IfIndex AS DWORD   ' IF_INDEX IfIndex
END TYPE

' // Size = 8 bytes
UNION IP_ADAPTER_ADDRESSES_UNION
   Alignment AS QUAD   ' ULONGLONG
   IP_ADAPTER_ADDRESSES_UNION_STRUCT
END UNION

' // Size = 4 bytes
UNION IP_ADAPTER_ADDRESSES_FLAGS_UNION
   Flags                                    AS DWORD              ' ULONG
   DdnsEnabled                              AS BIT * 1 IN DWORD   ' ULONG
   RegisterAdapterSuffix                    AS BIT * 1
   Dhcpv4Enabled                            AS BIT * 1
   ReceiveOnly                              AS BIT * 1
   NoMulticast                              AS BIT * 1
   Ipv6OtherStatefulConfig                  AS BIT * 1
   NetbiosOverTcpipEnabled                  AS BIT * 1
   Ipv4Enabled                              AS BIT * 1
   Ipv6Enabled                              AS BIT * 1
   Ipv6ManagedAddressConfigurationSupported AS BIT * 1
END UNION

' // Size = 376 bytes
TYPE IP_ADAPTER_ADDRESSES_LH  ' Must be 8 byte aligned
   IP_ADAPTER_ADDRESSES_UNION
#IF %DEF(%USEPBDECL)
   pNext                  AS IP_ADAPTER_ADDRESSES_LH PTR             ' struct _IP_ADAPTER_ADDRESSES_LH *Next
#ELSE
   Next                   AS IP_ADAPTER_ADDRESSES_LH PTR             ' struct _IP_ADAPTER_ADDRESSES_LH *Next
#ENDIF
   AdapterName            AS ASCIIZ PTR                              ' PCHAR AdapterName
   FirstUnicastAddress    AS IP_ADAPTER_UNICAST_ADDRESS_LH PTR       ' PIP_ADAPTER_UNICAST_ADDRESS_LH FirstUnicastAddress
   FirstAnycastAddress    AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR       ' PIP_ADAPTER_ANYCAST_ADDRESS_XP FirstAnycastAddress
   FirstMulticastAddress  AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR     ' PIP_ADAPTER_MULTICAST_ADDRESS_XP FirstMulticastAddress
   FirstDnsServerAddress  AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR    ' PIP_ADAPTER_DNS_SERVER_ADDRESS_XP FirstDnsServerAddress
   DnsSuffix              AS WSTRINGZ PTR                            ' PWCHAR DnsSuffix
   Description            AS WSTRINGZ PTR                            ' PWCHAR Description
   FriendlyName           AS WSTRINGZ PTR                            ' PWCHAR FriendlyName
   PhysicalAddress        AS STRING * %MAX_ADAPTER_ADDRESS_LENGTH    ' BYTE PhysicalAddress[MAX_ADAPTER_ADDRESS_LENGTH]
   PhysicalAddressLength  AS DWORD                                   ' ULONG PhysicalAddressLength
   IP_ADAPTER_ADDRESSES_FLAGS_UNION
   Mtu                    AS DWORD                                   ' ULONG Mtu
   IfType                 AS DWORD                                   ' IFTYPE IfType
   OperStatus             AS LONG                                    ' IF_OPER_STATUS OperStatus enum
   Ipv6IfIndex            AS DWORD                                   ' IF_INDEX Ipv6IfIndex
   ZoneIndices(15)        AS DWORD                                   ' ULONG ZoneIndices[16]
   FirstPrefix            AS IP_ADAPTER_PREFIX_XP PTR                ' PIP_ADAPTER_PREFIX_XP FirstPrefix
   TransmitLinkSpeed      AS QUAD                                    ' ULONG64 TransmitLinkSpeed
   ReceiveLinkSpeed       AS QUAD                                    ' ULONG64 ReceiveLinkSpeed
   FirstWinsServerAddress AS IP_ADAPTER_WINS_SERVER_ADDRESS_LH PTR   ' PIP_ADAPTER_WINS_SERVER_ADDRESS_LH FirstWinsServerAddress
   FirstGatewayAddress    AS IP_ADAPTER_GATEWAY_ADDRESS_LH PTR       ' PIP_ADAPTER_GATEWAY_ADDRESS_LH FirstGatewayAddress
   Ipv4Metric             AS DWORD                                   ' ULONG Ipv4Metric
   Ipv6Metric             AS DWORD                                   ' ULONG Ipv6Metric
   Luid                   AS IF_LUID                                 ' IF_LUID Luid
   Dhcpv4Server           AS SOCKET_ADDRESS                          ' SOCKET_ADDRESS Dhcpv4Server
   CompartmentId          AS DWORD                                   ' NET_IF_COMPARTMENT_ID CompartmentId
   NetworkGuid            AS GUID                                    ' NET_IF_NETWORK_GUID NetworkGuid
   ConnectionType         AS LONG                                    ' NET_IF_CONNECTION_TYPE ConnectionType
   TunnelType             AS LONG                                    ' TUNNEL_TYPE TunnelType
   Dhcpv6Server           AS SOCKET_ADDRESS                          ' SOCKET_ADDRESS Dhcpv6Server
#IF %DEF(%USEPBDECL)
   Dhcpv6ClientDuid(%MAX_DHCPV6_DUID_LENGTH-1) AS BYTE
#ELSE
   Dhcpv6ClientDuid       AS STRING * %MAX_DHCPV6_DUID_LENGTH        ' BYTE Dhcpv6ClientDuid[MAX_DHCPV6_DUID_LENGTH]
#ENDIF
   alignment1__           AS WORD                                    ' // To keep 8 byte alignment
   Dhcpv6ClientDuidLength AS DWORD                                   ' ULONG Dhcpv6ClientDuidLength
   Dhcpv6Iaid             AS DWORD                                   ' ULONG Dhcpv6Iaid
'#if (NTDDI_VERSION >= NTDDI_VISTASP1)
   FirstDnsSuffix         AS IP_ADAPTER_DNS_SUFFIX PTR               ' PIP_ADAPTER_DNS_SUFFIX FirstDnsSuffix
   alignment2__           AS DWORD                                   ' To keep 8 byte alignment
'#endif
END TYPE

' // Size = 144 bytes
TYPE IP_ADAPTER_ADDRESSES_XP   ' Must be 8 bytes aligned
   IP_ADAPTER_ADDRESSES_UNION
#IF %DEF(%USEPBDECL)
   pNext                 AS IP_ADAPTER_ADDRESSES_XP PTR            ' struct _IP_ADAPTER_ADDRESSES_XP *Next
#ELSE
   Next                  AS IP_ADAPTER_ADDRESSES_XP PTR            ' struct _IP_ADAPTER_ADDRESSES_XP *Next
#ENDIF
   AdapterName           AS ASCIIZ PTR                             ' PCHAR AdapterName
   FirstUnicastAddress   AS IP_ADAPTER_UNICAST_ADDRESS_XP PTR      ' PIP_ADAPTER_UNICAST_ADDRESS_XP FirstUnicastAddress
   FirstAnycastAddress   AS IP_ADAPTER_ANYCAST_ADDRESS_XP PTR      ' PIP_ADAPTER_ANYCAST_ADDRESS_XP FirstAnycastAddress
   FirstMulticastAddress AS IP_ADAPTER_MULTICAST_ADDRESS_XP PTR    ' PIP_ADAPTER_MULTICAST_ADDRESS_XP FirstMulticastAddress
   FirstDnsServerAddress AS IP_ADAPTER_DNS_SERVER_ADDRESS_XP PTR   ' PIP_ADAPTER_DNS_SERVER_ADDRESS_XP FirstDnsServerAddress
   DnsSuffix             AS WSTRINGZ PTR                           ' PWCHAR DnsSuffix
   Description           AS WSTRINGZ PTR                           ' PWCHAR Description
   FriendlyName          AS WSTRINGZ PTR                           ' PWCHAR FriendlyName
#IF %DEF(%USEPBDECL)
   PhysicalAddress(%MAX_ADAPTER_ADDRESS_LENGTH-1) AS BYTE
#ELSE
   PhysicalAddress       AS STRING * %MAX_ADAPTER_ADDRESS_LENGTH   ' BYTE PhysicalAddress[MAX_ADAPTER_ADDRESS_LENGTH]
#ENDIF
   PhysicalAddressLength AS DWORD                                  ' DWORD PhysicalAddressLength
   Flags                 AS DWORD                                  ' DWORD Flags
   Mtu                   AS DWORD                                  ' DWORD Mtu
   IfType                AS DWORD                                  ' DWORD IfType
   OperStatus            AS LONG                                   ' IF_OPER_STATUS OperStatus
   Ipv6IfIndex           AS DWORD                                  ' DWORD Ipv6IfIndex
   ZoneIndices(15)       AS DWORD                                  ' DWORD ZoneIndices[16]
   FirstPrefix           AS IP_ADAPTER_PREFIX_XP PTR               ' PIP_ADAPTER_PREFIX_XP FirstPrefix
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
MACRO IP_ADAPTER_ADDRESSES = IP_ADAPTER_ADDRESSES_LH
#ELSEIF (%NTDDI_VERSION >= %NTDDI_WINXP)
MACRO IP_ADAPTER_ADDRESSES = IP_ADAPTER_ADDRESSES_XP
#ENDIF

'//
'// Flags used as argument to GetAdaptersAddresses().
'// "SKIP" flags are added when the default is to include the information.
'// "INCLUDE" flags are added when the default is to skip the information.
'//
%GAA_FLAG_SKIP_UNICAST                = &H0001???
%GAA_FLAG_SKIP_ANYCAST                = &H0002???
%GAA_FLAG_SKIP_MULTICAST              = &H0004???
%GAA_FLAG_SKIP_DNS_SERVER             = &H0008???
%GAA_FLAG_INCLUDE_PREFIX              = &H0010???
%GAA_FLAG_SKIP_FRIENDLY_NAME          = &H0020???
%GAA_FLAG_INCLUDE_WINS_INFO           = &H0040???
%GAA_FLAG_INCLUDE_GATEWAYS            = &H0080???
%GAA_FLAG_INCLUDE_ALL_INTERFACES      = &H0100???
%GAA_FLAG_INCLUDE_ALL_COMPARTMENTS    = &H0200???
%GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER = &H0400???

'#endif /* _WINSOCK2API_ */
#ENDIF   ' #IF %DEF(%WINSOCK2API)

'//
'// IP_PER_ADAPTER_INFO - per-adapter IP information such as DNS server list.
'//

' // Size = 52 bytes
TYPE IP_PER_ADAPTER_INFO_W2KSP1 DWORD FILL
   AutoconfigEnabled AS DWORD                ' UINT AutoconfigEnabled
   AutoconfigActive  AS DWORD                ' UINT AutoconfigActive
   CurrentDnsServer  AS IP_ADDR_STRING PTR   ' PIP_ADDR_STRING CurrentDnsServer
   DnsServerList     AS IP_ADDR_STRING       ' IP_ADDR_STRING DnsServerList
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
   MACRO IP_PER_ADAPTER_INFO = IP_PER_ADAPTER_INFO_W2KSP1
#ENDIF

'//
'// FIXED_INFO - the set of IP-related information which does not depend on DHCP
'//

' // Size = 584 bytes
TYPE FIXED_INFO_W2KSP1 DWORD FILL
   HostName         AS ASCIIZ * %MAX_HOSTNAME_LEN + 4      ' char HostName[MAX_HOSTNAME_LEN + 4]
   DomainName       AS ASCIIZ * %MAX_DOMAIN_NAME_LEN + 4   ' char DomainName[MAX_DOMAIN_NAME_LEN + 4]
   CurrentDnsServer AS IP_ADDR_STRING PTR                  ' PIP_ADDR_STRING CurrentDnsServer
   DnsServerList    AS IP_ADDR_STRING                      ' IP_ADDR_STRING DnsServerList
   NodeType         AS DWORD                               ' UINT NodeType
   ScopeId          AS ASCIIZ * %MAX_SCOPE_ID_LEN + 4      ' char ScopeId[MAX_SCOPE_ID_LEN + 4]
   EnableRouting    AS DWORD                               ' UINT EnableRouting
   EnableProxy      AS DWORD                               ' UINT EnableProxy
   EnableDns        AS DWORD                               ' UINT EnableDns
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
   MACRO FIXED_INFO = FIXED_INFO_W2KSP1
#ENDIF

#IF NOT %DEF(%IP_INTERFACE_NAME_INFO_DEFINED)
    %IP_INTERFACE_NAME_INFO_DEFINED = 1

' // Size = 44 bytes
TYPE IP_INTERFACE_NAME_INFO_W2KSP1 DWORD FILL
   Index          AS DWORD   ' ULONG Index           // Interface Index
   MediaType      AS DWORD   ' ULONG MediaType       // Interface Types - see ipifcons.h
   ConnectionType AS BYTE    ' UCHAR ConnectionType
   AccessType     AS BYTE    ' UCHAR AccessType
   DeviceGuid     AS GUID    ' GUID  DeviceGuid      // Device GUID is the guid of the device that IP exposes
   InterfaceGuid  AS GUID    ' GUID  InterfaceGuid   // Interface GUID, if not GUID_NULL is the
                             '                       // GUID for the interface mapped to the device.
END TYPE

#IF (%NTDDI_VERSION >= %NTDDI_WIN2KSP1)
   MACRO IP_INTERFACE_NAME_INFO = IP_INTERFACE_NAME_INFO_W2KSP1
#ENDIF

#ENDIF
