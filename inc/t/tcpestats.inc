' ########################################################################################
' Microsoft Windows
' File: tcpestats.inc
' Contents: Definitions and structures for TCP extended statistics.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TCPESTATS_INC = 1

'//
'// Please don't change the order of this enum. The order defined in this
'// enum needs to match the order in EstatsToTcpObjectMappingTable.
'//

' enum TCP_ESTATS_TYPE
%TcpConnectionEstatsSynOpts   = 0
%TcpConnectionEstatsData      = 1
%TcpConnectionEstatsSndCong   = 2
%TcpConnectionEstatsPath      = 3
%TcpConnectionEstatsSendBuff  = 4
%TcpConnectionEstatsRec       = 5
%TcpConnectionEstatsObsRec    = 6
%TcpConnectionEstatsBandwidth = 7
%TcpConnectionEstatsFineRtt   = 8
%TcpConnectionEstatsMaximum   = 9

'//
'// TCP_BOOLEAN_OPTIONAL
'//
'// Define the states that a caller can specify when updating a boolean field.
'//

' enum _TCP_BOOLEAN_OPTIONAL
%TcpBoolOptDisabled  = 0
%TcpBoolOptEnabled   = 1
%TcpBoolOptUnchanged = -1

'//
'// TCP_ESTATS_SYN_OPTS_ROS
'//
'// Define extended SYN-exchange information maintained for TCP connections.
'//

' // Size = 12 bytes
TYPE TCP_ESTATS_SYN_OPTS_ROS_v0 DWORD
   ActiveOpen AS BYTE    ' BOOLEAN
   MssRcvd    AS DWORD   ' ULONG
   MssSent    AS DWORD   ' ULONG
END TYPE


'//
'// TCP_SOFT_ERROR
'//
'// Enumerate the non-fatal errors recorded on each connection.
'//

' enum TCP_SOFT_ERROR
%TcpErrorNone              = 0
%TcpErrorBelowDataWindow   = 1
%TcpErrorAboveDataWindow   = 2
%TcpErrorBelowAckWindow    = 3
%TcpErrorAboveAckWindow    = 4
%TcpErrorBelowTsWindow     = 5
%TcpErrorAboveTsWindow     = 6
%TcpErrorDataChecksumError = 7
%TcpErrorDataLengthError   = 8
%TcpErrorMaxSoftError      = 9

'//
'// TCP_ESTATS_DATA_ROD
'//
'// Define extended data-transfer information for TCP connections.
'//

' // Size = 96 bytes
TYPE TCP_ESTATS_DATA_ROD_v0 QWORD FILL
   DataBytesOut      AS QUAD    ' ULONG64
   DataSegsOut       AS QUAD    ' ULONG64
   DataBytesIn       AS QUAD    ' ULONG64
   DataSegsIn        AS QUAD    ' ULONG64
   SegsOut           AS QUAD    ' ULONG64
   SegsIn            AS QUAD    ' ULONG64
   SoftErrors        AS DWORD   ' ULONG
   SoftErrorReason   AS DWORD   ' ULONG
   SndUna            AS DWORD   ' ULONG
   SndNxt            AS DWORD   ' ULONG
   SndMax            AS DWORD   ' ULONG
   ThruBytesAcked    AS QUAD    ' ULONG64
   RcvNxt            AS DWORD   ' ULONG
   ThruBytesReceived AS QUAD    ' ULONG64
END TYPE

'//
'// TCP_ESTATS_DATA_RW
'//
'// Define structure for enabling extended data-transfer information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_DATA_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE


'//
'// TCP_ESTATS_SND_CONG_ROD
'//
'// Define extended sender-congestion information for TCP connections.
'//

' // Size = 72 bytes
TYPE TCP_ESTATS_SND_CONG_ROD_v0 DWORD
   SndLimTransRwin AS DWORD   ' ULONG
   SndLimTimeRwin  AS DWORD   ' ULONG
   SndLimBytesRwin AS DWORD   ' SIZE_T
   SndLimTransCwnd AS DWORD   ' ULONG
   SndLimTimeCwnd  AS DWORD   ' ULONG
   SndLimBytesCwnd AS DWORD   ' SIZE_T
   SndLimTransSnd  AS DWORD   ' ULONG
   SndLimTimeSnd   AS DWORD   ' ULONG
   SndLimBytesSnd  AS DWORD   ' SIZE_T
   SlowStart       AS DWORD   ' ULONG
   CongAvoid       AS DWORD   ' ULONG
   OtherReductions AS DWORD   ' ULONG
   CurCwnd         AS DWORD   ' ULONG
   MaxSsCwnd       AS DWORD   ' ULONG
   MaxCaCwnd       AS DWORD   ' ULONG
   CurSsthresh     AS DWORD   ' ULONG
   MaxSsthresh     AS DWORD   ' ULONG
   MinSsthresh     AS DWORD   ' ULONG
END TYPE

'//
'// TCP_ESTATS_SND_CONG_ROS
'//
'// Define static extended sender-congestion information for TCP connections.

' // Size = 4 bytes
TYPE TCP_ESTATS_SND_CONG_ROS_v0 DWORD
   LimCwnd AS DWORD   ' ULONG
END TYPE

'//
'// TCP_ESTATS_SND_CONG_RW
'//
'// Define structure for enabling extended sender-congestion information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_SND_CONG_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE

'//
'// TCP_ESTATS_PATH_ROD
'//
'// Define extended path-measurement information for TCP connections.
'//

' // Size = 160 bytes
TYPE TCP_ESTATS_PATH_ROD_v0 DWORD
   FastRetran            AS DWORD   ' ULONG
   Timeouts              AS DWORD   ' ULONG
   SubsequentTimeouts    AS DWORD   ' ULONG
   CurTimeoutCount       AS DWORD   ' ULONG
   AbruptTimeouts        AS DWORD   ' ULONG
   PktsRetrans           AS DWORD   ' ULONG
   BytesRetrans          AS DWORD   ' ULONG
   DupAcksIn             AS DWORD   ' ULONG
   SacksRcvd             AS DWORD   ' ULONG
   SackBlocksRcvd        AS DWORD   ' ULONG
   CongSignals           AS DWORD   ' ULONG
   PreCongSumCwnd        AS DWORD   ' ULONG
   PreCongSumRtt         AS DWORD   ' ULONG
   PostCongSumRtt        AS DWORD   ' ULONG
   PostCongCountRtt      AS DWORD   ' ULONG
   EcnSignals            AS DWORD   ' ULONG
   EceRcvd               AS DWORD   ' ULONG
   SendStall             AS DWORD   ' ULONG
   QuenchRcvd            AS DWORD   ' ULONG
   RetranThresh          AS DWORD   ' ULONG
   SndDupAckEpisodes     AS DWORD   ' ULONG
   SumBytesReordered     AS DWORD   ' ULONG
   NonRecovDa            AS DWORD   ' ULONG
   NonRecovDaEpisodes    AS DWORD   ' ULONG
   AckAfterFr            AS DWORD   ' ULONG
   DsackDups             AS DWORD   ' ULONG
   SampleRtt             AS DWORD   ' ULONG
   SmoothedRtt           AS DWORD   ' ULONG
   RttVar                AS DWORD   ' ULONG
   MaxRtt                AS DWORD   ' ULONG
   MinRtt                AS DWORD   ' ULONG
   SumRtt                AS DWORD   ' ULONG
   CountRtt              AS DWORD   ' ULONG
   CurRto                AS DWORD   ' ULONG
   MaxRto                AS DWORD   ' ULONG
   MinRto                AS DWORD   ' ULONG
   CurMss                AS DWORD   ' ULONG
   MaxMss                AS DWORD   ' ULONG
   MinMss                AS DWORD   ' ULONG
   SpuriousRtoDetections AS DWORD   ' ULONG
END TYPE

'//
'// TCP_ESTATS_PATH_ROS
'//
'// Define structure for enabling path-measurement information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_PATH_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE

'//
'// TCP_ESTATS_SEND_BUFF_ROD
'//
'// Define extended output-queuing information for TCP connections.
'//

' // Size = 16 bytes
TYPE TCP_ESTATS_SEND_BUFF_ROD_v0 DWORD
   CurRetxQueue AS DWORD   ' SIZE_T
   MaxRetxQueue AS DWORD   ' SIZE_T
   CurAppWQueue AS DWORD   ' SIZE_T
   MaxAppWQueue AS DWORD   ' SIZE_T
END TYPE

'//
'// TCP_ESTATS_SEND_BUFF_RW
'//
'// Define structure for enabling output-queuing information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_SEND_BUFF_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE


'//
'// TCP_ESTATS_REC_ROD
'//
'// Define extended local-receiver information for TCP connections.
'//

' // Size = 56 bytes
TYPE TCP_ESTATS_REC_ROD_v0 DWORD
   CurRwinSent    AS DWORD   ' ULONG
   MaxRwinSent    AS DWORD   ' ULONG
   MinRwinSent    AS DWORD   ' ULONG
   LimRwin        AS DWORD   ' ULONG
   DupAckEpisodes AS DWORD   ' ULONG
   DupAcksOut     AS DWORD   ' ULONG
   CeRcvd         AS DWORD   ' ULONG
   EcnSent        AS DWORD   ' ULONG
   EcnNoncesRcvd  AS DWORD   ' ULONG
   CurReasmQueue  AS DWORD   ' ULONG
   MaxReasmQueue  AS DWORD   ' ULONG
   CurAppRQueue   AS DWORD   ' SIZE_T
   MaxAppRQueue   AS DWORD   ' SIZE_T
   WinScaleSent   AS BYTE    ' UCHAR
END TYPE

'//
'// TCP_ESTATS_REC_RW
'//
'// Define structure for enabling local-receiver information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_REC_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE


'//
'// TCP_ESTATS_OBS_REC_ROD
'//
'// Define extended remote-receiver information for TCP connections.
'//

' // Size = 16 bytes
TYPE TCP_ESTATS_OBS_REC_ROD_v0 DWORD
   CurRwinRcvd  AS DWORD   ' ULONG
   MaxRwinRcvd  AS DWORD   ' ULONG
   MinRwinRcvd  AS DWORD   ' ULONG
   WinScaleRcvd AS BYTE    ' UCHAR
END TYPE


'//
'// TCP_ESTATS_OBS_REC_RW
'//
'// Define structure for enabling remote-receiver information.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_OBS_REC_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE


'//
'// TCP_ESTATS_BW_RW
'//
'// Define the structure for enabling bandwidth estimation for TCP connections.
'//

' // Size = 8 bytes
TYPE TCP_ESTATS_BANDWIDTH_RW_v0 BYTE
   EnableCollectionOutbound AS LONG   ' TCP_BOOLEAN_OPTIONAL
   EnableCollectionInbound  AS LONG   ' TCP_BOOLEAN_OPTIONAL
END TYPE

'//
'// TCP_ESTATS_BW_ROD
'//
'// Define bandwidth estimation statistics for TCP connections.
'//
'// Bandwidth and Instability metrics are expressed as bits per second.
'//

' // Size = 40 bytes
TYPE TCP_ESTATS_BANDWIDTH_ROD_v0   ' Must be 8 byte aligned
   OutboundBandwidth       AS QUAD   ' ULONG64
   InboundBandwidth        AS QUAD   ' ULONG64
   OutboundInstability     AS QUAD   ' ULONG64
   InboundInstability      AS QUAD   ' ULONG64
   OutboundBandwidthPeaked AS BYTE   ' BOOLEAN
   InboundBandwidthPeaked  AS BYTE   ' BOOLEAN
   alignment__(5)          AS BYTE   ' // To keep 8 byte alignment
END TYPE

'//
'// TCP_ESTATS_FINE_RTT_RW
'//
'// Define the structure for enabling fine-grained RTT estimation for TCP
'// connections.
'//

' // Size = 1 byte
TYPE TCP_ESTATS_FINE_RTT_RW_v0 BYTE
   EnableCollection AS BYTE   ' BOOLEAN
END TYPE


'//
'// TCP_ESTATS_FINE_RTT_ROD
'//
'// Define fine-grained RTT estimation statistics for TCP connections.
'//

' // Size = 16 bytes
TYPE TCP_ESTATS_FINE_RTT_ROD_v0 DWORD
   RttVar AS DWORD   ' ULONG
   MaxRtt AS DWORD   ' ULONG
   MinRtt AS DWORD   ' ULONG
   SumRtt AS DWORD   ' ULONG
END TYPE
