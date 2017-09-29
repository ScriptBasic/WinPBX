' ########################################################################################
' Microsoft Windows
' File: tcpioctl.inc
' Contents: Definitions for IOCTL_TCP_QUERY_INFORMATION_EX.
' Caveat: IPHLPAPI provides cleaner API's to access this information.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TCPIOCTL_INC = 1

#INCLUDE ONCE "WinIoCtl.inc"

%FSCTL_TCP_BASE                  = %FILE_DEVICE_NETWORK

'#define _TCP_CTL_CODE(function, method, access) \
'            CTL_CODE(FSCTL_TCP_BASE, function, method, access)
MACRO TCP_CTL_CODE(function_, method_, access_) = CTL_CODE(%FSCTL_TCP_BASE, function_, method_, access_)

'#define IOCTL_TCP_QUERY_INFORMATION_EX  \
'            _TCP_CTL_CODE(0, METHOD_NEITHER, FILE_ANY_ACCESS)
%IOCTL_TCP_QUERY_INFORMATION_EX = &H00120003???

'#define DD_TCP_DEVICE_NAME              L"\\Device\\Tcp"
$$DD_TCP_DEVICE_NAME            = "\Device\Tcp"$$

%IF_MIB_STATS_ID                = 1
%IP_MIB_STATS_ID                = 1
%IP_MIB_ADDRTABLE_ENTRY_ID      = &H102
%IP_INTFC_INFO_ID               = &H103

%MAX_PHYSADDR_SIZE   = 8

' // Size = 96 bytes
TYPE IFEntry DWORD
   if_index           AS DWORD                        ' ulong
   if_type            AS DWORD                        ' ulong
   if_mtu             AS DWORD                        ' ulong
   if_speed           AS DWORD                        ' ulong
   if_physaddrlen     AS DWORD                        ' ulong
   if_physaddr        AS STRING * %MAX_PHYSADDR_SIZE  ' uchar[MAX_PHYSADDR_SIZE]
   if_adminstatus     AS DWORD                        ' ulong
   if_operstatus      AS DWORD                        ' ulong
   if_lastchange      AS DWORD                        ' ulong
   if_inoctets        AS DWORD                        ' ulong
   if_inucastpkts     AS DWORD                        ' ulong
   if_innucastpkts    AS DWORD                        ' ulong
   if_indiscards      AS DWORD                        ' ulong
   if_inerrors        AS DWORD                        ' ulong
   if_inunknownprotos AS DWORD                        ' ulong
   if_outoctets       AS DWORD                        ' ulong
   if_outucastpkts    AS DWORD                        ' ulong
   if_outnucastpkts   AS DWORD                        ' ulong
   if_outdiscards     AS DWORD                        ' ulong
   if_outerrors       AS DWORD                        ' ulong
   if_outqlen         AS DWORD                        ' ulong
   if_descrlen        AS DWORD                        ' ulong
   if_descr(0)        AS BYTE                         ' uchar
END TYPE

' // Size = 92 bytes
TYPE IPSNMPInfo DWORD
   ipsi_forwarding      AS DWORD   ' ulong
   ipsi_defaultttl      AS DWORD   ' ulong
   ipsi_inreceives      AS DWORD   ' ulong
   ipsi_inhdrerrors     AS DWORD   ' ulong
   ipsi_inaddrerrors    AS DWORD   ' ulong
   ipsi_forwdatagrams   AS DWORD   ' ulong
   ipsi_inunknownprotos AS DWORD   ' ulong
   ipsi_indiscards      AS DWORD   ' ulong
   ipsi_indelivers      AS DWORD   ' ulong
   ipsi_outrequests     AS DWORD   ' ulong
   ipsi_routingdiscards AS DWORD   ' ulong
   ipsi_outdiscards     AS DWORD   ' ulong
   ipsi_outnoroutes     AS DWORD   ' ulong
   ipsi_reasmtimeout    AS DWORD   ' ulong
   ipsi_reasmreqds      AS DWORD   ' ulong
   ipsi_reasmoks        AS DWORD   ' ulong
   ipsi_reasmfails      AS DWORD   ' ulong
   ipsi_fragoks         AS DWORD   ' ulong
   ipsi_fragfails       AS DWORD   ' ulong
   ipsi_fragcreates     AS DWORD   ' ulong
   ipsi_numif           AS DWORD   ' ulong
   ipsi_numaddr         AS DWORD   ' ulong
   ipsi_numroutes       AS DWORD   ' ulong
END TYPE

' // Size = 24 bytes
TYPE IPAddrEntry DWORD FILL
   iae_addrAS      AS DWORD   ' ulong
   iae_indexAS     AS DWORD   ' ulong
   iae_maskAS      AS DWORD   ' ulong
   iae_bcastaddrAS AS DWORD   ' ulong
   iae_reasmsizeAS AS DWORD   ' ulong
   iae_context     AS WORD    ' ushort
   iae_pad         AS WORD    ' ushort
END TYPE

' // Size = 20 bytes
TYPE IPInterfaceInfo DWORD
   iii_flags      AS DWORD   ' ulong
   iii_mtu        AS DWORD   ' ulong
   iii_speed      AS DWORD   ' ulong
   iii_addrlength AS DWORD   ' ulong
   iii_addr(0)    AS BYTE    ' uchar
END TYPE
