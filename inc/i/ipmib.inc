' ########################################################################################
' Microsoft Windows
' File: ipmib.inc
' Contents: Public definitions and structures for the IP-specific parts of MIB-II.
' These definitions were previously in iprtrmib.h, which now includes this file.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPMIB_INC = 1

#INCLUDE ONCE "windows.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

'//
'// Pick up definitions of MAXLEN_PHYSADDR, etc.
'//
#INCLUDE ONCE "ifmib.inc"

#INCLUDE ONCE "nldef.inc"

%MIB_IPADDR_PRIMARY      = &H0001  ' // Primary ipaddr
%MIB_IPADDR_DYNAMIC      = &H0004  ' // Dynamic ipaddr
%MIB_IPADDR_DISCONNECTED = &H0008  ' // Address is on disconnected interface
%MIB_IPADDR_DELETED      = &H0040  ' // Address being deleted
%MIB_IPADDR_TRANSIENT    = &H0080  ' // Transient address
%MIB_IPADDR_DNS_ELIGIBLE = &H0100  ' // Address is published in DNS.

' // Size = 24 bytes
TYPE MIB_IPADDRROW_XP WORD
   dwAddr      AS DWORD   ' DWORD
   dwIndex     AS DWORD   ' IF_INDEX
   dwMask      AS DWORD   ' DWORD
   dwBCastAddr AS DWORD   ' DWORD
   dwReasmSize AS DWORD   ' DWORD
   unused1     AS WORD    ' unsigned short
   wType       AS WORD    ' unsigned short
END TYPE

' // Size = 24 bytes
TYPE MIB_IPADDRROW_W2K WORD
   dwAddr      AS DWORD   ' DWORD
   dwIndex     AS DWORD   ' DWORD
   dwMask      AS DWORD   ' DWORD
   dwBCastAddr AS DWORD   ' DWORD
   dwReasmSize AS DWORD   ' DWORD
   unused1     AS WORD    ' unsigned short
   unused2     AS WORD    ' unsigned short
END TYPE

#IF %WINVER >= &H0501
   MACRO MIB_IPADDRROW = MIB_IPADDRROW_XP
#ELSEIF %WINVER >= &H0500
   MACRO MIB_IPADDRROW = MIB_IPADDRROW_W2K
#ELSE
   MACRO MIB_IPADDRROW = MIB_IPADDRROW_XP
#ENDIF

' // Size = 28 bytes
TYPE MIB_IPADDRTABLE DWORD
   dwNumEntries AS DWORD           ' DWORD
   table(0)     AS MIB_IPADDRROW   ' MIB_IPADDRROW table[ANY_SIZE];
END TYPE

'#define SIZEOF_IPADDRTABLE(X) (FIELD_OFFSET(MIB_IPADDRTABLE,table[0]) + \
'                               ((X) * sizeof(MIB_IPADDRROW)) + ALIGN_SIZE)

' // Size = 4 bytes
TYPE MIB_IPFORWARDNUMBER DWORD
   dwValue AS DWORD   ' DWORD
END TYPE

'typedef NL_ROUTE_PROTOCOL MIB_IPFORWARD_PROTO;

' enum MIB_IPFORWARD_TYPE
%MIB_IPROUTE_TYPE_OTHER    = 1
%MIB_IPROUTE_TYPE_INVALID  = 2
%MIB_IPROUTE_TYPE_DIRECT   = 3
%MIB_IPROUTE_TYPE_INDIRECT = 4

' // Size = 4 bytes
UNION MIB_IPFORWARDROW_UNION_1 DWORD
   dwForwardType AS DWORD   ' DWORD // Old field name uses DWORD type.
   ForwardType   AS LONG    ' MIB_IPFORWARD_TYPE // New field name uses enum type.
END UNION

' // Size = 4 bytes
UNION MIB_IPFORWARDROW_UNION_2 DWORD
   dwForwardProto AS DWORD   ' DWORD // Old field name uses DWORD type.
   ForwardProto   AS LONG    ' MIB_IPFORWARD_PROTO // New field name uses enum type.
END UNION

' // Size = 56 bytes
TYPE MIB_IPFORWARDROW DWORD
   dwForwardDest      AS DWORD   ' DWORD
   dwForwardMask      AS DWORD   ' DWORD
   dwForwardPolicy    AS DWORD   ' DWORD
   dwForwardNextHop   AS DWORD   ' DWORD
   dwForwardIfIndex   AS DWORD   ' IF_INDEX
   MIB_IPFORWARDROW_UNION_1
   MIB_IPFORWARDROW_UNION_2
   dwForwardAge       AS DWORD   ' DWORD
   dwForwardNextHopAS AS DWORD   ' DWORD
   dwForwardMetric1   AS DWORD   ' DWORD
   dwForwardMetric2   AS DWORD   ' DWORD
   dwForwardMetric3   AS DWORD   ' DWORD
   dwForwardMetric4   AS DWORD   ' DWORD
   dwForwardMetric5   AS DWORD   ' DWORD
END TYPE

%MIB_IPROUTE_TYPE_OTHER    = 1
%MIB_IPROUTE_TYPE_INVALID  = 2
%MIB_IPROUTE_TYPE_DIRECT   = 3
%MIB_IPROUTE_TYPE_INDIRECT = 4

%MIB_IPROUTE_METRIC_UNUSED = &HFFFFFFFF???   ' (DWORD)-1


' // Size = 60 bytes
TYPE MIB_IPFORWARDTABLE DWORD
   dwNumEntries AS DWORD              ' DWORD
   table(0)     AS MIB_IPFORWARDROW   ' MIB_IPFORWARDROW table[ANY_SIZE];
END TYPE

'#define SIZEOF_IPFORWARDTABLE(X) \
'            (FIELD_OFFSET(MIB_IPFORWARDTABLE,table[0]) + \
'             ((X) * sizeof(MIB_IPFORWARDROW)) + ALIGN_SIZE)

' enum MIB_IPNET_TYPE
%MIB_IPNET_TYPE_OTHER   = 1
%MIB_IPNET_TYPE_INVALID = 2
%MIB_IPNET_TYPE_DYNAMIC = 3
%MIB_IPNET_TYPE_STATIC  = 4

' // Size = 4 bytes
UNION MIB_IPNETROW_LH_UNION DWORD
   dwType AS DWORD   ' DWORD // Old field name was just a DWORD.
   Type   AS LONG    ' MIB_IPNET_TYPE // New field name uses the enum type.
END UNION

' // Size = 24 bytes
TYPE MIB_IPNETROW_LH DWORD
   dwIndex                         AS DWORD  ' IF_INDEX
   dwPhysAddrLen                   AS DWORD  ' DWORD
   bPhysAddr(%MAXLEN_PHYSADDR - 1) AS BYTE   ' UCHAR
   dwAddr                          AS DWORD  ' DWORD
   MIB_IPNETROW_LH_UNION
END TYPE

' // Size = 24 bytes
TYPE MIB_IPNETROW_W2K DWORD
   dwIndex AS DWORD                          ' IF_INDEX
   dwPhysAddrLen AS DWORD                    ' DWORD
   bPhysAddr(%MAXLEN_PHYSADDR - 1) AS BYTE   ' UCHAR
   dwAddr AS DWORD                           ' DWORD
   dwType AS DWORD                           ' DWORD
END TYPE

#IF %WINVER >= &H0600
    MACRO MIB_IPNETROW = MIB_IPNETROW_LH
#ELSEIF %WINVER >= &H0500
    MACRO MIB_IPNETROW = MIB_IPNETROW_W2K
#ELSE
    MACRO MIB_IPNETROW = MIB_IPNETROW_LH
#ENDIF

TYPE MIB_IPNETTABLE
   dwNumEntries AS DWORD          ' DWORD
   table(0)     AS MIB_IPNETROW   ' MIB_IPNETROW table[ANY_SIZE]
END TYPE

'#define SIZEOF_IPNETTABLE(X) (FIELD_OFFSET(MIB_IPNETTABLE, table[0]) + \
'                              ((X) * sizeof(MIB_IPNETROW)) + ALIGN_SIZE)

' enum MIB_IPSTATS_FORWARDING
%MIB_IP_FORWARDING     = 1
%MIB_IP_NOT_FORWARDING = 2

%MIB_USE_CURRENT_TTL        = &HFFFFFFFF???   ' ((DWORD)-1)
%MIB_USE_CURRENT_FORWARDING = &HFFFFFFFF???   ' ((DWORD)-1)

' // Size = 4 bytes
UNION MIB_IPSTATS_LH_UNION DWORD
   dwForwarding AS DWORD   ' DWORD
   Forwarding   AS LONG    ' MIB_IPSTATS_FORWARDING
END UNION

' // Size = 92 bytes
TYPE MIB_IPSTATS_LH DWORD
   MIB_IPSTATS_LH_UNION
   dwDefaultTTL      AS DWORD   ' DWORD
   dwInReceives      AS DWORD   ' DWORD
   dwInHdrErrors     AS DWORD   ' DWORD
   dwInAddrErrors    AS DWORD   ' DWORD
   dwForwDatagrams   AS DWORD   ' DWORD
   dwInUnknownProtos AS DWORD   ' DWORD
   dwInDiscards      AS DWORD   ' DWORD
   dwInDelivers      AS DWORD   ' DWORD
   dwOutRequests     AS DWORD   ' DWORD
   dwRoutingDiscards AS DWORD   ' DWORD
   dwOutDiscards     AS DWORD   ' DWORD
   dwOutNoRoutes     AS DWORD   ' DWORD
   dwReasmTimeout    AS DWORD   ' DWORD
   dwReasmReqds      AS DWORD   ' DWORD
   dwReasmOks        AS DWORD   ' DWORD
   dwReasmFails      AS DWORD   ' DWORD
   dwFragOks         AS DWORD   ' DWORD
   dwFragFails       AS DWORD   ' DWORD
   dwFragCreates     AS DWORD   ' DWORD
   dwNumIf           AS DWORD   ' DWORD
   dwNumAddr         AS DWORD   ' DWORD
   dwNumRoutes       AS DWORD   ' DWORD
END TYPE

' // Size = 92 bytes
TYPE MIB_IPSTATS_W2K DWORD
   dwForwarding      AS DWORD   ' DWORD
   dwDefaultTTL      AS DWORD   ' DWORD
   dwInReceives      AS DWORD   ' DWORD
   dwInHdrErrors     AS DWORD   ' DWORD
   dwInAddrErrors    AS DWORD   ' DWORD
   dwForwDatagrams   AS DWORD   ' DWORD
   dwInUnknownProtos AS DWORD   ' DWORD
   dwInDiscards      AS DWORD   ' DWORD
   dwInDelivers      AS DWORD   ' DWORD
   dwOutRequests     AS DWORD   ' DWORD
   dwRoutingDiscards AS DWORD   ' DWORD
   dwOutDiscards     AS DWORD   ' DWORD
   dwOutNoRoutes     AS DWORD   ' DWORD
   dwReasmTimeout    AS DWORD   ' DWORD
   dwReasmReqds      AS DWORD   ' DWORD
   dwReasmOks        AS DWORD   ' DWORD
   dwReasmFails      AS DWORD   ' DWORD
   dwFragOks         AS DWORD   ' DWORD
   dwFragFails       AS DWORD   ' DWORD
   dwFragCreates     AS DWORD   ' DWORD
   dwNumIf           AS DWORD   ' DWORD
   dwNumAddr         AS DWORD   ' DWORD
   dwNumRoutes       AS DWORD   ' DWORD
END TYPE

#IF %WINVER >= &H0600
    MACRO MIB_IPSTATS = MIB_IPSTATS_LH
#ELSEIF %WINVER >= &H0500
    MACRO MIB_IPSTATS = MIB_IPSTATS_W2K
#ELSE
    MACRO MIB_IPSTATS = MIB_IPSTATS_LH
#ENDIF

' // Size = 52 bytes
TYPE MIBICMPSTATS DWORD
   dwMsgs          AS DWORD   ' DWORD
   dwErrors        AS DWORD   ' DWORD
   dwDestUnreachs  AS DWORD   ' DWORD
   dwTimeExcds     AS DWORD   ' DWORD
   dwParmProbs     AS DWORD   ' DWORD
   dwSrcQuenchs    AS DWORD   ' DWORD
   dwRedirects     AS DWORD   ' DWORD
   dwEchos         AS DWORD   ' DWORD
   dwEchoReps      AS DWORD   ' DWORD
   dwTimestamps    AS DWORD   ' DWORD
   dwTimestampReps AS DWORD   ' DWORD
   dwAddrMasks     AS DWORD   ' DWORD
   dwAddrMaskReps  AS DWORD   ' DWORD
END TYPE

' // Size = 104 bytes
TYPE MIBICMPINFO DWORD
   icmpInStats  AS MIBICMPSTATS
   icmpOutStats AS MIBICMPSTATS
END TYPE

' // Size = 104 bytes
TYPE MIB_ICMP DWORD
   stats AS MIBICMPINFO
END TYPE

' // Size = 1032 bytes
TYPE MIBICMPSTATS_EX DWORD
   dwMsgs             AS DWORD   ' DWORD
   dwErrors           AS DWORD   ' DWORD
   rgdwTypeCount(255) AS DWORD   ' DWORD[256]
END TYPE

' // Size = 2064 bytes
TYPE MIB_ICMP_EX DWORD
   icmpInStats  AS MIBICMPSTATS_EX
   icmpOutStats AS MIBICMPSTATS_EX
END TYPE

'//
'// ICMP6_TYPE
'//
'// ICMPv6 Type Values from RFC 2292, 2461 (ND), and 3810 (MLDv2)
'//

' enum ICMP6_TYPE
%ICMP6_DST_UNREACH          =   1
%ICMP6_PACKET_TOO_BIG       =   2
%ICMP6_TIME_EXCEEDED        =   3
%ICMP6_PARAM_PROB           =   4
%ICMP6_ECHO_REQUEST         = 128
%ICMP6_ECHO_REPLY           = 129
%ICMP6_MEMBERSHIP_QUERY     = 130
%ICMP6_MEMBERSHIP_REPORT    = 131
%ICMP6_MEMBERSHIP_REDUCTION = 132
%ND_ROUTER_SOLICIT          = 133
%ND_ROUTER_ADVERT           = 134
%ND_NEIGHBOR_SOLICIT        = 135
%ND_NEIGHBOR_ADVERT         = 136
%ND_REDIRECT                = 137
%ICMP6_V2_MEMBERSHIP_REPORT = 143

'//
'// Used to identify informational/error messages.
'//
%ICMP6_INFOMSG_MASK = &H80
'#define ICMP6_ISTYPEINFORMATIONAL(Type) (((Type) & ICMP6_INFOMSG_MASK) != 0)
'#define ICMP6_ISTYPEERROR(Type) (!ICMP6_ISTYPEINFORMATIONAL(Type))

MACRO ICMP6_ISTYPEINFORMATIONAL(nType) = (((nType) AND %ICMP6_INFOMSG_MASK) <> 0)
MACRO ICMP6_ISTYPEERROR(nType) = (NOT ICMP6_ISTYPEINFORMATIONAL(nType))

'//
'// ICMP4_TYPE
'//
'// There are no RFC-specified defines for ICMPv4 message types, so we try to
'// use the ICMP6 values from RFC 2292 modified to be prefixed with ICMP4.
'//

' enum ICMP4_TYPE
%ICMP4_ECHO_REPLY        =  0  ' // Echo Reply.
%ICMP4_DST_UNREACH       =  3  ' // Destination Unreachable.
%ICMP4_SOURCE_QUENCH     =  4  ' // Source Quench.
%ICMP4_REDIRECT          =  5  ' // Redirect.
%ICMP4_ECHO_REQUEST      =  8  ' // Echo Request.
%ICMP4_ROUTER_ADVERT     =  9  ' // Router Advertisement.
%ICMP4_ROUTER_SOLICIT    = 10  ' // Router Solicitation.
%ICMP4_TIME_EXCEEDED     = 11  ' // Time Exceeded.
%ICMP4_PARAM_PROB        = 12  ' // Parameter Problem.
%ICMP4_TIMESTAMP_REQUEST = 13  ' // Timestamp Request.
%ICMP4_TIMESTAMP_REPLY   = 14  ' // Timestamp Reply.
%ICMP4_MASK_REQUEST      = 17  ' // Address Mask Request.
%ICMP4_MASK_REPLY        = 18  ' // Address Mask Reply.

'//
'// See RFC 1812, section 4.3.1.
'//
'#define ICMP4_ISTYPEERROR(Type) \
'    (((Type) == ICMP4_DST_UNREACH) || \
'     ((Type) == ICMP4_SOURCE_QUENCH) || \
'     ((Type) == ICMP4_REDIRECT) || \
'     ((Type) == ICMP4_PARAM_PROB) || \
'     ((Type) == ICMP4_TIME_EXCEEDED)) \

MACRO ICMP4_ISTYPEERROR(nType) = (((nType) = %ICMP4_DST_UNREACH) OR ((nType) = %ICMP4_SOURCE_QUENCH) OR ((nType) = %ICMP4_REDIRECT) OR ((nType) = %ICMP4_PARAM_PROB) OR (nType) = %ICMP4_TIME_EXCEEDED))

' // Size = 16 bytes
TYPE MIB_IPMCAST_OIF_XP DWORD
   dwOutIfIndex  AS DWORD   ' DWORD
   dwNextHopAddr AS DWORD   ' DWORD
   dwReserved    AS DWORD   ' DWORD
   dwReserved1   AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE MIB_IPMCAST_OIF_W2K DWORD
   dwOutIfIndex  AS DWORD   ' DWORD
   dwNextHopAddr AS DWORD   ' DWORD
   pvReserved    AS DWORD   ' PVOID
   dwReserved    AS DWORD   ' DWORD
END TYPE

#IF %WINVER >= &H0501       ' Windows XP
    MACRO MIB_IPMCAST_OIF = MIB_IPMCAST_OIF_XP
#ELSEIF %WINVER >= &H0500   ' Windows 2000
    MACRO MIB_IPMCAST_OIF = MIB_IPMCAST_OIF_W2K
#ELSE
    MACRO MIB_IPMCAST_OIF = MIB_IPMCAST_OIF_XP
#ENDIF

' // Size = 76 bytes
TYPE MIB_IPMCAST_MFE DWORD
   dwGroup         AS DWORD   ' DWORD
   dwSource        AS DWORD   ' DWORD
   dwSrcMask       AS DWORD   ' DWORD
   dwUpStrmNgbr    AS DWORD   ' DWORD
   dwInIfIndex     AS DWORD   ' DWORD
   dwInIfProtocol  AS DWORD   ' DWORD
   dwRouteProtocol AS DWORD   ' DWORD
   dwRouteNetwork  AS DWORD   ' DWORD
   dwRouteMask     AS DWORD   ' DWORD
   ulUpTime        AS DWORD   ' ULONG
   ulExpiryTime    AS DWORD   ' ULONG
   ulTimeOut       AS DWORD   ' ULONG
   ulNumOutIf      AS DWORD   ' ULONG
   fFlags          AS DWORD   ' DWORD
   dwReserved      AS DWORD   ' DWORD
   rgmioOutInfo(0) AS MIB_IPMCAST_OIF   ' MIB_IPMCAST_OIF rgmioOutInfo[ANY_SIZE]
END TYPE

' // Size = 80 bytes
TYPE MIB_MFE_TABLE DWORD
   dwNumEntries AS DWORD              ' DWORD
   table(0)     AS MIB_IPMCAST_MFE    ' MIB_IPMCAST_MFE table[ANY_SIZE]
END TYPE

'#define SIZEOF_BASIC_MIB_MFE          \
'    (ULONG)(FIELD_OFFSET(MIB_IPMCAST_MFE, rgmioOutInfo[0]))

'#define SIZEOF_MIB_MFE(X)             \
'    (SIZEOF_BASIC_MIB_MFE + ((X) * sizeof(MIB_IPMCAST_OIF)))

' // Size = 28 bytes
TYPE MIB_IPMCAST_OIF_STATS_LH DWORD
   dwOutIfIndex  AS DWORD   ' DWORD
   dwNextHopAddr AS DWORD   ' DWORD
   dwDialContext AS DWORD   ' DWORD
   ulTtlTooLow   AS DWORD   ' ULONG
   ulFragNeeded  AS DWORD   ' ULONG
   ulOutPackets  AS DWORD   ' ULONG
   ulOutDiscards AS DWORD   ' ULONG
END TYPE

' // Size = 28 bytes
TYPE MIB_IPMCAST_OIF_STATS_W2K DWORD
   dwOutIfIndex  AS DWORD   ' DWORD
   dwNextHopAddr AS DWORD   ' DWORD
   pvDialContext AS DWORD   ' PVOID
   ulTtlTooLow   AS DWORD   ' ULONG
   ulFragNeeded  AS DWORD   ' ULONG
   ulOutPackets  AS DWORD   ' ULONG
   ulOutDiscards AS DWORD   ' ULONG
END TYPE

#IF %WINVER >= &H0600       ' Windows Vista
    MACRO MIB_IPMCAST_OIF_STATS = MIB_IPMCAST_OIF_STATS_LH
#ELSEIF %WINVER >= &H0500   ' Windows 2000
    MACRO MIB_IPMCAST_OIF_STATS = MIB_IPMCAST_OIF_STATS_W2K
#ELSE
    MACRO MIB_IPMCAST_OIF_STATS = MIB_IPMCAST_OIF_STATS_LH
#ENDIF

' // Size = 92 bytes
TYPE MIB_IPMCAST_MFE_STATS DWORD
   dwGroup           AS DWORD   ' DWORD
   dwSource          AS DWORD   ' DWORD
   dwSrcMask         AS DWORD   ' DWORD
   dwUpStrmNgbr      AS DWORD   ' DWORD
   dwInIfIndex       AS DWORD   ' DWORD
   dwInIfProtocol    AS DWORD   ' DWORD
   dwRouteProtocol   AS DWORD   ' DWORD
   dwRouteNetwork    AS DWORD   ' DWORD
   dwRouteMask       AS DWORD   ' DWORD
   ulUpTime          AS DWORD   ' ULONG
   ulExpiryTime      AS DWORD   ' ULONG
   ulNumOutIf        AS DWORD   ' ULONG
   ulInPkts          AS DWORD   ' ULONG
   ulInOctets        AS DWORD   ' ULONG
   ulPktsDifferentIf AS DWORD   ' ULONG
   ulQueueOverflow   AS DWORD   ' ULONG
   rgmiosOutStats(0) AS MIB_IPMCAST_OIF_STATS   ' MIB_IPMCAST_OIF_STATS   rgmiosOutStats[ANY_SIZE]
END TYPE

' // Size = 96 bytes
TYPE MIB_MFE_STATS_TABLE DWORD
   dwNumEntries AS DWORD                   ' DWORD
   table(0)     AS MIB_IPMCAST_MFE_STATS   ' MIB_IPMCAST_MFE_STATS   table[ANY_SIZE]
END TYPE

'#define SIZEOF_BASIC_MIB_MFE_STATS    \
'    (ULONG)(FIELD_OFFSET(MIB_IPMCAST_MFE_STATS, rgmiosOutStats[0]))

'#define SIZEOF_MIB_MFE_STATS(X)       \
'    (SIZEOF_BASIC_MIB_MFE_STATS + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))

' // Size = 112 bytes
TYPE MIB_IPMCAST_MFE_STATS_EX_XP DWORD
   dwGroup           AS DWORD   ' DWORD
   dwSource          AS DWORD   ' DWORD
   dwSrcMask         AS DWORD   ' DWORD
   dwUpStrmNgbr      AS DWORD   ' DWORD
   dwInIfIndex       AS DWORD   ' DWORD
   dwInIfProtocol    AS DWORD   ' DWORD
   dwRouteProtocol   AS DWORD   ' DWORD
   dwRouteNetwork    AS DWORD   ' DWORD
   dwRouteMask       AS DWORD   ' DWORD
   ulUpTime          AS DWORD   ' ULONG
   ulExpiryTime      AS DWORD   ' ULONG
   ulNumOutIf        AS DWORD   ' ULONG
   ulInPkts          AS DWORD   ' ULONG
   ulInOctets        AS DWORD   ' ULONG
   ulPktsDifferentIf AS DWORD   ' ULONG
   ulQueueOverflow   AS DWORD   ' ULONG
   ulUninitMfe       AS DWORD   ' ULONG
   ulNegativeMfe     AS DWORD   ' ULONG
   ulInDiscards      AS DWORD   ' ULONG
   ulInHdrErrors     AS DWORD   ' ULONG
   ulTotalOutPackets AS DWORD   ' ULONG
   rgmiosOutStats(0) AS MIB_IPMCAST_OIF_STATS   ' MIB_IPMCAST_OIF_STATS   rgmiosOutStats[ANY_SIZE]
END TYPE

#IF %WINVER >= &H0501   ' Windows XP
    MACRO MIB_IPMCAST_MFE_STATS_EX = MIB_IPMCAST_MFE_STATS_EX_XP
#ENDIF

' // Size = 8 bytes
TYPE MIB_MFE_STATS_TABLE_EX_XP DWORD
   dwNumEntries AS DWORD                             ' DWORD
   table(0)     AS MIB_IPMCAST_MFE_STATS_EX_XP PTR   ' PMIB_IPMCAST_MFE_STATS_EX_XP   table[ANY_SIZE]
END TYPE

#IF %WINVER >= &H0501   ' Windows XP
    MACRO MIB_MFE_STATS_TABLE_EX = MIB_MFE_STATS_TABLE_EX_XP
'#define SIZEOF_BASIC_MIB_MFE_STATS_EX    \
'    (ULONG)(FIELD_OFFSET(MIB_IPMCAST_MFE_STATS_EX, rgmiosOutStats[0]))
'#define SIZEOF_MIB_MFE_STATS_EX(X)       \
'    (SIZEOF_BASIC_MIB_MFE_STATS_EX + ((X) * sizeof(MIB_IPMCAST_OIF_STATS)))
#ENDIF

' // Size = 4 bytes
TYPE MIB_IPMCAST_GLOBAL DWORD
   dwEnable AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE MIB_IPMCAST_IF_ENTRY DWORD
   dwIfIndex        AS DWORD   ' DWORD
   dwTtl            AS DWORD   ' DWORD
   dwProtocol       AS DWORD   ' DWORD
   dwRateLimit      AS DWORD   ' DWORD
   ulInMcastOctets  AS DWORD   ' DWORD
   ulOutMcastOctets AS DWORD   ' DWORD
END TYPE

' // Size = 28 bytes
TYPE MIB_IPMCAST_IF_TABLE DWORD
   dwNumEntries AS DWORD                  ' DWORD
   table(0)     AS MIB_IPMCAST_IF_ENTRY   ' MIB_IPMCAST_IF_ENTRY   table[ANY_SIZE]
END TYPE

'#define SIZEOF_MCAST_IF_TABLE(X) \
'    (FIELD_OFFSET(MIB_IPMCAST_IF_TABLE, table[0]) +  \
'     ((X) * sizeof(MIB_IPMCAST_IF_ENTRY)) +  \
'     ALIGN_SIZE)
