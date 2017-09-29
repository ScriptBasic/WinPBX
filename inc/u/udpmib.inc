' ########################################################################################
' Microsoft Windows
' File: udpmib.inc
' Contents: Public definitions and structures for the UDP-specific parts of MIB-II.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UDPMIB_INC = 1

#INCLUDE ONCE "windows.inc"

#IF NOT %DEF(%ANY_SIZE)
%ANY_SIZE = 1
#ENDIF

%TCPIP_OWNING_MODULE_SIZE = 16

' // Size = 8 bytes
TYPE MIB_UDPROW DWORD
   dwLocalAddr AS DWORD   ' DWORD
   dwLocalPort AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE MIB_UDPTABLE DWORD
   dwNumEntries AS DWORD        ' DWORD
   table(0)     AS MIB_UDPROW   '  MIB_UDPROW table[ANY_SIZE]
END TYPE

'#define SIZEOF_UDPTABLE(X) (FIELD_OFFSET(MIB_UDPTABLE, table[0]) + \
'                      ((X) * sizeof(MIB_UDPROW)) + ALIGN_SIZE)

' // Size = 12 bytes
TYPE MIB_UDPROW_OWNER_PID DWORD
   dwLocalAddr AS DWORD   ' DWORD
   dwLocalPort AS DWORD   ' DWORD
   dwOwningPid AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE MIB_UDPTABLE_OWNER_PID DWORD
   dwNumEntries AS DWORD                  ' DWORD
   table(0)     AS MIB_UDPROW_OWNER_PID   ' MIB_UDPROW_OWNER_PID    table[ANY_SIZE]
END TYPE

'#define SIZEOF_UDPTABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_UDPTABLE_OWNER_PID, table[0]) + \
'                             ((X) * sizeof(MIB_UDPROW_OWNER_PID)) + ALIGN_SIZE)

' // Size = 4 bytes
TYPE MIB_UDPROW_OWNER_MODULE_STRUCT DWORD
   SpecificPortBind AS BIT * 1 IN DWORD   ' int
END TYPE

' // Size = 8 bytes
TYPE MIB_UDPROW_OWNER_MODULE_UNION DWORD
   MIB_UDPROW_OWNER_MODULE_STRUCT
   dwFlags AS LONG
END TYPE

' // Size = 160 bytes
TYPE MIB_UDPROW_OWNER_MODULE    ' Must be 8 byte aligned
   dwLocalAddr       AS DWORD   ' DWORD
   dwLocalPort       AS DWORD   ' DWORD
   dwOwningPid       AS DWORD   ' DWORD
   alignment__       AS DWORD   ' // To keep 8 byte alignment
   liCreateTimestamp AS QUAD    ' LARGE_INTEGER
   MIB_UDPROW_OWNER_MODULE_UNION
   OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE - 1) AS QUAD   ' ULONGLONG
END TYPE

' // Size = 168 bytes
TYPE MIB_UDPTABLE_OWNER_MODULE   ' Must be 8 byte aligned
   dwNumEntries AS DWORD                     ' DWORD
   alignment__  AS DWORD                     ' // To keep 8 byte alignment
   table(0)     AS MIB_UDPROW_OWNER_MODULE   ' MIB_UDPROW_OWNER_MODULE table[ANY_SIZE]
END TYPE

'#define SIZEOF_UDPTABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_UDPTABLE_OWNER_MODULE, table[0]) + \
'                               ((X) * sizeof(MIB_UDPROW_OWNER_MODULE)) + ALIGN_SIZE)

#IF %DEF(%WS2IPDEF_INC)
'//
'// The following definitions require Winsock2.
'//

' // Size = 24 bytes
TYPE MIB_UDP6ROW DWORD
   dwLocalAddr    AS IN6_ADDR
   dwLocalScopeId AS DWORD      ' DWORD
   dwLocalPort    AS DWORD      ' DWORD
END TYPE

' // Size = 28 bytes
TYPE MIB_UDP6TABLE DWORD
   dwNumEntries AS DWORD         ' DWORD
   table(0)     AS MIB_UDP6ROW   ' MIB_UDP6ROW table[ANY_SIZE]
END TYPE

'#define SIZEOF_UDP6TABLE(X) (FIELD_OFFSET(MIB_UDP6TABLE, table[0]) + \
'                      ((X) * sizeof(MIB_UDP6ROW)) + ALIGN_SIZE)

' // Size = 28 bytes
TYPE MIB_UDP6ROW_OWNER_PID DWORD
   ucLocalAddr(15) AS BYTE    ' UCHAR[16]
   dwLocalScopeId  AS DWORD   ' DWORD
   dwLocalPort     AS DWORD   ' DWORD
   dwOwningPid     AS DWORD   ' DWORD
END TYPE

' // Size = 32 bytes
TYPE MIB_UDP6TABLE_OWNER_PID DWORD
   dwNumEntries AS DWORD                   ' DWORD
   table(0)     AS MIB_UDP6ROW_OWNER_PID   ' MIB_UDP6ROW_OWNER_PID   table[ANY_SIZE]
END TYPE

'#define SIZEOF_UDP6TABLE_OWNER_PID(X) (FIELD_OFFSET(MIB_UDP6TABLE_OWNER_PID, table[0]) + \
'                              ((X) * sizeof(MIB_UDP6ROW_OWNER_PID)) + ALIGN_SIZE)

' // Size = 4 bytes
TYPE MIB_UDP6ROW_OWNER_MODULE_STRUCT DWORD
   SpecificPortBind AS BIT * 1 IN DWORD   ' int
END TYPE

' // Size = 4 bytes
UNION MMIB_UDP6ROW_OWNER_MODULE_UNION DWORD
   MIB_UDPROW_OWNER_MODULE_STRUCT
   dwFlags AS LONG
END UNION

' // Size = 176 bytes
TYPE MIB_UDP6ROW_OWNER_MODULE QWORD FILL  ' Must be 8 byte aligned
   ucLocalAddr(15) AS BYTE     ' UCHAR[16]
   dwLocalScopeId AS DWORD     ' DWORD
   dwLocalPort AS DWORD        ' DWORD
   dwOwningPid AS DWORD        ' DWORD
   liCreateTimestamp AS QUAD   ' LARGE_INTEGER
   MMIB_UDP6ROW_OWNER_MODULE_UNION
   OwningModuleInfo(%TCPIP_OWNING_MODULE_SIZE - 1) AS QUAD   ' ULONGLONG
END TYPE

' // Size = 184 bytes
TYPE MIB_UDP6TABLE_OWNER_MODULE QWORD FILL  ' Must be 8 byte aligned
   dwNumEntries AS DWORD                      ' DWORD
   table(0)     AS MIB_UDP6ROW_OWNER_MODULE   ' MIB_UDP6ROW_OWNER_MODULE table[ANY_SIZE];
END TYPE

'#define SIZEOF_UDP6TABLE_OWNER_MODULE(X) (FIELD_OFFSET(MIB_UDP6TABLE_OWNER_MODULE, table[0]) + \
'                                ((X) * sizeof(MIB_UDP6ROW_OWNER_MODULE)) + ALIGN_SIZE)

#ENDIF   ' // _WS2IPDEF_

' // Size = 20 bytes
TYPE MIB_UDPSTATS DWORD
   dwInDatagrams  AS DWORD   ' DWORD
   dwNoPorts      AS DWORD   ' DWORD
   dwInErrors     AS DWORD   ' DWORD
   dwOutDatagrams AS DWORD   ' DWORD
   dwNumAddrs     AS DWORD   ' DWORD
END TYPE
