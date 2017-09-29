' ########################################################################################
' Microsoft Windows
' File: IPHlpApi.inc
' Contents: Header file for functions to interact with the IP Stack for MIB-II and
' related functionality
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPHLPAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// IPRTRMIB.H has the definitions of the strcutures used to set and get     //
'// information                                                              //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

#INCLUDE ONCE "iprtrmib.inc"
#INCLUDE ONCE "ipexport.inc"
#INCLUDE ONCE "iptypes.inc"
#INCLUDE ONCE "tcpestats.inc"

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The GetXXXTable APIs take a buffer and a size of buffer.  If the buffer  //
'// is not large enough, the APIs return ERROR_INSUFFICIENT_BUFFER  and      //
'// *pdwSize is the required buffer size                                     //
'// The bOrder is a BOOLEAN, which if TRUE sorts the table according to      //
'// MIB-II (RFC XXXX)                                                        //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Retrieves the number of interfaces in the system. These include LAN and  //
'// WAN interfaces                                                           //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetNumberOfInterfaces IMPORT "iphlpapi.dll" ALIAS "GetNumberOfInterfaces" ( _
   BYREF pdwNumIf AS DWORD _                            ' __out PDWORD pdwNumIf
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the MIB-II ifEntry                                                  //
'// The dwIndex field of the MIB_IFROW should be set to the index of the     //
'// interface being queried                                                  //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetIfEntry IMPORT "iphlpapi.dll" ALIAS "GetIfEntry" ( _
   BYREF pIfRow AS MIB_IFROW _                          ' __inout PMIB_IFROW pIfRow
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the MIB-II IfTable                                                  //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetIfTable IMPORT "iphlpapi.dll" ALIAS "GetIfTable" ( _
   BYREF pIfTable AS MIB_IFTABLE _                      ' __out   PMIB_IFTABLE pIfTable
 , BYREF pdwSize AS DWORD _                             ' __inout PULONG       pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL         bOrder
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the Interface to IP Address mapping                                 //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetIpAddrTable IMPORT "iphlpapi.dll" ALIAS "GetIpAddrTable" ( _
   BYREF pIpAddrTable AS MIB_IPADDRTABLE _              ' __out   PMIB_IPADDRTABLE pIpAddrTable
 , BYREF pdwSize AS DWORD _                             ' __inout PULONG           pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL             bOrder
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the current IP Address to Physical Address (ARP) mapping            //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetIpNetTable IMPORT "iphlpapi.dll" ALIAS "GetIpNetTable" ( _
   BYREF pIpNetTable AS MIB_IPNETTABLE _                ' __out   PMIB_IPNETTABLE pIpNetTable
 , BYREF pdwSize AS DWORD _                             ' __inout PULONG          pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL            bOrder
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the IP Routing Table  (RFX XXXX)                                    //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetIpForwardTable IMPORT "iphlpapi.dll" ALIAS "GetIpForwardTable" ( _
   BYREF pIpForwardTable AS MIB_IPFORWARDTABLE _        ' __out   PMIB_IPFORWARDTABLE pIpForwardTable
 , BYREF pdwSize AS DWORD _                             ' __inout PULONG              pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL                bOrder
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets TCP Connection/UDP Listener Table                                   //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetTcpTable IMPORT "iphlpapi.dll" ALIAS "GetTcpTable" ( _
   BYREF pTcpTable AS MIB_TCPTABLE _                    ' __out   PMIB_TCPTABLE pTcpTable
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD        pdwSize
 , BYVAL bOrder AS  LONG _                              ' __in    BOOL          bOrder
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetExtendedTcpTable IMPORT "iphlpapi.dll" ALIAS "GetExtendedTcpTable" ( _
   BYREF pTcpTable AS ANY _                             ' __out   PVOID           pTcpTable
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD          pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL            bOrder
 , BYVAL ulAf AS DWORD _                                ' __in    ULONG           ulAf
 , BYVAL TableClass AS LONG _                           ' __in    TCP_TABLE_CLASS TableClass
 , BYVAL Reserved AS LONG _                             ' __in    ULONG           Reserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetOwnerModuleFromTcpEntry IMPORT "iphlpapi.dll" ALIAS "GetOwnerModuleFromTcpEntry" ( _
   BYREF pTcpEntry AS MIB_TCPROW_OWNER_MODULE _         ' __in    PMIB_TCPROW_OWNER_MODULE      pTcpEntry
 , BYVAL Class AS LONG _                                ' __in    TCPIP_OWNER_MODULE_INFO_CLASS Class
 , BYREF pBuffer AS ANY _                               ' __out   PVOID                         pBuffer
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD                        pdwSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetUdpTable IMPORT "iphlpapi.dll" ALIAS "GetUdpTable" ( _
   BYREF pUdpTable AS MIB_UDPTABLE _                    ' __out   PMIB_UDPTABLE pUdpTable
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD        pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL          bOrder
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetExtendedUdpTable IMPORT "iphlpapi.dll" ALIAS "GetExtendedUdpTable" ( _
   BYREF pUdpTable AS ANY _                             ' __out   PVOID           pUdpTable
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD          pdwSize
 , BYVAL bOrder AS LONG _                               ' __in    BOOL            bOrder
 , BYVAL ulAf AS DWORD _                                ' __in    ULONG           ulAf
 , BYVAL TableClass AS LONG _                           ' __in    UDP_TABLE_CLASS TableClass
 , BYVAL Reserved AS DWORD _                            ' __in    ULONG           Reserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetOwnerModuleFromUdpEntry IMPORT "iphlpapi.dll" ALIAS "GetOwnerModuleFromUdpEntry" ( _
   BYREF pUdpEntry AS MIB_UDPROW_OWNER_MODULE _         ' __in    PMIB_UDPROW_OWNER_MODULE      pUdpEntry
 , BYVAL Class AS LONG _                                ' __in    TCPIP_OWNER_MODULE_INFO_CLASS Class
 , BYREF pBuffer AS ANY _                               ' __out   PVOID                         pBuffer
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD                        pdwSize
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION GetTcpTable2 IMPORT "iphlpapi.dll" ALIAS "GetTcpTable2" ( _
   BYREF pTcpTable AS MIB_TCPTABLE2 _                   ' __out   PMIB_TCPTABLE2 pTcpTable
 , BYREF SizePointer AS DWORD _                         ' __inout PULONG         SizePointer
 , BYVAL bOrder AS LONG _                               ' __in    BOOL           bOrder
 ) AS DWORD                                             ' ULONG
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION < NTDDI_VISTA)
'//
'// Deprecated APIs, Added for documentation.
'//

'DECLARE FUNCTION AllocateAndGetTcpExTableFromStack IMPORT "iphlpapi.dll" ALIAS "AllocateAndGetTcpExTableFromStack" ( _
'   BYREF ppTcpTable AS ANY _                            ' __out PVOID         *ppTcpTable
' , BYVAL bOrder AS LONG _                               ' __in  BOOL          bOrder
' , BYVAL hHeap AS DWORD _                               ' __in  HANDLE        hHeap
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD         dwFlags
' , BYVAL dwFamily AS DWORD _                            ' __in  DWORD         dwFamily
' ) AS DWORD                                             ' DWORD

'DECLARE FUNCTION AllocateAndGetUdpExTableFromStack IMPORT "iphlpapi.dll" ALIAS "AllocateAndGetUdpExTableFromStack" ( _
'   BYREF ppUdpTable AS ANY _                            ' __out PVOID         *ppUdpTable
' , BYVAL bOrder AS LONG _                               ' __in  BOOL          bOrder
' , BYVAL hHeap AS DWORD _                               ' __in  HANDLE        hHeap
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD         dwFlags
' , BYVAL dwFamily AS DWORD _                            ' __in  DWORD         dwFamily
' ) AS DWORD                                             ' DWORD

'#endif // (NTDDI_VERSION < NTDDI_VISTA)

#IF %DEF(%WS2IPDEF_INC)
'//
'// The following definitions require Winsock2.
'//

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION GetTcp6Table IMPORT "iphlpapi.dll" ALIAS "GetTcp6Table" ( _
   BYREF TcpTable AS MIB_TCP6TABLE _                    ' __out   PMIB_TCP6TABLE TcpTable
 , BYREF SizePointer AS DWORD _                         ' __inout PULONG         SizePointer
 , BYVAL bOrder AS LONG _                               ' __in    BOOL           bOrder
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetTcp6Table2 IMPORT "iphlpapi.dll" ALIAS "GetTcp6Table2" ( _
   BYREF TcpTable AS MIB_TCP6TABLE2 _                   ' __out   PMIB_TCP6TABLE2 TcpTable
 , BYREF SizePointer AS DWORD _                         ' __inout PULONG          SizePointer
 , BYVAL bOrder AS LONG _                               ' __in    BOOL            bOrder
 ) AS DWORD                                             ' ULONG

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#ifdef WINAPI

DECLARE FUNCTION GetPerTcpConnectionEStats IMPORT "iphlpapi.dll" ALIAS "GetPerTcpConnectionEStats" ( _
   BYREF Row AS MIB_TCPROW _                            ' __in  PMIB_TCPROW Row
 , BYVAL EstatsType AS LONG _                           ' __in  TCP_ESTATS_TYPE EstatsType
 , BYVAL Rw AS DWORD _                                  ' __out_bcount_opt(RwSize) PUCHAR Rw
 , BYVAL RwVersion AS DWORD _                           ' __in  ULONG RwVersion
 , BYVAL RwSize AS DWORD _                              ' __in  ULONG RwSize
 , BYVAL Ros AS DWORD _                                 ' __out_bcount_opt(RosSize) PUCHAR Ros
 , BYVAL RosVersion AS DWORD _                          ' __in  ULONG RosVersion
 , BYVAL RosSize AS DWORD _                             ' __in  ULONG RosSize
 , BYVAL Rod AS DWORD _                                 ' __out_bcount_opt(RodSize) PUCHAR Rod
 , BYVAL RodVersion AS DWORD _                          ' __in  ULONG RodVersion
 , BYVAL RodSize AS DWORD _                             ' __in  ULONG RodSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION SetPerTcpConnectionEStats IMPORT "iphlpapi.dll" ALIAS "SetPerTcpConnectionEStats" ( _
   BYREF Row AS MIB_TCPROW _                            ' __in  PMIB_TCPROW Row
 , BYVAL EstatsType AS LONG _                           ' __in  TCP_ESTATS_TYPE EstatsType
 , BYVAL Rw AS DWORD _                                  ' __out_bcount(RwSize) PUCHAR Rw
 , BYVAL RwVersion AS DWORD _                           ' __in  ULONG RwVersion
 , BYVAL RwSize AS DWORD _                              ' __in  ULONG RwSize
 , BYVAL Offset AS DWORD _                              ' __in  ULONG Offset
 ) AS DWORD                                             ' ULONG

'#ifdef _WS2IPDEF_

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPerTcp6ConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "GetPerTcp6ConnectionEStats" (Row AS MIB_TCP6ROW, _
    BYVAL EstatsType AS LONG, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, Ros AS BYTE, _
    BYVAL RosVersion AS DWORD, BYVAL RosSize AS DWORD, Rod AS BYTE, _
    BYVAL RodVersion AS DWORD, BYVAL RodSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetPerTcp6ConnectionEStats IMPORT "iphlpapi.dll" ALIAS "GetPerTcp6ConnectionEStats" ( _
   BYREF Row AS MIB_TCP6ROW _                           ' __in  PMIB_TCP6ROW Row
 , BYVAL EstatsType AS LONG _                           ' __in  TCP_ESTATS_TYPE EstatsType
 , BYREF Rw AS ANY _                                    ' __out_bcount(RwSize) PUCHAR Rw
 , BYVAL RwVersion AS DWORD _                           ' __in  ULONG RwVersion
 , BYVAL RwSize AS DWORD _                              ' __in  ULONG RwSize
 , BYREF Ros AS ANY _                                   ' __out_bcount_opt(RosSize) PUCHAR Ros
 , BYVAL RosVersion AS DWORD _                          ' __in  ULONG RosVersion
 , BYVAL RosSize AS DWORD _                             ' __in  ULONG RosSize
 , BYREF Rod AS ANY _                                   ' __out_bcount_opt(RodSize) PUCHAR Rod
 , BYVAL RodVersion AS DWORD _                          ' __in  ULONG RodVersion
 , BYVAL RodSize AS DWORD _                             ' __in  ULONG RodSize
 ) AS DWORD                                             ' ULONG
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPerTcp6ConnectionEStats LIB "IpHlpApi.dll" _
    ALIAS "SetPerTcp6ConnectionEStats" (Row AS MIB_TCP6ROW, _
    BYVAL EstatsType AS LONG, Rw AS BYTE, _
    BYVAL RwVersion AS DWORD, BYVAL RwSize AS DWORD, BYVAL Offset AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION SetPerTcp6ConnectionEStats IMPORT "iphlpapi.dll" ALIAS "SetPerTcp6ConnectionEStats" ( _
   BYREF Row AS MIB_TCP6ROW _                           ' __in  PMIB_TCP6ROW Row
 , BYVAL EstatsType AS LONG _                           ' __in  TCP_ESTATS_TYPE EstatsType
 , BYREF Rw AS ANY _                                    ' __out_bcount(RwSize) PUCHAR Rw
 , BYVAL RwVersion AS DWORD _                           ' __in  ULONG RwVersion
 , BYVAL RwSize AS DWORD _                              ' __in  ULONG RwSize
 , BYVAL Offset AS DWORD _                              ' __in  ULONG Offset
 ) AS DWORD                                             ' ULONG
#ENDIF

'#endif // _WS2IPDEF_

'#endif // WINAPI

DECLARE FUNCTION GetOwnerModuleFromTcp6Entry IMPORT "iphlpapi.dll" ALIAS "GetOwnerModuleFromTcp6Entry" ( _
   BYREF pTcpEntry AS MIB_TCP6ROW_OWNER_MODULE _        ' __in    PMIB_TCP6ROW_OWNER_MODULE     pTcpEntry
 , BYVAL Class AS LONG _                                ' __in    TCPIP_OWNER_MODULE_INFO_CLASS Class
 , BYREF pBuffer AS ANY _                               ' __out   PVOID pBuffer
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD pdwSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetUdp6Table IMPORT "iphlpapi.dll" ALIAS "GetUdp6Table" ( _
   BYREF Udp6Table AS MIB_UDP6TABLE _                   ' __out PMIB_UDP6TABLE Udp6Table
 , BYREF SizePointer AS DWORD _                         ' __in  OUT PULONG SizePointer
 , BYVAL Order AS LONG _                                ' __in  BOOL Order
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetOwnerModuleFromUdp6Entry IMPORT "iphlpapi.dll" ALIAS "GetOwnerModuleFromUdp6Entry" ( _
   BYREF pUdpEntry AS MIB_UDP6ROW_OWNER_MODULE _        ' __in    PMIB_UDP6ROW_OWNER_MODULE     pUdpEntry
 , BYVAL Class AS LONG _                                ' __in    TCPIP_OWNER_MODULE_INFO_CLASS Class
 , BYREF pBuffer AS ANY _                               ' __out   PVOID  pBuffer
 , BYREF pdwSize AS DWORD _                             ' __inout PDWORD pdwSize
 ) AS DWORD                                             ' ULONG

#ENDIF   '  // _WS2IPDEF_

' Note: Can't find any documentation about this function
DECLARE FUNCTION GetOwnerModuleFromPidAndInfo IMPORT "iphlpapi.dll" ALIAS "GetOwnerModuleFromPidAndInfo" ( _
   BYVAL ulPid AS DWORD _                               ' __in  ULONG                         ulPid
 , BYREF pInfo AS QUAD _                                ' __in  ULONGLONG                     *pInfo
 , BYVAL Class AS LONG _                                ' __in  TCPIP_OWNER_MODULE_INFO_CLASS Class
 , BYREF pBuffer AS ANY _                               ' __out PVOID                         pBuffer
 , BYREF pdwSize AS DWORD _                             ' __in  OUT PDWORD                    pdwSize
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets IP/ICMP/TCP/UDP Statistics                                          //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

DECLARE FUNCTION GetIpStatistics IMPORT "iphlpapi.dll" ALIAS "GetIpStatistics" ( _
   BYREF Statistics AS MIB_IPSTATS _                    ' __out  PMIB_IPSTATS   Statistics
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetIcmpStatistics IMPORT "iphlpapi.dll" ALIAS "GetIcmpStatistics" ( _
   BYREF Statistics AS MIB_ICMP _                       ' __out PMIB_ICMP   Statistics
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetTcpStatistics IMPORT "iphlpapi.dll" ALIAS "GetTcpStatistics" ( _
   BYREF Statistics AS MIB_TCPSTATS _                   ' __out PMIB_TCPSTATS   Statistics
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetUdpStatistics IMPORT "iphlpapi.dll" ALIAS "GetUdpStatistics" ( _
   BYREF Stats AS MIB_UDPSTATS _                        ' __out PMIB_UDPSTATS   Stats
 ) AS DWORD                                             ' ULONG

'#endif

'#if (NTDDI_VERSION >= NTDDI_XP)

DECLARE FUNCTION GetIpStatisticsEx IMPORT "iphlpapi.dll" ALIAS "GetIpStatisticsEx" ( _
   BYREF Statistics AS MIB_IPSTATS _                    ' __out  PMIB_IPSTATS   Statistics
 , BYVAL Family AS DWORD _                              ' __in   ULONG          Family
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION SetIpStatisticsEx IMPORT "iphlpapi.dll" ALIAS "SetIpStatisticsEx" ( _
   BYREF Statistics AS MIB_IPSTATS _                    ' __in   PMIB_IPSTATS   Statistics
 , BYVAL Family AS DWORD _                              ' __in   ULONG          Family
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetIcmpStatisticsEx IMPORT "iphlpapi.dll" ALIAS "GetIcmpStatisticsEx" ( _
   BYREF Statistics AS MIB_ICMP_EX _                    ' __out PMIB_ICMP_EX Statistics
 , BYVAL Family AS DWORD _                              ' __in  ULONG        Family
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetTcpStatisticsEx IMPORT "iphlpapi.dll" ALIAS "GetTcpStatisticsEx" ( _
   BYREF Statistics AS MIB_TCPSTATS _                   ' __out PMIB_TCPSTATS   Statistics
 , BYVAL Family AS DWORD _                              ' __in  ULONG           Family
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION GetUdpStatisticsEx IMPORT "iphlpapi.dll" ALIAS "GetUdpStatisticsEx" ( _
   BYREF Statistics AS MIB_UDPSTATS _                   ' __out PMIB_UDPSTATS   Statistics
 , BYVAL Family AS DWORD _                              ' __in  ULONG           Family
 ) AS DWORD                                             ' ULONG

'#endif

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to set the ifAdminStatus on an interface.  The only fields of the   //
'// MIB_IFROW that are relevant are the dwIndex (index of the interface      //
'// whose status needs to be set) and the dwAdminStatus which can be either  //
'// MIB_IF_ADMIN_STATUS_UP or MIB_IF_ADMIN_STATUS_DOWN                       //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION SetIfEntry IMPORT "iphlpapi.dll" ALIAS "SetIfEntry" ( _
   BYREF pIfRow AS MIB_IFROW _                          ' __in PMIB_IFROW pIfRow
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to create, modify or delete a route.  In all cases the              //
'// dwForwardIfIndex, dwForwardDest, dwForwardMask, dwForwardNextHop and     //
'// dwForwardPolicy MUST BE SPECIFIED. Currently dwForwardPolicy is unused   //
'// and MUST BE 0.                                                           //
'// For a set, the complete MIB_IPFORWARDROW structure must be specified     //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION CreateIpForwardEntry IMPORT "iphlpapi.dll" ALIAS "CreateIpForwardEntry" ( _
   BYREF pRoute AS MIB_IPFORWARDROW _                   ' __in PMIB_IPFORWARDROW pRoute
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetIpForwardEntry IMPORT "iphlpapi.dll" ALIAS "SetIpForwardEntry" ( _
   BYREF pRoute AS MIB_IPFORWARDROW _                   ' __in PMIB_IPFORWARDROW pRoute
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeleteIpForwardEntry IMPORT "iphlpapi.dll" ALIAS "DeleteIpForwardEntry" ( _
   BYREF pRoute AS MIB_IPFORWARDROW _                   ' __in PMIB_IPFORWARDROW pRoute
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to set the ipForwarding to ON or OFF (currently only ON->OFF is     //
'// allowed) and to set the defaultTTL.  If only one of the fields needs to  //
'// be modified and the other needs to be the same as before the other field //
'// needs to be set to MIB_USE_CURRENT_TTL or MIB_USE_CURRENT_FORWARDING as  //
'// the case may be                                                          //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
DECLARE FUNCTION SetIpStatistics IMPORT "iphlpapi.dll" ALIAS "SetIpStatistics" ( _
   BYREF pIpStats AS MIB_IPSTATS _                      ' __in PMIB_IPSTATS pIpStats
 ) AS DWORD                                             ' DWORD
'#endif

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to set the defaultTTL.                                              //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION SetIpTTL IMPORT "iphlpapi.dll" ALIAS "SetIpTTL" ( _
   BYVAL nTTL AS DWORD _                                ' __in UINT nTTL
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to create, modify or delete an ARP entry.  In all cases the dwIndex //
'// dwAddr field MUST BE SPECIFIED.                                          //
'// For a set, the complete MIB_IPNETROW structure must be specified         //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION CreateIpNetEntry IMPORT "iphlpapi.dll" ALIAS "CreateIpNetEntry" ( _
   BYREF pArpEntry AS MIB_IPNETROW _                    ' __in PMIB_IPNETROW    pArpEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetIpNetEntry IMPORT "iphlpapi.dll" ALIAS "SetIpNetEntry" ( _
   BYREF pArpEntry AS MIB_IPNETROW _                    ' __in PMIB_IPNETROW    pArpEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeleteIpNetEntry IMPORT "iphlpapi.dll" ALIAS "DeleteIpNetEntry" ( _
   BYREF pArpEntry AS MIB_IPNETROW _                    ' __in PMIB_IPNETROW    pArpEntry
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION FlushIpNetTable IMPORT "iphlpapi.dll" ALIAS "FlushIpNetTable" ( _
   BYVAL dwIfIndex AS DWORD _                           ' __in DWORD   dwIfIndex
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to create or delete a Proxy ARP entry. The dwIndex is the index of  //
'// the interface on which to PARP for the dwAddress.  If the interface is   //
'// of a type that doesnt support ARP, e.g. PPP, then the call will fail     //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION CreateProxyArpEntry IMPORT "iphlpapi.dll" ALIAS "CreateProxyArpEntry" ( _
   BYVAL dwAddress AS DWORD _                           ' __in  DWORD   dwAddress
 , BYVAL dwMask AS DWORD _                              ' __in  DWORD   dwMask
 , BYVAL dwIfIndex AS DWORD _                           ' __in  DWORD   dwIfIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeleteProxyArpEntry IMPORT "iphlpapi.dll" ALIAS "DeleteProxyArpEntry" ( _
   BYVAL dwAddress AS DWORD _                           ' __in  DWORD   dwAddress
 , BYVAL dwMask AS DWORD _                              ' __in  DWORD   dwMask
 , BYVAL dwIfIndex AS DWORD _                           ' __in  DWORD   dwIfIndex
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Used to set the state of a TCP Connection. The only state that it can be //
'// set to is MIB_TCP_STATE_DELETE_TCB.  The complete MIB_TCPROW structure   //
'// MUST BE SPECIFIED                                                        //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION SetTcpEntry IMPORT "iphlpapi.dll" ALIAS "SetTcpEntry" ( _
   BYREF pTcpRow AS MIB_TCPROW _                        ' __in PMIB_TCPROW pTcpRow
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetInterfaceInfo IMPORT "iphlpapi.dll" ALIAS "GetInterfaceInfo" ( _
   BYREF pIfTable AS IP_INTERFACE_INFO _                ' __in PIP_INTERFACE_INFO pIfTable
 , BYREF dwOutBufLen AS DWORD _                         ' __out PULONG            dwOutBufLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetUniDirectionalAdapterInfo IMPORT "iphlpapi.dll" ALIAS "GetUniDirectionalAdapterInfo" ( _
   BYREF pIPIfInfo AS IP_UNIDIRECTIONAL_ADAPTER_ADDRESS _ ' __out PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS pIPIfInfo
 , BYREF dwOutBufLen AS DWORD _                         ' __out PULONG dwOutBufLen
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_WIN2KSP1)
#IF NOT %DEF(%NhpAllocateAndGetInterfaceInfoFromStack_DEFINED)
    %NhpAllocateAndGetInterfaceInfoFromStack_DEFINED = 1

DECLARE FUNCTION NhpAllocateAndGetInterfaceInfoFromStack _
   IMPORT "iphlpapi.dll" ALIAS "NhpAllocateAndGetInterfaceInfoFromStack" ( _
   BYREF ppTable AS ANY _                               ' __out IP_INTERFACE_NAME_INFO **ppTable
 , BYREF pdwCount AS DWORD _                            ' __out PDWORD                 pdwCount
 , BYVAL bOrder AS LONG _                               ' __in BOOL                    bOrder
 , BYVAL hHeap AS DWORD _                               ' __in HANDLE                  hHeap
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                   dwFlags
 ) AS DWORD                                             ' DWORD

#ENDIF
'#endif // (NTDDI_VERSION >= NTDDI_WIN2KSP1)

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the "best" outgoing interface for the specified destination address //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetBestInterface IMPORT "iphlpapi.dll" ALIAS "GetBestInterface" ( _
   BYVAL dwDestAddr AS DWORD _                          ' __in  IPAddr  dwDestAddr
 , BYREF pdwBestIfIndex AS DWORD _                      ' __out PDWORD  pdwBestIfIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetBestInterfaceEx IMPORT "iphlpapi.dll" ALIAS "GetBestInterfaceEx" ( _
   BYREF pDestAddr AS ANY _                             ' __in  struct sockaddr *pDestAddr
 , BYREF pdwBestIfIndex AS DWORD _                      ' __out PDWORD           pdwBestIfIndex
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Gets the best (longest matching prefix) route for the given destination  //
'// If the source address is also specified (i.e. is not 0x00000000), and    //
'// there are multiple "best" routes to the given destination, the returned  //
'// route will be one that goes out over the interface which has an address  //
'// that matches the source address                                          //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION GetBestRoute IMPORT "iphlpapi.dll" ALIAS "GetBestRoute" ( _
   BYVAL dwDestAddr AS DWORD _                          ' __in  DWORD               dwDestAddr
 , BYVAL dwSourceAddr AS DWORD _                        ' __in  DWORD               dwSourceAddr OPTIONAL
 , BYREF pBestRoute AS MIB_IPFORWARDROW _               ' __out PMIB_IPFORWARDROW   pBestRoute
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION NotifyAddrChange IMPORT "iphlpapi.dll" ALIAS "NotifyAddrChange" ( _
   BYREF Handle AS DWORD _                              ' __out PHANDLE      Handle
 , BYREF overlapped AS OVERLAPPED _                     ' __in  LPOVERLAPPED overlapped
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION NotifyRouteChange IMPORT "iphlpapi.dll" ALIAS "NotifyRouteChange" ( _
   BYREF Handle AS DWORD _                              ' __out PHANDLE      Handle
 , BYREF overlapped AS OVERLAPPED _                     ' __in  LPOVERLAPPED overlapped
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CancelIPChangeNotify IMPORT "iphlpapi.dll" ALIAS "CancelIPChangeNotify" ( _
   BYREF notifyOverlapped AS OVERLAPPED _               ' __in  LPOVERLAPPED notifyOverlapped
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetAdapterIndex IMPORT "iphlpapi.dll" ALIAS "GetAdapterIndex" ( _
   BYREF AdapterName AS WSTRINGZ _                      ' __in LPWSTR  AdapterName
 , BYREF IfIndex AS DWORD _                             ' __out PULONG IfIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION AddIPAddress IMPORT "iphlpapi.dll" ALIAS "AddIPAddress" ( _
   BYVAL Address AS DWORD _                             ' __in  IPAddr  Address
 , BYVAL IpMask AS DWORD _                              ' __in  IPMask  IpMask
 , BYVAL IfIndex AS DWORD _                             ' __in  DWORD   IfIndex
 , BYREF NTEContext AS DWORD _                          ' __out PULONG  NTEContext
 , BYREF NTEInstance AS DWORD _                         ' __out PULONG  NTEInstance
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeleteIPAddress IMPORT "iphlpapi.dll" ALIAS "DeleteIPAddress" ( _
   BYVAL NTEContext AS DWORD _                          ' __in ULONG NTEContext
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_WIN2KSP1)
DECLARE FUNCTION GetNetworkParams IMPORT "iphlpapi.dll" ALIAS "GetNetworkParams" ( _
   BYREF pFixedInfo AS FIXED_INFO _                     ' __out   PFIXED_INFO pFixedInfo
 , BYREF pOutBufLen AS DWORD _                          ' __inout PULONG pOutBufLen
 ) AS DWORD                                             ' DWORD
'#endif

DECLARE FUNCTION GetAdaptersInfo IMPORT "iphlpapi.dll" ALIAS "GetAdaptersInfo" ( _
   BYREF pAdapterInfo AS IP_ADAPTER_INFO _              ' __out   PIP_ADAPTER_INFO pAdapterInfo
 , BYREF pOutBufLen AS DWORD _                          ' __inout PULONG pOutBufLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetAdapterOrderMap IMPORT "iphlpapi.dll" ALIAS "GetAdapterOrderMap" ( _
 ) AS DWORD                                             ' PIP_ADAPTER_ORDER_MAP

#IF %DEF(%WINSOCK2API)

'//
'// The following functions require Winsock2.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAdaptersAddresses LIB "IpHlpApi.dll" _
    ALIAS "GetAdaptersAddresses" (BYVAL Family AS DWORD, _
    BYVAL Flags AS DWORD, Reserved AS ANY, _
    AdapterAddresses AS IP_ADAPTER_ADDRESSES, SizePointer AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetAdaptersAddresses IMPORT "iphlpapi.dll" ALIAS "GetAdaptersAddresses" ( _
   BYVAL Family AS DWORD _                              ' __in    ULONG                 Family
 , BYVAL Flags AS DWORD _                               ' __in    DWORD                 Flags
 , BYVAL Reserved AS DWORD _                            ' __in    PVOID                 Reserved
 , BYREF pAdapterAddresses AS IP_ADAPTER_ADDRESSES _    ' __out   PIP_ADAPTER_ADDRESSES pAdapterAddresses
 , BYREF pOutBufLen AS DWORD _                          ' __inout PULONG                pOutBufLen
 ) AS DWORD                                             ' DWORD
#ENDIF

#ENDIF   ' WINSOCK2API

'#if (NTDDI_VERSION >= NTDDI_WIN2KSP1)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPerAdapterInfo LIB "IpHlpApi.dll" _
    ALIAS "GetPerAdapterInfo" (BYVAL IfIndex AS DWORD, _
    BYVAL pPerAdapterInfo AS IP_PER_ADAPTER_INFO PTR, pOutBufLen AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetPerAdapterInfo IMPORT "iphlpapi.dll" ALIAS "GetPerAdapterInfo" ( _
   BYVAL IfIndex AS DWORD _                             ' __in    ULONG IfIndex
 , BYREF pPerAdapterInfo AS IP_PER_ADAPTER_INFO _       ' __out   PIP_PER_ADAPTER_INFO pPerAdapterInfo
 , BYREF pOutBufLen AS DWORD _                          ' __inout PULONG pOutBufLen
 ) AS DWORD                                             ' DWORD
 #ENDIF
'#endif

DECLARE FUNCTION IpReleaseAddress IMPORT "iphlpapi.dll" ALIAS "IpReleaseAddress" ( _
   BYREF AdapterInfo AS IP_ADAPTER_INDEX_MAP _          ' __in PIP_ADAPTER_INDEX_MAP AdapterInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION IpRenewAddress IMPORT "iphlpapi.dll" ALIAS "IpRenewAddress" ( _
   BYREF AdapterInfo AS IP_ADAPTER_INDEX_MAP _          ' __in PIP_ADAPTER_INDEX_MAP AdapterInfo
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SendARP LIB "IpHlpApi.dll" ALIAS "SendARP" _
    (BYVAL DestIP AS DWORD, BYVAL SrcIP AS DWORD, pMacAddr AS ANY, _
    PhyAddrLen AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION SendARP IMPORT "iphlpapi.dll" ALIAS "SendARP" ( _
   BYVAL DestIP AS DWORD _                              ' __in  IPAddr DestIP
 , BYVAL SrcIP AS DWORD _                               ' __in  IPAddr SrcIP
 , BYREF pMacAddr AS DWORD _                            ' __out PULONG pMacAddr
 , BYREF PhyAddrLen AS DWORD _                          ' __out PULONG  PhyAddrLen
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION GetRTTAndHopCount IMPORT "iphlpapi.dll" ALIAS "GetRTTAndHopCount" ( _
   BYVAL DestIpAddress AS DWORD _                       ' __in  IPAddr DestIpAddress,
 , BYREF HopCount AS DWORD _                            ' __out PULONG HopCount
 , BYVAL MaxHops AS DWORD _                             ' __in  ULONG  MaxHops
 , BYREF RTT AS DWORD _                                 ' __out PULONG RTT
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFriendlyIfIndex IMPORT "iphlpapi.dll" ALIAS "GetFriendlyIfIndex" ( _
   BYVAL IfIndex AS DWORD _                             ' __in DWORD IfIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION EnableRouter IMPORT "iphlpapi.dll" ALIAS "EnableRouter" ( _
   BYREF pHandle AS DWORD _                             ' __in HANDLE* pHandle
 , BYREF pOverlapped AS OVERLAPPED _                    ' __in OVERLAPPED* pOverlapped
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION UnenableRouter IMPORT "iphlpapi.dll" ALIAS "UnenableRouter" ( _
   BYREF pOverlapped AS OVERLAPPED _                    ' __in  OVERLAPPED* pOverlapped
 , BYREF lpdwEnableCount AS DWORD _                     ' __out LPDWORD lpdwEnableCount OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DisableMediaSense IMPORT "iphlpapi.dll" ALIAS "DisableMediaSense" ( _
   BYREF pHandle AS DWORD _                             ' __out HANDLE *pHandle
 , BYREF pOverlapped AS OVERLAPPED _                    ' __in OVERLAPPED* pOverlapped
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RestoreMediaSense IMPORT "iphlpapi.dll" ALIAS "RestoreMediaSense" ( _
   BYREF pOverlapped AS OVERLAPPED _                    ' __in  OVERLAPPED* pOverlapped
 , BYREF lpdwEnableCount AS DWORD _                     ' __out LPDWORD lpdwEnableCount OPTIONAL
 ) AS DWORD                                             ' DWORD

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION GetIpErrorString IMPORT "iphlpapi.dll" ALIAS "GetIpErrorString" ( _
   BYVAL ErrorCode AS DWORD _                           ' __in    IP_STATUS ErrorCode
 , BYREF Buffer AS WSTRINGZ _                           ' __out   PWCHAR Buffer
 , BYREF Size AS DWORD _                                ' __inout PDWORD Size
 ) AS DWORD                                             ' DWORD

'#ifdef _WS2DEF_
'Note  This function is deprecated and not supported. Developers should use the ResolveIpNetEntry2 function.
'DECLARE FUNCTION ResolveNeighbor IMPORT "iphlpapi.dll" ALIAS "ResolveNeighbor" ( _
'   BYREF NetworkAddress AS SOCKADDR _                   ' __in    SOCKADDR *NetworkAddress
' , BYREF PhysicalAddress AS ANY _                       ' __out   PVOID PhysicalAddress
' , BYREF PhysicalAddressLength AS DWORD _               ' __inout PULONG PhysicalAddressLength
' ) AS DWORD                                             ' ULONG
'#endif
'#endif

'//
'// Port reservation API routines.
'//

DECLARE FUNCTION CreatePersistentTcpPortReservation IMPORT "iphlpapi.dll" ALIAS "CreatePersistentTcpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in  USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in  USHORT NumberOfPorts
 , BYREF Token AS QUAD _                                ' __out PULONG64 Token
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION CreatePersistentUdpPortReservation IMPORT "iphlpapi.dll" ALIAS "CreatePersistentUdpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in  USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in  USHORT NumberOfPorts
 , BYREF Token AS QUAD _                                ' __out PULONG64 Token
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION DeletePersistentTcpPortReservation IMPORT "iphlpapi.dll" ALIAS "DeletePersistentTcpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in USHORT NumberOfPorts
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION DeletePersistentUdpPortReservation IMPORT "iphlpapi.dll" ALIAS "DeletePersistentUdpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in USHORT NumberOfPorts
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION LookupPersistentTcpPortReservation IMPORT "iphlpapi.dll" ALIAS "LookupPersistentTcpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in  USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in  USHORT NumberOfPorts
 , BYREF Token AS QUAD _                                ' __out PULONG64 Token
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION LookupPersistentUdpPortReservation IMPORT "iphlpapi.dll" ALIAS "LookupPersistentUdpPortReservation" ( _
   BYVAL StartPort AS WORD _                            ' __in  USHORT StartPort
 , BYVAL NumberOfPorts AS WORD _                        ' __in  USHORT NumberOfPorts
 , BYREF Token AS QUAD _                                ' __out PULONG64 Token
 ) AS DWORD                                             ' ULONG

'//
'// Network String parsing API
'//

%NET_STRING_IPV4_ADDRESS           = &H00000001???
'   // The string identifies an IPv4 Host/router using literal address.
'   // (port or prefix not allowed)
%NET_STRING_IPV4_SERVICE           = &H00000002???
'   // The string identifies an IPv4 service using literal address.
'   // (port required; prefix not allowed)
%NET_STRING_IPV4_NETWORK           = &H00000004???
'   // The string identifies an IPv4 network.
'   // (prefix required; port not allowed)
%NET_STRING_IPV6_ADDRESS           = &H00000008???
'   // The string identifies an IPv6 Host/router using literal address.
'   // (port or prefix not allowed; scope-id allowed)
%NET_STRING_IPV6_ADDRESS_NO_SCOPE  = &H00000010???
'   // The string identifies an IPv6 Host/router using literal address
'   // where the interface context is already known.
'   // (port or prefix not allowed; scope-id not allowed)
%NET_STRING_IPV6_SERVICE           = &H00000020???
'   // The string identifies an IPv6 service using literal address.
'   // (port required; prefix not allowed; scope-id allowed)
%NET_STRING_IPV6_SERVICE_NO_SCOPE  = &H00000040???
'   // The string identifies an IPv6 service using literal address
'   // where the interface context is already known.
'   // (port required; prefix not allowed; scope-id not allowed)
%NET_STRING_IPV6_NETWORK           = &H00000080???
'   // The string identifies an IPv6 network.
'   // (prefix required; port or scope-id not allowed)
%NET_STRING_NAMED_ADDRESS          = &H00000100???
'   // The string identifies an Internet Host using DNS.
'   // (port or prefix or scope-id not allowed)
%NET_STRING_NAMED_SERVICE          = &H00000200???
'   // The string identifies an Internet service using DNS.
'   // (port required; prefix or scope-id not allowed)

%NET_STRING_IP_ADDRESS = %NET_STRING_IPV4_ADDRESS OR %NET_STRING_IPV6_ADDRESS

%NET_STRING_IP_ADDRESS_NO_SCOPE = %NET_STRING_IPV4_ADDRESS OR %NET_STRING_IPV6_ADDRESS_NO_SCOPE

%NET_STRING_IP_SERVICE = %NET_STRING_IPV4_SERVICE OR %NET_STRING_IPV6_SERVICE

%NET_STRING_IP_SERVICE_NO_SCOPE = %NET_STRING_IPV4_SERVICE OR %NET_STRING_IPV6_SERVICE_NO_SCOPE

%NET_STRING_IP_NETWORK = %NET_STRING_IPV4_NETWORK OR %NET_STRING_IPV6_NETWORK

%NET_STRING_ANY_ADDRESS = %NET_STRING_NAMED_ADDRESS OR %NET_STRING_IP_ADDRESS

%NET_STRING_ANY_ADDRESS_NO_SCOPE = %NET_STRING_NAMED_ADDRESS OR %NET_STRING_IP_ADDRESS_NO_SCOPE

%NET_STRING_ANY_SERVICE = %NET_STRING_NAMED_SERVICE OR %NET_STRING_IP_SERVICE

%NET_STRING_ANY_SERVICE_NO_SCOPE = %NET_STRING_NAMED_SERVICE OR %NET_STRING_IP_SERVICE_NO_SCOPE

' enum NET_ADDRESS_FORMAT
%NET_ADDRESS_FORMAT_UNSPECIFIED = 0
%NET_ADDRESS_DNS_NAME           = 1
%NET_ADDRESS_IPV4               = 2
%NET_ADDRESS_IPV6               = 3

'#if defined (_WS2DEF_) && defined (_WS2IPDEF_) && defined(_WINDNS_INCLUDED_)
'   // app must include winsock2.h, ws2ipdef.h, and windns.h to use this API

#IF %DEF(%WS2DEF_INC)
#IF %DEF(%WS2IPDEF_INC)
#IF %DEF(%WINDNS_INC)

' // Size = 524 bytes
TYPE NET_ADDRESS_INFO_NamedAddress DWORD
   Address AS WSTRINGZ * %DNS_MAX_NAME_BUFFER_LENGTH   ' WCHAR
   Port(5) AS WORD   ' WCHAR[6]
END TYPE

' // Size = 524 bytes
UNION NET_ADDRESS_INFO_UNION
   NET_ADDRESS_INFO_NamedAddress
   Ipv4Address AS SOCKADDR_IN
   Ipv6Address AS SOCKADDR_IN6
   IpAddress   AS SOCKADDR
END UNION

' // Size = 528 bytes
TYPE NET_ADDRESS_INFO DWORD
   Format AS LONG   ' NET_ADDRESS_FORMAT
   NET_ADDRESS_INFO_UNION
END TYPE

DECLARE FUNCTION ParseNetworkString IMPORT "iphlpapi.dll" ALIAS "ParseNetworkString" ( _
   BYREF NetworkString AS WSTRINGZ _                    ' __in  CONST WCHAR* NetworkString
 , BYVAL Types AS DWORD _                               ' __in  DWORD Types
 , BYREF AddressInfo AS NET_ADDRESS_INFO _              ' __out PNET_ADDRESS_INFO AddressInfo OPTIONAL
 , BYREF PortNumber AS WORD _                           ' __out USHORT* PortNumber OPTIONAL
 , BYREF PrefixLength AS BYTE _                         ' __out BYTE* PrefixLength OPTIONAL
 ) AS DWORD                                             ' DWORD

#ENDIF   ' WS2DEF_INC
#ENDIF   ' WS2IPDEF_INC
#ENDIF   ' WINDNS_INC

'#endif

#INCLUDE ONCE "netioapi.inc"

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
