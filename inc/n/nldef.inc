' ########################################################################################
' Microsoft Windows
' File: nldef.inc
' Contents: Basic network layer definitions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NLDEF_INC = 1

'#define NL_MAX_METRIC_COMPONENT ((((ULONG) 1) << 31) - 1)
%NL_MAX_METRIC_COMPONENT = &H7FFFFFFF???

' enum NL_PREFIX_ORIGIN
' //
' // These values are from iptypes.h.
' // They need to fit in a 4 bit field.
' //
%IpPrefixOriginOther               = 0
%IpPrefixOriginManual              = 1
%IpPrefixOriginWellKnown           = 2
%IpPrefixOriginDhcp                = 3
%IpPrefixOriginRouterAdvertisement = 4
%IpPrefixOriginUnchanged           = &H10   ' 1 << 4

'//
'// TODO: Remove these definitions.
'//
%NlpoOther               = %IpPrefixOriginOther
%NlpoManual              = %IpPrefixOriginManual
%NlpoWellKnown           = %IpPrefixOriginWellKnown
%NlpoDhcp                = %IpPrefixOriginDhcp
%NlpoRouterAdvertisement = %IpPrefixOriginRouterAdvertisement

' enum NL_SUFFIX_ORIGIN
'//
'// TODO: Remove the Nlso* definitions.
'//
%NlsoOther            = 0
%NlsoManual           = 1
%NlsoWellKnown        = 2
%NlsoDhcp             = 3
%NlsoLinkLayerAddress = 4
%NlsoRandom           = 5

'//
'// These values are from in iptypes.h.
'// They need to fit in a 4 bit field.
'//
%IpSuffixOriginOther            = 0
%IpSuffixOriginManual           = 1
%IpSuffixOriginWellKnown        = 2
%IpSuffixOriginDhcp             = 3
%IpSuffixOriginLinkLayerAddress = 4
%IpSuffixOriginRandom           = 5
%IpSuffixOriginUnchanged        = &H10   ' 1 << 4

' enum NL_DAD_STATE
'//
'// TODO: Remove the Nlds* definitions.
'//
%NldsInvalid    = 0
%NldsTentative  = 1
%NldsDuplicate  = 2
%NldsDeprecated = 3
%NldsPreferred  = 4

'//
'// These values are from in iptypes.h.
'//
%IpDadStateInvalid    = 0
%IpDadStateTentative  = 1
%IpDadStateDuplicate  = 2
%IpDadStateDeprecated = 3
%IpDadStatePreferred  = 4

'//
'// MIB_IPPROTO_* values were previously in iprtrmib.h.
'// PROTO_IP_* values were previously in routprot.h.
'//
'#define MAKE_ROUTE_PROTOCOL(suffix, value) \
'    MIB_IPPROTO_ ## suffix = value, \
'    PROTO_IP_ ## suffix    = value

'//
'// Routing protocol values from RFC.
'//
' enum NL_ROUTE_PROTOCOL
'//
'// TODO: Remove the RouteProtocol* definitions.
'//
%RouteProtocolOther   = 1
%RouteProtocolLocal   = 2
%RouteProtocolNetMgmt = 3
%RouteProtocolIcmp    = 4
%RouteProtocolEgp     = 5
%RouteProtocolGgp     = 6
%RouteProtocolHello   = 7
%RouteProtocolRip     = 8
%RouteProtocolIsIs    = 9
%RouteProtocolEsIs    = 10
%RouteProtocolCisco   = 11
%RouteProtocolBbn     = 12
%RouteProtocolOspf    = 13
%RouteProtocolBgp     = 14

%MIB_IPPROTO_OTHER    = 1
%MIB_IPPROTO_LOCAL    = 2
%MIB_IPPROTO_NETMGMT  = 3
%MIB_IPPROTO_ICMP     = 4
%MIB_IPPROTO_EGP      = 5
%MIB_IPPROTO_GGP      = 6
%MIB_IPPROTO_HELLO    = 7
%MIB_IPPROTO_RIP      = 8
%MIB_IPPROTO_IS_IS    = 9
%MIB_IPPROTO_ES_IS    = 10
%MIB_IPPROTO_CISCO    = 11
%MIB_IPPROTO_BBN      = 12
%MIB_IPPROTO_OSPF     = 13
%MIB_IPPROTO_PROTOCOL = 14

'//
'// Windows-specific definitions.
'//

%MIB_IPPROTO_NT_AUTOSTATIC     = 10002
%MIB_IPPROTO_NT_STATIC         = 10006
%MIB_IPPROTO_NT_STATIC_NON_DOD = 10007

' enum NL_ADDRESS_TYPE
%NlatUnspecified = 0
%NlatUnicast     = 1
%NlatAnycast     = 2
%NlatMulticast   = 3
%NlatBroadcast   = 4
%NlatInvalid     = 5

'//
'// NL_ROUTE_ORIGIN
'//
'// Define route origin values.
'//

' enum NL_ROUTE_ORIGIN
%NlroManual              = 0
%NlroWellKnown           = 1
%NlroDHCP                = 2
%NlroRouterAdvertisement = 3
%Nlro6to4                = 4

'//
'// NL_NEIGHBOR_STATE
'//
'// Define network layer neighbor state.  RFC 2461, section 7.3.2 has details.
'// Note: Only state names are documented, we chose the values used here.
'//

' enum NL_NEIGHBOR_STATE {
%NlnsUnreachable = 0
%NlnsIncomplete  = 1
%NlnsProbe       = 2
%NlnsDelay       = 3
%NlnsStale       = 4
%NlnsReachable   = 5
%NlnsPermanent   = 6
%NlnsMaximum     = 7

' enum NL_LINK_LOCAL_ADDRESS_BEHAVIOR{
%LinkLocalAlwaysOff = 0    ' // Never use link locals.
%LinkLocalDelayed   = 1    ' // Use link locals only if no other addresses.
                           ' // (default for IPv4).
                           ' // Legacy mapping: IPAutoconfigurationEnabled.
%LinkLocalAlwaysOn  = 2    ' // Always use link locals (default for IPv6).
%LinkLocalUnchanged = -1

'typedef struct _NL_INTERFACE_OFFLOAD_ROD {
'    BOOLEAN NlChecksumSupported : 1;
'    BOOLEAN NlOptionsSupported : 1;
'    BOOLEAN TlDatagramChecksumSupported : 1;
'    BOOLEAN TlStreamChecksumSupported : 1;
'    BOOLEAN TlStreamOptionsSupported : 1;
'    BOOLEAN FastPathCompatible : 1;
'    BOOLEAN TlLargeSendOffloadSupported : 1;
'    BOOLEAN TlGiantSendOffloadSupported : 1;
'} NL_INTERFACE_OFFLOAD_ROD, *PNL_INTERFACE_OFFLOAD_ROD;

' // Size = 1 byte
TYPE NL_INTERFACE_OFFLOAD_ROD BYTE
   NlChecksumSupported         AS BIT * 1 IN BYTE
   NlOptionsSupported          AS BIT * 1
   TlDatagramChecksumSupported AS BIT * 1
   TlStreamChecksumSupported   AS BIT * 1
   TlStreamOptionsSupported    AS BIT * 1
   FastPathCompatible          AS BIT * 1
   TlLargeSendOffloadSupported AS BIT * 1
   TlGiantSendOffloadSupported AS BIT * 1
END TYPE

' enum NL_ROUTER_DISCOVERY_BEHAVIOR {
%RouterDiscoveryDisabled  = 0
%RouterDiscoveryEnabled   = 1
%RouterDiscoveryDhcp      = 2
%RouterDiscoveryUnchanged = -1

' enum NL_BANDWIDTH_FLAG {
%NlbwDisabled  = 0
%NlbwEnabled   = 1
%NlbwUnchanged = -1

' // Size = 24 bytes
TYPE NL_PATH_BANDWIDTH_ROD QWORD   ' Must be 8 byte aligned
   Bandwidth       AS QUAD   ' ULONG64
   Instability     AS QUAD   ' ULONG64
   BandwidthPeaked AS BYTE   ' BOOLEAN
END TYPE

' enum _NL_NETWORK_CATEGORY
%NetworkCategoryPublic              = 0
%NetworkCategoryPrivate             = 1
%NetworkCategoryDomainAuthenticated = 2
%NetworkCategoryUnchanged           = -1   '  // used in a set operation
%NetworkCategoryUnknown             = -1   '  // returned in a query operation

%NET_IF_CURRENT_SESSION = &HFFFFFFFF???   ' ((ULONG)-1)
