' ########################################################################################
' Microsoft Windows
' File: Ipinfoid.inc
' Contents: Defines the IDs needed for specifying various types of information to the
' router manager. Protocols use their ProtocolId for tagging information
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPINFOID_INC = 1

%IP_ROUTER_MANAGER_VERSION = 1

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// These are the ids used for different information types supported by      //
'// IP Router Manager. These ids live in the same space as the IP Routing    //
'// Protocol IDs, so any addition to them must be done with care             //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

%IP_GENERAL_INFO_BASE            = &Hffff0000???

%IP_IN_FILTER_INFO               = %IP_GENERAL_INFO_BASE + 1
%IP_OUT_FILTER_INFO              = %IP_GENERAL_INFO_BASE + 2
%IP_GLOBAL_INFO                  = %IP_GENERAL_INFO_BASE + 3
%IP_INTERFACE_STATUS_INFO        = %IP_GENERAL_INFO_BASE + 4
%IP_ROUTE_INFO                   = %IP_GENERAL_INFO_BASE + 5
%IP_PROT_PRIORITY_INFO           = %IP_GENERAL_INFO_BASE + 6
%IP_ROUTER_DISC_INFO             = %IP_GENERAL_INFO_BASE + 7
'// N.B. Unused ID available at IP_GENERAL_INFO_BASE + 8.
%IP_DEMAND_DIAL_FILTER_INFO      = %IP_GENERAL_INFO_BASE + 9
%IP_MCAST_HEARBEAT_INFO          = %IP_GENERAL_INFO_BASE + 10
%IP_MCAST_BOUNDARY_INFO          = %IP_GENERAL_INFO_BASE + 11
%IP_IPINIP_CFG_INFO              = %IP_GENERAL_INFO_BASE + 12
%IP_IFFILTER_INFO                = %IP_GENERAL_INFO_BASE + 13
%IP_MCAST_LIMIT_INFO             = %IP_GENERAL_INFO_BASE + 14
%IPV6_GLOBAL_INFO                = %IP_GENERAL_INFO_BASE + 15
%IPV6_ROUTE_INFO                 = %IP_GENERAL_INFO_BASE + 16

%IP_IN_FILTER_INFO_V6            = %IP_GENERAL_INFO_BASE + 17
%IP_OUT_FILTER_INFO_V6           = %IP_GENERAL_INFO_BASE + 18
%IP_DEMAND_DIAL_FILTER_INFO_V6   = %IP_GENERAL_INFO_BASE + 19
%IP_IFFILTER_INFO_V6             = %IP_GENERAL_INFO_BASE + 20


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The following IDS are defined in routprot.h and given here for           //
'// informational purposes only                                              //
'//                                                                          //
'// #define IP_OTHER         1                                               //
'// #define IP_LOCAL         2                                               //
'// #define IP_NETMGMT       3                                               //
'// #define IP_ICMP          4                                               //
'// #define IP_EGP           5                                               //
'// #define IP_GGP           6                                               //
'// #define IP_HELLO         7                                               //
'// #define IP_RIP           8                                               //
'// #define IP_IS_IS         9                                               //
'// #define IP_ES_IS         10                                              //
'// #define IP_CISCO         11                                              //
'// #define IP_BBN           12                                              //
'// #define IP_OSPF          13                                              //
'// #define IP_BGP           14                                              //
'//                                                                          //
'// #define IP_BOOTP         9999                                            //
'// #define IPRTRMGR_PID     10000                                           //
'// #define IP_NT_AUTOSTATIC 10002                                           //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////
