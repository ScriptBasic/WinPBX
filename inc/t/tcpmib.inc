' ########################################################################################
' Microsoft Windows
' File: tcpmib.inc
' Contents: Public definitions and structures for the TCP-specific parts of MIB-II.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TCPMIB_INC = 1

#INCLUDE ONCE "windows.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

%TCPIP_OWNING_MODULE_SIZE = 16

'//
'// TCP states, as defined in the MIB.
'//
' enum MIB_TCP_STATE
%MIB_TCP_STATE_CLOSED     =  1
%MIB_TCP_STATE_LISTEN     =  2
%MIB_TCP_STATE_SYN_SENT   =  3
%MIB_TCP_STATE_SYN_RCVD   =  4
%MIB_TCP_STATE_ESTAB      =  5
%MIB_TCP_STATE_FIN_WAIT1  =  6
%MIB_TCP_STATE_FIN_WAIT2  =  7
%MIB_TCP_STATE_CLOSE_WAIT =  8
%MIB_TCP_STATE_CLOSING    =  9
%MIB_TCP_STATE_LAST_ACK   = 10
%MIB_TCP_STATE_TIME_WAIT  = 11
%MIB_TCP_STATE_DELETE_TCB = 12

'//
'// Various Offload states a TCP connection can be in.
'//
' enum TCP_CONNECTION_OFFLOAD_STATE
%TcpConnectionOffloadStateInHost     = 0
%TcpConnectionOffloadStateOffloading = 1
%TcpConnectionOffloadStateOffloaded  = 2
%TcpConnectionOffloadStateUploading  = 3
%TcpConnectionOffloadStateMax        = 4

' // Size = 4 bytes
UNION MIB_TCPROW_LH_UNION DWORD
   dwState AS DWORD   ' DWORD // Old field used DWORD type.
   State   AS LONG    ' MIB_TCP_STATE // New field uses enum type.
END UNION

' // Size = 20 bytes
TYPE MIB_TCPROW_LH DWORD
   MIB_TCPROW_LH_UNION
   dwLocalAddr  AS DWORD   ' DWORD
   dwLocalPort  AS DWORD   ' DWORD
   dwRemoteAddr AS DWORD   ' DWORD
   dwRemotePort AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE MIB_TCPROW_W2K DWORD
   dwState      AS DWORD   ' DWORD
   dwLocalAddr  AS DWORD   ' DWORD
   dwLocalPort  AS DWORD   ' DWORD
   dwRemoteAddr AS DWORD   ' DWORD
   dwRemotePort AS DWORD   ' DWORD
END TYPE

#IF %WINVER >= &H0600      ' Windows Vista
MACRO MIB_TCPROW = MIB_TCPROW_LH
#ELSEIF %WINVER = &H0500   ' Windows 2000
MACRO MIB_TCPROW = MIB_TCPROW_W2K
#ELSE
MACRO MIB_TCPROW = MIB_TCPROW_LH
#ENDIF

' // Size = 24 bytes
TYPE MIB_TCPTABLE DWORD
   dwNumEntries AS DWORD        ' DWORD
   table(0)     AS MIB_TCPROW   ' MIB_TCPROW table[ANY_SIZE];
END TYPE

'#define SIZEOF_TCPTABLE(X) (FIELD_OFFSET(MIB_TCPTABLE,table[0]) + \
'                            ((X) * sizeof(MIB_TCPROW)) + ALIGN_SIZE)

' // Size = 28 bytes
TYPE MIB_TCPROW2 DWORD
   dwState        AS DWORD   ' DWORD
   dwLocalAddr    AS DWORD   ' DWORD
   dwLocalPort    AS DWORD   ' DWORD
   dwRemoteAddr   AS DWORD   ' DWORD
   dwRemotePort   AS DWORD   ' DWORD
   dwOwningPid    AS DWORD   ' DWORD
   dwOffloadState AS LONG    ' TCP_CONNECTION_OFFLOAD_STATE
END TYPE

' // Size = 32 bytes
TYPE MIB_TCPTABLE2 DWORD
   dwNumEntries AS DWORD         ' DWORD
   table(0)     AS MIB_TCPROW2   ' MIB_TCPROW2 table[ANY_SIZE];
END TYPE

'#define SIZEOF_TCPTABLE2(X) (FIELD_OFFSET(MIB_TCPTABLE2,table[0]) + \
'                            ((X) * sizeof(MIB_TCPROW2)) + ALIGN_SIZE)

' // Size = 24 bytes
TYPE MIB_TCPROW_OWNER_PID DWORD
   dwState      AS DWORD   ' DWORD
   dwLocalAddr  AS DWORD   ' DWORD
   dwLocalPort  AS DWORD   ' DWORD
   dwRemoteAddr AS DWORD   ' DWORD
   dwRemotePort AS DWORD   ' DWORD
   dwOwningPid  AS DWORD   ' DWORD
END TYPE

' // Size = 28 bytes
TYPE MIB_TCPTABLE_OWNER_PID DWORD
   dwNumEntries AS DWORD                  ' DWORD
   table(0)     AS MIB_TCPROW_OWNER_PID   ' MIB_TCPROW_OWNER_PID table[ANY_SIZE];
END TYPE

'#define SIZEOF_TCPTABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_TCPTABLE_OWNER_PID, table[0]) + \
'                             ((X) * sizeof(MIB_TCPROW_OWNER_PID)) + ALIGN_SIZE)

' // Size = 160 bytes
TYPE MIB_TCPROW_OWNER_MODULE   ' Must be 8 byte aligned
   dwState           AS DWORD   ' DWORD
   dwLocalAddr       AS DWORD   ' DWORD
   dwLocalPort       AS DWORD   ' DWORD
   dwRemoteAddr      AS DWORD   ' DWORD
   dwRemotePort      AS DWORD   ' DWORD
   dwOwningPid       AS DWORD   ' DWORD
   liCreateTimestamp AS QUAD    ' LARGE_INTEGER
   OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE -  1)    AS QUAD   ' ULONGLONG
END TYPE

' // Size = 168 bytes
TYPE MIB_TCPTABLE_OWNER_MODULE QWORD FILL  ' Must be 8 byte aligned
   dwNumEntries AS DWORD                     ' DWORD
   table(0)     AS MIB_TCPROW_OWNER_MODULE   ' MIB_TCPROW_OWNER_MODULE table[ANY_SIZE];
END TYPE

'#define SIZEOF_TCPTABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_TCPTABLE_OWNER_MODULE, table[0]) + \
'                               ((X) * sizeof(MIB_TCPROW_OWNER_MODULE)) + ALIGN_SIZE)

#IF %DEF(%WS2IPDEF_INC)
'//
'// The following definitions require Winsock2.
'//

' // Size = 52 bytes
TYPE MIB_TCP6ROW DWORD
   State           AS LONG       ' MIB_TCP_STATE enum
   LocalAddr       AS IN6_ADDR   ' IN6_ADDR
   dwLocalScopeId  AS DWORD      ' DWORD
   dwLocalPort     AS DWORD      ' DWORD
   RemoteAddr      AS IN6_ADDR   ' IN6_ADDR
   dwRemoteScopeId AS DWORD      ' DWORD
   dwRemotePort    AS DWORD      ' DWORD
END TYPE

' // Size = 56 bytes
TYPE MIB_TCP6TABLE DWORD
   dwNumEntries AS DWORD         ' DWORD
   table(0)     AS MIB_TCP6ROW   ' MIB_TCP6ROW table[ANY_SIZE];
END TYPE

'#define SIZEOF_TCP6TABLE(X) (FIELD_OFFSET(MIB_TCP6TABLE,table[0]) + \
'                             ((X) * sizeof(MIB_TCP6ROW)) + ALIGN_SIZE)

' // Size = 60 bytes
TYPE MIB_TCP6ROW2 DWORD
   LocalAddr       AS IN6_ADDR   ' IN6_ADDR
   dwLocalScopeId  AS DWORD      ' DWORD
   dwLocalPort     AS DWORD      ' DWORD
   RemoteAddr      AS IN6_ADDR   ' IN6_ADDR
   dwRemoteScopeId AS DWORD      ' DWORD
   dwRemotePort    AS DWORD      ' DWORD
   State           AS LONG       ' MIB_TCP_STATE
   dwOwningPid     AS DWORD      ' DWORD
   dwOffloadState  AS LONG       ' TCP_CONNECTION_OFFLOAD_STATE
END TYPE

' // Size = 64 bytes
TYPE MIB_TCP6TABLE2 DWORD
   dwNumEntries AS DWORD          ' DWORD
   table(0)     AS MIB_TCP6ROW2   ' MIB_TCP6ROW2 table[ANY_SIZE]
END TYPE

'#define SIZEOF_TCP6TABLE2(X) (FIELD_OFFSET(MIB_TCP6TABLE2,table[0]) + \
'                       ((X) * sizeof(MIB_TCP6ROW2)) + ALIGN_SIZE)

' // Size = 56 bytes
TYPE MIB_TCP6ROW_OWNER_PID DWORD
   ucLocalAddr(15)  AS BYTE    ' UCHAR[16]
   dwLocalScopeId   AS DWORD   ' DWORD
   dwLocalPort      AS DWORD   ' DWORD
   ucRemoteAddr(15) AS BYTE    ' UCHAR[16]
   dwRemoteScopeId  AS DWORD   ' DWORD
   dwRemotePort     AS DWORD   ' DWORD
   dwState          AS DWORD   ' DWORD
   dwOwningPid      AS DWORD   ' DWORD
END TYPE

' // Size = 60 bytes
TYPE MIB_TCP6TABLE_OWNER_PID DWORD
   dwNumEntries AS DWORD                   ' DWORD
   table(0)     AS MIB_TCP6ROW_OWNER_PID   ' MIB_TCP6ROW_OWNER_PID   table[ANY_SIZE]
END TYPE

'#define SIZEOF_TCP6TABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_TCP6TABLE_OWNER_PID, table[0]) + \
'                              ((X) * sizeof(MIB_TCP6ROW_OWNER_PID)) + ALIGN_SIZE)

' // Size = 192 bytes
TYPE MIB_TCP6ROW_OWNER_MODULE   ' Must be 8 byte aligned
   ucLocalAddr(15)   AS BYTE    ' UCHAR[16]
   dwLocalScopeId    AS DWORD   ' DWORD
   dwLocalPort       AS DWORD   ' DWORD
   ucRemoteAddr(15)  AS BYTE    ' UCHAR[16]
   dwRemoteScopeId   AS DWORD   ' DWORD
   dwRemotePort      AS DWORD   ' DWORD
   dwState           AS DWORD   ' DWORD
   dwOwningPid       AS DWORD   ' DWORD
   liCreateTimestamp AS QUAD    ' LARGE_INTEGER
   OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE -  1) AS QUAD   ' ULONGLONG
END TYPE

' // Size = 200 bytes
TYPE MIB_TCP6TABLE_OWNER_MODULE QWORD FILL   ' Must be 8 byte aligned
   dwNumEntries AS DWORD                      ' DWORD
   table(0)     AS MIB_TCP6ROW_OWNER_MODULE   ' MIB_TCP6ROW_OWNER_MODULE    table[ANY_SIZE]
END TYPE

'#define SIZEOF_TCP6TABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_TCP6TABLE_OWNER_MODULE, table[0]) + \
'                                ((X) * sizeof(MIB_TCP6ROW_OWNER_MODULE)) + ALIGN_SIZE)

#ENDIF ' // _WS2IPDEF_

%MIB_TCP_MAXCONN_DYNAMIC = &HFFFFFFFF???   ' ((ULONG)-1)

'//
'// The algorithm used to determine the timeout value used for retransmitting
'// unacknowledged octets.
'//
'// REVIEW: This enum adds another version of the defines that already
'// exist in iprtrmib.h (MIB_TCP_RTO_*).  Shouldn't we just use the
'// public names that already exist?
'//
' enum TCP_RTO_ALGORITHM
%TcpRtoAlgorithmOther    = 0
%TcpRtoAlgorithmConstant = 1
%TcpRtoAlgorithmRsre     = 2
%TcpRtoAlgorithmVanj     = 3

%MIB_TCP_RTO_OTHER     = 1
%MIB_TCP_RTO_CONSTANT  = 2
%MIB_TCP_RTO_RSRE      = 3
%MIB_TCP_RTO_VANJ      = 4

' // Size = 4 bytes
UNION MIB_TCPSTATS_LH_UNION DWORD
   dwRtoAlgorithm AS DWORD   ' DWORD
   RtoAlgorithm   AS LONG    ' TCP_RTO_ALGORITHM
END UNION

' // Size = 60 bytes
TYPE MIB_TCPSTATS_LH DWORD
   MIB_TCPSTATS_LH_UNION
   dwRtoMin       AS DWORD   ' DWORD
   dwRtoMax       AS DWORD   ' DWORD
   dwMaxConn      AS DWORD   ' DWORD
   dwActiveOpens  AS DWORD   ' DWORD
   dwPassiveOpens AS DWORD   ' DWORD
   dwAttemptFails AS DWORD   ' DWORD
   dwEstabResets  AS DWORD   ' DWORD
   dwCurrEstab    AS DWORD   ' DWORD
   dwInSegs       AS DWORD   ' DWORD
   dwOutSegs      AS DWORD   ' DWORD
   dwRetransSegs  AS DWORD   ' DWORD
   dwInErrs       AS DWORD   ' DWORD
   dwOutRsts      AS DWORD   ' DWORD
   dwNumConns     AS DWORD   ' DWORD
END TYPE

' // Size = 60 bytes
TYPE MIB_TCPSTATS_W2K DWORD
   dwRtoAlgorithm  AS DWORD   ' DWORD
   dwRtoMin        AS DWORD   ' DWORD
   dwRtoMax        AS DWORD   ' DWORD
   dwMaxConn       AS DWORD   ' DWORD
   dwActiveOpens   AS DWORD   ' DWORD
   dwPassiveOpens  AS DWORD   ' DWORD
   dwAttemptFails  AS DWORD   ' DWORD
   dwEstabResets   AS DWORD   ' DWORD
   dwCurrEstab     AS DWORD   ' DWORD
   dwInSegs        AS DWORD   ' DWORD
   dwOutSegs       AS DWORD   ' DWORD
   dwRetransSegs   AS DWORD   ' DWORD
   dwInErrs        AS DWORD   ' DWORD
   dwOutRsts       AS DWORD   ' DWORD
   dwNumConns      AS DWORD   ' DWORD
END TYPE

#IF %WINVER >= &H0600
   MACRO MIB_TCPSTATS = MIB_TCPSTATS_LH
#ELSE
   MACRO MIB_TCPSTATS = MIB_TCPSTATS_W2K
#ENDIF
