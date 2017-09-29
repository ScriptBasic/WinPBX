' ########################################################################################
' Microsoft Windows
' File: LMStats.inc
' Contents: This module defines the API function prototypes and data structures for the
' NetStatistics group of NT API functions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMSTATS_INC = 1

#INCLUDE ONCE "LMCONS.INC"

'//
'// Function Prototypes - Statistics
'//

DECLARE FUNCTION NetStatisticsGet IMPORT "NETAPI32.DLL" ALIAS "NetStatisticsGet" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LMSTR   server
 , BYREF service AS WSTRINGZ _                          ' __in  LMSTR   service
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL options AS DWORD _                             ' __in  DWORD   options
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Statistics
'//

#IF %DEF(%LM20_WORKSTATION_STATISTICS)

' // Size = 120 bytes
TYPE STAT_WORKSTATION_0 DWORD
   stw0_start          AS DWORD   ' DWORD stw0_start
   stw0_numNCB_r       AS DWORD   ' DWORD stw0_numNCB_r
   stw0_numNCB_s       AS DWORD   ' DWORD stw0_numNCB_s
   stw0_numNCB_a       AS DWORD   ' DWORD stw0_numNCB_a
   stw0_fiNCB_r        AS DWORD   ' DWORD stw0_fiNCB_r
   stw0_fiNCB_s        AS DWORD   ' DWORD stw0_fiNCB_s
   stw0_fiNCB_a        AS DWORD   ' DWORD stw0_fiNCB_a
   stw0_fcNCB_r        AS DWORD   ' DWORD stw0_fcNCB_r
   stw0_fcNCB_s        AS DWORD   ' DWORD stw0_fcNCB_s
   stw0_fcNCB_a        AS DWORD   ' DWORD stw0_fcNCB_a
   stw0_sesstart       AS DWORD   ' DWORD stw0_sesstart
   stw0_sessfailcon    AS DWORD   ' DWORD stw0_sessfailcon
   stw0_sessbroke      AS DWORD   ' DWORD stw0_sessbroke
   stw0_uses           AS DWORD   ' DWORD stw0_uses
   stw0_usefail        AS DWORD   ' DWORD stw0_usefail
   stw0_autorec        AS DWORD   ' DWORD stw0_autorec
   stw0_bytessent_r_lo AS DWORD   ' DWORD stw0_bytessent_r_lo
   stw0_bytessent_r_hi AS DWORD   ' DWORD stw0_bytessent_r_hi
   stw0_bytesrcvd_r_lo AS DWORD   ' DWORD stw0_bytesrcvd_r_lo
   stw0_bytesrcvd_r_hi AS DWORD   ' DWORD stw0_bytesrcvd_r_hi
   stw0_bytessent_s_lo AS DWORD   ' DWORD stw0_bytessent_s_lo
   stw0_bytessent_s_hi AS DWORD   ' DWORD stw0_bytessent_s_hi
   stw0_bytesrcvd_s_lo AS DWORD   ' DWORD stw0_bytesrcvd_s_lo
   stw0_bytesrcvd_s_hi AS DWORD   ' DWORD stw0_bytesrcvd_s_hi
   stw0_bytessent_a_lo AS DWORD   ' DWORD stw0_bytessent_a_lo
   stw0_bytessent_a_hi AS DWORD   ' DWORD stw0_bytessent_a_hi
   stw0_bytesrcvd_a_lo AS DWORD   ' DWORD stw0_bytesrcvd_a_lo
   stw0_bytesrcvd_a_hi AS DWORD   ' DWORD stw0_bytesrcvd_a_hi
   stw0_reqbufneed     AS DWORD   ' DWORD stw0_reqbufneed
   stw0_bigbufneed     AS DWORD   ' DWORD stw0_bigbufneed
END TYPE

#ELSE

'//
'// NB: The following structure is REDIR_STATISTICS in sdk\inc\ntddnfs.h. If you
'//     change the structure, change it in both places
'//

' // Size = 216 bytes
TYPE STAT_WORKSTATION_0   ' Must be 8 byte aligned
   StatisticsStartTime          AS QUAD    ' LARGE_INTEGER

   BytesReceived                AS QUAD    ' LARGE_INTEGER
   SmbsReceived                 AS QUAD    ' LARGE_INTEGER
   PagingReadBytesRequested     AS QUAD    ' LARGE_INTEGER
   NonPagingReadBytesRequested  AS QUAD    ' LARGE_INTEGER
   CacheReadBytesRequested      AS QUAD    ' LARGE_INTEGER
   NetworkReadBytesRequested    AS QUAD    ' LARGE_INTEGER

   BytesTransmitted             AS QUAD    ' LARGE_INTEGER
   SmbsTransmitted              AS QUAD    ' LARGE_INTEGER
   PagingWriteBytesRequested    AS QUAD    ' LARGE_INTEGER
   NonPagingWriteBytesRequested AS QUAD    ' LARGE_INTEGER
   CacheWriteBytesRequested     AS QUAD    ' LARGE_INTEGER
   NetworkWriteBytesRequested   AS QUAD    ' LARGE_INTEGER

   InitiallyFailedOperations    AS DWORD   ' DWORD InitiallyFailedOperations
   FailedCompletionOperations   AS DWORD   ' DWORD FailedCompletionOperations

   ReadOperations               AS DWORD   ' DWORD ReadOperations
   RandomReadOperations         AS DWORD   ' DWORD RandomReadOperations
   ReadSmbs                     AS DWORD   ' DWORD ReadSmbs
   LargeReadSmbs                AS DWORD   ' DWORD LargeReadSmbs
   SmallReadSmbs                AS DWORD   ' DWORD SmallReadSmbs

   WriteOperations              AS DWORD   ' DWORD WriteOperations
   RandomWriteOperations        AS DWORD   ' DWORD RandomWriteOperations
   WriteSmbs                    AS DWORD   ' DWORD WriteSmbs
   LargeWriteSmbs               AS DWORD   ' DWORD LargeWriteSmbs
   SmallWriteSmbs               AS DWORD   ' DWORD SmallWriteSmbs

   RawReadsDenied               AS DWORD   ' DWORD RawReadsDenied
   RawWritesDenied              AS DWORD   ' DWORD RawWritesDenied

   NetworkErrors                AS DWORD   ' DWORD NetworkErrors

   ' //  Connection/Session counts
   Sessions                     AS DWORD   ' DWORD Sessions
   FailedSessions               AS DWORD   ' DWORD FailedSessions
   Reconnects                   AS DWORD   ' DWORD Reconnects
   CoreConnects                 AS DWORD   ' DWORD CoreConnects
   Lanman20Connects             AS DWORD   ' DWORD Lanman20Connects
   Lanman21Connects             AS DWORD   ' DWORD Lanman21Connects
   LanmanNtConnects             AS DWORD   ' DWORD LanmanNtConnects
   ServerDisconnects            AS DWORD   ' DWORD ServerDisconnects
   HungSessions                 AS DWORD   ' DWORD HungSessions
   UseCount                     AS DWORD   ' DWORD UseCount
   FailedUseCount               AS DWORD   ' DWORD FailedUseCount

   ' //
   ' //  Queue Lengths (updates protected by RdrMpxTableSpinLock NOT
   ' //  RdrStatisticsSpinlock)
   ' //

   CurrentCommands             AS DWORD   ' DWORD CurrentCommands
   alignment__                 AS DWORD

END TYPE

#ENDIF

' // Size = 68 bytes
TYPE STAT_SERVER_0 DWORD
   sts0_start          AS DWORD   ' DWORD sts0_start
   sts0_fopens         AS DWORD   ' DWORD sts0_fopens
   sts0_devopens       AS DWORD   ' DWORD sts0_devopens
   sts0_jobsqueued     AS DWORD   ' DWORD sts0_jobsqueued
   sts0_sopens         AS DWORD   ' DWORD sts0_sopens
   sts0_stimedout      AS DWORD   ' DWORD sts0_stimedout
   sts0_serrorout      AS DWORD   ' DWORD sts0_serrorout
   sts0_pwerrors       AS DWORD   ' DWORD sts0_pwerrors
   sts0_permerrors     AS DWORD   ' DWORD sts0_permerrors
   sts0_syserrors      AS DWORD   ' DWORD sts0_syserrors
   sts0_bytessent_low  AS DWORD   ' DWORD sts0_bytessent_low
   sts0_bytessent_high AS DWORD   ' DWORD sts0_bytessent_high
   sts0_bytesrcvd_low  AS DWORD   ' DWORD sts0_bytesrcvd_low
   sts0_bytesrcvd_high AS DWORD   ' DWORD sts0_bytesrcvd_high
   sts0_avresponse     AS DWORD   ' DWORD sts0_avresponse
   sts0_reqbufneed     AS DWORD   ' DWORD sts0_reqbufneed
   sts0_bigbufneed     AS DWORD   ' DWORD sts0_bigbufneed
END TYPE

'//
'// Special Values and Constants
'//

%STATSOPT_CLR    = 1
%STATS_NO_VALUE  = &HFFFFFFFF???   ' ((unsigned long) -1L)
%STATS_OVERFLOW  = &HFFFFFFFE???   ' ((unsigned long) -2L)
