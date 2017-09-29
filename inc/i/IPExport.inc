' ########################################################################################
' Microsoft Windows
' File: IPExport.inc
' Contents: Public definitions exported to transport layer and application software.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPEXPORT_INC = 1

'//
'// IP type definitions.
'//
'typedef ULONG IPAddr;       // An IP address.
'typedef ULONG IPMask;       // An IP subnet mask.
'typedef ULONG IP_STATUS;    // Status code returned from IP APIs.

#INCLUDE ONCE "in6addr.inc"

'typedef struct in6_addr IPv6Addr;
MACRO IPv6Addr = in6_addr

#INCLUDE ONCE "inaddr.inc"

'/*INC*/

'//
'// The ip_option_information structure describes the options to be
'// included in the header of an IP packet. The TTL, TOS, and Flags
'// values are carried in specific fields in the header. The OptionsData
'// bytes are carried in the options area following the standard IP header.
'// With the exception of source route options, this data must be in the
'// format to be transmitted on the wire as specified in RFC 791. A source
'// route option should contain the full route - first hop thru final
'// destination - in the route data. The first hop will be pulled out of the
'// data and the option will be reformatted accordingly. Otherwise, the route
'// option should be formatted as specified in RFC 791.
'//

' // Size = 8 bytes
TYPE IP_OPTION_INFORMATION BYTE
   Ttl         AS BYTE      ' UCHAR   Ttl          // Time To Live
   Tos         AS BYTE      ' UCHAR   Tos          // Type Of Service
   Flags       AS BYTE      ' UCHAR   Flags        // IP header flags
   OptionsSize AS BYTE      ' UCHAR   OptionsSize  // Size in bytes of options data
   OptionsData AS BYTE PTR  ' PUCHAR  OptionsData  // Pointer to options data
END TYPE

'#if defined(_WIN64)

'typedef struct ip_option_information32 {
'    UCHAR   Ttl;
'    UCHAR   Tos;
'    UCHAR   Flags;
'    UCHAR   OptionsSize;
'    UCHAR * POINTER_32 OptionsData;
'} IP_OPTION_INFORMATION32, *PIP_OPTION_INFORMATION32;

'#endif // _WIN64

'//
'// The icmp_echo_reply structure describes the data returned in response
'// to an echo request.
'//

' // Size = 28 bytes
TYPE ICMP_ECHO_REPLY BYTE
   Address       AS DWORD                   ' IPAddr  Address;            // Replying address
   Status        AS DWORD                   ' ULONG   Status;             // Reply IP_STATUS
   RoundTripTime AS DWORD                   ' ULONG   RoundTripTime;      // RTT in milliseconds
   DataSize      AS WORD                    ' USHORT  DataSize;           // Reply data size in bytes
   Reserved      AS WORD                    ' USHORT  Reserved;           // Reserved for system use
   pData         AS BYTE PTR                ' PVOID   Data;               // Pointer to the reply data
   Options       AS IP_OPTION_INFORMATION   ' struct ip_option_information Options; // Reply options
END TYPE

'#if defined(_WIN64)

'typedef struct icmp_echo_reply32 {
'    IPAddr  Address;
'    ULONG   Status;
'    ULONG   RoundTripTime;
'    USHORT  DataSize;
'    USHORT  Reserved;
'    VOID * POINTER_32 Data;
'    struct ip_option_information32 Options;
'} ICMP_ECHO_REPLY32, *PICMP_ECHO_REPLY32;

'#endif // _WIN64

'#include <packon.h>
' // Size = 26 bytes
TYPE IPV6_ADDRESS_EX WORD
   sin6_port     AS WORD    ' USHORT
   sin6_flowinfo AS DWORD   ' ULONG
   sin6_addr(7)  AS WORD    ' USHORT[8]
   sin6_scope_id AS DWORD   ' ULONG
END TYPE
'#include <packoff.h>

' // Size = 36 bytes
TYPE ICMPV6_ECHO_REPLY_LH DWORD
   Address AS IPV6_ADDRESS_EX   ' // Replying address.
   Status AS DWORD              ' ULONG // Reply IP_STATUS.
   RoundTripTime AS DWORD       ' unisgned int // RTT in milliseconds.
   ' // Reply data follows this structure in memory.
END TYPE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef ICMPV6_ECHO_REPLY_LH ICMPV6_ECHO_REPLY;
'typedef ICMPV6_ECHO_REPLY_LH *PICMPV6_ECHO_REPLY;
'#endif

' // Size = 8 bytes
TYPE ARP_SEND_REPLY DWORD
   DestAddress AS DWORD   ' IPAddr  DestAddress
   SrcAddress  AS DWORD   ' IPAddr  SrcAddress
END TYPE

' // Size = 4 bytes
TYPE TCP_RESERVE_PORT_RANGE WORD
   UpperRange AS WORD   ' USHORT  UpperRange
   LowerRange AS WORD   ' USHORT  LowerRange
END TYPE

%MAX_ADAPTER_NAME = 128

' // To workaround the difference between PB includes, that use sName instead of Name.
UNION IP_ADAPTER_INDEX_MAP_NAME_UNION
   sName AS WSTRINGZ * %MAX_ADAPTER_NAME
   Name AS WSTRINGZ * %MAX_ADAPTER_NAME   ' WCHAR   Name[MAX_ADAPTER_NAME]
END UNION
' // Size = 260 bytes
TYPE IP_ADAPTER_INDEX_MAP DWORD
   Index AS DWORD                         ' ULONG   Index
   IP_ADAPTER_INDEX_MAP_NAME_UNION
END TYPE

' // Size = 264 bytes
TYPE IP_INTERFACE_INFO DWORD
   NumAdapters AS LONG                   ' LONG                 NumAdapters
   Adapter(0)  AS IP_ADAPTER_INDEX_MAP   ' IP_ADAPTER_INDEX_MAP Adapter[1]
END TYPE

' // Size = 8 bytes
TYPE IP_UNIDIRECTIONAL_ADAPTER_ADDRESS DWORD
   NumAdapters AS DWORD   ' ULONG   NumAdapters
   Address(0)  AS DWORD   ' IPAddr  Address[1]
END TYPE

' // Size = 8 bytes
TYPE IP_ADAPTER_ORDER_MAP DWORD
    NumAdapters     AS DWORD   ' ULONG   NumAdapters
    AdapterOrder(0) AS DWORD   ' ULONG   AdapterOrder[1]
END TYPE

' // Size = 32 bytes
TYPE IP_MCAST_COUNTER_INFO QWORD
   InMcastOctets  AS QUAD   ' ULONG64 InMcastOctets
   OutMcastOctets AS QUAD   ' ULONG64 OutMcastOctets
   InMcastPkts    AS QUAD   ' ULONG64 InMcastPkts
   OutMcastPkts   AS QUAD   ' ULONG64 OutMcastPkts
END TYPE

'//
'// IP_STATUS codes returned from IP APIs
'//

%IP_STATUS_BASE            = 11000

%IP_SUCCESS                = 0
%IP_BUF_TOO_SMALL          = %IP_STATUS_BASE + 1
%IP_DEST_NET_UNREACHABLE   = %IP_STATUS_BASE + 2
%IP_DEST_HOST_UNREACHABLE  = %IP_STATUS_BASE + 3
%IP_DEST_PROT_UNREACHABLE  = %IP_STATUS_BASE + 4
%IP_DEST_PORT_UNREACHABLE  = %IP_STATUS_BASE + 5
%IP_NO_RESOURCES           = %IP_STATUS_BASE + 6
%IP_BAD_OPTION             = %IP_STATUS_BASE + 7
%IP_HW_ERROR               = %IP_STATUS_BASE + 8
%IP_PACKET_TOO_BIG         = %IP_STATUS_BASE + 9
%IP_REQ_TIMED_OUT          = %IP_STATUS_BASE + 10
%IP_BAD_REQ                = %IP_STATUS_BASE + 11
%IP_BAD_ROUTE              = %IP_STATUS_BASE + 12
%IP_TTL_EXPIRED_TRANSIT    = %IP_STATUS_BASE + 13
%IP_TTL_EXPIRED_REASSEM    = %IP_STATUS_BASE + 14
%IP_PARAM_PROBLEM          = %IP_STATUS_BASE + 15
%IP_SOURCE_QUENCH          = %IP_STATUS_BASE + 16
%IP_OPTION_TOO_BIG         = %IP_STATUS_BASE + 17
%IP_BAD_DESTINATION        = %IP_STATUS_BASE + 18

'//
'// Variants of the above using IPv6 terminology, where different
'//

%IP_DEST_NO_ROUTE            = %IP_STATUS_BASE + 2
%IP_DEST_ADDR_UNREACHABLE    = %IP_STATUS_BASE + 3
%IP_DEST_PROHIBITED          = %IP_STATUS_BASE + 4
%IP_DEST_PORT_UNREACHABLE    = %IP_STATUS_BASE + 5
%IP_HOP_LIMIT_EXCEEDED       = %IP_STATUS_BASE + 13
%IP_REASSEMBLY_TIME_EXCEEDED = %IP_STATUS_BASE + 14
%IP_PARAMETER_PROBLEM        = %IP_STATUS_BASE + 15

'//
'// IPv6-only status codes
'//

%IP_DEST_UNREACHABLE         = %IP_STATUS_BASE + 40
%IP_TIME_EXCEEDED            = %IP_STATUS_BASE + 41
%IP_BAD_HEADER               = %IP_STATUS_BASE + 42
%IP_UNRECOGNIZED_NEXT_HEADER = %IP_STATUS_BASE + 43
%IP_ICMP_ERROR               = %IP_STATUS_BASE + 44
%IP_DEST_SCOPE_MISMATCH      = %IP_STATUS_BASE + 45

'//
'// The next group are status codes passed up on status indications to
'// transport layer protocols.
'//
%IP_ADDR_DELETED             = %IP_STATUS_BASE + 19
%IP_SPEC_MTU_CHANGE          = %IP_STATUS_BASE + 20
%IP_MTU_CHANGE               = %IP_STATUS_BASE + 21
%IP_UNLOAD                   = %IP_STATUS_BASE + 22
%IP_ADDR_ADDED               = %IP_STATUS_BASE + 23
%IP_MEDIA_CONNECT            = %IP_STATUS_BASE + 24
%IP_MEDIA_DISCONNECT         = %IP_STATUS_BASE + 25
%IP_BIND_ADAPTER             = %IP_STATUS_BASE + 26
%IP_UNBIND_ADAPTER           = %IP_STATUS_BASE + 27
%IP_DEVICE_DOES_NOT_EXIST    = %IP_STATUS_BASE + 28
%IP_DUPLICATE_ADDRESS        = %IP_STATUS_BASE + 29
%IP_INTERFACE_METRIC_CHANGE  = %IP_STATUS_BASE + 30
%IP_RECONFIG_SECFLTR         = %IP_STATUS_BASE + 31
%IP_NEGOTIATING_IPSEC        = %IP_STATUS_BASE + 32
%IP_INTERFACE_WOL_CAPABILITY_CHANGE  = %IP_STATUS_BASE + 33
%IP_DUPLICATE_IPADD          = %IP_STATUS_BASE + 34
%IP_NO_FURTHER_SENDS         = %IP_STATUS_BASE + 35   ' Removed in Windows Vista SDK

%IP_GENERAL_FAILURE          = %IP_STATUS_BASE + 50
%MAX_IP_STATUS               = %IP_GENERAL_FAILURE
%IP_PENDING                  = %IP_STATUS_BASE + 255

'//
'// Values used in the IP header Flags field.
'//
%IP_FLAG_REVERSE = &H1        ' // Do a round-trip echo request.
%IP_FLAG_DF      = &H2        ' // Don't fragment this packet.

'//
'// Supported IP Option Types.
'//
'// These types define the options which may be used in the OptionsData field
'// of the ip_option_information structure.  See RFC 791 for a complete
'// description of each.
'//
%IP_OPT_EOL          = 0     ' End of list option
%IP_OPT_NOP          = 1     ' No operation
%IP_OPT_SECURITY     = &H82  ' Security option
%IP_OPT_LSRR         = &H83  ' Loose source route
%IP_OPT_SSRR         = &H89  ' Strict source route
%IP_OPT_RR           = &H7   ' Record route
%IP_OPT_TS           = &H44  ' Timestamp
%IP_OPT_SID          = &H88  ' Stream ID (obsolete)
%IP_OPT_ROUTER_ALERT = &H94  ' Router Alert Option

%MAX_OPT_SIZE        = 40    ' Maximum length of IP options in bytes

#IF %DEF(%CHICAGO)

'// Ioctls code exposed by Memphis tcpip stack.
'// For NT these ioctls are define in ntddip.h  (private\inc)

%IOCTL_IP_RTCHANGE_NOTIFY_REQUEST        = 101
%IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST       = 102
%IOCTL_ARP_SEND_REQUEST                  = 103
%IOCTL_IP_INTERFACE_INFO                 = 104
%IOCTL_IP_GET_BEST_INTERFACE             = 105
%IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS = 106

#ENDIF
