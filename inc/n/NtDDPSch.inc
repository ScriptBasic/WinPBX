' ########################################################################################
' Microsoft Windows
' File: NtDDPSch.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTDDPSCH_INC = 1

'//
'// flow data returned in the Stats structure
'//

%PS_COMPONENT_ADAPTER   = 1
%PS_COMPONENT_FLOW      = 2
%PS_COMPONENT_CONFORMER = 3
%PS_COMPONENT_SHAPER    = 4
%PS_COMPONENT_DRRSEQ    = 5

'#pragma pack(1)
' // Size = 9 bytes
TYPE PS_COMPONENT_STATS BYTE
   Type     AS DWORD   ' ULONG
   Length   AS DWORD   ' ULONG
   Stats(0) AS BYTE    ' UCHAR [1]
END TYPE
'#pragma pack()

'#pragma pack(1)
' // Size = 4 bytes
TYPE PS_CONFORMER_STATS BYTE
   NonconformingPacketsScheduled AS DWORD   ' ULONG
END TYPE
'#pragma pack()

'#pragma pack(1)
' // Size = 8 bytes
TYPE PS_SHAPER_STATS BYTE
   MaxPacketsInShaper     AS DWORD   ' ULONG
   AveragePacketsInShaper AS DWORD   ' ULONG
END TYPE
'#pragma pack()

'#pragma pack(1)
' // Size = 20 bytes
TYPE PS_DRRSEQ_STATS BYTE
   MaxPacketsInNetcard             AS DWORD   ' ULONG
   AveragePacketsInNetcard         AS DWORD   ' ULONG
   MaxPacketsInSequencer           AS DWORD   ' ULONG
   AveragePacketsInSequencer       AS DWORD   ' ULONG
   NonconformingPacketsTransmitted AS DWORD   ' ULONG
END TYPE
'#pragma pack()


'#pragma pack(1)
' // Size = 28 bytes
TYPE PS_FLOW_STATS BYTE
   DroppedPackets     AS DWORD   ' ULONG
   PacketsScheduled   AS DWORD   ' ULONG
   PacketsTransmitted AS DWORD   ' ULONG
   BytesScheduled     AS QUAD    ' LARGE_INTEGER
   BytesTransmitted   AS QUAD    ' LARGE_INTEGER
END TYPE
'#pragma pack()

'#pragma pack(1)
' // Size = 28 bytes
TYPE PS_ADAPTER_STATS BYTE
   ' // OutOfPackets is incremented when no packets for sending/receive packet
   ' // indications are available.
   OutOfPackets         AS DWORD   ' ULONG
   ' // general flow stats
   FlowsOpened          AS DWORD   ' ULONG
   FlowsClosed          AS DWORD   ' ULONG
   FlowsRejected        AS DWORD   ' ULONG
   FlowsModified        AS DWORD   ' ULONG
   FlowModsRejected     AS DWORD   ' ULONG
   MaxSimultaneousFlows AS DWORD   ' ULONG
END TYPE
'#pragma pack()

'//
'// Defines that can be used for OID_QOS_FLOW_MODE
'//
%ADAPTER_FLOW_MODE_DIFFSERV = 1
%ADAPTER_FLOW_MODE_STANDARD = 2
